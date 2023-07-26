#include <lib/base/cfile.h>
#include <lib/base/ebase.h>
#include <lib/base/eerror.h>
#include <lib/base/wrappers.h>
#include <lib/dvb/decoder.h>
#include <lib/dvb/hisi_decoder.h>
#include <lib/components/tuxtxtapp.h>
#include <linux/dvb/audio.h>
#include <linux/dvb/video.h>
#include <linux/dvb/dmx.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <lib/dvb/fccdecoder.h>

DEFINE_REF(eDVBAudio);

eDVBAudio::eDVBAudio(eDVBDemux *demux, int dev)
    :m_demux(demux), m_dev(dev)
{
    char filename[128];
    if (demux)
    {
        sprintf(filename, "/dev/dvb/adapter%d/demux%d", demux->adapter, demux->demux);
        m_fd_demux = ::open(filename, O_RDWR | O_CLOEXEC);
        if (m_fd_demux < 0)
            eWarning("[eDVBAudio] %s: %m", filename);
    }
    else
    {
        m_fd_demux = -1;
    }

    m_hisi = eHISIDecoder::GetInstance();

}

// not finally values i think.. !!
#define VIDEO_STREAMTYPE_MPEG2 0
#define VIDEO_STREAMTYPE_MPEG4_H264 1
#define VIDEO_STREAMTYPE_VC1 3
#define VIDEO_STREAMTYPE_MPEG4_Part2 4
#define VIDEO_STREAMTYPE_VC1_SM 5
#define VIDEO_STREAMTYPE_MPEG1 6
#ifdef DREAMBOX
#define VIDEO_STREAMTYPE_H265_HEVC 22
#else
#define VIDEO_STREAMTYPE_H265_HEVC 7
#endif
#define VIDEO_STREAMTYPE_AVS 16
#define VIDEO_STREAMTYPE_AVS2 40


int eDVBAudio::startPid(int pid, int type)
{

    if (m_fd_demux >= 0)
    {
        dmx_pes_filter_params pes;

        pes.pid      = pid;
        pes.input    = DMX_IN_FRONTEND;
        pes.output   = DMX_OUT_DECODER;
        switch (m_dev)
        {
        case 0:
            pes.pes_type = DMX_PES_AUDIO0;
            break;
        case 1:
            pes.pes_type = DMX_PES_AUDIO1;
            break;
        case 2:
            pes.pes_type = DMX_PES_AUDIO2;
            break;
        case 3:
            pes.pes_type = DMX_PES_AUDIO3;
            break;
        }
        pes.flags    = 0;
        eDebugNoNewLineStart("[eDVBAudio%d] DMX_SET_PES_FILTER pid=0x%04x ", m_dev, pid);
        if (::ioctl(m_fd_demux, DMX_SET_PES_FILTER, &pes) < 0)
        {
            eDebugNoNewLine("failed: %m\n");
            return -errno;
        }
        eDebugNoNewLine("ok\n");
        eDebugNoNewLineStart("[eDVBAudio%d] DEMUX_START ", m_dev);
        if (::ioctl(m_fd_demux, DMX_START) < 0)
        {
            eDebugNoNewLine("failed: %m\n");
            return -errno;
        }
        eDebugNoNewLine("ok\n");

        if(m_hisi)
            m_hisi->AudioStartPid(pid, type);
    }

    return 0;
}

void eDVBAudio::stop()
{
    if(m_hisi)
        m_hisi->AudioStop();

    if (m_fd_demux >= 0)
    {
        eDebugNoNewLineStart("[eDVBAudio%d] DEMUX_STOP ", m_dev);
        if (::ioctl(m_fd_demux, DMX_STOP) < 0)
            eDebugNoNewLine("failed: %m\n");
        else
            eDebugNoNewLine("ok\n");
    }
}

void eDVBAudio::flush()
{
    if(m_hisi)
        m_hisi->AudioFlush();
}

void eDVBAudio::freeze()
{
    if(m_hisi)
        m_hisi->AudioFreeze();
}

void eDVBAudio::unfreeze()
{
    if(m_hisi)
        m_hisi->AudioUnfreeze();
}

void eDVBAudio::setChannel(int channel)
{
    switch (channel)
    {
    case aMonoLeft:
        HI_UNF_SND_SetTrackMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_ALL, HI_UNF_TRACK_MODE_DOUBLE_LEFT);
        break;
    case aMonoRight:
        HI_UNF_SND_SetTrackMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_ALL, HI_UNF_TRACK_MODE_DOUBLE_RIGHT);
        break;
    default:
        HI_UNF_SND_SetTrackMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_ALL, HI_UNF_TRACK_MODE_STEREO);
        break;
    }
}

int eDVBAudio::getPTS(pts_t &now)
{
    if(m_hisi)
        m_hisi->AudioGetPTS(now);

    return 0;
}

eDVBAudio::~eDVBAudio()
{
    unfreeze();  // why unfreeze here... but not unfreeze video in ~eDVBVideo ?!?
    if (m_fd_demux >= 0)
        ::close(m_fd_demux);

    m_hisi = 0;
    eDebug("[eDVBAudio%d] destroy", m_dev);
}

DEFINE_REF(eDVBVideo);

int eDVBVideo::m_close_invalidates_attributes = -1;

eDVBVideo::eDVBVideo(eDVBDemux *demux, int dev, bool fcc_enable)
	: m_demux(demux), m_dev(dev), m_fcc_enable(fcc_enable),
	m_width(-1), m_height(-1), m_framerate(-1), m_aspect(-1), m_progressive(-1), m_gamma(-1)
{
    char filename[128];
    if (demux)
    {
        sprintf(filename, "/dev/dvb/adapter%d/demux%d", demux->adapter, demux->demux);
        m_fd_demux = ::open(filename, O_RDWR | O_CLOEXEC);
        if (m_fd_demux < 0)
            eWarning("[eDVBVideo] %s: %m", filename);
        else
            eDebug("[eDVBVideo] demux device: %s", filename);
    }
    else
    {
        m_fd_demux = -1;
    }

    if (m_close_invalidates_attributes < 0)
    {
        /*
         * Some hardware does not invalidate the video attributes,
         * when we open the video device.
         * If that is the case, we cannot rely on receiving VIDEO_EVENTs
         * when the new video attributes are available, because they might
         * be equal to the old attributes.
         * Instead, we should just query the old attributes, and assume
         * them to be correct untill we receive VIDEO_EVENTs.
         *
         * Though this is merely a cosmetic issue, we do try to detect
         * whether attributes are invalidated or not.
         * So we can avoid polling for valid attributes, when we know
         * we can rely on VIDEO_EVENTs.
         */
        m_close_invalidates_attributes = (m_width == -1) ? 1 : 0;
    }
    m_hisi = eHISIDecoder::GetInstance();
}


int eDVBVideo::startPid(int pid, int type)
{
	
	if (m_fcc_enable)
		return 0;
	
    if (m_fd_demux >= 0)
    {
        dmx_pes_filter_params pes;
        pes.pid      = pid;
        pes.input    = DMX_IN_FRONTEND;
        pes.output   = DMX_OUT_DECODER;
        switch (m_dev)
        {
        case 0:
            pes.pes_type = DMX_PES_VIDEO0;
            break;
        case 1:
            pes.pes_type = DMX_PES_VIDEO1;
            break;
        case 2:
            pes.pes_type = DMX_PES_VIDEO2;
            break;
        case 3:
            pes.pes_type = DMX_PES_VIDEO3;
            break;
        }
        pes.flags    = 0;
        eDebugNoNewLineStart("[eDVBVideo%d] DMX_SET_PES_FILTER pid=0x%04x ", m_dev, pid);
        if (::ioctl(m_fd_demux, DMX_SET_PES_FILTER, &pes) < 0)
        {
            eDebugNoNewLine("failed: %m\n");
            return -errno;
        }
        eDebugNoNewLine("ok\n");
        eDebugNoNewLineStart("[eDVBVideo%d] DEMUX_START ", m_dev);
        if (::ioctl(m_fd_demux, DMX_START) < 0)
        {
            eDebugNoNewLine("failed: %m\n");
            return -errno;
        }
        eDebugNoNewLine("ok\n");

        if(m_hisi)
            m_hisi->VideoStartPid(pid, type);
    }

    return 0;
}

void eDVBVideo::stop()
{
	if (m_fcc_enable)
		return;
	
    if(m_hisi)
        m_hisi->VideoStop();

    if (m_fd_demux >= 0)
    {
        eDebugNoNewLineStart("[eDVBVideo%d] DEMUX_STOP  ", m_dev);
        if (::ioctl(m_fd_demux, DMX_STOP) < 0)
            eDebugNoNewLine("failed: %m\n");
        else
            eDebugNoNewLine("ok\n");
    }
}

void eDVBVideo::flush()
{
    if(m_hisi)
        m_hisi->VideoFlush();
}

void eDVBVideo::freeze()
{
    if(m_hisi)
        m_hisi->VideoFreeze();
}

void eDVBVideo::unfreeze()
{
    if(m_hisi)
        m_hisi->VideoUnfreeze();
}

int eDVBVideo::setSlowMotion(int repeat)
{
    return 0;
}

int eDVBVideo::setFastForward(int skip)
{
    return 0;
}

