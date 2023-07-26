/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-15
 */

#ifndef __HI_MEMORY_H__
#define __HI_MEMORY_H__

#include "hi_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************Structure declaration *****************************/
/** @addtogroup     MEMOYR */
/** @{ */ /** <!--  [MEMOYR] */

/** Maximum bytes of a buffer name */
#define MAX_BUFFER_NAME_SIZE 16

/**Structure of an MMZ buffer*/
typedef struct hiMMZ_BUF_S
{
    HI_CHAR bufname[MAX_BUFFER_NAME_SIZE];  /**<Strings of an MMZ buffer name*/ /**<CNcomment:  MMZ buffer\C3\FB\D7\D6\D7ַ\FB\B4\AE */
    HI_U32  phyaddr;                /**<Physical address of an MMZ buffer*/ /**<CNcomment:  MMZ buffer\CE\EF\C0\ED\B5\D8ַ */
    HI_U8  *kernel_viraddr;         /**<Kernel-state virtual address of an MMZ buffer*/ /**<CNcomment:  MMZ buffer\C4ں\CB̬\D0\E9\C4\E2\B5\D8ַ */
    HI_U8  *user_viraddr;           /**<User-state virtual address of an MMZ buffer*/ /**<CNcomment:  MMZ buffer\D3û\A7̬\D0\E9\C4\E2\B5\D8ַ */
    HI_U32  bufsize;                /**<Size of an MMZ buffer*/ /**<CNcomment:  MMZ buffer\B4\F3С */
    HI_U32  overflow_threshold;     /**<Overflow threshold of an MMZ buffer, in percentage. For example, the value 100 indicates 100%.*/ /**<CNcomment:  MMZ buffer\C9\CF\D2\E7ˮ\CFߣ\AC\B0\B4\B0ٷֱ\C8\C9\E8\D6ã\AC\C0\FD\C8\E7: 100 indicates 100%.*/
    HI_U32  underflow_threshold;    /**<Underflow threshold of an MMZ buffer, in percentage. For example, the value 0 indicates 0%.*/ /**<CNcomment:  MMZ buffer\CF\C2\D2\E7ˮ\CFߣ\AC\B0\B4\B0ٷֱ\C8\C9\E8\D6ã\AC\C0\FD\C8\E7: 0 indicates 0%.*/
} HI_MMZ_BUF_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      MEMOYR */
/** @{ */  /** <!-- [MEMOYR] */

