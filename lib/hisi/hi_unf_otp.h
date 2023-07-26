/******************************************************************************

  Copyright (C), 2016, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_otp.h
  Version       : Initial Draft
  Author        : Hisilicon otp software group
  Created       : 2016/10/9
  Description   :
*******************************************************************************/
/**
 * \file
 * \brief Describes the information about the otp module.
          CNcomment:\CCṩ OTP ģ\BF\E9\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */
#ifndef __HI_UNF_OTP_H__
#define __HI_UNF_OTP_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      OTP */
/** @{ */  /** <!-- [OTP] */

/** CA VendorID */
typedef enum {
    HI_UNF_OTP_VENDORID_COMMON     = 0x00,        /**<No-Advcance CA chipset, Marked with 0*/
    HI_UNF_OTP_VENDORID_NAGRA      = 0x01,        /**<NAGRA  Chipse, Marked with R*/
    HI_UNF_OTP_VENDORID_IRDETO     = 0x02,        /**<IRDETO Chipset, Marked with I*/
    HI_UNF_OTP_VENDORID_CONAX      = 0x03,        /**<CONAX Chipset, Marked with C*/
    HI_UNF_OTP_VENDORID_NDS        = 0x04,        /**<NDS Chipset*/
    HI_UNF_OTP_VENDORID_SUMA       = 0x05,        /**<SUMA Chipset, Marked with S*/
    HI_UNF_OTP_VENDORID_NOVEL      = 0x06,        /**<NOVEL Chipset, Marked with Y*/
    HI_UNF_OTP_VENDORID_VERIMATRIX = 0x07,        /**<VERIMATRIX Chipset, Marked with M*/
    HI_UNF_OTP_VENDORID_CTI        = 0x08,        /**<CTI Chipset, Marked with T*/
    HI_UNF_OTP_VENDORID_SAFEVIEW   = 0x09,        /**<SAFEVIEW CA Chipset*/
    HI_UNF_OTP_VENDORID_LATENSE    = 0x0a,        /**<LATENSE CA Chipset*/
    HI_UNF_OTP_VENDORID_SH_TELECOM = 0x0b,        /**<SH_TELECOM CA Chipset*/
    HI_UNF_OTP_VENDORID_DCAS       = 0x0c,        /**<DCAS CA Chipset*/
    HI_UNF_OTP_VENDORID_VIACCESS   = 0x0d,        /**<VIACCESS CA Chipset*/
    HI_UNF_OTP_VENDORID_BUTT
} HI_UNF_OTP_VENDORID_E;

/** FLASH device types*/
typedef enum {
    HI_UNF_OTP_FLASH_TYPE_SPI     = 0,    /**<SPI flash*/
    HI_UNF_OTP_FLASH_TYPE_NAND,           /**<nand flash*/
    HI_UNF_OTP_FLASH_TYPE_NOR,            /**<nor flash*/
    HI_UNF_OTP_FLASH_TYPE_EMMC,           /**<eMMC*/
    HI_UNF_OTP_FLASH_TYPE_SPI_NAND,       /**<spi_nand flash*/
    HI_UNF_OTP_FLASH_TYPE_SD,             /**<FSD/TSD flash*/
    HI_UNF_OTP_FLASH_TYPE_BUTT
} HI_UNF_OTP_FLASH_TYPE_E;

/** JTAG protect mode*/
typedef enum {
    HI_UNF_OTP_JTAG_MODE_OPEN     = 0,
    HI_UNF_OTP_JTAG_MODE_PROTECT,
    HI_UNF_OTP_JTAG_MODE_CLOSED,
    HI_UNF_OTP_JTAG_MODE_BUTT
} HI_UNF_OTP_JTAG_MODE_E;

/** Rootkey type*/
typedef enum {
    HI_UNF_OTP_OEM_ROOTKEY        = 0,
    HI_UNF_OTP_HDCP_ROOTKEY,
    HI_UNF_OTP_STB_ROOTKEY,
    HI_UNF_OTP_SW_ROOTKEY,
    HI_UNF_OTP_STBTA_ROOTKEY,
    HI_UNF_OTP_ROOTKEY_BUTT
} HI_UNF_OTP_ROOTKEY_E;

/** TA MSID(Trusted Application Market Segment ID) */
typedef enum {
    HI_UNF_OTP_TA_INDEX_1 = 0,
    HI_UNF_OTP_TA_INDEX_2,
    HI_UNF_OTP_TA_INDEX_3,
    HI_UNF_OTP_TA_INDEX_4,
    HI_UNF_OTP_TA_INDEX_5,
    HI_UNF_OTP_TA_INDEX_6,
    HI_UNF_OTP_TA_INDEX_BUTT
} HI_UNF_OTP_TA_INDEX_E;

#define OTP_FIELD_VALUE_MAX_LEN 1024
#define OTP_FIELD_NAME_MAX_LEN 32
typedef struct {
    HI_BOOL bBurn;
    HI_CHAR aszFieldName[OTP_FIELD_NAME_MAX_LEN]; //32
    HI_U32 u32ValueLen;
    HI_U8 au8Value[OTP_FIELD_VALUE_MAX_LEN]; //4
    HI_BOOL bLock;
} HI_UNF_OTP_BURN_PV_ITEM_S;

/** UART type
ChipSet: HI3796MV200/HI3716MV450
UART0:For REE CPU, TEE CPU and LPMCU.
UART1:Reserved.
UART2:Reserved.
UART3:Only for SMCU

ChipSet: HI3716MV430
UART0:For REE CPU,SMCU.
UART1:Reserved.
UART2:SECURE CPU.
UART3:Reserved
*/
typedef enum {
    HI_UNF_OTP_UART0 = 0,
    HI_UNF_OTP_UART1,
    HI_UNF_OTP_UART2,
    HI_UNF_OTP_UART3,
    HI_UNF_OTP_BUTT,
} HI_UNF_OTP_UART_TYPE_E;
/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API declaration *****************************/
/** \addtogroup      OTP */
/** @{ */  /** <!-- [OTP] */

#define HI_UNF_OTP_Open(HI_VOID) HI_UNF_OTP_Init(HI_VOID)
#define HI_UNF_OTP_Close(HI_VOID) HI_UNF_OTP_DeInit(HI_VOID)

/**
\brief Initializes the otp module. CNcomment:\B3\F5ʼ\BB\AFOTPģ\BF\E9 CNend
\attention \n
Before calling other functions in this file, you must call this application programming interface (API).
CNcomment \D4ڵ\F7\D3\C3OTPģ\BF\E9\C6\E4\CB\FB\BDӿ\DAǰ\A3\ACҪ\C7\F3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA CNend
\param N/A
\retval ::HI_SUCCESS  Success.   CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_Init(HI_VOID);

/**
\brief Deinitializes the otp module. CNcomment:ȥ\B3\F5ʼ\BB\AFOTP\C9豸 CNend
\attention \n
N/A
\param N/A                                        CNcomment:\CEޡ\A3 CNend
\retval ::HI_SUCCESS  Success.   CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_DeInit(HI_VOID);


/**
\brief Set customer key, the customer key is used by the customer to encrypt some private data.
\brief CNcomment:\C9\E8\D6\C3customer key\A3\ACcustomer key\D3ɿͻ\A7\D7Լ\BA\B6\A8\D2壬\C7\D2\D7Զ\A8\D2\E5\D3\C3;\A1\A3 CNend
\attention \n
N/A
\param[in] pKey:  Customer key to be written to otp.                    CNcomment:Customer key\B5\C4ֵ\A3\AC\B4\FDд\C8\EBOTP\A1\A3 CNend
\param[in] u32KeyLen:  The length of customer key, must be 16bytes.     CNcomment:Customer key\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪ16\D7ֽڡ\A3           CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetCustomerKey(HI_U8 *pKey, HI_U32 u32KeyLen);

/**
\brief Get customer key, the customer key is used by the customer to encrypt some private data.
\brief CNcomment:\BB\F1ȡcustomer key\A1\A3 CNend
\attention \n
N/A
\param[in] pKey:Buffer to store the customer key read from otp.     CNcomment:\B4洢customer key\B5\C4buffer\A1\A3 CNend
\param[in] u32KeyLen:The length of buffer, must be 16bytes.             CNcomment:customer key \B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪ16\D7ֽڡ\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetCustomerKey(HI_U8 *pKey, HI_U32 u32KeyLen);


/**
\brief Set stb private data, the stb private data is used by the customer to set some private data.
\brief CNcomment:\C9\E8\D6ÿͻ\A7˽\D3\D0\CA\FD\BEݡ\A3 CNend
\attention \n
N/A
\param[in] u32Offset:  The offset to set the private data, should be between 0 and 15.  CNcomment:\C9\E8\D6\C3stbprivData\B5\C4ƫ\D2ƣ\AC\B1\D8\D0\EBΪ0~15֮\BC䡣 CNend
\param[in] u8Data:  The private data to be set.                         CNcomment:\D0\E8Ҫ\C9\E8\D6õ\C4ֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetStbPrivData(HI_U32 u32Offset, HI_U8 u8Data);

/**
\brief Get stb private data, the stb private data is used by the customer to set some private data.
\brief CNcomment:\BB\F1ȡ\BFͻ\A7˽\D3\D0\CA\FD\BEݡ\A3 CNend
\attention \n
N/A
\param[in] u32Offset:  The offset to get the private data, should be between 0 and 15.  CNcomment:\BB\F1ȡstbprivData\B5\C4ƫ\D2ƣ\AC\B1\D8\D0\EBΪ0~15֮\BC䡣 CNend
\param[out] pu8Data:  The data read from otp.                           CNcomment:\BB\F1ȡ\B5\C4ֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetStbPrivData(HI_U32 u32Offset, HI_U8 *pu8Data);

/**
\brief burn chipset to normal chipset CNcomment:\BD\ABоƬ\C9\D5д\B3\C9\C6\D5ͨоƬ CNend
\attention \n
N/A
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_BurnToNormalChipset(HI_VOID);

/**
\brief Burn nomal chipset to secure chipset
\brief CNcomment:\BD\AB\C6\D5ͨоƬ\C9\D5д\B3ɰ\B2ȫоƬ\A1\A3 CNend
\attention \n
N/A
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_BurnToSecureChipset(HI_VOID);

/**
\brief Get idword lock status CNcomment:\BB\F1ȡоƬ\C4ڲ\BFIDWord\CB\F8\B6\A8\B1\EA־λ״̬ CNend
\attention \n
N/A
\param[out] pbLockFlag:  Point to IDWord lock status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CB\F8״̬\D0\C5Ϣ CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetIDWordLockFlag(HI_BOOL *pbLockFlag);
/**
\brief  Set hdcp root key to otp, 16bytes length.
\brief CNcomment:\CF\F2оƬ\C4ڲ\BFд\C8\EBhdcp root key\A3\AC\B1\D8\D0\EBΪ16\D7ֽڳ\A4\A1\A3 CNend
\attention \n
N/A
\param[in] pu8RootKey:  Set hdcp root key to otp.                   CNcomment\C9\E8\D6\C3hdcp root key\B5\BDOTP\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_WriteHdcpRootKey(HI_U8 *pu8HdcpRootKey, HI_U32 u32Keylen);

/**
\brief  Get hdcp root key from otp, 16bytes length.
\brief CNcomment:\B6\C1ȡоƬ\C4ڲ\BF\C9\E8\D6õ\C4hdcp root key\A3\AC\B1\D8\D0\EBΪ16\D7ֽڳ\A4\A1\A3 CNend
\attention \n
N/A
\param[out] pu8RootKey:  Point to hdcp root key from otp.               CNcomment:\B4\D3OTP\D6л\F1ȡhdcp root key\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_ReadHdcpRootKey(HI_U8 *pu8HdcpRootKey, HI_U32 u32Keylen);

/**
\brief  Lock hdcp root key in otp.
\brief CNcomment:\CB\F8\B6\A8оƬ\C4ڲ\BF\C9\E8\D6õ\C4hdcp root key\A1\A3\CB\F8\B6\A8\BA\F3\A3\AChdcp root key\BD\AB\B2\BB\BFɱ\BB\B6\C1ȡ\A1\A3 CNend
\attention \n
N/A
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_LockHdcpRootKey(HI_VOID);

/**
\brief  Get hdcp root Key lock flag.
\brief CNcomment:\B6\C1ȡоƬ\C4ڲ\BF\C9\E8\D6õ\C4hdcp root key\B5\C4\CB\F8\B6\A8\B1\EA־λ\A1\A3 CNend
\attention \n
N/A
\param[out] pbLockFlag:  Point to hdcp root key lock flag from otp.     CNcomment:ָ\CF\F2\BB\F1ȡ\B5\BD\B5ı\EA־λ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetHdcpRootKeyLockFlag(HI_BOOL *pbLock);

/**
\brief Set stb root key to otp.
\brief CNcomment:\CF\F2оƬ\C4ڲ\BF\C9\E8\D6\C3stb root key\A1\A3 CNend
\attention \n
N/A
\param[in] u8StbRootKey:  Point to stb root key value.                  CNcomment:Stb root key\B5\C4ֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_WriteStbRootKey(HI_U8 *pu8StbRootKey, HI_U32 u32Keylen);

/**
\brief Get stb root key from otp.
\brief CNcomment:\B6\C1ȡоƬ\C4ڲ\BF\C9\E8\D6õ\C4stb root key\A1\A3 CNend
\attention \n
N/A
\param[out] pu8RootKey:  Point to stb root key from otp.                CNcomment:ֻ\CF\EB\BB\F1ȡ\B5\BD\B5\C4Stb root key\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_ReadStbRootKey(HI_U8 *pu8StbRootKey, HI_U32 u32Keylen);

/**
\brief Lock stb root key in otp.
\brief CNcomment:\CB\F8סоƬ\C4ڲ\BF\C9\E8\D6õ\C4stb root key\A1\A3\CB\F8\B6\A8\BA\F3\A3\ACstb root key\BD\AB\B2\BB\BFɱ\BB\B6\C1ȡ\A1\A3 CNend
\attention \n
N/A
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_LockStbRootKey(HI_VOID);

/**
\brief Get stb root Key lock flag
\brief CNcomment:\BB\F1ȡоƬ\C4ڲ\BFstb root key\B5\C4\CB\F8\B6\A8\B1\EA־λ\A1\A3 CNend
\attention \n
N/A
\param[out] pbLockFlag:  Point to stb root key lock flag from otp.      CNcomment:ָ\CF\F2\BB\F1ȡ\B5\BD\B5ı\EA־λ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                     CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                          CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetStbRootKeyLockFlag(HI_BOOL *pbLockFlag);


/**
\brief Get CA Vendor ID. CNcomment:\BB\F1ȡ\B8߰\B2\B3\A7\C9̱\EAʶ CNend
\attention \n
N/A
\param[out] penVendorID:  CA VendorID. CNcomment:\B8߰\B2\B3\A7\C9̱\EAʶ CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetVendorID(HI_UNF_OTP_VENDORID_E *penVendorID);

/**
\brief Get the serial number of the STB. CNcomment:\BB\F1ȡ\BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8StbSn serial number of the STB. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\param[in/out] pu32Len point to the length of serial number of the STB, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\FA\B6\A5\BA\D0\D0\F2\C1кų\A4\B6ȣ\AC\B5\B1ǰ\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetStbSN(HI_U8 *pu8StbSN, HI_U32 *pu32Len);

/**
\brief Set the serial number of the STB. CNcomment:\C9\E8\D6û\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\attention \n
The serial number of the STB is set before delivery. The serial number can be set once only and takes effects after the STB restarts.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4Σ\AC\C9\E8\D6ú\F3\D6\D8\C6\F4\C9\FAЧ CNend
\param[in] pu8StbSn point to serial number of the STB. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\param[in] u32Len The length of serial number of the STB, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\FA\B6\A5\BA\D0\D0\F2\C1кų\A4\B6ȣ\AC\B5\B1ǰ\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_SETPARAM_AGAIN The parameter has been set already. CNcomment:\D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetStbSN(HI_U8 *pu8StbSN, HI_U32 u32Len);

/**
\brief set the type of flash memory for security startup. CNcomment:ָ\B6\A8\B0\B2ȫ\C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\attention N/A
\param[in]  enFlashType Type of the flash memory for security startup. CNcomment: \C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_SETPARAM_AGAIN The parameter has been set already. CNcomment:\D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetBootMode(HI_UNF_OTP_FLASH_TYPE_E enFlashType);


/**
\brief Disables the self-boot. CNcomment:\B9ر\D5\D7Ծٹ\A6\C4\DC, boot\CF²\BB\C4\DCʹ\D3ô\AE\BF\DA/\CD\F8\BF\DA\C9\FD\BC\B6 CNend
\attention \n
The setting is performed before delivery and can be performed once only.
The self-boot function is enabled by default.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4Σ\ACĬ\C8\CFʹ\C4\DCSelfBoot\B9\A6\C4\DC CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_DisableSelfBoot(HI_VOID);

/**
\brief Get the self-boot status. CNcomment:\BB\F1ȡ\D7Ծ\D9״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbDisable Pointer to the self-boot status, true means DISABLE. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D7Ծ\D9״̬\A3\ACtrue\B1\EDʾ\BD\FB\D3\C3\D7Ծٹ\A6\C4\DC CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetSelfBootStat(HI_BOOL *pbDisable);


/**
\brief Force decrypt the BootLoader. CNcomment:\C9\E8\D6ñ\D8\D0\EB\B6\D4BootLoader\BD\F8\D0н\E2\C3\DC CNend
\attention \n
The setting is performed before delivery and can be performed once only.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8ϸ\F9\BE\DDFlash\D6е\C4\CA\FD\BEݱ\EAʶ\A3\AC\BE\F6\B6\A8BootLoader\CAǷ\F1\D0\E8Ҫ\BD\E2\C3\DC CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_EnableBootDecrypt(HI_VOID);


/**
\brief Get the BootLoader Decryption status. CNcomment:\BB\F1ȡBootLoader\BD\E2\C3\DC״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Point to bootLoader Decryption status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACBootloader\BD\E2\C3ܱ\EA־λ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetBootDecryptStat(HI_BOOL *pbEnable);


/**
\brief Enable the security startup. This API should be used after the API HI_UNF_OTP_SetBootMode.
CNcomment:\C9\E8\D6ð\B2ȫ\C6\F4\B6\AFʹ\C4ܣ\AC\B8ýӿڱ\D8\D0\EB\BA\CDHI_UNF_OTP_COMMON_SetBootMode\C5\E4\CC\D7ʹ\D3\C3 CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_EnableSCS(HI_VOID);


/**
\brief Get the security startup status function. CNcomment:\BB\F1ȡ\B0\B2ȫ\C6\F4\B6\AFʹ\C4ܱ\EA\BC\C7 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Point to bootLoader SCS status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫ\C6\F4\B6\AFʹ\C4ܱ\EA־λ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetSCSStat(HI_BOOL *pbEnable);


/**
\brief Enable the Trust Zone. CNcomment:\C9\E8\D6\C3Trust Zoneʹ\C4\DCCNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_EnableTrustZone(HI_VOID);


/**
\brief Get the Trust Zone status.
CNcomment:\BB\F1ȡTrustZoneʹ\C4ܱ\EA\BC\C7 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Point to trust zone status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫ\C7\F8\D3\F2ʹ\C4ܱ\EA־λ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetTrustZoneStat(HI_BOOL *pbEnable);


/**
\brief Get the market segment identifier. CNcomment:\BB\F1ȡ\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8MSID Point to MSID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in/out] pu32Len Point to MSID length, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetMSId
*/
HI_S32 HI_UNF_OTP_GetMSID(HI_U8 *pu8MSID, HI_U32 *pu32Len);


/**
\brief Set the market segment identifier CNcomment:\C9\E8\D6\C3\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pu8MSID Point to MSID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in/out] u32MSIdLen MSID length, current is 4. CNcomment:\CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetMSID(HI_U8 *pu8MSID, HI_U32 u32Len);


/**
\brief Get the secure os market segment identifier CNcomment:\BB\F1ȡ\B0\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8SOSMSID Point to SOS MSID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in/out] pu32Len Point to SOS MSID length, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetMSId
*/
HI_S32 HI_UNF_OTP_GetSOSMSID(HI_U8 *pu8SOSMSID, HI_U32 *pu32Len);


/**
\brief Sets the sos market segment identifier CNcomment:\C9\E8\D6ð\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pu8SOSMSID Point to SOSMSID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in] u32Len MSID length, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B0\B2ȫOS\CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetSOSMSID(HI_U8 *pu8SOSMSID, HI_U32 u32Len);

/**
\brief Sets the LongData segment identifier CNcomment:\C9\E8\D6\C3LongData  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] u32Offset CNcomment: \B5\D8ַƫ\D2\C616\D7ֽڶ\D4\C6\EB CNend
\param[in] pu8Value CNcomment: otp\CA\FD\BE\DD\CA\FD\D7\E9  CNend
\param[in] u32Length CNcomment: otp\CA\FD\BE\DD\CA\FD\D7鳤\B6\C8,\B2\BB\D3\C316\D7ֽڶ\D4\C6\EB  CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetLongData(HI_CHAR *pFuseName, HI_U32 u32Offset, HI_U8 *pu8Value, HI_U32 u32Length);

/**
\brief Sets the LongData segment identifier CNcomment:\C9\E8\D6\C3LongData  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] u32Offset CNcomment: \B5\D8ַƫ\D2\C616\D7ֽڶ\D4\C6\EB CNend
\param[out] pu8Value CNcomment: \BD\D3\CA\DCotp\CA\FD\BE\DD\CA\FD\D7\E9  CNend
\param[in] u32Length CNcomment: otp\CA\FD\BE\DD\CA\FD\D7鳤\B6\C8,\B2\BB\D3\C316\D7ֽڶ\D4\C6\EB  CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetLongData(HI_CHAR *pFuseName, HI_U32 u32Offset, HI_U8 *pu8Value, HI_U32 u32Length);

/**
\brief Sets the LongData segment identifier CNcomment:\C9\E8\D6\C3LongData\B5\C4\CB\F8  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] u32Offset CNcomment: \B5\D8ַƫ\D2\C6,16\D7ֽڶ\D4\C6\EB CNend
\param[in] u32Length CNcomment: otp\CA\FD\BE\DD\CA\FD\D7鳤\B6\C8,16\D7ֽڶ\D4\C6\EB  CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetLongDataLock(HI_CHAR *pFuseName, HI_U32 u32Offset, HI_U32 u32Length);

/**
\brief Sets the LongData segment identifier CNcomment:\BB\F1\B5\C3LongData\B5\C4\CB\F8 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] u32Offset CNcomment: \B5\D8ַƫ\D2\C6,16\D7ֽڶ\D4\C6\EB CNend
\param[in] u32Length CNcomment: otp\CA\FD\BE\DD\CA\FD\D7鳤\B6\C8,16\D7ֽڶ\D4\C6\EB  CNend
\param[out] pu32Lock CNcomment: \B7\B5\BB\D80ȫû\CB\F8,\B7\B5\BB\D81ȫ\CB\F8,\B7\B5\BB\D82\B2\BF\B7ֱ\BB\CB\F8  CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetLongDataLock(HI_CHAR *pFuseName, HI_U32 u32Offset, HI_U32 u32Length,  HI_U32 *pu32Lock);

/**
\brief disable wake up from ddr. CNcomment:\B9ر\D5ԭ\B5ػ\BD\D0\D1ģʽ CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_DisableDDRWakeup(HI_VOID);


/**
\brief Get wake up from ddr status. CNcomment:\BB\F1ȡԭ\B5ػ\BD\D0\D1״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbDisable Point to DDR WakeUp status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACԭ\B5ػ\BD\D0\D1ʹ\C4\DC״̬ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetDDRWakeupStat(HI_BOOL *pbDisable);

/**
\brief Lock the whole OTP area. CNcomment:\CB\F8\B6\A8\D5\FB\B8\F6OTP\C7\F8\D3\F2 CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_LockGlobalOTP(HI_VOID);



/**
\brief Get global otp lock status function. CNcomment:\BB\F1ȡOTP\CB\F8״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out]  pbEnable Point to global OTP lock status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACOTP\CB\F8\B6\A8״̬ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetGlobalOTPLockStat(HI_BOOL *pbEnable);


/**
\brief Enable runtime-check. CNcomment:\C9\E8\D6\C3\D4\CB\D0\D0ʱУ\D1鹦\C4\DCʹ\C4\DC CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in]  None
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_EnableRuntimeCheck(HI_VOID);


/**
\brief Get runtime-check status CNcomment:\BB\F1ȡ\D4\CB\D0\D0ʱУ\D1\E9״̬ʹ\C4ܱ\EA\BC\C7  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Point to runtime Check status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D4\CB\D0\D0ʱУ\D1\E9ʹ\C4\DC״̬ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetRuntimeCheckStat(HI_BOOL *pbEnable);

/**
\brief Disable DDR wakeup check. CNcomment:\B9رմ\FD\BB\FA\BB\BD\D0\D1У\D1顣CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_DisableDDRWakeupCheck(HI_VOID);


/**
\brief Get ddr wakeup check status. CNcomment:\BB\F1ȡ\B4\FD\BB\FA\BB\BD\D0\D1У\D1\E9ʹ\C4ܱ\EA\BC\C7  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Point to DDR Wakeup Check status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\BB\FA\BB\BD\D0\D1У\D1\E9ʹ\C4\DC״̬ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetDDRWakeupCheckStat(HI_BOOL *pbEnable);


/**
\brief Enable ddr scramble. CNcomment:\C9\E8\D6\C3\C4ڴ\E6\BC\D3\C8Ź\A6\C4\DC CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_EnableDDRScramble(HI_VOID);


/**
\brief Get ddr scramble status CNcomment:\BB\F1ȡ\C4ڴ\E6\BC\D3\C8\C5ʹ\C4ܱ\EA\BC\C7  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable Pointer to DDR Scramble Stat. CNcomment:ָ\CF\F2\C4ڴ\E6\BC\D3\C8\C5ʹ\C4ܱ\EA\BC\C7ֵ\B5\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetDDRScrambleStat(HI_BOOL *pbEnable);


/**
\brief Get the mode of the JTAG. CNcomment:\BB\F1ȡJTAG\B5\F7\CAԽӿ\DAģʽ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penJtagMode Point to the mode of the JTAG. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACJTAG\B5\F7\CAԽӿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_OTP_GetJtagMode(HI_UNF_OTP_JTAG_MODE_E *penJtagMode);


/**
\brief Set the mode of the JTAG. CNcomment:\C9\E8\D6\C3JTAG\B5\F7\CAԽӿ\DAģʽ CNend
\attention \n
If the mode of the JTAG interface is set to closed or password-protected, it cannot be opened.
If the JTAG interface is open, it can be closed or password-protected.
If the JATG interface is password-protected, it can be closed.
After being closed, the JATG interface cannot be set to open or password-protected mode.
CNcomment:\B2\BB֧\B3\D6\C9\E8\D6\C3Ϊ\B4\F2\BF\AA״̬\A1\A3\n
\B4򿪵\C4ʱ\BA\F2\BF\C9\D2Թرջ\F2\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬\A1\A3\n
\B4\A6\D3\DA\C3\DCԿ\B1\A3\BB\A4״̬ʱ\BF\C9\D2Թرա\A3\n
\B9ر\D5֮\BA\F3\B2\BB\C4ܴ򿪺\CD\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬ CNend
\param[in] enJtagMode Mode of the JTAG. CNcomment:JTAG\B5\F7\CAԽӿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_OTP_SetJtagMode(HI_UNF_OTP_JTAG_MODE_E enJtagMode);


/**
\brief Get the mode of the TEE JTAG. CNcomment:\BB\F1ȡ TEE JTAG\B5\F7\CAԽӿ\DAģʽ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penJtagMode Point to the mode of the JTAG. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACJTAG\B5\F7\CAԽӿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_OTP_GetTEEJtagMode(HI_UNF_OTP_JTAG_MODE_E *penJtagMode);


/**
\brief Set the mode of the TEE JTAG. CNcomment:\C9\E8\D6\C3 TEE JTAG\B5\F7\CAԽӿ\DAģʽ CNend
\attention \n
If the mode of the JTAG interface is set to closed or password-protected, it cannot be opened.
If the JTAG interface is open, it can be closed or password-protected.
If the JATG interface is password-protected, it can be closed.
After being closed, the JATG interface cannot be set to open or password-protected mode.
CNcomment:\B2\BB֧\B3\D6\C9\E8\D6\C3Ϊ\B4\F2\BF\AA״̬\A1\A3\n
\B4򿪵\C4ʱ\BA\F2\BF\C9\D2Թرջ\F2\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬\A1\A3\n
\B4\A6\D3\DA\C3\DCԿ\B1\A3\BB\A4״̬ʱ\BF\C9\D2Թرա\A3\n
\B9ر\D5֮\BA\F3\B2\BB\C4ܴ򿪺\CD\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬ CNend
\param[in] enJtagMode Mode of the JTAG. CNcomment:JTAG\B5\F7\CAԽӿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_OTP_SetTEEJtagMode(HI_UNF_OTP_JTAG_MODE_E enJtagMode);


/**
\brief Get the boot version identifier CNcomment:\BB\F1ȡboot\B0汾\BA\C5  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8VersionID Point to version ID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACboot\B0汾\BA\C5 CNend
\param[in/out] pu32VersionIdLen Point to the length of version ID, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACboot\B0汾\BAų\A4\B6ȣ\AC\B5\B1ǰΪ4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetMSId
*/
HI_S32 HI_UNF_OTP_GetBootVersionID(HI_U8 *pu8VersionID, HI_U32 *pu32Len);


/**
\brief Sets the boot version identifier CNcomment:\C9\E8\D6\C3boot\B0汾\BA\C5  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pu8VersionID Point to version ID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACboot\B0汾\BA\C5 CNend
\param[in] u32Len The length of version ID, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACboot\B0汾\BAų\A4\B6ȣ\AC\B5\B1ǰΪ4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetBootVersionID(HI_U8 *pu8VersionID, HI_U32 u32Len);


/**
\brief Set root key to otp. CNcomment:\CF\F2оƬ\C4ڲ\BF\C9\E8\D6ø\F9\C3\DCԿ CNend
\attention \n
N/A
\param[in] enRootkeyType:   Type of rootkey.        CNcomment:\B8\F9\C3\DCԿ\C0\E0\D0\CD CNend
\param[in] pu8Rootkey: Point to root key value.     CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B8\F9\C3\DCԿ CNend
\param[in] u32Len: The length of root key.          CNcomment:\B8\F9\C3\DCԿ\B3\A4\B6\C8 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetRootKey(HI_UNF_OTP_ROOTKEY_E enRootkeyType, HI_U8 *pu8Rootkey, HI_U32 u32Len);


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
HI_S32 HI_UNF_OTP_GetRootKeyLockStat(HI_UNF_OTP_ROOTKEY_E enRootkeyType, HI_BOOL *pbLock);

/**
\brief Set RSA key to otp. CNcomment:\CF\F2оƬ\C4ڲ\BF\C9\E8\D6\C3RSA\C3\DCԿ CNend
\attention \n
N/A
\param[in] pu8Key: Point to RSA key value.         CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACRSA\C3\DCԿ CNend
\param[in] u32KeyLen: The length of RSA key.       CNcomment:RSA\C3\DCԿ\B3\A4\B6\C8 CNend
\retval ::HI_SUCCESS Success                                            CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called                        CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized  CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid   CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_SetRSAKey(HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Get rsa lock status. CNcomment:\BB\F1ȡRSA lock״̬ CNend
\attention \n
N/A
\param[out] pbLock: Rsa lock status.   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACRSA lock״̬ CNend
\retval ::HI_SUCCESS  Success.         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized. CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_GetRSALockStat(HI_BOOL *pbLock);


/**
\brief Burn product PV to otp. CNcomment:\CF\F2оƬ\C4ڲ\BFOTP\B9̶\A8\C5\E4\D6\C3 CNend
\attention \n
N/A
\param[in] pstPV: Point to the name of the config table.   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\C5\E4\D6\C3\CA\FD\BEݱ\ED\B5\D8ַ CNend
\param[in] u32Num: The nember of config table.         CNcomment:\C5\E4\D6\C3\CA\FD\BE\DD\CC\F5Ŀ\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_BurnProductPV(HI_UNF_OTP_BURN_PV_ITEM_S *pstPV, HI_U32 u32Num);

/**
\brief Verify product PV. CNcomment:\B5\F7\CA\D4У\D1\E9PV\CA\FD\BEݵ\C4\D5\FDȷ\D0\D4 CNend
\attention \n
N/A
\param[in] pstPV: Point to the name of the config table.   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\C5\E4\D6\C3\CA\FD\BEݱ\ED\B5\D8ַ CNend
\param[in] u32Num: The nember of config table.         CNcomment:\C5\E4\D6\C3\CA\FD\BE\DD\CC\F5Ŀ\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_OTP_VerifyProductPV(HI_UNF_OTP_BURN_PV_ITEM_S *pstPV, HI_U32 u32Num);

/**
\brief Set TEE enable lock flag. CNcomment:\C9\E8\D6\C3TEEʹ\C4\DC\CB\F8\B6\A8\B1\EA\BC\C7λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetTEECtrlLock(HI_VOID);

/**
\brief Get TEE enable lock flag. CNcomment: \BB\F1ȡTEEʹ\C4\DC\CB\F8\B6\A8\B1\EA\BC\C7λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbTEEEnL: Point to TEE lock status. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACTEE\CB\F8\B5\C4״̬ CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetTEECtrlLock(HI_BOOL *pbTEEEnL);

/**
\brief Set the ASC(ACPU Start Code) market segment ID. CNcomment: \C9\E8\D6\C3ASC(ACPU Start Code)\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pu8ASCMSID: Point to ASC market segment ID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACASC\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in] u32Len: ASC market segment ID length, current is 4. CNcomment:ASC \CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetASCMSID (HI_U8 *pu8ASCMSID, HI_U32 u32Len);

/**
\brief Get the ASC(ACPU Start Code) market segment ID. CNcomment:\BB\F1ȡASC(ACPU Start Code)\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8ASCMSID: Point to ASC market segment identifier. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACASC\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\param[in] pu32Len: ASC market segment ID length, current is 4. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACASC\CAг\A1\C7\F8\D3\F2\C2볤\B6ȣ\AC\B5\B1ǰ\B3\A4\B6\C8\CA\C74 CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetASCMSID(HI_U8 *pu8ASCMSID, HI_U32 *pu32Len);

/**
\brief Sets TA ID and TA market segment ID. CNcomment:\C9\E8\D6\C3TA ID\BA\CDTA\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] enIndex: TA ID and TA market segment ID index. CNcomment:TA ID\BA\CDTA\CAг\A1\C7\F8\D3\F2\C2\EB\B5\C4\CB\F7\D2\FD  CNend
\param[in] u32TAID: TA ID. CNcomment:TA ID CNend
\param[in] u32MSID: TA market Segment ID. CNcomment:TA\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_SetTAIDAndMSID(const HI_UNF_OTP_TA_INDEX_E enIndex, HI_U32 u32TAID, HI_U32 u32MSID);

/**
\brief Get TA ID and TA market segment ID. CNcomment:\BB\F1ȡTA ID\BA\CDTA\CAг\A1\C7\F8\D3\F2\C2\EB  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] enIndex: TA ID and TA market segment ID index. CNcomment:TA ID\BA\CDTA\CAг\A1\C7\F8\D3\F2\C2\EB\B5\C4\CB\F7\D2\FD  CNend
\param[out] pu32TAID: TA ID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACTA ID CNend
\param[out] pu32MSID: TA market segment ID. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACTA\CAг\A1\C7\F8\D3\F2\C2\EB CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetTAIDAndMSID(const HI_UNF_OTP_TA_INDEX_E enIndex, HI_U32 *pu32TAID, HI_U32 *pu32MSID);

/**
\brief Disable UART(Universal Asynchronous Receiver/Transmitter) output. CNcomment:\B9ر\D5UART\CA\E4\B3\F6  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] enUartType: UART type. CNcomment:UART\C0\E0\D0\CD  CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_NOT_SUPPORT Not support for this chipset. CNcomment:\B4\CBоƬ\B2\BB֧\B3\D6 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_DisableUART(HI_UNF_OTP_UART_TYPE_E enUartType);
/**
\brief Get UART(Universal Asynchronous Receiver/Transmitter) status. CNcomment:\BB\F1ȡUART״̬  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] enUartType: UART type. CNcomment:UART\C0\E0\D0\CD  CNend
\param[out] pbDisable Pointer to UART Stat. CNcomment:ָ\CF\F2UARTȥʹ\C4ܱ\EA\BC\C7ֵ\B5\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success.  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Failure.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_OTP_NOT_INIT The otp module is not initialized.  CNcomment:OTPδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_OTP_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_OTP_NOT_SUPPORT Not support for this chipset. CNcomment:\B4\CBоƬ\B2\BB֧\B3\D6 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_OTP_GetUARTStat(HI_UNF_OTP_UART_TYPE_E enUartType, HI_BOOL *pbDisable);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_OTP_H__ */
