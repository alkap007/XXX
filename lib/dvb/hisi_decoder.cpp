#include <lib/base/init.h>
#include <lib/base/init_num.h>
#include <lib/base/cfile.h>
#include <lib/base/ebase.h>
#include <lib/base/eerror.h>
#include <lib/base/wrappers.h>
#include <lib/dvb/hisi_decoder.h>


#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern "C"
{
#include <lib/hisi/hi_adp_mpi.h>
} // extern "C"


HI_S32 AVEventReport(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_VOID* pPara)
{
    return eHISIDecoder::GetInstance()->EventReport(hAvplay, enEvent, pPara);
}

eHISIDecoder *eHISIDecoder::instance;
eHISIDecoder::eHISIDecoder()
{
    m_hAvplay = 0;
    m_hWin = 0;
    m_hTrack = 0;

    m_opened = false;
    m_video_opend = false;
    m_audio_opend = false;
    m_audio_last_pts = INVALID_PTS_VALUE;
    m_video_last_pts = INVALID_PTS_VALUE;

    if (!instance)
    {
        eDebug("[eHISIDecoder] settings instance.");
        instance = this;
    }

    Init();
}

eHISIDecoder::~eHISIDecoder()
{
    VideoStop();
    AudioStop();
    Deinit();
    if (instance == this)
    {
        eDebug("[eHISIDecoder] clear instance");
        instance = 0;
    }
}
/*
eHISIDecoder* eHISIDecoder::GetInstance()
{
    static eHISIDecoder peHISIDecoder;
    return &peHISIDecoder;
}
*/

DEFINE_REF(eHISIDecoder);

bool eHISIDecoder::Init()
{
#ifdef USE_DMX
    HI_S32 ret = HI_SUCCESS;
#endif
    HI_UNF_AVPLAY_ATTR_S AvplayAttr;
    HI_UNF_SYNC_ATTR_S AvSyncAttr;

    if (m_opened)
        return true;

    if (HI_SYS_Init() != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_SYS_Init exception");
        goto SYS_DEINIT;
    }

    if (HI_UNF_OTP_Init() != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_OTP_Init exception");
        goto OTP_DEINIT;
    }

    if (HIADP_VO_Init(HI_UNF_VO_DEV_MODE_NORMAL) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_VO_Init exception");
        goto ADP_VO_DEINIT;
    }

    if (HI_UNF_AVPLAY_Init() != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_AVPlay_Init exception");
        goto AVPLAY_DEINIT;
    }

    if (HIADP_Snd_Init() != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_Snd_Init exception");
        goto ADP_Snd_Init;
    }

    if (HIADP_AVPlay_RegADecLib() != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_AVPlay_RegADecLib exception");
        goto ADP_Snd_Init;
    }

#ifdef USE_DMX
    ret = HI_UNF_DMX_Init();
    //ret |= HI_UNF_DMX_AttachTSPort(PLAY_DMX_ID, HI_UNF_DMX_PORT_RAM_0);
    if (HI_SUCCESS != ret)
    {
        eDebug("[eHISIDecoder] HI_UNF_DMX_Init failed");
        goto ADP_Snd_Init;
    }
    /*
            ret = HI_UNF_DMX_CreateTSBuffer(HI_UNF_DMX_PORT_RAM_0, 0x200000, &g_TsBuf);
            if (ret != HI_SUCCESS)
            {
                eDebug("[eHISIDecoder] HI_UNF_DMX_CreateTSBuffer failed");
                goto ADP_Snd_Init;
            }
    */
#endif

#ifdef USE_DMX
    if (HI_UNF_AVPLAY_GetDefaultConfig(&AvplayAttr, HI_UNF_AVPLAY_STREAM_TYPE_TS) != HI_SUCCESS)
#else
    if (HI_UNF_AVPLAY_GetDefaultConfig(&AvplayAttr, HI_UNF_AVPLAY_STREAM_TYPE_ES) != HI_SUCCESS)
#endif
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_GetDefaultConfig exception");
        goto AVPLAY_DEINIT;
    }

    AvplayAttr.u32DemuxId = 0;
    AvplayAttr.stStreamAttr.u32AudBufSize = 2 * 1024 * 1024;
    AvplayAttr.stStreamAttr.u32VidBufSize = 20 * 1024 * 1024;

    if (HI_UNF_AVPLAY_Create(&AvplayAttr, &m_hAvplay) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_Create exception");
        goto AVPLAY_DESTROY;
    }

    for (int AvEvent = (int)HI_UNF_AVPLAY_EVENT_EOS; AvEvent < (int)HI_UNF_AVPLAY_EVENT_BUTT;
            AvEvent++)
    {
        if (HI_UNF_AVPLAY_RegisterEvent64(m_hAvplay, (HI_UNF_AVPLAY_EVENT_E)AvEvent, AVEventReport) !=
                HI_SUCCESS)
        {
            eDebug("[eHISIDecoder] registe avplay AvEvent {%d} fail!", AvEvent);
            goto AVPLAY_DESTROY;
        }
    }

    if (HI_UNF_AVPLAY_GetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_MCE_Exit exception");
        goto AVPLAY_DESTROY;
    }

    AvSyncAttr.enSyncRef = HI_UNF_SYNC_REF_NONE;
    if (HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_ATTR_ID_SYNC exception");
        return false;
    }

    if (HIADP_VO_CreatWin(HI_NULL, &m_hWin) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_VO_CreatWin exception");
        goto VO_DEINIT;
    }

    eDebug("[eHISIDecoder] Init success");

    m_video_opend = false;
    m_audio_opend = false;

    m_opened = true;

    return true;

