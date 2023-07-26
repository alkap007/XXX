/******************************************************************************

  Copyright (C), 2012-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_video_codec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/07/31
  Description   : Common definitions of HI_CODEC(video).
                  The codec wants to register to HI_CODEC need to adapt to HI_CODEC_S.
  History       :
  1.Date        : 2012/07/31
    Author      : sdk
    Modification: Created file

*******************************************************************************/

#ifndef __HI_VIDEO_CODEC_H__
#define __HI_VIDEO_CODEC_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_type.h"

/*************************** Structure Definition ****************************/
/** \addtogroup  VCODEC  */
/** @{ */  /** <!--[VCODEC]  */

/*Codec error defination */
/**Operate fail due to insufficient resources(eg. no enough memory) */
/**CNcomment: \D7\CAԴ\B2\BB\D7㣬(\B1\E0)\BD\E2\C2\EBʧ\B0\DC*/ 
#define HI_ERR_CODEC_NOENOUGHRES    (HI_S32)(0x80510001)
/**Parameter invalid */
/**CNcomment: \B2\CE\CA\FD\CE\DEЧ*/ 
#define HI_ERR_CODEC_INVALIDPARAM   (HI_S32)(0x80510002)
/**The (en)decoding fails due to incorrect input(streams or frames) */
/**CNcomment: \CA\E4\C8\EB\CA\FD\BE\DD\D3\D0\CE\F3\A3\AC(\B1\E0)\BD\E2\C2\EB\BD\E1\CA\F8*/ 
#define HI_ERR_CODEC_INPUTCORRUPT   (HI_S32)(0x80510003)
/**The (en)decoding ends due to insufficient input data(streams or frames) */
/**CNcomment: \CA\E4\C8\EB\CA\FD\BEݲ\BB\D7㣬(\B1\E0)\BD\E2\C2\EB\BD\E1\CA\F8*/ 
#define HI_ERR_CODEC_NOENOUGHDATA   (HI_S32)(0x80510004)
/**The (en)decoding mode is not supported */
/**CNcomment: \B2\BB֧\B3ֵ\C4(\B1\E0)\BD\E2\C2\EB\C0\E0\D0\CD*/ 
#define HI_ERR_CODEC_INVALIDMODE    (HI_S32)(0x80510005)
/**Operate fail */
/**CNcomment: \B2\D9\D7\F7ʧ\B0\DC*/ 
#define HI_ERR_CODEC_OPERATEFAIL    (HI_S32)(0x80510006)
/**Version unmatch*/
/**CNcomment: \B0汾\B2\BBƥ\C5\E4*/ 
#define HI_ERR_CODEC_VERSIONUNMATCH (HI_S32)(0x80510007)
/**Unsupport operation */
/**CNcomment: \B2\BB֧\B3ֵĲ\D9\D7\F7*/
#define HI_ERR_CODEC_UNSUPPORT      (HI_S32)(0x80510008)
/**Decorder busy */
/**CNcomment: \BD\E2\C2\EB\C6\F7æ*/ 
#define HI_ERR_CODEC_BUSY           (HI_S32)(0x80510009)
/**Unknown error */
/**CNcomment: δ֪\B4\ED\CE\F3*/ 
#define HI_ERR_CODEC_UNKNOWN        (HI_S32)(0x80510010)

/**Codec ID */
/**CNcomment: Э\D2\E9\C0\E0\D0\CD */
typedef enum hiCODEC_ID_E
{
    HI_CODEC_ID_NONE = 0, 
        
    HI_CODEC_ID_VIDEO_MPEG1,
    HI_CODEC_ID_VIDEO_MPEG2,
    HI_CODEC_ID_VIDEO_MPEG2_XVMC,
    HI_CODEC_ID_VIDEO_MPEG4,      /**<MPEG4 DIVX4 DIVX5*/
    HI_CODEC_ID_VIDEO_MSMPEG4V1,
    HI_CODEC_ID_VIDEO_MSMPEG4V2,
    HI_CODEC_ID_VIDEO_MSMPEG4V3,

    HI_CODEC_ID_VIDEO_DIVX3,
    HI_CODEC_ID_VIDEO_XVID,

    HI_CODEC_ID_VIDEO_H261,
    HI_CODEC_ID_VIDEO_H263,
    HI_CODEC_ID_VIDEO_H263P,
    HI_CODEC_ID_VIDEO_H263I,
    HI_CODEC_ID_VIDEO_H264,
    HI_CODEC_ID_VIDEO_FFH264,

    HI_CODEC_ID_VIDEO_AVS,

    HI_CODEC_ID_VIDEO_REAL8,
    HI_CODEC_ID_VIDEO_REAL9,

    HI_CODEC_ID_VIDEO_VC1,
    HI_CODEC_ID_VIDEO_WMV1,
    HI_CODEC_ID_VIDEO_WMV2,
    HI_CODEC_ID_VIDEO_WMV3,

    HI_CODEC_ID_VIDEO_MSVIDEO1,

    HI_CODEC_ID_VIDEO_VP3,
    HI_CODEC_ID_VIDEO_VP5,
    HI_CODEC_ID_VIDEO_VP6,
    HI_CODEC_ID_VIDEO_VP6F,
    HI_CODEC_ID_VIDEO_VP6A,
    HI_CODEC_ID_VIDEO_VP8,
    HI_CODEC_ID_VIDEO_VP9,
    HI_CODEC_ID_VIDEO_AVS2,
    HI_CODEC_ID_VIDEO_RAW,
    HI_CODEC_ID_VIDEO_SORENSON,   /**<SORENSON SPARK*/

	HI_CODEC_ID_VIDEO_HEVC,
    HI_CODEC_ID_VIDEO_RV10,
    HI_CODEC_ID_VIDEO_RV20,
    HI_CODEC_ID_VIDEO_RV30,
    HI_CODEC_ID_VIDEO_RV40,
    
    HI_CODEC_ID_VIDEO_SVQ1,
    HI_CODEC_ID_VIDEO_SVQ3,

    HI_CODEC_ID_VIDEO_CINEPAK,
    HI_CODEC_ID_VIDEO_INDEO2,
    HI_CODEC_ID_VIDEO_INDEO3,
    HI_CODEC_ID_VIDEO_INDEO4,
    HI_CODEC_ID_VIDEO_INDEO5,

    HI_CODEC_ID_VIDEO_JPEG,
    HI_CODEC_ID_VIDEO_JPEGLS,
    HI_CODEC_ID_VIDEO_JPEG2000,
    HI_CODEC_ID_VIDEO_MJPEG,
    HI_CODEC_ID_VIDEO_MJPEGB,
    HI_CODEC_ID_VIDEO_LJPEG,

    HI_CODEC_ID_VIDEO_TIFF,
    HI_CODEC_ID_VIDEO_GIF,
    HI_CODEC_ID_VIDEO_PNG,

    HI_CODEC_ID_VIDEO_SP5X,
    
    HI_CODEC_ID_VIDEO_FLV1,
    HI_CODEC_ID_VIDEO_HUFFYUV,
    HI_CODEC_ID_VIDEO_CYUV,
    HI_CODEC_ID_VIDEO_THEORA,
    HI_CODEC_ID_VIDEO_ASV1,
    HI_CODEC_ID_VIDEO_ASV2,
    HI_CODEC_ID_VIDEO_FFV1,
    HI_CODEC_ID_VIDEO_4XM,
    HI_CODEC_ID_VIDEO_VCR1,
    HI_CODEC_ID_VIDEO_CLJR,
    HI_CODEC_ID_VIDEO_MDEC,
    HI_CODEC_ID_VIDEO_ROQ,
    HI_CODEC_ID_VIDEO_INTERPLAY_VIDEO,
    HI_CODEC_ID_VIDEO_XAN_WC3,
    HI_CODEC_ID_VIDEO_XAN_WC4,
    HI_CODEC_ID_VIDEO_RPZA,
    HI_CODEC_ID_VIDEO_WS_VQA,
    HI_CODEC_ID_VIDEO_MSRLE,
    HI_CODEC_ID_VIDEO_IDCIN,
    HI_CODEC_ID_VIDEO_8BPS,
    HI_CODEC_ID_VIDEO_SMC,
    HI_CODEC_ID_VIDEO_FLIC,
    HI_CODEC_ID_VIDEO_TRUEMOTION1,
    HI_CODEC_ID_VIDEO_VMDVIDEO,
    HI_CODEC_ID_VIDEO_MSZH,
    HI_CODEC_ID_VIDEO_ZLIB,
    HI_CODEC_ID_VIDEO_QTRLE,
    HI_CODEC_ID_VIDEO_SNOW,
    HI_CODEC_ID_VIDEO_TSCC,
    HI_CODEC_ID_VIDEO_ULTI,
    HI_CODEC_ID_VIDEO_QDRAW,
    HI_CODEC_ID_VIDEO_VIXL,
    HI_CODEC_ID_VIDEO_QPEG,
    HI_CODEC_ID_VIDEO_PPM,
    HI_CODEC_ID_VIDEO_PBM,
    HI_CODEC_ID_VIDEO_PGM,
    HI_CODEC_ID_VIDEO_PGMYUV,
    HI_CODEC_ID_VIDEO_PAM,
    HI_CODEC_ID_VIDEO_FFVHUFF,
    
    HI_CODEC_ID_VIDEO_LOCO,
    HI_CODEC_ID_VIDEO_WNV1,
    HI_CODEC_ID_VIDEO_AASC,
    HI_CODEC_ID_VIDEO_FRAPS,
    HI_CODEC_ID_VIDEO_TRUEMOTION2,
    HI_CODEC_ID_VIDEO_BMP,
    HI_CODEC_ID_VIDEO_CSCD,
    HI_CODEC_ID_VIDEO_MMVIDEO,
    HI_CODEC_ID_VIDEO_ZMBV,
    HI_CODEC_ID_VIDEO_SMACKVIDEO,
    HI_CODEC_ID_VIDEO_NUV,
    HI_CODEC_ID_VIDEO_KMVC,
    HI_CODEC_ID_VIDEO_FLASHSV,
    HI_CODEC_ID_VIDEO_CAVS,
    
    HI_CODEC_ID_VIDEO_VMNC,
    
    HI_CODEC_ID_VIDEO_TARGA,
    HI_CODEC_ID_VIDEO_DSICINVIDEO,
    HI_CODEC_ID_VIDEO_TIERTEXSEQVIDEO,
    
    HI_CODEC_ID_VIDEO_DXA,
    HI_CODEC_ID_VIDEO_DNXHD,
    HI_CODEC_ID_VIDEO_THP,
    HI_CODEC_ID_VIDEO_SGI,
    HI_CODEC_ID_VIDEO_C93,
    HI_CODEC_ID_VIDEO_BETHSOFTVID,
    HI_CODEC_ID_VIDEO_PTX,
    HI_CODEC_ID_VIDEO_TXD,
    HI_CODEC_ID_VIDEO_AMV,
    HI_CODEC_ID_VIDEO_VB,
    HI_CODEC_ID_VIDEO_PCX,
    HI_CODEC_ID_VIDEO_SUNRAST,
    HI_CODEC_ID_VIDEO_MIMIC,
    HI_CODEC_ID_VIDEO_RL2,
    HI_CODEC_ID_VIDEO_8SVX_EXP,
    HI_CODEC_ID_VIDEO_8SVX_FIB,
    HI_CODEC_ID_VIDEO_ESCAPE124,
    HI_CODEC_ID_VIDEO_DIRAC,
    HI_CODEC_ID_VIDEO_BFI,
    HI_CODEC_ID_VIDEO_CMV,
    HI_CODEC_ID_VIDEO_MOTIONPIXELS,
    HI_CODEC_ID_VIDEO_TGV,
    HI_CODEC_ID_VIDEO_TGQ,
    HI_CODEC_ID_VIDEO_TQI,
    HI_CODEC_ID_VIDEO_AURA,
    HI_CODEC_ID_VIDEO_AURA2,
    HI_CODEC_ID_VIDEO_V210X,
    HI_CODEC_ID_VIDEO_TMV,
    HI_CODEC_ID_VIDEO_V210,
    HI_CODEC_ID_VIDEO_DPX,
    HI_CODEC_ID_VIDEO_MAD,
    HI_CODEC_ID_VIDEO_FRWU,
    HI_CODEC_ID_VIDEO_FLASHSV2,
    HI_CODEC_ID_VIDEO_CDGRAPHICS,
    HI_CODEC_ID_VIDEO_R210,
    HI_CODEC_ID_VIDEO_ANM,
    HI_CODEC_ID_VIDEO_BINKVIDEO,
    HI_CODEC_ID_VIDEO_IFF_ILBM,
    HI_CODEC_ID_VIDEO_IFF_BYTERUN1,
    HI_CODEC_ID_VIDEO_KGV1,
    HI_CODEC_ID_VIDEO_YOP,
    HI_CODEC_ID_VIDEO_DV,
    HI_CODEC_ID_BUTT
}HI_CODEC_ID_E;

/*BIT0 of HI_CODEC_SUPPORT_S.u32Type: Driven type */
/**Need be driven by codec manager. Like FFMPEG. */ /**CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7\D0\E8Ҫ\B9\DC\C0\ED\C6\F7\C7\FD\B6\AF */
#define HI_CODEC_CAP_DRIVENOUTSIDE      (0x00000000)
/**Self-driven, only need call Start()/Stop(). Like VFMW. */ /**CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7\D3\D0\D7\D4\C7\FD\B6\AF\C4\DC\C1\A6 */
#define HI_CODEC_CAP_DRIVENSELF         (0x00000001)