/**
@brief Applies for a media memory zone (MMZ) and maps the user-state address.
CNcomment:  \C9\EA\C7\EBmmz\C4ڴ棬\B2\A2ӳ\C9\E4\D3û\A7̬\B5\D8ַ CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in/out] pstBuf Structure of the buffer information. Bufname and bufsize are inputs, and the physical address and user-state virtual address are outputs.
                    CNcomment: buffer\D0\C5Ϣ\BDṹ\A3\ACbufname\BA\CDbufsize\D7\F7Ϊ\CA\E4\C8\EB,\CE\EF\C0\ED\B5\D8ַ\BA\CD\D3û\A7̬\D0\E9\C4\E2\B5\D8ַ\D7\F7Ϊ\CA\E4\B3\F6 CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_Malloc(HI_MMZ_BUF_S *pstBuf);

/**
@brief Unmaps the user-state address and releases the MMZ. CNcomment: \BD\E2\B3\FD\D3û\A7̬\B5\D8ַ\B5\C4ӳ\C9䣬\B2\A2\CAͷ\C5mmz\C4ڴ\E6 CNend
@attention \n
Ensure that the lengths of the transferred physical address and user-state virtual address are correct.
CNcomment: \B1\A3֤\B4\AB\C8\EB\B5\C4\CE\EF\C0\ED\B5\D8ַ\A1\A2\D3û\A7̬\D0\E9\C4\E2\B5\D8ַ\BAͳ\A4\B6\C8\D5\FDȷ CNend
@param[in] pstBuf Structure of the buffer information CNcomment: buffer\D0\C5Ϣ\BDṹ CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_Free(HI_MMZ_BUF_S *pstBuf);

/**
@brief pplies for an MMZ with a specified name and obtains its physical address. CNcomment: ָ\B6\A8mmz\B5\C4\C3\FB\D7\D6\C9\EA\C7\EBmmz\C4ڴ棬\B7\B5\BB\D8\CE\EF\C0\ED\B5\D8ַ CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in] u32Size Buffer size CNcomment: buffer\B4\F3С CNend
@param[in] u32Align Alignment mode CNcomment: \B6\D4\C6뷽ʽ CNend
@param[in] ps8MMZName Name of an MMZ in the buffer. If the MMZ name is set to NULL, an MMZ is anonymously applied for. CNcomment: buffer\B7\D6\C7\F8\B5\C4\C3\FB\D7֣\AC\B4\AB\C8\EBNULL\C4\E4\C3\FB\C9\EA\C7\EB CNend
@param[in] ps8BufName Buffer name CNcomment: buffer\BF\E9\B5\C4\C3\FB\D7\D6 CNend
@retval ::NULL The application fails. CNcomment: \C9\EA\C7\EBʧ\B0\DC CNend
@retval Physical address CNcomment: \CE\EF\C0\ED\B5\D8ַ CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_VOID *HI_MMZ_New(HI_U32 u32Size , HI_U32 u32Align, HI_CHAR *ps8MMZName, HI_CHAR *ps8BufName);


/**
@brief Releases an MMZ based on its physical address. CNcomment: ͨ\B9\FD\CE\EF\C0\ED\B5\D8ַ\CAͷ\C5mmz\C4ڴ\E6 CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in] u32PhysAddr Physical address of a buffer CNcomment: buffer\CE\EF\C0\ED\B5\D8ַ CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_Delete(HI_U32 u32PhysAddr);

/**
@brief Maps the physical address of an MMZ applied for to a user-state virtual address. You can determine whether to cache the address.
CNcomment: \BD\ABmmz\C9\EA\C7\EB\B5\C4\CE\EF\C0\ED\B5\D8ַӳ\C9\E4\B3\C9\D3û\A7̬\D0\E9\C4\E2\B5\D8ַ\A3\AC\BF\C9\D2\D4ָ\B6\A8\CAǷ\F1cached CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in] u32PhysAddr Physical address of a buffer CNcomment: buffer\CE\EF\C0\ED\B5\D8ַ CNend
@param[in] u32Cached Whether to cache the address. 0: no; 1: yes CNcomment: \CAǷ\F1ʹ\D3\C3cache\A3\AC0\B2\BBʹ\D3ã\AC1ʹ\D3\C3 CNend
@retval ::NULL The application fails. CNcomment: \C9\EA\C7\EBʧ\B0\DC CNend
@retval User-state virtual address CNcomment: \D3û\A7̬\D0\E9\B5\D8ַ CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_VOID *HI_MMZ_Map(HI_U32 u32PhysAddr, HI_U32 u32Cached);

/**
@brief Unmaps the user-state address of an MMZ. CNcomment: \BD\E2\B3\FDmmz\C4ڴ\E6\D3û\A7̬\B5\D8ַ\B5\C4ӳ\C9\E4 CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in] u32PhysAddr Physical address of a buffer CNcomment: buffer\CE\EF\C0\ED\B5\D8ַ CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_Unmap(HI_U32 u32PhysAddr);


/**
@brief Flushes D-cache to the cached MMZ. CNcomment: \B6\D4\D3\DAcached\C0\E0\D0\CDMMZ\A3\ACˢDcache\B5\BD\C4ڴ\E6 CNend
@attention \n
refreshed transferred u32PhysAddr memory, the value 0 of u32PhysAddr is invalid.
CNcomment: ˢ\D0\C2u32PhysAddr\C6\F0ʼ\B5\C4\C4ڴ\E6\BF\E9 \A3\ACu32PhysAddr\B2\BB\D4\CA\D0\EDΪ0 CNend
@param[in] u32PhysAddr Physical address of a buffer CNcomment: buffer\CE\EF\C0\ED\B5\D8ַ CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_Flush(HI_U32 u32PhysAddr);


/**
@brief Obtains the physical address and size based on the virtual address. CNcomment: \B8\F9\BE\DD\D0\E9\C4\E2\B5\D8ַ\BB\F1ȡ\CE\EF\C0\ED\B5\D8ַ\A3\AC\D2Լ\B0\B4\F3С CNend
@attention \n
N/A CNcomment: \CE\DE CNend
@param[in] pVir User-state virtual address CNcomment: \D3û\A7̬\D0\E9\B5\D8ַ CNend
@param[out] pu32Phyaddr Physical address  CNcomment: \CE\EF\C0\ED\B5\D8ַ CNend
@param[out] pu32Size Size CNcomment: \B4\F3С CNend
@retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
@retval ::HI_FAILURE Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_S32 HI_MMZ_GetPhyaddr(HI_VOID * pVir, HI_U32 *pu32Phyaddr, HI_U32 *pu32Size);

/**
@brief malloc the pointed size from system heap. CNcomment:\B4\D3ϵͳ\D6з\D6\C5\E4ָ\B6\A8\B4\F3С\B5\C4\C4ڴ\E6 CNend
@attention None CNcomment:\CE\DE CNend
@param[in] u32ModuleID The module ID, who need to request memory. CNcomment:ģ\BF\E9ID CNend
@param[in] u32Size The size of requesting. CNcomment:\C7\EB\C7\F3\B7\D6\C5\E4\B5Ĵ\F3С\A3\AC\B5\A5λ\CA\C7\D7ֽ\DA CNend
@param[out] None CNcomment:\CE\DE CNend
@retval ::Valid memory address Success CNcomment:\B3ɹ\A6\B7\B5\BBط\D6\C5䵽\B5Ŀռ\E4\CA׵\D8ַ CNend
@retval ::NULL Failure CNcomment:ʧ\B0ܷ\B5\BB\D8NULL CNend
@see \n
N/A CNcomment:\CE\DE CNend
*/
HI_VOID* HI_MEM_Malloc(HI_U32 u32ModuleID, HI_U32 u32Size);


/**
@brief Free the requsted memory by hi_malloc. CNcomment:\CAͷŷ\D6\C5\E4\B5\C4\C4ڴ\E6 CNend
@attention when stopping to use the memory, calling this interface. CNcomment:\B2\BB\D4\D9\D0\E8Ҫ\D5\E2\BF\E9\C4ڴ\E6ʱ\A3\ACʹ\D3ô˽ӿڽ\F8\D0\D0\CAͷ\C5 CNend
@param[in] u32ModuleID The module ID, who need to free memory. CNcomment:ģ\BF\E9ID CNend
@param[in] pMemAddr The memory address to free CNcomment:\CAͷſռ\E4\B5\C4\CA׵\D8ַ CNend
@param[out] None CNcomment:\CE\DE CNend
@retval ::None CNcomment:\CE\DE CNend
@see \n
N/A CNcomment:\CE\DE CNend
*/
HI_VOID HI_MEM_Free(HI_U32 u32ModuleID, HI_VOID* pMemAddr);

/**
@brief Calloc memory, with u32MemBlock blocks and u32Size size per. CNcomment:\B7\D6\C5\E4\C1\AC\D0\F8\B4\F3С\B5\C4\C4ڴ\E6\BF\E9 CNend
@attention None CNcomment:\CE\DE CNend
@param[in] u32ModuleID The module id, who need to calloc memory. CNcomment:ģ\BF\E9ID CNend
@param[in] u32MemBlock The requesting block number. CNcomment:\B7\D6\C5\E4\B5Ŀ\E9\CA\FD CNend
@param[in] u32Size The requesting size per block. CNcomment:ÿ\BF\E9\B5Ĵ\F3С\A3\AC\B5\A5λ\CA\C7\D7ֽ\DA CNend
@param[out] None CNcomment:\CE\DE CNend
@retval ::Valid memory address Success CNcomment:\B3ɹ\A6\D4򷵻ط\D6\C5䵽\B5\C4\C4ڴ\E6\CA׵\D8ַ CNend
@retval ::NULL Failure CNcomment:ʧ\B0ܷ\B5\BB\D8NULL CNend
@see \n
N/A CNcomment: \CE\DE CNend
*/
HI_VOID* HI_MEM_Calloc(HI_U32 u32ModuleID, HI_U32 u32MemBlock, HI_U32 u32Size);


/** @} */ /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
}
#endif

#endif /* __HI_MEMORY_H__ */

