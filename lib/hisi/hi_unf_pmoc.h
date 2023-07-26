/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
File Name     : hi_unf_pmoc.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date  : 2012-08-24
Last Modified by:
Description   : Application programming interfaces (APIs) of the PMOC
Function List :
Change History:
 ******************************************************************************/

#ifndef __HI_UNF_PMOC_H__
#define __HI_UNF_PMOC_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#include "hi_unf_keyled.h"

#include "hi_unf_ir.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PMOC */
/** @{ */  /** <!-- [PMOC] */

/**ARM mode*/
/**CNcomment:ARM\CB\F9\B4\A6\B5\C4ģʽ*/
typedef enum hiUNF_PMOC_MODE_E
{
    HI_UNF_PMOC_MODE_NORMAL = 0,    /**<Normal*/     /**<CNcomment:\C6\D5ͨģʽ */
    HI_UNF_PMOC_MODE_SLOW,          /**<Not support*/ /**<CNcomment: \B2\BB֧\B3\D6 */
    HI_UNF_PMOC_MODE_DOZE,          /**<Not support*/ /**<CNcomment: \B2\BB֧\B3\D6 */
    HI_UNF_PMOC_MODE_SLEEP,         /**<Sleep*/      /**<CNcomment:˯\C3\DFģʽ */

    HI_UNF_PMOC_MODE_BUTT
}HI_UNF_PMOC_MODE_E;


/**standby woken type*/
/**CNcomment:\B4\FD\BB\FA\B1\BB\BB\BD\D0ѵ\C4\C0\E0\D0\CD */
typedef enum hiUNF_PMOC_ACTUAL_WKUP_E
{
    HI_UNF_PMOC_WKUP_IR = 0,      /**<Woken by the IR module*/                /**<CNcomment:\B1\BBIR\BB\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_KEYLED,      /**<Woken by the keys on the front panel*/  /**<CNcomment:\B1\BBǰ\C3\E6\B0\E5KEY\BB\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_TIMEOUT,     /**<Woken by the timing interrupt*/         /**<CNcomment:\B1\BB\B6\A8ʱ\D6жϻ\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_ETH,         /**<Woken by the ethernet interrupt*/       /**<CNcomment:\B1\BB\CD\F8\C2\E7\D6жϻ\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_USB,         /**<Woken by the USB interrupt*/            /**<CNcomment:\B1\BBUSB\CA\F3\B1\EA\BC\FC\C5\CC\D6жϻ\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_GPIO,        /**<Woken by the GPIO interrupt*/           /**<CNcomment:\B1\BBGPIO\D6жϻ\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_CEC,        /**<Woken by the CEC */                     /**<CNcomment:\B1\BBCEC \BB\BD\D0\D1 */
    HI_UNF_PMOC_WKUP_BUTT
}HI_UNF_PMOC_ACTUAL_WKUP_E;

typedef enum hiUNF_PMOC_SCENE_E
{
    HI_UNF_PMOC_SCENE_STANDARD = 0,  /**<Standard scenario*/                    /**<CNcomment:\B1\EA׼\B3\A1\BE\B0 */
    HI_UNF_PMOC_SCENE_ETH,           /**<Forward scenario over the ETH port */  /**<CNcomment:\CD\F8\BF\DAת\B7\A2\B3\A1\BE\B0(\B2\BB֧\B3\D6) */
    HI_UNF_PMOC_SCENE_PHONE,         /**<Calling scenario(not support)*/        /**<CNcomment:ͨ\BB\B0\B3\A1\BE\B0(\B2\BB֧\B3\D6) */
    HI_UNF_PMOC_SCENE_BUTT
}HI_UNF_PMOC_SCENE_E;

typedef enum hiUNF_PMOC_ETH_E
{
    HI_UNF_PMOC_ETH_0 = 0x01,        /**<The first ETH.*/    /**<CNcomment:\B5\DA1\B8\F6\CD\F8\BF\DA*/
    HI_UNF_PMOC_ETH_1 = 0x02,        /**<The second ETH.*/   /**<CNcomment:\B5\DA2\B8\F6\CD\F8\BF\DA*/
    HI_UNF_PMOC_ETH_BUTT = 0x04
}HI_UNF_PMOC_ETH_E;

