/******************************************************************************
Copyright (C), 2005-2018, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_debug.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2005/4/23
Description   : Common debugging macro definition
Function List :
History       :
******************************************************************************/
#ifndef __HI_DEBUG_H__
#define __HI_DEBUG_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#include "hi_type.h"
#include "hi_module.h"

#ifdef HI_LOG_SUPPORT
#define HI_DEBUG

#ifdef __KERNEL__
    #define HI_PRINT printk
    #define HI_PANIC printk
#else
#include <stdio.h>
    #define HI_PRINT printf
    #define HI_PANIC printf
#endif
#else
#undef HI_DEBUG

#define HI_PANIC(fmt...)    \
    do { \
    } while (0)

#define HI_PRINT(fmt...)    \
    do { \
    } while (0)
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup     HI_DEBUG */
/** @{ */  /** <!-- [HI_DEBUG] */


/**Default level of the output debugging information*/
/**CNcomment: Ĭ\C8ϵĵ\F7\CA\D4\D0\C5Ϣ\CA\E4\B3\F6\BC\B6\B1\F0*/
#define HI_LOG_LEVEL_DEFAULT HI_LOG_LEVEL_ERROR

/**Level of the output debugging information*/
/**CNcomment: \B5\F7\CA\D4\D0\C5Ϣ\CA\E4\B3\F6\BC\B6\B1\F0*/
typedef enum hiLOG_LEVEL_E
{
    HI_LOG_LEVEL_FATAL   = 0,     /**<Fatal error. It indicates that a critical problem occurs in the system. Therefore, you must pay attention to it.*/
                                  /**<CNcomment: \D6\C2\C3\FC\B4\ED\CE\F3, \B4\CB\C0\E0\B4\ED\CE\F3\D0\E8Ҫ\CCر\F0\B9\D8ע\A3\ACһ\B0\E3\B3\F6\CFִ\CB\C0\E0\B4\ED\CE\F3\B4\FA\B1\EDϵͳ\B3\F6\CF\D6\C1\CB\D6ش\F3\CE\CA\CC\E2 */
    HI_LOG_LEVEL_ERROR   = 1,     /**<Major error. It indicates that a major problem occurs in the system and the system cannot run.*/
                                  /**<CNcomment: һ\B0\E3\B4\ED\CE\F3, һ\B0\E3\B3\F6\CFִ\CB\C0\E0\B4\ED\CE\F3\B4\FA\B1\EDϵͳ\B3\F6\CF\D6\C1˱Ƚϴ\F3\B5\C4\CE\CA\CC⣬\B2\BB\C4\DC\D4\D9\D5\FD\B3\A3\D4\CB\D0\D0 */
    HI_LOG_LEVEL_WARNING = 2,     /**<Warning. It indicates that a minor problem occurs in the system, but the system still can run properly.*/
                                  /**<CNcomment: \B8澯\D0\C5Ϣ, һ\B0\E3\B3\F6\CFִ\CB\C0\E0\D0\C5Ϣ\B4\FA\B1\EDϵͳ\BF\C9\C4ܳ\F6\CF\D6\CE\CA\CC⣬\B5\AB\CAǻ\B9\C4ܼ\CC\D0\F8\D4\CB\D0\D0 */
    HI_LOG_LEVEL_INFO    = 3,     /**<Message. It is used to prompt users. Users can open the message when locating problems. It is recommended to disable this message in general.*/
                                  /**<CNcomment: \CC\E1ʾ\D0\C5Ϣ, һ\B0\E3\CA\C7Ϊ\CC\E1\D0\D1\D3û\A7\B6\F8\CA\E4\B3\F6\A3\AC\D4ڶ\A8λ\CE\CA\CC\E2\B5\C4ʱ\BA\F2\BF\C9\D2Դ򿪣\ACһ\B0\E3\C7\E9\BF\F6\CF½\A8\D2\E9\B9ر\D5 */
    HI_LOG_LEVEL_DBG     = 4,     /**<Debug. It is used to prompt developers. Developers can open the message when locating problems. It is recommended to disable this message in general.*/
                                  /**<CNcomment: \CC\E1ʾ\D0\C5Ϣ, һ\B0\E3\CA\C7Ϊ\BF\AA\B7\A2\C8\CBԱ\B5\F7\CA\D4\CE\CA\CC\E2\B6\F8\C9趨\B5Ĵ\F2ӡ\BC\B6\B1\F0\A3\ACһ\B0\E3\C7\E9\BF\F6\CF½\A8\D2\E9\B9ر\D5 */
    HI_LOG_LEVEL_TRACE   = 5,     /**<Trace. It is used to track the entry and exit of function when the interface is called.*/
                                  /**<CNcomment: \CC\E1ʾ\D0\C5Ϣ\A3\ACһ\B0\E3\D3\C3\D3ڸ\FA\D7ٽӿڵ\F7\D3\C3ʱ\BA\AF\CA\FD\B5Ľ\F8\C8\EB\D3\EB\CD˳\F6 */
    HI_LOG_LEVEL_BUTT
} HI_LOG_LEVEL_E;

/** @} */

/**Just only for fatal level print.   */   /**CNcomment: Ϊ\C1˴\F2ӡ\D6\C2\C3\FC\D0\C5Ϣ\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_FATAL    (0)
/**Just only for error level print.   */   /**CNcomment: Ϊ\C1˴\F2ӡ\B4\ED\CE\F3\D0\C5Ϣ\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_ERROR    (1)
/**Just only for warning level print. */   /**CNcomment: Ϊ\C1˴\F2ӡ\BE\AF\B8\E6\D0\C5Ϣ\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_WARN     (2)
/**Just only for info level print.    */   /**CNcomment: Ϊ\C1˴\F2ӡ\D0\C5Ϣ\BC\B6\B1\F0\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_INFO     (3)
/**Just only for debug level print.   */   /**CNcomment: Ϊ\C1˴\F2ӡ\B5\F7\CA\D4\D0\C5Ϣ\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_DBG      (4)
/**Just only for trace level print.   */   /**CNcomment: Ϊ\C1˴\F2ӡ\BDӿڸ\FA\D7\D9\D0\C5Ϣ\B6\F8\D6ƶ\A8\B5ĺ\EA\B4\F2ӡ\BC\B6\B1\F0 */
#define HI_TRACE_LEVEL_TRACE    (5)

#ifndef HI_LOG_LEVEL
#define HI_LOG_LEVEL         (HI_TRACE_LEVEL_INFO)
#endif


/**Just only debug output,MUST BE NOT calling it. */
/**CNcomment: \B5\F7\CA\D4\CA\E4\B3\F6\D0\C5Ϣ\BDӿڣ\AC\B2\BB\CDƼ\F6ֱ\BDӵ\F7\D3ô˽ӿ\DA */
extern HI_VOID HI_LogOut(HI_U32 u32Level, HI_MOD_ID_E enModId,
            HI_U8 *pFuncName, HI_U32 u32LineNum, const char *format, ...);

#ifdef HI_DEBUG

#define HI_TRACE(level, module_id, fmt...)                      \
    do{                                                         \
        HI_LogOut(level, module_id, (HI_U8*)__FUNCTION__,__LINE__,fmt);  \
    }while(0)

#define HI_ASSERT(expr)                                     \
    do{                                                     \
        if (!(expr)) {                                      \
            HI_PANIC("\nASSERT failed at:\n  >File name: %s\n  >Function : %s\n  >Line No. : %d\n  >Condition: %s\n", \
                __FILE__,__FUNCTION__, __LINE__, #expr);    \
        }                                                   \
    }while(0)


#define HI_ASSERT_RET(expr)                                     \
    do{                                                         \
        if (!(expr)) {                                          \
            HI_PRINT("\n<%s %d>: ASSERT Failure{" #expr "}\n",  \
                          __FUNCTION__, __LINE__);              \
            return HI_FAILURE;                                  \
        }                                                       \
    }while(0)

#define HI_DEBUG_LOG(fmt...) \
            HI_TRACE(HI_LOG_LEVEL_INFO, HI_ID_SYS, fmt)


/**Supported for debug output to serial/network/u-disk. */
/**CNcomment: \B8\F7\B8\F6ģ\BF\E9\D0\E8Ҫ\B5\F7\D3\C3\D2\D4\CFº\EA\BD\F8\D0\D0\CA\E4\B3\F6\B5\F7\CA\D4\D0\C5Ϣ\A1\A2\BF\C9\CA\E4\B3\F6\B5\BD\B4\AE\BFڡ\A2\CD\F8\BFڡ\A2U\C5̴洢\B5\C8 */
/**Just only reserve the fatal level output. */
/**CNcomment: \BD\F6\BD\F6\B1\A3\C1\F4\D6\C2\C3\FC\B5ĵ\F7\CA\D4\D0\C5Ϣ */
#if (HI_LOG_LEVEL == HI_TRACE_LEVEL_FATAL)
#define HI_FATAL_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_FATAL,    module_id, fmt)
#define HI_ERR_PRINT(  module_id, fmt...)
#define HI_WARN_PRINT( module_id, fmt...)
#define HI_INFO_PRINT( module_id, fmt...)
#define HI_DBG_PRINT(  module_id, fmt...)
#define HI_TRACE_PRINT(module_id, fmt...)
/**Just only reserve the fatal/error level output. */
/**CNcomment: \BD\F6\BD\F6\B1\A3\C1\F4\D6\C2\C3\FC\B5ĺʹ\ED\CE󼶱\F0\B5ĵ\F7\CA\D4\D0\C5Ϣ */
#elif (HI_LOG_LEVEL == HI_TRACE_LEVEL_ERROR)
#define HI_FATAL_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_FATAL,    module_id, fmt)
#define HI_ERR_PRINT(  module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_ERROR,    module_id, fmt)
#define HI_WARN_PRINT( module_id, fmt...)
#define HI_INFO_PRINT( module_id, fmt...)
#define HI_DBG_PRINT(  module_id, fmt...)
#define HI_TRACE_PRINT(module_id, fmt...)
/**Just only reserve the fatal/error/warning level output. */
/**CNcomment: \BD\F6\BD\F6\B1\A3\C1\F4\D6\C2\C3\FC\B5ġ\A2\B4\ED\CE\F3\B5ġ\A2\BE\AF\B8漶\B1\F0\B5ĵ\F7\CA\D4\D0\C5Ϣ */
#elif (HI_LOG_LEVEL == HI_TRACE_LEVEL_WARN)
#define HI_FATAL_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_FATAL,    module_id, fmt)
#define HI_ERR_PRINT(  module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_ERROR,    module_id, fmt)
#define HI_WARN_PRINT( module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_WARN,     module_id, fmt)
#define HI_INFO_PRINT( module_id, fmt...)
#define HI_DBG_PRINT(  module_id, fmt...)
#define HI_TRACE_PRINT(module_id, fmt...)
/**Just only reserve the fatal/error/warning/info level output. */
/**CNcomment: \BD\F6\BD\F6\B1\A3\C1\F4\D6\C2\C3\FC\B5ġ\A2\B4\ED\CE\F3\B5ġ\A2\BE\AF\B8\E6\BA\CD\D0\C5Ϣ\BC\B6\B1\F0\B5ĵ\F7\CA\D4\D0\C5Ϣ */
#elif (HI_LOG_LEVEL == HI_TRACE_LEVEL_INFO)
#define HI_FATAL_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_FATAL,    module_id, fmt)
#define HI_ERR_PRINT(  module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_ERROR,    module_id, fmt)
#define HI_WARN_PRINT( module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_WARN,     module_id, fmt)
#define HI_INFO_PRINT( module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_INFO,     module_id, fmt)
#define HI_DBG_PRINT(  module_id, fmt...)
#define HI_TRACE_PRINT(module_id, fmt...)
#else
/**Reserve all the levels output. */
/**CNcomment: \B1\A3\C1\F4\CB\F9\D3м\B6\B1\F0\B5\F7\CA\D4\D0\C5Ϣ */
#define HI_FATAL_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_FATAL,    module_id, fmt)
#define HI_ERR_PRINT(  module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_ERROR,    module_id, fmt)
#define HI_WARN_PRINT( module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_WARN,     module_id, fmt)
#define HI_INFO_PRINT( module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_INFO,     module_id, fmt)
#define HI_DBG_PRINT(  module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_DBG,      module_id, fmt)
#define HI_TRACE_PRINT(module_id, fmt...)   HI_TRACE(HI_TRACE_LEVEL_TRACE,    module_id, fmt)
#endif

#else
#define HI_FATAL_PRINT(module_id, fmt...)
#define HI_ERR_PRINT(  module_id, fmt...)
#define HI_WARN_PRINT( module_id, fmt...)
#define HI_INFO_PRINT( module_id, fmt...)
#define HI_DBG_PRINT(  module_id, fmt...)
#define HI_TRACE_PRINT(module_id, fmt...)

#define HI_TRACE(level, module_id, fmt...)
#define HI_ASSERT(expr)
#define HI_ASSERT_RET(expr)
#define HI_DEBUG_LOG(fmt...)
#endif /* endif HI_DEBUG */

/** @} */  /** <!-- ==== Structure Definition End ==== */


#define MKSTR(exp) # exp
#define MKMARCOTOSTR(exp) MKSTR(exp)
#define VERSION_STRING ("SDK_VERSION: [" MKMARCOTOSTR(SDK_VERSION) "] Build Time: [" __DATE__ ", " __TIME__ "]")
#define USER_VERSION_STRING ("SDK_VERSION: [" MKMARCOTOSTR(SDK_VERSION) "]")

/**Initialize a user module.*/
/**CNcomment: \D3û\A7ģ\BF\E9\B3\F5ʼ\BB\AF */
#define HI_MODULE_DECLARE(MODULE_NAME)	\
	static HI_U32 g_u32ModuleId = HI_INVALID_MODULE_ID;	\
	static HI_S32 __attribute__((constructor(200))) init_module_id() \
	{	 \
		return HI_MODULE_RegisterByName(MODULE_NAME, &g_u32ModuleId); \
	} \
    static HI_S32 __attribute__((destructor(200))) deinit_module_id() \
    { \
        return HI_MODULE_UnRegister(g_u32ModuleId); \
    }

/**Defines a user module ID.*/
/**CNcomment: \D3û\A7ģ\BF\E9ID\BA궨\D2\E5 */
#define MODULE_ID (g_u32ModuleId)

/**Defines the command of the user module different level log print.*/
/**CNcomment: \D3û\A7ģ\BF\E9\C8\D5־\CA\E4\B3\F6\BA궨\D2\E5 */
#define HI_MODULE_FATAL(pszFormat...)  HI_FATAL_PRINT(MODULE_ID,pszFormat)
#define HI_MODULE_ERROR(pszFormat...)  HI_ERR_PRINT(MODULE_ID,pszFormat)
#define HI_MODULE_WARN(pszFormat...)   HI_WARN_PRINT(MODULE_ID,pszFormat)
#define HI_MODULE_DEBUG(pszFormat...)  HI_DBG_PRINT(MODULE_ID,pszFormat)
#define HI_MODULE_INFO(pszFormat...)   HI_INFO_PRINT(MODULE_ID,pszFormat)

/**Defines the memory allocate and free command used by user module.*/
/**CNcomment: \D3û\A7ģ\BF\E9\C4ڴ\E6\B7\D6\C5\E4\BA궨\D2\E5 */
#define HI_MODULE_MALLOC(u32Size)               HI_MEM_Malloc(MODULE_ID, u32Size)
#define HI_MODULE_FREE(pMemAddr)                HI_MEM_Free(MODULE_ID, pMemAddr)
#define HI_MODULE_CALLOC(u32MemBlock, u32Size)  HI_MEM_Calloc(MODULE_ID, u32MemBlock, u32Size)


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_DEBUG_H__ */

