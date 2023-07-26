/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vp.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2011/03/25
  Description   :
  History       :
  1.Date        : 2011/03/25
    Author      :
    Modification: Created file

 *******************************************************************************/

/**
 * \file
 * \brief Describes the information about the video phone (VP) engine. CNcomment: \CCṩVP\CA\D3Ƶ\D2\FD\C7\E6\B5\C4\CF\E0\B9\D8\D0\C5ϢCNend
 */
#ifndef __HI_UNF_VP_H__
#define __HI_UNF_VP_H__
#include <netinet/in.h>
#include "hi_common.h"
#include "hi_unf_common.h"
#include "hi_unf_venc.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      VP*/
/** @{ */  /** <!-- [VP] */

/** Video source mode */
/**CNcomment: \CA\D3ƵԴģʽ*/
typedef enum hiUNF_VP_SOURCE_MODE_E
{
    HI_UNF_VP_SRC_MODE_USBCAM = 0,   /**<USB camera source mode *//**<CNcomment: USB \C9\E3\CF\F1ͷԴģʽ*/
    HI_UNF_VP_SRC_MODE_VI,           /**<VI camera source mode *//**<CNcomment: VIԴģʽ*/
    HI_UNF_VP_SRC_MODE_BUTT,
} HI_UNF_VP_SOURCE_MODE_E;

/**Video source attribute*/
/**CNcomment: \CA\D3ƵԴ\CA\F4\D0\D4 */
typedef struct hiUNF_VP_SOURCE_ATTR_S
{
    HI_HANDLE               hSrc;        /**<video source handle, can be set to VI handle or USB camera handle in v4l2*//**<CNcomment: \CA\D3Ƶ\CA\E4\C8\EB\BE\E4\B1\FA\A3\ACVI\BE\E4\B1\FA\BB\F2\D5\DFv4l2\D6\D0USB\C9\E3\CF\F1ͷ\B5ľ\E4\B1\FA*/
    HI_UNF_VP_SOURCE_MODE_E enSrcMode;   /**<Video source mode *//**<CNcomment: \CA\D3ƵԴģʽ*/
    HI_U32                  u32VIBufNum; /**<VI buffer number*//**<CNcomment:VI\BB\BA\B3\E5\C7\F8\B8\F6\CA\FD*/
} HI_UNF_VP_SOURCE_ATTR_S;

/**Network attribute*/
/**CNcomment: \CD\F8\C2\E7\CA\F4\D0\D4 */
typedef union hiUNF_VP_NET_ATTR_U
{
    struct sockaddr_in  stIpv4Attr;      /**<IPV4 attribute*//**<CNcomment:IPV4\CA\F4\D0\D4*/
    struct sockaddr_in6 stIpv6Attr;      /**<IPV6 attribute*//**<CNcomment:IPV6\CA\F4\D0\D4*/
} HI_UNF_VP_NET_ATTR_U;

/**RTP attribute*/
/**CNcomment: RTP\CA\F4\D0\D4*/
typedef struct hiUNF_VP_RTP_ATTR_S
{
    HI_U32 u32SplitSize;                       /**< split size, should be less than MTU size*//**<CNcomment:\B7\D6Ƭ\B4\F3С*/
    HI_U32 u32PayLoadType;                     /**< pay load type *//**<CNcomment:\B8\BA\D4\D8\C0\E0\D0\CD*/
    HI_U32 u32SortDepth;                       /**< sort in order when receive RTP packets, this para indicates sort depth *//**<CNcomment:\C5\C5\D0\F2\C9\EE\B6\C8*/
    HI_U32 u32RecvBufSize;                     /**< buffer size, usually 1500 bytes , should be bigger than u32SplitSize*//**<CNcomment:\BD\D3\CA\D5buf\A3\ACӦ\B8ô\F3\D3ڷ\D6Ƭ\B4\F3С*/
    HI_U32 u32RecvBufNum;                      /**< buffer number (total_size = u32BufSize * u32BufNum) *//**<CNcomment:\BD\D3\CA\D5buf\B8\F6\CA\FD*/
} HI_UNF_VP_RTP_ATTR_S;

