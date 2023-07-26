#ifndef __hisi_decoder_h
#define __hisi_decoder_h

#include <lib/base/object.h>



extern "C"
{
#include "lib/hisi/HA.AUDIO.PCM.decode.h"
#include <lib/hisi/hi_audio_codec.h>
#include <lib/hisi/hi_type.h>
#include <lib/hisi/hi_unf_advca.h>
#include <lib/hisi/hi_unf_audio.h>
#include <lib/hisi/hi_unf_common.h>
#include <lib/hisi/hi_unf_disp.h>
#include <lib/hisi/hi_unf_otp.h>
#include <lib/hisi/hi_unf_video.h>
#include <lib/hisi/hi_unf_vo.h>
#include <lib/hisi/hi_unf_avplay.h>
} // extern "C"

#ifndef INVALID_PTS_VALUE
#define INVALID_PTS_VALUE                       0x200000000ull
#endif

#define PLAY_DMX_ID  (0)
#define USE_DMX 1

#ifndef pts_t
typedef long long pts_t;
#endif

class eHISIDecoder;


class eHISIDecoder: public iObject
{		
    DECLARE_REF(eHISIDecoder);
    static eHISIDecoder *instance;
private:
    enum { aMPEG, aAC3, aDTS, aAAC, aAACHE, aLPCM, aDTSHD, aDDP, aDRA, aAC4 };
    enum { UNKNOWN = -1, MPEG2, MPEG4_H264, VC1 = 3, MPEG4_Part2, VC1_SM, MPEG1, H265_HEVC, AVS = 16 };

    HI_HANDLE m_hAvplay;
    HI_HANDLE m_hWin;
    HI_HANDLE m_hTrack;

    bool m_opened;
    bool m_video_opend;
    bool m_audio_opend;
    int64_t m_audio_last_pts;
    int64_t m_video_last_pts;
    int hi_width, hi_height, hi_framerate, hi_aspect, hi_progressive;

    HI_HANDLE g_TsBuf;

protected:
    bool Init();
    bool Deinit();
public:

    static eHISIDecoder* GetInstance(){ return instance; };

    eHISIDecoder();
    virtual ~eHISIDecoder();

    bool VideoStartPid(HI_U32 VidPid, HI_U32 codec_id);
    bool VideoStop();
    void VideoReset();
    bool VideoWrite(uint8_t* pData, size_t iSize, unsigned int pts_ms);
    bool VideoFreeze();
    bool VideoUnfreeze();
    bool VideoFlush();  
    int VideoGetPTS(pts_t &now); 
    int getVideoWidth() { return hi_width; }
    int getVideoHeight(){ return hi_height; }
    int getVideoProgressive(){ return hi_progressive; }
    int getVideoFrameRate() { return hi_framerate; }
    int getVideoAspect() { return hi_aspect; }     

    bool AudioStartPid(HI_U32 AudPid, HI_U32 codec_id);
    bool AudioStop();
    void AudioReset();
    bool AudioWrite(uint8_t* pData, size_t iSize, unsigned int pts_ms);
    bool AudioFreeze();
    bool AudioUnfreeze();
    bool AudioFlush();
    int AudioGetPTS(pts_t &now);

    HI_S32 EventReport(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_VOID* pPara);
    HA_CODEC_ID_E codec2adec(int enc);
    HI_UNF_VCODEC_TYPE_E codec2vdec(int enc);

};



#endif