/**Defines the modules working in smart standby */
/**CNcomment:\D6\C7\C4ܴ\FD\BB\FAʱ\B2\BB\CFµ\E7ģ\BF鶨\D2\E5 */
typedef enum hiUNF_PMOC_HOLD_MOD_E
{
    HI_UNF_PMOC_HOLD_ETH = 0x0001,   /**<Keep eth working */    /**<CNcomment:\CD\F8\BFڲ\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_WIFI = 0x0002,  /**<Keep WIFI working */   /**<CNcomment:WIFI\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_USB = 0x0004,   /**<Keep USB working */    /**<CNcomment:USB\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_TUNER = 0x0008, /**<Keep tuner working */  /**<CNcomment:Tuner\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_DEMUX = 0x0010, /**<Keep demux working */  /**<CNcomment:Demux\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_SDIO = 0x0020,  /**<Keep SDIO working */   /**<CNcomment:SD\BF\A8\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_SCI = 0x0040,   /**<Keep SCI working */    /**<CNcomment:SCI\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_VENC = 0x0080,  /**<Keep VENC working */   /**<CNcomment:VENC\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_PNG = 0x0100,   /**<Keep PNG working */    /**<CNcomment:PNG\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_JPGE = 0x0200,  /**<Keep JPGE working */   /**<CNcomment:JPGE\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_JPEG = 0x0400,  /**<Keep JPEG working */   /**<CNcomment:JPEG\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_WDG = 0x0800,   /**<Keep WDG working */    /**<CNcomment:WDG\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_HDMI = 0x1000,  /**<Keep HDMI working */   /**<CNcomment:HDMI\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_VO = 0x2000,    /**<Keep VO working */     /**<CNcomment:VO\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_DISP = 0x4000,  /**<Keep DISP working */   /**<CNcomment:DISP\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_AO = 0x8000,    /**<Keep AO working */     /**<CNcomment:AO\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_AI = 0x10000,   /**<Keep AI working */     /**<CNcomment:AI\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_ADSP = 0x20000, /**<Keep ADSP working */   /**<CNcomment:ADSP\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_CIPHER = 0x40000, /**<Keep CIPHER working */   /**<CNcomment:CIPHER\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_VDEC = 0x80000, /**<Keep VDEC working */   /**<CNcomment:VDEC\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_VPSS = 0x100000, /**<Keep VPSS working */  /**<CNcomment:VPSS\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_OTP = 0x200000, /**<Keep OTP working */    /**<CNcomment:OTP\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_TDE = 0x400000, /**<Keep TDE working */    /**<CNcomment:TDE\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_I2C = 0x800000, /**<Keep I2C working */    /**<CNcomment:I2C\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_GPIO = 0x1000000,/**<Keep GPIO working */  /**<CNcomment:GPIO\B2\BB\CFµ\E7 */
    HI_UNF_PMOC_HOLD_BUTT = 0x80000000,
}HI_UNF_PMOC_HOLD_MOD_E;

#define PMOC_WKUP_IRKEY_MAXNUM 6
#define FILTER_VALUE_COUNT   (31)
#define FILTER_COUNT         (4)

typedef struct hiUNF_PMOC_WAKEUP_FRAME
{
    HI_U32  u32MaskBytes;  /**<Mask byte, bitN to control u8Value[N]. 0: invalid, 1: valid*/  /**<CNcomment: \B6\D4Ӧvalue\B5\C4\D1\DA\C2\EB, bitN\B6\D4Ӧu8Value[N], 0\B4\FA\B1\ED\CE\DEЧ\A3\AC1\B4\FA\B1\ED\D3\D0Ч */
    HI_U8   u8Offset;      /**<Filter offset, should be bigger than or equal to 12*/          /**<CNcomment: \B9\FD\C2\CB\C6\F7ƫ\D2\C6\C1\BF\A1\A3\D0\E8Ҫ\B4\F3\D3ڻ\F2\B5\C8\D3\DA12*/
    HI_U8   u8Value[FILTER_VALUE_COUNT];   /**<Filter value*/                                 /**<CNcomment: \B9\FD\C2\CB\C6\F7\B5\C4ֵ*/
    HI_BOOL bFilterValid;  /**<Valid filter, 0: invalid, 1: valid*/                           /**<CNcomment: \B9\FD\C2\CB\C6\F7\CAǷ\F1\D3\D0Ч\A3\AC0\B4\FA\B1\ED\CE\DEЧ\A3\AC1\B4\FA\B1\ED\D3\D0Ч*/
}HI_UNF_PMOC_WAKEUP_FRAME_S, *HI_UNF_WAKEUP_FRAME_S_PTR;

