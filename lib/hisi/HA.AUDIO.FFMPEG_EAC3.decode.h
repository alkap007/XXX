/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
 File Name     : HA.AUDIO.FFMPEG_EAC3.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       :
 Last Modified :
 Description   :
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_FFMPEG_EAC3_DECODE_H__
#define __HISI_AUDIO_DECODER_FFMPEG_EAC3_DECODE_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define HA_FFMPEG_EAC3_ID 0x0320     
#define HA_CODEC_SET_EAC3_DEC_CONTEXT_CMD  		((((HI_U32)HA_FFMPEG_EAC3_ID) << 16) | 0x1000)
#define HA_CODEC_SET_EAC3_DOWNMIX_INFO_CMD  	((((HI_U32)HA_FFMPEG_EAC3_ID) << 16) | 0x1001)
#define HA_CODEC_SET_EAC3_CLEAR_CMD  			((((HI_U32)HA_FFMPEG_EAC3_ID) << 16) | 0x1003)

/**define status parameter of update information*/ /**CNcomment:״̬\D0\C5Ϣ\B8\FC\D0£\AC\CA¼\FE\BBص\F7\D3û\A7\CA\FD\BEݶ\A8\D2\E5*/
typedef struct hiFFMPEG_EAC3_DecodeContext_S {
	int frame_type;                         ///< frame type                             (strmtyp)
	int substreamid;                        ///< substream identification
	int frame_size;                         ///< current frame size, in bytes
	int bit_rate;                           ///< stream bit rate, in bits-per-second
	int sample_rate;                        ///< sample frequency, in Hz
	int num_blocks;                         ///< number of audio blocks
	int bitstream_id;                       ///< bitstream id                           (bsid)
	int bitstream_mode;                     ///< bitstream mode                         (bsmod)
	int channel_mode;                       ///< channel mode                           (acmod)
	int lfe_on;                             ///< lfe channel in use
	int dialog_normalization[2];            ///< dialog level in dBFS                   (dialnorm)
	int compression_exists[2];              ///< compression field is valid for frame   (compre)
	int compression_gain[2];                ///< gain to apply for heavy compression    (compr)
	int channel_map;                        ///< custom channel map
	int preferred_downmix;                  ///< Preferred 2-channel downmix mode       (dmixmod)
	int center_mix_level;                   ///< Center mix level index
	int center_mix_level_ltrt;              ///< Center mix level index for Lt/Rt       (ltrtcmixlev)
	int surround_mix_level;                 ///< Surround mix level index
	int surround_mix_level_ltrt;            ///< Surround mix level index for Lt/Rt     (ltrtsurmixlev)
	int lfe_mix_level_exists;               ///< indicates if lfemixlevcod is specified (lfemixlevcode)
	int lfe_mix_level;                      ///< LFE mix level index                    (lfemixlevcod)
	int eac3;                               ///< indicates if current frame is E-AC-3
	int eac3_frame_dependent_found;         ///< bitstream has E-AC-3 dependent frame(s)
	int eac3_subsbtreamid_found;            ///< bitstream has E-AC-3 additional substream(s)
	int dolby_surround_mode;                ///< dolby surround mode                    (dsurmod)
	int dolby_surround_ex_mode;             ///< dolby surround ex mode                 (dsurexmod)
	int dolby_headphone_mode;               ///< dolby headphone mode                   (dheadphonmod)

	int snr_offset_strategy;                ///< SNR offset strategy                    (snroffststr)
	int block_switch_syntax;                ///< block switch syntax enabled            (blkswe)
	int dither_flag_syntax;                 ///< dither flag syntax enabled             (dithflage)
	int bit_allocation_syntax;              ///< bit allocation model syntax enabled    (bamode)
	int fast_gain_syntax;                   ///< fast gain codes enabled                (frmfgaincode)
	int dba_syntax;                         ///< delta bit allocation syntax enabled    (dbaflde)
	int skip_syntax;                        ///< skip field syntax enabled              (skipflde)

	int fbw_channels;                           ///< number of full-bandwidth channels
	int channels;                               ///< number of total channels
	int lfe_ch;                                 ///< index of LFE channel
	int16_t *downmix_coeffs[2];              ///< stereo downmix coefficients
	int downmixed;                              ///< indicates if coeffs are currently downmixed
	int output_mode;                            ///< output channel configuration
	int out_channels;                           ///< number of output channels
}FFMPEG_EAC3_DecodeContext_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_EAC3_DEC_CONTEXT_CMD */
	FFMPEG_EAC3_DecodeContext_S* peEAc3DecodeContext;
} HA_FFMPEG_EAC3_DEC_CONTEXT_S;

typedef struct hiFFMPEG_EAC3_DownmixInfo_S {
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
}FFMPEG_EAC3_DownmixInfo_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_EAC3_DOWNMIX_INFO_CMD */
	FFMPEG_EAC3_DownmixInfo_S* peEAc3DownmixInfo;
} HA_FFMPEG_EAC3_DOWNMIX_INFO_S;

typedef struct
{
	HI_U32  enCmd;              /* HA_CODEC_SET_EAC3_CLEAR_CMD */
	void* Null;
} HA_FFMPEG_EAC3_CLEAR_S;

/**define the type of callback function*/ /**CNcomment:\CA¼\FE\BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD*/
typedef enum
{
	HA_FFMPEG_EAC3_EVENT_STATUS_CHANGE = 0,                   /**<update status information by every frame*/ /**<CNcomment:״̬\D0\C5Ϣ\B8\FC\D0\C2, ÿ֡\B8\FC\D0\C2һ\B4\CE*/
	HA_FFMPEG_EAC3_EVENT_BUTT
} HA_FFMPEG_EAC3_EVENT_E;

/**define callback function*/ /**CNcomment:\B6\A8\D2\E5\CA¼\FE\BBص\F7\BA\AF\CA\FDö\BE\D9\C0\E0\D0\CD*/
typedef HI_VOID (*FFMPEG_EAC3_EVENT_CB_FN)(HI_VOID* pAppData1, HI_VOID* pAppData2, HA_FFMPEG_EAC3_EVENT_E enEvent);

typedef struct  hiHA_FFMPEG_EAC3_DECODE_OPENCONFIG_S
{
	HI_VOID *               hAvCtx; /* Same as libavcodec AVCodecContext, Set/allocated/freed by user. */
	HI_BOOL                 bAutoDmxStereo; /* automatic downmix multi-ch to stereo. */
	HI_BOOL                 bConvert2fmt16bit; /* automatic convert none-16bit pcm to 16bit pcm. */
	FFMPEG_EAC3_EVENT_CB_FN      pfnEvtCbFunc[HA_FFMPEG_EAC3_EVENT_BUTT];    /* call back method */
	HI_VOID*                pAppData1[HA_FFMPEG_EAC3_EVENT_BUTT];       /* application handle,   Set/allocated/freed by user. */
	HI_VOID*                pAppData2[HA_FFMPEG_EAC3_EVENT_BUTT];       /* application defined value for call back method,  allocated/freed by user, set by ha_codec,*/
} HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S;

#define FFMPEEAC3_DecGetDefalutOpenConfig(pConfigParam) \
    do { \
		((HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S *)(pConfigParam))->bAutoDmxStereo = HI_TRUE; \
		((HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S *)(pConfigParam))->bConvert2fmt16bit = HI_TRUE; \
    } while (0)

#define HA_FFMPEEAC3_DecGetDefalutOpenParam_Config(pOpenParam, pFfmpegEAc3Config) \
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
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = pFfmpegEAc3Config; \
		((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = sizeof(HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S); \
		for (i = 0; i < HA_FFMPEG_EAC3_EVENT_BUTT; i++) \
		{ \
			((HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S *)(pFfmpegEAc3Config))->pfnEvtCbFunc[i] = HI_NULL; \
			((HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S *)(pFfmpegEAc3Config))->pAppData1[i] = HI_NULL; \
			((HA_FFMPEG_EAC3_DECODE_OPENCONFIG_S *)(pFfmpegEAc3Config))->pAppData2[i] = HI_NULL; \
		} \
    } while (0)

#define HA_FFMPEEAC3_DecGetDefalutOpenParam(pOpenParam) \
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

#endif /* __HISI_AUDIO_DECODER_FFMPEG_EAC3_DECODE_H__ */
