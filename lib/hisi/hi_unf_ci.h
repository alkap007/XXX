#ifndef __HI_UNF_CI_TYPE_H__
#define __HI_UNF_CI_TYPE_H__

#include "hi_error_mpi.h"
#include "hi_common.h"
#include <linux/string.h>


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      CI*/
/** @{ */  /** <!-- [CI] */

/** support CI Port*/
/** CNcomment:֧\B3ֵ\C4CI Port */
typedef enum hiUNF_CI_PORT_E
{
    HI_UNF_CI_PORT_0,
    HI_UNF_CI_PORT_1,
    HI_UNF_CI_PORT_BUTT
} HI_UNF_CI_PORT_E;

/** support CI PCMCIA Cards(Module) */
/** CNcomment:֧\B3ֵ\C4CI PCMCIA Cards(Module) */
typedef enum hiUNF_CI_PCCD_E
{
    HI_UNF_CI_PCCD_A,
    HI_UNF_CI_PCCD_B,
    HI_UNF_CI_PCCD_BUTT
} HI_UNF_CI_PCCD_E;

/** Module on-off power control */
/** CNcomment:Module\BF\AA\B9ص\E7Դ\BF\D8\D6\C6 */
typedef enum hiUNF_CI_PCCD_CTRLPOWER_E
{
    HI_UNF_CI_PCCD_CTRLPOWER_ON,
    HI_UNF_CI_PCCD_CTRLPOWER_OFF,
    HI_UNF_CI_PCCD_CTRLPOWER_BUFF
} HI_UNF_CI_PCCD_CTRLPOWER_E;

/** Module ready state:ready/busy */
/** CNcomment:Module\BE\CD\D0\F7״̬:ready/busy */
typedef enum hiUNF_CI_PCCD_READY_E
{
    HI_UNF_CI_PCCD_BUSY,
    HI_UNF_CI_PCCD_READY
} HI_UNF_CI_PCCD_READY_E, *HI_UNF_CI_PCCD_READY_E_PTR;

/** Module online state:present/absent */
/** CNcomment:Module\D4\DA\CF\DF״̬:present/absent */
typedef enum hiUNF_CI_PCCD_STATUS_E
{
    HI_UNF_CI_PCCD_STATUS_ABSENT,
    HI_UNF_CI_PCCD_STATUS_PRESENT,
    HI_UNF_CI_PCCD_STATUS_BUTT
} HI_UNF_CI_PCCD_STATUS_E, *HI_UNF_CI_PCCD_STATUS_E_PTR;

/** card call mode */
/** CNcomment:\BF\A8\B7\C3\CE\CAģʽ */
typedef enum hiUNF_CI_PCCD_ACCESSMODE_E
{
    HI_UNF_CI_PCCD_ACCESS_ATTR,
    HI_UNF_CI_PCCD_ACCESS_IO,
    HI_UNF_CI_PCCD_ACCESS_COMMON,
    HI_UNF_CI_PCCD_ACCESS_BUTT
} HI_UNF_CI_PCCD_ACCESSMODE_E;

/** get state register mask code */
/** CNcomment:\BB\F1ȡ״̬\BCĴ\E6\C6\F7\D1\DA\C2\EB */
typedef enum hiUNF_CI_PCCD_STATUS_BIT_E
{
    HI_UNF_CI_PCCD_STATUS_BIT_ALL,  /**< get all bits */               /**< CNcomment:\BB\F1ȡ\CB\F9\D3\D0λ */
    HI_UNF_CI_PCCD_STATUS_BIT_DA,   /**< get Data Available bit */     /**< CNcomment:\BB\F1ȡData Availableλ */
    HI_UNF_CI_PCCD_STATUS_BIT_FR,   /**< get Free bit */               /**< CNcomment:\BB\F1ȡFreeλ */
    HI_UNF_CI_PCCD_STATUS_BIT_RE,   /**< get Read Error bit */         /**< CNcomment:\BB\F1ȡRead Errorλ */
    HI_UNF_CI_PCCD_STATUS_BIT_WE,   /**< get Write Error bit */        /**< CNcomment:\BB\F1ȡWrite Errorλ */
    HI_UNF_CI_PCCD_STATUS_BIT_BUTT
} HI_UNF_CI_PCCD_STATUS_BIT_E;

/** The mode of CI Transport Stream Interface connection */
/** CNcomment:CI TSI\C1\AC\BDӷ\BDʽ */
typedef enum hiUNF_CI_TSI_MODE_E
{
    HI_UNF_CI_TSI_DAISY_CHAINED,      /**< Daisy-chained */
    HI_UNF_CI_TSI_INDEPENDENT,        /**< Independent, non-daisy-chained */
    HI_UNF_CI_TSI_BUTT
}HI_UNF_CI_TSI_MODE_E;

/** The mode of TS pass to the CI device*/
/** CNcomment:\B9\FDCI\C9豸\B5\C4TS\C1\F7ģʽ */
typedef enum hiUNF_CI_TS_MODE_E
{
    HI_UNF_CI_TS_SERIAL,         /**< serial 1*/
    HI_UNF_CI_TS_PARALLEL,       /**< Parallel TS, default */
    HI_UNF_CI_TS_USB2SERIAL,     /**< USB input, serial output */
    HI_UNF_CI_TS_USB2PARALLEL,   /**< USB input, parallel output */
    HI_UNF_CI_TS_BUTT
}HI_UNF_CI_TS_MODE_E;

/** The TSI serial number of the CI device*/
/** CNcomment:CI\C9豸\B5Ĵ\AE\D0\D0TS\CA\E4\C8\EB\B6˿\DA */
typedef enum hiUNF_CI_TSI_SERIAL_PORT_E
{
    HI_UNF_CI_TSI_SERIAL1 = 0x04,  /**< TSI serial 1*/
    HI_UNF_CI_TSI_SERIAL2,         /**< TSI serial 2*/
    HI_UNF_CI_TSI_SERIAL3,         /**< TSI serial 3*/
    HI_UNF_CI_TSI_SERIAL4,         /**< TSI serial 4*/
    HI_UNF_CI_TSI_SERIAL_BUTT
}HI_UNF_CI_TSI_SERIAL_PORT_E;

/** The command exchange channel between the host and device*/
/** CNcomment:CI\C9豸*/
typedef enum hiUNF_CI_CMD_EXCHANGE_CHAN_E
{
    HI_UNF_CI_CMD_EXCHANGE_CHAN_USB,
    HI_UNF_CI_CMD_EXCHANGE_CHAN_SPI,
    HI_UNF_CI_EXCHANGE_CHAN_BUTT,
}HI_UNF_CI_CMD_EXCHANGE_CHAN_E;

/** CI device*/
/** CNcomment:֧\B3ֵ\C4CI\C9豸 */
typedef enum hiUNF_CI_DEV_E
{
    HI_UNF_CI_DEV_CIMAX,        /**< CIMaX, default */
    HI_UNF_CI_DEV_CIMAXPLUS,    /**< CIMaX+ */
    HI_UNF_CI_DEV_HICI,         /**< HICI */
    HI_UNF_CI_DEV_STARCI2WIN,   /**< StarCI2Win */
    HI_UNF_CI_DEV_BUTT
}HI_UNF_CI_DEV_E;

/** CIMaX device configuration */
/** CNcomment:CIMaX\C9豸\C5\E4\D6\C3 */
typedef struct hiUNF_CI_CIMAX_ATTR_S
{
    HI_U32  u32SMIBitWidth;         /**< SMI Bit Width */
    HI_U32  u32SMIBaseAddr;         /**< SMI Base Address */
    HI_U32  u32I2cNum;              /**< I2C Group */
    HI_U8   u8DevAddress;           /**< I2C device address */
}HI_UNF_CI_CIMAX_ATTR_S, *HI_UNF_CI_CIMAX_ATTR_S_PTR;