typedef struct hiUNF_PMOC_NETWORK
{
    HI_UNF_PMOC_ETH_E          enEthIndex;         /**<Eth index, can set several eth once*/  /**<CNcomment: \CD\F8\BF\DA\D0\F2\BAţ\AC\BF\C9\D2\D4ͬʱ\C9\E8\D6ö\E0\B8\F6\CD\F8\BF\DA*/
    HI_BOOL                    bUcPacketEnable;    /**<Single packet enable*/                 /**<CNcomment: \B5\A5\B2\A5\B0\FCʹ\C4\DC */
    HI_BOOL                    bMagicPacketEnable; /**<Magic packet enable*/                  /**<CNcomment: ħ\B7\A8\B0\FCʹ\C4\DC*/
    HI_BOOL                    bWakeupFrameEnable; /**<Wakeup Frame enable*/                  /**<CNcomment: \BB\BD\D0\D1֡ʹ\C4\DC */
    HI_UNF_PMOC_WAKEUP_FRAME_S stFrame[FILTER_COUNT];         /**<Filter frame*/              /**<CNcomment: \BB\BD\D0\D1֡\CA\FD\BE\DD */
    HI_U32                     u32TimeToDeepStandby;          /**<time to deep standby(unit:s)*/      /**<CNcomment: \B6\A8ʱ\C7л\BB\B5\BD\D5\E6\B4\FD\BB\FA\B5\C4ʱ\BC\E4(\B5\A5λ:\C3\EB) */
}HI_UNF_PMOC_NETWORK_S, *HI_UNF_PMOC_NETWORK_S_PTR;

/**Defines the standby wake-up conditions.*/
/**CNcomment:\B4\FD\BB\FA\BB\BD\D0ѵ\C4\CC\F5\BC\FE\B6\A8\D2\E5*/
typedef struct hiUNF_PMOC_WKUP_S
{
    /**<Number of supported values of the power key. For the raw IR remote control, the number cannot be greater than the maximum key value 6 that is defined by the macro definition PMOC_WKUP_IRKEY_MAXNUM. Only one key value is supported for other remote controls.*/
    /**<CNcomment:\C4ܹ\BB֧\B3\D6power\BC\FCֵ\B8\F6\CA\FD\A3\ACraw \D0ͺ\EC\CD\E2ң\BF\D8: \B2\BB\C4ܳ\ACԽPMOC_WKUP_IRKEY_MAXNUM(<=6)\BA궨\D2\E5\CB\F9\CA\F6\B8\F6\CA\FD\BC\FCֵ\A3\AC\C6\E4\D3\E0\C0\E0\D0\CDֻ\C4\DC֧\B3\D6һ\B8\F6\BC\FCֵ*/
    HI_U32 u32IrPmocNum;

    HI_U32 u32IrPowerKey0[PMOC_WKUP_IRKEY_MAXNUM];  /**<Lower-bit value of the power key on an IR remote control*/  /**<CNcomment:\BA\EC\CD\E2ң\BF\D8 power \B5\CDλ\BC\FCֵ */
    HI_U32 u32IrPowerKey1[PMOC_WKUP_IRKEY_MAXNUM];  /**<Upper-bit value of the power key on an IR remote control*/  /**<CNcomment:\BA\EC\CD\E2ң\BF\D8 power \B8\DFλ\BC\FCֵ */
    HI_U32 u32IrSymbol[64];                         /**<Value of the raw power key of IR*/                          /**<CNcomment:\BA\EC\CD\E2ң\BFػ\BD\D0\D1ԭʼ\B5\E7ƽ\B6\D4 */
    HI_U32 u32KeypadPowerKey;                           /**<Value of the power key*/                                    /**<CNcomment:\B0\B4\BC\FC power\BC\FCֵ */
    HI_U32 u32WakeUpTime;                               /**<Preconfigured Wake-up time, in second*/                     /**<CNcomment:\BB\BD\D0Ѷ\A8ʱʱ\BC\E4 ,\B5\A5λΪ \C3\EB  */
    HI_UNF_PMOC_NETWORK_S stNetwork;                    /**<Network parameter*/                                         /**<CNcomment:\CD\F8\C2绽\D0Ѳ\CE\CA\FD*/
    HI_BOOL bMouseKeyboardEnable;                       /**<Mouse and key wake-up enable*/                              /**<CNcomment:\CA\F3\B1\EA\BC\FC\C5̻\BD\D0\D1ʹ\C4\DC*/
    HI_BOOL bResumeResetEnable;                         /**<When resume, reset board enable*/                           /**<CNcomment:\B4\FD\BB\FA\BB\BD\D0\D1\D6\D8\C6\F4ʹ\C4\DC*/
    HI_BOOL bGpioWakeUpEnable;                          /**<Gpio wake up enable */                                      /**<CNcomment:GPIO\BB\BD\D0\D1ʹ\C4\DC*/
    HI_U32 u32GpioNo;                                   /**<Gpio wake up number */                                      /**<CNcomment:GPIO\BB\BD\D0Ѷ˿\DA*/
    HI_BOOL bCECWakeUpEnable;                          /**< CEC wake up enable */                                      /**<CNcomment:CEC\BB\BD\D0\D1ʹ\C4\DC*/
}HI_UNF_PMOC_WKUP_S, *HI_UNF_PMOC_WKUP_S_PTR;

/**Configures the time displayed on the front panel in standby mode.*/
/**CNcomment:\B4\FD\BB\FAʱ\B5\C4ǰ\C3\E6\B0\E5\CF\D4ʾ\B5\C4ʱ\BC\E4\C5\E4\D6\C3 */
typedef struct hiUNF_PMOC_TIME_S
{
    HI_U32 u32Hour;            /**<Hour*/     /**<CNcomment:ʱ */
    HI_U32 u32Minute;          /**<Minute*/   /**<CNcomment:\B7\D6 */
    HI_U32 u32Second;          /**<Second*/   /**<CNcomment:\C3\EB */
}HI_UNF_PMOC_TIME_S, *HI_UNF_PMOC_TIME_S_PTR;

/**Configures the display mode of the front panel in standby mode.*/
/**CNcomment:\B4\FD\BB\FAʱ\B5\C4ǰ\C3\E6\B0\E5\CF\D4ʾ\C5\E4\D6\C3 */
typedef struct hiUNF_PMOC_STANDBY_MODE_S
{
    HI_U32             u32Mode;      /**<0: no display; 1: display the digits represented by u32DispCod; 2: display the time represented by stTimeInfo*/     /**<CNcomment:0 : \CE\DE\CF\D4ʾ 1 : \CF\D4ʾu32DispCode\B4\FA\B1\ED\B5\C4\CA\FD\D7\D6; 2 : \CF\D4ʾstTimeInfo\B4\FA\B1\ED\B5\C4ʱ\BC\E4. */
    HI_U32             u32DispCode;  /**<Digits displayed on the front panel when u32Mode is 1, value range from 0000 to 9999, do not support hex */         /**<CNcomment:u32ModeΪ1ʱ\A3\ACǰ\C3\E6\B0\E5\CF\D4ʾ\B5\C4\CA\FD\D7֣\ACȡֵ\B7\B6Χ\B4\D30000\B5\BD9999\A3\AC\B2\BB֧\B3\D616\BD\F8\D6\C6\CA\FD */
    HI_UNF_PMOC_TIME_S stTimeInfo; /**<Time displayed on the front panel when u32Mode is 2*/                                                                 /**<CNcomment:u32ModeΪ2ʱ\A3\ACǰ\C3\E6\B0\E5\CF\D4ʾ\B5\C4ʱ\BC\E4*/
}HI_UNF_PMOC_STANDBY_MODE_S, *HI_UNF_PMOC_STANDBY_MODE_S_PTR;

/**Type of the device that is woken in standby mode*/
/**CNcomment:\B4\FD\BB\FA\BB\BD\D0ѵ\C4\C9豸\C0\E0\D0\CD */
typedef struct hiUNF_PMOC_DEV_TYPE_S
{
    HI_UNF_IR_CODE_E     irtype;    /**<Type of the IR remote control*/  /**<CNcomment:\BA\EC\CD\E2ң\BF\D8\C0\E0\D0\CD */
    HI_UNF_KEYLED_TYPE_E kltype;  /**<Type of the front panel*/        /**<CNcomment:ǰ\C3\E6\B0\E5\C0\E0\D0\CD */
}HI_UNF_PMOC_DEV_TYPE_S, *HI_UNF_PMOC_DEV_TYPE_S_PTR;

