#ifndef __HI_GO_COMM_H__
#define __HI_GO_COMM_H__

#include "hi_type.h"
#include "hi_go_errno.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/
/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_COMMON */
/** @{ */  /**<!\A1\AA[HIGO_COMMON] */

/**Maximum number of colors in the palette*//** CNcomment: \B5\F7ɫ\B0\E5\D7\EE\B4\F3\D1\D5ɫ\CA\FD */
#define MAX_PALETTE_COLOR_SIZE 256

/**Color value*//** CNcomment: \D1\D5ɫֵ */
typedef HI_U32 HI_COLOR;

/**Palette*//** CNcomment: \B5\F7ɫ\B0\E5 */
typedef HI_COLOR HI_PALETTE[MAX_PALETTE_COLOR_SIZE];

typedef enum
{
    HIGO_IMGTYPE_JPEG = 0, /**<.jpeg picture*//**<CNcomment: JPEG\B8\F1ʽͼƬ*/
    HIGO_IMGTYPE_GIF,      /**<.gif picture*//**<CNcomment: GIF\B8\F1ʽͼƬ*/
    HIGO_IMGTYPE_BMP,      /**<.bmp picture*//**<CNcomment: BMP\B8\F1ʽͼƬ */
    HIGO_IMGTYPE_PNG,      /**<.png picture*//**<CNcomment: PNG\B8\F1ʽͼƬ */
    HIGO_IMGTYPE_RLE,      /**<.rle picture*//**<CNcomment: RLE\B8\F1ʽͼƬ */
    HIGO_IMGTPYE_BUTT
} HIGO_IMGTYPE_E;


/**Rectangle*//** CNcomment: \BE\D8\D0\CE */
typedef struct
{
    HI_S32 x, y;

    HI_S32 w, h;
} HI_RECT;

typedef HI_RECT HI_POINT;

/**Region*//** CNcomment: \C7\F8\D3\F2 */
typedef struct
{
    HI_S32 l;
    HI_S32 t;
    HI_S32 r;
    HI_S32 b;
} HI_REGION;

/**Mode of adjusting the window z-order*//**CNcomment:Z\D0\F2\B5\F7\D5\FB\B7\BDʽ*/
typedef enum
{
    HIGO_ZORDER_MOVETOP = 0,  /**<Move to the top*//**<CNcomment:\D2Ƶ\BD\D7\B2\BF*/
    HIGO_ZORDER_MOVEUP,       /**<Move upwards*//**<CNcomment:\CF\F2\C9\CF\D2\C6*/
    HIGO_ZORDER_MOVEBOTTOM,   /**<Move to the bottom*//**<CNcomment:\D2Ƶ\BD\D7\EE\B5ײ\BF*/
    HIGO_ZORDER_MOVEDOWN,     /**<Move downwards*//**<CNcomment:\CF\F2\CF\C2\D2\C6*/
    HIGO_ZORDER_BUTT
} HIGO_ZORDER_E;

#define HIGO_INVALID_HANDLE 0x0

/**Stream position*//** CNcomment: \C1\F7ʽλ\D6\C3*/


/** @} */  /*! <!-- Structure Definition end */

/********************** Global Variable declaration **************************/

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_COMMON */
/** @{ */  /** <!\A1\AA[HIGO_COMMON] */


/**
\brief Initializes the HiGo.CNcomment:HiGo\B3\F5ʼ\BB\AF CNend
\attention \n
Before using the HiGo, you must call this application programming interface (API) to initialize the HiGo. The HiGo
includes the graphic device (Gdev) module, decoder, Winc module, bit block transfer (Bliter) module, and surface
module.
CNcomment:ʹ\D3\C3HiGo\B9\A6\C4ܱ\D8\D0\EB\CFȵ\F7\D3øýӿڣ\AC\CD\EA\B3\C9HiGo\B5ĳ\F5ʼ\BB\AF\A3\AC\D6\F7Ҫ\B0\FC\C0\A8gdev, decoder, winc, blit, surfaceģ\BF\E9 CNend
\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_INITFAILED

\see \n
::HI_GO_Deinit
*/
HI_S32	HI_GO_Init(HI_VOID);

/**
\brief Deinitializes the HiGo.CNcomment: HiGoȥ\B3\F5ʼ\BB\AF CNend
\attention \n
If the HiGo is not used, you need to call this API to release resources.CNcomment: \B2\BB\D4\D9ʹ\D3\C3HiGo\B9\A6\C4\DCʱ\D0\E8Ҫ\B5\F7\D3øýӿڣ\AC\CAͷ\C5\D7\CAԴ CNend
\param N/A.CNcomment: \CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_DEINITFAILED

\see \n
::HI_GO_Init
*/
HI_S32	HI_GO_Deinit(HI_VOID);

/**
\brief Initializes the extended library of the HiGo.CNcomment:HiGo \C0\A9չ\BF\E2\B3\F5ʼ\BB\AF CNend
\attention \n
If the extended library of the HiGo is not used, you need to call this API to release resources, especially the
resources of the cursor and text modules.
CNcomment:\D6\F7Ҫ\CA\C7CURSOR\BA\CDTEXTģ\BF顣CNend
\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_DEINITFAILED

\see \n
::HI_GO_DeInitExt
*/
HI_S32 HI_GO_InitExt(HI_VOID);