int eDVBVideo::getPTS(pts_t &now)
{
    if(m_hisi)
        m_hisi->VideoGetPTS(now);
    return 0;
}

eDVBVideo::~eDVBVideo()
{
    if (m_fd_demux >= 0)
        ::close(m_fd_demux);

    m_hisi = 0;
    eDebug("[eDVBVideo%d] destroy", m_dev);
}

DEFINE_REF(eDVBPCR);

eDVBPCR::eDVBPCR(eDVBDemux *demux, int dev): m_demux(demux), m_dev(dev)
{
    char filename[128];
    sprintf(filename, "/dev/dvb/adapter%d/demux%d", demux->adapter, demux->demux);
    m_fd_demux = ::open(filename, O_RDWR | O_CLOEXEC);
    if (m_fd_demux < 0)
        eWarning("[eDVBPCR] %s: %m", filename);
}

int eDVBPCR::startPid(int pid)
{
    if (m_fd_demux < 0)
        return -1;
    dmx_pes_filter_params pes;

    pes.pid      = pid;
    pes.input    = DMX_IN_FRONTEND;
    pes.output   = DMX_OUT_DECODER;
    switch (m_dev)
    {
    case 0:
        pes.pes_type = DMX_PES_PCR0;
        break;
    case 1:
        pes.pes_type = DMX_PES_PCR1;
        break;
    case 2:
        pes.pes_type = DMX_PES_PCR2;
        break;
    case 3:
        pes.pes_type = DMX_PES_PCR3;
        break;
    }
    pes.flags    = 0;
    eDebugNoNewLineStart("[eDVBPCR%d] DMX_SET_PES_FILTER pid=0x%04x ", m_dev, pid);
    if (::ioctl(m_fd_demux, DMX_SET_PES_FILTER, &pes) < 0)
    {
        eDebugNoNewLine("failed: %m\n");
        return -errno;
    }
    eDebugNoNewLine("ok\n");
    eDebugNoNewLineStart("[eDVBPCR%d] DEMUX_START ", m_dev);
    if (::ioctl(m_fd_demux, DMX_START) < 0)
    {
        eDebugNoNewLine("failed: %m\n");
        return -errno;
    }
    eDebugNoNewLine("ok\n");
    return 0;
}

void eDVBPCR::stop()
{
    eDebugNoNewLineStart("[eDVBPCR%d] DEMUX_STOP ", m_dev);
    if (::ioctl(m_fd_demux, DMX_STOP) < 0)
        eDebugNoNewLine("failed: %m\n");
    else
        eDebugNoNewLine("ok\n");
}

eDVBPCR::~eDVBPCR()
{
    if (m_fd_demux >= 0)
        ::close(m_fd_demux);
    eDebug("[eDVBPCR%d] destroy", m_dev);
}

DEFINE_REF(eDVBTText);

eDVBTText::eDVBTText(eDVBDemux *demux, int dev)
    :m_demux(demux), m_dev(dev)
{
    char filename[128];
    sprintf(filename, "/dev/dvb/adapter%d/demux%d", demux->adapter, demux->demux);
    m_fd_demux = ::open(filename, O_RDWR | O_CLOEXEC);
    if (m_fd_demux < 0)
        eWarning("[eDVBText] %s: %m", filename);
}

int eDVBTText::startPid(int pid)
{
    if (m_fd_demux < 0)
        return -1;
    dmx_pes_filter_params pes;

    pes.pid      = pid;
    pes.input    = DMX_IN_FRONTEND;
    pes.output   = DMX_OUT_DECODER;
    switch (m_dev)
    {
    case 0:
        pes.pes_type = DMX_PES_TELETEXT0;
        break;
    case 1:
        pes.pes_type = DMX_PES_TELETEXT1;
        break;
    case 2:
        pes.pes_type = DMX_PES_TELETEXT2;
        break;
    case 3:
        pes.pes_type = DMX_PES_TELETEXT3;
        break;
    }
    pes.flags    = 0;

    eDebugNoNewLineStart("[eDVBText%d] DMX_SET_PES_FILTER pid=0x%04x ", m_dev, pid);
    if (::ioctl(m_fd_demux, DMX_SET_PES_FILTER, &pes) < 0)
    {
        eDebugNoNewLine("failed: %m\n");
        return -errno;
    }
    eDebugNoNewLine("ok\n");
    eDebugNoNewLineStart("[eDVBText%d] DEMUX_START ", m_dev);
    if (::ioctl(m_fd_demux, DMX_START) < 0)
    {
        eDebugNoNewLine("failed: %m\n");
        return -errno;
    }
    eDebugNoNewLine("ok\n");
    return 0;
}

