#ifndef __HI_GO_ERRNO_H__
#define __HI_GO_ERRNO_H__

/* add include here */
#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/
/** \addtogroup      HIGO_ERRCODE */
/** @{ */  /** <!-- [HIGO_ERRCODE] */

/**Error IDs of HiGo projects*/
/** CNcomment:HiGo \CF\EEĿ\B4\ED\CE\F3ID */
#define HIGO_ERR_APPID (0x80000000L + 0x30000000L)

typedef enum hiGOLOG_ERRLEVEL_E
{
    HIGO_LOG_LEVEL_DEBUG = 0,  /* debug-level                                  */
    HIGO_LOG_LEVEL_INFO,       /* informational                                */
    HIGO_LOG_LEVEL_NOTICE,     /* normal but significant condition             */
    HIGO_LOG_LEVEL_WARNING,    /* warning conditions                           */
    HIGO_LOG_LEVEL_ERROR,      /* error conditions                             */
    HIGO_LOG_LEVEL_CRIT,       /* critical conditions                          */
    HIGO_LOG_LEVEL_ALERT,      /* action must be taken immediately             */
    HIGO_LOG_LEVEL_FATAL,      /* just for compatibility with previous version */
    HIGO_LOG_LEVEL_BUTT
} HIGO_LOG_ERRLEVEL_E;

/**Macros for defining the error codes of the HiGo*/
/** CNcomment:HiGo \B4\ED\CE\F3\C2붨\D2\E5\BA\EA */
#define HIGO_DEF_ERR( module, errid) \
    ((HI_S32)((HIGO_ERR_APPID) | (((HI_U32)module) << 16) | (((HI_U32)HIGO_LOG_LEVEL_ERROR) << 13) | ((HI_U32)errid)))

/**HiGo Module encoding*/
/** CNcomment:HiGo ģ\BF\E9\B1\E0\C2\EB */
typedef enum
{
    HIGO_MOD_COMM = 0,
    HIGO_MOD_SURFACE,
    HIGO_MOD_MEMSURFACE,
    HIGO_MOD_LAYER,
    HIGO_MOD_BLITER,
    HIGO_MOD_DEC,
    HIGO_MOD_TEXTOUT,
    HIGO_MOD_WINC,
    HIGO_MOD_CURSOR,
    HIGO_MOD_TEXT_LAYOUT,
    HIGO_MOD_BUTT
} HIGO_MOD_E;

/**Common error codes of the HiGo*/
/** CNcomment:HiGo \B9\AB\B9\B2\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_COMM_NOTINIT = 0,
    ERR_COMM_INITFAILED,
    ERR_COMM_DEINITFAILED,
    ERR_COMM_NULLPTR,
    ERR_COMM_INVHANDLE,
    ERR_COMM_NOMEM,
    ERR_COMM_INTERNAL,
    ERR_COMM_INVSRCTYPE,
    ERR_COMM_INVFILE,
    ERR_COMM_INVPARAM,
    ERR_COMM_INUSE,
    ERR_COMM_UNSUPPORTED,
    ERR_COMM_DEPENDTDE,
    ERR_COMM_DEPENDFB ,
    ERR_COMM_DEPENDMMZ,
    ERR_COMM_DEPENDJPEG,
    ERR_COMM_DEPENDPNG,
    ERR_COMM_DEPENDBMP,
    ERR_COMM_DEPENDGIF,
    ERR_COMM_DEPENDCURSOR,
    ERR_COMM_DEPENDJPGENC,
    ERR_COMM_BUTT
} HIGO_ERR_E;

/**The dependent module is not initialized (0xB0008000).*/
/** CNcomment:\CB\F9\D2\C0\C0\B5\B5\C4ģ\BF\E9δ\B3\F5ʼ\BB\AF 0xB0008000 */
#define HIGO_ERR_NOTINIT HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_NOTINIT)

/*The module fails to be initialized (0xB0008001).*/
/** CNcomment:ģ\BF\E9\B3\F5ʼ\BB\AFʧ\B0\DC 0xB0008001 */
#define HIGO_ERR_DEINITFAILED HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INITFAILED)

/**The module fails to be deinitialized (0xB0008002).*/
/** CNcomment:ģ\BF\E9ȥ\B3\F5ʼ\BB\AFʧ\B0\DC 0xB0008002 */
#define HIGO_ERR_INITFAILED HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEINITFAILED)