/*BIT1 of HI_CODEC_SUPPORT_S.u32Type: Output type */
/**Codec outputs frame or stream to specified address directly.  */ /**CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7֧\B3ֽ\AB֡\CA\FD\BEݻ\F2\C1\F7\CA\FD\BE\DD\CA\E4\B3\F6\B5\BDָ\B6\A8\B5\D8ַ */
#define HI_CODEC_CAP_OUTPUT2SELFADDR    (0x00000000)
/**Codec outputs frame or stream to the address self allocated . */ /**CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7\BD\AB֡\CA\FD\BEݻ\F2\C1\F7\CA\FD\BE\DD\CA\E4\B3\F6\B5\BD\D7\D4\C9\ED\B5\D8ַ\A3\AC\D0\E8Ҫ\CDⲿ\BF\BD\B1\B4 */
#define HI_CODEC_CAP_OUTPUT2SPECADDR    (0x00000002)

/**Defines codec type: encoder or decoder  */
/**CNcomment:Codec\C0\E0\D0\CD:\B1\E0\C2\EB\BB\F2\BD\E2\C2\EB*/ 
typedef enum hiCODEC_TYPE_E
{
    HI_CODEC_TYPE_DEC = 0x01,       /**<decoder, value is b00000001*/ /**< CNcomment:\BD\E2\C2\EB\C6\F7 */
    HI_CODEC_TYPE_ENC = 0x02,       /**<encoder, value is b00000010*/ /**< CNcomment:\B1\E0\C2\EB\C6\F7 */
    
    HI_CODEC_TYPE_BUTT
}HI_CODEC_TYPE_E;

/**Defines codec types and formats */
/**CNcomment:Codec\C0\E0\D0\CD\D3\EB֧\B3ֵ\C4Э\D2\E9*/ 
typedef struct hiCODEC_SUPPORT_S
{
    HI_U32          u32Type;            /**< Codec type, OR value of HI_CODEC_TYPE_E */ /**< CNcomment:Codec\C0\E0\D0ͣ\ACHI_CODEC_TYPE_E\B5Ļ\F2ֵ */
    HI_CODEC_ID_E   enID;               /**< Codec ID*/ /**< CNcomment:Codec֧\B3ֵ\C4Э\D2\E9\C0\E0\D0\CD */
    struct hiCODEC_SUPPORT_S* pstNext;  /**< Pointer to next node*/ /**< CNcomment:ָ\CF\F2\CF\C2һ\B8\F6\C4\DC\C1\A6\BD\E1\B5\E3\B5\C4ָ\D5\EB */
}HI_CODEC_SUPPORT_S;

/**Defines codec capability */
/**CNcomment:Codec\C4\DC\C1\A6*/ 
typedef struct hiCODEC_CAP_S
{
    HI_U32              u32CapNumber;   /**< Codec capability index, OR value of several HI_CODEC_CAP_XXX */ /**< CNcomment:Codec\C4\DC\C1\A6ָʾֵ\A3\ACHI_CODEC_CAP_XXX\B5Ļ\F2ֵ */
    HI_CODEC_SUPPORT_S* pstSupport;     /**< Pointer to the support type and formats*/ /**< CNcomment:Codec\C4\DC\C1\A6\BDṹ\CC\E5ָ\D5\EB */
}HI_CODEC_CAP_S;

/**Defines the codec version*/
/**CNcomment:\B0汾\B6\A8\D2\E5*/ 
typedef union hiCODEC_VERSION_U
{
    struct
    {
        HI_U8 u8VersionMajor;           /**< Major version */ /**< CNcomment:\D6\F7\B0汾\BA\C5 */
        HI_U8 u8VersionMinor;           /**< Minor version */ /**< CNcomment:\B4ΰ汾\BA\C5 */
        HI_U8 u8Revision;               /**< Revision version */ /**< CNcomment:\D0޶\A9\B0汾\BA\C5 */
        HI_U8 u8Step;                   /**< Step version */ /**< CNcomment:\B2\BD\BD\F8\B0汾\BA\C5 */
    } stVersion;
    HI_U32 u32Version;
} HI_CODEC_VERSION_U;

/**Defines video decoder open parameter*/
/**CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B4򿪲\CE\CA\FD*/ 
typedef struct hiCODEC_VDEC_OPENPARAM_S
{
    HI_U32 u32Reserve;
    HI_VOID* pPlatformPriv;         /**< Special parameter for platform hardware codec */ /**< CNcomment:Ӳ\BD\E2\C2\EB\C6\F7˽\D3в\CE\CA\FD */
}HI_CODEC_VDEC_OPENPARAM_S;

/**Defines video encoder open parameter*/
/**CNcomment:\CA\D3Ƶ\B1\E0\C2\EB\C6\F7\B4򿪲\CE\CA\FD*/ 
typedef struct hiCODEC_VENC_OPENPARAM_S
{
    HI_U32 u32Reserve;
}HI_CODEC_VENC_OPENPARAM_S;

/**Defines the codec open parameters*/
/**CNcomment:ʵ\C0\FD\B4\B4\BD\A8\B2\CE\CA\FD*/
typedef struct hiCODEC_OPENPARAM_S
{
    HI_CODEC_TYPE_E enType;       /** Encode or Decode */ /**< CNcomment:\B4\B4\BD\A8\B1\E0\C2\EB\C6\F7\BB\B9\CAǽ\E2\C2\EB\C6\F7 */
    HI_CODEC_ID_E enID;           /** Format */ /**< CNcomment:\D0\E8Ҫ\B1\E0\C2\EB\BB\F2\BD\E2\C2\EB\B5\C4Э\D2\E9\C0\E0\D0\CD */
    union {
        HI_CODEC_VDEC_OPENPARAM_S stVdec; /** Open parameters of video decoder */ /**< CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B4\B4\BD\A8\B2\CE\CA\FD */
        HI_CODEC_VENC_OPENPARAM_S stVenc; /** Open parameters of video encoder */ /**< CNcomment:\CA\D3Ƶ\B1\E0\C2\EB\C6\F7\B4\B4\BD\A8\B2\CE\CA\FD */
    }unParam;
} HI_CODEC_OPENPARAM_S;

/**Defines the codec max priority */
/**CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7\D7\EE\B4\F3\D3\C5\CFȼ\B6\B6\A8\D2\E5*/
#define HI_CODEC_MAX_PRIORITY (16)

/**Defines attribute of video decoder */
/**CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\C6\F7ʵ\C0\FD\CA\F4\D0\D4*/
typedef struct hiCODEC_VDEC_ATTR_S
{
    HI_VOID*                pCodecContext;  /**< Codec context */ /**< CNcomment:\B1\E0\BD\E2\C2\EB\C6\F7\C9\CF\CF\C2\CEģ\AC\BF\C9\D2Դ\AB\B5ݽ\E2\C2\EB\C6\F7\CCض\A8\B2\CE\CA\FD */
    HI_VOID*                pPlatformPriv;  /**< Only used by platform */ /**< CNcomment:Ӳ\BD\E2\C2\EB\C6\F7˽\D3в\CE\CA\FD */
} HI_CODEC_VDEC_ATTR_S;

