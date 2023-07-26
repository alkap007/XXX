/******************************************************************************

Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_unf_advca.h
Version       : Initial
Author        : Hisilicon hisecurity team
Created       : 2013-08-28
Last Modified :
Description   : Hisilicon CA API declaration
Function List :
History       :
******************************************************************************/
#ifndef __HI_UNF_ADVCA_H__
#define __HI_UNF_ADVCA_H__

#include "hi_type.h"
#include "hi_unf_cipher.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      ADVCA */
/** @{ */  /** <!-- [ADVCA] */

/** advanced CA session serect key class*/
typedef enum hiUNF_ADVCA_KEYLADDER_LEV_E
{
    HI_UNF_ADVCA_KEYLADDER_LEV1     = 0,    /**<session serect key level 1*/
    HI_UNF_ADVCA_KEYLADDER_LEV2 ,           /**<session serect key level 2*/
    HI_UNF_ADVCA_KEYLADDER_LEV3 ,           /**<session serect key level 3*/
    HI_UNF_ADVCA_KEYLADDER_LEV4,            /**<session serect key level 4*/
    HI_UNF_ADVCA_KEYLADDER_LEV5,            /**<session serect key level 5*/
    HI_UNF_ADVCA_KEYLADDER_LEV6,            /**<session serect key level 6*/
    HI_UNF_ADVCA_KEYLADDER_BUTT
}HI_UNF_ADVCA_KEYLADDER_LEV_E;

/** advanced CA session keyladder target */
typedef enum hiUNF_ADVCA_CA_TARGET_E
{
    HI_UNF_ADVCA_CA_TARGET_DEMUX         = 0, /**<demux*/
    HI_UNF_ADVCA_CA_TARGET_MULTICIPHER,       /**<multicipher*/
    HI_UNF_ADVCA_CA_TARGET_BUTT
}HI_UNF_ADVCA_CA_TARGET_E;

/** advanced CA Encrypt arith*/
typedef enum hiUNF_ADVCA_ALG_TYPE_E
{
    HI_UNF_ADVCA_ALG_TYPE_TDES      = 0,    /**<Encrypt arith :3 DES*/
    HI_UNF_ADVCA_ALG_TYPE_AES,              /**<Encrypt arith : AES*/
    HI_UNF_ADVCA_ALG_TYPE_SM4,              /**<Encrypt arith : SM4*/
    HI_UNF_ADVCA_ALG_TYPE_BUTT
}HI_UNF_ADVCA_ALG_TYPE_E;

/** FLASH device types*/
typedef enum hiUNF_ADVCA_FLASH_TYPE_E
{
    HI_UNF_ADVCA_FLASH_TYPE_SPI     = 0,    /**<SPI flash*/
    HI_UNF_ADVCA_FLASH_TYPE_NAND ,          /**<nand flash*/
    HI_UNF_ADVCA_FLASH_TYPE_NOR ,           /**<nor flash*/
    HI_UNF_ADVCA_FLASH_TYPE_EMMC ,          /**<eMMC*/
    HI_UNF_ADVCA_FLASH_TYPE_SPI_NAND ,      /**<spi_nand flash*/
    HI_UNF_ADVCA_FLASH_TYPE_SD,             /**<FSD/TSD flash*/
    HI_UNF_ADVCA_FLASH_TYPE_BUTT
}HI_UNF_ADVCA_FLASH_TYPE_E;

/** JTAG protect mode*/
typedef enum hiUNF_ADVCA_JTAG_MODE_E
{
    HI_UNF_ADVCA_JTAG_MODE_OPEN     = 0,
    HI_UNF_ADVCA_JTAG_MODE_PROTECT,
    HI_UNF_ADVCA_JTAG_MODE_CLOSED,
    HI_UNF_ADVCA_JTAG_MODE_BUTT
}HI_UNF_ADVCA_JTAG_MODE_E;

typedef struct HiUNF_ADVCA_LOCK_TZ_OTP_PARAM
{
    HI_U32 u32Addr;
    HI_U32 u32Len;
}HI_UNF_ADVCA_LOCK_TZ_OTP_PARAM_S;

typedef enum hiUNF_ADVCA_SP_DSC_MODE_E
{
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_CSA2              = 0x0000,   /**<Demux PAYLOAD CSA2 */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_CSA3              = 0x0010,   /**<Demux PAYLOAD CSA3 */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_CBC_IDSA      = 0x0020,   /**<Demux PAYLOAD AES  IPTV Mode */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_ECB           = 0x0021,   /**<Demux PAYLOAD AES  ECB Mode */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_CBC_CI        = 0x0022,   /**<Demux PAYLOAD AES  CIPLUS */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_DES_IPTV          = 0x0030,   /**<Demux PAYLOAD DES  CIPLUS */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_DES_CIPLUS        = 0x0032,   /**<Demux PAYLOAD DES  CIPLUS */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_DES_CBC           = 0x0033,   /**<Demux PAYLOAD DES  CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_NOVEL         = 0x0040,   /**<Demux PAYLOAD AES  NOVEL */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_SMS4_NOVEL        = 0x0041,   /**<Demux PAYLOAD SMS4 NOVEL */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_SMS4_IPTV         = 0x0050,   /**<Demux PAYLOAD SMS4 IPTV */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_SMS4_ECB          = 0x0051,   /**<Demux PAYLOAD SMS4 ECB */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_SMS4_CBC          = 0x0053,   /**<Demux PAYLOAD SMS4 CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_CBC           = 0x0063,   /**<Demux PAYLOAD AES  CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_TDES_IPTV         = 0x0070,   /**<Demux PAYLOAD TDES IPTV */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_TDES_ECB          = 0x0071,   /**<Demux PAYLOAD TDES ECB */
     HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_TDES_CBC          = 0x0073,   /**<Demux PAYLOAD TDES CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_AES_CBC               = 0x4020,   /**<MultiCipher AES CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_AES_ECB               = 0x4021,   /**<MultiCipher AES ECB */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_AES_CBC_PIFF          = 0x4022,   /**<MultiCipher AES CBC PIFF */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_AES_CBC_APPLE         = 0x4023,   /**<MultiCipher AES CBC APPLE */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_AES_CTR               = 0x4024,   /**<MultiCipher AES CTR */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_TDES_CBC              = 0x4040,   /**<MultiCipher AES CBC */
     HI_UNF_ADVCA_SP_DSC_MODE_RAW_TDES_ECB              = 0x4041,   /**<MultiCipher AES ECB */
     HI_UNF_ADVCA_SP_DSC_MODE_BUTT
}HI_UNF_ADVCA_SP_DSC_MODE_E;

/** Advca CA VendorID */
typedef enum hiUNF_ADVCA_VENDORID_E
{
    HI_UNF_ADVCA_NULL       = 0x00,        /**<No-Advcance CA chipset, Marked with 0*/
    HI_UNF_ADVCA_NAGRA      = 0x01,        /**<NAGRA  Chipse, Marked with R*/
    HI_UNF_ADVCA_IRDETO     = 0x02,        /**<IRDETO Chipset, Marked with I*/
    HI_UNF_ADVCA_CONAX      = 0x03,        /**<CONAX Chipset, Marked with C*/
    HI_UNF_ADVCA_SUMA       = 0x05,        /**<SUMA Chipset, Marked with S*/
    HI_UNF_ADVCA_NOVEL      = 0x06,        /**<NOVEL Chipset, Marked with Y*/
    HI_UNF_ADVCA_VERIMATRIX = 0x07,        /**<VERIMATRIX Chipset, Marked with M*/
    HI_UNF_ADVCA_CTI        = 0x08,        /**<CTI Chipset, Marked with T*/
    HI_UNF_ADVCA_COMMONCA   = 0x0b,        /**<COMMONCA Chipset, Marked with H*/
    HI_UNF_ADVCA_DCAS       = 0x0c,        /**<DCAS CA Chipset*/
    HI_UNF_ADVCA_PANACCESS  = 0x0e,        /**<PANACCESS CA Chipset*/
    HI_UNF_ADVCA_VENDORIDE_BUTT
}HI_UNF_ADVCA_VENDORID_E;

/** Advca CA lock type */
typedef enum hiUNF_ADVCA_LOCK_TYPE
{
    HI_UNF_ADVCA_LOCK_RSA_KEY = 0,
    HI_UNF_ADVCA_LOCK_TZ_OTP,
    HI_UNF_ADVCA_LOCK_MISC_KL_DISABLE,
    HI_UNF_ADVCA_LOCK_GG_KL_DISABLE,
    HI_UNF_ADVCA_LOCK_TSKL_CSA3_DISABLE,
    HI_UNF_ADVCA_LOCK_BUTT,
}HI_UNF_ADVCA_LOCK_TYPE_E;


/** DCAS KeyLadder use mode */
typedef enum hiUNF_ADVCA_DCAS_KEYLADDER_LEV_E
{
    HI_UNF_ADVCA_DCAS_KEYLADDER_EK2         = 0,    /**<session EK2*/
    HI_UNF_ADVCA_DCAS_KEYLADDER_EK1         = 1,    /**<session EK1*/
    HI_UNF_ADVCA_DCAS_KEYLADDER_VENDORSYSID = 8,    /**<session Vendor_SysID*/
    HI_UNF_ADVCA_DCAS_KEYLADDER_NONCE       = 9,    /**<session nonce*/
    HI_UNF_ADVCA_DCAS_KEYLADDER_BUTT
}HI_UNF_ADVCA_DCAS_KEYLADDER_LEV_E;

/** MISC KeyLadder ROOTKEY Selection */
typedef enum hiUNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_E
{
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_CSA2    = 0,     /**<MISC ROOTKEY CSA2*/
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_CSA3,            /**<MISC ROOTKEY CSA3*/
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_AES,             /**<MISC ROOTKEY AES*/
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_SM4,             /**<MISC ROOTKEY SM4*/
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_MAX
}HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_E;

/**Defines the attribute ID of the OTP fuse. Please be kindly noted that the OTP fuse is set permanently.
After setting the OTP fuse, please power off and then power on the STB to make the OTP fuse function effective */
/**CNcomment: \B6\A8\D2\E5OTPλIDö\BE\D9\C0\E0\D0\CD. \C7\EBע\D2\E2OTPλ\C9\E8\D6ú󲻿ɸı\E4.
\C9\E8\D6ú\F3\A3\AC\C7\EB\B6ϵ\E7\D6\D8\C6\F4ʹOTPλ\B9\A6\C4\DC\C9\FAЧ.*/
typedef enum hiUNF_ADVCA_OTP_FUSE_E
{
    HI_UNF_ADVCA_OTP_NULL = 0,
    HI_UNF_ADVCA_OTP_SECURE_BOOT_ACTIVATION, /**<Whether to enable the secure boot authentication, set the boot flash type together, HI_UNF_ADVCA_OTP_SECURE_BOOT_ATTR_S*//**<CNcomment: \B0\B2ȫ\C6\F4\B6\AF\CAǷ\F1\BF\AA\C6\F4\A3\ACͬʱ\C9\E8\D6ð\B2ȫ\C6\F4\B6\AFflash\C0\E0\D0\CD, HI_UNF_ADVCA_OTP_SECURE_BOOT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_DECRYPTION_ACTIVATION, /**<Whether to enable the secure boot decryption, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: boot\BD\E2\C3ܹ\A6\C4\DC\CAǷ\F1\BF\AA\C6\F4, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SELF_BOOT_DEACTIVATION, /**<Whether to disable the self boot, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \D7Ծ\D9\CAǷ\F1\B9ر\D5, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_DDR_WAKEUP_DEACTIVATION, /**<Whether to disable the DDR wakeup, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \B4\FD\BB\FAԭ\B5ػ\BD\D0\D1\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA2_KL_LEVEL_SEL, /**<CSA2 keyladder stage, HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*//**<CNcomment: CSA2 keyladder\BC\B6\CA\FD , HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*/
    HI_UNF_ADVCA_OTP_R2R_KL_LEVEL_SEL, /**<R2R keyladder stage, HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*//**<CNcomment: R2R keyladder\BC\B6\CA\FD , HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*/
    HI_UNF_ADVCA_OTP_SP_KL_LEVEL_SEL, /**<SP keyladder stage, HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*//**<CNcomment: SP keyladder\BC\B6\CA\FD , HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA3_KL_LEVEL_SEL, /**<CSA3 keyladder stage, HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*//**<CNcomment: CSA3 keyladder\BC\B6\CA\FD , HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*/
    HI_UNF_ADVCA_OTP_LP_DEACTIVATION, /**<Whether to disable the LP keyladder, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: LP keyladder\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA2_CW_HARDONLY_ACTIVATION, /**<Whether to enable the CSA2 hard CW only, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: CSA2ӲCW\CAǷ\F1ʹ\C4\DC , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SP_CW_HARDONLY_ACTIVATION, /**<Whether to enable the SP hard CW only, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: SPӲCW\CAǷ\F1ʹ\C4\DC , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA3_CW_HARDONLY_ACTIVATION, /**<Whether to enable the CSA3 hard CW only, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: CSA3ӲCW\CAǷ\F1ʹ\C4\DC , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA2_KL_DEACTIVATION, /**<Whether to disable the CSA2 keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: CSA2 keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SP_KL_DEACTIVATION, /**<Whether to disable the SP keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: SP keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA3_KL_DEACTIVATION, /**<Whether to disable the CSA3 keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: CSA3 keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_MISC_KL_DEACTIVATION, /**<Whether to disable the MISC keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: MISC keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_GOOGLE_KL_DEACTIVATION, /**<Whether to disable the google keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: Google keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_DCAS_KL_DEACTIVATION, /**<Whether to disable the DCAS keyladder crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: DCAS keyladder\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_DDR_SCRAMBLE_ACTIVATION, /**<Whether to enable the DDR scrambling, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: DDR\BC\D3\C8\C5\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_GLOBAL_LOCK_ACTIVATION, /**<Whether to lock the whole OTP area, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: OTPд\B1\A3\BB\A4\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_RUNTIME_CHECK_ACTIVATION, /**<Whether to enable the runtime check, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: Runtime check\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_DDR_WAKEUP_CHECK_ACTIVATION, /**<Whether to enable the DDR check when wakeup from standby, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \B4\FD\BB\FAԭ\B5ػ\BD\D0\D1ʱDDRУ\D1\E9\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_VERSION_ID_CHECK_ACTIVATION, /**<Whether to enable the version id check, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: Version IDУ\D1\E9\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_MSID_CHECK_ACTIVATION, /**<Whether to enable the boot MSID check, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: Boot MSIDУ\D1\E9\CAǷ\F1\BF\AA\C6\F4 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_JTAG_MODE, /**<JTAG protected mode, HI_UNF_ADVCA_JTAG_PRT_MODE_ATTR_S*//**<CNcomment: JTAG\B1\A3\BB\A4ģʽ , HI_UNF_ADVCA_JTAG_PRT_MODE_ATTR_S*/
    HI_UNF_ADVCA_OTP_JTAG_READ_DEACTIVATION, /**<Whether to disable to read OTP via JTAG, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: ͨ\B9\FDJTAG\B6\C1ȡOTP\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA2_ROOTKEY, /**<CSA2 keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: CSA2 keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_R2R_ROOTKEY, /**<R2R keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: R2R keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_SP_ROOTKEY, /**<SP keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: SP keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_CSA3_ROOTKEY, /**<CSA3 keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: CSA3 keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_MISC_ROOTKEY, /**<MISC keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: MISC keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_OEM_ROOTKEY, /**<OEM keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: OEM keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_ESCK_ROOTKEY, /**<ESCK keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: ESCK keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_JTAG_KEY, /**<JTAG key, HI_UNF_ADVCA_JTAG_KEY_ATTR_S*//**<CNcomment: JTAG\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_CHIP_ID, /**<Chip ID, HI_UNF_ADVCA_CHIPID_ATTR_S*//**<CNcomment: Chip ID, HI_UNF_ADVCA_JTAG_KEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_MARKET_SEGMENT_ID, /**<Market segment ID, HI_UNF_ADVCA_MARKET_ID_ATTR_S*//**<CNcomment: Market segment ID , HI_UNF_ADVCA_MARKET_ID_ATTR_S*/
    HI_UNF_ADVCA_OTP_VERSION_ID, /**<Version ID, HI_UNF_ADVCA_VERSION_ID_ATTR_S*//**<CNcomment: Version ID, HI_UNF_ADVCA_VERSION_ID_ATTR_S*/
    HI_UNF_ADVCA_OTP_MISC_KL_LEVEL_SEL, /**<MISC keyladder stage, HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*//**<CNcomment: MISC keyladder\BC\B6\CA\FD , HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S*/
    HI_UNF_ADVCA_OTP_VMX_BL_FUSE, /**<Burn verimatrix bootloader fuse*//**<CNcomment: \C9\D5дverimatrix\CCض\A8\B5\C4bootloader fuseλ*/
    HI_UNF_ADVCA_OTP_IRDETO_ITCSA3_ACTIVATION, /**<Whether to enbale the tweaked CSA3, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: ˽\D3\D0CSA3\CB㷨\CAǷ\F1\BF\AA\C6\F4\A1\A3HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOTINFO_DEACTIVATION, /**<Whether to disable the bootinfo, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: Bootinfo\CAǷ\F1\B9ر\D5, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_ITCSA3_IMLB, /**<tweaked CSA3 IMLB, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: ˽\D3\D0CSA3\CB㷨IMLB,HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_USB_DEACTIVATION, /**<Whether to disable the usb host, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \BD\FBֹUSB\C9豸, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SERIAL_DEACTIVATION, /**<Whether to disable serial port, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \BD\FBֹ\B4\AE\BFڹ\A6\C4\DC, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_ETHERNET_DEACTIVATION, /**<Whether to disable the ethernet, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \BD\FBֹ\CD\F8\C2\E7, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SM4_CRYPTO_ENGINE_DEACTIVATION, /**<Whether to disable the SM4 crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: SM4\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_TDES_CRYPTO_ENGINE_DEACTIVATION, /**<Whether to disable the TDES crypto engine, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: TDES\BD\E2\C3\DC\D2\FD\C7\E6\CAǷ\F1\B9ر\D5 , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/

    HI_UNF_ADVCA_OTP_SECURE_BOOT_ACTIVATION_ONLY,   /**<Enable secure boot authentication only, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*//**<CNcomment: \B0\B2ȫ\C6\F4\B6\AFʹ\C4ܣ\AC HI_UNF_ADVCA_OTP_SECURE_BOOT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_FLASH_TYPE,   /**<Boot flash type, HI_UNF_ADVCA_OTP_BOOT_FLASH_TYPE_ATTR_S*//**<CNcomment: \B0\B2ȫ\C6\F4\B6\AFflash\C0\E0\D0ͣ\AC HI_UNF_ADVCA_OTP_BOOT_FLASH_TYPE_ATTR_S*/

    HI_UNF_ADVCA_OTP_RSA_KEY_LOCK_FLAG,   /**< Get the lock flag of RSA_Root_key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡRSA_Root_Key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_STBSN_LOCK_FLAG,   /**< Get the lock flag of STBSN, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡSTBSN lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_MSID_LOCK_FLAG,   /**< Get the lock flag of MSID, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡMSID lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_VERSIONID_LOCK_FLAG,   /**< Get the lock flag of VersionID, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡVersionID lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_OEM_ROOTKEY_LOCK_FLAG,   /**< Get the lock flag of OEM_Root_key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡOEM_Root_key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_R2R_ROOTKEY_LOCK_FLAG,   /**< Get the lock flag of R2R_Root_key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡR2R_Root_key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_JTAG_KEY_LOCK_FLAG,   /**< Get the lock flag of JTAG key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡJTAG key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_TZ_AREA_LOCK_FLAG,   /**< Get the lock flag of OTP trust area, when otp_tz_area_enable is set, these lock flags can only be accessed by secure cpu , HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡOTP trust area lock\B1\EA\BCǣ\AC\B5\B1otp_tz_area_enable\B1\BB\C9\E8\D6\C3ʱ\A3\AC\D5\E2Щ\B1\EA\BC\C7ֻ\C4ܱ\BB\B0\B2ȫCPU\B6\C1ȡ\A3\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_ENCRYPTION_DEACTIVATION, /**< whether to diable boot loader key generation, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \C9\FA\B3\C9bootloader key\B9\A6\C4\DC\CAǷ\F1\B9رգ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_ROOTKEY,        /**<Boot keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: boot keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_SEC_STORE_ROOTKEY,   /**<Sec store keyladder root key, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: Sec store keyladder\B8\F9\C3\DCԿ , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_BOOT_ROOTKEY_LOCK_FLAG, /**< Get the lock flag of BOOT_Root_key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡBOOT_Root_Key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SEC_STORE_ROOTKEY_LOCK_FLAG, /**< Get the lock flag of SEC_STORE_Root_key, HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/ /**<CNcomment: \BB\F1ȡSEC_STORE_Root_Key lock\B1\EA\BCǣ\ACHI_UNF_ADVCA_OTP_DEFAULT_ATTR_S*/
    HI_UNF_ADVCA_OTP_SOS_MSID, /**< Get the security OS MSID (market segment id)*/ /**<CNcomment: \BB\F1ȡ\B0\B2ȫϵͳ\B5\C4MSID */
    HI_UNF_ADVCA_OTP_REE_MSID, /**< Get MSID(market segment id) of REE images, Currently, this fuse is used for SBL(second boot loader) of VMX ultra*/ /**<CNcomment: \BB\F1ȡREE\BE\B5\CF\F1\B5\C4MSID Ŀǰ\A3\ACVMX ultra\B0\B2ȫ\B7\BD\B0\B8\D0\E8Ҫʹ\D3ô\CBOTPУ\D1\E9\B6\FE\BC\B6boot*/
    HI_UNF_ADVCA_OTP_SMK_EXT_KEY, /**<Dcas keyladder rkd SMK_EXT_KEY, HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*//**<CNcomment: Dcas keyladder rkd ʹ\D3õ\C4\C0\A9չkey , HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S*/
    HI_UNF_ADVCA_OTP_FUSE_BUTT
}HI_UNF_ADVCA_OTP_FUSE_E;

/**Defines the attribute of secure boot check.*/
/**CNcomment: \B6\A8\D2尲ȫ\C6\F4\B6\AFУ\D1\E9\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_ADVCA_OTP_SECURE_BOOT_ATTR_S
{
    HI_BOOL bEnable;    /**<Is secure boot check enable or not*/
    HI_UNF_ADVCA_FLASH_TYPE_E enFlashType; /**<Boot flash type*/
}HI_UNF_ADVCA_OTP_SECURE_BOOT_ATTR_S;

/**Defines the boot flash type.*/
/**CNcomment: \B6\A8\D2尲ȫ\C6\F4\B6\AFflash\C0\E0\D0ͽṹ\CC\E5*/
typedef struct hiUNF_ADVCA_OTP_BOOT_FLASH_TYPE_ATTR_S
{
    HI_BOOL bBootSelCtrl;    /**<0--the boot flash type is defined by chipset pin, 1--the boot flash type is defined by OTP value*/
    HI_UNF_ADVCA_FLASH_TYPE_E enFlashType; /**<Boot flash type, only valid when bBootSelCtrl is 1*/
}HI_UNF_ADVCA_OTP_BOOT_FLASH_TYPE_ATTR_S;

/**Defines the default attribute of OTP fuse. If one OTP fuse can ONLY be "Enable" or "Disable",
then we will use this attribute.*/
/**CNcomment: \B6\A8\D2\E5OTPλĬ\C8\CF\CA\F4\D0Խṹ\CC\E5. \CA\CA\D3\C3\D3\DAһ\B8\F6OTPλ\B5Ĺ\A6\C4\DC
+\CAǿ\AA\C6\F4\BB\F2\B9رյ\C4\C7\E9\BF\F6*/
typedef struct hiUNF_ADVCA_OTP_DEFAULT_ATTR_S
{
    HI_BOOL bEnable;    /**<Is the feature enable or not*/
}HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S;

/**Defines the attribute of the keyladder level.*/
/**CNcomment: \B6\A8\D2\E5keyladder\BC\B6\CA\FD\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_LEV_E enKeyladderLevel;   /**<Keyladder level*/
}HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S;

/**Defines the attribute of the JTAG protected mode.*/
/**CNcomment: \B6\A8\D2\E5JTAG\BDӿڱ\A3\BB\A4\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_JTAG_PRT_MODE_ATTR_S
{
    HI_UNF_ADVCA_JTAG_MODE_E enJtagMode;    /**<JTAG protection mode*/
}HI_UNF_ADVCA_JTAG_PRT_MODE_ATTR_S;

/**Defines the attribute of the keyladder root key.*/
/**CNcomment: \B6\A8\D2\E5keyladder \B8\F9\C3\DCԿ\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S
{
    HI_U8 u8RootKey[16];    /**<Root key of the keyladder*/
}HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S;

/**Defines the attribute of the JTAG key.*/
/**CNcomment: \B6\A8\D2\E5JTAG\BDӿڱ\A3\BB\A4\C3\DCԿ\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_JTAG_KEY_ATTR_S
{
    HI_U8 u8JtagKey[8];     /**<JTAG protected key*/
}HI_UNF_ADVCA_JTAG_KEY_ATTR_S;

/**Defines the attribute of the chip id.*/
/**CNcomment: \B6\A8\D2\E5chip id\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_CHIPID_ATTR_S
{
    HI_U8 au8ChipId[8];       /**<ChipID of the chipset, it is unique every chipset*/
}HI_UNF_ADVCA_CHIPID_ATTR_S;

/**Defines the attribute of the market segment id.*/
/**CNcomment: \B6\A8\D2\E5market segment id\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_MARKET_ID_ATTR_S
{
    HI_U8 u8MSID[4];    /**<Market Segment ID*/
}HI_UNF_ADVCA_MARKET_ID_ATTR_S;

/**Defines the attribute of the version id.*/
/**CNcomment: \B6\A8\D2\E5version id\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_VERSION_ID_ATTR_S
{
    HI_U8 u8VersionId[4];   /**<Bootloader Version ID*/
}HI_UNF_ADVCA_VERSION_ID_ATTR_S;

typedef struct hiUNF_ADVCA_VMX_BL_FUSE_ATTR_S
{
    HI_U32 u32VMXBLFuse;
}HI_UNF_ADVCA_VMX_BL_FUSE_S;

/**Defines the attribute of the tweaked CSA3 IMLB.*/
/**CNcomment: \B6\A8\D2\E5tweaked CSA3 IMLB\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_ITCSA3_IMLB_ATTR_S
{
    HI_U8 au8ItCsa3IMLB[2];   /**<tweaked CSA3 IMLB*/
}HI_UNF_ADVCA_ITCSA3_IMLB_ATTR_S;

