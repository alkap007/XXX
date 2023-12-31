#ifndef __HI_GO_BLITER_H__
#define __HI_GO_BLITER_H__

#include "hi_go_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/


/****************************** Error Number ********************************/


/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_BLIT */
/** @{ */  /** <!-- [HIGO_BLIT] */

/** Pixel-level alpha blending operation*/
/** CNcomment: \CF\F1\CBؼ\B6alpha\BB\EC\BAϲ\D9\D7\F7\D4\CB\CB\E3 */
typedef enum
{
    HIGO_COMPOPT_NONE = 0, /**<Porter/Duff None-blending operation*//**<CNcomment:Porter/Duff None\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_CLEAR,    /**<Porter/Duff clear blending operation*//**<CNcomment:Porter/Duff clear\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_SRC     , /**<Porter/Duff SRC blending operation*//**<CNcomment:Porter/Duff Src\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_SRCOVER , /**<Porter/Duff Srcover blending operation*//**<CNcomment:Porter/Duff Srcover\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_DSTOVER , /**<Porter/Duff DstOver blending operation*/ /**<CNcomment:Porter/Duff DstOver\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_SRCIN   , /**<Porter/Duff SrcIn blending operation*//**<CNcomment:Porter/Duff SrcIn\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_DSTIN   , /**<Porter/Duff DstIn blending operation*/ /**<CNcomment:Porter/Duff DstIn\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_SRCOUT  , /**<Porter/Duff SrcOut blending operation*//**<CNcomment:Porter/Duff SrcOut\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_DSTOUT  , /**<Porter/Duff DstOut blending operation*/ /** CNcomment:Porter/Duff DstOut\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_SRCATOP , /**<Porter/Duff SrcAtop blending operation*/ /**<CNcomment:Porter/Duff SrcAtop\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_DSTATOP , /**<Porter/Duff DstAtop blending operation*//**<CNcomment: Porter/Duff DstAtop\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_ADD     ,  /**<Porter/Duff DstAtop blending operation*/ /**<CNcomment: Porter/Duff DstAtop\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_XOR     , /**<Porter/Duff Xor blending operation*/ /**<CNcomment: Porter/Duff Xor\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_DST     , /**<Porter/Duff DstAtop blending operation*/ /**<CNcomment: Porter/Duff DstAtop\BB\EC\BAϲ\D9\D7\F7 */
    HIGO_COMPOPT_AKS,      /**<Assume that the destination surface is not transparent. After the alpha blending is performed, the source alpha is retained.*//**<CNcomment: \BC\D9\C9\E8Ŀ\B1\EAsurfaceΪ\B2\BB͸\C3\F7\A3\AC\BC\F2\B5\A5alpha\BB\EC\BAϣ\AC\BD\E1\B9\FB\B1\A3\C1\F4Դalpha */
    HIGO_COMPOPT_AKD,      /**<Assume that the destination surface is not transparent. After the alpha blending is performed, the destination alpha is retained.*//**<CNcomment: \BC\D9\C9\E8Ŀ\B1\EAsurfaceΪ\B2\BB͸\C3\F7\A3\AC\BC\F2\B5\A5alpha\BB\EC\BAϣ\AC\BD\E1\B9\FB\B1\A3\C1\F4Ŀ\B1\EAalpha */

    HIGO_COMPOPT_BUTT
} HIGO_COMPOPT_E;

/** Operation mode corresponding to colorkey*//** CNcomment: Colorkey\B6\D4Ӧ\B5Ĳ\D9\D7\F7\B7\BDʽ */
typedef enum
{
    HIGO_CKEY_NONE = 0, /**<Do not use the colorkey.*//**<CNcomment: \B2\BBʹ\D3\C3colorkey */
    HIGO_CKEY_SRC,      /**<Use the source colorkey.*//**<CNcomment: ʹ\D3\C3Դcolorkey */
    HIGO_CKEY_DST,     /**<Use the destination colorkey.*//**<CNcomment: ʹ\D3\C3Ŀ\B1\EAcolorkey */

    HIGO_CKEY_BUTT
} HIGO_CKEY_E;

/** Two raster of operations (ROPs)*//** CNcomment: 2ԪROP\B2\D9\D7\F7 */
typedef enum
{
    HIGO_ROP_BLACK = 0, /**< Blackness */
    HIGO_ROP_PSDon,     /**< ~(PS+D) */
    HIGO_ROP_PSDna,     /**< ~PS & D */
    HIGO_ROP_PSn,       /**< ~PS */
    HIGO_ROP_DPSna,     /**< PS & ~D */
    HIGO_ROP_Dn,        /**< ~D */
    HIGO_ROP_PSDx,      /**< PS^D */
    HIGO_ROP_PSDan,     /**< ~(PS&D) */
    HIGO_ROP_PSDa,      /**< PS & D */
    HIGO_ROP_PSDxn,     /**< ~(PS^D) */
    HIGO_ROP_D,         /**< D */
    HIGO_ROP_PSDno,     /**< ~PS + D */
    HIGO_ROP_PS,        /**< PS */
    HIGO_ROP_DPSno,     /**< PS + ~D */
    HIGO_ROP_PSDo,      /**< PS+D */
    HIGO_ROP_WHITE,     /**< Whiteness */

    HIGO_ROP_BUTT
} HIGO_ROP_E;