/** CIMaX+ device configuration */
/** CNcomment:CIMaX+\C9豸\C5\E4\D6\C3 */
typedef struct hiUNF_CI_CIMAXPLUS_ATTR_S
{
    HI_U32  u32ResetGpioNo; /**< The GPIO to reset the device */
    HI_U32  u32IntGpioNo;   /**< The GPIO to receive the device's Interrupt signal */
    HI_UNF_CI_TSI_SERIAL_PORT_E enTsiSerialPort[HI_UNF_CI_PCCD_BUTT]; /**< The TSI serial port of device*/
    HI_UNF_CI_CMD_EXCHANGE_CHAN_E  enCmdExchangeChan;     /**< The command exchange channel between the host and device*/
    HI_U32  u32SPIDevNo;           /**< The SPI device number*/
}HI_UNF_CI_CIMAXPLUS_ATTR_S, *HI_UNF_CI_CIMAXPLUS_ATTR_S_PTR;

/** HICI device configuration */
/** CNcomment:HICI\C9豸\C5\E4\D6\C3 */
typedef struct hiUNF_CI_HICI_ATTR_S
{
    HI_BOOL bIsPowerCtrlGpioUsed;
    HI_U32 u32PowerCtrlGpioNo[HI_UNF_CI_PCCD_BUTT];/**< The GPIO to power on/off the device */
}HI_UNF_CI_HICI_ATTR_S, *HI_UNF_CI_HICI_ATTR_S_PTR;

/** CI device configuration */
/** CNcomment:CI\C9豸\C5\E4\D6\C3 */
typedef struct hiUNF_CI_ATTR_S
{
    HI_UNF_CI_DEV_E enDevType;                          /**< CI device type */
    HI_UNF_CI_TSI_MODE_E enTSIMode;                     /**< The mode of CI Transport Stream Interface connection */
    HI_UNF_CI_TS_MODE_E enTSMode[HI_UNF_CI_PCCD_BUTT];     /**< The mode of TS pass to the CI device */
    union
    {
        HI_UNF_CI_CIMAX_ATTR_S stCIMaX;
        HI_UNF_CI_CIMAXPLUS_ATTR_S stCIMaXPlus;
        HI_UNF_CI_HICI_ATTR_S stCIHICI;
    }unDevAttr;
}HI_UNF_CI_ATTR_S, *HI_UNF_CI_ATTR_S_PTR;

/** TS control command */
/** CNcomment:TS\BF\D8\D6\C6\C3\FC\C1\EE */
typedef enum hiUNF_CI_PCCD_TSCTRL_E
{
    HI_UNF_CI_PCCD_TSCTRL_BYPASS,
    HI_UNF_CI_PCCD_TSCTRL_SETMODE,
    HI_UNF_CI_PCCD_TSCTRL_WRITETS,
    HI_UNF_CI_PCCD_TSCTRL_BUTT
}HI_UNF_CI_PCCD_TSCTRL_E;
/** USB TS Write parameter */
/** CNcomment:USB\CB\CD\C1\F7\B2\CE\CA\FD */
typedef struct hiUNF_CI_PCCD_TSWRITE_S
{
    HI_U8* pu8Data;     /**< Write data [in]*/
    HI_U32 u32Size;     /**< Write data size [in]*/
}HI_UNF_CI_PCCD_TSWRITE_S;

/** TS control parameter */
/** CNcomment:TS\BF\D8\D6Ʋ\CE\CA\FD */
typedef union
{
    struct
    {
        HI_BOOL bByPass;    /**< TURE means bypass, FALSE means pass-through */  /**< CNcomment:TRUE\B1\EDʾbypass, FALSE\B1\EDʾpass-through */
    }stByPass;

    struct
    {
        HI_UNF_CI_TS_MODE_E enTSMode;        /**< TS mode: parallel/serial/USB */
    }stMode;

    HI_UNF_CI_PCCD_TSWRITE_S stWrite;

    /* For extend */
}HI_UNF_CI_PCCD_TSCTRL_PARAM_U;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/** @} */  /** <!-- ==== API declaration end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      CI */
/** @{ */  /** <!-- [CI]*/

