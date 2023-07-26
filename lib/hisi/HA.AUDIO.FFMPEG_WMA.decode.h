/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
 File Name     : HA.AUDIO.FFMPEG_WMA.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       :
 Last Modified :
 Description   :
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_FFMPEG_WMA_DECODE_H__
#define __HISI_AUDIO_DECODER_FFMPEG_WMA_DECODE_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define HA_FFMPEG_WMA_ID 0x0300        
#define HA_CODEC_SET_WMA_INFO_CMD  ((((HI_U32)HA_FFMPEG_WMA_ID) << 16) | 0x1000)
#define HA_CODEC_SET_WMA_CLEAR_CMD  ((((HI_U32)HA_FFMPEG_WMA_ID) << 16) | 0x1001)

/**define status parameter of update information*/ /**CNcomment:״̬\D0\C5Ϣ\B8\FC\D0£\AC\CA¼\FE\BBص\F7\D3û\A7\CA\FD\BEݶ\A8\D2\E5*/
typedef struct  hiFFMPEG_WMA_INFO_S
{
	HI_S32  wma_version;
	HI_S32  codec_id;
	HI_S32  codec_type;
	HI_S32  codec_tag;
	HI_S32  sample_fmt;
	HI_S32  channels;
	HI_S32  sample_rate;
	HI_S32  bit_rate;
	HI_S32  block_align;
	HI_S32  word_size;
	HI_UCHAR extradata[1024];
	HI_S32 extradata_size;
} FFMPEG_WMA_INFO_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_WMA_INFO_CMD */
	FFMPEG_WMA_INFO_S* peWmaInfo;
} HA_FFMPEG_WMA_INFO_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_WMA_CLEAR_CMD */
	void* Null;
} HA_FFMPEG_WMA_CLEAR_S;

/**define the type of callback function*/ /**CNcomment:\CA¼\FE\BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD*/
typedef enum
{
	HA_FFMPEG_WMA_EVENT_STATUS_CHANGE = 0,                   /**<update status information by every frame*/ /**<CNcomment:״̬\D0\C5Ϣ\B8\FC\D0\C2, ÿ֡\B8\FC\D0\C2һ\B4\CE*/
	HA_FFMPEG_WMA_EVENT_BUTT
} HA_FFMPEG_WMA_EVENT_E;

/**define callback function*/ /**CNcomment:\B6\A8\D2\E5\CA¼\FE\BBص\F7\BA\AF\CA\FDö\BE\D9\C0\E0\D0\CD*/
typedef HI_VOID (*FFMPEG_WMA_EVENT_CB_FN)(HI_VOID* pAppData1, HI_VOID* pAppData2, HA_FFMPEG_WMA_EVENT_E enEvent);

typedef struct  hiHA_FFMPEG_WMA_DECODE_OPENCONFIG_S
{
	HI_VOID *               hAvCtx; /* Same as libavcodec AVCodecContext, Set/allocated/freed by user. */
	HI_BOOL                 bAutoDmxStereo; /* automatic downmix multi-ch to stereo. */
	HI_BOOL                 bConvert2fmt16bit; /* automatic convert none-16bit pcm to 16bit pcm. */
	FFMPEG_WMA_EVENT_CB_FN      pfnEvtCbFunc[HA_FFMPEG_WMA_EVENT_BUTT];    /* call back method */
	HI_VOID*                pAppData1[HA_FFMPEG_WMA_EVENT_BUTT];       /* application handle,   Set/allocated/freed by user. */
	HI_VOID*                pAppData2[HA_FFMPEG_WMA_EVENT_BUTT];       /* application defined value for call back method,  allocated/freed by user, set by ha_codec,*/
} HA_FFMPEG_WMA_DECODE_OPENCONFIG_S;

#define FFMPEWMA_DecGetDefalutOpenConfig(pConfigParam) \
    do { \
		((HA_FFMPEG_WMA_DECODE_OPENCONFIG_S *)(pConfigParam))->bAutoDmxStereo = HI_TRUE; \
		((HA_FFMPEG_WMA_DECODE_OPENCONFIG_S *)(pConfigParam))->bConvert2fmt16bit = HI_TRUE; \
    } while (0)

#define HA_FFMPEWMA_DecGetDefalutOpenParam_Config(pOpenParam, pFfmpegWmaConfig) \
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
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = pFfmpegWmaConfig; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = sizeof(HA_FFMPEG_WMA_DECODE_OPENCONFIG_S); \
		for (i = 0; i < HA_FFMPEG_WMA_EVENT_BUTT; i++) \
		{ \
			((HA_FFMPEG_WMA_DECODE_OPENCONFIG_S *)(pFfmpegWmaConfig))->pfnEvtCbFunc[i] = HI_NULL; \
			((HA_FFMPEG_WMA_DECODE_OPENCONFIG_S *)(pFfmpegWmaConfig))->pAppData1[i] = HI_NULL; \
			((HA_FFMPEG_WMA_DECODE_OPENCONFIG_S *)(pFfmpegWmaConfig))->pAppData2[i] = HI_NULL; \
		} \
    } while (0)

#define HA_FFMPEWMA_DecGetDefalutOpenParam(pOpenParam) \
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

#endif /* __HISI_AUDIO_DECODER_FFMPEG_WMA_DECODE_H__ */
