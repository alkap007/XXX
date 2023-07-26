#ifndef __HI_UNF_SUBT_H__
#define __HI_UNF_SUBT_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus*/

/*************************** Structure Definition ****************************/
/** \addtogroup      SUBTITLE */
/** @{ */  /** <!-- \A1\BESUBTITLE\A1\BF */

/** Invalid handle in subtitle *//** CNcomment:\CE\DEЧ\B5\C4\D7\D6Ļ\BE\E4\B1\FA */
#define SUBT_INVALID_HANDLE   (0x0)
/** the max item(language) in Subtitling descriptor *//** CNcomment:\D7\EE\B4\F3\B5\C4\D7\D6Ļ\CF\EE(\D3\EF\D1\D4)\B8\F6\CA\FD */
#define SUBT_ITEM_MAX_NUM     (32)
/** the max subtitle instance *//** CNcomment:\D7\EE\B4\F3\B5\C4\D7\D6Ļģ\BF\E9ʵ\C0\FD */
#define SUBT_INSTANCE_MAX_NUM (8)

/** Defines the subtitle data type  *//** CNcomment: \B6\A8\D2\E5\D7\D6Ļ\CA\FD\BE\DD\C0\E0\D0\CD */
typedef enum hiUNF_SUBT_DATA_TYPE_E
{
    HI_UNF_SUBT_DVB  = 0x1, /**<DVB subtitle *//**<CNcomment: DVB\D7\D6Ļ */
    HI_UNF_SUBT_SCTE = 0x2, /**<SCTE subtitle *//**<CNcomment: SCTE\D7\D6Ļ */
    HI_UNF_SUBT_BUTT
}HI_UNF_SUBT_DATA_TYPE_E;

/** Defines the type used to code the subtitle *//** CNcomment:\B6\A8\D2\E5\D7\D6Ļ\B1\E0\C2\EB\C0\E0\D0\CDö\BE\D9 */
typedef enum hiUNF_SUBT_TYPE_E
{
    HI_UNF_SUBT_TYPE_BITMAP = 0, /**<Coding of bitmap *//**<CNcomment:λͼ\B1\E0\C2\EB */
    HI_UNF_SUBT_TYPE_TEXT,       /**<Coded as a string of characters *//**<CNcomment:\CEı\BE\B1\E0\C2\EB */
    HI_UNF_SUBT_TYPE_BUTT
}HI_UNF_SUBT_TYPE_E;

/** Defines the status of the subtitling page *//** CNcomment:\B6\A8\D2\E5\D7\D6Ļҳ״̬ö\BE\D9 */
typedef enum hiUNF_SUBT_PAGE_STATE_E
{
    HI_UNF_SUBT_PAGE_NORMAL_CASE        = 0,    /**<Page update, use previous page instance to display *//**<CNcomment:\BEֲ\BF\B8\FC\D0\C2 */
    HI_UNF_SUBT_PAGE_ACQUISITION_POINT,         /**<Page refresh, use next page instance to display *//**<CNcomment:ȫ\C6\C1ˢ\D0\C2 */
    HI_UNF_SUBT_PAGE_MODE_CHANGE,               /**<New page, needed to display the new page *//**<CNcomment:ˢ\D0\C2\D5\FB\B8\F6\D7\D6Ļҳ */
    HI_UNF_SUBT_PAGE_BUTT
}HI_UNF_SUBT_PAGE_STATE_E;

/** Defines the data of the subtitle output *//** CNcomment:\B6\A8\D2\E5\D7\D6Ļ\CA\E4\B3\F6\CA\FD\BEݽṹ\CC\E5 */
typedef struct hiUNF_SUBT_DATA_S
{
    HI_UNF_SUBT_TYPE_E enDataType;        /**<The type used to code the subtitle *//**<CNcomment:\D7\D6Ļ\B1\E0\C2\EB\C0\E0\D0\CD */
    HI_UNF_SUBT_PAGE_STATE_E enPageState; /**<The status of the subtitling page *//**<CNcomment:\D7\D6Ļҳ״̬ */
    HI_U32             u32x;              /**<The horizontal address of subtitling page *//**<CNcomment:x\D7\F8\B1\EA */
    HI_U32             u32y;              /**<The vertical address of subtitling page *//**<CNcomment:y\D7\F8\B1\EA */
    HI_U32             u32w;              /**<The horizontal length of subtitling page *//**<CNcomment:\BF\ED\B6\C8 */
    HI_U32             u32h;              /**<The vertical length of subtitling page *//**<CNcomment:\B8߶\C8 */
    HI_U32             u32BitWidth;       /**<Bits in pixel-code *//**<CNcomment:λ\BF\ED */
    HI_U32             u32PTS;            /**<Presentation time stamp *//**<CNcomment:ʱ\BC\E4\B4\C1 */
    HI_U32             u32Duration;       /**<The period, expressed in ms, after which a page instance is no longer valid *//**<CNcomment:\B3\D6\D0\F8ʱ\BC䣬\B5\A5λ\CA\C7ms */
    HI_U32             u32PaletteItem;    /**<Pixels of palette *//**<CNcomment:\B5\F7ɫ\B0峤\B6\C8 */
    HI_VOID*           pvPalette;         /**<Palette data *//**<CNcomment:\B5\F7ɫ\B0\E5\CA\FD\BE\DD */
    HI_U32             u32DataLen;        /**<Subtitling page data length *//**<CNcomment:\D7\D6Ļ\CA\FD\BEݳ\A4\B6\C8 */
    HI_U8*             pu8SubtData;       /**<Subtitling page data *//**<CNcomment:\D7\D6Ļ\CA\FD\BE\DD */
    HI_U32             u32DisplayWidth;   /**<Display canvas width *//**<CNcomment:\CF\D4ʾ\BB\AD\B2\BC\B5Ŀ\ED\B6\C8 */
    HI_U32             u32DisplayHeight;  /**<Display canvas height *//**<CNcomment:\CF\D4ʾ\BB\AD\B2\BC\B5ĸ߶\C8 */
}HI_UNF_SUBT_DATA_S;

/** Defines the item of the subtitling content *//** CNcomment:\B6\A8\D2\E5\D7\D6Ļ\B7\FE\CE\F1\CF\EE\BDṹ\CC\E5 */
typedef struct hiUNF_SUBT_ITEM_S
{
    HI_U32 u32SubtPID;      /**<The pid for playing subtitle *//**<CNcomment:\D7\D6Ļpid */
    HI_U16 u16PageID;       /**<The Subtitle page id *//**<CNcomment:\D7\D6Ļҳid */
    HI_U16 u16AncillaryID;  /**<The Subtitle ancillary id *//**<CNcomment:\D7\D6Ļ\B8\A8\D6\FAҳid */
}HI_UNF_SUBT_ITEM_S;

/** Defines the callback function which output the subtitling data *//** CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6\D7\D6Ļ\CA\FD\BEݵĻص\F7\BA\AF\CA\FD */
typedef HI_S32 (*HI_UNF_SUBT_CALLBACK_FN)(HI_VOID* pUserData, HI_UNF_SUBT_DATA_S *pstData);

/** Defines the callback function which get current pts *//** CNcomment:\B6\A8\D2\E5\BB\F1ȡ\B5\B1ǰʱ\BC\E4\B4\C1\B5Ļص\F7\BA\AF\CA\FD */
typedef HI_S32 (*HI_UNF_SUBT_GETPTS_FN)(HI_VOID* pUserData, HI_S64 *ps64Pts);

/** Defines the parameter of subtitle instance *//** CNcomment:\B6\A8\D2\E5\D7\D6Ļģ\BF\E9\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiUNF_SUBT_PARAM_S
{
    HI_UNF_SUBT_ITEM_S astItems[SUBT_ITEM_MAX_NUM]; /**<The item of the subtitling content *//**<CNcomment:\D7\D6Ļ\C4\DA\C8\DD */
    HI_U8  u8SubtItemNum;                           /**<Amount of subtitling item *//**<CNcomment:\D7\D6Ļ\C4\DA\C8ݸ\F6\CA\FD */
    HI_UNF_SUBT_CALLBACK_FN pfnCallback;            /**<Callback function in which output subtitling page data *//**<CNcomment:\BBص\F7\BA\AF\CA\FD\A3\AC\D3\C3\C0\B4\CA\E4\B3\F6\BD\E2\C2\EB\BA\F3\B5\C4\D7\D6Ļ\CA\FD\BE\DD */
    HI_VOID* pUserData;                             /**<User data used in callback function *//**<CNcomment:\D3û\A7\CA\FD\BEݣ\ACֻ\D3\C3\D4ڻص\F7\BA\AF\CA\FD\C0\EF\C3\E6 */
    HI_UNF_SUBT_DATA_TYPE_E enDataType;             /**<subtitle data type in subt module *//**<CNcomment:\D4\DAsubtģ\BF\E9\D6\D0\D3õ\C4\D7\D6Ļ\CA\FD\BE\DD\C0\E0\D0\CD */
}HI_UNF_SUBT_PARAM_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      SUBTITLE */
/** @{*/  /** <!-- [SUBTITLE] */

/**
\brief Initialize subtitle module. CNcomment:\B3\F5ʼ\BB\AF\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS initialize success. CNcomment:\B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE initialize failure. CNcomment:\B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_Init(HI_VOID);

/**
\brief DeInitialize subtitle module. CNcomment:ȥ\B3\F5ʼ\BB\AF\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS deinitialize success. CNcomment:ȥ\B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE deinitialize failure. CNcomment:ȥ\B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
 HI_S32 HI_UNF_SUBT_DeInit(HI_VOID);

/**
\brief Create subtitle module. CNcomment:\B4\B4\BD\A8\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  pstSubtParam  parameters used in created subtitle. CNcomment:\B2\CE\CA\FDֵ\A1\A3CNend
\param[out] phSubt        subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS create success. CNcomment:\B4\B4\BD\A8\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE create failure. CNcomment:\B4\B4\BD\A8ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_Create(HI_UNF_SUBT_PARAM_S *pstSubtParam, HI_HANDLE *phSubt);

/**
\brief Destroy subtitle module. CNcomment:\CF\FA\BB\D9\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS destroy success. CNcomment:\CF\FA\BBٳɹ\A6\A1\A3CNend
\retval ::HI_FAILURE destroy failure. CNcomment:\CF\FA\BB\D9ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_Destroy(HI_HANDLE hSubt);

/**
\brief Select one subtitle content to output. CNcomment:\C7л\BB\D7\D6Ļ\C4\DA\C8ݡ\A3CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\param[in]  pstSubtItem   subtitle item. CNcomment:\D7\D6Ļ\C4\DA\C8\DD\CFCNend
\retval ::HI_SUCCESS switching success. CNcomment:\C7л\BB\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE switching failure. CNcomment:\C7л\BBʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_SwitchContent(HI_HANDLE hSubt, HI_UNF_SUBT_ITEM_S *pstSubtItem);

/**
\brief Reset subtitle module. CNcomment:\B8\B4λ\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS reset success. CNcomment:\B8\B4λ\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE reset failure. CNcomment:\B8\B4λʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_Reset(HI_HANDLE hSubt);

/**
\brief Update subtitle module. CNcomment:\B8\FC\D0\C2\D7\D6Ļģ\BF顣CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\param[in]  pstSubtParam  the new subtitle content. CNcomment:\D0µ\C4\D7\D6Ļ\C4\DA\C8\DD\D0\C5Ϣ\A1\A3CNend
\retval ::HI_SUCCESS update success. CNcomment:\B8\FC\D0³ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE update failure. CNcomment:\B8\FC\D0\C2ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_Update(HI_HANDLE hSubt, HI_UNF_SUBT_PARAM_S *pstSubtParam);

/**
\brief Inject DVB subtitle stream to decoder. CNcomment:ע\C8\EB\D7\D6Ļ\CA\FD\BEݵ\BD\BD\E2\C2\EB\C6\F7\A1\A3CNend
\attention \n
Used the PES packet syntax for carriage of DVB subtitles. CNcomment:DVB\D7\D6Ļ\B4\AB\CA\E4ʹ\D3\C3PES\B8\F1ʽ\A1\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\param[in]  u32SubtPID    the pid of subtitle stream. CNcomment:\D7\D6Ļ\C1\F7pid\A1\A3CNend
\param[in]  pu8Data       subtitle stream data. CNcomment:\D7\D6Ļ\CA\FD\BEݡ\A3CNend
\param[in]  u32DataSize   the size of subtitle stream data. CNcomment:\D7\D6Ļ\CA\FD\BEݳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS inject success. CNcomment:ע\C8\EB\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE inject failure. CNcomment:ע\C8\EBʧ\B0ܡ\A3CNend
\see \n
none. CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_InjectData(HI_HANDLE hSubt, HI_U32 u32SubtPID, HI_U8* pu8Data, HI_U32 u32DataSize);

/**
\brief Register the callback function geted current pts.
CNcomment:ע\B2\E1\BB\F1ȡ\B5\B1ǰʱ\BC\E4\B4\C1\B5Ļص\F7\BA\AF\CA\FD\A1\A3CNend
\attention \n
none. CNcomment:\CEޡ\A3CNend
\param[in]  hSubt         subtitle handle. CNcomment:\D7\D6Ļ\BE\E4\B1\FA\A1\A3CNend
\param[in]  pfnGetPts     callback funtion which geted current pts. CNcomment:\BB\F1ȡ\B5\B1ǰʱ\BC\E4\B4\C1\B5Ļص\F7\BA\AF\CA\FD\A1\A3CNend
\param[in]  pUserData   userdata which used in callback funtion. CNcomment:\BBص\F7\BA\AF\CA\FD\B5\C4\D3û\A7\CA\FD\BEݡ\A3CNend
\retval   ::HI_SUCCESS    success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval   ::HI_FAILURE    failure. CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_SUBT_RegGetPtsCb(HI_HANDLE hSubt, HI_UNF_SUBT_GETPTS_FN pfnGetPts, HI_VOID* pUserData);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus*/

#endif