/**
\brief CI init
\brief CNcomment:CI\B3\F5ʼ\BB\AF  CNend
\attention \n
N/A
\param    N/A                                         CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS              success             CNcomment: \B3ɹ\A6 CNend
\retval ::HI_FAILURE              fail                CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_OPEN_ERR      opening file fail   CNcomment:\B4\F2\BF\AA\CEļ\FEʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Init(HI_VOID);

/**
\brief CI deinit
\brief CNcomment:CIȥ\B3\F5ʼ\BB\AF  CNend
\attention \n
N/A
\param  N/A                                              CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS             success                 CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE             fail                    CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_CLOSE_ERR    closing file fail       CNcomment:\B9ر\D5\CEļ\FEʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_DeInit(HI_VOID);

/**
\brief Sets CI device configration.
\brief CNcomment:CI\C9豸\CA\F4\D0\D4\C9\E8\D6\C3  CNend
\attention \n
N/A
\param[in] enCIPort  CI Port number.                     CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] pstCIAttr The pointer to a structure of CI device.
                                                         CNcomment:ָ\CF\F2CI\C9豸\CA\F4\D0Ե\C4ָ\D5롣 CNend
\retval ::HI_SUCCESS            success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE            fail                     CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_SetAttr(HI_UNF_CI_PORT_E enCIPort, const HI_UNF_CI_ATTR_S *pstCIAttr);

/**
\brief Gets CI device configration.
\brief CNcomment:CI\C9豸\CA\F4\D0Ի\F1ȡ  CNend
\attention \n
N/A
\param[in] enCIPort  CI Port number.                     CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] pstCIAttr The pointer to a structure of CI device.
                                                         CNcomment:ָ\CF\F2CI\C9豸\CA\F4\D0Ե\C4ָ\D5롣 CNend
\retval ::HI_SUCCESS            success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE            fail                     CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_GetAttr(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_ATTR_S *pstCIAttr);

/**
\brief open CI Port
\brief CNcomment:\B4\F2\BF\AACI Port CNend
\attention \n
N/A
\param[in] enCIPort     CI Port number                    CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\retval ::HI_SUCCESS    success                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE     fail                             CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter     CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port   CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error   CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error  CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Open(HI_UNF_CI_PORT_E enCIPort);

/**
\brief close CI Port
\brief CNcomment:\B9ر\D5CI Port CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number   CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\retval ::HI_SUCCESS       success      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE       fail         CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_Close(HI_UNF_CI_PORT_E enCIPort);

/**
\brief open CAM
\brief CNcomment:\B4\F2\BF\AACAM\BF\A8 CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number                                       CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId     Card ID                                             CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\retval ::HI_SUCCESS    success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE     fail                                               CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA   invalid parameter                        CNcomment: \CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open   CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                     CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                     CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                    CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Open(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
 \brief close CAM
 \brief CNcomment:\B9ر\D5CAM\BF\A8 CNend

 \attention \n
N/A
 \param[in] enCIPort   CI Port number   CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
 \param[in] enCardId   Card Id          CNcomment:\B2\D9\D7\F7\BF\A8 CNend
 \retval ::HI_SUCCESS   success         CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE    fail           CNcomment:ʧ\B0\DC CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_CI_PCCD_Close(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
 \brief CAM power switch
 \brief CNcomment:CAM\BF\A8\B5\E7Դ\BF\AA\B9\D8 CNend
 \attention \n
    Some solutions don't support power down for a single card, the calling of this interface
    automatically detects a power outage card plug, if it is on ,it will keep power on
    CNcomment:\D3еķ\BD\B0\B8\B2\BB֧\B3\D6\D5\EB\B6Ե\A5\BF\A8\B6ϵ磬\B5\F7\D3ñ\BE\BDӿڶϵ\E7ʱ\BB\E1\D7Զ\AF\BC\EC\B2\E2\CAǷ\F1\D3п\A8\B2\E5\C9ϣ\AC\C8\E7\B9\FB\D3У\AC\BD\AB\B2\BB\BB\E1\B6ϵ\E7 CNend
 \param[in] enCIPort    CI Port number                                       CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
 \param[in] enCardId    Card Id                                              CNcomment:\B2\D9\D7\F7\BF\A8 CNend
 \param[in] enCtrlPower power on\power off                                   CNcomment:\BF\AA\B5硢\B9ص\E7 CNend
 \retval ::HI_SUCCESS      success                                           CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE      fail                                              CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_CI_INVALID_PARA     invalid parameter                      CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
 \retval ::HI_ERR_CI_NOT_INIT         have not been initialized or not open  CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_CI_UNSUPPORT        unsupported CI Port                    CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
 \retval ::HI_ERR_CI_REG_READ_ERR     read register error                    CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_CI_REG_WRITE_ERR    write register error                   CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_CI_CANNOT_POWEROFF  can not power off                      CNcomment:\B2\BB\C4ܶϵ\E7 CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_CI_PCCD_CtrlPower(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                            HI_UNF_CI_PCCD_CTRLPOWER_E enCtrlPower);

/**
\brief CI reset
\brief CNcomment:CAM\BF\A8\B8\B4λ CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId    Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\retval ::HI_SUCCESS   success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   fail                                                   CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                      CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open  CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                    CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                    CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                   CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Reset(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
\brief CAM ready state checking
\brief CNcomment:CAM\BF\A8\BE\CD\D0\F7״̬\BC\EC\B2\E2 CNend
\attention \n
N/A
\param[in] enCIPort       CI Port number                                     CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                            CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[out] penCardReady  state value                                        CNcomment:״ֵ̬ CNend
\retval ::HI_SUCCESS      success                                            CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE      fail                                               CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA   invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT       have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT      unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR   read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR  write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_IsReady(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                            HI_UNF_CI_PCCD_READY_E_PTR penCardReady);

/**
\brief check CAM if it is on
\brief CNcomment:CAM\BF\A8\CAǷ\F1\B2\E5\C9ϼ\EC\B2\E2 CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId    Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[out] penCardStatus  card up or card down                               CNcomment:\BF\A8\B2\E5\C9ϻ\F2δ\B2\E5״̬ CNend
\retval ::HI_SUCCESS        success                                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                              CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_Detect(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                            HI_UNF_CI_PCCD_STATUS_E_PTR penCardStatus);

/**
\brief CAM set access module
\brief CNcomment:CAM\BF\A8\C9\E8\D6÷\C3\CE\CAģ\BF\E9 CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId    Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[in] enAccessMode mode you want to set                                  CNcomment:Ҫ\C9\E8\D6õ\C4ģʽ CNend
\retval ::HI_SUCCESS        success                                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                              CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_SetAccessMode(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                                    HI_UNF_CI_PCCD_ACCESSMODE_E enAccessMode);

/**
\brief CAM write or read state checking
\brief CNcomment:CAM\BF\A8\B6\C1д״̬\BC\EC\B2\E2 CNend
\attention \n
N/A
\param[in] enCIPort    CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId    Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[in] enStatus    status of the bit will check                           CNcomment:Ҫ\BC\EC\B2\E2\B5\C4״̬λ CNend
\param[out] pu8Value   status code returned                                   CNcomment:\B7\B5\BBص\C4״̬\C2\EB CNend
\retval ::HI_SUCCESS        success                                           CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                              CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_IO_READ_ERR       read IO error                           CNcomment:IO\B6\C1\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_GetStatus (HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                                HI_UNF_CI_PCCD_STATUS_BIT_E enStatus, HI_U8 *pu8Value);

/**
\brief CAM IO read data
\brief CNcomment:CAM\BF\A8IO\B6\C1\CA\FD\BE\DD CNend
\attention \n
N/A
\param[in] enCIPort       CI Port number                                      CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                             CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[out] pu8Buffer     data buffer                                         CNcomment: \CA\FD\BEݻ\BA\B3\E5\C7\F8 CNend
\param[in]  u32BufferLen  data buffer length                                  CNcomment: \CA\FD\BEݻ\BA\B3\E5\C7\F8Buffer\B3\A4\B6\C8 CNend
\param[out] pu32ReadLen   data length that read successful                    CNcomment:\B3ɹ\A6\B6\C1ȡ\B5ĳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS      success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                              CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_IO_READ_ERR     read IO error                             CNcomment:IO\B6\C1\B4\ED\CE\F3 CNend
\see \n
    HI_UNF_CI_PCCD_IOWrite()
*/
HI_S32 HI_UNF_CI_PCCD_IORead(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                            HI_U8 *pu8Buffer, HI_U32 u32BufferLen,
                                            HI_U32 *pu32ReadLen);

/**
\brief CAM IO write data
\brief CNcomment:CAM\BF\A8IOд\CA\FD\BE\DD CNend
\attention \n
N/A
\param[in] enCIPort       CI Port number                                      CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                             CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[in] pu8Buffer      data buffer                                         CNcomment:\CA\FD\BEݻ\BA\B3\E5\C7\F8 CNend
\param[in] u32WriteLen     byte number that have been  writen                 CNcomment:д\C8\EB\D7ֽ\DA\CA\FD CNend
\param[out] pu32WriteOKLen  data length that write successful                 CNcomment:\B3ɹ\A6д\C8\EB\D7ֽ\DA\CA\FD CNend
\param[in] enCIPort       operate CI port                                     CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                             CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[out] pu8Buffer     data buffer                                         CNcomment: \CA\FD\BEݻ\BA\B3\E5\C7\F8 CNend
\param[out] pu32ReadLen   data length that read successful                    CNcomment:\B3ɹ\A6\B6\C1ȡ\B5ĳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS      success                                             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                              CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA    invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT        have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT       unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_IO_WRITE_ERR    write IO error                            CNcomment:IOд\B4\ED\CE\F3 CNend
\see \n
    HI_UNF_CI_PCCD_IORead()
*/
HI_S32 HI_UNF_CI_PCCD_IOWrite(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                            HI_U8 *pu8Buffer, HI_U32 u32WriteLen, HI_U32 *pu32WriteOKLen);

/**
\brief check CAM CIS information
\brief CNcomment:\BC\EC\D1\E9CAM\BF\A8CIS\D0\C5Ϣ CNend
\attention \n
    reference EN50221.
    CNcomment:\C7\EB\B2ο\BC\B9淶 EN50221. CNend
\param[in] enCIPort       CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:\C9豸æ CNend
\retval ::HI_ERR_CI_PCCD_CIS_READ      read CIS information fail                 CNcomment:\B6\C1CIS\D0\C5Ϣʧ\B0\DC CNend
\retval ::HI_ERR_CI_REG_READ_ERR    read register error                          CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR   write register error                         CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_CheckCIS(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
\brief config CAM COR information
\brief CNcomment:\C5\E4\D6\C3CAM\BF\A8COR\D0\C5Ϣ CNend
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:\C9豸æ CNend
\retval ::HI_ERR_CI_ATTR_WRITE_ERR     config COR fail                           CNcomment:\C5\E4\D6\C3CORʧ\B0\DC CNend
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
    N/A
*/
HI_S32 HI_UNF_CI_PCCD_WriteCOR(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
\brief CAM IO reset
\brief CNcomment:CAM\BF\A8IO\BFڸ\B4λ CNend
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          not supported CI Port                     CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_PCCD_TIMEOUT       timeout                                   CNcomment:\B3\ACʱ CNend
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
    HI_UNF_CI_PCCD_CheckCIS()
*/
HI_S32 HI_UNF_CI_PCCD_IOReset(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId);

/**
\brief CAM negotiate buffer size
\brief CNcomment:CAM\BF\A8Э\C9\CCbuffer size CNend
\attention \n
    N/A
\param[in] enCIPort      CI Port number                                          CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[in] pu16BufferSize   input  buffer size that master support               CNcomment:\CA\E4\C8\EB\D6\F7\BB\FA\B6\CB֧\B3\D6buffer size CNend
\param[out] pu16BufferSize  output buffer size after consultation                CNcomment:\CA\E4\B3\F6Э\C9̺\F3\B5\C4buffer size CNend
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_PCCD_TIMEOUT       timeout                                   CNcomment:\B3\ACʱ CNend
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_IO_READ_ERR        read IO error                             CNcomment:IO\B6\C1\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_NegBufferSize(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                                    HI_U16 *pu16BufferSize);

/**
\brief CAM TS control
CNcomment: \brief CAM\BF\A8TS\BF\D8\D6\C6 CNend
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port CNend
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8 CNend
\param[in] enCMD          control command                                        CNcomment:\BF\D8\D6\C6\C3\FC\C1\EE CNend
\param[in] pParam         parameter that matching command                        CNcomment:\D3\EB\C3\FC\C1\EEƥ\C5\E4\B5Ĳ\CE\CA\FD CNend
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD CNend
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port CNend
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_TSCtrl(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                        HI_UNF_CI_PCCD_TSCTRL_E enCMD, HI_UNF_CI_PCCD_TSCTRL_PARAM_U *pParam);

/**
\brief Get CAM CIS
CNcomment:\brief \BB\F1ȡCAM\B5\C4CIS\CA\FD\BE\DD
\attention \n
    N/A
\param[in] enCIPort            CI Port number                                       CNcomment:\B2\D9\D7\F7\B5\C4CI port
\param[in] enCardId           Card Id                                              CNcomment:\B2\D9\D7\F7\BF\A8
\param[out] pu8CisBuffer       output CIS data                                      CNcomment:\CA\E4\B3\F6CAM\B5\C4CIS\CA\FD\BE\DD
\param[in]  u32CisBufferLen the length of output CIS data buffer                 CNcomment:\CA\E4\B3\F6CAM\B5\C4CIS\CA\FD\BE\DDBuffer\B3\A4\B6\C8
\param[out] pu32CisLen      output CIS data length                                CNcomment:\CA\E4\B3\F6CAM\B5\C4CIS\CA\FD\BEݳ\A4\B6\C8
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:\C9豸æ
\retval ::HI_ERR_CI_PCCD_CIS_READ      read cis error                            CNcomment:\B6\C1CIS\B4\ED\CE\F3
\see \n
N/A
*/
HI_S32 HI_UNF_CI_PCCD_GetCIS(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                             HI_U8 *pu8CisBuffer, HI_U32 u32CisBufferLen, HI_U32 *pu32CisLen);

/**
\brief config CAM COR information
CNcomment:\brief \C5\E4\D6\C3CAM\BF\A8COR\D0\C5Ϣ
\attention \n
    N/A
\param[in] enCIPort       CI Port number                                         CNcomment:\B2\D9\D7\F7\B5\C4CI port
\param[in] enCardId       Card Id                                                CNcomment:\B2\D9\D7\F7\BF\A8
\param[in] u16Addr        COR register address                                   CNcomment:COR\BCĴ\E6\C6\F7\B5\D8ַ
\param[in] u8Data         COR register data                                      CNcomment:Ҫд\C8\EBCOR\BCĴ\E6\C6\F7\B5\C4\CA\FD\BE\DD
\retval ::HI_SUCCESS      success                                                CNcomment:\B3ɹ\A6
\retval ::HI_FAILURE        fail                                                 CNcomment:ʧ\B0\DC
\retval ::HI_ERR_CI_INVALID_PARA       invalid parameter                         CNcomment:\CE\DEЧ\B2\CE\CA\FD
\retval ::HI_ERR_CI_NOT_INIT           have not been initialized or not open     CNcomment:δ\B3\F5ʼ\BB\AF\BB\F2δ\B4\F2\BF\AA
\retval ::HI_ERR_CI_UNSUPPORT          unsupported CI Port                       CNcomment:\B2\BB֧\B3ֵ\C4CI Port
\retval ::HI_ERR_CI_PCCD_DEVICE_BUSY   device busy                               CNcomment:\C9豸æ
\retval ::HI_ERR_CI_ATTR_WRITE_ERR     config COR fail                           CNcomment:\C5\E4\D6\C3CORʧ\B0\DC
\retval ::HI_ERR_CI_REG_READ_ERR       read register error                       CNcomment:\B6\C1\BCĴ\E6\C6\F7\B4\ED\CE\F3
\retval ::HI_ERR_CI_REG_WRITE_ERR      write register error                      CNcomment:д\BCĴ\E6\C6\F7\B4\ED\CE\F3
\see \n
    N/A
*/
HI_S32 HI_UNF_CI_PCCD_WriteCOREx(HI_UNF_CI_PORT_E enCIPort, HI_UNF_CI_PCCD_E enCardId,
                                  HI_U16 u16Addr, HI_U8 u8Data);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ECS_TYPE_H__ */
