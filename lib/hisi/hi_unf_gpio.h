/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
******************************************************************************
 File Name     : hi_unf_gpio.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
******************************************************************************/
#ifndef __HI_UNF_GPIO_H__
#define __HI_UNF_GPIO_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      GPIO */
/** @{*/  /** <!-- [GPIO] */

#define HI_UNF_GPIO_Open  HI_UNF_GPIO_Init
#define HI_UNF_GPIO_Close HI_UNF_GPIO_DeInit

/**type of GPIO interrupt*/
/** CNcomment:GPIO \D6ж\CF\C0\E0\D0\CD*/
typedef enum hiUNF_GPIO_INTTYPE_E
{
    HI_UNF_GPIO_INTTYPE_UP, /**<spring by the up edge*/                 /**< CNcomment:\C9\CF\C9\FD\D1ش\A5\B7\A2*/
    HI_UNF_GPIO_INTTYPE_DOWN, /**<spring by the down edge*/               /**< CNcomment:\CF½\B5\D1ش\A5\B7\A2*/
    HI_UNF_GPIO_INTTYPE_UPDOWN, /**<spring by both the up and down edge*/   /**< CNcomment:˫\D1ش\A5\B7\A2*/
    HI_UNF_GPIO_INTTYPE_HIGH, /**<spring by the high level*/              /**< CNcomment:\B8ߵ\E7ƽ\B4\A5\B7\A2*/
    HI_UNF_GPIO_INTTYPE_LOW, /**<spring by the low level*/               /**< CNcomment:\B5͵\E7ƽ\B4\A5\B7\A2*/
    HI_UNF_GPIO_INTTYPE_BUTT, /**<Invalid value*/                        /**< CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_GPIO_INTTYPE_E;

/**GPIO output type*/
/** CNcomment:GPIO \CA\E4\B3\F6\C0\E0\D0\CD*/
typedef enum hiUNF_GPIO_OUTPUTTYPE_E
{
	HI_UNF_GPIO_OUTPUTTYPE_CMOS,
	HI_UNF_GPIO_OUTPUTTYPE_OD,
	HI_UNF_GPIO_OUTPUTTYPE_BUTT,		
}HI_UNF_GPIO_OUTPUTTYPE_E;

/** @}*/  /** <!-- ==== Structure Definition End ====*/




/******************************* API Declaration *****************************/
/** \addtogroup      GPIO*/
/** @{*/  /** <!-- [GPIO] */

/**
 \brief Starts the general-purpose input/output (GPIO) device.
CNcomment:\brief \B4\F2\BF\AAGPIO\A3\A8General Purpose Input/Output\A3\A9\C9豸\A1\A3CNend

 \attention \n
This API can be called repeatedly.
CNcomment:\D6ظ\B4\B4򿪻\E1\B3ɹ\A6\A1\A3CNend

 \param  N/A       CNcomment:\CEޡ\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE			Initialize GPIO failed.                 	CNcomment:\B4\F2\BF\AAGPIOʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_GPIO_OPEN_ERR  Initialize GPIO failed.                 	CNcomment:\B4\F2\BF\AAGPIOʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_Init(HI_VOID);

/**
 \brief Stops the GPIO device.
CNcomment:\brief \B9ر\D5GPIO\C9豸\A1\A3CNend

 \attention \n
This API can be called repeatedly.
CNcomment:\D6ظ\B4\B9رջ\E1\B3ɹ\A6\A1\A3CNend
 \param  N/A  CNcomment:\CEޡ\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_CLOSE_ERR  Deinitialize GPIO failed.                 	CNcomment:\B4\F2\BF\AAGPIOʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_DeInit(HI_VOID);

/**
 \brief Reads data from a GPIO pin.
CNcomment:\brief \B4\D3GPIO\B5\A5\B8\F6\D2\FD\BDŶ\C1ȡ\CA\FD\BEݡ\A3CNend

 \attention The pin number is defined as follows: Pin number = GPIO group ID x 8 + GPIO pin ID in the group\n
For example, GPIO1_2 indicates pin 2 in group 1, and the pin number is 10 (1 x 8 + 2).\n
Both pin group ID and pin number are numbered from 0. Each HD chip provides GPIO pins number reference to HD chip hardware manual.\n
CNcomment:\attention \B9ܽźż\C6\CB\E3\B9\E6\D4\F2: \B9ܽź\C5 = GPIO\D7\E9\BA\C5*8 + GPIO\B9ܽ\C5\D4\DA\D7\E9\C4ڵı\E9\BAš\A3\n
\B1\C8\C8\E7GPIO1_2,\B4\FA\B1\ED\B5\DA1\D7\E9\B5\DA2\BDţ\AC\C4\C7ô\B9ܽź\C5=1*8+2=10\A1\A3\n
GPIO\B5\C4\D7\E9\BAź͹ܽźŵı\E0\BAŶ\BC\B4\D30\BF\AAʼ\A1\A3\B8\DF\C7\E5оƬ\CCṩ\B5\C4gpio\B9ܽ\C5\CA\FD\C7\EB\B2ο\BC\CF\E0\B9ص\C4оƬӲ\BC\FE\CAֲ\E1\n CNend

 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[out] pbHighVolt   Pointer to the input level of a pin.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B7\B5\BBعܽ\C5\CA\E4\C8\EB\BB\F2\D5\DF\CA\E4\B3\F6\B5\E7ƽ\A1\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NULL_PTR  Pointer Parameters is NULL.                 	CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_OPT  Invalid Operation.              			CNcomment:\B7Ƿ\A8\B2\D9\D7\F7\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_ReadBit(HI_U32 u32GpioNo, HI_BOOL  *pbHighVolt);

/**
 \brief Writes data to a GPIO pin.
CNcomment:\brief \CF\F2GPIO\B5\A5\B8\F6\D2\FD\BD\C5\CA\E4\B3\F6\CA\FD\BEݡ\A3CNend
 \attention \n
N/A
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] bHighVolt  Output level of a pin              CNcomment:\B9ܽ\C5\CA\E4\B3\F6\B5\E7ƽ\A1\A3CNend
                      0: low level                       CNcomment:0: \B5͵\E7ƽ CNend
                      1: high level                      CNcomment:1\A3\BA\B8ߵ\E7ƽ CNend
                     Others: high level                  CNcomment:\C6\E4\CB\FB\A3\BA\B8ߵ\E7ƽ\A1\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_OPT  Invalid Operation.              			CNcomment:\B7Ƿ\A8\B2\D9\D7\F7\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_WriteBit(HI_U32 u32GpioNo, HI_BOOL bHighVolt );

/**
 \brief Sets the direction (input or output) of a GPIO pin.
CNcomment:\brief \C9\E8\D6\C3GPIO\B5\A5\B8\F6\D2\FD\BD\C5\CA\E4\C8\EB\CA\E4\B3\F6\B7\BD\CF\F2\A1\A3CNend

 \attention \n
When setting the operating mode of a GPIO pin, ensure that it works in GPIO mode only.\n
This is because the GPIO pin may be multiplexed.\n
CNcomment:\C9\E8\D6ö\D4Ӧ\B9ܽŵĹ\A4\D7\F7\B7\BDʽʱ\A3\AC\B1\D8\D0뱣֤\B8ùܽŽ\F6\B9\A4\D7\F7\D4\DAGPIOģʽ\CF£\ACGPIO\B9ܽ\C5\D3п\C9\C4ܱ\BB\B8\B4\D3á\A3CNend

 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] bInput  Boolean variable that indicates the direction of a pin  CNcomment:\B2\BC\B6\FB\B1\E4\C1\BF\A3\AC\B1\EAʶ\B9ܽŷ\BD\CF\F2\A1\A3CNend
                   HI_TRUE: input pin  HI_TRUE.                           CNcomment:\B8ùܽ\C5\D3\C3\D3\DA\CA\E4\C8롣CNend
                   HI_FALSE: output pin HI_FALSE.                         CNcomment:\B8ùܽ\C5\D3\C3\D3\DA\CA\E4\B3\F6\A1\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_SetDirBit(HI_U32 u32GpioNo, HI_BOOL bInput);

/**
 \brief Obtains the direction (input or output) of a GPIO pin.
CNcomment:\brief \BB\F1ȡGPIO\B5\A5\B8\F6\D2\FD\BD\C5\CA\E4\C8\EB\CA\E4\B3\F6\B7\BD\CF\F2\A1\A3CNend

 \attention \n
N/A
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type.     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[out] pbInput   Pointer to the boolean variable that indicates the direction of a pin.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF򲼶\FB\D0ͱ\E4\C1\BF\A3\AC\D3\C3\C0\B4\B7\B5\BBعܽŷ\BD\CF\F2\A1\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NULL_PTR  Pointer Parameters is NULL.                 	CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_GetDirBit(HI_U32 u32GpioNo, HI_BOOL    *pbInput);

/**
 \brief Starts the cipher device.
CNcomment:\brief \C9\E8\D6\C3GPIO\B5\A5\B8\F6\D2\FD\BDŵ\C4\D6ж\CF\C0\E0\D0͡\A3CNend

 \attention \n
N/A
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] enIntType    interrupt type                                CNcomment:\D6ж\CF\C0\E0\D0͡\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_INTTYPE_NOT_SUPPORT  interupt type is not support.       CNcomment:\B2\BB֧\B3ֵ\C4\D6ж\CF\C0\E0\D0͡\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_FAILED_SETINT  set interupt type failed.              	CNcomment:\C9\E8\D6\C3\D6ж\CF\C0\E0\D0\CDʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_SetIntType(HI_U32 u32GpioNo, HI_UNF_GPIO_INTTYPE_E enIntType);

/**
 \brief set GPIO single pin interrupt enable
CNcomment:\brief \C9\E8\D6\C3GPIO\B5\A5\B8\F6\D2\FD\BDŵ\C4\D6ж\CFʹ\C4ܡ\A3CNend
 \attention \n
interrupte type HI_UNF_GPIO_INTTYPE_LOW and HI_UNF_GPIO_INTTYPE_HIGH is not support
CNcomment:\B2\BB֧\B3\D6HI_UNF_GPIO_INTTYPE_LOW \BA\CD HI_UNF_GPIO_INTTYPE_HIGH\D6ж\CF\C0\E0\D0͡\A3CNend
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] bEnable  HI_TRUE: interrupt enable, HI_FALSE: interrupt disable CNcomment:HI_TRUE: \D6ж\CFʹ\C4\DC ,HI_FALSE: \D6жϽ\FBֹ\A1\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_FAILED_SETENABLE  enable interupt failed.              	CNcomment:ʹ\C4\DC\D6ж\CFʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_SetIntEnable(HI_U32 u32GpioNo, HI_BOOL bEnable);

/**
 \brief query GPIO interrupt, report it if there is interrupter happen.\n
CNcomment:\brief \B2\E9ѯGPIO\D6жϣ\ACֻҪ\D3\D0GPIO\D6жϾͻ\E1\C9ϱ\A8\C9\CF\C0\B4\A1\A3CNend
 \attention \n
N/A
 \param[out] p32GpioNo    get interrupt pin number.        CNcomment:\BB\F1ȡ\D6жϵĹܽźš\A3CNend
 \param[in] u32TimeoutMs  get interrupt timeout.           CNcomment:\BB\F1ȡ\D6жϳ\ACʱʱ\BC䡣CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_NULL_PTR  Pointer Parameters is NULL.                 	CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_FAILED_GETINT  Query interupt failed.              	CNcomment:\B2\E9ѯ\D6ж\CFʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_QueryInt(HI_U32 *p32GpioNo, HI_U32 u32TimeoutMs);

/**
 \brief Obtains the output type (od or cmos) of a GPIO pin.
CNcomment:\brief \C9\E8\D6\C3GPIO\B5\A5\B8\F6\D2\FD\BDŵ\C4\CA\E4\B3\F6\C0\E0\D0͡\A3CNend

 \attention \n
N/A
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type.     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] enOutputType   Pointer to the enumerate variable that indicates the direction of a pin.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ö\BE\D9\D0ͱ\E4\C1\BF\A3\AC\D3\C3\C0\B4\B7\B5\BBعܽ\C5\CA\E4\B3\F6\C0\E0\D0͡\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_FAILED_SETOUTPUTTYPE Get output type failed.				CNcomment:\C9\E8\D6\C3\CA\E4\B3\F6\C0\E0\D0\CDʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_SetOutputType(HI_U32 u32GpioNo, HI_UNF_GPIO_OUTPUTTYPE_E  enOutputType);

/**
 \brief Obtains the output type (od or cmos) of a GPIO pin.
CNcomment:\brief \BB\F1ȡGPIO\B5\A5\B8\F6\D2\FD\BDŵ\C4\CA\E4\B3\F6\C0\E0\D0͡\A3CNend

 \attention \n
N/A
 \param[in] u32GpioNo  Pin number, ranging from 0 to 103, ranging is different in otherness chip type.     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[out] penOutputType   Pointer to the enumerate variable that indicates the output type of a pin.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ö\BE\D9\D0ͱ\E4\C1\BF\A3\AC\D3\C3\C0\B4\B7\B5\BBعܽ\C5\CA\E4\B3\F6\C0\E0\D0͡\A3CNend
 \retval 0 Success. CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA	 Parameters Invalid.                 		CNcomment:\B7Ƿ\A8\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_GPIO_NOT_INIT  GPIO module is not initialiazed.              	CNcomment:GPIOģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_GPIO_FAILED_GETOUTPUTTYPE Get output type failed.				CNcomment:\BB\F1ȡ\CA\E4\B3\F6\C0\E0\D0\CDʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_GPIO_GetOutputType(HI_U32 u32GpioNo, HI_UNF_GPIO_OUTPUTTYPE_E  *penOutputType);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_UNF_GPIO_H__ */
