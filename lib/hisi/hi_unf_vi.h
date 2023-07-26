/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2010/03/26
  Description   :
  History       :
  1.Date        : 2010/03/26
    Author      : sdk
    Modification: Created file

 *******************************************************************************/

/**
 * \file
 * \brief Describes the information about video input (VI). CNcomment: \CCṩVI\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef  __HI_UNF_VI_H__
#define  __HI_UNF_VI_H__

#include "hi_type.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif

/********************************Macro Definition********************************/
/** \addtogroup      VI */
/** @{ */  /** <!-- \A1\BEVI\A1\BF */
/**Maximum external buffer number*/
/**CNcomment: VI\B9\DC\C0\ED\CDⲿ\BB\BA\B3\E5\C7\F8\D7\EE\B4\F3\B8\F6\CA\FD*/
#define MAX_VI_EXT_BUF_NUM (16)

/** @} */  /** <!-- ==== Macro Definition end ==== */

/********************************Struct Definition********************************/
/** \addtogroup      VI */
/** @{ */  /** <!-- \A1\BEVI\A1\BF */

/**Input port */
/**CNcomment: \CA\E4\C8\EB\B6˿\DA */
typedef enum hiUNF_VI_E
{
    HI_UNF_VI_PORT0 = 0,      /**<Port 0 *//**<CNcomment: \B6˿\DA0*/
    HI_UNF_VI_PORT1,          /**<Port 1 *//**<CNcomment: \B6˿\DA1*/
    HI_UNF_VI_BUTT
} HI_UNF_VI_E;

/**Input interface mode */
/**CNcomment: \CA\E4\C8\EB\BDӿ\DAģʽ */
typedef enum hiUNF_VI_INPUT_MODE_E
{
    HI_UNF_VI_MODE_BT656_576I = 0,  /**<ITU-R BT.656 YUV4:2:2 standard, 576I *//**<CNcomment: ITU-R BT.656 YUV4:2:2 \B1\EA׼\A3\AC576I */
    HI_UNF_VI_MODE_BT656_480I,      /**<ITU-R BT.656 YUV4:2:2 standard, 480I *//**<CNcomment: ITU-R BT.656 YUV4:2:2 \B1\EA׼\A3\AC480I */
    HI_UNF_VI_MODE_BT601_576I,      /**<ITU-R BT.601 YUV4:2:2 standard, 576I *//**<CNcomment: ITU-R BT.601 YUV4:2:2 \B1\EA׼ */
    HI_UNF_VI_MODE_BT601_480I,      /**<ITU-R BT.601 YUV4:2:2 standard, 480I *//**<CNcomment: ITU-R BT.601 YUV4:2:2 \B1\EA׼ */
    HI_UNF_VI_MODE_BT1120_640X480P, /**<ITU-R BT.1120 YUV4:2:2 standard, 480P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC640x480P */
    HI_UNF_VI_MODE_BT1120_480P,     /**<ITU-R BT.1120 YUV4:2:2 standard, 480P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC720x480P */
    HI_UNF_VI_MODE_BT1120_576P,     /**<ITU-R BT.1120 YUV4:2:2 standard, 576P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC720x576P */
    HI_UNF_VI_MODE_BT1120_720P_50,  /**<ITU-R BT.1120 YUV4:2:2 standard, 720P_50 *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC720P_50 */
    HI_UNF_VI_MODE_BT1120_720P_60,  /**<ITU-R BT.1120 YUV4:2:2 standard, 720P_60 *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC720P_60 */
    HI_UNF_VI_MODE_BT1120_1080I_50, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080I_50 *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080I_50 */
    HI_UNF_VI_MODE_BT1120_1080I_60, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080I_60 *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080I_60 */
    HI_UNF_VI_MODE_BT1120_1080P_25, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080P_25 */
    HI_UNF_VI_MODE_BT1120_1080P_30, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080P_30 */
    HI_UNF_VI_MODE_BT1120_1080P_50, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080P_50 */
    HI_UNF_VI_MODE_BT1120_1080P_60, /**<ITU-R BT.1120 YUV4:2:2 standard, 1080P *//**<CNcomment: ITU-R BT.1120 YUV4:2:2 \B1\EA׼\A3\AC1080P_60 */
    HI_UNF_VI_MODE_DIGITAL_CAMERA_480P_30,    /**<Digital camera. The data format can be RGB or YCbCr,480P_30*//**<CNcomment:\CA\FD\D7\D6\C9\E3\CF\F1ͷ\A3\AC\CA\FD\BEݿ\C9\C4\DC\CA\C7RGB\BB\F2\D5\DFYCbCr\A3\AC480P_30 */
    HI_UNF_VI_MODE_DIGITAL_CAMERA_576P_30,    /**<Digital camera. The data format can be RGB or YCbCr,576P_30 *//**<CNcomment:\CA\FD\D7\D6\C9\E3\CF\F1ͷ\A3\AC\CA\FD\BEݿ\C9\C4\DC\CA\C7RGB\BB\F2\D5\DFYCbCr\A3\AC576P_30*/
    HI_UNF_VI_MODE_DIGITAL_CAMERA_720P_30,    /**<Digital camera. The data format can be RGB or YCbCr,720P_30 *//**<CNcomment:\CA\FD\D7\D6\C9\E3\CF\F1ͷ\A3\AC\CA\FD\BEݿ\C9\C4\DC\CA\C7RGB\BB\F2\D5\DFYCbCr\A3\AC720P_30 */
    HI_UNF_VI_MODE_DIGITAL_CAMERA_1080P_30,   /**<Digital camera. The data format can be RGB or YCbCr,1080P_30 *//**<CNcomment:\CA\FD\D7\D6\C9\E3\CF\F1ͷ\A3\AC\CA\FD\BEݿ\C9\C4\DC\CA\C7RGB\BB\F2\D5\DFYCbCr \A3\AC1080P_30*/
    HI_UNF_VI_MODE_HDMIRX,              /**HDMI INPUT *//**<CNcomment: ITU-R YUV4:4:4 \B1\EA׼ \D6\F0\D0\D0\D0ź\C5*/
    HI_UNF_VI_MODE_BUTT
} HI_UNF_VI_INPUT_MODE_E;

/**VI frame buffer management mode */
/**CNcomment: VI֡\BB\BA\B4\E6\B9\DC\C0\ED\B7\BDʽ */
typedef enum hiUNF_VI_BUF_MGMT_E
{
    HI_UNF_VI_BUF_ALLOC = 0,  /**<VI alloc buffer *//**<CNcomment: VI\C9\EA\C7\EB֡BUF */
    HI_UNF_VI_BUF_MMAP,       /**<User alloc frame buffer, then maps it to VI *//**<CNcomment: \D3û\A7\C9\EA\C7\EB֡BUF\A3\AC\B2\A2ӳ\C9\E4\B8\F8VI */
    HI_UNF_VI_BUF_BUTT
} HI_UNF_VI_BUF_MGMT_E;

/**VI frame buffer struct */
/**CNcomment: VI֡\BB\BA\B4\E6\BDṹ\CC\E5 */
typedef struct hiUNF_VI_BUFF_ATTR_S
{
    HI_VOID *pUsrVirAddr[MAX_VI_EXT_BUF_NUM];  /**<User virtual address *//**<CNcomment: \D3û\A7̬\D0\E9\C4\E2\B5\D8ַ*/
    HI_U32 u32PhyAddr[MAX_VI_EXT_BUF_NUM];     /**<Physical address *//**<CNcomment: \CE\EF\C0\ED\B5\D8ַ*/
    HI_U32 u32BufNum;                          /**<Buffer number *//**<CNcomment: \BB\BA\B3\E5\C7\F8\B8\F6\CA\FD*/
    HI_U32 u32Stride;                          /**<Stride of external frame buffer *//**<CNcomment:\CDⲿ֡\B4\E6\B5\C4stride*/
} HI_UNF_VI_BUFFER_ATTR_S;