/**Mode of last wakeup*/
/**CNcomment:\C9\CFһ\B4δ\A5\B7\A2\BB\BD\D0ѵĲ\CE\CA\FD*/
typedef struct hiUNF_PMOC_WAKEUP_MODE_S
{
    HI_UNF_PMOC_ACTUAL_WKUP_E  enWakeUpMode; /**<Wake-up mode returned from last wakeup*/     /**<CNcomment:\C9\CFһ\B4δ\FD\BB\FA\BB\BD\D0ѵ\C4ģʽ */
    HI_U64                     u64IRPowerKey;  /**<The IR power key of last wakeup*/          /**<CNcomment:\C9\CFһ\B4δ\FD\BB\FA\BB\BD\D0ѵ\C4ң\BF\D8\C6\F7\B0\B4\BC\FCֵ */
    HI_U32                     u32GPIONo;     /**<Gpio number of last wakeup*/                /**<CNcomment:\C9\CFһ\B4δ\FD\BB\FA\BB\BD\D0ѵ\C4GPIO\B6˿\DA*/
}HI_UNF_PMOC_WAKEUP_MODE_S, *HI_UNF_PMOC_WAKEUP_MODE_S_PTR;

/** Define of chip temperature */
/**CNcomment: оƬ\CE¶Ƚṹ\CC\E5*/
typedef struct hiUNF_PMOC_CHIP_TEMP_S
{
    HI_S32 s32ChipSensor1Temp; /**<The temperature of chip sensor1 in millidegree Celsius */  /**<CNcomment:оƬ\B5\DAһ\B8\F6\B4\AB\B8\D0\C6\F7\B5\C4\CE¶ȣ\AC\B5\A5λ\BA\C1\B6\C8 */
    HI_S32 s32ChipSensor2Temp; /**<Reserved now*/ /**<CNcomment: \B5\B1ǰ\B1\A3\C1\F4 */
    HI_S32 s32ChipSensor3Temp; /**<Reserved now*/ /**<CNcomment: \B5\B1ǰ\B1\A3\C1\F4 */
    HI_S32 s32ChipSensor4Temp; /**<Reserved now*/ /**<CNcomment: \B5\B1ǰ\B1\A3\C1\F4 */
}HI_UNF_PMOC_CHIP_TEMP_S;


/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      PMOC */
/** @{ */  /** <!-- [PMOC] */
/*---- pm ----*/

/**
\brief Starts the power management on chip (PMoC) device.
CNcomment:\brief \B4򿪵͹\A6\BA\C4ģ\BF\E9\C9豸\A1\A3CNend

\attention \n
The ARM can be switched to another operating mode and then to low-power mode only after the PMoC device is started.\n
CNcomment:\D4ڴ򿪵͹\A6\BA\C4ģ\BF\E9\C9豸\BA󣬲\C5\C4\DC\C7л\BBARM\B5Ĺ\A4\D7\F7ģʽ\A3\AC\BC̶\F8\BD\F8\C8\EB\B5͹\A6\BA\C4״̬\A1\A3CNend

\param N/A                                                               CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_FAILED_INIT  The PMoC device fails to open.        CNcomment:PMoC\C9豸\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_Init(HI_VOID);

/**
\brief Stops the PMoC device.
CNcomment:\brief \B9رյ͹\A6\BA\C4\C9豸\A1\A3CNend

\attention \n
N/A
\param  N/A                                                             CNcomment:\CE\DE CNend
\retval HI_SUCCESS Success                                              CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.         CNcomment:\C9豸δ\B4\F2\BF\AA CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_DeInit(HI_VOID);

/**
\brief Sets the mode to which the ARM is switched and obtains the wake-up mode.
CNcomment:\brief \C9\E8\D6\C3ARMҪ\C7л\BB\B5\BD\B5\C4ģʽ\A3\ACͬʱ\BB\F1ȡARM\BB\BD\D0ѵķ\BDʽ\A1\A3CNend

\attention \n
If the ARM enters the HI_UNF_PMOC_MODE_SLEEP mode, programs stop running at once. The subsequent code can be executed only after the ARM is woken up.\n
Before enabling the standby mode, you must start the IR device, key device on the front panel; otherwise, the interrupts of these devices are masked. As a result, the corresponding wake-up modes cannot be achieved.\n
Do not access DDRs after the ARM enters the sleep mode. Therefore, the functions of display output, video output, DEMUX input, and audio/video decoding must be disabled.\n
CNcomment:ARM\BD\F8\C8\EBHI_UNF_PMOC_MODE_SLEEP\D5\E6\B4\FD\BB\FAģʽ\BA\F3\B3\CC\D0\F2\C1\A2\BC\B4ֹͣ\D4\CB\D0У\AC\B1\D8\D0\EB\D4ڻ\BD\D0Ѻ\F3\B2\C5\C4ܼ\CC\D0\F8ִ\D0к\F3\C3\E6\B5Ĵ\FA\C2\EB\n
\BD\F8\C8\EB\B4\FD\BB\FAģʽǰ\A3\AC\B1\D8\D0\EB\B4\F2\BF\AAIR\A3\A8ң\BF\D8\C6\F7\A3\A9\C9豸\A1\A2ǰ\C3\E6\B0\E5KEY\C9豸\A3\AC\B7\F1\D4\F2\B6\D4Ӧģ\BF\E9\B5\C4\D6жϱ\BB\C6\C1\B1Σ\AC\B2\BB\C4\DCʵ\CFָ\C3\D6\D6ģʽ\B5Ļ\BD\D0\D1\n
\BD\F8\C8\EB\D5\E6\B4\FD\BB\FAʱ\A3\AC\B1\D8\D0\EBȷ\B1\A3\B2\BB\B6\D4DDR\BD\F8\D0з\C3\CEʡ\A3\CB\F9\D2Ա\D8\D0\EB\B9ر\D5\CF\D4ʾ\CA\E4\B3\F6\A1\A2\CA\D3Ƶ\CA\E4\B3\F6\A1\A2DEMUX\CA\E4\C8롢\D2\F4\CA\D3Ƶ\BD\E2\C2\EB\B5ȡ\A3CNend

\param[in] enSystemMode   Mode of the ARM in low-power mode                CNcomment: \D6õ͹\A6\BA\C4\CF\C2ARM\CB\F9\B4\A6ģʽ\A1\A3CNend

\param[out]  penWakeUpStatus Wake-up mode returned from the HI_UNF_PMOC_MODE_SLEEP mode. For details about the definition, see the description of ::HI_UNF_PMOC_ACTUAL_WKUP_E. \n
                         CNcomment: \B4\D3HI_UNF_PMOC_MODE_SLEEP״̬\B7\B5\BB\D8ʱ\B5Ļ\BD\D0ѷ\BDʽ\A1\A3\BE\DF\CC庬\D2\E5\C7\EB\B2ο\BC::HI_UNF_PMOC_ACTUAL_WKUP_E CNend
\retval HI_SUCCESS Success                                                 CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT   The PMoC device is not started.           CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_STANDBY  It fails to enter standby            CNcomment:\BD\F8\C8\EB\B4\FD\BB\FAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SwitchSystemMode(HI_UNF_PMOC_MODE_E enSystemMode, HI_UNF_PMOC_ACTUAL_WKUP_E * penWakeUpStatus);

/**
\brief Sets the wake-up mode of the ARM.
CNcomment:\brief \C9\E8\D6\C3ARM\BB\BD\D0ѷ\BDʽ\A1\A3CNend

\attention \n
You can query the original IR code values by referring to IR remote manuals.\n
In addition, you can query the relationships between the keys and key IDs by checking the connection between hardware and chips.\n
CNcomment:IRԭʼ\C2\EBֵ\BF\C9\D2\D4ͨ\B9\FDң\BF\D8\C6\F7\B5\C4ʹ\D3\C3\CAֲ\E1\B5õ\BD\n
\B0\B4\BC\FC\D3\EB\BC\FCֵ\B5Ķ\D4Ӧ\B9\D8ϵ\BF\C9\D2\D4ͨ\B9\FDӲ\BC\FE\BA\CDоƬ\B5\C4\C1\AC\BDӹ\D8ϵ\B5õ\BD\A1\A3CNend

\param[in] pstAttr  Wake-up mode of the ARM                             CNcomment:ARM\BB\BD\D0ѷ\BDʽ\A1\A3CNend
\retval HI_SUCCESS Success                                              CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.         CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.            CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.           CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_SETWAKEUPVAL It fails to set power val.    CNcomment:\C9\E8\D6û\BD\D0ѷ\BDʽʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetWakeUpAttr(HI_UNF_PMOC_WKUP_S_PTR pstAttr);

/**
\brief Gets the wake-up mode of the ARM.
CNcomment:\brief \BB\F1ȡ\D2\D1\C9\E8\D6õ\C4ARM\BB\BD\D0ѷ\BDʽ\A1\A3CNend

\attention \n

\param[out] pstAttr  Wake-up mode of the ARM                            CNcomment:ARM\BB\BD\D0ѷ\BDʽ\A1\A3CNend
\retval HI_SUCCESS Success                                              CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.         CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.            CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.           CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_GETWAKEUPVAL It fails to set power val.    CNcomment:\BB\F1ȡ\BB\BD\D0ѷ\BDʽʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_GetWakeUpAttr(HI_UNF_PMOC_WKUP_S_PTR pstAttr);


/**
\brief set display content when wake up.
CNcomment:\brief \C9\E8\D6û\BD\D0\D1\CF\D4ʾ\C4\DA\C8ݡ\A3CNend

\attention \n
content that the panel display when standby
CNcomment:\B4\FD\BB\FAʱ\C3\E6\B0\E5\CF\D4ʾָ\B6\A8\C4\DA\C8\DD\n CNend

\param[in] pstStandbyMode  display content:time or channel or no display   CNcomment:\CF\D4ʾ\C4\DA\C8\DD:ʱ\BC\E4 or Ƶ\B5\C0 or \CE\DE\CF\D4ʾ\A1\A3CNend
\retval HI_SUCCESS  success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_STANDBY  It fails to set standby display      CNcomment:\C9\E8\D6û\BD\D0\D1\C4\DA\C8\DDʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetStandbyDispMode(HI_UNF_PMOC_STANDBY_MODE_S_PTR pstStandbyMode);

/**
\brief Obtains the current system mode.
CNcomment:\brief \BB\F1ȡϵͳ\B5\B1ǰģʽ\A1\A3CNend

\attention \n
This API is abandoned and only used for forward compatible. It always returns normal state.\n
CNcomment:\B4˽ӿ\DA\D2ѷ\CF\C6\FA\A3\ACʼ\D6շ\B5\BB\D8\C6\D5ͨģʽ\A3\AC\BD\F6Ϊ\BC\E6\C8\DD֮ǰ\B0汾ʹ\D3á\A3\n CNend

\param[in] penSystemMode  Mode to be obtained                   CNcomment:\D0\E8Ҫ\BB\F1ȡ\B5\C4ģʽ\A1\A3CNend
\retval HI_SUCCESS Success                                      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started. CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.    CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_ReadSystemMode(HI_UNF_PMOC_MODE_E * penSystemMode);

/**
\brief Sets the operating scenario.
CNcomment:\brief \C9\E8\D6ù\A4\D7\F7\B3\A1\BE\B0\A1\A3CNend

\attention \n
Only the standby scenario is supported currently.\n
CNcomment:Ŀǰ\BD\F6֧\B3ֱ\EA׼\B4\FD\BB\FA\B3\A1\BE\B0\n CNend

\param[in] eScene  Standby scenario                               CNcomment:\B4\FD\BB\FA\B3\A1\BE\B0\A1\A3CNend
\retval HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT    The PMoC device is not started. CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The parameter is invalid.    CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetScene(HI_UNF_PMOC_SCENE_E eScene);

/**
\brief Sets the types of the devices related to standby such as front panel and IR remote control.
CNcomment:\brief \C9\E8\D6\C3Ŀǰǰ\C3\E6\B0\E5ͬ\BA\EC\CD\E2ң\BFصȴ\FD\BB\FA\CF\E0\B9\D8\C9豸\B5\C4\C0\E0\D0͡\A3CNend

\attention \n

\param[in] pdevType  Standby device that needs to be supported in standby       CNcomment:\B4\FD\BB\FAʱ\D0\E8Ҫ֧\B3ֵĴ\FD\BB\FA\C9豸\A1\A3CNend
\retval HI_SUCCESS  success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_STANDBY  It fails to set standby devices.     CNcomment:\C9\E8\D6û\BD\D0\D1\C9豸ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetDevType(HI_UNF_PMOC_DEV_TYPE_S_PTR pdevType);

/**
\brief when standby, GPIO pin control 12v and 5v power,relate to hardware.
CNcomment:\brief \D3\C3\D3ڴ\FD\BB\FAʱ,GPIO\B9ܽſ\D8\D6\C612V0\BA\CD5V0\B5\E7Դ\A3\AC\D3\EBӲ\BC\FE\CF\E0\B9ء\A3CNend

\attention \n
when standby, the outside power controled by STANDBY_PWROFF pin, the function can be ignored.\n
when some part of outside power controled by GPIO pin, use this function will decrease standby power.\n
CNcomment:\B4\FD\BB\FAʱ\CD\E2Χ\B5\E7Դȫ\B2\BF\D3ɹܽ\C5STANDBY_PWROFF\BF\D8\D6\C6ʱ\A3\AC\B2\BB\D3\C3\C0\ED\BB\E1\B8ýӿڣ\BB\n
\B5\B1\B2\BF\B7\D6\CD\E2Χ\B5\E7Դ\D3\C9GPIO\B9ܽ\C5ȥ\BF\D8\D6\C6ʱ,\BA\CF\C0\ED\B5\F7\D3øýӿ\DA\D3\C3\D3ڽ\B5\B5ʹ\FD\BB\FA\B9\A6\BAġ\A3CNend

\param[in] u32GpioNo  GPIO pin index, choose the fifth[40,47] CNcomment:GPIO\B9ܽ\C5\CB\F7\D2\FD\BA\C5,ȡ\B5\DA5\D7\E9Ϊ[40, 47] CNend
\param[in] bHighOrLow GPIO output control                     CNcomment:GPIO\B9ܽ\C5\CA\E4\B3\F6\BF\D8\D6\C6 CNend
\retval HI_SUCCESS  success                                                CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_STANDBY  It fails to set standby Gpio.        CNcomment:\C9\E8\D6ô\FD\BB\FAGpio\B9ܽ\C5ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_SetPwrOffGpio(HI_U32 u32GpioNo, HI_BOOL bHighOrLow);

/**
\brief Get the period during standby status.
CNcomment:\brief \BB\F1ȡ\B4Ӵ\FD\BB\FA\B5\BD\BB\BD\D0ѳ\D6\D0\F8\B5\C4ʱ\BC䡣CNend

\attention \n

\param[out] pu32Period  The period of standby. CNcomment:\B4\FD\BB\FA\B3\D6\D0\F8\B5\C4ʱ\BC\E4 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_GETPERIOD  It fails to get standby period.    CNcomment:\BB\F1ȡ\B4\FD\BB\FAʱ\BC\E4ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_GetStandbyPeriod(HI_U32 *pu32Period);


/**
\brief Switch to smart standby status.
CNcomment:\brief \BD\F8\C8\EB\D6\C7\C4ܴ\FD\BB\FA״̬\A1\A3CNend

\attention \n

\param[in] u32HoldModules  The modules working in smart standby .          CNcomment:\B4\FD\BB\FAʱ\B2\BB\CFµ\E7\B5\C4ģ\BF\E9 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_SUCCESS            Standby success.                           CNcomment:\B4\FD\BB\FA\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_EnterSmartStandby(HI_U32 u32HoldModules);

/**
\brief Quit smart standby status.
CNcomment:\brief \CD˳\F6\D6\C7\C4ܴ\FD\BB\FA״̬\A1\A3CNend

\attention \n

\param  N/A                                                                CNcomment:\CE\DE CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_SUCCESS            Quit standby success.                      CNcomment:\BB\BD\D0ѳɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_QuitSmartStandby(HI_VOID);

/**
\brief Get the Parameters of last wake up.
CNcomment:\brief \BB\F1ȡ\B4\A5\B7\A2\B4\FD\BB\FA\BB\BD\D0ѵĲ\CE\CA\FD\A1\A3CNend

\attention \n

\param[out] pstAttr  The Parameters of last waking up. CNcomment:\B4\A5\B7\A2\C9\CFһ\B4λ\BD\D0ѵĲ\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_GETWAKEUPMODE  It fails to get parameters of last waking up.    CNcomment:\BB\F1ȡ\BB\BD\D0Ѳ\CE\CA\FDʧ\B0\DC CNend
\retval ::HI_SUCCESS            Getting waking up parameters succeeded.            CNcomment:\BB\F1ȡ\BB\BD\D0Ѳ\CE\CA\FD\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PMOC_GetWakeUpMode(HI_UNF_PMOC_WAKEUP_MODE_S_PTR pstAttr);

/**
\brief Get the temperatures of the chip.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰоƬ\B5\C4\CE¶ȡ\A3CNend

\attention \n

\param[out] pstChipTemp  The temperatures of the chip sensors. CNcomment:\B5\B1ǰоƬ\D6д\AB\B8\D0\C6\F7\B5\C4\CE¶\C8 CNend
\retval ::HI_ERR_PMOC_NOT_INIT  The PMoC device is not started.            CNcomment:PMoC\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_PMOC_INVALID_POINT  The pointer is invalid.               CNcomment:\B7Ƿ\A8ָ\D5\EB CNend
\retval ::HI_ERR_PMOC_INVALID_PARA  The parameter is invalid.              CNcomment:\B7Ƿ\A8\B2\CE\CA\FD CNend
\retval ::HI_ERR_PMOC_FAILED_GETTEMPERATURE  It fails to get chip temp.    CNcomment:\BB\F1ȡоƬ\CE¶\C8ʧ\B0\DC CNend
\see \n
N/A
*/

HI_S32 HI_UNF_PMOC_GetChipTemp(HI_UNF_PMOC_CHIP_TEMP_S *pstChipTemp);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_PMOC_H__ */
