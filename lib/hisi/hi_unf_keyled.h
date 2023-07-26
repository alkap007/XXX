/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
File Name     : hi_unf_keyled.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date  : 2012-08-24
Last Modified by:
Description   : Application programming interfaces (APIs) of the KEYLED
Function List :
Change History:
 ******************************************************************************/

#ifndef __HI_UNF_KEYLED_H__
#define __HI_UNF_KEYLED_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      KEYLED */
/** @{ */  /** <!-- [KEYLED] */
/**keyled type*/
/**CNcomment:KEYLED\C0\E0\D0\CD */
typedef enum  hiUNF_KEYLED_TYPE_E
{
    HI_UNF_KEYLED_TYPE_74HC164 = 0x0, /**<KEYLED type:74HC164*/                   /**<CNcomment:KEYLED\D0ͺ\C5: 74HC164 */
    HI_UNF_KEYLED_TYPE_PT6961,    /**<KEYLED type: PT6961*/                       /**<CNcomment:KEYLED\D0ͺţ\BAPT6961 */
    HI_UNF_KEYLED_TYPE_CT1642,    /**<KEYLED type: CT1642*/                       /**<CNcomment:KEYLED\D0ͺţ\BACT1642 */
    HI_UNF_KEYLED_TYPE_PT6964,	  /**<KEYLED type: PT6964*/                       /**<CNcomment:KEYLED\D0ͺţ\BAPT6964 */
    HI_UNF_KEYLED_TYPE_FD650,     /**<KEYLED type: FD650*/                        /**<CNcomment:KEYLED\D0ͺţ\BAFD650 */
    HI_UNF_KEYLED_TYPE_GPIOKEY,   /**<KEYLED type :GPIOKEY*/   					 /**<CNcomment:GPIO\B0\B4\BC\FC\C3\E6\B0\E5*/
    HI_UNF_KEYLED_TYPE_BUTT       
}HI_UNF_KEYLED_TYPE_E;

/**Blink frequency level of the LED*/
/**CNcomment:LED\C9\C1˸Ƶ\C2ʼ\B6\B1\F0*/
typedef enum hiUNF_KEYLED_LEVEL_E
{
    HI_UNF_KEYLED_LEVEL_1 = 0x01,   /**<Level 1, slowest*/  /**<CNcomment:\BC\B6\B1\F01,\C9\C1˸Ƶ\C2\CA\D7\EE\C2\FD*/
    HI_UNF_KEYLED_LEVEL_2,          /**<Level 2*/           /**<CNcomment:\BC\B6\B1\F02 */
    HI_UNF_KEYLED_LEVEL_3,          /**<Level 3*/           /**<CNcomment:\BC\B6\B1\F03 */
    HI_UNF_KEYLED_LEVEL_4,          /**<Level 4*/           /**<CNcomment:\BC\B6\B1\F04 */
    HI_UNF_KEYLED_LEVEL_5,          /**<Level 5, fastest*/  /**<CNcomment:\BC\B6\B1\F05 , \C9\C1˸Ƶ\C2\CA\D7\EE\BF\EC*/

    HI_UNF_KEYLED_LEVEL_BUTT
}HI_UNF_KEYLED_LEVEL_E;

/**Blink sequence of LEDs*/
/**CNcomment:\C9\C1˸\B5\C4LED\D0\F2\BA\C5*/
typedef enum hiUNF_KEYLED_LIGHT_E
{
    HI_UNF_KEYLED_LIGHT_1 = 0x01,   /**<The first LED blinks.*/   /**<CNcomment:\B5\DA1\B8\F6LED\C9\C1˸*/
    HI_UNF_KEYLED_LIGHT_2,          /**<The second LED blinks.*/  /**<CNcomment:\B5\DA2\B8\F6LED\C9\C1˸*/
    HI_UNF_KEYLED_LIGHT_3,          /**<The third LED blinks.*/   /**<CNcomment:\B5\DA3\B8\F6LED\C9\C1˸*/
    HI_UNF_KEYLED_LIGHT_4,          /**<The fourth LED blinks.*/  /**<CNcomment:\B5\DA4\B8\F6LED\C9\C1˸*/
    HI_UNF_KEYLED_LIGHT_ALL,        /**<All LEDs blink.*/        /**<CNcomment:\CB\F9\D3\D0LED\BE\F9\C9\C1˸*/
    HI_UNF_KEYLED_LIGHT_NONE,       /**<All LEDs do not blink.*/  /**<CNcomment:\CB\F9\D3\D0LED\BE\F9\B2\BB\C9\C1˸*/

    HI_UNF_KEYLED_LIGHT_BUTT
}HI_UNF_KEYLED_LIGHT_E;

