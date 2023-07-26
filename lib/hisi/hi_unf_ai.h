/******************************************************************************
  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_ai.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/4/22
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        : zgjie
  Modification  : Created file
******************************************************************************/
/**
 * \file
 * \brief Describes the information about the audio input (AI) module. CNcomment:\CCṩAI\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef  __HI_UNF_AI_H__
#define  __HI_UNF_AI_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/********************************Macro Definition********************************/
/** \addtogroup      AI */
/** @{ */  /** <!-- AI */


/** @} */  /** <!-- ==== Macro Definition end ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      AI */
/** @{ */  /** <!--  \A1\BEAI\A1\BF */




/**Audio inputport defination */
/**CNcomment:\D2\F4Ƶ\CA\E4\C8\EB\B6˿ڶ\A8\D2\E5*/
typedef enum hiUNF_AI_E
{
    HI_UNF_AI_I2S0 = 0,

    HI_UNF_AI_I2S1,

    HI_UNF_AI_ADC0 = 0x10,

    HI_UNF_AI_ADC1,

    HI_UNF_AI_ADC2,

    HI_UNF_AI_ADC3,

    HI_UNF_AI_ADC4,

    HI_UNF_AI_SIF0 = 0x20,

    HI_UNF_AI_HDMI0 = 0x30,

    HI_UNF_AI_HDMI1,

    HI_UNF_AI_HDMI2,

    HI_UNF_AI_HDMI3,

    HI_UNF_AI_BUTT = 0xff,
} HI_UNF_AI_E;

/**Defines internal Audio ADC inputport attribute */
/**CNcomment:\B6\A8\D2\E5\C4\DA\D6\C3\D2\F4ƵADC\CA\E4\C8\EB\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_AI_ADC_ATTR_S
{
    HI_BOOL   bByPass;
} HI_UNF_AI_ADC_ATTR_S;


/**Defines  Audio I2S inputport attribute */
/**CNcomment:\B6\A8\D2\E5\D2\F4ƵI2S\CA\E4\C8\EB\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_AI_I2S_ATTR_S
{
    HI_UNF_I2S_ATTR_S  stAttr;  /**<I2S Attribute*/ /**<CNcomment:I2S\CA\F4\D0\D4*/
}  HI_UNF_AI_I2S_ATTR_S;

/**Defines the HDMI RX Audio data format .*/
typedef enum hiHI_UNF_AI_HDMI_FORMAT_E
{
    HI_UNF_AI_HDMI_FORMAT_LPCM = 0,          /* LPCM 2/8 channels,  Audio Sample Packet layout0 or layout1 */ 
    HI_UNF_AI_HDMI_FORMAT_LBR = 1,           /* IEC-61937 DD/DDP/DTS, Audio Sample Packet layout0 */ 
    HI_UNF_AI_HDMI_FORMAT_HBR = 8,           /* IEC-61937 DTSHD/TrueHD, High-Bitrate (HBR) Audio Stream Packet*/ 
    HI_UNF_AI_HDMI_FORMAT_BUTT
} HI_UNF_AI_HDMI_FORMAT_E;


/**Defines  HDMI Audio inputport attribute */
/**CNcomment:\B6\A8\D2\E5HDMI\D2\F4Ƶ\CA\E4\C8\EB\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_AI_HDMI_ATTR_S
{
    HI_UNF_I2S_CHNUM_E    enChannel;    /**<Channel number*/ /**<CNcomment:ͨ\B5\C0\CA\FD*/
    HI_UNF_I2S_BITDEPTH_E enBitDepth;   /**<Bit Depth*/ /**<CNcomment:λ\BF\ED*/
    HI_UNF_SAMPLE_RATE_E  enSampleRate; /**<Sample Rate*/ /**<CNcomment:\B2\C9\D1\F9\C2\CA*/
    HI_UNF_AI_HDMI_FORMAT_E enHdmiAudioDataFormat;  /**<HDMI audio data format*/ /**<CNcomment:HDMI\D2\F4Ƶ\CA\FD\BEݸ\F1ʽ*/
} HI_UNF_AI_HDMI_ATTR_S;

/**Defines internal SIF(Audio Demodulator) inputport attribute */
/**CNcomment:\B6\A8\D2\E5SIF\CA\E4\C8\EB\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_AI_SIF_ATTR_S
{
    HI_VOID* pPara;
} HI_UNF_AI_SIF_ATTR_S;

/**Defines  Audio inputport attribute */
/**CNcomment:\B6\A8\D2\E5\D2\F4Ƶ\CA\E4\C8\EB\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiHI_UNF_AI_ATTR_S
{
    HI_UNF_SAMPLE_RATE_E    enSampleRate;          /**<samplerate, default 48000Hz*/ /**<CNcomment:\C9豸\B2\C9\D1\F9Ƶ\C2ʣ\ACĬ\C8\CF 48000Hz*/
    HI_U32                  u32PcmFrameMaxNum;     /**<Max frame of the PCM data at cast buffer, default 16*/ /**<CNcomment: \D7\EE\B4\F3\BFɻ\BA\B4\E6֡\CA\FD\A3\ACĬ\C8\CF 16*/
    HI_U32                  u32PcmSamplesPerFrame; /**<Number of sample of the PCM data, default 960*/ /**<CNcomment: PCM\CA\FD\BEݲ\C9\D1\F9\B5\E3\CA\FD\C1\BF\A3\ACĬ\C8\CF 960*/
    union
    {
        HI_UNF_AI_ADC_ATTR_S  stAdcAttr;    /**<ADC Attribute*/ /**<CNcomment:ADC\CA\F4\D0\D4*/
        HI_UNF_AI_I2S_ATTR_S  stI2sAttr;    /**<I2S Attribute*/ /**<CNcomment:I2S\CA\F4\D0\D4*/
        HI_UNF_AI_HDMI_ATTR_S stHDMIAttr;   /**<HDMI Attribute*/ /**<CNcomment:HDMI\CA\F4\D0\D4*/
    } unAttr;
} HI_UNF_AI_ATTR_S;

/**Defines AI Delay attribute */
/**CNcomment:\B6\A8\D2\E5AI\D1ӳ\D9\CA\F4\D0\D4*/
typedef struct hiHI_UNF_AI_DELAY_S
{
    HI_U32                  u32DelayMs;    /**<buffer delay compensation(ms), Min Value is 20, Max Value depends on u32PcmFrameMaxNum, u32PcmSamplesPerFrame and enSampleRate in HI_UNF_AI_ATTR_S.
                                                    MaxValue = u32PcmSamplesPerFrame * u32PcmFrameMaxNum * 1000 / enSampleRate. 
                                                    MaxValue is equal to 320ms according to default HI_UNF_AI_ATTR_S*/ 
                                                   /**<CNcomment:\BB\BA\B4\E6\D6\D0\CA\FD\BE\DD\C1\BF\D1ӳٲ\B9\B3\A5\BF\D8\D6\C6(ms), \D7\EEСֵΪ20ms\A3\AC\D7\EE\B4\F3ֵ\D2\C0\C0\B5HI_UNF_AI_ATTR_S\D6е\C4u32PcmFrameMaxNum\A3\ACu32PcmSamplesPerFrame\D2Լ\B0enSampleRate
                                                    \BC\C6\CB㹫ʽ:MaxValue = u32PcmSamplesPerFrame * u32PcmFrameMaxNum * 1000 / enSampleRate\A3\AC
                                                    \C8\F4\B8\F9\BE\DDĬ\C8\CFHI_UNF_AI_ATTR_S\A3\AC\D4\F2\D7\EE\B4\F3ֵΪ320ms */
    HI_BOOL                 bDelayMsAutoHold;  /**<if hold buffer delay compensation time automatically*/ /**<CNcomment:\CAǷ\F1\D3\C9AI_AOͨ·\D7Զ\AF\B1\A3\B3ֻ\BA\B4\E6\CA\FD\BE\DD\C1\BF\CEȶ\A8\D4\DAu32CompensationMs*/
} HI_UNF_AI_DELAY_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API declaration *****************************/
/** \addtogroup      AI */
/** @{ */  /** <!--  \A1\BEAI\A1\BF */