typedef enum
{
    HIGO_ROTATE_NONE = 0,
    HIGO_ROTATE_90,     /**<Rotate 90 degrees clockwise*//**<CNcomment: ˳ʱ\D5\EB\D0\FDת90\B6\C8 */
    HIGO_ROTATE_180,    /**<Rotate 180 degrees clockwise*//**<CNcomment: ˳ʱ\D5\EB\D0\FDת180\B6\C8 */
    HIGO_ROTATE_270,    /**<Rotate 270 degrees clockwise*//**<CNcomment: ˳ʱ\D5\EB\D0\FDת270\B6\C8 */

    HIGO_ROTATE_BUTT
} HIGO_ROTATE_E;

typedef enum
{
    HIGO_MIRROR_NONE = 0,

    HIGO_MIRROR_LR,     /**<Mirror the left and the right*//**<CNcomment: \D7\F3\D3Ҿ\B5\CF\F1 */
    HIGO_MIRROR_TB,     /**<Mirror the top and the bottom*//**<CNcomment: \C9\CF\CF¾\B5\CF\F1 */

    HIGO_MIRROR_BUTT
} HIGO_MIRROR_E;

typedef struct
{
    HI_BOOL EnableGlobalAlpha;      /**<Global alpha enable flag*//**<CNcomment: ȫ\BE\D6alphaʹ\C4ܱ\EA־ */
    HI_BOOL EnablePixelAlpha;       /**<Pixel alpha enable flag*//**<CNcomment: \CF\F1\CB\D8alphaʹ\C4ܱ\EA־ */
    HIGO_COMPOPT_E PixelAlphaComp;  /**<Pixel alpha operation*//**<CNcomment: \CF\F1\CB\D8alpha\B2\D9\D7\F7 */
    HIGO_CKEY_E    ColorKeyFrom;    /**<Colorkey operation*//**<CNcomment:ColorKey\B2\D9\D7\F7 */
    HI_BOOL        EnableRop;       /**<Enable the ROP2 operation*//**<CNcomment: \C6\F4\D3\C3ROP2\B2\D9\D7\F7 */
    HIGO_ROP_E     Rop;              /**<ROP2 operation type*//**<CNcomment: ROP2\B2\D9\D7\F7\C0\E0\D0\CD */
    HIGO_ROP_E     RopAlpha;         /**<Type of the ROP alpha operation*//**<CNcomment: ROP alpha\B2\D9\D7\F7\C0\E0\D0\CD*/
 }HIGO_BLTOPT2_S;

/** CNcomment: blit\B2\D9\D7\F7\CA\F4\D0\D4 */
typedef struct
{
    HI_BOOL EnableGlobalAlpha;      /**<Global alpha enable flag. If this flag is enabled, the PixelAlphaComp blending mode must be specified.*//**<CNcomment: ȫ\BE\D6alphaʹ\C4ܱ\EA־,\B4򿪴˿\AA\B9\D8֮\CD⻹\B1\D8\D0\EBָ\B6\A8PixelAlphaComp\B5Ļ\EC\BAϷ\BDʽ*/
    HI_BOOL EnablePixelAlpha;       /**<Pixel alpha enable flag*//**<CNcomment: \CF\F1\CB\D8alphaʹ\C4ܱ\EA־ */
    HIGO_COMPOPT_E PixelAlphaComp;  /**<Pixel alpha operation*//**<CNcomment: \CF\F1\CB\D8alpha\B2\D9\D7\F7 */
    HIGO_CKEY_E    ColorKeyFrom;    /**<colorkey operation*//**<CNcomment: ColorKey\B2\D9\D7\F7 */
    HI_BOOL        EnableRop;       /**<Enable the ROP2 operation*//**<CNcomment: \C6\F4\D3\C3ROP2\B2\D9\D7\F7 */
    HIGO_ROP_E     Rop;             /**<ROP2 operation type*//**<CNcomment: ROP2\B2\D9\D7\F7\C0\E0\D0\CD */
    HIGO_ROP_E     RopAlpha;        /**<Type of the ROP alpha operation*/    /**<CNcomment: ROP alpha\B2\D9\D7\F7\C0\E0\D0\CD*/
    HI_BOOL        EnableScale;      /**<Enable the scaling function*//**<CNcomment: \C6\F4\D3\C3\CB\F5\B7\C5 */
    HIGO_ROTATE_E  RotateType;      /**<Rotation type*//**<CNcomment: \D0\FDת\B7\BDʽ */
    HIGO_MIRROR_E  MirrorType;      /**<Mirror type*//**<CNcomment: \BE\B5\CF\F1\B7\BDʽ */
} HIGO_BLTOPT_S;

typedef struct
{
    HI_BOOL EnableGlobalAlpha;      /**<Global alpha enable flag*//**<CNcomment: ȫ\BE\D6alphaʹ\C4ܱ\EA־ */

    HIGO_COMPOPT_E PixelAlphaComp;  /**<Pixel alpha operation*//**<CNcomment: \CF\F1\CB\D8alpha\B2\D9\D7\F7 */
    HI_BOOL        EnableRop;       /**<Enable the ROP2 operation*//**<CNcomment: \C6\F4\D3\C3ROP2\B2\D9\D7\F7 */
    HIGO_ROP_E     RopColor;        /**<ROP2 operation type*//**<CNcomment: ROP2\B2\D9\D7\F7\C0\E0\D0\CD */
	HIGO_ROP_E     RopAlpha;

} HIGO_MASKOPT_S;

/**Anti-flicker level*//** CNcomment: \BF\B9\C9\C1˸\BC\B6\B1\F0 */
typedef enum
{
    HIGO_DEFLICKER_AUTO = 0, /*Anti-flicker level, ranging from low to high. The higher the level, the better the anti-flicker effect, but the more blurred the picture.*//** CNcomment:\BF\B9\C9\C1˸\BC\B6\B1\F0\A3\ACֵΪLOW~HIGH,ֵԽ\B4\F3\BF\B9\C9\C1˸Ч\B9\FBԽ\BAã\AC\B5\ABԽģ\BA\FD*/
    HIGO_DEFLICKER_LOW,
    HIGO_DEFLICKER_MIDDLE,
    HIGO_DEFLICKER_HIGH,
    HIGO_DEFLICKER_BUTT
}HIGO_DEFLICKEROPT_E;

/**Anti-flicker level*//** CNcomment: \BF\B9\C9\C1˸\BC\B6\B1\F0 */
typedef struct
{
    HIGO_DEFLICKEROPT_E DefLevel;
}HIGO_DEFLICKEROPT_S;
/** @} */  /*! <!-- Structure Definition end */

/********************** Global Variable declaration **************************/

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_BLIT */
/** @{ */  /** <!-- \A1\BEHIGO_BLIT\A1\BF */

/**
\brief Initializes the Bliter module.CNcomment: \B3\F5ʼ\BB\AFBliterģ\BF\E9 CNend
\attention \n
When ::HI_GO_Init is called, this application programming interface (API) is also called.CNcomment: ::HI_GO_Init\D6\D0\D2Ѱ\FC\BA\AC\C1˶Ըýӿڵĵ\F7\D3\C3 CNend
\param  N/A.CNcomment: \CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
::HI_GO_Init \n
::HI_GO_DeinitBliter
*/
HI_S32 HI_GO_InitBliter(HI_VOID);

/**
\brief Deinitializes the Bliter module.CNcomment:ȥ\B3\F5ʼ\BB\AFBliterģ\BF\E9 CNend
\attention \n
When ::HI_GO_Deinit is called, this API is also called.CNcomment:::HI_GO_Deinit\D6\D0\D2Ѱ\FC\BA\AC\C1˶Ըýӿڵĵ\F7\D3\C3 CNend
\param N/A. CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT

\see \n
::HI_GO_Deinit \n
::HI_GO_InitBliter
*/

HI_S32 HI_GO_DeinitBliter(HI_VOID);

/**
\brief Fills in a rectangle.CNcomment:\BE\D8\D0\CE\CC\EE\B3\E4 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] Surface Surface handle.CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] pRect Size of the rectangle to be filled in. If the parameter is not set, it indicates that the entire
surface is filled in.CNcomment: \CC\EE\B3\E4\BE\D8\D0δ\F3С\A3\ACΪ\BFձ\EDʾ\CC\EE\B3\E4\D5\FB\B8\F6surface CNend
\param[in] Color Color Fill color. For the RGB format, 32-bit color is filled in; for the palette, the color index (0-255)
is filled in.CNcomment:\CC\EE\B3\E4\D1\D5ɫ,ע\D2\E2\C8\E7\B9\FB\CA\C7RGB\B8\F1ʽ\A3\ACͳһ\CC\EE\B3\E432λɫ\A3\AC\C8\E7\B9\FB\B5\F7ɫ\B0壬\BE\CDֱ\BD\D3\CC\EE\B3\E4\D1\D5ɫ\CB\F7\D2\FD(0 ~ 255)\A1\A3CNend
\param[in] CompositeOpt Blending mode.CNcomment:\BB\EC\BAϷ\BDʽ CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_OUTOFPAL
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_FillRect(HI_HANDLE Surface, const HI_RECT* pRect, HI_COLOR Color, HIGO_COMPOPT_E CompositeOpt);

/**
\brief Transfers bit blocks. During the transfer, color space conversion (CSC), scaling, and rotation are supported.CNcomment:λ\BF\E9\B0\E1\D2ƣ\AC\D4ڰ\E1\D2ƹ\FD\B3\CC\D6У\AC\BF\C9\D2\D4ʵ\CF\D6ɫ\B2ʿռ\E4ת\BB\BB\A1\A2\CB\F5\B7š\A2\D0\FDת\B9\A6\C4\DC CNend
\attention \n
Only the YUV-to-RGB CSC is supported. \n
The operations of colorkey, alpha, ROP, and colorkey+ROP are supported.\
Scaling, rotation, and mirror cannot be combined. \n
For scaling, rotation, and mirror, the source and destination pixel formats must be the same, but the format cannot
be YUV or CLUT.\n
CNcomment:ɫ\B2ʿռ\E4ת\BB\BB\BD\F6֧\B3\D6YUV\B5\BDRGBת\BB\BB \n
\BF\C9\D2\D4֧\B3ֲ\D9\D7\F7\C8\E7\CF\C2colorkey\A1\A2alpha\A1\A2ROP\A1\A2colorkey+ROP\
\CB\F5\B7š\A2\D0\FDת\BB\F2\BE\B5\CF񲻿\C9\D7\E9\BA\CFʹ\D3\C3 \n
\CB\F5\B7š\A2\D0\FDת\BB\F2\BE\B5\CF\F1Ҫ\C7\F3Դ\D3\EBĿ\B1\EA\CF\F1\CBظ\F1ʽ\CD\EAȫ\CF\E0ͬ\A3\AC\B5\AB\B2\BB\C4\DC\CA\C7YUV\B8\F1ʽ\BA\CDCLUT\B8\F1ʽ \n CNend

\param[in] SrcSurface Source surface handle.CNcomment:Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect Source region for transfer. If the parameter is not set, it indicates the entire source surface.CNcomment:\B0\E1\D2Ƶ\C4Դ\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Դsurface\C7\F8\D3\F2 CNend
\param[in] DstSurface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pDstRect Destination region for transfer. If the parameter is not set, it indicates the entire destination
surface.CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pBlitOpt Blending mode.CNcomment:\BB\EC\BAϷ\BDʽ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVMIRRORTYPE
\retval ::HIGO_ERR_INVROTATETYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_INTERNAL

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_Blit (HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                   HI_HANDLE DstSurface, const HI_RECT* pDstRect,
                   const HIGO_BLTOPT_S* pBlitOpt);

/**
\brief Draws a line segment. Cropping is not supported.CNcomment:\BB\E6\D6\C6\CF߶Σ\AC\B2\BB֧\B3ֲü\F5 CNend
\attention \n
Cropping is not supported. Users must keep the entire line within the surface region.
CNcomment:\B2\BB֧\B3ֲü\F5\A3\ACʹ\D3\C3\D5߱\D8\D0뱣֤\D5\FB\CC\F5ֱ\CF\DF\D4\DAsurface\C7\F8\D3\F2\C4\DA CNend

\param[in] Surface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] x0 Horizontal coordinate of the start point.CNcomment:\C6\F0\B5\E3x\D7\F8\B1\EA CNend
\param[in] y0 Vertical coordinate of the start point.CNcomment:\C6\F0\B5\E3y\D7\F8\B1\EA CNend
\param[in] x1 Horizontal coordinate of the end point.CNcomment:\D6յ\E3x\D7\F8\B1\EA CNend
\param[in] y1 Vertical coordinate of the end point .CNcomment:\D6յ\E3y\D7\F8\B1\EA CNend
\param[in] color Line segment color.CNcomment:\CF߶\CE\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DrawLine(HI_HANDLE Surface, HI_S32 x0, HI_S32 y0, HI_S32 x1, HI_S32 y1, HI_COLOR color);

/**
\brief Draws an ellipse.CNcomment:\BB\E6\D6\C6\CD\D6Բ CNend
\attention \n
Cropping is not supported. Users must keep the entire ellipse within the surface region.
CNcomment:\B2\BB֧\B3ֲü\F5\A3\ACʹ\D3\C3\D5߱\D8\D0뱣֤\D5\FB\B8\F6\CD\D6Բ\D4\DAsurface\C7\F8\D3\F2\C4\DA CNend

\param[in] Surface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] sx Horizontal coordinate of the ellipse center.CNcomment:Բ\D0\C4x\D7\F8\B1\EA CNend
\param[in] sy Vertical coordinate of the ellipse center.CNcomment:Բ\D0\C4y\D7\F8\B1\EA CNend
\param[in] rx X axis radius .CNcomment:x\D6\E1\B0뾶 CNend
\param[in] ry Y axis radius.CNcomment:y\D6\E1\B0뾶 CNend
\param[in] color Ellipse color.CNcomment:\CD\D6Բ\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DrawEllipse(HI_HANDLE Surface, HI_S32 sx, HI_S32 sy, HI_S32 rx, HI_S32 ry, HI_COLOR color);

/**
\brief Draws a circle. Cropping is not supported.CNcomment:\BB\E6\D6\C6Բ\A3\AC\B2\BB֧\B3ֲü\F5 CNend
\attention \n
Cropping is not supported. Users must keep the entire circle within the surface region.
CNcomment:\B2\BB֧\B3ֲü\F5\A3\ACʹ\D3\C3\D5߱\D8\D0뱣֤\D5\FB\B8\F6Բ\D4\DAsurface\C7\F8\D3\F2\C4\DA CNend

\param[in] Surface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] x Horizontal coordinate of the circle center.CNcomment:Բ\D0\C4x\D7\F8\B1\EA CNend
\param[in] y Vertical coordinate of the circle center.CNcomment:Բ\D0\C4y\D7\F8\B1\EA CNend
\param[in] r Radius.CNcomment:\B0뾶 CNend
\param[in] color Circle color. The circle is filled in with 32-bit colors.CNcomment:Բ\D1\D5ɫ, \D1\D5ɫ\B0\B4\D5\D532λɫ\BD\F8\D0\D0\CC\EE\B3\E4 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DrawCircle(HI_HANDLE Surface, HI_S32 x, HI_S32 y, HI_S32 r, HI_COLOR color);

/**
\brief Draws a rectangle.CNcomment:\BB\E6\D6ƾ\D8\D0\CE CNend
\attention \n
If the rectangle is empty, it indicates that the rectangle size is the same as surface.
Cropping is not supported; therefore, you must ensure that the entire rectangle is within the surface.
CNcomment:\BE\D8\D0\CEΪ\BFձ\EDʾ\CA\E4\B3\F6\BE\D8\D0δ\F3С\D3\EBsurface\CF\E0ͬ
\B2\BB֧\B3ֲü\F5\A3\ACʹ\D3\C3\D5߱\D8\D0뱣֤\D5\FB\B8\F6\BE\D8\D0\CE\D4\DAsurface\C7\F8\D3\F2\C4\DA CNend

\param[in] Surface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pRect Rectangle region.CNcomment:\BE\D8\D0\CE\C7\F8\D3\F2 CNend
\param[in] color Rectangle color.CNcomment:\BE\D8\D0\CE\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DrawRect(HI_HANDLE Surface, const HI_RECT* pRect, HI_COLOR color);

/**
\brief Performs the mask ROP or mask blend transfer on the raster bitmap.CNcomment:\B6Թ\E2դλͼ\BD\F8\D0\D0Mask Rop\BB\F2\D5\DFMask Blend\B0\E1\D2Ʋ\D9\D7\F7 CNend
\attention \n
The mask bitmap is in A1 or A8 format.
You need to overlay the mask bitmap with the source bitmap, overlay the result with the destination bitmap, and then
output the final result to the destination bitmap.
If the ROP and blending operation are perform at the same time, only the ROP takes effect.
CNcomment:Mask\CA\C7A1\BB\F2A8\B5\C4λͼSurface\A1\A3
\CA\D7\CFȽ\ABMaskλͼ\D3\EBԴλͼ\D7\F6һ\B4ε\FE\BCӣ\ACȻ\BA\F3\D3õ\FE\BCӵĽ\E1\B9\FB\BA\CDĿ\B1\EA\D7\F6\B5\FE\BC\D3\CA\E4\B3\F6\B5\BDĿ\B1\EAλͼ
Rop\BA\CDBlend\BB\EC\BA\CFͬʱֻ\C4\DC\D3\D0һ\B8\F6\CA\C7\D3\D0Ч\B5ģ\AC\C1\BD\D5߶\BCѡֻ\D3\D0Rop\C9\FAЧ CNend

\param[in] SrcSurface Source surface handle.CNcomment:Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect Source rectangle.CNcomment:Դ\BE\D8\D0\CE CNend
\param[in] DstSurface Destination surface handle.CNcomment:Ŀ\B1\EAsurface\BE\E4\B1\FA CNend
\param[in] pDstRect Destination rectangle.CNcomment:Ŀ\B1\EA\BE\D8\D0\CE CNend
\param[in] MaskSurface Mask surface handle.CNcomment:MASK surface\BE\E4\B1\FA CNend
\param[in] pMaskRect Mask rectangle.CNcomment:MASK\BE\D8\D0\CE CNend
\param[in] pOpt Operation option.CNcomment:\B2\D9\D7\F7ѡ\CF\EE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_INVRECT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_INTERNAL

\see \n
N/A. CNcomment:\CE\DE CNend
*/

HI_S32 HI_GO_MaskBlit(HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                      HI_HANDLE DstSurface, const HI_RECT* pDstRect,
                      HI_HANDLE MaskSurface, const HI_RECT* pMaskRect,
                      const HIGO_MASKOPT_S* pOpt);

/**
\brief Transfers bit blocks. During the transfer, CSC is supported.CNcomment:λ\BF\E9\B0\E1\D2ƣ\AC\D4ڰ\E1\D2ƹ\FD\B3\CC\D6У\AC\BF\C9\D2\D4ʵ\CF\D6ɫ\B2ʿռ\E4ת\BB\BB CNend
\attention \n
Only the YUV-to-RGB CSC is supported. \n
The operations of colorkey, alpha, ROP, and colorkey+ROP are supported.\
CNcomment: ɫ\B2ʿռ\E4ת\BB\BB\BD\F6֧\B3\D6YUV\B5\BDRGBת\BB\BB \n
\BF\C9\D2\D4֧\B3ֲ\D9\D7\F7\C8\E7\CF\C2colorkey\A1\A2alpha\A1\A2ROP\A1\A2colorkey+ROP\ CNend

\param[in] SrcSurface Source surface handle.CNcomment:Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect Source region for transfer. If the parameter is not set, it indicates the entire source surface.CNcomment:\B0\E1\D2Ƶ\C4Դ\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Դsurface\C7\F8\D3\F2 CNend
\param[in] DstSurface Destination surface handle.CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pDstRect Destination region for transfer. If the parameter is not set, it indicates the entire destination
surface.CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pBlitOpt Blending mode. If the parameter is not set, default settings are used. CNcomment:\BB\EC\BAϷ\BDʽ\A3\AC\B2\CE\CA\FDΪ\BF\D5ʹ\D3\C3Ĭ\C8ϲ\CE\CA\FD\B2\D9\D7\F7 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_BitBlit (HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                       HI_HANDLE DstSurface, const HI_RECT* pDstRect,
                       const HIGO_BLTOPT2_S* pBlitOpt);

/**
\brief Transfers bit blocks. During the transfer, CSC and scaling are supported. CNcomment:λ\BF\E9\B0\E1\D2ƣ\AC\D4ڰ\E1\D2ƹ\FD\B3\CC\D6У\AC\BF\C9\D2\D4ʵ\CF\D6ɫ\B2ʿռ\E4ת\BB\BB, \CB\F5\B7\C5 CNend
\attention \n
Only the YUV-to-RGB CSC is supported. \n
The operations of colorkey, alpha, ROP, and colorkey+ROP are supported.\
CNcomment:ɫ\B2ʿռ\E4ת\BB\BB\BD\F6֧\B3\D6YUV\B5\BDRGBת\BB\BB \n
\BF\C9\D2\D4֧\B3ֲ\D9\D7\F7\C8\E7\CF\C2colorkey\A1\A2alpha\A1\A2ROP\A1\A2colorkey+ROP\ CNend

\param[in] SrcSurface  Source surface handle. CNcomment:Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect Source region for transfer. If the parameter is not set, it indicates the entire source surface.CNcomment:\B0\E1\D2Ƶ\C4Դ\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Դsurface\C7\F8\D3\F2 CNend
\param[in] DstSurface Destination surface handle. CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pDstRect pDstRect Destination region for transfer. If the parameter is not set, it indicates the entire destination
surface. CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pBlitOpt Blending mode. If the parameter is not set, default settings are used. CNcomment:\BB\EC\BAϷ\BDʽ,\B2\CE\CA\FDΪ\BF\D5ʹ\D3\C3Ĭ\C8ϲ\CE\CA\FD\B2\D9\D7\F7 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_StretchBlit (HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                       HI_HANDLE DstSurface, const HI_RECT* pDstRect,
                       const HIGO_BLTOPT2_S* pBlitOpt);

/**
\brief  Fills in the pattern.CNcomment:\BD\F8\D0\D0ģʽ\CC\EE\B3\E4 CNend
\attention \n
\param[in] SrcSurface  Source surface handle. CNcomment:Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect  Source region for transfer. If the parameter is not set, it indicates the entire source surface.CNcomment:\B0\E1\D2Ƶ\C4Դ\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Դsurface\C7\F8\D3\F2 CNend
\param[in] DstSurface  Destination surface handle. CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pDstRect  Destination region for transfer. If the parameter is not set, it indicates the entire destination
surface.CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pParOpt  Blending mode. If the parameter is not set, default settings are used. CNcomment:\BB\EC\BAϷ\BDʽ,\B2\CE\CA\FDΪ\BF\D5ʹ\D3\C3Ĭ\C8ϲ\CE\CA\FD\B2\D9\D7\F7 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_PatternBlit(HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                              HI_HANDLE DstSurface, const HI_RECT * pDstRect,
                              const HIGO_BLTOPT2_S* pParOpt);

/**
\brief Performs anti-flicker and transfer. This API is used for the second anti-flicker.CNcomment:\BF\B9\C9\C1˸\B0\E1\D2ƣ\AC\D5\E2\B8\F6\BDӿ\DA\D3\C3\D3ڵڶ\FE\B4ο\B9\C9\C1˸\A3\ACCNend
\attention \n
This API is used in the following two application scenarios:
1. The automatic anti-flicker effect of a graphics layer is poor.
2. The buffer mode of a graphics layer is single-buffer mode (HIGO_LAYER_BUFFER_SINGLE). In this case, users need to
perform anti-flicker by themselves.
When the sizes of the source bitmap and destination bitmap are different, scaling is performed automatically.
CNcomment:\C1\BD\D6\D6\C7\E9\BF\F6\D3õ\BD\B8ýӿ\DA
1 \B5\B1ͼ\B2\E3\B5\C4\D7Զ\AF\BF\B9\C9\C1˸Ч\B9\FB\B2\BB\CAǺܺ\C3ʱ\A3\AC\BF\C9\D2\D4ʹ\D3\C3\D5\E2\B8\F6\BDӿ\DA\D4\D9\D7\F6һ\B4Ρ\A3
2 \B5\B1ͼ\B2\E3\B5\C4bufferģʽ\CAǵ\A5bufferģʽ(HIGO_LAYER_BUFFER_SINGLE)ʱ\A3\AC\D3û\A7\D0\E8Ҫ\D7Լ\BA\D7\F6\BF\B9\C9\C1˸\A3\AC
\B5\B1Դ\BA\CDĿ\B1\EA\B4\F3С\B2\BBͬ\B5\C4ʱ\BA\F2\D7Զ\AF\BD\F8\D0\D0\CB\F5\B7š\A3CNend

\param[in] SrcSurface  SrcSurface Source surface handle.CNcomment: Դsurface\BE\E4\B1\FA CNend
\param[in] pSrcRect  pSrcRect Source region for transfer. If the parameter is not set, it indicates the entire source surface.CNcomment:\B0\E1\D2Ƶ\C4Դ\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Դsurface\C7\F8\D3\F2 CNend
\param[in] DstSurface  DstSurface Destination surface handle. CNcomment:Ŀ\B5\C4surface\BE\E4\B1\FA CNend
\param[in] pDstRect  pDstRect Destination region for transfer. If the parameter is not set, it indicates the entire destination
surface. CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pDefOpt  pDefOpt Anti-flicker level. If this parameter is not set, it indicates the automatic level. CNcomment:\BF\B9\C9\C1˸\BC\B6\B1\F0ѡ\CFΪ\BFձ\EDʾAUTO \BC\B6\B1\F0 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DeflickerBlit(HI_HANDLE SrcSurface, const HI_RECT* pSrcRect,
                                 HI_HANDLE DstSurface, const HI_RECT * pDstRect,
                                 const HIGO_DEFLICKEROPT_S* pDefOpt);

/**
\brief Do the alpha blending between the forground surface and the backgroud surface, transfers the result to the destination surface. The background surface and the destination surface must be in the RGB color space.
You can performs color space coversion, scale, or mirror, colorkey with alpha blending.CNcomment:\B8ú\AF\CA\FDʵ\CF\D6ǰ\BE\B0\BAͱ\B3\BE\B0\B5\FE\BC\D3\CA\E4\B3\F6\B5\BDĿ\B1깦\C4ܣ\AC\B1\B3\BE\B0\BA\CDĿ\B1\EAsurface\B1\D8\D0\EBλ\D3\DARGB\BFռ䣬\D4ڵ\FE\BCӹ\FD\B3\CC\D6п\C9\D2Ը\BD\BC\D3\D1\D5ɫ\BFռ\E4ת\BB\BB\A1\A2\CB\F5\B7š\A2\BE\B5\CF\F1\B5Ȳ\D9\D7\F7\A3\AC\B2\BB֧\B3\D6\D0\FDת\A1\A3CNend
\attention \n
Only the YUV-to-RGB CSC is supported. \n
The operations of colorkey, alpha, ROP, and colorkey+ROP are supported, rotation is not supported.\
Scaling, and mirror cannot be combined. \n
For scaling, and mirror, the source and destination pixel formats must be the same, but the format cannot
be YUV or CLUT.\n
CNcomment:ɫ\B2ʿռ\E4ת\BB\BB\BD\F6֧\B3\D6YUV\B5\BDRGBת\BB\BB \n
\BF\C9\D2\D4֧\B3ֲ\D9\D7\F7\C8\E7\CF\C2colorkey\A1\A2alpha\A1\A2ROP\A1\A2colorkey+ROP\A3\AC\B2\BB֧\B3\D6\CB\F5\B7\C5\
\CB\F5\B7š\A2\BE\B5\CF񲻿\C9\D7\E9\BA\CFʹ\D3\C3 \n
\CB\F5\B7Ż\F2\BE\B5\CF\F1Ҫ\C7\F3Դ\D3\EBĿ\B1\EA\CF\F1\CBظ\F1ʽ\CD\EAȫ\CF\E0ͬ\A3\AC\B5\AB\B2\BB\C4\DC\CA\C7YUV\B8\F1ʽ\BA\CDCLUT\B8\F1ʽ \n CNend

\param[in] BckSurface background surface handle.CNcomment:\B1\B3\BE\B0surface\BE\E4\B1\FA CNend
\param[in] pBckRect backgound region for transfer. If the parameter is not set, it indicates the entire background surface.CNcomment:\B1\B3\BE\B0surface\B2\D9\D7\F7\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6\B1\B3\BE\B0surface\C7\F8\D3\F2 CNend
\param[in] ForSurface forground surface handle.CNcomment:ǰ\BE\B0surface\BE\E4\B1\FA CNend
\param[in] pForRect forground region for transfer. If the parameter is not set, it indicates the entire forground surface.
surface.CNcomment:ǰ\BE\B0surface\B2\D9\D7\F7\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6ǰ\BE\B0surface\C7\F8\D3\F2 CNend
\param[in] DstSurface destination surface handle.CNcomment:Ŀ\B1\EAsurface\BE\E4\B1\FA CNend
\param[in] pDstRect destination region for transfer. If the parameter is not set, it indicates the entire destination surface.
surface.CNcomment:\B0\E1\D2Ƶ\C4Ŀ\B5\C4\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\D5\FB\B8\F6Ŀ\B1\EAsurface\C7\F8\D3\F2 CNend
\param[in] pBlitOpt Blending mode.CNcomment:\BB\EC\BAϷ\BDʽ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVMIRRORTYPE
\retval ::HIGO_ERR_INVROTATETYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_INTERNAL

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_Blit3Source(HI_HANDLE BckSurface, const HI_RECT* pBckRect,
                   HI_HANDLE ForSurface, const HI_RECT* pForRect,
                   HI_HANDLE DstSurface, const HI_RECT* pDstRect,
                   const HIGO_BLTOPT_S* pBlitOpt);
/**
\brief Fills in a rounded rectangle.CNcomment:Բ\BDǾ\D8\D0\CE\CC\EE\B3\E4 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] Surface Surface handle.CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] pRect Size of the rectangle to be filled in. If the parameter is not set, it indicates that the entire
surface is filled in.CNcomment: \CC\EE\B3\E4\BE\D8\D0δ\F3С\A3\ACΪ\BFձ\EDʾ\CC\EE\B3\E4\D5\FB\B8\F6surface CNend
\param[in] Color Color Fill color. For the RGB format, 32-bit color is filled in; for the palette, the color index (0-255)
is filled in.CNcomment:\CC\EE\B3\E4\D1\D5ɫ,ע\D2\E2\C8\E7\B9\FB\CA\C7RGB\B8\F1ʽ\A3\ACͳһ\CC\EE\B3\E432λɫ\A3\AC\C8\E7\B9\FB\B5\F7ɫ\B0壬\BE\CDֱ\BD\D3\CC\EE\B3\E4\D1\D5ɫ\CB\F7\D2\FD(0 ~ 255)\A1\A3CNend
\param[in] s32Radius radius.CNcomment:Բ\BDǰ뾶 CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_OUTOFPAL
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\see \n
N/A. CNcomment:\CE\DE CNend
*/

HI_S32 HI_GO_FillRoundRect(HI_HANDLE Surface, const HI_RECT* pRect, HI_COLOR Color, HI_S32 s32Radius);

/** @} */  /*! <!-- API declaration end */

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_BLITER_H__ */
