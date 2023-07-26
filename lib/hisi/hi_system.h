/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-15
 */

#ifndef __HI_SYSTEM_H__
#define __HI_SYSTEM_H__

#include "hi_type.h"
#include "hi_debug.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hiSYS_CONF_S
{
    HI_U32 u32Reverse; /* Not used, reserved for extension */ /* CNcomment: \D4\DDʱû\D3\D0ʹ\D3ã\AC\C1\F4\B4\FD\C0\A9չ */
} HI_SYS_CONF_S;

/* Define the chip type. */
typedef enum hiCHIP_TYPE_E
{
    HI_CHIP_TYPE_HI3716M,
    HI_CHIP_TYPE_HI3716H,
    HI_CHIP_TYPE_HI3716C,
    HI_CHIP_TYPE_HI3716D,

    HI_CHIP_TYPE_HI3720,
    HI_CHIP_TYPE_HI3712,
    HI_CHIP_TYPE_HI3715,

    HI_CHIP_TYPE_HI3718M,
    HI_CHIP_TYPE_HI3718C,
    HI_CHIP_TYPE_HI3719M,
    HI_CHIP_TYPE_HI3719C,
    HI_CHIP_TYPE_HI3719M_A,

    HI_CHIP_TYPE_HI3796C   = 0x20,
    HI_CHIP_TYPE_HI3798C,
    HI_CHIP_TYPE_HI3796M,
    HI_CHIP_TYPE_HI3798M,

    HI_CHIP_TYPE_HI3796C_A = 0x40,
    HI_CHIP_TYPE_HI3798C_A,
    HI_CHIP_TYPE_HI3798C_B,

    HI_CHIP_TYPE_HI3798M_A,
    HI_CHIP_TYPE_HI3798M_H,

    HI_CHIP_TYPE_BUTT
} HI_CHIP_TYPE_E;

/* Define the chip version. */
typedef enum hiCHIP_VERSION_E
{
    HI_CHIP_VERSION_V100 = 0x100,
    HI_CHIP_VERSION_V101 = 0x101,
    HI_CHIP_VERSION_V110 = 0x110,
    HI_CHIP_VERSION_V200 = 0x200,
    HI_CHIP_VERSION_V210 = 0x210,
    HI_CHIP_VERSION_V300 = 0x300,
    HI_CHIP_VERSION_V310 = 0x310,
    HI_CHIP_VERSION_V400 = 0x400,
    HI_CHIP_VERSION_V410 = 0x410,
    HI_CHIP_VERSION_V420 = 0x420,
    HI_CHIP_VERSION_V430 = 0x430,
    HI_CHIP_VERSION_V450 = 0x450,
    HI_CHIP_VERSION_BUTT
} HI_CHIP_VERSION_E;

typedef enum
{
    HI_CHIP_PACKAGE_TYPE_BGA_15_15 = 0,
    HI_CHIP_PACKAGE_TYPE_BGA_16_16,
    HI_CHIP_PACKAGE_TYPE_BGA_19_19,
    HI_CHIP_PACKAGE_TYPE_BGA_23_23,
    HI_CHIP_PACKAGE_TYPE_BGA_31_31,
    HI_CHIP_PACKAGE_TYPE_QFP_216,
    HI_CHIP_PACKAGE_TYPE_BGA_21_21,
    HI_CHIP_PACKAGE_TYPE_BGA_14_14,
    HI_CHIP_PACKAGE_TYPE_BUTT
} HI_CHIP_PACKAGE_TYPE_E;

/* Define the chip support attrs */
typedef enum hiCHIP_CAP_E
{
    HI_CHIP_CAP_DOLBY,
    HI_CHIP_CAP_DTS,
    HI_CHIP_CAP_ADVCA,
    HI_CHIP_CAP_MACROVISION,
    HI_CHIP_CAP_HDR10,
    HI_CHIP_CAP_DOLBYVISION,
    HI_CHIP_CAP_BUTT
} HI_CHIP_CAP_E;

