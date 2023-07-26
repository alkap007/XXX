/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2005-2018. All rights reserved.
 * Description: Common data types of the system.
 *              CNcomment: ϵͳ\B9\B2\D3õ\C4\CA\FD\BE\DD\C0\E0\D0Ͷ\A8\D2\E5 CNend
 * Author: Hisilicon multimedia software group
 * Create: 2005-4-23
 */

#ifndef __HI_TYPE_H__
#define __HI_TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------------------------------------------*
 * Defintion of basic data types. The data types are applicable to both the application layer and kernel codes. *
 * CNcomment: \BB\F9\B1\BE\CA\FD\BE\DD\C0\E0\D0Ͷ\A8\D2壬Ӧ\D3ò\E3\BA\CD\C4ں˴\FA\C2\EB\BE\F9ʹ\D3\C3  CNend                                                   *
 *--------------------------------------------------------------------------------------------------------------*/
/*************************** Structure Definition ****************************/
/** \addtogroup      Common_TYPE */
/** @{ */  /** <!-- [Common_TYPE] */

typedef unsigned char           HI_UCHAR;
typedef unsigned char           HI_U8;
typedef unsigned short          HI_U16;
typedef unsigned int            HI_U32;
typedef unsigned long long      HI_U64;
typedef unsigned long           HI_ULONG;

typedef char*                   HI_PCHAR;
typedef char                    HI_CHAR;
typedef signed char             HI_S8;
typedef short                   HI_S16;
typedef int                     HI_S32;
typedef long long               HI_S64;
typedef long                    HI_SLONG;

typedef float                   HI_FLOAT;
typedef double                  HI_DOUBLE;

/* typedef void                    HI_VOID; */
#define HI_VOID         void

typedef unsigned long           HI_SIZE_T;
typedef unsigned long           HI_LENGTH_T;

typedef HI_U32                  HI_HANDLE;

typedef unsigned int            HI_PHYS_ADDR_T;

#ifdef CONFIG_ARCH_LP64_MODE
typedef unsigned long long      HI_VIRT_ADDR_T;
#else
typedef unsigned int            HI_VIRT_ADDR_T;
#endif

/** Constant Definition */
/** CNcomment: \B3\A3\C1\BF\B6\A8\D2\E5 */
typedef enum
{
    HI_FALSE    = 0,
    HI_TRUE     = 1,
} HI_BOOL;

#ifndef NULL
#define NULL                0L
#endif

#define HI_NULL             0L
#define HI_NULL_PTR         0L

#define HI_SUCCESS          0
#define HI_FAILURE          (-1)

#define HI_INVALID_HANDLE   (0xffffffff)

#define HI_INVALID_PTS      (0xffffffff)
#define HI_INVALID_TIME     (0xffffffff)

#define HI_OS_LINUX     0xabcd
#define HI_OS_WIN32     0xcdef

#ifdef _WIN32
#define HI_OS_TYPE      HI_OS_WIN32
#else
#define __OS_LINUX__
#define HI_OS_TYPE      HI_OS_LINUX
#endif

#ifdef HI_ADVCA_SUPPORT
#define __INIT__
#define __EXIT__
#else
#define __INIT__  __init
#define __EXIT__  __exit
#endif

/**

define of HI_HANDLE :
bit31                                                           bit0
  |<----   16bit --------->|<---   8bit    --->|<---  8bit   --->|
  |--------------------------------------------------------------|
  |      HI_MOD_ID_E       |  mod defined data |     chnID       |
  |--------------------------------------------------------------|

mod defined data: private data define by each module(for example: sub-mod id), usually, set to 0.
*/

#define HI_HANDLE_MAKEHANDLE(mod, privatedata, chnid)  (HI_HANDLE)( (((mod)& 0xffff) << 16) | ((((privatedata)& 0xff) << 8) ) | (((chnid) & 0xff)) )

#define HI_HANDLE_GET_MODID(handle)     (((handle) >> 16) & 0xffff)
#define HI_HANDLE_GET_PriDATA(handle)   (((handle) >> 8) & 0xff)
#define HI_HANDLE_GET_CHNID(handle)     (((handle)) & 0xff)

#define HI_UNUSED(x) ((x)=(x))

typedef unsigned char           hi_uchar;
typedef unsigned char           hi_u8;
typedef unsigned short          hi_u16;
typedef unsigned int            hi_u32;
typedef unsigned long long      hi_u64;
typedef unsigned long           hi_ulong;

typedef char                    hi_char;
typedef signed char             hi_s8;
typedef short                   hi_s16;
typedef int                     hi_s32;
typedef long long               hi_s64;
typedef long                    hi_slong;

typedef float                   hi_float;
typedef double                  hi_double;

typedef void                    hi_void;

typedef unsigned long           hi_size_t;
typedef unsigned long           hi_length_t;

typedef hi_u32                  hi_handle;

typedef HI_BOOL                 hi_bool;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#ifdef __cplusplus
}
#endif

#endif /* __HI_TYPE_H__ */

