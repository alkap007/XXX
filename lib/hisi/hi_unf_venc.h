/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_venc.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2010/04/07
  Description   :
  History       :
  1.Date        : 2010/04/07
    Author      : sdk
    Modification: Created file

*******************************************************************************/
/** 
 * \file
 * \brief Describes the information about video encoding (VENC). CNcomment: \CCṩVENC\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef  __HI_UNF_VENC_H__
#define  __HI_UNF_VENC_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

#define HI_UNF_VENC_TYPE_NUM 3

/********************************Struct Definition********************************/
/** \addtogroup      VENC */
/** @{ */  /** <!-- \A1\BEVENC\A1\BF */

/**H.264 NALU type*/
/**CNcomment: H.264NALU\C0\E0\D0\CD */
typedef enum hiUNF_H264E_NALU_TYPE_E
{
    HI_UNF_H264E_NALU_PSLICE = 1,       /**<P slice NALU*/ 
    HI_UNF_H264E_NALU_ISLICE = 5,       /**<I slice NALU*/ 
    HI_UNF_H264E_NALU_SEI = 6,          /**<SEI NALU*/ 
    HI_UNF_H264E_NALU_SPS = 7,          /**<SPS NALU*/
    HI_UNF_H264E_NALU_PPS = 8,          /**<PPS NALU*/ 
    HI_UNF_H264E_NALU_BUTT
} HI_UNF_H264E_NALU_TYPE_E;

/**H.263 NALU type*/
/**CNcomment: H.263NALU\C0\E0\D0\CD */
typedef enum hiUNF_H263E_PACK_TYPE_E
{
    HI_UNF_H263E_NALU_PSLICE = 1,       /**<P slice NALU*/
    HI_UNF_H263E_NALU_ISLICE = 5,       /**<I slice NALU*/
    HI_UNF_H263E_NALU_SEI = 6,          /**<SEI NALU*/
    HI_UNF_H263E_NALU_SPS = 7,          /**<SPS NALU*/
    HI_UNF_H263E_NALU_PPS = 8,          /**<PPS NALU*/
    HI_UNF_H263E_NALU_BUTT
} HI_UNF_H263E_PACK_TYPE_E;

/**MPEG4 package type*/
/**CNcomment: MPEG4\B4\F2\B0\FC\C0\E0\D0\CD */
typedef enum hiUNF_MPEG4E_PACK_TYPE_E
{
    HI_UNF_MPEG4E_PACK_VO    = 1,          /**<VO package*/ /**<CNcomment: VO \B0\FC*/
    HI_UNF_MPEG4E_PACK_VOS   = 2,         /**<VOS package*/ /**<CNcomment: VOS \B0\FC*/
    HI_UNF_MPEG4E_PACK_VOL   = 3,         /**<VOL package*/ /**<CNcomment: VOL \B0\FC*/
    HI_UNF_MPEG4E_PACK_VOP   = 4,         /**<VOP package*/ /**<CNcomment: VOP \B0\FC*/
    HI_UNF_MPEG4E_PACK_SLICE = 5        /**<Slice package*/ /**<CNcomment: SLICE \B0\FC*/
} HI_UNF_MPEG4E_PACK_TYPE_E;

/**HEVC NALU type*/
/**CNcomment: HEVC NALU\C0\E0\D0\CD */
typedef enum hiUNF_HEVCE_NALU_TYPE_E
{
    HI_UNF_HEVCE_NALU_PSLICE = 1,    /**<P slice NALU*/
    HI_UNF_HEVCE_NALU_ISLICE,        /**<I slice NALU*/
    HI_UNF_HEVCE_NALU_VPS,           /**<VPS NALU*/
    HI_UNF_HEVCE_NALU_SPS,           /**<SPS NALU*/
    HI_UNF_HEVCE_NALU_PPS,           /**<PPS NALU*/
    HI_UNF_HEVCE_NALU_SEI,           /**<SEI NALU*/
    HI_UNF_HEVCE_NALU_BUTT
} HI_UNF_HEVCE_NALU_TYPE_E;

/*VENC Rate Control Type*/
/**CNcomment: \B1\E0\C2\EB\C6\F7\C2\EB\C2ʿ\D8\D6\C6\C0\E0\D0\CD*/
typedef enum hiUNF_VENC_RATECONTROL_TYPE_E
{
    HI_UNF_VENC_RATECONTROL_TYPE_CBR,
    HI_UNF_VENC_RATECONTROL_TYPE_AVBR,
    HI_UNF_VENC_RATECONTROL_TYPE_BUTT
} HI_UNF_VENC_RATECONTROL_TYPE_E;

/**Defines the source of input frame rate.*/
/**CNcomment: \B6\A8\D2\E5\B1\E0\C2\EB\C6\F7\CA\E4\C8\EB֡\C2\CA\C0\B4Դ\C0\E0\D0͵\C4ö\BE\D9 */
typedef enum hiUNF_VENC_FRMRATE_TYPE_E
{
    HI_UNF_VENC_FRMRATE_TYPE_AUTO,         /**<Use the frame rate calculates from real-time statistics */ /**<CNcomment:\C4ڲ\BFͳ\BC\C6У\D5\FDʵʱ\CAյ\BD\B5\C4֡\C2\CA*/
    HI_UNF_VENC_FRMRATE_TYPE_STREAM,       /**<Use the frame rate comes from stream*/ /**<CNcomment: \B2\C9\D3\C3\C2\EB\C1\F7\D0\C5Ϣ\D6е\C4֡\C2\CA */
    HI_UNF_VENC_FRMRATE_TYPE_USER,         /**<Use the frame rate set by user*/ /**<CNcomment: \B2\C9\D3\C3\D3û\A7\C9\E8\D6õ\C4֡\C2\CA */
    HI_UNF_VENC_FRMRATE_TYPE_BUTT
}HI_UNF_VENC_FRMRATE_TYPE_E;

/**Data type of the Encoder*/
/**CNcomment: \B1\E0\C2\EB\C6\F7\CA\FD\BE\DD\C0\E0\D0\CD */
typedef union hiUNF_VENC_DATA_TYPE_U
{
    HI_UNF_H264E_NALU_TYPE_E   enH264EType;	/**<H.264 encoding data*/ /**<CNcomment: h264\B1\E0\C2\EB\CA\FD\BE\DD*/
    HI_UNF_H263E_PACK_TYPE_E   enH263EType;	/**<H.263 encoding data*/ /**<CNcomment: h263\B1\E0\C2\EB\CA\FD\BE\DD*/
    HI_UNF_MPEG4E_PACK_TYPE_E  enMPEG4EType;    /**<MPEG4 encoding data*/ /**<CNcomment: MPEG4\B1\E0\C2\EB\CA\FD\BE\DD*/
    HI_UNF_HEVCE_NALU_TYPE_E   enHEVCEType;     /**<HEVC encoding data*/ /**<CNcomment: HEVC\B1\E0\C2\EB\CA\FD\BE\DD*/
}HI_UNF_VENC_DATA_TYPE_U;

/*Output stream attributes structure*/
/**CNcomment: \CA\E4\B3\F6\C2\EB\C1\F7\CA\F4\D0Խṹ\CC\E5 */
typedef struct hiVENC_STREAM_S
{
    HI_U8                   *pu8Addr ;       /**<Stream virtual address*/ /**<CNcomment: \C2\EB\C1\F7\D0\E9\C4\E2\B5\D8ַ*/
    HI_U32                  u32SlcLen;      /**<Stream length*/ /**<CNcomment: \C2\EB\C1\F7\B3\A4\B6\C8*/
    HI_U32                  u32PtsMs;        /**<Presentation time stamp (PTS), in ms*/ /**<CNcomment: ʱ\BC\E4\B4\C1\A3\AC\B5\A5λ\CAǺ\C1\C3\EB*/
    HI_BOOL                 bFrameEnd;       /**<Frame end or not*/ /**<CNcomment: \B1\EAʶ\CAǷ\F1Ϊ֡\BD\E1\CA\F8*/
    HI_UNF_VENC_DATA_TYPE_U enDataType;      /**Encoding data type*/ /**<CNcomment: \B1\E0\C2\EB\CA\FD\BE\DD\C0\E0\D0\CD*/
}HI_UNF_VENC_STREAM_S;

/*Coding channal attributes structure*/
/**CNcomment: \B1\E0\C2\EBͨ\B5\C0\CA\F4\D0Խṹ\CC\E5 */
typedef struct hiUNF_VENC_CHN_ATTR_S
{
    HI_UNF_VCODEC_TYPE_E        enVencType;	      /**<Encoder type*/ /**<CNcomment: \B1\E0\C2\EB\C6\F7\C0\E0\D0\CD */
    HI_UNF_VCODEC_CAP_LEVEL_E   enCapLevel;       /**<Encoder level*/ /**<CNcomment: \B1\E0\C2\EB\C6\F7\B1\E0\C2\EB\C4\DC\C1\A6 */
    HI_UNF_H264_PROFILE_E       enVencProfile;    /**<H264 Profile of Encoder,it is just valid for H264 Encoder*/ /**<CNcomment: \B1\E0\C2\EBH264\B5ĵ\B5\B4Σ\ACֻ\D4ڶ\A8\D2\E5\C1\CBH264Э\D2\E9\B1\E0\C2\EB\C6\F7\C7\E9\BF\F6\CF²\C5\D3\D0Ч*/
    HI_U32                      u32Width;         /**<Width, 4-byte aligned. The width can be configured dynamically in the limit of encoder level.*/
                                                  /**<CNcomment: \BF\ED\B6\C8,4\B6\D4\C6\EB,\B1\E0\C2\EB\C4\DC\C1\A6\BC\B6\B7\B6Χ\C4ڿ\C9֧\B3ֶ\AF̬\C9\E8\D6\C3 */
    HI_U32                      u32Height;        /**<Height, 4-byte aligned.The height can be configured dynamically in the limit of encoder level.*/
                                                  /**<CNcomment: \B8߶\C8,4\B6\D4\C6\EB,\B1\E0\C2\EB\C4\DC\C1\A6\BC\B6\B7\B6Χ\C4ڿ\C9֧\B3ֶ\AF̬\C9\E8\D6\C3 */
    HI_U32                      u32StrmBufSize;   /**<Stream buffer size, the value ranges from 32*1024 to 40*1024*1024.You'd better set larger streamBufferSize if you set larger target bitrate or Qlevel.*/
                                                  /**<CNcomment: \C2\EB\C1\F7buffer\B4\F3С,\C5\E4\D6õ\C4\C2\EB\C1\F7buffer\B4\F3С\B7\B6ΧΪ32x1024\B5\BD40x1024x1024\A3\AC\C8\E7\B9\FB\C9\E8\D6\C3\C1˽ϸߵ\C4\C2\EB\C2ʻ\F2JPEGͼ\CF\F1\D6\CA\C1\BF\B2\CE\CA\FD\A3\AC\BD\A8\D2\E9\CAʵ\B1\D4\F6\B4\F3\C2\EB\C1\F7buffer\B4\F3С\A1\A3*/
    HI_U32                      u32RotationAngle; /**<Rotation angle. This parameter cannot be set.It must be set to 0.*/ /**<CNcomment: \D0\FDת\BDǶ\C8,\CE\DEЧ\C9\E8\D6\C3,\D0\EB\C5\E4\D6ó\C90*/
    HI_BOOL                     bSlcSplitEn;      /**<Slice split enable,it is just valid for H264 Encoder*/ /**<CNcomment: \CAǷ\F1ʹ\C4ָܷ\EEslice,ֻ\D4ڶ\A8\D2\E5\C1\CBH264Э\D2\E9\B1\E0\C2\EB\C6\F7\C7\E9\BF\F6\CF²\C5\D3\D0Ч*/
                                                  /**<CNcomment: \B7ָ\EE\B5Ĵ\F3С\A3\ACJPGE\CF\C2\D2\D4MCUΪ\B5\A5λ,H264\BB\F2\D5\DFMP4\D2\D4\D7ֽ\DAΪ\B5\A5λ, H263\B2\BB\B9\D8\D0\C4 */
    HI_U32                      u32TargetBitRate; /**<RC parameter for the VENC,it is just valid for H264 Encoder. It can be set dynamically.Some reference values as follows:above 5M for 1080P,above 3M for 720P, about 2M for D1*/
                                                   /**<CNcomment: Venc\CF\C2\CA\C7RC\B2\CE\CA\FD,\BD\F6\D4ڱ\E0\C2\EBH264Э\D2\E9\D3\D0Ч\A3\AC\BFɶ\AF̬\C9\E8\D6\C3.\B2\BF\B7ֲο\BCֵ\C8\E7\CF\C2:1080P\CF\C25M\D2\D4\C9ϣ\AC720P\CF\C23M\D2\D4\C9ϣ\ACD1\CF\C22M\D7\F3\D3\D2*/
    HI_U32                      u32TargetFrmRate; /**<Target frame rate. It can be set dynamically.*/         /**<CNcomment: Ŀ\B1\EA֡\C2\CA,\BFɶ\AF̬\C9\E8\D6\C3 */
    HI_U32                      u32InputFrmRate;  /**<Input frame rate. It can be set dynamically. The value of u32TargetFrmRate is less than or equal to the value of u32InputFrmRate.
                                                   ** Attention the if in the mode of attach source to encode the InputFrmRate which set by user is in vain.*/
                                                  /**<CNcomment: \CA\E4\C8\EB֡\C2\CA,\BFɶ\AF̬\C9\E8\D6\C3,u32TargetFrmRate <= u32InputFrmRate ,ע\D2\E2\D4ڰ\F3\B6\A8ģʽ\B1\E0\C2\EB\C7\E9\BF\F6\CF\C2\D3û\A7\C5\E4\D6õ\C4\CA\E4\C8\EB֡\C2ʽ\ABʧЧ*/
    HI_U32                      u32Gop;           /**<GOP size,it is just valid for H264 Encoder. It can be set dynamically.*/ /**<CNcomment: GOP\B4\F3С,\BD\F6\D4ڱ\E0\C2\EBH264Э\D2\E9\D3\D0Ч\A3\AC\BFɶ\AF̬\C9\E8\D6\C3 */
    HI_U32                      u32MaxQp;         /**<The maximum quantization parameter,it is just valid for H264 Encoder. It can be set dynamically.*/    /**<CNcomment: \D7\EE\B4\F3\C1\BF\BB\AF\B2\CE\CA\FD,\BD\F6\D4ڱ\E0\C2\EBH264Э\D2\E9\D3\D0Ч\A3\AC\BFɶ\AF̬\C9\E8\D6\C3*/
    HI_U32                      u32MinQp;         /**<The minimum quantization parameter,it is just valid for H264 Encoder. It can be set dynamically.*/    /**<CNcomment: \D7\EEС\C1\BF\BB\AF\B2\CE\CA\FD,\BD\F6\D4ڱ\E0\C2\EBH264Э\D2\E9\D3\D0Ч\A3\AC\BFɶ\AF̬\C9\E8\D6\C3*/
    HI_BOOL                     bQuickEncode;     /**<Quick Encode Mode enable*/ /**<CNcomment:\CAǷ\F1ʹ\C4ܿ\EC\CBٱ\E0\C2\EBģʽ*/
    HI_U8                       u8Priority;       /**<the Priority Level of the channal,should between 0 to the max num of channel minus 1.It can be set dynamically.*/
                                                  /**<CNcomment: \B1\E0\C2\EBͨ\B5\C0\B5\C4\D3\C5\CFȼ\B6\CA\F4\D0ԣ\ACȡֵ\B7\B6ΧΪ0~\D7\EE\B4\F3ͨ\B5\C0\CA\FD-1,\BFɶ\AF̬\C9\E8\D6\C3*/
    HI_U32                      u32Qlevel;        /**<The value ranges from 1 to 99 for the JPGE, it is just valid for JPEG Encoder.*/ /**<CNcomment: JPGEȡֵ\B7\B6Χ1-99\A3\ACֻ\D4ڶ\A8\D2\E5\C1\CBJPEG\B1\E0\C2\EB\C6\F7\C7\E9\BF\F6\CF²\C5\D3\D0Ч */
    HI_U32                      u32DriftRateThr;  /**<Encoder bitrate fluctuation threshold.If u32DriftRateThr = 20 means the fluctuation of threshold is 20%*/
                                                  /**<CNcomment: \B1\E0\C2\EB\C6\F7\C2\EB\C2ʲ\A8\B6\AF\E3\D0ֵ\A3\AC\C8\E7\C9\E8\D6ó\C920\A3\AC\B1\EDʾ\B2\A8\B6\AF\E3\D0ֵΪ20%*/

    HI_U32                      u32SplitSize;     /**<Split size. The size is in the unit of minimum coded unit (MCU) for the JPEG format and byte for the MP4 format. The split size can be ignored in H.263 format.*/
}HI_UNF_VENC_CHN_ATTR_S;

/*VENC Capability Information Of One Resolution*/
/**CNcomment: ĳһ\B7ֱ\E6\C2ʵı\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣ*/
typedef struct hiUNF_VENC_CAP_RESO_S
{
    HI_UNF_VCODEC_CAP_LEVEL_E enCapLevel;       /**<support max enCapLevel*//**<CNcomment: \D7\EE\B4\F3\B1\E0\C2\EB\C4\DC\C1\A6\BC\B6 */
    HI_U32  u32Height;                          /**<support max height*//**<CNcomment: \B8߶\C8 */
    HI_U32  u32Width;                           /**<support min height*//**<CNcomment: \BF\ED\B6\C8 */
    HI_U32  u32MaxFrmRate;                      /**<support max frame rate*//**<CNcomment: \D7\EE\B4\F3֡\C2\CA */
    HI_U32  u32MaxBitRate;                      /**<support max bit rate*//**<CNcomment: \D7\EE\B4\F3\C2\EB\C2\CA*/
    HI_U32  u32MinBitRate;                      /**<support min bit rate*//**<CNcomment: \D7\EEС\C2\EB\C2\CA*/
    HI_U32  u32MinBufSize;                      /**<support min stream buffer size*//**<CNcomment: \D7\EE\B4\F3\C4\DC\C1\A6\BC\B6\B6\D4Ӧ\B5\C4\D7\EEС\C2\EB\C1\F7buffer\B4\F3С*/
}HI_UNF_VENC_CAP_RESO_S;

/*VENC Capability Information Of One Encode Type*/
/**CNcomment: ĳһ\B1\E0\C2\EBЭ\D2\E9\B5ı\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣ*/
typedef struct hiUNF_VENC_CAP_INFO_S
{
    HI_UNF_VCODEC_TYPE_E   enCodecType;         /**<support venc type*//**<CNcomment: \B1\E0\C2\EB\C0\E0\D0\CD*/
    HI_U32                 u32MaxChnNum;        /**<support max channel num*//**<CNcomment: \D7\EE\B4\F3ͨ\B5\C0\CA\FD*/
    HI_UNF_VENC_CAP_RESO_S stMaxReso;           /**<support capability information of max resolution*//**<CNcomment: \D7\EE\B4\F3\B7ֱ\E6\C2ʶ\D4Ӧ\B5\C4\C4\DC\C1\A6\D0\C5Ϣ*/
    HI_UNF_VENC_CAP_RESO_S stMinReso;           /**<support capability information of min resolution*//**<CNcomment: \D7\EEС\B7ֱ\E6\C2ʶ\D4Ӧ\B5\C4\C4\DC\C1\A6\D0\C5Ϣ*/
}HI_UNF_VENC_CAP_INFO_S;

/*VENC Capability Information*/
/**CNcomment: \B1\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣ*/
typedef struct hiUNF_VENC_CAP_S
{
    HI_U32                 u32SupportTypeNum;                   /**<support venc type num*//**<CNcomment: \B1\E0\C2\EB\C6\F7֧\B3ֵı\E0\C2\EB\C0\E0\D0\CD\CA\FD\C1\BF */
    HI_UNF_VENC_CAP_INFO_S stCapInfo[HI_UNF_VENC_TYPE_NUM];     /**<capability information for venc types*//**<CNcomment: \B1\E0\C2\EB\C6\F7\B2\BBͬ\B1\E0\C2\EB\C0\E0\D0͵ı\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣ */
}HI_UNF_VENC_CAP_S;

/** @} */  /** <!-- ==== Struct Definition End ==== */


/********************************API declaration********************************/
/** \addtogroup      VENC */
/** @{ */  /** <!-- \A1\BEVENC\A1\BF */

/** 
\brief Initializes the video encoder. CNcomment: \B3\F5ʼ\BB\AF\CA\D3Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
Before using the VENC, you must call this API. CNcomment: \B5\F7\D3\C3VENCģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param[in] N/A CNcomment: \CE\DE CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_DEV_NOT_EXIST No VENC device exists. CNcomment: \C9豸\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NOT_DEV_FILE The file is not a VENC file. CNcomment: \CEļ\FE\B7\C7\C9豸 CNend
\retval ::HI_ERR_VENC_DEV_OPEN_ERR The VENC device fails to start. CNcomment: \B4\F2\BF\AA\C9豸ʧ\B0\DC CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_Init(HI_VOID);


/** 
\brief Deinitializes the video encoder. CNcomment: ȥ\B3\F5ʼ\BB\AF\CA\D3Ƶ\B1\E0\C2\EB\C6\F7 CNend
\attention \n
N/A CNcomment: \CE\DE CNend
\param[in] N/A CNcomment: \CE\DE CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_DEV_CLOSE_ERR The video encoder fails to stop. CNcomment: \B9رձ\E0\C2\EB\C6\F7ʧ\B0\DC CNend
\see \n
N/A CNcomment: \CE\DE  CNend
*/
HI_S32 HI_UNF_VENC_DeInit(HI_VOID);


/** 
\brief Obtains the default attributes of a VENC channel. CNcomment: \BB\F1ȡ\B1\E0\C2\EBͨ\B5\C0Ĭ\C8\CF\CA\F4\D0\D4 CNend
\attention \n
By default, the encoding size is D1, encoding format is H.264, and a frame is a slice.
CNcomment: Ĭ\C8\CFD1\B1\E0\C2룬H.264\B8\F1ʽ\A3\ACһ֡Ϊһ\B8\F6Slice CNend
\param[out] pstAttr Pointer to the attributes of a VENC channel. CNcomment: pstAttr ָ\CF\F2\B1\E0\C2\EBͨ\B5\C0\CA\F4\D0Ե\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_NULL_PTR The input pointer parameter is null. CNcomment: \CA\E4\C8\EBָ\D5\EB\B2\CE\CA\FDΪ\BF\D5ָ\D5\EB CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_GetDefaultAttr(HI_UNF_VENC_CHN_ATTR_S *pstAttr);


/** 
\brief Creates a VENC channel. CNcomment: \B4\B4\BD\A8\CA\D3Ƶ\B1\E0\C2\EBͨ\B5\C0 CNend
\attention \n
You must create a VENC channel before video encoding. 
CNcomment: \BD\F8\D0\D0\CA\D3Ƶ\B1\E0\C2\EBҪ\C7\F3\CA\D7\CFȴ\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0 CNend
\param[in] pstAttr Pointer to the attributes of a VENC channel. CNcomment: pstAttr ָ\CF\F2\B1\E0\C2\EBͨ\B5\C0\CA\F4\D0Ե\C4ָ\D5\EB CNend
\param[out] phVenc Pointer to the handle of a VENC channel. CNcomment: phVenc ָ\CF\F2\B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B5\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
\retval ::HI_ERR_VENC_NULL_PTR The input pointer parameter is null. CNcomment: \CA\E4\C8\EBָ\D5\EB\B2\CE\CA\FD\D3п\D5ָ\D5\EB CNend
\retval ::HI_ERR_VENC_CREATE_ERR The number of VENC channels exceeds the limit. CNcomment: \B1\E0\C2\EBͨ\B5\C0\CA\FD\D2\D1\C2\FA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
CNcomment: \CE\DE  CNend
*/
HI_S32 HI_UNF_VENC_Create(HI_HANDLE *phVenc,const HI_UNF_VENC_CHN_ATTR_S *pstAttr);


/** 
\brief Destroys a VENC channel. CNcomment: \CF\FA\BB\D9\CA\D3Ƶ\B1\E0\C2\EBͨ\B5\C0 CNend
\attention \n
\param[in] hVenc Handle of a VENC channel. CNcomment: CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No handle exists. CNcomment: \BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE  CNend
*/
HI_S32 HI_UNF_VENC_Destroy(HI_HANDLE hVenc);


/** 
\brief Attaches a VENC channel to the video source. CNcomment: \B0󶨱\E0\C2\EBͨ\B5\C0\B5\BD\CA\D3ƵԴ CNend
\attention \n
You must call this API before performing encoding and obtaining streams. CNcomment: \BF\AAʼ\B1\E0\C2\EB\BAͻ\F1ȡ\C2\EB\C1\F7֮ǰ\D0\E8Ҫ\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] hSrc Data source handle CNcomment: hSrc \CA\D3ƵԴ\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The video source is invalid. CNcomment: \CA\D3ƵԴ\B4\ED\CE\F3  CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_AttachInput(HI_HANDLE hVenc,HI_HANDLE hSrc);


/** 
\brief Detaches a VENC channel from the video source. CNcomment: \BD\E2\B0\F3\B6\A8\CA\D3ƵԴ CNend
\attention \n
You must stop encoding before calling this API.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CF\C8ֹͣ\B1\E0\C2\EB CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6  CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The video source is invalid. CNcomment: \CA\D3ƵԴ\B4\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_CHN_INVALID_STAT Invalid state which the video encoder does not stop encoding. CNcomment: \D2쳣״̬,\B1\E0\C2\EB\C6\F7δֹͣ\B1\E0\C2\EB CNend
\retval ::HI_ERR_VENC_CHN_NO_ATTACH The VENC channel doesn't attach any source. CNcomment: \B1\E0\C2\EBͨ\B5\C0û\D3а\F3\B6\A8\C8κ\CEԴ CNend
\see \n
N/A CNcomment: \CE\DE  CNend
*/
HI_S32 HI_UNF_VENC_DetachInput(HI_HANDLE hVencChn);


/** 
\brief Starts to perform encoding. CNcomment: \BF\AAʼ\B1\E0\C2\EB CNend
\attention \n
You must initialize the video encoder, create a VENC channel, and attach the channel to the video source before calling this API.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȳ\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7\A3\AC\B4\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0\A3\AC\B0\F3\B6\A8\CA\D3ƵԴ CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_Start(HI_HANDLE hVenc);


/** 
\brief Stops encoding. CNcomment: ֹͣ\B1\E0\C2\EB CNend
\attention \n
You must initialize the video encoder, create a VENC channel, attach the channel to the video source, and start to perform encoding before calling this API.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȳ\F5ʼ\BB\AF\B1\E0\C2\EB\C6\F7\A3\AC\B4\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0\A3\AC\B0\F3\B6\A8\CA\D3ƵԴ\A3\AC\D2Ѿ\AD\BF\AAʼ\B1\E0\C2\EB CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_Stop(HI_HANDLE hVenc);

/** 
\brief Obtains VENC streams. CNcomment: \BB\F1ȡ\CA\D3Ƶ\B1\E0\C2\EB\C2\EB\C1\F7 CNend
\attention \n
You must attach a VENC channel to the video source and start to perform encoding before calling this API.
The block time (in ms) is configurable. If u32TimeOutMs is set to 0, the block time is 0; if u32TimeOutMs is set to 0xFFFFFFFF, it indicates infinite wait. \n
If the block time is reached but no data is received, ::HI_ERR_VENC_BUF_EMPTY is returned.\n
If the wait time is 0 and there is no data, ::HI_ERR_VENC_BUF_EMPTY is returned.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȰ\F3\B6\A8\CA\D3ƵԴ\A3\AC\BF\AAʼ\B1\E0\C2\EB
\D7\E8\C8\FBʱ\BC\E4\BF\C9\D2\D4\C9\E8\D6ã\ACʱ\BC䵥λΪ\BA\C1\C3룬\C9\E8\D6\C3Ϊ0\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffffһֱ\B5ȴ\FD\A1\A3\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\BB\B9û\D3\D0\CA\FD\BEݵ\BD\B4\D4򷵻\D8::HI_ERR_VENC_BUF_EMPTY\n
\C8\E7\B9\FB\B5ȴ\FDʱ\BC\E4Ϊ0\A3\AC\C7\D2û\D3\D0\C2\EB\C1\F7\CA\FD\BEݣ\AC\D4򷵻\D8::HI_ERR_VENC_BUF_EMPTY\n CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[out] pstStream Pointer to the structure for storing streams CNcomment: pstStream \B4\E6\B7\C5\C2\EB\C1\F7\BDṹ\B5\C4ָ\D5\EB CNend
\param[in] u32TimeoutMs: Wait timeout, count in ms CNcomment: u32TimeoutMs\A3\BA\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_NULL_PTR The stream pointer is null. CNcomment: \C2\EB\C1\F7ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VENC_BUF_EMPTY Streams fail to be obtained. CNcomment: \BB\F1ȡ\C2\EB\C1\F7ʧ\B0\DC CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_AcquireStream(HI_HANDLE hVenc,HI_UNF_VENC_STREAM_S *pstStream, HI_U32 u32TimeoutMs);


/** 
\brief Releases VENC streams. CNcomment: \CAͷ\C5\CA\D3Ƶ\B1\E0\C2\EB\C2\EB\C1\F7 CNend
\attention \n
You must obtain streams and keep the streams unchanged before calling this API.
The stream which you get first should be release first.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȻ\F1ȡ\C2\EB\C1\F7\A3\AC\C7Ҳ\BB\C4ܸı\E4\C2\EB\C1\F7\C4\DA\C8ݡ\A3
\CFȻ\F1ȡ\B5\C4\C2\EB\C1\F7\D0\E8Ҫ\CF\C8\CAͷš\A3 CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] pstStream Pointer to the structure for storing streams CNcomment: pstStream \B4\E6\B7\C5\C2\EB\C1\F7\BDṹ\B5\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_NULL_PTR The stream pointer is null. CNcomment: \C2\EB\C1\F7ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VENC_CHN_RELEASE_ERR Streams fail to be released. CNcomment: \CAͷ\C5\C2\EB\C1\F7ʧ\B0\DC CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_ReleaseStream(HI_HANDLE hVenc, const HI_UNF_VENC_STREAM_S *pstStream);


/** 
\brief Sets the encoding channel attributes dynamically. CNcomment: \B6\AF̬\C9\E8\D6ñ\E0\C2\EBͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
You must create a VENC channel before calling this API.
This API just can change these attributes as follows:input framerate,target output framerate,target output bitrate,gop,
max/min QP,channel priority, whether use QuickEncode mode and even the encode width and height within the limits of the encoder level.
Moreover,even though you can't change the attributes of encoder level,encoder type,Stream buffer size,Rotation angle,Slice split enable and so on,
you should still assign the real value to them at that time.
It's better that you should call HI_UNF_VENC_GetAttr() to obtain the attributes of a VENC channel before calling this API.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȴ\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0 .\B8ýӽӿ\DAֻ\C4ܶ\AF̬\B5\C4\C9\E8\D6\C3\D2\D4\CF\C2ͨ\B5\C0\CA\F4\D0\D4:\CA\E4\C8\EB֡\C2ʣ\ACĿ\B1\EA\CA\E4\B3\F6֡\C2ʣ\ACĿ\B1\EA\CA\E4\B3\F6\C2\EB\C2ʣ\ACGOPֵ\A3\AC\D7\EE\B4\F3/\D7\EEС\C1\BF\BB\AF\B2\CE\CA\FD\A3\AC
+\B5\C0\D3\C5\CFȼ\B6\A3\AC \BF\EC\CBٱ\E0\C2\EBʹ\C4ܣ\AC\C9\F5\D6\C1\D4ڱ\E0\C2\EB\C4\DC\C1\A6\BC\B6\B7\B6Χ\CF¶\AF̬\B8ı\E4\B1\E0\C2\EB\BF\ED\B8ߡ\A3\B4\CB\CD⣬\BC\B4ʹ\B8ýӿڲ\BB\C4ܶ\AF̬\B8ı\E4\B1\E0\C2\EB\C4\DC\C1\A6\BC\B6\A3\AC\B1\E0\C2\EBЭ\D2飬\C2\EB\C1\F7buffer\B4\F3С\A3\AC
\D0\FDת\BDǶȣ\AC\B7ָ\EE\B1\E0\C2\EBʹ\C4ܵ\C8\CA\F4\D0ԣ\AC\D4ڵ\F7\D3øýӿ\DAʱ\C4㻹\CA\C7Ҫ\B8\F8\D5\E2Щͨ\B5\C0\CA\F4\D0Ը\B3\C9ϵ\B1ʱ\B5\C4ʵ\BC\CAֵ\A1\A3\D7\EE\BA\C3\D4ڵ\F7\D3øýӿ\DA֮ǰ\B5\F7\D3\C3HI_UNF_VENC_GetAttr()\BDӿڻ\F1ȡ\B5\BD\B5\B1ʱ\B5\C4ͨ\B5\C0\CA\F4\D0\D4 CNend
\param[in] Venc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] pstAttr Pointer to the attributes of a VENC channel CNcomment: pstAttr \B4\E6\B7ű\E0\C2\EBͨ\B5\C0\CA\F4\D0Ե\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_NULL_PTR The pointer is null. CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VENC_NOT_SUPPORT This change of attributes dosen't be supported. CNcomment: \B2\BB֧\B3ָ\C3\CA\F4\D0Զ\AF̬\C5\E4\D6\C3 CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_SetAttr(HI_HANDLE hVenc,const HI_UNF_VENC_CHN_ATTR_S *pstAttr);


/** 
\brief Obtains the attributes of a VENC channel. CNcomment: \BB\F1ȡ\B1\E0\C2\EBͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
You must create a VENC channel before calling this API.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȴ\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0 CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[out] pstAttr Encoding channel attribute CNcomment: pstAttr \B1\E0\C2\EBͨ\B5\C0\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_NULL_PTR The pointer is null. CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\see \n 
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_GetAttr(HI_HANDLE hVenc, HI_UNF_VENC_CHN_ATTR_S *pstAttr);


/** 
\brief Applies for I frames. CNcomment: \C7\EB\C7\F3I֡ CNend
\attention \n
The video encoder encodes an I frame as soon as possible after you call this API.\n
You can call this API when you set up a video call or fix errors.\n
If you call this API repeatedly in a short period, I frames may be not generated each time.\n
CNcomment: \B5\F7\D3øýӿں󣬱\E0\C2\EB\C6\F7\BBᾡ\BF\EC\B1\E0\C2\EB\B3\F6һ\B8\F6I֡\C0\B4.\n
\B4˽ӿ\DAһ\B0\E3\D3\C3\D3ڿ\C9\CAӵ绰\B3\A1\BE\B0\B5\C4ͨ\BB\B0\BD\A8\C1\A2\BAʹ\ED\CE\F3\BBָ\B4.\n
\B4˽ӿ\DAֻ\CA\C7"\BE\A1\D7\EE\B4\F3\C4\DC\C1\A6"\BE\A1\BF\EC\B1\E0\C2\EB\B3\F6һ\B8\F6I֡\C0\B4\A3\AC\C8\E7\B9\FB\D4ڶ\CCʱ\BC\E4\C4ڶ\E0\B4ε\F7\D3ô˽ӿڣ\AC\C4\C7ô\B2\BB\C4ܱ\A3֤ÿ\B4ε\F7\D3ö\BC\C4ܶ\D4Ӧ\B1\E0\C2\EB\B3\F6һ\B8\F6I֡\C0\B4.\n CNend
\param[in] hVencChn Handle of a VENC channel CNcomment: hVencChn \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_RequestIFrame(HI_HANDLE hVencChn);


/** 
\brief Input frame to VENC. CNcomment: \CF\F2\B1\E0\C2\EB\C6\F7\CB\CD֡ CNend
\attention \n
You must create a VENC channel before calling this API.
If the venc channel has already attach the source,::HI_ERR_VENC_CHN_INVALID_STAT is returned.
This API should be matched with the API: HI_UNF_VENC_DequeueFrame.
HI_UNF_VENC_QueueFrame is used to send frame data to Encoder for user and HI_UNF_VENC_DequeueFrame is used to call the Encoder 
to receive the frame data which has already be processed.
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȴ\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0.
\C8\E7\B9\FB\B1\E0\C2\EBͨ\B5\C0\D2Ѿ\AD\B0\F3\B6\A8Դ\A3\AC\BB᷵\BB\D8HI_ERR_VENC_CHN_INVALID_STAT \CE\DEЧ\B2\D9\D7\F7 
\B8ýӿ\DA\D0\E8Ҫ\D3\EB HI_UNF_VENC_DequeueFrame \BDӿ\DA\C5\E4\B6\D4ʹ\D3á\A3
HI_UNF_VENC_QueueFrame\BDӿ\DA\D3\C3\D3\DAΪ\D3û\A7\CCṩһ\B8\F6\BDӿ\DA\CF\F2\B1\E0\C2\EB\C6\F7\CB\CD֡\B9\A9\B1\E0\C2룬HI_UNF_VENC_DequeueFrame\BDӿ\DA\CAǱ\E0\C2\EB\C6\F7\B9黹\D2Ѿ\AD\B4\A6\C0\ED\B5\C4֡ CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] pstFrameinfo Frame information struct CNcomment: ֡\D0\C5Ϣ\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS                      Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST       No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NULL_PTR            The pointer is null. CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VENC_NO_INIT             The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_CHN_INVALID_STAT    Invalid state which the VENC channel has already attach source. CNcomment: \D2쳣״̬\A3\AC\B1\E0\C2\EB\C6\F7ͨ\B5\C0\D2Ѿ\AD\B0\F3\B6\A8Դ CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_QueueFrame(HI_HANDLE hVenc, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);


/** 
\brief release frame from VENC. CNcomment: \CF\F2\B1\E0\C2\EB\C6\F7\BB\B9֡ CNend
\attention \n
You must create a VENC channel before calling this API.
If the venc channel has already attach the source,::HI_ERR_VENC_CHN_INVALID_STAT is returned.
Refer to the attention of the API: HI_UNF_VENC_QueueFrame.
If HI_UNF_VENC_DequeueFrame return HI_SUCCESS, it means the corresponding frame buffer could be set free by user. 
CNcomment: \B5\F7\D3øýӿ\DA\D0\E8Ҫ\CA\D7\CFȴ\B4\BD\A8\B1\E0\C2\EBͨ\B5\C0.
\C8\E7\B9\FB\B1\E0\C2\EBͨ\B5\C0\D2Ѿ\AD\B0\F3\B6\A8Դ\A3\AC\BB᷵\BB\D8HI_ERR_VENC_CHN_INVALID_STAT \CE\DEЧ\B2\D9\D7\F7 
ע\D2\E2\CA\C2\CF\EE\B2\CE\D5\D5 HI_UNF_VENC_QueueFrame\BDӿڡ\A3\C8\E7\B9\FBHI_UNF_VENC_DequeueFrame\BDӿڷ\B5\BBسɹ\A6\A3\AC\D2\E2ζ\D7Ŷ\D4Ӧ\B5\C4֡\B4\E6\D3û\A7\BF\C9\D2\D4\CAͷ\C5 CNend
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[out] pstFrameinfo Frame information struct CNcomment: ֡\D0\C5Ϣ\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS                       Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST        No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_NULL_PTR             The pointer is null. CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VENC_NO_INIT              The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VENC_CHN_INVALID_STAT     Invalid state which the VENC channel has already attach source. CNcomment: \D2쳣״̬\A3\AC\B1\E0\C2\EB\C6\F7ͨ\B5\C0\D2Ѿ\AD\B0\F3\B6\A8Դ CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_DequeueFrame(HI_HANDLE hVenc, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);

/**
\brief get encoding capbility from VENC. CNcomment: \BB\F1ȡ\B1\E0\C2\EB\C6\F7\B5ı\E0\C2\EB\C4\DC\C1\A6 CNend
\attention \n
\param[in] N/A CNcomment: \CE\DE CNend
\param[out] pstCapability Pointer to the capability of VENC CNcomment: pstCapability \B4\E6\B7ű\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣ\B5\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS               Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_NULL_PTR     The pointer is null. CNcomment: ָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_FAILURE               Capability fail to be obtained. CNcomment: \BB\F1ȡ\B1\E0\C2\EB\C4\DC\C1\A6\D0\C5Ϣʧ\B0\DC CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_GetCapability(HI_UNF_VENC_CAP_S *pstCapability);

/**
\brief set encoding rate control type of VENC. CNcomment: \C9\E8\D6ñ\E0\C2\EB\C6\F7\B5\C4\C2\EB\C2ʿ\D8\D6\C6\C0\E0\D0\CD CNend
\attention \n
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] enRcType Enum of rate control mode CNcomment: enRcType \C3\E8\CA\F6\B1\E0\C2\EB\C2\EB\C2ʿ\D8\D6\C6\C0\E0\D0͵\C4ö\BE\D9 CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_SetRateControlType(HI_HANDLE hVenc, HI_UNF_VENC_RATECONTROL_TYPE_E enRcType);


/**
\brief get encoding rate control type of VENC. CNcomment: \BB\F1ȡ\B1\E0\C2\EB\C6\F7\B5\C4\C2\EB\C2ʿ\D8\D6\C6\C0\E0\D0\CD CNend
\attention \n
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] penRcType Enum of rate control mode CNcomment: enRcType \C3\E8\CA\F6\B1\E0\C2\EB\C2\EB\C2ʿ\D8\D6\C6\C0\E0\D0͵\C4ö\BEٵ\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_GetRateControlType(HI_HANDLE hVenc, HI_UNF_VENC_RATECONTROL_TYPE_E *penRcType);

/**
\brief set input frame rate source type of VENC. CNcomment: \C9\E8\D6ñ\E0\C2\EB\C6\F7\B5\C4\CA\E4\C8\EB֡\C2\CA\C0\B4Դ\C0\E0\D0\CD CNend
\attention \n
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] enInputFrmRateType Enum of input frame rate mode CNcomment: enInputFrmRateType \C3\E8\CA\F6\CA\E4\C8\EB֡\C2\CA\C0\B4Դ\C0\E0\D0͵\C4ö\BE\D9 CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_SetInputFrmRateType(HI_HANDLE hVenc, HI_UNF_VENC_FRMRATE_TYPE_E enInputFrmRateType);

/**
\brief get input frame rate source type of VENC. CNcomment: \BB\F1ȡ\B1\E0\C2\EB\C6\F7\B5\C4\CA\E4\C8\EB֡\C2\CA\C0\B4Դ\C0\E0\D0\CD CNend
\attention \n
\param[in] hVenc Handle of a VENC channel CNcomment: hVenc \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA CNend
\param[in] penInputFrmRateType Enum of input frame rate control mode CNcomment: enRcType \C3\E8\CA\F6\B1\E0\C2\EB\CA\E4\C8\EB֡\C2\CA\C0\B4Դ\C0\E0\D0͵\C4ö\BEٵ\C4ָ\D5\EB CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_VENC_CHN_NOT_EXIST No VENC channel handle exists. CNcomment: \B1\E0\C2\EBͨ\B5\C0\BE\E4\B1\FA\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VENC_INVALID_PARA The channel attributes are incorrect. CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C9\E8\D6ô\ED\CE\F3 CNend
\retval ::HI_ERR_VENC_NO_INIT The video encoder is not initialized. CNcomment: \B1\E0\C2\EB\C6\F7δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_UNF_VENC_GetInputFrmRateType(HI_HANDLE hVenc, HI_UNF_VENC_FRMRATE_TYPE_E *penInputFrmRateType);


/** @} */  /** <!-- ==== API Declaration End ==== */
#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif

#endif//__HI_UNF_VENC_H__