/**Defines the attribute of the OTP fuse.*/
/**CNcomment: \B6\A8\D2\E5OTP fuse\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_OTP_ATTR_S
{
    union
    {
        HI_UNF_ADVCA_OTP_DEFAULT_ATTR_S          stDefaultAttr; /**<Default attribute, if one fuse can ONLY be "Enable" or "Disable", then we can use this attribute*/
        HI_UNF_ADVCA_OTP_SECURE_BOOT_ATTR_S      stEnableSecureBoot; /**<Secure boot attribute*/
        HI_UNF_ADVCA_KEYLADDER_LEVEL_SEL_ATTR_S  stKeyladderLevSel;  /**<Keyladder level attribute*/
        HI_UNF_ADVCA_JTAG_PRT_MODE_ATTR_S        stJtagPrtMode; /**<JTAG protected mode attribute*/
        HI_UNF_ADVCA_KEYLADDER_ROOTKEY_ATTR_S    stKeyladderRootKey; /**<Keyladder rootkey attribute*/
        HI_UNF_ADVCA_JTAG_KEY_ATTR_S             stJtagKey;   /**<JTAG key attribute*/
        HI_UNF_ADVCA_CHIPID_ATTR_S               stChipId;     /**<Chip ID attribute*/
        HI_UNF_ADVCA_MARKET_ID_ATTR_S            stMarketId;    /**<Market segment ID attribute*/
        HI_UNF_ADVCA_VERSION_ID_ATTR_S           stVersionId;  /**<Bootloadder version ID attribute*/
        HI_UNF_ADVCA_VMX_BL_FUSE_S               stVMXBLFuse;  /**<Vmx Bootloadder specific fuse attribute*/
        HI_UNF_ADVCA_ITCSA3_IMLB_ATTR_S          stItCsa3IMLB; /**<tweaked CSA3 IMLB attribute*/
        HI_UNF_ADVCA_OTP_BOOT_FLASH_TYPE_ATTR_S  stBootFlashType;   /**<Boot flash type attribute*/
    }unOtpFuseAttr;
}HI_UNF_ADVCA_OTP_ATTR_S;

/**Defines the attribute of the keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5keyladder\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_TYPE_E
{
    HI_UNF_ADVCA_KEYLADDER_CSA2 = 0,        /**<CSA2 keyladder*/
    HI_UNF_ADVCA_KEYLADDER_CSA3,            /**<CSA3 keyladder*/
    HI_UNF_ADVCA_KEYLADDER_R2R,             /**<R2R keyladder*/
    HI_UNF_ADVCA_KEYLADDER_SP,              /**<SP keyladder*/
    HI_UNF_ADVCA_KEYLADDER_MISC,            /**<MISC keyladder*/
    HI_UNF_ADVCA_KEYLADDER_LP,              /**<LP keyladder*/
    HI_UNF_ADVCA_KEYLADDER_TA,              /**<TA keyladder*/
    HI_UNF_ADVCA_KEYLADDER_GDRM,            /**<Google DRM key ladder*/
    HI_UNF_ADVCA_KEYLADDER_SECSTORE,        /**<Secure Store key ladder*/
    HI_UNF_ADVCA_KEYLADDER_SWPKDEC,         /**<SWPK DEC key ladder*/
    HI_UNF_ADVCA_KEYLADDER_SWPKENC,         /**<SWPK ENC key ladder*/
    HI_UNF_ADVCA_KEYLADDER_TYPE_BUTT
}HI_UNF_ADVCA_KEYLADDER_TYPE_E;

/**Defines the attribute of the CSA2 keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5CSA2 keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_CSA2_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_ALG = 0,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_E;

/**Defines the attribute of the CSA3 keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5CSA3 keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_CSA3_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_ALG = 0,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_E;

/**Defines the attribute of the R2R keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5R2R keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_R2R_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_ALG = 0,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_E;

/**Defines the attribute of the LP keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5LP keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_LP_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_LP_ATTR_LOAD_LPK = 0,            /**<Load Link protection key*/
    HI_UNF_ADVCA_KEYLADDER_LP_ATTR_DECRYPT_PROTECTED_DATA,   /**<Decrypt Link protected data*/
    HI_UNF_ADVCA_KEYLADDER_LP_ATTR_ALG,                       /**<LP Keyladder algorithm*/
    HI_UNF_ADVCA_KEYLADDER_LP_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_LP_ATTR_E;

/**Defines the attribute of the LP keyladder.*/
/**CNcomment: \B6\A8\D2\E5LP keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_LP_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_LP_ATTR_E  enLPKlAttr; /**<LP keyladder attribute ID*/
    HI_U8 u8Lpk[16];                                /**<Link protection key to be loaded*/
    HI_U8 *pu8ProtectedData;                /**<Input link protected data to be decrypted*/
    HI_U32 u32ProtectedDataLen;          /**<Input link protected data length*/
    HI_U8 *pu8OutputProtectedData;   /**<Output link protected data after decryption*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<LP Keyladder algorithm, only support TDES/AES*/
}HI_UNF_ADVCA_KEYLADDER_LP_ATTR_S;

/**Defines the attribute of the SP keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5SP keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_SP_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_ENABLE = 0,       /**<Use SPE keyladder or not for specal CA system */
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_ALG ,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_DSC_MODE,   /**<Descrambling mode*/
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_SP_ATTR_E;

/**Defines the attribute of the MISC keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5MISC keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_MISC_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_ENABLE = 0, /**<Use MISC keyladder or not. Before using the MISC keyladder, should set this attribute to HI_TRUE,
                                                                     and after using, should set it to HI_FALSE.*/
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_ALG,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_DSC_MODE,   /**<Descrambling mode*/
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_ROOTKEY_SEL,       /**<MISC Keyladder Root key Selection*/
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_E;

/**Defines the attribute of the TA keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5TA keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_TA_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_ENABLE = 0, /**<Use TA keyladder or not. Before using the TA keyladder, should set this attribute to HI_TRUE,
                                                                     and after using, should set it to HI_FALSE.*/
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_ALG,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_LOAD_TRANDATA,   /**<Transformation data protection and loading*/
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_TA_ATTR_E;

/**Defines the attribute of the SECSTORE keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5SECSTORE keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_SECSTORE_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_ENABLE = 0, /**<Use SECSTORE keyladder or not. Before using the TA keyladder, should set this attribute to HI_TRUE,
                                                                     and after using, should set it to HI_FALSE.*/
    HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_ALG,            /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_E;

/**Defines the attribute of the SWPK DEC keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5SWPK DEC keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_ALG = 0,            /**<Keyladder algorithm, TDES/SM4*/
    HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_E;

/**Defines the attribute of the SWPK ENC keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5SWPK ENC keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_SWPKENC_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_ALG = 0,            /**<Keyladder algorithm, TDES/SM4*/
    HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_E;

/**Defines the attribute of the CSA2 keyladder.*/
/**CNcomment: \B6\A8\D2\E5CSA2 keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_CSA2_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_E  enCsa2KlAttr; /**<CSA2 keyladder attribute ID*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;   /**<Keyladder stage of the session key to be set*/
    HI_U8 u8SessionKey[16];                                   /**<Session key*/
}HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_S;

/**Defines the attribute of the CSA3 keyladder.*/
/**CNcomment: \B6\A8\D2\E5CSA3 keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_CSA3_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_E  enCsa3KlAttr; /**<CSA3 keyladder attribute ID*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;   /**<Keyladder stage of the session key to be set*/
    HI_U8 u8SessionKey[16];                                    /**<Session key*/
}HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_S;

/**Defines the attribute of the R2R keyladder.*/
/**CNcomment: \B6\A8\D2\E5R2R keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_R2R_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_E  enR2RKlAttr; /**<R2R keyladder attribute  ID*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;   /**<Keyladder stage of the session key to be set*/
    HI_U8 u8SessionKey[16];                                   /**<Session key*/
}HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_S;

/**Defines the attribute of the SP keyladder.*/
/**CNcomment: \B6\A8\D2\E5SP keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_SP_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_SP_ATTR_E  enSPKlAttr; /**<SP keyladder attribute ID*/
    HI_BOOL bEnable;    /**<Use SP keyladder or not. Before using the SP keyladder*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;               /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_SP_DSC_MODE_E enDscMode;    /**<Descramblig mode*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;         /**<Keyladder stage of the session key to be set*/
    HI_U8 u8SessionKey[16];                                         /**<Session key*/
}HI_UNF_ADVCA_KEYLADDER_SP_ATTR_S;



/**Defines the attribute of the MISC keyladder.*/
/**CNcomment: \B6\A8\D2\E5MISC keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_MISC_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_E  enMiscKlAttr; /**<MISC keyladder attribute ID*/
    HI_BOOL bEnable;    /**<Use MISC keyladder or not. Before using the MISC keyladder, should be set to HI_TRUE,
                            and after using, should be set to HI_FALSE.*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;               /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_SP_DSC_MODE_E enDscMode;    /**<Descramblig mode*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;         /**<Keyladder stage of the session key to be set*/
    HI_U8 u8SessionKey[16];                                         /**<Session key*/
    HI_UNF_ADVCA_MISC_KEYLADDER_ROOTKEY_SEL_E enRootKeySel;    /**<MISC ROOT Key Selection*/
}HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_S;

/**Defines the attribute of the TA keyladder.*/
/**CNcomment: \B6\A8\D2\E5TA keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_TA_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_TA_ATTR_E  enTAKlAttr; /**<TA keyladder attribute ID*/
    HI_BOOL bEnable;    /**<Use TA keyladder or not. Before using the TA keyladder, should be set to HI_TRUE,
                            and after using, should be set to HI_FALSE.*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<Keyladder algorithm, TDES/AES*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;   /**<Keyladder stage of the session key to be set*/
    HI_U8 au8SessionKey[16];                                   /**<Session key*/
    HI_U8 *pu8TranData;                                         /**<Transformation data*/
    HI_U32 u32TranDataLen;                                  /**<Transformation data length*/
}HI_UNF_ADVCA_KEYLADDER_TA_ATTR_S;

/**Defines the attribute of the Google DRM keyladder type ID.*/
/**CNcomment: \B6\A8\D2\E5Google DRM keyladder\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_KEYLADDER_GDRM_ATTR_E
{
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_ENABLE = 0,    /**<Use GDRM keyladder or not. Before using the GDRM keyladder, should set this attribute to HI_TRUE, and after using, should set it to HI_FALSE.*/
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_ENCRYPT,       /**<Encrypt clear device key*/
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_SESSION_KEY,   /**<Keyladder session key*/
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_GETFLAG,       /**<Get flag*/
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_BUTT
}HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_E;

/**Defines the attribute of Google DRM keyladder.*/
/**CNcomment: \B6\A8\D2\E5Google DRM keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_GDRM_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_E  enGDRMKlAttr;
    HI_BOOL bEnable;                                  /**<Use GDRM keyladder or not. Before using the GDRM keyladder, should be set to HI_TRUE, and after using, should set it to HI_FALSE.*/
    HI_UNF_ADVCA_KEYLADDER_LEV_E enStage;       /**<Keyladder stage of the session key to be set*/
    HI_HANDLE hCipherHandle;                    /**<cipher handle, if enStage is HI_UNF_ADVCA_KEYLADDER_LEV3, hCipherHandle should be set*/
    HI_U8 au8SessionKey[32];                     /**<if select HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_ENCRYPT it is clear device key, if select HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_SESSION_KEY, it is session key*/
    HI_U8 au8Output[16];                          /**<if HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_ENCRYPT is set, it is encrypted device key, if HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_GETFLAG is set, it is flag*/
}HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_S;

/**Defines the attribute of the TA keyladder.*/
/**CNcomment: \B6\A8\D2\E5TA keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_SECSTORE_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_E  enSECSTREKlAttr; /**<Secure STORE keyladder attribute ID*/
    HI_BOOL bEnable;    /**<Use Secure STORE keyladder or not. Before using the Secure STORE keyladder, should be set to HI_TRUE,
                            and after using, should be set to HI_FALSE.*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;          /**<Keyladder algorithm, TDES/AES*/
}HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_S;

/**Defines the attribute of the SWPK DEC keyladder.*/
/**CNcomment: \B6\A8\D2\E5SWPK DEC keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_E  enSWPKDECKlAttr;     /**<SWPK DEC keyladder attribute ID*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;                          /**<Keyladder algorithm, TDES/SM4*/
}HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_S;

/**Defines the attribute of the SWPK ENC keyladder.*/
/**CNcomment: \B6\A8\D2\E5SWPK ENC keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_SWPKENC_ATTR_S
{
    HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_E  enSWPKENCKlAttr;     /**<SWPK ENC keyladder attribute ID*/
    HI_UNF_ADVCA_ALG_TYPE_E enAlgType;                          /**<Keyladder algorithm, TDES/SM4*/
}HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_S;

/**Defines the attribute of all of the keyladder.*/
/**CNcomment: \B6\A8\D2\E5\CB\F9\D3\D0 keyladder\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_KEYLADDER_ATTR_S
{
    union
    {
        HI_UNF_ADVCA_KEYLADDER_CSA2_ATTR_S      stCSA2KlAttr;       /**<CSA2 keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_CSA3_ATTR_S      stCSA3KlAttr;       /**<CSA3 keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_R2R_ATTR_S       stR2RKlAttr;        /**<R2R keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_SP_ATTR_S        stSPKlAttr;         /**<SP keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_LP_ATTR_S        stLpKlAttr;         /**<LP keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_MISC_ATTR_S      stMiscKlAttr;       /**<MISC keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_TA_ATTR_S        stTAKlAttr;         /**<TA keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_GDRM_ATTR_S      stGDRMAttr;         /**<Google DRM keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_SECSTORE_ATTR_S  stSECSTOREAttr;     /**<Secure STORE keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_SWPKDEC_ATTR_S   stSWPKDECKlAttr;    /**<SWPKDEC keyladder attribute*/
        HI_UNF_ADVCA_KEYLADDER_SWPKENC_ATTR_S   stSWPKENCKlAttr;    /**<SWPKENE keyladder attribute*/
    }unKlAttr;
}HI_UNF_ADVCA_KEYLADDER_ATTR_S;


/**Defines the attribute of the CA vendor type ID.*/
/**CNcomment: \B6\A8\D2\E5CA vendor\CA\F4\D0\D4\C0\E0\D0\CDID.*/
typedef enum hiUNF_ADVCA_CA_VENDOR_OPT_E
{
    HI_UNF_ADVCA_CA_VENDOR_OPT_IRDETO_CHIP_CONF_CMAC = 0, /**<To generate a secure message authentication code (MAC) tag for the OTP configuration data*/
    HI_UNF_ADVCA_CA_VENDOR_OPT_IRDETO_CBCMAC_CALC,  /**<To calculate the high level code CBC-MAC.*/
    HI_UNF_ADVCA_CA_VENDOR_OPT_IRDETO_CBCMAC_AUTH,  /**<To authenticate the high level code CBC-MAC.*/
    HI_UNF_ADVCA_CA_VENDOR_OPT_IRDETO_ACTIVATION_CODE, /**<To set the activation code for tweaked CSA3.*/
    HI_UNF_ADVCA_CA_VENDOR_OPT_VMX_GET_RNG, /**<To get the RNG number, ONLY used for verimatrix currently.*/
    HI_UNF_ADVCA_CA_VENDOR_OPT_BUTT
}HI_UNF_ADVCA_CA_VENDOR_OPT_E;

/**Defines the attribute of chip configuration CMAC.*/
/**CNcomment: \B6\A8\D2\E5\B2\FA\C9\FAOTP\CA\FD\BE\DDCMAC\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_IRDETO_CHIP_CONF_CMAC_ATTR_S
{
    HI_U8 au8ChipConfBitm[16]; /**<128bit Chip configuration bit map*/
    HI_U8 au8ChipConfCmac[16];   /**<128bit Chip configuration CMAC*/
}HI_UNF_ADVCA_IRDETO_CHIP_CONF_CMAC_ATTR_S;

/**Defines the attribute of the tweak CSA3, Activation Code.*/
/**CNcomment: \B6\A8\D2\E5CSA3\CB㷨\D0\E8Ҫ\C9\E8\D6õ\C4ACTIVATION CODE.*/
typedef struct hiUNF_ADVCA_IRDETO_ACTIVATION_CODE_ATTR_S
{
    HI_U8 au8CSA3ActCode[16];   /**<128bit tweak CSA3 Activation Code*/
}HI_UNF_ADVCA_IRDETO_ACTIVATION_CODE_ATTR_S;

/**Defines the attribute of the high level code CBC-MAC authentication.*/
/**CNcomment: \B6\A8\D2\E5\C9ϲ\E3Ӧ\D3\C3CBC-MACУ\D1\E9\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiUNF_ADVCA_IRDETO_CBCMAC_ATTR_S
{
    HI_U8 *pu8InputData;
    HI_U32 u32InputDataLen;
    HI_U8 au8OutputCBCMAC[16];
    HI_U8 au8RefCBCMAC[16];  /**<Reference CBC-MAC*/
    HI_U32 u32AppLen; /**<High level code length*/
}HI_UNF_ADVCA_IRDETO_CBCMAC_ATTR_S;

typedef struct hiUNF_ADVCA_VMX_GetRNG_S
{
    HI_U32 u32RNG;
}HI_UNF_ADVCA_VMX_GetRNG_S;

/**Defines the attribute of the CA vendor private function.*/
/**CNcomment: \B6\A8\D2\E5CA\B3\A7\BC\D2˽\D3й\A6\C4\DC\CA\F4\D0Խṹ\CC\E5.*/
typedef struct hiADVCA_CA_VENDOR_OPT_S
{
    HI_UNF_ADVCA_CA_VENDOR_OPT_E enCaVendorOpt;
    union
    {
        HI_UNF_ADVCA_IRDETO_CHIP_CONF_CMAC_ATTR_S     stIrdetoChipConfCmac;
        HI_UNF_ADVCA_IRDETO_ACTIVATION_CODE_ATTR_S    stIrdetoCsa3ActCode;
        HI_UNF_ADVCA_IRDETO_CBCMAC_ATTR_S             stIrdetoCbcMac;
        HI_UNF_ADVCA_VMX_GetRNG_S                     stVMXRng;
    }unCaVendorOpt;
}HI_UNF_ADVCA_CA_VENDOR_OPT_S;

/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      ADVCA */
/** @{ */  /** <!-- [ADVCA] */

/**
\brief Initializes the advanced CA module CNcomment:\B3\F5ʼ\BB\AFadvance CAģ\BF\E9 CNend
\attention \n
Call this application programming interface (API) before using the advanced CA module.
The code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:\D4ڽ\F8\D0\D0advance CA\CF\E0\B9ز\D9\D7\F7ǰӦ\B8\C3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA\n
\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڣ\AC\BB᷵\BBسɹ\A6 CNend
\param N/A CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_OPEN_ERR The CA device fails to start CNcomment:HI_ERR_CA_OPEN_ERR \B4\F2\BF\AACA\C9豸ʧ\B0\DC CNend
\see \n
::HI_UNF_ADVCA_DeInit
*/
HI_S32 HI_UNF_ADVCA_Init(HI_VOID);

/**
\brief Deinitializes the advanced CA module CNcomment:ȥ\B3\F5ʼ\BB\AFadvance CAģ\BF\E9 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param N/A CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_DeInit(HI_VOID);

/**
\brief Set the ChipId CNcomment:\C9\E8\D6\C3ChipId  CNend
\attention \n
This application programming interface (API) is allowed to invoked only once.
It's not allowed to call this API repeatedly.
CHIP_ID should have been setting before chipset is delivered to STB Manufacture.
Please contact Hisilicon before Customer try to use this interface.
CNcomment:\n  CNend
CNcomment:\B8ýӿ\DAֻ\D4\CA\D0\ED\B5\F7\D3\C3һ\B4Σ\AC\B2\BB\C4\DC\D6ظ\B4\B5\F7\D3ã\AC\C7\EB\BD\F7\C9\F7ʹ\D3\C3\n
CHIP_ID\BF\C9\C4\DC\D2Ѱ\B4\D5\D5CA\B9\AB˾Ҫ\C7\F3\C9\E8\D6ã\AC\B8ýӿ\DA\C8\E7\B9\FB\BFͻ\A7\D0\E8Ҫʹ\D3øýӿ\DA\D0\E8Ҫ\CF\C8֪ͨ\BA\A3˼\n  CNend
\param[in] Id chip id CNcomment:Id chip id\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\see \n
::HI_UNF_ADVCA_SetChipId
*/
HI_S32 HI_UNF_ADVCA_SetChipId(HI_U32 Id);

/**
\brief Obtains the chip ID CNcomment:\BB\F1ȡоƬID  CNend
\attention \n
The chip ID is read-only.
CNcomment:оƬIDֻ\C4ܶ\C1\B2\BB\C4\DCд CNend
\param[out] pu32ChipId Chip ID CNcomment:pu32ChipId   оƬID  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetChipId(HI_U32 *pu32ChipId);


/**
\brief Obtains the market ID CNcomment:\BB\F1ȡMarket ID  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8MarketId market ID CNcomment:pu8MarketId   \D5\EB\B6\D4\CAг\A1\B5ı\EAʶ\D0\F2\BA\C5 CNend
\param[in] u32MarketIdLen market ID length, must be equal to 4 CNcomment:u32MarketIdLen   \D5\EB\B6\D4\CAг\A1\B5ı\EAʶ\D0\F2\BAų\A4\B6ȣ\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetMarketId
*/
HI_S32 HI_UNF_ADVCA_GetMarketId(HI_U8 *pu8MarketId, HI_U32 u32MarketIdLen);

/**
\brief Sets the Market ID CNcomment:\C9\E8\D6\C3Market ID  CNend
\attention \n
The market ID of the set-top box (STB) is set before delivery. The market ID can be set once only and takes effects after the STB restarts.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE \C9\E8\D6ú\F3\D6\D8\C6\F4\C9\FAЧ CNend
\param[in] pu8MarketId market ID CNcomment:pu8MarketId   \D5\EB\B6\D4\CAг\A1\B5ı\EAʶ\D0\F2\BA\C5 CNend
\param[in] u32MarketIdLen market ID length, must be equal to 4 CNcomment:u32MarketIdLen   \D5\EB\B6\D4\CAг\A1\B5ı\EAʶ\D0\F2\BAų\A4\B6ȣ\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetMarketId(HI_U8 *pu8MarketId, HI_U32 u32MarketIdLen);

/**
\brief Obtains the serial number of the STB CNcomment:\BB\F1ȡ\BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8StbSn Serial number of the STB CNcomment:pu8StbSn   \BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\param[in] u32StbSnLen Serial number length, must be equal to 4 CNcomment:u32StbSnLen   \BB\FA\B6\A5\BA\D0\D0\F2\C1кţ\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetStbSn
*/
HI_S32 HI_UNF_ADVCA_GetStbSn(HI_U8 *pu8StbSn, HI_U32 u32StbSnLen);

/**
\brief Sets the serial number of the STB CNcomment:\C9\E8\D6û\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\attention \n
The serial number of the STB is set before delivery. The market ID can be set once only and takes effects after the STB restarts.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE \C9\E8\D6ú\F3\D6\D8\C6\F4\C9\FAЧ CNend
\param[in] pu8StbSn serial number of the STB CNcomment:pu8StbSn   \BB\FA\B6\A5\BA\D0\D0\F2\C1к\C5 CNend
\param[in] u32StbSnLen Serial number length, must be equal to 4 CNcomment:u32StbSnLen   \BB\FA\B6\A5\BA\D0\D0\F2\C1кţ\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetStbSn(HI_U8 *pu8StbSn, HI_U32 u32StbSnLen);

/**
\brief Set the R2R RootKey and lock it. CNcomment:\C9\E8\D6\C3R2R RootKey\B2\A2\C7\D2\CB\F8ס\A1\A3  CNend
\attention \n
This application programming interface (API) is allowed to invoked only once.
It's not allowed to call this API repeatedly.
R2R RootKey should have been setting before chipset is delivered to STB Manufacture.
Please contact Hisilicon before Customer try to use this interface.
CNcomment:\B8ýӿ\DAֻ\D4\CA\D0\ED\B5\F7\D3\C3һ\B4Σ\AC\B2\BB\C4\DC\D6ظ\B4\B5\F7\D3\C3,\C7\EB\BD\F7\C9\F7ʹ\D3øýӿ\DA\n
R2RRootKey\BF\C9\C4\DC\D2Ѱ\B4\D5\D5CA\B9\AB˾Ҫ\C7\F3\C9\E8\D6ã\AC\B8ýӿ\DA\C8\E7\B9\FB\BFͻ\A7\D0\E8Ҫʹ\D3øýӿ\DA\D0\E8Ҫ\CF\C8֪ͨ\BA\A3˼\n  CNend
\param[in] pkey R2R Root Key CNcomment:pkey  R2R\B8\F9\C3\DCԿ\n  CNend
\param[in] u32KeyLen R2R Root key length, must be equal to 16. CNcomment:u32KeyLen R2R\B8\F9\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
*/
HI_S32 HI_UNF_ADVCA_SetR2RRootKey(HI_U8* pkey, HI_U32 u32KeyLen);

/**
\brief Obtains the security startup enable status CNcomment:\BB\F1ȡ\B0\B2ȫ\C6\F4\B6\AFʹ\C4\DC״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbEnable: Security startup enable. CNcomment:pbEnable   \B0\B2ȫ\C6\F4\B6\AF\CAǷ\F1ʹ\C4ܣ\AC CNend
HI_TRUE enabled CNcomment:HI_TRUE ʹ\C4ܣ\AC  CNend
HI_FALSE disabled CNcomment:HI_FALSE \B2\BBʹ\C4\DC CNend
\param[out] penFlashType the startup flash type, only valid when SCS is enable
CNcomment:penFlashType \BD\F6\D4ڰ\B2ȫ\C6\F4\B6\AFʹ\C4\DCʱ\D3\D0Ч\A3\AC\B1\EDʾ\B0\B2ȫ\C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetSecBootStat(HI_BOOL *pbEnable,HI_UNF_ADVCA_FLASH_TYPE_E *penFlashType);

/**
\brief Obtains the mode of the JTAG interface CNcomment:\BB\F1ȡJTAG\B5\F7\CAԿ\DAģʽ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penJtagMode Mode of the JTAG interface CNcomment:penJtagMode   JTAG\B5\F7\CAԿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_ADVCA_GetJtagMode(HI_UNF_ADVCA_JTAG_MODE_E *penJtagMode);

/**
\brief Sets the mode of the JTAG interface CNcomment:\C9\E8\D6\C3JTAG\B5\F7\CAԿ\DAģʽ   CNend
\attention \n
If the mode of the JTAG interface is set to closed or password-protected, it cannot be opened.
If the JTAG interface is open, it can be closed or password-protected.
If the JATG interface is password-protected, it can be closed.
After being closed, the JATG interface cannot be set to open or password-protected mode.
CNcomment:\B2\BB֧\B3\D6\C9\E8\D6\C3Ϊ\B4\F2\BF\AA״̬\A1\A3\n
\B4򿪵\C4ʱ\BA\F2\BF\C9\D2Թرջ\F2\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬\A1\A3\n
\B4\A6\D3\DA\C3\DCԿ\B1\A3\BB\A4״̬ʱ\BF\C9\D2Թرա\A3\n
\B9ر\D5֮\BA\F3\B2\BB\C4ܴ򿪺\CD\C9\E8\D6\C3Ϊ\C3\DCԿ\B1\A3\BB\A4״̬ CNend
\param[in] enJtagMode Mode of the JTAG interface CNcomment:enJtagMode   JTAG\B5\F7\CAԿ\DAģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
::HI_UNF_ADVCA_JTAG_MODE_E
*/
HI_S32 HI_UNF_ADVCA_SetJtagMode(HI_UNF_ADVCA_JTAG_MODE_E enJtagMode);


/**
\brief Obtains the R2R key ladder stage CNcomment:\BB\F1ȡR2R key ladder\BC\B6\CA\FD CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penStage Key ladder stage CNcomment:penStage   key ladder\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_GetR2RKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E *penStage);

/**
\brief Sets the R2R key ladder stage CNcomment:\C9\E8\D6\C3R2R key ladder\B5ļ\B6\CA\FD    CNend
\attention \n
The key ladder stage can be set only once before delivery and cannot be changed. Please use default value.
CNcomment:\BB\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6\C3 \BD\F6\C4\DC\C9\E8\D6\C3һ\B4\CE \B2\BB\BFɸ\FC\B8\C4,\B2\BB\BD\A8\D2\E9ʹ\D3øýӿڸı\E4stage  CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3
CNcomment:enStage   key ladder\BC\B6\CA\FD\n ȡֵֻ\C4\DCΪHI_UNF_ADVCA_KEYLADDER_LEV2 \BB\F2\D5\DF HI_UNF_ADVCA_KEYLADDER_LEV3  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_SetR2RKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage);

/**
\brief Obtains the digital video broadcasting (DVB) key ladder stage CNcomment:\BB\F1ȡDVB key ladder\B5ļ\B6\CA\FD CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penStage Key ladder stage CNcomment:penStage   key ladder\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_GetDVBKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E *penStage);

/**
\brief Sets the DVB key ladder stage CNcomment:\C9\E8\D6\C3DVB key ladder\B5ļ\B6\CA\FD    CNend
\attention \n
The key ladder stage can be set only once before delivery and cannot be changed. Please use default value.
CNcomment:\BB\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6\C3 \BD\F6\C4\DC\C9\E8\D6\C3һ\B4\CE \B2\BB\BFɸ\FC\B8\C4,\B2\BB\BD\A8\D2\E9ʹ\D3øýӿڸı\E4stage  CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage  key ladder\BC\B6\CA\FD\n ȡֵֻ\C4\DCΪHI_UNF_ADVCA_KEYLADDER_lev2 \BB\F2\D5\DF HI_UNF_ADVCA_KEYLADDER_lev3  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_SetDVBKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage);

/**
\brief Obtains the CSA3 key ladder stage CNcomment:\BB\F1ȡCSA3 key ladder\B5ļ\B6\CA\FD CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penStage Key ladder stage CNcomment:penStage   key ladder\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_GetCSA3KeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E *penStage);

/**
\brief Sets the CSA3 key ladder stage CNcomment:\C9\E8\D6\C3CSA3 key ladder\B5ļ\B6\CA\FD    CNend
\attention \n
The key ladder stage can be set only once before delivery and cannot be changed. Please use default value.
CNcomment:\BB\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6\C3 \BD\F6\C4\DC\C9\E8\D6\C3һ\B4\CE \B2\BB\BFɸ\FC\B8\C4,\B2\BB\BD\A8\D2\E9ʹ\D3øýӿڸı\E4stage  CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage  key ladder\BC\B6\CA\FD\n ȡֵֻ\C4\DCΪHI_UNF_ADVCA_KEYLADDER_lev2 \BB\F2\D5\DF HI_UNF_ADVCA_KEYLADDER_lev3  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_SetCSA3KeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage);

/**
\brief Sets session keys for an R2R key ladder CNcomment:ΪR2R key ladder\C5\E4\D6ûỰ\C3\DCԿ    CNend
\attention \n

The stage of the session key cannot be greater than the configured stage of the key ladder. The last stage of the session key is configured by calling the API of the CIPHER module rather than this API.
That is, only session key 1 and session key 2 need to be configured for a 3-stage key ladder.
Only session key 1 needs to be configured for a 2-stage key ladder.
You need to set the key ladder stage by calling HI_UNF_ADVCA_SetR2RKeyLadderStage first.
Session keys can be set during initialization or changed at any time.
CNcomment:ע\D2\E2\C5\E4\D6õļ\B6\CA\FD\B2\BB\C4ܳ\AC\B9\FD\C9\E8\D6õļ\B6\CA\FDֵ\A3\AC\D7\EE\BA\F3һ\BC\B6\D3\C9CIPHERģ\BF\E9\C4ڲ\BF\C5\E4\D6ã\AC\B2\BB\D3\C3ͨ\B9\FD\B4˽ӿ\DA\C5\E4\D6á\A3\n
Ҳ\BE\CD\CA\C7˵\A3\AC\B6\D4\D3\DA3\BC\B6key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\BAͻỰ\C3\DCԿ2\A1\A3\n
\B6\D4\D3\DA2\BC\B6\B5\C4key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\A1\A3\n
\C7\EB\CFȵ\F7\D3\C3HI_UNF_ADVCA_SetR2RKeyLadderStage\C9\E8\D6\C3key ladder\BC\B6\CA\FD\A1\A3\n
\BBỰ\C3\DCԿ\BF\C9\D2Գ\F5ʼʱ\C9\E8\D6\C3һ\B4Σ\ACҲ\BF\C9\D2\D4\CB\E6ʱ\D0޸ġ\A3 CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage    \C3\DCԿ\BC\B6\CA\FD\A3\AC[HI_UNF_ADVCA_KEYLADDER_LEV1 ~ HI_UNF_ADVCA_KEYLADDER_LEV2]  CNend
\param[in] pu8Key Protection key pointer, 128 bits (16 bytes) in total CNcomment:pu8Key     \B1\A3\BB\A4\C3\DCԿָ\D5룬\B9\B2128bit(16byte)  CNend
\param[in] u32KeyLen Protection key length, must be equal to 16. CNcomment:u32KeyLen \B1\A3\BB\A4\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\retval ::HI_ERR_CA_R2R_DECRYPT The R2R decryption fails CNcomment:HI_ERR_CA_R2R_DECRYPT  R2R\BD\E2\C3\DCʧ\B0\DC CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_SetR2RSessionKey(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage, HI_U8* pu8Key, HI_U32 u32KeyLen);

/**
\brief Sets session keys for a DVB key ladder CNcomment:ΪDVB key ladder\C5\E4\D6ûỰ\C3\DCԿ    CNend
\attention \n
The stage of the session key cannot be greater than the configured stage of the key ladder. The last stage of the session key is configured by calling the API of the CIPHER module rather than this API.
That is, only session key 1 and session key 2 need to be configured for a 3-stage key ladder.
Only session key 1 needs to be configured for a 2-stage key ladder.
You need to set the key ladder stage by calling HI_UNF_ADVCA_SetDVBKeyLadderStage first.
 Session keys can be set during initialization or changed at any time.
CNcomment:ע\D2\E2\C5\E4\D6õļ\B6\CA\FD\B2\BB\C4ܳ\AC\B9\FD\C9\E8\D6õļ\B6\CA\FDֵ\A3\AC\D7\EE\BA\F3һ\BC\B6\D3\C9Descramblerģ\BF\E9\C4ڲ\BF\C5\E4\D6ã\AC\B2\BB\D3\C3ͨ\B9\FD\B4˽ӿ\DA\C5\E4\D6á\A3\n
Ҳ\BE\CD\CA\C7˵\A3\AC\B6\D4\D3\DA3\BC\B6key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\BAͻỰ\C3\DCԿ2\A1\A3\n
\B6\D4\D3\DA2\BC\B6\B5\C4key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\A1\A3\n
\C7\EB\CFȵ\F7\D3\C3HI_UNF_ADVCA_SetDVBKeyLadderStage\C9\E8\D6\C3key ladder\BC\B6\CA\FD\A1\A3\n
\BBỰ\C3\DCԿ\BF\C9\D2Գ\F5ʼʱ\C9\E8\D6\C3һ\B4Σ\ACҲ\BF\C9\D2\D4\CB\E6ʱ\D0޸ġ\A3 CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage    \C3\DCԿ\BC\B6\CA\FD\A3\AC[HI_UNF_ADVCA_KEYLADDER_LEV1 ~ HI_UNF_ADVCA_KEYLADDER_LEV2]  CNend
\param[in] pu8Key Protection key pointer, 128 bits (16 bytes) in total CNcomment:pu8Key     \B1\A3\BB\A4\C3\DCԿָ\D5룬\B9\B2128bit(16byte)  CNend
\param[in] u32KeyLen Protection key length, must be equal to 16. CNcomment:u32KeyLen \B1\A3\BB\A4\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\retval ::HI_ERR_CA_R2R_DECRYPT The CW decryption fails CNcomment:HI_ERR_CA_CW_DECRYPT   CW\BD\E2\C3\DCʧ\B0\DC CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetDVBSessionKey(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage, HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Sets session keys for a CSA3 key ladder CNcomment:ΪCSA3 key ladder\C5\E4\D6ûỰ\C3\DCԿ    CNend
\attention \n
The stage of the session key cannot be greater than the configured stage of the key ladder. The last stage of the session key is configured by calling the API of the CIPHER module rather than this API.
That is, only session key 1 and session key 2 need to be configured for a 3-stage key ladder.
Only session key 1 needs to be configured for a 2-stage key ladder.
You need to set the key ladder stage by calling HI_UNF_ADVCA_SetDVBKeyLadderStage first.
 Session keys can be set during initialization or changed at any time.
CNcomment:ע\D2\E2\C5\E4\D6õļ\B6\CA\FD\B2\BB\C4ܳ\AC\B9\FD\C9\E8\D6õļ\B6\CA\FDֵ\A3\AC\D7\EE\BA\F3һ\BC\B6\D3\C9Descramblerģ\BF\E9\C4ڲ\BF\C5\E4\D6ã\AC\B2\BB\D3\C3ͨ\B9\FD\B4˽ӿ\DA\C5\E4\D6á\A3\n
Ҳ\BE\CD\CA\C7˵\A3\AC\B6\D4\D3\DA3\BC\B6key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\BAͻỰ\C3\DCԿ2\A1\A3\n
\B6\D4\D3\DA2\BC\B6\B5\C4key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\A1\A3\n
\C7\EB\CFȵ\F7\D3\C3HI_UNF_ADVCA_SetDVBKeyLadderStage\C9\E8\D6\C3key ladder\BC\B6\CA\FD\A1\A3\n
\BBỰ\C3\DCԿ\BF\C9\D2Գ\F5ʼʱ\C9\E8\D6\C3һ\B4Σ\ACҲ\BF\C9\D2\D4\CB\E6ʱ\D0޸ġ\A3 CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage    \C3\DCԿ\BC\B6\CA\FD\A3\AC[HI_UNF_ADVCA_KEYLADDER_LEV1 ~ HI_UNF_ADVCA_KEYLADDER_LEV2]  CNend
\param[in] pu8Key Protection key pointer, 128 bits (16 bytes) in total CNcomment:pu8Key     \B1\A3\BB\A4\C3\DCԿָ\D5룬\B9\B2128bit(16byte)  CNend
\param[in] u32KeyLen Protection key length, must be equal to 16. CNcomment:u32KeyLen \B1\A3\BB\A4\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\retval ::HI_ERR_CA_R2R_DECRYPT The CW decryption fails CNcomment:HI_ERR_CA_CW_DECRYPT   CW\BD\E2\C3\DCʧ\B0\DC CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetCSA3SessionKey(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage, HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Set widevine keyladder session key CNcomment:\C9\E8\D6\C3widevine keyladder\B5ĸ\F7\BC\B6\CA\E4\C8\EB\C3\DCԿ CNend
\param[in]  enLevel keyladder level for input CNcomment:enLevel \CA\E4\C8\EB\C3\DCԿ\B5ļ\B6\CA\FD CNend
\param[in]  hCipherHandle cipher handle input when level 3 CNcomment:hCipherHandle \B5\B1\CA\E4\C8\EB\B5\DA\C8\FD\BC\B6\CA\FD\BE\DDʱ\A3\AC\D0\E8Ҫ\B4\AB\C8\EBԤ\CFȴ\B4\BD\A8\BAõ\C4Cipher\B5ľ\E4\B1\FA CNend
\param[in]  pu8Input input data for keyladder CNcomment:pu8Input  keyladder\B5\C4\CA\E4\C8\EB\CA\FD\BE\DD CNend
\param[in]  u32InputLen input data length CNcomment:u32InputLen \CA\FD\BEݵĳ\A4\B6\C8 CNend
\param[out] pu32GdrmFlag the flag value when level 3 CNcomment:pu32GdrmFlag  \B5\B1\CA\E4\C8\EB\B5\DA\C8\FD\BC\B6\B1\F0\C3\DCԿʱ\A3\AC\CA\E4\B3\F6\B5\C4GDRM\B1\EA־  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS               \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT       CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA   \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_NOT_SUPPORT The function is not supported CNcomment:HI_ERR_CA_NOT_SUPPORT    \B9\A6\C4ܲ\BB֧\B3\D6 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT   CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\return ::HI_ERR_CA_SWPK_ENCRYPT SWPK encryption fails CNcomment:HI_ERR_CA_SWPK_ENCRYPT   SWPK\BC\D3\C3\DCʧ\B0\DC CNend
\see
\li ::
*/
HI_S32 HI_UNF_ADVCA_SetGDRMSessionKey(HI_UNF_ADVCA_KEYLADDER_LEV_E enLevel,
                                    HI_HANDLE hCipherHandle,
                                    HI_U8 *pu8Input,
                                    HI_U32 u32InputLen,
                                    HI_U32 *pu32GdrmFlag);


