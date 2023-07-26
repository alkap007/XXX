/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_edid.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013-8-28
  Description   :
  History       :
  1.Date        : 2013-8-28
    Author      : sdk
    Modification: Created file

*******************************************************************************/
#ifndef __HI_UNF_EDID_H__
#define __HI_UNF_EDID_H__

#include "hi_unf_common.h"
#include "hi_unf_audio.h"
#include "hi_unf_video.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      EDID */
/** @{*/  /** <!-- [EDID] */

/**EDID Audio type enum*//**CNcomment:HDMI \D2\F4Ƶ\C0\E0\D0\CD ö\BE\D9 */
typedef enum hiUNF_EDID_AUDIO_FORMAT_CODE_E
{
    HI_UNF_EDID_AUDIO_FORMAT_CODE_RESERVED  = 0x00,  /**<Audio coding type, refer stream,default type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C0\E0\D0ͣ\AC\B2ο\BC\CA\FD\BE\DD\C1\F7\A3\ACȱʡ\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_PCM,               /**<Audio coding PCM type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBPCM\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_AC3,               /**<Audio coding AC3 type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBAC3\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_MPEG1,             /**<Audio coding MPEG1 type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBMPEG1\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_MP3,               /**<Audio coding MP3 type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBMP3\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_MPEG2,             /**<Audio coding MPEG2 type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBMPEG2\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_AAC,               /**<Audio coding AAC type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBAAC\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_DTS,               /**<Audio coding DTS type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBDTS\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_ATRAC,             /**<Audio coding ATRAC type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBATRAC\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_ONE_BIT,           /**<Audio coding ONE BIT AUDIO type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBONE_BIT\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_DDP,               /**<Audio coding DDPLUS type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBDDPLUS\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_DTS_HD,            /**<Audio coding DTS HD type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBDTS HD\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_MAT,               /**<Audio coding MAT type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBMAT\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_DST,               /**<Audio coding DST type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBDST\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_WMA_PRO,           /**<Audio coding WMA PRO type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EBWMA PRO\B8\F1ʽ */
    HI_UNF_EDID_AUDIO_FORMAT_CODE_BUTT,
}HI_UNF_EDID_AUDIO_FORMAT_CODE_E;

/**the max audio smprate count*//**CNcomment:\D7\EE\B4\F3\D2\F4Ƶ\B2\C9\D1\F9\C2ʸ\F6\CA\FD */
#define MAX_SAMPE_RATE_NUM 8

/**the max audio bit depth count*//**CNcomment:\D7\EE\B4\F3\D2\F4Ƶ\B1\C8\CC\D8\C9\EE\B6ȸ\F6\CA\FD */
#define MAX_BIT_DEPTH_NUM  6

/**EDID Audio Info struct*//**CNcomment:EDID \D2\F4Ƶ\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_AUDIO_INFO_S
{
    HI_UNF_EDID_AUDIO_FORMAT_CODE_E enAudFmtCode; /**<Audio coding type*//**<CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C0\E0\D0\CD */
    HI_UNF_SAMPLE_RATE_E            enSupportSampleRate[MAX_SAMPE_RATE_NUM]; /**<Audio sample rate*//**<CNcomment:\D2\F4Ƶ\B2\C9\D1\F9\C2\CA */
    HI_U32                          u32SupportSampleRateNum; /**<Audio sample rate num*//**<CNcomment:\D2\F4Ƶ\B2\C9\D1\F9\C2\CA\C0\E0\D0\CD */
    HI_U8                           u8AudChannel;      /**<Aud Channel of the coding type*//**<CNcomment:\B1\E0\C2\EB\C0\E0\D0Ͷ\D4Ӧ\B5\C4\D2\F4Ƶͨ\B5\C0\C4\DC\C1\A6 */

    HI_UNF_BIT_DEPTH_E              bSupportBitDepth[MAX_BIT_DEPTH_NUM];/*sample bit depth,when audio format code is HI_UNF_EDID_AUDIO_FORMAT_CODE_PCM*//**<CNcomment:PCM\C0\E0\D0\CD\CF\C2\C0\A9չ\D0\C5ϢΪ\B1\C8\CC\D8\C9\EE\B6\C8 */
    HI_U32                          u32SupportBitDepthNum; /*sample bit depth Num,when audio format code is HI_UNF_EDID_AUDIO_FORMAT_CODE_PCM*//**<CNcomment:PCM\C0\E0\D0\CD\CF\C2\C0\A9չ\D0\C5ϢΪ\B1\C8\CC\D8\C9\EE\B6ȸ\F6\CA\FD */
    HI_U32                          u32MaxBitRate;  /**enter max bit rate,when audio format code is HI_UNF_EDID_AUDIO_FORMAT_CODE_AC3 - HI_UNF_EDID_AUDIO_FORMAT_CODE_ATRAC**//**<CNcomment:AC3-ATRACʱ \C0\A9չ\D0\C5Ϣ\C0\E0\D0\CDΪ\D7\EE\B4\F3\B1\C8\CC\D8\CB\D9\C2\CA*/
    HI_BOOL                         bSupportDolbyAtmos;/**<Dolby Atmos support or not*//**CNcomment:\CAǷ\F1֧\B3\D6Dolby Atmos */
}HI_UNF_EDID_AUDIO_INFO_S;

/**EDID Audio speaker enum*//**CNcomment:EDID \D2\F4Ƶ\D1\EF\C9\F9\C6\F7\C5\E4\D6\C3ö\BE\D9 */
typedef enum hiUNF_EDID_AUDIO_SPEAKER_E
{
    HI_UNF_EDID_AUDIO_SPEAKER_FL_FR   ,
    HI_UNF_EDID_AUDIO_SPEAKER_LFE     ,
    HI_UNF_EDID_AUDIO_SPEAKER_FC      ,
    HI_UNF_EDID_AUDIO_SPEAKER_RL_RR   ,
    HI_UNF_EDID_AUDIO_SPEAKER_RC      ,
    HI_UNF_EDID_AUDIO_SPEAKER_FLC_FRC ,
    HI_UNF_EDID_AUDIO_SPEAKER_RLC_RRC ,
    HI_UNF_EDID_AUDIO_SPEAKER_FLW_FRW ,
    HI_UNF_EDID_AUDIO_SPEAKER_FLH_FRH ,
    HI_UNF_EDID_AUDIO_SPEAKER_TC      ,
    HI_UNF_EDID_AUDIO_SPEAKER_FCH     ,
    HI_UNF_EDID_AUDIO_SPEAKER_BUTT    ,
} HI_UNF_EDID_AUDIO_SPEAKER_E;

/**EDID MANUFACTURE Info struct*//**CNcomment:EDID\D6\C6\D4\EC\C9\CC\D0\C5Ϣ */
typedef struct hiUNF_EDID_MANUFACTURE_INFO_E
{
    HI_U8      u8MfrsName[4];            /**<Manufacture name*//**<CNcomment:\C9豸\B3\A7\C9̱\EAʶ */
    HI_U32     u32ProductCode;           /**<Product code*//**<CNcomment:\C9豸ID */
    HI_U32     u32SerialNumber;          /**<Serial numeber of Manufacture*//**<CNcomment:\C9豸\D0\F2\C1к\C5 */
    HI_U32     u32Week;                  /**<the week of manufacture*//**<CNcomment:\C9豸\C9\FA\B2\FA\C8\D5\C6\DA(\D6\DC) */
    HI_U32     u32Year;                  /**<the year of manufacture*//**<CNcomment:\C9豸\C9\FA\B2\FA\C8\D5\C6\DA(\C4\EA) */
    HI_U8      u8pSinkName[14];          /**<Sink Name*//**<CNcomment:\C9豸\C3\FB\B3\C6*/
}HI_UNF_EDID_MANUFACTURE_INFO_S;


/**EDID Display Base Parameters struct*//**CNcomment:EDID \CF\D4ʾ\C6\C1\BB\F9\B1\BE\B2\CE\CA\FD */
typedef struct hiUNF_EDID_BASE_PARA_S
{
    HI_U8      u8MaxImageWidth;               /**<The disp image max width  (0~255)cm*//**<CNcomment: \BF\C9\CF\D4ʾͼ\CF\F1\D7\EE\B4\F3\BF\ED */
    HI_U8      u8MaxImageHeight;              /**<The disp image max height (0~255)cm*//**<CNcomment: \BF\C9\CF\D4ʾͼ\CF\F1\D7\EE\B4\F3\B8\DF */
} HI_UNF_EDID_BASE_DISP_PARA_S;


/**EDID Colorimety Info struct*//**CNcomment:EDID ɫ\B5\F7\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_COLORIMETRY_S
{
    HI_BOOL    bxvYCC601      ;          /**<The sink is support xcYCC601 or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6xvYCC601\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bxvYCC709      ;          /**<The sink is support xvYCC709 or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6xvYCC709\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bsYCC601       ;          /**<The sink is support sYCC601 or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6sYCC601\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bAdobleYCC601  ;          /**<The sink is support AdobleYCC601 or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6AdobleYCC601\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bAdobleRGB     ;          /**<The sink is support AdobleRGB or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6AdobleRGB\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bBT2020cYCC    ;          /**<The sink is support BT2020cYCC or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6BT2020cYCC\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bBT2020YCC     ;          /**<The sink is support BT2020YCC or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6BT2020YCC\D1\D5ɫ\B8\F1ʽ */
    HI_BOOL    bBT2020RGB     ;          /**<The sink is support BT2020RGB or not flag*//**<CNcomment:\CAǷ\F1֧\B3\D6BT2020RGB\D1\D5ɫ\B8\F1ʽ */
} HI_UNF_EDID_COLORIMETRY_S;

/**EDID color space Info struct*//**CNcomment:EDID ɫ\B2ʿռ\E4\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_COLOR_SPACE_S
{
    HI_BOOL    bRGB444        ;          /**<The sink is support RGB444 or not flag*//**<CNcomment:< \CAǷ\F1֧\B3\D6RGB444\CF\D4ʾ */
    HI_BOOL    bYCbCr422      ;          /**<The sink is support YCbCr422 or not flag*//**<CNcomment:< \CAǷ\F1֧\B3\D6YCbCr422\CF\D4ʾ */
    HI_BOOL    bYCbCr444      ;          /**<The sink is support YCbCr444 or not flag*//**<CNcomment:< \CAǷ\F1֧\B3\D6YCbCr444\CF\D4ʾ */
    HI_BOOL    bYCbCr420      ;          /**<The sink is support YCbCr420 or not flag*//**<CNcomment:< \CAǷ\F1֧\B3\D6YCbCr420\CF\D4ʾ */
} HI_UNF_EDID_COLOR_SPACE_S;

/**EDID cec address Info struct*//**CNcomment:EDID cec\B5\D8ַ\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_CEC_ADDRESS_S
{
    HI_BOOL    bPhyAddrValid   ;          /**<the flag of phyiscs address is valid or not*//**<CNcomment:CEC\CE\EF\C0\ED\B5\D8ַ\CAǷ\F1\D3\D0Ч\B1\EA־ */
    HI_U8      u8PhyAddrA      ;          /**<phyiscs address A of CEC*//**<CNcomment:CEC\CE\EF\C0\ED\B5\D8ַA */
    HI_U8      u8PhyAddrB      ;          /**<phyiscs address B of CEC*//**<CNcomment:CEC\CE\EF\C0\ED\B5\D8ַB */
    HI_U8      u8PhyAddrC      ;          /**<phyiscs address C of CEC*//**<CNcomment:CEC\CE\EF\C0\ED\B5\D8ַC */
    HI_U8      u8PhyAddrD      ;          /**<phyiscs address D of CEC*//**<CNcomment:CEC\CE\EF\C0\ED\B5\D8ַD */
} HI_UNF_EDID_CEC_ADDRESS_S;

/**EDID deep color Info struct*//**CNcomment:EDID \C9\EEɫ\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_DEEP_COLOR_S
{
    HI_BOOL    bDeepColorY444   ;         /**<the Deep Color support YCBCR444-bits same with RGB-bits or not*//**<CNcomment:\CAǷ\F1֧\B3\D6 YCBCR 4:4:4  Deep Color \D3\EBRGB\B5\C4bit\CA\FDһ\D6\C2 */
    HI_BOOL    bDeepColor30Bit  ;         /**<the Deep Color support RGB 30 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6RGB Deep Color 30bit ģʽ */
    HI_BOOL    bDeepColor36Bit  ;         /**<the Deep Color support RGB 36 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6RGB Deep Color 36bit ģʽ */
    HI_BOOL    bDeepColor48Bit  ;         /**<the Deep Color support RGB 48 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6RGB Deep Color 48bit ģʽ */
} HI_UNF_EDID_DEEP_COLOR_S;

typedef struct hiUNF_EDID_DEEP_COLOR_Y420_S
{
    HI_BOOL    bY420DeepColor30Bit  ;     /**<the Deep Color support YCBCR420  30 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6YCBCR420 Deep Color 30bit ģʽ */
    HI_BOOL    bY420DeepColor36Bit  ;     /**<the Deep Color support YCBCR420  36 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6YCBCR420 Deep Color 36bit ģʽ */
    HI_BOOL    bY420DeepColor48Bit  ;     /**<the Deep Color support YCBCR420  48 bit  or not *//**<CNcomment:\CAǷ\F1֧\B3\D6YCBCR420 Deep Color 48bit ģʽ */
} HI_UNF_EDID_DEEP_COLOR_Y420_S;

typedef struct hiUNF_EDID_HDCP_S
{
    HI_BOOL     bHdcp14Support  ;         /**<the HDCP support HDCP1.4 or not *//**<CNcomment:\CAǷ\F1֧\B3\D6HDCP1.4 */
    HI_BOOL     bHdcp22Support  ;         /**<the HDCP support HDCP2.2 or not *//**<CNcomment:\CAǷ\F1֧\B3\D6HDCP2.2 */
} HI_UNF_EDID_HDCP_S;

/**HDMI 3d enum type*/
/**CNcomment: HDMI 3d ö\BE\D9\C0\E0\D0\CD */
typedef enum hiUNF_EDID_3D_TYPE_E
{
    HI_UNF_EDID_3D_FRAME_PACKETING                 = 0x00, /**<3d type:Frame Packing*//**<CNcomment:3d ģʽ:֡\B7\E2װ*/
    HI_UNF_EDID_3D_FIELD_ALTERNATIVE               = 0x01, /**<3d type:Field alternative*//**<CNcomment:3d ģʽ:\B3\A1\BD\BB\B4\ED*/
    HI_UNF_EDID_3D_LINE_ALTERNATIVE                = 0x02, /**<3d type:Line alternative*//**<CNcomment:3d ģʽ:\D0н\BB\B4\ED*/
    HI_UNF_EDID_3D_SIDE_BY_SIDE_FULL               = 0x03, /**<3d type:Side by side full*//**<CNcomment:3d ģʽ:\B2\A2\C5\C5ʽ \D7\F3\D3\D2ȫ\B3\A1*/
    HI_UNF_EDID_3D_L_DEPTH                         = 0x04, /**<3d type:L+depth*//**<CNcomment:3d ģʽ:L+DEPTH*/
    HI_UNF_EDID_3D_L_DEPTH_GRAPHICS_GRAPHICS_DEPTH = 0x05, /**<3d type:L+depth+Graphics+Graphics-depth*//**<CNcomment:3d ģʽ:L+depth+Graphics+Graphics-depth*/
    HI_UNF_EDID_3D_TOP_AND_BOTTOM                  = 0x06, /**<3d type:Top and Bottom*//**<CNcomment:3d ģʽ:\C9\CF\CF\C2ģʽ*/
    HI_UNF_EDID_3D_SIDE_BY_SIDE_HALF               = 0x08, /**<3d type:Side by side half*//**<CNcomment:3d ģʽ:\B2\A2\C5\C5ʽ \D7\F3\D3Ұ\EB\B1\DF*/
    HI_UNF_EDID_3D_BUTT,
}HI_UNF_EDID_3D_TYPE_E;

/**3d Info struct*//**CNcomment: 3d \D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_EDID_3D_INFO_S
{
    HI_BOOL    bSupport3D  ;                         /**<flag of 3d*//**<CNcomment:\CAǷ\F1֧\B3\D63d*/
    HI_BOOL    bSupport3DType[HI_UNF_EDID_3D_BUTT] ; /**<supported 3d type*//**<CNcomment:֧\B3ֵ\C43d\C0\E0\D0\CD*/
} HI_UNF_EDID_3D_INFO_S;

/**EDID detailed Timing Info struct*//**CNcomment: EDID \CF\EAϸʱ\D0\F2*/
typedef struct hiUNF_EDID_TIMING_S
{
    HI_U32                        u32VFB;          /**<vertical front blank*//**<CNcomment:\B4\B9ֱǰ\CF\FB\D2\FE*/
    HI_U32                        u32VBB;          /**<vertical back blank*//**<CNcomment:\B4\B9ֱ\BA\F3\CF\FB\D2\FE*/
    HI_U32                        u32VACT;         /**<vertical active area*//**<CNcomment:\B4\B9ֱ\D3\D0Ч\C7\F8*/
    HI_U32                        u32HFB;          /**<horizonal front blank*//**<CNcomment:ˮƽǰ\CF\FB\D2\FE*/
    HI_U32                        u32HBB;          /**<horizonal back blank*//**<CNcomment:ˮƽ\BA\F3\CF\FB\D2\FE*/
    HI_U32                        u32HACT;         /**<horizonal active area*/ /**<CNcomment:ˮƽ\D3\D0Ч\C7\F8*/
    HI_U32                        u32VPW;          /**<vertical sync pluse width*//**<CNcomment:\B4\B9ֱ\C2\F6\B3\E5\BF\ED\B6\C8*/
    HI_U32                        u32HPW;          /**<horizonal sync pluse width*/ /**<CNcomment:ˮƽ\C2\F6\B3\E5\BF\ED\B6\C8*/
    HI_BOOL                       bIDV;            /**< flag of data valid signal is needed flip*//**<CNcomment:\D3\D0Ч\CA\FD\BE\DD\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_BOOL                       bIHS;            /**<flag of horizonal sync pluse is needed flip*//**<CNcomment:ˮƽͬ\B2\BD\C2\F6\B3\E5\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_BOOL                       bIVS;            /**<flag of vertical sync pluse is needed flip*//**<CNcomment:\B4\B9ֱͬ\B2\BD\C2\F6\B3\E5\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_U32                        u32ImageWidth;   /**<image width *//**<CNcomment:ͼ\CF\F1\BF\ED*/
    HI_U32                        u32ImageHeight;  /**<image height *//**<CNcomment:ͼ\CF\F1\B8\DF */
    HI_U32                        u32AspectRatioW; /**<aspect ratio width *//**<CNcomment:\BF\ED\B8߱\C8 */
    HI_U32                        u32AspectRatioH; /**<aspect ratio height *//**<CNcomment:\BF\ED\B8߱\C8 */
    HI_BOOL                       bInterlace;      /**<flag of interlace *//**<CNcomment:\D6\F0\B8\F4\D0м\EC\B2\E2\B1\EA\BC\C7 */
    HI_S32                        u32PixelClk;     /**<pixelc clk for this timing *//**<CNcomment:\B5\B1ǰ\D6\C6ʽ\B6\D4Ӧ\B5\C4ʱ\D6\D3 */
} HI_UNF_EDID_TIMING_S;

/**the max audio capability count*//**CNcomment:\D7\EE\B4\F3\D2\F4Ƶ\C4\DC\C1\A6\BC\AF\B8\F6\CA\FD */
#define HI_UNF_EDID_MAX_AUDIO_CAP_COUNT  16

/**EDID Dolby capability in VSVDB version 0*//**CNcomment: EDID VSVDB\B0汾0\D6\D0Dolby\C4\DC\C1\A6\C3\E8\CA\F6*/
typedef struct hiUNF_EDID_DOLBY_CAPS_VER_0_S
{
    HI_BOOL     bYUV422_12Bit;          /* support(HI_TRUE) or not support(HI_FALSE) a YUV422-12Bit dolby singal *//**<CNcomment:\CAǷ\F1֧\B3\D6YUV422-12Bit\B5\C4Dolby\D0ź\C5*/
    HI_BOOL     b2160P60;               /* capable of processing a max timming 3840X2160p60(HI_TRUE) /3840X2160p30(HI_FALSE) *//**<CNcomment:\D7\EE\B4\F3\C4\DC\C1\A6\CAǵ\BD4kp60\BB\B9\CA\C74kp30 */
    HI_BOOL     bGlobalDimming;         /**<support(HI_TRUE) or not support(HI_FALSE) global dimming. *//**<CNcomment:\CAǷ\F1֧\B3\D6global dimming\A3\AC֧\B3\D6(HI_TRUE)\A3\AC\B2\BB֧\B3\D6(HI_FALSE)*/
    HI_U16      u16White_X;             /* white point chromaticity coordinate x   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N), only support when u8VSVDBVersion = 0. */
    HI_U16      u16White_Y;             /* white point  chromaticity coordinate y  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N), only support when u8VSVDBVersion = 0.*/
    HI_U8       u8DMmajorVersion;       /* the major version of display management implemented. only support when u8VSVDBVersion = 0.*/
    HI_U8       u8DMminorVersion;       /* the minor version of display management implemented. only support when u8VSVDBVersion = 0.*/
    HI_U16      u16TargetMinPQ;         /* Perceptual quantization(PQ)-encoded value of minimum display luminance */
    HI_U16      u16TargetMaxPQ;         /* PQ-encoded value of maximum display luminance */
    HI_U16      u16Red_X;               /**<red primary chromaticity coordinate x   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Red_Y;               /**<red primary chromaticity coordinate y   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_X;             /**<green primary chromaticity coordinate x ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_Y;             /**<green primary chromaticity coordinate y ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_X;              /**<blue primary chromaticity coordinate x  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_Y;              /**<blue primary chromaticity coordinate y  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
}HI_UNF_EDID_DOLBY_CAPS_VER_0_S;

/**EDID Dolby capability in VSVDB version 1*//**CNcomment: EDID VSVDB\B0汾1\D6\D0Dolby\C4\DC\C1\A6\C3\E8\CA\F6*/
typedef struct hiUNF_EDID_DOLBY_CAPS_VER_1_S
{
    HI_BOOL     bYUV422_12Bit;          /* support(HI_TRUE) or not support(HI_FALSE) a YUV422-12Bit dolby singal; For low-latency dolbyvision this flag is ingnored *//**<CNcomment:\CAǷ\F1֧\B3\D6YUV422-12Bit\B5\C4Dolby\D0ź\C5, \B5\B1Low-latency\B6ű\C8\CF¸ñ\EA־\BA\F6\C2\D4 */
    HI_BOOL     b2160P60;               /* capable of processing a max timming 3840X2160p60(HI_TRUE) /3840X2160p30(HI_FALSE); For low-latency dolbyvision this bit maybe ingnored,relay on supported video format from the E-EDID *//**<CNcomment:\D7\EE\B4\F3\C4\DC\C1\A6\CAǵ\BD4kp60\BB\B9\CA\C74kp30, \B5\B1Low-latency\B6ű\C8\CF¸ñ\EA־\D0\E8\B2ο\BC\D6\C6ʽ\C4\DC\C1\A6 */
    HI_BOOL     bGlobalDimming;         /**<support(HI_TRUE) or not support(HI_FALSE) global dimming. *//**<CNcomment:\CAǷ\F1֧\B3\D6global dimming\A3\AC֧\B3\D6(HI_TRUE)\A3\AC\B2\BB֧\B3\D6(HI_FALSE)*/
    HI_BOOL     bColorimetry;           /* this bit is valid only u8VSVDBVersion = 1. 0: Dolby Vision HDMI sink's colorimetry is close to Rec.709, 1: EDR HDMI sink's colorimetry is close to P3, if Byte[9] to Byte[14] are present, ignores this bit. *//**<CNcomment:\C8\F4Ϊ0\A3\ACDolby Vision Sink\C9豸ɫ\D3\F2\BDӽ\FCRec.709\A3\AC\C8\F4Ϊ1\A3\ACDolby Vision Sink\C9豸ɫ\D3\F2\BDӽ\FCP3\A3\AC\B5\AB\C8\E7\B9\FBByte[9]\B5\BDByte[14]\D3\D0\C9\F9\C3\F7\A3\AC\D4\F2\BA\F6\C2Դ˱\EA־\A1\A3*/
    HI_U8       u8DMVersion;            /* 0:based on display management v2.x; 1:based on the video and blending pipeline v3.x; 2-7: reserved. only support when u8VSVDBVersion = 1. */
    HI_U8       u8LowLatency;           /* 0:supports only standard DolbyVison; 1: Supports low latency with 12-bit YCbCr 4:2:2 interface using the HDMI native 12-bit YCbCr4:2:2 pixel encoding and standard Dolby Vision interface; 2-3:reserved */
    HI_U16      u16TargetMinLuminance;  /* minimum display luminance = (100+50*CV)cd/m2, where CV is the value */
    HI_U16      u16TargetMaxLuminance;  /* maximum display luminance = (CV/127)^2cd/m2, where CV is the value */
    HI_U16      u16Red_X;               /**<red primary chromaticity coordinate x   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Red_Y;               /**<red primary chromaticity coordinate y   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_X;             /**<green primary chromaticity coordinate x ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_Y;             /**<green primary chromaticity coordinate y ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_X;              /**<blue primary chromaticity coordinate x  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_Y;              /**<blue primary chromaticity coordinate y  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
}HI_UNF_EDID_DOLBY_CAPS_VER_1_S;

/**EDID Dolby capability in VSVDB version 2*//**CNcomment: EDID VSVDB\B0汾2\D6\D0Dolby\C4\DC\C1\A6\C3\E8\CA\F6*/
typedef struct hiUNF_EDID_DOLBY_CAPS_VER_2_S
{
    HI_BOOL     bYUV422_12Bit;          /* support(HI_TRUE) or not support(HI_FALSE) a YUV422-12Bit dolby singal */
    HI_BOOL     bBackLightContol;       /* supports Backlight Control */
    HI_BOOL     bGlobalDimming;         /**<support(HI_TRUE) or not support(HI_FALSE) global dimming. *//**<CNcomment:\CAǷ\F1֧\B3\D6global dimming\A3\AC֧\B3\D6(HI_TRUE)\A3\AC\B2\BB֧\B3\D6(HI_FALSE)*/
    HI_U8       u8DMVersion;            /* 0:based on display management v2.x; 1:based on the video and blending pipeline v3.x; 2-7: reserved. only support when u8VSVDBVersion = 1. */
    HI_U8       u8BackLtMinLuma;        /* minimum luminance level 0:25cd/m2 1:50cd/m2 2:75cd/m2 3:100cd/m2 */
    HI_U8       u8Interface;            /* 0:support only "low latency with YUV422" 1:support both "low latency with YUV422" and YUV444/RGB_10/12bit* 2:support both "standard DolbyVision" and "low latency with YUV422" 3:support "standard DolbyVision" "low latency YUV422 YUV444/RGB_10/12bit" */
    HI_U8       u8YUV444RGB444_10b12b;  /* 0:not support 1:support YUV444/RGB444_10bit 2:support YUV444/RGB444_12bit 3:reserved */
    HI_U16      u16TargetMinPQv2;       /* maximum display luminance, in the PQ-encoded value= u16TargetMinPQv2*20. A code value of 31 is approximately equivalent to 1cd/m2 */
    HI_U16      u16TargetMaxPQv2;       /* minimum display luminance, in the PQ-encoded value= 2055+u16TargetMaxPQv2*65. */
    HI_U16      u16Red_X;               /**<red primary chromaticity coordinate x   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Red_Y;               /**<red primary chromaticity coordinate y   ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_X;             /**<green primary chromaticity coordinate x ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Green_Y;             /**<green primary chromaticity coordinate y ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_X;              /**<blue primary chromaticity coordinate x  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
    HI_U16      u16Blue_Y;              /**<blue primary chromaticity coordinate y  ,bit[11:0]valid.Real value =SUM OF bit[N]*2^-(12-N) */
}HI_UNF_EDID_DOLBY_CAPS_VER_2_S;

/**EDID union of Dolby capability.*//**CNcomment: EDID Dolby\C4\DC\C1\A6\BC\AF\C1\AA\BA\CF\CC\E5*/
typedef union hiUNF_EDID_DOLBY_CAPS_U
{
    HI_UNF_EDID_DOLBY_CAPS_VER_0_S stVer0;
    HI_UNF_EDID_DOLBY_CAPS_VER_1_S stVer1;
    HI_UNF_EDID_DOLBY_CAPS_VER_2_S stVer2;
}HI_UNF_EDID_DOLBY_CAPS_U;

/**EDID Dolby capability.see <Dolby  Vision  HDMI Transmission Specification> *//**CNcomment: EDID Dolby\C4\DC\C1\A6\BC\AF\A3\AC\B2ο\BCDolby  Vision  HDMI Transmission Specification*/
typedef struct hiUNF_EDID_DOLBY_CAP_S
{
    HI_U8       u8VSVDBVersion;         /**<the version of VSVDB, value of 0-version0, 1-version1 2-version2, others means we not support at present. see <Dolby Vision HDMI Transmission Specification issue 2.9>*//**<CNcomment:VSVDB\B0汾,0\B1\EDʾ\B0汾0,1\B1\EDʾ\B0汾1,2\B1\EDʾ\B0汾2\A3\AC\C6\E4\CB\FBĿǰ\D4ݲ\BB֧\B3\D6*/
    HI_UNF_EDID_DOLBY_CAPS_U unVersionCaps; /**<DolbyVision capability in Dolby VSVDB. stVer0(u8VSVDBVersion=0) and stVer1(u8VSVDBVersion=1) and stVer2(u8VSVDBVersion=2).*//**<CNcomment:Dolby\B8\F7\B0汾\C4\DC\C1\A6\A3\AC\D2\C0\BE\DDDolby VSVDB\B0汾stVer0\B6\D4Ӧ(u8VSVDBVersion=0),stVer1\B6\D4Ӧ(u8VSVDBVersion=1),stVer2\B6\D4Ӧ(u8VSVDBVersion=2),\C6\E4\CB\FB\D4ݲ\BB֧\B3\D6*/
}HI_UNF_EDID_DOLBY_CAP_S;

/**EDID EOTF support. *//**CNcomment:EDID ֧\B3ֵ\C4EOTF\C0\E0\D0\CD */
typedef struct hiUNF_EDID_EOTF_S
{
    HI_BOOL bEotfSdr;               /**<Traditional gamma - SDR Luminance Range. *//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6SDR EOTF\A1\A3*/
    HI_BOOL bEotfHdr;               /**<Traditional gamma - HDR Luminance Range. *//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6HDR EOTF\A1\A3*/
    HI_BOOL bEotfSmpteSt2084;       /**<SMPTE ST 2084 *//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6SmpteSt2084 EOTF\A1\A3*/
    HI_BOOL bEotfHLG;               /**<Hybrid Log-Gamma(HLG) based on Recommendation ITU-R BT.2100-0 *//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6Hybrid Log-Gamma(HLG) */
    HI_BOOL bEotfFuture;            /**<Future EOTF *//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6\C6\E4\CB\FBEOTF\C0\E0\D0͡\A3*/
}HI_UNF_EDID_EOTF_S;

/**EDID Supported Static Metadata Descriptor *//**CNcomment:EDID ֧\B3ֵ\C4Metadata\C0\E0\D0\CD */
typedef struct hiUNF_EDID_HDR_METADATA_TYPE_S
{
    HI_BOOL bDescriptorType1;       /**<Support Static Metadata Type 1 or not.*//**<CNcomment:Sink\C9豸\CAǷ\F1֧\B3\D6metadata\C0\E0\D0\CD1\A1\A3*/
}HI_UNF_EDID_HDR_METADATA_TYPE_S;

/**EDID HDR capability,see <CEA-861.3-2015> *//**CNcomment:EDID HDR\C4\DC\C1\A6\BC\AF\A3\AC\B2ο\BCCEA-861.3-2015 */
typedef struct hiUNF_EDID_HDR_CAP_S{

    HI_UNF_EDID_EOTF_S                  stEotf;                 /**<EOTF support. *//**<CNcomment:Sink\C9豸֧\B3ֵ\C4EOTF\C0\E0\D0͡\A3*/
    HI_UNF_EDID_HDR_METADATA_TYPE_S     stMetadata;             /**<static metadata descriptor type(ID) support. *//**<CNcomment:Sink\C9豸֧\B3ֵ\C4metadata\C0\E0\D0͡\A3*/
    HI_U8                               u8MaxLuminance_CV;      /**<Desired Content Max Luminance Data. Real value(in 1cd/m^2) = 50.2^(CV/32) *//**<CNcomment:Sink\C9豸֧\B3\D6\D7\EE\B4\F3\C1\C1\B6\C8ֵ\A1\A3*/
    HI_U8                               u8AverageLumin_CV;      /**<Desired Content Max Frame-average Luminance. Real value(in 1cd/m^2) = 50.2^(CV/32) *//**<CNcomment:Sink\C9豸֧\B3\D6ƽ\BE\F9\C1\C1\B6\C8ֵ\A1\A3*/
    HI_U8                               u8MinLuminance_CV;      /**<Desired Content Min Luminance Data. Real value(in 1cd/m^2) = u8MaxLuminance_CV * (u8MinLuminance_CV/255)^2 / 100  *//**<CNcomment:Sink\C9豸֧\B3\D6\D7\EEС\C1\C1\B6\C8ֵ\A1\A3*/
}HI_UNF_EDID_HDR_CAP_S;

/**EDID Latency capability,see <HDMI1.4b> Page154 *//**CNcomment:Latency\C4\DC\C1\A6\A3\AC\B2ο\BC<HDMI1.4b> 154ҳ */
typedef struct hiUNF_EDID_LATENCY_S{
    HI_BOOL  bLatencyPresent;                  /**<Latency info is valid. *//**<CNcomment:Latency\D0\C5Ϣ\D3\D0Ч\A1\A3*/
    HI_U32   u32PVideoLatency;                 /**<video latency for progressive video formats.in milliseconds *//**<CNcomment:\D6\F0\D0\D0ɨ\C3\E8\CA\D3Ƶ\B5\C4\CA\D3Ƶlatency\A1\A3\B5\A5λms*/
    HI_U32   u32PAudioLatency;                 /**<audio latency for progressive video formats.in milliseconds *//**<CNcomment:\D6\F0\D0\D0ɨ\C3\E8\CA\D3Ƶ\B5\C4\D2\F4Ƶlatency\A1\A3\B5\A5λms*/
    HI_U32   u32IVideoLatency;                 /**<video latency for interlaced video formats.in milliseconds *//**<CNcomment:\D6\F0\D0\D0ɨ\C3\E8\CA\D3Ƶ\B5\C4\CA\D3Ƶlatency\A1\A3\B5\A5λms*/
    HI_U32   u32IAudioLatency;                 /**<audio latency for interlaced video formats.in milliseconds *//**<CNcomment:\B8\F4\D0\D0ɨ\C3\E8\CA\D3Ƶ\B5\C4\D2\F4Ƶlatency\A1\A3\B5\A5λms*/
}HI_UNF_EDID_LATENCY_S;


/**HDMI sink capability of interface*/
/**CNcomment: HDMI sink \BDӿ\DA\C4\DC\C1\A6\BC\AF */
typedef struct hiUNF_EDID_BASE_INFO_S
{
    HI_BOOL                         bSupportHdmi;           /**<The Device suppot HDMI or not,the device is DVI when nonsupport HDMI*//**<CNcomment:\C9豸\CAǷ\F1֧\B3\D6HDMI\A3\AC\C8\E7\B9\FB\B2\BB֧\B3֣\AC\D4\F2ΪDVI\C9豸.*/
    HI_UNF_ENC_FMT_E                enNativeFormat;         /**<The sink native video format*//**<CNcomment:\CF\D4ʾ\C9豸\CE\EF\C0\ED\B7ֱ\E6\C2\CA */
    HI_BOOL                         bSupportFormat[HI_UNF_ENC_FMT_BUTT]; /**<video capability,HI_TRUE:support the video display format;HI_FALSE:nonsupport the video display foramt*//**<CNcomment:\CA\D3Ƶ\C4\DC\C1\A6\BC\AF,HI_TRUE\B1\EDʾ֧\B3\D6\D5\E2\D6\D6\CF\D4ʾ\B8\F1ʽ\A3\ACHI_FALSE\B1\EDʾ\B2\BB֧\B3\D6 */
    HI_UNF_EDID_3D_INFO_S           st3DInfo;               /**<3d Info*//**<CNcomment:3d \C4\DC\C1\A6\BC\AF */
    HI_UNF_EDID_DEEP_COLOR_S        stDeepColor;            /**<YCBCR/RGB deep color Info*//**<CNcomment:YCBCR/RGB deep color \C4\DC\C1\A6\BC\AF*/
    HI_UNF_EDID_COLORIMETRY_S       stColorMetry;           /**<colorimetry Info*//**<CNcomment:ɫ\D3\F2\C4\DC\C1\A6\BC\AF */
    HI_UNF_EDID_COLOR_SPACE_S       stColorSpace;           /**<color space Info*//**<CNcomment:\D1\D5ɫ\BFռ\E4\C4\DC\C1\A6\BC\AF */
    HI_BOOL                         bYccQrangeSelectable;   /**<flag of YCC Quantization Range selectable.when HI_TRUE,sink expect full/limited range is selectable;or sink expect default range. *//**<CNcomment:SinkҪ\C7\F3RGB\C1\BF\BB\AF\B7\B6Χ\CAǷ\F1\C2\FA/\CF\DE\D6\C6 \B7\B6Χ\BF\C9ѡ\A1\A3HI_TRUE\B1\EDʾsinkҪ\C7\F3\B7\B6Χ\BF\C9ѡ\A3\ACHI_FALSE\B1\EDʾsinkҪ\C7\F3Ĭ\C8Ϸ\B6Χ\A1\A3*/
    HI_BOOL                         bRgbQrangeSelectable;   /**<flag of RGB Quantization Range selectable.when HI_TRUE,sink expect full/limited range is selectable;or sink expect default range. *//**<CNcomment:SinkҪ\C7\F3YCC\C1\BF\BB\AF\B7\B6Χ\CAǷ\F1\C2\FA/\CF\DE\D6\C6 \B7\B6Χ\BF\C9ѡ\A1\A3HI_TRUE\B1\EDʾsinkҪ\C7\F3\B7\B6Χ\BF\C9ѡ\A3\ACHI_FALSE\B1\EDʾsinkҪ\C7\F3Ĭ\C8Ϸ\B6Χ\A1\A3*/

    HI_UNF_EDID_AUDIO_INFO_S        stAudioInfo[HI_UNF_EDID_MAX_AUDIO_CAP_COUNT];   /**<audio Info*//**<CNcomment:\D2\F4Ƶ\C4\DC\C1\A6\BC\AF */
    HI_U32                          u32AudioInfoNum;                                /**<num of audio Info*//**<CNcomment:\D2\F4Ƶ \C4\DC\C1\A6\BC\AF\B8\F6\CA\FD */
    HI_BOOL                         bSupportAudioSpeaker[HI_UNF_EDID_AUDIO_SPEAKER_BUTT];/**<speaker Info*//**<CNcomment:speaker \C4\DC\C1\A6\BC\AF */

    HI_U8                           u8ExtBlockNum;          /**<edid extend block num Info*//**<CNcomment:edid\C0\A9չ\BF\E9\B8\F6\CA\FD */

    HI_U8                           u8Version;              /**<the version of manufacture*//**<CNcomment:\C9豸\B0汾\BA\C5 */
    HI_U8                           u8Revision;             /**<the revision of manufacture*//**<CNcomment:\C9豸\D7Ӱ汾\BA\C5 */
    HI_UNF_EDID_MANUFACTURE_INFO_S  stMfrsInfo;

    HI_UNF_EDID_CEC_ADDRESS_S       stCECAddr;              /**<cec address Info*//**<CNcomment:cec\B5\D8ַ\D0\C5Ϣ */
    HI_BOOL                         bSupportDVIDual;        /**<the DVI support dual-link or not *//**<CNcomment:\CAǷ\F1֧\B3\D6 DVI dual-link \B2\D9\D7\F7 */
    HI_BOOL                         bSupportsAI;            /**<support AI or not *//**<CNcomment:\CAǷ\F1֧\B3\D6 Supports_AI ģʽ */
    HI_UNF_EDID_TIMING_S            stPerferTiming;         /**<first detailed timing Info*//**<CNcomment:VESA\D7\EE\BC\D1\CF\EAϸ\D6\C6ʽ\D0\C5Ϣ */
    HI_U32                          u32MaxTMDSClock;        /**<Max TMDS clock in MHz*//**<CNcomment:֧\B3ֵ\C4\D7\EE\B4\F3TMDSʱ\D6\D3(MHz) */
    HI_BOOL                         bSupportY420Format[HI_UNF_ENC_FMT_BUTT];/**<video capability,HI_TRUE:support the video display format in YCBCR420;HI_FALSE:nonsupport the video display foramt  in YCBCR420*//**<CNcomment:\CA\D3Ƶ\C4\DC\C1\A6\BC\AF,HI_TRUE\B1\EDʾ֧\B3\D6\D5\E2\D6\D6\CF\D4ʾ\B8\F1ʽ\B5\C4YCBCR420ģʽ\A3\ACHI_FALSE\B1\EDʾ\B2\BB֧\B3\D6 */
    HI_UNF_EDID_DEEP_COLOR_Y420_S   stY420DeepColor;        /**<YCBCR deep color Info*//**<CNcomment:YCBCR420 deep color \C4\DC\C1\A6\BC\AF */

    HI_BOOL                         bDolbySupport;          /**<Dolby support flag.When VSVDB is indicated,flag HI_TRUE;or,HI_FALSE.*//**<CNcomment:\B6\C1\B5\BDVSVDB\A3\ACΪHI_TRUE;\B7\F1\D4\F2ΪHI_FALSE.*/
    HI_UNF_EDID_DOLBY_CAP_S         stDolby;                /**<Dolby capability*//**<CNcomment:Dolby\C4\DC\C1\A6\BC\AF */
    HI_BOOL                         bHdrSupport;            /**<HDR support flag.When HDR Static Metadata Data Block is indicated,flag HI_TRUE;or,HI_FALSE.*//**<CNcomment:\B6\C1\B5\BDHDR \BE\B2̬Ԫ\CA\FD\BEݿ\E9(HI_UNF_EDID_EOTF_S\D6\D0\C1е\C4\CB\C4\D6\D6֮һΪHI_TRUE)\A3\ACΪHI_TRUE;\B7\F1\D4\F2ΪHI_FALSE.*/
    HI_UNF_EDID_HDR_CAP_S           stHdr;                  /**<HDR capability*//**<CNcomment:HDR\C4\DC\C1\A6\BC\AF */
    HI_UNF_EDID_HDCP_S              stHDCPSupport;          /**<HDCP capability,HI_TRUE:support the HDCP version;HI_FALSE:nonsupport the HDCP version*//**<CNcomment:HDCP\C4\DC\C1\A6,HI_TRUE\B1\EDʾ֧\B3\D6\D5\E2\D6\D6HDCP\B0汾\A3\ACHI_FALSE\B1\EDʾ\B2\BB֧\B3\D6 */
    HI_UNF_EDID_BASE_DISP_PARA_S    stBaseDispPara;         /**<the parameters of display*//**<CNcomment: \CF\D4ʾ\C6\C1\B2\CE\CA\FD */
    HI_UNF_EDID_LATENCY_S           stLatency;              /**<Latency information*//**<CNcomment: Latency \D0\C5Ϣ */

} HI_UNF_EDID_BASE_INFO_S;

/**enum define about Video port*/
/**CNcomment:\B6\A8\D2\E5\CA\D3Ƶ\BDӿ\DA*/
typedef enum hiUNF_EDID_VIDEO_PORT_E
{
    HI_UNF_EDID_VIDEO_PORT_VGA   = 0x00,/**<VGA port *//**<CNcomment: VGA\BDӿ\DA */
    HI_UNF_EDID_VIDEO_PORT_DVI,         /**<DVI port *//**<CNcomment: DVI\BDӿ\DA */
    HI_UNF_EDID_VIDEO_PORT_HDMI,        /**<HDMI port *//**<CNcomment: HDMI \BDӿ\DA */
    HI_UNF_EDID_VIDEO_PORT_BUTT
} HI_UNF_EDID_VIDEO_PORT_E;

/**enum define about timing protocol type*/
/**CNcomment:\B6\A8\D2\E5ʱ\D0\F2\B5\C4Э\D2\E9\C0\E0\D0\CD*/
typedef enum hiUNF_EDID_TIMING_TYPE_E
{
    HI_UNF_EDID_TIMING_TYPE_DMT= 0x00,/**< DMT  protocol Timing *//**<CNcomment: DMTЭ\D2\E9ʱ\D0\F2 */
    HI_UNF_EDID_TIMING_TYPE_861,/**< 861D  protocol Timing *//**<CNcomment: 861DЭ\D2\E9ʱ\D0\F2 */
    HI_UNF_EDID_TIMING_TYPE_CVT,/**< CVT  protocol Timing *//**<CNcomment: CVTЭ\D2\E9ʱ\D0\F2 */
    HI_UNF_EDID_TIMING_TYPE_CVT_RB,/**< CVT_RB  protocol Timing *//**<CNcomment: CVT_RBЭ\D2\E9ʱ\D0\F2 */
    HI_UNF_EDID_TIMING_TYPE_GTF,/**< GTF  protocol Timing *//**<CNcomment: GTFЭ\D2\E9ʱ\D0\F2 */
    HI_UNF_EDID_TIMING_TYPE_BUTT
} HI_UNF_EDID_TIMING_TYPE_E;

/**enum define about timing type*/
/**CNcomment:\B6\A8\D2\E5ʱ\D0\F2\B5\C4\C0\E0\D0\CD*/
typedef enum hiUNF_EDID_TIMING_ATTR_E
{
    HI_UNF_EDID_TIMING_ATTR_NONE = 0x00,/**< None *//**<CNcomment: \CE\DE */
    HI_UNF_EDID_TIMING_ATTR_PREFERRED_TIMING,/**< None *//**<CNcomment: \D7\EE\BC\D1ʱ\D0\F2*/
    HI_UNF_EDID_TIMING_ATTR_PREFERRED_VERTICAL_FREQ,/**< None *//**<CNcomment: \D7\EE\BC\D1ˢ\D0\C2\C2\CA*/
    HI_UNF_EDID_TIMING_ATTR_BUTT
} HI_UNF_EDID_TIMING_ATTR_E;

/**Detailed Timing Definitions Sync Signal Definitions*/
/**CNcomment:\CF\EAϸʱ\D0\F2\D6ж\A8\D2\E5ͬ\B2\BD\C0\E0\D0\CD*/
typedef enum hiUNF_EDID_SYNC_TYPE_E
{
    /*Analog Sync Signal Definitions*/
    HI_UNF_EDID_SYNC_ACS_WS_GREEN    = 0x00,     /**<Analog Composite Sync - Without Serrations - Sync On Green Signal only*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BDȥ\B4\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C2\CCɫͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_ACS_WS_ALL,                 /**<Analog Composite Sync - Without Serrations - Sync On all three (RGB) video signals*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BDȥ\B4\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C8\FD\B8\F6ͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_ACS_DS_GREEN,               /**<Analog Composite Sync - With Serrations (H-sync during V-sync); - Sync On Green Signal only*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BD\B1\A3\B3ִ\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C2\CCɫͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_ACS_DS_ALL,                 /**<Analog Composite Sync - With Serrations (H-sync during V-sync); - Sync On all three (RGB) video signals*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BD\B1\A3\B3ִ\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C8\FD\B8\F6ͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_BACS_WS_GREEN,              /**<Bipolar Analog Composite Sync - Without Serrations; - Sync On Green Signal only*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BDȥ\B4\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C8\FD\B8\F6ͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_BACS_WS_ALL,                /**<Bipolar Analog Composite Sync - Without Serrations; - Sync On all three (RGB) video signals*//**<CNcomment: ģ\C4⸴\BA\CFͬ\B2\BDȥ\B4\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C8\FD\B8\F6ͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_BACS_DS_GREEN,              /**<Bipolar Analog Composite Sync - With Serrations (H-sync during V-sync); - Sync On Green Signal only*//**<CNcomment:  \BC\AB\D0\D4ģ\C4⸴\BA\CFͬ\B2\BD\B1\A3\B3ִ\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C2\CCɫͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    HI_UNF_EDID_SYNC_BACS_DS_ALL,                /**<Bipolar Analog Composite Sync - With Serrations (H-sync during V-sync); - Sync On all three (RGB) video signals*//**<CNcomment:  \BC\AB\D0\D4ģ\C4⸴\BA\CFͬ\B2\BD\B1\A3\B3ִ\B9ֱͬ\B2\BDʱ\C6ڵ\C4ˮƽ\BE\E2\B3ݣ\AC\C2\CCɫͨ\B5\C0\B5\FE\BC\D3ͬ\B2\BD*/
    /*Digital Sync Signal Definitions*/
    HI_UNF_EDID_SYNC_DCS_WS,                     /**<Digital Composite Sync - Without Serrations*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\ACȥ\B4\B9ֱͬ\B2\BD\C6ڼ\E4\D0\D0ͬ\B2\BD\BE\E2\B3\DD\D0ź\C5*/
    HI_UNF_EDID_SYNC_DCS_DS,                     /**<Digital Composite Sync - With Serrations (H-sync during V-sync)*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\AC\B1\A3\B3ִ\B9ֱͬ\B2\BD\C6ڼ\E4\D0\D0ͬ\B2\BD\BE\E2\B3\DD\D0ź\C5*/
    HI_UNF_EDID_SYNC_DSS_VN_HN,                  /**<Digital Separate Sync Vsync(-) Hsync(-)*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\ACˮƽ\BAʹ\B9ֱͬ\B2\BD\BC\AB\D0\D4(-)(-)*/
    HI_UNF_EDID_SYNC_DSS_VN_HP,                  /**<Digital Separate Sync Vsync(-) Hsync(+)*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\ACˮƽ\BAʹ\B9ֱͬ\B2\BD\BC\AB\D0\D4(-)(+)*/
    HI_UNF_EDID_SYNC_DSS_VP_HN,                  /**<Digital Separate Sync Vsync(+) Hsync(-)*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\ACˮƽ\BAʹ\B9ֱͬ\B2\BD\BC\AB\D0\D4(+)(-)*/
    HI_UNF_EDID_SYNC_DSS_VP_HP,                  /**<Digital Separate Sync Vsync(+) Hsync(+)*//**<CNcomment: \CA\FD\D7ָ\B4\BA\CFͬ\B2\BD\A3\ACˮƽ\BAʹ\B9ֱͬ\B2\BD\BC\AB\D0\D4(+)(+)*/
    HI_UNF_EDID_SYNC_BUTT
} HI_UNF_EDID_SYNC_TYPE_E;


/**Simple Timing Definitions*/
/**CNcomment:\B6\A8\D2\E5\BC\F2Ҫʱ\D0\F2*/
typedef struct hiUNF_EDID_SIMPLE_TIMING_S
{
    HI_U32              u32Vact;    /**<  Active Line *//**<CNcomment: \D3\D0Ч\D0\D0*/
    HI_U32              u32Hact;/**< Active Pixels *//**<CNcomment: \D3\D0Ч\CF\F1\CB\D8*/
    HI_U32              u32VerFreq;/**<Ver Frequency *//**<CNcomment: ˢ\D0\C2\C2\CA */
    HI_UNF_EDID_TIMING_TYPE_E          enTimingType;/**< Timing protocol type *//**<CNcomment: \B6\A8\D2\E5ʱ\D0\F2\B5\C4Э\D2\E9\C0\E0\D0\CD*/
    HI_UNF_EDID_TIMING_ATTR_E          enTimingAttr;/**<timing type *//**<CNcomment: :\B6\A8\D2\E5ʱ\D0\F2\B5\C4\C0\E0\D0\CD*/
} HI_UNF_EDID_SIMPLE_TIMING_S;

/**Detailed Timing Definitions*/
/**CNcomment:\B6\A8\D2\E5\CF\EAϸʱ\D0\F2*/
typedef struct hiUNF_EDID_DETAIL_TIMING_S
{
    HI_UNF_EDID_TIMING_S                stTiming; /**<  Detailed Timing *//**<CNcomment: \CF\EAϸʱ\D0\F2*/
    HI_UNF_EDID_SYNC_TYPE_E             enSyncType;/**Detailed Timing Definitions Sync Signal Definitions*//**CNcomment:\CF\EAϸʱ\D0\F2\D6ж\A8\D2\E5ͬ\B2\BD\C0\E0\D0\CD*/
    HI_UNF_EDID_TIMING_ATTR_E           enTimingAttr;/**<timing type *//**<CNcomment: :\B6\A8\D2\E5ʱ\D0\F2\B5\C4\C0\E0\D0\CD*/
} HI_UNF_EDID_DETAIL_TIMING_S;

/**EDID information*/
/**CNcomment:EDID\BD\E2\CE\F6\D0\C5Ϣ*/
typedef struct hiUNF_EDID_INFO_S
{
    HI_UNF_EDID_BASE_INFO_S         stEDIDBaseInfo;/**< EDID base information *//**<CNcomment: EDID\BB\F9\B1\BE\D0\C5Ϣ */
    HI_UNF_EDID_VIDEO_PORT_E        enVideoPort;                  /**<video port  *//**<CNcomment: \CA\D3Ƶ\BDӿ\DA\C0\E0\D0\CD */
    HI_UNF_EDID_SIMPLE_TIMING_S*    pstSimpleTiming;    /**<Simple timing   *//**<CNcomment: \BC\F2Ҫʱ\D0\F2*/
    HI_U32                          u32SimpleTimingNum;/**<Simple timing number *//**<CNcomment: \BC\F2Ҫʱ\D0\F2\B8\F6\CA\FD*/
    HI_UNF_EDID_DETAIL_TIMING_S*    pstDetailTiming;    /**<Simple timing *//**<CNcomment: \CF\EAϸʱ\D0\F2\B8\F6\CA\FD*/
    HI_U32                          u32DetailTimingNum;/**<Simple timing number *//**<CNcomment: \CF\EAϸʱ\D0\F2\B8\F6\CA\FD*/
} HI_UNF_EDID_INFO_S;



/** @}*/  /** <!-- ==== Structure Definition End ====*/




/******************************* API Declaration *****************************/
/** \addtogroup      EDID*/
/** @{*/  /** <!-- [EDID] */


/**
\brief parse the edid information. CNcomment:\BD\E2\CE\F6EDID\CA\FD\BE\DD CNend
\attention \n
\param[in]  u32EdidLength EDID data length . CNcomment:EDID\CA\FD\BE\DD \B5Ľṹ \B3\A4\B6\C8 CNend
\param[in]  *pu8Edid  EDID data point . CNcomment:EDID\CA\FD\BE\DD \B5\C4ָ\D5\EBCNend
\param[in]  *pstEdidInfo  EDID parse information . CNcomment:EDID\BD\E2\CE\F6\D0\C5Ϣָ\D5\EBCNend

\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_EDID_EdidParse(HI_U8* pu8Edid, HI_U32 u32EdidLength, HI_UNF_EDID_INFO_S* pstEdidInfo);

/**
\brief release the edid information. CNcomment:\CAͷ\C5EDID\D0\C5Ϣ CNend
\attention \n
\param[in]  *pstEdidInfo  EDID parse information . CNcomment:EDID\BD\E2\CE\F6\D0\C5Ϣָ\D5\EBCNend
\retval HI_SUCCESS   success.   CNcomment:\B3ɹ\A6 CNend
\retval please refer to the err code definitino of mpi.CNcomment:\C7\EB\B2ο\BCMPI\B4\ED\CE\F3\C2\EB CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_VOID HI_UNF_EDID_EdidRelease(HI_UNF_EDID_INFO_S * pstEdidInfo);


/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_EDID_H__ */

