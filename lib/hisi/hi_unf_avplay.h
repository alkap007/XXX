/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_avplay.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/21
  Description   :
  History       :
  1.Date        : 2009/12/21
    Author      : sdk
    Modification: Created file

*******************************************************************************/
/**
 * \file
 * \brief Describes the information about the audio/video player (AVPLAY) module.
          CNcomment:\CCṩAVPLAY\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */
#ifndef __HI_UNF_AVPLAY_H__
#define __HI_UNF_AVPLAY_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/*********************************error  macro******************************************/
/*************************** Structure Definition ****************************/
/** \addtogroup      AVPLAY */
/** @{ */  /** <!-- [AVPLAY] */

/**Highest priority of the video decoder*/
/**CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B5\C4\D7\EE\B4\F3\D3\C5\CFȼ\B6 */
#define HI_UNF_VCODEC_MAX_PRIORITY  16


/**Defines the buffer ID required in an AVPLAY.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\D6\D0\D0\E8Ҫ\B5\C4BufferIDö\BE\D9\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_BUFID_E
{
    HI_UNF_AVPLAY_BUF_ID_ES_VID  = 0,       /**<ID of the buffer for storing the video elementary streams (ESs) played by an AVPLAY*//**<CNcomment: AV\B2\A5\B7\C5\C6\F7ES\CA\D3ƵBuffer ID. */
    HI_UNF_AVPLAY_BUF_ID_ES_AUD,            /**<ID of the buffer for storing the audio ESs played by an AVPLAY*//**<CNcommentAV\B2\A5\B7\C5\C6\F7ES\D2\F4ƵBuffer ID.*/
    HI_UNF_AVPLAY_BUF_ID_ES_AUD_AD,         /**<ID of the buffer for storing the AD audio ESs played by an AVPLAY*//**<CNcommentAV\B2\A5\B7\C5\C6\F7AD ES\D2\F4ƵBuffer ID.*/
    HI_UNF_AVPLAY_BUF_ID_ES_VID_HDR_BL,     /**<ID of the buffer for storing the HDR BL video elementary streams (ESs) played by an AVPLAY*//**<CNcomment: AV\B2\A5\B7\C5\C6\F7HDR BL֡Buffer ID. */
    HI_UNF_AVPLAY_BUF_ID_ES_VID_HDR_EL,     /**<ID of the buffer for storing the HDR EL video elementary streams (ESs) played by an AVPLAY*//**<CNcomment: AV\B2\A5\B7\C5\C6\F7HDR EL֡Buffer ID. */
    HI_UNF_AVPLAY_BUF_ID_ES_VID_HDR_DL,     /**<ID of the buffer for storing the HDR BL+EL video elementary streams (ESs) played by an AVPLAY*//**<CNcomment: AV\B2\A5\B7\C5\C6\F7HDR BL+EL֡Buffer ID. */
    HI_UNF_AVPLAY_BUF_ID_BUTT
} HI_UNF_AVPLAY_BUFID_E;

/**Defines the type of a media channel.*/
/**CNcomment:\B6\A8\D2\E5ý\CC\E5ͨ\B5\C0\C0\E0\D0\CD. */
typedef enum hiUNF_AVPLAY_MEDIA_CHAN
{
    HI_UNF_AVPLAY_MEDIA_CHAN_AUD  = 0x01,  /**<Audio channel*//**<CNcomment: \D2\F4Ƶͨ\B5\C0 */
    HI_UNF_AVPLAY_MEDIA_CHAN_VID  = 0x02,  /**<Video channel*//**<CNcomment: \CA\D3Ƶͨ\B5\C0 */

    HI_UNF_AVPLAY_MEDIA_CHAN_BUTT = 0x8
} HI_UNF_AVPLAY_MEDIA_CHAN_E;

/**Defines the type of an input stream interface.*/
/**CNcomment:\B6\A8\D2\E5\CA\FD\BE\DD\CA\E4\C8\EB\C1\F7\BDӿ\DA\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_STREAM_TYPE_E
{
    HI_UNF_AVPLAY_STREAM_TYPE_TS = 0,   /**<Transport stream (TS)*//**<CNcomment:TS\C2\EB\C1\F7 */
    HI_UNF_AVPLAY_STREAM_TYPE_ES,       /**<ES stream*//**<CNcomment:ES\C2\EB\C1\F7 */

    HI_UNF_AVPLAY_STREAM_TYPE_BUTT
} HI_UNF_AVPLAY_STREAM_TYPE_E;

/**Defines the stream attributes.*/
/**CNcomment:\B6\A8\D2\E5\C2\EB\C1\F7\CA\F4\D0ԵĽṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_STREAM_ATTR_S
{
    HI_UNF_AVPLAY_STREAM_TYPE_E enStreamType;   /**<Stream type*//**<CNcomment:\C2\EB\C1\F7\C0\E0\D0\CD */

    HI_U32                      u32VidBufSize;  /**<Video buffer size*//**<CNcomment: \CA\D3Ƶ\BB\BA\B3\E5\B4\F3С */
    HI_U32                      u32AudBufSize;  /**<Audio buffer size*//**<CNcomment: \D2\F4Ƶ\BB\BA\B3\E5\B4\F3С */

} HI_UNF_AVPLAY_STREAM_ATTR_S;

/**Supported synchronization control mode*/
/**CNcomment:֧\B3ֵ\C4ͬ\B2\BD\BF\D8\D6\C6ģʽ */
typedef enum hiUNF_SYNC_REF_E
{
    HI_UNF_SYNC_REF_NONE = 0, /**<Free playing without synchronization*//**<CNcomment: \D7\D4\D3ɲ\A5\B7\C5 */
    HI_UNF_SYNC_REF_AUDIO,    /**<Audio-based synchronization*//**<CNcomment: \D2\D4\D2\F4ƵΪ׼ */
    HI_UNF_SYNC_REF_VIDEO,    /**<Video-based synchronization*//**<CNcomment: \D2\D4\CA\D3ƵΪ׼ */
    HI_UNF_SYNC_REF_PCR,      /**<Program Clock Reference (PCR)-based synchronization*//**<CNcomment: \D2\D4PCR\A3\A8Program Clock Reference\A3\A9Ϊ׼ */
    HI_UNF_SYNC_REF_SCR,      /**<System Clock Reference (SCR)-based synchronization*//**<CNcomment: \D2\D4SCR (System Clock Reference) Ϊ׼ */

    HI_UNF_AVPLAY_SYNC_REF_BUTT
} HI_UNF_SYNC_REF_E;

/**Defines the status of a buffer.*/
/**CNcomment:\B6\A8\D2\E5ʹ\D3õĻ\BA\B3\E5\C7\F8״̬ö\BE\D9\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_BUF_STATE_E
{
    HI_UNF_AVPLAY_BUF_STATE_EMPTY = 0,   /**<The buffer is idle.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\BF\D5\CF\D0 */
    HI_UNF_AVPLAY_BUF_STATE_LOW,         /**<The buffer usage is too low.*//**<CNcomment: \BB\BA\B3\E5\C7\F8ռ\D3\C3\C2ʹ\FD\B5\CD */
    HI_UNF_AVPLAY_BUF_STATE_NORMAL,      /**<The buffer works normally.*//**<CNcomment: \BB\BA\B3\E5\C7\F8ʹ\D3\C3\D5\FD\B3\A3 */
    HI_UNF_AVPLAY_BUF_STATE_HIGH,        /**<The buffer usage is too high.*//**<CNcomment: \BB\BA\B3\E5\C7\F8ռ\D3\C3\C2ʹ\FD\B8\DF */
    HI_UNF_AVPLAY_BUF_STATE_FULL,        /**<The buffer is full.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\D2\D1\C2\FA */

    HI_UNF_AVPLAY_BUF_STATE_BUTT
}HI_UNF_AVPLAY_BUF_STATE_E;

/**Defines the type of pts channel.*/
/** CNcomment:\B6\A8\D2\E5PTSͨ\B5\C0\C0\E0\D0\CD */
typedef enum hiUNF_SYNC_PTS_CHAN_E
{
    HI_UNF_SYNC_PTS_CHAN_VID,   /**<Video pts channel.*//**<CNcomment:\CA\D3ƵPTSͨ\B5\C0 */
    HI_UNF_SYNC_PTS_CHAN_AUD,   /**<Audio pts channel.*//**<CNcomment:\D2\F4ƵPTSͨ\B5\C0 */
    HI_UNF_SYNC_PTS_CHAN_PCR,   /**<Pcr channel.*//**<CNcomment:PCRͨ\B5\C0 */

    HI_UNF_SYNC_PTS_CHAN_BUTT
}HI_UNF_SYNC_PTS_CHAN_E;

/**Defines the parameters of pts jump.*/
/** CNcomment:\B6\A8\D2\E5PTS\CC\F8\B1\E4\B2\CE\CA\FD\B5Ľṹ\CC\E5 */
typedef struct hiUNF_SYNC_PTSJUMP_PARAM_S
{
    HI_UNF_SYNC_PTS_CHAN_E  enPtsChan;  /**<Pts channel.*//**<CNcomment:PTSͨ\B5\C0 */
    HI_BOOL                 bLoopback;  /**<Loopback or not.*//**<CNcomment:\CAǷ񻷻\D8 */
    HI_U32                  u32FirstPts;/**<The first pts.*//**<CNcomment:\B5\DAһ\B8\F6PTS */
    HI_U32                  u32FirstValidPts;/**<The first valid pts.*//**<CNcomment:\B5\DAһ\B8\F6\D3\D0ЧPTS */
    HI_U32                  u32CurSrcPts;   /**<The current src pts.*//**<CNcomment:\B5\B1ǰԭʼPTS */
    HI_U32                  u32CurPts;      /**<The current pts.*//**<CNcomment:\B5\B1ǰPTS */
    HI_U32                  u32LastSrcPts;  /**<The last src pts.*//**<CNcomment:\C9\CFһ\B8\F6ԭʼPTS */
    HI_U32                  u32LastPts;     /**<The last pts.*//**<CNcomment:\C9\CFһ\B8\F6PTS */
}HI_UNF_SYNC_PTSJUMP_PARAM_S;

typedef enum hiUNF_SYNC_PROC_E
{
    HI_UNF_SYNC_PROC_DISCARD,       /**<*Discard*//**<CNcomment:\B6\AA֡*/
    HI_UNF_SYNC_PROC_REPEAT,        /**<*Repeat*//**<CNcomment:\D6ظ\B4֡*/
    HI_UNF_SYNC_PROC_PLAY,          /**<*Play*//**<CNcomment:\B2\A5\B7\C5*/
    HI_UNF_SYNC_PROC_QUICKOUTPUT,   /**<*Quickoutput*//**<CNcomment:\BF\EC\CA\E4\B3\F6*/
    HI_UNF_SYNC_PROC_TPLAY,         /**<*Tplay*//**<CNcomment:\CCؼ\BC\B2\A5\B7\C5*/
    HI_UNF_SYNC_PROC_CONTINUE,      /**<*Continue*//**<CNcomment:\BC\CC\D0\F8*/
    HI_UNF_SYNC_PROC_BLOCK,         /**<*Block*//**<CNcomment:\D7\E8\C8\FB*/

    HI_UNF_SYNC_PROC_BUTT
}HI_UNF_SYNC_PROC_E;

typedef struct hiUNF_SYNC_VID_TPLAYTIME_S
{
    HI_U32              u32PrivDispTime;    /**<This displaytime is for pvr smooth tplay*//**<CNcomment:\B4\CB\CF\D4ʾʱ\BC\E4\CA\CA\D3\C3\D3\DApvr\C1\F7\B3\A9\B2\A5\B7\C5*/
    HI_U32              u32Pts;             /**<The fram info PTS*//**<CNcomment:֡\D0\C5ϢPTS*/
    HI_UNF_SYNC_PROC_E  enSyncProc;         /**<*Sync results*//**<CNcomment:֡ͬ\B2\BD\BD\E1\B9\FB*/
}HI_UNF_SYNC_VID_TPLAYTIME_S;

/**Defines the parameters of synchronization status change*/
/** CNcomment:\B6\A8\D2\E5ͬ\B2\BD״̬\B1\E4\B8\FC\B2\CE\CA\FD\B5Ľṹ\CC\E5 */
typedef struct hiUNF_SYNC_STAT_PARAM_S
{
     HI_S32          s32VidAudDiff;     /**<The diffrence between video and audio frames*//**<CNcomment: \D2\F4\CA\D3Ƶ\B2\EEֵ */
     HI_S32          s32VidPcrDiff;     /**<The diffrence between video frame and pcr*//**<CNcomment: \CA\D3ƵPCR\B2\EEֵ */
     HI_S32          s32AudPcrDiff;     /**<The diffrence between audio frame and pcr*//**<CNcomment: \D2\F4ƵPCR\B2\EEֵ */
     HI_U32          u32VidLocalTime;   /**<Local video synchronization reference time*//**<CNcomment: \CA\D3Ƶ\B1\BE\B5\D8ʱ\BC\E4 */
     HI_U32          u32AudLocalTime;   /**<Local audio synchronization reference time*//**<CNcomment: \D2\F4Ƶ\B1\BE\B5\D8ʱ\BC\E4 */
     HI_U32          u32PcrLocalTime;   /**<Local pcr synchronization reference time*//**<CNcomment: PCR\B1\BE\B5\D8ʱ\BC\E4 */
}HI_UNF_SYNC_STAT_PARAM_S;

/**Defines the parameters of pcr and stc info*/
/** CNcomment:\B6\A8\D2\E5PCR \BA\CDSTC\D0\C5Ϣ\B5Ľṹ\CC\E5 */
typedef struct hiUNF_SYNC_PCR_STC_INFO_S
{
     HI_U64          u64PcrValue;     /**<the value of PCR*//**<CNcomment:PCRֵ */
     HI_U64          u64StcValue;     /**<The value of STC*//**<CNcomment:STCֵ */
}HI_UNF_SYNC_PCR_STC_INFO_S;

/*Type of the event callback function*/
/**CNcomment: \CA¼\FE\BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_EVENT_E
{
    HI_UNF_AVPLAY_EVENT_EOS,                   /**<The end of stream (EOS) operation is performed, NULL*//**<CNcomment: EOSִ\D0н\E1\CA\F8, NULL.*/
    HI_UNF_AVPLAY_EVENT_STOP,                  /**<The stop operation is performed, NULL*//**<CNcomment: STOPִ\D0н\E1\CA\F8, NULL.*/
    HI_UNF_AVPLAY_EVENT_RNG_BUF_STATE,         /**<Status change of the media buffer queue, HI_UNF_AVPLAY_BUF_STATE_E*//**<CNcomment: ý\CC建\B4\E6\B6\D3\C1\D0״̬\B1仯, HI_UNF_AVPLAY_BUF_STATE_E.*/
    HI_UNF_AVPLAY_EVENT_NORM_SWITCH,           /**<Standard switch, HI_UNF_NORMCHANGE_PARAM_S*//**<CNcomment: \D6\C6ʽ\C7л\BB, HI_UNF_NORMCHANGE_PARAM_S .*/
    HI_UNF_AVPLAY_EVENT_FRAMEPACKING_CHANGE,   /**<3D Frame packing change, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E*//**<CNcomment: 3D֡\C0\E0\D0ͱ仯, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E .*/
    HI_UNF_AVPLAY_EVENT_NEW_VID_FRAME,         /**<New video frame will be rendered, indicates the new video frame that can be sent to display, HI_UNF_VIDEO_FRAME_INFO_S*//**<CNcomment: \D0\C2\CB\CD\CF\D4\CA\D3Ƶ֡, HI_UNF_VIDEO_FRAME_INFO_S .*/
    HI_UNF_AVPLAY_EVENT_NEW_AUD_FRAME,         /**<New audio frame, HI_UNF_AO_FRAMEINFO_S*//**<CNcomment: \D0\C2\D2\F4Ƶ֡, HI_UNF_AO_FRAMEINFO_S .*/
    HI_UNF_AVPLAY_EVENT_NEW_USER_DATA,         /**<New video user data, HI_UNF_VIDEO_USERDATA_S*//**<CNcomment: \D0\C2\CA\D3Ƶ\D3û\A7\CA\FD\BE\DD, HI_UNF_VIDEO_USERDATA_S .*/
    HI_UNF_AVPLAY_EVENT_GET_AUD_ES,            /**<New audio ES data, HI_UNF_ES_BUF_S*//**<CNcomment: \D0\C2\D2\F4ƵES\CA\FD\BE\DD, HI_UNF_ES_BUF_S .*/
    HI_UNF_AVPLAY_EVENT_IFRAME_ERR,            /**<I frame decode error*//**<CNcomment: \BD\E2\C2\EBI֡\B4\ED\CE\F3 .*/
    HI_UNF_AVPLAY_EVENT_SYNC_PTS_JUMP,         /**<Pts Jump, HI_UNF_SYNC_PTSJUMP_PARAM_S * *//**<CNcomment: PTS\CC\F8\B1\E4, HI_UNF_SYNC_PTSJUMP_PARAM_S * .*/
    HI_UNF_AVPLAY_EVENT_SYNC_STAT_CHANGE,      /**<Synchronization status change, HI_UNF_SYNC_STAT_PARAM_S * *//**<CNcomment: ͬ\B2\BD״̬\B1\E4\B8\FC, HI_UNF_SYNC_STAT_PARAM_S * .*/
    HI_UNF_AVPLAY_EVENT_VID_BUF_STATE,         /**<Status change of the media buffer queue, HI_UNF_AVPLAY_EVENT_VID_BUF_STATE*//**<CNcomment: \CA\D3Ƶ\BB\BA\B4\E6\B6\D3\C1\D0״̬\B1仯, HI_UNF_AVPLAY_EVENT_VID_BUF_STATE */
    HI_UNF_AVPLAY_EVENT_AUD_BUF_STATE,         /**<Status change of the media buffer queue, HI_UNF_AVPLAY_EVENT_AUD_BUF_STATE*//**<CNcomment: \D2\F4Ƶ\BB\BA\B4\E6\B6\D3\C1\D0״̬\B1仯, HI_UNF_AVPLAY_EVENT_AUD_BUF_STATE */
    HI_UNF_AVPLAY_EVENT_VID_UNSUPPORT,         /**<The video stream is unsupport*//**<CNcomment: \CA\D3Ƶ\C2\EB\C1\F7\B2\BB֧\B3\D6*/
    HI_UNF_AVPLAY_EVENT_VID_ERR_RATIO,         /**<frame error ratio *//**<CNcomment: ͼ\CF\F1֡\B3\F6\B4\ED\B1\C8\C0\FD*/
    HI_UNF_AVPLAY_EVENT_AUD_INFO_CHANGE,       /**<audio info change, HI_UNF_ACODEC_STREAMINFO_S *//**<CNcomment: \D2\F4Ƶ\D0\C5Ϣ\B1仯\A3\ACHI_UNF_ACODEC_STREAMINFO_S*/
    HI_UNF_AVPLAY_EVENT_AUD_UNSUPPORT,         /**<unsupported audio *//**<CNcomment: \B2\BB֧\B3ֵ\C4\D2\F4Ƶ*/
    HI_UNF_AVPLAY_EVENT_AUD_FRAME_ERR,         /**<audio frame error *//**<CNcomment: \D2\F4Ƶ֡\B3\F6\B4\ED*/
    HI_UNF_AVPLAY_EVENT_VID_ERR_TYPE,          /**<the setting vid codec type is error, HI_UNF_VCODEC_TYPE_E*//**<CNcomment: \C9\E8\D6õ\C4\CA\D3ƵЭ\D2\E9\C0\E0\D0ʹ\ED\CE\F3, HI_UNF_VCODEC_TYPE_E*/
    HI_UNF_AVPLAY_EVENT_FIRST_FRAME_DISPLAYED, /**<the first deocded frame have been displayed out by the tv.*//**<CNcomment: \B5\DAһ֡\D2ѱ\BB\CF\D4ʾ*/
    HI_UNF_AVPLAY_EVENT_VID_ERR_FRAME,         /**<vid frame decode error.*/ /**<CNcomment: \BD\E2\C2\EB\CA\D3Ƶ֡\B4\ED\CE\F3*/
    HI_UNF_AVPLAY_EVENT_STATUS_REPORT,         /**<avplay status info, HI_UNF_AVPLAY_STATUS_INFO_S*/ /**<CNcomment: \B2\A5\B7\C5\C6\F7״̬\D0\C5Ϣ*/
    HI_UNF_AVPLAY_EVENT_VID_FRAME_INFO,        /**<Video frame status info, HI_UNF_VIDEO_FRM_STATUS_INFO_S*/ /**<CNcomment: \CA\D3Ƶ֡״̬\D0\C5Ϣ*/
    HI_UNF_AVPLAY_EVENT_VID_START_POS,         /**<the peek frame first pts, HI_U32*/ /**<CNcomment: peek֡pts, HI_U32*/
    HI_UNF_AVPLAY_EVENT_FRAME_DISPLAY_TIME,    /**<Estimated time of display, HI_UNF_VIDEO_FRM_DISPLAY_TIME_S*/ /**<CNcomment: \CA\D3Ƶ֡Ԥ\CF\D4ʾʱ\BC\E4, HI_UNF_VIDEO_FRM_DISPLAY_TIME_S*/
    HI_UNF_AVPLAY_EVENT_HDCPSTRATEGY_CHANGE,   /**<HDCP strategy change, HI_UNF_AVPLAY_HDCPSTRATEGY_PARAM_S*//**<CNcomment:HDCP \B1\A3\BB\A4\B2\DF\C2Ըı\E4, HI_UNF_AVPLAY_HDCPSTRATEGY_PARAM_S .*/
    HI_UNF_AVPLAY_EVENT_GET_PCR_STC_VALUE,     /**<Pcr and Stc info,HI_UNF_SYNC_PCR_STC_INFO_S*//**<CNcomment:Pcr\BA\CDStcֵ,HI_UNF_SYNC_PCR_STC_INFO_S.*/
    HI_UNF_AVPLAY_EVENT_VID_LASTFRMFLAG,       /**<Report vid last frame flag*//**<CNcomment: \C9ϱ\A8vdec\D7\EE\BA\F3һ֡\B1\EA־*/
    HI_UNF_AVPLAY_EVENT_VID_TPLAYTIME_SYNC,    /**<Trick play is to adjust the video frame,HI_UNF_SYNC_VID_TPLAYTIME_S*//**<CNcomment: \CCؼ\BC\B2\A5\B7\C5ʱ\B6\D4\CA\D3Ƶ֡\BD\F8\D0е\F7\D5\FB,HI_UNF_SYNC_VID_TPLAYTIME_S*/
    HI_UNF_AVPLAY_EVENT_NEW_PICTURE_DECODED, /**<New video frame is decoded, indicates that the video decoder present a new video frame\A3\ACHI_UNF_VIDEO_FRAME_INFO_S*//**<CNcomment: \D0½\E2\C2\EB\CA\D3Ƶ֡, HI_UNF_VIDEO_FRAME_INFO_S .*/
    HI_UNF_AVPLAY_EVENT_BUTT
} HI_UNF_AVPLAY_EVENT_E;

/**Mode of processing the buffer overflow*/
/**CNcomment: \BB\BA\B3\E5\D2\E7\B3\F6\B4\A6\C0\ED\C0\E0\D0\CD  */
typedef enum hiUNF_AVPLAY_OVERFLOW_E
{
    HI_UNF_AVPLAY_OVERFLOW_RESET,              /**<Reset during overflow*//**<CNcomment: \D2\E7\B3\F6ʱ\BD\F8\D0и\B4λ  */
    HI_UNF_AVPLAY_OVERFLOW_DISCARD,            /**<Discard during overflow*//**<CNcomment: \D2\E7\B3\F6ʱ\BD\F8\D0ж\AA\C6\FA  */
    HI_UNF_AVPLAY_OVERFLOW_BUTT
} HI_UNF_AVPLAY_OVERFLOW_E;

/**Defines the parameters of HDCP output control */
/**CNcomment: \B6\A8\D2\E5HDCP\CA\E4\B3\F6\BF\D8\D6\C6\CF\E0\B9ز\CE\CA\FD*/
typedef struct hiUNF_AVPLAY_HDCPSTRATEGY_PARAM_S
{
    HI_U32 u32ImageWidth;                     /**<Width of image allowed by HDCP strategy*/ /**<CNcomment: \B5\B1ǰ\C2\EB\C1\F7 HDCP \B2\DF\C2\D4\D4\CA\D0\ED\CA\E4\B3\F6\B5\C4ͼ\CF\F1\B7ֱ\E6\C2ʿ\ED\B6\C8(\BD\F6\D4\DAtvpģʽ\CF\C2\D3\D0Ч)*/
    HI_U32 u32ImageHeight;                    /**<Height of image allowed by HDCP strategy*/ /**<CNcomment: \B5\B1ǰ\C2\EB\C1\F7 HDCP \B2\DF\C2\D4\D4\CA\D0\ED\CA\E4\B3\F6\B5\C4ͼ\CF\F1\B7ֱ\E6\C2ʸ߶\C8(\BD\F6\D4\DAtvpģʽ\CF\C2\D3\D0Ч)*/
}HI_UNF_AVPLAY_HDCPSTRATEGY_PARAM_S;

/**Defines the type of the event callback function.*/
/**CNcomment: \B6\A8\D2\E5\CA¼\FE\BBص\F7\BA\AF\CA\FDö\BE\D9\C0\E0\D0\CD */
typedef HI_S32 (*HI_UNF_AVPLAY_EVENT_CB_FN)(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_U32 u32Para);

/**Defines the type of the event callback function.*/
/**CNcomment: \B6\A8\D2\E5\CA¼\FE\BBص\F7\BA\AF\CA\FDö\BE\D9\C0\E0\D0\CD */
typedef HI_S32 (*HI_UNF_AVPLAY_EVENT_CB_FN64)(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent, HI_VOID *pPara);

/**Defines the attribute of audio security.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\B0\B2ȫ\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_AVPLAY_AUD_SECURITY_ATTR_S
{
    HI_BOOL    bEnable; /**<Audio dmx channel is security mode or not*//**<CNcomment: \D2\F4ƵDMXͨ\B5\C0\CAǷ\F1Ϊ\B0\B2ȫģʽ*/
}HI_UNF_AVPLAY_AUD_SECURITY_ATTR_S;

/**Defines the attribute ID of an AVPLAY.*/
/**CNcomment: \B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\CA\F4\D0\D4IDö\BE\D9\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_ATTR_ID_E
{
    HI_UNF_AVPLAY_ATTR_ID_STREAM_MODE = 0,  /**<Playing mode, HI_UNF_AVPLAY_ATTR_S*//**<CNcomment: \B2\A5\B7\C5ģʽ, HI_UNF_AVPLAY_ATTR_S.*/

    HI_UNF_AVPLAY_ATTR_ID_ADEC,             /**<Audio attribute, HI_UNF_ACODEC_ATTR_S*//**<CNcomment: \D2\F4Ƶ\CA\F4\D0\D4, HI_UNF_ACODEC_ATTR_S.*/
    HI_UNF_AVPLAY_ATTR_ID_VDEC,             /**<Video attribute, HI_UNF_VCODEC_ATTR_S*//**<CNcomment: \CA\D3Ƶ\CA\F4\D0\D4, HI_UNF_VCODEC_ATTR_S.*/

    HI_UNF_AVPLAY_ATTR_ID_AUD_PID,          /**<Audio packet identifier (PID), HI_U32*//**<CNcomment: \D2\F4ƵPID, HI_U32.*/
    HI_UNF_AVPLAY_ATTR_ID_VID_PID,          /**<Video PID, HI_U32*//**<CNcomment: \CA\D3ƵPID, HI_U32.*/
    HI_UNF_AVPLAY_ATTR_ID_PCR_PID,          /**<PCR PID, HI_U32*//**<CNcomment: PCR PID, HI_U32.*/

    HI_UNF_AVPLAY_ATTR_ID_SYNC,             /**<Synchronization attribute, HI_UNF_SYNC_ATTR_S*//**<CNcomment: ͬ\B2\BD\CA\F4\D0\D4, HI_UNF_SYNC_ATTR_S.*/
    HI_UNF_AVPLAY_ATTR_ID_AFD,              /**<Whether to enable the active format descriptor (AFD), HI_BOOL* *//**<CNcomment: AFD \CAǷ\F1\BF\AA\C6\F4\A3\AC HI_BOOL * .*/
    HI_UNF_AVPLAY_ATTR_ID_OVERFLOW,         /**<Overflow processing type, HI_UNF_AVPLAY_OVERFLOW_E* *//**<CNcomment: \D2\E7\B3\F6\B4\A6\C0\ED\C0\E0\D0\CD , HI_UNF_AVPLAY_OVERFLOW_E * .*/

    HI_UNF_AVPLAY_ATTR_ID_MULTIAUD,         /**<Multiple audio attribute,  HI_UNF_AVPLAY_MULTIAUD_ATTR_S **//**<CNcomment: \B6\E0\D2\F4\B9\EC\CA\F4\D0\D4, HI_UNF_AVPLAY_MULTIAUD_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_FRMRATE_PARAM,    /**<Frame Rate Parameter, HI_UNF_AVPLAY_FRMRATE_PARAM_S * *//**<CNcomment:֡\C2ʲ\CE\CA\FD,HI_UNF_AVPLAY_FRMRATE_PARAM_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_FRMPACK_TYPE,     /**<3D Frame Packing Type, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E * *//**<CNcomment:3D֡\B5Ĵ\F2\B0\FC\C0\E0\D0\CD,HI_UNF_VIDEO_FRAME_PACKING_TYPE_E * .*/
    HI_UNF_AVPLAY_ATTR_ID_LOW_DELAY,        /**<Low Delay Attr, HI_UNF_AVPLAY_LOW_DELAY_ATTR_S * *//**<CNcomment: \B5\CD\D1\D3ʱ\CA\F4\D0\D4 , HI_UNF_AVPLAY_LOW_DELAY_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_TVP,              /**<Trusted Video Path Attr, HI_UNF_AVPLAY_TVP_ATTR_S * *//**<CNcomment: \B0\B2ȫ\CA\D3Ƶͨ·\CA\F4\D0\D4 , HI_UNF_AVPLAY_TVP_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_AD,               /**<MS12 Attr, HI_UNF_AVPLAY_AD_ATTR_S * *//**<CNcomment: MS12ͨ·\CA\F4\D0\D4 , HI_UNF_AVPLAY_AD_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_HDR,              /**<HDR Attr, HI_UNF_AVPLAY_HDR_ATTR_S * *//**<CNcomment: HDRͨ·\CA\F4\D0\D4 , HI_UNF_AVPLAY_HDR_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_AUD_SECURITY,     /**<Dmx audio channel security mode, HI_UNF_AVPLAY_AUD_SECURITY_ATTR_S * *//**<CNcomment: \D2\F4Ƶ\B0\B2ȫ\CA\F4\D0\D4 , HI_UNF_AVPLAY_AUD_SECURITY_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_AD_PID,           /**<AD program id*/ /**<CNcomment: AD\C1\F7PID,HI_S32*/
    HI_UNF_AVPLAY_ATTR_ID_START_POSITION,   /**< Set video start play position, HI_UNF_AVPLAY_START_POSITION_ATTR_S * *//**<CNcomment: \C9\E8\D6\C3\CA\D3Ƶ\C6𲥵㣬 HI_UNF_AVPLAY_START_POSITION_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_EXTERNAL_AUDIO,   /**< Set external audio codec attr, HI_UNF_ACODEC_ATTR_S * *//**<CNcomment: \C9\E8\D6\C3\CDⲿ\D2\F4Ƶ\CA\F4\D0ԣ\AC HI_UNF_ACODEC_ATTR_S * .*/
    HI_UNF_AVPLAY_ATTR_ID_BUTT
} HI_UNF_AVPLAY_ATTR_ID_E;

/**Defines the stream type of HDR.*/
/**CNcomment: \B6\A8\D2\E5DOLBY HDR\C2\EB\C1\F7\C0\E0\D0\CD */
typedef enum hiUNF_AVPLAY_HDR_STREAM_TYPE_E
{
    HI_UNF_AVPLAY_HDR_STREAM_TYPE_DL_SINGLE_VES = 0,    /**<Dolby Vision Dual layer Single VES Format*/ /**<CNcomment: \B5\A5\C1\F7˫\B2\E3\B8\F1ʽ.*/
    HI_UNF_AVPLAY_HDR_STREAM_TYPE_DL_DUAL_VES,          /**<Dolby Vision Dual Layer Dual VES Format*/ /**<CNcomment: ˫\C1\F7˫\B2\E3\B8\F1ʽ.*/
    HI_UNF_AVPLAY_HDR_STREAM_TYPE_SL_VES,               /**<Dolby Vision Single Layer VES Format*/ /**<CNcomment: \B5\A5\C1\F7\B5\A5\B2\E3\B8\F1ʽ.*/
    HI_UNF_AVPLAY_HDR_STREAM_TYPE_BUTT
} HI_UNF_AVPLAY_HDR_STREAM_TYPE_E;

/**Defines the low delay mode.*/
/**CNcomment: \B6\A8\D2\E5\B5\CD\D1\D3ʱģʽ */
typedef enum
{
    HI_UNF_AVPLAY_LOW_DELAY_FIRST = 0,      /**<Low delay first*/ /**<CNcomment: \B5\CD\D1\D3ʱ\D3\C5\CF\C8.*/
    HI_UNF_AVPLAY_LOW_DELAY_SMOOTH_LEVEL1, /**<Smooth first ,the delaytime is longer than LOW_DELAY_FIRST mode*/ /**<CNcomment: \C1\F7\B3\A9\D0\D4\D3\C5\CF\C8.\BB\E1\CE\FE\C9\FC\D1\D3ʱ\A3\AC\CF\E0\B1\C8FIRST\D1\D3ʱ\B8\FC\B4\F3*/
    HI_UNF_AVPLAY_LOW_DELAY_SMOOTH_LEVEL2, /**<Smooth than level 1, the delaytime is longer than LOW_DELAY_FIRST mode*/ /**<CNcomment: \C1\F7\B3\A9\D0\D4\D3\C5\D3\DAlevel1.\BB\E1\CE\FE\C9\FC\D1\D3ʱ\A3\AC\CF\E0\B1\C8FIRST\D1\D3ʱ\B8\FC\B4\F3*/
    HI_UNF_AVPLAY_LOW_DELAY_MODE_BUTT
} HI_UNF_AVPLAY_LOW_DELAY_MODE_E;

/**Defines the attribute of low delay.*/
/**CNcomment: \B6\A8\D2\E5\B5\CD\D1\D3ʱ\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_AVPLAY_LOW_DELAY_ATTR_S
{
    HI_BOOL               bEnable;          /**<Is low delay enable or not*//**<CNcomment: \B5\CD\D1\D3ʱ\CAǷ\F1ʹ\C4\DC*/
    HI_UNF_AVPLAY_LOW_DELAY_MODE_E enMode;  /**<Low delay mode*//**<CNcomment: \B5\CD\D1\D3ʱģʽ*/
}HI_UNF_AVPLAY_LOW_DELAY_ATTR_S;

/**Defines the attribute of trust video path.*/
/**CNcomment: \B6\A8\D2尲ȫ\CA\D3Ƶͨ·\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_AVPLAY_TVP_ATTR_S
{
    HI_BOOL               bEnable;  /**<Is trusted video path enable or not*//**<CNcomment: \B0\B2ȫ\CA\D3Ƶͨ·\CAǷ\F1ʹ\C4\DC*/
}HI_UNF_AVPLAY_TVP_ATTR_S;

/**Defines the audio/video synchronization .*/
/**CNcomment: \B6\A8\D2\E5\D2\F4\CA\D3Ƶͬ\B2\BD\B5\F7\D5\FB\C7\F8\BC\E4 */
typedef struct hiUNF_SYNC_REGION_S
{
    HI_S32                s32VidPlusTime;        /**<Plus time range during video synchronization*//**<CNcomment: \CA\D3Ƶͬ\B2\BD\B3\ACǰ\B5\C4ʱ\BC䷶Χ */
    HI_S32                s32VidNegativeTime;    /**<Negative time range during video synchronization*//**<CNcomment: \CA\D3Ƶͬ\B2\BD\C2\E4\BA\F3\B5\C4ʱ\BC䷶Χ */
    HI_BOOL               bSmoothPlay;           /**<Slow playing enable*//**<CNcomment: \C2\FD\B7\C5ʹ\C4\DC */
} HI_UNF_SYNC_REGION_S;

/**Defines the audio/video synchronization attributes.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4\CA\D3Ƶͬ\B2\BD\CA\F4\D0\D4 */
typedef struct hiUNF_SYNC_ATTR_S
{
    HI_UNF_SYNC_REF_E     enSyncRef;             /**<Audio-based synchronization, PCR-based synchronization, and free playing without synchronization*//**<CNcomment: \D2\F4ƵΪ׼\A3\ACPCRΪ׼\A3\AC\D7\D4\D3ɲ\A5\B7ŵ\C8 */
    HI_UNF_SYNC_REGION_S  stSyncStartRegion;     /**<Synchronization start region*//**<CNcomment: ͬ\B2\BD\C6\F0\B5\F7\C7\F8\BC\E4 */
    HI_UNF_SYNC_REGION_S  stSyncNovelRegion;     /**<Synchronization exception region*//**<CNcomment: ͬ\B2\BD\D2쳣\C7\F8\BC\E4 */
    HI_S32                s32VidPtsAdjust;       /**<Video presentation time stamp (PTS) adjustment*//**<CNcomment: \CA\D3ƵPTS\B5\F7\D5\FB */
    HI_S32                s32AudPtsAdjust;       /**<Audio PTS adjustment*//**<CNcomment: \D2\F4ƵPTS\B5\F7\D5\FB */

    HI_U32                u32PreSyncTimeoutMs;   /**<Pre-synchronization timeout, in ms*//**<CNcomment: Ԥͬ\B2\BD\B5ĳ\ACʱʱ\BC䣬\B5\A5λΪ\BA\C1\C3\EB */
    HI_BOOL               bQuickOutput;          /**<Fast output enable*//**<CNcomment: \BF\EC\CB\D9\CA\E4\B3\F6ʹ\C4\DC */
} HI_UNF_SYNC_ATTR_S;

/**Defines the playing attributes of an AVPLAY.*/
/**CNcomment: \B6\A8\D2\E5AV\B2\A5\B7\C5\CA\F4\D0\D4 */
typedef struct hiUNF_AVPLAY_ATTR_S
{
    HI_U32                       u32DemuxId;   /**<ID of the DEMUX used by an AVPLAY*//**<CNcomment: AVPLAY\CB\F9ʹ\D3õ\C4DEMUX ID \BD\F6\B5\B1\C2\EB\C1\F7\C0\E0\D0\CDΪTSʱ\D3\D0Ч */
    HI_UNF_AVPLAY_STREAM_ATTR_S  stStreamAttr; /**<Stream attributes*//**<CNcomment: \C2\EB\C1\F7\CA\F4\D0\D4 */
} HI_UNF_AVPLAY_ATTR_S;

/**Defines the synchronization status when an AVPLAY is running.*/
/**CNcomment: \B6\A8\D2岥\B7\C5\C6\F7\D4\CB\D0\D0״̬\D0\C5Ϣ\D6\D0ͬ\B2\BD״̬\D0\C5Ϣ\C0\E0\D0\CD */
typedef struct hiUNF_SYNC_STATUS_S
{
    HI_U32 u32FirstAudPts;    /**<PTS of the first audio frame*//**<CNcomment: \B5\DAһ\B8\F6\D2\F4Ƶ֡ PTS .*/
    HI_U32 u32FirstVidPts;    /**<PTS of the first video frame*//**<CNcomment: \B5\DAһ\B8\F6\CA\D3Ƶ֡ PTS .*/
    HI_U32 u32LastAudPts;     /**<PTS of the last audio frame*//**<CNcomment: \D7\EE\BD\FC\B2\A5\B7ŵ\C4һ\B8\F6\D2\F4Ƶ֡ PTS .*/
    HI_U32 u32LastVidPts;     /**<PTS of the last video frame*//**<CNcomment: \D7\EE\BD\FC\B2\A5\B7ŵ\C4һ\B8\F6\CA\D3Ƶ֡ PTS .*/
    HI_S32 s32DiffAvPlayTime; /**<Playing time difference between audio and video frames*//**<CNcomment: \D2\F4\CA\D3Ƶ \B2\A5\B7\C5ʱ\B2\EE .*/
    HI_U32 u32PlayTime;       /**<Playing time*//**<CNcomment: \B5\B1ǰ\D2Ѳ\A5\B7\C5ʱ\BC\E4 .*/
    HI_U32 u32LocalTime;      /**<Local synchronization reference time*//**<CNcomment: \B1\BE\B5\D8ͬ\B2\BD\B2ο\BCʱ\BC\E4 .*/
} HI_UNF_SYNC_STATUS_S;

/**Defines the status of a media buffer.*/
/**CNcomment:\B6\A8\D2\E5ý\CC建\B3\E5\C7\F8\B5\C4״̬\D0\C5Ϣ */
typedef struct hiUNF_AVPLAY_BUF_STATUS_S
{
    HI_U32 u32BufId;                /**<Media buffer ID*//**<CNcomment: ý\CC建\B3\E5 \B1\EAʶ */
    HI_U32 u32BufSize;              /**<Media buffer size*//**<CNcomment: ý\CC建\B3\E5\B4\F3С */
    HI_U32 u32BufRptr;              /*Read pointer of the media buffer. This pointer is valid when TSs are being played.*//**<CNcomment: ý\CC建\B3\E5\B6\C1ָ\D5\EB,Ts\B2\A5\B7\C5ʱ\D3\D0Ч */
    HI_U32 u32BufWptr;              /*Write pointer of the media buffer. This pointer is valid when TSs are being played.*//**<CNcomment: ý\CC建\B3\E5дָ\D5\EB,Ts\B2\A5\B7\C5ʱ\D3\D0Ч */
    HI_U32 u32UsedSize;             /**<Used size of the media buffer*//**<CNcomment: ý\CC建\B3\E5\D2\D1ʹ\D3ô\F3С */
    HI_U32 u32CurrentAvailableSize; /**<Current available size of the media buffer for HI_UNF_AVPLAY_GetBuf()*//**<CNcomment: ý\CC建\B3\E5\BF\C9ʹ\D3ô\F3С */
    HI_U32 u32FrameBufTime;         /**<Frame buffer time*//**<CNcomment: ֡\BB\BA\B3\E5ʱ\BC\E4 */
    HI_U32 u32FrameBufNum;          /**<The number of frames in frame buffer*//**<CNcomment: ֡\BB\BA\B3\E5\CA\FDĿ \BD\F6VIDEO\D3\D0Ч */
    HI_BOOL bEndOfStream;           /**<Flag to indicate end of stream*//**<CNcomment: \BB\BA\B3\E5\D6\D0\C2\EB\C1\F7\BD\E2\C2\EB\CD\EA\B1ϱ\EAʶ \BD\F6VIDEO\D3\D0Ч */
} HI_UNF_AVPLAY_BUF_STATUS_S;

/**Defines the playing status of an AVPLAY.*/
/**CNcomment:\B6\A8\D2\E5AV\B5Ĳ\A5\B7\C5״̬ */
typedef enum hiUNF_AVPLAY_STATUS_E
{
    HI_UNF_AVPLAY_STATUS_STOP = 0,  /**<Stop*/      /**<CNcomment: ֹͣ */
    HI_UNF_AVPLAY_STATUS_PREPLAY,   /**<Buffer*/    /**<CNcomment: \BB\BA\B3\E5 */
    HI_UNF_AVPLAY_STATUS_PLAY,      /**<Play*/      /**<CNcomment: \B2\A5\B7\C5 */
    HI_UNF_AVPLAY_STATUS_TPLAY,     /**<Trick play, such as fast forward and rewind*/   /**<CNcomment: TPlay, \BF\EC\BD\F8\BF\EC\CD\CB */
    HI_UNF_AVPLAY_STATUS_PAUSE,     /**<Pause*/     /**<CNcomment: \D4\DDͣ */
    HI_UNF_AVPLAY_STATUS_EOS,       /**<EOS*/       /**<CNcomment: \C2\EB\C1\F7\B2\A5\B7Ž\E1\CA\F8 */
    HI_UNF_AVPLAY_STATUS_SEEK ,     /**<Seek play*/ /**<CNcomment: \B6\A8λ\B2\A5\B7\C5 */

    HI_UNF_AVPLAY_STATUS_BUTT
} HI_UNF_AVPLAY_STATUS_E;

/**Defines the output value after the playing status of an AVPLAY is queried.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5״̬\B2\E9ѯ\CA\E4\B3\F6ֵ\C0\E0\D0\CD */
typedef struct hiUNF_AVPLAY_STATUS_INFO_S
{
    HI_UNF_SYNC_STATUS_S       stSyncStatus;      /**<Synchronization status*//**<CNcomment: ͬ\B2\BD״̬ */
    HI_UNF_AVPLAY_STATUS_E     enRunStatus;       /**<Running status*//**< CNcomment:\D4\CB\D0\D0״̬ */
    HI_U32                     u32VidFrameCount;  /**<Count of played video frames*//**<CNcomment: \CA\D3Ƶ\D2Ѳ\A5\B7\C5֡\CA\FD */
    HI_U32                     u32AuddFrameCount; /**<Count of played audio frames*//**<CNcomment: \D2\F4Ƶ\D2Ѳ\A5\B7\C5֡\CA\FD */
    HI_UNF_AVPLAY_BUF_STATUS_S stBufStatus[HI_UNF_AVPLAY_BUF_ID_BUTT]; /**<Status of the media buffer*//**<CNcomment:ý\CC建\B3\E5״̬ */
    HI_U32                     u32VidErrorFrameCount; /**<Number of error frames during video decoding*/ /**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\B4\ED\CE\F3֡\CA\FD */
    HI_U32                     u32AudErrorFrameCount; /**<Number of error frames during audio decoding*//**<CNcomment: \D2\F4Ƶ\BD\E2\C2\EB\B4\ED\CE\F3֡\CA\FD */
    HI_U32                     u32VidFrameDropCount; /**<Number of dropped video frame*/ /**<CNcomment: \CA\D3Ƶ\B2\A5\B7\C5\C6ڼ䶪֡\B8\F6\CA\FD*/
    HI_U32                     u32AudFrameDropCount; /**<Number of dropped audio frame*/ /**<CNcomment: \D2\F4Ƶ\B2\A5\B7\C5\C6ڼ䶪֡\B8\F6\CA\FD*/
} HI_UNF_AVPLAY_STATUS_INFO_S;

/**Defines the information about the playing program streams to be queried.*/
/**CNcomment: \B6\A8\D2岥\B7Ž\DAĿ\C1\F7\B2\E9ѯ\D0\C5Ϣ\C0\E0\D0\CD */
typedef struct hiUNF_AVPLAY_STREAM_INFO_S
{
    HI_UNF_VCODEC_STREAMINFO_S stVidStreamInfo; /**<Video stream information*//**<CNcomment:\CA\D3Ƶ\C1\F7\D0\C5Ϣ */
    HI_UNF_ACODEC_STREAMINFO_S stAudStreamInfo; /**<Audio stream information*//**<CNcomment:\D2\F4Ƶ\C1\F7\D0\C5Ϣ */
} HI_UNF_AVPLAY_STREAM_INFO_S;

/**Defines the information about an I frame.*//**CNcomment:\B6\A8\D2\E5I֡\CA\FD\BE\DD\D0\C5Ϣ\C0\E0\D0\CD */
typedef struct hiUNF_AVPLAY_I_FRAME_S
{
    HI_U8  *pu8Addr;    /**<User-state virtual address of a frame*//**<CNcomment:֡\CA\FD\BE\DD\D3û\A7̬\D0\E9\C4\E2\B5\D8ַ */
    HI_U32 u32BufSize; /**<Frame size, in byte*//**<CNcomment:֡\CA\FD\BEݴ\F3С\A3\AC\B5\A5λ\D7ֽ\DA */
    HI_UNF_VCODEC_TYPE_E enType;     /*Protocol type of a data segment*//**<CNcomment:\B8\C3Ƭ\CA\FD\BEݵ\C4Э\D2\E9\C0\E0\D0\CD */
    HI_UNF_VCODEC_EXTATTR_U unExtAttr; /**<Extra attribute for video format vc1 and vp6*//**<CNcomment:Ϊ\CA\D3Ƶ\B8\F1ʽvc1\BA\CDvp6\CC\ED\BCӵĶ\EE\CD\E2\CA\F4\D0\D4\D0\C5Ϣ*/
} HI_UNF_AVPLAY_I_FRAME_S;

/**Defines the decoder type. The occupied memory varies according to decoders.*/
/**CNcomment:\B6\A8\D2\E5\BD\E2\C2\EB\C6\F7\C0\E0\D0\CD \B2\BBͬ\C0\E0\D0͵Ľ\E2\C2\EB\C6\F7ռ\D3\C3\C4ڴ治ͬ */
typedef enum hiHI_UNF_VCODEC_DEC_TYPE_E
{
    HI_UNF_VCODEC_DEC_TYPE_NORMAL,            /**<Normal type.*//**<CNcomment:\C6\D5ͨ\C0\E0\D0\CD */

    /**<I frame decoding type. If an AVPLAY is used to decode I frames only (HI_UNF_AVPLAY_DecodeIFrame), you can select this type to reduce the memory usage.*/
    /**<CNcomment:I֡\BD\E2\C2\EB\C0\E0\D0\CD \C8\E7\B9\FBavplay\BD\F6\D3\C3\D3\DAI֡\BD\E2\C2\EB(HI_UNF_AVPLAY_DecodeIFrame) \C9\E8\D6\C3Ϊ\B4\CB\C0\E0\D0Ϳ\C9\D2Խ\DAʡ\C4ڴ\E6 */
    HI_UNF_VCODEC_DEC_TYPE_ISINGLE,

    HI_UNF_VCODEC_DEC_TYPE_BUTT
}HI_UNF_VCODEC_DEC_TYPE_E;

/**Defines the level of the protocol supported by the decoder. This value affects the number of frame buffers allocated by the normal decoder.
The greater the value, the more the required frame buffers.*/
/**CNcomment:\B6\A8\D2\E5\BD\E2\C2\EB\C6\F7֧\B3ֵ\C4Э\D2鼶\B1\F0 Ӱ\CF\ECNORMAL\C0\E0\D0ͽ\E2\C2\EB\C6\F7\B7\D6\C5\E4\B5\C4֡\B4\E6\B8\F6\CA\FD ֵԽ\B4\F3\D0\E8Ҫ\B5\C4֡\B4\E6\CA\FDĿԽ\B6\E0 */
typedef enum hiHI_UNF_VCODEC_PRTCL_LEVEL_E
{
    HI_UNF_VCODEC_PRTCL_LEVEL_MPEG = 0,     /**<All protocols except MVC *//**<CNcomment:\B3\FDMVC\CD\E2\B5\C4\CB\F9\D3\D0Э\D2\E9 */
    HI_UNF_VCODEC_PRTCL_LEVEL_H264 = 1,     /**<Same as HI_UNF_VCODEC_PRTCL_LEVEL_MPEG now *//**<CNcomment:\BA\CDHI_UNF_VCODEC_PRTCL_LEVEL_MPEG\CF\E0ͬ*/
    HI_UNF_VCODEC_PRTCL_LEVEL_MVC,
    HI_UNF_VCODEC_PRTCL_LEVEL_BUTT
}HI_UNF_VCODEC_PRTCL_LEVEL_E;

/**Defines the attributes when an AVPLAY enables the video decoder. The settings affect the memory occupied by the video decoder and decoding performance.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\B4\F2\BF\AA\CA\D3Ƶ\BD\E2\C2\EB\C6\F7ʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 Ӱ\CF\EC\CA\D3Ƶ\BD\E2\C2\EB\C6\F7ռ\D3\C3\C4ڴ\E6\B4\F3С\BC\B0\BD\E2\C2\EB\C4\DC\C1\A6 */
typedef struct hiHI_UNF_AVPLAY_OPEN_OPT_S
{
    HI_UNF_VCODEC_DEC_TYPE_E    enDecType;       /**<Decoder type.*//**<CNcomment:\BD\E2\C2\EB\C6\F7\C0\E0\D0\CD*/
    HI_UNF_VCODEC_CAP_LEVEL_E   enCapLevel;      /**<Maximum resolution supported by the decoder. This value affects the size of each frame buffer.*//**<CNcomment:\BD\E2\C2\EB\C6\F7֧\B3ֵ\C4\D7\EE\B4\F3\B7ֱ\E6\C2\CA Ӱ\CF\ECÿ\B8\F6֡\B4\E6\B5Ĵ\F3С */
    HI_UNF_VCODEC_PRTCL_LEVEL_E enProtocolLevel; /**<Supported protocol level. This value affects the number of frame buffers.*//**<CNcomment:֧\B3ֵ\C4Э\D2鼶\B1\F0 Ӱ\CF\EC֡\B4\E6\CA\FDĿ */
}HI_UNF_AVPLAY_OPEN_OPT_S;

/**Defines the attribute of MS12.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵMS12\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_AVPLAY_AD_ATTR_S
{
    HI_BOOL             bAdEnble;       /**<whether enable ad service (on/off)*/ /**<CNcomment: \CAǷ\F1ʹ\C4\DCAD.*/
    HI_BOOL             bAdToSomePort;  /**<whether enable ad only to some port,such as speaker/headphone etc*/ /**<CNcomment: \CAǷ\F1ʹ\C4\DC\CB\F9\D3\D0\CA\E4\B3\F6\B6\BC\BB\EC\D2\F4\A3\ACĬ\C8\CFΪfalse.*/
    HI_U32              u32AdPid;       /**<AD program id*/ /**<CNcomment: AD\C1\F7PID.*/
    HI_S16              s16AdBalance;   /**<AD Balance 0~-100 AD Volume attenuation percentage. 0~100 master Volume attenuation percentage*/ /**<CNcomment: 0~-100 \B8\A8\D2\F4\D2\F4\C1\BF˥\BC\F5\B0ٷֱ\C8, 0~100 \D6\F7\D2\F4\C1\BF˥\BC\F5\B0ٷֱ\C8*/
} HI_UNF_AVPLAY_AD_ATTR_S;

/**Defines the attribute of HDR.*/
/**CNcomment: \B6\A8\D2\E5HDR\CA\F4\D0Խṹ\CC\E5*/
typedef struct hiUNF_AVPLAY_HDR_ATTR_S
{
    HI_BOOL                           bEnable;          /**<Is Dolby HDR enable or not*/ /**<CNcomment: Dolby HDR\CAǷ\F1ʹ\C4\DC.*/
    HI_UNF_AVPLAY_HDR_STREAM_TYPE_E   enHDRStreamType;  /**<Dolby Vision VES Format*/ /**<CNcomment: Dolby HDR\C1\F7\C0\E0\D0\CD.*/
    HI_UNF_VCODEC_TYPE_E              enElType;         /**<Video encoding type*/ /**<CNcomment: EL\CA\D3Ƶ\B1\E0\C2\EB\C0\E0\D0\CD*/
    HI_UNF_AVPLAY_OPEN_OPT_S          stElCodecOpt;     /**<Video decoding option*/ /**<CNcomment: \CA\D3Ƶ\BD\E2\C2\EB\C4\DC\C1\A6\BC\B6\C9\E8\D6\C3*/
    HI_BOOL                           bCompatible;      /**<Dolby frame is compatible or not.*/ /**<CNcomment: Dolby֡\CAǷ\F1\BC\E6\C8\DD.*/
} HI_UNF_AVPLAY_HDR_ATTR_S;

/**Defines the video display mode after an AVPLAY is stopped.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7ֹͣʱ\CA\D3Ƶ\CF\D4ʾģʽ */
typedef enum hiUNF_AVPLAY_STOP_MODE_E
{
    HI_UNF_AVPLAY_STOP_MODE_STILL = 0,  /**<The last frame is still after an AVPLAY is stopped.*//**<CNcomment:stop\BA\F3\B1\A3\C1\F4\D7\EE\BA\F3һ֡ */
    HI_UNF_AVPLAY_STOP_MODE_BLACK = 1,  /**<The blank screen is displayed after an AVPLAY is stopped.*//**<CNcomment:stop\BA\F3\BA\DA\C6\C1 */
    HI_UNF_AVPLAY_STOP_MODE_BUTT
} HI_UNF_AVPLAY_STOP_MODE_E;


/**Defines the attributes when an AVPLAY is prestarted.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7Ԥ\C6\F4\B6\AFʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_PRESTART_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_PRESTART_OPT_S;

/**Defines the attributes when an AVPLAY is started.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\C6\F4\B6\AFʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_START_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_START_OPT_S;

/**Defines the attributes when an AVPLAY is prestoped.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7Ԥֹͣʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_PRESTOP_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_PRESTOP_OPT_S;


/**Defines the attributes when an AVPLAY is stopped.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7ֹͣʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_STOP_OPT_S
{
    /*
         s32Timeout: end of stream timeout
         s32Timeout = 0   Wait until streams are played in non-block mode, that is, the interface is returned immediately. CNcomment:\B7\C7\D7\E8\C8\FB\B5ȴ\FD\C2\EB\C1\F7\B2\A5\B7Ž\E1\CA\F8\A3\AC\C1\A2\BC\B4\B7\B5\BB\D8 CNend
         s32Timeout > 0   Block timeout, in ms, CNcomment:\D7\E8\C8\FB\B3\ACʱʱ\BC䣬\B5\A5λΪ\BA\C1\C3\EB CNend
         s32Timeout = -1  Infinite wait,CNcomment:\CE\DE\CF޵ȴ\FD CNend
     */
    HI_U32                    u32TimeoutMs;    /**<Timeout*//**<CNcomment:\B3\ACʱֵ */
    HI_UNF_AVPLAY_STOP_MODE_E enMode;          /**<Video display mode*//**<CNcomment:\CA\D3Ƶ\CF\D4ʾģʽ */
} HI_UNF_AVPLAY_STOP_OPT_S;

/*Defines the attributes when an AVPLAY is paused.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\D4\DDͣʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_PAUSE_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_PAUSE_OPT_S;

/**Defines the direction of tplay*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7TPLAY\B5ķ\BD\CF\F2 */
typedef enum hiUNF_AVPLAY_TPLAY_DIRECT_E
{
    HI_UNF_AVPLAY_TPLAY_DIRECT_FORWARD,     /**<Tplay forward*//**<CNcomment: \CF\F2ǰTPLAY. */
    HI_UNF_AVPLAY_TPLAY_DIRECT_BACKWARD,    /**<Tplay backward*//**<CNcomment: \CF\F2\BA\F3TPLAY. */
    HI_UNF_AVPLAY_TPLAY_DIRECT_BUTT

} HI_UNF_AVPLAY_TPLAY_DIRECT_E;

/**Defines the attributes when the playing mode of an AVPLAY is tplay.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7TPALYʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_TPLAY_OPT_S
{
    HI_UNF_AVPLAY_TPLAY_DIRECT_E    enTplayDirect;      /**<Tplay direction*//**<CNcomment: TPLAY\B7\BD\CF\F2 */
    HI_U32                          u32SpeedInteger;    /**<Integral part of tplay speed*//**<CNcomment: TPLAY\B1\B6\CA\FD\B5\C4\D5\FB\CA\FD\B2\BF\B7\D6 */
    HI_U32                          u32SpeedDecimal;    /**<Fractional part (calculated to three decimal places) of tplay speed*//**<CNcomment: TPLAY\B1\B6\CA\FD\B5\C4С\CA\FD\B2\BF\B7֣\AC\B1\A3\C1\F43λС\CA\FD */
} HI_UNF_AVPLAY_TPLAY_OPT_S;

/**Defines the attributes when an AVPLAY is resumed.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\BBָ\B4ʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_RESUME_OPT_S
{
    HI_U32       u32Reserved;
} HI_UNF_AVPLAY_RESUME_OPT_S;

/**Defines the attributes when an AVPLAY is reset.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\B8\B4λʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiAVPLAY_RESET_OPT_S
{
    HI_U32        u32SeekPtsMs;   /**<clear these datas which pts is smaller than u32SeekPtsMs in buffer *//**<CNcomment:\C7\E5\BF\D5buffer\C4\DAu32SeekPtsMs֮ǰ\B5\C4\CA\FD\BE\DD */
} HI_UNF_AVPLAY_RESET_OPT_S;

/**Defines the attributes when an AVPLAY is step.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7\B2\BD\BD\F8ʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_STEP_OPT_S
{
    HI_U32       u32Reserved;
}HI_UNF_AVPLAY_STEP_OPT_S;

/**Defines the attributes when an AVPLAY is in Flushing Stream Status.*/
/**CNcomment:\B6\A8\D2\E5AV\B2\A5\B7\C5\C6\F7Flush Streamʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_FLUSH_STREAM_OPT_S
{
    HI_U32          u32Reserved;
}HI_UNF_AVPLAY_FLUSH_STREAM_OPT_S;

/**Defines the attributes of multiple audio.*/
/**CNcomment:\B6\A8\D2\E5\B6\E0\D2\F4\B9\EC\CA\F4\D0Խṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_MULTIAUD_ATTR_S
{
    HI_U32                  u32PidNum;      /**<the number of Audio PID *//**< CNcomment:\D2\F4ƵPID\B8\F6\CA\FD */
    HI_U32                  *pu32AudPid;    /**<Pointer to the array of audio PID*//**< CNcomment:ָ\CF\F2PID\CA\FD\D7\E9\B5\C4ָ\D5\EB */
    HI_UNF_ACODEC_ATTR_S    *pstAcodecAttr; /**<Pointer to the array of audio attribute*//**< CNcomment:ָ\CF\F2\D2\F4Ƶ\CA\F4\D0\D4\CA\FD\D7\E9\B5\C4ָ\D5\EB */
}HI_UNF_AVPLAY_MULTIAUD_ATTR_S;

/**Defines the source of frame rate.*/
/**CNcomment: \B6\A8\D2\E5֡\C2\CA\C0\B4Դ\C0\E0\D0͵\C4ö\BE\D9 */
typedef enum hiUNF_AVPLAY_FRMRATE_TYPE_E
{
    HI_UNF_AVPLAY_FRMRATE_TYPE_PTS,         /**<Use the frame rate calculates from PTS*//**<CNcomment: \B2\C9\D3\C3PTS\BC\C6\CB\E3֡\C2\CA */
    HI_UNF_AVPLAY_FRMRATE_TYPE_STREAM,      /**<Use the frame rate comes from stream*//**<CNcomment: \B2\C9\D3\C3\C2\EB\C1\F7\D0\C5Ϣ\D6е\C4֡\C2\CA */
    HI_UNF_AVPLAY_FRMRATE_TYPE_USER,        /**<Use the frame rate set by user*//**<CNcomment: \B2\C9\D3\C3\D3û\A7\C9\E8\D6õ\C4֡\C2\CA */
    HI_UNF_AVPLAY_FRMRATE_TYPE_USER_PTS,    /**<Use the frame rate set by user until the 2nd I frame comes, then use the frame rate calculates from PTS*//**<CNcomment: \B5ڶ\FE\B8\F6I֡\C0\B4֮ǰ\B2\C9\D3\C3\D3û\A7\C9\E8\D6õ\C4֡\C2ʣ\AC֮\BA\F3\B8\F9\BE\DDPTS\BC\C6\CB\E3֡\C2\CA */
    HI_UNF_AVPLAY_FRMRATE_TYPE_BUTT
}HI_UNF_AVPLAY_FRMRATE_TYPE_E;

/**Defines the parameter of frame rate.*/
/**CNcomment: \B6\A8\D2\E5֡\C2\CA\CA\F4\D0Բ\CE\CA\FD\B5Ľṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_FRMRATE_PARAM_S
{
    HI_UNF_AVPLAY_FRMRATE_TYPE_E    enFrmRateType;  /**<The source of frame rate*//**<CNcomment: ֡\C2\CA\C0\B4Դ\C0\E0\D0\CD */
    HI_UNF_VCODEC_FRMRATE_S         stSetFrmRate;   /**<Setting frame rate*//**<CNcomment: \C9\E8\D6õ\C4֡\C2\CA */
}HI_UNF_AVPLAY_FRMRATE_PARAM_S;

/**Defines commond to get vdec information, the parameter is HI_UNF_AVPLAY_VDEC_INFO_S.*/
/**CNcomment: \BB\F1ȡ\BD\E2\C2\EB\C6\F7\D0\C5Ϣ\C3\FC\C1\B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_UNF_AVPLAY_VDEC_INFO_S */
#define HI_UNF_AVPLAY_GET_VDEC_INFO_CMD         0x20
/**Defines commond to set TPLAY parameter, the parameter is HI_UNF_AVPLAY_TPLAY_OPT_S.*/
/**CNcomment: \C9\E8\D6\C3TPLAY\B2\CE\CA\FD\C3\FC\C1\B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_UNF_AVPLAY_TPLAY_OPT_S*/
#define HI_UNF_AVPLAY_SET_TPLAY_PARA_CMD        0x21
/**Defines commond to set special control information of stream, the parameter is HI_UNF_AVPLAY_CONTROL_INFO_S*/
/**CNcomment: \D3\C3\C0\B4\C9\E8\D6\C3һЩ\C2\EB\C1\F7\B5\C4\CC\D8\CA\E2\BF\D8\D6\C6\D0\C5Ϣ\A3\AC\B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_UNF_AVPLAY_CONTROL_INFO_S*/
#define HI_UNF_AVPLAY_SET_CTRL_INFO_CMD         0x22

/**Defines commond to set video sample type, HI_BOOL *, HI_TRUE: force Progressive, HI_FALSE: auto recognise Progressive or Interlance */
/**CNcomment: \C9\E8\D6\C3\CA\D3Ƶ\D6\F0\D0\D0\D0\C5Ϣ, HI_TRUE: ǿ\D6\C6\D6\F0\D0\D0, HI_FALSE: \D7Զ\AFʶ\B1\F0\D6\F0\B8\F4\D0\D0*/
#define HI_UNF_AVPLAY_SET_PROGRESSIVE_CMD       0x23

/**Defines commond to set video color space, the parameter is HI_UNF_COLOR_SPACE_E*/
/**CNcomment: \C9\E8\D6\C3\CA\D3Ƶɫ\B2ʿռ\E4, \B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_UNF_COLOR_SPACE_E*/
#define HI_UNF_AVPLAY_SET_COLORSPACE_CMD        0x24

