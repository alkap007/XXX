/******************************************************************************
Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_audio_codec.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2009/11/01
Last Modified :
Description   : define audio common data structure
  History       :
  1.Date        : 2009/11/10
    Author      : zgjie
    Modification: Created file
******************************************************************************/

/**
 * \file
 * \brief Describes the information about the audio codec. CNcomment:\CCṩAUDIO_CODEC\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef __HI_AUDIO_CODEC_H__
#define __HI_AUDIO_CODEC_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**Define HA codec Print Level*/
/**CNcomment:\B6\A8\D2\E5HA codec\B4\F2ӡ\BC\B6\B1\F0*/
#define HA_TRACE_LEVEL_FATAL    (0)
#define HA_TRACE_LEVEL_ERROR    (1)
#define HA_TRACE_LEVEL_WARN     (2)
#define HA_TRACE_LEVEL_INFO     (3)
#define HA_TRACE_LEVEL_DBG      (4)


#ifndef HI_ADVCA_FUNCTION_RELEASE

#ifndef CFG_HA_LOG_LEVEL
#define CFG_HA_LOG_LEVEL         (HA_TRACE_LEVEL_ERROR)
#endif

#if (CFG_HA_LOG_LEVEL == HA_TRACE_LEVEL_FATAL)
#define HA_FATAL_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_ERR_PRINT(fmt...)
#define HA_WARN_PRINT(fmt...)
#define HA_INFO_PRIN(fmt...)
#define HA_DBG_PRINT(fmt...)

#elif (CFG_HA_LOG_LEVEL == HA_TRACE_LEVEL_ERROR)
#define HA_FATAL_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_ERR_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_WARN_PRIN(fmt...)
#define HA_INFO_PRIN(fmt...)
#define HA_DBG_PRINT(fmt...)

#elif(CFG_HA_LOG_LEVEL == HA_TRACE_LEVEL_WARN)
#define HA_FATAL_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_ERR_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_WARN_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_INFO_PRINT(fmt...)
#define HA_DBG_PRINT(fmt...)

#elif(CFG_HA_LOG_LEVEL == HA_TRACE_LEVEL_INFO)
#define HA_FATAL_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_ERR_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_WARN_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_INFO_PRINT(fmt...)    do{printf(fmt);}while(0)
#define HA_DBG_PRINT(fmt...)

#elif(CFG_HA_LOG_LEVEL == HA_TRACE_LEVEL_DBG)

#define HA_FATAL_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_ERR_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_WARN_PRINT(fmt...)   do{printf(fmt);}while(0)
#define HA_INFO_PRINT(fmt...)    do{printf(fmt);}while(0)
#define HA_DBG_PRINT(fmt...)     do{printf(fmt);}while(0)

#endif

#else

#define HA_FATAL_PRINT(fmt...)
#define HA_ERR_PRINT(fmt...)
#define HA_WARN_PRINT(fmt...)
#define HA_INFO_PRIN(fmt...)
#define HA_DBG_PRINT(fmt...)

#endif

/**Define software dual decode*/
/**CNcomment:\B6\A8\D2\E5\C8\ED\BD\E2˫·\BD\E2\C2\EB*/
#define HA_SW_DUALDEC_SUPPORT

/**Define HA codec ID*/
/**CNcomment:\B6\A8\D2\E5HA codec ID*/
/*
*                HA CODEC_ID defination
*   |      7bit                9bit                3bit                   13bit  |
*   |---vendor---|---format---|---reserved---|---id---|
*/
#define VENDOR_HISI 0x040
#define VENDOR_NONE 0x010
#define HA_VENDOR_OFFSETK  25 /* (32-7) */
#define HA_VENDOR_MASK     (0x007fUL << HA_VENDOR_OFFSETK)
#define HA_FORMAT_OFFSETK  16 /* (32-7-9) */
#define HA_FORMAT_MASK     (0x01ffUL << HA_FORMAT_OFFSETK)
#define HA_RESERVED_OFFSET 13 /* (32-7-9-3) */
#define HA_RESERVED_MASK   (0x007UL << HA_RESERVED_OFFSET)
#define HA_ID_OFFSET       0 /* (32-7-9-3-13) */
#define HA_ID_MASK         (0x1fffUL<< HA_ID_OFFSET)

#define HA_BUILD_CODEC_ID(vendor, format, id) (((((HI_U32)vendor) << HA_VENDOR_OFFSETK) & HA_VENDOR_MASK) | ((((HI_U32)format) << HA_FORMAT_OFFSETK) & HA_FORMAT_MASK) | (((HI_U32)id) & HA_ID_MASK))
#define HA_GET_VENDOR(codec) ((HI_U32)(codec&HA_VENDOR_MASK)>>HA_VENDOR_OFFSETK)
#define HA_GET_FORMAT(codec) ((HI_U32)(codec&HA_FORMAT_MASK)>>HA_FORMAT_OFFSETK)
#define HA_GET_ID(codec)     ((HI_U32)(codec&HA_ID_MASK)>>HA_ID_OFFSET)

/********************************Macro Definition********************************/
/** \addtogroup      ACODEC */
/** @{ */  /** <!-- \A1\BEACODEC\A1\BF */

/**Define HA codec common command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec \B9\AB\B9\B2CMD ID*/
#define HA_COMMON_CMD_ID   0xffff

/**Define HA codec format query command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec \B8\F1ʽ\B2\E9ѯCMD ID*/
#define HA_CODEC_FORMAT_QUERY_CMD         ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1000)

/**Define HA codec decoder open parameter command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec \BD\E2\C2\EB\C6\F7\B4򿪲\CE\CA\FDCMD ID*/
#define HA_CODEC_GET_DECOPENPARAM_CMD     ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1001)

/**Define HA codec encoder open parameter command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec \B1\E0\C2\EB\C6\F7\B4򿪲\CE\CA\FDCMD ID*/
#define HA_CODEC_GET_ENCOPENPARAM_CMD     ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1002)

/**Define HA codec packet query command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec packet\BD\E2\C2\EBģʽCMD ID*/
#define HA_CODEC_PACKETDECODER_QUERY_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1003)

/**Define HA codec hwdecode query command ID*/
/**CNcomment:\B6\A8\D2\E5HA codec hwdecode\BD\E2\C2\EBģʽCMD ID*/
#define HA_CODEC_HARDWARECODEC_QUERY_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1004)

/**Define HA codec set outbuf addr command ID  only for hardware codec*/
/**CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6Buffer\B5\D8ַ\C9\E8\D6\C3CMD ID*/
#define HA_CODEC_OUTBUFADDR_SET_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1005)

/**Define dual decode capability support query command ID*/
/**CNcomment:\B6\A8\D2\E5˫·\BD\E2\C2\EB\C4\DC\C1\A6\B2\E9ѯCMD ID*/
#define HA_CODEC_DUAL_DECODE_QUERY_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1006)

/**Define dual decode set ad output mode command ID*/
/**CNcomment:\B6\A8\D2\E5˫·\BD\E2\C2\EBAD\CA\E4\B3\F6ģʽ\C9\E8\D6\C3CMD ID*/
#define HA_CODEC_AD_OUTPUTMODE_SET_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1007)

/**Define AD Balance Setting command ID*/
/**CNcomment:\B6\A8\D2\E5AD Ȩ\D6\D8\C9\E8\D6\C3CMD ID*/
#define HA_CODEC_AD_BALANCE_SET_CMD     ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1008)

/**Define PTS Delay command ID*/
/**CNcomment:\B6\A8\D2\E5PTS Delay CMD ID*/
#define HA_CODEC_PTS_DELAY_SET_CMD      ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x1009)