/* Define the video codec lisence contrl enum. */
typedef enum hiSYS_VIDEO_CODEC_E
{
    HI_SYS_VIDEO_MPEG2 = 0x1,
    HI_SYS_VIDEO_MPEG4 = 0x2,
    HI_SYS_VIDEO_VC1   = 0x4,
    HI_SYS_VIDEO_H264  = 0x8,
    HI_SYS_VIDEO_MVC   = 0x10,
    HI_SYS_VIDEO_H265  = 0x20,
    HI_SYS_VIDEO_AVS   = 0x40,
    HI_SYS_VIDEO_DIVX  = 0x80,
    HI_SYS_VIDEO_REAL8 = 0x100,
    HI_SYS_VIDEO_REAL9 = 0x200,
    HI_SYS_VIDEO_AVS2  = 0x400,
    HI_SYS_VIDEO_MASK  = 0x7FF,
} HI_SYS_VIDEO_CODEC_E;

/* System version, that is, the version of the software developer's kit (SDK) */
typedef struct hiSYS_VERSION_S
{
    HI_CHIP_TYPE_E  enChipTypeSoft;     /* Chip type corresponding to the SDK */ /* CNcomment: SDK\C8\ED\BC\FE\B6\D4Ӧ\B5\C4оƬ\C0\E0\D0\CD */
    HI_CHIP_TYPE_E  enChipTypeHardWare; /* Chip type that is detected when the SDK is running */ /* CNcomment: SDK\D4\CB\D0\D0ʱ\BC\EC\B2⵽\B5\C4оƬ\C0\E0\D0\CD */
    HI_CHIP_VERSION_E enChipVersion;    /* Chip version that is detected when the SDK is running */ /* CNcomment: SDK\D4\CB\D0\D0ʱ\BC\EC\B2⵽оƬ\B0汾\BA\C5 */
    HI_CHAR         aVersion[80];       /* Version string of the SDK */ /* CNcomment: SDK\C8\ED\BC\FE\B0汾\BA\C5\D7ַ\FB\B4\AE */
    HI_CHAR         BootVersion[80];    /* Version string of the Boot */ /* CNcomment: Boot\B0汾\BA\C5\D7ַ\FB\B4\AE */
    HI_CHAR         SecureOSImageVersion[96]; /* Version string of the secure os image */ /* CNcomment: \B0\B2ȫOS\BE\B5\CF\F1\B0汾\D7ַ\FB\B4\AE */
} HI_SYS_VERSION_S;

/* Define the chip attributes */
typedef struct hiSYS_CHIP_ATTR_S
{
    HI_BOOL bDolbySupport;       /* Whether support dolby or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3ֶű\C8 */
    HI_BOOL bDTSSupport;         /* Whether support DTS or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3\D6DTS */
    HI_BOOL bADVCASupport;       /* Whether support ADVCA or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3ָ߰\B2 */
    HI_BOOL bMacrovisionSupport; /* Whether support Macrovision or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3\D6Macrovision */
    HI_BOOL bHDR10Support;       /* Whether support HDR10 or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3\D6HDR10 */
    HI_BOOL bDolbyvisionSupport; /* Whether support DolbyVision or not */ /* CNcomment:оƬ\CAǷ\F1֧\B3\D6Dolbyvision */
    HI_U64  u64ChipID;           /* the unique 64 bits chipid */ /* CNcomment:64λоƬΨһID */
    HI_U32  u32ChipID;           /* the unique 32 bits chipid since 98mv200 */ /* CNcomment:32λоƬΨһID\A3\AC98mv200\BC\B0\D2Ժ\F3\B5\C4оƬ\BF\AAʼ֧\B3\D6 */
} HI_SYS_CHIP_ATTR_S;

/* Define the Sys attributes */
typedef struct hiSYS_ATTR_S
{
    HI_BOOL bSMPSupport; /* Whether support SMP or not */ /* CNcomment:ϵͳ\CAǷ\F1֧\B3ְ\B2ȫý\CC\E5ͨ· */
} HI_SYS_ATTR_S;

/* Defines DDR configuration type struct */
/* CNcomment: DDR \C5\E4\D6\C3\C0\E0\D0ͽṹ\B6\A8\D2\E5 */
typedef struct hiSYS_MEM_CONFIG_S
{
    HI_U32 u32TotalSize; /* Total memory size(MB) */ /* CNcomment: \D7\DC\C4ڴ\E6\B4\F3С(MB) */
    HI_U32 u32MMZSize;   /* MMZ memory size(MB) */ /* CNcomment: MMZ\C4ڴ\E6\B4\F3С(MB) */
} HI_SYS_MEM_CONFIG_S;

#ifndef __KERNEL__
#include <time.h>

/*
 * brief Initializes the system. CNcomment: ϵͳ\B3\F5ʼ\BB\AF CNend
 * attention \n
 * You must call this API to initialize the system before using the APIs of all modules.
 * Though you can call other APIs successfully before calling this API, the subsequent operations may fail.\n
 * CNcomment: \D4\DAʹ\D3\C3\CB\F9\D3\D0ģ\BF\E9\B5Ľӿ\DA֮ǰ\B6\BC\D0\E8Ҫ\CFȵ\F7\D3ô˽ӿڶ\D4ϵͳ\BD\F8\D0г\F5ʼ\BB\AF\n
 * \D4ڵ\F7\D3\C3\D5\E2\B8\F6\BDӿ\DA֮ǰ\B5\F7\D3\C3\C6\E4\CB\FB\BDӿڣ\AC\B2\BB\BB᷵\BB\D8ʧ\B0ܣ\AC\B5\AB\CAǲ\BB\B1\A3ִ֤\D0е\C4\D5\FDȷ\D0\D4 CNend
 * param N/A CNcomment: \CE\DE CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_Init(HI_VOID);

/*
 * brief Deinitializes the system. CNcomment: ϵͳȥ\B3\F5ʼ\BB\AF CNend
 * attention \n
 * If all modules are not used, you need to call this API to deinitialize the system.\n
 * CNcomment: \CB\F9\D3\D0ģ\BF鶼\B2\BB\D4\D9ʹ\D3ú\F3\B5\F7\D3ô˽ӿ\DAȥ\B3\F5ʼ\BB\AF CNend
 * param N/A CNcomment: \CE\DE CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_DeInit(HI_VOID);

/*
 * brief Obtains the compiled time of a version. CNcomment: \BB\F1ȡ\B0汾\B5ı\E0\D2\EBʱ\BC\E4 CNend
 * attention \n
 * The compiled time is the time during which the common module is made again.
 * CNcomment: ʱ\BC\E4Ϊ\BD\F8\D0\D0commonģ\BF\E9\D6\D8\D0\C2make\B5\C4ʱ\BC\E4 CNend
 * param[out] pstTime Pointer to the compiled time of a version (output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B0汾\B1\E0\D2\EB\B5\C4ʱ\BC\E4 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetBuildTime(struct tm * pstTime);

/*
 * brief Obtains the version number. CNcomment: \BB\F1ȡ\B0汾\BA\C5 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pstVersion Pointer to the version number (output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B0汾\BA\C5 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetVersion(HI_SYS_VERSION_S *pstVersion);

/*
 * brief Obtains the package type. CNcomment: \BB\F1ȡ\B7\E2װ\C0\E0\D0\CD CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] penPackageType Pointer to the package type (output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B7\E2װ\C0\E0\D0\CD CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetChipPackageType(HI_CHIP_PACKAGE_TYPE_E *penPackageType);

/*
 * brief Obtains the chip support attributes. CNcomment: \BB\F1ȡоƬ֧\B3ֵ\C4\C4\DC\C1\A6 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] enChipCap Indicate which chip capability. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\A3\ACָ\C3\F7\BB\F1ȡ\BA\CE\D6\D6оƬ\C4\DC\C1\A6 CNend
 * param[out] pbSupport Pointer to the chip whether support the attributes(output). CNcomment: \CA\E4\B3\F6\B2\CE\CA\FD\A3\AC\B1\A3\B4\E6\BB\F1ȡ\BD\E1\B9\FB CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetChipCapability(HI_CHIP_CAP_E enChipCap, HI_BOOL *pbSupport);

/*
 * brief Obtains the chip attributes. CNcomment: \BB\F1ȡоƬ\CA\F4\D0\D4 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pstChipAttr Pointer to the chip attributes(output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6оƬ\CA\F4\D0\D4 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetChipAttr(HI_SYS_CHIP_ATTR_S *pstChipAttr);

/*
 * brief Obtains the Sys attributes. CNcomment: \BB\F1ȡϵͳ\CA\F4\D0\D4 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pstSysAttr Pointer to the chip attributes(output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ϵͳ\CA\F4\D0\D4 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetAttr(HI_SYS_ATTR_S *pstSysAttr);

/*
 * brief CRC32 function. CNcomment: CRC32\B9\A6\C4\DC CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] pu8Src Pointer to the source buffer. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EBbuffer CNend
 * param[in] u32SrcLen length of the source buffer. CNcomment: \CA\E4\C8\EBbuffer\B3\A4\B6\C8 CNend
 * param[out] pu32Dst Pointer to the out value. CNcomment: \CA\E4\B3\F6\CA\FD\BE\DDָ\D5\EB CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_CRC32(HI_U8 *pu8Src, HI_U32 u32SrcLen, HI_U32 *pu32Dst);

/*
 * brief Obtains the chip attributes. CNcomment: \BB\F1ȡ\C4ڴ\E6\C5\E4\D6\C3\D0\C5Ϣ CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pstConfig Pointer to address for memory configuration(output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\C4ڴ\E6\C5\E4\D6\C3\D0\C5Ϣָ\D5\EB CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetMemConfig(HI_SYS_MEM_CONFIG_S *pstConfig);

/*
 * brief Performs global system configuration. CNcomment: \C9\E8\D6\C3ϵͳ\B5\C4ȫ\BE\D6\C5\E4\D6\C3 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] pstSysConf Pointer to the address for system configuration CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACϵͳ\C5\E4\D6\C3ָ\D5\EB\B5\D8ַ CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_SetConf(const HI_SYS_CONF_S *pstSysConf);

/*
 * brief Obtains global system configuration. CNcomment: \BB\F1ȡϵͳ\B5\C4ȫ\BE\D6\C5\E4\D6\C3 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pstSysConf Pointer to the system configuration (output). CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ϵͳ\C5\E4\D6\C3 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetConf(HI_SYS_CONF_S *pstSysConf);

/*
 * brief Sets the debugging information level of a module. CNcomment: \C9\E8\D6\C3ģ\BF\E9\B5ĵ\F7\CA\D4\D0\C5Ϣ\BC\B6\B1\F0 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] enModId Debugging ID of a module CNcomment: ģ\BF\E9\B5ĵ\F7\CA\D4ID\A1\A3 CNend
 * param[in] enLogLevel Debugging information level of a module CNcomment: ģ\BF\E9\B5ĵ\F7\CA\D4\D0\C5Ϣ\BC\B6\B1\F0 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 */