/**Video engine attribute*/
/**CNcomment: \CA\D3Ƶ\D2\FD\C7\E6\CA\F4\D0\D4 */
typedef struct hiUNF_VP_ATTR_S
{
    HI_UNF_VENC_CHN_ATTR_S stVencAttr;        /**<VENC attribute*//**<CNcomment: \CA\D3Ƶ\B1\E0\C2\EB\C6\F7\CA\F4\D0\D4*/
    HI_UNF_VCODEC_TYPE_E   enDecType;         /**<VDEC attribute*//**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\C6\F7\CA\F4\D0\D4*/
    HI_BOOL                bIsIpv4;           /**<whether use IPV4 attribute, use 1 to demonstrate IPV4, use 0 to demonstrate IPV6 *//**<CNcomment: \CAǷ\F1ʹ\D3\C3IPV4\B2\CE\CA\FD\A3\AC1\B1\EDʾʹ\D3\C3IPV4\A3\AC0\B1\EDʾʹ\D3\C3IPV6*/
    HI_UNF_VP_NET_ATTR_U   stLocalNetAttr;    /**<Local network attribute*//**<CNcomment: \B1\BE\B5\D8\CD\F8\C2\E7\CA\F4\D0\D4*/
    HI_UNF_VP_NET_ATTR_U   stRemoteNetAttr;   /**<Remote network attribute*//**<CNcomment: Զ\B6\CB\CD\F8\C2\E7\CA\F4\D0\D4*/
    HI_UNF_VP_RTP_ATTR_S   stRtpAttr;         /**<RTP attribute. Generally, We highly recommend that you don't modify it.*//**<CNcomment: RTP\CA\F4\D0ԣ\ACһ\B0㲻\BD\A8\D2\E9\D0޸\C4*/
} HI_UNF_VP_ATTR_S;

/**Remote mode*/
/**CNcomment: Զ\B6\CBģʽ*/
typedef enum hiUNF_VP_REMOTE_MODE_E
{
    HI_UNF_VP_RMT_MODE_SEND = 0x1,         /**<Send local video to remote mode*//**<CNcomment: \B7\A2\CBͱ\BE\B5\D8\CA\D3Ƶ\B5\BDԶ\B6\CBģʽ*/
    HI_UNF_VP_RMT_MODE_RECV = 0x2,         /**<Receive remote video mode*//**<CNcomment: \BD\D3\CA\D5Զ\B6\CB\CA\D3Ƶģʽ*/
    HI_UNF_VP_RMT_MODE_BUTT = 0x4,
} HI_UNF_VP_REMOTE_MODE_E;

/**RTCP configure of video engine*/
/**CNcomment: \CA\D3Ƶ\D2\FD\C7\E6RTCP\C5\E4\D6\C3\D0\C5Ϣ */
typedef struct hiUNF_VP_RTCP_CFG_S
{
    HI_U32 u32EnableFlag;     /**<Enable RTCP function: 0--disable, 1--enable*//**<CNcomment: RTCPͳ\BC\C6ʹ\C4\DC: 0--\B2\BBʹ\C4\DC, 1--ʹ\C4\DC*/
    HI_U32 u32SendInterval;   /**<Send interval of RTCP report, [500, 65535]ms, must be integer of 500ms*//**<CNcomment: RTCP\B1\A8\B8淢\CBͼ\E4\B8\F4, [500, 65535] ms , \B1\D8\D0\EBΪ500ms\B5\C4\D5\FB\CA\FD\B1\B6*/
} HI_UNF_VP_RTCP_CFG_S;

/**RTCP statistics information*/
/**CNcomment: RTCP ͳ\BC\C6\D0\C5Ϣ*/
typedef struct hiUNF_VP_RTCP_STATIC_INFO_S
{
    HI_U32 u32TotalLostPacket;     /**<Total lost packet, this value may reset to 0 when network connection become abnormal *//**<CNcomment: \CA\FD\BEݶ\AA\B0\FCͳ\BCƣ\AC\CD\F8\C2\E7\C1\AC\BD\D3\D2쳣ʱ\A3\AC\B8\C4\CA\FD\BEݿ\C9\C4\DC\C7\E5\C1\E3*/
    HI_U32 u32LossFraction;        /**<Lost rate(%)*//**<CNcomment: \B6\AA\B0\FC\C2\CA(%) */
    HI_U32 u32Jitter;              /**<Jitter(ms)*//**<CNcomment: ƽ\BE\F9\B6\B6\B6\AF(ms) */
    HI_U32 u32Delay;               /**<Delay(ms)*//**<CNcomment: ƽ\BE\F9ʱ\D1\D3(ms) */
} HI_UNF_VP_RTCP_STATIC_S;

/**Statistic information of network*/
/**CNcomment: \CA\D3Ƶ\D2\FD\C7\E6\CD\F8\C2\E7ͳ\BC\C6\D0\C5Ϣ */
typedef struct hiUNF_VP_NET_STA_S
{
    HI_U32                  u32SendPacketNum; /**<Total send packet number*//**<CNcomment: \B7\A2\CBͰ\FC\D7\DC\CA\FD*/
    HI_U32                  u32SendBytes;     /**<Total send bytes*//**<CNcomment: \B7\A2\CB\CD\D7ֽ\DA\CA\FD*/
    HI_U32                  u32RecvPacketNum; /**<Total recv packet number*//**<CNcomment: \BD\D3\CAհ\FC\D7\DC\CA\FD*/
    HI_U32                  u32RecvBytes;      /**<Total recv bytes*//**<CNcomment: \BD\D3\CA\D5\D7ֽ\DA\CA\FD*/
    HI_UNF_VP_RTCP_STATIC_S stSendInfo;       /**<Send information*//**<CNcomment: \B7\A2\CB\CDͳ\BC\C6*/
    HI_UNF_VP_RTCP_STATIC_S stRecvInfo;       /**<Reveive information*//**<CNcomment: \BD\D3\CA\D5ͳ\BC\C6*/
} HI_UNF_VP_NET_STA_S;

/**Record stream format*/
/**CNcomment: ¼\D6\C6\C2\EB\C1\F7\C0\E0\D0\CD*/
typedef enum hiUNF_VP_RECORD_FORMAT_E
{
    HI_UNF_VP_RECORD_TS = 0x1,         /**<Record TS stream*//**<CNcomment: ¼\D6\C6TS\C1\F7*/
    HI_UNF_VP_RECORD_BUTT = 0x2,
} HI_UNF_VP_RECORD_FORMAT_E;

/**Statistic information of video*/
/**CNcomment: \CA\D3Ƶ\D2\FD\C7\E6ͳ\BC\C6\D0\C5Ϣ */
typedef struct hiUNF_VP_VIDEO_STATICS_S
{
    HI_U32                  u32CaptureFrmCnt;    /**<Total camera capture frame number*//**<CNcomment: \C9\E3\CF\F1ͷ\B2ɼ\AF֡\D7\DC\CA\FD*/
    HI_U32                  u32EncoderOutFrmCnt; /**<Total encoder output frame number*//**<CNcomment: \B1\E0\C2\EB\C6\F7\CA\E4\B3\F6֡\CA\FD*/
    HI_U32                  u32EncoderOutBytes;  /**<Total encoder output bytes*//**<CNcomment: \B1\E0\C2\EB\C6\F7\CA\E4\B3\F6\D7ֽ\DA*/
    HI_U32                  u32DecoderInFrmCnt;  /**<Total decoder input frame number*//**<CNcomment: \BD\E2\C2\EB\C6\F7\CA\E4\C8\EB֡\CA\FD*/
    HI_U32                  u32DecoderInBytes;   /**<Total decoder input bytes*//**<CNcomment: \BD\E2\C2\EB\C6\F7\CA\E4\C8\EB\D7ֽ\DA*/
} HI_UNF_VP_VIDEO_STATICS_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      VP */
/** @{ */  /** <!-- \A1\BEVP\A1\BF */

