/**
 \file
 \brief Subtitle output Module
 \author Shenzhen Hisilicon Co., Ltd.
 \version 1.0
 \author
 \date 2010-03-10
 */

#ifndef __HI_UNF_SO_H__
#define __HI_UNF_SO_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup     SUBTITLEOUT */
/** @{ */  /** <!-- \A1\BESUBTITLEOUT\A1\BF */

/** Number of palette *//** CNcomment:\B5\F7ɫ\B0\E5\D1\D5ɫ\B8\F6\CA\FD */
#define HI_UNF_SO_PALETTE_ENTRY (256)

/** Invalid pts value *//** CNcomment:\CE\DEЧ\B5\C4PTSֵ */
#define HI_UNF_SO_NO_PTS        (-1)

/** The max node in SO *//** CNcomment:SO\C4ܻ\BA\B4\E6\B5\C4\D7\EE\B4\F3\BDڵ\E3\CA\FD */
#define HI_UNF_SO_MAX_NODE_NUM  (20)

/** The max buffer size *//** CNcomment:SO\D7\EE\B4\F3\B5Ļ\BA\B4泤\B6\C8 */
#define HI_UNF_SO_MAX_BUFFER_SIZE (0x200000)


/** Subtitle type *//** CNcomment:\D7\D6Ļ\C0\E0\D0\CD */
typedef enum hiUNF_SO_SUBTITLE_TYPE_E
{
    HI_UNF_SUBTITLE_BITMAP = 0x0,  /**<Bmp subtitle *//**<CNcomment:ͼ\CF\F1\D7\D6Ļ */
    HI_UNF_SUBTITLE_TEXT,          /**<Text subtitle *//**<CNcomment:string\D7\D6Ļ */
    HI_UNF_SUBTITLE_ASS,           /**<Ass/ssa sbutitle *//**<CNcomment:ass\D7\D6Ļ */
    HI_UNF_SUBTITLE_BUTT
} HI_UNF_SO_SUBTITLE_TYPE_E;

/** Message type of subtitle *//** CNcomment:\CF\D4ʾ\CF\FBϢ\A3\AC\B6\D4\D3\DAteltext\A3\AC\BA\AC\CF\D4ʾ\BAͲ\C1\B3\FD\C1\BD\B8\F6\CF\FBϢ */
typedef enum hiUNF_SO_DISP_MSG_TYPE_E
{
    HI_UNF_SO_DISP_MSG_NORM  = 0x0,     /**<Draw the subtitle *//**<CNcomment:\D5\FD\B3\A3\CF\D4ʾ\CA\FD\BE\DD */
    HI_UNF_SO_DISP_MSG_ERASE,           /**<Clear the subtitle *//**<CNcomment:\B2\C1\B3\FD */
    HI_UNF_SO_DISP_MSG_END              /**<Message of drawing a page *//**<CNcomment:\D5\FBҳ\CF\D4ʾ\BD\E1\CA\F8 */
} HI_UNF_SO_DISP_MSG_TYPE_E;

/** The parameter of clear region *//** CNcomment:\B2\C1\B3\FD\B2\CE\CA\FD */
typedef struct hiUNF_SO_CLEAR_PARAM_S
{
    HI_U32 x, y, w, h;     /**<Postion of clearing *//**<CNcomment:\B2\C1\B3\FDλ\D6ú͸߿\ED\D0\C5Ϣ */
    HI_S64 s64ClearTime;   /**<Clear operation time,larger than or equal to s64NodePts+u32Duration*//**<CNcomment:\B2\C1\B3\FD\B2\D9\D7\F7\B7\A2\C9\FA\B5\C4ʱ\BC\E4,\B4\F3\D3ڵ\C8\D3\DAs64NodePts+u32Duration */
    HI_S64 s64NodePts;     /**<the present pts of sub *//**<CNcomment:\D7\D6Ļ\CF\D4ʾʱ\BC\E4\B4\C1 */
    HI_U32 u32Duration;    /**<the present duration of sub *//**<CNcomment:\D7\D6Ļ\CF\D4ʾʱ\BC䳤\B6\C8 */
} HI_UNF_SO_CLEAR_PARAM_S;

/** Color components  *//** CNcomment:\D1\D5ɫ\BDṹ */
typedef struct hiUNF_SO_COLOR_S
{
    HI_U8 u8Red;      /**<Red component *//**<CNcomment:R\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Green;    /**<Green component *//**<CNcomment:G\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Blue;     /**<Blue component *//**<CNcomment:B\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Alpha;    /**<Alpha component *//**<CNcomment:͸\C3\F7\B6ȣ\ACֵΪ0Ϊ͸\C3\F7\A3\AC0xFFΪ\B2\BB͸\C3\F7 */
} HI_UNF_SO_COLOR_S;

/** Information of bitmap subtitle *//** CNcomment:ͼ\CF\F1\D7\D6Ļ\D0\C5Ϣ */
typedef struct hiUNF_SO_GFX_S
{
    HI_S64 s64Pts;         /**<Start a display time, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\BC\E4\B4\C1\A3\AC\B5\A5λms */
    HI_U32 u32Duration;    /**<Duration of displaying, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\B3\A4\A3\AC\B5\A5λms */
    HI_U32 u32Len;         /**<Bytes of subtitle data *//**<CNcomment:\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λ\D7ֽ\DA */
    HI_U8  *pu8PixData;    /**<Data of subtitle *//**<CNcomment:ͼ\CF\F1\CA\FD\BE\DD */

    HI_UNF_SO_DISP_MSG_TYPE_E enMsgType;                   /**<Type of display message *//**<CNcomment:\CF\D4ʾ\CF\FBϢ\C0\E0\D0\CD */
    HI_UNF_SO_COLOR_S stPalette[HI_UNF_SO_PALETTE_ENTRY];  /**<Palette *//**<CNcomment:\B5\F7ɫ\B0壬ARGB8888 */
    HI_S32 s32BitWidth;    /**<Bits of Pix *//**<CNcomment:\CF\F3\CB\D8λ\BF\ED , \BF\C9\D2\D4Ϊ 2,4,8λ*/
    HI_U32 x, y, w, h;     /**<Position of display subtitle *//**<CNcomment:\CF\D4ʾλ\D6ú͸߿\ED\D0\C5Ϣ */
    HI_U32 u32CanvasWidth;   /**<Display canvas width *//**<CNcomment:\CF\D4ʾ\BB\AD\B2\BC\B5Ŀ\ED\B6\C8\D0\C5Ϣ */
    HI_U32 u32CanvasHeight;  /**<Display canvas height *//**<CNcomment:\CF\D4ʾ\BB\AD\B2\BC\B5ĸ߶\C8\D0\C5Ϣ */
} HI_UNF_SO_GFX_S;

/** Infomation of text subtitle *//** CNcomment:\CEı\BE\D7\D6Ļ\D0\C5Ϣ */
typedef struct hiUNF_SO_TEXT_S
{
    HI_S64 s64Pts;              /**<Start a display time, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\BC\E4\B4\C1\A3\AC\B5\A5λms */
    HI_U32 u32Duration;         /**<Duration of displaying, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\B3\A4\A3\AC\B5\A5λms */
    HI_U32 u32Len;              /**<Bytes of subtitle data *//**<CNcomment:\D7\D6Ļ\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λ\D7ֽ\DA */
    HI_U8 *pu8Data;             /**<Data of subtitle *//**<CNcomment:\D7\D6Ļ\CA\FD\BE\DD */

    HI_U32 x, y, w, h;          /**<Position of display subtitle *//**<CNcomment:\CF\D4ʾλ\D6ú͸߿\ED\D0\C5Ϣ */
} HI_UNF_SO_TEXT_S;

/** Infomation of ass/ssa subtitle *//** CNcomment:ass\D7\D6Ļ\D0\C5Ϣ */
typedef struct hiUNF_SO_ASS_S
{
    HI_S64 s64Pts;                /**<Start a display time, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\BC\E4\B4\C1\A3\AC\B5\A5λms */
    HI_U32 u32Duration;           /**<Duration of displaying, unit is Millisecond *//**<CNcomment:\CF\D4ʾʱ\B3\A4\A3\AC\B5\A5λms */
    HI_U32 u32FrameLen;           /**<Bytes of subtitle data *//**<CNcomment:֡\B3\A4\B6ȣ\AC\B5\A5λ\D7ֽ\DA */
    HI_U8  *pu8EventData;         /**<Data of subtitle *//**<CNcomment:֡\CA\FD\BE\DD */
    HI_U32 u32ExtradataSize;      /**<Length of extra data *//**<CNcomment:\C0\A9չ\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λ\D7ֽ\DA */
    HI_U8  *pu8Extradata;         /**<Extra data *//**<CNcomment:\C0\A9չ\CA\FD\BE\DD */
} HI_UNF_SO_ASS_S;

/** Infomation of subtitle *//** CNcomment:\D7\D6Ļ\D0\C5Ϣ */
typedef struct hiUNF_SO_SUBTITLE_INFO_S
{
    HI_UNF_SO_SUBTITLE_TYPE_E eType; /**<type *//**<CNcomment:\D7\D6Ļ\C0\E0\D0\CD */

    union
    {
        HI_UNF_SO_GFX_S  stGfx;      /**<Gfx subtitle *//**<CNcomment:ͼ\D0\CE\D7\D6Ļ */
        HI_UNF_SO_TEXT_S stText;     /**<Text subtitle *//**<CNcomment:\CEı\BE\D7\D6Ļ */
        HI_UNF_SO_ASS_S  stAss;      /**<Ass subtitle *//**<CNcomment:ASS\D7\D6Ļ */
    } unSubtitleParam;
} HI_UNF_SO_SUBTITLE_INFO_S;

/**
\brief Call back funtion of getting current play time.
CNcomment:\BB\F1ȡ\B5\B1ǰ\B2\A5\B7\C5֡\B5\C4ʱ\BC\E4\B4\C1\A3\AC\C8\E7\B9\FB\B5\B1ǰʱ\BC\E4\CE\DEЧ\A3\ACps64CurrentPts\B8\B3ֵΪHI_UNF_SO_NO_PTS\A1\A3CNend
\attention \n
None
\param[in] pUserData Userdata.CNcomment:ע\B2ᴫ\C8\EB\B5\C4\D3û\A7\CA\FD\BEݡ\A3CNend
\param[out] ps64CurrentPts Current play time. CNcomment:\B5\B1ǰ\B2\A5\B7\C5֡ʱ\BC\E4\B4\C1\A3\AC\B5\A5λms\A1\A3CNend

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_GETPTS_FN)(HI_VOID* pUserData, HI_S64 *ps64CurrentPts);

/**
\brief Callback funtion of drawing the subtitle. CNcomment:\D7\D6Ļ\BB\ADͼ\BBص\F7\BA\AF\CA\FD\A1\A3CNend
\attention \n
None
\param[in] pUserData Userdata. CNcomment:ע\B2ᴫ\C8\EB\B5\C4\D3û\A7\CA\FD\BEݡ\A3CNend
\param[in] pstInfo Information of subtitle. CNcomment:\D7\D6Ļ\D0\C5Ϣ\A1\A3CNend
\param[in] pArg User data. CNcomment:\C0\A9չ\CA\FD\BEݡ\A3CNend

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_ONDRAW_FN)(HI_VOID* pUserData, const HI_UNF_SO_SUBTITLE_INFO_S *pstInfo, HI_VOID *pArg);

/**
\brief Call back funtion of clearing the subtitle. CNcomment:\D7\D6Ļ\CF\D4ʾ\B5\BDʱ\C7\E5\B3\FD\BA\AF\CA\FD\A1\A3CNend
\attention \n
None
\param[in] pUserData User data. CNcomment:ע\B2ᴫ\C8\EB\B5\C4\D3û\A7\CA\FD\BEݡ\A3CNend
\param[out] pArg Parameter of clearing the subtitle, Type is HI_UNF_SO_CLEAR_PARAM_S. CNcomment:\B2\C1\B3\FD\B2\CE\CA\FD\A3\ACָ\CF\F2HI_UNF_SO_CLEAR_PARAM_S\BDṹ\A1\A3CNend

\retval ::HI_SUCCESS

\see \n
None
*/
typedef HI_S32 (*HI_UNF_SO_ONCLEAR_FN)(HI_VOID* pUserData, HI_VOID *pArg);

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      SUBTITLEOUT */
/** @{*/  /** <!-- [SUBTITLEOUT]*/

/**
\brief  Init SO module. CNcomment:subtitle output ģ\BF\E9\B3\F5ʼ\BB\AF\A1\A3CNend
\attention \n
None
\param None

\retval ::HI_SUCCESS Init success. CNcomment:\B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Operation fail. CNcomment:\B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_Init(HI_VOID);

/**
\brief  Deinit SO module. CNcomment:subtitle output ģ\BF\E9ȥ\B3\F5ʼ\BB\AF\A1\A3CNend
\attention \n
None
\param None

\retval ::HI_SUCCESS  Deinit success. CNcomment:ȥ\B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Operation fail. CNcomment:ȥ\B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_DeInit(HI_VOID);

/**
\brief  Creates an SO instance. CNcomment:\B4\B4\BD\A8һ\B8\F6soʵ\C0\FD\A1\A3CNend
\attention \n
None
\param[out] phdl Handle of SO instance. CNcomment:\B2\A5\B7\C5\C6\F7ʵ\C0\FD\A1\A3CNend

\retval ::HI_SUCCESS  Create success. CNcomment:\B4\B4\BD\A8\B3ɹ\A6\A3\AC\BE\E4\B1\FA\D3\D0Ч\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:\B4\B4\BD\A8ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_Create(HI_HANDLE *phdl);

/**
\brief  Destroy an SO instance. CNcomment:\CF\FA\BB\D9һ\B8\F6soʵ\C0\FD\A1\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend

\retval ::HI_SUCCESS  Destroy success. CNcomment:\CF\FA\BBٳɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:\CF\FA\BB\D9ʧ\B0ܣ\AC\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_Destroy(HI_HANDLE handle);

/**
\brief  Setting offset time of the subtitle. CNcomment:\C9\E8\D6\C3\D7\D6Ļʱ\BC\E4ƫ\D2ơ\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] s64OffsetMs Offset of subtitle, unit is Millisecondes.CNcomment:\D7\D6Ļ\CF\D4ʾʱ\BC\E4ƫ\D2\C6ֵ\A3\AC\B5\A5λms\A1\A3CNend

\retval ::HI_SUCCESS  Operation success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetOffset(HI_HANDLE handle, HI_S64 s64OffsetMs);

/**
\brief  Register the callback function of getting current play time. CNcomment:ע\B2\E1ʱ\BC\E4\B4\C1\BB\F1ȡ\BBص\F7\BA\AF\CA\FD\A3\ACsoͨ\B9\FD\BB\F1ȡ\B5\B1ǰ\B2\A5\B7\C5ʱ\BC\E4\B4\C1ͬ\B2\BD\D7\D6Ļ\A1\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance.CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] pstCallback Callback function. CNcomment:\BBص\F7\BA\AF\CA\FD\B2\CE\CA\FD\A1\A3CNend
\param[in] pUserData User data. CNcomment:\D3û\A7\CA\FD\BEݡ\A3CNend

\retval ::HI_SUCCESS  Register success. CNcomment:ע\B2\E1\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Parameter invalid. CNcomment:ע\B2\E1ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_RegGetPtsCb(HI_HANDLE handle, HI_UNF_SO_GETPTS_FN pstCallback, HI_VOID* pUserData);

/**
\brief  Register the callback function of drawing subtitle.
CNcomment:ע\B2\E1\D7\D6Ļ\BB\E6\D6\C6\C7\E5\B3\FD\BBص\F7\BA\AF\CA\FD\A3\AC\C8\E7\B9\FB\C9\E8\D6\C3\C1˸ú\AF\CA\FD\A3\AC\D4\F2soʹ\D3øú\AF\CA\FDʵ\CF\D6\D7\D6Ļ\CA\E4\B3\F6\A3\AC\D7\D6Ļ\CF\D4ʾʱ\B3\A4\B5\BD\B4\EF\BA\F3\A3\ACso\B5\F7\D3\C3\C7\E5\B3\FD\BA\AF\CA\FD֪ͨ\C7\E5\B3\FD\A1\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] pfnOnDraw Callback function of drawing subtitle. CNcomment:\BB\E6\D6ƺ\AF\CA\FD\A1\A3CNend
\param[in] pfnOnClear Callback function of clearing subtitle. CNcomment:\C7\E5\B3\FD\BA\AF\CA\FD\A1\A3CNend
\param[in] pUserData User data. CNcomment:\D3û\A7\CA\FD\BEݡ\A3CNend

\retval ::HI_SUCCESS  Register success. CNcomment:ע\B2\E1\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Parameter invalid. CNcomment:ע\B2\E1ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_RegOnDrawCb(HI_HANDLE handle, HI_UNF_SO_ONDRAW_FN pfnOnDraw,
                                          HI_UNF_SO_ONCLEAR_FN pfnOnClear, HI_VOID* pUserData);

/**
\brief  Set the surface of drawing subtitle, if you do not set the ondraw callback function, SO painting subtitles with the surface.
CNcomment:\C9\E8\D6\C3\D7\D6Ļ\BB\E6\D6ƻ\AD\B2\BC\BE\E4\B1\FA\A3\AC\C8\E7\B9\FBû\D3\D0\C9\E8\D6\C3ondraw\BBص\F7\BA\AF\CA\FD\A3\AC\D4\F2soʹ\D3\C3\C9\E8\D6õĻ\AD\B2\BC\BE\E4\B1\FA\CA\E4\B3\F6\D7\D6Ļ\A1\A3CNend
\attention \n
This feature is not implemented. CNcomment:\B8ù\A6\C4\DCδʵ\CF֡\A3CNend
\param[in] handle Handle of SO instance.CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] hSurfaceHandle Handle of surface. CNcomment:\BB\AD\B2\BC\BE\E4\B1\FA\A1\A3CNend

\retval ::HI_SUCCESS Success of setting surface. CNcomment:\C9\E8\D6óɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation invalid. CNcomment:\C9\E8\D6\C3ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetDrawSurface(HI_HANDLE handle, HI_HANDLE hSurfaceHandle);

/**
\brief  Set the font of drawing subtitle.
CNcomment:\C9\E8\D6\C3\D7\D6Ļ\CF\D4ʾ\D7\D6\CC壬\B8\C3\C9\E8\D6ý\F6\B6\D4\C9\E8\D6û\AD\B2\BC\CA\E4\B3\F6\D7\D6Ļ\B5ķ\BDʽ\C6\F0\D7\F7\D3á\A3CNend
\attention \n
This feature is not implemented. CNcomment:\B8ù\A6\C4\DCδʵ\CF֡\A3CNend
\param[in] handle Handle of SO instance.CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] hFont Handle of font instance.CNcomment:\B4\B4\BD\A8\B5\C4\D7\D6\CC\E5\BE\E4\B1\FA\A1\A3CNend

\retval ::HI_SUCCESS  Success.CNcomment:\C9\E8\D6óɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation invalid. CNcomment:\C9\E8\D6\C3ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetFont(HI_HANDLE handle, HI_HANDLE hFont);

/**
\brief Set the color of drawing text subtitle.
CNcomment:\C9\E8\D6\C3\D7\D6Ļ\CF\D4ʾ\D1\D5ɫ\A3\AC\B8\C3\C9\E8\D6ý\F6\B6\D4\C9\E8\D6û\AD\B2\BC\CA\E4\B3\F6\D7\D6Ļ\B5ķ\BDʽ\C6\F0\D7\F7\D3á\A3CNend
\attention \n
This feature is not implemented. CNcomment:\B8ù\A6\C4\DCδʵ\CF֡\A3CNend
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] u32Color Value of the color. CNcomment:\D1\D5ɫֵ\A1\A3CNend

\retval ::HI_SUCCESS  Success. CNcomment:\C9\E8\D6óɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation invalid. CNcomment:\C9\E8\D6\C3ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetColor(HI_HANDLE handle, HI_U32 u32Color);

/**
\brief Set the position of display subtitle.
CNcomment:\C9\E8\D6\C3\D7\D6Ļ\CF\D4ʾ\D7\F8\B1꣬\B8\C3\C9\E8\D6ý\F6\B6\D4\C9\E8\D6û\AD\B2\BC\CA\E4\B3\F6\D7\D6Ļ\B5ķ\BDʽ\C6\F0\D7\F7\D3á\A3CNend
\attention \n
This feature is not implemented. CNcomment:\B8ù\A6\C4\DCδʵ\CF֡\A3CNend
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] u32x Value of x coordinate.CNcomment:x\D7\F8\B1ꡣCNend
\param[in] u32y Value of y coordinate. CNcomment:y\D7\F8\B1ꡣCNend

\retval ::HI_SUCCESS  Success. CNcomment:\C9\E8\D6óɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Parameter invalid. CNcomment:\C9\E8\D6\C3ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetPos(HI_HANDLE handle, HI_U32 u32x, HI_U32 u32y);

/**
\brief  Getting the number in the butitle queue.
CNcomment:\BB\F1ȡ\BB\BA\B3\E5buffer\D6\D0δ\CF\D4ʾ\B5\C4\D7\D6Ļ\CA\FD\BEݸ\F6\CA\FD\A1\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[out] pu32SubNum Number of subtitles in queue. CNcomment:\BB\BA\B3\E5\D7\D6Ļ\B8\F6\CA\FD\A1\A3CNend

\retval ::HI_SUCCESS Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_GetSubNumInBuff(HI_HANDLE handle, HI_U32 *pu32SubNum);

/**
\brief Clear the subtitles in queue.
CNcomment:\C7\E5\B3\FD\D7\D6Ļ\BB\BA\B3\E5\D6е\C4\CA\FD\BEݣ\AC\D7\D6Ļ\C7л\BBʱ\A3\AC\D0\E8\B5\F7\D3øýӿ\DA\C7\E5\B3\FDso\D7\D6Ļ\BB\BA\B4档CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend

\retval ::HI_SUCCESS Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Operation invalid. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_ResetSubBuf(HI_HANDLE handle);

/**
\brief  Clear the subtitles in queue by PTS. If PTS is 0, the same as HI_UNF_SO_ResetSubBuf.
CNcomment:\C7\E5\B3\FD\D7\D6Ļ\BB\BA\B3\E5\D6е\C4\CA\FD\BE\DD,С\D3\DAָ\B6\A8PTS\B5\C4\D7\D6Ļ\BB\BA\B3屻\C7\E5\B3\FD.\C8\E7\B9\FBָ\B6\A8PTSֵΪ0,\D5\E2\B8\F6\BDӿڵ\C8Ч\D3\DAHI_UNF_SO_ResetSubBuf\A1\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend

\retval ::HI_SUCCESS Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Operation invalid. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_ResetSubBuf_ByPts(HI_HANDLE handle, HI_S64 s64Pts);

/**
\brief  Send subtitles to SO queue. If the data size and the number is larger than the value set by the user, then the transmission fails.
CNcomment:\B7\A2\CB\CD\D7\D6Ļ\CA\FD\BEݸ\F8so\A3\AC\C8\E7\B9\FB\BB\BA\B3\E5size\BA͸\F6\CA\FD\B6\BC\B3\AC\B9\FD\D3û\A7\C9\E8\D6õ\C4ֵ\A3\AC\D4\F2\B7\A2\CB\CDʧ\B0ܡ\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] pstSubInfo Data of subtitle. CNcomment:\D7\D6Ļ\D0\C5Ϣ\A1\A3CNend
\param[in] u32TimeOut Timeout of sending subtitle. CNcomment:\B7\A2\CBͳ\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend

\retval ::HI_SUCCESS  Success. CNcomment:\B7\A2\CBͳɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail.CNcomment:\B7\A2\CB\CDʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SendData(HI_HANDLE handle, const HI_UNF_SO_SUBTITLE_INFO_S *pstSubInfo, HI_U32 u32TimeOutMs);

/**
\brief  Get current subt data in SO queue.
CNcomment:\BB\F1ȡSO \B6\D3\C1\D0\D6У\AC\B5\B1ǰ\D5\FD\D4ڴ\A6\C0\ED\B5\C4\D7\D6Ļ\CA\FD\BEݡ\A3CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] pstSubInfo Data of subtitle. CNcomment:\D7\D6Ļ\D0\C5Ϣ\A1\A3CNend

\retval ::HI_SUCCESS  Success. CNcomment:\B7\A2\CBͳɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail.CNcomment:\B7\A2\CB\CDʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_GetCurData(HI_HANDLE handle, HI_UNF_SO_SUBTITLE_INFO_S *pstSubInfo);

/**
\brief  Setting max interval time of the subtitle.
CNcomment:\C9\E8\D6\C3\D7\D6Ļ\D7\EE\B4\F3\B5\C4ʱ\BC\E4ƫ\B2CNend
\attention \n
None
\param[in] handle Handle of SO instance. CNcomment:soʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] u32IntervalMs max interval of subtitle, unit is Millisecondes.
CNcomment:\D7\D6Ļ\D7\EE\B4\F3\B5\C4ʱ\BC\E4ƫ\B2\EEֵ\A3\AC\B5\A5λms\A1\A3CNend

\retval ::HI_SUCCESS  Operation success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_SO_SetMaxInterval(HI_HANDLE handle, HI_U32 u32IntervalMs );

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_SO_H__ */
