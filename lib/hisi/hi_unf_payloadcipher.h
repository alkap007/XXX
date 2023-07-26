/******************************************************************************
Copyright (C), 2016, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name   :  hi_unf_payloadcipher.h
Author        :  Hisilicon multimedia software group
Created      :  2016/10/21
Description :
******************************************************************************/
#ifndef __HI_UNF_PAYLOADCIPHER_H__
#define __HI_UNF_PAYLOADCIPHER_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PayloadCipher */
/** @{ */  /** <!-- [PayloadCipher] */

/** Max pidFilter Num */
/**CNcomment:\D7\EE\B4\F3PID\B9\FD\C2\CB\CA\FD*/
#define HI_UNF_PLCIPHER_PIDFILTER_NUM 16

/** PLCipher algorithm */
/** CNcomment:PLCipher\BC\D3\C3\DC\CB㷨*/
typedef enum
{
    HI_UNF_PLCIPHER_ALG_AES_IPTV            = 0x20,  /**<AES IPTV*/
    HI_UNF_PLCIPHER_ALG_AES_ECB             = 0x21,  /**<AES ECB*/
    HI_UNF_PLCIPHER_ALG_AES_CBC             = 0x22,  /**<AES CBC*/
    HI_UNF_PLCIPHER_ALG_AES_CISSA           = 0x23,  /**<AES CISSA*/
    HI_UNF_PLCIPHER_ALG_BUTT                = 0x84
}HI_UNF_PLCIPHER_ALG_E;

/** PLCipher Key Type */
/** CNcomment:PLCipher Key \C0\E0\D0\CD*/
typedef enum
{
    HI_UNF_PLCIPHER_KEY_EVEN       = 0,   /**< Even key type */ /**< CNcomment:żKEY\C0\E0\D0\CD*/
    HI_UNF_PLCIPHER_KEY_ODD        = 1,   /**< Odd key type */ /**< CNcomment:\C6\E6KEY\C0\E0\D0\CD*/
    HI_UNF_PLCIPHER_KEY_BUTT,
}HI_UNF_PLCIPHER_KEY_EVENODD_E;

/** Structure of the plcipher control information */
/** CNcomment:\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct
{
    HI_UNF_PLCIPHER_ALG_E enAlg;                   /**< Algorithm  type*/ /**< CNcomment:\CB㷨\C0\E0\D0\CD*/
    HI_BOOL bPIDFilterEn;                          /**< Pid filter switch, default disable, plcipher will encrypt all pids in the ts when the switch is setted with HI_FALSE, and plcipher will just encrypt the assigned pids when the switch is setted with HI_TRUE*/
                                                   /**< CNcomment:Pid \B9\FD\C2\CBʹ\D3ÿ\AA\B9أ\ACĬ\C8Ϲرգ\AC\B9ر\D5ʱplcipher\BD\AB\B6\D4TS\B0\FC\B5\C4\CB\F9\D3\D0PID\BD\F8\D0м\D3\C3ܣ\AC\B6\F8\B5\B1\BF\AA\C6\F4ʱplcipher\BD\F6\B6\D4ָ\B6\A8\B5\C4PID\CA\FD\BEݽ\F8\D0м\D3\C3\DC*/
    HI_U32  u32PidNum;                             /**< valid when bPIDFilterEn is HI_TRUE, the pid number need to be filted.*/ /**< CNcomment:\BD\F6\B5\B1bPIDFilterEnΪHI_TRUEʱ\D3\D0Ч\A3\ACҪ\B9\FD\C2˵\C4PID\B8\F6\CA\FD*/
    HI_U16  u16PID[HI_UNF_PLCIPHER_PIDFILTER_NUM]; /**< valid when bPIDFilterEn is HI_TRUE, the pid arrays need to be filted.*/ /**< CNcomment:\BD\F6\B5\B1bPIDFilterEnΪHI_TRUEʱ\D3\D0Ч\A3\ACҪ\B9\FD\C2˵\C4PID\CA\FD\D7\E9*/
    HI_UNF_PLCIPHER_KEY_EVENODD_E enEvenOdd;       /**< Even Odd type, for keyladder encrypt even or odd key set */ /**< CNcomment:\C6\E6ż\C0\E0\D0ͣ\AC\D5\EB\B6\D4\D3\DAkeyladder \BC\D3\C3ܳ\A1\BE\B0ʱ\C5\E4\D6\C3\C6\E6ż\CA\F4\D0\D4*/
} HI_UNF_PLCIPHER_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      PayloadCipher */
/** @{ */  /** <!--[PayloadCipher]*/

/**
\brief Initializes the PLCIPHER module.CNcomment:\B3\F5ʼ\BB\AFPLCIPHERģ\BF顣CNend
\attention \n
Before using PLCIPHERs, you must call this application programming interface (API).\n
Before using the ts level encryption function, you need to initialize the PLCIPHER module.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:\D4ڽ\F8\D0\D0PLCIPHER\CF\E0\B9ز\D9\D7\F7ǰӦ\B8\C3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA\n
\D4\DAʹ\D3\C3TS\BC\B6\BC\D3\C3ܹ\A6\C4\DCǰ\C7\EB\CC\E1ǰ\BD\F8\D0\D0PLCIPHERģ\BF\E9\B5ĳ\F5ʼ\BB\AF\n
\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڷ\B5\BBسɹ\A6\A1\A3CNend
\param  N/A.CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\see \n
N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_Init(HI_VOID);

/**
\brief Deinitializes the PLCIPHER module. CNcomment:ȥ\B3\F5ʼ\BB\AFPLCIPHERģ\BF顣CNend
\attention \n
After this API is called, the PLCIPHER module is stopped, and the PLCIPHER resources used by the process are released.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.
CNcomment:\B5\F7\D3ñ\BE\BDӿ\DAֹͣʹ\D3\C3PLCIPHERģ\BF飬\B2\A2\CAͷű\BE\BD\F8\B3\CC\CB\F9ռ\D3õ\C4PLCIPHER\D7\CAԴ\n
\B1\BE\BDӿڵ\DAһ\B4ε\F7\D3\C3\C6\F0\D7\F7\D3ã\AC\D6ظ\B4\B5\F7\D3÷\B5\BBسɹ\A6\A1\A3CNend
\param  N/A.CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_DeInit(HI_VOID);

/**
\brief Creates a PLCIPHER channel for encryption.CNcomment:\B4\B4\BD\A8һ·PLCIPHERͨ\B5\C0\A1\A3CNend
\param[out] phPLCipher     Pointer to the handle of a PLCIPHER.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\C9\EA\C7뵽\B5\C4PLCIPHER Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_FAILED_GETHANDLE There is no more PLCIPHER channel left. CNcomment:û\D3п\D5\CFе\C4PLCIPHERͨ\B5\C0\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_Create(HI_HANDLE *phPLCipher);

/**
\brief Destroys an existing PLCIPHER channel.CNcomment:\CF\FA\BB\D9һ·PLCIPHERͨ\B5\C0\A1\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel to be destroyed.CNcomment:\B4\FD\CF\FA\BBٵ\C4PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_Destroy(HI_HANDLE hPLCipher);

/**
\brief Gets the attributes of a PLCIPHER channel.CNcomment:\BB\F1ȡһ·PLCIPHERͨ\B5\C0\B5\C4\CA\F4\D0ԡ\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] pstAttr  Pointer to the attributes of a PLCIPHER channel.CNcomment:PLCIPHERͨ\B5\C0\CA\F4\D0\D4ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_GetAttr(HI_HANDLE hPLCipher, HI_UNF_PLCIPHER_ATTR_S *pstAttr);

/**
\brief Sets the attributes of a PLCIPHER channel.CNcomment:\C9\E8\D6\C3һ·PLCIPHERͨ\B5\C0\B5\C4\CA\F4\D0ԡ\A3CNend
\attention \n
plcipher will encrypt all pids in the ts when bPIDFilterEn is setted with HI_FALSE,\n
and plcipher will just encrypt the assigned pids when bPIDFilterEn is setted with HI_TRUE.
CNcomment:bPIDFilterEn ΪHI_FALSEʱplcipher\BD\AB\B6\D4TS\B0\FC\B5\C4\CB\F9\D3\D0PID\BD\F8\D0м\D3\C3ܣ\AC\B6\F8\B5\B1bPIDFilterEn ΪHI_TRUEʱplcipher\BD\F6\B6\D4ָ\B6\A8\B5\C4PID\CA\FD\BEݽ\F8\D0м\D3\C3ܡ\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] pstAttr  Pointer to the attributes of a PLCIPHER channel.CNcomment:PLCIPHERͨ\B5\C0\CA\F4\D0\D4ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PARA  The input attribute is invalid.CNcomment:\CA\E4\C8\EB\CA\F4\D0Խṹ\B3\C9Ա\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_SetAttr(HI_HANDLE hPLCipher, HI_UNF_PLCIPHER_ATTR_S *pstAttr);

/**
\brief Sets the CW keys of a PLCIPHER channel. This API is used to configure the PLCIPHER channel.CNcomment:\C5\E4\D6\C3PLCIPHERͨ\B5\C0\B5\C4\C3\DCԿ\A3\AC\B1\BE\BDӿ\DA\D3\C3\D3\DA\C5\E4\D6\C3PLCIPHERͨ\B5\C0\B5\C4\C3\DCԿ\A1\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] enKeyEvenOdd  Type of CW key odd or even.CNcomment:\B4\FD\C9\E8\D6\C3\C3\DCԿ\B5\C4\C6\E6ż\C0\E0\D0͡\A3CNend
\param[in] pu8Key  Pointer to odd or even CW key buffer to be set, always a 8 or 16 bytes array.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\BB\F2ż\C3\DCԿ\CA\FD\BEݣ\ACһ\B0\E38\BB\F216\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\param[in] u32KeyLen  The length of CW key data to be set, always 8 or 16.CNcomment:Ҫ\C9\E8\D6õ\C4\C3\DCԿ\CA\FD\BEݵĳ\A4\B6ȣ\ACһ\B0\E38\BB\F216\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PARA  The input attribute is invalid.CNcomment:\CA\E4\C8\EB\CA\F4\D0Խṹ\B3\C9Ա\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_SetKey(HI_HANDLE hPLCipher, HI_UNF_PLCIPHER_KEY_EVENODD_E enKeyEvenOdd, const HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Sets the IV vector of a PLCIPHER channel. This API is used to configure the PLCIPHER channel.CNcomment:\C5\E4\D6\C3PLCIPHERͨ\B5\C0\B5\C4IV\CF\F2\C1\BF\A3\AC\B1\BE\BDӿ\DA\D3\C3\D3\DA\C5\E4\D6\C3PLCIPHERͨ\B5\C0\B5\C4IV\CF\F2\C1\BF\A1\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] enIVEvenOdd  Type of IV vector odd or even.CNcomment:\B4\FD\C9\E8\D6\C3IV\CF\F2\C1\BF\B5\C4\C6\E6ż\C0\E0\D0͡\A3CNend
\param[in] pu8IV  Pointer to odd or even IV vector buffer to be set, always a 8 or 16 bytes array.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\BB\F2żIV\CF\F2\C1\BF\A3\ACһ\B0\E38\BB\F216\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\param[in] u32IVLen  The length of IV vector to be set, always 8 or 16.CNcomment:Ҫ\C9\E8\D6õ\C4IV\CF\F2\C1\BF\CA\FD\BEݵĳ\A4\B6ȣ\ACһ\B0\E38\BB\F216\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PARA  The input attribute is invalid.CNcomment:\CA\E4\C8\EB\CA\F4\D0Խṹ\B3\C9Ա\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/

HI_S32 HI_UNF_PLCIPHER_SetIV(HI_HANDLE hPLCipher, HI_UNF_PLCIPHER_KEY_EVENODD_E enIVEvenOdd, const HI_U8 *pu8IV, HI_U32 u32IVLen);

/**
\brief Encrypt TS package data in a PLCIPHER channel.CNcomment:ʹ\D3\C3PLCIPHERͨ\B5\C0\B6\D4TS\B0\FC\CA\FD\BEݽ\F8\D0\D0TS\BC\B6\BC\D3\C3ܡ\A3CNend
\attention \n
PLCIPHER support pSrcBuf and pDestBuf are the same address, in other word, PLCIPHER support encryption at the same adress.
CNcomment:PLCIPHER֧\B3\D6pSrcBuf\BA\CDpDestBuf\B5\C4ֵ\CF\E0ͬ\A3\AC\BB\BB\BE仰˵PLCIPHER֧\B3־͵ؼ\D3\C3ܡ\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] pSrcBuf  The physical address(must be 16 bytes align) of TS package data to be encrypted.CNcomment:VOIDָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\BC\D3\C3\DCTS\B0\FC\CA\FD\BEݵ\C4\C6\F0ʼ\CE\EF\C0\ED\B5\D8ַ\A3\AC\B1\D8\D0\EB16\D7ֽڶ\D4\C6롣CNend
\param[in] pDestBuf  The physical address(must be 16 bytes align) of the encryted TS package data.CNcomment:VOIDָ\D5\EB\C0\E0\D0ͣ\AC\BC\D3\C3\DC\CD\EA\B3ɺ\F3TS\B0\FC\CA\FD\BE\DD\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ\A3\AC\B1\D8\D0\EB16\D7ֽڶ\D4\C6롣CNend
\param[in] u32Length  The length of TS package data to be encrypted.CNcomment:\B4\FD\BC\D3\C3\DCTS\B0\FC\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PARA  The input attribute is invalid.CNcomment:\CA\E4\C8\EB\CA\F4\D0Խṹ\B3\C9Ա\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_Encrypt(HI_HANDLE hPLCipher, HI_VOID* pSrcBuf, HI_VOID* pDestBuf, HI_U32 u32Length);

/**
\brief Decrypt TS package data in a PLCIPHER channel.CNcomment:ʹ\D3\C3PLCIPHERͨ\B5\C0\B6\D4TS\B0\FC\CA\FD\BEݽ\F8\D0\D0TS\BC\B6\BD\E2\C3ܡ\A3CNend
\attention \n
PLCIPHER support pSrcBuf and pDestBuf are the same address, in other word, PLCIPHER support decryption at the same adress.
CNcomment:PLCIPHER֧\B3\D6pSrcBuf\BA\CDpDestBuf\B5\C4ֵ\CF\E0ͬ\A3\AC\BB\BB\BE仰˵PLCIPHER֧\B3־͵ؽ\E2\C3ܡ\A3CNend
\param[in] hPLCipher  Handle of PLCIPHER channel.CNcomment:PLCIPHER ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] pSrcBuf  The physical address(must be 16 bytes align) of TS package data to be decrypted.CNcomment:VOIDָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\BD\E2\C3\DCTS\B0\FC\CA\FD\BEݵ\C4\C6\F0ʼ\CE\EF\C0\ED\B5\D8ַ\A3\AC\B1\D8\D0\EB16\D7ֽڶ\D4\C6롣CNend
\param[in] pDestBuf  The physical address(must be 16 bytes align) of the decryted TS package data.CNcomment:VOIDָ\D5\EB\C0\E0\D0ͣ\AC\BD\E2\C3\DC\CD\EA\B3ɺ\F3TS\B0\FC\CA\FD\BE\DD\CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ\A3\AC\B1\D8\D0\EB16\D7ֽڶ\D4\C6롣CNend
\param[in] u32Length  The length of TS package data to be decrypted.CNcomment:\B4\FD\BD\E2\C3\DCTS\B0\FC\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_PLCIPHER_NOT_INIT  The PLCIPHER module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_HANDLE The input PLCIPHER handle is invalid. CNcomment:\CA\E4\C8\EBPLCIPHER\BE\E4\B1\FA\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_PLCIPHER_INVALID_PARA  The input attribute is invalid.CNcomment:\CA\E4\C8\EB\CA\F4\D0Խṹ\B3\C9Ա\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_PLCIPHER_Decrypt(HI_HANDLE hPLCipher, HI_VOID* pSrcBuf, HI_VOID* pDestBuf, HI_U32 u32Length);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_PAYLOADCIPHER_H__ */