/**Define HA codec set whether work in compress mode command ID */
/**CNcomment:\B6\A8\D2\E5\CAǷ\F1\B9\A4\D7\F7\D3\DA\D4\DA\CF\DFѹ\CB\F5ģʽ\C9\E8\D6\C3CMD ID*/
#define HA_CODEC_COMPRESSMODE_SET_CMD ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x100A)

/**Define HA codec get codec output delay ms*/
/**CNcomment:\B6\A8\D2\E5\BB\F1ȡ\BD\E2\C2\EB\C6\F7\CA\E4\B3\F6\D1\D3ʱCMD ID*/
#define HA_CODEC_OUTPUTDELAY_GET_CMD  ((((HI_U32)HA_COMMON_CMD_ID) << 16) | 0x100B)

/**Define HA codec maximum audio channel*/
/**CNcomment:\B6\A8\D2\E5HA codec \D7\EE\B4\F3\D2\F4Ƶͨ\B5\C0 */
#define HA_AUDIO_MAXCHANNELS 8
/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      ACODEC */
/** @{ */  /** <!--  \A1\BEACODEC\A1\BF */

/**HA format definition*/
/**CNcomment:HA format \B6\A8\D2\E5*/
typedef enum hiHA_FORMAT_E
{
    FORMAT_MP2 = 0x000,  /**<MPEG audio layer 1, 2.*/ /**<CNcomment:MPEG\D2\F4Ƶ\B5\DAһ\B2㡢\B5ڶ\FE\B2\E3 */
    FORMAT_MP3, /**<MPEG audio layer 1, 2, 3.*/ /**<CNcomment:MPEG\D2\F4Ƶ\B5\DAһ\B2㡢\B5ڶ\FE\B2\E3 \A1\A2\B5\DA\C8\FD\B2\E3*/
    FORMAT_AAC,
    FORMAT_AC3,
    FORMAT_DTS,
    FORMAT_VORBIS,
    FORMAT_DVAUDIO,
    FORMAT_WMAV1,
    FORMAT_WMAV2,
    FORMAT_MACE3,
    FORMAT_MACE6,
    FORMAT_VMDAUDIO,
    FORMAT_SONIC,
    FORMAT_SONIC_LS,
    FORMAT_FLAC,
    FORMAT_MP3ADU,
    FORMAT_MP3ON4,
    FORMAT_SHORTEN,
    FORMAT_ALAC,
    FORMAT_WESTWOOD_SND1,
    FORMAT_GSM,
    FORMAT_QDM2,
    FORMAT_COOK,
    FORMAT_TRUESPEECH,
    FORMAT_TTA,
    FORMAT_SMACKAUDIO,
    FORMAT_QCELP,
    FORMAT_WAVPACK,
    FORMAT_DSICINAUDIO,
    FORMAT_IMC,
    FORMAT_MUSEPACK7,
    FORMAT_MLP,
    FORMAT_GSM_MS, /**<as found in WAV.*/ /**<CNcomment:\B4\E6\D4\DAWAV\B8\F1ʽ\D6\D0 */
    FORMAT_ATRAC3,
    FORMAT_VOXWARE,
    FORMAT_APE,
    FORMAT_NELLYMOSER,
    FORMAT_MUSEPACK8,
    FORMAT_SPEEX,
    FORMAT_WMAVOICE,
    FORMAT_WMAPRO,
    FORMAT_WMALOSSLESS,
    FORMAT_ATRAC3P,
    FORMAT_EAC3,
    FORMAT_SIPR,
    FORMAT_MP1,
    FORMAT_TWINVQ,
    FORMAT_TRUEHD,
    FORMAT_MP4ALS,
    FORMAT_ATRAC1,
    FORMAT_BINKAUDIO_RDFT,
    FORMAT_BINKAUDIO_DCT,
    FORMAT_DRA,

    FORMAT_PCM = 0x100,/**<various PCM codecs.*/ /**<CNcomment:PCM\B8\F1ʽ */
    FORMAT_PCM_BLURAY = 0x121,

    FORMAT_ADPCM = 0x130,/**<various ADPCM codecs.*/ /**<CNcomment:ADPCM\B8\F1ʽ */

    FORMAT_AMR_NB = 0x160,/**<various AMR codecs.*/ /**<CNcomment:AMR\B8\F1ʽ */
    FORMAT_AMR_WB,
    FORMAT_AMR_AWB,

    FORMAT_RA_144 = 0x170,/**<RealAudio codecs.*/ /**<CNcomment:RealAudio\B8\F1ʽ */
    FORMAT_RA_288,

    FORMAT_DPCM = 0x180,/**<various DPCM codecs.*/ /**<CNcomment:DPCM\B8\F1ʽ */

    FORMAT_G711 = 0x190,/**<various G.7xx codecs.*/ /**<CNcomment:G.7xx\B8\F1ʽ */
    FORMAT_G722,
    FORMAT_G7231,
    FORMAT_G726,
    FORMAT_G728,
    FORMAT_G729AB,

    FORMAT_OPUS = 0x1a0,

    FORMAT_MULTI = 0x1f0,/**<support multi codecs.*/ /**<CNcomment:\B6\E0\D6ָ\F1ʽ */
/*ZHTQ ADD*/
	FORMAT_MULTI_TRUEHD = 0x1f6,
	FORMAT_MULTI_LPCM = 0x1f7,
	FORMAT_MULTI_WMA = 0x1f8,
	FORMAT_MULTI_WMAPRO = 0x1f9,
    FORMAT_BUTT = 0x1ff,
} HA_FORMAT_E;

/**HA format definition*/
/**CNcomment:HA_Codec\B6\A8\D2\E5*/
typedef enum hiHA_CODEC_ID_E
{
    /** HISI Codec*/
    HA_AUDIO_ID_PCM             = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_PCM, 0x0000),
    HA_AUDIO_ID_MP2             = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MP2, 0x0002),
    HA_AUDIO_ID_MP3             = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x0003),
    HA_AUDIO_ID_AAC             = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_AAC, 0x001),
    HA_AUDIO_ID_BLYRAYLPCM      = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_PCM_BLURAY, 0x021),
    HA_AUDIO_ID_COOK            = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_COOK, 0x0009),
    HA_AUDIO_ID_DRA             = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_DRA, 0x007),
    HA_AUDIO_ID_WMA9STD         = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x0006),
    HA_AUDIO_ID_AMRNB           = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_AMR_NB, 0x0100),
    HA_AUDIO_ID_AMRWB           = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_AMR_WB, 0x0110),
    HA_AUDIO_ID_G711            = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_G711, 0x0102),
    HA_AUDIO_ID_G722            = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_G722, 0x0105),
    HA_AUDIO_ID_G726            = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_G726, 0x0106),
    HA_AUDIO_ID_ADPCM           = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_ADPCM, 0x0107),
    HA_AUDIO_ID_VOICE           = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x0108),
    HA_AUDIO_ID_TRUEHD          = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_TRUEHD, 0x0008),
    HA_AUDIO_ID_AC3PASSTHROUGH  = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI, 0x0055),
    HA_AUDIO_ID_DTSPASSTHROUGH  = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_DTS, 0x1025),
    HA_AUDIO_ID_OPUS            = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_OPUS, 0x1006),
    HA_AUDIO_ID_VORBIS          = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_VORBIS, 0x1007),

    /** DOLBY/DTS IPR Codec*/
    HA_AUDIO_ID_DOLBY_PLUS      = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI, 0x1010),
    HA_AUDIO_ID_DOLBY_TRUEHD    = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_TRUEHD, 0x1011),
    HA_AUDIO_ID_MS12_DDP        = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x1012),
    HA_AUDIO_ID_MS12_AAC        = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x1013),
    HA_AUDIO_ID_MS12_AC4        = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_MULTI, 0x1014),
    HA_AUDIO_ID_DTSHD           = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_DTS, 0x1020),
    HA_AUDIO_ID_DTSM6           = HA_BUILD_CODEC_ID(VENDOR_NONE, FORMAT_DTS, 0x1030),

    /** FFMPEG Codec*/
    HA_AUDIO_ID_FFMPEG_DECODE   = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI,  0x03ff),
    HA_AUDIO_ID_FFMPEG_WMAPRO   = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_WMAPRO, 0x041f),

    /** CUSTOMER Codec*/
    HA_AUDIO_ID_CUSTOM_0        = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI, 0x0400),
    HA_AUDIO_ID_CUSTOM_1        = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI, 0x0401),
/*ZHTQ ADD*/	
	HA_AUDIO_ID_CUSTOM_2        = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI, 0x0402),
	HA_AUDIO_ID_CUSTOM_3        = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI_TRUEHD, 0x0403),
	HA_AUDIO_ID_CUSTOM_4        = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI_LPCM, 0x0404),
	HA_AUDIO_ID_CUSTOM_5	  = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI_WMA, 0x0405),
	HA_AUDIO_ID_CUSTOM_6	  = HA_BUILD_CODEC_ID(VENDOR_HISI, FORMAT_MULTI_WMAPRO, 0x0406),
} HA_CODEC_ID_E;

/**HA Channel Mode definition*/
/**CNcomment:\C9\F9\B5\C0\C5\E4\D6\C3\D0\C5Ϣ\B6\A8\D2\E5*/
typedef enum
{
    HA_AUDIO_CH_MODE_DUAL_MONO = 0x0,
    HA_AUDIO_CH_MODE_MONO      = 0x1,
    HA_AUDIO_CH_MODE_STEREO    = 0x2,
    HA_AUDIO_CH_MODE_3_0_MODE  = 0x3,
    HA_AUDIO_CH_MODE_2_1_MODE  = 0x4,
    HA_AUDIO_CH_MODE_3_1_MODE  = 0x5,
    HA_AUDIO_CH_MODE_2_2_MODE  = 0x6,
    HA_AUDIO_CH_MODE_3_2_MODE  = 0x7,
    HA_AUDIO_CH_MODE_JOINT_STEREO = 0x8,   /**<only in mp3 format.*/ /**<CNcomment:\BD\F6mp3\B8\F1ʽ\B2\C5\D3\D0joint stereoģʽ*/
    HA_AUDIO_CH_MODE_BUTT      = 0x1ff
} HA_AUDIO_CHANNELMODE_E;

/**HA Audio Output AD Mode definition*/
/**CNcomment:HA OUTPUT AD MODE \B6\A8\D2\E5*/
typedef enum
{
    HA_OUTPUT_AD_OFF = 0,
    HA_OUTPUT_AD_ON,
    HA_OUTPUT_AD_OFF_WITHASSOC,
    HA_OUTPUT_AD_BUTT
} HA_CODEC_OUTPUT_AD_MODE_E;

/**Define query parameter of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec \B2\E9ѯ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;
    HI_VOID *pPara;
} HA_CODEC_PARAMETER_QUERY_S;

/**Define format query parameter of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec \B8\F1ʽ\B2\E9ѯ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;
    HA_FORMAT_E enFormat;
} HA_CODEC_FORMAT_QUERY_PARAM_S;

/**Define packet query parameter of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec packet\BD\E2\C2\EBģʽ\B2\E9ѯ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;              /**<packet query command.*/ /**<CNcomment:packetģʽ\B2\E9ѯ\C3\FC\C1\EE*/
    HI_BOOL bPacketDecoder;     /**<Packet mode.In this mode, the decoder can decode the next packet only after processing an entire packet. */
                                /**<CNcomment:packetģʽ.\D4\DA\D5\E2\D6\D6ģʽ\CF£\ACֻ\D3д\A6\C0\ED\CD굱ǰ\D5\FB\B8\F6packet\BA\F3\BD\E2\C2\EB\C6\F7\B2\C5\C4ܴ\A6\C0\ED\CF\C2һ\B8\F6packet\B0\FC*/
} HA_CODEC_PACKETDECODER_QUERY_PARAM_S;

/**Define hardware decode query parameter of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec hardware\BD\E2\C2\EBģʽ\B2\E9ѯ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;      /**<hwdecode query command.*/ /**<CNcomment: hwdecodeģʽ\B2\E9ѯ\C3\FC\C1\EE*/
    HI_BOOL bHwCodec;   /**<HI_TRUE: hwdecode mode else swdecode mode. */ /**<CNcomment:hwdecodeģʽ*/
} HA_CODEC_HARDWARECODER_QUERY_PARAM_S;

/**Define query parameter of dual decode capability.*/
/**CNcomment:\B6\A8\D2\E5˫·\BD\E2\C2\EB\C4\DC\C1\A6\B2\E9ѯ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;                  /**<query dual decode capability command.*/ /**<CNcomment: \B2\E9ѯ˫·\BD\E2\C2\EB\C4\DC\C1\A6\C3\FC\C1\EE*/
    HI_BOOL bDualDecSupport;        /**<support dual decode or not. */  /**<CNcomment:\CAǷ\F1֧\B3\D6˫·\BD\E2\C2\EB*/
} HA_CODEC_DUALDECODE_QUERY_PARAM_S;

/**Define setting parameter of dual decode ad output mode.*/
/**CNcomment:\C9\E8\D6\C3˫·\BD\E2\C2\EBAD\CA\E4\B3\F6ģʽ**/
typedef struct
{
    HI_U32               enCmd;             /**<set AD Output Mode command.*/ /**<CNcomment: \C9\E8\D6\C3AD\CA\E4\B3\F6ģʽ\C3\FC\C1\EE*/
    HA_CODEC_OUTPUT_AD_MODE_E  enAdMode;    /**<AD Output Mode. */  /**<CNcomment:AD\CA\E4\B3\F6ģʽ*/
} HA_CODEC_ADMODE_SET_PARAM_S;

/**Define setting parameter of AD Balance.*/
/**CNcomment:\C9\E8\D6\C3AD Ȩ\D6\D8**/
typedef struct
{
    HI_U32  enCmd;                      /**<set AD Balance command.*/ /**<CNcomment: \C9\E8\D6\C3ADȨ\D6\D8\C3\FC\C1\EE*/
    HI_S16  s16ADBalance;               /**<set the value of AD Balance */  /**<CNcomment:\C9\E8\D6\C3ADȨ\D6\D8ֵ*/
} HA_CODEC_ADBALANCE_SET_PARAM_S;

/**Define set parameter of whether work in compress mode.*/
/**CNcomment:\B6\A8\D2\E5\CAǷ\F1\B9\A4\D7\F7\D3\DA\D4\DA\CF\DFѹ\CB\F5ģʽ\C9\E8\D6ò\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;          /**<set the compress mode command. */ /**<CNcomment:\C9\E8\D6\C3\CAǷ\F1\D4\DA\CF\DFѹ\CB\F5ģʽ\C3\FC\C1\EE*/
    HI_BOOL bCompressMode;  /**<whether work in compress mode. */ /**<CNcomment:\CAǷ\F1\B9\A4\D7\F7\D3\DA\D4\DA\CF\DFѹ\CB\F5ģʽ*/
} HA_CODEC_COMPRESSMODE_SET_PARAM_S;

/**Define get parameter of decoder output delay.*/
/**CNcomment:\B6\A8\D2\E5\BB\F1ȡ\BD\E2\C2\EB\C6\F7\CA\E4\B3\F6\D1\D3ʱ\B2\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;          /**<get the output delay command. */ /**<CNcomment:\BB\F1ȡ\BD\E2\C2\EB\C6\F7\CA\E4\B3\F6\D1\D3ʱ\C3\FC\C1\EE*/
    HI_U32  u32OutputDelay; /**<decoder output delay ms. */ /**<CNcomment:\BD\E2\C2\EB\C6\F7\B5\C4\CA\E4\B3\F6\D1\D3ʱ(\BA\C1\C3\EB)*/
} HA_CODEC_OUTOUTDELAY_GET_PARAM_S;

/**Define the error codes of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec \B4\ED\CE\F3\C2\EB*/
typedef enum hiHA_ERRORTYPE_E
{
    HA_ErrorNone = 0, /**<None error.*/ /**<CNcomment:û\D3д\ED\CE\F3 */

    HA_ErrorInsufficientResources = (HI_S32) 0x80001000,/**<The device fails to be created due to insufficient resources.*/ /**<CNcomment:\D7\CAԴ\B2\BB\B9\BB\A3\AC\B4\B4\BD\A8\C9豸ʧ\B0\DC */

    HA_ErrorInvalidParameter = (HI_S32) 0x80001001, /**<The input parameter is invalid.*/ /**<CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 */

    HA_ErrorStreamCorrupt = (HI_S32) 0x80001002, /**<The decoding fails due to incorrect input streams.*/ /**<CNcomment:\CA\E4\C8\EB\C2\EB\C1\F7\B4\ED\CE󣬽\E2\C2\EBʧ\B0\DC */

    HA_ErrorNotEnoughData = (HI_S32) 0x80001003,/**<The decoding ends due to insufficient streams.*/ /**<CNcomment:\CA\E4\C8\EB\C2\EB\C1\F7\B2\BB\B9\BB\A3\AC\CD˳\F6\BD\E2\C2\EB */

    HA_ErrorDecodeMode = (HI_S32) 0x80001004,/**<The decoding mode is not supported.*/ /**<CNcomment:\BD\E2\C2\EBģʽ\B2\BB֧\B3\D6 */

    HA_ErrorNotSupportCodec = (HI_S32) 0x80001005,/**<The codec is not supported.*/ /**<CNcomment:\BD\E2\C2\EB\C6\F7\B2\BB֧\B3\D6 */

    HA_ErrorInBufFull = (HI_S32) 0x80001006,/**<Input buffer is full.*/ /**<CNcomment:\CA\E4\C8뻺\B4\E6\C2\FA */

    HA_ErrorOutBufEmpty = (HI_S32) 0x80001007,/**<Output buffer is empty.*/ /**<CNcomment:\CA\E4\B3\F6\BB\BA\B4\E6\BF\D5 */

#ifdef HA_SW_DUALDEC_SUPPORT
    HA_ErrorNotEnoughADData = (HI_S32) 0x80001008,/**<The decoding ends due to insufficient ad streams.*/ /**<CNcomment:ad\CA\E4\C8\EB\C2\EB\C1\F7\B2\BB\B9\BB\A3\AC\CD˳\F6\BD\E2\C2\EB */

    HA_ErrorADDecFailed = (HI_S32) 0x80001009,
#endif

    HA_ErrorMax = 0x9FFFFFFF
} HI_HA_ERRORTYPE_E;

/**Definition of the distribution mode of the channels of an HA codec.*/
/**CNcomment:\B6\A8\D2\E5HA codec \C9\F9\B5\C0\B7ֲ\BCģʽ*/
typedef enum hiHA_CHANNELTYPE_E
{
    HA_AUDIO_ChannelNone = 0x0,    /**< Unused or empty.*/ /**<CNcomment:δʹ\D3û\F2Ϊ\BF\D5*/
    HA_AUDIO_ChannelLF  = 0x1,     /**< Left front.*/ /**<CNcomment:\D7\F3ǰ*/
    HA_AUDIO_ChannelRF  = 0x2,     /**< Right front.*/ /**<CNcomment:\D3\D2ǰ*/
    HA_AUDIO_ChannelCF  = 0x3,     /**< Center front.*/ /**<CNcomment:\D6\D0\D6\C3*/
    HA_AUDIO_ChannelLS  = 0x4,     /**< Left surround.*/ /**<CNcomment:\D7\F3\BB\B7\C8\C6*/
    HA_AUDIO_ChannelRS  = 0x5,     /**< Right surround.*/ /**<CNcomment:\D3һ\B7\C8\C6*/
    HA_AUDIO_ChannelLFE = 0x6,     /**< Low frequency effects.*/ /**<CNcomment:\B5\CD\D2\F4*/
    HA_AUDIO_ChannelCS  = 0x7,     /**< Back surround.*/ /**<CNcomment:\BA\F3\BB\B7\C8\C6*/
    HA_AUDIO_ChannelLR  = 0x8,     /**< Left rear.*/ /**<CNcomment:\D7\F3\BA\F3*/
    HA_AUDIO_ChannelRR  = 0x9,     /**< Right rear.*/ /**<CNcomment:\D3Һ\F3*/
    HA_AUDIO_ChannelMax = 0x7FFFFFFF
} HI_HA_CHANNELTYPE_E;

/**Definition of the decoding mode of an HA decoder.*/
/**CNcomment:\B6\A8\D2\E5HA \BD\E2\C2\EB\C6\F7\BD\E2\C2\EBģʽ*/
typedef enum hiHA_DECODEMODE_E
{
    HD_DEC_MODE_RAWPCM = 0,        /**<PCM decoding mode.*/ /**<CNcomment:PCM \BD\E2\C2\EBģʽ*/
    HD_DEC_MODE_THRU,              /**<SPIDF61937 passthrough decoding mode only, such as AC3/DTS.*/ /**<CNcomment:͸\B4\AB\BD\E2\C2\EBģʽ*/
    HD_DEC_MODE_SIMUL,             /**<PCM and passthrough decoding mode.*/ /**<CNcomment:PCM + ͸\B4\AB\BD\E2\C2\EBģʽ*/
    HD_DEC_MODE_BUTT = 0x7FFFFFFF
} HI_HA_DECODEMODE_E;

/**Definition of the HA codec version.*/
/**CNcomment:HA codec \B0汾\B6\A8\D2\E5*/
typedef union hiHI_HAAUDIO_VERSIONTYPE_U
{
    struct
    {
        HI_U8 u8VersionMajor;      /**< Major version.*/ /**<CNcomment:\D6\F7\B0汾\BA\C5 */
        HI_U8 u8VersionMinor;      /**< Minor version.*/ /**<CNcomment:\B8\B1\B0汾\BA\C5 */
        HI_U8 u8Revision;          /**< Revision version.*/ /**<CNcomment:\D0޶\A9\B0汾 */
        HI_U8 u8Step;              /**< Step version.*/ /**<CNcomment:\BD׶\CE\D0԰汾 */
    } s;
    HI_U32 u32Version;
} HI_HAAUDIO_VERSIONTYPE_U;

/**Definition of the data types of the PCM module in an HA codec HA codec.*/
/**CNcomment:pcm \CA\FD\BE\DD\C0\E0\D0ͽṹ\CC嶨\D2\E5*/
typedef struct hiHA_PCMMODETYPE_S
{
    HI_U32              u32DesiredOutChannels;/**<Input,number of expected output channels.If the number of original channels is not equal to the number of expected output channels,
                                                  the decoded automatically performs down-mixing or up-mixing,In this way,
                                                  the number of output channels is equal to the value of u32DesiredOutChannels,1: mono; 2 stereo. \n*/
                                              /**<CNcomment:IN \C6\DA\CD\FB\CA\E4\B3\F6\C9\F9\B5\C0\CA\FDĿ. \C8\E7\B9\FB\C2\EB\C1\F7ԭʼ\C9\F9\B5\C0\B2\BB\B5\C8\D3\DA
                                                  \C6\DA\CD\FB\CA\E4\B3\F6\C9\F9\B5\C0\A3\AC\BD\E2\C2\EB\C6\F7\D7Զ\AF\BD\F8\D0\D0down-mix \BB\F2up-mix \B4\A6\C0\ED\A3\ACʹ\B5\C3\CA\E4\B3\F6
                                                  \C9\F9\B5\C0\B5\C8\D3\DAu32DesiredOutChannels.  1: mono, 2 for stereo*/
    HI_BOOL             bInterleaved;/**<Whether the PCM data is interleaved.
                                         HI_TRUE: interleaved mode (L/R/L/R.. .L/R/L/R).
                                         HI_FALSE: non-interleaved mode (L/L/L.../R/R/R...). \n*/
                                     /**<CNcomment:IN PCM \CA\FD\BE\DD\CAǷ\F1\BD\BB֯ģʽ
                                         HI_TRUE:  \BD\BB֯ģʽ: L/R/L/R...L/R/L/R.
                                         HI_FALSE: \B7ǽ\BB֯ģʽ: L/L/L......../R/R/R....... */
    HI_U32              u32BitPerSample;/**<Input Bit width of the PCM data.Only 16-bit or 24-bit width is supported.For the data of 16-bit width, 16-bit memory is used,
                                            For the data of 24-bit width, 32-bit memory is used,The active bits of the 24-bit PCM data are upper bits, and the lower eight bits are padded with 0s. \n*/
                                        /**<CNcomment:IN PCM \CA\FD\BE\DDλ\BF\ED,\BD\F6֧\B3\D616 \BB\F224 \CA\FD\BE\DDλ\BF\ED 16bit λ\BF\EDռ\D3\C316bit \C4ڴ\E6,
                                            24bit λ\BF\EDռ\D3\C332\B1\C8\CC\D8\C4ڴ\E6.24bit PCM\CA\FD\BE\DD\D3\D0ЧΪ\D4ڸ\DFλ\A3\AC\B5\CD8 λ\B2\B90*/
    HI_U32              u32DesiredSampleRate; /**<Input, expected output sampling rate.*/ /**<CNcomment:IN \C6\DA\CD\FB\CA\E4\B3\F6\B2\C9\D1\F9Ƶ\C2\CA*/
    HI_HA_CHANNELTYPE_E enChannelMapping[HA_AUDIO_MAXCHANNELS]; /**<Input, distribution mode of output channels.*/ /**<CNcomment:IN \CA\E4\B3\F6\C9\F9\B5\C0\B7ֲ\BCģʽ*/
} HI_HA_PCMMODETYPE_S;

/**Configuration parameters required by an HA codec for creating devices.*/
/**CNcomment:HA \BD\E2\C2\EB\C6\F7\B4\B4\BD\A8\C9豸\B5\C4\C5\E4\D6ò\CE\CA\FD*/
typedef struct hiHADECODE_OPENPARAM_S
{
    HI_HA_DECODEMODE_E  enDecMode;  /**<IN Decode Mode.*/ /**<CNcomment:\BD\E2\C2\EBģʽ*/
    HI_HA_PCMMODETYPE_S sPcmformat; /**<IN data types of pcm module.*/ /**<CNcomment:PCM\CA\FD\BE\DD\C0\E0\D0ͽṹ\CC\E5*/
    HI_VOID *           pCodecPrivateData;/**<Input, pointer to private data.If the decoder does not contain private data, this parameter is set to 0. */
                                          /**<CNcomment:IN  ָ\CF\F2˽\D3\D0\C5\E4\D6ýṹ\CC\E5\B5\C4ָ\D5룬\C8\E7\B9\FB\BD\E2\C2\EB\C6\F7û\D3\D0˽\D3\D0\C5\E4\D6ã\AC\C9\E8\D6\C3Ϊ0*/
    HI_U32              u32CodecPrivateDataSize;/**<Input, size of the private data.If the decoder does not contain private data, this parameter is set to 0. */
                                                /**<CNcomment:IN ˽\D3нṹ\CC\E5\B4\F3С, \C8\E7\B9\FB\BD\E2\C2\EB\C6\F7û\D3\D0˽\D3\D0\C5\E4\D6ã\AC\C9\E8\D6\C3Ϊ0*/
} HI_HADECODE_OPENPARAM_S;

/**Input streams of an HA decoder.*/
/**CNcomment:HA \BD\E2\C2\EB\C6\F7\CA\E4\C8\EB\C2\EB\C1\F7\BDṹ\CC\E5*/
typedef struct hiHADECODE_INPACKET_S
{
    HI_U32  u32PtsMs;  /**<Input, presentation time stamp (PTS) (in ms).Note: The HA decoder must discard this information. */ /**<CNcomment:\B5\B1ǰʱ\BC\E4\B4\C1*/
    HI_U8  *pu8Data;   /**<Input/output, pointer to input streams.The decoder update this pointer after decoding. */ /**<CNcomment:IN/OUT \CA\E4\C8\EB\C2\EB\C1\F7ָ\D5룬\BD\E2\C2\EB\CD\EA\B3ɺ\F3\BD\E2\C2\EB\C6\F7\B8\FC\D0¸\C3ָ\D5\EB*/
    HI_S32  s32Size;   /**<Input, size (in byte) of input streams.*/ /**<CNcomment:IN \CA\E4\C8\EB\C2\EB\C1\F7\B4\F3С. unit: Byte*/
    HI_BOOL bEndOfFrm; /**<Input, the last frame or not.*/ /**<CNcomment:IN \CAǷ\F1\D7\EE\BA\F3һ֡*/
} HI_HADECODE_INPACKET_S;

/**Get Open parameter of an HA decoder.*/
/**CNcomment:\BB\F1ȡHA \BD\E2\C2\EB\C6\F7\B4򿪲\CE\CA\FD*/
typedef struct
{
    HI_U32  enCmd;
    HI_HADECODE_OPENPARAM_S *pstDecodeParams;
} HA_CODEC_GET_DECOPENPARAM_PARAM_S;

/**Definition of the decoder output pts infomations.*/
/**CNcomment:pts\CA\E4\B3\F6\D0\C5Ϣ*/
typedef struct hiHI_HA_OUTPTSINFO_S
{
    union
    {
        HI_U32 u32SwDecoderBytesLeft;   /**<left bytes of software decoder.*/ /**<CNcomment:\C8\ED\BD\E2ʣ\D3\E0\D7ֽ\DA\CA\FD */
        HI_U32 u32HwDecoderPtsReadPos;  /**<pts read position of software decoder.*/ /**<CNcomment:Ӳ\BD\E2pts\B6\C1λ\D6\C3 */
    } unPts;

    union
    {
        HI_U32 u32SwAdDecoderBytesLeft;     /**<ad left bytes of software decoder.*/ /**<CNcomment:\C8\ED\BD\E2adʣ\D3\E0\D7ֽ\DA\CA\FD */
        HI_U32 u32HwAdDecoderPtsReadPos;    /**<ad pts read position of software decoder.*/ /**<CNcomment:Ӳ\BD\E2ad pts\B6\C1λ\D6\C3 */
    } unAdPts;
} HI_HA_OUTPTSINFO_S;