/**
\brief Encrypts software protect keys (SWPKs) CNcomment:\BC\D3\C3\DC\C8\ED\BC\FE\B1\A3\BB\A4\C3\DCԿ CNend
\attention
Before the delivery of the STB, you need to read the SWPKs in plain text format from the flash memory, encrypt SWPKs by calling this API, and store the encrypted SWPKs in the flash memory for security startup.
CNcomment:\BB\FA\B6\A5\BAг\F6\B3\A7ʱ \B4\D3Flash\C9϶\C1ȡ\C3\F7\CEĵ\C4SWPK(Software Protect Key),\B5\F7\D3øýӿڼ\D3\C3\DC,\BD\AB\BC\D3\C3ܵ\C4SWPK\B4洢\D4\DAFlash\D6У\AC\D3\C3\D3ڰ\B2ȫ\C6\F4\B6\AF CNend
The fist 8 bytes of the SWPK can't be equal to the last 8 bytes.
CNcomment:SWPK\B5\C4ǰ8\B8\F6\D7ֽ\DA\D3\EB\BA\F38\B8\F6\D7ֽڲ\BB\C4\DC\CF\E0\B5\C8 CNend
This API is only for special CA, please contact Hislicon before usage.
CNcomment:ע\D2\E2:\B4˽ӿ\DAΪ\CCض\A8CAר\D3ã\AC\C8\E7\D0\E8ʹ\D3ã\AC\C7\EB\C1\AAϵ\BA\A3˼ CNend
\param[in]  pPlainSwpk SWPKs in plain text format CNcomment:pPlainSwpk    \C3\F7\CE\C4SWPK  CNend
\param[in] u32PlainSwpkLen SWPK length, must be equal to 16. CNcomment:u32PlainSwpkLen \C3\F7\CE\C4SWPK\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\param[out] pEncryptedSwpk Encrypted SWPKs CNcomment:pEncryptedSwpk  \BC\D3\C3ܺ\F3\B5\C4SWPK  CNend
\param[in] u32PlainSwpkLen Encrypted SWPK length, must be equal to 16. CNcomment:u32PlainSwpkLen \BC\D3\C3ܵ\C4SWPK\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS               \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT       CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA   \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_NOT_SUPPORT The function is not supported CNcomment:HI_ERR_CA_NOT_SUPPORT    \B9\A6\C4ܲ\BB֧\B3\D6 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT   CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\return ::HI_ERR_CA_SWPK_ENCRYPT SWPK encryption fails CNcomment:HI_ERR_CA_SWPK_ENCRYPT   SWPK\BC\D3\C3\DCʧ\B0\DC CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_EncryptSWPK(HI_U8 *pPlainSwpk, HI_U32 u32PlainSwpkLen, HI_U8 *pEncryptedSwpk, HI_U32 u32EncryptedSwpkLen);

/**
\brief Sets the algorithm of the DVB key ladder CNcomment:\C9\E8\D6\C3DVB key ladder\B5\C4\CB㷨    CNend
\attention \n
You must set an algorithm before using a key ladder in a session. The default algorithm is TDES.
It is recommended that you retain the algorithm in a session.
CNcomment:ÿ\B4λỰ\B9\FD\B3\CC\D6\D0ʹ\D3\C3key ladder֮ǰ\A3\AC\D0\EB\C9\E8\D6þ\DF\CC\E5\CB㷨, ϵͳ\B3\F5ʼĬ\C8\CFֵ HI_UNF_ADVCA_ALG_TYPE_TDES\A3\BB\n
\B1\BE\B4λỰ\B9\FD\B3\CC\D6У\AC\BD\A8\D2鱣\B3\D6\CB㷨\B5\C4\CEȶ\A8\B2\BB\B1䡣 CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_SetDVBAlg(HI_UNF_ADVCA_ALG_TYPE_E enType);

/**
\brief Sets the algorithm of the CSA2 key ladder CNcomment:\C9\E8\D6\C3CSA3 key ladder\B5\C4\CB㷨    CNend
\attention \n
You must set an algorithm before using a key ladder in a session. The default algorithm is TDES.
It is recommended that you retain the algorithm in a session.
CNcomment:ÿ\B4λỰ\B9\FD\B3\CC\D6\D0ʹ\D3\C3key ladder֮ǰ\A3\AC\D0\EB\C9\E8\D6þ\DF\CC\E5\CB㷨, ϵͳ\B3\F5ʼĬ\C8\CFֵ HI_UNF_ADVCA_ALG_TYPE_TDES\A3\BB\n
\B1\BE\B4λỰ\B9\FD\B3\CC\D6У\AC\BD\A8\D2鱣\B3\D6\CB㷨\B5\C4\CEȶ\A8\B2\BB\B1䡣 CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_SetCSA3Alg(HI_UNF_ADVCA_ALG_TYPE_E enType);

/**
\brief Sets the algorithm of the R2R key ladder CNcomment:\C9\E8\D6\C3R2R key ladder\B5\C4\CB㷨    CNend
\attention \n
You must set an algorithm before using a key ladder in a session. The default algorithm is TDES.
It is recommended that you retain the algorithm in a session.
CNcomment:ÿ\B4λỰ\B9\FD\B3\CC\D6\D0ʹ\D3\C3key ladder֮ǰ\A3\AC\D0\EB\C9\E8\D6þ\DF\CC\E5\CB㷨, ϵͳ\B3\F5ʼĬ\C8\CFֵ HI_UNF_ADVCA_ALG_TYPE_TDES\A3\BB\n
\B1\BE\B4λỰ\B9\FD\B3\CC\D6У\AC\BD\A8\D2鱣\B3\D6\CB㷨\B5\C4\CEȶ\A8\B2\BB\B1䡣 CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_SetR2RAlg(HI_UNF_ADVCA_ALG_TYPE_E enType);

/**
\brief Obtains the algorithm of the DVB key ladder CNcomment: \BB\F1ȡ DVB key ladder\B5\C4\CB㷨    CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pEnType Key ladder algorithm CNcomment:pEnType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_GetDVBAlg(HI_UNF_ADVCA_ALG_TYPE_E *pEnType);

/**
\brief Obtains the algorithm of the R2R key ladder CNcomment:\BB\F1ȡ R2R key ladder\B5\C4\CB㷨    CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_GetR2RAlg(HI_UNF_ADVCA_ALG_TYPE_E *pEnType);

/**
  \brief set RSA key CNcomment:\C9\E8\D6\C3ǩ\C3\FBУ\D1\E9\B5\C4RSA\B9\ABԿ CNeng
  \attention \n
  If the mass-produced chipset have been set RSA Key by CA, there's no need to use this API to set RSA Key again.
  This API can been called only once, please be careful, after setting RSA key, you should lock it by call API
  HI_UNF_ADVCA_ConfigLockFlag.The length of RSA key must be 512 Bytes.
  CNcomment:\C8\E7\B9\FB\C1\BF\B2\FAоƬ\D2Ѿ\AD\B0\B4\D5\D5CA\B9\AB˾\C9\E8\D6\C3RSAKey,\D4\F2\CE\DE\D0\E8\D4ٴ\CEʹ\D3øýӿ\DA\C9\E8\D6\C3RSAKey\n
     \B8ýӿ\DAֻ\D4\CA\D0\ED\B5\F7\D3\C3һ\B4Σ\AC\B2\BB\C4\DC\D6ظ\B4\B5\F7\D3\C3,\C7\EB\BD\F7\C9\F7ʹ\D3øýӿ\DA,\B2\A2\C7\D2\C9\E8\D6ú\F3RSAKey\BA\F3\D0\E8Ҫʹ\D3ýӿ\DA\n
     HI_UNF_ADVCA_ConfigLockFlag\BD\F8\D0\D0\CB\F8\B6\A8\A1\A3 RSA key\B5ĳ\A4\B6ȱ\D8\D0\EBΪ512 Bytes  CNend
  \param[in] pkey RSA key CNcomment:pkey  RSA\B9\ABԿ\n  CNend
  \param[in] u32KeyLen RSA key length, must be equal to 512. CNcomment:u32KeyLen RSA\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ512 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetRSAKey(HI_U8 *pkey, HI_U32 u32KeyLen);

/**
  \brief set RSA key CNcomment:\BB\F1ȡǩ\C3\FBУ\D1\E9\B5\C4RSA\B9\ABԿ CNend
  \attention \n
     RSA key can be read out when only the RSAKey is not locked,The length of RSA key is 512 Bytes.
     RSA key should have been setting and lock before chipset is delivered to STB Manufacture.
     Please contact Hisilicon before Customer try to use this interface.
  CNcomment:\B8ýӿڽ\F6\D4\DARSAkeyû\D3б\BB\CB\F8\B6\A8\B5\C4\C7\E9\BF\F6\CF£\AC\B6\C1ȡ\B3\F6\C0\B4, RSA key\B5ĳ\A4\B6\C8Ϊ512 Bytes\n
     RSA key\BF\C9\C4\DC\D2Ѱ\B4\D5\D5CA\B9\AB˾Ҫ\C7\F3\C9\E8\D6ò\A2\CB\F8\B6\A8\A3\AC\B8ýӿ\DA\C8\E7\B9\FB\BFͻ\A7\D0\E8Ҫʹ\D3øýӿ\DA\D0\E8Ҫ\CF\C8֪ͨ\BA\A3˼\n  CNend
  \param[out] pkey RSA key CNcomment:pkey  RSA\C3ܹ\ABԿ\n  CNend
  \param[in] u32KeyLen RSA key length, must be equal to 512. CNcomment:u32KeyLen RSA\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ512 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetRSAKey(HI_U8 *pkey, HI_U32 u32KeyLen);

/**
  \brief set RSA key CNcomment:\BB\F1ȡǩ\C3\FBУ\D1\E9\B5\C4RSA\C3\DC\C2\EB CNend
  \attention \n
    This API is used to lock RSA KEY/Trustzone OTP\misc keyladder etc.Please contact Hisilicon before Customer try to use this interface.
  CNcomment:\B8ýӿ\DA\D3\C3\D3\DA\CB\F8\B6\A8RSAkey\Trustzone OTP\misc keyladder\B5ȣ\AC\B8ýӿ\DA\C8\E7\B9\FB\BFͻ\A7\D0\E8Ҫʹ\D3øýӿ\DA\D0\E8Ҫ\CF\C8֪ͨ\BA\A3˼\n  CNend
  \param[enType] enType the type you want to lock.  CNcomment:enType  \D0\E8Ҫ\CB\F8\B6\A8\B5\C4\C0\E0\D0\CD\n  CNend
  \param[pu8ParamIn] pu8ParamIn reserved, default is null. CNcomment:pu8ParamIn  Ԥ\C1\F4\A3\ACĬ\C8\CFΪnull\n  CNend
  \param[u32ParamLen] u32ParamLen reserved, default is 0. CNcomment:u32ParamLen  Ԥ\C1\F4\A3\ACĬ\C8\CFΪ0\n  CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_ConfigLockFlag(HI_UNF_ADVCA_LOCK_TYPE_E enType, HI_U8 *pu8ParamIn, HI_U32 u32ParamLen);


/**
  \brief This function is used to check if the MarketID is already set
  \attention \n
  None
  \param[in] pbIsMarketIdSet: the pointer point to the buffer to store the return value
  \param[out] pbIsMarketIdSet: save the return value
  \retval ::HI_SUCCESS Success
  \retval ::HI_FAILURE This API fails to be called
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_IsMarketIdSet(HI_BOOL *pbIsMarketIdSet);

/**
  \brief This function is used to get the vendor type of the chipset
  \attention \n
  None
  \param[out] pu32VendorID: The number indicates the vendor id
  \retval ::HI_SUCCESS Success
  \retval ::HI_FAILURE This API fails to be called
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetVendorID(HI_U32 *pu32VendorID);

/**
\brief Enables the security startup function and sets the type of flash memory for security startup
CNcomment:\C9\E8\D6ð\B2ȫ\C6\F4\B6\AFʹ\C4\DC,ͬʱָ\B6\A8\B0\B2ȫ\C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\attention \n
This function can be enabled only and cannot be disabled after being enabled.
CNcomment:ֻ\C4\DCʹ\C4ܣ\ACʹ\C4\DC֮\BA󲻿\C9\D0޸ġ\A3 CNend
\param[in]  enFlashType Type of the flash memory for security startup CNcomment:enFlashType  \C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_EnableSecBoot(HI_UNF_ADVCA_FLASH_TYPE_E enFlashType);

/**
\brief Enables the security startup function. This API should be used with the API HI_UNF_ADVCA_SetFlashTypeEx.
CNcomment:\C9\E8\D6ð\B2ȫ\C6\F4\B6\AFʹ\C4ܣ\AC\B8ýӿڱ\D8\D0\EB\BA\CDHI_UNF_ADVCA_SetFlashTypeEx\C5\E4\CC\D7ʹ\D3á\A3 CNend
\attention \n
\param[in]  None
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_EnableSecBootEx(HI_VOID);

/**
\brief Sets the type of flash memory for security startup and disable the self boot, which mean that you cannot use the serial port to update the boot. This API should be used with the API HI_UNF_ADVCA_EnableSecBootEx
CNcomment:ָ\B6\A8\B0\B2ȫ\C6\F4\B6\AF\B5\C4Flash\C0\E0\D0ͣ\ACͬʱ\B9ر\D5\D7Ծٹ\A6\C4ܣ\AC\BC\B4\B2\BB\C4\DCͨ\B9\FD\B4\AE\BF\DA\C9\FD\BC\B6fastboot\A1\A3\B8ýӿڸ\FAHI_UNF_ADVCA_EnableSecBootEx\C5\E4\CC\D7ʹ\D3\C3 CNend
\attention \n
The setting is performed before delivery and can be performed once only.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE CNend
\param[in]  enFlashType Type of the flash memory for security startup CNcomment:enFlashType  \C6\F4\B6\AF\B5\C4Flash\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetFlashTypeEx(HI_UNF_ADVCA_FLASH_TYPE_E enFlashType);

/**
\brief  Sets whether to use hardware CWs only CNcomment:\C9\E8\D6ù̶\A8ʹ\D3\C3Ӳ\BC\FECW\D7\D6 CNend
\attention
The setting is performed before delivery and can be performed once only.
By default, the CW type (hardware CWs or software CWs) depends on the configuration of the DEMUX.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8ϸ\F9\BE\DDDemux\B5\C4\C5\E4\D6\C3ѡ\D4\F1ʹ\D3\C3Ӳ\BC\FECW\D7ֻ\B9\CA\C7\C8\ED\BC\FECW\D7\D6 CNend
\param  none
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\return ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN    \D6ظ\B4\C9\E8\D6ò\CE\CA\FD CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_LockHardCwSel(HI_VOID);

/**
\brief Disables the self-boot function CNcomment:\B9ر\D5SelfBoot\B9\A6\C4\DC,Ҳ\BE\CD\CA\C7boot\CF²\BB\C4\DCʹ\D3ô\AE\BF\DA/\CD\F8\BF\DA\C9\FD\BC\B6 CNend
\attention
The setting is performed before delivery and can be performed once only.
The self-boot function is enabled by default.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8\CFʹ\C4\DCSelfBoot\B9\A6\C4\DC CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized.  CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\return ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN    \D6ظ\B4\C9\E8\D6ò\CE\CA\FD CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_DisableSelfBoot(HI_VOID);

/**
\brief Obtains the self-boot status CNcomment:\BB\F1ȡSelfBoot״̬ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pbDisable: self-boot status. CNcomment:pbEnable   SelfBoot\CAǷ\F1\BD\FB\D3\C3 CNend
HI_TRUE enabled CNcomment:HI_TRUE \BD\FB\D3ã\AC  CNend
HI_FALSE disabled CNcomment:HI_FALSE δ\BD\FB\D3\C3 CNend

\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetSelfBootStat(HI_BOOL *pbDisable);

/**
+\brief  Get whether to use hardware CWs only CNcomment:\BB\F1ȡ\B9̶\A8ʹ\D3\C3Ӳ\BC\FECW\D7ֱ\EA־ CNend
+\attention
+None CNcomment:\CE\DE CNend
\param[out] pbLock indicates the state of hardware CWs  CNcomment:pbLock Ӳ\BC\FECW\D7ֵı\EA־λ CNend

\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetHardCwSelStat(HI_BOOL *pbLock);

/**
\brief  Open the SWPK key ladder CNcomment:\B4\F2\BF\AAboot key ladder  CNend
\attention
\param  none

\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SWPKKeyLadderOpen(HI_VOID);

/**
\brief  Close the SWPK key ladder CNcomment:\B9ر\D5boot key ladder  CNend
\attention
\param  none

\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SWPKKeyLadderClose(HI_VOID);

/**
\brief Obtains the Version ID CNcomment:\BB\F1ȡVersion ID  CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu8VersionId Version ID CNcomment:pu8VersionId   \B0汾\BAű\EA־ CNend
\param[in] u32VersionIdLen Version ID length, must be equal to 4 CNcomment:u32VersionIdLen   \B0汾\BAű\EA־\A3\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_SetVersionId
*/
HI_S32 HI_UNF_ADVCA_GetVersionId(HI_U8 *pu8VersionId, HI_U32 u32VersionIdLen);