/**Defines commond to set dpb full control, HI_BOOL* ,HI_TRUE:force delete min poc frame when dpb is full,HI_FALSE:return error when dpb is full*/
/**CNcomment:\C9\E8\D6\C3dpb\C2\FA\B5\C4ʱ\BA\F2\B5Ĵ\A6\C0\ED\B2\DF\C2\D4, \B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_BOOL*/
#define HI_UNF_AVPLAY_SET_DPBFULL_CTRL_CMD      0x25

/***fix  videophone scene by AVPLAY ,  format MJPEG**/
#define HI_UNF_AVPLAY_SET_SCENE_MODE_CMD        0x26

/**Defines commond to keep SPS/PPS(VDEC) info in vfmw,set it before avplay reset. HI_BOOL* ,HI_TRUE:keep SPS/PPS,HI_FALSE:not keep*/
/**CNcomment:\B1\A3\C1\F4SPS/PPS\D0\C5Ϣ\B5\BDVFMW, AVPLAY resetǰ\B5\F7\D3á\A3\B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_BOOL*/
#define HI_UNF_AVPLAY_KEEP_SPS_PPS_INFO_CMD     0x27

/***Defines commond to get vdec handle, the parameter is HI_U32**/
#define HI_UNF_AVPLAY_GET_VDEC_HANDLE_CMD       0x28

/**Defines commond to set video last frame, the parameter is HI_BOOL*/
/**CNcomment: \C9\E8\D6\C3VDEC\D7\EE\BA\F3һ֡\B1\EA־, \B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_BOOL*/
#define HI_UNF_AVPLAY_SET_VDEC_LSTFRAME_CMD     0x29

/**Defines commond to set video last frame, the parameter is HI_U32,range is 0-0xffffffff*/
/**CNcomment: \C9\E8\D6\C3VDEC POC\E3\D0ֵ, \B2\CE\CA\FD\B6\D4Ӧ\C0\E0\D0\CDΪHI_U32 \B7\B6Χ\CA\C70-0xffffffff*/
#define HI_UNF_AVPLAY_SET_VDEC_POC_THRESHOLD_CMD 0x2c

/**Defines the mode of videophone.*/
/**CNcomment: \B6\A8\D2\E5Videophone \B3\A1\BE\B0\C0\E0\D0͵\C4ö\BE\D9 */
typedef enum hiUNF_AVPLAY_SCENE_MODE_E
{
   HI_UNF_AVPLAY_SCENE_MODE_NORMAL,     /**<Normal scene of non-voip*//**<CNcomment: \B7ǿ\C9\CAӵ\E7\CAӳ\A1\BE\B0 */
   HI_UNF_AVPLAY_SCENE_MODE_VIDEOPHONE_PREVIEW,   /**<Voip scene of the local end*//**<CNcomment: \BF\C9\CAӵ绰\BD\FC\B6˳\A1\BE\B0 */
   HI_UNF_AVPLAY_SCENE_MODE_VIDEOPHONE_REMOTE,   /**<Voip scene of the remote end*//**<CNcomment: \BF\C9\CAӵ绰Զ\B6˳\A1\BE\B0 */
   HI_UNF_AVPLAY_SCENE_MODE_VIRTUAL_REAL,     /**<Virtual reality *//**<CNcomment: VR\B3\A1\BE\B0 */
   HI_UNF_AVPLAY_SCENE_MODE_BUTT,
} HI_UNF_AVPLAY_SCENE_MODE_E;


/**Defines the type of AVPLAY invoke.*/
/**CNcomment: \B6\A8\D2\E5AVPLAY Invoke\B5\F7\D3\C3\C0\E0\D0͵\C4ö\BE\D9 */
typedef enum hiUNF_AVPLAY_INVOKE_E
{
    HI_UNF_AVPLAY_INVOKE_ACODEC  = 0,   /**<Invoke commond to control audio codec*//**<CNcomment: \BF\D8\D6\C6\D2\F4Ƶ\BD\E2\C2\EB\C6\F7\B5\C4Invoke\B5\F7\D3\C3 */
    HI_UNF_AVPLAY_INVOKE_VCODEC,        /**<Invoke commond to control video codec, HI_CODEC_VIDEO_CMD_S*//**<CNcomment: \BF\D8\D6\C6\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B5\C4Invoke\B5\F7\D3\C3 */
    HI_UNF_AVPLAY_INVOKE_GET_PRIV_PLAYINFO, /**<Invoke commond to get private play infomation,the parameter is HI_UNF_AVPLAY_PRIVATE_STATUS_INFO_S*//**<CNcomment: \BB\F1ȡ˽\D3в\A5\B7\C5\D0\C5Ϣ\B5\C4Invoke\B5\F7\D3ã\AC \B2\CE\CA\FDΪHI_UNF_AVPLAY_PRIVATE_STATUS_INFO_S * */
    HI_UNF_AVPLAY_INVOKE_SET_DISP_OPTIMIZE_FLAG, /**Defines commond to set Display Optimize Flag, The Parameter is HI_U32, 1: Enable, 0: Disable */
    HI_UNF_AVPLAY_INVOKE_GET_GLOBAL_PLAYINFO,   /**<Get global play information of avplay*//**<CNcomment: \BB\F1ȡAVPLAYȫ\BEֲ\A5\B7\C5\D0\C5Ϣ */
    HI_UNF_AVPLAY_INVOKE_SET_SYNC_MODE,  /**<Invoke commond to set sync mode, HI_U32, 0 normal sync, 1 use sync replace frc*//**<CNcomment: \C9\E8\D6\C3ͬ\B2\BDģʽ\A3\ACHI_U32\A3\AC0: \D5\FD\B3\A3ģʽ, 1: ʹ\D3\C3ͬ\B2\BD\CC\E6\B4\FA֡\C2\CAת\BB\BB*/
    HI_UNF_AVPLAY_INVOKE_SET_TPLAY_AUDIO_ENABLE, /**<Invoke commond to enable audio tplay(support 0.25/0.5/0.9/0.95/1.05/1.1/1.25/1.5/2), HI_U32, 1: enable audio tplay, 0: disable audio tplay*//**<CNcomment: ʹ\C4\DC\D2\F4Ƶ\B1\B6\CBٲ\A5\B7\C5(֧\B3\D6 0.25/0.5/0.9/0.95/1.05/1.1/1.25/1.5/2)\A3\ACHI_U32\A3\AC1: ʹ\C4\DC\D2\F4Ƶ\B1\B6\CB\D9, 0: ȥʹ\C4\DC\D2\F4Ƶ\B1\B6\CB\D9*/
    HI_UNF_AVPLAY_INVOKE_SET_TPLAY_RESET_ENABLE,  /**<Invoke commond to set tplay mode, HI_U32, 0 do not reset avplay, 1 reset avplay*//**<CNcomment:\C9\E8\D6\C3tplay ģʽ\A3\ACHI_U32,  0: \B2\BBreset avplay, 1: reset avplay*/
    HI_UNF_AVPLAY_INVOKE_BUTT
} HI_UNF_AVPLAY_INVOKE_E;

/**Defines the decoding information of video codec.*/
/**CNcomment: \B6\A8\D2\E5VDEC\BD\E2\C2\EB\D0\C5Ϣ\B5Ľṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_VDEC_INFO_S
{
    HI_U32                  u32DispFrmBufNum;   /**<the number of display frame*//**<CNcomment: \CF\D4ʾ֡\B4\E6\B8\F6\CA\FD */
    HI_U32                  u32FieldFlag;       /**<The encoding mode of image, 0 frame mode, 1 filed mode*//**<CNcomment: ͼ\CF\F1\B1\E0\C2뷽ʽ, 0 ֡ģʽ\A3\AC1 \B3\A1ģʽ */
    HI_UNF_VCODEC_FRMRATE_S stDecFrmRate;      /**<decoding frame rate*//**<CNcomment: \BD\E2\C2\EB֡\C2\CA */
    HI_U32                  u32UndecFrmNum;     /**<the number of undecoded frame*//**<CNcomment: δ\BD\E2\C2\EB֡\B8\F6\CA\FD */
}HI_UNF_AVPLAY_VDEC_INFO_S;

/**Defines the private status information.*/
/**CNcomment: \B6\A8\D2\E5AVPLAY˽\D3\D0״̬\D0\C5Ϣ */
typedef struct hiUNF_AVPLAY_PRIVATE_STATUS_INFO_S
{
    HI_U32 u32LastPts;   /**<PTS of the last audio or video frame*/ /**<CNcomment: \D7\EE\BD\FC\B2\A5\B7ŵ\C4һ\B8\F6\D2\F4Ƶ֡ PTS\BB\F2\CA\D3ƵPTS*/
    HI_U32 u32LastPlayTime; /**< PlayTime of the last audio or video frame */ /**<CNcomment: \D7\EE\BD\FC\B2\A5\B7ŵ\C4һ\B8\F6\D2\F4Ƶ֡ PlayTime\BB\F2\CA\D3PlayTime  */
    HI_U32 u32DispOptimizeFlag; /**<Display Optimize Flag,1: Enable, 0: Disable*//**<CNcomment: \CF\D4ʾ\D3Ż\AF\B1\EA־*/
} HI_UNF_AVPLAY_PRIVATE_STATUS_INFO_S;

/**Defines the special control information of stream.*/
/**CNcomment: \B6\A8\D2\E5\CC\D8\CA\E2\BF\D8\D6\C6\D0\C5Ϣ */
typedef struct hiUNF_AVPLAY_CONTROL_INFO_S
{
    HI_U32 u32IDRFlag;               /**<IDR frame Flag, 1 means IDR(instantaneous decoding refresh) frame.*/ /**<CNcomment: \CAǷ\F1\CA\C7IDR(\B4\CB֡ǰ\BA\F3\CE޲ο\BC\B9\D8ϵ)֡\A3\AC1\B1\EDʾ\CA\C7*/
    HI_U32 u32BFrmRefFlag;           /**<Whether B frame is refer frame, 1 means B frame is refer frame.*/ /**<CNcomment: B֡\CAǷ\F1\CAǲο\BC֡\A3\AC1\B1\EDʾ\CA\C7*/
    HI_U32 u32ContinuousFlag;        /**<Whether send frame is continusous. 1 means continusous*/ /**<CNcomment: ֡\CAǷ\F1\C1\AC\D0\F8\A3\AC1\B1\EDʾ\C1\AC\D0\F8*/
    HI_U32 u32BackwardOptimizeFlag;  /**<The Backward Optimize Flag*//**<CNcomment: \BF\EC\CD\CB\D3Ż\AFʹ\C4ܱ\EA־.*/
    HI_U32 u32DispOptimizeFlag;      /**<Display Optimize Flag,1: Enable, 0: Disable*//**<CNcomment: \CF\D4ʾ\D3Ż\AF\B1\EA־*/
}HI_UNF_AVPLAY_CONTROL_INFO_S;

/**Defines the parameter when the stream is send by HI_UNF_AVPLAY_PutBufEx.*/
/**CNcomment: \B6\A8\D2尴PutBufExģʽ\CB\CD\C2\EB\C1\F7\B5Ĳ\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiUNF_AVPLAY_PUTBUFEX_OPT_S
{
    HI_BOOL bEndOfFrm;      /**<whether this package of stream is the end of one frame*//**<CNcomment: \B8ð\FC\C2\EB\C1\F7\CAǷ\F1Ϊһ֡\B5\C4\D7\EE\BA\F3һ\B0\FC */
    HI_BOOL bContinue;      /**<whether this package of stream is contnued with the last package*//**<CNcomment: \B8ð\FC\C2\EB\C1\F7\CAǷ\F1\D3\EB֮ǰ\C1\AC\D0\F8 */
}HI_UNF_AVPLAY_PUTBUFEX_OPT_S;

typedef struct hiUNF_AVPLAY_GLOBAL_PLAY_INFO_S
{
    HI_U32 u32ContentCount;
} HI_UNF_AVPLAY_GLOBAL_PLAY_INFO_S;

typedef struct hiUNF_AVPLAY_VIDEO_FRAME_INFO_S
{
    HI_U32                              u32Width;           /**<Width of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\BF\ED*/
    HI_U32                              u32Height;          /**<Height of the source picture*/ /**<CNcomment: ԭʼͼ\CF\F1\B8\DF*/
    HI_U32                              u32AspectWidth;     /**<aspect ratio: width*/ /**<CNcomment:\BF\ED\B8߱\C8֮\BF\EDֵ */
    HI_U32                              u32AspectHeight;    /**<aspect ratio: height*/ /**<CNcomment:\BF\ED\B8߱\C8֮\B8\DFֵ */
    HI_U32                              u32fpsInteger;     /**<Integral part of the frame rate (in frame/s)*/ /**<CNcomment: \C2\EB\C1\F7\B5\C4֡\C2ʵ\C4\D5\FB\CA\FD\B2\BF\B7\D6, fps */
    HI_U32                              u32fpsDecimal;     /**<Fractional part (calculated to three decimal places) of the frame rate (in frame/s)*/
    HI_BOOL                             bProgressive;       /**<Sampling type (progressive or interlaced)*/ /**<CNcomment: \B2\C9\D1\F9\B7\BDʽ(\D6\F0\D0\D0/\B8\F4\D0\D0) */
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E   enFramePackingType; /**<3D frame packing type*/
} HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S;

/**Defines the avplay video start position .*/
/**CNcomment: \CA\D3Ƶ\C6𲥵\E3\CA\F4\D0\D4 */
typedef struct hiUNF_AVPLAY_START_POSITION_ATTR_S
{
    HI_U32                              u32StartPosPts;     /**<Start play Pts*/ /**<CNcomment: \C6\F0\B2\A5Pts*/
    HI_U32                              u32IdrPts;          /**<Instantaneous Decoding Refresh Pts */ /**<CNcomment: I֡Pts*/
}HI_UNF_AVPLAY_START_POSITION_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      AVPLAY */
/** @{ */  /** <!-- [AVPLAY] */