/**
\brief Deinitializes the extended library of the HiGo.CNcomment: HiGo\C0\A9չ\BF\E2ȥ\B3\F5ʼ\BB\AF CNend
\attention \n
If the HiGo is not used, you need to call this API to release resources.CNcomment: \B2\BB\D4\D9ʹ\D3\C3HiGo\C0\A9չ\BF⹦\C4\DCʱ\D0\E8Ҫ\B5\F7\D3øýӿڣ\AC\CAͷ\C5\D7\CAԴ\A3\AC\D6\F7Ҫ\CA\C7CURSOR\BA\CDTEXTģ\BF顣CNend
\param N/A.CNcomment: \CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_DEINITFAILED

\see \n
::HI_GO_InitExt
*/
HI_S32 HI_GO_DeInitExt(HI_VOID);

/**
\brief Obtains the version information.CNcomment:\BB\F1ȡ\B0汾\D0\C5Ϣ CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[out] ppVersion Output address of the version information string. The value cannot be empty.CNcomment: \B0汾\D0\C5Ϣ\D7ַ\FB\B4\AE\CA\E4\B3\F6\B5\D8ַ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] ppBuildTime Build Output address of the time string. The value cannot be empty.CNcomment:Buildʱ\BC\E4\D7ַ\FB\B4\AE\CA\E4\B3\F6\B5\D8ַ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetVersion(HI_CHAR ** ppVersion, HI_CHAR **ppBuildTime);

/**
\brief Converts the data on a surface into a .bmp picture for output.CNcomment: \BD\ABSurface\D6е\C4\CA\FD\BE\DDת\BB\BB\B3\C9BMP\B8\F1ʽͼ\CF\F3\CA\E4\B3\F6\A1\A3CNend
\attention \n
The output file is [year]-[date]-[hour]-[min]-[second]-[ms].bmp.CNcomment: \CA\E4\B3\F6\CEļ\FE\C3\FBΪ[year]-[date]-[hour]-[min]-[second]-[ms].bmp CNend
The output picture must be a 16-bit bitmap.CNcomment: \CA\E4\B3\F6ͼƬ\B9̶\A8Ϊ16λͼ\A1\A3CNend
It is recommended that you call HI_GO_EncodeToFile rather than HI_GO_Surface2Bmp.CNcomment: \BD\A8\D2\E9ʹ\D3\C3HI_GO_EncodeToFile\BDӿ\DA\C0\B4\B4\FA\CC\E6\B4˽ӿ\DA CNend

\param[in] Surface Data to be captured.CNcomment: \D0\E8Ҫ\BD\F8\D0н\D8\C6\C1\B5\C4\CA\FD\BEݡ\A3CNend
\param[in] pRect Pointer to a rectangle. If this parameter is not set, it indicates the entire surface.CNcomment: \C7\F8\D3\F2ָ\D5\EB,Ϊ\BFձ\EDʾ\D5\FB\B8\F6surface\A1\A3CNend


\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVSURFACESIZE
\retval ::HIGO_ERR_INVSURFACEPF
\retval ::HIGO_ERR_NOTINIT
\retval ::HIGO_ERR_NOMEM

*/
HI_S32	HI_GO_Surface2Bmp(HI_HANDLE Surface, const HI_RECT *pRect);

/**
\brief Enables the memory management module.CNcomment:ʹ\C4\DC\C4ڴ\E6\B9\DC\C0\EDģ\BF\E9 CNend
\attention \n
The memory management module is disabled by default. Before using the memory statistics function, you must call this
API to enable the memory management module.
CNcomment:Ĭ\C8\CF\C7\E9\BF\F6\B4\A6\D3ڷ\C7ʹ\C4\DC״̬\A3\ACֻ\D3иýӿڴ򿪺\F3\B2\C5\C4\DCʹ\D3\C3\C4ڴ\E6ͳ\BCƹ\A6\C4\DC CNend

\param[in] bEnable Whether to enable the memory statistics function.CNcomment:\CAǷ\F1\BF\AA\C6\F4\C4ڴ\E6ͳ\BCƹ\A6\C4\DC CNend

\retval ::HI_SUCCESS

*/
HI_S32 HI_GO_EnableMemMng(HI_BOOL bEnable);



/**
\brief Obtains the enable status of the memory management module.CNcomment:\BB\F1ȡ\C4ڴ\E6\B9\DC\C0\EDģ\BF\E9ʹ\C4\DC״̬ CNend
\attention \n
\param[out] pbEnable Whether to obtain the enable status of the memory statistics function.CNcomment:\BB\F1ȡ\C4ڴ\E6ͳ\BCƹ\A6\C4\DC\CAǷ\F1\BF\AA\C6\F4 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR

*/
HI_S32 HI_GO_GetMemMngStatus(HI_BOOL *pbEnable);

/**
\brief Outputs the general information about the system memory.CNcomment:\CA\E4\B3\F6ϵͳ\C4ڴ\E6\B5\C4\D7\DC\CC\E5\D0\C5Ϣ CNend
\attention \n
\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS
*/
HI_S32 HI_GO_SysMemQuene(HI_VOID);

/**
\brief Outputs the general information about the media memory zone (MMZ).CNcomment: \CA\E4\B3\F6MMZ\C4ڴ\E6\B5\C4\D7\DC\CC\E5\D0\C5Ϣ\A1\A3CNend
\attention \n
\param N/A.CNcomment:\CE\DE CNend

\retval ::HI_SUCCESS

*/
HI_S32 HI_GO_MMZMemQuene(HI_VOID);

/** @} */  /*! <!-- API declaration end */


#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_COMM_H__ */