void eDVBTText::stop()
{
    eDebugNoNewLineStart("[eDVBText%d] DEMUX_STOP ", m_dev);
    if (::ioctl(m_fd_demux, DMX_STOP) < 0)
        eDebugNoNewLine("failed: %m\n");
    else
        eDebugNoNewLine("ok\n");
}

eDVBTText::~eDVBTText()
{
    if (m_fd_demux >= 0)
        ::close(m_fd_demux);
    eDebug("[eDVBText%d] destroy", m_dev);
}

DEFINE_REF(eTSMPEGDecoder);

int eTSMPEGDecoder::setState()
{
    int res = 0;

    int noaudio = (m_state != statePlay) && (m_state != statePause);
    int nott = noaudio; /* actually same conditions */

    if ((noaudio && m_audio) || (!m_audio && !noaudio))
        m_changed |= changeAudio | changeState;

    if ((nott && m_text) || (!m_text && !nott))
        m_changed |= changeText | changeState;

    const char *decoder_states[] = {"stop", "pause", "play", "decoderfastforward", "trickmode", "slowmotion"};
    eDebug("[eTSMPEGDecoder] decoder state: %s, vpid=%04x, apid=%04x", decoder_states[m_state], m_vpid, m_apid);

    int changed = m_changed;
    if (m_changed & changePCR)
    {
        if (m_pcr)
            m_pcr->stop();
        m_pcr = 0;
    }
    if (m_changed & changeAudio)
    {
        if (m_audio)
            m_audio->stop();
        m_audio = 0;
    }
    if (m_changed & changeVideo)
    {
        if (m_video)
        {
            m_video->stop();
            m_video = 0;
        }
    }
    if (m_changed & changeText)
    {
        if (m_text)
        {
            m_text->stop();
            if (m_demux && m_decoder == 0)	// Tuxtxt caching actions only on primary decoder
                eTuxtxtApp::getInstance()->stopCaching();
        }
        m_text = 0;
    }
    if (m_changed & changePCR)
    {
        if ((m_pcrpid >= 0) && (m_pcrpid < 0x1FFF))
        {
            m_pcr = new eDVBPCR(m_demux, m_decoder);
            if (m_pcr->startPid(m_pcrpid))
                res = -1;
        }
        m_changed &= ~changePCR;
    }
    if (m_changed & changeAudio)
    {
        if ((m_apid >= 0) && (m_apid < 0x1FFF) && !noaudio)
        {
            m_audio = new eDVBAudio(m_demux, m_decoder);
            if (m_audio->startPid(m_apid, m_atype))
                res = -1;
        }
        m_changed &= ~changeAudio;
    }	
    if (m_changed & changeVideo)
    {
        if ((m_vpid >= 0) && (m_vpid < 0x1FFF))
        {
            m_video = new eDVBVideo(m_demux, m_decoder, m_fcc_enable);
            if (m_video->startPid(m_vpid, m_vtype))
                res = -1;
        }
        m_changed &= ~changeVideo;
    }
    if (m_changed & changeText)
    {
        if ((m_textpid >= 0) && (m_textpid < 0x1FFF) && !nott)
        {
            m_text = new eDVBTText(m_demux, m_decoder);
            if (m_text->startPid(m_textpid))
                res = -1;

            if (m_demux && m_decoder == 0)	// Tuxtxt caching actions only on primary decoder
            {
                uint8_t demux = 0;
                m_demux->getCADemuxID(demux);
                eTuxtxtApp::getInstance()->startCaching(m_textpid, demux);
            }
        }
        else if (m_demux && m_decoder == 0)	// Tuxtxt caching actions only on primary decoder
            eTuxtxtApp::getInstance()->resetPid();

        m_changed &= ~changeText;
    }

    if (changed & (changeState|changeVideo|changeAudio))
    {
        /* play, slowmotion, fast-forward */
        int state_table[6][4] =
        {
            /* [stateStop] =                 */ {0, 0, 0},
            /* [statePause] =                */ {0, 0, 0},
            /* [statePlay] =                 */ {1, 0, 0},
            /* [stateDecoderFastForward] =   */ {1, 0, m_ff_sm_ratio},
            /* [stateHighspeedFastForward] = */ {1, 0, 1},
            /* [stateSlowMotion] =           */ {1, m_ff_sm_ratio, 0}
        };
        int *s = state_table[m_state];
        if (changed & (changeState|changeVideo) && m_video)
        {
            m_video->setSlowMotion(s[1]);
            m_video->setFastForward(s[2]);
            if (s[0])
                m_video->unfreeze();
            else
                m_video->freeze();
        }
        if (changed & (changeState|changeAudio) && m_audio)
        {
            if (s[0])
                m_audio->unfreeze();
            else
                m_audio->freeze();
        }
        m_changed &= ~changeState;
    }

    if (changed && !m_video && m_audio && m_radio_pic.length())
        showSinglePic(m_radio_pic.c_str());

    return res;
}

int eTSMPEGDecoder::m_pcm_delay=-1,
                    eTSMPEGDecoder::m_ac3_delay=-1;

RESULT eTSMPEGDecoder::setHwPCMDelay(int delay)
{
    if (delay != m_pcm_delay )
    {
        if (CFile::writeIntHex("/proc/stb/audio/audio_delay_pcm", delay*90) >= 0)
        {
            m_pcm_delay = delay;
            return 0;
        }
    }
    return -1;
}

RESULT eTSMPEGDecoder::setHwAC3Delay(int delay)
{
    if ( delay != m_ac3_delay )
    {
        if (CFile::writeIntHex("/proc/stb/audio/audio_delay_bitstream", delay*90) >= 0)
        {
            m_ac3_delay = delay;
            return 0;
        }
    }
    return -1;
}


RESULT eTSMPEGDecoder::setPCMDelay(int delay)
{
    return m_decoder == 0 ? setHwPCMDelay(delay) : -1;
}

RESULT eTSMPEGDecoder::setAC3Delay(int delay)
{
    return m_decoder == 0 ? setHwAC3Delay(delay) : -1;
}

eTSMPEGDecoder::eTSMPEGDecoder(eDVBDemux *demux, int decoder)
    : m_demux(demux),
      m_vpid(-1), m_vtype(-1), m_apid(-1), m_atype(-1), m_pcrpid(-1), m_textpid(-1),
      m_width(-1), m_height(-1), m_framerate(-1), m_aspect(-1), m_progressive(-1),
      m_changed(0), m_decoder(decoder), m_video_clip_fd(-1), m_showSinglePicTimer(eTimer::create(eApp)), m_VideoRead(eTimer::create(eApp)),
	  m_fcc_fd(-1), m_fcc_enable(false), m_fcc_state(fcc_state_stop), m_fcc_feid(-1), m_fcc_vpid(-1), m_fcc_vtype(-1), m_fcc_pcrpid(-1)
{
    if (m_demux)
    {
        m_demux->connectEvent(sigc::mem_fun(*this, &eTSMPEGDecoder::demux_event), m_demux_event_conn);
    }
    CONNECT(m_showSinglePicTimer->timeout, eTSMPEGDecoder::finishShowSinglePic);
    CONNECT(m_VideoRead->timeout, eTSMPEGDecoder::parseVideoInfo);
    m_VideoRead->start(500, false);

    m_state = stateStop;

    if (m_demux && m_decoder == 0)	// Tuxtxt caching actions only on primary decoder
        eTuxtxtApp::getInstance()->initCache();

    m_hisi = eHISIDecoder::GetInstance();
}

eTSMPEGDecoder::~eTSMPEGDecoder()
{
    finishShowSinglePic();
    m_vpid = m_apid = m_pcrpid = m_textpid = pidNone;
    m_changed = -1;
    setState();
	fccStop();
	fccFreeFD();
	
    if (m_demux && m_decoder == 0)	// Tuxtxt caching actions only on primary decoder
        eTuxtxtApp::getInstance()->freeCache();

    m_hisi = 0;
}

RESULT eTSMPEGDecoder::setVideoPID(int vpid, int type)
{
    if ((m_vpid != vpid) || (m_vtype != type))
    {
        m_changed |= changeVideo;
        m_vpid = vpid;
        m_vtype = type;
    }
    return 0;
}

RESULT eTSMPEGDecoder::setAudioPID(int apid, int type)
{
    if ((m_apid != apid) || (m_atype != type))
    {
        m_changed |= changeAudio;
        m_atype = type;
        m_apid = apid;
    }
    return 0;
}

int eTSMPEGDecoder::m_audio_channel = -1;

RESULT eTSMPEGDecoder::setAudioChannel(int channel)
{
	if (channel == -1)
		channel = ac_stereo;
	if (m_decoder == 0 && m_audio_channel != channel)
	{
		if (m_audio)
		{
			m_audio->setChannel(channel);
			m_audio_channel=channel;
		}
		else
			eDebug("[eTSMPEGDecoder] setAudioChannel but no audio decoder exist");
	}
	return 0;
}

int eTSMPEGDecoder::getAudioChannel()
{
    return m_audio_channel == -1 ? ac_stereo : m_audio_channel;
}

RESULT eTSMPEGDecoder::setSyncPCR(int pcrpid)
{
    if (m_pcrpid != pcrpid)
    {
        m_changed |= changePCR;
        m_pcrpid = pcrpid;
    }
    return 0;
}

RESULT eTSMPEGDecoder::setTextPID(int textpid)
{
    if (m_textpid != textpid)
    {
        m_changed |= changeText;
        m_textpid = textpid;
    }
    return 0;
}

RESULT eTSMPEGDecoder::setSyncMaster(int who)
{
    return -1;
}

RESULT eTSMPEGDecoder::set()
{
    return setState();
}

RESULT eTSMPEGDecoder::play()
{
    if (m_state == statePlay)
    {
        if (!m_changed)
            return 0;
    }
    else
    {
        m_state = statePlay;
        m_changed |= changeState;
    }
    return setState();
}

RESULT eTSMPEGDecoder::pause()
{
    if (m_state == statePause)
        return 0;
    m_state = statePause;
    m_changed |= changeState;
    return setState();
}

RESULT eTSMPEGDecoder::setFastForward(int frames_to_skip)
{
    // fast forward is only possible if video data is present
    if (!m_video)
        return -1;

    if ((m_state == stateDecoderFastForward) && (m_ff_sm_ratio == frames_to_skip))
        return 0;

    m_state = stateDecoderFastForward;
    m_ff_sm_ratio = frames_to_skip;
    m_changed |= changeState;
    return setState();

//		return m_video->setFastForward(frames_to_skip);
}

RESULT eTSMPEGDecoder::setSlowMotion(int repeat)
{
    // slow motion is only possible if video data is present
    if (!m_video)
        return -1;

    if ((m_state == stateSlowMotion) && (m_ff_sm_ratio == repeat))
        return 0;

    m_state = stateSlowMotion;
    m_ff_sm_ratio = repeat;
    m_changed |= changeState;
    return setState();
}

RESULT eTSMPEGDecoder::setTrickmode()
{
    // trickmode is only possible if video data is present
    if (!m_video)
        return -1;

    if (m_state == stateTrickmode)
        return 0;

    m_state = stateTrickmode;
    m_changed |= changeState;
    return setState();
}

RESULT eTSMPEGDecoder::flush()
{
    if (m_audio)
        m_audio->flush();
    if (m_video)
        m_video->flush();
    return 0;
}

void eTSMPEGDecoder::demux_event(int event)
{
    switch (event)
    {
    case eDVBDemux::evtFlush:
        flush();
        break;
    default:
        break;
    }
}

RESULT eTSMPEGDecoder::getPTS(int what, pts_t &pts)
{
    if (what == 0) /* auto */
        what = m_video ? 1 : 2;

    if (what == 1) /* video */
    {
        if (m_video)
            return m_video->getPTS(pts);
        else
            return -1;
    }

    if (what == 2) /* audio */
    {
        if (m_audio)
            return m_audio->getPTS(pts);
        else
            return -1;
    }

    return -1;
}

RESULT eTSMPEGDecoder::setRadioPic(const std::string &filename)
{
    m_radio_pic = filename;
    return 0;
}

RESULT eTSMPEGDecoder::showSinglePic(const char *filename)
{
    return 0;
}

void eTSMPEGDecoder::finishShowSinglePic()
{
}

void eTSMPEGDecoder::parseVideoInfo()
{
    int x = -1;
    int y = -1;

    if (m_width <= 0 && m_height <= 0)
    {

        if(m_hisi)
            x = m_hisi->getVideoWidth();

        if(m_hisi)
            y = m_hisi->getVideoHeight();
        if ( x > 0 && y > 0)
        {
            struct iTSMPEGDecoder::videoEvent event;
            if(m_hisi)
                m_aspect = m_hisi->getVideoAspect();
            event.type = iTSMPEGDecoder::videoEvent::eventSizeChanged;
            m_aspect = event.aspect = m_aspect == 1 ? 2 : 3;  // convert dvb api to etsi
            m_height = event.height = y;
            m_width = event.width = x;
            video_event(event);
            eDebug("[eTSMPEGDecoder] event size change %d %d %d", m_height, m_width, m_aspect);
        }
    }
    else if (m_width > 0 && m_framerate == -1)
    {
        struct iTSMPEGDecoder::videoEvent event;
        if(m_hisi)
            m_framerate = m_hisi->getVideoFrameRate();
        event.type = iTSMPEGDecoder::videoEvent::eventFrameRateChanged;
        event.framerate = m_framerate;
        video_event(event);
        eDebug("[eTSMPEGDecoder] event frame rate change %d", m_framerate);
    }
    else if (m_width > 0 && m_progressive == -1)
    {
        if(m_hisi)
            m_progressive = m_hisi->getVideoProgressive();
        if (m_progressive != 2)
        {
            struct iTSMPEGDecoder::videoEvent event;
            event.type = iTSMPEGDecoder::videoEvent::eventProgressiveChanged;
            event.progressive = m_progressive;
            video_event(event);
            eDebug("[eTSMPEGDecoder] event progressive change %d", m_progressive);
        }
    }
}

RESULT eTSMPEGDecoder::connectVideoEvent(const sigc::slot1<void, struct videoEvent> &event, ePtr<eConnection> &conn)
{
    conn = new eConnection(this, m_video_event.connect(event));
    return 0;
}


void eTSMPEGDecoder::video_event(struct videoEvent event)
{
    /* emit */ m_video_event(event);
}


int eTSMPEGDecoder::getVideoWidth()
{
    int _width = -1;
    if(m_hisi)
        _width = m_hisi->getVideoWidth();
    if (!_width)
        return -1;
    return _width;

}

int eTSMPEGDecoder::getVideoHeight()
{
    int _height = -1;
    if(m_hisi)
        _height = m_hisi->getVideoHeight();
    if (!_height)
        return -1;
    return _height;

}

int eTSMPEGDecoder::getVideoProgressive()
{
    int _progressive = -1;
    if(m_hisi)
        _progressive = m_hisi->getVideoProgressive();
    if (_progressive == 2)
        return -1;
    return _progressive;

}

int eTSMPEGDecoder::getVideoFrameRate()
{
    int _framerate = -1;
    if(m_hisi)
        _framerate = m_hisi->getVideoFrameRate();
    return _framerate;

}

int eTSMPEGDecoder::getVideoAspect()
{
    int _aspect = -1;
    if(m_hisi)
        _aspect = m_hisi->getVideoAspect();
    if (!_aspect)
        return -1;

    return _aspect == 1 ? 2 : 3;
}

int eTSMPEGDecoder::getVideoGamma()
{
    //if (m_video)
    //	return m_video->getGamma();
    return -1;

}

#define FCC_SET_VPID 100
#define FCC_SET_APID 101
#define FCC_SET_PCRPID 102
#define FCC_SET_VCODEC 103
#define FCC_SET_ACODEC 104
#define FCC_SET_FRONTEND_ID 105
#define FCC_START 106
#define FCC_STOP 107
#define FCC_DECODER_START 108
#define FCC_DECODER_STOP 109

RESULT eTSMPEGDecoder::prepareFCC(int fe_id, int vpid, int vtype, int pcrpid)
{
	//eDebug("[eTSMPEGDecoder] prepareFCC vp : %d, vt : %d, pp : %d, fe : %d", vpid, vtype, pcrpid, fe_id); 

	if ((fccGetFD() == -1) || (fccSetPids(fe_id, vpid, vtype, pcrpid) < 0) || (fccStart() < 0))
	{
		fccFreeFD();
		return -1;
	}

	m_fcc_enable = true;

	return 0;
}

RESULT eTSMPEGDecoder::fccDecoderStart()
{
	if (m_fcc_fd == -1)
		return -1;

	if (m_fcc_state != fcc_state_ready)
	{
		eDebug("[eTSMPEGDecoder] FCC decoder is already in decoding state.");
		return 0;
	}

	if (ioctl(m_fcc_fd, FCC_DECODER_START) < 0)
	{
		eDebug("[eTSMPEGDecoder] ioctl FCC_DECODER_START failed! (%m)");
		return -1;
	}

	m_fcc_state = fcc_state_decoding;

	eDebug("[eTSMPEGDecoder] FCC_DECODER_START OK!");
	return 0;
}

RESULT eTSMPEGDecoder::fccDecoderStop()
{
	if (m_fcc_fd == -1)
		return -1;

	if (m_fcc_state != fcc_state_decoding)
	{
		eDebug("[eTSMPEGDecoder] FCC decoder is not in decoding state.");
	}
	else if (ioctl(m_fcc_fd, FCC_DECODER_STOP) < 0)
	{
		eDebug("[eTSMPEGDecoder] ioctl FCC_DECODER_STOP failed! (%m)");
		return -1;
	}

	m_fcc_state = fcc_state_ready;

	/* stop pcr, video, audio, text */
	finishShowSinglePic();

	m_vpid = m_apid = m_pcrpid = m_textpid = pidNone;
	m_changed = -1;
	setState();

	eDebug("[eTSMPEGDecoder] FCC_DECODER_STOP OK!");
	return 0;
}

RESULT eTSMPEGDecoder::fccUpdatePids(int fe_id, int vpid, int vtype, int pcrpid)
{
	//eDebug("[eTSMPEGDecoder] vp : %d, vt : %d, pp : %d, fe : %d", vpid, vtype, pcrpid, fe_id);

	if ((fe_id != m_fcc_feid) || (vpid != m_fcc_vpid) || (vtype != m_fcc_vtype) || (pcrpid != m_fcc_pcrpid))
	{
		fccStop();
		if (prepareFCC(fe_id, vpid, vtype, pcrpid))
		{
			eDebug("[eTSMPEGDecoder] prepare FCC failed!");
			return -1;
		}
	}
	return 0;
}

RESULT eTSMPEGDecoder::fccStart()
{
	if (m_fcc_fd == -1)
		return -1;

	if (m_fcc_state != fcc_state_stop)
	{
		eDebug("[eTSMPEGDecoder] FCC is already started!");
		return 0;
	}
	else if (ioctl(m_fcc_fd, FCC_START) < 0)
	{
		eDebug("[eTSMPEGDecoder] ioctl FCC_START failed! (%m)");
		return -1;
	}

	eDebug("[eTSMPEGDecoder] FCC_START OK!");

	m_fcc_state = fcc_state_ready;
	return 0;
}

RESULT eTSMPEGDecoder::fccStop()
{
	if (m_fcc_fd == -1)
		return -1;

	if (m_fcc_state == fcc_state_stop)
	{
		eDebug("[eTSMPEGDecoder] FCC is already stopped!");
		return 0;
	}

	else if (m_fcc_state == fcc_state_decoding)
	{
		fccDecoderStop();
	}

	if (ioctl(m_fcc_fd, FCC_STOP) < 0)
	{
		eDebug("[eTSMPEGDecoder] ioctl FCC_STOP failed! (%m)");
		return -1;
	}

	m_fcc_state = fcc_state_stop;

	eDebug("[eTSMPEGDecoder] FCC_STOP OK!");
	return 0;
}

RESULT eTSMPEGDecoder::fccSetPids(int fe_id, int vpid, int vtype, int pcrpid)
{
	int streamtype = VIDEO_STREAMTYPE_MPEG2;

	if (m_fcc_fd == -1)
		return -1;

	if (ioctl(m_fcc_fd, FCC_SET_FRONTEND_ID, fe_id) < 0)
	{
		eDebug("[eTSMPEGDecoder] FCC_SET_FRONTEND_ID failed! (%m)");
		return -1;
	}

	else if(ioctl(m_fcc_fd, FCC_SET_PCRPID, pcrpid) < 0)
	{
		eDebug("[eTSMPEGDecoder] FCC_SET_PCRPID failed! (%m)");
		return -1;
	}

	else if (ioctl(m_fcc_fd, FCC_SET_VPID, vpid) < 0)
	{
		eDebug("[eTSMPEGDecoder] FCC_SET_VPID failed! (%m)");
		return -1;
	}

	switch(vtype)
	{
		default:
		case eDVBVideo::MPEG2:
			break;
		case eDVBVideo::MPEG4_H264:
			streamtype = VIDEO_STREAMTYPE_MPEG4_H264;
			break;
		case eDVBVideo::MPEG1:
			streamtype = VIDEO_STREAMTYPE_MPEG1;
			break;
		case eDVBVideo::MPEG4_Part2:
			streamtype = VIDEO_STREAMTYPE_MPEG4_Part2;
			break;
		case eDVBVideo::VC1:
			streamtype = VIDEO_STREAMTYPE_VC1;
			break;
		case eDVBVideo::VC1_SM:
			streamtype = VIDEO_STREAMTYPE_VC1_SM;
			break;
		case eDVBVideo::H265_HEVC:
			streamtype = VIDEO_STREAMTYPE_H265_HEVC;
			break;
	}

	if(ioctl(m_fcc_fd, FCC_SET_VCODEC, streamtype) < 0)
	{
		eDebug("[eTSMPEGDecoder] FCC_SET_VCODEC failed! (%m)");
		return -1;
	}

	m_fcc_feid = fe_id;
	m_fcc_vpid = vpid;
	m_fcc_vtype = vtype;
	m_fcc_pcrpid = pcrpid;

	//eDebug("[eTSMPEGDecoder] SET PIDS OK!");
	return 0;
}

RESULT eTSMPEGDecoder::fccGetFD()
{
	if (m_fcc_fd == -1)
	{
		eFCCDecoder* fcc = eFCCDecoder::getInstance();
		if (fcc != NULL)
		{
			m_fcc_fd = fcc->allocateFcc();
		}
	}

	return m_fcc_fd;
}

RESULT eTSMPEGDecoder::fccFreeFD()
{
	if (m_fcc_fd != -1)
	{
		eFCCDecoder* fcc = eFCCDecoder::getInstance();
		if (fcc != NULL)
		{
			fcc->freeFcc(m_fcc_fd);
			m_fcc_fd = -1;
		}
	}

	return 0;
}
