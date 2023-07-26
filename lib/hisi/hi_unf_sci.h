/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
******************************************************************************
 File Name     : hi_unf_sci.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
******************************************************************************/
#ifndef __HI_UNF_SCI_H__
#define __HI_UNF_SCI_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      SCI */
/** @{*/  /** <!-- [SCI] */

/**Output configuration of the smart card interface clock (SCICLK) pin*/
/** CNcomment:SCICLK\D2\FD\BD\C5\CA\E4\B3\F6\C5\E4\D6\C3*/
typedef enum  hiUNF_SCI_MODE_E
{
    HI_UNF_SCI_MODE_CMOS = 0, /**<Complementary metal-oxide semiconductor (CMOS) output*/   /**<CNcomment:CMOS\CA\E4\B3\F6*/
    HI_UNF_SCI_MODE_OD, /**<Open drain (OD) output*/                                  /**<CNcomment:OD\CA\E4\B3\F6*/
    HI_UNF_SCI_MODE_BUTT
} HI_UNF_SCI_MODE_E;

/**SCI port*/
/** CNcomment:SCI \B6˿\DA */
typedef enum hiUNF_SCI_PORT_E
{
    HI_UNF_SCI_PORT0, /**< SCI port 0*/  /**<CNcomment:SCI\B6˿\DA0*/
    HI_UNF_SCI_PORT1, /**< SCI port 1*/  /**<CNcomment:SCI\B6˿\DA1*/
    HI_UNF_SCI_PORT_BUTT
} HI_UNF_SCI_PORT_E;

/**Status of the SCI card*/
/** CNcomment:\D6\C7\C4ܿ\A8״̬ */
typedef enum hiUNF_SCI_STATUS_E
{
    HI_UNF_SCI_STATUS_UNINIT = 0, /**<The SCI card is not initialized.(Reserved status) */               /**<CNcomment: SCIδ\B3\F5ʼ\BB\AF\A1\A3(Ԥ\C1\F4״̬) */
    HI_UNF_SCI_STATUS_FIRSTINIT, /**<The SCI card is being initialized.(Reserved status)*/             /**<CNcomment:SCI\B3\F5ʼ\BB\AF\B9\FD\B3\CC\D6С\A3(Ԥ\C1\F4״̬)*/
    HI_UNF_SCI_STATUS_NOCARD, /**<There is no SCI card.*/                          /**<CNcomment:\CE޿\A8 */
    HI_UNF_SCI_STATUS_INACTIVECARD, /**<The SCI card is not activated (unavailable).*/   /**<CNcomment:\BF\A8δ\CD\EA\B3ɼ\A4\BB\BF\A8\CE\DEЧ\A3\A9 */

    //   HI_UNF_SCI_STATUS_CARDFAULT, /**<The SCI card is faulty.*/                        /**<CNcomment:\BF\A8\B9\CA\D5\CF*/
    HI_UNF_SCI_STATUS_WAITATR, /**<The SCI card is waiting for the ATR data.*/      /**<CNcomment:\B5ȴ\FDATR*/
    HI_UNF_SCI_STATUS_READATR, /**<The SCI card is receiving the ATR data.*/        /**<CNcomment:\D5\FD\D4ڽ\D3\CA\D5ATR*/
    HI_UNF_SCI_STATUS_ATR_ERROR, /**<The ATR is wrong.*/                        /**<CNcomment:ATR\B4\ED\CE\F3*/
    HI_UNF_SCI_STATUS_READY, /**<The SCI card is available (activated).*/         /**<CNcomment:\BF\A8\BF\C9\D2\D4ʹ\D3ã\A8\BF\A8\BC\A4\BB */
    HI_UNF_SCI_STATUS_RX, /**<The SCI card is busy receiving data.*/           /**<CNcomment:\BF\A8æ\A3\A8\BD\D3\CA\D5\CA\FD\BE\DD\D6У\A9 */
    HI_UNF_SCI_STATUS_TX /**<The SCI card is busy transmitting data.*/        /**<CNcomment:\BF\A8æ\A3\A8\B7\A2\CB\CD\CA\FD\BE\DD\D6У\A9 */
} HI_UNF_SCI_STATUS_E;

/**SCI protocol*/
/** CNcomment:SCI Э\D2\E9 */
typedef enum hiUNF_SCI_PROTOCOL_E
{
    HI_UNF_SCI_PROTOCOL_T0, /**<7816 T0 protocol*/   /**<CNcomment:7816 T0 Э\D2\E9 */
    HI_UNF_SCI_PROTOCOL_T1, /**<7816 T1 protocol*/   /**<CNcomment:7816 T1 Э\D2\E9 */
    HI_UNF_SCI_PROTOCOL_T14, /**<7816 T14 protocol*/  /**<CNcomment:7816 T14 Э\D2\E9 */
    HI_UNF_SCI_PROTOCOL_BUTT
} HI_UNF_SCI_PROTOCOL_E;

/**SCI active level*/
/** CNcomment:SCI\D3\D0Ч\B5\E7ƽ*/
typedef enum hiUNF_SCI_LEVEL_E
{
    HI_UNF_SCI_LEVEL_LOW, /**<Active low*/   /**<CNcomment:\B5͵\E7ƽ\D3\D0Ч */
    HI_UNF_SCI_LEVEL_HIGH, /**<Active high*/  /**<CNcomment:\B8ߵ\E7ƽ\D3\D0Ч */
    HI_UNF_SCI_LEVEL_BUTT
} HI_UNF_SCI_LEVEL_E;

/** Secure mode type*/
/**CNcomment:\B0\B2ȫģʽ\C0\E0\D0\CD*/
typedef enum hiUNF_SCI_SECURE_MODE_E
{
    HI_UNF_SCI_SECURE_MODE_NONE = 0,        /** <no security protection*/ /**<CNcomment:\CEް\B2ȫ\B1\A3\BB\A4*/
    HI_UNF_SCI_SECURE_MODE_TEE,             /** <trustedzone security protection*/ /**<CNcomment:trustedzone\B0\B2ȫ\B1\A3\BB\A4*/

    HI_UNF_SCI_SECURE_MODE_BUTT
} HI_UNF_SCI_SECURE_MODE_E;

/**SCI system parameters*/
/**CNcomment:SCI ϵͳ\B2\CE\CA\FD */
typedef struct hiUNF_SCI_PARAMS_S
{
    HI_UNF_SCI_PORT_E     enSciPort; /**<SCI port ID*/                                                      /**<CNcomment:SCI \B6˿ں\C5 */
    HI_UNF_SCI_PROTOCOL_E enProtocolType; /**<Used protocol type*/                                    /**<CNcomment:ʹ\D3õ\C4Э\D2\E9\C0\E0\D0\CD */
    HI_U32                ActalClkRate; /**<Actual clock rate conversion factor F*/                     /**<CNcomment:ʵ\BCʵ\C4F ֵʱ\D6\D3ת\BB\BB\D2\F2\D7\D3 */
    HI_U32                ActalBitRate; /**<Actual bit rate conversion factor D*/                         /**<CNcomment:ʵ\BCʵ\C4D ֵ\B1\C8\CC\D8\C2\CAת\BB\BB\D2\F2\D7\D3 */
    HI_U32                Fi; /**<Clock factor returned by the answer to reset (ATR)*/                      /**<CNcomment:ATR \B7\B5\BBص\C4ʱ\D6\D3\D2\F2\D7\D3 */
    HI_U32                Di; /**<Bit rate factor returned by the ATR*/                                     /**<CNcomment:ATR \B7\B5\BBصı\C8\CC\D8\C2\CA\D2\F2\D7\D3 */
    HI_U32                GuardDelay; /**<Extra guard time N*/                                        /**<CNcomment:N ֵ\B6\EE\CD\E2\D4\F6\BCӵı\A3\BB\A4ʱ\BC\E4*/
    HI_U32                CharTimeouts; /**<Character timeout of T0 or T1*/                             /**<CNcomment:T0 \BB\F2T1\B5\C4\D7ַ\FB\B3\ACʱʱ\BC\E4*/
    HI_U32                BlockTimeouts; /**<Block timeout of T1 */                                     /**<CNcomment:T1\B5Ŀ鳬ʱʱ\BC\E4*/
    HI_U32                TxRetries; /**<Number of transmission retries*/                                   /**<CNcomment:\B7\A2\CB\CD\D6\D8\CAԴ\CE\CA\FD*/
} HI_UNF_SCI_PARAMS_S, *HI_UNF_SCI_PARAMS_S_PTR;

/** @}*/  /** <!-- ==== Structure Definition End ====*/




/******************************* API Declaration *****************************/
/** \addtogroup      SCI*/
/** @{*/  /** <!-- [SCI] */

/**
 \brief Initializes the SCI.   CNcomment:SCI\B3\F5ʼ\BB\AF\A1\A3CNend
 \attention \n
 \param  N/A                   CNcomment:\CEޡ\A3CNend
 \retval 0 Success             CNcomment:\B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_Init(HI_VOID);

/**
 \brief Deinitializes the SCI. CNcomment:SCIȥ\B3\F5ʼ\BB\AF\A1\A3CNend
 \attention \n
 \param  N/A                   CNcomment:\CEޡ\A3CNend
 \retval 0 Success             CNcomment:0 \B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_DeInit(HI_VOID);

/**
 \brief Set the SCI SecurityMod.              CNcomment:SCI\C9\E8\D6ð\B2ȫģʽ\A1\A3CNend
 \attention \n
 \param[in]  SecurityMode        System mode  CNcomment:\B0\B2ȫģʽģʽ\C0\E0\D0\CD
 \retval 0 Success               CNcomment:0 \B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetSecurityMode(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_SECURE_MODE_E SecurityMode);

/**
 \brief Starts an SCI device to initialize it based on the input port and protocol. If there is an SCI card, the card is also initialized.\n
CNcomment:\B4\F2\BF\AASCI\A3\A8Smart Card Interface\A3\A9\C9豸\A3\AC\D5\EB\B6\D4\CA\E4\C8\EB\B5Ķ˿ں\CDЭ\D2飬\BD\F8\D0\D0SCI\BDӿ\DA\C9豸\B5ĳ\F5ʼ\BB\AF\A3\BB\C8\E7\B9\FB\BF\A8\B4\E6\D4ڣ\AC\D4\F2ͬʱ\B6Կ\A8\BD\F8\D0г\F5ʼ\BB\AF\A1\A3CNend
\attention \n
After an SCI device is started, it is initialized based on the default configuration.\n
If you modify the configuration, you need to call HI_UNF_SCI_ResetCard for the modifications to take effect.\n
If you remove and then insert the SCI card, you need to call HI_UNF_SCI_ResetCard to reset the card.\n
You need to set frequency parameters when enabling an SCI device. The actual SCI clock provided by the chip is obtained by using the clock divider.\n
The clock divider is calculated based on the externally transferred clock frequency parameters. The fractional part of the clock divider is discarded during calculation. \n
Therefore, an enhanced error occurs when the SCI clock is obtained by dividing the system clock by the clock divider. You need to set the actual output frequency of \n
the SCI card based on the close output frequency. The SCI clock is calculated as follows: Fsci_clk = Frefclk/[(Clkicc + 1) x 2]. Where, Frefclk is the 96 MHz system clock, \n
Fsci_clk is the SCI clock required by peripherals, and clkicc is the required clock divider of registers. clkicc is calculated as follows: Clkicc = Frefclk/(2 x Fsci_clk) - 1. \n
The clkicc may be a floating point value, but only the integral part is used. Therefore, the configured frequency is different from the actual frequency.\n

CNcomment: \B4򿪺\F3SCI\C9豸\B2\C9\D3\C3Ĭ\C8\CF\C5\E4\D6ö\D4\C9豸\BD\F8\D0г\F5ʼ\BB\AF\A1\A3\n 
+\BA\F3\C8\E7\B9\FB\B8\FC\B8\C4\C1\CB\C5\E4\D6ã\AC\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\C0\B4ʹ\C5\E4\D6\C3\C9\FAЧ\A1\A3\n 
+\BA\F3\C8\E7\B9\FB\B6Կ\A8\BD\F8\D0аβ壬\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\C0\B4\BD\F8\D0и\B4λ\A1\A3\n 
\B4\F2\BF\AA\C9豸\B5\C4ʱ\BA\F2\D0\E8Ҫ\C9\E8\D6\C3Ƶ\C2ʲ\CE\CA\FD\A3\AC\B6\F8оƬʵ\BCʸ\F8SCI \B5\C4ʱ\D6\D3\CA\C7\D3\C9\CDⲿ\B4\AB\C8\EB\B5\C4 \n
ʱ\D6\D3Ƶ\C2ʲ\CE\CA\FD\BC\C6\CB\E3\B5ķ\D6Ƶ\D2\F2\D7ӷ\D6Ƶ\B5\C3\C0\B4\A3\AC\D2\F2Ϊ\BC\C6\CB㹫ʽ\BB\E1\C9\E1\C6\FA\BC\C6\CB\E3\B5ķ\D6Ƶ\D2\F2\D7ӵ\C4С\CA\FD\B2\BF\B7֣\AC\n
\CB\F9\D2\D4ͨ\B9\FDϵͳʱ\D6ӷ\D6Ƶ֮\BA\F3\B8\F8\BF\A8\B5\C4ʱ\D6ӻ\E1\B4\E6\D4\DA\D4\F6\C1\BF\CE\F3\B2ʵ\BC\CA\C5\E4\D6ÿ\BC\C2\C7\D3\EB\D0\E8\C7\F3\D7\EE\BDӽ\FC\B5\C4ֵ\C0\B4 \n
\C9\E8\D6ú\CDȨ\BA⣬\BE\DF\CC\E5\CB㷨 Fsci_clk = Frefclk/[(Clkicc + 1) x 2];\C6\E4\D6\D0Frefclk\CA\C7ϵͳ96Mʱ\D6ӣ\ACFsci_clk\CA\C7\CDⲿ\D0\E8Ҫ\C9\E8\D6õ\C4 \n
sciʱ\D6\D3,ʵ\BC\CAҪ\C5\E4\C8\EB\BCĴ\E6\C6\F7\B7\D6Ƶ\D2\F2\D7\D3Clkicc = Frefclk/(2 x Fsci_clk) - 1;clkicc \D3\D0ʱ\BA\F2\BC\C6\CB\E3\B3\F6\C0\B4\CAǸ\A1\B5\E3\CA\FD\A3\AC\B5\ABֻȡ\D5\FB\A3\AC\n
\CB\F9\D2\D4\C9\E8\D6õ\C4Ƶ\C2\CA\D3\EBʵ\BC\CAƵ\C2\CA\D3\D0ƫ\B2CNend

 \param[in] enSciPort     ID of an SCI port. The port ID can be 0 or 1.  CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enSciProtocol Protocol type.                                  CNcomment:Э\D2\E9\C0\E0\D0͡\A3CNend
 \param[in] u32Frequency    Frequency of the SCI card to be set, in kHz. For the T0 and T1 cards, the frequency ranges from 1 MHz to 5 MHz; for the T14 card, the frequency must be set to 6 MHz.  CNcomment:Ҫ\C9\E8\D6õ\C4SCI\BF\A8Ƶ\C2ʡ\A3\B6\D4\D3\DAT0\A3\ACT1\BF\A8\A3\AC֧\B3\D6Ƶ\C2\CA1MHz\A1\AB5MHz\A3\BB\B6\D4\D3\DAT14\BF\A8\A3\AC6MHz\B2\C5\C4\DCͨ\D0ųɹ\A6\A1\A3\B5\A5λΪkhz\A1\A3CNend
 \retval 0 Success.                                                       CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  SCI  No SCI device is started.           CNcomment:\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.            CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_Open(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PROTOCOL_E enSciProtocol, HI_U32 u32Frequency);

/**
 \brief Stops an SCI device.
CNcomment:\B9ر\D5SCI\C9豸\A1\A3CNend

 \attention \n
This API cannot be called repeatedly.
CNcomment:\D6ظ\B4\B9رջ᷵\BBسɹ\A6\A1\A3CNend

 \param[in] enSciPort     ID of an SCI port. The port ID can be 0 or 1.  CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \retval 0 Success.                                                       CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.               CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.            CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_Close(HI_UNF_SCI_PORT_E enSciPort);

/**
 \brief Performs a warm reset on an SCI card.
CNcomment:\B8\B4λSCI\BF\A8\A1\A3CNend

 \attention \n
If no SCI card is inserted, the reset fails.\n
If you modify the configuration of an SCI device, you need to call HI_S32 HI_UNF_SCI_ResetCard for the modifications to take effect.\n
In addition, if you remove and insert an SCI card after calling HI_UNF_SCI_Open, you also need to call HI_S32 HI_UNF_SCI_ResetCard to reset the card.
CNcomment:û\D3в\E5\C8뿨\A3\AC\B8\B4λ\BB\E1ʧ\B0ܡ\A3\n
\B5\B1\B8\FC\B8\C4\C1\CBSCI\C9豸\B5\C4\C5\E4\D6ú\F3\A3\AC\D0\E8Ҫ\B5\F7\D3øýӿ\DAʹ\C5\E4\D6\C3\C9\FAЧ\A1\A3\n
\D4ڵ\F7\D3ô\F2\BF\AASCI\C9豸\BDӿں󣬶Կ\A8\BD\F8\D0аβ壬Ҳ\D0\E8Ҫ\B5\F7\D3øýӿڽ\F8\D0и\B4λ\A1\A3CNend

 \param[in] enSciPort   ID of an SCI port. The port ID can be 0 or 1                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] bWarmResetValid   Reset mode.  HI_TRUE: warm reset; HI_FALSE: cold reset (recommended)    			 CNcomment:\B8\B4λ\B7\BDʽ\A1\A3HI_TRUE: \C8ȸ\B4λ; HI_FALSE: \C0临λ\A3\A8\CDƼ\F6\D3\C3\D5\E2\D6ַ\BDʽ\A3\A9\A1\A3CNend
 \retval 0 Success.                                                                                              CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ResetCard(HI_UNF_SCI_PORT_E enSciPort, HI_BOOL bWarmResetValid);

/**
 \brief Deactivates an SCI card.
CNcomment:ȥ\BC\A4\BB\EESCI\BF\A8\A1\A3CNend

 \attention \n
After an SCI card is deactivated, the card cannot be read or written until it is reset.
CNcomment:ȥ\BC\A4\BB\BA\F3\A3\AC\CE޷\A8\B6\C1д\CA\FD\BEݡ\A3ֻ\D3\D0\D6\D8\D0¸\B4λ\BF\A8\BA󣬲\C5\C4ܼ\CC\D0\F8\B6\C1д\A1\A3CNend

 \param[in] enSciPort ID of an SCI port. The port ID can be 0 or 1.         CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \retval 0   Success.                                                        CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT No SCI device is started.                    CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.               CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_DeactiveCard(HI_UNF_SCI_PORT_E enSciPort);

/**
 \brief Obtains the ATR data of an SCI card.
CNcomment:\BB\F1ȡSCI\BF\A8ATR\CA\FD\BEݡ\A3CNend

 \attention \n
N/A
 \param[in]  enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[out]  pu8AtrBuf   Address for storing the obtained ATR data.                                               CNcomment:\BB\F1ȡ\B5\C4ATR\CA\FD\BEݵĴ洢\B5\D8ַ\A1\A3CNend
 \param[in]  u32AtrBufSize  Length of the ATR data read from the buffer.                                          CNcomment:ATR \CA\FD\BEݶ\C1ȡ buffer \B3\A4\B6ȡ\A3CNend
 \param[out]  pu8AtrRcvCount Actual number of ATR data segments.                                                   CNcomment:ʵ\BCʻ\F1ȡ\B5\C4ATR\CA\FD\BEݸ\F6\CA\FD\A1\A3CNend
 \retval 0   Success.                                                                                             CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR The pointer is invalid.                                                      	  CNcomment: \B7Ƿ\A8ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                     CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_NO_ATR  There is no ATR data.                                                               CNcomment:\CE\DEATR\CA\FD\BEݡ\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			  				  CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_GetATR(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pu8AtrBuf, HI_U32 u32AtrBufSize, HI_U8 *pu8AtrRcvCount);

/**
 \brief Obtains the status of an SCI card.
CNcomment:\BB\F1ȡSCI\BF\A8״̬\A1\A3CNend

 \attention \n
This API is a non-block API. You can transfer data to an SCI card by calling HI_UNF_SCI_Send or HI_UNF_SCI_Receive only when the card status is HI_UNF_SCI_STATUS_READY.\n
CNcomment:\B4˽ӿ\DA\CA\C7\CE\DE\D7\E8\C8\FB\BA\AF\CA\FD\A3\AC\D4ڿ\A8\B5\C4״̬ΪHI_UNF_SCI_STATUS_READYʱ\A3\AC\B2ſɵ\F7\D3\C3HI_UNF_SCI_Send\BB\F2HI_UNF_SCI_Receive\BDӿ\DA\D3뿨\BD\F8\D0\D0\CA\FD\BEݽ\BB\BB\A5\A1\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[out] penSCIStatus  Status of an SCI card.                                                                CNcomment: SCI\BF\A8״̬\A1\A3CNend
 \retval 0 Success.                                                                                              CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR The pointer is invalid.                                                      	 CNcomment:\B7Ƿ\A8ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_GetCardStatus(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_STATUS_E *penSciStatus);

/**
 \brief Transmits data to an SCI card.
CNcomment:\CF\F2SCI\BF\A8\B7\A2\CB\CD\CA\FD\BEݡ\A3CNend

 \attention \n
Data must be transmitted based on application protocols.\n
Data cannot be transmitted consecutively.\n
In addition, data is transmitted and received in block mode. Therefore, when a large number of data is being transmitted, the transmission may fail if the timeout is too small.\n
CNcomment:\B7\A2\CB\CD\CA\FD\BE\DD\D0\E8Ҫ\B0\B4\D5\D5Ӧ\D3\C3Э\D2\E9\C0\B4\B7\A2\CB\CD \n
\B2\BB\C4\DC\C1\AC\D0\F8\C1\BD\B4η\A2\CBͶ\F8\D6м䲻\BD\D3\CA\D5\CA\FD\BE\DD \n
\B7\A2\CBͶ\C1ȡ\B6\BC\CA\C7\D7\E8\C8\FB\B5ģ\AC\D2\F2\B4˷\A2\CBʹ\F3\C1\BF\B5\C4\CA\FD\BE\DDʱ\A3\AC\CAܵ\BD\B3\ACʱʱ\BC\E4\B5\C4\CF\DE\D6ƣ\AC\C8\E7\B9\FB\B3\ACʱֵ\B1Ƚ϶̣\AC\D3п\C9\C4ܷ\A2\CB\CDʧ\B0ܡ\A3CNend

 \param[in] enSciPort   ID of an SCI port. The port ID can be 0 or 1.                                            CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in]  pSciSendBuf Address for storing the data to be transmitted.                                          CNcomment:\B7\A2\CB\CD\CA\FD\BEݵĴ洢\B5\D8ַ\A1\A3CNend
 \param[in] u32SendLen  Number of data segments (in byte) to be transmitted.                                      CNcomment:\B7\A2\CB\CD\CA\FD\BEݵĸ\F6\CA\FD,\B5\A5λΪ BYTE\A1\A3CNend
 \param[out]  pu32ActLen Number of transmitted data segments (in byte).                                            CNcomment:ʵ\BCʷ\A2\CB\CD\CA\FD\BEݸ\F6\CA\FD,\B5\A5λΪ BYTE\A1\A3CNend
 \param[in] u32TimeoutMs Wait timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block.                        CNcomment:\B5ȴ\FD\B3\ACʱֵ, \B5\A5λ\CAǺ\C1\C3\EB, 0 - \B2\BB\D7\E8\C8\FB, 0xFFFFFFFF-\D3\C0\BE\C3\D7\E8\C8\FB\A1\A3CNend
 \retval 0 Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  SCI  No SCI device is started.                                                   CNcomment:\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR  The pointer is invalid.                                                     	 CNcomment:\B7Ƿ\A8ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                                     CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_SEND_ERR  The transmission operation fails.                                             	CNcomment: \B7\A2\CBͲ\D9\D7\F7ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_Send(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciSendBuf, HI_U32 u32SendLen, HI_U32 *pu32ActLen,
                       HI_U32 u32TimeoutMs);

/**
 \brief Receives data from an SCI card.
CNcomment:\B4\D3SCI\BF\A8\BD\D3\CA\D5\CA\FD\BEݡ\A3CNend

 \attention \n
You must set the data length obtained by each upper-layer application based on the protocol. If the length of the obtained data is greater than that of the returned data, this API is returned after timeout occurs.\n
CNcomment:\C9ϲ\E3Ӧ\D3ó\CC\D0\F2\B1\D8\D0\EB\B8\F9\BE\DDЭ\D2\E9\C0\B4\C5\E4\D6\C3\CB\F9\BB\F1ȡ\B5ĳ\A4\B6ȣ\AC\C8\E7\B9\FBϣ\CD\FB\BB\F1ȡ\B5ĳ\A4\B6ȳ\AC\B3\F6ʵ\BC\CA\C4ܹ\BB\B7\B5\BBصĳ\A4\B6ȣ\AC\D4\F2ֻ\C4ܵȵ\BD\B3\ACʱ\B5\BD\C6ڲ\C5\C4ܷ\B5\BBء\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[out]  pSciReceiveBuf   Address for storing the received data.                                              CNcomment:\BD\D3\CA\D5\CA\FD\BEݵĴ洢\B5\D8ַ\A1\A3CNend
 \param[in] u32ReceiveLen  Number of data segments (in byte) to be received.                                      CNcomment:\C6\DA\CD\FB\BD\D3\CA\D5\CA\FD\BEݵĸ\F6\CA\FD,\B5\A5λΪ BYTE\A1\A3CNend
 \param[out]  pu32ActLen   Number of received data segments (in byte).                                             CNcomment:ʵ\BCʽ\D3\CA\D5\CA\FD\BEݸ\F6\CA\FD,\B5\A5λΪ BYTE\A1\A3CNend
 \param[in] u32TimeOutMs  Wait timeout (in ms). 0: not blocked; 0xFFFFFFFF: infinite block.                       CNcomment:\B5ȴ\FD\B3\ACʱֵ, \B5\A5λ\CAǺ\C1\C3\EB, 0 - \B2\BB\D7\E8\C8\FB, 0xFFFFFFFF-\D3\C0\BE\C3\D7\E8\C8\FB\A1\A3CNend
 \retval 0 Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                       CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR  The pointer is invalid.                                                     	 CNcomment: \B7Ƿ\A8ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_RECEIVE_ERR  The reception operation fails.                                             	CNcomment:\BD\D3\CAղ\D9\D7\F7ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_Receive(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciReceiveBuf, HI_U32 u32ReceiveLen, HI_U32 *pu32ActLen,
                          HI_U32 u32TimeOutMs);

/**
 \brief Sets the active level of the VCCEN signal.
CNcomment:\C5\E4\D6\C3VCCEN\D0ź\C5\CFߵ\C4\D3\D0Ч\B5\E7ƽ\A1\A3CNend
 \attention \n
The active level needs to be set based on the circuits of hardware, and the low level is active by default.\n
After changing the active level, you need to call HI_UNF_SCI_ResetCard for the modification take effect.\n
CNcomment:\D0\E8Ҫ\B8\F9\BE\DDӲ\BC\FE\B5\E7·\BD\F8\D0\D0\C5\E4\D6ã\ACĬ\C8\CFΪ\B5͵\E7ƽ\D3\D0Ч\A3\AC\B8\FC\B8Ĵ\CB\CF\EE\C5\E4\D6ú\F3\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\B2\C5\C4\DCʹ\D0µ\C4\C5\E4\D6\C3\D3\D0Ч\A1\A3CNend

 \param[in] enSciPort ID of an SCI port. The port ID can be 0 or 1.                                              CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enSciVcc  Active level of a signal. HI_FALSE: active low; HI_TRUE: active high  Active level of a signal. HI_FALSE: active low; HI_TRUE: active high.  CNcomment:\D0ź\C5\CFߵ\C4\D3\D0Ч\B5\E7ƽ\A1\A3HI_FALSE\A3\BA\B5͵\E7ƽ\D3\D0Ч\A3\ACHI_TRUE\A3\BA\B8ߵ\E7ƽ\D3\D0Ч\A1\A3CNend
 \retval 0   Success.                                                                                             CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                                       CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ConfigVccEn(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_LEVEL_E enSciVcc);

/**
 \brief Sets the active level of the DETECT signal.
CNcomment:\C5\E4\D6\C3DETECT\D0ź\C5\CFߵ\C4\D3\D0Ч\B5\E7ƽ\A1\A3CNend

 \attention \n
The active level needs to be set based on the circuits of hardware, and the high level is active by default.\n
After changing the active level, you need to call HI_UNF_SCI_ResetCard for the modification take effect.\n
CNcomment:\D0\E8Ҫ\B8\F9\BE\DDӲ\BC\FE\B5\E7·\BD\F8\D0\D0\C9\E8\D6ã\ACĬ\C8\CFΪ\B8ߵ\E7ƽ\D3\D0Ч\A3\AC\B8\FC\B8Ĵ\CB\CF\EE\C5\E4\D6ú\F3\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\B2\C5\C4\DCʹ\D0µ\C4\C5\E4\D6\C3\D3\D0Ч\A1\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enSciDetect Active level of a signal. HI_FALSE: active low; HI_TRUE: active high.                     CNcomment:\D0ź\C5\CFߵ\C4\D3\D0Ч\B5\E7ƽ\A1\A3HI_FALSE\A3\BA\B5͵\E7ƽ\D3\D0Ч\A3\ACHI_TRUE\A3\BA\B8ߵ\E7ƽ\D3\D0Ч\A1\A3CNend
 \retval 0  Success.                                                                                              CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ConfigDetect(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_LEVEL_E enSciDetect);

/**
 \brief Sets the mode of a clock signal.
CNcomment:\C9\E8\D6\C3ʱ\D6\D3\CFߵ\C4ģʽ\A1\A3CNend
 \attention \n
The mode needs to be set based on the circuits of hardware, and the OD mode is selected by default.\n
After changing the mode, you need to call HI_UNF_SCI_ResetCard for the modification take effect.\n
CNcomment:\D0\E8Ҫ\B8\F9\BE\DDӲ\BC\FE\B5\E7·\BD\F8\D0\D0\C9\E8\D6ã\ACĬ\C8\CFΪODģʽ\A3\AC\B8\FC\B8Ĵ\CB\CF\EE\C5\E4\D6ú\F3\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\B2\C5\C4\DCʹ\D0µ\C4\C5\E4\D6\C3\D3\D0Ч\A1\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enClkMode  Mode of a clock signal.                                                                    CNcomment:ʱ\D6\D3\CFߵ\C4ģʽ\A1\A3CNend
 \retval 0 Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                            			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ConfigClkMode(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_MODE_E enClkMode);

/**
 \brief Sets the mode of a clock signal.
CNcomment:\C9\E8\D6\C3RESET\CFߵ\C4ģʽ\A1\A3CNend
 \attention \n
The mode needs to be set based on the circuits of hardware, and the OD mode is selected by default.\n
After changing the mode, you need to call HI_UNF_SCI_ResetCard for the modification take effect.\n
CNcomment:\D0\E8Ҫ\B8\F9\BE\DDӲ\BC\FE\B5\E7·\BD\F8\D0\D0\C9\E8\D6ã\ACĬ\C8\CFΪODģʽ\A3\AC\B8\FC\B8Ĵ\CB\CF\EE\C5\E4\D6ú\F3\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\B2\C5\C4\DCʹ\D0µ\C4\C5\E4\D6\C3\D3\D0Ч\A1\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enClkMode  Mode of a reset signal.                                                                    CNcomment:ʱ\D6\D3\CFߵ\C4ģʽ\A1\A3CNend
 \retval 0 Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                            			                 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NOTSUPPORT	Current chipset not support config RESET output type.                        CNcomment:\B5\B1ǰоƬ\B2\BB֧\B3\D6\C5\E4\D6\C3RESET\CA\E4\B3\F6\C0\E0\D0͡\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ConfigResetMode(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_MODE_E enResetMode);

/**
 \brief Sets the mode of a clock signal.
CNcomment:\C9\E8\D6\C3POWEREN\CFߵ\C4ģʽ\A1\A3CNend
 \attention \n
The mode needs to be set based on the circuits of hardware, and the OD mode is selected by default.\n
After changing the mode, you need to call HI_UNF_SCI_ResetCard for the modification take effect.\n
CNcomment:\D0\E8Ҫ\B8\F9\BE\DDӲ\BC\FE\B5\E7·\BD\F8\D0\D0\C9\E8\D6ã\ACĬ\C8\CFΪODģʽ\A3\AC\B8\FC\B8Ĵ\CB\CF\EE\C5\E4\D6ú\F3\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\B2\C5\C4\DCʹ\D0µ\C4\C5\E4\D6\C3\D3\D0Ч\A1\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enClkMode  Mode of a poweren signal.                                                                    CNcomment:ʱ\D6\D3\CFߵ\C4ģʽ\A1\A3CNend
 \retval 0 Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                            			                 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NOTSUPPORT	Current chipset not support config POWEREN output type.                      CNcomment:\B5\B1ǰоƬ\B2\BB֧\B3\D6\C5\E4\D6\C3POWEREN\CA\E4\B3\F6\C0\E0\D0͡\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_ConfigVccEnMode(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_MODE_E enVccEnMode);


/**
 \brief Changes the card slot.
CNcomment:\C7л\BB\BF\A8\B2ۡ\A3CNend

 \attention \n
When you call HI_UNF_SCI_Open, the primary card is used by default, that is, port 0 is used.\n
After you switch to a new SCI device, all the preceding SCI APIs are called to operate the new SCI device.\n
In addition, after a new SCI device is switched, the device is initialized based on the default configuration.\n
If any modifications are made, you need to call HI_UNF_SCI_ResetCard for the modifications to take effect.\n
If the SCI port to be switched to is the same as the current active port, an error code is returned.\n
CNcomment:\B5\F7\D3\C3HI_UNF_SCI_Openʱ\A3\ACĬ\C8ϴ򿪵\C4Ϊ\D6\F7\BF\A8\A3\AC\BC\B4\B6˿\DA0\A1\A3\n
\C7л\BB\B5\BD\D0µ\C4SCI\C9豸\BA\F3\A3\AC\C9\CF\CA\F6\CB\F9\D3\D0SCI\BDӿڼ\B4\B6\D4\D0µ\C4SCI\C9豸\BD\F8\D0в\D9\D7\F7\A1\A3\n
\C7л\BB\B5\BD\D0µ\C4SCI\C9豸\B2\C9\D3\C3Ĭ\C8\CF\C5\E4\D6ö\D4\C9豸\BD\F8\D0г\F5ʼ\BB\AF\A1\A3\n
+\BA\F3\C8\E7\B9\FB\B8\FC\B8\C4\C1\CB\C5\E4\D6ã\AC\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_SCI_ResetCard\C0\B4ʹ\C5\E4\D6\C3\C9\FAЧ\A1\A3\n
ϣ\CD\FB\C7л\BB\B5\BD\B5\C4SCI\B6˿\DA\D3뵱ǰ\D3\D0Ч\B6˿\DA\CF\E0ͬʱ\A3\AC\BB᷵\BB\D8ʧ\B0ܡ\A3CNend

 \param[in] enSciPort  ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param[in] enSciProtocol  Protocol type.                                                                         CNcomment:Э\D2\E9\C0\E0\D0͡\A3CNend
 \param[in] u32Frequency Frequency of the SCI card to be set, in kHz. For the T0 and T1 cards, the frequency ranges from 1 MHz to 5 MHz; for the T14 card, the frequency must be set to 6 MHz. CNcomment:Ҫ\C9\E8\D6õ\C4SCI\BF\A8Ƶ\C2ʡ\A3\B6\D4\D3\DAT0\A3\ACT1\BF\A8\A3\AC֧\B3\D6Ƶ\C2\CA1MHz~5MHz\A3\BB\B6\D4\D3\DAT14\BF\A8\A3\ACֻ֧\B3\D66MHz\A1\A3\B5\A5λΪkHz\A1\A3CNend
 \retval 0  Success.                                                                                              CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                        CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR The pointer is invalid.                                                      	 CNcomment:\B7Ƿ\A8ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                                    CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			 CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SwitchCard(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PROTOCOL_E enSciProtocol, HI_U32 u32Frequency);

/**
 \brief Sets the clock rate factor (in ETU) and baud rate regulator factor for special cards.
CNcomment:\B6\D4\CC\D8\CA⿨\D0\E8Ҫ\C9\E8\D6\C3ָ\B6\A8etu ʱ\D6\D3\C2\CA\D2\F2\D7ӣ\AC\B2\A8\CC\D8\C2ʵ\F7\BD\DA\D2\F2\D7ӡ\A3CNend

 \attention \n
This API needs to be called only for special cards.
The configured values must match the clock rate conversion factor F and bit rate regulator factor D defined in the protocol.
You can also set the factors to the values defined in the card specifications. Note that the values must be set correctly.
CNcomment:ֻ\D3\D0\CC\D8\D0\E8Ҫ\C7\F3\B5Ŀ\A8\D0\E8Ҫ\C9\E8\D6ã\AC\C6\D5ͨ\BF\A8\B2\BB\D0\E8Ҫ\B5\F7\D3ô˽ӿ\DA\C9\E8\D6ã\AC
\C9\E8\D6õ\C4ֵҪ\D3\EBЭ\D2\E9\D6й涨\B5\C4Fʱ\D6\D3ת\C2\CAת\BB\BB\D2\F2\D7ӡ\A2D\B1\C8\CC\D8\C2ʵ\F7\BD\DA\D2\F2\D7Ӽ\E6\C8ݣ\AC
\BB\F2\D5\DF\C9\E8\D6\C3Ϊ\BF\A8\B9淶\D6й涨\B5\C4ֵ\A3\AC\B2\BB\BF\C9\CB\E6\D2\E2\C9\E8\D6á\A3CNend

 \param [in] 	enSciPort	ID of an SCI port. The port ID can be 0 or 1.                                             CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	u32ClkFactor  Clock rate conversion factor, ranging from 372 to 2048. For details, see the factor F and card features in the protocol.	CNcomment:ʱ\D6\D3ת\C2\CA\D2\F2\D7\D3372\A1\AB2048 \A3\AC\BE\DF\CC\E5\C9\E8\D6òο\BCЭ\D2\E9\B5\C4F\D2\F2\D7ӺͿ\A8\CC\D8\D0ԡ\A3CNend
 \param [in] 	u32BaudFactor	Baud rate regulator factor 1, 2 x n (n = 1-16). For details, see the factor D and card features in the protocol. CNcomment:\B2\A8\CC\D8\C2\CAУ\D5\FD\D2\F2\D7\D31\A1\A22*n (n=1\A1\AB16) \A3\AC\BE\DF\CC\E5\C9\E8\D6òο\BCЭ\D2\E9D\D2\F2\D7ӺͿ\A8\CC\D8\D0ԡ\A3CNend
 \retval  0 	Success.                                                                                               CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT  No SCI device is started.                                                          CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                                       CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             			   CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetEtuFactor(HI_UNF_SCI_PORT_E enSciPort, HI_U32 u32ClkFactor, HI_U32 u32BaudFactor);

/**
 \brief \brief Sets the extra guard time for transmitting two consecutive bytes from the terminal to an IC card. The guard time is the interval between the start edges of two consecutive bytes.
CNcomment:\C9\E8\D6\C3\D6ն\CB\CF\F2IC\BF\A8\B7\A2\CB\CD\C1\AC\D0\F8\B5\C4\C1\BD\B8\F6\D7ֽ\DA\C6\F0ʼ\D1ض\EE\CD\E2\D4\F6\BCӵļ\E4\B8\F4ʱ\BC䡣CNend

 \attention \n
This setting is performed based on related features only for the cards that require extra character guard time.
In general, the default value is used or the interval guard time is automatically set based on the ART analysis result.
CNcomment:ֻ\D3\D0\CC\D8\D0\E8Ҫ\C7\F3\B5Ŀ\A8\A3\AC\D0\E8Ҫ\B6\EE\CD\E2\C9\E8\D6\C3\D7ַ\FB\B1\A3\BB\A4ʱ\BC\E4\B5Ĳ\C5\C4ܸ\F9\BEݿ\A8\B5\C4\CF\E0\B9\D8\CC\D8\D0\D4\C9\E8\D6ã\AC
\B2\BB\BF\C9\CB\E6\D2\E2\C9\E8\D6á\A3һ\B0\E3ʹ\D3\C3ϵͳĬ\C8\CFֵ\A3\AC\BB\F2\D5\DFϵͳ\B8\F9\BE\DDATR\BD\E2\CE\F6\D7Զ\AF\C9\E8\D6á\A3CNend
 \param [in] 	enSciPort	ID of an SCI port. The port ID can be 0 or 1.      	CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	u32GuardTime  Extra guard time, ranging from 0 to 254 ETU.	   	CNcomment:\B6\EE\CD\E2\BC\E4\B8\F4\B1\A3\BB\A4\B5ķ\B6Χ0\A1\AB254  etu\A1\A3CNend
 \retval 0  Success.	                                                       		CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                  		CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.               		CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                          CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetGuardTime(HI_UNF_SCI_PORT_E enSciPort, HI_U32 u32GuardTime);

/**
 \brief Sets the baud rate supported by the SCI card through protocol and parameters selection (PPS) negotiation or performs negotiation by using the F and D factors returned by the ATR to switch the protocol of a card.
CNcomment:ͨ\B9\FDPPS Э\C9̿\C9\D2\D4\C9\E8\D6ÿ\A8\CB\F9֧\B3ֵĲ\A8\CC\D8\C2ʻ\F2\D5\DF\D3\C3ATR \B4\AB\BBص\C4F\A1\A2D\D2\F2\D7ӽ\F8\D0\D0Э\C9̣\AC֧\B3ֶ\E0Э\D2鿨\B5\C4Э\D2\E9\C7л\BB\A1\A3CNend
\attention \n
PPS negotiation is available only when the SCI card supports this function.
The negotiated baud rate must be supported by the SCI card.
The command words for negotiation must comply with the specifications defined in section 9.2 "PPS request and response" in the 7816-3 protocol.
CNcomment:Ҫ\BD\F8\D0\D0PPS Э\C9\CC\CA\D7\CFȿ\A8\B1\D8\D0\EB֧\B3ָù\A6\C4ܣ\AC
ҪЭ\C9̵Ĳ\A8\CC\D8\C2\CA\C4\DA\C8ݱ\D8\D0\EB\CAǿ\A8\CB\F9\B9涨\B5\C4֧\B3ֵĲ\A8\CC\D8\C2ʷ\B6Χ\A3\AC
\C7\EB\C7\F3Э\C9̵\C4\C3\FC\C1\EE\D7\D6\D0\E8\B7\FB\BA\CF7816-3 \D6\D09.2 PPS request and response\A1\A3CNend

 \param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                                 CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	pSciSendBuf  PPS negotiation command combined based on card specifications. If the default negotiation mode is used, the command word can be left empty.   CNcomment:\B8\F9\BEݿ\A8\B9淶\D7\E9\BAϵ\C4PPSЭ\C9\CC\C3\FC\C1\C8\F4ʹ\D3\C3ϵͳĬ\C8ϵ\C4Э\C9̷\BDʽ\A3\AC\C3\FC\C1\EE\D7ֵ\C4\C4\DA\C8ݿ\C9Ϊ\BFա\A3CNend
 \param [in]	Sendlen	   Length of the command word to be transmitted, ranging from 0 bytes to 5 bytes. The value 0 indicates that the default negotiation mode is used.   CNcomment: \B7\A2\CB\CD\C3\FC\C1\EE\D7ֵĳ\A4\B6\C8(0\A1\AB5),\C9\E8\D6\C3Ϊ0\B1\EDʾʹ\D3\C3ϵͳĬ\C8ϵ\C4Э\C9\CC\C3\FC\C1ʽ\A1\A3CNend
 \param [in]	RecTimeouts  PPS response timeout after commands are transmitted. The value ranges from 1 ms to 10000 ms.  CNcomment: \B7\A2\CB\CD\CD\EA\C3\FC\C1\EE֮\BA󣬽\D3\CA\D5PPS \CF\ECӦ\B5ĳ\ACʱʱ\BC\E4(1-10000),\B5\A5λ\CAǺ\C1\C3롣CNend
 \retval 0 	Success.                                                                               		CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_NOT_INIT   No SCI device is started.                                         		CNcomment:SCI\C9豸δ\B4򿪡\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                                      		CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR		The pointer is null.                                          		CNcomment:\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                          	CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_RECEIVE_ERR  A reception error occurs.                                       		CNcomment:\BD\D3\CAմ\ED\CE\F3\A1\A3CNend
 \retval ::HI_ERR_SCI_PPS_PTYPE_ERR 	The protocol type for PPS negotiation is incorrect.           		CNcomment:PPSЭ\C9̵\C4Э\D2\E9\C0\E0\D0ʹ\ED\CE\F3\A1\A3CNend
 \retval ::HI_ERR_SCI_PPS_FACTOR_ERR 	The F factor and D factor for PPS negotiation are incorrect. 	        CNcomment:PPSЭ\C9̵\C4F\A1\A2D\D2\F2\D7Ӵ\ED\CE\F3\A1\A3CNend
 \retval ::HI_ERR_SCI_PPS_NOTSUPPORT_ERR  The PPS negotiation type is not supported.               		CNcomment:\B2\BB֧\B3ֵ\C4PPSЭ\C9\CC\C0\E0\D0͡\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_NegotiatePPS(HI_UNF_SCI_PORT_E enSciPort, HI_U8 *pSciSendBuf, HI_U32 Sendlen, HI_U32 RecTimeouts);

/**
 \brief  Obtains the PPS data for the card response after PPS negotiation is successful.
CNcomment:PPS Э\C9̳ɹ\A6֮\BA\F3,ͨ\B9\FD\B8ýӿڿɻ\F1\B5ÿ\A8\CF\ECӦ\B5\C4PPS \CA\FD\BEݡ\A3CNend
 \attention \n
This API takes effect only after PPS negotiation is successful.
CNcomment:Ҫ\B5\C8PPS Э\C9̳ɹ\A6֮\BA\F3,ʹ\D3øýӿڲ\C5\D3\D0ʵ\BC\CA\D2\E2\D2塣CNend

 \param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                   CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [out] 	pRecBuf   Address of the buffer for storing the data to be received.   	CNcomment:\B4\FD\BD\D3\CAյ\C4\CA\FD\BE\DDbuffer \B5\D8ַ\A1\A3CNend
 \param [out]	pDataLen	  Required length of the received data.                      CNcomment:\C6\DA\CD\FB\BD\D3\CA\D5\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
 \retval 0  Success.	                                                                	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                        	CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR	The pointer is null.                                	CNcomment:\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_SCI_PPS_NOTSUPPORT_ERR  The PPS negotiation type is not supported. 	CNcomment:\B2\BB֧\B3ֵ\C4PPSЭ\C9\CC\C0\E0\D0͡\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_GetPPSResponData(HI_UNF_SCI_PORT_E enSciPort, HI_U8* pRecBuf, HI_U32* pDataLen);

/**
brief  Obtains the SCI parameter values including the protocol, ATR clock factor, ATR bit rate factor, actual clock factor, actual bit rate factor, number of retries, guard delay, character wait timeout, and block wait timeout.
CNcomment:\BB\F1ȡsci \B2\CE\CA\FD\B0\FC\C0\A8Э\D2顢ATR ʱ\D6Ӻͱ\C8\CC\D8\C2\CA\D2\F2\D7ӡ\A2ʵ\BC\CA\C9\E8\D6õ\C4ʱ\D6\D3\D2\F2\D7Ӻͱ\C8\CC\D8\C2\CA\D2\F2\D7ӣ\AC
\B7\A2\CB\CD\D6\D8\CAԴ\CE\CA\FD\A1\A2GuardDelay \A1\A2\D7ַ\FB\B5ȴ\FD\B3\ACʱ\A1\A2\BF\E9\B5ȴ\FD\B3\ACʱ\A1\A3CNend
 \attention \n
This API is available only after HI_UNF_SCI_Init and HI_UNF_SCI_ResetCard are called.
CNcomment:Ҫ\B5\C8 \B5\BD\B3\F5ʼ\BB\AF\B8\B4λ֮\BA\F3,\B2\C5\C4\DCʹ\D3øýӿڡ\A3CNend

 \param [in] 	enSciPort	 ID of an SCI port. The port ID is 0 or 1.                      CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [out] 	pParams   Pointer to the data type of the data structure to be received.   	CNcomment:\B4\FD\BD\D3\CAյĽṹ\CC\E5\CA\FD\BE\DD\C0\E0\D0\CDָ\D5롣CNend
 \retval 0 	Success.                                                                     	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                             	CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_NULL_PTR		The pointer is null.                                    CNcomment:\BF\D5ָ\D5롣CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                	CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NOT_INIT  	The SCI device is not initialized.                      CNcomment:û\CD\EA\B3ɳ\F5ʼ\BB\AF\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_GetParams(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PARAMS_S_PTR pParams);

/**
 \brief  Sets the character timeout of T0 and T1 separately based on the current protocol type.
CNcomment:\B8\F9\BEݵ\B1ǰЭ\D2\E9\C0\E0\D0ͷֱ\F0\BF\C9\C9\E8\D6\C3T0\A1\A2T1\B5\C4\D7ַ\FB\B3\ACʱʱ\BC䡣CNend

 \attention \n
The timeout can be set only after the SCI card is reset successfully. The protocol type must be consistent with the current card type. In general, the timeout is obtained by parsing the ATR. That is, the timeout needs to be set only when card communication fails.
CNcomment:Ҫ\B5ȿ\A8\B8\B4λ\B3ɹ\A6֮\BA\F3,\B2\C5\C4ܽ\F8\D0\D0\C9\E8\D6ã\ACЭ\D2\E9\C0\E0\D0Ͳ\CE\CA\FD\B1\D8\D0\EB\D3뵱ǰ\BF\A8\C0\E0\D0\CDһ\D6£\ACһ\B0\E3\C7\E9\BF\F6\B6\BC\CAǸ\F9\BE\DDATR\BD\E2\CE\F6\A3\ACֻ\D3\D0\CC\D8\CA⿨\C7\E9\BF\F6\B2\C5\D0\E8Ҫ\C9\E8\D6á\A3CNend

 \param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.   CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	enSciProtocol  Protocol type.                           	CNcomment:Э\D2\E9\C0\E0\D0͡\A3CNend
 \param [in]	MaxCharTime  Maximum character timeout. The value of MaxCharTime for T0 ranges from 960 to 244800, and the value of MaxCharTime for T1 ranges from 12 to 32779.	  CNcomment:\C9\E8\D6\C3\D7\EE\B4\F3\B5\C4\D7ַ\FB\B3\ACʱʱ\BC䣬\C9\E8\D6÷\B6ΧT0(960\A1\AB244800),T1(12\A1\AB32779)\A1\A3CNend
 \retval 0 	Success.                                                  	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.         	CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.             	CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NO_ATR  	The SCI card fails to be reset.        	CNcomment:û\B8\B4λ\B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetCharTimeout(HI_UNF_SCI_PORT_E enSciPort, HI_UNF_SCI_PROTOCOL_E enSciProtocol, HI_U32 MaxCharTime);

/**
 \brief  Sets the block timeout of T1.
CNcomment:\C9\E8\D6\C3T1\B5Ŀ鳬ʱʱ\BC䡣CNend
\attention \n
The timeout can be set only after the SCI card is reset successfully. In general, the timeout is obtained by parsing the ATR. That is, the timeout needs to be set only in special cases
CNcomment:Ҫ\B5ȿ\A8\B8\B4λ\B3ɹ\A6֮\BA\F3,\B2\C5\C4ܽ\F8\D0\D0\C9\E8\D6ã\ACһ\B0\E3\C7\E9\BF\F6\B6\BC\CAǸ\F9\BE\DDATR\BD\E2\CE\F6\A3\ACֻ\D3\D0\CC\D8\CA⿨\C7\E9\BF\F6\B2\C5\D0\E8Ҫ\C9\E8\D6á\A3CNend

 \param [in] 	enSciPort	 ID of an SCI port. The port ID is 0 or 1.                         	CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	MaxBlockTime   Maximum block timeout. The value ranges from 971 to 491531.   	CNcomment:\C9\E8\D6ÿ鳬ʱ\B5\C4\D7\EE\B4\F3ֵ\A3\AC\B7\B6Χ(971\A1\AB491531)\A1\A3CNend
 \retval 0 	Success.                                                                        		CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA The parameter is invalid.                                		CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                                   	CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NO_ATR  		The SCI card fails to be reset.                            	CNcomment:û\B8\B4λ\B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetBlockTimeout(HI_UNF_SCI_PORT_E enSciPort, HI_U32 MaxBlockTime);

/**
 \brief  Sets the maximum number of transmission retries after a check error occurs.
CNcomment:\C9\E8\D6\C3У\D1\E9\B4\ED\CE\F3\BA\F3\D6ط\A2\CB\CD\D7\EE\B4\F3\B4\CE\CA\FD\A1\A3CNend
\attention \n
The number can be set only after the SCI card is reset successfully.
CNcomment:Ҫ\B5ȿ\A8\B8\B4λ\B3ɹ\A6֮\BA\F3,\B2\C5\C4ܽ\F8\D0\D0\C9\E8\D6á\A3CNend

 \param [in] 	enSciPort	ID of an SCI port. The port ID is 0 or 1.                   CNcomment:SCI\B6˿ںţ\ACȡֵ\B7\B6ΧΪ0\BA\CD1\A1\A3CNend
 \param [in] 	TxRetryTimes   Number of transmission retries, ranging from 0 to 7.    	CNcomment:\B4\CE\CA\FD\B7\B6Χ(0\A1\AB7)\A1\A3CNend
 \retval 0 	Success.                                                                  	CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_PARA  The parameter is invalid.                         	CNcomment:\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
 \retval ::HI_ERR_SCI_INVALID_OPT	The option is invalid.                             	CNcomment:\B2\BB\BF\C9\D3õ\C4ѡ\CFCNend
 \retval ::HI_ERR_SCI_NO_ATR  	The SCI card fails to be reset.	                       	CNcomment:û\B8\B4λ\B3ɹ\A6\A1\A3CNend

 \see \n
N/A
 */
HI_S32 HI_UNF_SCI_SetTxRetries(HI_UNF_SCI_PORT_E enSciPort, HI_U32 TxRetryTimes);

/** @}*/  /** <!-- ==== API Declaration End ====*/

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_UNF_SCI_H__ */
