/******************************************************************************

  Copyright (C), 2017, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_otp_common_ca.h
  Version       : Initial Draft
  Author        : Hisilicon otp software group
  Created       : 2017/1/14
  Description   :
*******************************************************************************/
#ifndef __HI_UNF_OTP_COMMON_CA_H__
#define __HI_UNF_OTP_COMMON_CA_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      OTP_COMMON_CA */
/** @{ */  /** <!-- [OTP_COMMON_CA] */

/** advanced CA session serect key class*/
typedef enum {
    HI_UNF_OTP_COMMON_CA_KLAD_LEV1 = 0,   /**<session serect key level 1*/
    HI_UNF_OTP_COMMON_CA_KLAD_LEV2,       /**<session serect key level 2*/
    HI_UNF_OTP_COMMON_CA_KLAD_LEV3,       /**<session serect key level 3*/
    HI_UNF_OTP_COMMON_CA_KLAD_LEV4,       /**<session serect key level 4*/
    HI_UNF_OTP_COMMON_CA_KLAD_LEV5,       /**<session serect key level 5*/
    HI_UNF_OTP_COMMON_CA_KLAD_LEV_BUTT
} HI_UNF_OTP_COMMON_CA_KLAD_LEV_E;


/** advanced CA session serect key class*/
typedef enum {
    HI_UNF_OTP_COMMON_CA_KLAD_TARGET_DEMUX_CIPHER = 0,
    HI_UNF_OTP_COMMON_CA_KLAD_TARGET_DEMUX,
    HI_UNF_OTP_COMMON_CA_KLAD_TARGET_CIPHER,
    HI_UNF_OTP_COMMON_CA_KLAD_TARGET_NULL,
    HI_UNF_OTP_COMMON_CA_KLAD_TARGET_BUTT
} HI_UNF_OTP_COMMON_CA_KLAD_TARGET_E;


typedef enum {
    HI_UNF_OTP_COMMON_CA_KLAD_CSA2 = 0,
    HI_UNF_OTP_COMMON_CA_KLAD_CSA3,
    HI_UNF_OTP_COMMON_CA_KLAD_SP,
    HI_UNF_OTP_COMMON_CA_KLAD_MISC,
    HI_UNF_OTP_COMMON_CA_KLAD_R2R,
    HI_UNF_OTP_COMMON_CA_KLAD_LP,
    HI_UNF_OTP_COMMON_CA_KLAD_BUTT
} HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E;

/** Rootkey type*/
typedef enum {
    HI_UNF_OTP_COMMON_CA_CSA2 = 0,
    HI_UNF_OTP_COMMON_CA_CSA3,
    HI_UNF_OTP_COMMON_CA_SP,
    HI_UNF_OTP_COMMON_CA_MISC,
    HI_UNF_OTP_COMMON_CA_R2R,
    HI_UNF_OTP_COMMON_CA_LP,
    HI_UNF_OTP_COMMON_CA_BOOT,
    HI_UNF_OTP_COMMON_CA_BUTT
} HI_UNF_OTP_COMMON_CA_ROOTKEY_E;


/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      OTP_COMMON_CA */
/** @{ */  /** <!-- [OTP_COMMON_CA] */