VO_DEINIT:
    HI_UNF_VO_DestroyWindow(m_hWin);
    m_hWin = 0;

AVPLAY_DESTROY:
    HI_UNF_AVPLAY_Destroy(m_hAvplay);
    m_hAvplay = 0;

ADP_Snd_Init:
    HIADP_Snd_DeInit();

AVPLAY_DEINIT:
    HI_UNF_AVPLAY_DeInit();

#ifdef USE_DMX
    //HI_UNF_DMX_DestroyTSBuffer(g_TsBuf);
    //HI_UNF_DMX_DetachTSPort(PLAY_DMX_ID);
    HI_UNF_DMX_DeInit();
#endif

ADP_VO_DEINIT:
    HIADP_VO_DeInit();

OTP_DEINIT:
    HI_UNF_OTP_DeInit();

SYS_DEINIT:
    HI_SYS_DeInit();

    m_opened = false;
    return false;
}

bool eHISIDecoder::Deinit()
{

    if ((m_video_opend) || (m_audio_opend))
        return false;

    if(!m_opened)
        return false;

    for (int AvEvent = (int)HI_UNF_AVPLAY_EVENT_EOS; AvEvent < (int)HI_UNF_AVPLAY_EVENT_BUTT; AvEvent++)
    {
        if (m_hAvplay)
            HI_UNF_AVPLAY_UnRegisterEvent(m_hAvplay, (HI_UNF_AVPLAY_EVENT_E)AvEvent);
    }

    if (m_hWin)
    {
        HI_UNF_VO_DestroyWindow(m_hWin);
        m_hWin = 0;
    }

    if (m_hAvplay)
    {
        HI_UNF_AVPLAY_Destroy(m_hAvplay);
        m_hAvplay = 0;
    }

    HI_UNF_AVPLAY_DeInit();
    HIADP_Snd_DeInit();

#ifdef USE_DMX
    //HI_UNF_DMX_DetachTSPort(PLAY_DMX_ID);
    HI_UNF_DMX_DeInit();
#endif

    HIADP_VO_DeInit();
    HI_UNF_OTP_DeInit();
    HI_SYS_DeInit();

    m_opened = false;

    eDebug("[eHISIDecoder] Deinit Success");

    return true;
}

bool eHISIDecoder::VideoStartPid(HI_U32 VidPid, HI_U32 codec_id)
{

    HI_S32 ret = HI_SUCCESS;
    HI_U32 pVidPid = VidPid;

    if (m_video_opend)
        VideoStop();

    HI_UNF_VCODEC_TYPE_E VdecType = codec2vdec(codec_id);
	
    hi_width = -1;
    hi_height = -1;
    hi_framerate = -1;
    hi_aspect = -1;
    hi_progressive = -1;	

    HI_UNF_AVPLAY_OPEN_OPT_S* pMaxCapbility = HI_NULL;
    HI_UNF_AVPLAY_OPEN_OPT_S stMaxCapbility;
    HI_UNF_VCODEC_ATTR_S VcodecAttr;
    HI_UNF_AVPLAY_FRMRATE_PARAM_S stFramerate;

    eDebug("[eHISIDecoder] codec: using video codec ID %#06x", codec_id);

    if (HI_UNF_VCODEC_TYPE_MVC == VdecType)
    {
        stMaxCapbility.enCapLevel = HI_UNF_VCODEC_CAP_LEVEL_FULLHD;
        stMaxCapbility.enDecType = HI_UNF_VCODEC_DEC_TYPE_BUTT;
        stMaxCapbility.enProtocolLevel = HI_UNF_VCODEC_PRTCL_LEVEL_MVC;
        pMaxCapbility = &stMaxCapbility;
    }

    if (HI_UNF_AVPLAY_ChnOpen(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID, pMaxCapbility) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_ChnOpen exception");
        return false;
    }

    if (HI_UNF_AVPLAY_GetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_VDEC, &VcodecAttr) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_GetAttr exception");
        goto VCHN_CLOSE;
    }

    if (HI_UNF_VCODEC_TYPE_VC1 == VdecType)
    {
        VcodecAttr.unExtAttr.stVC1Attr.bAdvancedProfile = (codec_id == VC1) ? HI_TRUE : HI_FALSE;
        VcodecAttr.unExtAttr.stVC1Attr.u32CodecVersion = 8;
        eDebug("[eHISIDecoder] stVC1Attr bAdvancedProfile %d, version:%d", VcodecAttr.unExtAttr.stVC1Attr.bAdvancedProfile, VcodecAttr.unExtAttr.stVC1Attr.u32CodecVersion);
    }

    if (HI_UNF_VCODEC_TYPE_VP6 == VdecType)
    {
        VcodecAttr.unExtAttr.stVP6Attr.bReversed = HI_FALSE;
    }

    VcodecAttr.enType = VdecType;
    if (HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_VDEC, &VcodecAttr) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_ChnOpen exception");
        goto VCHN_CLOSE;
    }

    if (HI_UNF_VO_AttachWindow(m_hWin, m_hAvplay) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_VO_AttachWindow exception");
        goto VCHN_CLOSE;
    }

    if (HI_UNF_VO_SetWindowEnable(m_hWin, HI_TRUE) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_VO_SetWindowEnable exception");
        goto WIN_DETATCH;
    }

    ret = HIADP_AVPlay_SetVdecAttr(m_hAvplay, VdecType, HI_UNF_VCODEC_MODE_NORMAL);
#ifdef USE_DMX
    ret |= HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_VID_PID, &pVidPid);
#endif // USE_DMX     

    if (ret != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HIADP_AVPlay_SetVdecAttr exception");
        goto WIN_DETATCH;
    }

    stFramerate.enFrmRateType = HI_UNF_AVPLAY_FRMRATE_TYPE_PTS;
    stFramerate.stSetFrmRate.u32fpsInteger = 0 ;
    stFramerate.stSetFrmRate.u32fpsDecimal = 0;
    eDebug("[eHISIDecoder] HI_UNF_AVPLAY_SetAttr , frame rate : %d.%d", stFramerate.stSetFrmRate.u32fpsInteger, stFramerate.stSetFrmRate.u32fpsDecimal);
    if (HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_FRMRATE_PARAM, &stFramerate) !=
            HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_SetAttr exception, frame rate %d.%d", stFramerate.stSetFrmRate.u32fpsInteger, stFramerate.stSetFrmRate.u32fpsDecimal);
        goto WIN_DETATCH;
    }


    if (HI_UNF_AVPLAY_Start(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID, HI_NULL) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_Start exception");
        goto AVPLAY_VSTOP;
    }

    eDebug("[eHISIDecoder] Open Video success");

    m_video_opend = true;
    m_video_last_pts = INVALID_PTS_VALUE;

    return true;

AVPLAY_VSTOP:
    HI_UNF_AVPLAY_STOP_OPT_S Stop;
    Stop.enMode = HI_UNF_AVPLAY_STOP_MODE_BLACK;
    Stop.u32TimeoutMs = 0;
    HI_UNF_AVPLAY_Stop(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID, &Stop);

WIN_DETATCH:
    HI_UNF_VO_SetWindowEnable(m_hWin, HI_FALSE);
    HI_UNF_VO_DetachWindow(m_hWin, m_hAvplay);

VCHN_CLOSE:
    HI_UNF_AVPLAY_ChnClose(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID);

    return false;
}
bool eHISIDecoder::VideoStop()
{
    if (!m_video_opend)
        return false;

    HI_UNF_AVPLAY_STATUS_INFO_S stStatusInfo;
    if (HI_UNF_AVPLAY_GetStatusInfo(m_hAvplay, &stStatusInfo) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_GetStatusInfo exception");
        return false;
    }

    if (stStatusInfo.enRunStatus == HI_UNF_AVPLAY_STATUS_PAUSE)
    {
        if (HI_UNF_AVPLAY_Resume(m_hAvplay, HI_NULL) != HI_SUCCESS)
        {
            eDebug("[eHISIDecoder] HI_UNF_AVPLAY_Resume exception");
            return false;
        }
    }

    HI_UNF_AVPLAY_STOP_OPT_S Stop;
    Stop.enMode = HI_UNF_AVPLAY_STOP_MODE_BLACK;
    Stop.u32TimeoutMs = 0;
    if (HI_UNF_AVPLAY_Stop(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID, &Stop) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_Stop exception");
        return false;
    }

    if (HI_UNF_VO_SetWindowEnable(m_hWin, HI_FALSE) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_VO_SetWindowEnable exception");
        return false;
    }

    if (HI_UNF_VO_DetachWindow(m_hWin, m_hAvplay) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_VO_DetachWindow exception");
        return false;
    }

    if (HI_UNF_AVPLAY_ChnClose(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_ChnClose exception");
        return false;
    }

    VideoReset();

    m_video_opend = false;
	
    hi_width = -1;
    hi_height = -1;
    hi_framerate = -1;
    hi_aspect = -1;
    hi_progressive = -1;	

    return true;
}

void eHISIDecoder::VideoReset()
{
    HI_BOOL bIsEmpty = HI_FALSE;
    m_video_last_pts = INVALID_PTS_VALUE;

#ifdef USE_DMX
    //HI_UNF_DMX_ResetTSBuffer(g_TsBuf);
#endif

    HI_UNF_AVPLAY_IsBuffEmpty(m_hAvplay, &bIsEmpty);

    HI_UNF_AVPLAY_Reset(m_hAvplay, NULL);

    eDebug("[eHISIDecoder] VideoReset , check buffer empty:%d", bIsEmpty);
}

bool eHISIDecoder::VideoWrite(uint8_t* pData, size_t iSize, unsigned int pts_ms)
{
    if (!m_video_opend)
        return false;

    HI_UNF_STREAM_BUF_S StreamBuf;
#ifdef USE_DMX
    if (HI_UNF_DMX_GetTSBuffer(g_TsBuf, iSize, &StreamBuf, 1000) != HI_SUCCESS)
#else
    if (HI_UNF_AVPLAY_GetBuf(m_hAvplay, HI_UNF_AVPLAY_BUF_ID_ES_VID, iSize, &StreamBuf, 0) != HI_SUCCESS)
#endif

        return false;

    memcpy(StreamBuf.pu8Data, pData, iSize);

#ifdef USE_DMX
    if (HI_UNF_DMX_PutTSBuffer(g_TsBuf, iSize) != HI_SUCCESS)
#else
    if (HI_UNF_AVPLAY_PutBuf(m_hAvplay, HI_UNF_AVPLAY_BUF_ID_ES_VID, iSize, pts_ms) != HI_SUCCESS)
#endif

        return false;

    return true;
}


bool eHISIDecoder::VideoFreeze()
{
    if (!m_video_opend)
        return false;

    if (HI_UNF_AVPLAY_Pause(m_hAvplay, NULL) != HI_SUCCESS)
        return false;

    return true;
}
bool eHISIDecoder::VideoUnfreeze()
{
    if (!m_video_opend)
        return false;

    if (HI_UNF_AVPLAY_Resume(m_hAvplay, NULL) != HI_SUCCESS)
        return false;

    return true;
}
bool eHISIDecoder::VideoFlush()
{
    if (!m_video_opend)
        return false;

    HI_UNF_AVPLAY_FLUSH_STREAM_OPT_S stFlushOpt;
    HI_UNF_AVPLAY_FlushStream(m_hAvplay, &stFlushOpt);
    return true;
}

int eHISIDecoder::VideoGetPTS(pts_t &now)
{
    if (!m_video_opend)
        return -1;

    HI_UNF_AVPLAY_STATUS_INFO_S stStatusInfo;
    if(HI_UNF_AVPLAY_GetStatusInfo(m_hAvplay, &stStatusInfo) == HI_SUCCESS)
        now = stStatusInfo.stSyncStatus.u32LastVidPts;
    else
        now = 0;

    return now > 0 ? 0 : -1;
}


bool eHISIDecoder::AudioStartPid(HI_U32 AudPid, HI_U32 codec_id)
{

#ifdef USE_DMX
    HI_U32 pAudPid = AudPid;
#endif // USE_DMX

    if (m_audio_opend)
        AudioStop();

    HA_CODEC_ID_E AdecType = codec2adec(codec_id);
    HI_UNF_AUDIOTRACK_ATTR_S stTrackAttr;
    HI_UNF_ACODEC_ATTR_S AdecAttr;
    HI_UNF_AVPLAY_FRMRATE_PARAM_S stFrmRateAttr;

    memset(&stTrackAttr, 0x00, sizeof(stTrackAttr));
    memset(&AdecAttr, 0x00, sizeof(AdecAttr));
    memset(&stFrmRateAttr, 0x00, sizeof(stFrmRateAttr));

    eDebug("[eHISIDecoder] codec: using audio codec %#06x", codec_id);

    if (HI_UNF_AVPLAY_ChnOpen(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_ChnOpen audio exception");
        return false;
    }

    if (HI_UNF_SND_GetDefaultTrackAttr(HI_UNF_SND_TRACK_TYPE_MASTER, &stTrackAttr) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_TRACK_TYPE_MASTER exception");
        goto ACHN_CLOSE;
    }

    if (HI_UNF_SND_CreateTrack(HI_UNF_SND_0, &stTrackAttr, &m_hTrack) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_CreateTrack exception");
        goto ACHN_CLOSE;
    }

    if (HI_UNF_SND_Attach(m_hTrack, m_hAvplay) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_Attach exception");
        goto TRACK_DESTORY;
    }

    if (HIADP_AVPlay_SetAdecAttr(m_hAvplay, AdecType, HD_DEC_MODE_THRU, 0))
    {
        eDebug("[eHISIDecoder] HIADP_AVPlay_SetAdecAttr failed.");
        goto TRACK_DETATCH;
    }
#ifdef USE_DMX
    if (HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_AUD_PID, &pAudPid))
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_SetAttr failed.");
        goto TRACK_DETATCH;
    }
#endif // USE_DMX           
    if (HI_UNF_SND_SetHdmiMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_HDMI0, HI_UNF_SND_HDMI_MODE_RAW))
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_SetSpdifMode failed.");
        goto TRACK_DETATCH;
    }
    if (HI_UNF_SND_SetSpdifMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_SPDIF0,  HI_UNF_SND_SPDIF_MODE_RAW))
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_SetSpdifMode failed.");
        goto TRACK_DETATCH;
    }



    HI_UNF_SYNC_ATTR_S AvSyncAttr;
    HI_UNF_AVPLAY_GetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr);
    AvSyncAttr.enSyncRef = HI_UNF_SYNC_REF_AUDIO;
    AvSyncAttr.stSyncStartRegion.s32VidPlusTime = 60;
    AvSyncAttr.stSyncStartRegion.s32VidNegativeTime = -20;
    AvSyncAttr.u32PreSyncTimeoutMs =  1000;
    AvSyncAttr.bQuickOutput = HI_FALSE;
    if (HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr))
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_SetAttr failed.");
        goto TRACK_DETATCH;
    }

    if (HI_UNF_AVPLAY_Start(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] AUD HI_UNF_AVPLAY_Start failed.");
        goto AVPLAY_ASTOP;
    }


    m_audio_opend = true;
    m_audio_last_pts = INVALID_PTS_VALUE;

    return true;

AVPLAY_ASTOP:
    HI_UNF_AVPLAY_STOP_OPT_S Stop;
    Stop.u32TimeoutMs = 0;
    Stop.enMode = HI_UNF_AVPLAY_STOP_MODE_BLACK;
    HI_UNF_AVPLAY_Stop(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, &Stop);

TRACK_DETATCH:
    HI_UNF_SND_Detach(m_hTrack, m_hAvplay);

TRACK_DESTORY:
    HI_UNF_SND_DestroyTrack(m_hTrack);
    m_hTrack = 0;

ACHN_CLOSE:
    HI_UNF_AVPLAY_ChnClose(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD);

    return false;
}

bool eHISIDecoder::AudioStop()
{

    if(!m_hTrack)
        return false;

    if(!m_audio_opend)
        return false;

    HI_UNF_AVPLAY_STOP_OPT_S Stop;
    Stop.u32TimeoutMs = 0;
    Stop.enMode = HI_UNF_AVPLAY_STOP_MODE_BLACK;

    if (HI_UNF_AVPLAY_Stop(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, &Stop) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_AVPLAY_Stop");
        return false;
    }

    eDebug("[eHISIDecoder] CloseAudio, track %d", m_hTrack);
    if (HI_UNF_SND_Detach(m_hTrack, m_hAvplay) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_Detach AdecType exception");
        return false;
    }

    if (HI_UNF_SND_DestroyTrack(m_hTrack) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_DestroyTrack exception");
        return false;
    }

    m_hTrack = 0;

    if (HI_UNF_AVPLAY_ChnClose(m_hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD) != HI_SUCCESS)
    {
        eDebug("[eHISIDecoder] HI_UNF_SND_DestroyTrack exception");
        return false;
    }

    HI_UNF_SYNC_ATTR_S AvSyncAttr;
    HI_UNF_AVPLAY_GetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr);
    AvSyncAttr.enSyncRef = HI_UNF_SYNC_REF_NONE;
    HI_UNF_AVPLAY_SetAttr(m_hAvplay, HI_UNF_AVPLAY_ATTR_ID_SYNC, &AvSyncAttr);

    AudioReset();

    m_audio_opend = false;

    eDebug("[eHISIDecoder] CloseAudio Success");


    return true;
}

void eHISIDecoder::AudioReset()
{
    m_audio_last_pts = INVALID_PTS_VALUE;
    HI_UNF_AVPLAY_Reset(m_hAvplay, NULL);
    eDebug("[eHISIDecoder] AudioReset");
}

bool eHISIDecoder::AudioWrite(uint8_t* pData, size_t iSize, unsigned int pts_ms)
{

    if (!m_audio_opend)
        return false;

    HI_UNF_STREAM_BUF_S StreamBuf;
#ifdef USE_DMX
    if (HI_UNF_DMX_GetTSBuffer(g_TsBuf, iSize, &StreamBuf, 1000) != HI_SUCCESS)
#else
    if (HI_UNF_AVPLAY_GetBuf(m_hAvplay, HI_UNF_AVPLAY_BUF_ID_ES_AUD, iSize, &StreamBuf, 0) != HI_SUCCESS)
#endif
        return false;

    memcpy(StreamBuf.pu8Data, pData, iSize);

#ifdef USE_DMX
    if (HI_UNF_DMX_PutTSBuffer(g_TsBuf, iSize) != HI_SUCCESS)
#else
    if (HI_UNF_AVPLAY_PutBuf(m_hAvplay, HI_UNF_AVPLAY_BUF_ID_ES_AUD, iSize, pts_ms) != HI_SUCCESS)
#endif
        return false;

    return true;
}

bool eHISIDecoder::AudioFreeze()
{
    if (!m_audio_opend)
        return false;

    if (HI_UNF_AVPLAY_Pause(m_hAvplay, NULL) != HI_SUCCESS)
        return false;

    return true;
}
bool eHISIDecoder::AudioUnfreeze()
{
    if (!m_audio_opend)
        return false;

    if (HI_UNF_AVPLAY_Resume(m_hAvplay, NULL) != HI_SUCCESS)
        return false;

    return true;
}
bool eHISIDecoder::AudioFlush()
{
    if (!m_audio_opend)
        return false;
    /*
        HI_UNF_AVPLAY_FLUSH_STREAM_OPT_S stFlushOpt;
        HI_BOOL bIsEmpty = HI_FALSE;


        HI_UNF_AVPLAY_FlushStream(m_hAvplay, &stFlushOpt);
        do
        {
            if (HI_UNF_AVPLAY_IsBuffEmpty(m_hAvplay, &bIsEmpty) != HI_SUCCESS)
                break;
        }
        while(bIsEmpty != HI_TRUE);
    */
    return true;
}

int eHISIDecoder::AudioGetPTS(pts_t &now)
{
    if (!m_audio_opend)
        return -1;

    HI_UNF_AVPLAY_STATUS_INFO_S stStatusInfo;
    if(HI_UNF_AVPLAY_GetStatusInfo(m_hAvplay, &stStatusInfo) == HI_SUCCESS)
        now = stStatusInfo.stSyncStatus.u32LastAudPts;
    else
        now = 0;

    return now > 0 ? 0 : -1;
}

HI_S32 eHISIDecoder::EventReport(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_VOID* pPara)
{
    switch (enEvent)
    {

    case HI_UNF_AVPLAY_EVENT_NEW_VID_FRAME:
    {
        HI_UNF_VIDEO_FRAME_INFO_S* frame = (HI_UNF_VIDEO_FRAME_INFO_S*)pPara;

        if((hi_width <= 0) && (hi_height <= 0))
        {
            hi_width = frame->u32Width;
            hi_height = frame->u32Height;
            hi_progressive = frame->bProgressive;
            hi_framerate = frame->stFrameRate.u32fpsInteger;

            float aspect = hi_width/float(hi_height);
            // according to wikipedia, widescreen is when width to height is greater then 1.37:1
            if (aspect > 1.37)
            {
                // WIDESCREEN values from ServiceInfo.py: 3, 4, 7, 8, 0xB, 0xC, 0xF, 0x10
                hi_aspect = 3;
            }
            else
            {
                // 4:3 values from ServiceInfo.py: 1, 2, 5, 6, 9, 0xA, 0xD, 0xE
                hi_aspect = 1;
            }

            eDebug("[eHISIDecoder] Event Report width:%d height:%d aspect_ratio:%d frame_rate:%d progressive:%d",
                   hi_width, hi_height, hi_aspect, hi_framerate, hi_progressive);


        }
    }
    break;

    case HI_UNF_AVPLAY_EVENT_EOS:
    case HI_UNF_AVPLAY_EVENT_NEW_AUD_FRAME:
    case HI_UNF_AVPLAY_EVENT_VID_BUF_STATE:
    case HI_UNF_AVPLAY_EVENT_AUD_BUF_STATE:
    case HI_UNF_AVPLAY_EVENT_FIRST_FRAME_DISPLAYED:
    case HI_UNF_AVPLAY_EVENT_STATUS_REPORT:
        break;

    default:
        break;
    }

    return HI_SUCCESS;
}

HA_CODEC_ID_E eHISIDecoder::codec2adec(int enc)
{
    HA_CODEC_ID_E Acodec = HA_AUDIO_ID_MP3;
    char buf[0x20];
    HI_S32 fd;
    switch (enc)
    {
    case aLPCM:
        Acodec = HA_AUDIO_ID_PCM;
        eDebug("[eHISIDecoder] Audio codec PCM");
        break;
    case aMPEG:
        Acodec = HA_AUDIO_ID_MP3;
        eDebug("[eHISIDecoder] Audio codec MP3");
        break;
    case aAAC:
        Acodec = HA_AUDIO_ID_AAC;
        eDebug("[eHISIDecoder] Audio codec AAC");
        break;
    case aAC3:
        Acodec = HA_AUDIO_ID_CUSTOM_0;
        eDebug("[eHISIDecoder] Audio codec AC3");
        break;
    case aDTS:
        Acodec = HA_AUDIO_ID_CUSTOM_1;
        eDebug("[eHISIDecoder] Audio codec DTS");
        break;

    //case HI_FORMAT_AUDIO_AC4:
    //    return HA_AUDIO_ID_MS12_AC4;
    case aAC4:
        Acodec = HA_AUDIO_ID_MS12_AC4;
        eDebug("[eHISIDecoder] Audio codec AC4");
        break;

    case aDDP:
        Acodec = HA_AUDIO_ID_CUSTOM_0;
        eDebug("[eHISIDecoder] Audio codec DDP");
        break;

    default:
        break;
    }
    HI_UNF_SND_SetSpdifMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_SPDIF0, HI_UNF_SND_SPDIF_MODE_LPCM);
    HI_UNF_SND_SetHdmiMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_HDMI0, HI_UNF_SND_HDMI_MODE_LPCM);

    if ( Acodec == HA_AUDIO_ID_CUSTOM_0 )
    {
        fd = open("/proc/stb/audio/ac3", O_RDONLY);
        if ( fd > 0 )
        {
            memset(&buf[0], 0, 0x20);
            read(fd, &buf[0], 0x1F);
            close(fd);
            if ( strncmp(&buf[0], "passthrough", 0xB) == 0 )
            {
                Acodec = HA_AUDIO_ID_AC3PASSTHROUGH;
                HI_UNF_SND_SetHdmiMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_HDMI0, HI_UNF_SND_HDMI_MODE_RAW);
                HI_UNF_SND_SetSpdifMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_SPDIF0,  HI_UNF_SND_SPDIF_MODE_RAW);
                eDebug("[eHISIDecoder] ac3 passthrough");
            }
            else
            {
                eDebug("[eHISIDecoder] ac3 downmix");
            }
        }
    }
    else if ( Acodec == HA_AUDIO_ID_CUSTOM_1 )
    {
        fd = open("/proc/stb/audio/dts", O_RDONLY);
        if ( fd > 0 )
        {
            memset(&buf[0], 0, 0x20);
            read(fd, &buf[0], 0x1F);
            close(fd);
            if ( strncmp(&buf[0], "passthrough", 0xB) == 0 )
            {
                Acodec = HA_AUDIO_ID_DTSPASSTHROUGH;
                HI_UNF_SND_SetHdmiMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_HDMI0, HI_UNF_SND_HDMI_MODE_RAW);
                HI_UNF_SND_SetSpdifMode(HI_UNF_SND_0, HI_UNF_SND_OUTPUTPORT_SPDIF0,  HI_UNF_SND_SPDIF_MODE_RAW);
                eDebug("[eHISIDecoder] dts passthrough");
            }
            else
            {
                eDebug("[eHISIDecoder] dts downmix");
            }
        }
    }
    return Acodec;
}

HI_UNF_VCODEC_TYPE_E eHISIDecoder::codec2vdec(int enc)
{
    switch (enc)
    {
    case MPEG2:
        eDebug("[eHISIDecoder] Video codec MPEG2");
        return HI_UNF_VCODEC_TYPE_MPEG2;

    case MPEG4_Part2:
        eDebug("[eHISIDecoder] Video codec MPEG4");
        return HI_UNF_VCODEC_TYPE_MPEG4;

    case AVS:
        eDebug("[eHISIDecoder] Video codec AVS");
        return HI_UNF_VCODEC_TYPE_AVS;

    case MPEG4_H264:
        eDebug("[eHISIDecoder] Video codec H264");
        return HI_UNF_VCODEC_TYPE_H264;

    case VC1:
        eDebug("[eHISIDecoder] Video codec VC1");
        return HI_UNF_VCODEC_TYPE_VC1;

    case H265_HEVC:
        eDebug("[eHISIDecoder] Video codec H265_HEVC");
        return HI_UNF_VCODEC_TYPE_HEVC;

    default:
        break;
    }

    return HI_UNF_VCODEC_TYPE_BUTT;
}

eAutoInitPtr<eHISIDecoder> init_eHISIDecoder(eAutoInitNumbers::hisi, "HISIDecoder");

