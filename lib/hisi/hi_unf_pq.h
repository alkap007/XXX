/******************************************************************************

  Copyright (C), 2012-2014, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_unf_pq.h
  Version       : Initial Draft
  Author        : sdk
  Created       : 2014/4/23
  Description   :

******************************************************************************/

#ifndef __HI_UNF_PQ_H__
#define __HI_UNF_PQ_H__

#include "hi_type.h"
#include "hi_unf_disp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
/******************************************************************************/


/********************************Struct Definition********************************/
/** \addtogroup      PQ */
/** @{ */  /** <!-- [PQ] */

/**<Image Mode Set Different Parameters Under Different Mode*/
/**<CNcomment:ͼ\CF\F1ģʽѡ\D4\F1\A3\BB\D4ڲ\BBͬ\B5\C4ģʽ\CF\C2\C5\E4\D6ò\BBͬ\B5Ĳ\CE\CA\FD CNend*/
typedef enum hiUNF_PQ_IMAGE_MODE_E
{
    HI_UNF_OPTION_MODE_NATURAL    = 0,  /**<Natural mode*/ /**<CNcomment:\D7\D4Ȼģʽ CNend*/
    HI_UNF_OPTION_MODE_PERSON     = 1,  /**<Person mode*/ /**<CNcomment:\C8\CB\CE\EFģʽ CNend*/
    HI_UNF_OPTION_MODE_FILM       = 2,  /**<Film mode*/ /**<CNcomment:\B5\E7Ӱģʽ CNend*/
    HI_UNF_OPTION_MODE_UD         = 3,  /**<User Defined mode*/ /**<CNcomment:\D3û\A7\D7Զ\A8\D2\E5ģʽ CNend*/
    HI_UNF_OPTION_MODE_NORMAL     = 4,  /**<Normal mode*/ /**<CNcomment:\D5\FD\B3\A3ģʽ CNend*/
    HI_UNF_OPTION_MODE_VIDEOPHONE = 5,  /**<Video Phone mode*/ /**<CNcomment:\BF\C9\CAӵ绰ģʽ CNend*/
    HI_UNF_OPTION_MODE_GALLERY    = 6,  /**<Gallery mode*/ /**<CNcomment:ͼ\BF\E2ģʽ CNend*/

    HI_UNF_OPTION_MODE_BUTT,
} HI_UNF_PQ_IMAGE_MODE_E;

typedef enum hiUNF_PQ_HDR_MODE_E
{
    HI_UNF_PQ_HDR_PROCESS_SCENE_HDR10_TO_SDR   = 0,
    HI_UNF_PQ_HDR_PROCESS_SCENE_HDR10_TO_HDR10 = 1,
    HI_UNF_PQ_HDR_PROCESS_SCENE_HDR10_TO_HLG   = 2,
    HI_UNF_PQ_HDR_PROCESS_SCENE_HLG_TO_SDR     = 3,
    HI_UNF_PQ_HDR_PROCESS_SCENE_HLG_TO_HDR10   = 4,
    HI_UNF_PQ_HDR_PROCESS_SCENE_HLG_TO_HLG     = 5,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SLF_TO_SDR     = 6,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SLF_TO_HDR10   = 7,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SLF_TO_HLG     = 8,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SDR_TO_SDR     = 9,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SDR_TO_HDR10   = 10,
    HI_UNF_PQ_HDR_PROCESS_SCENE_SDR_TO_HLG     = 11,

    HI_UNF_PQ_HDR_PROCESS_SCENE_BUTT,
} HI_UNF_PQ_HDR_PROCESS_SCENE_E;

/******************************************************************************/
typedef struct hiUNF_PQ_SETHDROFFSET_S
{
    HI_UNF_PQ_HDR_PROCESS_SCENE_E enHdrProcessScene;
    HI_U32       u32HdrMode;
    HI_U32       u32Bright;
    HI_U32       u32Contrast;
    HI_U32       u32Satu;
    HI_U32       u32Hue;
    HI_U32       u32R;
    HI_U32       u32G;
    HI_U32       u32B;
    HI_U32       u32darkCv;
    HI_U32       u32brightCv;
    HI_U32       u32ACCdark;
    HI_U32       u32ACCbrigt;
} HI_UNF_PQ_SETHDROFFSET_S;
/******************************************************************************/

/**<Demo Mode*/
/**<CNcomment:\C2\F4\B3\A1ģʽ CNend*/
typedef enum hiUNF_PQ_DEMO_E
{
    HI_UNF_PQ_DEMO_SHARPNESS = 0,   /**<Sharpen */ /**<CNcomment:\C8\F1\BB\AF CNend*/
    HI_UNF_PQ_DEMO_DCI,             /**<Dynamic Contrast Improvement */ /**<CNcomment:\D7Զ\AF\B6Աȶȵ\F7\BD\DA CNend*/
    HI_UNF_PQ_DEMO_COLOR,           /**<Automatic Color Management */ /**<CNcomment:\D6\C7\C4\DC\D1\D5ɫ\B5\F7\BD\DA CNend*/
    HI_UNF_PQ_DEMO_SR,              /**<Super Resolution */ /**<CNcomment:\B3\AC\BC\B6\B7ֱ\E6\C2\CA CNend*/
    HI_UNF_PQ_DEMO_TNR,             /**<Time Noise Reduction */ /**<CNcomment:ʱ\D3\F2\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_DEMO_DEI,             /**<De interlace */ /**<CNcomment:ȥ\B8\F4\D0\D0 CNend*/
    HI_UNF_PQ_DEMO_DBM,             /**<Digital Noise Reduction; include DB DM DR DS*/ /**<CNcomment:\CA\FD\D7\D6\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_DEMO_SNR,             /**<Space Noise Reduction */ /**<CNcomment:\BF\D5\D3\F2\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_DEMO_ALL,             /**<All Algorithm */ /**<CNcomment:ȫ\B2\BF\CB㷨 CNend*/

    HI_UNF_PQ_DEMO_BUTT
} HI_UNF_PQ_DEMO_E;

/**<Demo Display Mode*/
/**<CNcomment:\C2\F4\B3\A1\CF\D4ʾģʽ CNend*/
typedef enum hiUNF_PQ_DEMO_MODE_E
{
    HI_UNF_PQ_DEMO_MODE_FIXED_R,    /**<Fixed Enable Right */ /**<CNcomment:\B9̶\A8\D3Ҳ\E0ʹ\C4\DC CNend*/
    HI_UNF_PQ_DEMO_MODE_FIXED_L,    /**<Fixed Enable Left */ /**<CNcomment:\B9̶\A8\D7\F3\B2\E0ʹ\C4\DC CNend*/
    HI_UNF_PQ_DEMO_MODE_SCROLL_R,   /**<Enable Right; and Roll from Left to right */ /**<CNcomment:\D3Ҳ\E0ʹ\C4ܣ\BB\B4\D3\D7\F3\CF\F2\D3\D2\D2ƶ\AF CNend*/
    HI_UNF_PQ_DEMO_MODE_SCROLL_L,   /**<Enable Left; and Roll from Left to right */ /**<CNcomment:\D7\F3\B2\E0ʹ\C4ܣ\BB\B4\D3\D7\F3\CF\F2\D3\D2\D2ƶ\AF CNend*/

    HI_UNF_PQ_DEMO_MODE_BUTT
} HI_UNF_PQ_DEMO_MODE_E;

/**<Algorithm Moudle*/
/**<CNcomment:\CB㷨ģ\BF\E9 CNend*/
typedef enum hiUNF_PQ_MODULE_E
{
    HI_UNF_PQ_MODULE_SHARPNESS = 0, /**<Sharpen */ /**<CNcomment:\C8\F1\BB\AF CNend*/
    HI_UNF_PQ_MODULE_DCI,           /**<Dynamic Contrast Improvement */ /**<CNcomment:\D7Զ\AF\B6Աȶȵ\F7\BD\DA CNend*/
    HI_UNF_PQ_MODULE_COLOR,         /**<Automatic Color Management */ /**<CNcomment:\D6\C7\C4\DC\D1\D5ɫ\B5\F7\BD\DA CNend*/
    HI_UNF_PQ_MODULE_SR,            /**<Super Resolution */ /**<CNcomment:\B3\AC\BC\B6\B7ֱ\E6\C2\CA CNend*/
    HI_UNF_PQ_MODULE_TNR,           /**<Time Noise Reduction */ /**<CNcomment:ʱ\D3\F2\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_MODULE_DBM,           /**<Digital Noise Reduction; include DB DM DR DS*/ /**<CNcomment:\CA\FD\D7\D6\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_MODULE_SNR,           /**<Space Noise Reduction */ /**<CNcomment:\BF\D5\D3\F2\D4\EB\C9\F9\CF\FB\B3\FD CNend*/
    HI_UNF_PQ_MODULE_MCDI,          /**<Motion Compensation DeInterlace */ /**<CNcomment:\BB\F9\D3\DA\D4˶\AF\B2\B9\B3\A5\B5\C4ȥ\B8\F4\D0\D0\CB㷨 CNend*/

    HI_UNF_PQ_MODULE_ALL,           /**<All Algorithm */ /**<CNcomment:ȫ\B2\BF\CB㷨 CNend*/

    HI_UNF_PQ_MODULE_BUTT
} HI_UNF_PQ_MODULE_E;

/**<Spuer Resolution Demo Mode*/
/**<CNcomment:SR\D1\DDʾģʽ CNend*/
typedef enum hiUNF_PQ_SR_DEMO_E
{
    HI_UNF_PQ_SR_DISABLE  = 0, /**<Close SR */ /**<CNcomment:\B9\D8SR,ֻ\BF\AA\CB\F5\B7\C5 CNend*/
    HI_UNF_PQ_SR_ENABLE_R,     /**<SR open at right hand side */ /**<CNcomment:\D3ұ\DFSR CNend*/
    HI_UNF_PQ_SR_ENABLE_L,     /**<SR open at left hand side */ /**<CNcomment:\D7\F3\B1\DFSR CNend*/
    HI_UNF_PQ_SR_ENABLE_A,     /**<SR open all screen */ /**<CNcomment:ȫ\C6\C1SR CNend*/

    HI_UNF_PQ_SR_DEMO_BUTT
} HI_UNF_PQ_SR_DEMO_E;

/**<Custom Colors Parameter*/
/**<CNcomment:\D7Զ\A8\D2\E5\D1\D5ɫ\B2\CE\CA\FD CNend*/
typedef struct  hiUNF_PQ_SIX_BASE_S
{
    HI_U32  u32Red;       /**<Red; Range:0~100 */ /**<CNcomment:\BA\ECɫ\A3\BB\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Green;     /**<Green; Range:0~100 */ /**<CNcomment:\BA\ECɫ\A3\BB\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Blue;      /**<Blue; Range:0~100 */ /**<CNcomment:\BA\ECɫ\A3\BB\B7\B6Χ:0~100 CNend*/

    HI_U32  u32Cyan;      /**<Cyan; Range:0~100 */ /**<CNcomment:\C7\E0ɫ\A3\BB\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Magenta;   /**<Magenta; Range:0~100 */ /**<CNcomment:Ʒ\BA죻\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Yellow;    /**<Yellow; Range:0~100 */ /**<CNcomment:\BB\C6ɫ\A3\BB\B7\B6Χ:0~100 CNend*/
} HI_UNF_PQ_SIX_BASE_S;

/**<Custom Color Temperature Parameter*/
/**<CNcomment:\D7Զ\A8\D2\E5ɫ\CE²\CE\CA\FD CNend*/
typedef struct  hiUNF_PQ_COLORTEMPERATURE_S
{
    HI_U32  u32Red;       /**<Red; Range:0~100 */ /**<CNcomment:\BA\ECɫ\A3\BB\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Green;     /**<Green; Range:0~100 */ /**<CNcomment:\C2\CCɫ\A3\BB\B7\B6Χ:0~100 CNend*/
    HI_U32  u32Blue;      /**<Blue; Range:0~100 */ /**<CNcomment:\C0\B6ɫ\A3\BB\B7\B6Χ:0~100 CNend*/
} HI_UNF_PQ_COLORTEMPERATURE_S;

/**<Portrait Colors Parameter*/
/**<CNcomment:\C8\CB\CF\F1ģʽ\B2\CE\CA\FD CNend*/
typedef enum hiUNF_PQ_FLESHTONE_E
{
    HI_UNF_PQ_FLESHTONE_GAIN_OFF  = 0,   /**<Portrait Model Strength Off */ /**<CNcomment:\C8\CB\CF\F1ģʽ\B9ر\D5 CNend*/
    HI_UNF_PQ_FLESHTONE_GAIN_LOW  = 1,   /**<Portrait Model Strength Low */ /**<CNcomment:\C8\CB\CF\F1ģʽǿ\B6ȵ\CD CNend*/
    HI_UNF_PQ_FLESHTONE_GAIN_MID  = 2,   /**<Portrait Model Strength Middle */ /**<CNcomment:\C8\CB\CF\F1ģʽǿ\B6\C8\D6\D0 CNend*/
    HI_UNF_PQ_FLESHTONE_GAIN_HIGH = 3,   /**<Portrait Model Strength High */ /**<CNcomment:\C8\CB\CF\F1ģʽǿ\B6ȸ\DF CNend*/

    HI_UNF_PQ_FLESHTONE_GAIN_BUTT
}  HI_UNF_PQ_FLESHTONE_E;

/**<Color Optimization Model*/
/**<CNcomment:\D1\D5ɫ\D4\F6ǿ\C0\E0\D0\CD CNend*/
typedef enum hiUNF_PQ_COLOR_SPEC_MODE_E
{
    HI_UNF_PQ_COLOR_MODE_RECOMMEND  = 0, /**<Optimization Model */ /**<CNcomment:\D7\EE\D3\C5ģʽ CNend*/
    HI_UNF_PQ_COLOR_MODE_BLUE       = 1, /**<Blue Model */ /**<CNcomment:\C0\B6ɫ\D4\F6ǿģʽ CNend*/
    HI_UNF_PQ_COLOR_MODE_GREEN      = 2, /**<Green Model */ /**<CNcomment:\C2\CCɫ\D4\F6ǿģʽ CNend*/
    HI_UNF_PQ_COLOR_MODE_BG         = 3, /**<Cyan Model */ /**<CNcomment:\C0\B6\C2\CC\D4\F6ǿģʽ CNend*/
    HI_UNF_PQ_COLOR_MODE_ORIGINAL   = 4, /**<Original Model */ /**<CNcomment:ԭʼ\D1\D5ɫģʽ CNend*/

    HI_UNF_PQ_COLOR_MODE_BUTT
} HI_UNF_PQ_COLOR_SPEC_MODE_E;

/**<Intelligent Colors Form*/
/**<CNcomment:\D6\C7\C4\DC\D1\D5ɫ\C0\E0\D0\CD CNend*/
typedef enum hiUNF_PQ_COLOR_ENHANCE_E
{
    HI_UNF_PQ_COLOR_ENHANCE_FLESHTONE       = 0,  /**<Portrait Model */ /**<CNcomment:\C8\CB\CF\F1ģʽ CNend*/
    HI_UNF_PQ_COLOR_ENHANCE_SIX_BASE        = 1,  /**<Custom Model */ /**<CNcomment:\D7Զ\A8\D2\E5\D1\D5ɫ CNend*/
    HI_UNF_PQ_COLOR_ENHANCE_SPEC_COLOR_MODE = 2,  /**<Special Color Model */ /**<CNcomment:\D1\D5ɫ\D4\F6ǿģʽ CNend*/

    HI_UNF_PQ_COLOR_ENHANCE_BUTT
} HI_UNF_PQ_COLOR_ENHANCE_E;

/**<Intelligent Colors Parameter*/
/**<CNcomment:\D6\C7\C4\DC\D1\D5ɫ\B2\CE\CA\FD CNend*/
typedef struct  hiUNF_PQ_COLOR_ENHANCE_S
{
    HI_UNF_PQ_COLOR_ENHANCE_E  enColorEnhanceType;  /**<Color Model */ /**<CNcomment\D4\F6ǿ\C0\E0\D0\CD CNend*/
    union
    {
        HI_UNF_PQ_FLESHTONE_E        enFleshtone;   /**<Portrait Model Parameter */ /**<CNcomment\C8\CB\CF\F1ģʽ\B2\CE\CA\FD CNend*/
        HI_UNF_PQ_SIX_BASE_S         stSixBase;     /**<Custom Model Parameter */ /**<CNcomment\D7Զ\A8\D2\E5\D1\D5ɫ\B2\CE\CA\FD CNend*/
        HI_UNF_PQ_COLOR_SPEC_MODE_E  enColorMode;   /**<Special Color Model Parameter */ /**<CNcomment\D1\D5ɫ\D4\F6ǿ\B2\CE\CA\FD CNend*/
    } unColorGain;
} HI_UNF_PQ_COLOR_ENHANCE_S;

typedef enum hiUNF_PQ_IMAGE_TYPE_E
{
    HI_UNF_PQ_IMAGE_GRAPH = 0,          /**<graph image */ /**<CNcomment: ͼ\D0\CEͼ\CF\F1 CNend*/
    HI_UNF_PQ_IMAGE_VIDEO,              /**<video image */ /**<CNcomment: \CA\D3Ƶͼ\CF\F1 CNend*/

    HI_UNF_PQ_IMAGE_BUTT
} HI_UNF_PQ_IMAGE_TYPE_E;

typedef struct hiUNF_PQ_IMAGE_PARAM_S
{
    HI_U32       u32Brightness;         /**<Brightness; Range:0~100; recommended: 50 */ /**<CNcomment:\C1\C1\B6ȣ\BB\B7\B6Χ: 0~100\A3\BB\CDƼ\F6ֵ: 50 CNend*/
    HI_U32       u32Contrast;           /**<Contrast; Range:0~100; recommended: 50 */ /**<CNcomment:\B6Աȶȣ\BB\B7\B6Χ: 0~100\A3\BB\CDƼ\F6ֵ: 50 CNend*/
    HI_U32       u32Hue;                /**<HuePlus; Range:0~100; recommended: 50 */ /**<CNcomment:ɫ\B5\F7\A3\BB\B7\B6Χ: 0~100\A3\BB\CDƼ\F6ֵ: 50 CNend*/
    HI_U32       u32Saturation;         /**<Saturation; Range:0~100; recommended: 50 */ /**<CNcomment:\B1\A5\BAͶȣ\BB\B7\B6Χ: 0~100\A3\BB\CDƼ\F6ֵ: 50 CNend*/
} HI_UNF_PQ_IMAGE_PARAM_S;

/******************************* API Declaration *****************************/
/** \addtogroup      PQ */
/** @{ */  /** <!-- [PQ] */

/******************************************************************************/
/**
 \brief Set PQ mode . CNcomment: \C9\E8\D6\C3ͼ\CF\F1ģʽ CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] enImageMode Destination DISP channel PQ mode CNcomment: Ŀ\B1\EAͨ\B5\C0ͼ\CF\F1ģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_PQ_SetImageMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_IMAGE_MODE_E enImageMode);


/**
 \brief Get PQ mode . CNcomment: \BB\F1ȡͼ\CF\F1ģʽ CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] penImageMode  pointer of image mode CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ͼ\CF\F1ģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_PQ_GetImageMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_IMAGE_MODE_E *penImageMode);

/**
 \brief Set the default PQ configuration for video parameter test.  CNcomment: Ϊ\C8\EB\CD\F8ָ\B1\EA\B2\E2\CA\D4\C9\E8\D6\C3PQ \B5\C4Ĭ\C8\CFֵCNend
 \attention \n
 \param[in] N/A CNcomment: \CE\DE CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \see \n
 N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_PQ_SetDefaultParam(HI_VOID);


/**
 \brief Initializes the picture quality unit (PQU). CNcomment: \B3\F5ʼ\BB\AFPQ CNend
 \attention \n
Before calling the PQU, you must call this application programming interface (API).
CNcomment: \B5\F7\D3\C3PQģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
 \param[in] N/A CNcomment: \CE\DE CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_PQ_DEV_NOT_EXIST No PQ device exists. CNcomment: \C9豸\B2\BB\B4\E6\D4\DA CNend
 \retval ::HI_ERR_PQ_NOT_DEV_FILE The file is not a PQ file. CNcomment: \CEļ\FE\B7\C7\C9豸 CNend
 \retval ::HI_ERR_PQ_DEV_OPENED The PQ device fails to be started. CNcomment: \B4\F2\BF\AA\C9豸ʧ\B0\DC CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_PQ_Init(HI_VOID);


/**
 \brief Deinitializes the PQU. CNcomment: ȥ\B3\F5ʼ\BB\AFPQ CNend
 \attention \n
 \param[in] N/A CNcomment: \CE\DE CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_PQ_DeInit(HI_VOID);


/**
 \brief Get Brightness. CNcomment:\BB\F1ȡ\C1\C1\B6\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] pu32Brightness   CNcomment: \C1\C1\B6\C8ֵ\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetBrightness(HI_UNF_DISP_E enChan, HI_U32 *pu32Brightness);


/**
 \brief Set Brightness. CNcomment:\C9\E8\D6\C3\C1\C1\B6\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] u32Brightness; Range:0~100 CNcomment: \C1\C1\B6\C8ֵ\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetBrightness(HI_UNF_DISP_E enChan, HI_U32 u32Brightness);


/**
 \brief Get Contrast. CNcomment:\BB\F1ȡ\B6Աȶ\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel  CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] pu32Contrast; Range:0~100  CNcomment: \B6Աȶȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetContrast(HI_UNF_DISP_E enChan, HI_U32 *pu32Contrast);


/**
 \brief Set Contrast. CNcomment:\C9\E8\D6öԱȶ\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] u32Contrast; Range:0~100  CNcomment: \B6Աȶȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetContrast(HI_UNF_DISP_E enChan, HI_U32 u32Contrast);


/**
 \brief Get Saturation. CNcomment:\BB\F1ȡ\B1\A5\BAͶ\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] pu32Saturation; Range:0~100  CNcomment: \B1\A5\BAͶȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetSaturation(HI_UNF_DISP_E enChan, HI_U32 *pu32Saturation);


/**
 \brief Set Saturation. CNcomment:\C9\E8\D6ñ\A5\BAͶ\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] u32Saturation; Range:0~100  CNcomment: \B1\A5\BAͶȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetSaturation(HI_UNF_DISP_E enChan, HI_U32 u32Saturation);


/**
 \brief Get Hue. CNcomment:\BB\F1ȡɫ\B5\F7 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] pu32Hue; Range:0~100  CNcomment: ɫ\B5\F7\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetHue(HI_UNF_DISP_E enChan, HI_U32 *pu32Hue);


/**
 \brief Set Hue. CNcomment:\C9\E8\D6\C3ɫ\B5\F7 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] u32Hue; Range:0~100  CNcomment: ɫ\B5\F7\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetHue(HI_UNF_DISP_E enChan, HI_U32 u32Hue);

/**
\brief  set color temperature. CNcomment:\C9\E8\D6\C3ɫ\CE\C2 CNend
\attention \n
none.CNcomment:\CE\DE CNend
\param[in] enDisp              DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
\param[in] colortemp           temperature value. the range is 0~100, 0 means the min value. \n
CNcomment:\CF\D4ʾ\CA\E4\B3\F6ɫ\CE\C2\D4\F6\D2\E6ֵ\A1\A3\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\B1\EDʾ\D7\EEСɫ\CE\C2\D4\F6\D2棻100\A3\BA\B1\EDʾ\D7\EE\B4\F3ɫ\CE\C2\D4\F6\D2\E6 CNend
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_PQ_SetColorTemperature(HI_UNF_DISP_E enChan, HI_UNF_PQ_COLORTEMPERATURE_S stColorTemperature);


/**
\brief  set color temperature. CNcomment:\C9\E8\D6\C3ɫ\CE\C2 CNend
\attention \n
none.CNcomment:\CE\DE CNend
\param[in] enDisp              DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
\param[in] colortemp           temperature value. the range is 0~100, 0 means the min value. \n
CNcomment:\CF\D4ʾ\CA\E4\B3\F6ɫ\CE\C2\D4\F6\D2\E6ֵ\A1\A3\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\B1\EDʾ\D7\EEСɫ\CE\C2\D4\F6\D2棻100\A3\BA\B1\EDʾ\D7\EE\B4\F3ɫ\CE\C2\D4\F6\D2\E6 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_PQ_GetColorTemperature(HI_UNF_DISP_E enChan, HI_UNF_PQ_COLORTEMPERATURE_S *pstColorTemperature);

/**
 \brief Set Basic image para. CNcomment:\C9\E8\D6\C3ͼ\CF\F1\BB\F9\B1\BE\B2\CE\CA\FD. CNend
 \attention \n
 \param[in] enType: Graph or Video  CNcomment: \C9\E8\D6õ\C4\CA\C7ͼ\D0λ\B9\CA\C7\CA\D3Ƶ CNend
 \param[in] enChan: Destination DISP channel  CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] stParam:Basic Image Param CNcomment:ͼ\CF\F1\BB\F9\B1\BE\B2\CE\CA\FDCNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetBasicImageParam(HI_UNF_PQ_IMAGE_TYPE_E enType, HI_UNF_DISP_E enChan, HI_UNF_PQ_IMAGE_PARAM_S stParam);


/**
 \brief Get Basic image para. CNcomment:\BB\F1ȡͼ\CF\F1\BB\F9\B1\BE\B2\CE\CA\FD CNend
 \attention \n
 \param[in] enType: Graph or Video  CNcomment: ѡ\D4\F1\B5\C4\CA\C7ͼ\D0λ\B9\CA\C7\CA\D3Ƶ CNend
 \param[in] enChan: Destination DISP channel  CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] pstParam:Basic Image Param CNcomment:ͼ\CF\F1\BB\F9\B1\BE\B2\CE\CA\FD CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetBasicImageParam(HI_UNF_PQ_IMAGE_TYPE_E enType, HI_UNF_DISP_E enChan, HI_UNF_PQ_IMAGE_PARAM_S *pstParam);


/**
 \brief Get SR Demo Mode. CNcomment:\BB\F1ȡSR\D1\DDʾ\C0\E0\D0\CD CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] *penType, SR Demo Mode  CNcomment:ָ\D5룬SR \CF\D4ʾģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetSRMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_SR_DEMO_E *penType);


/**
 \brief  Set SR Demo Mode. CNcomment:\C9\E8\D6\C3SR\D1\DDʾ\C0\E0\D0\CD CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] enType, SR Demo Mode  CNcomment:SR \CF\D4ʾģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetSRMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_SR_DEMO_E enType);


/**
 \brief Get Sharpness. CNcomment:\BB\F1ȡ\C7\E5\CE\FA\B6\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[out] pu32Sharpness; Range:0~100  CNcomment: \C7\E5\CE\FA\B6ȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetSharpness(HI_UNF_DISP_E enChan, HI_U32 *pu32Sharpness);


/**
 \brief Set Sharpness. CNcomment:\C9\E8\D6\C3\C7\E5\CE\FA\B6\C8 CNend
 \attention \n
 \param[in] enChan Destination DISP channel CNcomment: Ŀ\B1\EAͨ\B5\C0\BA\C5 CNend
 \param[in] u32Sharpness; Range:0~100  CNcomment: \C7\E5\CE\FA\B6ȣ\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS  Success CNcomment: \B3ɹ\A6 CNend
 */
HI_S32 HI_UNF_PQ_SetSharpness(HI_UNF_DISP_E enChan, HI_U32 u32Sharpness);

/**
 \brief Get Color Enhance Type and Para. CNcomment:\BB\F1ȡ\D1\D5ɫ\D4\F6ǿ\B5\C4\C0\E0\D0ͺͲ\CE\CA\FD CNend
 \attention \n
 \param[out] pstColorEnhanceParam  CNcomment:\D1\D5ɫ\D4\F6ǿ\B5\C4\C0\E0\D0ͺͲ\CE\CA\FD CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetColorEnhanceParam(HI_UNF_PQ_COLOR_ENHANCE_S *pstColorEnhanceParam);


/**
 \brief Set Color Enhance Type and Para. CNcomment:\C9\E8\D6\C3\D1\D5ɫ\D4\F6ǿ\B5\C4\C0\E0\D0ͺͲ\CE\CA\FD CNend
 \attention \n
 \param[out] stColorEnhanceParam  CNcomment:\D1\D5ɫ\D4\F6ǿ\B5\C4\C0\E0\D0ͺͲ\CE\CA\FD CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetColorEnhanceParam(HI_UNF_PQ_COLOR_ENHANCE_S stColorEnhanceParam);


/** Dynamic Contrast Improvement(DCI)
 \brief Get Dynamic Contrast Improvement(DCI) Range  CNcomment:\BB\F1ȡDCI\A3\A8\B6\AF̬\B6Աȶ\C8\D4\F6ǿ\A3\A9\B5\C4ǿ\B6ȷ\B6Χ CNend
 \attention \n
 \param[out] pu32DCIlevel; Range:0~100 CNcomment:\B6\AF̬\B6Աȶȵȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetDynamicContrast(HI_U32 *pu32DCIlevel);


/**
 \brief Get DCI Range  CNcomment:\BB\F1ȡDCIǿ\B6ȷ\B6Χ CNend
 \attention \n
 \param[in] u32DCIlevel; Range:0~100 CNcomment:\B6\AF̬\B6Աȶȵȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetDynamicContrast(HI_U32 u32DCIlevel);


/**
 \brief Get noise reduction strength CNcomment:\BB\F1ȡ\BD\B5\D4\EBǿ\B6\C8 CNend
 \attention \n
 \param[out] pu32NRLevel: noise reduction level; Range:0~100 CNcomment:\BD\B5\D4\EB\B5ȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetNR(HI_UNF_DISP_E enChan, HI_U32 *pu32NRLevel);


/**
 \brief  Set noise reduction strength CNcomment:\C9\E8\D6ý\B5\D4\EBǿ\B6\C8 CNend
 \attention \n
 \param[in] u32NRLevel: noise reduction level; Range:0~100 CNcomment:\BD\B5\D4\EB\B5ȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetNR(HI_UNF_DISP_E enChan, HI_U32 u32NRLevel);

/**
 \brief Get digital noise reduction strength CNcomment:\BB\F1ȡ\CA\FD\D7ֽ\B5\D4\EBǿ\B6\C8 CNend
 \attention \n
 \param[out] pu32NRLevel: noise reduction level; Range:0~100 CNcomment:\CA\FD\D7ֽ\B5\D4\EB\B5ȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetDNR(HI_UNF_DISP_E enChan, HI_U32 *pu32DNRLevel);


/**
 \brief  Set digital noise reduction strength CNcomment:\C9\E8\D6\C3\CA\FD\D7ֽ\B5\D4\EBǿ\B6\C8 CNend
 \attention \n
 \param[in] u32NRLevel: noise reduction level; Range:0~100 CNcomment:\CA\FD\D7ֽ\B5\D4\EB\B5ȼ\B6\A3\BB\D3\D0Ч\B7\B6Χ: 0~100 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetDNR(HI_UNF_DISP_E enChan, HI_U32 u32DNRLevel);



/**
 \brief  Set Algorithm Moudle on-off  CNcomment:\C9\E8\D6\C3\CB㷨ģ\BF鿪\B9\D8 CNend
 \attention \n
 \param[in] enFlags   CNcomment:\CB㷨ģ\BF\E9 CNend
 \param[in] u32OnOff  CNcomment:\CB㷨\BF\AA\B9\D8 CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 */
HI_S32 HI_UNF_PQ_SetPQModule(HI_UNF_PQ_MODULE_E enFlags, HI_U32 u32OnOff);


/**
 \brief Get Algorithm Moudle on-off  CNcomment:\BB\F1ȡ\CB㷨ģ\BF鿪\B9\D8 CNend
 \attention \n
 \param[in]  enFlags   CNcomment:\CB㷨ģ\BF\E9 CNend
 \param[out] pu32OnOff CNcomment:\CB㷨\BF\AA\B9\D8 CNend
 \retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetPQModule(HI_UNF_PQ_MODULE_E enFlags, HI_U32 *pu32OnOff);


/**
 \brief Set Demo Mode on-off  CNcomment:\C9\E8\D6\C3\C2\F4\B3\A1ģʽ\BF\AA\B9\D8 CNend
 \attention \n
 \param[in] enFlags   CNcomment:\CB㷨ģ\BF\E9 CNend
 \param[in] u32OnOff  CNcomment:\C2\F4\B3\A1ģʽ\BF\AA\B9\D8 CNend
 \retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetDemo(HI_UNF_PQ_DEMO_E enFlags, HI_U32 u32OnOff);


/**
 \brief Set Demo Display Mode  CNcomment:\C9\E8\D6\C3\C2\F4\B3\A1\CF\D4ʾģʽ CNend
 \attention \n
 \param[in] enChan    CNcomment:\CF\D4ʾͨ\B5\C0 CNend
 \param[in] enMode    CNcomment:\C2\F4\B3\A1\CF\D4ʾģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetDemoMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_DEMO_MODE_E enMode);


/**
 \brief Get Demo Display Mode  CNcomment:\BB\F1ȡ\C2\F4\B3\A1\CF\D4ʾģʽ CNend
 \attention \n
 \param[in] enChan    CNcomment:\CF\D4ʾͨ\B5\C0 CNend
 \param[out] enMode   CNcomment:\C2\F4\B3\A1\CF\D4ʾģʽ CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetDemoMode(HI_UNF_DISP_E enChan, HI_UNF_PQ_DEMO_MODE_E *penMode);

/**
 \brief Set Demo Display Mode Coordinate CNcomment:\C9\E8\D6\C3\C2\F4\B3\A1\CF\D4ʾ\D7\F8\B1\EA CNend
 \attention \n
 \param[in] u32X Range:0~100 Default:50 CNcomment:\C2\F4\B3\A1\CF\D4ʾ\B7ֽ\E7\CFߺ\E1\D7\F8\B1\EA \D3\D0Ч\B7\B6Χ:0~100 Ĭ\C8\CFֵ:50 CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_SetDemoCoordinate(HI_U32 u32X);


/**
 \brief Get Demo Display Mode Coordinate CNcomment:\BB\F1ȡ\C2\F4\B3\A1\CF\D4ʾģʽ\D7\F8\B1\EA CNend
 \attention \n
 \param[out] pu32X  Range:0~100 Default:50 CNcomment:\C2\F4\B3\A1\CF\D4ʾ\B7ֽ\E7\CFߺ\E1\D7\F8\B1\EA \D3\D0Ч\B7\B6Χ:0~100 Ĭ\C8\CFֵ:50 CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend

 */
HI_S32 HI_UNF_PQ_GetDemoCoordinate(HI_U32 *pu32X);


/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_PQ_H__ */