/**
 \brief Initializes the VP module. CNcomment: \B3\F5ʼ\BB\AFVPģ\BF\E9CNend
 \attention \n
Call this application programming interface (API) before creating VP by calling ::HI_UNF_VP_Create.
CNcomment: \D4ڵ\F7\D3\C3::HI_UNF_VP_Create\BDӿڴ\B4\BD\A8\D2\FD\C7\E6֮ǰ\A3\AC\B5\F7\D3ñ\BE\BDӿ\DACNend
 \param N/A CNcomment: \CE\DECNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_DEV_NOT_EXIST The VP device does not exist. CNcomment: \C9豸\B2\BB\B4\E6\D4\DACNend
 \retval ::HI_ERR_VP_DEV_OPEN_ERR The VP device fails to be started. CNcomment: \C9豸\B4򿪴\ED\CE\F3CNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_Init(HI_VOID);

/**
 \brief Deinitialize the VP module. CNcomment: ȥ\B3\F5ʼ\BB\AFVPģ\BF\E9CNend
 \attention \n
Call this API after destroying all VPs by calling ::HI_UNF_VP_DestroyChannel.
CNcomment: \D4ڵ\F7\D3\C3::HI_UNF_VP_Destroy\BDӿ\DA\CF\FA\BB\D9VP\BA󣬵\F7\D3ñ\BE\BDӿ\DACNend
 \param N/A CNcomment: \CE\DECNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_NOT_INIT The VP is not initialized. CNcomment: VPδ\B3\F5ʼ\BB\AFCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_DeInit(HI_VOID);

/**
 \brief Obtain the default parameter values of VP. CNcomment: \BB\F1ȡVPȱʡ\B2\CE\CA\FDCNend
 \attention \n
Call this API before creating VP by calling ::HI_UNF_VP_Create. This enables you to set parameters conveniently.
CNcomment: \D4ڵ\F7\D3\C3::HI_UNF_VP_Create\BDӿڴ\B4\BD\A8VP֮ǰ\A3\AC\B5\F7\D3ñ\BE\BDӿڣ\AC\B7\BD\B1\E3\CC\EEд\B2\CE\CA\FDCNend
 \param[in] N/A CNcomment: \CE\DECNend
 \param[out] pstDefAttr Pointer to the default VP attributes. For details, see :HI_UNF_VP_ATTR_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVPĬ\C8\CF\CA\F4\D0ԣ\AC\B2μ\FB:HI_UNF_VP_ATTR_S CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */

HI_S32 HI_UNF_VP_GetDefaultAttr(HI_UNF_VP_ATTR_S *pstDefAttr);

/**
 \brief Create VP. CNcomment: \B4\B4\BD\A8VP  CNend
 \attention \n
N/A CNcomment: \CE\DECNend
 \param[in]  pstAttr parameter CNcomment: VP\B2\CE\CA\FDCNend
 \param[out] phVP Pointer to the VP handle. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP\BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval ::HI_ERR_VP_NOT_SUPPORT The input parameter is invalid. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8CNend
 \retval ::HI_ERR_VP_NOT_SUPPORT The mode is not supported. CNcomment: \B2\BB֧\B3\D6ģʽCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_Create(const HI_UNF_VP_ATTR_S *pstAttr, HI_HANDLE *phVP);

/**
 \brief Destroy VP. CNcomment: \CF\FA\BB\D9VP  CNend
 \attention \n
N/A CNcomment: \CE\DECNend
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_NOT_INIT The VP module is not initialized. CNcomment: VPδ\B3\F5ʼ\BB\AFCNend
 \retval ::HI_ERR_VP_INVALID_HANDLE The VP handle is invalid. CNcomment: \B7Ƿ\A8\B5\C4VP\BE\E4\B1\FACNend
 \retval Other values: A fails to be destroyed. CNcomment: \C6\E4\CB\FC \CF\FA\BB\D9ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_Destroy(HI_HANDLE hVP);

/**
 \brief Attach input source of VP. CNcomment: \B0\F3\B6\A8\CA\D3Ƶ\CA\E4\C8\EBԴCNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \param[in] stSrcAttr Video input attribute. CNcomment:\CA\D3Ƶ\CA\E4\C8\EBͨ\B5\C0\CA\F4\D0\D4CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to attach input source of VP. CNcomment: \B0\F3\B6\A8\CA\D3Ƶ\CA\E4\C8\EBԴʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_AttachSource(HI_HANDLE hVP, HI_UNF_VP_SOURCE_ATTR_S *pstSrcAttr);

/**
 \brief Attach local window of VP. CNcomment: \B0󶨱\BE\B5\D8\CA\D3Ƶ\B4\B0\BF\DACNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \param[in] hLocalWin Local window handle. CNcomment:\B1\BE\B5\D8\CA\D3Ƶ\B4\B0\BFھ\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to attach local window of VP. CNcomment: \B0󶨱\BE\B5\D8\CA\D3Ƶ\B4\B0\BF\DAʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_AttachLocalWin(HI_HANDLE hVP, HI_HANDLE hLocalWin);

/**
 \brief Attach remote window of VP. CNcomment: \B0\F3\B6\A8Զ\B6\CB\CA\D3Ƶ\B4\B0\BF\DACNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \param[in] hRemoteWin Remote window handle. CNcomment:Զ\B6\CB\CA\D3Ƶ\B4\B0\BFھ\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to attach remote window of VP. CNcomment: \B0\F3\B6\A8Զ\B6\CB\CA\D3Ƶ\B4\B0\BF\DAʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_AttachRemoteWin(HI_HANDLE hVP, HI_HANDLE hRemoteWin);

/**
 \brief Detach input source of VP. CNcomment: ȥ\B0\F3\B6\A8\CA\D3Ƶ\CA\E4\C8\EBԴCNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to detach input source of VP. CNcomment: ȥ\B0\F3\B6\A8\CA\D3Ƶ\CA\E4\C8\EBԴʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_DetachSource(HI_HANDLE hVP);

/**
 \brief Detach local window of VP. CNcomment: ȥ\B0󶨱\BE\B5\D8\CA\D3Ƶ\B4\B0\BF\DACNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to detach local window of VP. CNcomment: ȥ\B0󶨱\BE\B5\D8\CA\D3Ƶ\B4\B0\BF\DAʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_DetachLocalWin(HI_HANDLE hVP);

/**
 \brief Detach remote window of VP. CNcomment: ȥ\B0\F3\B6\A8Զ\B6\CB\CA\D3Ƶ\B4\B0\BF\DACNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval Other values: Failed to detach remote window of VP. CNcomment: ȥ\B0\F3\B6\A8Զ\B6\CB\CA\D3Ƶ\B4\B0\BF\DAʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_DetachRemoteWin(HI_HANDLE hVP);

/**
 \brief Obtains the configuration of VP. CNcomment: \BB\F1ȡVP \C5\E4\D6\C3CNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \param[out] pstAttr Pointer to VP attributes. For details, see :HI_UNF_VP_ATTR_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP \CA\F4\D0ԣ\AC\B2μ\FB:HI_UNF_VP_ATTR_S  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values:Fail to obtain attributes. CNcomment: \BB\F1ȡͨ\B5\C0\CA\F4\D0\D4ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */

HI_S32 HI_UNF_VP_GetAttr(HI_HANDLE hVP, HI_UNF_VP_ATTR_S *pstAttr);

