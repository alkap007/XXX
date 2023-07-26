/******************************************************************************

Copyright (C), 2016, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_unf_klad_common_ca.h
Version       : Initial draft
Author        : Hisilicon hisecurity team
Created       : 2016-12-08
Last Modified :
Description   : Key ladder API declaration for common ca
Function List :
History       :
******************************************************************************/
#ifndef __HI_UNF_KLAD_COMMON_CA_H__
#define __HI_UNF_KLAD_COMMON_CA_H__

#include "hi_type.h"
#include "hi_unf_klad.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      COMMON_CA */
/** @{ */  /** <!-- [COMMON_CA] */

/*
Level: 2/3 depends on OTP
Algorithm: TDES/AES
Target Engine: Demux - CSA2
*/
#define HI_UNF_KLAD_COMMON_CA_TYPE_CSA2   0x3f00

/*
Level: 2/3 depends on OTP
Algorithm: TDES/AES
Target Engine: Demux - CSA3
*/
#define HI_UNF_KLAD_COMMON_CA_TYPE_CSA3   0x3f01

/*
Level: 2/3/4/5 depends on OTP
Algorithm: TDES/AES
Target Engine: Demux - AES/NOVEL/SM4; Payload cipher - AES; Multicipher - fixed
*/
#define HI_UNF_KLAD_COMMON_CA_TYPE_SP     0x3f02

/*
Level: 2/3 depends on OTP
Algorithm: TDES/AES
Target Engine: Demux - AES/NOVEL/SM4/TDES; Payload cipher - AES; Multicipher - fixed
*/
#define HI_UNF_KLAD_COMMON_CA_TYPE_R2R    0x3f03

/*
Level: 2/3/4/5 depends on OTP
Algorithm: TDES/AES
Target Engine: Demux - CSA2/CSA3/AES/NOVEL/SM4/TDES; Payload cipher - AES; Multicipher - fixed
*/
#define HI_UNF_KLAD_COMMON_CA_TYPE_MISC   0x3f04


/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      COM_CA */
/** @{ */  /** <!-- [COM_CA] */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_KLAD_COMMON_CA_H__ */

iff -Naur a/lib/hisi/hi_unf_klad_dcas.h b/lib/hisi/hi_unf_klad_dcas.h
-- a/lib/hisi/hi_unf_klad_dcas.h	1970-01-01 01:00:00.000000000 +0100
++ b/lib/hisi/hi_unf_klad_dcas.h	2021-11-02 11:53:28.000000000 +0100
@ -0,0 +1,81 @@
/******************************************************************************

Copyright (C), 2017, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_unf_klad_dcas.h
Version       : Initial draft
Author        : Hisilicon hisecurity team
Created       : 2017-03-21
Last Modified :
Description   : Key ladder API declaration for DCAS
Function List :
History       :
******************************************************************************/
#ifndef __HI_UNF_KLAD_DCAS_H__
#define __HI_UNF_KLAD_DCAS_H__

#include "hi_type.h"
#include "hi_unf_klad.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup       */
/** @{ */  /** <!-- [DCAS] */


/*
Level: 1
Algorithm: AES
Target Engine: NA
*/
#define HI_UNF_KLAD_DCAS_TYPE_RKD    0x0c00

/*
Level: 3
Algorithm: TDES/AES
Target Engine: Demux - CSA2/CSA3/AES/NOVEL/SM4/TDES; Payload cipher - AES; Multicipher - fixed
*/
#define HI_UNF_KLAD_DCAS_TYPE_K30    0x0c01


/**da nonce*/
typedef struct hiUNF_KLAD_DCAS_DA_NONCE_S
{
    HI_U8 au8Nonce[HI_UNF_KLAD_MAX_KEY_LEN];
    HI_U8 au8DaNonce[HI_UNF_KLAD_MAX_KEY_LEN];
} HI_UNF_KLAD_DCAS_DA_NONCE_S;


/************************************************/

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      DCAS */
/** @{ */  /** <!-- [DCAS] */


/**
\brief Generate K30 DA nonce
\param[in] hKlad    Handle of key ladder
\param[in/out] pstDaNonce    pointer to the DA nonce
\retval HI_SUCCESS  Success
\retval HI_FAILURE  Failure
*/
HI_S32 HI_UNF_KLAD_DCAS_K30GenDaNonce(HI_HANDLE hKlad, HI_UNF_KLAD_DCAS_DA_NONCE_S *pstDaNonce);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_KLAD_DCAS_H__ */


iff -Naur a/lib/hisi/hi_unf_mailbox.h b/lib/hisi/hi_unf_mailbox.h
-- a/lib/hisi/hi_unf_mailbox.h	1970-01-01 01:00:00.000000000 +0100
++ b/lib/hisi/hi_unf_mailbox.h	2021-11-02 11:53:28.000000000 +0100
@ -0,0 +1,151 @@
/******************************************************************************

  Copyright (C), 2016, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_mailbox.h
  Version       : Initial Draft
  Author        : Hisilicon hisecurity team
  Created       : 2016-11-4
  Description   :
  History       :
  1.Date        :
  Author        : sdk
  Modification  :

*******************************************************************************/
#ifndef __HI_UNF_MAILBOX_H__
#define __HI_UNF_MAILBOX_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/** Mailbox ID */
#define MID_SCPU_COMMON          (0x01)
#define MID_TCPU_COMMON          (0x40)
#define MID_ACPU_COMMON          (0x60)

typedef struct
{
    HI_VOID *pMessage;
    HI_U32 u32MessageLen;
    HI_VOID *pOutBuffer;
    HI_U32 *pu32OutBufferLen;
} HI_UNF_MAILBOX_BUFFER_S;

/******************************* API declaration *****************************/

/**
\brief Initializes the mailbox module. CNcomment:\B3\F5ʼ\BB\AFMailboxģ\BF\E9 CNend
\attention \n
Before calling other functions in this file, you must call this application programming interface (API).
\param N/A
\retval ::HI_SUCCESS  Success.       CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_Init(HI_VOID);

/**
\brief Deinitializes the mailbox module. CNcomment:ȥ\B3\F5ʼ\BB\AFMailbox\C9豸 CNend
\attention \n
N/A
\param N/A                           CNcomment:\CEޡ\A3 CNend
\retval ::HI_SUCCESS  Success.       CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Failure.       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_DeInit(HI_VOID);

/**
\brief Open mailbox device.                      CNcomment:\B4\F2\BF\AA mailbox \C9豸\A3\AC\B7\B5\BB\D8 maibox \BE\E4\B1\FA\A1\A3 CNend
\attention \n
N/A
\param[out] pHandle: Create handle/A             CNcomment:\CEޡ\A3 CNend
\param[in]  u32Id:  mailbox ID, now it is fixed to MID_ACPU_COMMON/A  CNcomment:\CEޡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.  CNcomment:ϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API failure.     CNcomment:\B7\D6\C5\E4\BE\E4\B1\FAʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_Open(HI_HANDLE* pHandle, HI_U32 u32Id);

/**
\brief Destory mailbox instance.                 CNcomment:\B9ر\D5 mailbox \C9豸ʵ\C0\FD\A1\A3 CNend
\attention \n
N/A
\param [in] handle: mailbox instance handle/A    CNcomment:\CEޡ\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.  CNcomment:ϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API failure.     CNcomment:\CAͷž\E4\B1\FAʧ\B0ܡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_Close(HI_HANDLE handle);

/**
\brief  send data by mailbox.                    CNcomment:ͨ\B9\FD mailbox \B7\A2\CB\CD\CA\FD\BEݡ\A3 CNend
\attention \n
N/A
\param [in] handle: mailbox instance handle/A
\param [in] u32ReceiverId: mailbox ID of data receiver/A
\param [in/out] pstBuffer: intput and output buffer/A
\param [in] u32Flags: mailbox mode. 0 means block mode, 1 means timeout mode/A
\param [in] u32Param: mailbox max wait time, it is valid when mailbox mode is set to 1/A
\retval ::HI_SUCCESS  Call this API successful.
\retval ::HI_FAILURE  Call this API failure.
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_Send
(
    HI_HANDLE handle,
    HI_U32 u32ReceiverId,
    HI_UNF_MAILBOX_BUFFER_S *pstBuffer,
    HI_U32 u32Flags,
    HI_U32 u32Param
);

/**
\brief  start transaction.                    CNcomment:\BF\AA\C6\F4\CA\C2\CE\F1\B4\A6\C0\ED CNend
\attention \n
N/A
\param [in] handle: mailbox instance handle/A
\retval ::HI_SUCCESS  Call this API successful.
\retval ::HI_FAILURE  Call this API failure.
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_BeginTransaction(HI_HANDLE handle);

/**
\brief  end transaction.                    CNcomment:\BD\E1\CA\F8\CA\C2\CE\F1\B4\A6\C0\ED CNend
\attention \n
N/A
\param [in] handle: mailbox instance handle/A
\retval ::HI_SUCCESS  Call this API successful.
\retval ::HI_FAILURE  Call this API failure.
\see \n
N/A
*/
HI_S32 HI_UNF_MAILBOX_EndTransaction(HI_HANDLE handle);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif /** __HI_UNF_MAILBOX_H__*/