/**Display time of each LED*/
/**CNcomment:LED\CF\D4ʾʱ\BC\E4*/
typedef struct hiUNF_KEYLED_Time_S
{
    HI_U32 u32Hour;           /**<Hour*/   /**<CNcomment:ʱ*/
    HI_U32 u32Minute;         /**<Minute*/ /**<CNcomment:\B7\D6*/
}HI_UNF_KEYLED_TIME_S, *HI_UNF_KEYLED_TIME_S_PTR;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      KEYLED */
/** @{ */  /** <!-- [KEYLED] */
/**---- keyled ----*/

/**
\brief Initializes the KEYLED module.
CNcomment:\brief \B3\F5ʼ\BB\AFKEYLEDģ\BF顣CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڣ\AC\BB᷵\BBسɹ\A6\A1\A3CNend

\param N/A                                             CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  The KEYLED device fails to open. CNcomment:KEYLED\C9豸\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_Init(HI_VOID);


/**
\brief Deinitializes the KEYLED module.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFKEYLEDģ\BF顣CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڣ\AC\BB᷵\BBسɹ\A6\A1\A3CNend

\param N/A                                             CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  The KEYLED device fails to close. CNcomment:KEYLED\C9豸\B9ر\D5ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_DeInit(HI_VOID);

/**
\brief Selects the type of the KEYLED.
CNcomment:\brief ѡ\D4\F1KEYLED\C6\F7\BC\FE\C0\E0\D0͡\A3CNend

\attention \n
It is recommended to call this API once after the KEYLED module is initialized.
CNcomment:\BD\A8\D2\E9\B3\F5ʼ\BB\AF\BA\F3ֻѡ\D4\F1һ\B4Σ\AC\B2\BBҪ\D6ظ\B4\B5\F7\D3á\A3CNend

\param[in] enKeyLedType   KEYLED type                                           CNcomment:keyled\C0\E0\D0͡\A3 CNend
\retval ::HI_SUCCESS   Success                                                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED device is not initialized.         CNcomment:KEYLED\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_KEYLED_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                                     CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_KEYLED_SelectType(HI_UNF_KEYLED_TYPE_E enKeyLedType);

/**
\brief Enables the key function.
CNcomment:\brief \B4򿪰\B4\BC\FC\B9\A6\C4ܡ\A3CNend
\attention \n
The KEYLED module starts to receive key values after the key function is enabled.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.\n
CNcomment:\B4򿪺\F3\BF\AAʼ\BD\D3\CAհ\B4\BC\FC\n
\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڣ\AC\BB᷵\BBسɹ\A6\A1\A3CNend
\param N/A                                                                      CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                                                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED device is not initialized.         CNcomment:KEYLED\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                                     CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Open(HI_VOID);

/**
\brief Disables the key function.
CNcomment:\brief \B9رհ\B4\BC\FC\B9\A6\C4ܡ\A3CNend

\attention \n
The KEYLED module stops receiving key IDs after the key function is disabled.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.\n
CNcomment:\B9رպ\F3ֹͣ\BD\D3\CAհ\B4\BC\FC\n
\B1\BE\BDӿڵ\DAһ\B4ε\F7\D3\C3\C6\F0\D7\F7\D3\C3,\D6ظ\B4\B5\F7\D3÷\B5\BBسɹ\A6\A1\A3CNend

\param N/A                                                                      CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                                                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED device is not initialized.         CNcomment:KEYLED\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                                     CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Close(HI_VOID);

/**
\brief Clears the key values that are not received.
CNcomment:\brief \C7\E5\BFյ\B1ǰû\D3н\D3\CAյİ\B4\BC\FC\A1\A3CNend

\attention \n
This API is used to clear the buffer for storing the key values. In this way, the initial state is returned.
CNcomment:\C7\E5\BFհ\B4\BC\FCbuffer\A3\AC\BBص\BD\B3\F5ʼ״̬\A1\A3CNend
\param N/A Success                                                              CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                                                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED device is not initialized.         CNcomment:KEYLED\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                                     CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_Reset(HI_VOID);


/**
\brief Obtains a key value.
CNcomment:\brief \BB\F1ȡһ\B8\F6\B0\B4\BC\FCֵ\A1\A3CNend

\attention \n
This API is used to obtain the key value that is received first in the buffer. After this API is called, the key value and key status are returned.\n
The key status contains pressed, hold and released.\n
This API needs to work with ::HI_UNF_KEY_SetBlockTime.\n
If there are no key values, the API waits until timeout occurs. In this case, the error code ::HI_ERR_KEYLED_TIMEOUT is returned.\n
If the timeout is set to 0 in non-block mode, the error code ::HI_ERR_KEYLED_NO_NEW_KEY is returned when there are no key values.\n
If the timeout is set to 0xFFFFFFFF, it indicates infinite wait.\n
CNcomment:\BB\F1ȡbuffer\D6\D0\D7\EE\D4絽\B4\EF\B5İ\B4\BC\FCֵ\A3\AC\B7\B5\BBذ\B4\BC\FCֵ\B5\C4\CA\FDֵ\BA\CD״̬\n
״̬\B0\FC\BA\AC\B0\B4\CF£\AC\B3\A4\B0\B4\BA͵\AF\C6\F0\n
\BDӿ\DA\C5\E4\BA\CF::HI_UNF_KEY_SetBlockTime\BDӿ\DAһ\C6\F0ʹ\D3\C3\n
û\D3а\B4\BC\FCʱ\A3\AC\BD\F8\D0еȴ\FD\A3\AC\B3\ACʱ\BA\F3\CD˳\F6\B2\A2\B7\B5\BBس\ACʱ\B4\ED\CE\F3\C2\EB\n
\B3\ACʱֵΪ0ʱΪ\B7\C7\D7\E8\C8\FB\BDӿڣ\ACû\D3а\B4\BC\FCֱ\BDӷ\B5\BB\D8û\D3а\B4\BC\FC\B4\ED\CE\F3\C2\EB\n
\B3\ACʱֵ\C9\E8\D6\C3Ϊ0xffffffff\A3\ACһֱ\B5ȴ\FD\A1\A3CNend
\param[out] pu32PressStatus Key status: pressed(0x0), hold(0x1) or released(0x2) CNcomment:\B0\B4\BC\FC״̬\CAǰ\B4\CF£\AC\B3\A4\B0\B4\BB\B9\CAǵ\AF\C6\F0\A1\A3CNend
\param[out] pu32KeyId  Key value                                                 CNcomment:\B0\B4\BC\FCֵ\A1\A3CNend
\retval ::HI_SUCCESS  Success                                                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.          CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\retval ::HI_ERR_KEYLED_NULL_PTR  The pointer is null.                           CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_KEYLED_NO_NEW_KEY  There are no key values.                     CNcomment:û\D3а\B4\BC\FC CNend
\retval ::HI_ERR_KEYLED_TIMEOUT  Waiting for key values times out.               CNcomment:\B5ȴ\FD\B0\B4\BC\FC\B3\ACʱ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_GetValue(HI_U32 * pu32PressStatus, HI_U32 * pu32KeyId);

/**
\brief Sets the timeout of reading key IDs.
CNcomment:\brief \C9\E8\D6ð\B4\BC\FC\B6\C1ȡ\B5ĳ\ACʱʱ\BC䡣CNend

\attention \n
If the timeout is set to 0, the API is not blocked. If there is no key ID, the error code HI_ERR_KEYLED_NO_NEW_KEY is returned.\n
If the timeout is set to 0xFFFFFFFF, it indicates infinite wait.\n
The default time is 500 ms.\n
CNcomment:\B3\ACʱֵΪ0ʱ\B2\BB\D7\E8\C8\FB\A3\ACû\D3а\B4\BC\FCֱ\BDӷ\B5\BB\D8û\D3а\B4\BC\FC\B4\ED\CE\F3\C2\EB\n
\B3\ACʱֵ\C9\E8\D6\C3Ϊ0xffffffff\A3\ACһֱ\B5ȴ\FD\A1\A3\n 
Ĭ\C8ϵĳ\ACʱ\C5ж\CFʱ\BC\E4Ϊ500ms\A1\A3CNend
\param[in] u32BlockTimeMs   Timeout, in ms                               CNcomment:\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_SetBlockTime(HI_U32 u32BlockTimeMs);


/**
\brief Set the time of pressing a key repeatedly.
CNcomment:\brief \C9\E8\D6\C3\D6ظ\B4\B0\B4\BC\FC\B5\C4ʱ\BC䡣CNend

\attention \n
If a key is pressed for a period of time, it considers that the key is pressed repeatedly.\n
The time ranges from 108 ms to 65536 ms. If the time is not within the range, the time is automatically restricted to this range.\n
The default time is 200 ms.\n
CNcomment:\B5\B1ĳ\B8\F6\BC\FC\B4\A6\D3ڰ\B4\CF\C2״̬\A3\AC\B3\AC\B9\FD\C9\E8\D6õ\C4ʱ\BC\E4ֵ\C5ж\CFΪ\D6ظ\B4\B0\B4\BC\FC\n
\D6ظ\B4\B0\B4\BC\FC\B5\C4\C9\E8\D6÷\B6Χ\D4\DA108ms\B5\BD65536ms֮\BC䣬\B3\AC\B9\FD\D5\E2\B8\F6\B7\B6Χ\BB\E1\D7Զ\AFԼ\CA\F8\B5\BD\C9\CF\CF޻\F2\CF\C2\CF\DE\C9\CF\n
Ĭ\C8ϵ\C4\D6ظ\B4\B0\B4\BC\FC\C5ж\CFʱ\BC\E4Ϊ200ms\A1\A3CNend

\param[in] u32RepTimeMs  Time of pressing a key repeatedly, in ms       CNcomment:\C5ж\CFΪ\D6ظ\B4\B0\B4\BC\FC\B5\C4ʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\see \n 
N/A
*/
HI_S32 HI_UNF_KEY_RepKeyTimeoutVal(HI_U32 u32RepTimeMs);

/**
\brief Enables or disables the function of reporting the same key ID.
CNcomment:\brief \C9\E8\D6\C3\CAǷ\F1ʹ\C4\DC\D6ظ\B4\B0\B4\BC\FC\A1\A3CNend

\attention \n
The ID of a pressed key is reported consecutively only after the report function is enabled.\n
CNcomment:ֻ\D3\D0ʹ\C4ܺ\F3\A3\ACһֱ\B0\B4סĳ\B8\F6\BC\FC\A3\AC\B2\C5\C4\DC\C1\AC\D0\F8\C9ϱ\A8\BC\FCֵ\A1\A3CNend

\param[in] u32IsRepKey Repeat key report enable. 1: enabled; 0: disabled   CNcomment:\CAǷ\F1ʹ\C4\DC\D6ظ\B4\B0\B4\BC\FC\A3\AC1 ʹ\C4ܣ\AC0 \B2\BBʹ\C4ܡ\A3CNend
\retval ::HI_SUCCESS Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                                CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.    CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_KEY_IsRepKey(HI_U32 u32IsRepKey);

/**
\brief Enables or disables the function of reporting the released status of a key.
CNcomment:\brief \C9\E8\D6\C3\CAǷ\F1\C9ϱ\A8\B0\B4\BC\FC\B5\AF\C6\F0\A1\A3CNend

\attention \n
The released statuses of keys are reported only after the report function is enabled. Otherwise, only the pressed statuses are reported.\n
CNcomment:ʹ\C4ܺ\F3\B2Ż\E1\C9ϱ\A8\B0\B4\BC\FC\B5\AF\C6\F0\CA¼\FE\A3\AC\B2\BBȻֻ\C9ϱ\A8\B0\B4\CF\C2\CA¼\FE\A1\A3CNend

\param[in] u32IsKeyUp Repeat key report enable. 1: enabled; 0: disabled  CNcomment:\CAǷ\F1ʹ\C4\DC\D6ظ\B4\B0\B4\BC\FC\A3\AC1 ʹ\C4ܣ\AC0 \B2\BBʹ\C4ܡ\A3CNend
\retval ::HI_SUCCESS Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\see \n 
N/A
*/
HI_S32 HI_UNF_KEY_IsKeyUp(HI_U32 u32IsKeyUp);

/**
\brief Enables the display function of LEDs.
CNcomment:\brief \B4\F2\BF\AA\CA\FD\C2\EB\B9\DC\CF\D4ʾ\B9\A6\C4ܡ\A3CNend

\attention \n
The LEDs work only after the display function is enabled.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.\n
CNcomment:\B4򿪺\F3\B2Ż\E1\D3\D0\CA\FD\C2\EB\B9ܵ\C4\CF\D4ʾ\n
\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڣ\AC\BB᷵\BBسɹ\A6\A1\A3CNend

\param N/A                                     CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.    CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Open(HI_VOID);

/**
\brief Disables the display function of LEDs.
CNcomment:\brief \B9ر\D5\CA\FD\C2\EB\B9\DC\CF\D4ʾ\B9\A6\C4ܡ\A3CNend

\attention \n
The LEDs do not work after the display function is disabled.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.\n
CNcomment:\B9رպ\F3ֹͣ\CA\FD\C2\EB\B9\DC\CF\D4ʾ\n
\B1\BE\BDӿڵ\DAһ\B4ε\F7\D3\C3\C6\F0\D7\F7\D3\C3,\D6ظ\B4\B5\F7\D3÷\B5\BBسɹ\A6\A1\A3CNend
 
\param N/A                                    CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.   CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Close(HI_VOID);


/**
\brief Displays characters based on the type of the input code.
CNcomment:\brief \B8\F9\BEݴ\AB\C8\EB\B5\C4\C2\EB\D0\CDֵ\BD\F8\D0\D0\CF\D4ʾ\A1\A3CNend

\attention \n
Each LED displays a character that corresponds to the value of one byte.\n
During displaying, the values of the four characters to be displayed need to be combined to form a 32-bit unsigned int data segment. The data serves as the parameter value of this API.\n
The four LEDs from left to right display bit[7:0], bit[15:8], bit[23:16], and bit[31:24] of the data respectively.\n
For example, if you want to display "0123" on LEDs, you need to combine the display values corresponding to these characters to form the following unsigned int variable:\n
  Unsigned int parameter = 0x03 + (0x9F <<8) + (0x25<<16) + (0x0D <<24);\n
Where, 0x03, 0x9F, 0x25, and 0x0D are the display values of 0, 1, 2, and 3 respectively.\n
The following shows the mapping between the segments of a 7-segment LED and data bits:\n
       --7--       \n
      |     |      \n
     2|     |6     \n
      |--1--       \n
      |     |      \n
     3|     |5     \n
       --4-- .0    \n
The common display characters and values of the LEDs on HiSilicon demo board are as follows in the case of co-anode (the display characters and values need to be reversed in the case of co-cathode):
  Digitals 0-9: 0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09\n
  Upper-case letters A-Z (the characters that cannot be displayed are expressed as 0xFF):\n
     0xFF, 0xFF, 0x63, 0xFF, 0x61, 0x71, 0xFF, 0x91, 0xFF, 0xFF, 0xFF, 0xE3, 0xFF,\n
     0xFF, 0x03, 0x31, 0xFF, 0xFF, 0x49, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF\n
  Lower-case letters a-z (the characters that cannot be displayed are expressed as 0xFF):\n
    0xFF, 0xC1, 0xE5, 0x85, 0x21, 0xFF, 0x09, 0xD1, 0xDF, 0xFF, 0xFF, 0x9F, 0xFF,\n
    0xD5, 0xC5, 0x31, 0x19, 0xFF, 0x49, 0xFF, 0xC7, 0xE1, 0xFF, 0xFF, 0xFF, 0xFF
CNcomment:	ÿ\B8\F6\CA\FD\C2\EB\B9\DCҪ\CF\D4ʾ\B5\C4\D7ַ\FB\B6\D4Ӧһ\B8\F6\D7ֽڵ\C4\CF\D4ʾֵ\A1\A3\n
\CF\D4ʾʱ\D0\E8Ҫ\BD\AB4 \B8\F6\B4\FD\CF\D4ʾ\D7ַ\FB\B6\D4Ӧ\B5\C4\CF\D4ʾֵ\D7\E9\BAϳ\C9һ\B8\F6unsiged int\A3\A832bit\A3\A9\CA\FD\BE\DD\D7\F7Ϊ\B4˽ӿڵĲ\CE\CA\FDֵ\A1\A3\n
\B4\D3\D7\F3\B5\BD\D3ҵ\C44 \B8\F6LED \D2\C0\B4\CE\CF\D4ʾ\CA\FD\BEݵ\C4bit[7:0]\A1\A2bit[15:8]\A1\A2bit[23:16]\A1\A2bit[31:24]\A1\A3\n
\C0\FD\C8磺\D4\DALED \C9\CF\CF\D4ʾ\A1\B00123\A1\B1\A3\AC\D4\F2\D0\E8Ҫ\BD\AB\D5\E2Щ\D7ַ\FB\B6\D4Ӧ\B5\C4\CF\D4ʾֵ\D7\E9\BAϳ\C9һ\B8\F6Unsigned int \B5ı\E4\C1\BF\A3\BA\n
   Unsigned int parameter = 0x03 + (0x9F <<8) + (0x25<<16) + (0x0D <<24)\A3\BB\n
\C6\E4\D6У\BA0x03\A1\A20x9F\A1\A20x25\A1\A20x0D \B7ֱ\F0\CAǡ\AE0\A1\AF\A1\A2\A1\AE1\A1\AF\A1\A2\A1\AE2\A1\AF\A1\A2\A1\AE3\A1\AF\B5\C4\CF\D4ʾֵ\A1\A3\n
\C6߶\CE\CA\FD\C2\EB\B9ܶ\CE\CA\FD\D3\EB\CA\FD\BEݵ\C4bit\B6\D4Ӧ\B9\D8ϵ\C8\E7\CF\C2:\n
       --7--       \n
      |     |      \n
     2|     |6     \n
      |--1--       \n
      |     |      \n
     3|     |5     \n
       --4-- .0    \n
\BA\A3˼DEMO\B0\E5\CA\FD\C2\EB\B9ܳ\A3\D3\C3\CF\D4ʾ\D7ַ\FB\BC\B0\C6\E4\B6\D4Ӧ\B5\C4\CF\D4ʾֵ\C8\E7\CF\C2(\D5\EB\B6Թ\B2\D1\F4\BC\AB\A3\AC\B9\B2\D2\F5\BC\ABҪȡ\B7\B4)\A3\BA\n
  . \D7ַ\FB0-9\A3\BA0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09\n
  . \B4\F3д\D7\D6ĸA-Z\A3\A8\B2\BB\C4\DC\CF\D4ʾ\B5\C4\D3\C30xFF \B1\EDʾ\A3\A9\A3\BA\n
     0xFF, 0xFF, 0x63, 0xFF, 0x61, 0x71, 0xFF, 0x91, 0xFF, 0xFF, 0xFF, 0xE3, 0xFF,\n
     0xFF, 0x03, 0x31, 0xFF, 0xFF, 0x49, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF\n
  . Сд\D7\D6ĸa-z\A3\A8\B2\BB\C4\DC\CF\D4ʾ\B5\C4\D3\C30xFF \B1\EDʾ\A3\A9\A3\BA\n
     0xFF, 0xC1, 0xE5, 0x85, 0x21, 0xFF, 0x09, 0xD1, 0xDF, 0xFF, 0xFF, 0x9F, 0xFF,\n
     0xD5, 0xC5, 0x31, 0x19, 0xFF, 0x49, 0xE1, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF CNend
\param[in] u32CodeValue 4-digit value to be displayed                   CNcomment:\D0\E8Ҫ\CF\D4ʾ\B5\C44λ\CA\FDֵ\A1\A3CNend
\retval ::HI_SUCCESS Success                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                             CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_Display(HI_U32 u32CodeValue);


/**
\brief Displays the time on LEDs.
CNcomment:\brief \D4\DA\CA\FD\C2\EB\B9\DC\C9\CF\CF\D4ʾʱ\BC䡣CNend

\attention \n
The values of hour and minute need to be converted into corresponding decimal values. For example, if you want to display 22:45, you need to set hour to 22 and set minute to 45.\n
After the start time is set, the time is displayed on LEDs. At the same time, the colon (:) in the time blinks at the frequency of 1 Hz.\n
Because the time is displayed in 24-hour format, the maximum value of hour is 23, and the maximum value of minute is 59.\n
CNcomment:Сʱ\A1\A2\B7\D6\D6\D3ֻ\D0\E8\C5\E4\D6ó\C9\CF\E0Ӧ\B5\C4ʮ\BD\F8\D6\C6ֵ\BE\CD\D0\D0\C1ˡ\A3\B1\C8\C8\E7\CF\D4ʾ22\A3\BA45\A3\AC\D4\F2hour=22\A3\ACminute=45\A1\A3\n
\B4\AB\C8\EBʱ\BC\E4\CA\FD\BEݽṹ\A3\ACȻ\BA\F3\D4\DA\CA\FD\C2\EB\B9\DC\C9\CF\CF\D4ʾ\A3\AC\CF\D4ʾʱ\BC\E4\B5\C4ͬʱð\BAŻ\E1\D2\D41HZ\B5\C4Ƶ\C2\CA\C9\C1˸\n
ʱ\BC\E4\B5ķ\B6Χע\D2ⰴ24Сʱ\D6ƣ\AC\D7\EE\B4\F3֧\B3\D6СʱΪ23\A3\AC\B7\D6Ϊ59\A1\A3CNend

\param[in] stLedTime Time                                                CNcomment:ʱ\BC䡣CNend
\retval ::HI_SUCCESS  Success                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\retval ::HI_ERR_KEYLED_INVALID_PARA  The input parameter is invalid.    CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_DisplayTime(HI_UNF_KEYLED_TIME_S stLedTime);

/**
\brief Sets the ID of the blinked LED.
CNcomment:\brief \C9\E8\D6\C3Ҫ\C9\C1˸\B5\C4LED \D0\F2\BAš\A3CNend

\attention \n
The IDs of the LEDs on the board are 1, 2, 3, and 4 from left to right. If you want 4 LEDs to blink together, set 5.\n
CNcomment:\B5\A5\B0\E5\C9ϵ\C4\CA\FD\C2\EB\B9ܵ\C4\D0\F2\BAŴ\D3\D7\F3\B5\BD\D3\D2\D2\C0\B4\CEΪ\A3\BA1\A1\A22\A1\A23\A1\A24\A1\A3\C9\E8\D6\C34\B8\F6\CA\FD\C2\EB\B9\DCһ\C6\F0\C9\C1˸:5\A3\BBCNend

\param[in] enPin  Pin ID                                                 CNcomment:Ҫ\CF\D4ʾ\B5\C4\D0\F2\BAš\A3CNend
\retval ::HI_SUCCESS Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\retval ::HI_ERR_KEYLED_INVALID_PARA  The input parameter is invalid.    CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_SetFlashPin(HI_UNF_KEYLED_LIGHT_E enPin);

/**
\brief Sets the blink level of an LED.
CNcomment:\brief \C9\E8\D6\C3LED \C9\C1˸\BC\B6\B1\F0\A1\A3CNend

\attention \n
The higher the level, the faster an LED blinks.
CNcomment:\BC\B6\B1\F0Խ\B8\DF\C9\C1˸\CBٶ\C8Խ\BF졣CNend

\param[in] enLevel  Blink level from 1 to 5.                             CNcomment:\C9\C1˸\BC\B6\B1\F0\A3\AC\C9\E8\D6÷\B6Χ:1 \B5\BD 5 CNend
\retval ::HI_SUCCESS Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_NOT_INIT  The KEYLED module is not initialized.  CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF CNend
\retval ::HI_ERR_KEYLED_INVALID_PARA The input parameter is invalid.     CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_SetFlashFreq(HI_UNF_KEYLED_LEVEL_E enLevel);

/**
\brief  whether enable the lockfreq led.
CNcomment:\brief \C9\E8\D6\C3\CB\F8ƵLED\A1\A3CNend

\attention \n
At present,only FD650 KEYLED support this.
CNcomment:Ŀǰֻ\D3\D0FD650\C3\E6\B0\E5֧\B3ָ\C3\C9\E8\D6\C3CNend

\param[in] setLock  If lock ,set to HI_TRUE. Otherwise,set to HI_FALSE.                            CNcomment:LOCKLED\C9\E8\D6ã\AC\CB\F8\B6\A8ʱ\C9\E8\D6\C3ΪHI_TRUE\A3\AC\B7\F1\D4\F2\A3\AC\C9\E8\D6\C3ΪHI_FALSE.CNend
\retval ::HI_SUCCESS Success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling Ioctrl fails.                              CNcomment: Ioctrl\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_KEYLED_INVALID_PARA The input parameter is invalid.     CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_LED_SetLockPin(HI_BOOL setLock);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_KEYLED_H__ */