/**The input pointer is null (0xB0008003).*/
/** CNcomment:\B4\AB\C8\EB\B2\CE\CA\FDΪ\BF\D5ָ\D5\EB 0xB0008003 */
#define HIGO_ERR_NULLPTR HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_NULLPTR)

/**The input handle is invalid (0xB0008004).*/
/** CNcomment:\B4\AB\C8\EB\CE\DEЧ\B5ľ\E4\B1\FA 0xB0008004 */
#define HIGO_ERR_INVHANDLE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INVHANDLE)

/**The memory is insufficient (0xB0008005).*/
/** CNcomment:\C4ڴ治\D7\E3 0xB0008005 */
#define HIGO_ERR_NOMEM HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_NOMEM)

/**An internal error occurs (0xB0008006).*/
/** CNcomment:\C4ڲ\BF\B4\ED\CE\F3 0xB0008006 */
#define HIGO_ERR_INTERNAL HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INTERNAL)

/**The I/O source is invalid (0xB0008007).*/
/** CNcomment:\CE\DEЧ\B5\C4IO\C0\B4Դ 0xB0008007 */
#define HIGO_ERR_INVSRCTYPE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INVSRCTYPE)

/**The file operation fails because the file is invalid (0xB0008008).*/
/** CNcomment:\CE\DEЧ\B5\C4\CEļ\FE\A3\AC\CEļ\FE\B2\D9\D7\F7ʧ\B0\DC 0xB0008008 */
#define HIGO_ERR_INVFILE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INVFILE)

/**The parameter is invalid (0xB0008009).*/
/** CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD 0xB0008009*/
#define HIGO_ERR_INVPARAM HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INVPARAM)

/**The handle is being used (0xB000800A).*/
/** CNcomment:\B4˾\E4\B1\FA\D5\FD\D4ڱ\BBʹ\D3\C3 0xB000800A */
#define HIGO_ERR_INUSE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_INUSE)

/**The operation is invalid (0xB000800B).*/
/** CNcomment:\CE\DEЧ\B5Ĳ\D9\D7\F7 0xB000800B */
#define HIGO_ERR_UNSUPPORTED HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_UNSUPPORTED)

/**An error occurs when the APIs related to the TDE are called (0xB000800C).*/
/** CNcomment:\D2\C0\C0\B5TDE\B3\F6\B4\ED 0xB000800C*/
#define HIGO_ERR_DEPEND_TDE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDTDE)

/**An error occurs when the APIs related to the FB are called (0xB000800D).*/
/** CNcomment:\D2\C0\C0\B5FB\B3\F6\B4\ED  0xB000800D*/
#define HIGO_ERR_DEPEND_FB HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDFB)

/**An error occurs when the APIs related to the MMZ are called (0xB000800E).*/
/** CNcomment:\D2\C0\C0\B5MMZ\B3\F6\B4\ED 0xB000800E*/
#define HIGO_ERR_DEPEND_MMZ HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDMMZ)

/**An error occurs when the APIs related to .jpeg decoding are called (0xB000800F).*/
/** CNcomment:\D2\C0\C0\B5JPEG\BD\E2\C2\EB\B3\F6\B4\ED    0xB000800F*/
#define HIGO_ERR_DEPEND_JPEG HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDJPEG)

/**An error occurs when the APIs related to .png decoding are called (0xB0008010).*/
/** CNcomment:\D2\C0\C0\B5PNG\BD\E2\C2\EB\B3\F6\B4\ED 0xB0008010*/
#define HIGO_ERR_DEPEND_PNG HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDPNG)

/**An error occurs when the APIs related to .bmp decoding are called (0xB0008011).*/
/** CNcomment:\D2\C0\C0\B5BMP\BD\E2\C2\EB\B3\F6\B4\ED 0xB0008011*/
#define HIGO_ERR_DEPEND_BMP HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDBMP)

/**An error occurs when the APIs related to .gif decoding are called (0xB0008012).*/
/** CNcomment:\D2\C0\C0\B5GIF\BD\E2\C2\EB\B3\F6\B4\ED 0xB0008012*/
#define HIGO_ERR_DEPEND_GIF HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDGIF)

/**An error occurs when the APIs related to the cursor are called (0xB0008013).*/
/** CNcomment:\D2\C0\C0\B5CURSOR\BD\E2\C2\EB\B3\F6\B4\ED  0xB0008013*/
#define HIGO_ERR_DEPEND_CURSOR HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDCURSOR)

/**An error occurs when the APIs related to .jpeg encoding are called (0xB0008014).*/
/** CNcomment:\D2\C0\C0\B5jpeg\B1\E0\C2\EBʧ\B0\DC 0xB0008014*/
#define HIGO_ERR_DEPEND_JPGE HIGO_DEF_ERR(HIGO_MOD_COMM, ERR_COMM_DEPENDJPGENC)


/**Error codes of the HiGo surface module*/
/** CNcomment:HiGo surfaceģ\BF\E9\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_SURFACE_INVSURFACESIZE = 0,
    ERR_SURFACE_INVSURFACEPF,
    ERR_SURFACE_NOTLOCKED,
    ERR_SURFACE_LOCKED,
    ERR_SURFACE_NOCOLORKEY,
    ERR_SURFACE_BUTT
} HIGO_SURFACE_ERR_E;

#define SURFACE_DEF_ERR(err) HIGO_DEF_ERR(HIGO_MOD_SURFACE, err)

/**The surface size is incorrect (0xB0018000).*/
/** CNcomment:surface\B3ߴ粻\D5\FDȷ 0xB0018000 */
#define HIGO_ERR_INVSURFACESIZE SURFACE_DEF_ERR(ERR_SURFACE_INVSURFACESIZE)

/**The pixel format of the surface is incorrect (0xB0018001).*/
/** CNcomment:surface\CF\F1\CBظ\F1ʽ\B2\BB\D5\FDȷ 0xB0018001 */
#define HIGO_ERR_INVSURFACEPF SURFACE_DEF_ERR(ERR_SURFACE_INVSURFACEPF)

/**The surface cannot be unlocked because it is not locked (0xB0018002).*/
/** CNcomment:surfaceδ\CB\F8\B6\A8\A3\AC\B2\BB\C4ܽ\F8\D0\D0surface\BD\E2\CB\F8\B2\D9\D7\F7 0xB0018002 */
#define HIGO_ERR_NOTLOCKED SURFACE_DEF_ERR(ERR_SURFACE_NOTLOCKED)

/**The surface cannot be written because it is locked (0xB0018003).*/
/** CNcomment:surface\D2\D1\CB\F8\B6\A8\A3\AC\B6\D4surface\BD\F8\D0е\C4д\B2\D9\D7\F7\B1\BB\BD\FBֹ 0xB0018003 */
#define HIGO_ERR_LOCKED SURFACE_DEF_ERR(ERR_SURFACE_LOCKED)

/**The surface does not contain the colorkey value (0xB0018004).*/
/** CNcomment:surface\B2\BB\BA\AC\D3\D0colorKeyֵ 0xB0018004 */
#define HIGO_ERR_NOCOLORKEY SURFACE_DEF_ERR(ERR_SURFACE_NOCOLORKEY)

/**Error codes of the HiGo Gdev module*/
/** CNcomment:HiGo gdevģ\BF\E9\B4\ED\CE\F3\C2\EB*/
typedef enum
{
    ERR_LAYER_INVSIZE = 0,
    ERR_LAYER_INVLAYERID,
    ERR_LAYER_INVPIXELFMT,
    ERR_LAYER_FLUSHTYPE,
    ERR_LAYER_FREEMEM,
    ERR_LAYER_CLOSELAYER,
    ERR_LAYER_CANNOTCHANGE,
    ERR_LAYER_INVORDERFLAG,
    ERR_LAYER_SETALPHA,
    ERR_LAYER_ALREADYSHOW,
    ERR_LAYER_ALREADYHIDE,
    ERR_LAYER_INVLAYERPOS,
    ERR_LAYER_INVSURFACE,
    ERR_LAYER_INVLAYERSIZE,
    ERR_LAYER_INVFLUSHTYPE,
    ERR_LAYER_INVANILEVEL,
    ERR_LAYER_NOTOPEN,
    ERR_LAYER_FB_OPENFAILURE,
    ERR_LAYER_FB_GETVSCREENINFOFAILURE,
    ERR_LAYER_FB_PUTVSCREENINFOFAILURE,
    ERR_LAYER_FB_GETLAYERINFO,
    ERR_LAYER_FB_PUTLAYERINFO,
    ERR_LAYER_FB_GETLAYERALPHA,
    ERR_LAYER_FB_PUTLAYERALPHA,
    ERR_LAYER_FB_WRONG_LAYERID,
    ERR_LAYER_FB_REFRESHFAILURE,
    ERR_LAYER_FB_GETCANVASBUFFER,
    ERR_LAYER_FB_PUTCANVASBUFFER,
    ERR_LAYER_FB_GETZORDER,
    ERR_LAYER_FB_PUTZORDER,
    ERR_LAYER_BUTT
} HIGO_LAYER_ERR_E;

#define LAYER_DEF_ERR(err) HIGO_DEF_ERR(HIGO_MOD_LAYER, err)

/**The layer size is invalid (0xB0038000).*/
/** CNcomment:\CE\DEЧ\B5\C4ͼ\B2\E3\B4\F3С 0xB0038000 */
#define HIGO_ERR_INVSIZE LAYER_DEF_ERR(ERR_LAYER_INVSIZE)

/**The hardware layer ID is invalid (0xB0038001).*/
/** CNcomment:\CE\DEЧ\B5\C4Ӳ\BC\FEͼ\B2\E3ID 0xB0038001 */
#define HIGO_ERR_INVLAYERID LAYER_DEF_ERR(ERR_LAYER_INVLAYERID)

/**The pixel format is invalid (0xB0038002).*/
/** CNcomment:\CE\DEЧ\B5\C4\CF\F1\CBظ\F1ʽ 0xB0038002 */
#define HIGO_ERR_INVPIXELFMT LAYER_DEF_ERR(ERR_LAYER_INVPIXELFMT)

/**The layer refresh mode is incorrect (0xB0038003).*/
/** CNcomment:ͼ\B2\E3ˢ\D0\C2ģʽ\B4\ED\CE\F3 0xB0038003 */
#define HIGO_ERR_INVFLUSHTYPE LAYER_DEF_ERR(ERR_LAYER_FLUSHTYPE)

/**The display buffer fails to be released (0xB0038004).*/
/** CNcomment:\CAͷ\C5\CFԴ\E6ʧ\B0\DC 0xB0038004 */
#define HIGO_ERR_FREEMEM LAYER_DEF_ERR(ERR_LAYER_FREEMEM)

/**The layer device fails to be stopped (0xB0038005).*/
/** CNcomment:\B9ر\D5ͼ\B2\E3\C9豸ʧ\B0\DC 0xB0038005 */
#define HIGO_ERR_CLOSELAYERFAILED LAYER_DEF_ERR(ERR_LAYER_CLOSELAYER)

/**The z-order of the graphics layer cannot be changed (0xB0038006).*/
/** CNcomment:ͼ\B2\E3Z\D0򲻿ɸı\E4 0xB0038006 */
#define HIGO_ERR_CANNOTCHANGE LAYER_DEF_ERR(ERR_LAYER_CANNOTCHANGE)

/**The z-order change flag is invalid (0xB0038007).*/
/** CNcomment:\CE\DEЧ\B5\C4Z\D0\F2\D0޸ı\EA־ 0xB0038007 */
#define HIGO_ERR_INVORDERFLAG LAYER_DEF_ERR(ERR_LAYER_INVORDERFLAG)

/**The surface alpha value fails to be set (0xB0038008).*/
/** CNcomment:\C9\E8\D6\C3surface alphaʧ\B0\DC 0xB0038008 */
#define HIGO_ERR_SETALPHAFAILED LAYER_DEF_ERR(ERR_LAYER_SETALPHA)

/**The graphics layer has been displayed (0xB0038009).*/
/** CNcomment:ͼ\B2\E3\D2Ѿ\AD\CF\D4ʾ 0xB0038009 */
#define HIGO_ERR_ALREADYSHOW LAYER_DEF_ERR(ERR_LAYER_ALREADYSHOW)

/**The graphics layer has been hidden (0xB003800A).*/
/** CNcomment:ͼ\B2\E3\D2Ѿ\AD\D2\FE\B2\D8 0xB003800A */
#define HIGO_ERR_ALREADYHIDE LAYER_DEF_ERR(ERR_LAYER_ALREADYHIDE)

/**The start position of the graphics layer is invalid (0xB003800B).*/
/** CNcomment:\CE\DEЧ\B5\C4ͼ\B2\E3\C6\F0ʼλ\D6\C3 0xB003800B*/
#define HIGO_ERR_INVLAYERPOS LAYER_DEF_ERR(ERR_LAYER_INVLAYERPOS)

/**Alignment fails because the surface is invalid (0xB003800C).*/
/** CNcomment:\CE\DEЧ\B5\C4surface\A3\AC\B1\EDʾ\B6\D4\C6\EBʧ\B0\DC 0xB003800C*/
#define HIGO_ERR_INVLAYERSURFACE LAYER_DEF_ERR(ERR_LAYER_INVSURFACE)

/**The anti-flicker level of the graphics layer is invalid (0xB003800F).*/
/** CNcomment:\CE\DEЧ\B5\C4ͼ\B2㿹\C9\C1˸\BC\B6\B1\F0 0xB003800F*/
#define HIGO_ERR_INVANILEVEL LAYER_DEF_ERR(ERR_LAYER_INVANILEVEL)

/**The graphics layer is not started (0xB0038010).*/
/** CNcomment:ͼ\B2\E3û\D3д\F2\BF\AA 0xB0038010*/
#define HIGO_ERR_NOTOPEN LAYER_DEF_ERR(ERR_LAYER_NOTOPEN)

/** frame buffer: open fb device failure (0xB0038011).*/
/** CNcomment: frame buffer, \B4\F2\BF\AAfb\C9豸ʧ\B0\DC 0xB0038011*/
#define HIGO_ERR_FB_OPEN_FAILURE                    LAYER_DEF_ERR(ERR_LAYER_FB_OPENFAILURE)

/** frame buffer: get vscreeninfo failure (0xB0038012). */
/** CNcomment: frame buffer, \BB\F1ȡ\BFɱ\E4\D0\C5Ϣʧ\B0\DC 0xB0038012 */
#define HIGO_ERR_FB_GET_VSCREENINFO_FAILURE         LAYER_DEF_ERR(ERR_LAYER_FB_GETVSCREENINFOFAILURE)

/** frame buffer: put vscreeninfo failure (0xB0038013). */
/** CNcomment: frame buffer, \C9\E8\D6ÿɱ\E4\D0\C5Ϣʧ\B0\DC 0xB0038013 */
#define HIGO_ERR_FB_PUT_VSCREENINFO_FAILURE         LAYER_DEF_ERR(ERR_LAYER_FB_PUTVSCREENINFOFAILURE)

/** frame buffer: get layer info failure (0xB0038014). */
/** CNcomment: frame buffer, \BB\F1ȡͼ\B2\E3\D0\C5Ϣʧ\B0\DC 0xB0038014 */
#define HIGO_ERR_FB_GET_LAYERINFO_FAILURE           LAYER_DEF_ERR(ERR_LAYER_FB_GETLAYERINFO)

/** frame buffer: put layer info failure (0xB0038015). */
/** CNcomment: frame buffer, \C9\E8\D6\C3ͼ\B2\E3\D0\C5Ϣʧ\B0\DC 0xB0038015 */
#define HIGO_ERR_FB_PUT_LAYERINFO_FAILURE           LAYER_DEF_ERR(ERR_LAYER_FB_PUTLAYERINFO)

/** frame buffer: get layer alpha failure (0xB0038016). */
/** CNcomment: frame buffer, \BB\F1ȡͼ\B2\E3alphaʧ\B0\DC 0xB0038016 */
#define HIGO_ERR_FB_GET_LAYERALPHA_FAILURE          LAYER_DEF_ERR(ERR_LAYER_FB_GETLAYERALPHA)

/** frame buffer: put layer alpha failure (0xB0038017). */
/** CNcomment: frame buffer, \C9\E8\D6\C3ͼ\B2\E3alphaʧ\B0\DC 0xB0038017 */
#define HIGO_ERR_FB_PUT_LAYERALPHA_FAILURE          LAYER_DEF_ERR(ERR_LAYER_FB_PUTLAYERALPHA)

/** frame buffer: wrong layre id (0xB0038018). */
/** CNcomment: frame buffer, \B4\ED\CE\F3\B5\C4ͼ\B2\E3ID 0xB0038018 */
#define HIGO_ERR_FB_WRONG_LAYER_ID                  LAYER_DEF_ERR(ERR_LAYER_FB_WRONG_LAYERID)

/** frame buffer: refresh failure (0xB0038019). */
/** CNcomment: frame buffer, ˢ\D0\C2ʧ\B0\DC 0xB0038019 */
#define HIGO_ERR_FB_REFRESH_FAILURE                 LAYER_DEF_ERR(ERR_LAYER_FB_REFRESHFAILURE)

/** frame buffer: get canvas buffer failure (0xB003801A). */
/** CNcomment: frame buffer, \BB\F1ȡCANVAS BUFFERʧ\B0\DC 0xB003801A */
#define HIGO_ERR_FB_GET_CANVAS_BUFFER_FAILURE       LAYER_DEF_ERR(ERR_LAYER_FB_GETCANVASBUFFER)

/** frame buffer: put canvas buffer failure (0xB003801B). */
/** CNcomment: frame buffer, \C9\E8\D6\C3CANVAS BUFFERʧ\B0\DC 0xB003801B */
#define HIGO_ERR_FB_PUT_CANVAS_BUFFER_FAILURE       LAYER_DEF_ERR(ERR_LAYER_FB_PUTCANVASBUFFER)

/** frame buffer: get zorder failure (0xB003801C). */
/** CNcomment: frame buffer, \BB\F1ȡzorderʧ\B0\DC 0xB003801C */
#define HIGO_ERR_FB_GET_ZORDER_FAILURE              LAYER_DEF_ERR(ERR_LAYER_FB_GETZORDER)

/** frame buffer: put zorder failure (0xB003801D). */
/** CNcomment: frame buffer, \C9\E8\D6\C3zorderʧ\B0\DC 0xB003801D */
#define HIGO_ERR_FB_PUT_ZORDER_FAILURE              LAYER_DEF_ERR(ERR_LAYER_FB_PUTZORDER)


/**Error codes of the HiGo Bliter module*/
/** CNcomment:HiGo bliterģ\BF\E9\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_BLITER_INVCOMPTYPE = 0,
    ERR_BLITER_INVCKEYTYPE,
    ERR_BLITER_INVMIRRORTYPE,
    ERR_BLITER_INVROTATETYPE,
    ERR_BLITER_INVROPTYPE,
    ERR_BLITER_INVSCALING,
    ERR_BLITER_OUTOFBOUNDS,
    ERR_BLITER_EMPTYRECT,
    ERR_BLITER_OUTOFPAL,
    ERR_BLITER_NOP,
    ERR_BLITER_BUTT
} HIGO_BLITER_ERR_S;

/**The blending mode is incorrect (0xB0048000).*/
/** CNcomment:\B4\ED\CE\F3\B5Ļ\EC\BA\CFģʽ  0xB0048000 */
#define HIGO_ERR_INVCOMPTYPE HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVCOMPTYPE)

/**The colorkey operation is invalid (0xB0048001).*/
/** CNcomment:\CE\DEЧ\B5\C4colorKey\B2\D9\D7\F7 0xB0048001 */
#define HIGO_ERR_INVCKEYTYPE HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVCKEYTYPE)

/**The mirror operation is invalid (0xB0048002).*/
/** CNcomment:\CE\DEЧ\B5ľ\B5\CF\F1\B2\D9\D7\F7 0xB0048002 */
#define HIGO_ERR_INVMIRRORTYPE HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVMIRRORTYPE)

/**The rotation operation is invalid (0xB0048003).*/
/** CNcomment:\CE\DEЧ\B5\C4\D0\FDת\B2\D9\D7\F7 0xB0048003 */
#define HIGO_ERR_INVROTATETYPE HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVROTATETYPE)

/**The ROP operation is invalid (0xB0048004).*/
/** CNcomment:\CE\DEЧ\B5\C4ROP\B2\D9\D7\F7 0xB0048004 */
#define HIGO_ERR_INVROPTYPE HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVROPTYPE)

/**The scaling is abnormal (0xB0048005).*/
/** CNcomment:\CB\F5\B7ű\C8\C0\FD\D2쳣 0xB0048005 */
#define HIGO_ERR_INVSCALING HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_INVSCALING)

/**The rectangle exceeds the boundary (0xB0048006).*/
/** CNcomment:\BE\D8\D0γ\AC\B3\F6\B1߽\E7 0xB0048006*/
#define HIGO_ERR_OUTOFBOUNDS HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_OUTOFBOUNDS)

/**The rectangle is empty (0xB0048007).*/
/** CNcomment:\BFվ\D8\D0\CE 0xB0048007*/
#define HIGO_ERR_EMPTYRECT HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_EMPTYRECT)

/**The palette does not contain this color (0xB0048008).*/
/** CNcomment:\D1\D5ɫ\B2\BB\D4ڵ\F7ɫ\B0\E5\D6\D0 0xB0048008*/
#define HIGO_ERR_OUTOFPAL HIGO_DEF_ERR(HIGO_MOD_BLITER, ERR_BLITER_OUTOFPAL)

/**Error codes of the HiGo decoder*/
/** CNcomment:HiGo decodeģ\BF\E9\B4\ED\CE\F3\C2\EB*/
typedef enum
{
    ERR_DEC_INVIMAGETYPE = 0,
    ERR_DEC_INVINDEX,
    ERR_DEC_INVIMGDATA,
    ERR_DEC_BUTT
} HIGO_ERR_DEC_E;

/**<The picture format is invalid (0xB0058000).*/
/**<CNcomment:\CE\DEЧ\B5\C4ͼƬ\C0\E0\D0\CD 0xB0058000 */
#define HIGO_ERR_INVIMAGETYPE HIGO_DEF_ERR(HIGO_MOD_DEC, ERR_DEC_INVIMAGETYPE)

/**<The picture index number is invalid (0xB0058001).*/
/**<CNcomment:\CE\DEЧͼƬ\CB\F7\D2\FD\BA\C5 0xB0058001 */
#define HIGO_ERR_INVINDEX HIGO_DEF_ERR(HIGO_MOD_DEC, ERR_DEC_INVINDEX)

/**<The picture data is invalid (0xB0058002).*/
/**<CNcomment:\CE\DEЧͼƬ\CA\FD\BE\DD 0xB0058002 */
#define HIGO_ERR_INVIMGDATA HIGO_DEF_ERR(HIGO_MOD_DEC, ERR_DEC_INVIMGDATA)

/**Error codes of the HiGo textout module*/
/** CNcomment:HiGo textoutģ\BF\E9\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_TEXTOUT_INVRECT = 0,
    ERR_TEXTOUT_UNSUPPORT_CHARSET,
    ERR_TEXTOUT_ISUSING,
    ERR_TEXTOUT_NOIMPLEMENT,
    ERR_TEXTOUT_SHAPE,
    ERR_TEXTOUT_MAX_CHAR,
    ERR_TEXTOUT_CHAR_SET,
    ERR_TEXTOUT_BIDI,
    ERR_TEXTOUT_ERRCODE_MAX = 0x1F,
    ERR_TEXTOUT_INTERNAL = 0,
    ERR_TEXTOUT_BUTT
} HIGO_TEXTOUT_ERR_S;

/**The rectangle region is invalid (0xB0068000).*/
/** CNcomment:\CE\DEЧ\B5ľ\D8\D0\CE\C7\F8\D3\F2 0xB0068000 */
#define HIGO_ERR_INVRECT HIGO_DEF_ERR(HIGO_MOD_TEXTOUT,ERR_TEXTOUT_INVRECT)

/**The character set is not supported (0xB0068001).*/
/** CNcomment:\B2\BB֧\B3ֵ\C4\D7ַ\FB\BC\AF 0xB0068001*/
#define HIGO_ERR_UNSUPPORT_CHARSET HIGO_DEF_ERR(HIGO_MOD_TEXTOUT,ERR_TEXTOUT_UNSUPPORT_CHARSET)

/**The character set is not supported (0xB0068002).*/
/** CNcomment:\B2\BB֧\B3ֵ\C4\D7ַ\FB\BC\AF 0xB0068002*/
#define HIGO_ERR_ISUSING HIGO_DEF_ERR(HIGO_MOD_TEXTOUT,ERR_TEXTOUT_ISUSING)
/**The function not implement yet (0xB0068003) */
/** CNcomment:\B8ú\AF\CA\FD\C9\D0δʵ\CF\D6 0xB0068003 */
#define HIGO_ERR_NOIMPLEMENT  HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_NOIMPLEMENT);
/**Shape Failed (0xB0068004) */
/** CNcomment:\D5\FB\D0\CEʧ\B0\DC 0xB0068004 */
#define HIGO_ERR_SHAPEFAILED HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_SHAPE);

/**Number of characters greater than limit (0xB0068005) */
/** CNcomment:\D7ַ\FB\CA\FD\C1\BF\B9\FD\B6\E0 0xB0068005 */
#define HIGO_ERR_MAX_CHAR HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_MAX_CHAR);

/**Char set error (0xB0068006) */
/** CNcomment:\D7ַ\FB\BC\AF\B1\E0\C2\EB\B4\ED\CE\F3 0xB0068006 */
#define HIGO_ERR_CHAR_SET HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_CHAR_SET);

/**bi-directional process erro(0xB)068007) */
/** CNcomment:˫\CF\F2\B4\A6\C0\ED\B4\ED\CE\F3 0xB0068006 */
#define HIGO_ERROR_BIDI HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_BIDI);

/**Internal error (0xB006801F) */
/** CNcomment:\C4ڲ\BF\B4\ED\CE\F3 0xB006801F */
#define HIGO_ERR_TEXTINTERNAL HIGO_DEF_ERR(HIGO_MOD_TEXTOUT, ERR_TEXTOUT_INTERNAL)