/**Output structure of the HA decoder.*/
/**CNcomment:HA \BD\E2\C2\EB\C6\F7\CA\E4\B3\F6\BDṹ\CC\E5*/
typedef struct hiHI_HADECODE_OUTPUT_S
{
    HI_S32 *ps32PcmOutBuf;       /**<Input, pointer to the decoded PCM data.
                                     Note: 1) ps32PcmOutBuf must be 32-word aligned.
                                           2) ps32PcmOutBuf is NULL when the decoder is working in HD_DEC_MODE_THRU mode.\n*/
                                 /**<CNcomment:IN ָ\CF\F2PCM \BD\E2\C2\EB\CA\E4\B3\F6\B5\C4ָ\D5\EB. */

    HI_U32  u32PcmOutBufSize;    /**<Input, size (in byte) of the buffer for storing the decoded PCM data
                                     Note: u32PcmOutBufSize is 0 when the decoder is working in HD_DEC_MODE_THRU mode.\n*/
                                 /**<CNcomment:IN  PCM \BD\E2\C2\EB\CA\E4\B3\F6\BB\BA\B3\E5\C7\F8\B4\F3С. unit:Byte */

    HI_S32 *ps32BitsOutBuf;      /**<Input, pointer to the decoded passthrough data.
                                     Note: 1) ps32BitsOutBuf must be 32-word aligned.
                                           2) ps32BitsOutBuf is NULL when the decoder is working in HD_DEC_MODE_RAWPCM mode.\n*/
                                 /**<CNcomment:IN ָ\CF\F2͸\B4\AB\BD\E2\C2\EB\CA\E4\B3\F6\B5\C4ָ\D5\EB. */

    HI_U32  u32BitsOutBufSize;   /**<Input, size (in byte) of the buffer for storing the decoded passthrough data (IEC61937)
                                     Note: u32BitsOutBufSize is 0 when the decoder is working in HD_DEC_MODE_RAWPCM mode.\n*/
                                 /**<CNcomment:IN ͸\B4\AB(IEC61937) \BD\E2\C2\EB\CA\E4\B3\F6\BB\BA\B3\E5\C7\F8\B4\F3С. unit:Byte */

    HI_U32  u32PcmOutSamplesPerFrame; /**<Output, number of output sampling points after the PCM data is decoded.*/ /**<CNcomment:OUT. \BD\E2\C2\EBPcm \CA\E4\B3\F6\D1\F9\B5\E3\CA\FD */
    HI_BOOL bInterleaved;             /**<Output, interleaved mode for PCM decoding.*/ /**<CNcomment:OUT PCM  \BD\E2\C2뽻֯ģʽ*/
    HI_U32  u32BitPerSample;          /**<Output, bit per sampling.*/ /**<CNcomment:OUT λ\BF\ED*/
    HI_U32  u32BitsOutBytesPerFrame;  /**<Output, size (in byte) of the passthrough frame.*/ /**<CNcomment:OUT ͸\B4\AB\CA\E4\B3\F6֡\B4\F3С. unit: Byte*/
    HI_U32  u32OutChannels;           /**<Output, number of output channels.*/ /**<CNcomment:OUT \CA\E4\B3\F6\C9\F9\B5\C0\CA\FD*/
    HI_U32  u32OutSampleRate;         /**<Output, output sampling rate.*/ /**<CNcomment:OUT. \CA\E4\B3\F6\B2\C9\D1\F9Ƶ\C2\CA*/
    HI_U32  u32OrgChannels;           /**<Output, number of original channels.*/ /**<CNcomment:OUT \C2\EB\C1\F7ԭʼ\C9\F9\B5\C0\CA\FD*/
    HI_U32  u32OrgSampleRate;         /**<Output, original sampling rate.*/ /**<CNcomment:OUT \C2\EB\C1\F7ԭʼ\B2\C9\D1\F9Ƶ\C2\CA*/
    HI_U32  u32BitRate;               /**<Output, bit rate (in bit/s) of the compressed streams.*/ /**<CNcomment:OUT \C2\EB\C1\F7ѹ\CB\F5\C2\CAunit: bit/S*/
    HI_HA_OUTPTSINFO_S stPtsInfo;     /**<Output, pts information.*/ /**<CNcomment:OUT. pts\D0\C5Ϣ*/
    HI_U32  u32FrameIndex;   /**<Output, output frame index.*/ /**<CNcomment:OUT. \CA\E4\B3\F6֡\D0\F2\BA\C5*/
} HI_HADECODE_OUTPUT_S;

