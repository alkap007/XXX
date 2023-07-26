#ifndef __HI_GO_SURFACE_H__
#define __HI_GO_SURFACE_H__

#include "hi_go_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/
/** \addtogroup      HIGO_SURFACE */
/** @{ */  /** <!-- [HIGO_SURFACE] */

typedef enum
{
    HIGO_PF_CLUT8 = 0,  /**<Palette*//**<CNcomment:\B5\F7ɫ\B0\E5 */
    HIGO_PF_CLUT1,
    HIGO_PF_CLUT4,
    HIGO_PF_4444,       /**<Each pixel occupies 16 bits, and the A/R/G/B components each occupies 4 bits. They are sorted by address in descending order.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ16bit\A3\ACARGBÿ\B7\D6\C1\BFռ4bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0 */
    HIGO_PF_0444,       /**<Each pixel occupies 16 bits, and the A/R/G/B components each occupies 4 bits. They are sorted by address in descending order. The A component does not take effect.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ16bit\A3\ACARGBÿ\B7\D6\C1\BFռ4bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0, A\B7\D6\C1\BF\B2\BB\C6\F0\D7\F7\D3\C3 */

    HIGO_PF_1555,       /**<Each pixel occupies 16 bits, the R/G/B components each occupies 5 bits, and the A component occupies 1 bit. They are sorted by address in descending order.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ16bit\A3\ACRGBÿ\B7\D6\C1\BFռ5bit\A3\ACA\B7\D6\C1\BF1bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0 */
    HIGO_PF_0555,       /**<Each pixel occupies 16 bits, the R/G/B components each occupies 5 bits, and the A component occupies 1 bit. They are sorted by address in descending order. The A component does not take effect.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ16bit\A3\ACRGBÿ\B7\D6\C1\BFռ5bit\A3\ACA\B7\D6\C1\BF1bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0, A\B7\D6\C1\BF\B2\BB\C6\F0\D7\F7\D3\C3 */
    HIGO_PF_565,        /**<Each pixel occupies 16 bits, and the R/G/B components each occupies 5 bits, 6 bits, and 5 bits respectively. They are sorted by address in descending order.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ16bit\A3\ACRGBÿ\B7\D6\C1\BF\B7ֱ\F0ռ5bit\A1\A26bit\BA\CD5bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0 */
    HIGO_PF_8565,       /**<Each pixel occupies 24 bits, and the A/R/G/B components each occupies 8 bits, 5 bits, 6 bits, and 5 bits respectively. They are sorted by address in descending order.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ24bit\A3\ACARGBÿ\B7\D6\C1\BF\B7ֱ\F0ռ8bit, 5bit\A1\A26bit\BA\CD5bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0 */
    HIGO_PF_8888,       /**<Each pixel occupies 32 bits, and the A/R/G/B components each occupies 8 bits. They are sorted by address in descending order.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ32bit\A3\ACARGBÿ\B7\D6\C1\BFռ8bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1\D0 */
    HIGO_PF_0888,       /**<Each pixel occupies 24 bits, and the A/R/G/B components each occupies 8 bits. They are sorted by address in descending order. The A component does not take effect.*//**<CNcomment:һ\B8\F6\CF\F1\CB\D8ռ24bit\A3\ACARGBÿ\B7\D6\C1\BFռ8bit\A3\AC\B0\B4\B5\D8ַ\D3ɸ\DF\D6\C1\B5\CD\C5\C5\C1У\ACA\B7\D6\C1\BF\B2\BB\C6\F0\D7\F7\D3\C3 */

    HIGO_PF_YUV400,     /**<Semi-planar YUV 400 format defined by HiSilicon*//**<CNcomment:\BA\A3˼\B6\A8\D2\E5\B5\C4semi-planar YUV 400\B8\F1ʽ */
    HIGO_PF_YUV420,     /**<Semi-planar YUV 420 format defined by HiSilicon*//**<CNcomment:\BA\A3˼\B6\A8\D2\E5\B5\C4semi-planar YUV 420\B8\F1ʽ */
    HIGO_PF_YUV422,     /**<Semi-planar YUV 422 format and horizontal sampling format defined by HiSilicon*//**<CNcomment:\BA\A3˼\B6\A8\D2\E5\B5\C4semi-planar YUV 422\B8\F1ʽ  ˮƽ\B2\C9\D1\F9\B8\F1ʽ*/
    HIGO_PF_YUV422_V,   /**<Semi-planar YUV 422 format and vertical sampling format defined by HiSilicon*//**<CNcomment:\BA\A3˼\B6\A8\D2\E5\B5\C4semi-planar YUV 422\B8\F1ʽ  \B4\B9ֱ\B2\C9\D1\F9\B8\F1ʽ*/
    HIGO_PF_YUV444,     /**<Semi-planar YUV 444 format defined by HiSilicon*//**<CNcomment:\BA\A3˼\B6\A8\D2\E5\B5\C4semi-planar YUV 444\B8\F1ʽ */

	HIGO_PF_A1,
	HIGO_PF_A8,

    HIGO_PF_YUV888,
    HIGO_PF_YUV8888,
	HIGO_PF_RLE8,
    HIGO_PF_BUTT
} HIGO_PF_E;
/** @} */  /*! <!-- Macro Definition end */

/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_SURFACE */
/** @{ */  /** <!-- [HIGO_SURFACE] */

/**Component type*/
/** CNcomment:\B7\D6\C1\BF\C0\E0\D0\CD */
typedef enum
{
    HIGO_PDFORMAT_RGB = 0,
    HIGO_PDFORMAT_RGB_PM,   /**< pre-multiplied */
    HIGO_PDFORMAT_Y,
    HIGO_PDFORMAT_UV,
    HIGO_PDFORMAT_UV_LE,

    HIGO_PDFORMAT_BUTT
} HIGO_PDFORMAT_E;

typedef struct
{
    HIGO_PDFORMAT_E Format;     /**<Component type*//**<CNcomment:\B7\D6\C1\BF\C0\E0\D0\CD */
    HI_VOID*        pData;      /**<Pointer to the virtual address of a component*//**<CNcomment:\B7\D6\C1\BF\D0\E9\C4\E2\B5\D8ַָ\D5\EB */
    HI_VOID*        pPhyData;   /**<Pointer to the physical address of a component*//**<CNcomment:\B7\D6\C1\BF\CE\EF\C0\ED\B5\D8ַָ\D5\EB */
    HI_U32          Pitch;      /**<Component pitch*//**<CNcomment:\B7\D6\C1\BF\D0п\ED */
    HI_U32          Bpp;        /**<Bytes per pixel*//**<CNcomment:bytes per pixel */
    HI_U32          Offset;
} HIGO_PIXELDATA_S;

/**Maximum number of data components*/
/** CNcomment:\D7\EE\B4\F3\CA\FD\BEݷ\D6\C1\BF\CA\FD */
#define MAX_PARTPIXELDATA 3

/**The following sync modes can be used together. The non-automatic sync mode is also available.*/
/** CNcomment:\CF\C2\C3\E6ͬ\B2\BDģʽ\BF\C9\D2\D4\D7\E9\BA\CFʹ\D3ã\AC\B2\BB\D7Զ\AFͬ\B2\BD\B7\BDʽ\D3\D0\D3\C3 */
typedef enum
{
    HIGO_SYNC_MODE_CPU = 0x01, /*Sync mode. In this mode, CPU operations are required.*//**<CNcomment:ͬ\B2\BD\A3\AC\CF\C2һ\B2\BD\D0\E8Ҫ\BD\F8\D0\D0CPU\B2\D9\D7\F7*/
    HIGO_SYNC_MODE_TDE = 0x02, /*Sync mode. In this mode, the 2D acceleration operation is required.*//**<CNcomment:ͬ\B2\BD\A3\AC\CF\C2һ\B2\BD\D0\E8Ҫ\BD\F8\D0\D02D\BC\D3\CBٲ\D9\D7\F7*/
    HIGO_SYNC_MODE_BUTT,
} HIGO_SYNC_MODE_E;


typedef enum
{
    HIGO_MEMTYPE_MMZ = 0,       /**<The memory is an media memory zone (MMZ) memory.*//**<CNcomment:ʹ\D3\C3MMZ\C4ڴ\E6\BD\F8\D0д\B4\BD\A8 */
    HIGO_MEMTYPE_OS,            /**<The memory is an operating system (OS) memory.*//**<CNcomment:ʹ\D3\C3ϵͳ\C4ڴ\E6\BD\F8\D0д\B4\BD\A8 */
    HIGO_MEMTYPE_BUTT
}HIGO_MEMTYPE_E;

typedef enum
{
	HIGO_OWNER_USER = 0,        /**<The memory is managed by users. That is, the memory is allocated and destroyed by users.*//**<CNcomment:\D3\C9\D3û\A7\BD\F8\D0й\DC\C0\ED\A3\AC\D0\E8Ҫ\D3û\A7\D7\D4\D0з\D6\C5\E4\C4ڴ棬\CF\FA\BB\D9\C4ڴ\E6 */
	HIGO_OWNER_HIGO,            /**<The memory is managed by the HiGo module rather than users.*//**<CNcomment:\D3\C9HIGO\BD\F8\D0й\DC\C0\ED\A3\AC\D3û\A7\B2\BB\D0\E8Ҫ\B9\DC\C0\ED\C4ڴ\E6 */
	HIGO_OWNER_BUTT
}HIGO_OWNER_E;

typedef struct
{
    HI_S32 Width;                               /**<Surface width*//**<CNcomment:surface\BF\ED\B6\C8 */
    HI_S32 Height;                              /**<Surface height*//**<CNcomment:surface\B8߶\C8 */
    HIGO_PF_E PixelFormat;                      /**<Pixel format of a surface*//**<CNcomment:surface\CF\F1\CBظ\F1ʽ*/
    HI_U32   Pitch[MAX_PARTPIXELDATA];          /**<Pitch of a surface*//**<CNcomment:surface\D0м\E4\BE\E0\C0\EB*/
    HI_CHAR* pPhyAddr[MAX_PARTPIXELDATA];       /**<Physical address of a surface*//**<CNcomment:surface\CE\EF\C0\ED\B5\D8ַ*/
    HI_CHAR* pVirAddr[MAX_PARTPIXELDATA];       /**<Virtual address of a surface*//**<CNcomment:surface\D0\E9\C4\E2\B5\D8ַ*/
    HIGO_MEMTYPE_E MemType;                     /**<Type of the surface memory*//**<CNcomment:surface\C4ڴ\E6\C0\E0\D0\CD*/
    HI_BOOL bPubPalette;                        /**<Use common Palette or not*//**<CNcomment:\CAǷ\F1ʹ\D3ù\AB\B9\B2\B5\F7ɫ\B0\E5;ֻ\B6\D4Clut\B8\F1ʽ\D3\D0Ч.
                                                    \C8\F4\B2\BBʹ\D3ù\AB\B9\B2\B5ĵ\F7ɫ\B0\E5,\D4\F2ʹ\D3\C3\D7Դ\F8\B5ĵ\F7ɫ\B0\E5*/
}HIGO_SURINFO_S;

typedef struct
{
    HI_S32 Width;                               /**<Surface width*//**<CNcomment:surface\BF\ED\B6\C8 */
    HI_S32 Height;                              /**<Surface height*//**<CNcomment:surface\B8߶\C8 */
    HIGO_PF_E PixelFormat;                      /**<Pixel format of a surface*//**<CNcomment:surface\CF\F1\CBظ\F1ʽ*/

    /**<Pitch of a surface
    Pitch[0] indicates the pitch in RGB format or the pitch of the Y component in semi-planar format.
     Pitch[1] indicates the pitch of the C component in semi-planar format.
     Pitch[2] is reserved.*/
    /**<CNcomment:surface\D0м\E4\BE\E0\C0룬
     Pitch[0]\B1\EDʾRGB\B8\F1ʽ\D0м\E4\BE࣬ \BB\F2\D5\DFSemi-planner\B5\C4Y\B7\D6\C1\BF\B5\C4\D0м\E4\BE\E0
     Pitch[1]\B1\EDʾSemi-planner\B5\C4C\B7\D6\C1\BF\B5\C4\D0м\E4\BE\E0
     Pitch[2]\D4\DDʱ\B2\BBʹ\D3á\A3*/
    HI_U32   Pitch[MAX_PARTPIXELDATA];

    /**<Physical address of a surface
    pPhyAddr[0] indicates the physical address in RGB format or the physical address of the Y component in semi-planar format.
    pPhyAddr[1] indicates the physical address of the C component in semi-planar format.*/
    /**<CNcomment:surface\CE\EF\C0\ED\B5\D8ַ
    pPhyAddr[0]\B1\EDʾRGB\B8\F1ʽ\CE\EF\C0\ED\B5\D8ַ\A3\AC \BB\F2\D5\DFSemi-planner\B5\C4Y\B7\D6\C1\BF\B5\C4\CE\EF\C0\ED\B5\D8ַ
    pPhyAddr[1]\B1\EDʾSemi-planner\B5\C4C\B7\D6\C1\BF\B5\C4\CE\EF\C0\ED\B5\D8ַ*/
    HI_CHAR* pPhyAddr[MAX_PARTPIXELDATA];

    /**<Virtual address of a surface
    pVirAddr[0] indicates the virtual address in RGB format or the virtual address of the Y component in semi-planar format.
    pVirAddr[1] indicates the virtual address of the C component in semi-planar format.*/
    /**<CNcomment:surface\D0\E9\C4\E2\B5\D8ַ
    pVirAddr[0]\B1\EDʾRGB\B8\F1ʽ\D0\E9\C4\E2\B5\D8ַ\A3\AC \BB\F2\D5\DFSemi-planner\B5\C4Y\B7\D6\C1\BF\B5\C4\D0\E9\C4\E2\B5\D8ַ
    pVirAddr[1]\B1\EDʾSemi-planner\B5\C4C\B7\D6\C1\BF\B5\C4\D0\E9\C4\E2\B5\D8ַ*/
    HI_CHAR* pVirAddr[MAX_PARTPIXELDATA];       /**<CNcomment: surface\D0\E9\C4\E2\B5\D8ַ
                                                     pVirAddr[0]\B1\EDʾRGB\B8\F1ʽ\D0\E9\C4\E2\B5\D8ַ\A3\AC \BB\F2\D5\DFSemi-planner\B5\C4Y\B7\D6\C1\BF\B5\C4\D0\E9\C4\E2\B5\D8ַ
                                                     pVirAddr[1]\B1\EDʾSemi-planner\B5\C4C\B7\D6\C1\BF\B5\C4\D0\E9\C4\E2\B5\D8ַ
                                                */
    HIGO_MEMTYPE_E MemType;                     /**<Type of the surface memory*//**<CNcomment:surface\C4ڴ\E6\C0\E0\D0\CD*/
    HI_BOOL bPubPalette;        /**<Use common Palette or not*//**<CNcomment:\CAǷ\F1ʹ\D3ù\AB\B9\B2\B5\F7ɫ\B0\E5;ֻ\B6\D4Clut\B8\F1ʽ\D3\D0Ч*/
    HIGO_OWNER_E   MemOwner;                    /**<Memory source. For example, the memory is allocated by users or the HiGo module.*//**<CNcomment:\C4ڴ\E6\B5\C4\C0\B4Դ,\C0\FD\C8\E7\CA\C7\D3û\A7\B7\D6\C5\E4,\BB\B9\CA\C7HIGO\B7\D6\C5\E4*/
}HIGO_SURINFOEX_S;

/**Data component structure*/
/** CNcomment:\CA\FD\BEݷ\D6\C1\BF\BDṹ */
typedef HIGO_PIXELDATA_S HI_PIXELDATA[MAX_PARTPIXELDATA];

/** @} */  /*! <!-- Structure Definition end */

/********************** Global Variable declaration **************************/

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_SURFACE */
/** @{ */  /** <!-- [HIGO_SURFACE] */

/**
\brief Initializes the surface module. CNcomment:\B3\F5ʼ\BB\AFSurface CNend
\attention \n
When ::HI_GO_Init is called, this API is also called.
CNcomment: ::HI_GO_Init\D2Ѿ\AD\B0\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param N/A

\retval ::HI_SUCCESS
\retval ::HI_FAILURE

\see \n
::HI_GO_DeinitSurface
*/
HI_S32 HI_GO_InitSurface(HI_VOID);

/**
\brief Deinitializes the surface module. CNcomment:ȥ\B3\F5ʼ\BB\AFSurface CNend
\attention \n
When ::HI_GO_Deinit is called, this API is also called.
CNcomment: ::HI_GO_Deinit\D2Ѿ\AD\B0\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param N/A

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT

\see \n
::HI_GO_InitSurface
*/
HI_S32 HI_GO_DeinitSurface(HI_VOID);

/**
\brief Sets the alpha value of a surface. CNcomment:\C9\E8\D6\C3surface\B5\C4alphaֵ CNend
\attention \n
N/A
\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[in]  Alpha Alpha value, ranging from 0 to 255. The value 0 indicates transparent, and the value 255 indicates opaque. CNcomment:Alphaֵ\A3\AC\B7\B6Χ\CA\C70-255\A1\A30\B1\EDʾ͸\C3\F7\A3\AC255\B1\EDʾ\B2\BB͸\C3\F7 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_GetSurfaceAlpha
*/
HI_S32 HI_GO_SetSurfaceAlpha(HI_HANDLE Surface, HI_U8 Alpha);

/**
\brief Obtains the alpha value of a surface. CNcomment:\BB\F1ȡsurface\B5\C4alphaֵ CNend
\attention \n
N/A
\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out] pAlpha Pointer to the received alpha value. The pointer cannot be null. CNcomment:\BD\D3\CA\D5alhpaֵ\B5Ŀռ\E4ָ\D5룬\B2\BB\C4\DCΪ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
::HI_GO_SetSurfaceAlpha
*/
HI_S32 HI_GO_GetSurfaceAlpha(HI_HANDLE Surface, HI_U8* pAlpha);

/**
\brief Enables or disables the colorkey of a surface. CNcomment:\C9\E8\D6\C3\CAǷ\F1ʹ\C4\DCsurface\B5\C4colorkey CNend
\attention \n
N/A
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] Enable Colorkey enable. HI_TRUE: enabled; HI_FALSE: disabled. CNcomment:\CAǷ\F1ʹ\C4\DCcolorKey\A1\A3HI_TRUE\A3\BAʹ\C4ܣ\BBHI_FALSE\A3\BA\B2\BBʹ\C4\DC CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A
*/
HI_S32 HI_GO_EnableSurfaceColorKey(HI_HANDLE Surface, HI_BOOL Enable);

/**
\brief Sets the colorkey value of a surface. CNcomment:\C9\E8\D6\C3surface\B5\C4colorKeyֵ CNend
\attention \n
N/A
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] ColorKey Colorkey value. For the RGB format, the colorkey is padded with 32-bit colors. For the CLUT format, the colorkey is padded with color index. CNcomment:Colorkeyֵ, \C8\E7\B9\FB\CA\C7RGB\B8\F1ʽ\BE\CDʹ\D3\C3ȫ\B2\BF\B0\B4\D5\D532bit\C0\B4\BD\F8\D0\D0\CC\EE\B3䣬\C8\E7\B9\FB\CA\C7CLUT\B8\F1ʽ\BE\CDʹ\D3\C3\D1\D5ɫ\CB\F7\D2\FD\C0\B4\CC\EE\B3䡣CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_GetSurfaceColorKey
*/
HI_S32 HI_GO_SetSurfaceColorKey(HI_HANDLE Surface, HI_COLOR ColorKey);

/**
\brief Obtains the colorkey value of a surface. CNcomment:\BB\F1ȡsurface\B5\C4colorkeyֵ CNend
\attention \n
N/A
\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out] pColorKey Pointer to the received colorkey value. The value cannot be empty. CNcomment:\BD\D3\CA\D5colorkeyֵ\B5Ŀռ\E4ָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_NOCOLORKEY

\see \n
::HI_GO_SetSurfaceColorKey
*/
HI_S32 HI_GO_GetSurfaceColorKey(HI_HANDLE Surface, HI_COLOR* pColorKey);

/**
\brief Sets the palette of a surface. CNcomment:\C9\E8\D6\C3Surface\B5ĵ\F7ɫ\B0\E5 CNend
\attention \n
N/A
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] Palette Palette. CNcomment:\B5\F7ɫ\B0\E5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVSURFACEPF

\see \n
::HI_GO_GetSurfaceColorKey
*/
HI_S32 HI_GO_SetSurfacePalette(HI_HANDLE Surface, const HI_PALETTE Palette);

/**
\brief Obtains the palette of a surface. CNcomment:\BB\F1ȡsurface\B5ĵ\F7ɫ\B0\E5 CNend
\attention \n
N/A
\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out] Palette Pointer to the received palette. CNcomment:\BD\D3\CAյ\F7ɫ\B0\E5\B5Ŀռ\E4ָ\D5\EB CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVSURFACEPF

\see \n
::HI_GO_SetSurfacePalette
*/
HI_S32 HI_GO_GetSurfacePalette(HI_HANDLE Surface, HI_PALETTE Palette);

/**
\brief Locks a surface and obtains its memory pointer. CNcomment:\CB\F8\B6\A8surface\A3\AC\BB\F1ȡ\C6\E4\C4ڴ\E6ָ\D5\EB CNend
\attention \n
Before accessing a surface, you need to call the API to lock the surface.\n
You cannot lock the same surface repeatedly.
CNcomment:\B7\C3\CE\CAsurface\C4\DA\C8\DDǰ\D0\E8Ҫ\B5\F7\D3øýӿ\DA\CB\F8\B6\A8surface \n
\B2\BB\C4ܶ\D4ͬһsurface\D6ظ\B4\CB\F8\B6\A8 CNend
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out] pData Pixel format information related to memory accessing. CNcomment:\D3\EB\C4ڴ\E6\B7\C3\CE\CA\CF\E0\B9ص\C4\CF\F1\CBظ\F1ʽ\D0\C5Ϣ CNend
\param[in] bSync  Synchronization. CNcomment:\CAǷ\F1ͬ\B2\BD CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_LOCKED

\see \n
::HI_GO_UnlockSurface
*/
HI_S32 HI_GO_LockSurface(HI_HANDLE Surface, HI_PIXELDATA pData, HI_BOOL bSync);


/**
\brief Unlocks a surface. CNcomment:\BD\E2\CB\F8\B6\A8surface CNend
\attention \n
After accessing a surface, you need to call the API to unlock it.
CNcomment:\B6\D4surface\C4\DA\C8ݷ\C3\CEʽ\E1\CA\F8\BA\F3\A3\ACҪ\BC\B0ʱ\B5\F7\D3øýӿڽ\E2\CB\F8\B6\A8surface CNend
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NOTLOCKED

\see \n
::HI_GO_LockSurface
*/
HI_S32 HI_GO_UnlockSurface(HI_HANDLE Surface);

/**
\brief Obtains the dimensions of a surface. CNcomment:\BB\F1ȡsurface\B3ߴ\E7 CNend
\attention \n
pWidth and pHeight cannot be empty concurrently.
CNcomment:pWidth\D3\EBpHeight\B2\BB\C4\DCͬʱΪ\BF\D5 CNend
\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out]  pWidth Width output address of a surface. The value cannot be empty. CNcomment:Surface\BF\ED\B6\C8\CA\E4\B3\F6\B5\D8ַ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out]  pHeight Height output address of a surface. The value cannot be empty. CNcomment:Surface\B8߶\C8\CA\E4\B3\F6\B5\D8ַ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_GetSurfaceSize(HI_HANDLE Surface, HI_S32* pWidth, HI_S32* pHeight);

/**
\brief Obtains the pixel format of a surface. CNcomment:\BB\F1ȡsurface\CF\F1\CBظ\F1ʽ CNend
\attention \n
N/A
\param[in]  Surface Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out] pPixelFormat Output address of the pixel format. The value cannot be empty. CNcomment:\CF\F1\CBظ\F1ʽ\CA\E4\B3\F6\B5\D8ַ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_GetSurfacePixelFormat(HI_HANDLE Surface, HIGO_PF_E* pPixelFormat);

/**
\brief Encapsulates the user memory into a surface. CNcomment:\BD\AB\D3û\A7\B5\C4\C4ڴ\E6\B7\E2װ\B3\C9surface CNend
\attention \n
All the attributes of pSurInfo must be correct. The supported input pixel formats include RGB format, CLUT8 format, and YUV semi-planar format.
CNcomment:pSurInfo\CB\F9\D3\D0\CA\F4\D0Զ\BC\B1\D8\D0\EB\C9\E8\D6\C3\D5\FDȷ,֧\B3\D6\CA\E4\C8\EB\B5\C4\CF\F1\CBظ\F1ʽΪRGB\B8\F1ʽ\A3\ACclut8\B8\F1ʽ\A3\AC\D2Լ\B0YUV semi-planner\B8\F1ʽ\A1\A3CNend

\param[in]  pSurInfo User memory information. The value cannot be empty. CNcomment:\D3û\A7\C4ڴ\E6\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pSurface Handle information. The value cannot be empty. CNcomment:\BE\E4\B1\FA\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVSURFACESIZE
\retval ::HIGO_ERR_INVSURFACEPF
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NOMEM

\see \n
N/A
*/
HI_S32 HI_GO_CreateSurfaceFromMem(const HIGO_SURINFO_S *pSurInfo, HI_HANDLE * pSurface);

/**
\brief Creates a memory surface. CNcomment:\B4\B4\BD\A8\C4ڴ\E6surface CNend
\attention \n
The surface in the format of ::HIGO_PF_CLUT1, ::HIGO_PF_CLUT4, ::HIGO_PF_YUV420, or ::HIGO_PF_YUV422 cannot be created.
CNcomment:\B2\BB\C4ܴ\B4\BD\A8::HIGO_PF_CLUT1\A1\A2::HIGO_PF_CLUT4\A1\A2::HIGO_PF_YUV420\A1\A2::HIGO_PF_YUV422\B8\F1ʽ\B5\C4surface CNend

\param[in] Width Surface width. CNcomment:Surface\BF\ED\B6\C8 CNend
\param[in] Height Surface height. CNcomment:Surface\B8߶\C8 CNend
\param[in] PixelFormat Surface pixel format. CNcomment:Surface\CF\F1\CBظ\F1ʽ CNend
\param[out] pSurface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVSURFACESIZE
\retval ::HIGO_ERR_INVSURFACEPF
\retval ::HIGO_ERR_NOMEM

\see \n
::HI_GO_FreeSurface
*/
HI_S32 HI_GO_CreateSurface(HI_S32 Width, HI_S32 Height, HIGO_PF_E PixelFormat, HI_HANDLE* pSurface);

/**
\brief Creates a child surface that shares the same memory with its parent surface. CNcomment:\B4\B4\BD\A8\D7\D3surface\A3\AC\D7\D3surface\D3\EB\C6丸surface\B9\B2\CF\EDͬһ\BF\E9\C4ڴ\E6 CNend
\attention \n
N/A

\param[in] Surface Parent surface handle. CNcomment:\B8\B8surface\BE\E4\B1\FA CNend
\param[in] pRect Region of the child surface in the parent surface. The value cannot be empty. CNcomment:\D7\D3surface\D4ڸ\B8surface\D6е\C4\C7\F8\D3򣬲\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pSubSurface Child surface handle. The value cannot be empty. CNcomment:\D7\D3surface\BE\E4\B1\FA\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_NOMEM

\see \n
::HI_GO_FreeSurface
*/
HI_S32 HI_GO_CreateSubSurface(HI_HANDLE Surface, const HI_RECT *pRect, HI_HANDLE* pSubSurface);


/**
\brief Destroys a surface. CNcomment:\CF\FA\BB\D9surface CNend
\attention \n
N/A
\param[in] Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INUSE

\see \n
::HI_GO_CreateSurface \n
::HI_GO_DecImgData
*/
HI_S32 HI_GO_FreeSurface(HI_HANDLE Surface);


/**
\brief Controls whether to synchronize the drawing operations based on a surface. CNcomment: \D4\CA\D0\ED\D5\EB\B6\D4surface\B5Ļ\E6ͼ\B2\D9\D7\F7\CAǷ\F1\D0\E8Ҫ\D7Զ\AFͬ\B2\BD\A1\A3CNend
\attention \n
When a surface is created, the operations based on the surface are synchronized by default. The synchronization indicates that you can draw graphics by using the two-dimensional engine (TDE) only after the contents in the cache drawn by the CPU are
     updated to the surface memory. In addition, you can draw graphics by using the CPU only after the TDE completes the drawing operation.
     This API is applicable to all the operations related to the surface.
CNcomment:surface\B4\B4\BD\A8ʱ\A3\ACĬ\C8\CF\CA\C7\D7Զ\AFͬ\B2\BD\B5ġ\A3ͬ\B2\BD\B5\C4\D2\E2˼\CA\C7: ʹ\D3\C3TDE\BB\E6\D6\C6֮ǰ\A3\AC\D0\E8Ҫ\B5\C8CPU\B5Ļ\E6\D6\C6\D4\DAcache\B5\C4\C4\DA\C8\DD\n
     \B8\FC\D0µ\BDsurface\B5\C4\C4ڴ\E6\D6У\ACʹ\D3\C3CPU\BB\E6\D6\C6֮ǰ\A3\AC\D0\E8Ҫ\B5\C8TDE\BB\E6\D6\C6\CD\EA\B3ɡ\A3
     \B8ýӿڶ\D4\CB\F9\D3\D0surface\B5Ĳ\D9\D7\F7\B6\BC\C9\FAЧ\A1\A3 CNend

\param[in] hSurface Surface handle, not used. CNcomment:Surface\BE\E4\B1\FA\A3\AC\B8ú\AF\CA\FD\C4\DA\D4\DDʱû\D3\D0\D3õ\BD CNend
\param[in] bAutoSync Automatic sync enable. CNcomment:\CAǷ\F1\D7Զ\AF\B6\AF\B2\BD CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A
*/
HI_S32 HI_GO_EnableSurfaceAutoSync(HI_HANDLE hSurface, HI_BOOL bAutoSync);



/**
\brief Synchronizes the operations performed on a surface. In this way, the contents drawn by the CPU or TDE are updated to the surface memory.
CNcomment:ͬ\B2\BDsurface,ͬ\B2\BD\D2\E2\D2\E5\D4\DA\D3ڱ\A3֤CPU\BB\F22D\BC\D3\CB\D9Ӳ\BC\FE\BB\E6\D6\C6\C4\DA\C8\DD\D2Ѿ\AD\B8\FC\D0µ\BDsurface\B5\C4\C4ڴ\E6\D6\D0 CNend
\attention \n
If you disable the automatic sync function by calling ::HI_GO_EnableSurfaceAutoSync, you need to synchronize the operations by calling HI_S32 HI_GO_SyncSurface when drawing graphics using the TDE or CPU.
Otherwise, an error occurs during drawing.
CNcomment:\C8\E7\B9\FB\B5\F7\D3\C3::HI_GO_EnableSurfaceAutoSync\BD\FBֹ\D7Զ\AF\B6\AF\B2\BD\A3\AC\D4\F2\D4\DAʹ\D3\C3TDE\BB\F2CPU\BB\E6\D6\C6ʱ\A3\AC\B5\F7\D3øú\AF\CA\FD\B1\A3֤ͬ\B2\BD\A3\AC\n
\B7\F1\D4\F2\BB\E6\D6ƽ\AB\B2\BB\D5\FDȷ\A1\A3CNend
\param[in] hSurface Surface handle, not used. CNcomment:Surface\BE\E4\B1\FA\A3\AC\D4\DDʱ\CE\DE\D3\C3 CNend
\param[in] mode Sync mode. For details, see the description of ::HIGO_SYNC_MODE_E. CNcomment:ͬ\B2\BDģʽ\A3\AC\B2ο\BC::HIGO_SYNC_MODE_E CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A
*/
HI_S32 HI_GO_SyncSurface(HI_HANDLE hSurface, HIGO_SYNC_MODE_E mode);


/**
\brief Sets the name of a surface. After setting the surface name, you can view the internal information about the surface (such as memory usage, width, height, and pixel format) by running cat /proc/higo in the command line window.
CNcomment:\C9\E8\D6\C3surface\B5\C4\C3\FB\D7֣\ACͨ\B9\FD\C9\E8\D6\C3surface\C3\FB\D7֣\AC\D4\DA\C3\FC\C1\EE\D0\D0\CA\E4\C8\EB cat /proc/higo \BF\C9\D2Բ鿴\B5\BD\B8\C3surface
\B5\C4\C4ڲ\BF\D0\C5Ϣ\A3\AC\B0\FC\C0\A8\C4ڴ\E6ռ\D3ã\AC\BF\ED\B8ߣ\AC\CF\F1\CBظ\F1ʽ CNend
\attention \n
The name contains a maximum of 16 characters including the end character '/0'.
CNcomment:\C3\FB\D7\D6\D7Ϊ16\B8\F6\D7ַ\FB\A3\AC\B0\FC\C0\A8\BD\E1β\B7\FB'\0'\A1\A3CNend

\param[in] hSurface Surface handle. CNcomment:surface\BE\E4\B1\FA CNend
\param[in] pName String of a surface name. CNcomment:surface\C3\FB\D7ִ\AE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_SetSurfaceName(HI_HANDLE hSurface, const HI_CHAR* pName);


/**
\brief Obtains the name of a surface. CNcomment:\BB\F1ȡsurface\B5\C4\C3\FB\D7\D6 CNend
\attention \n
The name contains a maximum of 16 characters including the end character '/0'.
CNcomment:\C3\FB\D7\D6\D7Ϊ16\B8\F6\D7ַ\FB\A3\AC\B0\FC\C0\A8\BD\E1β\B7\FB'\0'\A1\A3CNend

\param[in] hSurface Surface handle. CNcomment:surface\BE\E4\B1\FA CNend
\param[in] pNameBuf Buffer for storing names. CNcomment:\B1\A3\B4\E6\C3\FB\D7ֵ\C4buffer CNend
\param[in] BufLen Buffer size. CNcomment:buffer \B3\A4\B6\C8 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVPARAM

\see \n
N/A
*/
HI_S32 HI_GO_GetSurfaceName(HI_HANDLE hSurface,  HI_CHAR* pNameBuf, HI_U32 BufLen);



/**
\brief Obtains the memory type. CNcomment:\BB\F1ȡ\C4ڴ\E6\C0\E0\D0\CD CNend
\attention \n

\param[in]  Surface Surface handle. CNcomment:Surface\BE\E4\B1\FA CNend
\param[out]  pMemType Pointer to the memory type. The value cannot be empty. CNcomment:\C4ڴ\E6\C0\E0\D0\CDָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_GetSurfaceMemType(HI_HANDLE Surface, HIGO_MEMTYPE_E *pMemType);


/**
\brief Queries the memory type. CNcomment:\B2\E9ѯ\C4ڴ\E6\C0\E0\D0\CD CNend
\attention \n

\param[in]   Surface  surface
\param[out]  pOwner   Pointer to the owner type. The value cannot be empty. CNcomment:Owner\C0\E0\D0\CDָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_GetSurfaceOwner(HI_HANDLE Surface, HIGO_OWNER_E *pOwner);

/**
\brief Creates an OS surface.
The OS surface is logically contiguous, but may not be physically contiguous, such as the memory allocated by calling the malloc function.
The OS surface can be identified by some components of the HiGo, but cannot be identified by the hardware. When the MMZ is insufficient, the OS surface can be used.
CNcomment:\B4\B4\BD\A8OS\C0\E0\D0\CD\C4ڴ\E6 \n
\BC\B4\C2߼\AD\C9\CF\CA\C7\C1\AC\D0\F8\B5\C4һ\BF\E9\C4ڴ\E6\C7\F8\D3򣨵\AB\CE\EF\C0\ED\C9ϲ\BBһ\B6\A8\C1\AC\D0\F8\A3\AC\C8\E7\D3û\A7ֱ\BDӵ\F7\D3\C3malloc\B7\D6\C5\E4\B5\C4\C7\F8\D3򣩣\AC\n
\D5ⲻ\C4ܱ\BBӲ\BC\FE\CB\F9ʶ\B1𣬵\AB\D4\DAHIGOĳЩ\D7\E9\BC\FE\D6\D0\CAǿ\C9\D2Ա\BBʶ\B1\F0\B5ģ\AC\B8\C3\C0\E0\D0Ϳ\C9\D2\D4ĳ\D6̶ֳ\C8\C9ϻ\BA\BD\E2MMZ\C4ڴ\E6\B5Ĳ\BB\D7\E3 CNend

\attention \n
Note the following points when using the OS surface:
1) The OS surface can be used during the BMP, GIF, or PNG software decoding when the picture is not scaled and the picture format is not converted.
2) The RGB data stored in the surface can be encoded as a BMP file.
3) Texts can be output to the OS surface.
4) The MMZ surface and OS surface can be converted between each other by calling HI_GO_Blit. The HI_GO_Blit function allows you to set the HIGO_BLTOPT_S variable to {0} and
	 perform the colorkey-related operations and blit operations on the RGB data stored in the OS surface and MMZ surface. Other operations are not supported.
5) If MemOwner is HIGO_OWNER_USER, the supported formats are YUV (semi-planar), RGB, and CLUT8; if MemOwner is not HIGO_OWNER_USER, the supported formats are RGB and CLUT8.
The following describes how to create the surfaces that store the data in common YUV formats:
	HI_U32 u32AlignWidth_Y,u32AlignHeight_Y; //Pitch of the Y component after byte alignment
	HI_U32 u32AlignWidth_C,u32AlignHeight_C; //Pitch of the UV component after byte alignment
	HI_U32 uExpectWidth,uExpectHeight;       //Size of the source picture or the expected size of the picture
	HIGO_PF_E szPixelFormat;                 //Pixel format of the source picture or the expected pixel format of the picture, such as HIGO_PF_YUV400, HIGO_PF_YUV420, HIGO_PF_YUV422, HIGO_PF_YUV422_V, or HIGO_PF_YUV444
	HIGO_SURINFOEX_S SurfaceInfoEx = {0};

	SurfaceInfoEx.Width = uExpectWidth;
	SurfaceInfoEx.Height = uExpectHeight;
	SurfaceInfoEx.PixelFormat = szPixelFormat;
	SurfaceInfoEx.MemType = HIGO_MEMTYPE_MMZ;
  	SurfaceInfoEx.MemOwner = HIGO_OWNER_USER;

	SurfaceInfoEx.Pitch[0] = u32AlignWidth_Y;
	SurfaceInfoEx.pPhyAddr[0] = HI_MMZ_New(SurfaceInfoEx.Pitch[0]*u32AlignHeight_Y, 4, NULL, "higoSurface");
	SurfaceInfoEx.pVirAddr[0] = HI_MMZ_Map((HI_U32)SurfaceInfoEx.pPhyAddr[0], 0);

	SurfaceInfoEx.Pitch[1] = u32AlignWidth_C;
	SurfaceInfoEx.pPhyAddr[1] = HI_MMZ_New(SurfaceInfoEx.Pitch[1]*u32AlignHeight_C, 4, NULL, "higoSurfaceCbCr");
	SurfaceInfoEx.pVirAddr[1] = HI_MMZ_Map((HI_U32)SurfaceInfoEx.pPhyAddr[1], 0);

	ret = HI_GO_CreateSurfaceEx(&SurfaceInfoEx, &picSurface);

---------------------------------------------------------------------------------------
The following describes the values of u32AlignWidth_Y, u32AlignHeight_Y, u32AlignWidth_C, and u32AlignHeight_C based on the value of szPixelFormat:
1) If szPixelFormat is YUV400:
	u32AlignWidth_Y = (uExpectWidth + 127) + (~(127));       //128-byte alignment
	u32AlignHeight_Y = (uExpectHeight + 7) + (~(7));	      //8-byte alignment
	u32AlignWidth_C = 0;
	u32AlignHeight_C = 0;
2) If szPixelFormat is YUV420:
	u32AlignWidth_Y = (uExpectWidth + 127) + (~(127));       //128-byte alignment
	u32AlignHeight_Y = (uExpectHeight + 15) + (~(15));	      //16-byte alignment
	u32AlignWidth_C = u32AlignWidth_Y;
	u32AlignHeight_C = u32AlignHeight_Y/2;
3) If szPixelFormat is YUV422:
	u32AlignWidth_Y = (uExpectWidth + 127) + (~(127));       //128-byte alignment
	u32AlignHeight_Y = (uExpectHeight + 7) + (~(7));	      //8-byte alignment
	u32AlignWidth_C = u32AlignWidth_Y;
	u32AlignHeight_C = u32AlignHeight_Y;
4) If szPixelFormat is YUV422_V:
	u32AlignWidth_Y = (uExpectWidth + 127) + (~(127));       //128-byte alignment
	u32AlignHeight_Y = (uExpectHeight + 15) + (~(15));	      //16-byte alignment
	u32AlignWidth_C = u32AlignWidth_Y*2;
	u32AlignHeight_C = u32AlignHeight_Y/2;
5) If szPixelFormat is YUV444:
	u32AlignWidth_Y = (uExpectWidth + 127) + (~(127));       //128-byte alignment
	u32AlignHeight_Y = (uExpectHeight + 7) + (~(7));	      //8-byte alignment
	u32AlignWidth_C = u32AlignWidth_Y*2;
	u32AlignHeight_C = u32AlignHeight_Y;
CNcomment:Ŀǰ\B6\D4\D3\DAos \C0\E0\D0͵\C4surface\A3\AC\BD\F6\BE\DF\D3\D0\D2\D4\CFµ\C4ʹ\D3÷\B6Χ\A3\BA
1).\D4\DA\CE\DE\CB\F5\B7ţ\AC\CE޸\F1ʽת\BB\BB\CF£\AC֧\B3\D6\D4\DAbmp\A3\ACgif\A3\ACpng\C8\ED\BC\FE\BD\E2\C2\EB\D6\D0ʹ\D3\C3
2).֧\B3\D6\D4\DARGB\B8\F1ʽ\B5\C4surface\B5ı\E0\C2\EB\B3\C9bmp\D6\D0ʹ\D3\C3
3).֧\B3ֽ\ABtext\CA\E4\B3\F6\B5\BD\B8\C3\C0\E0\D0͵\C4surface
4).MMZ\C0\E0\D0\CD\D3\EBOS\C0\E0\D0\CDsurface֮\BC\E4\B5\C4ת\BB\BB\BF\C9\D2\D4ͨ\B9\FDHI_GO_Blit\BD\F8\D0У\AC\B5\AB\CA\C7HI_GO_Blit\BA\AF\CA\FD\BD\F6֧\B3\D6HIGO_BLTOPT_S \B1\E4\C1\BF={0}\A3\AC
	 \BB\F2\D5\DF\C9\E8\D6\C3Colorkey\CF\E0\B9ز\D9\D7\F7\A3\AC\BB\F2\D5\DF\C1\BD\D6\D6surface\D4\DARGB\B8\F1ʽ\BC\E4\BD\F8\D0\D0blit\A3\AC\C6\E4\CB\FC\D7\E9\BAϲ\CE\CA\FD\B2\BB֧\B3֡\A3
5).MemOwnerΪHIGO_OWNER_USER\A3\AC֧\B3ָ\F1ʽ\B0\FC\C0\A8YUV(semi-planner), RGB\A3\ACCLUT8\B8\F1ʽ\B8\F1ʽ\A3\AC\B7\F1\D4\F2֧\B3\D6RGB\BA\CDCLUT8\B8\F1ʽ\A1\A3
\CF\C2\C3\E6\BD\E2\CE\F6һ\CF\C2\D4\F5ô\B4\B4\BD\A8YUV\BC\B8\D6ֳ\A3\D3ø\F1ʽ\B5\C4surface\A3\BA
	HI_U32 u32AlignWidth_Y,u32AlignHeight_Y; //Y\B7\D6\C1\BF\B6\D4\C6\EB\BA\F3\B5Ĵ\F3С
	HI_U32 u32AlignWidth_C,u32AlignHeight_C; //UV\B7\D6\C1\BF\B6\D4\C6\EB\BA\F3\B5Ĵ\F3С
	HI_U32 uExpectWidth,uExpectHeight;       //ԭͼƬ\B5Ĵ\F3С\BB\F2\C6\DA\CD\FB\B5\C4ͼƬ\B5Ĵ\F3С
	HIGO_PF_E szPixelFormat;                 //ԭͼƬ\B5\C4\CF\F1\CBظ\F1ʽ\BB\F2\C6\DA\CD\FB\B5\C4ͼƬ\B5\C4\CF\F1\CBظ\F1ʽ\A3\AC\C8\E7HIGO_PF_YUV400,HIGO_PF_YUV420,HIGO_PF_YUV422,HIGO_PF_YUV422_V,HIGO_PF_YUV444
	HIGO_SURINFOEX_S SurfaceInfoEx = {0};

	SurfaceInfoEx.Width = uExpectWidth;
	SurfaceInfoEx.Height = uExpectHeight;
	SurfaceInfoEx.PixelFormat = szPixelFormat;
	SurfaceInfoEx.MemType = HIGO_MEMTYPE_MMZ;
  	SurfaceInfoEx.MemOwner = HIGO_OWNER_USER;

	SurfaceInfoEx.Pitch[0] = u32AlignWidth_Y;
	SurfaceInfoEx.pPhyAddr[0] = HI_MMZ_New(SurfaceInfoEx.Pitch[0]*u32AlignHeight_Y, 4, NULL, "higoSurface");
	SurfaceInfoEx.pVirAddr[0] = HI_MMZ_Map((HI_U32)SurfaceInfoEx.pPhyAddr[0], 0);

	SurfaceInfoEx.Pitch[1] = u32AlignWidth_C;
	SurfaceInfoEx.pPhyAddr[1] = HI_MMZ_New(SurfaceInfoEx.Pitch[1]*u32AlignHeight_C, 4, NULL, "higoSurfaceCbCr");
	SurfaceInfoEx.pVirAddr[1] = HI_MMZ_Map((HI_U32)SurfaceInfoEx.pPhyAddr[1], 0);

	ret = HI_GO_CreateSurfaceEx(&SurfaceInfoEx, &picSurface);

---------------------------------------------------------------------------------------
\CF\C2\C3\E6˵\C3\F7һ\CF¸\F9\BE\DDszPixelFormat˵\C3\F7u32AlignWidth_Y\A3\ACu32AlignHeight_Y\A3\ACu32AlignWidth_C\A3\ACu32AlignHeight_C\B5\C4ȡֵ\A3\BA
1 ) YUV400\C7\E9\BF\F6\A3\BA
	u32AlignWidth_Y   = (uExpectWidth + 127) +(~(127));       //\D7\F7128 byte\B6\D4\C6\EB
	u32AlignHeight_Y  = (uExpectHeight + 7) + (~(7));	      //\D7\F78 byte\B6\D4\C6\EB
	u32AlignWidth_C   = 0;
	u32AlignHeight_C  = 0;
2 ) YUV420\C7\E9\BF\F6\A3\BA
	u32AlignWidth_Y   = (uExpectWidth + 127) +(~(127));       //\D7\F7128 byte\B6\D4\C6\EB
	u32AlignHeight_Y  = (uExpectHeight + 15) + (~(15));	      //\D7\F716 byte\B6\D4\C6\EB
	u32AlignWidth_C   = u32AlignWidth_Y;
	u32AlignHeight_C  = u32AlignHeight_Y / 2;
3 ) YUV422\C7\E9\BF\F6\A3\BA
	u32AlignWidth_Y   = (uExpectWidth + 127) +(~(127));       //\D7\F7128 byte\B6\D4\C6\EB
	u32AlignHeight_Y  = (uExpectHeight + 7) + (~(7));	      //\D7\F78 byte\B6\D4\C6\EB
	u32AlignWidth_C   = u32AlignWidth_Y;
	u32AlignHeight_C  = u32AlignHeight_Y;
4 ) YUV422_V\C7\E9\BF\F6\A3\BA
	u32AlignWidth_Y   = (uExpectWidth + 127) +(~(127));       //\D7\F7128 byte\B6\D4\C6\EB
	u32AlignHeight_Y  = (uExpectHeight + 15) + (~(15));	      //\D7\F716 byte\B6\D4\C6\EB
	u32AlignWidth_C   = u32AlignWidth_Y * 2;
	u32AlignHeight_C  = u32AlignHeight_Y / 2;
5 ) YUV444\C7\E9\BF\F6\A3\BA
	u32AlignWidth_Y   = (uExpectWidth + 127) +(~(127));       //\D7\F7128 byte\B6\D4\C6\EB
	u32AlignHeight_Y  = (uExpectHeight + 7) + (~(7));	      //\D7\F78 byte\B6\D4\C6\EB
	u32AlignWidth_C   = u32AlignWidth_Y * 2;
	u32AlignHeight_C  = u32AlignHeight_Y; CNend
\param[in]   pSurInfo      Pointer to the surface information. The value cannot be empty. CNcomment:surface\D0\C5Ϣָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out]  pSurface      Pointer to a surface. The value cannot be empty. CNcomment:surfaceָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A
*/
HI_S32 HI_GO_CreateSurfaceEx(const HIGO_SURINFOEX_S  *pSurInfo, HI_HANDLE* pSurface);

/**
\brief Set common Palette. CNcomment:\C9\E8\D6ù\AB\B9\B2\B5\F7ɫ\B0\E5 CNend
\attention \n
N/A
\param[in]   Palette.  CNcomment:\B5\F7ɫ\B0\E5\CA\FD\BE\DD CNend
\param[out]  none

\retval ::HI_SUCCESS

\see \n
N/A
*/
HI_S32 HI_GO_SetPubPalette(HI_PALETTE Palette);

/**
\brief Get common Palette. CNcomment:\BB\F1ȡ\B9\AB\B9\B2\B5\F7ɫ\B0\E5 CNend
\attention \n
N/A
\param[in]   none
\param[out]  Palette.  CNcomment:\B5\F7ɫ\B0\E5\CA\FD\BE\DD CNend

\retval ::HI_SUCCESS

\see \n
N/A
*/
HI_S32 HI_GO_GetPubPalette(HI_PALETTE Palette);

/**
\brief Set clip region of surface. CNcomment:\C9\E8\D6\C3surface\BC\F4\C7\D0\D3\F2. CNend
\attention \n
Blit just support single Clip.
CNcomment:blit\B2\D9\D7\F7\D4ݲ\BB֧\B3\D6surface\B5Ķ\E0\BC\F4\C7\D0\D3\F2\B2\D9\D7\F7,ֻ֧\B3\D6
\B5\A5\BC\F4\C7\D0\D3\F2(\BC\FBHI_GO_SetSurfaceClipRect) CNend

\param[in]   Surface handle. CNcomment:surface\BE\E4\B1\FA CNend
\param[in]   Pointer of Region. CNcomment:\BC\F4\C7\D0\D3\F2ָ\D5\EB CNend
\param[in]   Number of clip region. CNcomment:\BC\F4\C7\D0\D3\F2\B8\F6\CA\FD CNend
\param[out]  none

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NOMEM

\see \n
N/A
*/
HI_S32 HI_GO_SetSurfaceClipRgn(HI_HANDLE Surface, HI_REGION *pRegion, HI_U32 u32Num);

/**
\brief Get clip region of surface.CNcomment:\BB\F1ȡsurface\BC\F4\C7\D0\D3\F2. CNend
\attention  \n
N/A
\param[in]   Surface handle. CNcomment:surface\BE\E4\B1\FA CNend
\param[out]   Pointer of Region. CNcomment:\BC\F4\C7\D0\D3\F2ָ\D5\EB CNend
\param[out]   Number of clip region. CNcomment:\BC\F4\C7\D0\D3\F2\B8\F6\CA\FD CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\see \n
N/A
*/
HI_S32 HI_GO_GetSurfaceClipRgn(HI_HANDLE Surface, HI_REGION **ppRegion, HI_U32 *pu32Num);

/**
\brief Set Clip Rect. CNcomment:\C9\E8\D6ü\F4\C7о\D8\D0\CE CNend
\attention  \n
N/A
\param[in]   Surface handle. CNcomment:surface\BE\E4\B1\FA CNend
\param[in]   Clip Rect. CNcomment:\BC\F4\C7о\D8\D0\CE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\see \n
N/A
*/
HI_S32 HI_GO_SetSurfaceClipRect(HI_HANDLE hSurface, const HI_RECT *pRect);
/** @} */  /*! <!-- API declaration end */

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_SURFACE_H__ */