/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
******************************************************************************
 File Name     : hi_unf_i2c.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
******************************************************************************/
#ifndef __HI_UNF_I2C_H__
#define __HI_UNF_I2C_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      I2C */
/** @{*/  /** <!-[I2C]*/

#define HI_UNF_I2C_Open  HI_UNF_I2C_Init
#define HI_UNF_I2C_Close HI_UNF_I2C_DeInit

/**Maximum I2C channel ID*/ /**CNcomment:\D7\EE\B4\F3I2Cͨ\B5\C0\BA\C5*/
#define HI_I2C_MAX_NUM_USER (15)

/**Rate type of the I2C module*/
/**CNcomment:I2C\B5\C4\CB\D9\C2\CA\C0\E0\D0\CD */
typedef enum hiUNF_I2C_RATE_E
{
    HI_UNF_I2C_RATE_10K = 0, /**<Standard rate: 10 kbit/s*/         /**<CNcomment:\B1\EA׼\CB\D9\C2ʣ\BA10kbit/s*/
    HI_UNF_I2C_RATE_50K, /**<Standard rate: 50 kbit/s*/   /**<CNcomment:\B1\EA׼\CB\D9\C2ʣ\BA50kbit/s*/
    HI_UNF_I2C_RATE_100K, /**<Standard rate: 100 kbit/s*/  /**<CNcomment:\B1\EA׼\CB\D9\C2ʣ\BA100kbit/s*/
    HI_UNF_I2C_RATE_200K, /**<Standard rate: 200 kbit/s*/  /**<CNcomment:\B1\EA׼\CB\D9\C2ʣ\BA200kbit/s*/
    HI_UNF_I2C_RATE_300K, /**<Standard rate: 300 kbit/s*/  /**<CNcomment:\B1\EA׼\CB\D9\C2ʣ\BA300kbit/s*/
    HI_UNF_I2C_RATE_400K, /**<Fast rate: 400 kbit/s*/      /**<CNcomment:\BF\EC\CB\D9\CB\D9\C2ʣ\BA400kbit/s*/

    HI_UNF_I2C_RATE_BUTT
} HI_UNF_I2C_RATE_E;

/** @}*/  /** <!-- ==== Structure Definition End ====*/




/******************************* API Declaration *****************************/
/** \addtogroup      I2C*/
/** @{*/  /** <!-- -I2C=*/

