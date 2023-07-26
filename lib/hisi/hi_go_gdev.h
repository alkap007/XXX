#ifndef __HI_GO_GDEV_H__
#define __HI_GO_GDEV_H__

#include "hi_go_comm.h"
#include "hi_go_surface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/

/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_GDEV */
/** @{ */  /** <!-- [HIGO_GDEV] */

/** Definition of the graphics layer ID*/
/** CNcomment:ͼ\B2\E3ID\B6\A8\D2\E5*/
typedef enum
{
    HIGO_LAYER_SD_0 = 0,
    HIGO_LAYER_SD_1,
    HIGO_LAYER_HD_0,
    HIGO_LAYER_HD_1,
    HIGO_LAYER_HD_2,
    HIGO_LAYER_HD_3,
    HIGO_LAYER_AD_0,
    HIGO_LAYER_AD_1,
    HIGO_LAYER_BUTT,
}HIGO_LAYER_E;

/**Standard-definition (SD) graphics layer 0*/
/** CNcomment:\B1\EA\C7\E5ͼ\D0ε\FE\BCӲ\E30 */
#define HIGO_LAYER_RGB0 HIGO_LAYER_SD_0

/**SD graphics layer 1*/
/** CNcomment:\B1\EA\C7\E5ͼ\D0ε\FE\BCӲ\E31 */
#define HIGO_LAYER_RGB1 HIGO_LAYER_SD_1

#define GRAPHICS_LAYER_MAX_NUM 4
/** The following macro defines the buffer mode of each graphics layer of the HiGo. The canvas buffer is used for drawing,
and the display buffer is used for display output.*/
/** CNcomment:\CF\C2\C3\E6\BA궨\D2\E5\C1\CBhigo\B5\C4ÿ\B8\F6ͼ\B2\E3\B5\C4bufferģʽ\A3\AC\C6\E4\D6\D0canvas buffer\CAǹ\A9\D3û\A7\BB\E6\D6Ƶ\C4buffer, display buffer\CA\C7\D3\C3\D3\DA\CF\D4ʾ\CA\E4\B3\F6\B5\C4buffer.*/
#define HIGO_LAYER_BUFFER_SINGLE      0x02 /**<One canvas buffer, and no display buffer*//**<CNcomment:1\BF\E9canvas buffer, \CE\DEdisplay buffer */
#define HIGO_LAYER_BUFFER_DOUBLE      0x04 /**<One canvas buffer, and one display buffer. Dual buffers are supported.*//**<CNcomment:1\BF\E9canvas buffer, 1\BF\E9display buffer ֧\B3\D6˫\BB\BA\B3\E5 */
#define HIGO_LAYER_BUFFER_TRIPLE      0x08 /**<One canvas buffer, and two display buffers. The flip function is supported.*//**<CNcomment:1\BF\E9canvas buffer, 2\BF\E9display buffer ֧\B3\D6flip,ˢ\D0µ\C4ʱ\BA\F2\B5ȴ\FD\C8\CE\CE\F1\CD\EA\B3\C9 */
#define HIGO_LAYER_BUFFER_OVER        0x10 /**<One canvas buffer, and two display buffers. The flip function is supported. If tasks are being performed during refresh, the current frame is discarded.*//**<CNcomment:1\BF\E9canvas buffer, 2\BF\E9display buffer ֧\B3\D6flip,\C8\E7\B9\FBˢ\D0µ\C4ʱ\BA\F2\B4\F8\D3\D0\C8\CE\CE\F1æ\A3\AC\D4\F2\B6\AA\C6\FA\B5\B1ǰ֡ */

/**Refresh mode of graphics layers for complying with old definitions. The mode is not recommended.*/
/** CNcomment:Ϊ\BC\E6\C8\DD\C0϶\A8\D2壬ͼ\B2\E3\B5\C4ˢ\D0·\BDʽ\A3\AC\B2\BB\BD\A8\D2\E9ʹ\D3\C3*/
typedef enum
{
    HIGO_LAYER_FLUSH_FLIP        = HIGO_LAYER_BUFFER_TRIPLE,
    HIGO_LAYER_FLUSH_DOUBBUFER   = HIGO_LAYER_BUFFER_DOUBLE,
    HIGO_LAYER_FLUSH_NORMAL      = HIGO_LAYER_BUFFER_SINGLE,
    HIGO_LAYER_FLUSH_OVER        = HIGO_LAYER_BUFFER_OVER,
    HIGO_LAYER_FLUSH_BUTT
} HIGO_LAYER_FLUSHTYPE_E;

/**Anti-flicker level, ranging from low to high. The higher the level, the better the anti-flicker effect, but the more blurred the picture.*/
/** CNcomment:\BF\B9\C9\C1˸\BC\B6\B1\F0\A3\ACֵΪLOW~HIGH,ֵԽ\B4\F3\BF\B9\C9\C1˸Ч\B9\FBԽ\BAã\AC\B5\ABԽģ\BA\FD*/
typedef enum
{
    HIGO_LAYER_DEFLICKER_NONE = 0,
    HIGO_LAYER_DEFLICKER_LOW,
    HIGO_LAYER_DEFLICKER_MIDDLE,
    HIGO_LAYER_DEFLICKER_HIGH,
    HIGO_LAYER_DEFLICKER_AUTO,
    HIGO_LAYER_DEFLICKER_BUTT
}HIGO_LAYER_DEFLICKER_E;

/**Frame encode format*/
/** CNcomment:֡\B1\E0\C2봫\CA\E4\B8\F1ʽ*/
typedef enum
{
    HIGO_ENCPICFRM_MONO   = 0x0,            /**<Normal display, no 3D TV*//**<CNcomment:\D5\FD\B3\A3\CA\E4\B3\F6\A3\AC\B7\C73D \B5\E7\CA\D3*/
    HIGO_ENCPICFRM_STEREO_SIDEBYSIDE_HALF,  /**< L/R frames are downscaled horizontally by 2 andpacked side-by-side into a single frame, left on lefthalf of frame*//**<CNcomment:\BD\ABL/R֡ˮƽ\CB\F5\B7ŵ\BD\B5\A5֡\D6\D0*/
    HIGO_ENCPICFRM_STEREO_TOPANDBOTTOM,     /**< L/R frames are downscaled vertically by 2 andpacked into a single frame, left on top*//**<CNcomment:\BD\ABL/R֡\B4\B9ֱ\CB\F5\B7ŵ\BD\B5\A5֡\D6\D0*/
    HIGO_ENCPICFRM_BUTT
}HIGO_ENCPICFRM_E;

/**3D STEREO mode*/
/** CNcomment:3D STEREOģʽ*/
typedef enum
{
    HIGO_STEREO_MODE_HW_FULL = 0x0,  /**< 3d stereo function use hardware and transfer full frame to vo, note: hardware doesn't support the mode if encoder picture delivery method is top and bottom */
    HIGO_STEREO_MODE_HW_HALF ,       /**< 3d stereo function use hardware and transfer half frame to vo*/
    HIGO_STEREO_MODE_SW_EMUL,        /**<3d stereo function use software emulation */
    HIGO_STEREO_MODE_BUTT
}HIGO_STEREO_MODE_E;

/**Layer attribute parameters*/
/** CNcomment:ͼ\B2\E3\CA\F4\D0Բ\CE\CA\FD*/
typedef struct
{
    HI_S32                 ScreenWidth;    /**<Height of a graphics layer on the screen. The value must be greater than 0.*//**<CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9\CF\CF\D4ʾ\BF\ED\B6ȣ\AC\B1\D8\D0\EB\B4\F3\D3\DA0 */
    HI_S32                 ScreenHeight;   /**<Width of a graphics layer on the screen. The value must be greater than 0.*//**<CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9\CF\CF\D4ʾ\B8߶ȣ\AC\B1\D8\D0\EB\B4\F3\D3\DA0 */
    HI_S32                 CanvasWidth;    /**<Width of the canvas buffer of a graphics layer. If the value is 0, no canvas buffer is created.*//**<CNcomment:ͼ\B2\E3\B5Ļ\E6\D6\C6buffer\BF\ED\B6ȣ\ACΪ0ʱ\A3\AC\B2\BB\B4\B4\BD\A8\BB\E6\D6\C6buffer */
    HI_S32                 CanvasHeight;   /**<Height of the canvas buffer of a graphics layer. If the value is 0, no canvas buffer is created.*//**<CNcomment:ͼ\B2\E3\B5Ļ\E6\D6\C6buffer\B8߶ȣ\ACΪ0ʱ\A3\AC\B2\BB\B4\B4\BD\A8\BB\E6\D6\C6buffer */
    HI_S32                 DisplayWidth;   /**<Width of the display buffer of a graphics layer. If the value is 0, the value of ScreenWidth is used.*//**<CNcomment:ͼ\B2\E3\B5\C4\CF\D4ʾbuffer\BF\ED\B6ȣ\ACΪ0ʱ\A3\AC\BA\CDScreenWidth\CF\E0ͬ*/
    HI_S32                 DisplayHeight;  /**<Height of the display buffer of a graphics layer. If the value is 0, the value of ScreenHeight is used.*//**<CNcomment:ͼ\B2\E3\B5\C4\CF\D4ʾbuffer\B8߶ȣ\ACΪ0ʱ\A3\AC\BA\CDScreenHeight\CF\E0ͬ*/
    HIGO_LAYER_FLUSHTYPE_E LayerFlushType; /**< Refresh mode of the layer. You can choose the refresh mode based on the actual scenario to improve the refresh efficiency. If the value is 0, the dual-buffer+flip refresh mode is used by default. *//**<CNcomment:ͼ\B2\E3\B5\C4ˢ\D0·\BDʽ\A3\AC\D3û\A7\BFɸ\F9\BE\DDʹ\D3ó\A1\BE\B0ѡ\D4\F1\B2\BBͬ\B5\C4ˢ\D0\C2ģʽ\C0\B4\CC\E1\B8\DFˢ\D0\C2Ч\C2\CA,\B5\C8\D3\DA0ʱĬ\C8\CFʹ\D3\C3˫\BB\BA\B3\E5+Flipˢ\D0\C2ģʽ */
    HIGO_LAYER_DEFLICKER_E AntiLevel;      /**<Anti-flicker level of a graphics layer*//**<CNcomment:ͼ\B2㿹\C9\C1˸\BC\B6\B1\F0 */
    HIGO_PF_E              PixelFormat;    /**<Pixel format of a graphics layer. The format must be supported by the hardware layer. You need to choose the pixel format parameters of the layer based on hardware devices.*//**<CNcomment:ͼ\B2\E3\B5\C4\CF\F1\CBظ\F1ʽ\A3\AC\B4˸\F1ʽ\B1\D8\D0\EBΪӲ\BC\FEͼ\B2\E3\CB\F9֧\B3ֵĸ\F1ʽ\A3\AC\C7\EB\B8\F9\BEݲ\BBͬӲ\BC\FE\C9豸\C0\B4ѡ\D4\F1ͼ\B2\E3\B5\C4\CF\F1\CBظ\F1ʽ\B2\CE\CA\FD */
    HIGO_LAYER_E           LayerID;        /**<Hardware ID of a graphics layer. The supported graphics layer depends on the chip platform. For example, the Hi3720 supports an HD graphics layer and an SD graphics layer.*//**<CNcomment:ͼ\B2\E3Ӳ\BC\FEID\A3\AC\C4\DC֧\B3\D6ͼ\B2\E3ȡ\BE\F6\D3\DAоƬƽ̨\A3\AC֧\B3\D6һ\B8\F6\B8\DF\C7\E5\BA\CDһ\B8\F6\B1\EA\C7\E5 */
} HIGO_LAYER_INFO_S;

/**Status of a graphics layer*/
/** CNcomment:ͼ\B2\E3״̬\BDṹ */
typedef struct
{
    HI_BOOL bShow;             /**<Whether to display a graphics layer.*//**<CNcomment:ͼ\B2\E3\CAǷ\F1\CF\D4ʾ */
} HIGO_LAYER_STATUS_S;