/**Definition of the HA decoder.*/
/**CNcomment:HA \BD\E2\C2\EB\C6\F7\C9豸\B6\A8\D2\E5*/
typedef struct hiHA_DECODE_S
{
    const HI_PCHAR szName;/**<Input, description information about a decoder, such as MP3 or AAC. */
                          /**<CNcomment:IN \BD\E2\C2\EB\C6\F7\C3\E8\CA\F6\C3\FB\D7֣\AC\C8\E7MP3,AAC*/

    const HI_U32 enCodecID;/**<Input, decoder ID.Note: This ID is the identifier of a decoder, and must be unique. */
                           /**<CNcomment:IN \BD\E2\C2\EB\C6\F7\B1\EAʶ\A3\ACע\D2\E2: \B4˱\EAʶ\D7\F7Ϊ\BD\E2\C2\EB\C6\F7Ψһ\C9\ED\B7ݱ\EAʶ\A3\AC\B1\D8\D0\EBΨһ\B6\F8\B2\BB\C4\DC\D3\D0\D6ظ\B4*/

    const HI_HAAUDIO_VERSIONTYPE_U uVersion;/**<Input, decoder version.*/ /**<CNcomment:IN \BD\E2\C2\EB\C6\F7\B0汾\C3\E8\CA\F6*/

    const HI_PCHAR pszDescription;/**<Input, detailed information about a decoder.*/ /**<CNcomment:IN \BD\E2\C2\EB\C6\F7\CF\EAϸ\C3\E8\CA\F6\D0\C5Ϣ*/



    struct hiHA_DECODE_S *pstNext;/**<Output, pointer to the next decoder.This member variable is maintained by the client that calls the HA codec,
                                      Therefore, the developers of the HA decoder can ignore this member variable. \n*/
                                  /**<CNcomment:OUT  ָ\CF\F2\CF¸\F6\BD\E2\C2\EB\C6\F7\C9豸\B5\C4ָ\D5\EB.  \B8ó\C9Ա\B1\E4\C1\BF\D3ɵ\F7\D3\C3HA Codec \B5Ŀͻ\A7\B6\CBά\BB\A4, HA \BD\E2\C2\EB\C6\F7\BF\AA\B7\A2\D5߿\C9\D2Ժ\F6\C2Ըó\C9Ա*/

    HI_VOID  * pDllModule;/**<Output, pointer to the dll symbol of an HA decoder,This member variable is maintained by the client that calls the HA codec,
                              Therefore, the developers of the HA decoder can ignore this member variable.\n*/
                          /**<CNcomment:OUT \B8ó\C9Ա\B1\E4\C1\BF\D3ɵ\F7\D3\C3HA Codec \B5Ŀͻ\A7\B6\CBά\BB\A4, HA \BD\E2\C2\EB\C6\F7\BF\AA\B7\A2\D5߿\C9\D2Ժ\F6\C2Ըó\C9Ա*/

    /**
    \brief Initializes a decoder. CNcomment:\B3\F5ʼ\BB\AF\BD\E2\C2\EB\C6\F7 CNend
    \attention \n
    \param[in] pstOpenParam pointer of the open params CNcomment:open\B2\CE\CA\FD\BDṹ\CC\E5ָ\D5\EB CNend
    \param[out] phDecoder   pointer of the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FAָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecInit)(HI_VOID * *phDecoder,
                                 const HI_HADECODE_OPENPARAM_S * pstOpenParam);

    /**
    \brief DeInitializes a decoder. CNcomment:ȥ\B3\F5ʼ\BB\AF\BD\E2\C2\EB\C6\F7 CNend
    \attention \n
    \param[in] hDecoder   pointer of the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FAָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecDeInit)(HI_VOID* hDecoder);

    /**
    \brief Configure a decoder dynamically. You can call this API when a decoder works.
    CNcomment:\BD\E2\C2\EB\C6\F7\B6\AF̬\C5\E4\D6÷\BD\B7\A8\A3\AC\D3û\A7\BF\C9\D2\D4\D4ڽ\E2\C2\EB\C6\F7\D4\CB\D0\D0ʱ\B5\F7\D3øýӿ\DA CNend
    \attention \n
    \param[in] hDecoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[in] pstConfigStructure pointer to application allocated structure to be used for initialization by the decoder CNcomment:\BD\E2\C2\EB\C6\F7\B3\F5ʼ\BB\AF\BDṹ\CC\E5 CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecSetConfig)(HI_VOID* hDecoder, HI_VOID* pstConfigStructure);

    /**
    \brief Maximum size of the buffer required for storing the PCM data decoded by the decoder,
    The memory needs to be allocated based on the size on the client.
    CNcomment:\BD\E2\C2\EB\C6\F7PCM\CA\E4\B3\F6\CB\F9\D0\E8\D7\EE\B4󻺳\E5\C7\F8size. \BFͻ\A7\B6\CB\D0\E8Ҫ\B8\F9\BEݸ÷\BD\B7\A8\B7\D6\C5\E4\C4ڴ\E6 CNend
    \attention \n
    \param[in] hDecoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[out] pu32OutSizes pointer to the max size of the pcm audio frame. unit:Byte CNcomment:\D7\EE\B4\F3PCM\CA\E4\B3\F6\BB\BA\B3\E5\C7\F8\B4\F3С CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecGetMaxPcmOutSize)(HI_VOID* hDecoder,
            HI_U32* pu32OutSizes);

    /**
    \brief Maximum size of the buffer required for storing the passthrough data decoded by the decoder,
    The memory needs to be allocated based on the size on the client.
    CNcomment:\BD\E2\C2\EB\C6\F7͸\B4\AB\CA\E4\B3\F6\CB\F9\D0\E8\D7\EE\B4󻺳\E5\C7\F8size.\BFͻ\A7\B6\CB\D0\E8Ҫ\B8\F9\BEݸ÷\BD\B7\A8\B7\D6\C5\E4\C4ڴ\E6 CNend
    \attention \n
    \param[in] hDecoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[out] pu32OutSizes pointer to the max size of the iec61937 audio frame. unit:Byte CNcomment:\D7\EE\B4\F3͸\B4\AB\CA\E4\B3\F6\BB\BA\B3\E5\C7\F8\B4\F3С CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecGetMaxBitsOutSize)(HI_VOID* hDecoder,
            HI_U32* pu32OutSizes);

    /**
    \brief This method is used to decode a frame. CNcomment:\BD\E2\C2\EB\C6\F7\BD\E2\C2\EBһ֡\B7\BD\B7\A8 CNend
    \attention \n
    \param[in] hDecoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[in] pstApkt pointer to audio stream packet CNcomment:\D2\F4Ƶ\CA\E4\C8\EB\C1\F7ָ\D5\EB CNend
    \param[out] pstAOut pointer to audio output CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C1\F7ָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecDecodeFrame)(HI_VOID* hDecoder,
                                        HI_HADECODE_INPACKET_S* pstApkt,
                                        HI_HADECODE_OUTPUT_S* pstAOut);

#ifdef HA_SW_DUALDEC_SUPPORT
    /**
    \brief This method is used to dual decode a frame. CNcomment:\BD\E2\C2\EB\C6\F7˫·\BD\E2\C2\EBһ֡\B7\BD\B7\A8 CNend
    \attention \n
    \param[in] hDecoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[in] pstApkt pointer to audio stream packet CNcomment:\D2\F4Ƶ\CA\E4\C8\EB\C1\F7ָ\D5\EB CNend
    \param[in] pstADApkt pointer to AD audio stream packet CNcomment:AD\D2\F4Ƶ\CA\E4\C8\EB\C1\F7ָ\D5\EB CNend
    \param[out] pstAOut pointer to audio output CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C1\F7ָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*DecDualDecodeFrame)(HI_VOID* hDecoder,
                                            HI_HADECODE_INPACKET_S* pstApkt,
                                            HI_HADECODE_INPACKET_S* pstADApkt,
                                            HI_HADECODE_OUTPUT_S* pstAOut);
#endif

} HI_HA_DECODE_S;

/**Parameters for creating an HA encoder.*/
/**CNcomment:HA \B1\E0\C2\EB\C6\F7\B4\B4\BD\A8\C5\E4\D6ò\CE\CA\FD*/
typedef struct hiHAENCODE_OPENPARAM_S
{
    HI_U32      u32DesiredOutChannels; /**<IN Number of channels (e.g 2 for stereo).*/ /**<CNcomment:\C9\F9\B5\C0\CA\FD*/
    HI_BOOL     bInterleaved;       /**<IN interleave or not.*/ /**<CNcomment:\BD\BB֯ģʽ*/
    HI_S32      s32BitPerSample;    /**<IN bitwidth per sample.*/ /**<CNcomment:λ\BF\ED*/
    HI_U32      u32DesiredSampleRate; /**<IN desired samplerate.*/ /**<CNcomment:\C6\DA\CD\FB\B2\C9\D1\F9\C2\CA*/
    HI_U32      u32SamplePerFrame;  /**<IN Pcm samples per frame for encoder.*/ /**<CNcomment:ÿ֡\B2\C9\D1\F9\B5\E3*/
    HI_VOID*    pCodecPrivateData;  /**<IN Pointer of decoder private open parameters note: if there is none private parameters, pCodecPrivateData=0.*/
                                    /**<CNcomment:˽\D3в\CE\CA\FD*/
    HI_U32      u32CodecPrivateDataSize;/**<IN Size of decoder private open parameters note: if there is none private parameters, u32CodecPrivateDataSize=0.*/
                                        /**<CNcomment:˽\D3в\CE\CA\FD\B4\F3С*/
} HI_HAENCODE_OPENPARAM_S;

/**HA input pcm  packet struct.*/
/**CNcomment:packetģʽ\BDṹ\CC\E5*/
typedef struct hiHAENCODE_INPACKET_S
{
    HI_U32  u32PtsMs;       /**<IN  PTS (unit:MS) Note: HA encoder should discard this infomation.*/
                            /**<CNcomment:PTS\A3\AC\B5\A5λ:\BA\C1\C3\EB*/
    HI_U8*  pu8Data;        /**<IN/OUT pointer to input auduo pcm data note: HA encoder would update pu8Data after encode.*/
                            /**<CNcomment:\CA\E4\C8\EB\CA\FD\BE\DDָ\D5\EB*/
    HI_U32  u32Size;        /**<IN/OUT size of the input auduo data. unit: Byte.*/ /**<CNcomment:\CA\E4\C8\EB\CA\FD\BEݴ\F3С*/
} HI_HAENCODE_INPACKET_S;

/**HA encoder output struct.*/
/**CNcomment:\B1\E0\C2\EB\C6\F7\CA\E4\B3\F6\BDṹ\CC\E5*/
typedef struct hiHAENCODE_OUTPUT_S
{
    HI_S32* ps32BitsOutBuf;         /**<IN the pointer to encoded bitstream output buffer note: ps32BitsOutBuf must  be word32-aligned.*/
                                    /**<CNcomment:\B1\E0\C2\EB\CA\FD\BE\DD\CA\E4\B3\F6buffer*/
    HI_U32  u32BitsOutBufSize;      /**<IN the buffer size of bitstream output buffer. unit:Byte.*/ /**<CNcomment:\B1\E0\C2\EB\C6\F7\CA\E4\B3\F6buffer\B4\F3С*/
    HI_U32  u32BitsOutBytesPerFrame;/**<IN size of the encoded audio data frame ,unit: Byte.*/ /**<CNcomment:\B1\E0\C2\EB\CA\FD\BE\DD֡\B4\F3С\A3\AC\B5\A5λ:Byte*/
    HI_U32  u32BitRate;             /**<IN compress bit rate of the audio stream.*/ /**<CNcomment:\B1\C8\CC\D8\C2\CA*/
} HI_HAENCODE_OUTPUT_S;

/**HA encoder struct define.*/
/**CNcomment:\B6\A8\D2\E5\B1\E0\C2\EB\C6\F7\BDṹ\CC\E5*/
typedef struct hiHA_ENCODE_S
{
    const HI_PCHAR szName;/**<Input, description information about audio encoder. */
    /**<CNcomment:IN \B1\E0\C2\EB\C6\F7\C3\E8\CA\F6\C3\FB\D7\D6*/

    const HI_U32 enCodecID;/**<Input, encoder ID.Note: This ID is the identifier of a encoder, and must be unique. */
    /**<CNcomment:IN \B1\E0\C2\EB\C6\F7\B1\EAʶ\A3\ACע\D2\E2: \B4˱\EAʶ\D7\F7Ϊ\B1\E0\C2\EB\C6\F7Ψһ\C9\ED\B7ݱ\EAʶ\A3\AC\B1\D8\D0\EBΨһ\B6\F8\B2\BB\C4\DC\D3\D0\D6ظ\B4*/

    const HI_HAAUDIO_VERSIONTYPE_U uVersion;/**<Input, encoder version.*/ /**<CNcomment:IN \B1\E0\C2\EB\C6\F7\B0汾\C3\E8\CA\F6*/

    const HI_PCHAR pszDescription;/**<Input, Description infomation of the audio encoder. */ /**<CNcomment:IN \B1\E0\C2\EB\C6\F7\CF\EAϸ\C3\E8\CA\F6\D0\C5Ϣ*/

    struct hiHA_ENCODE_S* pstNext;/**<OUT pointer to next HA enocder.manager by client.client:The layer of software that invokes the methods of the HA encoder. */
    /**<CNcomment:OUT \CF¸\F6\B1\E0\C2\EB\C6\F7\BDṹ\CC\E5ָ\D5룬\D3ɿͻ\A7\B9\DC\C0\ED */

    HI_VOID*   pDllModule;/**<Output, pointer to the dll symbol of an HA encoder.This member variable is maintained by the client that calls the HA codec
                              Therefore, the developers of the HA encoder can ignore this member variable. \n*/
    /**<CNcomment:OUT \B8ó\C9Ա\B1\E4\C1\BF\D3ɵ\F7\D3\C3HA Codec \B5Ŀͻ\A7\B6\CBά\BB\A4, HA \B1\E0\C2\EB\C6\F7\BF\AA\B7\A2\D5߿\C9\D2Ժ\F6\C2Ըó\C9Ա*/

    /**
    \brief Initializes a encoder. CNcomment:\B3\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7 CNend
    \attention \n
    \param[in] pstOpenParam pointer of the open params CNcomment:open\B2\CE\CA\FD\BDṹ\CC\E5ָ\D5\EB CNend
    \param[out] phEncoder   pointer of the encoder handle CNcomment:\B1\E0\C2\EB\C6\F7\BE\E4\B1\FAָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*EncodeInit)(HI_VOID * *phEncoder,
                                    const HI_HAENCODE_OPENPARAM_S* pstOpenParam);

    /**
    \brief DeInitializes a encoder. CNcomment:ȥ\B3\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7 CNend
    \attention \n
    \param[in] hEncoder   pointer of the encoder handle CNcomment:\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*EncodeDeInit)(HI_VOID* hEncoder);

    /**
    \brief Configure a encoder dynamically. It can be invoked anytime after the Encoder has been loaded.
    CNcomment:\B1\E0\C2\EB\C6\F7\B6\AF̬\C5\E4\D6÷\BD\B7\A8\A1\A3\D3û\A7\BF\C9\D2\D4\D4ڱ\E0\C2\EB\C6\F7\D4\CB\D0\D0ʱ\B5\F7\D3øýӿ\DA CNend
    \attention \n
    \param[in] hEncoder   the encoder handle CNcomment:\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[in] pstConfigStructure pointer to application allocated structure to be used for initialization by the encoder CNcomment:\B1\E0\C2\EB\C6\F7\B3\F5ʼ\BB\AF\BDṹ\CC\E5 CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*EncodeSetConfig)(HI_VOID* hEncoder, HI_VOID* pstConfigStructure);

    /**
    \brief Maximum output size of an encoded bitstream CNcomment:\B1\E0\C2\EB\C6\F7\CA\E4\B3\F6\CB\F9\D0\E8\D7\EE\B4󻺳\E5\C7\F8size CNend
    \attention \n
    \param[in] hEncoder   the decoder handle CNcomment:\BD\E2\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[out] pu32OutSizes pointer to the max size of the encoded audio frame. unit:Byte CNcomment:\D7\EE\B4\F3\B1\E0\C2\EB֡\CA\E4\B3\F6\BB\BA\B3\E5\C7\F8\B4\F3С CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*EncodeGetMaxBitsOutSize)(HI_VOID* hEncoder,
            HI_U32* pu32OutSizes);

    /**
    \brief This method is used to encode a frame. CNcomment:\B1\E0\C2\EB\C6\F7\B1\E0\C2\EBһ֡\B7\BD\B7\A8 CNend
    \attention \n
    \param[in] hEncoder   the decoder handle CNcomment:\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
    \param[in] pstApkt pointer to audio stream packet CNcomment:\D2\F4Ƶ\CA\E4\C8\EB\C1\F7ָ\D5\EB CNend
    \param[out] pstAOut pointer to audio output CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C1\F7ָ\D5\EB CNend
    \retval ::HA_ErrorNone  SUCCESS CNcomment:\B3ɹ\A6 CNend
    \retval ::HI_HA_ERRORTYPE_E FAILURE CNcomment:ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_HA_ERRORTYPE_E (*EncodeFrame)(HI_VOID* hEncoder,
                                     HI_HAENCODE_INPACKET_S* pstApkt,
                                     HI_HAENCODE_OUTPUT_S* pstAOut);
} HI_HA_ENCODE_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* #ifndef __HI_AUDIO_CODEC_H__ */