/**
\brief Set the chipID. CNcomment:\C9\E8\D6\C3оƬID CNend
\attention \n
\param[in] pu8ChipID point to chip id. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACоƬID CNend
\param[in] u32Len The length of ChipID, current is 8. CNcomment:оƬID\B3\A4\B6ȣ\AC8 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_SETPARAM_AGAIN The parameter has been set already. CNcomment:\D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_COMMON_CA_SetChipID(HI_U8 *pu8ChipID, HI_U32 u32Len);


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
HI_S32 HI_UNF_OTP_COMMON_CA_GetChipID(HI_U8 *pu8ChipID, HI_U32 *pu32Len);


/**
\brief Set klad level. CNcomment:\C9\E8\D6\C3keylad\BC\B6\CA\FD CNend
\attention \n
N/A
\param[in] enType: klad type.   CNcomment:Klad\C0\E0\D0\CD CNend
\param[in] enLevel: klad level. CNcomment:Klad\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_SetKladLevel(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType, HI_UNF_OTP_COMMON_CA_KLAD_LEV_E enLevel);


/**
\brief Get klad level. CNcomment:\C9\E8\D6\C3keylad\BC\B6\CA\FD CNend
\attention \n
N/A
\param[in] enType: klad type.       CNcomment:Klad\C0\E0\D0\CD CNend
\param[out] penLevel: klad level.   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACKlad\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS  Success.      CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_GetKladLevel(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType, HI_UNF_OTP_COMMON_CA_KLAD_LEV_E *penLevel);


/**
\brief Set klad target. CNcomment:\C9\E8\D6\C3keyladĿ\B1\EA CNend
\attention \n
N/A
\param[in] enType: klad type.           CNcomment:Klad\C0\E0\D0\CD CNend
\param[in] enTarget: target type.       CNcomment:Ŀ\B1\EA\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS  Success.          CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_SetKladTarget(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType, HI_UNF_OTP_COMMON_CA_KLAD_TARGET_E enTarget);


/**
\brief Get klad target control. CNcomment:\BB\F1ȡkeyladĿ\B1\EA CNend
\attention \n
N/A
\param[in] enType: klad type.           CNcomment:Klad\C0\E0\D0\CD CNend
\param[out] penTarget: target type.     CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACĿ\B1\EA\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS  Success.          CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_GetKladTarget(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType, HI_UNF_OTP_COMMON_CA_KLAD_TARGET_E *penTarget);

/**
\brief Disable keyladder. CNcomment:\BD\FB\D3\C3keyladder CNend
\attention \n
N/A
\param[in] enType: klad type.               CNcomment:Klad\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_DisableKlad(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType);

/**
\brief Get klad disable status. CNcomment:\BB\F1ȡkladʹ\C4\DC״̬ CNend
\attention \n
N/A
\param[in] enType: klad type.               CNcomment:Klad\C0\E0\D0\CD CNend
\param[out] pbEnable:  Klad enable status.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACKladʹ\C4\DC״̬ CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_GetKladStat(HI_UNF_OTP_COMMON_CA_KLAD_TYPE_E enType, HI_BOOL *pbEnable);


/**
\brief Set root key to otp. CNcomment:\CF\F2оƬ\C4ڲ\BF\C9\E8\D6ø\F9\C3\DCԿ CNend
\attention \n
N/A
\param[in] enType: Type of keyladder rootkey.       CNcomment:\B8\F9\C3\DCԿ\C0\E0\D0\CD CNend
\param[in] pu8Key: Point to root key value.         CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B8\F9\C3\DCԿ CNend
\param[in] u32KeyLen: The length of root key.       CNcomment:\B8\F9\C3\DCԿ\B3\A4\B6\C8 CNend
\retval ::HI_SUCCESS Success                                            CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called                        CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized  CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid   CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_SetRootKey(HI_UNF_OTP_COMMON_CA_ROOTKEY_E enType, HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Get root key lock status.                    CNcomment:\BB\F1ȡOTP\CB\F8״̬\D0\C5Ϣ CNend
\attention \n
N/A
\param[in] enRootkeyType: Type of rootkey.          CNcomment:\B8\F9\C3\DCԿ\C0\E0\D0\CD CNend
\param[out] pbLock: Point to root key lock status.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B8\FA\C3\DCԿ\CAǷ\F1\B1\BB\CB\F8 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_GetRootKeyLockStat(HI_UNF_OTP_COMMON_CA_ROOTKEY_E enType, HI_BOOL *pbLock);

/**
\brief Set JTAG key to otp. CNcomment:\CF\F2оƬ\C4ڲ\BF\C9\E8\D6\C3JTAG\C3\DCԿ CNend
\attention \n
N/A
\param[in] pu8Key: Point to JTAG key value.         CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACJTAG\C3\DCԿ CNend
\param[in] u32KeyLen: The length of JRAG key.       CNcomment:JTAG\C3\DCԿ\B3\A4\B6\C8 CNend
\retval ::HI_SUCCESS Success                                            CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called                        CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized  CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid   CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_SetJTAGKey(HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Get JTAG key lock status.                    CNcomment:\BB\F1ȡJTAG key\CB\F8״̬\D0\C5Ϣ CNend
\attention \n
N/A
\param[out] pbLock: Point to JTAG key lock status.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACJTAG key\CAǷ\F1\B1\BB\CB\F8 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_COMMON_CA_GetJTAGKeyLockStat(HI_BOOL *pbLock);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_OTP_COMMON_CA_H__ */
