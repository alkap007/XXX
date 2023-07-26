/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-15
 */

#ifndef __HI_MODULE_H__
#define __HI_MODULE_H__

#include "hi_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************Structure declaration *****************************/
/** @addtogroup     MODULE */
/** @{ */ /** <!--  [MODULE] */

#define HI_INVALID_MODULE_ID        (0xffffffff)
#define HI_MAX_USER_MODULE_NUMBER   (256)

/** Module ID flags */
typedef enum hiMOD_ID_E
{
    HI_ID_STB         = 0,

    /**< common. */ /**< CNcomment: ϵͳͨ\D3\C3ö\BE\D9\CA\FD\BEݳ\A3\C1\BF */
    HI_ID_SYS         = 1,
    HI_ID_MODULE      ,
    HI_ID_LOG         ,
    HI_ID_PROC        ,
    HI_ID_MEM         ,
    HI_ID_STAT        ,
    HI_ID_PDM         ,
    HI_ID_MEMDEV      ,

    HI_ID_DEMUX       = 0x0A,
    HI_ID_TSIO,
    HI_ID_IFCP,

    /**< audio. */ /**< CNcomment: \D2\F4Ƶ\B2\BF\B7ֳ\A3\C1\BF\C7\F8 */
    HI_ID_ADEC        = 0x10,
    HI_ID_AO          ,
    HI_ID_SIO_AI      ,
    HI_ID_SIO_AO      ,
    HI_ID_SIO         ,
    HI_ID_AI          ,
    HI_ID_AENC        ,
    HI_ID_SRC         ,
    HI_ID_AIAO        ,
    HI_ID_AFLT        ,
    HI_ID_ADSP        ,
    HI_ID_AMP         ,
    HI_ID_SIF         ,

    /**< video. */ /**< CNcomment: \CA\D3Ƶ\B2\BF\B7ֳ\A3\C1\BF\C7\F8 */
    HI_ID_VFMW        = 0x20,
    HI_ID_SVDEC       ,
    HI_ID_DISP        ,
    HI_ID_HDMI        ,
    HI_ID_VO          ,
    HI_ID_VPSS        ,
    HI_ID_VDEC        ,
    HI_ID_VI          ,
    HI_ID_VENC        ,
    HI_ID_PQ         ,
    HI_ID_EDID,
    HI_ID_VICAP       ,
    HI_ID_HDMIRX      ,
    /**< graphics. */ /**< CNcomment: ͼ\D0β\BF\B7ֳ\A3\C1\BF\C7\F8 */
    HI_ID_TDE         = 0x30,
    HI_ID_JPGDEC      ,
    HI_ID_JPGENC      ,
    HI_ID_FB          ,
    HI_ID_PNG         ,
    HI_ID_HIGO        ,
    HI_ID_GFX2D       ,

    /**< player. */ /**< CNcomment: \B2\A5\B7\C5\CF\E0\B9ز\BF\B7ֳ\A3\C1\BF\C7\F8 */
    HI_ID_PVR         = 0x40,
    HI_ID_AVPLAY      ,
    HI_ID_SYNC        ,
    HI_ID_VSYNC       ,
    HI_ID_ASYNC       ,
    HI_ID_FASTPLAY ,

    /**< ecs. */ /**< CNcomment: \CD\E2\C9貿\B7ֳ\A3\C1\BF\C7\F8 */
    HI_ID_FLASH       = 0x50,
    HI_ID_IR          ,
    HI_ID_RTC         ,
    HI_ID_I2C         ,
    HI_ID_SCI         ,
    HI_ID_ETH         ,
    HI_ID_USB_PROTECT ,
    HI_ID_WDG         = 0x57,   /* watch dog used 'W' */
    HI_ID_GPIO        ,
    HI_ID_GPIO_I2C    ,
    HI_ID_DMAC        ,
    HI_ID_PMOC        ,
    HI_ID_TUNER       ,
    HI_ID_KEYLED      ,
    HI_ID_E2PROM      ,
    HI_ID_CIPHER      ,
    HI_ID_OTP         = 0x60,
    HI_ID_CA          ,
    HI_ID_PM          ,
    HI_ID_CI          ,
    HI_ID_CIMAXPLUS   ,
    HI_ID_TVP5150     ,
    HI_ID_SIL9293     ,
    HI_ID_PWM         ,
    HI_ID_SPI         ,
    HI_ID_PLCIPHER    ,//0x69
    HI_ID_CERT        ,//0x6A
    HI_ID_SM          ,//0x6B
    HI_ID_RUNTIME     ,//0x6C
    HI_ID_MAILBOX     ,//0x6D
    HI_ID_CASIMAGE    ,//0x6E

    /**< voip, bluetooth,alsa. */ /**<  CNcomment: VOIP\A1\A2\C0\B6\D1\C0\B2\BF\B7ֳ\A3\C1\BF\C7\F8*/
    HI_ID_VOIP_HME    = 0x80,
    HI_ID_NDPT        ,
    HI_ID_AUDADP      ,
    HI_ID_BT          ,
    HI_ID_ALSA        ,
    HI_ID_3G          ,
    HI_ID_KARAOKE     ,

    /**< vp. */ /**<  CNcomment: VP\B3\A3\C1\BF\C7\F8*/
    HI_ID_VP          = 0x90,
    HI_ID_HDCP        ,

    /**< subtitle. */ /**<  CNcomment: \D7\D6Ļ\B3\A3\C1\BF\C7\F8*/
    HI_ID_SUBT        = 0x98,
    HI_ID_TTX         ,
    HI_ID_CC          ,

    /**< loader. */ /**< CNcomment: loader */
    HI_ID_LOADER      = 0xA0,

    /**< Reserve fro middleware: 0xA1-0XB7. */ /**<  CNcomment: \B8\F8\D6м\E4\BC\FEԤ\C1\F4 0xA1-0XB7.*/

    /**<GPU. */ /**< CNcomment:GPU*/
    HI_ID_GPU        = 0xB8,

    /**< user definition. */ /**< CNcomment: Ϊ\D5\FB\BB\FA\B1\A3\C1\F4\B5\C4\D7Զ\A8\D2\E5\C7\F8 */
    HI_ID_USR_START   = 0xC0,
    HI_ID_USR_END     = 0xFE,

    HI_ID_BUTT        = 0xFF
} HI_MOD_ID_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      MODULE */
/** @{ */  /** <!-- [MODULE] */

/**
@brief Register one module to manager. CNcomment:ģ\BF\E9ע\B2ᣬ\D3\C3\D3ڹ\DC\C0\ED CNend
@attention Before manager someone module, calling this interface. CNcomment:\C8\E7\D0\E8\B9\DC\C0\EDģ\BF飬\D3ô˽ӿ\DA\CF\C8ע\B2\E1 CNend
@param[in] pszModuleName The module name CNcomment:ģ\BF\E9\C3\FB\B3\C6 CNend
@param[in] u32ModuleID   The module ID. CNcomment:ģ\BF\E9ID CNend
@retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
@retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
@see \n
N/A CNcomment:\CE\DE CNend
*/
HI_S32 HI_MODULE_Register(HI_U32 u32ModuleID, const HI_CHAR * pszModuleName);

/**
@brief Register one moudle by name. CNcomment:ģ\BF\E9ע\B2ᣬID\D3\C9ϵͳ\B7\D6\C5\E4 CNend
@attention Before manager someone module, calling this interface. CNcomment:\C8\E7\D0\E8\B9\DC\C0\EDģ\BF飬\D3ô˽ӿ\DA\CF\C8ע\B2\E1 CNend
@param[in] pszModuleName The module name CNcomment:ģ\BF\E9\C3\FB\B3\C6 CNend
@param[out] pu32ModuleID The module id allocated by system. CNcomment:ϵͳ\B7\D6\C5\E4\B5\C4ģ\BF\E9ID CNend
@retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
@retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
@see \n
N/A CNcomment:\CE\DE CNend
*/
HI_S32 HI_MODULE_RegisterByName(const HI_CHAR * pszModuleName, HI_U32* pu32ModuleID);

/**
@brief UnRegister one module to trace. CNcomment:ģ\BF\E9\D2Ƴ\FD CNend
@attention Before stopping to manage someone module, calling this interface. CNcomment:\B2\BB\D0\E8Ҫ\B9\DC\C0\ED\B4\CBģ\BF\E9ʱ\A3\ACʹ\D3ô˽ӿ\DA\D2Ƴ\FDģ\BF\E9 CNend
@param[in] u32ModuleID The module ID. CNcomment:ģ\BF\E9ID CNend
@param[out] None CNcomment:\CE\DE CNend
@retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
@retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
@see \n
N/A CNcomment:\CE\DE CNend
*/
HI_S32 HI_MODULE_UnRegister(HI_U32 u32ModuleID);

/** @} */ /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
}
#endif

#endif /* __HI_MODULE_H__ */

