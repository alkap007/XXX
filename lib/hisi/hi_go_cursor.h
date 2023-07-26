#ifndef _HI_GO_CURSOR_H
#define _HI_GO_CURSOR_H

#include "hi_go_comm.h"
#include "hi_go_gdev.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_CURSOR */
/** @{ */  /** <!-- [HIGO_CURSOR] */

typedef struct
{
    HI_HANDLE hCursor;    /**<The maximum resolution is 128x128, and the minimum resolution is 16x16 for the cursor picture. Both pixel alpha and colorkey are supported.*/
    				      /**<CNcomment: \B9\E2\B1\EAͼƬ\D7\EE\B4\F3128*128,\D7\EEС16*16\CF\F1\CB\D8, ֧\B3\D6\CF\F1\CB\D8alpha\BA\CDcolorkey */
    HI_U32    HotspotX;   /**<Horizontal coordinate of the cursor hot spot relative to the cursor picture*//**<CNcomment: \B9\E2\B1\EA\C8ȵ\E3X\D7\F8\B1꣬\CF\E0\B6\D4\D3\DAͼƬ */
    HI_U32    HotspotY;   /**<Vertical coordinate of the cursor+ hot spot relative to the cursor picture*//**<CNcomment: \B9\E2\B1\EA\C8ȵ\E3Y\D7\F8\B1꣬\CF\E0\B6\D4\D3\DAͼƬ */
} HIGO_CURSOR_INFO_S;

/**Status of the cursor layer*//** CNcomment: \B9\E2\B1\EA\B2\E3״̬\BDṹ */
typedef struct
{
    HI_BOOL bShow;             /**<Whether to display the cursor layer.*//**<CNcomment: \B9\E2\B1\EA\B2\E3\CAǷ\F1\CF\D4ʾ */
} HIGO_CURSOR_STATUS_S;
/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_CURSOR */
/** @{ */  /** <!-- [HIGO_CURSOR] */

/**
\brief Initializes the cursor module.CNcomment:\B9\E2\B1\EA\B3\F5ʼ\BB\AF CNend
\attention \n

\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment: \CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_INITFAILED
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
::HI_GO_DeinitCursor
*/

HI_S32 HI_GO_InitCursor();

/**
\brief Deinitializes the cursor module.CNcomment:ȥ\B3\F5ʼ\BB\AF\B9\E2\B1\EA\B3\F5ʼ\BB\AF CNend
\attention \n

\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT

\see \n
::HI_GO_InitCursor
*/

HI_S32 HI_GO_DeinitCursor();

/**
\brief  Displays the cursor layer.CNcomment:\CF\D4ʾ\B9\E2\B1\EA CNend
\attention \n
1. The cursor of the output layer is located in the middle of the screen by default.CNcomment:1 \CA\E4\B3\F6\B2\E3\B5Ĺ\E2\B1\EAλ\D6\C3Ĭ\C8\CF\D4\DA\C6\C1Ļ\D6м\E4 CNend
2. You need set the cursor information before the cursor layer is displayed.CNcomment:2.show\B9\E2\B1\EA\B5\C4ʱ\BA\F2\A3\AC\D0\E8Ҫ\CA\D7\CF\C8\C9\E8\D6ù\E2\B1\EA\B5\C4\D0\C5Ϣ\A1\A3CNend
\param[in] bVisible Visible status of the cursor layer. HI_TRUE: visible; HI_FASLE: invisible.CNcomment:\B9\E2\B1\EA\B2\E3\BFɼ\FB״̬\A3\AC HI_TRUE:\BFɼ\FB\A3\AC HI_FASLE:\B9\E2\B1\EA\B2㲻\BFɼ\FB\A1\A3CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NOCURSORINF
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
::HI_GO_GetCursorStatus
::HI_GO_SetCursorInfo
*/
HI_S32 HI_GO_ShowCursor(HI_BOOL bVisible);

/**
\brief Obtains the current status of the cursor layer.CNcomment:\BB\F1ȡ\B9\E2\B1\EA\B2㵱ǰ״̬ CNend
\attention \n
N/A.CNcomment:\CE\DE CNend

\param[out] pCursorStatus Pointer to the current status of the cursor layer. The value cannot be empty.CNcomment:\B9\E2\B1\EA\B2㵱ǰ״̬\BDṹָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
::HI_GO_ShowLayer
*/
HI_S32 HI_GO_GetCursorStatus( HIGO_CURSOR_STATUS_S* pCursorStatus);

/**
\brief Moves the cursor to a specified position on a specified screen.CNcomment:\D2ƶ\AF\B9\E2\B1굽ָ\B6\A8\C6\C1Ļָ\B6\A8λ\D6\C3 CNend
\attention \n
The cursor position can be changed only when the cursor status is show.CNcomment:\B1\D8\D0\EB\D4\DAcursorΪshow\B5\C4\C7\E9\BF\F6\CF²\C5\C4ܸı\E4\B9\E2\B1\EAλ\D6\C3 CNend

\param[in] x Horizontal coordinate (in pixel) of the cursor on the screen relative to the canvas surface of a
graphics layer.CNcomment: \C6\C1ĻX\D7\F8\B1\EA,\B5\A5λ\CF\F1\CB\D8, \CF\E0\B6\D4\D3\DAͼ\B2\E3canvas surface CNend
\param[in] y Vertical coordinate (in pixel) of the cursor on the screen relative to the canvas surface of a graphics
layer.CNcomment:\C6\C1ĻY\D7\F8\B1\EA,\B5\A5λ\CF\F1\CB\D8, \CF\E0\B6\D4\D3\DAͼ\B2\E3canvas surface CNend

\retval ::HIGO_ERR_NOTINIT
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32 HI_GO_SetCursorPos(HI_S32 x, HI_S32 y);

/**
\brief Obtains the coordinates of the cursor on the screen.CNcomment:ȡ\B5ù\E2\B1\EA\B5\C4\C6\C1Ļ\D7\F8\B1\EA CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[out] pX Horizontal coordinate (in pixel) of the cursor on the screen.CNcomment:\B9\E2\B1\EA\B5\C4\C6\C1ĻX\D7\F8\B1\EA,\B5\A5λ\CF\F1\CB\D8 CNend
\param[out] pY Vertical coordinate (in pixel) of the cursor on the screen.CNcomment:\B9\E2\B1\EA\B5\C4\C6\C1ĻY\D7\F8\B1\EA,\B5\A5λ\CF\F1\CB\D8 CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32 HI_GO_GetCursorPos(HI_S32* pX, HI_S32* pY);

/**
\brief Sets the hot spot of the displayed cursor picture.CNcomment:\C9\E8\D6ù\E2\B1\EA\B5\C4\CF\D4ʾͼƬ\B5\C4\C8ȵ\E3 CNend
\attention \n
The minimum resolution is 16x16, and the maximum resolution is 128x128 for the cursor picture. Both colorkey and
alpha are supported. CNcomment:ͼƬ\D7\EEС16x16,\D7\EE\B4\F3128x128\CF\F1\CBأ\AC֧\B3\D6colorkey, alpha\A1\A3 CNend
\param[in] pCursorInfo Information about the cursor picture and coordinates of the hot spot.CNcomment:\B9\E2\B1\EAͼƬ\A3\AC\C8ȵ\E3\D7\F8\B1\EA\D0\C5Ϣ CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVSURFACESIZE
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INVHOTSPOT
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32 HI_GO_SetCursorInfo(const HIGO_CURSOR_INFO_S* pCursorInfo);

/**
\brief Obtains the information about the displayed cursor picture.CNcomment:\BB\F1ȡ\B9\E2\B1\EA\B5\C4\CF\D4ʾͼƬ\D0\C5Ϣ CNend
\attention \n
\param[in] pCursorInfo Information about the cursor picture and coordinates of the hot spot.CNcomment:\B9\E2\B1\EAͼƬ\A3\AC\C8ȵ\E3\D7\F8\B1\EA\D0\C5Ϣ CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32 HI_GO_GetCursorInfo(HIGO_CURSOR_INFO_S* pCursorInfo);

/**
\brief Attaches the cursor to one or more graphics layers.CNcomment:\BD\AB\B9\E2\B1\EA\B0󶨵\BDͼ\B2\E3\C9ϣ\AC֧\B3\D6һ\B8\F6\B9\E2\B1\EA\B0󶨵\BD\B6\E0\B8\F6ͼ\B2\E3\C9\CF CNend
\attention \n
The graphics layers to which the cursor is attached must be opened.CNcomment:\B1\D8\D0뽫\B9\E2\B1\EA\B0󶨵\BDһ\B8\F6\D2Ѿ\ADopen\B5\C4ͼ\B2\E3\C9ϡ\A3CNend
\param[in] hLayer CNcomment:ͼ\B2\E3ID CNend

\retval ::HI_SUCCESS Layer ID.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Success.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVLAYERID
\retval ::HIGO_ERR_NOTOPEN
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32  HI_GO_AttchCursorToLayer(HI_HANDLE hLayer);

/**
\brief Detaches the cursor from graphics layers.CNcomment:\BD\AB\B9\E2\B1\EA\BD\E2\B0\F3\B6\A8ͼ\B2\E3 CNend
\attention \n
\param[in] hLayer Layer ID.CNcomment:ͼ\B2\E3ID CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE The display fails.CNcomment:\CF\D4ʾʧ\B0\DC CNend
\retval ::HIGO_ERR_INVLAYERID
\retval ::HIGO_ERR_DEPEND_CURSOR

\see \n
*/
HI_S32  HI_GO_DetachCursorFromLayer(HI_HANDLE hLayer);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif
