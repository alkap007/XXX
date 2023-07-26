/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vo.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/16
  Description   :
  History       :
  1.Date        : 2009/12/16
    Author      : sdk
    Modification: Created file

*******************************************************************************/
/**
 * \file
 * \brief  supply info of vo module.
 */

#ifndef  __HI_UNF_VO_H__
#define  __HI_UNF_VO_H__

#include "hi_unf_common.h"
#include "hi_unf_disp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */



/**defines the ROTATION type.*/
/**CNcomment:\B6\A8\D2\E5\CA\D3Ƶ\D0\FDת\BDǶ\C8*/
typedef enum hiUNF_VO_ROTATION_E
{
    HI_UNF_VO_ROTATION_0, /**< 0 degree rotation*//**<CNcomment: 0\B6\C8\D0\FDת*/
    HI_UNF_VO_ROTATION_90, /**< 90 degree rotation*//**<CNcomment: 90\B6\C8\D0\FDת*/
    HI_UNF_VO_ROTATION_180, /**< 180 degree rotation*//**<CNcomment: 180\B6\C8\D0\FDת*/
    HI_UNF_VO_ROTATION_270, /**< 270 degree rotation*//**<CNcomment: 270\B6\C8\D0\FDת*/
    HI_UNF_VO_ROTATION_BUTT
}HI_UNF_VO_ROTATION_E;


/**conversion mode of AspectRatio.*/
/**CNcomment:\BF\ED\B8߱\C8ת\BB\BBģʽ*/
typedef enum hiUNF_VO_ASPECT_CVRS_E
{
    HI_UNF_VO_ASPECT_CVRS_IGNORE = 0x0,
    HI_UNF_VO_ASPECT_CVRS_LETTERBOX,      /**<Add black borders*//**<CNcomment: \BCӺڱ\DF*/
    HI_UNF_VO_ASPECT_CVRS_PAN_SCAN,      /**<Clip the picture*//**<CNcomment: \B2ü\F5*/
    HI_UNF_VO_ASPECT_CVRS_COMBINED,       /**<Add black borders and clip the picture*//**<CNcomment: \BCӺڱߺͲü\F5\BB\EC\BA\CF*/

    HI_UNF_VO_ASPECT_CVRS_HORIZONTAL_FULL,  /**<keep picture's HORIZONTAL be full*//**<CNcomment: \B1\A3\B3\D6ˮƽ\B7\BD\CF\F2\C6\CC\C2\FA*/
    HI_UNF_VO_ASPECT_CVRS_VERTICAL_FULL,    /**<keep picture's VERTICAL be full*//**<CNcomment: \B1\A3\B3ִ\B9ֱ\B7\BD\CF\F2\C6\CC\C2\FA*/
    HI_UNF_VO_ASPECT_CVRS_BUTT,
} HI_UNF_VO_ASPECT_CVRS_E;

/** AspectRatio attribute.*/
/**CNcomment:\BF\ED\B8߱\C8\CA\F4\D0\D4*/
typedef struct hiUNF_WINDOW_ASPECT_ATTR_S
{
    HI_UNF_VO_ASPECT_CVRS_E   enAspectCvrs;  /**<the method to the aspect ratio transfer.\n*//**<CNcomment: \B4\B0\BFڵĿ\ED\B8\DFת\BB\BB\B7\BDʽ */
    HI_BOOL                   bUserDefAspectRatio;  /**<use or not user define aspectratio. \n
                                                     if this is true, u32UserAspectWidth and u32UserAspectHeight will be effective.\n*/
                                                    /**<CNcomment: \CAǷ\F1ʹ\D3\C3\D3û\A7\C9趨\B5Ŀ\ED\B8߱\C8, ΪTRUEʱ\A3\ACu32UserAspectWidth\BA\CDu32UserAspectHeight\C9\FAЧ*/
    HI_U32                    u32UserAspectWidth; /**<aspect width of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                  /**<CNcomment: \D3û\A7\C6\DA\CD\FB\CF\D4ʾ\B5\C4\CA\D3Ƶ\BF\ED\B6\C8 \n
                                                   \C9\E8\D6\C3ֵ\B7\B6Χ\D4\DA0~3840֮\BC\E4 \n
                                                   0\B4\FA\B1\EDʹ\D3\C3\CA\D3ƵԴ\B7ֱ\E6\C2\CA*/
    HI_U32                    u32UserAspectHeight; /**<aspect height of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                    /**<CNcomment: \D3û\A7\C6\DA\CD\FB\CF\D4ʾ\B5\C4\CA\D3Ƶ\B8߶\C8 \n
                                                    \C9\E8\D6\C3ֵ\B7\B6Χ\D0\E8Ҫ\D4\DA0~3840\B5ķ\B6Χ\C4\DA \n
                                                    0\B4\FA\B1\EDʹ\D3\C3\CA\D3ƵԴ\B7ֱ\E6\C2\CA*/
} HI_UNF_WINDOW_ASPECT_ATTR_S;

/**define the attribution of window.*/
/**CNcomment:\B6\A8\D2\E5WINDOW\CA\F4\D0\D4*/
typedef struct hiUNF_WINDOW_ATTR_S
{
    HI_UNF_DISP_E             enDisp;          /**<the display channel where window locate in. can not be modified.\n*//**<CNcomment: \B4\B0\BF\DA\CB\F9\D4ڵ\C4\CF\D4ʾͨ\B5\C0, \B4\B4\BD\A8\BA󲻿\C9\D0޸\C4 */
    HI_BOOL                   bVirtual;      /**< whether is virtual window or not. can not be modified.\n*//**<CNcomment: \CAǷ\F1Ϊ\D0\E9\C4ⴰ\BFڣ\AC\B4\B4\BD\A8\BA󲻿\C9\D0޸\C4 */
    HI_UNF_VIDEO_FORMAT_E     enVideoFormat; /**<the data format of virtual window.\n*//**<CNcomment: \D0\E9\C4ⴰ\BF\DA\CA\FD\BEݸ\F1ʽ */
    HI_UNF_WINDOW_ASPECT_ATTR_S     stWinAspectAttr;  /**<the AspectRatio of window.\n*//**<CNcomment:  \B4\B0\BFڵĿ\ED\B8߱\C8\CA\F4\D0\D4*/
    HI_BOOL                   bUseCropRect;     /**<cut video frame as stCropRect struct or as stInputRect struct \n
                                                    if this is TRUE, stCropRect will be effective \n
                                                    if this is false, stInputRect will be effective.*/
                                                   /**<CNcomment: \CAǷ\F1ʹ\D3\C3stCropRect\B6\D4\CA\D3Ƶ\CA\E4\C8\EB\BD\F8\D0вü\F4 \n
                                                    ΪTRUEʱ\A3\ACstCropRect\C9\E8\D6\C3\C9\FAЧ \n
                                                    ΪFALSEʱ\A3\ACstInputRect\C9\E8\D6\C3\C9\FAЧ*/

    HI_UNF_CROP_RECT_S        stCropRect;   /**<clip window of user define ,clip pix num of top,buttom,left,right.\n*/
                                            /**<CNcomment: \D3û\A7\B6\A8\D2\E5\B5\C4\CA\D3Ƶ\B2ü\F4\BDṹ\CC\E5\C0\E0\D0\CD, \C9\CF\CF\C2\D7\F3\D3Ҳü\F4\B5\C4\CF\F1\CBظ\F6\CA\FD*/

    HI_RECT_S                 stInputRect;       /**<the crop area .\n
                                                  all values are zero indicate outputing whole video stream \n
                                                  if the value is bigger than video frame, the whole video frame will be displayed \n
                                                  width and height should not be less than 64.\n*/
                                                 /**<CNcomment: \B4\B0\BFڵĲü\F5\C7\F8\D3\F2  \n
                                                  \CB\F9\D3\D0ֵΪ0\B4\FA\B1\ED\CF\D4ʾ\D5\FB\B8\F6\CA\D3Ƶͼ\CF\F1 \n
                                                  \B4\F3\D3\DA\CA\D3ƵԴ\B4\F3С\B5\C4\C9\E8\D6\C3, \CF\D4ʾ\D5\FB\B8\F6\CA\D3Ƶͼ\CF\F1\A1\A3\n
                                                  \BF\ED\B6Ⱥ͸߶Ȳ\BB\C4\DCС\D3\DA64\A3\AC\BD\AB\CF\DE\D6Ƶ\BD64*64*/

    HI_RECT_S                 stOutputRect;  /**<the window display area on the virtual screen. \n
                                                The width and height of display area should not larger than virtual screen,\n
                                                and all parameters are zero means to fill whole virtual screen.\n
                                                The area could move out of virtual screen, and the outside part will not display.\n*/
                                                /**<CNcomment: \B4\B0\BF\DA\D4\DA\D0\E9\C4\E2\C6\C1Ļ\C9ϵ\C4\CF\D4ʾ\C7\F8\D3\F2\A1\A3\n
                                                \CF\D4ʾ\C7\F8\D3\F2\B5Ŀ\ED\B6\C8\D3\EB\B8߶Ȳ\BB\C4ܴ\F3\D3\DA\D0\E9\C4\E2\C6\C1Ļ\B5Ŀ\ED\B6Ⱥ͸߶ȣ\ACȫ\B2\BFΪ0\B1\EDʾ\CC\EE\C2\FA\D0\E9\C4\E2\C6\C1Ļ\A1\A3\n
                                                \CF\D4ʾ\C7\F8\D3\F2\BF\C9\D2\D4\D2Ƴ\F6\D0\E9\C4\E2\C6\C1Ļ\A3\AC\D2Ƴ\F6\C6\C1Ļ\B2\BF\B7ֲ\BB\CF\D4ʾ*/



} HI_UNF_WINDOW_ATTR_S;


/**define user buffer management attribute.*/
/**CNcomment:\B6\A8\D2\E5\D3û\A7\BB\BA\B3\E5\C7\F8\B9\DC\C0\ED\CA\F4\D0\D4*/
typedef struct hiUNF_BUFFER_ATTR_S
{
    HI_S32              s32Stride;          /**<the stride of the buffer.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\B2\BD\B3\A4*/
    HI_U32              u32PhyAddr[16];     /**<start physics addrss of the buffer.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\CE\EF\C0\ED\C6\F0ʼ\B5\D8ַ*/
    HI_U32              u32BuffIndex[16];   /**<Stride of the buffer.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\CB\F7\D2\FD\B1\E0\BA\C5*/
    HI_S32              s32BuffNum;         /**<the number of the buffer.*//**<CNcomment: \BB\BA\B3\E5\C7\F8\B8\F6\CA\FD*/
} HI_UNF_BUFFER_ATTR_S;

/** the running mode of vo*/
/**CNcomment:VO\C9豸\B5\C4\D4\CB\D0\D0ģʽ */
typedef enum hiUNF_VO_DEV_MODE_E
{
    HI_UNF_VO_DEV_MODE_NORMAL,  /**<normal mode:
                                  3716 V100/V200 :no more than 2 windows to be created.
                                  3716 v300:no more than 3 windows to be created.
                                  3712 v300:no more than 1 windows to be created.*/
                                  /**<CNcomment: \D5\FD\B3\A3ģʽ\A3\AC
                                   3716 V100/V200:ֻ\C4ܴ\B4\BD\A82\B8\F6WINDOW
                                   3716 v300: ֻ\C4ܴ\B4\BD\A83\B8\F6WINDOW
                                   3712 v300: ֻ\C4ܴ\B4\BD\A81\B8\F6WINDOW*/
    HI_UNF_VO_DEV_MODE_MOSAIC,  /**<mosaic mode: can create more than 2 windows.
                                 3712 v300: not support*/
                                /**<CNcomment: \C2\ED\C8\FC\BF\CBģʽ\A3\AC\BF\C9\D2Դ\B4\BD\A8\B6\E0\B8\F6WINDOW
                                 3712 v300: \B2\BB֧\B3\D6*/
    HI_UNF_VO_DEV_MODE_STANDALONE,  /**<seperate mode,only 1 window can be created,and  the aspect ratio set seperately.
                                        3716 v300: not support*/
                                    /**<CNcomment: standaloneģʽ\A3\AC\B8߱\EA\C7\E5\CF\D4ʾ\BF\ED\B8߱\C8ת\BB\BB\B5\A5\B6\C0\B4\A6\C0\EDģʽ
                                     3716 v300 : \B2\BB֧\B3\D6*/
    HI_UNF_VO_DEV_MODE_BUTT
} HI_UNF_VO_DEV_MODE_E;

/**define the freeze mode enumeration.*/
/**CNcomment:\B6\A8\D2\E5Freezeģʽö\BE\D9*/
typedef enum hiUNF_WINDOW_FREEZE_MODE_E
{
    HI_UNF_WINDOW_FREEZE_MODE_LAST = 0,   /**<display the last frame when freeze.*//**<CNcomment: freezeʱ\CF\D4ʾ\D7\EE\BA\F3һ֡*/
    HI_UNF_WINDOW_FREEZE_MODE_BLACK = 1,  /**<display a black frame when freeze.*//**<CNcomment: freezeʱ\CF\D4ʾ\BA\F3\BA\DA\C6\C1*/
    HI_UNF_WINDOW_FREEZE_MODE_BUTT
} HI_UNF_WINDOW_FREEZE_MODE_E;

/**<Frosted glass effect level*/
/**<CNcomment:\B6\A8\D2\E5ë\B2\A3\C1\A7Ч\B9\FBǿ\B6\C8 CNend*/
typedef enum hiUNF_WINDOW_FROST_E
{
    HI_UNF_WINDOW_FROST_CLOSE = 0x0 ,       /**<Close  */ /**<CNcomment:\B9ر\D5 CNend*/
    HI_UNF_WINDOW_FROST_LOW         ,       /**<Low    */ /**<CNcomment:\C8\F5   CNend*/
    HI_UNF_WINDOW_FROST_MIDDLE      ,       /**<Middle */ /**<CNcomment:\D6\D0   CNend*/
    HI_UNF_WINDOW_FROST_HIGH        ,       /**<High   */ /**<CNcomment:ǿ   CNend*/

    HI_UNF_WINDOW_FROST_BUTT
}HI_UNF_WINDOW_FROST_E;

typedef struct hiUNF_WIN_PLAY_INFO_S
{
    HI_U32    u32Underload;        /**< Compared with the normal play ,frame underload count  */ /**<CNcomment:\BA\CD\D5\FD\B3\A3\B2\A5\B7\C5\CF\E0\B1\C8ȱ\C9\D9֡\B5ļ\C6\CA\FD CNend*/
}HI_UNF_WIN_PLAY_INFO_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */

/**
\brief  init vo module.CNcomment:\B3\F5ʼ\BB\AFVOģ\BF\E9 CNend
\attention \n
Before call this func, you should confirm that HI_UNF_DISP_Init and HI_UNF_DISP_Open have been called yet.
call this func before any other vo funcs .
CNcomment:\D0\E8\CFȳ\F5ʼ\BB\AF\B2\A2\B4\F2\BF\AADISPLAY\BA\F3\B2\C5\C4ܵ\F7\D3øýӿڡ\A3\B5\F7\D3\C3VOģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA CNend
\param[in]   enDevMode  the vo running mode.  CNcomment:VOģ\BF\E9\B5\C4\D4\CB\D0\D0ģʽ CNend
\retval ::HI_SUCCESS successs.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_DEV_NOT_EXIST  vo device not exist. CNcomment:VO\C9豸\B2\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VO_NOT_DEV_FILE   not vo device. CNcomment:VO\B7\C7\C9豸 CNend
\retval ::HI_ERR_VO_DEV_OPEN_ERR   open vo failed. CNcomment:VO\B4\F2\BF\AAʧ\B0\DC CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal param. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

/**
\brief  deinit vo module.CNcomment:ȥ\B3\F5ʼ\BB\AFVOģ\BF\E9 CNend
\attention \n
before calling this func ,you should call HI_UNF_VO_Close to close all the windows first.
CNcomment:\D4ڵ\F7\D3\C3::HI_UNF_VO_Close\BDӿڹر\D5\CB\F9\D3д򿪵\C4VO\BA\F3\B5\F7\D3ñ\BE\BDӿ\DA CNend
\param CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_DEV_CLOSE_ERR  vo deinited failed. CNcomment:VO\B9ر\D5ʧ\B0\DC CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_DeInit(HI_VOID);

/**
\brief create the window.CNcomment:\B4\B4\BD\A8WINDOW CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] pWinAttr   a pointer typeof HI_UNF_WINDOW_ATTR_S.CNcomment:WINDO\CA\F4\D0Խṹָ\D5\EB CNend
\param[in] phWindow   the window handler to be created.CNcomment:\B4\B4\BD\A8\B5\C4WINDOW\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_CREATE_ERR     CNcomment:\B4\B4\BD\A8ʧ\B0\DC CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_CreateWindow(const HI_UNF_WINDOW_ATTR_S *pWinAttr, HI_HANDLE *phWindow);

/**
\brief create the window.CNcomment:\B4\B4\BD\A8\B2\C9\D3\C3\CE\EF\C0\ED\D7\F8\B1\EAϵ\B5\C4WINDOW CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] pWinAttr   a pointer typeof HI_UNF_WINDOW_ATTR_S.CNcomment:WINDO\CA\F4\D0Խṹָ\D5\EB CNend
\param[in] phWindow   the window handler to be created.CNcomment:\B4\B4\BD\A8\B5\C4WINDOW\BE\E4\B1\FA CNend
\param[in] bVirtScreen   flag indicates whether creating with virtscreen coordinate.CNcomment:\CAǷ\F1\B2\C9\D3\C3\D0\E9\C4\E2\D7\F8\B1\EAϵ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_CREATE_ERR     CNcomment:\B4\B4\BD\A8ʧ\B0\DC CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_CreateWindowExt(const HI_UNF_WINDOW_ATTR_S* pWinAttr,
                                  HI_HANDLE *phWindow,
                                  HI_BOOL bVirtScreen);

/**
\brief  destroy the given window.CNcomment:\CF\FA\BB\D9WINDOW CNend
\attention \n
user should disable window before call this func
CNcomment:\C7\EB\CFȵ\F7\D3ýӿ\DAdisable\B4\B0\BFڣ\AC \D4ٵ\F7\D3ô˽ӿ\DA CNend
\param[in] hWindow    the input window handler. CNcomment:WINDOW\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_DestroyWindow(HI_HANDLE hWindow);


/**
\brief to enable or disable the given window.CNcomment:ʹ\C4\DC/\BD\FBֹWINDOW CNend
\attention \n
Window can only be disabled after the corresponding avplay is stopped, else data will overflow.
CNcomment:ֻ\D3\D0\CFȽ\ABAVPLAY\B5\C4VIDͨ\B5\C0stop\BA󣬲\C5\C4ܽ\FBֹwindow\A3\AC\B7\F1\D4\F2\BD\AB\D2\FD\C6\F0\CA\FD\BEݵ\C4\D2\E7\B3\F6 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] bEnable     the flag  of enable or disable window. CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetWindowEnable(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief get the status of the given window: enable or not.CNcomment:\BB\F1ȡWINDOW\B5\C4ʹ\C4\DC״̬ CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pbEnable    the status of window:enable or disable.CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־. CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetWindowEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);

/**
\brief set the attribution of the given window.CNcomment:\C9\E8\D6\C3WINDOW\CA\F4\D0\D4 CNend
\attention \n
the two members of pWinAttr:enDisp and bVirtual are fixed when window created, and they can't be modified here.
Each value as HI_UNF_WINDOW_ATTR_S Definition
CNcomment:enDisp\BA\CDbVirtual\B2\CE\CA\FDһ\B5\A9\B4\B4\BD\A8\BA\F3\BEͲ\BB\C4\DC\D4ٽ\F8\D0\D0\D0޸ġ\A3\B2\CE\CA\FD\D0޸Ĳ\CE\D5\D5HI_UNF_WINDOW_ATTR_S\B5Ĳ\CE\CA\FD˵\C3\F7\A1\A3 CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pWinAttr   the pointer of windows attr.CNcomment:WINDO\CA\F4\D0Խṹָ\D5\EB CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetWindowAttr(HI_HANDLE hWindow, const HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the attribution of the given window.CNcomment:\BB\F1ȡWINDOW\CA\F4\D0\D4 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pWinAttr    the pointer of windows attr. CNcomment:WINDO\CA\F4\D0Խṹָ\D5\EB CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetWindowAttr(HI_HANDLE hWindow, HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the frame from given window.CNcomment:\BB\F1ȡWINDOW\B5\C4Frame\D0\C5Ϣ CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[out] pstFrameinfo  frame information. CNcomment:Frame\D0\C5Ϣ CNend
\param[in] u32TimeoutMs wait time in ms.CNcomment:\B5ȴ\FDʱ\BC䣬\BA\C1\C3\EBΪ\B5\A5λ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited.CNcomment: VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_AcquireFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo, HI_U32 u32TimeoutMs);

/**
\brief return the frame back to the given window, used for 3d graphics testing.CNcomment:\CAͷ\C5\D3û\A7\BB\F1ȡWINDOW\B5\C4Frame\A3\ACר\C3\C5\D3\C3\D3\DA3Dͼ\D0β\E2\CA\D4 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_ReleaseFrame(HI_HANDLE hWindow,HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);

/**
\brief set the zorder of the given window.CNcomment:\C9\E8\D6\C3WINDOW\B5\C4Z\D0\F2 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] enZFlag    how to adjust zorder. CNcomment:Z\D0\F2\B5\F7\BDڷ\BDʽ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetWindowZorder(HI_HANDLE hWindow, HI_LAYER_ZORDER_E enZFlag);

/**
\brief get the zorder of the given window.CNcomment:\BB\F1ȡWINDOW\B5\C4Z\D0\F2 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow       the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pu32Zorder    value of zoder, bigger value means higher prioty. CNcomment:Z\D0\F2\CA\FDֵ\A3\AC\CA\FDֵԽ\B4\F3\D3\C5\CFȼ\B6Խ\B8\DF CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetWindowZorder(HI_HANDLE hWindow, HI_U32 *pu32Zorder);

/**
\brief attach the window with video source such as vi/avplay.CNcomment:\B0\D1WINDOW\D3\EBָ\B6\A8\B5\C4AVPLAY/VI\B0\F3\B6\A8 CNend
\attention \n
it can attach the handler of avplay or vi to the window.
CNcomment:\BF\C9\D2Խ\ABAVPLAY\BB\F2VI\B5ľ\E4\B1\FA\B0󶨵\BDWINDOW\C9ϡ\A3 CNend
\param[in] hWindow     the input window handler. CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] hSrc        the handler of video source. CNcomment:\CA\FD\BE\DDԴ\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_AttachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);


/**
\brief detach the window from the video source such as avplay or vi.CNcomment:\B0\D1WINDOW\D3\EBָ\B6\A8\B5\C4AVPLAY/VI\BD\E2\B0\F3\B6\A8 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] hSrc        the handler of video source.CNcomment:\CA\FD\BE\DDԴ\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: \CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_DetachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief Set frost glass effect level at one window .CNcomment:\D4ڴ\B0\BF\DA\D6\D0\C9\E8\D6\C3ë\B2\A3\C1\A7Ч\B9\FB\B5ĵȼ\B6 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow         the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] enWinFrostMode  Frost glass level.CNcomment:Ч\B9\FBǿ\B6ȵȼ\B6 CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetFrostGlassLevel(HI_HANDLE hWindow, HI_UNF_WINDOW_FROST_E enWinFrostMode);

/**
\brief Get frost glass effect level at one window .CNcomment:\BB\F1ȡ\B4\B0\BF\DA\D6\D0\C9\E8\D6\C3ë\B2\A3\C1\A7Ч\B9\FB\B5ĵȼ\B6 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] *penWinFrostMode  Frost glass level.CNcomment:Ч\B9\FBǿ\B6ȵȼ\B6 CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetFrostGlassLevel(HI_HANDLE hWindow, HI_UNF_WINDOW_FROST_E* penWinFrostMode);

/**
\brief  to freeze the video content of given window.CNcomment:\B6\B3\BD\E1WINDOW\B5\C4\CF\D4ʾ\C4\DA\C8\DD CNend
\attention \n
the display will be freezed after calling this func, but backgrounddly,the data flow is normal from video decoder.
so when freezing is cacelled, the newest video content can be display at once.
CNcomment:\B4˹\A6\C4\DC\D3\C3\D3\DA\D4ڲ\A5\B7Ź\FD\B3\CC\D6ж\B3\BD\E1\C6\C1Ļ\CF\D4ʾ\C4\DA\C8ݣ\AC\B4\CBʱWINDOW\D6е\C4\CA\FD\BE\DD\C1\F7\BC\CC\D0\F8\D4\CB\D0У\AC\n
\D2\F2\B4\CBȡ\CF\FB\B6\B3\BD\E1\BA󣬻\E1\C1\A2\BF\CC\CF\D4ʾ\D7\EE\D0µ\C4\C4\DA\C8ݡ\A3 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] bEnable           shows whether to freeze window.CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\param[in] enWinFreezeMode   the mode of freeze.CNcomment:\B6\B3\BD\E1\B5ķ\BDʽ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: \CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_FreezeWindow(HI_HANDLE hWindow, HI_BOOL bEnable, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief  to get the freeze status of the given window.CNcomment:\BB\F1ȡ\B4\B0\BFڵĶ\B3\BD\E1״̬ CNend
\attention \n
\param[in] hWindow            the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[out] pbEnable           shows whether to freeze window.CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\param[out] penWinFreezeMode   the mode of freeze.CNcomment:\B6\B3\BD\E1\B5ķ\BDʽ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: \CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetWindowFreezeStatus(HI_HANDLE hWindow, HI_BOOL *pbEnable, HI_UNF_WINDOW_FREEZE_MODE_E *penWinFreezeMode);


/**
\brief reset the window.CNcomment:\B8\B4λWINDOW CNend
\attention \n
this function can reset buffers of the given window, and black frame or the last frame will be displayed according configuration.
CNcomment:\B4˹\A6\C4\DC\C7\E5\BF\D5window\D6еĻ\BA\B3壬\B8\F9\BEݲ\CE\CA\FD\CF\D4ʾ\BA\DA֡\BB\F2\D7\EE\BA\F3һ֡\A1\A3 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] enWinFreezeMode   method of freeze the window.CNcomment:\B8\B4λ\B5ķ\BDʽ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_ResetWindow(HI_HANDLE hWindow, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief pass the external allocated buffer to this function to test 3d graphics.CNcomment:\CF\F2WINDOW\B4\AB\B5\DD\D3û\A7\CDⲿ\B7\D6\C5\E4\B5\C4buffer\A3\ACר\C3\C5\D3\C3\D3\DA3Dͼ\D0β\E2\CA\D4 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pstBufAttr  external buffer.CNcomment:\CDⲿ\B5\C4buffer CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_AttachExternBuffer(HI_HANDLE hWindow,HI_UNF_BUFFER_ATTR_S* pstBufAttr);

/**
\brief to set the work mode of window: quick output or not. Deinterlace alg will be disabled when quick output is enabled.
CNcomment:\C9\E8\D6\C3WINDOW\CAǷ\F1\B9\A4\D7\F7\D4ڿ\EC\CB\D9\CA\E4\B3\F6ģʽ\A3\AC\BF\EC\CB\D9\CA\E4\B3\F6ģʽǿ\D6ƹر\D5ȥ\B8\F4\D0\D0\CB㷨 CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] bQuickOutputEnable  whether determine the output mode of window. CNcomment:\BF\EC\CB\D9\CA\E4\B3\F6ģʽʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetQuickOutputEnable(HI_HANDLE hWindow, HI_BOOL bQuickOutputEnable);

/**
\brief to get the work mode of window: quick output or not.
CNcomment:\BB\F1ȡWINDOW\CAǷ\F1\B9\A4\D7\F7\D4ڿ\EC\CB\D9\CA\E4\B3\F6ģʽ CNend
\attention \n
CNcomment:\CE\DE CNend
\param[in]  hWindow     the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[out] pbQuickOutputEnable  whether determine the output mode of window. CNcomment:\BF\EC\CB\D9\CA\E4\B3\F6ģʽʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetQuickOutputStatus(HI_HANDLE hWindow, HI_BOOL *pbQuickOutputEnable);

/**
\brief  to set the filed mode of given window.CNcomment:\C9\E8\D6ô\B0\BFڵĳ\A1\B2\A5\B7\C5ģʽ CNend
\attention \n
when fast-backward playing, there will be no abnormity through calling this func. But calling of this
func is forbidden when normal playing. It should be called after HI_UNF_VO_AttachWindow.
CNcomment:ͨ\B9\FD\C9\E8\D6ô˽ӿ\DAʹ\C4ܣ\AC\B1\A3֤\BF\EC\CD˲\BB\BB\E1\B3\F6\CFֳ\A1ͼ\CF\F1\BB\D8\CD˵\C4\CF\D6\CF\F3\A3\AC\D4\DA\D5\FD\B3\A3\B2\A5\B7\C5ʱ\A3\AC\n
\C7\EB\C9\E8\D6\C3Ϊ\BD\FBֹ\A3\ACĬ\C8\CFΪ\BD\FBֹ\A1\A3HI_UNF_VO_AttachWindow\B5\F7\D3\C3֮\BA\F3ʹ\D3\C3\D3\D0Ч\A1\A3 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] bEnable           wether to enable field play.CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VO_WIN_UNSUPPORT  unsupported operation.CNcomment:\B2\D9\D7\F7\B2\BB֧\B3\D6 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetWindowFieldMode(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief  to get the filed mode of given window.CNcomment:\BB\F1ȡ\B4\B0\BFڵĳ\A1\B2\A5\B7\C5ģʽ CNend
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[out] pbEnable         wether to enable field play.CNcomment:ʹ\C4\DC/\BD\FBֹ\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\retval ::HI_ERR_VO_WIN_UNSUPPORT  unsupported operation.CNcomment:\B2\D9\D7\F7\B2\BB֧\B3\D6 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetWindowFieldMode(HI_HANDLE hWindow, HI_BOOL *pbEnable);


/**
\brief capture the current frame of given window.CNcomment:\B2\B6\BB\F1WINDOW\B5ĵ\B1ǰ֡ CNend
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: \B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_CapturePicture(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);


/**
\brief if you capture picture is finished, release the memory.CNcomment:\B2\B6\BB\F1\CD\EA\B1ϣ\AC\CAͷŲ\B6\BB\F1\B5\C4\C4ڴ\E6\C7\F8\D3\F2 CNend
\attention \n
this function will release captured picture, so user should call this function
after you used this captured picture.
CNcomment:\D3\C9\D3ڸú\AF\CA\FD\BB\E1\CAͷű\BB\B2\B6\BB\F1\B5\C4һ֡\A3\AC\CB\F9\D2\D4\D3û\A7\D0\E8Ҫ\D4\DA\D3\C3\CD겶\BB\F1֮֡\BA\F3\D4ٵ\F7\D3ô˽ӿ\DA CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW\BE\E4\B1\FA CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: \B2\D9\D7\F7\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:\B4\B0\BFڲ\BB\B4\E6\D4\DA CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_CapturePictureRelease(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);

/**
\brief set window rotion type.CNcomment:\C9\E8\D6ô\B0\BFڵ\C4\D0\FDת\C0\E0\D0\CD CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712\B2\BB֧\B3\D6 CNend
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] enRotation    rotion type.CNcomment:\D0\FDת\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS openned success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E enRotation);


/**
\brief get window rotion type.CNcomment:\BB\F1ȡ\B4\B0\BFڵ\C4\D0\FDת\BE\E4\B1\FA CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712\B2\BB֧\B3\D6 CNend
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] enRotation    rotion type.CNcomment:\D0\FDת\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS openned success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E *penRotation);

/**
\brief flip window.CNcomment:\B7\ADתwindow CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712\B2\BB֧\B3\D6 CNend
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] bHoriFlip    horizon flip.CNcomment:ˮƽ\B7\ADת CNend
\param[in] bVertFlip    vertical flip.CNcomment:\B4\B9ֱ\B7\ADת CNend
\retval ::HI_SUCCESS openned success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_SetFlip(HI_HANDLE hWindow, HI_BOOL bHoriFlip, HI_BOOL bVertFlip);

/**
\brief get fliping tpye of window.CNcomment:\BB\F1\B5ô\B0\BFڵķ\ADת\C0\E0\D0\CD CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712\B2\BB֧\B3\D6 CNend
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] bHoriFlip    horizon flip flag.CNcomment:ˮƽ\B7\ADת\B1\EA־ CNend
\param[in] bVertFlip    vertical flip flag.CNcomment:\B4\B9ֱ\B7\ADת\B1\EA־ CNend
\retval ::HI_SUCCESS openned success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\see \n
CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_VO_GetFlip(HI_HANDLE hWindow, HI_BOOL *pbHoriFlip, HI_BOOL *pbVertFlip);

/**
\brief set video stereo depth for 3D output.CNcomment:\C9\E8\D6\C33D\CA\E4\B3\F6\CA\D3Ƶ\BE\B0\C9\EE CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712\B2\BB֧\B3\D6 .\BD\F6\D4\DA3D\CA\E4\B3\F6ʱ\D3\D0Ч CNend
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] s32Depth Depth of filed. the range is [-50,50].CNcomment:\BE\B0\C9ȡֵΪ[-50,50]. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_SetStereoDetpth(HI_HANDLE hWindow, HI_S32 s32Depth);

/**
\brief get video stereo depth for 3D output.CNcomment: \BB\F1ȡ3D\CA\E4\B3\F6\CA\D3Ƶ\BE\B0\C9\EE CNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[out] ps32Depth Depth of filed. the range is [-50,50].CNcomment:\BE\B0\C9ȡֵΪ[-50,50]. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_GetStereoDetpth(HI_HANDLE hWindow, HI_S32 *ps32Depth);

/**
\brief Queue frame into the specified window.CNcomment: \CF\F2\CCض\A8\B4\B0\BF\DA\D6\D0\CD\C6֡\A3\AC\D3\C3\D3\DA\CF\D4ʾ\A1\A3 CNend
\attention \n
\param[in] hWindow    window handle. CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] pstFrameinfo  frame infor to be passed into. CNcomment:Ҫ\B4\AB\C8\EB\B5\C4֡\D0\C5Ϣ. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR   null input ptr.CNcomment:\BF\D5ָ\D5\EB CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\retval ::HI_ERR_VO_BUFQUE_FULL   buffer is full .CNcomment:buffer \B4\A6\D3\DA\C2\FA\B5\C4״̬ CNend
\retval ::HI_ERR_VO_INVALID_OPT   invalid opt.CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_QueueFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);

/**
\brief dequeue frame from window.CNcomment: \BB\D8\CA\D5\CDƵ\BD\B4\B0\BFڵ\C4֡CNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[out] pstFrameinfo  frame infor dequeued from window .CNcomment:\B4Ӵ\B0\BF\DA\D6л\F1ȡ\B5\C4֡\D0\C5Ϣ. CNend
\param[in] u32TimeoutMs  timeout when get frame failed .CNcomment:\B3\ACʱֵ\A3\AC\D3\C3\D3ڻ\F1ȡ֡ʧ\B0\DCʱ\B5ĳ\ACʱ\CD˳\F6. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_NULL_PTR   null input ptr.CNcomment:\BF\D5ָ\D5\EB CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_DeQueueFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo, HI_U32 u32TimeoutMs);

/**
\brief set  window alpha.CNcomment: \C9\E8\D6ô\B0\BFڵ\C4alphaֵCNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] u32Alpha  window alpha .CNcomment:\B4\B0\BFڵ\C4alphaֵ. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_SetWindowAlpha(HI_HANDLE hWindow, HI_U32 u32Alpha);
/**
\brief get  window alpha.CNcomment: \BB\F1ȡ\B4\B0\BFڵ\C4alphaֵCNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] pu32Alpha  window alpha .CNcomment:\B4\B0\BFڵ\C4alphaֵ. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_GetWindowAlpha(HI_HANDLE hWindow, HI_U32 *pu32Alpha);


/**
\brief get  window play information.CNcomment: \BB\F1ȡ\B4\B0\BFڲ\A5\B7\C5\D0\C5ϢCNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] pstPlayInfo  window play information .CNcomment:\B4\B0\BFڵĲ\A5\B7\C5\D0\C5Ϣ. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\see \n
none.CNcomment:\CE\DE CNend
 */

HI_S32 HI_UNF_VO_GetWindowPlayInfo(HI_HANDLE hWindow, HI_UNF_WIN_PLAY_INFO_S *pstPlayInfo);


/**
\brief get  window frame delay time.CNcomment: \BB\F1ȡ\B4\B0\BF\DA֡\CF\D4ʾ\B5ȴ\FDʱ\BC\E4CNend
\attention \n
\param[in] hWindow    window handle .CNcomment:\B4\B0\BFھ\E4\B1\FA CNend
\param[in] pu32DelayMs  window frame delay time.CNcomment:֡\CF\D4ʾ\B5ȴ\FDʱ\BC\E4. CNend
\retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_VO_FRAME_INFO_ERROR   invalid frame infor.CNcomment:\CE\DEЧ֡\D0\C5Ϣ CNend
\see \n
none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_VO_GetDelayMs(const HI_HANDLE hWindow, HI_U32 *pu32DelayMs);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
/************************************** The End Of File **************************************/