/**Error codes of the HiGo Winc module*/
/** CNcomment:HiGo Wincģ\BF\E9\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_WINC_ALREADYBIND = 0, /**<The Winc module has been attached.*//**<CNcomment:\D2Ѿ\AD\B1\BB\B0\F3\B6\A8 */
    ERR_WINC_INVZORDERTYPE,   /**<The z-order adjustment mode is invalid.*//**<CNcomment:\CE\DEЧ\B5\C4Z\D0\F2\B5\F7\D5\FB\B7\BDʽ */
    ERR_WINC_NOUPDATE,        /**<The desktop is not refreshed.*//**<CNcomment:\D7\C0\C3\E6\CE޸\FC\D0\C2 */
    ERR_WINC_INVPF,           /**<The pixel format is invalid.*//**<CNcomment:\CE\DEЧ\B5\C4\CF\F1\CBظ\F1ʽ */
    ERR_WINC_INVTREE,           /**<The window tree is invalid.*//**<CNcomment:\CE\DEЧ\B5Ĵ\B0\BF\DA\CA\F7 */
    ERR_WINC_ALREADYSETMODE,    /**<The window already be set mode.*//**<CNcomment:\D2Ѿ\AD\C9趨\B4\B0\BF\DA\C4ڴ\E6ģʽ*/
    ERR_WINC_BUTT
} HIGO_ERR_WINC_E;

/**The desktop has been attached to a graphics layer (0xB0078000).*/
/** CNcomment:\D7\C0\C3\E6\D3\EBͼ\B2\E3\D2Ѿ\AD\B0\F3\B6\A8 0xB0078000 */
#define HIGO_ERR_ALREADYBIND HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_ALREADYBIND)

/**The z-order adjustment mode is invalid (0xB0078001).*/
/** CNcomment:\CE\DEЧ\B5\C4Z\D0\F2\B5\F7\D5\FB\B7\BDʽ 0xB0078001 */
#define HIGO_ERR_INVZORDERTYPE HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_INVZORDERTYPE)

/**The desktop is not refreshed (0xB0078002).*/
/** CNcomment:\D7\C0\C3\E6\CE޸\FC\D0\C2 0xB0078002 */
#define HIGO_ERR_NOUPDATE HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_NOUPDATE)

/**The desktop is not refreshed (0xB0078003).*/
/** CNcomment:\D7\C0\C3\E6\CE޸\FC\D0\C2 0xB0078003 */
#define HIGO_ERR_INVPF HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_INVPF)

/**The desktop is not refreshed (0xB0078004).*/
/** CNcomment:\D7\C0\C3\E6\CE޸\FC\D0\C2 0xB0078004 */
#define HIGO_ERR_INVTREE HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_INVTREE)

/**The window already be set mode (0xB0078005).*/
/** CNcomment:\D2Ѿ\AD\C9趨\B4\B0\BF\DA\C4ڴ\E6ģʽ 0xB0078005 */
#define HIGO_ERR_ALREADYSETMODE HIGO_DEF_ERR(HIGO_MOD_WINC, ERR_WINC_ALREADYSETMODE)

/**Error codes of the HiGo surface module*/
/** CNcomment:HiGo Cursorģ\BF\E9\B4\ED\CE\F3\C2\EB */
typedef enum
{
    ERR_CURSOR_INVHOTSPOT = 0,
    ERR_CURSOR_NOCURSORINFO,
    ERR_CURSOR_BUTT
} HIGO_CURSOR_ERR_E;

/**The hot spot coordinate of the cursor is invalid (0xB0088000).*/
/** CNcomment:\CE\DEЧ\B5\C4cursor\C8ȵ\E3\D7\F8\B1\EA 0xB0088000 */
#define HIGO_ERR_INVHOTSPOT  HIGO_DEF_ERR(HIGO_MOD_CURSOR, ERR_CURSOR_INVHOTSPOT)

/**The cursor information is not set (0xB0088001).*/
/** CNcomment:û\D3\D0\C9\E8\D6\C3cursor\D0\C5Ϣ 0xB0088001 */
#define HIGO_ERR_NOCURSORINF HIGO_DEF_ERR(HIGO_MOD_CURSOR, ERR_CURSOR_NOCURSORINFO)

/** @} */  /*! <!-- Macro Definition end */



/*************************** Structure Definition ****************************/


/********************** Global Variable declaration **************************/


/******************************* API declaration *****************************/


#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_ERRNO_H__ */
