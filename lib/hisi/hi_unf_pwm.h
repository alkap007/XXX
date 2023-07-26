/******************************************************************************

   Copyright (C), 2011-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_unf_pwm.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/10/28
   Description   :
   History       :
   1.Date        : 2013/10/28
    Author      : sdk
    Modification: Created file

 *******************************************************************************/

/**
 * \file
 **\brief : define PWM module information
 * \brief supply infor about display.
 */

#ifndef __HI_UNF_PWM_H__
#define __HI_UNF_PWM_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      PWM */
/** @{ */  /** <!-- [PWM] */

/**enum define about PWM*/
/**CNcomment: \B6\A8\D2\E5PWMö\BE\D9*/
typedef enum hiUNF_PWM_E
{
    HI_UNF_PWM_0 = 0,   /**< PWM0 */
    HI_UNF_PWM_1,       /**< PWM1 */
    HI_UNF_PWM_2,       /**< PWM2 */
    
    HI_UNF_PWM_BUTT
}HI_UNF_PWM_E;

/**Define the PWM attributes*/
/**CNcomment: \B6\A8\D2\E5PWM\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_PWM_ATTR_S
{
    HI_U32      u32Freq;        /**< Frequency(HZ)*//**< CNcomment: Ƶ\C2\CA, \B5\A5λHZ*/
    HI_U32      u32DutyRatio;   /**< Duty ratio(calculated to three decimal places)*//**<CNcomment: ռ\BFձȣ\AC\B1\A3\C1\F4С\CA\FD\B5\E3\BA\F3\C8\FDλ*/
}HI_UNF_PWM_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      PWM */
/** @{ */  /** <!-- [PWM] */

/**
\brief Initializes the PWM module.CNcomment:\B3\F5ʼ\BB\AFPWMģ\BF\E9 CNend
\attention \n
Before calling anyother interface, you must call this application programming interface (API) first.
CNcomment \D4ڵ\F7\D3\C3PWMģ\BF\E9\C6\E4\CB\FB\BDӿ\DAǰ\A3\ACҪ\C7\F3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA CNend
\param  N/A
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_DEV_NOT_EXIST    There is no PWM. CNcomment:PWM\C9豸\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_PWM_OPEN_ERR         Open PWM failed. CNcomment:PWM\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_Init(HI_VOID);

/**
\brief DeInitializes the PWM module.CNcomment:ȥ\B3\F5ʼ\BB\AFPWMģ\BF\E9 CNend
\attention N/A
\param  N/A
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_DEV_NOT_EXIST    There is no PWM. CNcomment:PWM\C9豸\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_PWM_CLOSE_ERR        Open PWM failed. CNcomment:PWM\B9ر\D5ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_DeInit(HI_VOID);

/**
\brief Opem PWM.CNcomment:\B4\F2\BF\AAPWM CNend
\attention N/A
\param[in] enPWM  PWM device. CNcomment:PWM\C9豸\A3\AC\BC\FB::HI_UNF_PWM_E CNend
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_INVALID_PARA     Parameter is invalid. CNcomment:\B2\CE\CA\FD\CE\DEЧ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_Open(HI_UNF_PWM_E enPWM);

/**
\brief Close PWM.CNcomment:\B9ر\D5PWM CNend
\attention N/A
\param[in] enPWM  PWM device. CNcomment:PWM\C9豸\A3\AC\BC\FB::HI_UNF_PWM_E CNend
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_INVALID_PARA     Parameter is invalid. CNcomment:\B2\CE\CA\FD\CE\DEЧ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_Close(HI_UNF_PWM_E enPWM);

/**
\brief Set PWM attributes.CNcomment:\BB\F1ȡPWM\CA\F4\D0\D4 CNend
\attention N/A
\param[in] enPWM  PWM device. CNcomment:PWM\C9豸\A3\AC\BC\FB::HI_UNF_PWM_E CNend
\param[out] pstAttr  Pointer of PWM attributes. CNcomment:PWM\CA\F4\D0\D4ָ\D5룬\BC\FB::HI_UNF_PWM_ATTR_S CNend
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_INVALID_PARA     Parameter is invalid. CNcomment:\B2\CE\CA\FD\CE\DEЧ CNend
\retval ::HI_ERR_PWM_INVALID_OPT      Opration is invalid. CNcomment:\B2\D9\D7\F7\CE\DEЧ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_GetAttr(HI_UNF_PWM_E enPWM, HI_UNF_PWM_ATTR_S *pstAttr);

/**
\brief Set PWM attributes.CNcomment:\C9\E8\D6\C3PWM\CA\F4\D0\D4 CNend
\attention N/A
\param[in] enPWM  PWM device. CNcomment:PWM\C9豸\A3\AC\BC\FB::HI_UNF_PWM_E CNend
\param[in] pstAttr  Pointer of PWM attributes. CNcomment:PWM\CA\F4\D0\D4ָ\D5룬\BC\FB::HI_UNF_PWM_ATTR_S CNend
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_INVALID_PARA     Parameter is invalid. CNcomment:\B2\CE\CA\FD\CE\DEЧ CNend
\retval ::HI_ERR_PWM_INVALID_OPT      Opration is invalid. CNcomment:\B2\D9\D7\F7\CE\DEЧ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_SetAttr(HI_UNF_PWM_E enPWM, HI_UNF_PWM_ATTR_S *pstAttr);

/**
\brief Send signal to PWM.CNcomment:\CF\F2PWM\B7\A2\CB\CD\D0ź\C5 CNend
\attention N/A
\param[in] enPWM  PWM device. CNcomment:PWM\C9豸\A3\AC\BC\FB::HI_UNF_PWM_E CNend
\param[in] u32CarrierTimeUs  The duration of carrier signal(us). CNcomment:\D4ز\A8\D0źų\D6\D0\F8ʱ\BC\E4(us) CNend
\param[in] u32LowLevelTimeUs  The duration of low-level signal(us). CNcomment:\B5\CD\D0źų\D6\D0\F8ʱ\BC\E4(us) CNend
\retval ::HI_SUCCESS                  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PWM_INVALID_PARA     Parameter is invalid. CNcomment:\B2\CE\CA\FD\CE\DEЧ CNend
\retval ::HI_ERR_PWM_INVALID_OPT      Opration is invalid. CNcomment:\B2\D9\D7\F7\CE\DEЧ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PWM_SendSignal(HI_UNF_PWM_E enPWM, HI_U32 u32CarrierTimeUs, HI_U32 u32LowLevelTimeUs);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif


