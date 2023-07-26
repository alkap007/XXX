/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
******************************************************************************
File Name       : hi_unf_wdg.h
Version         : Initial draft
Author          : HiSilicon multimedia software group
Created Date    : 2008-06-05
Last Modified by:
Description     : Application programming interfaces (APIs) of the external chip software (ECS)
Function List   :
Change History  :
******************************************************************************/
#ifndef __HI_UNF_WDG_H__
#define __HI_UNF_WDG_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define HI_UNF_WDG_Open     HI_UNF_WDG_Init
#define HI_UNF_WDG_Close    HI_UNF_WDG_DeInit

/******************************* API Declaration *****************************/
/** \addtogroup      WDG*/
/** @{*/  /** <!-- [WDG] */

/**
 \brief Starts the WDG device.
CNcomment:\brief \B3\F5ʼ\BB\AFWDG\A3\A8Watch Dog\A3\A9\C9豸\A1\A3CNend

 \attention \n
By default, the WDG device is disabled after it is started. In this case, you need to call HI_UNF_WDG_Enable to enable it.\n
CNcomment:\B4\F2\BF\AA֮\BA\F3\A3\ACWDGĬ\C8\CF\CAǽ\FBֹ\B5ģ\AC\D0\E8Ҫ\CF\D4ʽ\B5\F7\D3\C3HI_UNF_WDG_Enableʹ\C4\DCWDG\C9豸\A1\A3CNend\N

 \param N/A          	CNcomment:\CEޡ\A3CNend
 \retval 0 Success.   	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_INIT	open failed
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_Init(HI_VOID);

/**
 \brief Stops the WDG device.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFWDG\C9豸\A1\A3CNend

 \attention \n
N/A
 \param N/A          	CNcomment:\CEޡ\A3CNend
 \retval 0 Success.   	CNcomment:\B3ɹ\A6\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_DeInit(HI_VOID);

/**
 \brief Get the number of WDG device.
CNcomment:\brief \BB\F1ȡWDG\C9豸\CA\FD\C1\BF\A1\A3CNend

 \attention \n
You can call this API to get thenumber of WDG chipset supports after the WDG device is started.
CNcomment:\B4\F2\BF\AAWDG\C9豸\BA󣬵\F7\D3ô˽ӿڻ\F1ȡоƬ֧\B3ֵ\C4WDG\B5\C4\CA\FD\C1\BF\A1\A3CNend

 \param[out] pu32WdgNum  The number of WDG chipset supports        	CNcomment:оƬ֧\B3ֵ\C4WDG\B5\C4\CA\FD\C1\BF\A1\A3CNend
 \retval 0 Success  CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE The Parameter pu32WdgNum is NULL.       CNcomment:\B2\CE\CA\FDָ\D5\EBpu32WdgNumΪ\BFա\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_GetCapability(HI_U32 *pu32WdgNum);

/**
 \brief Enables the WDG device.
CNcomment:\brief ʹ\C4\DCWDG\C9豸\A1\A3CNend

 \attention \n
You must call HI_UNF_WDG_Enable after the WDG device is started.
CNcomment:\B4\F2\BF\AAWDG\C9豸\BA󣬱\D8\D0\EB\CF\D4ʽ\B5\F7\D3\C3ʹ\C4ܽӿڡ\A3CNend

 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \retval 0 Success.  	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT The WDG device is not initialized.       CNcomment:WDG\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA The Paramteter is invalid. 			CNcomment:\B2\CE\CA\FD\CE\DEЧ\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_ENABLE enable watchdog failed.				CNcomment:ʹ\C4ܿ\B4\C3Ź\B7ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_Enable(HI_U32 u32WdgNum);

/**
 \brief Disables the WDG device.
CNcomment:\brief \BD\FBֹWDG\C9豸\A1\A3CNend

 \attention \n
After calling this API, you cannot feed and reset the WDG.
CNcomment:\B5\F7\D3ô˺\AF\CA\FD\BA\F3\A3\ACι\B9\B7\BA͸\B4λ\B2\D9\D7\F7\B2\BB\C6\F0\D7\F7\D3á\A3CNend

 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA The Paramteter is invalid. 			CNcomment:\B2\CE\CA\FD\CE\DEЧ\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_DISABLE  disable watchdog failed.			CNcomment:\BD\FBֹ\BF\B4\C3Ź\B7ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_Disable(HI_U32 u32WdgNum);

/**
 \brief Obtains the interval of feeding the WDG.
CNcomment:\brief \BB\F1ȡι\B9\B7ʱ\BC\E4\BC\E4\B8\F4\A1\A3CNend

 \attention \n
The interval precision is as high as 1000 ms.
CNcomment:ʱ\BC\E4\BC\E4\B8\F4\BE\ABȷ\B5\BD1000ms\A1\A3CNend

 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \param[in] pu32Value  Interval of feeding the WDG, in ms.             	CNcomment:ι\B9\B7ʱ\BC\E4\BC\E4\B8\F4\A3\AC\B5\A5λΪms\A1\A3CNend
 \retval 0 Success.                                                  	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.     	CNcomment:WDG \C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA  The WDG input pointer is invalid.  	CNcomment:WDG\CA\E4\C8\EBָ\D5\EB\CE\DEЧ\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_SETTIMEOUT get timeout failed.			  	CNcomment:WDG\BB\F1ȡ\B3\ACʱʱ\BC\E4ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_GetTimeout(HI_U32 u32WdgNum, HI_U32 *pu32Value);

/**
 \brief Sets the interval of feeding the WDG.
CNcomment:\brief \C9\E8\D6\C3ι\B9\B7ʱ\BC\E4\BC\E4\B8\F4\A1\A3CNend

 \attention \n
N/A
 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \param[out] u32Value  Interval of feeding the WDG, in ms.                		CNcomment:ι\B9\B7ʱ\BC\E4\BC\E4\B8\F4\A3\AC\B5\A5λΪms\A1\A3CNend
 \retval 0 Success.                                                      		CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT The WDG device is not initialized.       		CNcomment:WDG\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_SETTIMEOUT The WDG set timeout failed.   			CNcomment:WDG\C9\E8\D6ó\ACʱʱ\BC\E4ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA  The WDG input parameter is invalid. 		CNcomment:WDG\CA\E4\C8\EB\B2\CE\CA\FD\CE\DEЧ\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_SetTimeout(HI_U32 u32WdgNum, HI_U32 u32Value);

/**
 \brief Feeds the WDG.
CNcomment:\brief ִ\D0\D0ι\B9\B7\B2\D9\D7\F7\A1\A3CNend

 \attention \n
N/A
 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \retval 0 Success.                                                   	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.      CNcomment:WDG\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_CLEARWDG  The WDG clear watchdog failed.   CNcomment:WDG ι\B9\B7ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA The Paramteter is invalid. 			CNcomment:\B2\CE\CA\FD\CE\DEЧ\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_Clear(HI_U32 u32WdgNum);

/**
 \brief Resets the entire system.
CNcomment:\brief \D3\C3\D3ڸ\B4λ\D5\FB\B8\F6ϵͳ\A1\A3CNend

 \attention \n
N/A
 \param[in] u32WdgNum WDG No. to operate.        	CNcomment:ִ\D0в\D9\D7\F7\B5\C4WDG\BAš\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_WDG_NOT_INIT  The WDG device is not initialized.  CNcomment:WDG\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_WDG_FAILED_RESET The WDG reset failed.   			CNcomment:WDG\B8\B4λʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_WDG_INVALID_PARA The Paramteter is invalid. 		CNcomment:\B2\CE\CA\FD\CE\DEЧ\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_WDG_Reset(HI_U32 u32WdgNum);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* __HI_UNF_WDG_H__ */
