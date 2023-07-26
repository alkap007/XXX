/******************************************************************************

  Copyright (C), 2011-2014, HiSilicon Technologies Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_pdm.h
  Version       : Initial Draft
  Author        : HiSilicon multimedia software group
  Created       : 2011-xx-xx
  Description   : hi_unf_pdm.h header file
  History       :
  1.Date        : 2011/xx/xx
    Author      :
    Modification: This file is created.

******************************************************************************/

#ifndef __HI_UNF_PDM_H__
#define __HI_UNF_PDM_H__

#include "hi_unf_common.h"
#include "hi_unf_mce.h"
#include "hi_go_surface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif  /* End of #ifdef __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */

/**Defines the base config parameter*/
/** CNcomment:\BB\F9\B1\BE\C5\E4\D6ò\CE\CA\FD\BDṹ\CC\E5*/
typedef struct hiUNF_PDM_DISP_PARAM_S
{
    HI_UNF_DISP_E               enSrcDisp;          /**<source display*//**<CNcomment: ͬԴdisplayö\BE\D9*/
    HI_UNF_ENC_FMT_E            enFormat;           /**<Format*//**<CNcomment: \D6\C6ʽ*/
    HI_U32                      u32Brightness;      /**<Brightness*//**<CNcomment: \C1\C1\B6\C8*/
    HI_U32                      u32Contrast;        /**<Contrast*//**<CNcomment: \B6Աȶ\C8*/
    HI_U32                      u32Saturation;      /**<Saturation*//**<CNcomment: \B1\A5\BAͶ\C8*/
    HI_U32                      u32HuePlus;         /**<HuePlus*//**<CNcomment: ɫ\B6\C8*/
    HI_BOOL                     bGammaEnable;       /**<Is Gamma enable*//**<CNcomment: \CAǷ\F1ʹ\C4\DCgamma*/
    HI_UNF_DISP_BG_COLOR_S      stBgColor;          /**<Background Color*//**<CNcomment: \B1\B3\BE\B0ɫ*/
    HI_UNF_DISP_INTF_S          stIntf[HI_UNF_DISP_INTF_TYPE_BUTT];     /**<configuration of display interface*//**<CNcomment: \CF\D4ʾ\BDӿ\DA\C5\E4\D6\C3*/
    HI_UNF_DISP_TIMING_S        stDispTiming;       /**<Display timeing*//**<CNcomment: \CF\D4ʾʱ\D0\F2*/

    HIGO_PF_E                   enPixelFormat;      /**<Pixel format*//**<CNcomment: \CF\F1\CBظ\F1ʽ*/
    HI_UNF_DISP_OFFSET_S        stDispOffset;       /**<Display margin info*//**<CNcomment: \CF\D4ʾ\BFհ\D7\C7\F8\D3\F2*/
    HI_U32                      u32VirtScreenWidth; /**<Virtual screen width*//**<CNcomment: \D0\E9\C4\E2\C6\C1Ļ\BF\ED*/
    HI_U32                      u32VirtScreenHeight;    /**<Virtual screen height*//**<CNcomment: \D0\E9\C4\E2\C6\C1Ļ\B8\DF*/

    HI_UNF_DISP_ASPECT_RATIO_S  stAspectRatio;      /**<The device aspect ratio*//**<CNcomment: \C9豸\BF\ED\B8߱\C8*/
    HI_UNF_HDMI_VIDEO_MODE_E    enVidOutMode;       /**<HDMI output vedio mode*//**<CNcomment:HDMI\CA\E4\B3\F6\CA\D3Ƶģʽ*/
    HI_UNF_HDMI_DEEP_COLOR_E    enDeepColorMode;    /**<Deep Color output mode*//**<CNcomment:DeepColor\CA\E4\B3\F6ģʽ*/
}HI_UNF_PDM_DISP_PARAM_S;

typedef struct hiUNF_PDM_SOUND_PARAM_S
{
    HI_U32                    u32PortNum;  /**<Outport number attached sound*/ /**<CNcomment:\B0󶨵\BDSound\C9豸\B5\C4\CA\E4\B3\F6\B6˿\DA\CA\FD*/
    HI_UNF_SND_OUTPORT_S stOutport[HI_UNF_SND_OUTPUTPORT_MAX];  /**<Outports attached sound*/ /**<CNcomment:\B0󶨵\BDSound\C9豸\B5\C4\CA\E4\B3\F6\B6˿\DA*/
    HI_U32               au32Volume[HI_UNF_SND_OUTPUTPORT_MAX];
}HI_UNF_PDM_SOUND_PARAM_S;

typedef struct hiUNF_PDM_PMOC_PARAM_S
{
    HI_U32      u32Flag;  /**<Restore the standby mode, 1: enable; 0: disable>*/ /**<CNcomment:\BBָ\B4\B9ػ\FAǰ\B5Ĵ\FD\BB\FA״̬\A3\AC1:ʹ\C4\DC; 0:\B2\BBʹ\C4\DC*/
}HI_UNF_PDM_PMOC_PARAM_S;

typedef enum hiUNF_PDM_BASEPARAM_TYPE_E
{
    HI_UNF_PDM_BASEPARAM_DISP0 = 0,     /*HI_UNF_PDM_DISP_PARAM_S * */
    HI_UNF_PDM_BASEPARAM_DISP1,         /*HI_UNF_PDM_DISP_PARAM_S * */
    HI_UNF_PDM_BASEPARAM_SOUND0 = 10,
    HI_UNF_PDM_BASEPARAM_SOUND1,
    HI_UNF_PDM_BASEPARAM_SOUND2,
    HI_UNF_PDM_BASEPARAM_HDMI = 20,
    HI_UNF_PDM_BASEPARAM_PMOC = 30,

    HI_UNF_PDM_BASEPARAM_BUTT = 0xFFFF,
}HI_UNF_PDM_BASEPARAM_TYPE_E;

typedef struct hiUNF_PDM_HDMI_PARAM_S
{
    HI_U8    *pu8EDID;
    HI_U32   *pu32EDIDLen;
}HI_UNF_PDM_HDMI_PARAM_S;

/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */
/**
\brief Obtains the basic configuration information.  CNcomment:\BB\F1ȡBASE\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstBaseParam   Pointer to the basic parameters.  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);


/**
\brief Modifies the basic configuration information.  CNcomment:\B8\FC\D0\C2BASE\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstBaseParam Pointer to the basic parameters.  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);

/**
\brief Obtains the basic configuration information from the flash memory.
CNcomment:\BB\F1ȡLOGO\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);

/**
\brief Modifies the configuration of the logo parameter.  CNcomment:\B8\FC\D0\C2LOGO\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
Update logo parameter, you must invoke this function befor update data of logo
\CNcomment:\B8\FC\D0\C2logo\B2\CE\CA\FD\A3\AC\D4ڸ\FC\D0\C2logo\C4\DA\C8\DDǰ\B1\D8\D0\EB\CFȵ\F7\D3ô˺\AF\CA\FD CNend
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);


/**
\brief Obtains the logo data from the flash memory. CNcomment:\BB\F1ȡLOGO\C4\DA\C8\DD\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the logo data that is written from the flash memory CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size  Size of the logo data to be written  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);


/**
\brief Modifies the logo data.  CNcomment:\B8\FC\D0\C2LOGO\C4\DA\C8\DD\C7\F8\D0\C5Ϣ CNend
\attention \n
Update data in logo partition, You must invoke HI_UNF_PDM_UpdateLogoParam to update logo parameter before invoke this function
\CNcomment:\B8\FC\D0\C2logo\C4\DA\C8ݣ\AC\D4ڴ˺\AF\CA\FD֮ǰ\B1\D8\D0\EB\CFȵ\F7\D3\C3HI_UNF_PDM_UpdateLogoParam\BA\AF\CA\FD\B8\FC\D0\C2logo\B2\CE\CA\FD CNend
\param[in]  pu8Content   Pointer to the logo data that is read from the flash memory  CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size   Size of the logo data to be read  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);

/**
\brief Obtains the playing configuration information.  CNcomment:\BB\F1ȡPLAY\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstPlayParam   Playing configuration information  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/**
\brief   Modifies the playing configuration information.  CNcomment:\B8\FC\D0\C2PLAY\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
Update play parameter, you must invoke this function befor update data of play
\CNcomment:\B8\FC\D0\C2play\B2\CE\CA\FD\A3\AC\D4ڸ\FC\D0\C2play\C4\DA\C8\DDǰ\B1\D8\D0\EB\CFȵ\F7\D3ô˺\AF\CA\FD CNend
\param[in]  pstPlayParam  Playing configuration information  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/**
\brief Obtains the data being playing from the flash memory.  CNcomment:\BB\F1ȡPLAY\C4\DA\C8\DD\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the data that is read from the flash memory  CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size  Size of the data being played that is read from the flash memory  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayContent(HI_U8 *pu8Content, HI_U32 u32Size);


/**
\brief Updates the playing data part. CNcomment:\B8\FC\D0\C2PLAY\C4\DA\C8\DD\C7\F8\D0\C5Ϣ CNend
\attention \n
Update data in play partition, You must invoke HI_UNF_PDM_UpdatePlayParam to update plat parameter before invoke this function
\CNcomment:\B8\FC\D0\C2play\C4\DA\C8ݣ\AC\D4ڴ˺\AF\CA\FD֮ǰ\B1\D8\D0\EB\CFȵ\F7\D3\C3HI_UNF_PDM_UpdatePlayParam\BA\AF\CA\FD\B8\FC\D0\C2play\B2\CE\CA\FD CNend
\param[in]  pu8Content  Pointer to the data that is written to the flash memroy  CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size  Size of the data being played  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayContent(HI_U8 *pu8Content, HI_U32 u32Size);

/**
\brief Obtains the playing configuration information from backup partition.  CNcomment:\B4ӱ\B8\B7ݷ\D6\C7\F8\BB\F1ȡPLAY\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstPlayParam   Playing configuration information  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayBakParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/**
\brief   Modifies the playing configuration information to backup partition.  CNcomment:\B8\FC\D0\C2PLAY\C5\E4\D6\C3\C7\F8\D0\C5Ϣ CNend
\attention \n
Update play parameter, you must invoke this function befor update data of play
\CNcomment:\B8\FC\D0\C2play\B2\CE\CA\FD\A3\AC\D4ڸ\FC\D0\C2play\C4\DA\C8\DDǰ\B1\D8\D0\EB\CFȵ\F7\D3ô˺\AF\CA\FD CNend
\param[in]  pstPlayParam  Playing configuration information  CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayBakParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/**
\brief Obtains the playing content from backup partition.  CNcomment:\B4ӱ\B8\B7ݷ\D6\C7\F8\BB\F1ȡPLAY\C4\DA\C8\DD\C7\F8\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the data that is read from the flash memory  CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size  Size of the data being played that is read from the flash memory  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayBakContent(HI_U8 *pu8Content, HI_U32 u32Size);


/**
\brief Updates the playing content to backup partition. CNcomment:\B8\FC\D0\C2PLAY\C4\DA\C8ݵ\BD\B1\B8\B7ݷ\D6\C7\F8 CNend
\attention \n
Update data in play partition, You must invoke HI_UNF_PDM_UpdatePlayBakParam to update plat parameter before invoke this function
\CNcomment:\B8\FC\D0\C2play\C4\DA\C8ݣ\AC\D4ڴ˺\AF\CA\FD֮ǰ\B1\D8\D0\EB\CFȵ\F7\D3\C3HI_UNF_PDM_UpdatePlayBakParam\BA\AF\CA\FD\B8\FC\D0\C2play\B2\CE\CA\FD CNend
\param[in]  pu8Content  Pointer to the data that is written to the flash memroy  CNcomment:\C4\DA\C8\DDbufָ\D5\EB CNend
\param[in]  u32Size  Size of the data being played  CNcomment:\C4\DA\C8ݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AAFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:\B2\C1\B3\FDFlash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayBakContent(HI_U8 *pu8Content, HI_U32 u32Size);


/**
\brief Obtains the device cfg info.  CNcomment:\BB\F1ȡ\C9豸\CF\E0\B9ص\C4\C5\E4\D6\C3\D0\C5Ϣ CNend
\attention \n
N/A
\param[in]  pstrCfgName Pointer to the cfg name,for exampe,
"MAC" to get the MAC address,"SN" to get the SN number.
Other configure items can be refered from the Readme file and BurnConfig.ini in HiproInfo tool directory.
CNcomment:\B4\AB\C8\EB\B5\C4\C5\E4\D6\C3\CF\EE\C3\FB,\C0\FD\C8\E7"MAC"Ϊ\BB\F1ȡMAC\B5\D8ַ,"SN"Ϊ\BB\F1ȡSN\BA\C5,
\C6\E4\CB\FB\C5\E4\D6\C3\CF\EE\C7\EB\B2ο\BCHiproInfo \B9\A4\BE\DFĿ¼\B5\C4Readme\CEļ\FE\BC\B0\C5\E4\D6\C3\CEļ\FE CNend
\param[in]  pstrCfgValue Pointer to the cfg output buffer  CNcomment:\CA\E4\B3\F6
buffer\B5ĵ\D8ַ\A3\AC\CA\E4\B3\F6buffer\D3\C3\D2Ա\A3\B4\E6\B6\C1ȡ\B5\BD\B5\C4ֵ CNend
\param[in]  u32Size  Size of the output buffer  CNcomment:\CA\E4\B3\F6buffer\B3\A4\B6\C8 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error.
CNcomment:\BB\F1ȡFlash\B7\D6\C7\F8\D0\C5Ϣʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:\B4\F2\BF\AA
Flash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment
:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:\B6\C1ȡ
Flash\B7\D6\C7\F8ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_GET_DEVINFO_ERR      Parse device info failed. CNcomment
:\BD\E2\CE\F6device info\C5\E4\D6\C3ʧ\B0\DC  CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetDeviceInfo(const HI_CHAR * pstrCfgName, HI_CHAR * pstrCfgValue, HI_U32 u32Size);

/**
\brief Get specific Reserve mem data. when the target buffer less than Reserve mem, this function
can only get "u32Size" size data or the whole data will be obtained.CNcomment:\BB\F1ȡָ\B6\A8\B1\A3\C1\F4\C4ڴ\E6\C7\F8\CA\FD\BE\DD.
\D4\DAĿ\B5\C4bufferС\D3ڱ\A3\C1\F4\C4ڴ\E6\C7\F8\B4\F3Сʱ\A3\AC\BA\AF\CA\FD\BD\F6\BFɻ\F1ȡ\B5\BDu32Size\B4\F3С\CA\FD\BEݣ\AC\B7\F1\D4򽫻\F1ȡ\D5\FB\B8\F6\B1\A3\C1\F4\C4ڴ\E6\CA\FD\BE\DD CNend
\attention \n
\param[in]  pstrName  Pointer to the reserve memery name  CNcomment:ָ\CF\F2\B1\A3\C1\F4\C4ڴ\E6\C7\F8\C3\FB\D7ֵ\C4\D7ַ\FB\B4\AEָ\D5\EB CNend
\param[in]  pBuf  Pointer to the out buffer used to get data  CNcomment:ָ\CF\F2\BB\F1ȡ\B4洢\CA\FD\BEݵ\C4\CA\E4\B3\F6bufferָ\D5\EB CNend
\param[in]  u32Size  The size of the pBuf  CNcomment: pBuf \B4\F3С CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_PARAM_INVALID para invalid. CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT   The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetReserveMemData(const HI_CHAR *pstrName, HI_VOID *pBuf, HI_U32 u32Size);

/**
\brief Get specific Reserve mem addr .CNcomment:\BB\F1ȡָ\B6\A8\B1\A3\C1\F4\C4ڴ\E6\C4ڴ\E6\B5\D8ַ\A3\A8\D0\E9\C4\E2\B5\D8ַ\C1\F4\D7\F7\D2Ժ\F3\CD\D8չ\A3\A9. CNend
\attention \n
\param[in]   pstrName  Pointer to the reserve memery name  CNcomment:ָ\CF\F2\B1\A3\C1\F4\C4ڴ\E6\C7\F8\C3\FB\D7ֵ\C4\D7ַ\FB\B4\AEָ\D5\EB CNend
\param[out]  pPhyAddr  Pointer to Phyaddr  CNcomment:ָ\CF\F2\B1\A3\C1\F4\C4ڴ\E6\B5\C4\CE\EF\C0\ED\B5\D8ַ CNend
\param[out]  pVirAddr  Pointer to Viraddr  CNcomment: ָ\CF\F2\B1\A3\C1\F4\C4ڴ\E6\B5\C4\D0\E9\C4\E2\B5\D8ַ CNend
\param[out]  pBufLen   The size of reserve mem  CNcomment: \B1\A3\C1\F4\C4ڴ\E6\C7\F8\B4\F3С CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_PDM_PARAM_INVALID para invalid. CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:\B7\D6\C5\E4\C4ڴ\E6ʧ\B0\DC CNend
\retval :: HI_ERR_PDM_INVALID_OPT   The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetReserveMemAddr(const HI_CHAR *pstrName, HI_U64 *pPhyAddr,  HI_U8 *pVirAddr, HI_U32 *pBufLen);

/** @} */  /*! <!-- API declaration end */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif




