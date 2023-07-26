/******************************************************************************
  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_aenc.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       :
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        :
  Modification  : Created file
******************************************************************************/

/**
 * \file
 * \brief describle the information about AENC. CNcomment:\CCṩAENC\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef  __HI_UNF_AENC_H__
#define  __HI_UNF_AENC_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define HI_UNF_AENC_MAX_TYPE 1

/* AENC Capability Description */
/**CNcomment: \B1\E0\C2\EB\C4\DC\C1\A6\C3\E8\CA\F6*/
typedef struct
{
    HA_CODEC_ID_E  enCodecType; /* support aenc type */
} HI_UNF_AENC_CAP_INFO_S;

typedef struct
{
    HI_U32 u32SupportTypeNum;                               /* support aenc type num */
    HI_U32 u32MaxAencInstance;                              /* maximum running aenc encoder */
    HI_UNF_AENC_CAP_INFO_S stCapInfo[HI_UNF_AENC_MAX_TYPE]; /* capability information for each aenc type */
} HI_UNF_AENC_CAP_S;

/******************************* API Declaration *****************************/
/** \addtogroup      AENC */
/** @{ */  /** <!-- [AENC] */

/**
\brief Initializes audio encoder. CNcomment:\B3\F5ʼ\BB\AF\D2\F4Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
Call the interface before calling HI_UNF_AENC_Open. CNcomment:HI_UNF_AENC_Open\BDӿ\DAǰ\B5\F7\D3\C3 CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_Init(HI_VOID);

/**
\brief Deinitializes audio encoder. CNcomment:ȥ\B3\F5ʼ\BB\AF\D2\F4Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
N/A
\param N/A
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT  Invalid operation CNcomment:HI_ERR_AENC_CH_NOT_SUPPORT \CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_DeInit(HI_VOID);

/**
\brief Create audio encoder. CNcomment:\B4\B4\BD\A8\D2\F4Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
Before calling the interface, you must configure the encoder. Now AENC only supports 16-bit and 2 channels, and support 16K, 22K, 24K, 32K, 44K, or 48Ksample rate.
CNcomment:\B5\F7\D3øýӿ\DAǰ\A3\AC\B1\D8\D0\EB\C5\E4\D6ñ\E0\C2\EB\C6\F7\A3\ACĿǰAENCֻ֧\B3\D616λ2\C9\F9\B5\C0\A3\AC\C7Ҳ\C9\D1\F9\C2\CAΪ\A3\BA16K 22K 24K 32K 44K\BA\CD48K CNend
\param[in] pstAencAttr               Attribute structure of the audio encoder. CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\CA\F4\D0Խṹ CNend
\param[out] phAenc                   Obtain the handle of the audio encoder. CNcomment:\B5õ\BD\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AENC_NULL_PTR        The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AENC_CREATECH_FAIL   The encoder fails to be created. CNcomment:\B4\B4\BD\A8\B1\E0\C2\EB\C6\F7ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_Create(const HI_UNF_AENC_ATTR_S* pstAencAttr, HI_HANDLE* phAenc);

/**
\brief Destroy the audio encoder. CNcomment:\CF\FA\BB\D9\D2\F4Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
\param[in] phAenc the handle of the audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT  The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\retval ::HI_ERR_AENC_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_CH_NOT_OPEN     The audio encoder is not opened. CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7û\D3д\F2\BF\AA CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_Destroy(HI_HANDLE hAenc);

/**
\brief Copy data to the encoder for encoding. CNcomment:\CF\F2\B1\E0\C2\EB\C6\F7\BF\BD\B1\B4\CA\FD\BE\DD\D2Թ\A9\B1\E0\C2\EB CNend
\attention \n
\param[in] phAenc     The audio encoder handle CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\param[in] pstAOFrame Send a frame of data to the encoder. CNcomment:\CF\F2\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\CB\CDһ֡\CA\FD\BE\DD CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_IN_BUF_FULL      The input buffer of the encoder is full. CNcomment:\B1\E0\C2\EB\C6\F7\CA\E4\C8뻺\B3\E5\C2\FA CNend
\retval ::HI_ERR_AENC_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT   The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_SendFrame(HI_HANDLE hAenc, const HI_UNF_AO_FRAMEINFO_S* pstAOFrame);

/**
\brief Obtain data from a output buffer of the encoder and write the data into the file. CNcomment:\B4ӱ\E0\C2\EB\C6\F7\B5\C4һ\B8\F6\CA\E4\B3\F6\BB\BA\B3\E5\D6\D0ȡ\B3\F6\CA\FD\BE\DD\D2Թ\A9д\C8\EB\CEļ\FE CNend
\attention \n
\param[in] phAenc     The audio encoder handle CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\param[in] pstStream  The data in a output buffer of the audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7һ\B8\F6\CA\E4\B3\F6\BB\BA\B3\E5\D6е\C4\CA\FD\BE\DD CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_OUT_BUF_EMPTY   The output buffer of the encoder is empty. CNcomment:\B1\E0\C2\EB\C6\F7\CA\E4\B3\F6\BB\BA\B3\E5Ϊ\BF\D5 CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT  The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_AcquireStream(HI_HANDLE hAenc, HI_UNF_ES_BUF_S* pstStream, HI_U32 u32TimeoutMs);

/**
\brief Destroy the data in a output buffer of the encoder. CNcomment:\CF\FA\BBٱ\E0\C2\EB\C6\F7һ\B8\F6\CA\E4\B3\F6\BB\BA\B3\E5\D6е\C4\CA\FD\BE\DD CNend
\attention \n
Call the interface after calling HI_UNF_AENC_ReceiveStream. CNcomment:\D4\DAHI_UNF_AENC_ReceiveStream֮\BA\F3\B5\F7\D3\C3 CNend
\param[in] phAenc     The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\param[in] u32TimeoutMs   allowable timeout  CNcomment:\BB\F1ȡ\B1\E0\C2\EB\CA\FD\BE\DD\D4\CA\D0\ED\B5ĳ\ACʱ CNend
\param[out] pstStream  The data in a output buffer of the audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7һ\B8\F6\CA\E4\B3\F6\BB\BA\B3\E5\D6е\C4\CA\FD\BE\DD CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA   The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_OUT_BUF_BAD    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_IN_BUF_UNEMPTY The input buffer is empty. CNcomment:\CA\E4\C8뻺\B3\E5\B7ǿ\D5 CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_AENC_ReleaseStream(HI_HANDLE hAenc, const HI_UNF_ES_BUF_S* pstStream);

/**
\brief Register dynamic audio encoding libraries. CNcomment:ע\B2\E1\D2\F4Ƶ\B6\AF̬\B1\E0\C2\EB\BF\E2 CNend
\attention \n
\param[in] pEncoderDllName The file name of audio encoding  libraries CNcomment:pEncoderDllName \D2\F4Ƶ\B1\E0\C2\EB\BF\E2\CEļ\FE\C3\FB CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_RegisterEncoder(const HI_CHAR* pEncoderDllName);

/**
\brief Attach audio encoder with audio track. CNcomment:\B0\F3\B6\A8\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BA\CD\D2\F4ƵTrack ͨ· CNend
\attention \n
Before obtaining the streams and encoding, you must call the interface. CNcomment:\BF\AAʼ\B1\E0\C2\EB\BAͻ\F1ȡ\C2\EB\C1\F7֮ǰ\D0\E8Ҫ\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param[in] hSrc   The handle of audio track CNcomment:\D7\CAԴ\BE\E4\B1\FA CNend
\param[in] hAenc     The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA	        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT        The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\retval ::HI_ERR_AENC_NULL_PTR	            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT	        The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_AttachInput(HI_HANDLE hAenc, HI_HANDLE hSrc);

/**
\brief Detach audio encoder with audio track. CNcomment:\BD\E2\B3\FD\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BA\CD\D2\F4ƵTrack ͨ·\B5İ\F3\B6\A8 CNend
\attention \n
Before calling the interface, stop the encoding. CNcomment:\B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CF\C8ֹͣ\B1\E0\C2\EB CNend
\param[in] hAenc     The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA	        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_CH_NOT_SUPPORT        The operation is invalid. CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 CNend
\retval ::HI_ERR_AENC_NULL_PTR	            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT	        The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_DetachInput(HI_HANDLE hAenc);

/**
\brief Start to encode. CNcomment:\BF\AAʼ\B1\E0\C2\EB CNend
\attention \n
Before calling the interface, you need to initialize the encoder, create an encoding channel and attach the player.
CNcomment:\B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȳ\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7\A3\AC\B4\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0\A3\AC\B0󶨲\A5\B7\C5\C6\F7 CNend
\param[in] hAenc The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA	        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_NULL_PTR	            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT	        The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_Start(HI_HANDLE hAenc);

/**
\brief Stop to encode. CNcomment:ֹͣ\B1\E0\C2\EB CNend
\attention \n
Before calling the interface, you need to initialize the encoder, create an encoding channel, attach the player, and start the encoding.
CNcomment:\B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȳ\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7\A3\AC\B4\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0\A3\AC\B0󶨲\A5\B7\C5\C6\F7\A3\AC\D2Ѿ\AD\BF\AAʼ\B1\E0\C2\EB CNend
\param[in] hAenc   The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA	        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_NULL_PTR	            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT	        The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_Stop(HI_HANDLE hAenc);

/**
\brief Set the attribution of encode. CNcomment:\C9\E8\D6ñ\E0\C2\EB\CA\F4\D0\D4 CNend
\attention \n
Before calling the interface, you need to stop the encoder.
CNcomment:\B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CF\C8ֹͣ\B1\E0\C2\EBCNend
\param[in] hAenc   The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\param[in] pstAencAttr   The attribution of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_NULL_PTR            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_SetAttr(HI_HANDLE hAenc, const HI_UNF_AENC_ATTR_S* pstAencAttr);

/**
\brief Set the attribution of encode. CNcomment:\BB\F1ȡ\B1\E0\C2\EB\CA\F4\D0\D4 CNend
\attention \n
\param[in] hAenc   The handle of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\BE\E4\B1\FA CNend
\param[out] pstAencAttr   The attribution of audio encoder CNcomment:\D2\F4Ƶ\B1\E0\C2\EB\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AENC_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AENC_NULL_PTR            The pointer is null. CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_GetAttr(HI_HANDLE hAenc, HI_UNF_AENC_ATTR_S* pstAencAttr);

/**
\brief get AENC capability. CNcomment:\BB\F1ȡ\B1\E0\C2\EB\C4\DC\C1\A6\BC\AF CNend
\attention \n
\param[in] pstCapability The returned capability of AENC CNcomment:pstCapability \B1\E0\C2\EB\C4\DC\C1\A6\BC\AF\C3\E8\CA\F6\BDṹ\CC\E5 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AENC_GetCapability(HI_UNF_AENC_CAP_S* pstCapability);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AENC_H__*/