/**
\brief Sets the Version ID CNcomment:\C9\E8\D6\C3Version ID  CNend
\attention \n
The version ID of the set-top box (STB) is set before delivery. The version ID can be set once only and takes effects after the STB restarts.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE \C9\E8\D6ú\F3\D6\D8\C6\F4\C9\FAЧ CNend
\param[in] pu8VersionId version ID CNcomment:pu8VersionId   \B0汾\BAű\EA־ CNend
\param[in] u32VersionIdLen Version ID length, must be equal to 4 CNcomment:u32VersionIdLen   \B0汾\BAű\EA־\A3\AC\B1\D8\D0\EB\B5\C8\D3\DA4 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN  \D6ظ\B4\C9\E8\D6\C3 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetVersionId(HI_U8 *pu8VersionId, HI_U32 u32VersionIdLen);

/**
\brief  Sets whether to check the boot version CNcomment:\C9\E8\D6\C3\CAǷ\F1\BC\EC\B2\E9Version  CNend
\attention
The setting is performed before delivery and can be performed once only.
By default, the version check function is disabled
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8ϲ\BBʹ\C4\DCversion check  CNend
\param  none
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\return ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN    \D6ظ\B4\C9\E8\D6ò\CE\CA\FD CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_EnableVersionCheck(HI_VOID);

/**
\brief  Get the boot version check flag CNcomment:\BB\F1ȡ\CAǷ\F1\BC\EC\B2\E9version\B5ı\EA־λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu32Stat boot version check flag CNcomment:pu32Stat    version\BC\EC\B2\E9\B5ı\EA־λ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetVersionCheckStat(HI_U32 *pu32Stat);

/**
\brief  Sets whether to check the MSID in boot area CNcomment:\C9\E8\D6\C3\CAǷ\F1\BC\EC\B2\E9boot area\B5\C4MSID  CNend
\attention
The setting is performed before delivery and can be performed once only.
By default, the boot MSID check function is disabled
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8ϲ\BBʹ\C4\DCboot MSID check  CNend
\param none
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\return ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN    \D6ظ\B4\C9\E8\D6ò\CE\CA\FD CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_EnableBootMSIDCheck(HI_VOID);

/**
\brief  Get the boot MSID check flag CNcomment:\BB\F1ȡ\CAǷ\F1\BC\EC\B2\E9MSID\B5ı\EA־λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu32Stat boot MSID check flag CNcomment:pu32Stat    MSID\BC\EC\B2\E9\B5ı\EA־λ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetBootMSIDCheckStat(HI_U32 *pu32Stat);

/**
\brief  Get the software revision
CNcomment:\BB\F1ȡ\C8\ED\BC\FE\B5\C4revision\B0汾\BA\C5 CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] revision string of Revision CNcomment:revision    Revision\B0汾\BA\C5 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetRevision(HI_U8 revision[25]);

/**
\brief  Set the DDR Scramble flag. Normally, this flag has been set as required by CA vendor
CNcomment:\C9\E8\D6\C3DDR\BC\D3\C8ű\EA־λ\A3\ACһ\B0\E3\B8߰\B2оƬ\B3\F6\B3\A7ʱ\D2Ѱ\B4\D5\D5CA\B9\AB˾Ҫ\C7\F3\C9\E8\D6\C3 CNend
\attention \n
None CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetDDRScramble(HI_VOID);

/**
\brief  Get the DDR Scramble flag
CNcomment:\BB\F1ȡDDR\BC\D3\C8ű\EA־λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu32Stat DDR Scramble flag CNcomment:pu32Stat    DDR\BC\D3\C8ű\EA־ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetDDRScrambleStat(HI_U32 *pu32Stat);

/**
\brief Sets whether to decrypt the BootLoader CNcomment:\C9\E8\D6ñ\D8\D0\EB\B6\D4BootLoader\BD\F8\D0н\E2\C3\DC CNend
\attention
The setting is performed before delivery and can be performed once only.
CNcomment:\D4ڻ\FA\B6\A5\BAг\F6\B3\A7ʱѡ\D4\F1\CAǷ\F1\C9\E8\D6ã\AC\BD\F6֧\B3\D6\C9\E8\D6\C3һ\B4\CE
Ĭ\C8ϸ\F9\BE\DDFlash\D6е\C4\CA\FD\BEݱ\EAʶ\A3\AC\BE\F6\B6\A8BootLoader\CAǷ\F1\D0\E8Ҫ\BD\E2\C3\DC CNend

\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS                  \B3ɹ\A6 CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT          CAδ\B3\F5ʼ\BB\AF CNend
\return ::HI_ERR_CA_SETPARAM_AGAIN The parameter has been set CNcomment:HI_ERR_CA_SETPARAM_AGAIN    \D6ظ\B4\C9\E8\D6ò\CE\CA\FD CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_LockBootDecEn(HI_VOID);

/**
\brief Get the BootLoader Decryption flag CNcomment:\BB\F1ȡBootLoader\BD\E2\C3ܵı\EA־λ CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] pu32Stat BootLoader Decryption flag CNcomment:pu32Stat    Bootloader\BD\E2\C3ܱ\EA־λ CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized CNcomment:HI_ERR_CA_NOT_INIT  CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA  \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetBootDecEnStat(HI_U32 *pu32Stat);



/**
\brief  Calculte the AES_CMAC value of data
CNcomment: \BC\C6\CB\E3\CA\FD\BEݵ\C4AES_CMAC ֵ CNend
\attention \n
None CNcomment:\CE\DE CNend

\param[in]  buffer  pointer of data buffer .        CNcomment:\CA\FD\BE\DDbuffer ָ\D5\EB CNend
\param[in]  Length  The length  of data .   CNcomment:\CA\FD\BEݳ\A4\B6\C8 CNend
\param[in]  pKey   The key used in Calculte the AES_CMAC of data           CNcomment:pKey AES_CMAC \BC\C6\CB\E3\D6\D0ʹ\D3õ\C4key  CNend
\param[in] u32KeyLen pKey length, must be equal to 16. CNcomment:u32KeyLen \C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\param[out]  pCMAC   The AES_CMAC value          CNcomment:pCMAC AES_CMAC ֵ CNend
\param[in] u32CMACLen AES_CMAC length, must be equal to 16. CNcomment:u32CMACLen AES_CMAC\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS  Success                 CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE    Failure                     CNcomment:ʧ\B0\DC CNend
\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_CalculteAES_CMAC(HI_U8 *buffer, HI_U32 Length, HI_U8 *pKey, HI_U32 u32KeyLen, HI_U8 *pCMAC, HI_U32 u32CMACLen);

/**
\brief Sets the algorithm of the SP key ladder CNcomment:\C9\E8\D6\C3SP key ladder\B5\C4\CB㷨    CNend
\attention \n
You must set an algorithm before using a key ladder in a session. The default algorithm is TDES.
It is recommended that you retain the algorithm in a session.
CNcomment:ÿ\B4λỰ\B9\FD\B3\CC\D6\D0ʹ\D3\C3key ladder֮ǰ\A3\AC\D0\EB\C9\E8\D6þ\DF\CC\E5\CB㷨, ϵͳ\B3\F5ʼĬ\C8\CFֵ HI_UNF_ADVCA_ALG_TYPE_TDES\A3\BB\n
\B1\BE\B4λỰ\B9\FD\B3\CC\D6У\AC\BD\A8\D2鱣\B3\D6\CB㷨\B5\C4\CEȶ\A8\B2\BB\B1䡣 CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_SetSPAlg(HI_UNF_ADVCA_ALG_TYPE_E enType);

/**
\brief Obtains the algorithm of the SP key ladder CNcomment: \BB\F1ȡ SP key ladder\B5\C4\CB㷨    CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pEnType Key ladder algorithm CNcomment:pEnType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_GetSPAlg(HI_UNF_ADVCA_ALG_TYPE_E *pEnType);

/**
\brief Sets the SP key ladder stage CNcomment:\C9\E8\D6\C3SP key ladder\B5ļ\B6\CA\FD    CNend
\attention \n
The key ladder stage can be set only once before delivery and cannot be changed. Please use default value.
CNcomment:\BB\FA\B6\A5\BAг\F6\B3\A7ʱ\C9\E8\D6\C3 \BD\F6\C4\DC\C9\E8\D6\C3һ\B4\CE \B2\BB\BFɸ\FC\B8\C4,\B2\BB\BD\A8\D2\E9ʹ\D3øýӿڸı\E4stage  CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage  key ladder\BC\B6\CA\FD\n ȡֵֻ\C4\DCΪHI_UNF_ADVCA_KEYLADDER_lev2 \BB\F2\D5\DF HI_UNF_ADVCA_KEYLADDER_lev3  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_SetSPKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage);

/**
\brief Obtains the SP key ladder stage CNcomment:\BB\F1ȡSP key ladder\B5ļ\B6\CA\FD CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[out] penStage Key ladder stage CNcomment:penStage   key ladder\BC\B6\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_KEYLADDER_LEV_E
*/
HI_S32 HI_UNF_ADVCA_GetSPKeyLadderStage(HI_UNF_ADVCA_KEYLADDER_LEV_E *penStage);


/**
\brief Sets session keys for a SP key ladder CNcomment:ΪSP key ladder\C5\E4\D6ûỰ\C3\DCԿ    CNend
\attention \n
The stage of the session key cannot be greater than the configured stage of the key ladder. The last stage of the session key is configured by calling the API of the CIPHER module rather than this API.
That is, only session key 1 and session key 2 need to be configured for a 3-stage key ladder.
Only session key 1 needs to be configured for a 2-stage key ladder.
You need to set the key ladder stage by calling HI_UNF_ADVCA_SetSPKeyLadderStage first.
 Session keys can be set during initialization or changed at any time.
CNcomment:ע\D2\E2\C5\E4\D6õļ\B6\CA\FD\B2\BB\C4ܳ\AC\B9\FD\C9\E8\D6õļ\B6\CA\FDֵ\A3\AC\D7\EE\BA\F3һ\BC\B6\D3\C9Descramblerģ\BF\E9\C4ڲ\BF\C5\E4\D6ã\AC\B2\BB\D3\C3ͨ\B9\FD\B4˽ӿ\DA\C5\E4\D6á\A3\n
Ҳ\BE\CD\CA\C7˵\A3\AC\B6\D4\D3\DA3\BC\B6key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\BAͻỰ\C3\DCԿ2\A1\A3\n
\B6\D4\D3\DA2\BC\B6\B5\C4key ladder\A3\ACֻ\D3\C3\C5\E4\D6ûỰ\C3\DCԿ1\A1\A3\n
\C7\EB\CFȵ\F7\D3\C3HI_UNF_ADVCA_SetSPKeyLadderStage\C9\E8\D6\C3key ladder\BC\B6\CA\FD\A1\A3\n
\BBỰ\C3\DCԿ\BF\C9\D2Գ\F5ʼʱ\C9\E8\D6\C3һ\B4Σ\ACҲ\BF\C9\D2\D4\CB\E6ʱ\D0޸ġ\A3 CNend
\param[in] enStage Key ladder stage Its value is HI_UNF_ADVCA_KEYLADDER_LEV2 or HI_UNF_ADVCA_KEYLADDER_LEV3.
CNcomment:enStage    \C3\DCԿ\BC\B6\CA\FD\A3\AC[HI_UNF_ADVCA_KEYLADDER_LEV1 ~ HI_UNF_ADVCA_KEYLADDER_LEV2]  CNend
\param[in] pu8Key Protection key pointer, 128 bits (16 bytes) in total CNcomment:pu8Key     \B1\A3\BB\A4\C3\DCԿָ\D5룬\B9\B2128bit(16byte)  CNend
\param[in] u32KeyLen Protection key length, must be equal to 16. CNcomment:u32KeyLen \B1\A3\BB\A4\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_WAIT_TIMEOUT Timeout occurs when the CA module waits for encryption or decryption
CNcomment:HI_ERR_CA_WAIT_TIMEOUT CA\B5ȴ\FD\BCӽ\E2\C3ܳ\ACʱ CNend
\retval ::HI_ERR_CA_R2R_DECRYPT The CW decryption fails CNcomment:HI_ERR_CA_CW_DECRYPT   CW\BD\E2\C3\DCʧ\B0\DC CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetSPSessionKey(HI_UNF_ADVCA_KEYLADDER_LEV_E enStage, HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
\brief Sets the descramble mode of the SP key ladder CNcomment:\C9\E8\D6\C3SP key ladder\B5Ľ\E2\C8\C5\CB㷨    CNend
\attention \n
You must set a descramble mode before using a key ladder in a session. The default algorithm is HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_CBC_CI.
It is recommended that you retain the descramble mode in a session.
CNcomment:ÿ\B4λỰ\B9\FD\B3\CC\D6\D0ʹ\D3\C3key ladder֮ǰ\A3\AC\D0\EB\C9\E8\D6þ\DF\CC\E5\CB㷨, ϵͳ\B3\F5ʼĬ\C8\CFֵ HI_UNF_ADVCA_SP_DSC_MODE_PAYLOAD_AES_CBC_CI\A3\BB\n
\B1\BE\B4λỰ\B9\FD\B3\CC\D6У\AC\BD\A8\D2鱣\B3\D6\CB㷨\B5\C4\CEȶ\A8\B2\BB\B1䡣 CNend
\param[in] enType Key ladder algorithm CNcomment:enType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_SetSPDscMode(HI_UNF_ADVCA_SP_DSC_MODE_E enType);

/**
\brief Obtains the descramble mode of the SP key ladder CNcomment: \BB\F1ȡ SP key ladder\B5\C4\CB㷨    CNend
\attention \n
None CNcomment:\CE\DE CNend
\param[in] pEnType Key ladder algorithm CNcomment:pEnType  key ladder\CB㷨\n  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
::HI_UNF_ADVCA_ALG_TYPE_E
*/
HI_S32 HI_UNF_ADVCA_GetSPDscMode(HI_UNF_ADVCA_SP_DSC_MODE_E *pEnType);

/**
  \brief this function is used by the Novel CA for the encryption and decryption setting
   CNcomment:Novel\C4ڴ\E6\BCӽ\E2\C3\DC\CB㷨\BA\CDkey\C5\E4\D6\C3 CNend
  \attention \n
  This function is used for the Novel encryption and decrption
  CNcomment:  \B1\BE\BA\AF\CA\FD\CA\C7\CCṩ\B8\F8 Novel \C4ڴ\E6\BCӽ\E2\C3ܷ\BD\B0\B8ʹ\D3ã\AC\D3\C3\D7\F7\C5\E4\D6üӽ\E2\C3ܹ\FD\B3\CCkeyladder\CB㷨\BA\CDkey CNend
  \retval ::HI_SUCCESS Success  CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called  CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_NovelCryptologyConfig(HI_VOID);

/**
  \brief Used for Novel CA to encrypt the data  CNcomment:Novel\C4ڴ\E6\CA\FD\BEݼ\D3\C3\DC CNend
  \attention \n
  None  CNcomment: \CE\DE CNend
  \param[in]  pPlainText: the buffer to store the data to be encrypted CNcomment:pPlainText \B4\FD\BC\D3\C3\DC\CA\FD\BE\DDָ\D5\EB CNend
  \param[in]  TextLen: the length of the data to be encrypted CNcomment:TextLen    \B4\FD\BC\D3\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
  \param[in]  pCipherText: the buffer to store the encrypted data CNcomment:pCipherText \BC\D3\C3ܺ\F3\CA\FD\BE\DDָ\D5\EB CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_NovelDataEncrypt(HI_U8 *pPlainText, HI_U32 TextLen, HI_U8 *pCipherText);

/**
  \brief This function is used for Novel to decrypt the data CNcomment:TextNovel\C4ڴ\E6\CA\FD\BEݽ\E2\C3\DC CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  pPlainText: point to the data to be decrypted CNcomment:pPlainText \B4\FD\BD\E2\C3\DC\C3\DC\CA\FD\BE\DDָ\D5\EB CNend
  \param[in]  TextLen: the length of the data to be decrypted CNcomment:TextLen    \B4\FD\BD\E2\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
  \param[in]  pCipherText: the buffer store the decrypted data CNcomment:pCipherText \BD\E2\C3ܺ\F3\CA\FD\BE\DDָ\D5\EB CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_NovelDataDecrypt(HI_U8 *pCipherText, HI_U32 TextLen, HI_U8 *pPlainText);

/**
\brief Sets oem root key\A3\AC it's mainly used for widevine keyladder CNcomment:OEM_root_key \D6\F7Ҫ\D3\C3\D3\DAWidevine keyladder    CNend
\attention \n
This root key could only be written only once be careful, thanks    CNcomment: \D5\E2\B8\F6\C3\DCԿֻ\D4\CA\D0\EDдһ\B4\CE,\C7\EB\BD\F7\C9\F7\B2\D9\D7\F7 CNend
\param[in] pu8OEMRootKey buffer of the input key    CNcomment:pu8OEMRootKey    \CA\E4\C8\EB\C3\DCԿ\B5\C4buffer  CNend
\param[in] u32KeyLen key length of the input CNcomment:u32KeyLen     \CA\E4\C8\EB\C3\DCԿ\B5ĳ\A4\B6ȣ\AC\CF޶\A8Ϊ16\D7ֽ\DA  CNend
\retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_CA_R2R_DECRYPT The CW decryption fails CNcomment:HI_ERR_CA_CW_DECRYPT   CW\BD\E2\C3\DCʧ\B0\DC CNend

\see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetOEMRootKey(HI_U8 *pu8OEMRootKey, HI_U32 u32KeyLen);

/**
  \brief This function is used to open the DCAS CNcomment:\D3\C3\D3ڴ\F2\BF\AADCAS CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enAlg: DCAS keyladder algorithm CNcomment:enAlg DCAS keyladder\CB㷨 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_DCASOpen(HI_UNF_CIPHER_ALG_E enAlg);

/**
  \brief This function is used to get the DCAS CHIPID CNcomment:\D3\C3\D3ڻ\F1ȡDCAS CHIPID
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[out]  pu32MSBID: First 4 bytes of DCAS CHIPID CNcomment:DCAS CHIPIDǰ4\B8\F6\D7ֽ\DA CNend
  \param[out]  pu32LSBID: last 4 bytes of DCAS CHIPID CNcomment:DCAS CHIPID\BA\F34\B8\F6\D7ֽ\DA CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetDCASChipId(HI_U32 *pu32MSBID, HI_U32 *pu32LSBID);

/**
  \brief This function is used to set the session key CNcomment:\D3\C3\D3\DA\C9\E8\D6\C3DCAS session\C3\DCԿ CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enDCASLevel: the DCAS keyladder level CNcomment:enAlg DCAS keyladder\BC\B6\CA\FD CNend
  \param[in]  pu8Key: the DCAS keyladder session key CNcomment:enAlg DCAS keyladder\C3\DCԿ CNend
  \param[in] u32KeyLen DCAS keyladder session key length, must be equal to 16. CNcomment:u32KeyLen DCAS keyladder\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
  \param[out]  pu8Output: the output of the DCAS keyladder CNcomment:pu8Output DCAS keyladder\CA\E4\B3\F6 CNend
  \param[in] u32OutputLen Output length, must be equal to 16. CNcomment:u32OutputLen DCAS keyladder\CA\E4\B3\F6\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetDCASSessionKey(HI_UNF_ADVCA_DCAS_KEYLADDER_LEV_E enDCASLevel,
                            HI_U8 *pu8Key , HI_U32 u32KeyLen, HI_U8 *pu8Output,  HI_U32 u32OutputLen);

/**
  \brief This function is used to close the DCAS keyladder CNcomment:\D3\C3\D3ڹر\D5DCAS CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see  \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_DCASClose(HI_VOID);

/**
  \brief This function is used to set the OTP fuse. CNcomment:\D3\C3\D3\DA\C9\E8\D6\C3OTPλ CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enOtpFuse: the OTP fuse ID CNcomment:enOtpFuse \B4\FD\C9\E8\D6õ\C4OTPλID CNend
  \param[in]  pstOtpFuseAttr: the OTP fuse attribute CNcomment:pstOtpFuseAttr \B4\FD\C9\E8\D6õ\C4OTPλ\CA\F4\D0\D4 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetOtpFuse(HI_UNF_ADVCA_OTP_FUSE_E enOtpFuse, HI_UNF_ADVCA_OTP_ATTR_S *pstOtpFuseAttr);

/**
  \brief This function is used to get the OTP fuse. CNcomment:\D3\C3\D3ڻ\F1ȡOTPλ CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enOtpFuse: the OTP fuse ID CNcomment:enOtpFuse \B4\FD\BB\F1ȡ\B5\C4OTPλID CNend
  \param[in]  pstOtpFuseAttr: the OTP fuse attribute CNcomment:pstOtpFuseAttr \BB\F1ȡ\B5\C4OTPλ\CA\F4\D0\D4 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_GetOtpFuse(HI_UNF_ADVCA_OTP_FUSE_E enOtpFuse, HI_UNF_ADVCA_OTP_ATTR_S *pstOtpFuseAttr);

/**
  \brief This function is used to set the keyladder attribute. CNcomment:\D3\C3\D3\DA\C9\E8\D6\C3keyladder\CA\F4\D0\D4 CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enKeyLadderType: The keyladder type ID CNcomment:enKeyLadderType Keyladder\C0\E0\D0\CDID CNend
  \param[in]  pstKeyladderAttr: The keyladder attribute CNcomment:pstKeyladderAttr \B4\FD\C9\E8\D6õ\C4keyladder\CA\F4\D0\D4CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetKeyLadderAttr(HI_UNF_ADVCA_KEYLADDER_TYPE_E enKeyLadderType, HI_UNF_ADVCA_KEYLADDER_ATTR_S *pstKeyladderAttr);

/**
  \brief This function is used to achieve the CA vendor privated function. CNcomment:\D3\C3\D3\DA\CD\EA\B3\C9CA\B3\A7\BC\D2\CC\D8\D3еĲ\D9\D7\F7 CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  enCaVendor: The CA vendor type ID CNcomment:enCaVendor CA vendor\C0\E0\D0\CDID CNend
  \param[in]  pstCavendorOpt: The parameter to achieve the CA vendor private function CNcomment:pstCavendorOpt \CD\EA\B3\C9CA\B3\A7\BC\D2\CC\D8\D3й\A6\C4\DC\D0\E8Ҫ\B5Ĳ\CE\CA\FDCNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS  \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \retval ::HI_ERR_CA_NOT_INIT The advanced CA module is not initialized. CNcomment:HI_ERR_CA_NOT_INIT CAδ\B3\F5ʼ\BB\AF CNend
  \retval ::HI_ERR_CA_INVALID_PARA The input parameter value is invalid CNcomment:HI_ERR_CA_INVALID_PARA \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_CaVendorOperation(HI_UNF_ADVCA_VENDORID_E enCaVendor, HI_UNF_ADVCA_CA_VENDOR_OPT_S *pstCaVendorOpt);

/**
  \brief This function is used to set the session key CNcomment:\D3\C3\D3\DA\C9\E8\D6\C3LP session\C3\DCԿ CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  pu8Key: the LP keyladder session key CNcomment:enAlg LP keyladder\C3\DCԿ CNend
  \param[in] u32KeyLen Protection key length, must be equal to 16. CNcomment:u32KeyLen \B1\A3\BB\A4\C3\DCԿ\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_SetLPSessionKey(HI_U8 *pu8Key, HI_U32 u32KeyLen);

/**
  \brief This function is used to generate the clear key CNcomment:\D3\C3\D3\DA\C9\FA\B3\C9LP \C3\F7\CE\C4\C3\DCԿ CNend
  \attention \n
  None  CNcomment:\CE\DE CNend
  \param[in]  pEncryptedKey: the LP keyladder encrypted key CNcomment:\C5\E4\D6\C3\C3\DC\CE\C4key CNend
  \param[in] u32EncryptedSwpkLen SWPK length, must be equal to 16. CNcomment:u32EncryptedSwpkLen  \BC\D3\C3ܵ\C4SWPK\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
  \param[out]  pPlainKey: the LP keyladder clear key CNcomment:\C9\FA\B3ɵ\C4\C3\F7\CE\C4key CNend
  \param[in] u32PlainSwpkLen SWPK length, must be equal to 16. CNcomment:u32PlainSwpkLen \C3\F7\CE\C4SWPK\B3\A4\B6ȣ\AC\B1\D8\D0\EBΪ16 CNend
  \retval ::HI_SUCCESS Success CNcomment:HI_SUCCESS \B3ɹ\A6 CNend
  \retval ::HI_FAILURE This API fails to be called CNcomment:HI_FAILURE  APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
  \see \n
None CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_ADVCA_DecryptLPKey(HI_U8 *pEncryptedSwpk, HI_U32 u32EncryptedSwpkLen, HI_U8 *pPlainSwpk, HI_U32 u32PlainSwpkLen);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ADVCA_H__ */