typedef struct
{
    HI_COLOR ColorKey;         /**<Transparency of a graphics layer*//**<CNcomment:ͼ\B2\E3\B5\C4͸\C3\F7ɫ*/
    HI_BOOL bEnableCK;         /**<Whether the colorkey of a graphics layer is enabled.*//**<CNcomment:ͼ\B2\E3\CAǷ\F1ʹ\C4\DCcolorkey */
}HIGO_LAYER_KEY_S;

typedef struct
{
    HI_BOOL bAlphaEnable;   /**<Alpha pixel enable flag*//**<CNcomment:alpha\CF\F1\CB\D8ʹ\C4ܱ\EA־ */
    HI_BOOL bAlphaChannel;  /**<Alpha channel enable flag*//**<CNcomment:alphaͨ\B5\C0ʹ\C4ܱ\EA־  */
    HI_U8   Alpha0;         /**<Alpha0 value. It is valid in ARGB1555 format.*//**<CNcomment:alpha0ֵ,\D4\DAARGB1555\B8\F1ʽ\CF\C2\C9\FAЧ */
    HI_U8   Alpha1;         /**<Alpha1 value. It is valid in ARGB1555 format.*//**<CNcomment:alpha1ֵ,\D4\DAARGB1555\B8\F1ʽ\CF\C2\C9\FAЧ */
    HI_U8   GlobalAlpha;    /**<Global alpha. This value is valid only when the alpha channel is valid.*//**<CNcomment:ȫ\BE\D6alpha\A3\AC\B8\C3ֵֻ\D3\D0\D4\DAalphaͨ\B5\C0\D3\D0Ч\B5\C4ʱ\BA\F2\B2\C5\D3\D0\D2\E2\D2\E5 */
}HIGO_LAYER_ALPHA_S;

typedef struct
{
    HI_HANDLE   Layer;          /** The layer the scrolltext want to show */
    HI_RECT       stScrollRect;   /** the position you wanted to show on the layer */
    HIGO_PF_E   ePixelFormat;    /** the color format of scrolltext content */
    HI_U16        u16CacheNum;       /** The cached buffer number for store scrolltext content */
    HI_U16        u16RefreshFreq;    /** The refresh frequency you wanted */
    HI_BOOL     bDeflicker;        /** Whether enable antificker */
} HIGO_SCROLLTEXT_ATTR_S;

typedef struct
{
    HI_U32 u32PhyAddr;   /** The physical address of the scrolltext content buffer */
    HI_U8  *pu8VirAddr;  /** The virtual address of the scrolltext content buffer */
    HI_U32 u32BufferLen; /** The virtual or physical address Length of the scrolltext content buffer */
    HI_U32 u32Stride;    /** The stride of the scrolltext content buffer */
} HIGO_SCROLLTEXT_DATA_S;



/** @} */  /*! <!-- Structure Definition end */

/********************** Global Variable declaration **************************/

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_GDEV */
/** @{ */  /** <!--[HIGO_GDEV] */

/**
\brief Initializes a display device. CNcomment:\B3\F5ʼ\BB\AF\CF\D4ʾ\C9豸 CNend
\attention \n
When ::HI_GO_Init is called, this API is also called.
CNcomment: ::HI_GO_Init\D2Ѱ\FC\BA\AC\C1˶Ըýӿڵĵ\F7\D3\C3 CNend
\param N/A. CNcomment:\CE\DE CNend

\retval ::HI_FAILURE
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INITFAILED

\see \n
::HI_GO_Init \n
::HI_GO_DeinitDisplay
*/
HI_S32 HI_GO_InitDisplay(HI_VOID);

/**
\brief Deinitializes a display device. CNcomment:ȥ\B3\F5ʼ\BB\AF\CF\D4ʾ\C9豸 CNend
\attention \n
When ::HI_GO_Deinit is called, this API is also called.
CNcomment: ::HI_GO_Deinit\D2Ѱ\FC\BA\AC\C1˶Ըýӿڵĵ\F7\D3\C3 CNend
\param N/A. CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_DEINITFAILED

\see \n
::HI_GO_Deinit \n
::HI_GO_InitDisplay
*/
HI_S32 HI_GO_DeinitDisplay(HI_VOID);

/**
\brief Obtains the default parameters of an SD or HD graphics layer based on its ID.
If you do not want to use default values, you can set the members of pLayerInfo.
CNcomment:\B8\F9\BE\DDͼ\B2\E3ID\BB\F1ȡ\CF\E0Ӧͼ\B2\E3(SD,HD)\B4\B4\BD\A8ʱ\B5\C4Ĭ\C8ϲ\CE\CA\FD\A3\AC
\C8\E7\B9\FB\D0\E8Ҫʹ\D3÷\C7Ĭ\C8\CFֵ\A3\AC\BF\C9\D2\D4ֱ\BD\D3\C9\E8\D6\C3pLayerInfo\B8\F7\B8\F6\B3\C9Ա CNend
\attention \n

\param[in] LayerID Layer ID. CNcomment:ͼ\B2\E3ID CNend
\param[in]  pLayerInfo Obtained parameters of a graphics layer when it is created. CNcomment:\BB\F1ȡ\B5\BD\B5Ĵ\B4\BD\A8\B2\CE\CA\FD CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVLAYERID
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVPARAM
\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetLayerDefaultParam (HIGO_LAYER_E LayerID, HIGO_LAYER_INFO_S *pLayerInfo);


/**
\brief Creates a graphics layer. CNcomment:\B4\B4\BD\A8ͼ\B2\E3 CNend
\attention \n
The platform determines whether VO hardware scaling is supported.
If VO hardware scaling is supported, the display size is scaled to fit the screen when the display size is inconsistent with the screen size.
If VO hardware scaling is not supported, the display size and screen size must be the same.
CNcomment:\CAǷ\F1֧\B3\D6VOӲ\BC\FE\CB\F5\B7\C5ȡ\BE\F6\D3\DAƽ̨\A1\A3
\C8\E7\B9\FBƽ̨֧\B3\D6VO Ӳ\BC\FE\CB\F5\B7ţ\AC\BC\B4\D4\DA\C9\E8\D6\C3displaysize\D3\EBscreensize\B2\BBһ\D6µ\C4\C7\E9\BF\F6\CF£\AC\D7\EE\D6ջ\E1\CB\F5\B7ŵ\BDscreensize\B5Ĵ\F3С\A1\A3
\C8\E7\B9\FBƽ̨\B2\BB֧\B3\D6VO Ӳ\BC\FE\CB\F5\B7ţ\AC\BC\B4ʹdisplaysize\D3\EBscreensize\B2\BBһ\D6£\ACҲ\BB\E1ǿ\D6\C6Ҫ\C7\F3displaysize\D3\EBscreensizeһ\D6\C2 CNend

\param[in]  pLayerInfo Basic attributes of a graphics layer. The value cannot be empty. CNcomment:ͼ\B2\E3\BB\F9\B1\BE\CA\F4\D0ԣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pLayer Pointer to the handle of a graphics layer. The value cannot be empty. CNcomment:ͼ\B2\E3\B5ľ\E4\B1\FAָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVSIZE
\retval ::HIGO_ERR_INVLAYERID
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INVFLUSHTYPE
\retval ::HIGO_ERR_INVANILEVEL
\retval ::HIGO_ERR_INVSIZE
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB
\retval ::HIGO_ERR_ALREADYBIND
\retval ::HIGO_ERR_INVLAYERSURFACE

\see \n
::HI_GO_DestroyLayer
*/
HI_S32 HI_GO_CreateLayer (const HIGO_LAYER_INFO_S *pLayerInfo, HI_HANDLE* pLayer);

/**
\brief Destroys a graphics layer. CNcomment:\CF\FA\BB\D9ͼ\B2\E3 CNend
\attention \n
If a graphics layer is in use (for example, the desktop based on the layer is not destroyed), the layer cannot be destroyed.
CNcomment:\B5\B1ͼ\B2\E3\D5\FD\D4ڱ\BBʹ\D3\C3ʱ\A3\A8\C0\FD\C8\E7\BB\F9\D3ڴ\CBͼ\B2\E3\B5\C4\D7\C0\C3\E6δ\CF\FA\BB٣\A9\A3\AC\D4\F2ͼ\B2\E3\CE޷\A8\B1\BB\CF\FA\BB\D9 CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE


\see \n
::HI_GO_CreateLayer
*/
HI_S32 HI_GO_DestroyLayer(HI_HANDLE Layer);


/**
\brief Sets the position of a graphics layer on the screen. CNcomment:\C9\E8\D6\C3ͼ\B2\E3\D4\DA\C6\C1Ļ\D6е\C4λ\D6\C3 CNend
\attention \n
The value takes effect at once and you do not need to refresh it. If the start position of a layer exceeds the screen, it is automatically adjusted to the boundary of the screen.
CNcomment:\C1\A2\BC\B4\C9\FAЧ\A3\AC\CE\DE\D0\E8ˢ\D0¡\A3\B5\B1\C9\E8\D6õ\C4ͼ\B2\E3\B5\C4\C6\F0ʼλ\D6ó\AC\B3\F6\C6\C1Ļ\B7\B6Χʱ\BB\E1\D7Զ\AF\B5\F7\D5\FB\D6\C1\C6\C1Ļ\B5ı߽\E7ֵ CNend
\param[in] Layer  Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] u32StartX Horizontal coordinate of the position where a layer appears on the screen. CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9ϵ\C4\CF\D4ʾλ\D6\C3X\D7\F8\B1\EA CNend
\param[in] u32StartY Vertical coordinate of the position where a layer appears on the screen. CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9ϵ\C4\CF\D4ʾλ\D6\C3Y\D7\F8\B1\EA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVLAYERPOS
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_GetLayerPos
*/
HI_S32 HI_GO_SetLayerPos(HI_HANDLE Layer, HI_U32 u32StartX, HI_U32 u32StartY);

/**
\brief Obtains the position where a layer appears on the screen. CNcomment:\BB\F1ȡͼ\B2\E3\D4\DA\C6\C1Ļ\C9ϵ\C4λ\D6\C3 CNend
\attention \n
N/A. CNcomment:\CE\DE CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pStartX Pointer of the horizontal coordinate of the position where a layer appears on the screen. The value cannot be empty. CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9ϵ\C4\CF\D4ʾλ\D6\C3X\D7\F8\B1\EAָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pStartY Pointer of the vertical coordinate of the position where a layer appears on the screen. The value cannot be empty. CNcomment:ͼ\B2\E3\D4\DA\C6\C1Ļ\C9ϵ\C4\CF\D4ʾλ\D6\C3Y\D7\F8\B1\EAָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_SetLayerPos
*/
HI_S32 HI_GO_GetLayerPos(HI_HANDLE Layer, HI_U32 *pStartX, HI_U32 *pStartY);


/**
\brief Sets the output height and width of a graphics layer on the display device. CNcomment:\C9\E8\D6\C3\D4\DA\CA\E4\B3\F6\CF\D4ʾ\C9豸\C9ϵ\C4\CA\E4\B3\F6\B5ĸ߶ȺͿ\ED\B6\C8 CNend
\attention \n
This API supports zoom in operations. The maximum range is specified when a graphics layer is created.\n
CNcomment:\D4\DA\C4ڴ\E6֧\B3ֵ\C4ǰ\CC\E1\CF£\AC\B8ýӿڿ\C9\D2\D4֧\B3\D6\CB\F5\B7\C5 CNend

\param[in]  Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] u32SWidth  Actual output width. CNcomment:ʵ\BC\CA\CA\E4\B3\F6\BF\ED\B6\C8 CNend
\param[in] u32SHeight Actual output height. CNcomment:ʵ\BC\CA\CA\E4\B3\F6\B8߶\C8 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVSIZE
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_GetScreenSize
*/
HI_S32 HI_GO_SetScreenSize(HI_HANDLE Layer, HI_U32 u32SWidth, HI_U32 u32SHeight);


/**
\brief Obtains the output height and width of a graphics layer on the display device. CNcomment:\BB\F1ȡ\D4\DA\CA\E4\B3\F6\CF\D4ʾ\C9豸\C9ϵ\C4\CA\E4\B3\F6\B5ĸ߶ȺͿ\ED\B6ȡ\A3CNend
\attention \n
N/A. CNcomment:\CE\DE CNend
\param[in]  Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pSWidth  Pointer to the actual output width. CNcomment:ʵ\BC\CA\CA\E4\B3\F6\BF\ED\B6\C8ָ\D5\EB CNend
\param[out] pSHeight Pointer to the actual output height. CNcomment:ʵ\BC\CA\CA\E4\B3\F6\B8߶\C8ָ\D5\EB CNend
\retval none
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_SetScreenSize
*/
HI_S32 HI_GO_GetScreenSize(HI_HANDLE Layer, HI_U32 *pSWidth, HI_U32 *pSHeight);