/**
 \brief Modifies the configuration of VP. CNcomment: \D0޸\C4VP\C5\E4\D6\C3CNend
 \attention \n
You are advised to obtain the current configuration by calling HI_UNF_VP_GetChAttr(), and modify parameter values as required.
CNcomment: \BD\A8\D2\E9\CFȵ\F7\D3\C3HI_UNF_VP_GetChAttr()\BB\F1ȡ\B5\B1ǰ\C5\E4\D6ã\AC\D4ٶԲ\CE\CA\FD\D7\F6\B1\D8Ҫ\D0޸\C4CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \param[in] pstAttr Pointer to VP attributes. For details, see :HI_UNF_VP_ATTR_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP \CA\F4\D0ԣ\AC\B2μ\FB:HI_UNF_VP_ATTR_S  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values: Fail to modify attributes . CNcomment: \D0޸\C4\CA\F4\D0\D4ʧ\B0\DCCNend
 \see \n
N/A CNcomment:\CE\DECNend
 */
HI_S32 HI_UNF_VP_SetAttr(HI_HANDLE hVP, const HI_UNF_VP_ATTR_S *pstAttr);

/**
 \brief Starts VP. CNcomment: VP\BF\AAʼ\D4\CB\D0\D0CNend
 \attention \n
After setting parameters including the codec, video input (VI), and video output (VO) parameters, you can start the video engine by calling this API to transmit or receive data over the Internet and display the local or remote video output.
CNcomment: \D4ڲ\CE\CA\FD׼\B1\B8\BAú󣬰\FC\C0\A8\B1\E0\BD\E2\C2\EB\C6\F7\A1\A2VI/VO\C9\E8\D6\C3\D5\FDȷ\BA󣬵\F7\D3ô˽ӿڿ\C9\D2\D4\C6\F4\B6\AF\CA\D3Ƶ\D2\FD\C7\E6\B5\C4\D4\CB\D0У\ACʵ\CF\D6\CD\F8\C2\E7\CAշ\A2\A1\A2\CF\D4ʾ\B1\BE\B5ء\A2Զ\B6\CB\CA\D3Ƶ\CA\E4\B3\F6CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values: VP fails to be started. CNcomment:  VP\BF\AAʼ\D4\CB\D0\D0ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_Start(HI_HANDLE hVP);

/**
 \brief Stops VP. CNcomment: VPֹͣ\D4\CB\D0\D0CNend
 \attention \n
After VP is started successfully, you can stop it by calling this API to freeze the screen or stop transmitting or receiving data over Internet. You can resume the VP by calling HI_UNF_VP_Start.
CNcomment: \D4\DAVP\D5\FD\B3\A3\C6\F4\B6\AF\D4\CB\D0к󣬿\C9\D2\D4ͨ\B9\FD\B4˽ӿ\DA\D4\DDͣ\D4\CB\D0У\ACʹ\BB\AD\C3涳\BDᡢ\CD\F8\C2\E7\CAշ\A2\D4\DDͣ\A1\A3\BF\C9\D2Ե\F7\D3\C3HI_UNF_VP_Start\BBָ\B4\D4\CB\D0\D0CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values: VP fails to be started. CNcomment: VP\BF\AAʼ\D4\CB\D0\D0ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_Stop(HI_HANDLE hVP);

/**
 \brief Previews the local video over VP. CNcomment: VP\BF\AAʼԤ\C0\C0\B1\BE\B5\D8\CA\D3ƵCNend
 \attention \n
After the VI and hLocalWin parameters are set, you can preview the local video by calling this API.
CNcomment: \D4\DAVI\BA\CDhLocalWin׼\B1\B8\BA\C3֮\BA󣬿\AAʼԤ\C0\C0\B1\BE\B5\D8\CA\D3ƵCNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values: VP fails to be started. CNcomment: VP\BF\AAʼ\D4\CB\D0\D0ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_StartPreView(HI_HANDLE hVP);

/**
 \brief Stops previewing the local video over VP. CNcomment: VPԤ\C0\C0\B1\BE\B5\D8\CA\D3ƵCNend
 \attention \n
When a local video is previewed over VP, you can stop previewing the video by calling this API.
CNcomment: \D4\DAVPԤ\C0\C0\B1\BE\B5\D8\CA\D3Ƶ\BA󣬵\F7\D3\C3ֹͣԤ\C0\C0CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FACNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other values: VP fails to be started. CNcomment: \C6\E4\CB\FC  VP\BF\AAʼ\D4\CB\D0\D0ʧ\B0\DCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_StopPreView(HI_HANDLE hVP);

/**
 \brief Starts remote VP. CNcomment: VP\C6\F4\B6\AFԶ\B6\CB  CNend
 \attention \n
Starts remote VP, this interface enables vp start sending local video to remote, or receiving remote video.
CNcomment: \C6\F4\B6\AFԶ\B6ˣ\AC\BF\C9\D2Ե\A5\B6\C0\C6\F4\B6\AF\B7\A2\CBͱ\BE\B5\D8\CA\D3Ƶ\B5\BDԶ\B6ˣ\AC\BB\F2\BD\D3\CA\D5Զ\B6\CB\CA\D3Ƶ  CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FA  CNend
 \param[in] enRmtMode remote mode CNcomment: Զ\B6\CBģʽ  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB  CNend
 \retval Other values: VP fails to be started. CNcomment: VP\D4\CB\D0\D0ʧ\B0\DC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_StartRemote(HI_HANDLE hVP, HI_UNF_VP_REMOTE_MODE_E enRmtMode);

/**
 \brief Stops remote VP. CNcomment: VPֹͣԶ\B6\CB  CNend
 \attention \n
Stops remote VP, this interface enables vp stop sending local video to remote, or receiving remote video.
CNcomment: ֹͣԶ\B6ˣ\AC\BF\C9\D2Ե\A5\B6\C0ֹͣ\B7\A2\CBͱ\BE\B5\D8\CA\D3Ƶ\B5\BDԶ\B6ˣ\AC\BB\F2ֹͣ\BD\D3\CA\D5Զ\B6\CB\CA\D3Ƶ  CNend
 \param[in] hVP VP handle CNcomment: VP \BE\E4\B1\FA  CNend
 \param[in] enRmtMode remote mode CNcomment: Զ\B6\CBģʽ  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB  CNend
 \retval Other values: VP fails to be started. CNcomment: VPֹͣʧ\B0\DC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_StopRemote(HI_HANDLE hVP, HI_UNF_VP_REMOTE_MODE_E enRmtMode);

/**
 \brief Configs RTCP over VP. CNcomment: VP\C5\E4\D6\C3RTCP  CNend
 \attention \n
When VP has been created, you can config RTCP to enable and config RTCP sending frequency by calling this API.
CNcomment: \D4ڴ\B4\BD\A8VP\BA󣬵\F7\D3øýӿ\DA\C5\E4\D6\C3RTCP\A3\AC\BF\C9\D2\D4ʹ\C4\DC\D2Լ\B0\B5\F7\BD\DARTCP\B7\A2\B0\FCƵ\C2\CACNend
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FACNend
 \param[out] pstRtcpCfg Pointer to config RTCP information, refer to HI_UNF_VP_RTCP_CFG_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP RTCP\C5\E4\D6\C3\D0\C5Ϣ\A3\AC\B2μ\FB:HI_UNF_VP_RTCP_CFG_S  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other value CNcomment: \C6\E4\CB\FCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_ConfigRtcp(HI_HANDLE hVP, HI_UNF_VP_RTCP_CFG_S *pstRtcpCfg);

/**
 \brief Gets network statistics information over VP. CNcomment: VP\BB\F1ȡ\CD\F8\C2\E7ͳ\BC\C6\D0\C5ϢCNend
 \attention \n
When VP has been started, you can get network statistics information to config parameter of video encoder by calling this API.
CNcomment: \D4\DA\D4\CB\D0\D0VP\BA󣬵\F7\D3øýӿڻ\F1ȡ\CD\F8\C2\E7ͳ\BC\C6\D0\C5Ϣ\D2Ե\F7\D5\FB\B1\E0\C2\EB\C6\F7\B2\CE\CA\FDCNend
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FACNend
 \param[out] pstNetStatics Pointer to network statistics information of VP, refer to HI_UNF_VP_NET_STA_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP\CD\F8\C2\E7ͳ\BC\C6\D0\C5Ϣ\A3\AC\B2μ\FB:HI_UNF_VP_NET_STA_S  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other value CNcomment: \C6\E4\CB\FCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_GetNetStatics(HI_HANDLE hVP, HI_UNF_VP_NET_STA_S *pstNetStatics);

/**
 \brief Gets VENC handle. CNcomment: \BB\F1ȡVENC\BE\E4\B1\FA  CNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FA  CNend
 \param[out] phVenc Pointer to VENC handle. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVENC\BE\E4\B1\FA  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB  CNend
 \retval Other value CNcomment: \C6\E4\CB\FC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_GetVencHandle(HI_HANDLE hVp, HI_HANDLE *phVenc);

/**
 \brief Gets AVPLAY handle that play remote video. CNcomment: \BB\F1ȡ\B2\A5\B7\C5Զ\B6\CB\CA\D3Ƶ\B5\C4AVPLAY\BE\E4\B1\FA  CNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FA  CNend
 \param[out] phAvplay Pointer to AVPLAY handle. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACAVPLAY\BE\E4\B1\FA  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB  CNend
 \retval Other value CNcomment: \C6\E4\CB\FC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_GetAvplayHandle(HI_HANDLE hVp, HI_HANDLE *phAvplay);

/**
 \brief Start record stream. CNcomment: \BF\AAʼ¼\D6\C6\C2\EB\C1\F7  CNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FA  CNend
 \param[in] enRecordFmt Record stream format. CNcomment: ¼\D6\C6\C2\EB\C1\F7\B8\F1ʽ\C0\E0\D0\CD  CNend
 \param[in] enRecordType Record type. CNcomment: ¼\D6\C6\C0\E0\D0\CD  CNend
 \param[in] ucFullName Record stream full name, full directory included. CNcomment: ¼\D6\C6\C2\EB\C1\F7\C3\FB\B3ƣ\AC\B4\F8\CD\EA\D5\FB·\BE\B6  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB  CNend
 \retval Other value CNcomment: \C6\E4\CB\FC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_StartRecord(HI_HANDLE hVP, HI_UNF_VP_REMOTE_MODE_E enRecordType,
                                 HI_UNF_VP_RECORD_FORMAT_E enRecordFmt, HI_CHAR * ucFullName);

/**
 \brief Stop record stream. CNcomment: ֹͣ¼\D6\C6\C2\EB\C1\F7  CNend
 \attention \n
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FA  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FD  CNend
 \retval Other value CNcomment: \C6\E4\CB\FC  CNend
 \see \n
N/A CNcomment: \CE\DE  CNend
 */
HI_S32 HI_UNF_VP_StopRecord(HI_HANDLE hVP);


/**
 \brief Gets video statistics information over VP. CNcomment: VP\BB\F1ȡ\CA\D3Ƶͳ\BC\C6\D0\C5ϢCNend
 \param[in] hVP VP handle CNcomment: VP\BE\E4\B1\FACNend
 \param[out] pstNetStatics Pointer to video statistics information of VP, refer to HI_UNF_VP_NET_STA_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACVP\CA\D3Ƶͳ\BC\C6\D0\C5Ϣ  CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6CNend
 \retval ::HI_ERR_VP_INVALID_PARA The input parameter is invalid. CNcomment: \CE\DEЧ\B5\C4\CA\E4\C8\EB\B2\CE\CA\FDCNend
 \retval ::HI_ERR_VP_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EBCNend
 \retval Other value CNcomment: \C6\E4\CB\FCCNend
 \see \n
N/A CNcomment: \CE\DECNend
 */
HI_S32 HI_UNF_VP_GetVideoStatics(HI_HANDLE hVP, HI_UNF_VP_VIDEO_STATICS_S *pstVideoStatics);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif
