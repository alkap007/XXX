/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
File Name     : hi_unf_ir.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date  : 2012-08-24
Last Modified by:
Description   : Application programming interfaces (APIs) of IR
Function List :
Change History:
 ******************************************************************************/

#ifndef __HI_UNF_IR_H__
#define __HI_UNF_IR_H__

#include "hi_common.h"
#include "hi_error_mpi.h"
//#include "hi_unf_keyled.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      IR */
/** @{ */  /** <!-- [IR] */

/**status of key*/
/**CNcomment:\B0\B4\BC\FC״̬*/
typedef enum  hiUNF_KEY_STATUS_E
{
    HI_UNF_KEY_STATUS_DOWN = 0 ,   /**<Pressed*/   /**<CNcomment:\B0\B4\CF°\B4\BC\FC */
    HI_UNF_KEY_STATUS_HOLD ,       /**<Hold*/      /**<CNcomment:\B0\B4ס\B2\BB\B6\AF */
    HI_UNF_KEY_STATUS_UP ,         /**<Released*/  /**<CNcomment:̧\C6𰴼\FC */

    HI_UNF_KEY_STATUS_BUTT
}HI_UNF_KEY_STATUS_E ;

/**Code type supported by the infrared (IR) module*/
/**CNcomment:IR֧\B3ֵ\C4\C2\EB\D0\CD*/
typedef enum hiUNF_IR_CODE_E
{
    HI_UNF_IR_CODE_NEC_SIMPLE = 0,  /**<NEC with simple repeat code*/   /**<CNcomment:NEC with simple repeat code\C2\EB\D0\CD*/
    HI_UNF_IR_CODE_TC9012,          /**<TC9012 code*/                   /**<CNcomment:TC9012\C2\EB\D0\CD*/
    HI_UNF_IR_CODE_NEC_FULL,        /**<NEC with full repeat code*/     /**<CNcomment:NEC with full repeat code\C2\EB\D0\CD*/
    HI_UNF_IR_CODE_SONY_12BIT,      /**<SONY 12-bit code */             /**<CNcomment:SONY 12BIT\C2\EB\D0\CD*/
    HI_UNF_IR_CODE_RAW,               /**<Raw code*/	                    /**<CNcomment:raw \C2\EB\D0\CD*/
    HI_UNF_IR_CODE_BUTT
}HI_UNF_IR_CODE_E;

/**List of IR code type. For details about HI_UNF_IR_STD, see HI_UNF_IR_CODE_E.*/
/**CNcomment:IR\C2\EB\D0\CD\C1б\ED,HI_UNF_IR_STD\B2\BF\B7\D6\C7\EB\B2\CE\D5\D5HI_UNF_IR_CODE_E */
typedef enum hiUNF_IR_PROTOCOL_E
{
    HI_UNF_IR_NEC,               /**<For NEC protocol*/                          /**<CNcomment:NEC\C2\EB\D0\CD*/
    HI_UNF_IR_RC6A = 10,         /**<For RC6A protocol*/                         /**<CNcomment:RC6A\C2\EB\D0\CD*/
    HI_UNF_IR_RC5,               /**<For RC5 protocol*/                          /**<CNcomment:RC5\C2\EB\D0\CD*/
    HI_UNF_IR_LOW_LATENCY_PROTOCOL,
    HI_UNF_IR_RC6_MODE0,         /**<For RC6 mode 0*/                            /**<CNcomment:RC6 mode0\C2\EB\D0\CD*/
    HI_UNF_IR_RCMM,              /**<For RCMM 24/32 protocol*/                   /**<CNcomment:RCMM 24/32\C2\EB\D0\CD*/
    HI_UNF_IR_RUWIDO,            /**<For Ruwido protocol*/                       /**<CNcomment:Ruwido\C2\EB\D0\CD*/
    HI_UNF_IR_RCRF8,             /**<For RCRF8 protocol*/                        /**<CNcomment:RCRF8\C2\EB\D0\CD*/
    HI_UNF_IR_MULTIPLE,          /**<For multiple protocol support*/             /**<CNcomment:Multiple\C2\EB\D0\CD*/    
    HI_UNF_IR_RMAP,              /**<For RMAP protocol with Mancester coding*/   /**<CNcomment:RMAP \C2\FC\B3\B9˹\CC\D8\C2\EB\D0\CD*/
    HI_UNF_IR_RSTEP,             /**<For RSTEP protocol*/                        /**<CNcomment:RSTEP\C2\EB\D0\CD*/
    HI_UNF_IR_RMAP_DOUBLEBIT,    /**<For RMAP protocol with Double bit coding*/  /**<CNcomment:RMAP ˫bit\C2\EB\D0\CD*/
    HI_UNF_IR_LOW_LATENCY_PRO_PROTOCOL,
    HI_UNF_IR_XMP,               /**<For XMP protocol*/                          /**<CNcomment:XMP\C2\EB\D0\CD*/
    HI_UNF_IR_USER_DEFINED,      /**<For user protocol*/                         /**<CNcomment:\D3û\A7\D7Զ\A8\D2\E5\C2\EB\D0\CD*/    
    HI_UNF_IR_PROTOCOL_BUTT 
} HI_UNF_IR_PROTOCOL_E;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      IR */
/** @{ */  /** <!-- [IR] */
/*---IR---*/

/**
\brief Starts the IR device.
CNcomment:\brief \B4\F2\BF\AAIR\C9豸\A1\A3CNend

\attention \n
This API can be called repeatedly. Key IDs can be received only after you can start the IR device, and then call HI_UNF_IR_Enable. \n
CNcomment:\D6ظ\B4\B5\F7\D3û᷵\BBسɹ\A6\A3\AC\B4\F2\BF\AA\C9豸\BA\F3\B1\D8\D0\EB\D4ٵ\F7\D3\C3HI_UNF_IR_Enable\B2\C5\C4\DC\D5\FD\B3\A3\BD\D3\CAռ\FCֵ\A1\A3CNend

\param N/A                                                                   CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_OPEN_ERR   The IR device fails to open                   CNcomment:IR\C9豸\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Init(HI_VOID);

#define HI_UNF_IR_Open() HI_UNF_IR_Init()

/**
\brief Stops the IR device.
CNcomment:\brief \B9ر\D5IR\C9豸\A1\A3CNend

\attention \n
This API can be called repeatedly. \n
CNcomment:\D6ظ\B4\B5\F7\D3ùرջ᷵\BBسɹ\A6\A1\A3CNend

\param  N/A                                                                  CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_CLOSE_ERR  The IR device fails to close.                 CNcomment:IR\C9豸\B9ر\D5ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_DeInit(HI_VOID);

#define HI_UNF_IR_Close() HI_UNF_IR_DeInit()

/**
\brief Enables the IR device.
CNcomment:\brief ʹ\C4\DCIR\C9豸\A1\A3CNend
\attention \n
N/A
\param[in] bEnable  IR enable. HI_TRUE: enabled; HI_FALSE: disabled           CNcomment:IR ʹ\C4ܿ\AA\B9\D8, HI_TRUE ʹ\C4\DC, HI_FALSE \BD\FB\D3á\A3CNend
\retval HI_SUCCESS Success                                                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.               CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                   CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_ENABLE_FAILED It fails to enable IR device.               CNcomment:ʹ\C4\DC\C9豸ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Enable ( HI_BOOL bEnable);

/**
\brief Obtains the protocol type of a remote control.
CNcomment:\brief \BB\F1ȡң\BF\D8\C6\F7\B5\C4Э\D2\E9\C0\E0\D0\CD \A1\A3CNend

\attention \n
This interface is only supported in IR_STD mode. And it must be used after function "HI_UNF_IR_GetValueWithProtocol".\n
CNcomment:\B4˽ӿ\DAֻ\D4\DAIR_STDģʽ\CF\C2֧\B3֡\A3\D0\E8Ҫ\D4\DAHI_UNF_IR_GetValueWithProtocol\BA\AF\CA\FD\BA\F3\B5\F7\D3á\A3 CNend

\param[out]  penProtocol  protocol type pointer,reference HI_UNF_IR_PROTOCOL_E for detail   CNcomment:Э\D2\E9\C0\E0\D0\CDָ\D5\EB  \BE\DF\CC庬\D2\E5\C7\EB\B2ο\BC::HI_UNF_IR_PROTOCOL_E CNend
\retval HI_SUCCESS Success                                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                       CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.                                 CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/

HI_S32 HI_UNF_IR_GetProtocol(HI_UNF_IR_PROTOCOL_E *penProtocol);

/**
\brief obtain name of remote control protocol
CNcomment:\brief \BB\F1ȡң\BF\D8\C6\F7\B5\C4Э\D2\E9\C3\FB\B3\C6 \A1\A3CNend

\attention \n
when IR_TYPE=IR_LIRC is effective, this interface is not supported now.
CNcomment:\B5\B1IR_TYPE=IR_LIRCʱ\D3\D0Ч\A3\AC\B4˽ӿ\DA\D4ݲ\BB֧\B3\D6 CNend

\param[out]  pProtocolName  used to save first address of the protocol name buffer    CNcomment:\D3\C3\D3ڴ洢Э\D2\E9\C3\FB\B3ƵĻ\BA\B3\E5\C7\F8\CA׵\D8ַ CNend
\param[in]   s32BufLen      used to save length of the protocol name buffer           CNcomment:\D3\C3\D3ڴ洢Э\D2\E9\C3\FB\B3ƵĻ\BA\B3\E5\C7\F8\B3\A4\B6\C8 CNend
\retval ::HI_ERR_IR_UNSUPPORT   It is not supported.                                  CNcomment:\B2\D9\D7\F7\B2\BB֧\B3\D6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetProtocolName(HI_CHAR *pProtocolName, HI_S32 s32BufLen);

/**
\brief Obtains the key values and key status of the remote control.
CNcomment:\brief \BB\F1ȡң\BF\D8\C6\F7\B5İ\B4\BC\FCֵ\BAͰ\B4\BC\FC״̬ \A1\A3CNend

\attention \n

\param[out]  penPressStatus  Key status. For details about the definition, see the description of ::HI_UNF_KEY_STATUS_E.  CNcomment:\B0\B4\BC\FC״̬\A1\A3\BE\DF\CC庬\D2\E5\C7\EB\B2ο\BC::HI_UNF_KEY_STATUS_E CNend
\param[out]  pu64KeyId  Key value                                                     CNcomment:\B0\B4\BC\FCֵ CNend
\param[out]  pszProtocolName  used to save first address of the protocol name buffer    CNcomment:\D3\C3\D3ڴ洢Э\D2\E9\C3\FB\B3ƵĻ\BA\B3\E5\C7\F8\CA׵\D8ַ CNend
\param[in]   s32NameSize      used to save length of the protocol name buffer           CNcomment:\D3\C3\D3ڴ洢Э\D2\E9\C3\FB\B3ƵĻ\BA\B3\E5\C7\F8\B3\A4\B6\C8 CNend
\param[in] u32TimeoutMs  Timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block  CNcomment:\B3\ACʱֵ, \B5\A5λ\CAǺ\C1\C3\EB, 0 - \B2\BB\D7\E8\C8\FB, 0xFFFFFFFF-\D3\C0\BE\C3\D7\E8\C8\FB CNend
\retval HI_SUCCESS Success                                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                       CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.                                 CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                           CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_SET_BLOCKTIME_FAILED  The IR device fails to set block time.      CNcomment:\C9\E8\D6\C3\D7\E8\C8\FBʱ\BC\E4ʧ\B0\DC CNend
\retval ::HI_ERR_IR_READ_FAILED  The IR device fails to read key.                     CNcomment:\B6\C1ȡ\BC\FCֵ\BA\CD״̬ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetValueWithProtocol(HI_UNF_KEY_STATUS_E *penPressStatus, HI_U64 *pu64KeyId,
                                      HI_CHAR *pszProtocolName, HI_S32 s32NameSize, HI_U32 u32TimeoutMs);

#define HI_UNF_IR_GetValue(penPressStatus, pu64KeyId, u32TimeoutMs) HI_UNF_IR_GetValueWithProtocol(penPressStatus, \
                                                                                                   pu64KeyId, NULL, 0, \
                                                                                                   u32TimeoutMs)


/**
\brief Set key fetch or symbol fetch from ir driver.
CNcomment:\brief \C9趨\B4Ӻ\EC\CD\E2\C7\FD\B6\AF\BB\F1ȡ\B5\C4\CAǼ\FCֵ\BB\B9\CA\C7\C2\E3\B5\E7ƽ \A1\A3CNend

\attention \n
when IR_TYPE=IR_S2 is effective.
CNcomment:\B5\B1IR_TYPE=IR_S2ʱ\D3\D0Ч\A1\A3CNend

\param[in] mode 0 means key mode. 1 means symbol mode                                 CNcomment:0\BB\F1ȡ\BC\FCֵ\A3\AC1\BB\F1ȡ\C2\E3\B5\E7ƽ CNend
\retval HI_SUCCESS Success                                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                       CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.                           CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_SET_FETCHMETHOD_FAILED  The IR device fails to set fetch method.  CNcomment:\C9\E8\D6û\F1ȡ\B7\BDʽʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetFetchMode(HI_S32 s32Mode);

/**
\brief Obtains the raw symbols from ir driver.
CNcomment:\brief \BB\F1ȡң\BF\D8\C6\F7\B5\C4\C2\E3\B5\E7ƽ \A1\A3CNend

\attention \n
when IR_TYPE=IR_S2 is effective.
CNcomment:\B5\B1IR_TYPE=IR_S2ʱ\D3\D0Ч\A1\A3CNend

\param[out]  pu64lower  lower pluse value                                             CNcomment:\C2\E3\B5\E7ƽ\B6Եĵ\CDλ CNend
\param[out]  pu64upper  upper space value                                             CNcomment:\C2\E3\B5\E7ƽ\B6Եĸ\DFλ CNend
\param[in] s32TimeoutMs read timeout .                                                CNcomment:\B6\C1\B3\ACʱʱ\BC䡣CNend

\retval HI_SUCCESS Success                                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized. 					  CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.								  CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_IR_SET_BLOCKTIME_FAILED  The IR device fails to set block time.      CNcomment:\C9\E8\D6\C3\D7\E8\C8\FBʱ\BC\E4ʧ\B0\DC CNend
\retval ::HI_ERR_IR_READ_FAILED  The IR device fails to read key.					  CNcomment:\B6\C1ȡ\BC\FCֵ\BA\CD״̬ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetSymbol(HI_U64 *pu64First, HI_U64* pu64Second, HI_U32 u32TimeoutMs);

/**
\brief Enables or disables the function of reporting the released status of a key.
CNcomment:\brief \C9\E8\D6\C3\CAǷ\F1\C9ϱ\A8\B0\B4\BC\FC\B5\AF\C6\F0״̬\A1\A3CNend

\attention \n
The function is enabled by default.
CNcomment:\C8粻\C9\E8\D6ã\ACĬ\C8\CFΪ\B4򿪡\A3CNend

\param[in] bEnable      Key released enable.  CNcomment:\B0\B4\BC\FC\B5\AF\C6\F0\D3\D0Ч\A1\A3CNend
                        0: disabled           CNcomment:0\A3\BA\B9رգ\BBCNend
                        1: enabled            CNcomment: 1\A3\BAʹ\C4ܡ\A3CNend
\retval HI_SUCCESS  Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.         CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_INVALID_PARA  The parameter is invalid.             CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_SET_KEYUP_FAILED  It fails to enable released key.  CNcomment:\C9\E8\D6\C3\C9ϱ\A8\B0\B4\BC\FC\B5\AF\C6\F0״̬ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableKeyUp(HI_BOOL bEnable);

/**
\brief Enables or disables the function of reporting the same key value. If keys are pressed and held down, data is continuously transmitted to the receive buffer. Therefore, you can enable or disable this function for applications as required.
CNcomment:\brief \C9\E8\D6\C3\CAǷ\F1\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\A1\A3һֱ\B0\B4\BC\FCʱ\A3\AC\CA\FD\BEݻ\E1ԴԴ\B2\BB\B6ϵ\C4\CB\CD\C8뵽\BD\D3\CAջ\BA\B3\E5\C7\F8\A3\AC\D2\F2\B4\CBӦ\D3ó\CC\D0\F2\BF\C9\D2Ը\F9\BE\DD\D0\E8Ҫ\C0\B4\C9\E8\D6\C3\CAǷ\F1\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\A1\A3CNend

\attention \n
The function is enabled by default.\n
This API must work with HI_UNF_IR_RepKeyTimeoutVal. The API HI_UNF_IR_RepKeyTimeoutVal is used to set the interval of reporting the same key value.\n
If the function of reporting the same key value is enabled, the keys are pressed and held down, and the interval is set to 300 ms, data is reported once every 300 ms.
If the function is disabled, data is reported only once regardless of how long the keys are held down.
CNcomment:\C8粻\C9\E8\D6ã\ACĬ\C8\CFΪ\B4\F2\BF\AA\n 
\B4˽ӿ\DA\D0\E8Ҫ\BA\CDHI_UNF_IR_RepKeyTimeoutVal\BA\AF\CA\FD\BD\E1\BA\CFʹ\D3ã\AC\D3\C9HI_UNF_IR_RepKeyTimeoutVal\C9\E8\D6\C3\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\B5ļ\E4\B8\F4\n 
\C8\E7\B9\FBʹ\C4\DC\C1\CB\D6ظ\B4\B0\B4\BC\FC\C9ϱ\A8\A3\AC\B5\B1\B0\B4\BC\FCһֱ\B4\A6\D3ڰ\B4\CF\C2״̬\A3\AC\BC\E4\B8\F4\C9\E8Ϊ300\BA\C1\C3룬\D4\F2ÿ300\BA\C1\C3\EB\BB\E1\C9ϱ\A8һ\B4\CE\CA\FD\BE\DD\n 
\C8\E7\B9\FB\BD\FBֹ\C1\CB\D6ظ\B4\B0\B4\BC\FC\C9ϱ\A8\A3\AC\D4\F2\B2\BB\C2۰\B4\CF¶೤ʱ\BC䣬ֻ\C9ϱ\A8һ\B4\CE\CA\FD\BEݡ\A3CNend
\param[in] bEnable     Repeat key report enable.    CNcomment:\B0\B4\BC\FC\B2\FA\C9\FA\D6ظ\B4\B0\B4\BC\FC\B9\A6\C4ܡ\A3CNend
                       0: disabled                  CNcomment:0\A3\BA\B9رգ\BBCNend
                       1: enabled                   CNcomment:1\A3\BAʹ\C4ܡ\A3CNend
\retval HI_SUCCESS Success                                                     CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT   The IR device is not initialized.               CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                   CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_SET_REPEAT_FAILED   It fails to enable repeat key.         CNcomment:\C9\E8\D6\C3\C9ϱ\A8\D6ظ\B4\BC\FCʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableRepKey(HI_BOOL bEnable);

/**
\brief Sets the interval (in ms) of reporting the same key value.
CNcomment:\brief \C9\E8\D6\C3\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\B5\C4ʱ\BC\E4\BC\E4\B8\F4\A3\AC\B5\A5λΪms \A1\A3CNend

\attention \n
This API is unavailable if the function of reporting the same key value is disabled by calling HI_UNF_IR_IsRepKey.
CNcomment:\B5\B1HI_UNF_IR_IsRepKey\C5\E4\D6\C3Ϊ\B2\BB\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FCʱ\A3\AC\B4˽ӿ\DA\C9\E8\D6\C3\CE\DEЧ\A1\A3CNend

\param[in] u32TimeoutMs   Interval of reporting the same key value. The interval ranges from 0 ms to 65,536 ms.\n
						  The value 0 will be set to 108, and the value bigger than 65536 will be set to 65536 \n
                          CNcomment:\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\B5\C4ʱ\BC\E4\BC\E4\B8\F4\A3\AC\C9\E8\D6÷\B6Χ\A3\BA0ms\A1\AB65536ms \A1\A3\n
						  \B5\C8\D3\DA0\B5Ĳ\CE\CA\FD\BBᱻǿ\D6\C6\C9\E8\D6ó\C9108\A3\AC\B4\F3\D3\DA65536\B5Ĳ\CE\CA\FD\BBᱻǿ\D6\C6\C9\E8\D6ó\C965536\A1\A3CNend
\retval HI_SUCCESS Success CNcomment:                                          CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_SET_REPKEYTIMEOUT_FAILED  It fails to set repeat key timeout.  CNcomment:\C9\E8\D6\C3\C9ϱ\A8\D6ظ\B4\B0\B4\BC\FC\BC\E4\B8\F4ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetRepKeyTimeoutAttr(HI_U32 u32TimeoutMs);

/**
\brief Sets the code type of the remote control.
CNcomment:\brief \C9\E8\D6\C3ң\BF\D8\C6\F7\C2\EB\D0͡\A3CNend

\attention \n
when IR_TYPE=IR_STD is effective.
CNcomment:\B5\B1IR_TYPE=IR_STDʱ\D3\D0Ч\A1\A3CNend


\param[in] enIRCode Four standard code types of the remote control are supported by default.  CNcomment:Ĭ\C8\CF֧\B3\D64\D6ֱ\EA׼ң\BF\D8\C6\F7\C2\EB\D0ͣ\BACNend
                     HI_UNF_IR_CODE_NEC_SIMPLE:Nec With Simple code type. CNcomment:Nec Simple \C2\EB\D0͡\A3 CNend
                     HI_UNF_IR_CODE_TC9012:TC9012 code type.              CNcomment:TC9012 \C2\EB\D0͡\A3     CNend
                     HI_UNF_IR_CODE_NEC_FULL:Nec With Full code type.     CNcomment:Nec Full \C2\EB\D0͡\A3   CNend
                     HI_UNF_IR_CODE_SONY_12BIT:Sony 12 Bit code type.     CNcomment:Sony 12 bit \C2\EB\D0͡\A3CNend
\retval HI_SUCCESS Success                                                 CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.            CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.               CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_SETFORMAT_FAILED It fails to set IR code type.         CNcomment:\C9\E8\D6\C3IR\C0\E0\D0\CDʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_SetCodeType(HI_UNF_IR_CODE_E enIRCode);

/**
\brief  Resets the IR device.
CNcomment:\brief  \B8\B4λIR\C9豸\A1\A3CNend

\attention \n
This API is used to delete the key values in the buffer.
CNcomment:ֻ\CAǰ\D1buffer\D6еļ\FCֵ\C7\E5\B5\F4\A1\A3CNend

\param N/A         CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                 CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_RESET_FAILED  The IR device fails to reset.                 CNcomment:IR\C9豸\B8\B4λʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_Reset(HI_VOID);

/**
\brief enable an infrared code.
CNcomment:\brief  \BC\A4\BB\EEĳ\C0\E0\BA\EC\CD\E2ң\BF\D8\C6\F7Э\D2顣CNend

\attention \n
when IR_TYPE=IR_S2 is effective.
CNcomment:\B5\B1IR_TYPE=IR_S2ʱ\D3\D0Ч\A1\A3CNend

\param N/A         CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                 CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.							CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_ENABLE_PROT_FAILED  It fails to enable an infrared code.    CNcomment:\BC\A4\BB\EEң\BF\D8Э\D2\E9ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_EnableProtocol(const HI_CHAR* pszProtocolName);

/**
\brief disable an infrared code.
CNcomment:\brief  \BD\FB\D3\C3ĳ\C0\E0\BA\EC\CD\E2ң\BF\D8\C6\F7Э\D2顣CNend

\attention \n
when IR_TYPE=IR_S2 is effective.
CNcomment:\B5\B1IR_TYPE=IR_S2ʱ\D3\D0Ч\A1\A3CNend

\param N/A         CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                 CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.							CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_DISABLE_PROT_FAILED   It fails to disalbe an infrared code. CNcomment:\BD\FB\D3\C3ң\BF\D8Э\D2\E9ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_DisableProtocol(const HI_CHAR* pszProtocolName);

/**
\brief get the enable or disable status of  an infrared code.
CNcomment:\brief  \BB\F1ȡĳ\C0\E0\BA\EC\CD\E2ң\BF\D8\C6\F7Э\D2鼤\BB\EE״̬\A1\A3CNend

\attention \n
when IR_TYPE=IR_S2 is effective.
CNcomment:\B5\B1IR_TYPE=IR_S2ʱ\D3\D0Ч\A1\A3CNend

\param N/A         CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                                      CNcomment:\B3ɹ\A6 CNend
\retval HI_FAILURE Failure                                                      CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_IR_NOT_INIT  The IR device is not initialized.                 CNcomment:IR\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_IR_NULL_PTR  The pointer is invalid.							CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_IR_INVALID_PARA   The parameter is invalid.                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_IR_GET_PROTENABLE_FAILED It fails to get status of an infrared code.  CNcomment:\BB\F1ȡң\BF\D8Э\D2\E9״̬ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_IR_GetProtocolEnabled(const HI_CHAR* pszProtocolName, HI_BOOL *pbEnabled);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_IR_H__ */