/**
 \brief Init the I2C device.
CNcomment:\brief \B3\F5ʼ\BB\AFI2C\A3\A8the Inter-Integrated Circuit\A3\A9\C9豸\A1\A3CNend

 \param N/A                                                               CNcomment:\CEޡ\A3CNend
 \retval 0 Success                                                        CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_I2C_OPEN_ERR  Open I2c Error				  CNcomment:I2C\CE\DEЧ\B2\CE\CA\FD\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_Init (HI_VOID);

/**
 \brief  DeInit the I2C device.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFI2C\C9豸\A1\A3CNend

 \attention \n
This API is called after I2C operations are completed.\n
CNcomment:\D4\DAI2C\B2\D9\D7\F7\BD\E1\CA\F8\BA\F3\B5\F7\D3ô˽ӿ\DA\n CNend

 \param N/A                                                        CNcomment:\CEޡ\A3CNend
 \retval 0 Success                                                 CNcomment: \B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_I2C_CLOSE_ERR  Close I2c Error.	 	   CNcomment:I2C\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_DeInit(HI_VOID);

/**
 \brief  Get the number of I2C module.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFI2C\C9豸\A1\A3CNend

 \attention \n
Call this API to get the number of I2C module befor read/write data.\n
CNcomment:\D4\DAʹ\D3\C3I2C\B6\C1д\CA\FD\BE\DD֮ǰ\B5\F7\D3ô˽ӿڻ\F1ȡоƬ\B5\C4I2Cģ\BF\E9\CA\FDĿ\n CNend

 \param N/A                                                        CNcomment:\CEޡ\A3CNend
 \retval 0 Success                                                 CNcomment: \B3ɹ\A6\A1\A3CNend
 \retval ::	 
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_GetCapability(HI_U32 *pu32I2cNum);

/**
The I2C device is not initialized.
CNcomment:\brief \B4\B4\BD\A8һ·GpioI2c\A1\A3CNend

 \attention \n
If the specified GPIO pins are used, this API fails to be called.\n
CNcomment:\C8\E7\B9\FBGpio\D2ѱ\BBռ\D3û\E1ʧ\B0\DC\n CNend

 \param[out] u32I2cNum  ID of the obtained I2C bus                            CNcomment:\B5õ\BDI2C\D7\DC\CFߺš\A3CNend
 \param[in] u32SCLGpioNo  SCL Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \param[in] u32SDAGpioNo  SDA Pin number, ranging from 0 to 103, ranging is different in otherness chip type     CNcomment:\B9ܽźţ\ACȡֵ\B7\B6ΧΪ0\A1\AB103\A3\AC\B2\BBͬ\B5\C4оƬ\C0\E0\D0ͷ\B6Χ\B2\BBһ\D1\F9\A1\A3CNend
 \retval 0 Success                                                           CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Create gpioi2c failed								CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_I2C_NULL_PTR 		The pointer parameter is NULL			CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA  The parameter is invalid.               CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_CreateGpioI2c(HI_U32 *pu32I2cNum, HI_U32 u32SCLGpioNo, HI_U32 u32SDAGpioNo);

/**
 \brief Destroys a inter-integrated circuit (I2C) channel that simulates the general-purpose input/output (GPIO) function.
CNcomment:\brief \CF\FA\BB\D9һ·GpioI2c\A1\A3CNend

 \attention \n
If the I2C channel is not used, a code indicating success is returned.\n
CNcomment:\C8\E7\B9\FB\B8\C3GpioI2cδʹ\D3ã\ACֱ\BDӷ\B5\BBسɹ\A6\n CNend

 \param[in] u32I2cNum ID of the I2C bus to be destroyed        CNcomment:Ҫ\CF\FA\BBٵ\C4I2C\D7\DC\CFߺš\A3CNend
 \retval 0  Success                                            CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Destroy gpioi2c failed				  CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_GPIO_INVALID_PARA  The parameter is invalid. CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_DestroyGpioI2c(HI_U32 u32I2cNum);

/**
 \brief Reads data by using the I2C bus.
CNcomment:\brief ͨ\B9\FDI2C\B6\C1\CA\FD\BEݡ\A3CNend

 \attention \n
N/A
 \param[in] u32I2cNum  I2C bus of the device to be read           CNcomment:\CB\F9\B6\C1ȡ\C9豸ʹ\D3õ\C4I2C\D7\DC\CFߡ\A3CNend
 \param[in] u8DevAddress  Address of a device on the I2C bus      CNcomment:\C9豸\D4\DAI2C\D7\DC\CF\DF\C9ϵĵ\D8ַ\A1\A3CNend
 \param[in] u32RegAddr  On-chip offset address of a device        CNcomment:\C9豸\B5\C4Ƭ\C4\DAƫ\D2Ƶ\D8ַ\A1\A3CNend
 \param[in] u32RegAddrCount  Length of an on-chip offset address. CNcomment:Ƭ\C4\DAƫ\D2Ƶ\D8ַ\B5ĳ\A4\B6ȵ\A5λ\A1\A3CNend
                      1: 8-bit sub address                       CNcomment:1\A3\BA\B1\EDʾ8bit\D7ӵ\D8ַ\A3\BBCNend
                      2: 16-bit sub address                      CNcomment:2\A3\BA\B1\EDʾ16bit\D7ӵ\D8ַ\A3\BBCNend
                      3: 24-bit sub address                      CNcomment:3\A3\BA\B1\EDʾ24bit\D7ӵ\D8ַ\A3\BBCNend
                      4: 32-bit sub address                      CNcomment:4\A3\BA\B1\EDʾ32bit\D7ӵ\D8ַ\A1\A3CNend

 \param[out] pu8Buf   Buffer for storing the data to be read                            CNcomment:\B6\C1Buffer\A3\AC\B4\E6\B7Ŷ\C1ȡ\CA\FD\BEݡ\A3CNend
 \param[in] u32Length  Length of the data to be read                                    CNcomment:Ҫ\B6\C1ȡ\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3CNend
 \retval 0 Success                                                                      CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Read data failed					  	CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                      CNcomment:I2C\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_I2C_NULL_PTR  The I2C pointer is invalid.                        	   CNcomment:I2C\CE\DEЧָ\D5롣CNend
 \retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                       CNcomment:I2C\CE\DEЧ\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_I2C_FAILED_READ  Data fails to be read by using the I2C bus.          CNcomment:I2C\B6\C1\CA\FD\BE\DDʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_Read(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                       HI_U32 u32RegAddrCount, HI_U8 *pu8Buf, HI_U32 u32Length);

/**
 \brief Writes data by using the I2C bus. That is, you can call this API to write data to the device mounted on the I2C bus through the I2C channel.
CNcomment:\brief ͨ\B9\FDI2Cд\CA\FD\BEݡ\A3ͨ\B9\FDI2Cͨ\B5\C0\A3\AC\CF\F2I2C\D7\DC\CF\DF\C9Ϲҽӵ\C4\C9豸\BD\F8\D0\D0д\B2\D9\D7\F7\A1\A3CNend

 \attention \n
N/A
 \param[in] u32I2cNum  I2C bus of the device to be written         CNcomment:\B4\FDд\C9豸ʹ\D3õ\C4I2C\D7\DC\CFߡ\A3CNend
 \param[in] u8DevAddress  Address of a device on the I2C bus       CNcomment:\C9豸\D4\DAI2C\D7\DC\CF\DF\C9ϵĵ\D8ַ\A1\A3CNend
 \param[in] u32RegAddr  On-chip offset address of a device         CNcomment:\C9豸\B5\C4Ƭ\C4\DAƫ\D2Ƶ\D8ַ\A1\A3CNend
 \param[in] u32RegAddrCount Length of an on-chip offset address.   CNcomment:Ƭ\C4\DAƫ\D2Ƶ\D8ַ\B5ĳ\A4\B6ȵ\A5λ\A1\A3CNend
                    1: 8-bit sub address                          CNcomment:1\A3\BA\B1\EDʾ8bit\D7ӵ\D8ַ\A3\BBCNend
                    2: 16-bit sub address                         CNcomment:2\A3\BA\B1\EDʾ16bit\D7ӵ\D8ַ\A3\BBCNend
                    3: 24-bit sub address                         CNcomment:3\A3\BA\B1\EDʾ24bit\D7ӵ\D8ַ\A3\BBCNend
                    4: 32-bit sub address                         CNcomment:4\A3\BA\B1\EDʾ32bit\D7ӵ\D8ַ\A1\A3CNend

 \param[in]  pu8Buf   Buffer for storing the data to be written                         CNcomment:дBuffer\A3\AC\B4\E6\B7Ŵ\FDд\C8\EB\CA\FD\BEݡ\A3CNend
 \param[in] u32Length  Length of the data to be written                                 CNcomment:Ҫд\C8\EB\B5\C4\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
 \retval 0  Success                                                                     CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Write data failed					  	CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                      CNcomment:I2C\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_I2C_NULL_PTR  The I2C pointer is invalid.                        	   CNcomment:I2C\CE\DEЧָ\D5롣CNend
 \retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                       CNcomment:I2C\CE\DEЧ\B2\CE\CA\FD\A1\A3CNend
 \retval ::HI_ERR_I2C_FAILED_WRITE  Data fails to be written by using the I2C bus.      CNcomment:I2Cд\CA\FD\BE\DDʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_Write(HI_U32 u32I2cNum, HI_U8 u8DevAddress, HI_U32 u32RegAddr,
                        HI_U32 u32RegAddrCount, HI_U8 * pu8Buf, HI_U32 u32Length);

/**
 \brief Sets the transfer rate of the I2C bus.
CNcomment:\brief \C9\E8\D6\C3I2C\B5Ĵ\AB\CA\E4\CB\D9\C2ʡ\A3CNend

 \attention \n
Call this API Only be effect in standard i2c, gpio simulate i2c is noneffective.\n 
If you do not call this API to set the transfer rate, the rate 100 kbit/s is used by default.\n
CNcomment:\B4˽ӿڽ\F6\B6Ա\EA׼\B5\C4i2cͨ\B5\C0\D3\D0Ч\A3\AC\B6\D4gpio ģ\C4\E2 i2c \CE\DEЧ\A1\A3\nCNend
CNcomment:\C8\E7\B9\FB\B2\BB\B5\F7\D3ô˽ӿڣ\ACϵͳ\B2\C9\D3\C3400Kbit/s\D7\F7Ϊȱʡ\CB\D9\C2ʡ\A3\n CNend

 \param[in] u32I2cNum  D of channel corresponding to the device to be written on the I2C bus                         CNcomment:\CB\F9д\C9豸\D4\DAI2C\D7\DC\CF\DF\C9ϵ\C4ͨ\B5\C0\BAš\A3CNend
 \param[in] enI2cRate  I2C clock rate. For details about the definition, see the description of ::HI_UNF_I2C_RATE_E. CNcomment:I2Cʱ\D6\D3\CB\D9\C2ʡ\A3\BA\AC\D2\E5\C7\EB\B2ο\BC::HI_UNF_I2C_RATE_E\A1\A3CNend
 \retval 0  Success                                                                                                  CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Set rate failed									   	     CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                                                   CNcomment:I2C\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                                                    CNcomment:I2C\CE\DEЧ\B2\CE\CA\FD\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_SetRate(HI_U32 u32I2cNum, HI_UNF_I2C_RATE_E enI2cRate);

/**
 \brief Sets the transfer rate of the I2C bus.
CNcomment:\brief \C9\E8\D6\C3I2C\B5Ĵ\AB\CA\E4\CB\D9\C2ʡ\A3CNend

 \attention \n
Call this API Only be effect in standard i2c, gpio simulate i2c is noneffective.\n 
If you do not call this API to set the transfer rate, the rate 100 kbit/s is used by default.\n
CNcomment:\B4˽ӿڽ\F6\B6Ա\EA׼\B5\C4i2cͨ\B5\C0\D3\D0Ч\A3\AC\B6\D4gpio ģ\C4\E2 i2c \CE\DEЧ\A1\A3\n
\C8\E7\B9\FB\B2\BB\B5\F7\D3ô˽ӿڣ\ACϵͳ\B2\C9\D3\C3400Kbit/s\D7\F7Ϊȱʡ\CB\D9\C2ʡ\A3\n CNend

 \param[in] u32I2cNum  D of channel corresponding to the device to be written on the I2C bus                         CNcomment:\CB\F9д\C9豸\D4\DAI2C\D7\DC\CF\DF\C9ϵ\C4ͨ\B5\C0\BAš\A3CNend
 \param[in] u32I2cRate  I2C clock rate.  CNcomment:I2Cʱ\D6\D3\CB\D9\C2ʡ\A3CNend
 \retval 0  Success                                                                                                  CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Set rate failed									   	     CNcomment:ʧ\B0ܡ\A3CNend
 \retval ::HI_ERR_I2C_NOT_INIT  The I2C device is not initialized.                                                   CNcomment:I2C\C9豸δ\B3\F5ʼ\BB\AF\A1\A3CNend
 \retval ::HI_ERR_I2C_INVALID_PARA  The I2C parameter is invalid.                                                    CNcomment:I2C\CE\DEЧ\B2\CE\CA\FD\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_I2C_SetRateEx(HI_U32 u32I2cNum, HI_U32 u32I2cRate);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ECS_TYPE_H__ */
