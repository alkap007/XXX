/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
 ******************************************************************************
 File Name     : HA.AUDIO.TRUEHD.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       : 
 Last Modified :
 Description   : 
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_DOLBY_TRUEHD_H__
#define __HISI_AUDIO_DECODER_DOLBY_TRUEHD_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */  


typedef enum hiTRUEHD_DRC_STATEMODE_TYPE_E
{
    TRUEHD_DRC_STATEMODE_TYPE_OFF,
    TRUEHD_DRC_STATEMODE_TYPE_FOLLOW,      /**<default*/ /**<Ĭ\C8\CF\C5\E4\D6\C3 */
    TRUEHD_DRC_STATEMODE_TYPE_ON
} TRUEHD_DRC_STATEMODE_TYPE_E;


typedef struct hiTRUEHD_DECODE_OPENCONFIG_S
{
    HI_S32            				startByte ;
    HI_S32           				s32chanflag;
    HI_BOOL           			    fbaChannelOrder;

    HI_BOOL           			    lossless;
    TRUEHD_DRC_STATEMODE_TYPE_E     enDrcMode;
    HI_S32            				drcBoost;
    HI_S32            				drcCut;            
    HI_BOOL           			    verbose;
    HI_S32			  				lenSamp ;
    HI_S32            				lenByte ;
    HI_BOOL           			    archive;
} TRUEHD_DECODE_OPENCONFIG_S;


#define HA_DOLBY_TRUEHD_DecGetDefalutOpenConfig(pConfigParam) \
do { ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->s32chanflag = 0x2; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->startByte   = 0; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->lenByte   = 0x7fffffff; \
	 ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->lenSamp   = 0x7fffffff; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->fbaChannelOrder = HI_FALSE; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->lossless = HI_TRUE; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->enDrcMode   = TRUEHD_DRC_STATEMODE_TYPE_FOLLOW; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->drcBoost  = 100; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->drcCut = 100; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->verbose = HI_FALSE; \
     ((TRUEHD_DECODE_OPENCONFIG_S *)(pConfigParam))->archive = HI_FALSE; \
} while (0)

#define HA_DOLBY_TRUEHD_DecGetDefalutOpenParam(pOpenParam, pstPrivateParams) \
do{ HI_S32 i; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_SIMUL; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 2; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved  = HI_TRUE; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 24; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
    for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
    { \
        ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
    } \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = (HI_VOID*)pstPrivateParams; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = sizeof(TRUEHD_DECODE_OPENCONFIG_S); \
}while(0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HISI_AUDIO_DECODER_TRUEHD_H__ */

iff -Naur a/lib/hisi/HA.AUDIO.DRA.decode.h b/lib/hisi/HA.AUDIO.DRA.decode.h
-- a/lib/hisi/HA.AUDIO.DRA.decode.h	1970-01-01 01:00:00.000000000 +0100
++ b/lib/hisi/HA.AUDIO.DRA.decode.h	2021-11-02 11:53:28.000000000 +0100
@ -0,0 +1,93 @@
/******************************************************************************
 Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
 ******************************************************************************
 File Name     : HA.AUDIO.DRA.decode.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       : 
 Last Modified :
 Description   : 
 Function List :
 History       :
******************************************************************************/
#ifndef __HISI_AUDIO_DECODER_DRA_H__
#define __HISI_AUDIO_DECODER_DRA_H__

#include "hi_type.h"
#include "hi_audio_codec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define    HA_DRA_ID 0x007        

#define HA_CODEC_GET_DRA_DonwmixMultich_MODE_CMD  ((((HI_U32)HA_DRA_ID) << 16) | 0x1000)
#define HA_CODEC_GET_DRA_RAWCHANNEL_MODE_CMD      ((((HI_U32)HA_DRA_ID) << 16) | 0x1001)

typedef struct
{
    HI_U32  enCmd;              /* HA_DRA_GET_DonwmixMultich_MODE_S */
    HI_BOOL  *pbDonwmixMultichMode;
} HA_DRA_GET_DonwmixMultich_MODE_S;

typedef enum
{
    DRA_RAWCHANNEL_MODE10 = 0,
    DRA_RAWCHANNEL_MODE11,
    DRA_RAWCHANNEL_MODE20,
    DRA_RAWCHANNEL_MODE21,
    DRA_RAWCHANNEL_MODE30,
    DRA_RAWCHANNEL_MODE31,
    DRA_RAWCHANNEL_MODE40,
    DRA_RAWCHANNEL_MODE41,
    DRA_RAWCHANNEL_MODE50,
    DRA_RAWCHANNEL_MODE51,
    DRA_RAWCHANNEL_BUTT = 0x100,   /* Unsupported Channel Mode */
} HA_DRA_RAWCHANNEL_MODE;

typedef struct
{
    HI_U32  enCmd;              /* HA_CODEC_GET_DRA_RAWCHANNEL_MODE_CMD */
    HA_DRA_RAWCHANNEL_MODE  eRawChannelMode;
} HA_DRA_GET_RawChannel_MODE_S;

#define HA_DRA_DecGetDefalutOpenParam(pOpenParam) \
do{ HI_S32 i; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_SIMUL; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = HI_NULL; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = 0; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 2; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved  = HI_TRUE; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 24; \
    ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
    for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
    { \
        ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
    } \
}while(0)

#define HA_DRA_DecGetOpenParam_MultichPcm(pOpenParam) \
    do{ HI_S32 i; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->enDecMode = HD_DEC_MODE_SIMUL; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->pCodecPrivateData = HI_NULL; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->u32CodecPrivateDataSize = 0; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredOutChannels = 8; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.bInterleaved  = HI_TRUE; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32BitPerSample = 24; \
        ((HI_HADECODE_OPENPARAM_S *)(pOpenParam))->sPcmformat.u32DesiredSampleRate = 48000; \
        for (i = 0; i < HA_AUDIO_MAXCHANNELS; i++) \
        { \
            ((HI_HADECODE_OPENPARAM_S *)pOpenParam)->sPcmformat.enChannelMapping[i] = HA_AUDIO_ChannelNone; \
        } \
    }while(0)
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HISI_AUDIO_DECODER_DRA_H__ */