/**
\brief Initializes an AI device. CNcomment:\B3\F5ʼ\BB\AF\D2\F4Ƶ\CA\E4\C8\EB\C9豸 CNend
\attention \n
Before calling the AI module, you must call this application programming interface (API). CNcomment:\B5\F7\D3\C3AIģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AI_Init(HI_VOID);

/**
\brief Deinitializes an AI device. CNcomment:ȥ\B3\F5ʼ\BB\AF\D2\F4Ƶ\CA\E4\C8\EB\C9豸 CNend
\attention \n
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6  CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AI_DeInit(HI_VOID);

/**
 \brief Obtains the default attributes of a AI port. CNcomment: \BB\F1ȡAI\B6˿\DAĬ\C8\CF\CA\F4\D0\D4 CNend
 \attention \n
 \param[in] pstAttr Pointer to AI attributes CNcomment: AI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_AI_NULL_PTR   The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_AI_GetDefaultAttr(HI_UNF_AI_E enAiPort, HI_UNF_AI_ATTR_S *pstAttr);

/**
 \brief Enables a AI port to create a AI handle. CNcomment: \B4\F2\BF\AAAI Port\A3\AC\B4\B4\BD\A8AI\BE\E4\B1\FA CNend
 \attention \n
Before calling the AI, you must call this API.\n
CNcomment: \B5\F7\D3\C3AI ģ\BF\E9\D0\E8Ҫ\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
 \param[in] pstAttr CNcomment: Pointer to AI attributes AI\CA\F4\D0\D4ָ\D5\EB CNend
 \param[in] phandle CNcomment: hAi Pointer to the AI handle AI\BE\E4\B1\FAָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_AI_NULL_PTR   The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_AI_INVALID_PARA   The attribute parameters are incorrect. CNcomment: \CA\F4\D0Բ\CE\CA\FD\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_AI_Create(HI_UNF_AI_E enAiPort, HI_UNF_AI_ATTR_S *pstAttr, HI_HANDLE *phAI);

/**
 \brief Disable a AI port to destroy the handle. CNcomment: \B9ر\D5AI Port\A3\AC\CF\FA\BBپ\E4\B1\FA CNend
 \attention \n
 \param[in] hAi AI handle CNcomment: AI\BE\E4\B1\FA CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_AI_INVALID_PARA  The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_AI_Destroy(HI_HANDLE hAI);

/**
 \brief Set the attributes of a AI port. CNcomment: \C9\E8\D6\C3AI Port\CA\F4\D0\D4 CNend
 \attention \n
 \param[in] hAi AI handle CNcomment: AI\BE\E4\B1\FA CNend
 \param[in] pstAttr  Pointer to AI attributes CNcomment: AI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_AI_NULL_PTR   The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_AI_INVALID_ID   The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
 \retval ::HI_ERR_AI_INVALID_PARA   The attribute parameters are incorrect. CNcomment: \CA\F4\D0Բ\CE\CA\FD\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
 HI_S32 HI_UNF_AI_SetAttr(HI_HANDLE hAI, HI_UNF_AI_ATTR_S *pstAttr);


/**
 \brief Obtains the attributes of a AI port. CNcomment: \BB\F1ȡAI Port\CA\F4\D0\D4 CNend
 \attention \n
 \param[in] hAi AI handle CNcomment: AI\BE\E4\B1\FA CNend
 \param[out] pstAttr Pointer to AI attributes CNcomment: AI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_AI_NULL_PTR   The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_AI_INVALID_ID   The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
 \retval ::HI_ERR_AI_INVALID_PARA   The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_AI_GetAttr(HI_HANDLE hAI, HI_UNF_AI_ATTR_S *pstAttr);


/**
\brief enable AI port. CNcomment: ʹ\C4\DCAIͨ\B5\C0 CNend
\attention \n
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[in] bEnable      enable  .CNcomment:ʹ\C4ܿ\D8\D6\C6 CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_SetEnable(HI_HANDLE hAI, HI_BOOL bEnable);

/**
\brief Obtains enable/disable status of AI port. CNcomment: \BB\F1ȡAIͨ\B5\C0ʱ\C4\DC״̬ CNend
\attention \n
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[out] pbEnable enable/disable status AI port. CNcomment:AIͨ\B5\C0ʱ\C4\DC״̬ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_GetEnable(HI_HANDLE hAI, HI_BOOL *pbEnable);

/**
\brief set AI delay compensation. CNcomment: \C9\E8\D6\C3AI\BB\BA\B4\E6\D1ӳٲ\B9\B3\A5 CNend
\attention \n
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[in] pstDelay  delay compensation .CNcomment:\D1ӳٲ\B9\B3\A5\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_SetDelay(HI_HANDLE hAI, const HI_UNF_AI_DELAY_S *pstDelay);

/**
\brief Obtains AI delay compensation. CNcomment: \BB\F1ȡAI\BB\BA\B4\E6\D1ӳٲ\B9\B3\A5 CNend
\attention \n
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[out] pstDelay delay compensation. CNcomment:\D1ӳٲ\B9\B3\A5\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_GetDelay(HI_HANDLE hAI, HI_UNF_AI_DELAY_S *pstDelay);

/**
\brief get frame buffer from AI. CNcomment: \BB\F1ȡ\C9\F9\D2\F4֡\B4\E6 CNend
\attention \n
Cast pcm data format  s32BitPerSample(16), u32Channels(2),bInterleaved(HI_TRUE), u32SampleRate(same as AI).
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[in] u32TimeoutMs     acquire timeout.CNcomment:\BB\F1ȡ\B3\ACʱ CNend
\param[out] pstFrame        frame info.CNcomment:֡\D0\C5Ϣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_AcquireFrame(HI_HANDLE hAI, HI_UNF_AO_FRAMEINFO_S *pstFrame, HI_U32 u32TimeoutMs);

/**
\brief Releases the frame buffer for AI . CNcomment: \CAͷ\C5\C9\F9\D2\F4֡\B4\E6 CNend
\attention \n
\param[in] AI handle CNcomment: AI\BE\E4\B1\FA CNend
\param[in] u32TimeoutMs     acquire timeout.CNcomment:\CAͷų\ACʱ CNend
\param[out] pstFrame        frame info.CNcomment:֡\D0\C5Ϣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AI_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AI_INVALID_ID     The handle is invalid. CNcomment: \B7Ƿ\A8\BE\E4\B1\FA CNend
\retval ::HI_ERR_AI_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_AI_ReleaseFrame(HI_HANDLE hAI, HI_UNF_AO_FRAMEINFO_S *pstFrame);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AI_H__*/