/**
\brief Initializes the AVPLAY module.CNcomment:\B3\F5ʼ\BB\AFAVPLAYģ\BF\E9 CNend
\attention \n
Before calling ::HI_UNF_AVPLAY_Create to create an AVPLAY, you must call this application programming interface (API).
CNcomment \D4ڵ\F7\D3\C3AVPLAYģ\BF\E9\C6\E4\CB\FB\BDӿ\DAǰ\A3\ACҪ\C7\F3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA CNend
\param  N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NOT_EXIST There is no AVPLAY. CNcomment:AVPLAY\C9豸\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_AVPLAY_NOT_DEV_FILE  The file is not an AVPLAY file. CNcomment:AVPLAY\B7\C7\C9豸 CNend
\retval ::HI_ERR_AVPLAY_DEV_OPEN_ERR  An AVPLAY fails to be started. CNcomment:AVPLAY\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Init(HI_VOID);

/**
\brief Deinitializes the AVPLAY module. CNcomment:ȥ\B3\F5ʼ\BB\AFAVPLAYģ\BF\E9 CNend
\attention \n
Please call this API function, before call anyother API of AVPLAY module.
CNcomment: \D4ڵ\F7\D3\C3::HI_UNF_AVPLAY_Destroy\BDӿ\DA\CF\FA\BB\D9\CB\F9\D3еĲ\A5\B7\C5\C6\F7\BA󣬵\F7\D3ñ\BE\BDӿ\DA CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT  The operation is invalid.  CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_DEV_CLOSE_ERR  An AVPLAY fails to be stopped. CNcomment:AVPLAY\B9ر\D5ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_DeInit(HI_VOID);

/**
\brief Get video frame info. CNcomment:\BB\F1ȡ\CA\D3Ƶ֡\D0\C5Ϣ CNend
\attention \n
\param[out] pstVideoFrameInfo  Pointer to video frame info. For details, see the description of ::HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\D3Ƶ֡\D0\C5Ϣ\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S. CNend
\param[in] hAvplay    AVPLAY handle . CNcomment:AVPLAY\BE\E4\B1\FA . CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR  The pointer is null.  CNcomment:ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_FAILURE  Failure. CNcomment:ʧ\B0\DC. CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetVideoFrameInfo(HI_HANDLE hAvplay, HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S *pstVideoFrameInfo);

/**
\brief Obtains the default configuration of an AVPLAY. CNcomment:\BB\F1ȡȱʡ\B5\C4AV\B2\A5\B7\C5\C5\E4\D6\C3 CNend
\attention \n
When calling this API to set the enCfg parameter, you must enter correct mode of the player to be created.\n
It is recommended that you call this API to obtain the default AVPLAY attributes before creating an AVPLAY. This avoids creation failures due to incomplete or incorrect parameters.
CNcomment:\B5\F7\D3ñ\BE\BDӿ\DA\CA\E4\C8\EBenCfg\B2\CE\CA\FDʱ\A3\AC\C7\EB\D5\FDȷ\CA\E4\C8\EB\CF\EBҪ\B4\B4\BD\A8\B2\A5\B7\C5\C6\F7ģʽ\n
\B4\B4\BD\A8AV\B2\A5\B7\C5\C6\F7ǰ\BD\A8\D2\E9\B5\F7\D3ñ\BE\BDӿڣ\AC\BB\F1ȡ\B5\BDAV\B2\A5\B7\C5\C6\F7Ĭ\C8\CF\CA\F4\D0ԣ\AC\B1\DC\C3ⴴ\BD\A8AV\B2\A5\B7\C5\C6\F7ʱ\D3\C9\D3ڲ\CE\CA\FD\B2\BBȫ\BB\F2\B2\CE\CA\FD\B4\ED\CE\F3\B5\BC\D6²\A5\B7\C5\C6\F7\B4\B4\BD\A8\B2\BB\B3ɹ\A6\CF\D6\CF\F3 CNend
\param[out] pstAvAttr  Pointer to AVPLAY attributes. For details, see the description of ::HI_UNF_AVPLAY_ATTR_S. CNcomment: ָ\D5\EB\C0\E0\D0ͣ\ACAV\B2\A5\B7\C5\CA\F4\D0ԣ\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_ATTR_S. CNend
\param[in] enCfg       AVPLAY type. For details, see the description of ::HI_UNF_AVPLAY_STREAM_TYPE_E. CNcomment: AV\B2\A5\B7ŵ\C4\C0\E0\D0ͣ\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_STREAM_TYPE_E. CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDefaultConfig(HI_UNF_AVPLAY_ATTR_S *pstAvAttr, HI_UNF_AVPLAY_STREAM_TYPE_E enCfg);

/**
\brief Registers a dynamic audio decoding library. CNcomment:ע\B2\E1\D2\F4Ƶ\B6\AF̬\BD\E2\C2\EB\BF\E2 CNend
\attention \n
\param[in] pFileName Name of the file in the audio decoding library CNcomment:\D2\F4Ƶ\BD\E2\C2\EB\BF\E2\CEļ\FE\C3\FB CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR  The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterAcodecLib(const HI_CHAR *pFileName);

/**
\brief Registers a dynamic video decoding library. CNcomment:ע\B2\E1\CA\D3Ƶ\B6\AF̬\BD\E2\C2\EB\BF\E2 CNend
\attention \n
\param[in] pFileName Name of the file in the video decoding library CNcomment:\CA\D3Ƶ\BD\E2\C2\EB\BF\E2\CEļ\FE\C3\FB CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR  The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterVcodecLib(const HI_CHAR *pFileName);

/**
\brief Searches for registered dynamic audio decoding libraries based on the audio format.
CNcomment:\B8\F9\BE\DD\D2\F4Ƶ\B8\F1ʽ, \B2\E9\D5\D2ע\B2\E1\D2\F4Ƶ\B6\AF̬\BD\E2\C2\EB\BF\E2 CNend
\attention \n
\param[in] enFormat Audio format CNcomment:\D2\F4Ƶ\B8\F1ʽ CNend
\param[out] penDstCodecID If an audio decoding library is found, its codec ID is returned.
CNcomment:\B3ɹ\A6\D4򷵻\D8\D2\F4Ƶ\BD\E2\C2\EB\BF\E2CodecID CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_FoundSupportDeoder(const HA_FORMAT_E enFormat,HI_U32 * penDstCodecID);


/**
\brief Sets private commands for a dynamic audio decoding library. These commands are used to call ha_codec.
CNcomment:\C9\E8\D6\C3˽\D3\D0\C3\FC\C1\EE\B8\F8\D2\F4Ƶ\B6\AF̬\BD\E2\C2\EB\BF\E2, \B5\F7\D3\C3ha_codec \B7\BD\B7\A8  CNend
HI_HA_ERRORTYPE_E (*DecSetConfig)(HI_VOID * hDecoder, HI_VOID * pstConfigStructure);
\attention \n
\param[in] enDstCodecID  The audio Codec ID  CNcomment:\D2\F4Ƶ\BD\E2\C2\EB\BF\E2ID CNend
\param[in] pPara  Attribute structure CNcomment:\CA\F4\D0Խṹ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR  The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ConfigAcodec(const HI_U32 enDstCodecID, HI_VOID *pPara);

/**
\brief Creates an AVPLAY. CNcomment:\B4\B4\BD\A8AV\B2\A5\B7\C5\C6\F7 CNend
\attention \n
Note the following point when setting the input parameter pstAttr: The stream source can be HI_UNF_AVPLAY_STREAM_TYPE_ES (ESs input from the memory) or HI_UNF_AVPLAY_STREAM_TYPE_TS (ESs input from the memory and TSs input from the Tuner).
CNcomment:\CA\E4\C8\EB\CA\F4\D0Բ\CE\CA\FDpstAttr\D6\D0\D3м\B8\B5\E3\D0\E8Ҫע\D2⣺\C2\EB\C1\F7Դ֧\B3\D6HI_UNF_AVPLAY_STREAM_TYPE_ES\A3\A8\C4ڴ\E6\CA\E4\C8\EBES\C1\F7\A3\A9\A1\A2HI_UNF_AVPLAY_STREAM_TYPE_TS\A3\A8\C4ڴ\E6\CA\E4\C8\EBTS\C1\F7\BB\F2TUNER\CA\E4\C8\EBTS \C1\F7\A3\A9CNend
\param[in]  pstAvAttr   Pointer to AVPLAY attributes. For details, see the description of ::HI_UNF_AVPLAY_ATTR_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACAV\B2\A5\B7\C5\CA\F4\D0ԣ\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_ATTR_S. CNend
\param[out] phAvplay    Pointer to the handle of a created AVPLAY.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\B4\BD\A8\B5\C4AV\B2\A5\B7ž\E4\B1\FA CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_CREATE_ERR       The AVPLAY fails to be created. CNcomment:AVPLAY\B4\B4\BD\A8ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Create(const HI_UNF_AVPLAY_ATTR_S *pstAvAttr, HI_HANDLE *phAvplay);

/**
\brief Destroys an AVPLAY. CNcomment:\CF\FA\BB\D9AV\B2\A5\B7\C5\C6\F7 CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Destroy(HI_HANDLE hAvplay);

/**
\brief Sets the attributes of an AVPLAY. CNcomment:\C9\E8\D6\C3AV\B2\A5\B7\C5\CA\F4\D0\D4 CNend
\attention \n
You can set the audio/video PID, audio/video decoding type, and synchronization mode by calling this API.\n
Different attribute IDs correspond to different data types. For details, see the Note part of HI_UNF_AVPLAY_ATTR_ID_E. The attribute types of the pPara and enAttrID parameters must be the same.\n
Before setting HI_UNF_AVPLAY_ATTR_ID_ADEC (audio decoding attribute) and HI_UNF_AVPLAY_ATTR_ID_VDEC (video decoding attribute),\n
you must disable the audio channel or video channel. The new attributes take effect when you enable the audio channel or video channel again.
CNcomment:\B5\F7\D3ñ\BE\BDӿڿ\C9ʵ\CF\D6\C9\E8\D6\C3\D2\F4\CA\D3ƵPID\A1\A2\C9\E8\D6\C3\D2\F4\CA\D3Ƶ\BD\E2\C2\EB\C0\E0\D0͡\A2\C9\E8\D6\C3ͬ\B2\BD\B7\BDʽ\B5ȹ\A6\C4\DC\n
\B2\BBͬ\B5\C4\CA\F4\D0\D4ID\B6\D4Ӧ\B5Ľṹ\CC\E5\C7\EB\B2μ\FB\BDṹ\CC\E5HI_UNF_AVPLAY_ATTR_ID_E\B5\C4[ע\D2\E2], pPara\B2\CE\CA\FDҪ\D3\EBenAttrID\B6\D4Ӧ\B5\C4\CA\F4\D0Խṹ\CC\E5\C0\E0\D0ͱ\A3\B3\D6һ\D6\C2\n
\B5\B1\D0\E8Ҫ\C9\E8\D6\C3HI_UNF_AVPLAY_ATTR_ID_ADEC(\D2\F4Ƶ\BD\E2\C2\EB\CA\F4\D0\D4),HI_UNF_AVPLAY_ATTR_ID_VDEC(\CA\D3Ƶ\BD\E2\C2\EB\CA\F4\D0\D4)ʱ\n
\D0\E8Ҫ\CFȹر\D5\D2\F4Ƶ\BB\F2\CA\D3Ƶͨ\B5\C0\A3\AC\D4\D9\C9\E8\D6\C3\D0\C2\CA\F4\D0ԣ\ACȻ\BA\F3\D4\D9\D6\D8\D0´\F2\BF\AA\D2\F4Ƶ\BB\F2\CA\D3Ƶͨ\B5\C0\D0\C2\CA\F4\D0Բſ\C9\D2\D4\C9\FAЧ\A1\A3 CNend
\param[in] hAvplay         AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enAttrID        Attribute ID CNcomment:\CA\F4\D0\D4ID CNend
\param[in] pPara  Data type corresponding to an attribute ID CNcomment:\CA\F4\D0\D4ID\B6\D4Ӧ\BDṹ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetAttr(HI_HANDLE hAvplay, HI_UNF_AVPLAY_ATTR_ID_E enAttrID, const HI_VOID *pPara);

/**
\brief Obtains the attributes of an AVPLAY. CNcomment:\BB\F1ȡAV\B2\A5\B7\C5\CA\F4\D0\D4 CNend
\attention \n
N/A
\param[in] hAvplay          AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enAttrID         Attribute ID CNcomment:\CA\F4\D0\D4ID CNend
\param[in] pPara   Data type corresponding to an attribute ID, CNcomment:\CA\F4\D0\D4ID\B6\D4Ӧ\BDṹ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetAttr(HI_HANDLE hAvplay, HI_UNF_AVPLAY_ATTR_ID_E enAttrID, HI_VOID *pPara);

/**
\brief Decodes I frames. CNcomment:\BD\E2\C2\EBI֡\C2\EB\C1\F7 CNend
\attention \n
If pstCapPicture is null, the decoded I frames are displayed in the window,and do not need release memory; \n
if pstCapPicture is not null, the information about I frames is reported, and need invoke ::HI_UNF_AVPLAY_ReleaseIFrame to release memory.
You must stop the video decoder before calling this API. If I frames are being processed, do not enable the video decoder.
CNcomment:\B5\B1pstCapPictureΪ\BF\D5ָ\D5\EBʱ\A3\AC\BD\E2\CD\EA\B5\C4I֡\BD\AB\D4\DAwindow\C9\CF\CF\D4ʾ\A3\AC\B2\BB\D0\E8\CAͷ\C5\C4ڴ棬\C8\E7\B9\FB\B7ǿգ\AC\D4򲻻\E1\CF\D4ʾ\B6\F8\CAǽ\ABI֡\D0\C5Ϣ\C9ϱ\A8,ͬʱI֡\B4\A6\C0\ED\CD\EA\B1Ϻ\F3\A3\AC\D0\E8Ҫ\B5\F7\D3\C3HI_UNF_AVPLAY_ReleaseIFrame\C0\B4\CAͷ\C5I֡
\B5\F7\D3øýӿ\DAǰ\A3\AC\D0\E8ֹͣ\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\A3\BBI֡\B4\A6\C0\EDû\D3\D0\CD\EA\B3\C9ʱ\A3\ACҲ\B2\BB\C4\DC\C6\F4\B6\AF\CA\D3Ƶ\BD\E2\C2\EB\C6\F7 CNend
\param[in] hAvplay         AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstFrame        Pointer to frame attributes CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC֡\CA\FD\BE\DD\CA\F4\D0\D4 CNend
\param[in] pstCapPicture   Pointer to the frame information CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC֡\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_DecodeIFrame(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_I_FRAME_S *pstFrame, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);


/**
\brief Release memory of I frame. CNcomment:\CAͷ\C5I֡֡\B4\E6 CNend
\attention \n
If you call HI_UNF_AVPLAY_DecodeIFrame with non-null pstCapPicture, you need call this API to release the memory.
CNcomment:\C8\E7\B9\FB\B5\F7\D3\C3HI_UNF_AVPLAY_DecodeIFrameʱpstCapPicture\B2\BBΪ\BFգ\AC\D0\E8Ҫ\B5\F7\D3ô˽ӿ\DA\C0\B4\CAͷ\C5\C4ڴ\E6 CNend
\param[in] hAvplay         AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstCapPicture   Pointer to the frame information CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CAͷŵ\C4֡\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ReleaseIFrame(HI_HANDLE hAvplay, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);


/**
\brief Sets the mode of a video decoder. CNcomment:\C9\E8\D6\C3\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B5\C4ģʽ CNend
\attention \n
This API is used in trick play mode. Before switching the mode to the trick play mode, you must enable a decoder to decode only I frames by calling this API.\n
Before switching the mode to the normal mode, you also need to set the mode of a decoder to normal by calling this API.
CNcomment:\B1\BE\BDӿ\DA\D6\F7ҪӦ\D3\C3\D4ڿ\EC\BD\F8\B2\A5\B7ŵĳ\A1\BE\B0\A3\AC\B5\B1\C7л\BB\B5\BD\BF\EC\BD\F8\B2\A5\B7\C5ǰ\A3\AC\BF\C9\D2\D4\CFȵ\F7\D3ñ\BE\BDӿڽ\AB\BD\E2\C2\EB\C6\F7\C9\E8\D6\C3Ϊֻ\BD\E2I֡\A3\AC\n
\B5\B1\C7л\BB\BB\D8\D5\FD\B3\A3\B2\A5\B7\C5ǰ\A3\AC\CFȵ\F7\D3ñ\BE\BDӿڽ\AB\BD\E2\C2\EB\C6\F7\C9\E8\D6\C3ΪNORMAL\A1\A3 CNend
\param[in] hAvplay            AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enDecodeMode       Decoding mode CNcomment:\BD\E2\C2\EBģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetDecodeMode(HI_HANDLE hAvplay, HI_UNF_VCODEC_MODE_E enDecodeMode);

/**
\brief Registers an event on 32bit system. CNcomment:ע\B2\E1\CA¼\FE CNend
\attention \n
N/A
\param[in] hAvplay     AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enEvent     Event type enumeration CNcomment:ö\BE\D9\C0\E0\D0ͣ\AC\B1\EDʾ\CA¼\FE\C0\E0\D0\CD CNend
\param[in] pfnEventCB  Pointer to the callback function corresponding to the registered event. CNcomment:\BBص\F7\BA\AF\CA\FDָ\D5룬ָ\CF\F2\D3\EBע\B2\E1\CA¼\FE\B6\D4Ӧ\B5Ļص\F7\BA\AF\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT     The AVPLAY is not initialized.  CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterEvent(HI_HANDLE      hAvplay,
                                   HI_UNF_AVPLAY_EVENT_E     enEvent,
                                   HI_UNF_AVPLAY_EVENT_CB_FN pfnEventCB);
/**
\brief Registers an event on 64bit system. CNcomment:64λϵͳע\B2\E1\CA¼\FE CNend
\attention \n
N/A
\param[in] hAvplay     AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enEvent     Event type enumeration CNcomment:ö\BE\D9\C0\E0\D0ͣ\AC\B1\EDʾ\CA¼\FE\C0\E0\D0\CD CNend
\param[in] pfnEventCB  Pointer to the callback function corresponding to the registered event. CNcomment:\BBص\F7\BA\AF\CA\FDָ\D5룬ָ\CF\F2\D3\EBע\B2\E1\CA¼\FE\B6\D4Ӧ\B5Ļص\F7\BA\AF\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT     The AVPLAY is not initialized.  CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RegisterEvent64(HI_HANDLE      hAvplay,
                                   HI_UNF_AVPLAY_EVENT_E     enEvent,
                                   HI_UNF_AVPLAY_EVENT_CB_FN64 pfnEventCB);

/**
\brief Deregisters an event. CNcomment:ȡ\CF\FBע\B2\E1\CA¼\FE CNend
\attention \n
N/A
\param[in] hAvplay   AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enEvent   Event type enumeration CNcomment:ö\BE\D9\C0\E0\D0ͣ\AC\B1\EDʾ\CA¼\FE\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_UnRegisterEvent(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E enEvent);

/**
\brief Enables an AVPLAY channel. CNcomment:\B4\F2\BF\AAAV\B2\A5\B7\C5\C6\F7ͨ\B5\C0 CNend
\attention \n
You can enable an audio channel and a video channel for each AVPLAY. If you only need to play videos or audios, you can enable the corresponding channel to save resources.
CNcomment:ÿ\B8\F6AV\B2\A5\B7\C5\C6\F7\BD\F6֧\B3ִ\F2\BF\AA\D2\F4\CA\D3Ƶͨ\B5\C0\B8\F71\B8\F6\A1\A3\C8\E7\B9\FBֻ\B2\A5\B7\C5\D2\F4Ƶ\BB\F2\CA\D3Ƶ\A3\ACֻ\D0\E8Ҫ\B4\F2\BF\AA\CF\E0Ӧͨ\B5\C0\A3\AC\D2Խ\DAʡ\D7\CAԴ\A1\A3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn    Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\param[in] pPara    Pointer type. For details, see the description of ::HI_UNF_AVPLAY_OPEN_OPT_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_OPEN_OPT_S. CNend
    If enChn is set to HI_UNF_AVPLAY_MEDIA_CHAN_VID, this API is used to specify the maximum decoding performance of the video decoder.
    If enChn is set to NULL, the maximum performance H264+HI_UNF_VCODEC_CAP_LEVEL_FULLHD is used by default.
    The higher the configured decoding performance, the larger the required MMZ. It is recommended that you configure the performance as required.
    CNcomment:enChnΪHI_UNF_AVPLAY_MEDIA_CHAN_VIDʱ\D3\C3\C0\B4ָ\B6\A8\CA\D3Ƶ\BD\E2\C2\EB\C6\F7\B5\C4\D7\EE\B4\F3\BD\E2\C2\EB\C4\DC\C1\A6\A1\A3
    \C8\E7\B9\FB\C9\E8ΪNULL\A3\AC\BD\ABĬ\C8\CFΪ\D7\EE\B4\F3\C4\DC\C1\A6: H264+HI_UNF_VCODEC_CAP_LEVEL_FULLHD\A1\A3
    \C5\E4\D6\C3֧\B3ֵ\C4\C4\DC\C1\A6Խ\B4\F3\A3\AC\D0\E8Ҫ\B5\C4MMZ\CE\EF\C0\ED\C4ڴ\E6Ҳ\BE\CDԽ\B4󣬽\A8\D2鰴\D0\E8\C5\E4\D6ü\B4\BFɡ\A3 CNend
\retval ::HI_SUCCESS Success             CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ChnOpen(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_VOID *pPara);

/**
\brief Disables an AVPLAY channel. CNcomment:\B9ر\D5AV\B2\A5\B7\C5\C6\F7ͨ\B5\C0 CNend
\attention \n
N/A
\param[in] hAvplay   AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn     Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_ChnClose(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn);

/**
\brief Start an AVPLAY to prepare play mode, which just demux ts stream. CNcomment:\C6\F4\B6\AF\B2\A5\B7\C5\C6\F7\BD\F8\C8\EB\BD\F6\BD\F6\D7\F6\BD⸴\D3\C3TS\B5\C4PREPLAY״̬ CNend
\attention \n
After enabling channels and setting their attributes, you can call this API to start an AVPLAY to enable it to work in prepare play mode. The audios and videos can be prepared play separately or simultaneously.
CNcomment:\B5\B1\CD\EA\B3\C9ͨ\B5\C0\B4򿪺\CD\CA\F4\D0\D4\C9\E8\D6ú󣬵\F7\D3ñ\BE\BDӿ\DA\C6\F4\B6\AFԤ\B2\A5\B7ţ\AC\BD\F8\C8\EBPREPLAY״̬\A1\A3֧\B3ֱַ\F0\BA\CDͬʱ\C6\F4\B6\AF\D2\F4\CA\D3ƵԤ\B2\A5\B7š\A3 CNend
\param[in] hAvplay         AVPLAY handle  CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn           Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\param[in] pstPreStartOpt     Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪNULL\BC\B4\BF\C9. CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_PreStart(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_PRESTART_OPT_S *pstPreStartOpt);

/**
\brief Starts an AVPLAY. The AVPLAY is in play mode. CNcomment:\C6\F4\B6\AF\B2\A5\B7\C5\C6\F7\A3\AC\BD\F8\C8\EBPLAY״̬ CNend
\attention \n
After enabling channels and setting their attributes, you can call this API to start an AVPLAY to enable it to work in play mode. The audios and videos can be played separately or simultaneously.
CNcomment:\B5\B1\CD\EA\B3\C9ͨ\B5\C0\B4򿪺\CD\CA\F4\D0\D4\C9\E8\D6ú󣬵\F7\D3ñ\BE\BDӿ\DA\C6\F4\B6\AF\B2\A5\B7ţ\AC\BD\F8\C8\EBPLAY״̬\A1\A3֧\B3ֱַ\F0\BA\CDͬʱ\C6\F4\B6\AF\D2\F4\CA\D3Ƶ\B2\A5\B7š\A3 CNend
\param[in] hAvplay         AVPLAY handle  CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn           Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\param[in] pstStartOpt     Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪNULL\BC\B4\BF\C9. CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Start(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_START_OPT_S *pstStartOpt);

/**
\brief Stop an AVPLAY to prepare stop mode,the interface is reserved for future use. CNcomment:ֹͣAV\B2\A5\B7\C5ʹ\C6\E4\BD\F8\C8\EBPRESTOP״̬,\B8ýӿڱ\A3\C1\F4\B1\B8\D3\C3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn    Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\param[in] pstPreStopOpt   Pointer to stop mode. For details, see the description of ::HI_UNF_AVPLAY_PRESTOP_OPT_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\C7\E5\C6\C1ģʽ\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_STOP_OPT_S. CNend
\retval ::HI_ERR_AVPLAY_NOT_SUPPORT not support for the moment  CNcomment:\D4ݲ\BB֧\B3\D6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_PreStop(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_PRESTOP_OPT_S *pstPreStopOpt);

/**
\brief Stops an AVPLAY. Then the AVPLAY is in stop mode. CNcomment:ֹͣAV\B2\A5\B7ţ\AC\BD\F8\C8\EBSTOP״̬ CNend
\attention \n
If you call this API, all selected channels stop playing. The playing audios and videos can be stopped separately or simultaneously.\n
The parameter pstStopOpt->enMode takes effect only when a video channel is selected.\n
If pstStopOpt->enMode is set to NULL or HI_UNF_AVPLAY_STOP_MODE_STILL, the last frame is kept still.\n
If pstStopOpt->enMode is set to HI_UNF_AVPLAY_STOP_MODE_BLACK, the last frame is cleared, and the blank screen appears.\n
When pstStopOpt->u32TimeoutMs is 0, the AVPLAY stops and this API is returned.\n
When pstStopOpt->u32TimeoutMs is greater than 0, this API is blocked until the data in the buffer is used up.\n
When pstStopOpt->u32TimeoutMs is greater than -1, this API is blocked until the data in the buffer is used up.\n
To stop the audio or video separately when both the audio and video are enabled, you must set pstStopOpt->u32TimeoutMs to 0.
CNcomment:\B5\F7\D3ñ\BE\BDӿڽ\ABֹͣ\CB\F9ѡͨ\B5\C0\B5Ĳ\A5\B7ţ\AC֧\B3ֱַ\F0\BA\CDͬʱֹͣ\D2\F4\CA\D3Ƶ\B2\A5\B7š\A3\n
\B5\B1\CB\F9ѡͨ\B5\C0\D6а\FC\BA\AC\CA\D3Ƶͨ\B5\C0ʱ\A3\AC\B2\CE\CA\FDpstStopOpt->enMode\B2\C5\D3\D0\D2\E2\D2塣\n
\B5\B1pstStopOpt->enModeΪ\BFջ\F2\D5\DFΪHI_UNF_AVPLAY_STOP_MODE_STILLʱ\A3\AC\B1\A3\C1\F4\D7\EE\BA\F3һ֡\CA\D3Ƶͼ\CF\F1\A1\A3\n
\B5\B1pstStopOpt->enModeΪHI_UNF_AVPLAY_STOP_MODE_BLACKʱ\A3\AC\C7\E5\B3\FD\CA\D3Ƶ\D7\EE\BA\F3һ֡\A3\AC\CA\D3Ƶ\CA\E4\B3\F6Ϊ\BA\DA\C6\C1\A1\A3\n
\B5\B1pstStopOpt->u32TimeoutMsΪ0ʱ\BD\AB\C0뿪ֹͣ\B2\A5\B7Ų\A2\B7\B5\BBء\A3\n
\B5\B1pstStopOpt->u32TimeoutMs>0ʱ\BD\AB\D7\E8\C8\FB\CF\E0Ӧʱ\BC䣬ֱ\B5\BD\BB\BA\B3\E5\D6е\C4\CA\FD\BEݲ\A5\CDꡣ\n
\B5\B1pstStopOpt->u32TimeoutMs=-1ʱ\BD\ABһֱ\D7\E8\C8\FB\B5\BD\BB\BA\B3\E5\D6е\C4\CA\FD\BEݲ\A5\CDꡣ\n
\B5\B1\D2\F4\CA\D3Ƶ\B6\BC\B4\A6\D3ڿ\AA\C6\F4״̬ʱ,Ҫ\B5\A5\B6\C0ֹͣ\D2\F4Ƶ\BA\CD\CA\D3Ƶ\A3\AC\B1\D8\D0\EB\C9\E8\D6\C3pstStopOpt->u32TimeoutMsΪ0. CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enChn    Separate audio channel or video channel. For details, see the description of ::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNcomment:\B5\A5\B6\C0\B5\C4\D2\F4\CA\D3Ƶͨ\B5\C0\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_MEDIA_CHAN_E. CNend
\param[in] pstStopOpt   Pointer to the clear screen mode. For details, see the description of ::HI_UNF_AVPLAY_STOP_OPT_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\C7\E5\C6\C1ģʽ\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_STOP_OPT_S. CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Stop(HI_HANDLE hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_E enChn, const HI_UNF_AVPLAY_STOP_OPT_S *pstStopOpt);

/**
\brief Pauses an AVPLAY. Then the AVPLAY is in pause mode. CNcomment:\D4\DDͣAV\B2\A5\B7ţ\AC\BD\F8\C8\EBPAUSE״̬ CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstPauseOpt  Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪΪNULL\BC\B4\BF\C9 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Pause(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_PAUSE_OPT_S *pstPauseOpt);

/**
\brief Plays videos or audios in trick play mode. Then the AVPLAY is in TPLAY mode. CNcomment:\B1\B6\CBٲ\A5\B7ţ\AC\BD\F8\C8\EBTPLAY״̬ CNend
\attention \n
pstTplayOpt->u32SpeedInteger is the integer part of speed, the range is 0-64.
pstTplayOpt->u32SpeedDecimal is the decimal part of speed, the range is 0-999.
CNcomment: pstTplayOpt->u32SpeedIntegerΪ\CBٶȵ\C4\D5\FB\CA\FD\B2\BF\B7֣\ACȡֵ\B7\B6ΧΪ0-64. CNend
CNcomment: pstTplayOpt->u32SpeedDecimalΪ\CBٶȵ\C4С\CA\FD\B2\BF\B7֣\AC\B1\A3\C1\F43λС\CA\FD\A3\ACȡֵ\B7\B6ΧΪ0-999. CNend
\param[in] hAvplay  AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstTplayOpt   The pointer of Tplay parameter,For details, see the description of ::HI_UNF_AVPLAY_TPLAY_OPT_S . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACTPLAY\B2\CE\CA\FDָ\D5\EB,\C7\EB\B2μ\FBHI_UNF_AVPLAY_TPLAY_OPT_S\BDṹ\CC嶨\D2\E5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Tplay(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_TPLAY_OPT_S *pstTplayOpt);

/**
\brief Resumes an AVPLAY. Then the AVPLAY is in play mode. CNcomment:\BBָ\B4AV\B2\A5\B7ţ\AC\BD\F8\C8\EBPLAY״̬ CNend
\attention \n
By calling this API, you can resume an AVPLAY from the trick play mode or pause mode rather than the stop mode.
CNcomment:\B1\BE\BDӿ\DA\D3\C3\C0\B4\BD\AB\B1\B6\CBٻ\F2\D4\DDͣ״̬\BBָ\B4Ϊ\B2\A5\B7\C5״̬\A3\AC\B5\AB\CE޷\A8\BD\ABֹͣ״̬\BBָ\B4Ϊ\B2\A5\B7\C5״̬\A1\A3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstResumeOpt  Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\D4\DD\D6\C3Ϊ\BFռ\B4\BF\C9 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Resume(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_RESUME_OPT_S *pstResumeOpt);

/**
\brief Resets an AVPLAY. In this case, the play mode is not changed. CNcomment:\B8\B4λAV\B2\A5\B7ţ\AC\B2\BB\B8ı\E4״̬ CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstResetOpt   Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪΪNULL\BC\B4\BF\C9 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Reset(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_RESET_OPT_S *pstResetOpt);

/**
\brief Step play. CNcomment:\B2\BD\BD\F8\B2\A5\B7\C5 CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstStepOpt   Pointer used for expansion. You can set it to NULL. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪΪNULL\BC\B4\BF\C9 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Step(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_STEP_OPT_S *pstStepOpt);

/**
\brief Applies for a buffer for storing the streams played by an AVPLAY. CNcomment:\C9\EA\C7\EBAV\B2\A5\B7ŵ\C4\C2\EB\C1\F7\BB\BA\B3\E5 CNend
\attention \n
This API is used only when you want to play the ESs obtained from Internet or local ESs.\n
The pstData parameter is used to return the start address and size of the buffer applied for.\n
If u32TimeOutMs is set to 0, it indicates that the waiting time is 0; if u32TimeOutMs is set to 0XFFFFFFFF, it indicates that the API waits for an infinite time; if u32TimeOutMs is set to other values, it indicates that the waiting time is u32TimeOutMs ms.\n
If no buffer can be applied for during the block period, an error code indicating full buffer is returned.\n
If u32TimeOutMs is set to 0, and no buffer can be applied for, it indicates that the audio and video buffers are full. In this case, you need to call the usleep(N*1000) function to release the CPU.
Therefore, other threads can be scheduled.
CNcomment:\B5\B1\B2\A5\B7\C5\CD\F8\C2\E7\BB򱾵\D8ES\C1\F7ʱ\B2\C5\D0\E8Ҫʹ\D3ñ\BE\BDӿڡ\A3\n
\B2\CE\CA\FDpstData\D3\C3\C0\B4\B7\B5\BBسɹ\A6\C9\EA\C7뵽\B5\C4Buffer\B5\C4\CA׵\D8ַ\D2Լ\B0\B4\F3С\A1\A3\n
u32TimeOutMs\C9\E8\D6\C3Ϊ0\B1\EDʾ\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffff\B1\EDʾһֱ\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ\C6\E4\CB\FBֵ\B1\EDʾ\B5ȴ\FDu32TimeOutMs\BA\C1\C3롣\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\BB\B9\CE޷\A8\C9\EA\C7뵽Buffer\A3\AC\D4򷵻\D8buffer\C2\FA\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C5\E4\D6\C3Ϊ0ʱ\A3\AC\C8\E7\B9\FB\C9\EA\C7벻\B5\BDBuffer\A3\AC˵\C3\F7\B4\CBʱ\D2\F4\CA\D3Ƶ\B5\C4Buffer\D2\D1\C2\FA\A3\AC\D0\E8Ҫͨ\B9\FDusleep(N*1000)\CAͷ\C5cpu
\D2\D4ʹ\C6\E4\CB\FC\CF߳\CC\C4ܹ\BB\B5õ\BD\B5\F7\B6ȡ\A3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enBufId     Buffer queue ID CNcomment:\BB\BA\B3\E5\B6\D3\C1\D0ID CNend
\param[in] u32ReqLen   Size of the buffer applied for CNcomment:\C9\EA\C7뻺\B4\E6\B5Ĵ\F3С CNend
\param[out] pstData    Pointer to the returned buffer CNcomment:\B7\B5\BBػ\BA\B4\E6ָ\D5\EB CNend
\param[in] u32TimeOutMs      Wait timeout, in ms CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms. CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetBuf(HI_HANDLE  hAvplay,
                            HI_UNF_AVPLAY_BUFID_E enBufId,
                            HI_U32                u32ReqLen,
                            HI_UNF_STREAM_BUF_S  *pstData,
                            HI_U32                u32TimeOutMs);

/**
\brief Updates the write pointer after data is successfully copied. CNcomment:\BF\BD\B1\B4\CA\FD\BEݳɹ\A6\BA󣬸\FC\D0\C2дָ\D5\EB CNend
\attention \n
After transmitting streams to the buffer applied for, you can call this API to update the write pointer of the audio and video buffers.\n
If the transmitted streams do not contain PTS, u32ptsMs must be set to -1.
CNcomment:\D4\DA\CF\F2\C9\EA\C7뵽\B5Ļ\BA\B3\E5\C7\F8\C4\DA\CB\CD\C2\EB\C1\F7\CD\EA\B1Ϻ󣬵\F7\D3ñ\BE\BDӿڸ\FC\D0\C2\D2\F4\CA\D3Ƶ\BB\BA\B3\E5\C7\F8\B5\C4дָ\D5롣\n
\C8\E7\B9\FB\B1\BE\B4\CE\CB\CD\C8\EB\B5\C4\C2\EB\C1\F7û\D3ж\D4Ӧ\B5\C4PTS\A3\ACu32ptsMs\B1\D8\D0\EBΪ-1\A1\A3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enBufId     Buffer queue ID CNcomment:\BB\BA\B3\E5\B6\D3\C1\D0ID. CNend
\param[in] u32ValidDataLen     Number of bytes that are written to the buffer CNcomment:ʵ\BC\CAд\C8뻺\B3\E5\C7\F8\B5\C4\D7ֽ\DA\CA\FD CNend
\param[in] u32PtsMs            PTS, in ms  CNcomment:ʱ\BC\E4\B4\C1,\D2Ժ\C1\C3\EBΪ\B5\A5λ CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_PutBuf(HI_HANDLE hAvplay, HI_UNF_AVPLAY_BUFID_E enBufId,
                         HI_U32 u32ValidDataLen, HI_U32 u32PtsMs);


/**
\brief Updates the write pointer after data is successfully copied. CNcomment:\BF\BD\B1\B4\CA\FD\BEݳɹ\A6\BA󣬸\FC\D0\C2дָ\D5\EB CNend
\attention \n
After transmitting streams to the buffer applied for, you can call this API to update the write pointer of the audio and video buffers.\n
If the transmitted streams do not contain PTS, u32ptsMs must be set to -1.
CNcomment:\D4\DA\CF\F2\C9\EA\C7뵽\B5Ļ\BA\B3\E5\C7\F8\C4\DA\CB\CD\C2\EB\C1\F7\CD\EA\B1Ϻ󣬵\F7\D3ñ\BE\BDӿڸ\FC\D0\C2\D2\F4\CA\D3Ƶ\BB\BA\B3\E5\C7\F8\B5\C4дָ\D5\EB, \B1\BE\BDӿڿ\C9\D3\C9\D3\DAһ֡\C2\EB\C1\F7\B7ֶ\E0\B0\FC\CB\CD\C8롣\n
\C8\E7\B9\FB\B1\BE\B4\CE\CB\CD\C8\EB\B5\C4\C2\EB\C1\F7û\D3ж\D4Ӧ\B5\C4PTS\A3\ACu32ptsMs\B1\D8\D0\EBΪ-1\A1\A3 CNend
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enBufId     Buffer queue ID CNcomment:\BB\BA\B3\E5\B6\D3\C1\D0ID CNend
\param[in] u32ValidDataLen     Number of bytes that are written to the buffer CNcomment:ʵ\BC\CAд\C8뻺\B3\E5\C7\F8\B5\C4\D7ֽ\DA\CA\FD CNend
\param[in] u32PtsMs            PTS, in ms  CNcomment:ʱ\BC\E4\B4\C1,\D2Ժ\C1\C3\EBΪ\B5\A5λ CNend
\param[in] pPutOpt   the extern parameter of PutBufEx, see the description of ::HI_UNF_AVPLAY_PUTBUFEX_OPT_S.CNcomment:PutBufEx\B5Ķ\EE\CD\E2\B2\CE\CA\FD\A3\AC\C7\EB\B2μ\FB::HI_UNF_AVPLAY_PUTBUFEX_OPT_S. CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT      The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_PutBufEx(HI_HANDLE hAvplay, HI_UNF_AVPLAY_BUFID_E enBufId,
                                       HI_U32 u32ValidDataLen, HI_U32 u32Pts, HI_UNF_AVPLAY_PUTBUFEX_OPT_S *pPutOpt);

/**
\brief Obtains the handle of the DMX audio channel used by an AVPLAY in TS mode. CNcomment:TSģʽʱ\BB\F1ȡAV\B2\A5\B7\C5\C6\F7ʹ\D3õ\C4DMX\D2\F4Ƶͨ\B5\C0\B5\C4Handle CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] phDmxAudChn    Pointer to the handle of a DMX audio channel CNcomment:DMX\D2\F4Ƶͨ\B5\C0Handleָ\D5\EB CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDmxAudChnHandle(HI_HANDLE hAvplay, HI_HANDLE *phDmxAudChn);

/**
\brief Obtains the handle of the DMX audio channel used by an AVPLAY in TS mode. CNcomment:TSģʽʱ\BB\F1ȡAV\B2\A5\B7\C5\C6\F7ʹ\D3õ\C4DMX\B8\A8\D2\F4\D2\F4Ƶͨ\B5\C0\B5\C4Handle CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] phDmxAudChn    Pointer to the handle of a DMX audio channel CNcomment:DMX\B8\A8\D2\F4\D2\F4Ƶͨ\B5\C0Handleָ\D5\EB CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDmxAdAudChnHandle(HI_HANDLE hAvplay, HI_HANDLE *phDmxAdAudChn);

/**
\brief Obtains the handle of the DMX video channel used by an AVPLAY in TS mode. CNcomment:TSģʽʱ\BB\F1ȡAV\B2\A5\B7\C5\C6\F7ʹ\D3õ\C4DMX\CA\D3Ƶͨ\B5\C0\B5\C4Handle. CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] phDmxVidChn    Pointer to the handle of a DMX video channel CNcomment:DMX\CA\D3Ƶͨ\B5\C0Handleָ\D5\EB CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetDmxVidChnHandle(HI_HANDLE hAvplay, HI_HANDLE *phDmxVidChn);


/**
\brief Obtains the status information about an AVPLAY. CNcomment:\BB\F1ȡAV\B2\A5\B7\C5״̬\D0\C5Ϣ CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle  CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[out] pstStatusInfo  Pointer to the status of an AVPLAY. For details, see the description of HI_UNF_AVPLAY_STATUS_INFO_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACAV\B2\A5\B7\C5״̬\D0\C5Ϣ\A3\AC\C7\EB\B2μ\FBHI_UNF_AVPLAY_STATUS_INFO_S. CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetStatusInfo(HI_HANDLE          hAvplay,
                                 HI_UNF_AVPLAY_STATUS_INFO_S *pstStatusInfo);


/**
\brief Obtains the information about audio and video streams. CNcomment:\BB\F1ȡ\D2\F4\CA\D3Ƶ\C2\EB\C1\F7\D0\C5Ϣ CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle  CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstStreamInfo     Pointer to the information about audio and video streams. For details, see the description of HI_UNF_AVPLAY_STREAM_INFO_S. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D2\F4\CA\D3Ƶ\C2\EB\C1\F7\D0\C5Ϣ\A3\AC\C7\EB\B2μ\FBHI_UNF_AVPLAY_STREAM_INFO_S CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetStreamInfo(HI_HANDLE          hAvplay,
                                   HI_UNF_AVPLAY_STREAM_INFO_S *pstStreamInfo);

/**
\brief Obtains the information audio spectrums. CNcomment:\BB\F1ȡ\D2\F4Ƶ\C4\DC\C1\BF\D0\C5Ϣ CNend
\attention \n
N/A
\param[in] hAvplay  AVPLAY handle  CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pSpectrum      Pointer to the array of audio spectrums. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D2\F4Ƶ\C4\DC\C1\BF\D0\C5Ϣ\CA\FD\D7\E9ָ\D5\EB CNend
\param[in] u32BandNum     Length of an audio spectrum array CNcomment:\D2\F4Ƶ\C4\DC\C1\BF\D0\C5Ϣ\CA\FD\D7鳤\B6\C8 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AVPLAY_INVALID_OPT    The operation is invalid. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetAudioSpectrum(HI_HANDLE hAvplay, HI_U16 *pSpectrum, HI_U32 u32BandNum);

/**
\brief Queries whether the AVPLAY buffer is empty. CNcomment:\B2\E9ѯAVPLAY buffer\CAǷ\F1\D2Ѿ\ADΪ\BF\D5 CNend
\attention \n
N/A
\param[in] hAvplay        AVPLAY handle CNcomment:AV\B2\A5\B7ž\E4\B1\FA CNend
\param[out] pbIsEmpty      Pointer type. This pointer indicates whether the AVPLAY buffer is empty (the playing ends). CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָʾbuffer\CAǷ\F1\D2Ѿ\ADΪ\BF\D5(\B2\A5\B7\C5\CD\EA\B3\C9) CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_IsBuffEmpty(HI_HANDLE hAvplay, HI_BOOL * pbIsEmpty);

/**
\brief Switch the demux audio channel CNcomment:\C7л\BB\D2\F4ƵDEMUX\BE\E4\B1\FA CNend
\attention \n
N/A
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] hNewDmxAud     New demux audio handle CNcomment:\D0\C2DMX\BE\E4\B1\FA CNend
\param[out] phOldDmxAud     Old  demux audio handle CNcomment:\BE\C9DMX\BE\E4\B1\FAָ\D5\EB CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SwitchDmxAudChn(HI_HANDLE hAvplay, HI_HANDLE hNewDmxAud, HI_HANDLE *phOldDmxAud);

/**
\brief Notify an AVPLAY the stream is end CNcomment:֪ͨAVPLAY\C2\EB\C1\F7\D2Ѿ\AD\CB\CD\CD\EA CNend
\attention \n
Call this interface to notice AVPLAY when the last package of stream has been sent,
then check whether the last frame has been output by eos event or by invoking ::HI_UNF_AVPLAY_IsBuffEmpty,
this interface is only apply to ES mode.
CNcomment: \B5\B1\D3û\A7\CB\CD\CD\EA\D7\EE\BA\F3һ\B0\FC\C2\EB\C1\F7ʱ\A3\AC\B5\F7\D3øýӿ\DA֪ͨAVPLAY\A3\AC֮\BA\F3\BF\C9\D2\D4ͨ\B9\FD\BC\EC\B2\E2EOS\CA¼\FE\BB\F2\D5ߵ\F7\D3\C3::HI_UNF_AVPLAY_IsBuffEmpty\C5ж\CF\D7\EE\BA\F3һ֡\CAǷ\F1\CA\E4\B3\F6
Ŀǰ\B8ýӿڽ\F6\CA\CA\D3\C3\D3\DAESģʽ CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstFlushOpt   Pointer used for expansion. You can set it to NULL.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪΪNULL\BC\B4\BF\C9 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_FlushStream(HI_HANDLE hAvplay, const HI_UNF_AVPLAY_FLUSH_STREAM_OPT_S *pstFlushOpt);

/**
\brief AVPLAY private command invoking. CNcomment: AVPLAY˽\D3\D0\C3\FC\C1\EE\B5\F7\D3\C3 CNend
\attention \n
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enInvokeType  Type of private command invoking.CNcomment:˽\D3\D0\C3\FC\C1\EE\B5\F7\D3\C3\C0\E0\D0\CD CNend
\param[in] pPara         Pointer to the parameter of invoking. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Invoke\B5\F7\D3õĲ\CE\CA\FD CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_Invoke(HI_HANDLE hAvplay, HI_UNF_AVPLAY_INVOKE_E enInvokeType, HI_VOID *pPara);

/**
\brief Accquire user dada. CNcomment: \BB\F1ȡ\D3û\A7\CA\FD\BE\DD CNend
\attention \n
Only support Closed Caption Data.
CNcomment: \BD\F6֧\B3\D6CC\CA\FD\BE\DD CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[out] pstUserData  user data.CNcomment:\D3û\A7\CA\FD\BE\DD CNend
\param[out] penType      user data type. CNcomment:\D3û\A7\CA\FD\BE\DD\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_AcqUserData(HI_HANDLE hAvplay, HI_UNF_VIDEO_USERDATA_S *pstUserData, HI_UNF_VIDEO_USERDATA_TYPE_E *penType);

/**
\brief Accquire user dada. CNcomment: \CAͷ\C5\D3û\A7\CA\FD\BE\DD CNend
\attention \n
Only support Closed Caption Data.
CNcomment: \BD\F6֧\B3\D6CC\CA\FD\BE\DD CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstUserData  user data.CNcomment:\D3û\A7\CA\FD\BE\DD CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RlsUserData(HI_HANDLE hAvplay, HI_UNF_VIDEO_USERDATA_S* pstUserData);

/**
\brief Extended interface for Accquire user data. CNcomment: \BB\F1ȡ\D3û\A7\CA\FD\BEݵ\C4\C0\A9չ\BDӿ\DA CNend
\attention \n
support Closed Caption Data,Active Format Description.
CNcomment: ֧\B3\D6CC\A1\A2AFD\CA\FD\BE\DD CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enType      user data type. CNcomment:\D3û\A7\CA\FD\BE\DD\C0\E0\D0\CD CNend
\param[out] pstUserData  user data.CNcomment:\D3û\A7\CA\FD\BE\DD CNend

\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_AcqUserDataEx(HI_HANDLE hAvplay, HI_UNF_VIDEO_USERDATA_TYPE_E enType, HI_UNF_VIDEO_USERDATA_S *pstUserData);

/**
\brief Extended interface for Release user dada. CNcomment: \CAͷ\C5\D3û\A7\CA\FD\BEݵ\C4\C0\A9չ\BDӿ\DA CNend
\attention \n
Only support Closed Caption Data,Active Format Description..
CNcomment: \BD\F6֧\B3\D6CC\A1\A2AFD\CA\FD\BE\DD CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] enType      user data type. CNcomment:\D3û\A7\CA\FD\BE\DD\C0\E0\D0\CD CNend
\param[in] pstUserData  user data.CNcomment:\D3û\A7\CA\FD\BE\DD CNend

\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_RlsUserDataEx(HI_HANDLE hAvplay, HI_UNF_VIDEO_USERDATA_TYPE_E enType, HI_UNF_VIDEO_USERDATA_S *pstUserData);

/**
\brief set stream HDR information. CNcomment: \C9\E8\D6\C3HDR\D0\C5Ϣ\BDӿ\DA CNend
\attention \n
Only support VP9 HDR.
CNcomment: \BD\F6֧\B3\D6VP9 HDR \D0\C5Ϣ CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstHdrInfo    HDR information. CNcomment:HDR\D0\C5Ϣ CNend
\param[in] bPaddingHdrInfo    if need padding HDR information to frame information. CNcomment:\CAǷ\F1\D0\E8Ҫ\CC\EE\B3\E4HDR\D0\C5Ϣ\B5\BD֡\D0\C5Ϣ\D6\D0 CNend
\param[in] u32PtsMs  current pts of HDR information.it must be set invaild(-1),when that can not available.CNcomment:\B5\B1ǰHDR\D0\C5Ϣ\B6\D4Ӧ\B5\C4pts CNend

\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SetHDRInfo(HI_HANDLE hAvplay, const HI_UNF_VIDEO_HDR_INFO_S* pstHdrInfo, HI_BOOL bPaddingHdrInfo, HI_U32 u32PtsMs);

/**
\brief Queries whether the AudioCodec is supported. CNcomment:\B2\E9ѯ AudioCodec \CAǷ\F1֧\B3\D6 CNend
\attention \n
N/A
\param[in] enCodecID        AudioCodec CNcomment:\D2\F4Ƶ\B1\E0\BD\E2\C2\EB\C6\F7\C0\E0\D0\CD CNend
\param[out] pbSupport      Pointer support. This pointer indicates whether the AudioCodec is supported. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָʾAudioCodec\CAǷ\F1֧\B3\D6 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_IsAudioCodecSupport(const HA_CODEC_ID_E enCodecID, HI_BOOL* pbSupport);

/**
\brief Switch to external audio.  CNcomment:\C7л\BB\CDⲿ\D2\F4Ƶ CNend
\attention \n
N/A
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] bSwitchExternalAudio     whether switch to exteral audio:\CAǷ\F1\C7л\BB\B5\BD\CDⲿ\D2\F4Ƶ CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_FAILUER     Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_SwitchToExternalAudio(HI_HANDLE hAvplay,HI_BOOL bSwitchExternalAudio);

/**
\brief Stc calibration by user.  CNcomment:STC У\D5\FD CNend
\attention \n
N/A
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] StcPPM      stc ppm:STCУ\D5\FDPPM CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_FAILUER     Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_STCCalibration(HI_HANDLE hAvplay,HI_S32 StcPPM);

/**
\brief get stream HDR information. CNcomment: \BB\F1ȡHDR\D0\C5Ϣ\BDӿ\DA CNend
\attention \n
Support getting HDR info.
CNcomment: ֧\B3ֻ\F1ȡ HDR \D0\C5Ϣ CNend
\param[in] hAvplay       AVPLAY handle CNcomment: AV\B2\A5\B7ž\E4\B1\FA CNend
\param[in] pstHdrInfo    HDR information. CNcomment:HDR\D0\C5Ϣ CNend

\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AVPLAY_DEV_NO_INIT      The AVPLAY is not initialized. CNcomment:AVPLAYδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_AVPLAY_NULL_PTR         The input pointer is null. CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AVPLAY_INVALID_PARA     The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_AVPLAY_GetHDRInfo(HI_HANDLE hAvplay, HI_UNF_VIDEO_HDR_INFO_S* pstHdrInfo);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif
