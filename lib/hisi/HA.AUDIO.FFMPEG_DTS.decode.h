/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
 File Name     : HA.AUDIO.FFMPEG_DTS.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       :
 Last Modified :
 Description   :
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_FFMPEG_DTS_DECODE_H__
#define __HISI_AUDIO_DECODER_FFMPEG_DTS_DECODE_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define HA_FFMPEG_DTS_ID 0x0340     
#define HA_CODEC_SET_DTS_DOWNMIX_INFO_CMD  	((((HI_U32)HA_FFMPEG_DTS_ID) << 16) | 0x1000)

typedef struct hiFFMPEG_DTS_DownmixInfo_S {
    /**
     * Type of downmix preferred by the mastering engineer.
     */
	int preferred_downmix_type;

    /**
     * Absolute scale factor representing the nominal level of the center
     * channel during a regular downmix.
     */
	double center_mix_level;

    /**
     * Absolute scale factor representing the nominal level of the center
     * channel during an Lt/Rt compatible downmix.
     */
	double center_mix_level_ltrt;

    /**
     * Absolute scale factor representing the nominal level of the surround
     * channels during a regular downmix.
     */
	double surround_mix_level;

    /**
     * Absolute scale factor representing the nominal level of the surround
     * channels during an Lt/Rt compatible downmix.
     */
	double surround_mix_level_ltrt;

    /**
     * Absolute scale factor representing the level at which the LFE data is
     * mixed into L/R channels during downmixing.
     */
	double lfe_mix_level;
}FFMPEG_DTS_DownmixInfo_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_DTS_DOWNMIX_INFO_CMD */
	FFMPEG_DTS_DownmixInfo_S* peDTSDownmixInfo;
} HA_FFMPEG_DTS_DOWNMIX_INFO_S;

/**define the type of callback function*/ /**CNcomment:\CA¼\FE\BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD*/
typedef enum
{
	HA_FFMPEG_DTS_EVENT_STATUS_CHANGE = 0,                   /**<update status information by every frame*/ /**<CNcomment:״̬\D0\C5Ϣ\B8\FC\D0\C2, ÿ֡\B8\FC\D0\C2һ\B4\CE*/
	HA_FFMPEG_DTS_EVENT_BUTT
} HA_FFMPEG_DTS_EVENT_E;

/**define callback function*/ /**CNcomment:\B6\A8\D2\E5\CA¼\FE\BBص\F7\BA\AF\CA\FDö\BE\D9\C0\E0\D0\CD*/
typedef HI_VOID (*FFMPEG_DTS_EVENT_CB_FN)(HI_VOID* pAppData1, HI_VOID* pAppData2, HA_FFMPEG_DTS_EVENT_E enEvent);

typedef struct  hiHA_FFMPEG_DTS_DECODE_OPENCONFIG_S
{
	HI_VOID *               hAvCtx; /* Same as libavcodec AVCodecContext, Set/allocated/freed by user. */
	HI_BOOL                 bAutoDmxStereo; /* automatic downmix multi-ch to stereo. */
	HI_BOOL                 bConvert2fmt16bit; /* automatic convert none-16bit pcm to 16bit pcm. */
	FFMPEG_DTS_EVENT_CB_FN      pfnEvtCbFunc[HA_FFMPEG_DTS_EVENT_BUTT];    /* call back method */
	HI_VOID*                pAppData1[HA_FFMPEG_DTS_EVENT_BUTT];       /* application handle,   Set/allocated/freed by user. */
	HI_VOID*                pAppData2[HA_FFMPEG_DTS_EVENT_BUTT];       /* application defined value for call back method,  allocated/freed by user, set by ha_codec,*/
} HA_FFMPEG_DTS_DECODE_OPENCONFIG_S;

#define FFMPEDTS_DecGetDefalutOpenConfig(pConfigParam) \
    do { \
		((HA_FFMPEG_DTS_DECODE_OPENCONFIG_S *)(pConfigParam))->bAutoDmxStereo = HI_TRUE; \
		((HA_FFMPEG_DTS_DECODE_OPENCONFIG_S *)(pConfigParam))->bConvert2fmt16bit = HI_TRUE; \
    } while (0)

#define HA_FFMPEDTS_DecGetDefalutOpenParam_Config(pOpenParam, pFfmpegDTSConfig) \
    do { 	HI_S32 i; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_RAWPCM; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 2; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved = HI_TRUE; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 16; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
		for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
		{ \
			((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
		} \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = pFfmpegDTSConfig; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = sizeof(HA_FFMPEG_DTS_DECODE_OPENCONFIG_S); \
		for (i = 0; i < HA_FFMPEG_DTS_EVENT_BUTT; i++) \
		{ \
			((HA_FFMPEG_DTS_DECODE_OPENCONFIG_S *)(pFfmpegDTSConfig))->pfnEvtCbFunc[i] = HI_NULL; \
			((HA_FFMPEG_DTS_DECODE_OPENCONFIG_S *)(pFfmpegDTSConfig))->pAppData1[i] = HI_NULL; \
			((HA_FFMPEG_DTS_DECODE_OPENCONFIG_S *)(pFfmpegDTSConfig))->pAppData2[i] = HI_NULL; \
		} \
    } while (0)

#define HA_FFMPEDTS_DecGetDefalutOpenParam(pOpenParam) \
            do {    HI_S32 i; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_RAWPCM; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 2; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved = HI_TRUE; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 16; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
                for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
                { \
                    ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
                } \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = NULL; \
                ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = 0; \
            } while (0)

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HISI_AUDIO_DECODER_FFMPEG_DTS_DECODE_H__ */