/**Defines attribute of codec instance */
/**CNcomment:ʵ\C0\FD\CA\F4\D0\D4*/
typedef struct hiCODEC_ATTR_S
{
    HI_CODEC_ID_E           enID;   /**< Codec ID*/ /**< CNcomment:\B1\E0\C2\EB\BB\F2\BD\E2\C2\EB\B5\C4Э\D2\E9\C0\E0\D0\CD*/
    union {
        HI_CODEC_VDEC_ATTR_S stVdec;/**< Instance attribute*/ /**< CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\CA\F4\D0Բ\CE\CA\FD*/
    } unAttr;
} HI_CODEC_ATTR_S;

/**Defines video sub standard */
/**CNcomment: \CA\D3ƵЭ\D2\E9\B7\D6֧\B1\EA׼ */
typedef enum hiCODEC_VIDEO_SUB_STANDARD_E
{
    HI_CODEC_VIDEO_SUB_STANDARD_UNKNOWN,       /**<Unknown*/ /**<CNcomment: δ֪Э\D2\E9\B7\D6֧*/
    HI_CODEC_VIDEO_SUB_STANDARD_MPEG2_MPEG1,   /**<The MPEG2 protocol family is compatible with MPEG1.*/ /**<CNcomment: MPEG2Э\D2\E9\D7\E5\BF\C9\D2Լ\E6\C8\DDMPEG1 */
    HI_CODEC_VIDEO_SUB_STANDARD_MPEG4_SHV,     /**<The MPEG4 protocol family is compatible with SHV.*/ /**<CNcomment: MPEG4Э\D2\E9\D7\E5\BF\C9\D2Լ\E6\C8\DDSHV*/
    HI_CODEC_VIDEO_SUB_STANDARD_MPEG4_XVID,    /**<The MPEG4 protocol family includes the sub protocol XVID.*/ /**<CNcomment: MPEG4Э\D2\E9\B0\FC\BA\ACXVID\B7\D6֧*/
    HI_CODEC_VIDEO_SUB_STANDARD_MPEG4_DIVX,    /**<The MPEG4 protocol family includes the sub protocol DIVX.*/ /**<CNcomment: MPEG4Э\D2\E9\B0\FC\BA\ACDIVX\B7\D6֧*/

    HI_CODEC_VIDEO_SUB_STANDARD_BUTT
}HI_CODEC_VIDEO_SUB_STANDARD_E;

/**Defines the video norm*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\D6\C6ʽö\BE\D9*/
typedef enum hiCODEC_ENC_FMT_E
{
    HI_CODEC_ENC_FMT_1080P_60 = 0,     /**<1080p 60 Hz*/ /**< CNcomment:1080p 60\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_1080P_50,         /**<1080p 50 Hz*/ /**< CNcomment:1080p 50\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_1080P_30,         /**<1080p 30 Hz*/ /**< CNcomment:1080p 30\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_1080P_25,         /**<1080p 25 Hz*/ /**< CNcomment:1080p 25\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_1080P_24,         /**<1080p 24 Hz*/ /**< CNcomment:1080p 24\BA\D5\D7\C8*/

    HI_CODEC_ENC_FMT_1080i_60,         /**<1080i 60 Hz*/ /**< CNcomment:1080i 60\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_1080i_50,         /**<1080i 50 Hz*/ /**< CNcomment:1080i 50\BA\D5\D7\C8*/

    HI_CODEC_ENC_FMT_720P_60,          /**<720p 60 Hz*/  /**< CNcomment:720p 60\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_720P_50,          /**<720p 50 Hz */ /**< CNcomment:720p 50\BA\D5\D7\C8*/

    HI_CODEC_ENC_FMT_576P_50,          /**<576p 50 Hz*/  /**< CNcomment:576p 50\BA\D5\D7\C8*/
    HI_CODEC_ENC_FMT_480P_60,          /**<480p 60 Hz*/  /**< CNcomment:480p 60\BA\D5\D7\C8*/

    HI_CODEC_ENC_FMT_PAL,              /**<B D G H I PAL */ /**< CNcomment:B D G H I PAL\D6\C6ʽ*/
    HI_CODEC_ENC_FMT_PAL_N,            /**<(N)PAL        */ /**< CNcomment:(N)PAL\D6\C6ʽ*/
    HI_CODEC_ENC_FMT_PAL_Nc,           /**<(Nc)PAL       */ /**< CNcomment:(Nc)PAL\D6\C6ʽ*/

    HI_CODEC_ENC_FMT_NTSC,             /**<(M)NTSC       */ /**< CNcomment:(M)NTSC\D6\C6ʽ*/
    HI_CODEC_ENC_FMT_NTSC_J,           /**<NTSC-J        */ /**< CNcomment:NTSC-J\D6\C6ʽ*/
    HI_CODEC_ENC_FMT_NTSC_PAL_M,       /**<(M)PAL        */ /**< CNcomment:(M)PAL\D6\C6ʽ*/

    HI_CODEC_ENC_FMT_SECAM_SIN,        /**< SECAM_SIN*/ /**< CNcomment:SECAM_SIN\D6\C6ʽ*/
    HI_CODEC_ENC_FMT_SECAM_COS,        /**< SECAM_COS*/ /**< CNcomment:SECAM_COS\D6\C6ʽ*/

    HI_CODEC_ENC_FMT_1080P_24_FRAME_PACKING,
    HI_CODEC_ENC_FMT_720P_60_FRAME_PACKING,
    HI_CODEC_ENC_FMT_720P_50_FRAME_PACKING,
    
    HI_CODEC_ENC_FMT_861D_640X480_60,
    HI_CODEC_ENC_FMT_VESA_800X600_60,
    HI_CODEC_ENC_FMT_VESA_1024X768_60,
    HI_CODEC_ENC_FMT_VESA_1280X720_60,
    HI_CODEC_ENC_FMT_VESA_1280X800_60,
    HI_CODEC_ENC_FMT_VESA_1280X1024_60,
    HI_CODEC_ENC_FMT_VESA_1360X768_60,
    HI_CODEC_ENC_FMT_VESA_1366X768_60,
    HI_CODEC_ENC_FMT_VESA_1400X1050_60,
    HI_CODEC_ENC_FMT_VESA_1440X900_60,
    HI_CODEC_ENC_FMT_VESA_1440X900_60_RB,
    HI_CODEC_ENC_FMT_VESA_1600X900_60_RB,
    HI_CODEC_ENC_FMT_VESA_1600X1200_60,
    HI_CODEC_ENC_FMT_VESA_1680X1050_60,
    HI_CODEC_ENC_FMT_VESA_1920X1080_60,
    HI_CODEC_ENC_FMT_VESA_1920X1200_60,
    HI_CODEC_ENC_FMT_VESA_2048X1152_60,

    HI_CODEC_ENC_FMT_BUTT
}HI_CODEC_ENC_FMT_E;

/**Defines the video YUV format*/
/**CNcomment: YUV\B8\F1ʽö\BE\D9*/
typedef enum hiCODEC_COLOR_FORMAT_E
{
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_400 = 0,   /**<The YUV spatial sampling format is SEMIPLANAR 4:0:0.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:0:0*/
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_411,       /**<The YUV spatial sampling format is SEMIPLANAR 4:1:1.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:1:1*/
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_420,       /**<The YUV spatial sampling format is SEMIPLANAR 4:2:0.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:2:0*/
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_422_1X2,   /**<The YUV spatial sampling format is SEMIPLANAR 4:2:2,two Y correspond to one U and V at vertical direction.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:2:2\A3\AC\B4\B9ֱ\B7\BD\CF\F2\C1\BD\B8\F6\C1\C1\B6Ȳ\C9\D1\F9\B5㹲\D3\C3һ\B6\D4ɫ\B6Ȳ\C9\D1\F9\B5\E3*/
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_422_2X1,   /**<The YUV spatial sampling format is SEMIPLANAR 4:2:2,two Y correspond to one U and V at horizontal direction.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:2:2\A3\ACˮƽ\B7\BD\CF\F2\C1\BD\B8\F6\C1\C1\B6Ȳ\C9\D1\F9\B5㹲\D3\C3һ\B6\D4ɫ\B6Ȳ\C9\D1\F9\B5\E3*/
    HI_CODEC_COLOR_FORMAT_YUV_SEMIPLANAR_444,       /**<The YUV spatial sampling format is SEMIPLANAR 4:4:4.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪSEMIPLANAR 4:4:4*/

    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_400 = 0x10,    /**<The YUV spatial sampling format is PLANAR 4:0:0.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:0:0*/   
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_411,           /**<The YUV spatial sampling format is PLANAR 4:1:1.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:1:1*/   
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_420,           /**<The YUV spatial sampling format is PLANAR 4:2:0.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:2:0*/   
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_422_1X2,       /**<The YUV spatial sampling format is PLANAR 4:2:2,two Y correspond to one U and V at vertical direction.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:2:2\A3\AC\B4\B9ֱ\B7\BD\CF\F2\C1\BD\B8\F6\C1\C1\B6Ȳ\C9\D1\F9\B5㹲\D3\C3һ\B6\D4ɫ\B6Ȳ\C9\D1\F9\B5\E3*/
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_422_2X1,       /**<The YUV spatial sampling format is PLANAR 4:2:2,two Y correspond to one U and V at horizontal direction.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:2:2\A3\ACˮƽ\B7\BD\CF\F2\C1\BD\B8\F6\C1\C1\B6Ȳ\C9\D1\F9\B5㹲\D3\C3һ\B6\D4ɫ\B6Ȳ\C9\D1\F9\B5\E3*/
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_444,           /**<The YUV spatial sampling format is PLANAR 4:4:4.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:4:4*/   
    HI_CODEC_COLOR_FORMAT_YUV_PLANAR_410,           /**<The YUV spatial sampling format is PLANAR 4:1:0.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪPLANAR 4:1:0*/   
    
    HI_CODEC_COLOR_FORMAT_YUV_PACKAGE_UYVY422 = 0x20,   /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is UYVY.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪUYVY*/
    HI_CODEC_COLOR_FORMAT_YUV_PACKAGE_YUYV422,          /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is YUYV.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪYUYV*/
    HI_CODEC_COLOR_FORMAT_YUV_PACKAGE_YVYU422,          /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is YVYU.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪYVYU*/
    HI_CODEC_COLOR_FORMAT_YUV_BUTT
}HI_CODEC_COLOR_FORMAT_E;

/**Defines the type of the video frame*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ֡\B5\C4\C0\E0\D0\CDö\BE\D9*/
typedef enum hiCODEC_VIDEO_FRAME_TYPE_E
{
    HI_CODEC_VIDEO_FRAME_TYPE_UNKNOWN,   /**<Unknown*/ /**<CNcomment: δ֪\B5\C4֡\C0\E0\D0\CD*/
    HI_CODEC_VIDEO_FRAME_TYPE_I,         /**<I frame*/ /**<CNcomment: I֡*/
    HI_CODEC_VIDEO_FRAME_TYPE_P,         /**<P frame*/ /**<CNcomment: P֡*/
    HI_CODEC_VIDEO_FRAME_TYPE_B,         /**<B frame*/ /**<CNcomment: B֡*/
    HI_CODEC_VIDEO_FRAME_TYPE_BUTT
}HI_CODEC_VIDEO_FRAME_TYPE_E;

/**Defines the video frame/field mode*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ֡\B3\A1ģʽö\BE\D9*/
typedef enum hiCODEC_VIDEO_FIELD_MODE_E
{
    HI_CODEC_VIDEO_FIELD_ALL,        /**<Frame mode*/ /**<CNcomment: ֡ģʽ*/
    HI_CODEC_VIDEO_FIELD_TOP,        /**<Top field mode*/ /**<CNcomment: \B6\A5\B3\A1ģʽ*/
    HI_CODEC_VIDEO_FIELD_BOTTOM,     /**<Bottom field mode*/ /**<CNcomment: \B5׳\A1ģʽ*/
    HI_CODEC_VIDEO_FIELD_BUTT
}HI_CODEC_VIDEO_FIELD_MODE_E;

/**Defines 3D frame packing type*/
/**CNcomment: 3D֡\B4\F2\B0\FC\B7\BDʽ */
typedef enum hiCODEC_VIDEO_FRAME_PACKING_TYPE_E
{
    HI_CODEC_VIDEO_FRAME_PACKING_NONE,              /**< normal frame, not a 3D frame */ /**<CNcomment: \B7\C73D֡*/
    HI_CODEC_VIDEO_FRAME_PACKING_SIDE_BY_SIDE,      /**< side by side */ /**<CNcomment:\D7\F3\D3\D2ģʽ3D֡ */
    HI_CODEC_VIDEO_FRAME_PACKING_TOP_AND_BOTTOM,    /**< top and bottom */ /**<CNcomment:\C9\CF\CF\C2ģʽ3D֡ */
    HI_CODEC_VIDEO_FRAME_PACKING_TIME_INTERLACED,   /**< time interlaced: one frame for left eye, the next frame for right eye */ /**<CNcomment:ʱ\BC\E4\B2\EEģʽ3D֡ */
    HI_CODEC_VIDEO_FRAME_PACKING_BUTT             
}HI_CODEC_VIDEO_FRAME_PACKING_TYPE_E;

/**Defines address information*/
/**CNcomment: \B5\D8ַ\C3\E8\CA\F6\BDṹ\CC\E5*/
typedef struct hiCODEC_ADDRESS_S
{
    HI_U8   *pu8Vir;             /**<Virtual address of (frame or stream) buffer */ /**<CNcomment: ֡\BB\F2\C1\F7\CA\FD\BEݵ\C4\D0\E9\C4\E2\B5\D8ַ */
    HI_U32  u32Phy;             /**<Physical address of (frame or stream) buffer */ /**<CNcomment: ֡\BB\F2\C1\F7\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ */
    HI_U32  u32Size;            /**<Size of (frame or stream) buffer*/ /**<CNcomment: ֡\BB\F2\C1\F7\CA\FD\BEݵĴ\F3С */
}HI_CODEC_ADDRESS_S;

/**Defines the pixel width.*/
/**CNcomment: \B6\A8\D2\E5\CF\F1\CB\D8λ\BF\ED*/
typedef enum hiCODEC_PIXEL_BITWIDTH_E
{
    HI_CODEC_PIXEL_BITWIDTH_8BIT = 0,
    HI_CODEC_PIXEL_BITWIDTH_10BIT,
    HI_CODEC_PIXEL_BITWIDTH_12BIT,
    HI_CODEC_PIXEL_BITWIDTH_BUTT,
} HI_CODEC_PIXEL_BITWIDTH_E;

/**Defines color space enum*/
/**CNcomment: \B6\A8\D2\E5\D1\D5ɫ\BFռ\E4ö\BE\D9*/
typedef enum hiCODEC_COLOR_SPACE_E
{
    HI_CODEC_COLOR_SPACE_UNKNOWN = 0,

    HI_CODEC_COLOR_SPACE_BT601_YUV_LIMITED = 0x10,/* ::::Current Used:::: BT.601  */
    HI_CODEC_COLOR_SPACE_BT601_YUV_FULL,
    HI_CODEC_COLOR_SPACE_BT601_RGB_LIMITED,
    HI_CODEC_COLOR_SPACE_BT601_RGB_FULL,

    HI_CODEC_COLOR_SPACE_NTSC1953 = 0x20,

    /* These should be useful.  Assume 601 extents. */
    HI_CODEC_COLOR_SPACE_BT470_SYSTEM_M = 0x30,
    HI_CODEC_COLOR_SPACE_BT470_SYSTEM_BG,

    HI_CODEC_COLOR_SPACE_BT709_YUV_LIMITED = 0x40,/* ::::Current Used:::: BT.709 */
    HI_CODEC_COLOR_SPACE_BT709_YUV_FULL,
    HI_CODEC_COLOR_SPACE_BT709_RGB_LIMITED,
    HI_CODEC_COLOR_SPACE_BT709_RGB_FULL,
    HI_CODEC_COLOR_SPACE_BT2020_YUV_LIMITED,/* ::::Current Used:::: BT.2020 */
    HI_CODEC_COLOR_SPACE_BT2020_YUV_FULL,
    HI_CODEC_COLOR_SPACE_BT2020_RGB_LIMITED,
    HI_CODEC_COLOR_SPACE_BT2020_RGB_FULL,   /* ::::Current Used:::: */

    HI_CODEC_COLOR_SPACE_REC709 = 0x50,      /* HD and modern captures. */

    HI_CODEC_COLOR_SPACE_SMPT170M= 0x60, /* ITU-R 601 -- broadcast NTSC/PAL */
    HI_CODEC_COLOR_SPACE_SMPT240M, /* 1125-Line (US) HDTV */

    HI_CODEC_COLOR_SPACE_BT878 = 0x70,    /* broken BT878 extents
                           (601, luma range 16-253 instead of 16-235) */

    HI_CODEC_COLOR_SPACE_XVYCC = 0x80,

    /* I know there will be cameras that send this.  So, this is
     * unspecified chromaticities and full 0-255 on each of the
     * Y'CbCr components
     */
    HI_CODEC_COLOR_SPACE_JPEG = 0x90,
    HI_CODEC_COLOR_SPACE_RGB = 0xa0,

    HI_CODEC_COLOR_SPACE_BUTT
}HI_CODEC_COLOR_SPACE_E;

/**Defines video stream info */
/** CNcomment: \CA\D3Ƶ\C1\F7\D0\C5Ϣ\BDṹ\CC\E5*/
typedef struct hiCODEC_VIDEO_STREAMINFO_S
{
    HI_CODEC_ID_E                   enCodecID;      /**<Stream type*/ /**<CNcomment: \C2\EB\C1\F7\C0\E0\D0\CD */
    HI_CODEC_VIDEO_SUB_STANDARD_E   enSubStandard;  /**<Sub stream protocol*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4Э\D2\E9\B7\D6֧ */
    HI_U32                          u32SubVersion;  /**<Version of the sub stream protocol*/ /**<CNcomment: \C2\EB\C1\F7\D7\D3Э\D2\E9\B0汾\BA\C5 */
    HI_U32                          u32Profile;     /**<Stream profile*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4profile */
    HI_U32                          u32Level;       /**<Stream level*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4level */
    HI_CODEC_ENC_FMT_E              enDisplayNorm;  /**<Display norm*/ /**<CNcomment: \CF\D4ʾ\B1\EA׼ */
    HI_BOOL                         bProgressive;   /**<Sampling type (progressive or interlaced)*/ /**<CNcomment: \B2\C9\D1\F9\B7\BDʽ(\D6\F0\D0\D0/\B8\F4\D0\D0) */

    HI_U32                          u32AspectWidth; /**<Aspect width*/ /**<CNcomment: \D7\EE\BC\D1\CF\D4ʾ\B7\F9\D0ͱ\C8֮\BF\ED\B6ȱ\C8ֵ*/
    HI_U32                          u32AspectHeight;/**<Aspect height*/ /**<CNcomment: \D7\EE\BC\D1\CF\D4ʾ\B7\F9\D0ͱ\C8֮\B8߶ȱ\C8ֵ*/

    HI_U32 u32bps;            /**<Bit rate, in kbit/s*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4\C2\EB\C2\CA, Kbps */
    HI_U32 u32FrameRateInt;   /**<Integral part of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4\D5\FB\CA\FD\B2\BF\B7\D6, fps */
    HI_U32 u32FrameRateDec;   /**<Fractional part (calculated to three decimal places) of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4С\CA\FD\B2\BF\B7֣\A8\B1\A3\C1\F43λ\A3\A9, fps */
    HI_U32 u32Width;          /**<Width of the decoded picture*/ /**<CNcomment: \BD\E2\C2\EBͼ\CF\F1\BF\ED */
    HI_U32 u32Height;         /**<Height of the decoded picture*/ /**<CNcomment: \BD\E2\C2\EBͼ\CF\F1\B8\DF */
    HI_U32 u32DisplayWidth;   /**<Width of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\BF\ED */
    HI_U32 u32DisplayHeight;  /**<Height of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\B8\DF */
    HI_U32 u32DisplayCenterX; /**<Horizontal coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/
                              /**<CNcomment: \CF\D4ʾͼ\CF\F1\D6\D0\D0ĺ\E1\D7\F8\B1꣬\D2\D4ԭʼͼ\CF\F1\B5\C4\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3 */
    HI_U32 u32DisplayCenterY; /**<Vertical coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/
                              /**<CNcomment: \CF\D4ʾͼ\CF\F1\D6\D0\D0\C4\D7\DD\D7\F8\B1꣬\D2\D4ԭʼͼ\CF\F1\B5\C4\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3 */
    HI_CODEC_PIXEL_BITWIDTH_E enBitWidth; /**<Bit width decoded from stream*/ /**<CNcomment: \CA\D3Ƶ\CF\F1\CB\D8λ\BF\ED*/
    HI_CODEC_COLOR_SPACE_E      enSrcColorSpace;/**<Color space decoded from stream*/ /**<CNcomment: \D1\D5ɫɫ\D3\F2\BFռ\E4*/
}HI_CODEC_VIDEO_STREAMINFO_S;

/**Defines stream information */
/**CNcomment: \C2\EB\C1\F7\D0\C5Ϣ\BDṹ\CC\E5*/
typedef union hiCODEC_STREAMINFO_S
{
    HI_CODEC_VIDEO_STREAMINFO_S stVideo;    /**<video stream information*/ /**<CNcomment: \CA\D3Ƶ\C1\F7\D0\C5Ϣ*/
}HI_CODEC_STREAMINFO_S;

typedef struct hiCODEC_FRAME_BUF_S
{
	HI_U32 u32PhyAddr;
	HI_U32 u32Size;
}HI_CODEC_FRAME_BUF_S;

/**Defines stream descriptor */
/**CNcomment: \C2\EB\C1\F7\CA\FD\BEݽṹ\CC\E5*/
typedef struct hiCODEC_STREAM_S
{
    HI_U8* pu8Addr;     /**<Stream buffer address*/ /**<CNcomment: \C1\F7\CA\FD\BEݵ\D8ַ*/
	HI_U32 u32PhyAddr;  /**<Stream buffer address*/ /**<CNcomment: \C1\F7\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ*/
    HI_U32 u32Size;     /**<Stream buffer size*/ /**<CNcomment: \C1\F7\CA\FD\BEݴ\F3С*/
    HI_S64 s64PtsMs;    /**<PTS(ms)*/ /**<CNcomment: \C1\F7\CA\FD\BEݶ\D4ӦPTS\A3\AC\BA\C1\C3\EBΪ\B5\A5λ*/
}HI_CODEC_STREAM_S;

/**Defines video codec comonds */
/**CNcomment: \CA\D3Ƶ\B1\E0\BD\E2\C2\EB\C6\F7\BF\D8\D6\C6\C3\FC\C1\EE\BDṹ\CC\E5*/
typedef struct hiCODEC_VIDEO_CMD_S
{
    HI_U32      u32CmdID;   /**<Commond ID*/ /**<CNcomment: \C3\FC\C1\EEID*/
    HI_VOID     *pPara;     /**<Control parameter*/ /**<CNcomment: \C3\FC\C1\EEЯ\B4\F8\B2\CE\CA\FD*/
}HI_CODEC_VIDEO_CMD_S;

/**Defines video frame information*/
/**CNcomment: \CA\D3Ƶ֡\D0\C5Ϣ\BDṹ\CC\E5*/
typedef struct hiCODEC_VIDEO_FRAME_S
{
    HI_CODEC_COLOR_FORMAT_E             enColorFormat;        /**<Video format*/ /**<CNcomment: \CA\D3Ƶ\B8\F1ʽ*/
    HI_CODEC_VIDEO_FRAME_TYPE_E         enFrameType;          /**<Frame type*/ /**<CNcomment: ֡\C0\E0\D0\CD*/
    HI_BOOL                             bProgressive;         /**<Sampling type*/ /**<CNcomment: \B2\C9\D1\F9\C0\E0\D0\CD*/
    
    HI_CODEC_VIDEO_FIELD_MODE_E         enFieldMode;          /**<Frame or field encoding mode*/ /**<CNcomment: ֡\BB򳡱\E0\C2\EBģʽ*/
    HI_BOOL                             bTopFieldFirst;       /**<Top field first flag*/ /**<CNcomment: \B6\A5\B3\A1\D3\C5\CFȱ\EA־*/

    HI_CODEC_VIDEO_FRAME_PACKING_TYPE_E enFramePackingType;   /**<3D frame packing type*/ /**<CNcomment: 3D֡\B4\F2\B0\FC\B7\BDʽ*/
    
    HI_U32                              u32FrameRate;         /**<Frame rate*//**<CNcomment: ֡\C2\CA*/
    
    HI_U32                              u32Width;             /**<Width of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\BF\ED*/
    HI_U32                              u32Height;            /**<Height of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\B8\DF*/
    HI_U32                              u32AspectWidth;       /**<Aspect width*/ /**<CNcomment: \D7\EE\BC\D1\CF\D4ʾ\BF\ED\B6\C8*/
    HI_U32                              u32AspectHeight;      /**<Aspect height*/ /**<CNcomment: \D7\EE\BC\D1\CF\D4ʾ\B8߶\C8*/

    HI_U32                              u32YAddr;             /**<Address of the Y component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡Y\B7\D6\C1\BF\CA\FD\BEݵĵ\D8ַ*/
    HI_U32                              u32UAddr;             /**<Address of the U component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡U\B7\D6\C1\BF\CA\FD\BEݵĵ\D8ַ*/
    HI_U32                              u32VAddr;             /**<Address of the V component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡V\B7\D6\C1\BF\CA\FD\BEݵĵ\D8ַ*/
    HI_U32                              u32YStride;           /**<Stride of the Y component*/ /**<CNcomment: Y\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/
    HI_U32                              u32UStride;           /**<Stride of the U component*/ /**<CNcomment: C\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/
    HI_U32                              u32VStride;           /**<Stride of the V component*/ /**<CNcomment: C\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/

    HI_U8*                              pu8UserData;          /**<User data *//**<CNcomment: \D3û\A7\CA\FD\BE\DD*/
    HI_U32                              u32UserDataSize;      /**<User data size *//**<CNcomment: \D3û\A7\CA\FD\BEݳ\A4\B6\C8*/
}HI_CODEC_VIDEO_FRAME_S;

/**Defines frame descriptor */
/**CNcomment: ֡\C3\E8\CA\F6\BDṹ\CC\E5*/
typedef struct hiCODEC_FRAME_S
{
    HI_CODEC_ADDRESS_S          stOutputAddr;   /**< Always [in], only used by the codecs which support HI_CODEC_OUTPUT_TOSPECADDR, Only used by decoder  */
                                                /**< CNcomment: ֡\CA\E4\B3\F6\B5\D8ַ\A3\ACһֱ\CA\C7\CA\E4\C8\EB\B2\CE\CA\FD\A3\AC\BD\F6\CA\CA\D3\C3\D3\DA֧\B3\D6HI_CODEC_OUTPUT_TOSPECADDR\B5Ľ\E2\C2\EB\C6\F7 */
    HI_S64                      s64SrcPtsMs;    /**< Decoder [out], encoder [in], The source pts(ms) */
                                                /**< CNcomment: ֡ԴPTS\A3\AC\BA\C1\C3\EBΪ\B5\A5λ\A3\AC\B6Խ\E2\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\B3\F6\B2\CE\CA\FD\A3\AC\B6Ա\E0\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\C8\EB\B2\CE\CA\FD*/
    HI_S64                      s64PtsMs;       /**< Decoder [out], encoder [in], The pts(ms)*/
                                                /**< CNcomment: ֡PTS\A3\AC\BA\C1\C3\EBΪ\B5\A5λ\A3\AC\B6Խ\E2\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\B3\F6\B2\CE\CA\FD\A3\AC\B6Ա\E0\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\C8\EB\B2\CE\CA\FD*/
    union{
        HI_CODEC_VIDEO_FRAME_S  stVideo;        /**< Decoder [out], encoder [in], The video frame information*/ 
                                                /**< CNcomment: \CA\D3Ƶ֡\D0\C5Ϣ\A3\AC\B6Խ\E2\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\B3\F6\B2\CE\CA\FD\A3\AC\B6Ա\E0\C2\EB\C6\F7\C0\B4˵\CA\C7\CA\E4\C8\EB\B2\CE\CA\FD*/
    }unInfo;
}HI_CODEC_FRAME_S;

/**Defines codec*/
/**CNcomment: CODEC\BDṹ\CC嶨\D2\E5*/
typedef struct hiCODEC_S
{
    /**<Description information about a codec */
    /**<CNcomment: \B1\E0\BD\E2\C2\EB\C6\F7\C3\E8\CA\F6\C3\FB\D7\D6 */ 
    const HI_CHAR *pszName;

    /**<Codec version */
    /**<CNcomment: \B1\E0\BD\E2\C2\EB\C6\F7\B0汾\C3\E8\CA\F6 */ 
    const HI_CODEC_VERSION_U unVersion;

    /**<Detailed information about a codec */
    /**<CNcomment: \B1\E0\BD\E2\C2\EB\C6\F7\CF\EAϸ\C3\E8\CA\F6\D0\C5Ϣ */
    const HI_CHAR *pszDescription;

    /**
    \brief Get codec capability. CNcomment:\BB\F1ȡ\B1\E0\BD\E2\C2\EB\C6\F7\C4\DC\C1\A6 CNend
    \attention \n
    N/A
    \param [out] pstCodecCap, Pointer of the codec capability. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\B1\E0\BD\E2\C2\EB\C6\F7\C4\DC\C1\A6 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_S32 (*GetCap)(HI_CODEC_CAP_S *pstCodecCap);
  
    /**
    \brief Create a codec instance. CNcomment:\B4\B4\BD\A8\B1\E0\BD\E2\C2\EB\C6\F7ʵ\C0\FD CNend
    \attention \n
    N/A
    \param [in] pstParam, Pointer of the open params. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ʵ\C0\FD\B4򿪲\CE\CA\FD CNend
    \param [out] phInst, Pointer to instance handle. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ʵ\C0\FD\BE\E4\B1\FA CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */
    HI_S32 (*Create)(HI_HANDLE* phInst, const HI_CODEC_OPENPARAM_S * pstParam);

    /**
    \brief Destroy a codec instance. CNcomment:\CF\FA\BBٱ\E0\BD\E2\C2\EB\C6\F7ʵ\C0\FD CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */     
    HI_S32 (*Destroy)(HI_HANDLE hInst);

    /**
    \brief Start a codec instance. CNcomment:\C6\F4\B6\AF\B1\E0\BD\E2\C2\EB\C6\F7ʵ\C0\FD CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */       
    HI_S32 (*Start)(HI_HANDLE hInst);

    /**
    \brief Stop a codec instance. CNcomment:ֹͣ\B1\E0\BD\E2\C2\EB\C6\F7ʵ\C0\FD CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */       
    HI_S32 (*Stop)(HI_HANDLE hInst);

    /**
    \brief Reset a codec instance. CNcomment:\B8\B4λ\B1\E0\BD\E2\C2\EB\C6\F7ʵ\C0\FD CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */        
    HI_S32 (*Reset)(HI_HANDLE hInst);

    /**
    \brief Set attribute to a codec instance. CNcomment:\C9\E8\D6ñ\E0\BD\E2\C2\EB\C6\F7\CA\F4\D0\D4 CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [in] pstAttr, Pointer to the instance attribute. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ʵ\C0\FD\CA\F4\D0\D4 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */      
    HI_S32 (*SetAttr)(HI_HANDLE hInst, const HI_CODEC_ATTR_S * pstAttr);

    /**
    \brief Get attribute to a codec instance. CNcomment:\BB\F1ȡ\B1\E0\BD\E2\C2\EB\C6\F7\CA\F4\D0\D4 CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [out] pstAttr, Pointer to the instance attribute. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ʵ\C0\FD\CA\F4\D0\D4 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */        
    HI_S32 (*GetAttr)(HI_HANDLE hInst, HI_CODEC_ATTR_S * pstAttr);

    /**
    \brief Decode a frame.. CNcomment:\BD\E2\C2\EBһ֡ CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [in] pstIn, Pointer to stream data descriptor. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\C2\EB\C1\F7\CA\FD\BE\DD\D0\C5Ϣ\BDṹ\CC\E5 CNend
    \param [out] pstOut, Pointer to frame data descriptor. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2֡\CA\FD\BE\DD\D0\C5Ϣ\BDṹ\CC\E5 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */     
    HI_S32 (*DecodeFrame)(HI_HANDLE hInst, HI_CODEC_STREAM_S * pstIn, HI_CODEC_FRAME_S * pstOut);

    /**
    \brief Encode a frame. CNcomment:\B1\E0\C2\EBһ֡ CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [in] pstIn, Pointer to stream data descriptor. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\C2\EB\C1\F7\CA\FD\BE\DD\D0\C5Ϣ\BDṹ\CC\E5 CNend
    \param [out] pstOut, Pointer to frame data descriptor. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2֡\CA\FD\BE\DD\D0\C5Ϣ\BDṹ\CC\E5 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */     
    HI_S32 (*EncodeFrame)(HI_HANDLE hInst, HI_CODEC_FRAME_S * pstIn, HI_CODEC_STREAM_S * pstOut);

    /**
    \brief Get stream information. CNcomment:\BB\F1ȡ\C2\EB\C1\F7\D0\C5Ϣ CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [out] pstAttr, Pointer to stream information. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\C2\EB\C1\F7\D0\C5Ϣ\BDṹ\CC\E5 CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */     
    HI_S32 (*GetStreamInfo)(HI_HANDLE hInst, HI_CODEC_STREAMINFO_S * pstAttr);

	HI_S32 (*RegFrameBuffer)(HI_HANDLE hInst, HI_CODEC_STREAM_S *pstRawPacket);
    /**
    \brief Other control, can be extended. CNcomment:\C6\E4\CB\FB\BF\D8\D6\C6ѡ\CF\BF\C9\C0\A9չ CNend
    \attention \n
    N/A
    \param [in] hInst, Instance handle. CNcomment:ʵ\C0\FD\BE\E4\B1\FA CNend
    \param [out] u32CMD, The commond ID. CNcomment:\C3\FC\C1\EEID CNend
    \param [out] pParam, Pointer to control parameter. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\BF\D8\D6Ʋ\CE\CA\FD CNend
    \retval ::HI_SUCCESS CNcomment:\B2\D9\D7\F7\B3ɹ\A6 CNend
    \retval ::HI_FAILURE CNcomment:\B2\D9\D7\F7ʧ\B0\DC CNend
    \see \n
    N/A
    */     
    HI_S32 (*Control)(HI_HANDLE hInst, HI_U32 u32CMD, HI_VOID * pParam);
}HI_CODEC_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_VIDEO_CODEC_H__ */