/**Vvideo 3D to 2D transfer mode */
/**CNcomment: 3D\B2\A5\B7\C5ģʽ */
typedef enum hiUNF_VI_3DT2D_MODE_E
{
    HI_UNF_VI_3DT2D_OFF = 0,        /**< Keep normal left and right eye 3D format *//**<CNcomment: \B1\A3\C1\F43D\B8\F1ʽ\B5\C4\D7\F3\D3\D2\D1\DB\D5\FD\B3\A3\B2\A5\B7\C5ͼ\CF\F1 */
    HI_UNF_VI_3DT2D_L,              /**< Keep normal left eye 3D format*//**<CNcomment: \B1\A3\C1\F43D\B8\F1ʽ\B5\C4\D7\F3\D1\DBͼ\CF\F1 */
    HI_UNF_VI_3DT2D_R,              /**< Keep normal right eye 3D format*//**<CNcomment: \B1\A3\C1\F43D\B8\F1ʽ\B5\C4\D3\D2\D1\DBͼ\CF\F1 */

    HI_UNF_VI_3DT2D_BUTT,
} HI_UNF_VI_3DT2D_MODE_E;


/**VI attributes */
/**CNcomment: VI\CA\F4\D0\D4 */
typedef struct hiUNF_VI_ATTR_S
{
    HI_BOOL                           bVirtual;             /**<Whether to create virtual VI, only u32BufNum is valid in virtual VI mode *//**<CNcomment: \CAǷ񴴽\A8\D0\E9\C4\E2VI\A3\AC\D0\E9\C4\E2VI\CF\C2ֻ\D3\D0u32BufNum\B2\CE\CA\FD\D3\D0Ч*/
    HI_UNF_VI_INPUT_MODE_E            enInputMode;          /**<Video input mode *//**<CNcomment: \CA\D3Ƶ\CA\E4\C8\EBģʽ */
    HI_RECT_S                         stInputRect;          /**<Crop region of a window *//**<CNcomment: \B4\B0\BFڵĲü\F5\C7\F8\D3\F2 */
    HI_UNF_VIDEO_FORMAT_E             enVideoFormat;        /**<Output Video format *//**<CNcomment: \CA\D3Ƶ\B8\F1ʽ */
    HI_UNF_VI_BUF_MGMT_E              enBufMgmtMode;        /**<VI frame buffer management mode *//**<CNcomment: VI֡\BB\BA\B4\E6\B9\DC\C0\ED\B7\BDʽ */
    HI_U32                            u32BufNum;            /**<Number of available buffers *//**<CNcomment: \BF\C9\D3õ\C4֡buf\B5ĸ\F6\CA\FD */

    HI_BOOL                           bInterlace;           /**<Intput video interlace or progressive *//**<CNcomment: \D6\F0\D0и\F4\D0\D0\D0\C5Ϣ */
    HI_U32                            u32Width;             /**<Intput video width *//**<CNcomment: Դͼ\CF\F1һ֡\B5Ŀ\ED\B6\C8,3D\B8\F1ʽΪ\B5\A5\D1ۿ\ED\B8\DF */
    HI_U32                            u32Height;            /**<Intput video height *//**<CNcomment: Դͼ\CF\F1һ֡\B5ĸ߶ȣ\AC\BC\B4\B8\F4\D0\D0\D0ź\C5\CA\C7\C1\BD\B3\A1\B5ĸ߶ȣ\AC\D6\F0\D0\D0\D0ź\C5\CA\C7һ֡\B5ĸ߶ȣ\AC3D\B8\F1ʽΪ\B5\A5\D1ۿ\ED\B8\DF */
    HI_U32                            u32Vblank;	        /**<Intput video field blanking width, used 3d FB*//**<CNcomment: \B3\A1\CF\FB\D2\FE\C7\F8\BF\ED\B6ȣ\AC\D3\C3\D3ڴ\A6\C0\ED3D\B8\F1ʽFP */
    HI_U32                            u32FrameRate;         /**<Intput video intput frequency *//**<CNcomment: \CA\E4\C8\EB֡\C2\CA [24Hz,85] */
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E en3dFmt;              /**<Intput video format 2D or3D *//**<CNcomment: 2D/3D \B8\F1ʽ */
    HI_UNF_VIDEO_FORMAT_E             enPixFmt;             /**<Intput pixel format *//**<CNcomment: \CA\E4\C8\EB\CF\F1\CBظ\F1ʽ RGB444,YUV444/422 */
    HI_UNF_PIXEL_BITWIDTH_E           enSrcBitWidth;        /**<Intput pixel Width *//**<CNcomment: \CA\E4\C8\EBλ\BF\ED 8/10/12BIT */
    HI_UNF_OVERSAMPLE_MODE_E          enOverSample;         /**<Intput Over Sample format *//**<CNcomment: \B9\FD\B2\C9\D1\F9ģʽ */
    HI_UNF_COLOR_SPACE_E              enColorSpace;         /**<Intput Color Space *//**<CNcomment: ɫ\B2ʿռ\E4 */
    HI_UNF_VI_3DT2D_MODE_E            enDst3DT2DMode;       /**<video 3D to 2D mode *//**<CNcomment: \BE\B2̬,3D\B2\A5\B7\C5ģʽ\A3\AC\D3ɰ\F3\B6\A8ģ\BF\E9(VENC/VDP)ȷ\B6\A8 */
    HI_UNF_PIXEL_BITWIDTH_E           enDstBitWidth;        /**<output pixel Width *//**<CNcomment: \BE\B2̬,\CA\E4\C8\EBΪ\CA\E4\C8\EBλ\BF\EDΪ8bit\D4\F28bit\CA\E4\B3\F6\A3\AC\B4\F3\D3\DA8bit\D4\F210bit\CA\E4\B3\F6\A3\BB\BB\F2\D4\F2\D3ɰ\F3\B6\A8ģ\BF\E9ȷ\C8\CF\CA\E4\B3\F6֡\C2\CA */
} HI_UNF_VI_ATTR_S;
/** @} */  /** <!-- ==== Struct Definition End ==== */

/********************************API Declaration********************************/
/** \addtogroup      VI */
/** @{ */  /** <!-- \A1\BEVI\A1\BF */

/**
 \brief Initializes the video input unit (VIU). CNcomment: \B3\F5ʼ\BB\AFVI CNend
 \attention \n
Before calling the VIU, you must call this application programming interface (API).
CNcomment: \B5\F7\D3\C3VIģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
 \param[in] N/A CNcomment: \CE\DE CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_DEV_NOT_EXIST No VI device exists. CNcomment: \C9豸\B2\BB\B4\E6\D4\DA CNend
 \retval ::HI_ERR_VI_NOT_DEV_FILE The file is not a VI file. CNcomment: \CEļ\FE\B7\C7\C9豸 CNend
 \retval ::HI_ERR_VI_DEV_OPENED The VI device fails to be started. CNcomment: \B4\F2\BF\AA\C9豸ʧ\B0\DC CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_Init(HI_VOID);

/**
 \brief Deinitializes the VIU. CNcomment: ȥ\B3\F5ʼ\BB\AFVI CNend
 \attention \n
 \param[in] N/A CNcomment: \CE\DE CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_DeInit(HI_VOID);

/**
 \brief Obtains the attributes of a VI port. CNcomment: \BB\F1ȡVI\B6˿\DAĬ\C8\CF\CA\F4\D0\D4 CNend
 \attention \n
By default, port 0 is used, half D1 and BT656 formats are used, the data of the odd field is collected, and the semi-planar YUV4:2:0 data is output.
CNcomment: Ĭ\C8\CFPort=0, HALF-D1, BT656\A3\AC\B2ɼ\AFż\B3\A1\A3\AC\CA\E4\B3\F6SemiPlanner YUV4:2:0\B8\F1ʽ\CA\FD\BE\DD CNend
 \param[out] pstAttr Pointer to VI attributes CNcomment: VI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_GetDefaultAttr(HI_UNF_VI_ATTR_S *pstAttr);

/**
 \brief Set the attributes of a VI port. CNcomment: \C9\E8\D6\C3VI Port\CA\F4\D0\D4 CNend
 \attention \n
This reserved API is combined with HI_UNF_VI_Create, and cannot be called dynamically.
CNcomment: Ԥ\C1\F4\BDӿڣ\AC\D3\EBCreate\BA\CFһ\A3\AC\B2\BB\BFɶ\AF̬\B5\F7\D3\C3 CNend
 \param[in] hVi VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[in] pstAttr  Pointer to VI attributes CNcomment: VI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_CHN_INIT_BUF_ERR An error occurs when the buffer is initialized. CNcomment: \B3\F5ʼ\BB\AFbuffer\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_INVALID_PARA The attribute parameters are incorrect. CNcomment: \CA\F4\D0Բ\CE\CA\FD\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_SetAttr(HI_HANDLE hVI, HI_UNF_VI_ATTR_S *pstAttr);

/**
 \brief Obtains the attributes of a VI port. CNcomment: \BB\F1ȡVI Port\CA\F4\D0\D4 CNend
 \attention \n
 \param[in] hVi VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[out] pstAttr Pointer to VI attributes CNcomment: VI\CA\F4\D0\D4ָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_GetAttr(HI_HANDLE hVI, HI_UNF_VI_ATTR_S *pstAttr);

/**
 \brief Enables a VI port to create a VI handle. CNcomment: \B4\F2\BF\AAVI Port\A3\AC\B4\B4\BD\A8Vi\BE\E4\B1\FA CNend
 \attention \n
Before calling the VIU, you must call this API.\n
Unless the virtual VI is used, the port ID must correspond to the hardware. That is, the hardware and software must use the same port\n
CNcomment: \B5\F7\D3\C3VI ģ\BF\E9\D0\E8Ҫ\CA\D7\CFȵ\F7\D3øýӿ\DA\n
           \B3\FD\B7\C7ʹ\D3\C3\D0\E9\C4\E2VI, \B7\F1\D4\F2PortID\D0\E8Ҫ\D3\EBӲ\BC\FE\B6\D4Ӧ,Ӳ\BC\FE\C9\CFʹ\D3\C3\C1\CB\C4ĸ\F6Port,\C4\C7ô\C8\ED\BC\FEҲ\B1\D8\D0\EBʹ\D3\C3\C4ĸ\F6Port.\n CNend
 \param[in] enViPort VI port CNcomment: VI\B6˿\DA CNend
 \param[in] pstAttr Pointer to VI attributes CNcomment: VI\CA\F4\D0\D4ָ\D5\EB CNend
 \param[out] phandle hVi Pointer to the VI handle CNcomment: VI\BE\E4\B1\FAָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \retval ::HI_ERR_VI_CHN_INIT_BUF_ERR An error occurs when the buffer is initialized. CNcomment: \B3\F5ʼ\BB\AFbuffer\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_INVALID_PARA The attribute parameters are incorrect. CNcomment: \CA\F4\D0Բ\CE\CA\FD\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */

HI_S32 HI_UNF_VI_Create(HI_UNF_VI_E enViPort, HI_UNF_VI_ATTR_S *pstAttr, HI_HANDLE *phandle);

/**
 \brief Disable a VI port to destroy the handle. CNcomment: \B9ر\D5VI Port\A3\AC\CF\FA\BBپ\E4\B1\FA CNend
 \attention \n
 \param[in] hVi VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_Destroy(HI_HANDLE hVI);

/**
 \brief Start VI. CNcomment: \C6\F4\B6\AFVI\A3\AC\CF\FA\BBپ\E4\B1\FA CNend
 \attention \n
 \param[in] hVI VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_Start(HI_HANDLE hVI);

/**
 \brief Stop VI. CNcomment: ֹͣVI\A3\AC\CF\FA\BBپ\E4\B1\FA CNend
 \attention \n
 \param[in] hVI VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_Stop(HI_HANDLE hVI);

/**
 \brief Set external buffer which will be managed by VI. CNcomment: \C9\E8\D6\C3\CDⲿ\BB\BA\B3\E5\C7\F8\A3\AC\D3\C9VI\B9\DC\C0\ED CNend
 \attention \n
 The interface is only valid in real VI scene, and ::HI_UNF_VI_BUF_MMAP mode should be set.
 CNcomment: \D3û\A7ֻ\C4\DC\D4\DAʵ\CC\E5VI\B3\A1\BE\B0\CF£\AC\C9\E8\D6\C3Ϊ::HI_UNF_VI_BUF_MMAPģʽʱ\A3\AC\B2\C5\C4\DCʹ\D3ô˽ӿ\DA\n CNend
 \param[in] hVI VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[in] pstBufAttr Buffer attributes CNcomment: \BB\BA\B3\E5\C7\F8\CA\F4\D0\D4 CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_SetExternBuffer(HI_HANDLE hVI, HI_UNF_VI_BUFFER_ATTR_S* pstBufAttr);

/**
 \brief Obtains the address of a frame buffer over a VI port.
 CNcomment:\BB\F1ȡ\D0\E9\C4\E2VI Port һ֡ͼ\CF\F1Buffer CNend
 \attention \n
 The interface can only be used in virual VI scene\n
CNcomment: ֻ\D3\D0\D4\DA\D0\E9\C4\E2VI\B3\A1\BE\B0\CF£\AC\B2ſ\C9ʹ\D3ô˽ӿڻ\B9֡\n CNend
 \param[in] hVI VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[out] pViBuf Pointer to the VI buffer CNcomment: VI bufferָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_DequeueFrame(HI_HANDLE hVI, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/**
 \brief Releases the VI frame buffer for the driver.
 CNcomment: \B7\A2\CB\CD\D0\E9\C4\E2VI Port һ֡ͼ\CF\F1Buffer\A3\AC\C7\FD\B6\AF\D0\E9\C4\E2Port\B9\A4\D7\F7 CNend
 \attention
 The interface can only be used in virual VI scene\n
CNcomment: ֻ\D3\D0\D4\DA\D0\E9\C4\E2VI\B3\A1\BE\B0\CF£\AC\B2ſ\C9ʹ\D3ô˽ӿ\DA\CB\CD֡\n CNend
 \param[in] hVI VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[in] pViBuf Pointer to the VI buffer CNcomment: VI bufferָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_QueueFrame(HI_HANDLE hVI, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/**
 \brief Obtains the address of a YUV picture. CNcomment: \BB\F1ȡһ֡YUV ͼ\CF\F1\B5\D8ַ CNend
 \attention \n
You do not need to call this API generally. It is recommended that you bind the VIU to the video encoder (VENC) or video output unit (VOU) to implement the encoding function or VIVO loopback function.
CNcomment: һ\B0\E3\C7\E9\BF\F6\CF£\AC\D3û\A7\B2\BB\D0\E8Ҫ\B5\F7\D3ô˽ӿڣ\AC\CDƼ\F6ֱ\BDӽ\ABVI\D3\EBVENC\BB\F2\D5\DFVO\BD\F8\D0а\F3\B6\A8\D2Ա\E3ʵ\CFֱ\E0\C2\EB\BB\F2\D5\DFVIVO\BB\B7\BBع\A6\C4ܡ\A3 CNend
 \param[in] hVi VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[out] pViBuf Pointer to the VI buffer CNcomment: VI bufferָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_AcquireFrame(HI_HANDLE hVI, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo, HI_U32 u32TimeoutMs);

/**
 \brief Releases the frame buffer for the VIU after the VENC or VOU obtains a YUV picture.
CNcomment: \D3û\A7\B9黹һ֡YUV ͼ\CF\F1\B5\D8ַ CNend
 \attention \n
You do not need to call this API generally. It is recommended that you bind the VIU to the VENC or VOU to implement the encoding function or VIVO loopback function.
CNcomment: һ\B0\E3\C7\E9\BF\F6\CF£\AC\D3û\A7\B2\BB\D0\E8Ҫ\B5\F7\D3ô˽ӿڣ\AC\CDƼ\F6ֱ\BDӽ\ABVI\D3\EBVENC\BB\F2\D5\DFVO\BD\F8\D0а\F3\B6\A8\D2Ա\E3ʵ\CFֱ\E0\C2\EB\BB\F2\D5\DFVIVO\BB\B7\BBع\A6\C4ܡ\A3 CNend
 \param[in] hVi VI handle CNcomment: VI\BE\E4\B1\FA CNend
 \param[in] pViBuf Pointer to the VI buffer CNcomment: VI bufferָ\D5\EB CNend
 \retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
 \retval ::HI_ERR_VI_CHN_NOT_EXIST The handle is incorrect. CNcomment: \BE\E4\B1\FA\B4\ED\CE\F3 CNend
 \retval ::HI_ERR_VI_NULL_PTR The pointer is null. CNcomment: \BF\D5ָ\D5\EB CNend
 \see \n
N/A CNcomment: \CE\DE CNend
 */
HI_S32 HI_UNF_VI_ReleaseFrame(HI_HANDLE hVI, const HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/** @} */  /** <!-- ====API Declaration End ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
