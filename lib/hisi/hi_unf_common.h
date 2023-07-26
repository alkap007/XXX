/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_common.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/17
  Description   :
  History       :
  1.Date        : 2009/12/17
    Author      : sdk
    Modification: Created file

*******************************************************************************/

#ifndef __HI_UNF_COMMON_H__
#define __HI_UNF_COMMON_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_common.h"
#include "hi_unf_audio.h"
#include "hi_unf_video.h"

/*************************** Structure Definition ****************************/
/** \addtogroup      Media_Common */
/** @{ */  /** <!-- [Media_Common] */

/**Defines the stream buffer.*/
/**CNcomment: \B6\A8\D2\E5\C2\EB\C1\F7\BB\BA\B3\E5\BDṹ\CC\E5 */
typedef struct hiUNF_STREAM_BUF_S
{
    HI_U8   *pu8Data;        /**<Data pointer*/ /**<CNcomment: \CA\FD\BE\DDָ\D5\EB */
    HI_U32  u32Size;         /**<Data size*/ /**<CNcomment: \CA\FD\BEݳ\A4\B6\C8 */
} HI_UNF_STREAM_BUF_S;

/**Defines the private Es buffer address.*/
typedef struct hiUNF_BUF_ADDR_S
{
        HI_U64 u64BufKerVirAddr;    /**<Es Buffer Kernel Virtual Address*/ /**<CNcomment: Buffer\C4ں\CB̬\D0\E9\C4\E2\B5\D8ַ*/
        HI_U64 u64BufPhyAddr;       /**<Es Buffer Physical Address*/ /**<CNcomment: Buffer\CE\EF\C0\ED\B5\D8ַ*/
}HI_UNF_BUF_ADDR_S;

/**Defines the structure of the ES buffer.*/
/**CNcomment: \B6\A8\D2\E5ES\C2\EB\C1\F7\BB\BA\B3\E5\BDṹ\CC\E5 */
typedef struct hiUNF_ES_BUF_S
{
    HI_U8 * pu8Buf;    /**<User-state virtual address of the buffer*/ /**<CNcomment: buffer\B5\C4\D3û\A7̬\D0\E9\B5\D8ַ*/
    HI_U32 u32BufLen;  /**<Buffer length*/ /**<CNcomment: buffer\B5ĳ\A4\B6\C8*/
    HI_U32 u32PtsMs;   /**<Presentation time stamp (PTS) value corresponding to the start of the stream. The invalid value is 0xFFFFFFFF.*/
                       /**<CNcomment: \C2\EB\C1\F7\BF\AAʼ\B4\A6\B6\D4Ӧ\B5\C4PTSֵ\A3\AC\CE\DEЧΪ0xffffffff*/
    HI_UNF_BUF_ADDR_S   stPriEsBufAddr;  /**<Private Es Buffer Address */ /**<CNcomment: Es buffer˽\D3е\D8ַ\D0\C5Ϣ */
}HI_UNF_ES_BUF_S;

/* Crop parameter */
typedef struct hiUNF_CROP_RECT_S
{
    HI_U32 u32LeftOffset;
    HI_U32 u32TopOffset;
    HI_U32 u32RightOffset;
    HI_U32 u32BottomOffset;
}HI_UNF_CROP_RECT_S;

/**Defines the signal status of the input source.*/
/**CNcomment: \B6\A8\D2\E5\CA\E4\C8\EBԴ\B5\C4\D0ź\C5״̬ */
typedef enum hiUNF_SIG_STATUS_E
{
    HI_UNF_SIG_SUPPORT = 0,  /**<Stable signal*/            /**<CNcomment:ʶ\B1\F0\CEȶ\A8\D0ź\C5 */
    HI_UNF_SIG_NO_SIGNAL,    /**<No signal*/                /**<CNcomment:\CE\DE\D0ź\C5 */
    HI_UNF_SIG_NOT_SUPPORT,  /**<Not support the signal*/   /**<CNcomment:\D0źŲ\BB֧\B3\D6 */
    HI_UNF_SIG_UNSTABLE,     /**<Unstable signal*/          /**<CNcomment:\D0źŲ\BB\CEȶ\A8 */
    HI_UNF_SIG_BUTT          /**<Invalid value*/            /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ */
} HI_UNF_SIG_STATUS_E;

/** @} */  /** <!-- ==== Structure Definition End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_COMMON_ H*/