/**
\brief Sets the global alpha value of a layer surface. CNcomment:\C9\E8\D6\C3ͼ\B2\E3surface\B5\C4ȫ\BE\D6alphaֵ CNend
\attention \n
The value takes effect at once, and you do not need to refresh it.
CNcomment:\C1\A2\BC\B4\C9\FAЧ\A3\AC\CE\DE\D0\E8ˢ\D0\C2 CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] Alpha Global alpha value. The value cannot be empty and ranges from 0 to 255. CNcomment:Alpha ȫ\BE\D6alphaֵ\A3\AC\B2\BB\BF\C9Ϊ\BFգ\AC\B7\B6Χ0-255 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_SETALPHAFAILED
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_GetLayerAlpha
*/

HI_S32 HI_GO_SetLayerAlpha(HI_HANDLE Layer, HI_U8 Alpha);

/**
\brief Sets layer premul state. CNcomment:\C9\E8\D6\C3Ԥ\B3\CB״̬ CNend
\attention \n
The value takes effect at once, and you do not need to refresh it.
CNcomment:\C1\A2\BC\B4\C9\FAЧ\A3\AC\CE\DE\D0\E8ˢ\D0\C2 CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] enable or disable layer premu. CNcomment:\C9\E8\D6\C3Ԥ\B3\CB״̬CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE

\see \n
::HI_GO_SetLayerPreMul
*/
HI_S32 HI_GO_SetLayerPreMul(HI_HANDLE Layer, HI_BOOL bPreMul);


/**
\brief Obtains the global alpha value of a layer surface. CNcomment:\BB\F1ȡͼ\B2\E3surface\B5\C4ȫ\BE\D6alphaֵ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pAlpha Pointer to the global alpha value. CNcomment:ȫ\BE\D6alphaָ\D5\EB CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_SetLayerAlpha
*/
HI_S32 HI_GO_GetLayerAlpha(HI_HANDLE Layer, HI_U8* pAlpha);


/**
\brief Obtains the surface of a graphics layer. CNcomment:\BB\F1ȡͼ\B2\E3\B5\C4surface CNend
\attention \n
Surface of a graphics layer. It cannot be released by calling HI_GO_FreeSurface. The surface can be released only when the corresponding layer is destroyed.
After a process is switched, you must obtain the layer surface again by calling HI_S32 HI_GO_GetLayerSurface.
CNcomment:ͼ\B2\E3surface\A3\AC\B2\BB\C4\DCʹ\D3\C3HI_GO_FreeSurface\C0\B4\CAͷš\A3ֻ\D3\D0\D4\DA\CF\FA\BB\D9ͼ\B2\E3\B5\C4ʱ\BA\F2\B2Żᱻ\CAͷ\C5
\BD\F8\B3\CC\C7л\BB֮\BA\F3\B1\D8\D0\EB\B5\F7\D3øýӿ\DA\C0\B4\D6\D8\D0»\F1ȡͼ\B2\E3surface; CNend
\param[in] Layer handle. CNcomment:Layer ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pSurface Pointer to the surface handle. The value cannot be empty. CNcomment:surface\BE\E4\B1\FAָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVLAYERSURFACE
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_DEPEND_FB

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetLayerSurface(HI_HANDLE Layer, HI_HANDLE *pSurface);

/**
\brief Shows or hides a graphics layer. CNcomment:\CF\D4ʾ\BB\F2\D2\FE\B2\D8ͼ\B2\E3 CNend
\attention \n
The value takes effect at once, and you do not need to refresh it.
CNcomment:\C1\A2\BC\B4\C9\FAЧ\A3\AC\CE\DE\D0\E8ˢ\D0\C2 CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] bVisbile Show/hide flag. HI_TRUE: show; HI_FALSE: hide. CNcomment:\CF\D4ʾ\D2\FE\B2ر\EA־\A1\A3HI_TRUE\A3\BA\CF\D4ʾ\A3\BBHI_FALSE\A3\BA\D2\FE\B2\D8 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_GetLayerStatus
*/
HI_S32 HI_GO_ShowLayer(HI_HANDLE Layer, HI_BOOL bVisbile);

/**
\brief Obtains the current status of a graphics layer. CNcomment:\BB\F1ȡͼ\B2㵱ǰ״̬ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pLayerStatus Pointer to the current status of a graphics layer. The value cannot be empty. CNcomment:ͼ\B2㵱ǰ״̬\BDṹָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_ShowLayer
*/
HI_S32 HI_GO_GetLayerStatus(HI_HANDLE Layer, HIGO_LAYER_STATUS_S* pLayerStatus);

/**
\brief Refreshes a graphics layer. CNcomment:ˢ\D0\C2ͼ\B2\E3 CNend
\attention \n
1. After drawing, you need to refresh the layer to display the drawing result.
2. There are two display modes after a graphics layer is refreshed. If there is no window, the contents of the layer surface are displayed; if there is a window, its contents are displayed.
CNcomment:1.\BB\E6\D6\C6\CD\EA\B3ɺ\F3\A3\AC\D0\E8ˢ\D0\C2ͼ\B2\E3\B2\C5\C4\DC\CF\D4ʾ\BB\E6\D6ƺ\F3\BD\E1\B9\FB
2.ˢ\D0\C2\D3\D0\C1\BD\D6\D6ģʽ\A3\ACһ\D6\D6\CA\C7û\D3\D0\C8κδ\B0\BFڵ\C4ʱ\BA\F2\BE\CD\CF\D4ʾlayersurface\B5\C4\C4\DA\C8ݣ\AC\B7\F1\D4\F2\CF\D4ʾ\B4\B0\BF\DA\D6е\C4\C4\DA\C8ݡ\A3CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in]  pRect Rectangle to be refreshed. If the value is NULL, the entire screen is refreshed. CNcomment:ˢ\D0µľ\D8\D0\CE\C7\F8\D3\F2\A3\AC\C8\E7\B9\FB\CA\C7NULL, \D4\F2ˢ\D0\C2\D5\FB\B8\F6ȫ\C6\C1 CNend
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVLAYERSURFACE
\retval ::HIGO_ERR_DEPEND_FB
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_EMPTYRECT

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_RefreshLayer(HI_HANDLE Layer, const HI_RECT* pRect);


/**
\brief Sets the canvas buffer of a graphics layer. CNcomment:\C9\E8\D6ò\E3\B5\C4canvas surface. CNend
\attention \n
If the stream sources of the HD and SD graphics layer are the same, the canvas buffer of the SD graphics layer can be shared with the HD graphics layer.
CNcomment:\B8\DF\C7\E5\BAͱ\EA\C7\E5ͬԴʱ\A3\AC\CE\D2\C3ǿ\C9\D2\D4\C8ñ\EA\C7\E5\B5\C4canvas buffer\D3\EB\B8\DF\C7\E5\B5Ĺ\B2\CF\EDͬһ\B8\F6
     Surrface\B5\C4\C4ڴ\E6\C0\E0\D0ͱ\D8\D0\EB\CA\C7MMZ\C0\E0\D0͵\C4. CNend
\param[in] Layer     Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] hSurface  Surface of a graphics layer. If the value is INVALID_HANDLE, there is no user handle. CNcomment:ͼ\B2\E3\B5\C4surface\A3\AC\C8\E7\B9\FB\B8ò\CE\CA\FDΪINVALID_HANDLE\B1\EDʾû\D3\D0\D3û\A7\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVLAYERSURFACE
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INVPARAM

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetLayerSurface(HI_HANDLE Layer, HI_HANDLE hSurface);



/**
\brief Sets the background color of a graphics layer. CNcomment:\C9\E8\D6\C3ͼ\B2\E3\B5ı\B3\BE\B0\D1\D5ɫ CNend
\attention \n
The background color of a graphics layer takes effect only when widows are overlaid with each other.
CNcomment:ͼ\B2㱳\BE\B0ɫ\A3\ACֻ\D3\D0\D4ڵ\FE\BCӴ\B0\BFڲ\C5\D3\D0Ч CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] Color Background color of a graphics layer. CNcomment:ͼ\B2㱳\BE\B0\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetLayerBGColor(HI_HANDLE Layer, HI_COLOR Color);

/**
\brief Obtains the background color of a graphics layer. CNcomment:\BB\F1ȡͼ\B2\E3\B5ı\B3\BE\B0\D1\D5ɫ CNend
\attention \n
This API is available only when there are windows on graphics layers. Otherwise, the configured background color does not take effect.
CNcomment:\B4˽ӿ\DAֻ\D3\D0\D4\DAͼ\B2\E3\C9\CF\D3д\B0\BFڵ\C4ʱ\BA\F2\B2Ż\E1\D3\D0Ч\A1\A3\B7\F1\D4\F2\B8\C3\D1\D5ɫ\C9\E8\D6\C3\CE\DEЧ\A1\A3CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] pColor Used for storing the background color of a graphics layer. CNcomment:\B4洢ͼ\B2㱳\BE\B0\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A. CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetLayerBGColor(HI_HANDLE Layer, HI_COLOR* pColor);

/**
\brief Sets the size of a display buffer. CNcomment:\C9\E8\D6\C3\CF\D4ʾbuffer size CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer      Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] u32DWidth     Pointer to the width. CNcomment:\BF\ED\B6\C8ָ\D5\EB CNend
\param[in] u32DHeight    Pointer to the height. CNcomment:\B8߶\C8ָ\D5\EB CNend
\param[out] N/A . CNcomment:\CE\DE  CNend

\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVSIZE
\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
    ::HI_GO_GetDisplaySize
*/
HI_S32 HI_GO_SetDisplaySize(HI_HANDLE Layer, HI_U32 u32DWidth, HI_U32 u32DHeight);

/**
\brief Obtains the size of a display buffer. CNcomment:\BB\F1ȡ\CF\D4ʾbuffer\B5\C4size CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer      Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] pDWidth    Pointer to the width. The value cannot be empty. CNcomment:\BF\ED\B6\C8ָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5  CNend
\param[in] pDHeight   Pointer to the height. The value cannot be empty. CNcomment:\B8߶\C8ָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] N/A. CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE

\see \n
    ::HI_GO_SetDisplaySize
*/
HI_S32 HI_GO_GetDisplaySize(HI_HANDLE Layer, HI_U32 *pDWidth, HI_U32 *pDHeight);

/**
\brief Sets the refresh mode. CNcomment:\C9\E8\D6\C3ˢ\D0\C2\C0\E0\D0\CD CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer         Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] FlushType     Refresh mode of a graphics layer. CNcomment:ͼ\B2\E3ˢ\D0\C2\C0\E0\D0\CD CNend
\param[out] N/A. CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVFLUSHTYPE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetFlushType
*/
HI_S32 HI_GO_SetFlushType(HI_HANDLE Layer, HIGO_LAYER_FLUSHTYPE_E FlushType);

/**
\brief Obtains the refresh mode. CNcomment:\BB\F1ȡˢ\D0\C2\C0\E0\D0\CD CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA  CNend
\param[in] *pFlushType Refresh mode of a graphics layer. The value cannot be empty. CNcomment:ͼ\B2\E3ˢ\D0\C2\C0\E0\D0ͣ\AC\B2\BB\BF\C9Ϊ\BF\D5  CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetFlushType
*/
HI_S32 HI_GO_GetFlushType(HI_HANDLE Layer, HIGO_LAYER_FLUSHTYPE_E *pFlushType);

/**
\brief Sets the transparency of a graphics layer. CNcomment:\C9\E8\D6\C3ͼ\B2\E3\B5\C4͸\C3\F7ɫ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA  CNend
\param[in] pKey        Pointer to the transparency information. The value cannot be empty. CNcomment:͸\C3\F7ɫ\D0\C5Ϣָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetLayerColorkey
*/
HI_S32 HI_GO_SetLayerColorkey(HI_HANDLE Layer, const HIGO_LAYER_KEY_S *pKey);

/**
\brief Obtains the transparency information about a graphics layer. CNcomment:\BB\F1ȡ͸\C3\F7ɫ\D0\C5Ϣ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] pKey        Pointer to the transparency information. CNcomment:͸\C3\F7ɫ\D0\C5Ϣָ\D5\EB CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetLayerColorkey
*/
HI_S32 HI_GO_GetLayerColorkey(HI_HANDLE Layer, HIGO_LAYER_KEY_S *pKey);

/**
\brief Sets the palette of a graphics layer. CNcomment:\C9\E8\D6\C3ͼ\B2\E3\B5ĵ\F7ɫ\B0\E5 CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] Palette     Palette of a graphics layer. CNcomment:ͼ\B2\E3\B5\F7ɫ\B0\E5 CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetLayerPalette
*/
HI_S32 HI_GO_SetLayerPalette(HI_HANDLE Layer, const HI_PALETTE Palette);

/**
\brief Obtains the palette of a graphics layer. CNcomment:\BB\F1ȡͼ\B2\E3\B5\F7ɫ\B0\E5 CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] Palette     Palette of a graphics layer. CNcomment:ͼ\B2\E3\B5\F7ɫ\B0\E5 CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetLayerPalette
*/
HI_S32 HI_GO_GetLayerPalette(HI_HANDLE Layer, HI_PALETTE Palette);

/**
\brief Waits for the blanking area. CNcomment:\B5ȴ\FD\CF\FB\D2\FE\C7\F8 CNend
\attention \n
N/A
CNcomment:\CE\DE  CNend
\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA  CNend
\param[out] N/A. CNcomment:\CE\DE  CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetLayerPalette
*/
HI_S32 HI_GO_WaitForBlank(HI_HANDLE Layer);


/**
\brief Configures the alpha information about a graphics layer. This API is an extended API. CNcomment:\C9\E8\D6\C3ͼ\B2\E3alpha\D0\C5Ϣ\A3\AC\C0\A9չ\BDӿ\DA CNend
\attention \n
The alpha0 and alpha1 of the data structure HIGO_LAYER_ALPHA_S are valid only in ARGB1555 format.
This API is used to implement the translucent effect in ARGB1555 format.
CNcomment:\B8ýӿ\DAHIGO_LAYER_ALPHA_S\BDṹ\CC\E5\B5\C4alpha0,alpha1ֻ\D4\DAARGB1555\B8\F1ʽ\CF²\C5\D3\D0Ч\A3\AC
\D3\C3\D3\DA\D4\DAARGB1555\B8\F1ʽ\CF\C2ʵ\CFְ\EB͸\C3\F7Ч\B9\FB CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] pAlphaInfo   Alpha information about a graphics layer. The value cannot be empty. CNcomment:ͼ\B2\E3alpha\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] N/A.

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_FB

\see \n
::HI_GO_GetLayerAlphaEx
*/
HI_S32 HI_GO_SetLayerAlphaEx(HI_HANDLE Layer,  HIGO_LAYER_ALPHA_S *pAlphaInfo);


/**
\brief Obtains the alpha information about a graphics layer. This API is an extended API. CNcomment:\BB\F1ȡͼ\B2\E3alpha\D0\C5Ϣ\A3\AC\C0\A9չ\BDӿ\DA CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pAlphaInfo  Alpha information about a graphics layer. The value cannot be empty. CNcomment:ͼ\B2\E3alpha\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetLayerAlphaEx
*/
HI_S32 HI_GO_GetLayerAlphaEx(HI_HANDLE Layer,  HIGO_LAYER_ALPHA_S *pAlphaInfo);

/**
\brief set the Z order of graphics layer in the sample display. CNcomment:\B8ı\E4ͬһ\CF\D4ʾ\C9豸\C9\CFͼ\D0β\E3\B5\C4Z\D0\F2\A1\A3CNend
\attention \n
this function make effect imediately. CNcomment:\B8ù\A6\C4\DC\D0\E8ҪӲ\BC\FE֧\B3\D6Z\D0\F2\B5\C4\D0޸ģ\AC\C1\A2\BC\B4\C9\FAЧ\A3\AC\CE\DE\D0\E8ˢ\D0\C2 CNend
\param[in] Layer Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA  CNend
\param[in] ZFlag zorder flag. CNcomment:\D0޸\C4Z\D0\F2\B1\EA־ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVORDERFLAG
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_CANNOTCHANGE

\see \n
::HI_GO_GetLayerZorder
*/
HI_S32 HI_GO_SetLayerZorder(HI_HANDLE Layer, HIGO_ZORDER_E enZOrder);

/**
\brief get the Z order of graphics layer in the sample display. CNcomment:\BB\F1ȡͬһ\CF\D4ʾ\C9豸\C9\CFͼ\D0β\E3\B5\C4Z\D0\F2\A1\A3CNend
\attention \n
CNcomment:Z\D0\F2ԽС\B5\C4ͼ\B2\E3Խ\BF\BF\CF\C2 CNend
\param[in] Layer    Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA  CNend
\param[out] pZOrder Z Order Information. CNcomment:ͼ\B2\E3Z\D0\F2\D0\C5Ϣ\A1\A3CNend


\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_ChangeLayerZorder
*/
HI_S32 HI_GO_GetLayerZorder(HI_HANDLE Layer, HI_U32* pu32ZOrder);

/**
\brief Sets frame input encode mode of a graphic layer. CNcomment:\C9\E8\D6\C3ͼ\D0β\E3\CA\E4\C8\EB3D\B8\F1ʽ\A3\AC\CA\E4\B3\F6\B8\F1ʽ\D7Զ\AF\B8\FA\CB\E6VO\BD\F8\D0\D0\C9\E8\D6á\A3CNend
\attention \n
MONO is the default mode.
CNcomment:Ĭ\C8\CFΪMONO\B8\F1ʽ\A3\AC\BC\B4\C6\D5ͨ\B7\C73D Stereo\B8\F1ʽ. CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] EncPicFrm  Frame encode mode.The value cannot be empty. CNcomment:ͼ\B2\E3֡\B4\AB\CA\E4\B1\E0\C2\EB\B8\F1ʽ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetStereoMode
*/
HI_S32 HI_GO_SetStereoMode(HI_HANDLE Layer,  HIGO_STEREO_MODE_E InputEnc);



/**
\brief Obtains frame encode mode of a graphic layer. CNcomment:\BB\F1ȡͼ\D0β\E33D\B8\F1ʽ\A1\A3CNend
\attention \n
CNcomment:\CE\DE CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pInputEnc  Frame encode mode.The value cannot be empty. CNcomment:ͼ\B2\E3֡\B4\AB\CA\E4\B1\E0\C2\EB\B8\F1ʽ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetStereoMode
*/
HI_S32 HI_GO_GetStereoMode(HI_HANDLE Layer,  HIGO_STEREO_MODE_E *pInputEnc);


/**
\brief set the 3d depth, only support depth in Horizontal . CNcomment:\C9\E8\D6þ\B0\C9\EE,ֻ֧\B3\D6ˮƽ\B7\BD\CF\F2\BE\B0\C9\EE CNend
\attention \n
CNcomment:\CE\DE CNend

\param[in]  Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] StereoDepth  3D depth. CNcomment:\BE\B0\C9\EE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetStereoDepth
*/
HI_S32 HI_GO_SetStereoDepth(HI_HANDLE Layer,  HI_S32  s32StereoDepth);


/**
\brief get the 3d depth, only support depth in Horizontal . CNcomment:\BB\F1ȡ\BE\B0\C9\EE,ֻ֧\B3\D6ˮƽ\B7\BD\CF\F2\BE\B0\C9\EE CNend
\attention \n
CNcomment:\CE\DE CNend

\param[in]  Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pStereoDepth  3D depth. CNcomment:\BE\B0\C9\EE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetStereoDepth
*/
HI_S32 HI_GO_GetStereoDepth(HI_HANDLE Layer,  HI_S32  *ps32StereoDepth);

/**
\brief Sets compress mode of a graphic layer. CNcomment:\C9\E8\D6\C3ʹ\C4\DCѹ\CB\F5ģʽ CNend
\attention \n
When compress is enable, only HIGO_PF_8888 is supported;SD layer and  STEREO TOPANDBOTTOM
are also not supported.
CNcomment:ֻ֧\B3\D6\CF\F1\CBظ\F1ʽΪHIGO_PF_8888\A3\AC\B2\BB֧\B3ֱ\EA\C7\E5\BA\CD3D STEREO TOPANDBOTTOMģʽ CNend

\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[in] StereoMode  Stereo mode, the value cannot be empty. CNcomment:ѹ\CB\F5ʹ\C4ܣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_GetStereoMode
*/
HI_S32 HI_GO_SetCompression(HI_HANDLE Layer,  HI_BOOL bEnable);


/**
\brief Sets compress mode of a graphic layer. CNcomment:\BB\F1ȡѹ\CB\F5ģʽ\CAǷ\F1ʹ\C4\DC CNend
\attention \n
N/A. CNcomment:\CE\DE CNend
\param[in] Layer       Layer handle. CNcomment:ͼ\B2\E3\BE\E4\B1\FA CNend
\param[out] pbEnable  Stereo mode, the value cannot be empty. CNcomment:ѹ\CB\F5ʹ\C4ܣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_SetStereoMode
*/
HI_S32 HI_GO_GetCompression(HI_HANDLE Layer,  HI_BOOL* pbEnable);

/**
\brief Create ScrollText. CNcomment:\B4\B4\BD\A8\B9\F6\B6\AF\D7\D6Ļ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] pstScrollAttr  ScrollText attribute,the value cannot be empty. CNcomment:\B9\F6\B6\AF\D7\D6Ļ\CA\F4\D0\D4 CNend
\param[out] phScrollText  ScrollText handle. CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5\C4\CA\E4\B3\F6\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_DEPEND_FB
\retval ::HIGO_ERR_DEPEND_FB
\retval ::HIGO_ERR_INVSURFACEPF
\retval ::HIGO_ERR_INUSE

\see \n
    ::HI_GO_CreateScrollText
*/
HI_S32 HI_GO_CreateScrollText(HIGO_SCROLLTEXT_ATTR_S * pstScrollAttr, HI_HANDLE * phScrollText);


/**
\brief Fill data to ScrollText cache buffer. CNcomment:\CF\F2\B9\F6\B6\AF\D7\D6Ļ\CB\CD\C8\EB\CA\FD\BE\DD CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] hScrollText  ScrollText handle.     CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5ľ\E4\B1\FA CNend
\param[out] pstScrollData ScrollText data information. CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5\C4\CA\FD\BE\DD\D0\C5Ϣ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_FB
\retval ::HIGO_ERR_INVHANDLE

\see \n
    ::HI_GO_FillScrollText
*/
HI_S32 HI_GO_FillScrollText(HI_HANDLE hScrollText, HIGO_SCROLLTEXT_DATA_S * pstScrollData);


/**
\brief Pause the ScrollText. CNcomment:\D4\DDͣ\B9\F6\B6\AF\D7\D6Ļ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] hScrollText  ScrollText handle.   CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5ľ\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_PauseScrollText
*/
HI_S32  HI_GO_PauseScrollText(HI_HANDLE hScrollText);


/**
\brief Resume the ScrollText,the ScrollText has Paused. CNcomment:\BBָ\B4\D2\D1\D4\DDͣ\B5Ĺ\F6\B6\AF\D7\D6Ļ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] hScrollText  ScrollText handle.  CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5ľ\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_ResumeScrollText
*/
HI_S32  HI_GO_ResumeScrollText(HI_HANDLE hScrollText);


/**
\brief Destroy ScrollText. CNcomment:\CF\FA\BBٹ\F6\B6\AF\D7\D6Ļ CNend
\attention \n
N/A. CNcomment:\CE\DE CNend

\param[in] hScrollText ScrollText handle.  CNcomment:\B9\F6\B6\AF\D7\D6Ļ\B5ľ\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_DEPEND_FB

\see \n
    ::HI_GO_DestoryScrollText
*/
HI_S32  HI_GO_DestoryScrollText(HI_HANDLE hScrollText);
/** @} */  /*! <!-- API declaration end */

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_GDEV_H__ */