HI_S32 HI_SYS_SetLogLevel(HI_MOD_ID_E enModId,  HI_LOG_LEVEL_E enLogLevel);

/*
 * brief Sets the debugging information file path for U-disk. CNcomment: \C9\E8\D6\C3\C8\D5־\B4洢·\BE\B6 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in]  pszLogPath Debugging information file path. CNcomment: \C8\D5־\B5Ĵ洢·\BE\B6 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 */
HI_S32 HI_SYS_SetLogPath(const HI_CHAR* pszLogPath);

/*
 * brief Sets the debugging files(may be stream, YUV data, image...) save path. CNcomment: \C9\E8\D6õ\F7\CA\D4\CEļ\FE\B4洢·\BE\B6 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in]  pszPath Debugging files path. CNcomment: \B5\F7\CA\D4\CEļ\FE\B5Ĵ洢·\BE\B6 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 */
HI_S32 HI_SYS_SetStorePath(const HI_CHAR* pszPath);

/*
 * brief Sets the debugging information file size(MB), range from 1 to 120. CNcomment: \C9\E8\D6\C3\C8\D5־\B4\F3С(MB)\A3\AC\B7\B6ΧΪ1\B5\BD120 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in]  u32LogSize Debugging information file size(MB). CNcomment: \C8\D5־\B5Ĵ\F3С(MB) CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 */
HI_S32 HI_SYS_SetLogSize(HI_U32 u32LogSize);

/*
 * brief Writes to a register or a memory. CNcomment: д\BCĴ\E6\C6\F7 CNend
 * attention:\n
 * support register range: \n
 * {0xF8000000, 0xF8000FFF} \n
 * {0xF8A20000, 0xF8A20FFF} \n
 * {0xF8A21000, 0xF8A21FFF} \n
 * {0xF8A22000, 0xF8A22FFF} \n
 * CNcomment:\n
 * \BCĴ\E6\C6\F7\B7\B6Χ֧\B3\D6:
 * {0xF8000000, 0xF8000FFF} \n
 * {0xF8A20000, 0xF8A20FFF} \n
 * {0xF8A21000, 0xF8A21FFF} \n
 * {0xF8A22000, 0xF8A22FFF} \n
 * CNend
 * param[in] u32RegAddr Physical address of a register CNcomment: \BCĴ\E6\C6\F7\CE\EF\C0\ED\B5\D8ַ CNend
 * param[in] u32Value Value of a register CNcomment:  \BCĴ\E6\C6\F7\B5\C4ֵ CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_WriteRegister(HI_U32 u32RegAddr, HI_U32 u32Value);

/*
 * brief Reads a register. CNcomment: \B6\C1\BCĴ\E6\C6\F7CNend
 * attention \n
 * support register range: \n
 * {0xF8000000, 0xF8000FFF} \n
 * {0xF8A20000, 0xF8A20FFF} \n
 * {0xF8A21000, 0xF8A21FFF} \n
 * {0xF8A22000, 0xF8A22FFF} \n
 * {0xF8AB0000, 0xF8ABFFFF} \n
 * CNcomment:\n
 * \BCĴ\E6\C6\F7\B7\B6Χ֧\B3\D6:
 * {0xF8000000, 0xF8000FFF} \n
 * {0xF8A20000, 0xF8A20FFF} \n
 * {0xF8A21000, 0xF8A21FFF} \n
 * {0xF8A22000, 0xF8A22FFF} \n
 * {0xF8AB0000, 0xF8ABFFFF} \n
 * CNend
 * param[in] u32RegAddr Physical address of a register CNcomment: \BCĴ\E6\C6\F7\CE\EF\C0\ED\B5\D8ַ CNend
 * param[out] pu32Value Pointer to the register value (output) CNcomment:  ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\BCĴ\E6\C6\F7\B5\C4ֵ CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_ReadRegister(HI_U32 u32RegAddr, HI_U32 *pu32Value);

/*
 * brief Get timestamp. CNcomment: \BB\F1ȡʱ\BC\E4\B4\C1 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[out] pu32TimeMs Pointer to the timestamp value (output) CNcomment: \CA\E4\B3\F6ʱ\BC\E4\B4\C1 CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_GetTimeStampMs(HI_U32 *pu32TimeMs);

/*
 * brief Disable some video codec. CNcomment: \BD\FB\D3\C3ĳ\D6\D6\CA\D3Ƶ\BD\E2\C2\EB\CB㷨 CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] enVideoCodec  The type of video codec:   \CA\D3Ƶ\BD\E2\C2\EB\CB㷨\C0\E0\D0\CD CNend
 * retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 * retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_SYS_DisableVideoCodec(HI_SYS_VIDEO_CODEC_E enVideoCodec);

#endif /* endif __KERNEL__ */

#ifdef __cplusplus
}
#endif

#endif /* __HI_SYSTEM_H__ */

