#ifndef __HI_UNF_HDCP_H__
#define __HI_UNF_HDCP_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      HDCP */
/** @{ */  /** <!-- [HDCP] */

typedef struct hiUNF_DECRYPT_HDCP_S
{
	HI_U8 u8KSV[5];                         /**< HDCP KSV:40bits, Orignal data */
	HI_U8 u8PrivateKey[280];                /**< HDCP Device Private key:40*56bits, Orignal data */
}HI_UNF_HDCP_DECRYPT_S;

/** Encrypted HDCP key */
/** CNcomment:\BC\D3\C3ܵ\C4HDCP key */
typedef struct hiUNF_ENCRYPT_HDCP_S
{
	HI_U8 u8EncryptKey[384];
}HI_UNF_HDCP_ENCRYPT_S;

typedef struct hiUNF_HDCPKEY_HDCP_S
{
    HI_BOOL bIsUseHdcpRootKey;            /**< This parameter is used to select the key(key in otp or a fixed key by hisilicon). */   /**< CNcomment: \CAǷ\F1ʹ\D3\C3OTP/EFUSE\D6\D0\C9\D5д\B5\C4HdcpRootKey\BC\D3\C3\DCHDCP key. CNend*/
    HI_U8  u8ToolAesKey[16];                 /**< The AES Key used by tool to encrypt the original hdcp key. */   /**< CNcomment: HDCP\B9\A4\BE߼\D3\C3\DCԭʼHDCP Keyʱʹ\D3õ\C4AES\C3\DCԿ\A3\AC\B8ýӿڽ\AB\CF\C8ʹ\D3\C3\D5\E2\B8\F6\C3\DCԿ\BD\E2\C3\DC\D4\D9ʹ\D3\C3Ӳ\BC\FE\C3\DCԿ\BC\D3\C3\DC. CNend*/
    HI_U8  u8ToolAesIV[16];                 /**< The AES IV used by tool to encrypt the original hdcp key. */   /**< CNcomment: HDCP\B9\A4\BE߼\D3\C3\DCԭʼHDCP Keyʱʹ\D3õ\C4AES\B3\F5ʼ\CF\F2\C1\BF\A3\AC\B8ýӿڽ\AB\CF\C8ʹ\D3\C3\D5\E2\B8\F6\C3\DCԿ\BD\E2\C3\DC\D4\D9ʹ\D3\C3Ӳ\BC\FE\C3\DCԿ\BC\D3\C3\DC. CNend*/
    HI_BOOL EncryptionFlag;               /**< HI_TRUE:Encryption, HI_FALSE: Unencryption */    /**< CNcomment: HI_TRUE: \CA\E4\C8\EB\B5\C4\CAǼ\D3\C3ܺ\F3\B5\C4ԭʼHDCP Key, HI_FALSE:\CA\E4\C8\EB\B5\C4\CA\C7\C3\F7\CE\C4ԭʼHDCP Key. CNend*/
    union
    {
        HI_UNF_HDCP_DECRYPT_S DecryptData;
        HI_UNF_HDCP_ENCRYPT_S EncryptData;
    }key;									/**< Key = DecryptData,if EncryptionFlag == HI_FALSE.if EncryptionFlag == HI_TRUE,key = Encrpytiondata */
    HI_U32 Reserved;                        /**< Reserved for future use */
}HI_UNF_HDCP_HDCPKEY_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      HDCP */
/** @{ */  /** <!-- [HDCP] */


/**
\brief Encrypt HDCP key. HDCP key is encrypted using hdcp root key in otp when bIsUseOTPRootKey equals 'HI_TRUE' or using key defined by hisilicon when bIsUseOTPRootKey equals 'HI_FALSE'.
\n Additional descryption:Only the 'HDMIIP_HDCPKey' is encrypted. The HDCP key format shows belows:
\n        head                HDMIIP_HDCPKey               CRC32_0 CRC32_1
\n		|-------|-----------------------------------------|------|------|
\n
\brief CNcomment: \BC\D3\C3ܿͻ\A7\C9\E8\D6õ\C4HDCP key\A1\A3ͨ\B9\FD bIsUseOTPRootKey ѡ\D4\F1\CAǷ\F1ʹ\D3\C3OTP\C4ڲ\BF\B5\C4RootKey\BC\D3\C3\DC\CA\FD\BEݻ\B9\CA\C7ʹ\D3ú\A3˼\B9̶\A8\B5\C4key\BC\D3\C3\DC\CA\FD\BEݡ\A3 CNend
\attention \n The encrypted data(u8OutEncryptKey) include two CRC32 values.CRC32_1 is used to verify the integration of the whole data, and CRC32_0 is used to debug.  CNcomment: \BC\D3\C3ܵ\C4\CA\FD\BE\DDu8OutEncryptKey\B0\FC\BA\AC2\B4\CECRCУ\D1\E9ֵ\A3\ACCRC32_1 \D3\C3\D3\DA\CA\FD\BE\DD\CD\EA\D5\FB\D0\D4\C5жϣ\ACCRC32_0\D3\C3\D3ڵ\F7\CA\D4ʹ\D3á\A3 CNend
\param[in] :pstHdcpKey.This parameter is used to define hdcp key in encrypted mode or clear mode.  CNcomment: \B8ò\CE\CA\FDΪHDCP key\B5Ĳ\CE\CA\FD\B6\A8\D2\E5,\B0\FC\BA\AC\BC\D3\C3\DC/\B7Ǽ\D3\C3ܵķ\BDʽ. CNend
\param[out]:pu8OutEncryptKey. Output the encrypted hdcp key.   CNcomment: \CA\E4\B3\F6\B5ļ\D3\C3ܺ\F3\B5\C4HDCP KEY\B2\CE\CA\FD\A1\A3 CNend
\param[in] :u32OutEncryptKeyBufLength. The buffer length of pu8OutEncryptKey.  CNcomment: pu8OutEncryptKeyָ\CF\F2\B5Ļ\BA\B3\E5\C7\F8\B4\F3С. CNend
\param[out]:pu32OutEncryptKeyLength. The length of data that write to pu8OutEncryptKey.   CNcomment: д\B5\BD\BB\BA\B3\E5\C7\F8pu8OutEncryptKey\D6е\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\retval HI_SUCCESS  Call this API succussful.  	CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval HI_FAILURE  Call this API fails.  		CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
*/
HI_S32  HI_UNF_HDCP_EncryptHDCPKey(HI_UNF_HDCP_HDCPKEY_S *pstHdcpKey,
                                   HI_U8 *pu8OutEncryptKey,
                                   HI_U32 u32OutEncryptKeyBufLength,
                                   HI_U32 *pu32OutEncryptKeyLength);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_HDCP_H__ */
