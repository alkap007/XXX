/******************************************************************************

  Copyright (C), 2017, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_otp_dcas.h
  Version       : Initial Draft
  Author        : Hisilicon otp software group
  Created       : 2017/1/14
  Description   :
*******************************************************************************/
#ifndef __HI_UNF_OTP_DCAS_H__
#define __HI_UNF_OTP_DCAS_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      OTP_DCAS */
/** @{ */  /** <!-- [OTP_DCAS] */


/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      OTP_DCAS */
/** @{ */  /** <!-- [OTP_DCAS] */


/**
\brief Get the chipID. CNcomment:\BB\F1ȡоƬID CNend
\attention \n
\param[out] pu8ChipID point to chip id. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACоƬID CNend
\param[in/out] pu32Len Point to the length of ChipID, current output length is 8. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACоƬID\B3\A4\B6ȣ\AC\B5\B1ǰ\CA\E4\B3\F68 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_SETPARAM_AGAIN The parameter has been set already. CNcomment:\D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_DCAS_GetChipID(HI_U8 *pu8ChipID, HI_U32 *pu32Len);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_OTP_DCAS_H__ */
