/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_video.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/17
  Description   :
  History       :
  1.Date        : 2009/12/17
    Author      : sdk
    Modification: Created file

*******************************************************************************/

#ifndef __HI_UNF_VIDEO_H__
#define __HI_UNF_VIDEO_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "hi_common.h"

/*************************** Structure Definition ****************************/
/** \addtogroup      VIDEO */
/** @{ */  /** <!-- [VIDEO] */

/**Defines the oversample mode.*/
/**CNcomment: \B6\A8\D2\E5\B9\FD\B2\C9\D1\F9ģʽ*/
typedef enum hiUNF_OVERSAMPLE_MODE_E
{
    HI_UNF_OVERSAMPLE_1X = 0,
    HI_UNF_OVERSAMPLE_2X,
    HI_UNF_OVERSAMPLE_4X,
    HI_UNF_OVERSAMPLE_BUTT,
} HI_UNF_OVERSAMPLE_MODE_E;

/**Defines the pixel width.*/
/**CNcomment: \B6\A8\D2\E5\CF\F1\CB\D8λ\BF\ED*/
typedef enum hiUNF_PIXEL_BITWIDTH_E
{
    HI_UNF_PIXEL_BITWIDTH_8BIT = 0,
    HI_UNF_PIXEL_BITWIDTH_10BIT,
    HI_UNF_PIXEL_BITWIDTH_12BIT,
    HI_UNF_PIXEL_BITWIDTH_BUTT,
} HI_UNF_PIXEL_BITWIDTH_E;

/**Defines color space enum*/
/**CNcomment: \B6\A8\D2\E5\D1\D5ɫ\BFռ\E4ö\BE\D9*/
typedef enum hiUNF_COLOR_SPACE_E
{
    HI_UNF_COLOR_SPACE_UNKNOWN = 0,

    HI_UNF_COLOR_SPACE_BT601_YUV_LIMITED = 0x10,/* ::::Current Used:::: BT.601  */
    HI_UNF_COLOR_SPACE_BT601_YUV_FULL,
    HI_UNF_COLOR_SPACE_BT601_RGB_LIMITED,
    HI_UNF_COLOR_SPACE_BT601_RGB_FULL,

    HI_UNF_COLOR_SPACE_NTSC1953 = 0x20,

    /* These should be useful.  Assume 601 extents. */
    HI_UNF_COLOR_SPACE_BT470_SYSTEM_M = 0x30,
    HI_UNF_COLOR_SPACE_BT470_SYSTEM_BG,

    HI_UNF_COLOR_SPACE_BT709_YUV_LIMITED = 0x40,/* ::::Current Used:::: BT.709 */
    HI_UNF_COLOR_SPACE_BT709_YUV_FULL,
    HI_UNF_COLOR_SPACE_BT709_RGB_LIMITED,
    HI_UNF_COLOR_SPACE_BT709_RGB_FULL,
    HI_UNF_COLOR_SPACE_BT2020_YUV_LIMITED,/* ::::Current Used:::: BT.2020 */
    HI_UNF_COLOR_SPACE_BT2020_YUV_FULL,
    HI_UNF_COLOR_SPACE_BT2020_RGB_LIMITED,
    HI_UNF_COLOR_SPACE_BT2020_RGB_FULL,   /* ::::Current Used:::: */

    HI_UNF_COLOR_SPACE_REC709 = 0x50,      /* HD and modern captures. */

    HI_UNF_COLOR_SPACE_SMPT170M= 0x60, /* ITU-R 601 -- broadcast NTSC/PAL */
    HI_UNF_COLOR_SPACE_SMPT240M, /* 1125-Line (US) HDTV */

    HI_UNF_COLOR_SPACE_BT878 = 0x70,    /* broken BT878 extents
                           (601, luma range 16-253 instead of 16-235) */

    HI_UNF_COLOR_SPACE_XVYCC = 0x80,

    /* I know there will be cameras that send this.  So, this is
     * unspecified chromaticities and full 0-255 on each of the
     * Y'CbCr components
     */
    HI_UNF_COLOR_SPACE_JPEG = 0x90,
    HI_UNF_COLOR_SPACE_RGB = 0xa0,

    HI_UNF_COLOR_SPACE_BUTT
}HI_UNF_COLOR_SPACE_E;

/**Defines the RGB range.*/
/**CNcomment: \B6\A8\D2\E5RGB \B7\B6Χ*/
typedef enum hiUNF_RGB_RANGE_E
{
    HI_UNF_RGB_DEFAULT,
    HI_UNF_RGB_LIMIT_RANGE,
    HI_UNF_RGB_FULL_RANGE,
    HI_UNF_RGB_RANGE_BUTT
} HI_UNF_RGB_RANGE_E;
/**Defines the video norm.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\D6\C6ʽö\BE\D9*/
typedef enum hiUNF_ENC_FMT_E
{
    HI_UNF_ENC_FMT_1080P_60 = 0,     /**<1080p 60 Hz*/
    HI_UNF_ENC_FMT_1080P_50,         /**<1080p 50 Hz*/
    HI_UNF_ENC_FMT_1080P_30,         /**<1080p 30 Hz*/
    HI_UNF_ENC_FMT_1080P_25,         /**<1080p 25 Hz*/
    HI_UNF_ENC_FMT_1080P_24,         /**<1080p 24 Hz*/

    HI_UNF_ENC_FMT_1080i_60,         /**<1080i 60 Hz*/
    HI_UNF_ENC_FMT_1080i_50,         /**<1080i 50 Hz*/

    HI_UNF_ENC_FMT_720P_60,          /**<720p 60 Hz*/
    HI_UNF_ENC_FMT_720P_50,          /**<720p 50 Hz */

    HI_UNF_ENC_FMT_576P_50,          /**<576p 50 Hz*/
    HI_UNF_ENC_FMT_480P_60,          /**<480p 60 Hz*/

    HI_UNF_ENC_FMT_PAL,              /* B D G H I PAL */
    HI_UNF_ENC_FMT_PAL_N,            /* (N)PAL        */
    HI_UNF_ENC_FMT_PAL_Nc,           /* (Nc)PAL       */

    HI_UNF_ENC_FMT_NTSC,             /* (M)NTSC       */
    HI_UNF_ENC_FMT_NTSC_J,           /* NTSC-J        */
    HI_UNF_ENC_FMT_NTSC_PAL_M,       /* (M)PAL        */

    HI_UNF_ENC_FMT_SECAM_SIN,        /**< SECAM_SIN*/
    HI_UNF_ENC_FMT_SECAM_COS,        /**< SECAM_COS*/

    HI_UNF_ENC_FMT_1080P_24_FRAME_PACKING,
    HI_UNF_ENC_FMT_720P_60_FRAME_PACKING,
    HI_UNF_ENC_FMT_720P_50_FRAME_PACKING,

    HI_UNF_ENC_FMT_861D_640X480_60,
    HI_UNF_ENC_FMT_VESA_800X600_60,
    HI_UNF_ENC_FMT_VESA_1024X768_60,
    HI_UNF_ENC_FMT_VESA_1280X720_60,
    HI_UNF_ENC_FMT_VESA_1280X800_60,
    HI_UNF_ENC_FMT_VESA_1280X1024_60,
    HI_UNF_ENC_FMT_VESA_1360X768_60,
    HI_UNF_ENC_FMT_VESA_1366X768_60,
    HI_UNF_ENC_FMT_VESA_1400X1050_60,
    HI_UNF_ENC_FMT_VESA_1440X900_60,
    HI_UNF_ENC_FMT_VESA_1440X900_60_RB,
    HI_UNF_ENC_FMT_VESA_1600X900_60_RB,
    HI_UNF_ENC_FMT_VESA_1600X1200_60,
    HI_UNF_ENC_FMT_VESA_1680X1050_60,
    HI_UNF_ENC_FMT_VESA_1680X1050_60_RB,
    HI_UNF_ENC_FMT_VESA_1920X1080_60,
    HI_UNF_ENC_FMT_VESA_1920X1200_60,
    HI_UNF_ENC_FMT_VESA_1920X1440_60,
    HI_UNF_ENC_FMT_VESA_2048X1152_60,
    HI_UNF_ENC_FMT_VESA_2560X1440_60_RB,
    HI_UNF_ENC_FMT_VESA_2560X1600_60_RB,

    HI_UNF_ENC_FMT_3840X2160_24 = 0x40,
    HI_UNF_ENC_FMT_3840X2160_25,
    HI_UNF_ENC_FMT_3840X2160_30,
    HI_UNF_ENC_FMT_3840X2160_50,
    HI_UNF_ENC_FMT_3840X2160_60,

    HI_UNF_ENC_FMT_4096X2160_24,
    HI_UNF_ENC_FMT_4096X2160_25,
    HI_UNF_ENC_FMT_4096X2160_30,
    HI_UNF_ENC_FMT_4096X2160_50,
    HI_UNF_ENC_FMT_4096X2160_60,

    HI_UNF_ENC_FMT_3840X2160_23_976,
    HI_UNF_ENC_FMT_3840X2160_29_97,
    HI_UNF_ENC_FMT_720P_59_94,
    HI_UNF_ENC_FMT_1080P_59_94,
    HI_UNF_ENC_FMT_1080P_29_97,
    HI_UNF_ENC_FMT_1080P_23_976,
    HI_UNF_ENC_FMT_1080i_59_94,
    HI_UNF_ENC_FMT_BUTT
}HI_UNF_ENC_FMT_E;

/**Defines the mode of the video decoder.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\BD\E2\C2\EB\C6\F7ģʽö\BE\D9*/
typedef enum hiUNF_VCODEC_MODE_E
{
    HI_UNF_VCODEC_MODE_NORMAL = 0,   /**<Decode all frames.*/ /**<CNcomment: \BD\E2\CB\F9\D3\D0֡*/
    HI_UNF_VCODEC_MODE_IP,           /**<Decode only I frames and P frames.*/ /**<CNcomment: ֻ\BD\E2IP֡*/
    HI_UNF_VCODEC_MODE_I,            /**<Decode only I frames.*/ /**<CNcomment: ֻ\BD\E2I֡*/
    HI_UNF_VCODEC_MODE_DROP_INVALID_B,  /**<Decode all frames except the first B frame sequence behind I frames */ /**<CNcomment: \BD\E2\CB\F9\D3\D0֡\A3\AC\B3\FD\C1˽\F4\B8\FA\D7\C5I֡\BA\F3\C3\E6\B5\C4B֡*/
    HI_UNF_VCODEC_MODE_FIRST_I,   /**<only decodes the first I frame in the input buffer */
    HI_UNF_VCODEC_MODE_BUTT
} HI_UNF_VCODEC_MODE_E;

/**Defines special control operation of decoder*/
/**CNcomment: \B6\A8\D2\E5\BD\E2\C2\EB\C6\F7\BD\E2\C2\EB\B5\C4\CC\D8\CA\E2\BF\D8\D6\C6ѡ\CF\EE */
typedef enum hiHI_UNF_VCODEC_CTRL_OPTION_E
{
    HI_UNF_VCODEC_CTRL_OPTION_NORMAL_DPB = 0x0,
    HI_UNF_VCODEC_CTRL_OPTION_SIMPLE_DPB = 0x1,
    HI_UNF_VCODEC_CTRL_OPTION_REPAIR_EN  = 0x2,/**CNcomment: \C6\F4\B6\AF\D0޲\B9\A3\AC\BD\F6\D3\C3\D3\DAmiracast\B3\A1\BE\B0 */
    HI_UNF_VCODEC_CTRL_OPTION_LINEAR_EN = 0x4, /**CNcomment: 2D\CA\E4\B3\F6,\BD\F6Hi3716MV430 dongle\D0\FDת\B3\A1\BE\B0\C5\E4\D6\C3 */
    HI_UNF_VCODEC_CTRL_OPTION_ONLY_VDH_FRMAE_MEM = 0x8, /**CNcomment: ֻ\B7\D6\C5\E4\BD\E2\C2\EB\C6\F7ʹ\D3õ\C4֡\B4\E6,\BD\F6Hi3716MV430 dongle\D0\FDת\B3\A1\BE\B0\C5\E4\D6\C3 */
    HI_UNF_VCODEC_CTRL_OPTION_MAX
} HI_UNF_VCODEC_CTRL_OPTION_E;

/**Defines the decoding capability (resolution) of the decoder.*/
/**CNcomment: \B6\A8\D2\E5\BD\E2\C2\EB\C6\F7\BD\E2\C2\EB\C4\DC\C1\A6(\B7ֱ\E6\C2\CA) */
typedef enum hiUNF_VCODEC_CAP_LEVEL_E
{
    HI_UNF_VCODEC_CAP_LEVEL_NULL = 0, /**<Do not decode.*/ /**<CNcomment: \B2\BB\D0\E8Ҫ\BD\E2\C2\EB */
    HI_UNF_VCODEC_CAP_LEVEL_QCIF = 0, /**<The resolution of the picture to be decoded is less than or equal to 176x144.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD176*144 */
    HI_UNF_VCODEC_CAP_LEVEL_CIF,      /**<The resolution of the picture to be decoded less than or equal to 352x288.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD352*288 */
    HI_UNF_VCODEC_CAP_LEVEL_D1,       /**<The resolution of the picture to be decoded less than or equal to 720x576.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD720*576 */
    HI_UNF_VCODEC_CAP_LEVEL_720P,     /**<The resolution of the picture to be decoded is less than or equal to 1280x720.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1280*720 */
    HI_UNF_VCODEC_CAP_LEVEL_FULLHD,   /**<The resolution of the picture to be decoded is less than or equal to 1920x1080.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1920*1080 */

    HI_UNF_VCODEC_CAP_LEVEL_1280x800, /**<The resolution of the picture to be decoded is less than or equal to 1280x800.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1280x800*/
    HI_UNF_VCODEC_CAP_LEVEL_800x1280, /**<The resolution of the picture to be decoded is less than or equal to 800x1280.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD800x1280*/
    HI_UNF_VCODEC_CAP_LEVEL_1488x1280, /**<The resolution of the picture to be decoded is less than or equal to 1488x1280.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1488x1280 */
    HI_UNF_VCODEC_CAP_LEVEL_1280x1488, /**<The resolution of the picture to be decoded is less than or equal to 1280x1488.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1280x1488 */
    HI_UNF_VCODEC_CAP_LEVEL_2160x1280, /**<The resolution of the picture to be decoded is less than or equal to 2160x1280.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD2160x1280 */
    HI_UNF_VCODEC_CAP_LEVEL_1280x2160, /**<The resolution of the picture to be decoded is less than or equal to 1280x2160.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD1280x2160 */
    HI_UNF_VCODEC_CAP_LEVEL_2160x2160, /**<The resolution of the picture to be decoded is less than or equal to 2160x2160.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD2160x2160 */
    HI_UNF_VCODEC_CAP_LEVEL_4096x2160, /**<The resolution of the picture to be decoded is less than or equal to 4096x2160.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD4096x2160 */
    HI_UNF_VCODEC_CAP_LEVEL_2160x4096, /**<The resolution of the picture to be decoded is less than or equal to 2160x4096.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD2160x4096 */
    HI_UNF_VCODEC_CAP_LEVEL_4096x4096, /**<The resolution of the picture to be decoded is less than or equal to 4096x4096.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD4096x4096 */
    HI_UNF_VCODEC_CAP_LEVEL_8192x4096, /**<The resolution of the picture to be decoded is less than or equal to 8192x4096.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD8192x4096 */
    HI_UNF_VCODEC_CAP_LEVEL_4096x8192, /**<The resolution of the picture to be decoded is less than or equal to 4096x8192.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD4096x8192 */
    HI_UNF_VCODEC_CAP_LEVEL_8192x8192, /**<The resolution of the picture to be decoded is less than or equal to 8192x8192.*/ /**<CNcomment: \BD\E2\C2\EB\B5\C4ͼ\CF\F1\B4\F3С\B2\BB\B3\AC\B9\FD8192x8192 */

    HI_UNF_VCODEC_CAP_LEVEL_BUTT
} HI_UNF_VCODEC_CAP_LEVEL_E;

/**Defines the stream type supported by the decoder.*/
/**CNcomment: \B6\A8\D2\E5\BD\E2\C2\EB\C6\F7֧\B3ֵ\C4\C2\EB\C1\F7\C0\E0\D0\CD */
typedef enum hiUNF_VCODEC_TYPE_E
{
    HI_UNF_VCODEC_TYPE_MPEG2,
    HI_UNF_VCODEC_TYPE_MPEG4,       /**<MPEG4*/
    HI_UNF_VCODEC_TYPE_AVS,
    HI_UNF_VCODEC_TYPE_H263,
    HI_UNF_VCODEC_TYPE_H264,
    HI_UNF_VCODEC_TYPE_REAL8,
    HI_UNF_VCODEC_TYPE_REAL9,
    HI_UNF_VCODEC_TYPE_VC1,
    HI_UNF_VCODEC_TYPE_VP6,
    HI_UNF_VCODEC_TYPE_VP6F,
    HI_UNF_VCODEC_TYPE_VP6A,
    HI_UNF_VCODEC_TYPE_MJPEG,
    HI_UNF_VCODEC_TYPE_SORENSON,    /**<SORENSON SPARK */
    HI_UNF_VCODEC_TYPE_DIVX3,       /**<Not Supportted */
    HI_UNF_VCODEC_TYPE_RAW,
    HI_UNF_VCODEC_TYPE_JPEG,        /**<Used only for VENC */
    HI_UNF_VCODEC_TYPE_VP8,
    HI_UNF_VCODEC_TYPE_MSMPEG4V1,   /**<MS private MPEG4 */
    HI_UNF_VCODEC_TYPE_MSMPEG4V2,
    HI_UNF_VCODEC_TYPE_MSVIDEO1,    /**<MS video */
    HI_UNF_VCODEC_TYPE_WMV1,
    HI_UNF_VCODEC_TYPE_WMV2,
    HI_UNF_VCODEC_TYPE_RV10,
    HI_UNF_VCODEC_TYPE_RV20,
    HI_UNF_VCODEC_TYPE_SVQ1,        /**<Apple video */
    HI_UNF_VCODEC_TYPE_SVQ3,        /**<Apple video */
    HI_UNF_VCODEC_TYPE_H261,
    HI_UNF_VCODEC_TYPE_VP3,
    HI_UNF_VCODEC_TYPE_VP5,
    HI_UNF_VCODEC_TYPE_CINEPAK,
    HI_UNF_VCODEC_TYPE_INDEO2,
    HI_UNF_VCODEC_TYPE_INDEO3,
    HI_UNF_VCODEC_TYPE_INDEO4,
    HI_UNF_VCODEC_TYPE_INDEO5,
    HI_UNF_VCODEC_TYPE_MJPEGB,
    HI_UNF_VCODEC_TYPE_MVC,
    HI_UNF_VCODEC_TYPE_HEVC,
    HI_UNF_VCODEC_TYPE_DV,
    HI_UNF_VCODEC_TYPE_VP9,
    HI_UNF_VCODEC_TYPE_AVS2,
    HI_UNF_VCODEC_TYPE_BUTT
}HI_UNF_VCODEC_TYPE_E;

/**Defines the H264 profile of the video encoder.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\BD\E2\C2\EB\C6\F7 H264Э\D2鵵\B4\CE*/
typedef enum hiUNF_H264_PROFILE_E
{
    HI_UNF_H264_PROFILE_BASELINE = 0,   /**<Encode H264 stream by baseline profile.*/ /**<CNcomment: \B2\C9\D3û\F9\CFߵ\B5\B4α\E0\C2\EBH264\C2\EB\C1\F7*/
    HI_UNF_H264_PROFILE_MAIN,           /**<Encode H264 stream by main profile.*/     /**<CNcomment:\B2\C9\D3\C3\D6\F7Ҫ\B5\B5\B4α\E0\C2\EBH264\C2\EB\C1\F7*/
    HI_UNF_H264_PROFILE_EXTENDED,       /**<Encode H264 stream by extended profile.*/ /**<CNcomment:\B2\C9\D3\C3\C0\A9չ\B5\B5\B4α\E0\C2\EBH264\C2\EB\C1\F7*/
    HI_UNF_H264_PROFILE_HIGH,           /**<Encode H264 stream by high profile.*/     /**<CNcomment: \B2\C9\D3ø߼\B6\B5\B5\B4α\E0\C2\EBH264\C2\EB\C1\F7*/
    HI_UNF_H264_PROFILE_BUTT
}HI_UNF_H264_PROFILE_E;

typedef enum hiUNF_VIDEO_HDR_TYPE_E
{
    HI_UNF_VIDEO_HDR_TYPE_HDR10 = 0,
    HI_UNF_VIDEO_HDR_TYPE_HLG,
    HI_UNF_VIDEO_HDR_TYPE_BUTT
}HI_UNF_VIDEO_HDR_TYPE_E;

typedef struct hiUNF_VCODEC_VC1_ATTR_S
{
    HI_BOOL  bAdvancedProfile;   /**<Whether the profile is an advanced profile*/ /**<CNcomment: \CAǷ\F1Advanced Profile*/
    HI_U32   u32CodecVersion;    /**<Version number*/ /**<CNcomment: \B0汾\BA\C5*/
}HI_UNF_VCODEC_VC1_ATTR_S;

typedef struct hiUNF_VCODEC_VP6_ATTR_S
{
    HI_BOOL  bReversed;     /**<To reverse a picture, set this parameter to 1. In this cases, set it to 0.*/ /**<CNcomment: ͼ\CF\F1\D0\E8Ҫ\B5\B9תʱ\D6\C31\A3\AC\B7\F1\D4\F2\D6\C30*/
    HI_U16   u16DispWidth;  /**<Display Width.*/ /**<CNcomment: ͼ\CF\F1\B5\C4\CF\D4ʾ\BF\ED\B6\C8*/
    HI_U16   u16DispHeight; /**<Display Height.*/ /**<CNcomment: ͼ\CF\F1\B5\C4\CF\D4ʾ\B8߶\C8*/
}HI_UNF_VCODEC_VP6_ATTR_S;

typedef union hiUNF_VCODEC_EXTATTR_U
{
    HI_UNF_VCODEC_VC1_ATTR_S stVC1Attr;
    HI_UNF_VCODEC_VP6_ATTR_S stVP6Attr;
}HI_UNF_VCODEC_EXTATTR_U;

/**Defines the attributes of a video decoder.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\CA\F4\D0Խṹ*/
typedef struct hiUNF_VCODEC_ATTR_S
{
    HI_UNF_VCODEC_TYPE_E        enType;          /**<Video encoding type*/ /**<CNcomment: \CA\D3Ƶ\B1\E0\C2\EB\C0\E0\D0\CD*/
    HI_UNF_VCODEC_EXTATTR_U     unExtAttr;       /**<Extra attributes related to the video encoding type*/ /**<CNcomment: \CA\D3Ƶ\B1\E0\C2\EB\C0\E0\D0\CD\CF\E0\B9صĶ\EE\CD\E2\CA\F4\D0\D4*/
    HI_UNF_VCODEC_MODE_E        enMode;          /**<Mode of a video decoder*/ /**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\C6\F7ģʽģʽ*/
    HI_U32                      u32ErrCover;     /**<Error concealment threshold of the output frames of a video decoder. The value 0 indicates that no frames are output if an error occurs; the value 100 indicates that all frames are output no matter whether errors occur.*/
                                                 /**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B5\C4\CA\E4\B3\F6֡\B4\ED\CE\F3\D2\FE\B2\D8\C3\C5\CFޣ\AC0:\B3\F6\CFִ\ED\CE󼴲\BB\CA\E4\B3\F6\A3\BB100:\B2\BB\B9ܴ\ED\CE\F3\B1\C8\C0\FDȫ\B2\BF\CA\E4\B3\F6*/
    HI_U32                      u32Priority;     /**<Priority of a video decoder. The value range is [1, HI_UNF_VCODEC_MAX_PRIORITY]. The value 0 is a reserved value. If you set the value to 0, no error message is displayed, but the value 1 is used automatically. The smaller the value, the lower the priority.*/
                                                 /**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\C6\F7\D3\C5\CFȼ\B6, ȡֵ\B7\B6Χ: \B4\F3\D3ڵ\C8\D3\DA1\A3\ACС\D3ڵ\C8\D3\DAHI_UNF_VCODEC_MAX_PRIORITY, 0\CAǱ\A3\C1\F4ֵ\A3\AC\C5\E4\D6\C3Ϊ0\B2\BB\BBᱨ\B4\ED\A3\AC\B5\AB\CAǻ\E1\D7Զ\AFȡֵΪ1,\CA\FDֵԽС\D3\C5\CFȼ\B6Խ\B5\CD */
    HI_BOOL                     bOrderOutput;    /**<Whether the videos are output by the decoding sequence. You are advised to set this parameter to HI_TRUE in VP mode, and HI_FALSE in other modes.*/
                                                 /**<CNcomment: \CAǷ񰴽\E2\C2\EB\D0\F2\CA\E4\B3\F6\A3\ACVPģʽ\CF\C2\CDƼ\F6\C5\E4\D6\C3ΪHI_TRUE, һ\B0\E3ģʽ\CF\C2\C5\E4\D6\C3ΪHI_FALSE */
    HI_S32                      s32CtrlOptions;  /**<The value is HI_UNF_VCODEC_CTRL_OPTION_E, or the 'or' value of several enum type*/
                                                 /**<CNcomment: ȡֵΪHI_UNF_VCODEC_CTRL_OPTION_E\A3\AC\BB\F2\D5߼\B8\B8\F6ö\BEٵ\C4'\BB\F2'  */
    HI_VOID*                    pCodecContext;   /**<Private codec context */
}HI_UNF_VCODEC_ATTR_S;

/**Defines the hdr attributes of a video decoder.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3ƵHDR\CA\F4\D0Խṹ*/
typedef struct hiUNF_VIDEO_MASTERING_DISPLAY_COLOUR_VOLUME_S
{
    HI_U16 u16DisplayPrimaries_x[3];
    HI_U16 u16DisplayPrimaries_y[3];
    HI_U16 u16WhitePoint_x;
    HI_U16 u16WhitePoint_y;
    HI_U32 u32MaxDisplayMasteringLuminance;
    HI_U32 u32MinDisplayMasteringLuminance;
} HI_UNF_VIDEO_MASTERING_DISPLAY_COLOUR_VOLUME_S;

typedef struct hiUNF_VIDEO_CONTENT_LIGHT_LEVEL_S
{
    HI_U32 u32MaxContentLightLevel;
    HI_U32 u32MaxPicAverageLightLevel;
} HI_UNF_VIDEO_CONTENT_LIGHT_LEVEL_S;

typedef struct hiUNF_VIDEO_HDR10__S
{
    HI_U8  u8FullRangeFlag;
    HI_U8  u8ColourPrimaries;
    HI_U8  u8TransferCharacteristics;
    HI_U8  u8MatrixCoeffs;
    HI_U8  u8MasteringAvailable;      /**<Whether the Mastering available,The value 0 indicates available, The value 1 indicates unavailable.*/
                                      /**<CNcomment: Mastering\CA\FD\BE\DD\CAǷ\F1\BF\C9\D3\C3,0:\B2\BB\BF\C9\D3ã\BB1:\BF\C9\D3\C3*/
    HI_U8  u8ContentAvailable;        /**<Whether the Content available,,The value 0 indicates available, The value 1 indicates unavailable.*/
                                      /**<CNcomment: Content\CA\FD\BE\DD\CAǷ\F1\BF\C9\D3\C3,0:\B2\BB\BF\C9\D3ã\BB1:\BF\C9\D3\C3*/
    HI_UNF_VIDEO_MASTERING_DISPLAY_COLOUR_VOLUME_S  stMasteringInfo;
    HI_UNF_VIDEO_CONTENT_LIGHT_LEVEL_S              stContentInfo;
} HI_UNF_VIDEO_HDR10_INFO_S;

typedef struct hiUNF_VIDEO_HLG_INFO_S
{
    HI_U8  u8FullRangeFlag;
    HI_U8  u8ColourPrimaries;
    HI_U8  u8TransferCharacteristics;
    HI_U8  u8MatrixCoeffs;
    HI_U8  u8MasteringAvailable;      /**<Whether the Mastering available,The value 0 indicates available, The value 1 indicates unavailable.*/
                                      /**<CNcomment: Mastering\CA\FD\BE\DD\CAǷ\F1\BF\C9\D3\C3,0:\B2\BB\BF\C9\D3ã\BB1:\BF\C9\D3\C3*/
    HI_U8  u8ContentAvailable;        /**<Whether the Content available,,The value 0 indicates available, The value 1 indicates unavailable.*/
                                      /**<CNcomment: Content\CA\FD\BE\DD\CAǷ\F1\BF\C9\D3\C3,0:\B2\BB\BF\C9\D3ã\BB1:\BF\C9\D3\C3*/
    HI_UNF_VIDEO_MASTERING_DISPLAY_COLOUR_VOLUME_S  stMasteringInfo;
    HI_UNF_VIDEO_CONTENT_LIGHT_LEVEL_S              stContentInfo;
    HI_U8  u8BackWardsCompatible;
} HI_UNF_VIDEO_HLG_INFO_S;

typedef union hiUNF_VIDEO_HDR_METADATA_U
{
    HI_UNF_VIDEO_HDR10_INFO_S stHdr10Info;
    HI_UNF_VIDEO_HLG_INFO_S   stHlgInfo;
}HI_UNF_VIDEO_HDR_METADATA_U;

typedef struct hiUNF_VIDEO_HDR_INFO_S
{
    HI_UNF_VIDEO_HDR_TYPE_E          enHdrType;
    HI_UNF_VIDEO_HDR_METADATA_U      unHdrMetadata;
} HI_UNF_VIDEO_HDR_INFO_S;

/**Defines the sub stream protocol.*/
/**CNcomment: \B6\A8\D2\E5\C2\EB\C1\F7\B5\C4Э\D2\E9\B7\D6֧ö\BE\D9*/
typedef enum hiUNF_VIDEO_SUB_STANDARD_E
{
    HI_UNF_VIDEO_SUB_STANDARD_UNKNOWN,       /**<Unknown*/ /**<CNcomment: δ֪Э\D2\E9\B7\D6֧*/
    HI_UNF_VIDEO_SUB_STANDARD_MPEG2_MPEG1,   /**<The MPEG2 protocol family is compatible with MPEG1.*/ /**<CNcomment: MPEG2Э\D2\E9\D7\E5\BF\C9\D2Լ\E6\C8\DDMPEG1 */
    HI_UNF_VIDEO_SUB_STANDARD_MPEG4_SHV,     /**<The MPEG4 protocol family is compatible with SHV.*/ /**<CNcomment: MPEG4Э\D2\E9\D7\E5\BF\C9\D2Լ\E6\C8\DDSHV*/
    HI_UNF_VIDEO_SUB_STANDARD_MPEG4_XVID,    /**<The MPEG4 protocol family includes the sub protocol XVID.*/ /**<CNcomment: MPEG4Э\D2\E9\B0\FC\BA\ACXVID\B7\D6֧*/
    HI_UNF_VIDEO_SUB_STANDARD_MPEG4_DIVX,    /**<The MPEG4 protocol family includes the sub protocol DIVX.*/ /**<CNcomment: MPEG4Э\D2\E9\B0\FC\BA\ACDIVX\B7\D6֧*/

    HI_UNF_VIDEO_SUB_STANDARD_BUTT
}HI_UNF_VIDEO_SUB_STANDARD_E;

/**Defines the frame rate of the video stream.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\C2\EB\C1\F7֡\C2ʽṹ*/
typedef struct hiUNF_VCODEC_FRMRATE_S
{
    HI_U32 u32fpsInteger;     /**<Integral part of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4\D5\FB\CA\FD\B2\BF\B7\D6, fps */
    HI_U32 u32fpsDecimal;     /**<Fractional part (calculated to three decimal places) of the frame rate (in frame/s)*/
                              /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4С\CA\FD\B2\BF\B7֣\A8\B1\A3\C1\F43λ\A3\A9, fps */
}HI_UNF_VCODEC_FRMRATE_S;

/**Defines the information about video streams.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\C2\EB\C1\F7\D0\C5Ϣ\BDṹ*/
typedef struct hiUNF_VCODEC_STREAMINFO_S
{
    HI_UNF_VCODEC_TYPE_E        enVCodecType;   /**<Stream type*/ /**<CNcomment: \C2\EB\C1\F7\C0\E0\D0\CD */
    HI_UNF_VIDEO_SUB_STANDARD_E enSubStandard;  /**<Sub stream protocol*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4Э\D2\E9\B7\D6֧ */
    HI_U32                      u32SubVersion;  /**<Version of the sub stream protocol*/ /**<CNcomment: \C2\EB\C1\F7\D7\D3Э\D2\E9\B0汾\BA\C5 */
    HI_U32                      u32Profile;     /**<Stream profile*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4profile */
    HI_U32                      u32Level;       /**<Stream level*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4level */
    HI_UNF_ENC_FMT_E            enDisplayNorm;  /**<Display norm (PAL or NTSC)*/ /**<CNcomment: \CF\D4ʾ\B1\EA׼(P/N) */
    HI_BOOL                     bProgressive;   /**<Sampling type (progressive or interlaced)*/ /**<CNcomment: \B2\C9\D1\F9\B7\BDʽ(\D6\F0\D0\D0/\B8\F4\D0\D0) */
    HI_U32                      u32AspectWidth; /**<Output aspect ratio: width*/ /**<CNcomment: \CA\E4\B3\F6\BF\ED\B8߱\C8֮\BF\EDֵ */
    HI_U32                      u32AspectHeight;/**<Output aspect ratio: height*/ /**<CNcomment: \CA\E4\B3\F6\BF\ED\B8߱\C8֮\B8\DFֵ */

    HI_U32 u32bps;            /**<Bit rate, in kbit/s*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4\C2\EB\C2\CA, Kbps */
    HI_U32 u32fpsInteger;     /**<Integral part of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4\D5\FB\CA\FD\B2\BF\B7\D6, fps */
    HI_U32 u32fpsDecimal;     /**<Fractional part (calculated to three decimal places) of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4С\CA\FD\B2\BF\B7֣\A8\B1\A3\C1\F43λ\A3\A9, fps */
    HI_U32 u32Width;          /**<Width of the decoded picture*/ /**<CNcomment: \BD\E2\C2\EBͼ\CF\F1\BF\ED */
    HI_U32 u32Height;         /**<Height of the decoded picture*/ /**<CNcomment: \BD\E2\C2\EBͼ\CF\F1\B8\DF */
    HI_U32 u32DisplayWidth;   /**<Width of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\BF\ED */
    HI_U32 u32DisplayHeight;  /**<Height of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\B8\DF */
    HI_U32 u32DisplayCenterX; /**<Horizontal coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/
                              /**<CNcomment: \CF\D4ʾͼ\CF\F1\D6\D0\D0ĺ\E1\D7\F8\B1꣬\D2\D4ԭʼͼ\CF\F1\B5\C4\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3 */
    HI_U32 u32DisplayCenterY; /**<Vertical coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/
                              /**<CNcomment: \CF\D4ʾͼ\CF\F1\D6\D0\D0\C4\D7\DD\D7\F8\B1꣬\D2\D4ԭʼͼ\CF\F1\B5\C4\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3 */
    HI_UNF_PIXEL_BITWIDTH_E enBitWidth; /**<Bit width decoded from stream*/ /**<CNcomment: \CA\D3Ƶ\CF\F1\CB\D8λ\BF\ED*/
    HI_UNF_COLOR_SPACE_E       enSrcColorSpace; /**<Color space decoded from stream*/ /**<CNcomment: \D1\D5ɫɫ\D3\F2\BFռ\E4*/
}HI_UNF_VCODEC_STREAMINFO_S;


/**Defines the types of the user data in the video information.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\D0\C5Ϣ\D6е\C4\D3û\A7\CA\FD\BE\DD\C0\E0\D0\CD */
typedef enum hiHI_UNF_VIDEO_USERDATA_TYPE_E
{
    HI_UNF_VIDEO_USERDATA_UNKNOWN = 0,      /**<Unknown type*/ /**<CNcomment: δ֪\C0\E0\D0\CD*/
    HI_UNF_VIDEO_USERDATA_DVB1_CC = 0x1,    /**<Closed Caption Data*/ /**<CNcomment: \D7\D6Ļ\CA\FD\BE\DD*/
    HI_UNF_VIDEO_USERDATA_DVB1_BAR = 0x2,   /**<Bar Data*/ /**<CNcomment: Bar\CA\FD\BE\DD*/
    HI_UNF_VIDEO_USERDATA_AFD = 0x10000,    /**<Active Format Description*/ /**<CNcomment: ģʽ\C3\E8\CA\F6\CA\FD\BE\DD*/
    HI_UNF_VIDEO_USERDATA_BUTT
}HI_UNF_VIDEO_USERDATA_TYPE_E;

/**Defines the profile of video broadcasting.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\B9㲥\B5\C4profileö\BE\D9*/
typedef enum hiUNF_VIDEO_BROADCAST_PROFILE_E
{
    HI_UNF_VIDEO_BROADCAST_DVB,        /**<Digital video broadcasting (DVB)*/ /**<CNcomment: \CA\FD\D7\D6\CA\D3Ƶ\B9㲥DVB*/
    HI_UNF_VIDEO_BROADCAST_DIRECTV,    /**<American live broadcast operator DirecTV*/ /**<CNcomment: \C3\C0\B9\FAֱ\B2\A5\D4\CBӪ\C9\CCDirecTV*/
    HI_UNF_VIDEO_BROADCAST_ATSC,       /**<Advanced Television Systems Committee (ATSC)*/ /**<CNcomment: \CFȽ\F8\B5\E7\CA\D3\D6\C6ʽίԱ\BB\E1ATSC\A3\A8Advanced Television Systems Committee\A3\A9*/
    HI_UNF_VIDEO_BROADCAST_DVD,        /**<Digital video disc (DVD)*/ /**<CNcomment: \CA\FD\D7\D6\CA\D3Ƶ\B9\E2\C5\CC*/
    HI_UNF_VIDEO_BROADCAST_ARIB,       /**<Association of Radio Industries and Businesses (ARIB)*/ /**<CNcomment: \CE\DE\CFߵ繤ҵ\BC\B0\C9\CCҵЭ\BB\E1\B9\E6\B8\F1*/
    HI_UNF_VIDEO_BROADCAST_BUTT
}HI_UNF_VIDEO_BROADCAST_PROFILE_E;

/**Defines the position of the user data in the video information.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\D0\C5Ϣ\D6\D0\D3û\A7\CA\FD\BEݵ\C4λ\D6\C3ö\BE\D9*/
typedef enum hiUNF_VIDEO_USER_DATA_POSITION_E
{
    HI_UNF_VIDEO_USER_DATA_POSITION_UNKNOWN,       /**<Unknown*/ /**<CNcomment: δ֪λ\D6\C3*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG2_SEQ,     /**<The data is parsed from sequences under the MPEG2 protocol.*/ /**<CNcomment: MPEG2Э\D2\E9\CF£\AC\B4\D3\D0\F2\C1\D0\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG2_GOP,     /**<The data is parsed from the group of pictures (GOP) under the MPEG2 protocol.*/ /**<CNcomment: MPEG2Э\D2\E9\CF£\AC\B4\D3GOP\A3\A8Group Of Pictures\A3\A9\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG2_FRAME,   /**<The data is parsed from picture frames under the MPEG2 protocol.*/ /**<CNcomment: MPEG2Э\D2\E9\CF£\AC\B4\D3ͼ\CF\F1֡\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG4_VSOS,    /**<The data is parsed from the sequences of visible objects under the MPEG4 protocol.*/ /**<CNcomment: MPEG4Э\D2\E9\CF£\AC\B4ӿ\C9\CAӶ\D4\CF\F1\D0\F2\C1\D0\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG4_VSO,     /**<The data is parsed from visible objects under the MPEG4 protocol.*/ /**<CNcomment: MPEG4Э\D2\E9\CF£\AC\B4ӿ\C9\CAӶ\D4\CF\F1\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG4_VOL,     /**<The data is parsed from the video object layer under the MPEG4 protocol.*/ /**<CNcomment: MPEG4Э\D2\E9\CF£\AC\B4\D3\CA\D3Ƶ\B6\D4\CF\F1\B2\E3\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_MPEG4_GOP,     /**<The data is parsed from the GOP under the MPEG4 protocol.*/ /**<CNcomment: MPEG4Э\D2\E9\CF£\AC\B4\D3GOP\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_H264_REG,      /**<The data is parsed from the user_data_regestered_itu_t_t35() syntax under the H.264 protocol.*/ /**<CNcomment: \B4\D3H.264Э\D2\E9\B5\C4user_data_regestered_itu_t_t35()\D3﷨\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_H264_UNREG,    /**<The data is parsed from the user_data_unregestered() syntax under the H.264 protocol.*/ /**<CNcomment: \B4\D3H.264Э\D2\E9\B5\C4user_data_unregestered()\D3﷨\D6н\E2\B3\F6*/
    HI_UNF_VIDEO_USER_DATA_POSITION_BUTT
}HI_UNF_VIDEO_USER_DATA_POSITION_E;

/**Defines the structure of the user data in the video information.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\D0\C5Ϣ\D6е\C4\D3û\A7\CA\FD\BEݽṹ*/
typedef struct hiUNF_VIDEO_USERDATA_S
{
    HI_UNF_VIDEO_BROADCAST_PROFILE_E   enBroadcastProfile;   /**<Broadcasting profile of the user data*/ /**<CNcomment: \D3û\A7\CA\FD\BEݵĹ㲥profile*/
    HI_UNF_VIDEO_USER_DATA_POSITION_E  enPositionInStream;   /**<Position of the user data in video streams*/ /**<CNcomment: \D3û\A7\CA\FD\BE\DD\D4\DA\CA\D3Ƶ\C1\F7\D6е\C4λ\D6\C3*/
    HI_U32                             u32Pts;               /**<PTS corresponding to the user data*/ /**<CNcomment: \D3û\A7\CA\FD\BEݶ\D4Ӧ\B5\C4ʱ\BC\E4\B4\C1*/
    HI_U32                             u32SeqCnt;            /**<Sequence ID of the user data*/ /**<CNcomment: \D3û\A7\CA\FD\BEݵ\C4ǰһ\D0\F2\C1\D0\CA\FD*/
    HI_U32                             u32SeqFrameCnt;       /**<Frame number of the user data*/ /**<CNcomment: \D3û\A7\CA\FD\BEݵ\C4ǰһ֡\CA\FD*/
    HI_U8                              *pu8Buffer;           /**<Initial address of the user data memory, output parameter*/ /**<CNcomment: \D3û\A7\CA\FD\BE\DD\C4ڴ\E6\C7\F8\B5ĳ\F5ʼ\B5\D8ַ,\CA\E4\B3\F6\B2\CE\CA\FD*/
    HI_U32                             u32Length;            /**<User data size (a multiple of 1 byte)*/ /**<CNcomment: \D3û\A7\CA\FD\BEݵĴ\F3С\A3\AC\D2\D41byteΪ\B5\A5λ*/
    HI_BOOL                            bBufferOverflow;      /**<Indicate that whether the user data size exceeds the maximum size defined by MAX_USER_DATA_LEN.*/ /**<CNcomment: \B1\EA־\D3û\A7\CA\FD\BEݵĳ\A4\B6\C8\CAǷ񳬹\FD\C1\CBMAX_USER_DATA_LEN\B6\A8\D2\E5\B5\C4\D7\EE\B4\F3ֵ*/
    HI_BOOL                            bTopFieldFirst;       /**<Top field first flag*/ /**<CNcomment: \B6\A5\B3\A1\D3\C5\CFȱ\EA־*/
}HI_UNF_VIDEO_USERDATA_S;

/**Defines the parameters of format changing */
/**CNcomment: \B6\A8\D2\E5\D6\C6ʽ\C7л\BBʱ\B5\C4\CF\E0\B9ز\CE\CA\FD*/
typedef struct hiUNF_NORMCHANGE_PARAM_S
{
    HI_UNF_ENC_FMT_E            enNewFormat;            /**<New format*/ /**<CNcomment: \D0µ\C4\D6\C6ʽ*/
    HI_U32                      u32ImageWidth;          /**<Width of image*/ /**<CNcomment: ͼ\CF\F1\BF\ED\B6\C8*/
    HI_U32                      u32ImageHeight;         /**<Height of image*/ /**<CNcomment: ͼ\CF\F1\B8߶\C8*/
    HI_BOOL                     bProgressive;           /**<Sampling type (progressive or interlaced)*/ /**<CNcomment: \B2\C9\D1\F9\B7\BDʽ(\D6\F0\D0\D0/\B8\F4\D0\D0) */
    HI_U32                      u32FrameRate;           /**<Frame rate*//**<CNcomment:֡\C2\CA*/
}HI_UNF_NORMCHANGE_PARAM_S;

/**Defines the video format.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ\B8\F1ʽö\BE\D9*/
typedef enum hiUNF_VIDEO_FORMAT_E
{
    /* Semi-Planner */
    HI_UNF_FORMAT_YUV_SEMIPLANAR_422,       /**<The YUV spatial sampling format is 4:2:2.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪ4:2:2*/
    HI_UNF_FORMAT_YUV_SEMIPLANAR_420,       /**<The YUV spatial sampling format is 4:2:0, V first.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪ4:2:0\A3\ACV\D4ڵ\CDλ*/
    HI_UNF_FORMAT_YUV_SEMIPLANAR_400,
    HI_UNF_FORMAT_YUV_SEMIPLANAR_411,
    HI_UNF_FORMAT_YUV_SEMIPLANAR_422_1X2,
    HI_UNF_FORMAT_YUV_SEMIPLANAR_444,
    HI_UNF_FORMAT_YUV_SEMIPLANAR_420_UV,   /**<The YUV spatial sampling format is 4:2:0,U first.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪ4:2:0, U\D4ڵ\CDλ*/


    /* Package */
    HI_UNF_FORMAT_YUV_PACKAGE_UYVY,         /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is UYVY.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪUYVY*/
    HI_UNF_FORMAT_YUV_PACKAGE_YUYV,         /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is YUYV.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪYUYV*/
    HI_UNF_FORMAT_YUV_PACKAGE_YVYU,         /**<The YUV spatial sampling format is package, and the pixel arrangement sequence in the memory is YVYU.*/ /**<CNcomment: YUV\BFռ\E4\B2\C9\D1\F9\B8\F1ʽΪpackage,\C4ڴ\E6\C5\C5\C1\D0ΪYVYU*/

    /* Planner */
    HI_UNF_FORMAT_YUV_PLANAR_400,
    HI_UNF_FORMAT_YUV_PLANAR_411,
    HI_UNF_FORMAT_YUV_PLANAR_420,
    HI_UNF_FORMAT_YUV_PLANAR_422_1X2,
    HI_UNF_FORMAT_YUV_PLANAR_422_2X1,
    HI_UNF_FORMAT_YUV_PLANAR_444,
    HI_UNF_FORMAT_YUV_PLANAR_410,
    HI_UNF_FORMAT_YUV_TILE_420,             /**<The YUV spatial sampling format is TILE 4:2:0, V first.*/
    HI_UNF_FORMAT_YUV_TILE_420_UV,          /**<The YUV spatial sampling format is TILE 4:2:0, U first.*/
    HI_UNF_FORMAT_YUV_BUTT,

    HI_UNF_FORMAT_RGB_SEMIPLANAR_444,
    HI_UNF_FORMAT_RGB_888,
    HI_UNF_FORMAT_ARGB_8888,
    HI_UNF_FORMAT_RGB_BUTT
}HI_UNF_VIDEO_FORMAT_E;

/**Defines the type of the video frame.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ֡\B5\C4\C0\E0\D0\CDö\BE\D9*/
typedef enum hiUNF_VIDEO_FRAME_TYPE_E
{
    HI_UNF_FRAME_TYPE_UNKNOWN,   /**<Unknown*/ /**<CNcomment: δ֪\B5\C4֡\C0\E0\D0\CD*/
    HI_UNF_FRAME_TYPE_I,         /**<I frame*/ /**<CNcomment: I֡*/
    HI_UNF_FRAME_TYPE_P,         /**<P frame*/ /**<CNcomment: P֡*/
    HI_UNF_FRAME_TYPE_B,         /**<B frame*/ /**<CNcomment: B֡*/
    HI_UNF_FRAME_TYPE_IDR,       /**<IDR frame*/ /**<CNcomment: IDR֡*/
    HI_UNF_FRAME_TYPE_BLA,       /**<BLA frame*/ /**<CNcomment: BLA֡*/
    HI_UNF_FRAME_TYPE_CRA,       /**<CRA frame*/ /**<CNcomment: CRA֡*/
    HI_UNF_FRAME_TYPE_BUTT
}HI_UNF_VIDEO_FRAME_TYPE_E;

/**Defines the video frame/field mode.*/
/**CNcomment: \B6\A8\D2\E5\CA\D3Ƶ֡\B3\A1ģʽö\BE\D9*/
typedef enum hiUNF_VIDEO_FIELD_MODE_E
{
    HI_UNF_VIDEO_FIELD_ALL,        /**<Frame mode*/ /**<CNcomment: ֡ģʽ*/
    HI_UNF_VIDEO_FIELD_TOP,        /**<Top field mode*/ /**<CNcomment: \B6\A5\B3\A1ģʽ*/
    HI_UNF_VIDEO_FIELD_BOTTOM,     /**<Bottom field mode*/ /**<CNcomment: \B5׳\A1ģʽ*/
    HI_UNF_VIDEO_FIELD_BUTT
}HI_UNF_VIDEO_FIELD_MODE_E;


/**Defines 3D frame packing type*/
typedef enum hiUNF_VIDEO_FRAME_PACKING_TYPE_E
{
    HI_UNF_FRAME_PACKING_TYPE_NONE,             /**< Normal frame, not a 3D frame */
    HI_UNF_FRAME_PACKING_TYPE_SIDE_BY_SIDE,     /**< Side by side */
    HI_UNF_FRAME_PACKING_TYPE_TOP_AND_BOTTOM,   /**< Top and bottom */
    HI_UNF_FRAME_PACKING_TYPE_TIME_INTERLACED,  /**< Time interlaced: one frame for left eye, the next frame for right eye */
    HI_UNF_FRAME_PACKING_TYPE_FRAME_PACKING,    /**< frame packing */
    HI_UNF_FRAME_PACKING_TYPE_3D_TILE,          /**< Tile 3D */
    HI_UNF_FRAME_PACKING_TYPE_BUTT
}HI_UNF_VIDEO_FRAME_PACKING_TYPE_E;

typedef struct hiUNF_VIDEO_FRAME_ADDR_S
{
    HI_U32             u32YAddr;    /**<Physical address of the Y  component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡Y\B7\D6\C1\BF\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ*/
    HI_U32             u32CAddr;    /**<Physical address of the C  component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡C\B7\D6\C1\BF\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ*/
    HI_U32             u32CrAddr;   /**<Physical address of the Cr component in the current frame*/ /**<CNcomment: \B5\B1ǰ֡Cr\B7\D6\C1\BF\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ*/

    HI_U32             u32YStride;  /**<Stride of the Y component*/ /**<CNcomment: Y\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/
    HI_U32             u32CStride;  /**<Stride of the C component*/ /**<CNcomment: C\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/
    HI_U32             u32CrStride; /**<Stride of the Cr component*/ /**<CNcomment: Cr\B7\D6\C1\BF\CA\FD\BEݵĿ\E7\B7\F9*/
}HI_UNF_VIDEO_FRAME_ADDR_S;

typedef struct hiUNF_VIDEO_FRAME_INFO_S
{
    HI_U32                              u32FrameIndex;      /**<Frame index ID of a video sequence*/ /**<CNcomment: \CA\D3Ƶ\D0\F2\C1\D0\D6е\C4֡\CB\F7\D2\FD\BA\C5*/
    HI_UNF_VIDEO_FRAME_ADDR_S           stVideoFrameAddr[2];
    HI_U32                              u32Width;           /**<Width of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\BF\ED*/
    HI_U32                              u32Height;          /**<Height of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\B8\DF*/
    HI_U32                              u32SrcPts;          /**<Original PTS of a video frame*/ /**<CNcomment: \CA\D3Ƶ֡\B5\C4ԭʼʱ\BC\E4\B4\C1*/
    HI_U32                              u32Pts;             /**<PTS of a video frame*/ /**<CNcomment: \CA\D3Ƶ֡\B5\C4ʱ\BC\E4\B4\C1*/
    HI_U32                              u32AspectWidth;
    HI_U32                              u32AspectHeight;
    HI_UNF_VCODEC_FRMRATE_S             stFrameRate;

    HI_UNF_VIDEO_FORMAT_E               enVideoFormat;      /**<Video YUV format*/ /**<CNcomment: \CA\D3ƵYUV\B8\F1ʽ*/
    HI_BOOL                             bProgressive;       /**<Sampling type (progressive or interlaced)*/ /**<CNcomment: \B2\C9\D1\F9\B7\BDʽ(\D6\F0\D0\D0/\B8\F4\D0\D0) */
    HI_UNF_VIDEO_FIELD_MODE_E           enFieldMode;        /**<Frame or field encoding mode*/ /**<CNcomment: ֡\BB򳡱\E0\C2\EBģʽ*/
    HI_BOOL                             bTopFieldFirst;     /**<Top field first flag*/ /**<CNcomment: \B6\A5\B3\A1\D3\C5\CFȱ\EA־*/
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E   enFramePackingType; /**<3D frame packing type*/
    HI_U32                              u32Circumrotate;    /**<Need circumrotate, 1 need */
    HI_BOOL                             bVerticalMirror;
    HI_BOOL                             bHorizontalMirror;
    HI_U32                              u32DisplayWidth;    /**<Width of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\BF\ED*/
    HI_U32                              u32DisplayHeight;   /**<Height of the displayed picture*/ /**<CNcomment: \CF\D4ʾͼ\CF\F1\B8\DF*/
    HI_U32                              u32DisplayCenterX;  /**<Horizontal coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/ /**<CNcomment: \CF\D4ʾ\D6\D0\D0\C4x\D7\F8\B1꣬ԭʼͼ\CF\F1\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3*/
    HI_U32                              u32DisplayCenterY;  /**<Vertical coordinate of the center of the displayed picture (the upper left point of the source picture serves as the coordinate origin)*/ /**<CNcomment: \CF\D4ʾ\D6\D0\D0\C4y\D7\F8\B1꣬ԭʼͼ\CF\F1\D7\F3\C9Ͻ\C7Ϊ\D7\F8\B1\EAԭ\B5\E3*/
    HI_U32                              u32ErrorLevel;      /**<Error percentage of a decoded picture, ranging from 0% to 100%*/ /**<CNcomment: һ\B7\F9\BD\E2\C2\EBͼ\CF\F1\D6еĴ\ED\CE\F3\B1\C8\C0\FD\A3\ACȡֵΪ0\A1\AB100*/
    HI_U32                              u32Private[64];     /**<Private data for every frame:
                                                                u32Private[0]: securty flag, if u32Private[0] == 1, this is a secure frame;
                                                                */


}HI_UNF_VIDEO_FRAME_INFO_S;

typedef struct hiUNF_VIDEO_FRM_STATUS_INFO_S
{
    HI_UNF_VIDEO_FRAME_TYPE_E enVidFrmType; /**<Type of video frame*/ /**<CNcomment: \CA\D3Ƶ֡\C0\E0\D0\CD*/
    HI_U32 u32VidFrmStreamSize;             /**<Size of video frame*/ /**<CNcomment: \CA\D3Ƶ֡\B4\F3С*/
    HI_U32 u32VidFrmQP;                     /**<QP of video frame*/ /**<CNcomment: \CA\D3Ƶ֡QP*/
    HI_U32 u32VidFrmPTS;                    /**<PTS of video frame*/ /**<CNcomment: \CA\D3Ƶ֡pts*/
    HI_U32 u32MaxMV;                        /**<MAX MV*/ /**<CNcomment: \CA\D3Ƶ֡\D7\EE\B4\F3MV*/
    HI_U32 u32MinMV;                        /**<MIN MV*/ /**<CNcomment: \CA\D3Ƶ֡\D7\EEСMV*/
    HI_U32 u32AvgMV;                        /**<AVG MV*/ /**<CNcomment: \CA\D3Ƶ֡MVƽ\BE\F9ֵ*/
    HI_U32 u32SkipRatio;                    /**<MB ratio */ /**<CNcomment: \CA\D3Ƶ֡MB\B1\C8\C0\FD0~100*/
    HI_U32 u32DecoderBuffer;                /**<BUFFER STATE>*/ /**<CNcomment: 0-ok, 2-UnderFlow, 3-DecodeErr*/
}HI_UNF_VIDEO_FRM_STATUS_INFO_S;

typedef struct hiUNF_VIDEO_FRM_DISPLAY_TIME_S
{
    HI_S64 s64PTS;                          /**<PTS of video frame*/ /**<CNcomment: \CA\D3Ƶ֡PTS*/
    HI_S64 s64DisplayTime;                  /**<Estimated time of display */ /**<CNcomment: \CA\D3Ƶ֡Ԥ\BC\C6\CF\D4ʾʱ\BC\E4*/
} HI_UNF_VIDEO_FRM_DISPLAY_TIME_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* __HI_UNF_VIDEO_ H*/
