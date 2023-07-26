/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-15
 */

#ifndef __HI_USER_PROC_H__
#define __HI_USER_PROC_H__

#include "hi_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Defines user mode proc show buffer
 * CNcomment: \D3û\A7̬PROC buffer\B6\A8\D2\E5
 */
typedef struct hiPROC_SHOW_BUFFER_S {
    HI_U8 *pu8Buf;    /* Buffer address */ /* CNcomment: Buffer\B5\D8ַ */
    HI_U32 u32Size;   /* Buffer size */    /* CNcomment: Buffer\B4\F3С */
    HI_U32 u32Offset; /* Offset */         /* CNcomment: \B4\F2ӡƫ\D2Ƶ\D8ַ */
} HI_PROC_SHOW_BUFFER_S;

/*
 * Proc show function
 * CNcomment: Proc\D0\C5Ϣ\CF\D4ʾ\BBص\F7\BA\AF\CA\FD
 */
typedef HI_S32 (* HI_PROC_SHOW_FN)(HI_PROC_SHOW_BUFFER_S *pstBuf, HI_VOID *pPrivData);

/*
 * Proc command function
 * CNcomment: Proc\BF\D8\D6ƻص\F7\BA\AF\CA\FD
 */
typedef HI_S32 (* HI_PROC_CMD_FN)(HI_PROC_SHOW_BUFFER_S *pstBuf, HI_U32 u32Argc, HI_U8 *pu8Argv[], HI_VOID *pPrivData);

/*
 * Defines user mode proc entry
 * CNcomment: \D3û\A7̬PROC\C8\EB\BFڶ\A8\D2\E5
 */
typedef struct hiPROC_ENTRY_S {
    HI_CHAR *pszEntryName;       /* Entry name */            /* CNcomment: \C8\EB\BF\DA\CEļ\FE\C3\FB */
    HI_CHAR *pszDirectory;       /* Directory name. If null, the entry will be added to /proc/hisi/ */ /* CNcomment: Ŀ¼\C3\FB\A3\AC\C8\E7\B9\FBΪ\BFգ\AC\BD\AB\B4\B4\BD\A8\B5\BD/proc/hisiĿ¼\CF\C2 */
    HI_PROC_SHOW_FN pfnShowProc; /* Proc show function */    /* CNcomment: Proc\D0\C5Ϣ\CF\D4ʾ\BBص\F7\BA\AF\CA\FD */
    HI_PROC_CMD_FN pfnCmdProc;   /* Proc command function */ /* CNcomment: Proc\BF\D8\D6ƻص\F7\BA\AF\CA\FD */
    HI_VOID *pPrivData;          /* Private data */          /* CNcomment: Buffer\B5\D8ַ */
} HI_PROC_ENTRY_S;

/*
 * brief User mode proc cretea directory. CNcomment:\D3û\A7̬proc\B4\B4\BD\A8Ŀ¼ CNend
 * attention You need register module before calling this API. Only support create one level directory. CNcomment:\D0\E8Ҫ\CF\C8ע\B2\E1ģ\BF飬ֻ֧\B3ִ\B4\BD\A8һ\BC\B6Ŀ¼ CNend
 * param[in] pszName The directory name. CNcomment:Ŀ¼\C3\FB CNend
 * param[out] None CNcomment:\CE\DE CNend
 * retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 * retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment:\CE\DE CNend
 */
HI_S32 HI_PROC_AddDir(const HI_CHAR *Name);

/*
 * brief User mode proc remove directory. CNcomment:\D3û\A7̬procɾ\B3\FDĿ¼ CNend
 * attention It will return fail if there are entries in the directory. CNcomment:\C8\E7\B9\FBĿ¼\CF»\B9\D3\D0\C8\EB\BF\DA\CEļ\FE,\BD\AB\BB\E1ɾ\B3\FDʧ\B0\DC CNend
 * param[in] pszName The directory name. CNcomment:Ŀ¼\C3\FB CNend
 * retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 * retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment:\CE\DE CNend
 */
HI_S32 HI_PROC_RemoveDir(const HI_CHAR *Name);

/*
 * brief User mode proc add entry. CNcomment:\D3û\A7̬proc\B4\B4\BD\A8\C8\EB\BF\DA CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] u32ModuleID Module ID. CNcomment:ģ\BF\E9ID CNend
 * param[in] pstEntry Parameter of entry. CNcomment:\B4\B4\BD\A8\C8\EB\BFڲ\CE\CA\FD CNend
 * retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 * retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment:\CE\DE CNend
 */
HI_S32 HI_PROC_AddEntry(HI_U32 ModuleID, const HI_PROC_ENTRY_S *Entry);

/*
 * brief User mode proc remove entry. CNcomment:\D3û\A7̬procɾ\B3\FD\C8\EB\BF\DA CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] u32ModuleID Module ID. CNcomment:ģ\BF\E9ID CNend
 * param[in] pstEntry Parameter of entry. CNcomment:ɾ\B3\FD\C8\EB\BFڲ\CE\CA\FD CNend
 * retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 * retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment:\CE\DE CNend
 */
HI_S32 HI_PROC_RemoveEntry(HI_U32 ModuleID, const HI_PROC_ENTRY_S *Entry);

/*
 * brief User mode proc print function. CNcomment:\D3û\A7̬proc\B4\F2ӡ\C4\DA\C8ݵĺ\AF\CA\FD CNend
 * attention \n
 * N/A CNcomment: \CE\DE CNend
 * param[in] pstBuf Output buffer parameter. CNcomment:\CA\E4\B3\F6buffer\B2\CE\CA\FD CNend
 * param[in] pFmt   Format parameter. CNcomment:\B4\F2ӡ\B8\F1ʽ\BB\AF\B2\CE\CA\FD CNend
 * retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 * retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
 * see \n
 * N/A CNcomment:\CE\DE CNend
 */
HI_S32 HI_PROC_Printf(HI_PROC_SHOW_BUFFER_S *ShowBuf, const HI_CHAR *Fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* __HI_USER_PROC_H__ */
