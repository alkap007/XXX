/******************************************************************************

Copyright (C), 2004-2014, HiSilicon Technologies Co., Ltd.
******************************************************************************
File Name     : hi_unf_demux.h
Version       : Initial
Author        : HiSilicon multimedia software group
Created       : 2008-06-10
Last Modified :
Description   : HiSilicon DEMUX API declaration
Function List :
History       :
* Version   Date         Author                           Defect No.     Description
* main\1    2008-06-10   Jiang Lei (employee ID: 40671)     NULL         Created this file.
* main\2    2010-04-02   Jiang Lei (employee ID: 40671)     NULL         modified for HD series.
******************************************************************************/
/**
 * \file
 * \brief Describes the information about the DEMUX module.CNcomment:\CCṩDEMUX\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef __HI_UNF_DEMUX_H__
#define __HI_UNF_DEMUX_H__

#include "hi_unf_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      DEMUX */
/** @{ */  /** <!-- [DEMUX] */

/**Maximum depth of a filter. */
/**CNcomment:filter\D7\EE\B4\F3\C9\EE\B6\C8*/
#define DMX_FILTER_MAX_DEPTH            16
#define DMX_MAX_IDX_ACQUIRED_EACH_TIME  256

/**Defines the capability of the DEMUX module*/
/**CNcomment:\B6\A8\D2\E5DEMUXģ\BF\E9ҵ\CE\F1\B9\A6\C4ܽṹ\CC\E5*/
typedef struct hiUNF_DMX_CAPABILITY_S
{
    HI_U32 u32IFPortNum;        /**<Number of IF ports. */ /**< CNcomment: IF \B6˿\DA\CA\FD\C1\BF  (\D3\EBTS In \B6˿ڶ\BC\CA\C7ͨ\B9\FDTuner \C1\AC\BD\D3,\B5\AB\CA\C7IF \B6˿\DA\CA\C7ʹ\D3\C3\C4\DA\D6\C3 QAM)    */
    HI_U32 u32TSIPortNum;       /**<Number of TS In ports. */ /**< CNcomment: TS In \B6˿\DA\CA\FD\C1\BF (\D3\EBIF\B6˿ڶ\BC\CA\C7ͨ\B9\FDTuner \C1\AC\BD\D3,\B5\AB\CA\C7IF \B6˿\DA\CA\C7ʹ\D3\C3\C4\DA\D6\C3 QAM)    */
    HI_U32 u32TSOPortNum;       /**<Number of TS Out ports. */ /**< CNcomment: TS Out  \B6˿\DA\CA\FD\C1\BF*/
    HI_U32 u32RamPortNum;       /**<Number of Ram ports. */ /**< CNcomment: Ram\B6˿\DA\CA\FD\C1\BF     */
    HI_U32 u32DmxNum;           /**<Number of DEMUX devices*/ /**< CNcomment:\C9豸\CA\FD\C1\BF     */
    HI_U32 u32ChannelNum;       /**<Number of channels, containing the audio and video channels */ /**< CNcomment:ͨ\B5\C0\CA\FD\C1\BF\A3\AC\BA\AC\D2\F4\CA\D3Ƶͨ\B5\C0\B5\C4\CA\FD\C1\BF */
    HI_U32 u32AVChannelNum;     /**<Number of av channels*/ /**< CNcomment:\D2\F4\CA\D3Ƶͨ\B5\C0\CA\FD\C1\BF */
    HI_U32 u32FilterNum;        /**<Number of filters*/ /**< CNcomment:\B9\FD\C2\CB\C6\F7\CA\FD\C1\BF   */
    HI_U32 u32KeyNum;           /**<Number of keys*/ /**< CNcomment:\C3\DCԿ\C7\F8\CA\FD\C1\BF   */
    HI_U32 u32RecChnNum;        /**<Number of record channels */ /**< CNcomment:¼\D6\C6ͨ\B5\C0\B5\C4\CA\FD\C1\BF */
    HI_U32 u32TagPortNum;       /**<Number of Tag ports. */ /**< CNcomment: Tag\B6˿\DA\CA\FD\C1\BF     */
    HI_U32 u32TsioPortNum;      /**<Number of Tsio ports. */ /**< CNcomment: Tsio\B6˿\DA\CA\FD\C1\BF     */
} HI_UNF_DMX_CAPABILITY_S;

/**TSO port ID*/
/**CNcomment:TS\CA\E4\B3\F6\B6˿\DAID */
typedef enum hiUNF_DMX_TSO_PORT_E
{
    HI_UNF_DMX_PORT_TSO_0,      /**<The first TS OUT port . */ /**< CNcomment:TS Out \B6˿\DA0 */
    HI_UNF_DMX_PORT_TSO_1,
    HI_UNF_DMX_PORT_TSO_2,
    HI_UNF_DMX_PORT_TSO_3
}HI_UNF_DMX_TSO_PORT_E;

/**TS port ID*/
/**CNcomment:TS\B6˿\DAID */
typedef enum hiUNF_DMX_PORT_E
{
    HI_UNF_DMX_PORT_IF_0 = 0x0,  /**<The first IF port (port with  QAM  inside chipset). */ /**< CNcomment: IF \B6˿\DA0 , (IF \B6˿\DA\CA\C7\C4\DA\D6\C3QAM\B6˿ڣ\ACͨ\B3\A3\B2\BB\B6\E0\D3\DAһ\B8\F6) */
    HI_UNF_DMX_PORT_IF_1,
    HI_UNF_DMX_PORT_IF_2,
    HI_UNF_DMX_PORT_IF_3,
    HI_UNF_DMX_PORT_IF_4,
    HI_UNF_DMX_PORT_IF_5,
    HI_UNF_DMX_PORT_IF_6,
    HI_UNF_DMX_PORT_IF_7,
    HI_UNF_DMX_PORT_IF_8,
    HI_UNF_DMX_PORT_IF_9,
    HI_UNF_DMX_PORT_IF_10,
    HI_UNF_DMX_PORT_IF_11,
    HI_UNF_DMX_PORT_IF_12,
    HI_UNF_DMX_PORT_IF_13,
    HI_UNF_DMX_PORT_IF_14,
    HI_UNF_DMX_PORT_IF_15,

    HI_UNF_DMX_PORT_TSI_0 = 0x20,/**<The first TS IN  port . */ /**< CNcomment:TSIN \B6˿\DA0 , (TSIN \B6˿ڼ\B4Tuner \B6˿\DA) */
    HI_UNF_DMX_PORT_TSI_1,
    HI_UNF_DMX_PORT_TSI_2,
    HI_UNF_DMX_PORT_TSI_3,
    HI_UNF_DMX_PORT_TSI_4,
    HI_UNF_DMX_PORT_TSI_5,
    HI_UNF_DMX_PORT_TSI_6,
    HI_UNF_DMX_PORT_TSI_7,
    HI_UNF_DMX_PORT_TSI_8,
    HI_UNF_DMX_PORT_TSI_9,
    HI_UNF_DMX_PORT_TSI_10,
    HI_UNF_DMX_PORT_TSI_11,
    HI_UNF_DMX_PORT_TSI_12,
    HI_UNF_DMX_PORT_TSI_13,
    HI_UNF_DMX_PORT_TSI_14,
    HI_UNF_DMX_PORT_TSI_15,

    HI_UNF_DMX_PORT_RAM_0 = 0x80,/**<The first RAM port . */ /**< CNcomment:RAM \B6˿\DA0 */
    HI_UNF_DMX_PORT_RAM_1,
    HI_UNF_DMX_PORT_RAM_2,
    HI_UNF_DMX_PORT_RAM_3,
    HI_UNF_DMX_PORT_RAM_4,
    HI_UNF_DMX_PORT_RAM_5,
    HI_UNF_DMX_PORT_RAM_6,
    HI_UNF_DMX_PORT_RAM_7,
    HI_UNF_DMX_PORT_RAM_8,
    HI_UNF_DMX_PORT_RAM_9,
    HI_UNF_DMX_PORT_RAM_10,
    HI_UNF_DMX_PORT_RAM_11,
    HI_UNF_DMX_PORT_RAM_12,
    HI_UNF_DMX_PORT_RAM_13,
    HI_UNF_DMX_PORT_RAM_14,
    HI_UNF_DMX_PORT_RAM_15,

    HI_UNF_DMX_PORT_TSIO_0 = 0xA0,/**<The first TSIO port . */ /**< CNcomment:TSIO \B6˿\DA0 */
    HI_UNF_DMX_PORT_TSIO_1,
    HI_UNF_DMX_PORT_TSIO_2,
    HI_UNF_DMX_PORT_TSIO_3,
    HI_UNF_DMX_PORT_TSIO_4,
    HI_UNF_DMX_PORT_TSIO_5,
    HI_UNF_DMX_PORT_TSIO_6,
    HI_UNF_DMX_PORT_TSIO_7,

    HI_UNF_DMX_PORT_TAG_0 = 0xB0,/**<The first Tag port . */ /**< CNcomment:Tag \B6˿\DA0 */
    HI_UNF_DMX_PORT_TAG_1,
    HI_UNF_DMX_PORT_TAG_2,
    HI_UNF_DMX_PORT_TAG_3,
    HI_UNF_DMX_PORT_TAG_4,
    HI_UNF_DMX_PORT_TAG_5,
    HI_UNF_DMX_PORT_TAG_6,
    HI_UNF_DMX_PORT_TAG_7,

    HI_UNF_DMX_PORT_BUTT
} HI_UNF_DMX_PORT_E;


/**TS port mode*/
/**CNcomment:TS\B6˿\DAģʽ */
typedef enum hiUNF_DMX_PORT_MODE_E
{
    HI_UNF_DMX_PORT_MODE_EXTERNAL,   /**<External TS input mode*/ /**< CNcomment:\CDⲿTS\CA\E4\C8\EB*/
    HI_UNF_DMX_PORT_MODE_INTERNAL,   /**<Internal TS input mode*/ /**< CNcomment:\C4ڲ\BFTS\CA\E4\C8\EB*/
    HI_UNF_DMX_PORT_MODE_RAM,        /**<Memory input mode*/ /**< CNcomment:\B4\D3\C4ڴ\E6\CA\E4\C8\EB*/

    HI_UNF_DMX_PORT_MODE_BUTT
} HI_UNF_DMX_PORT_MODE_E;

/**TS port type*/
/**CNcomment:TS\B6˿\DA\C0\E0\D0\CD */
typedef enum hiUNF_DMX_PORT_TYPE_E
{
    HI_UNF_DMX_PORT_TYPE_PARALLEL_BURST,          /**<Parallel burst mode*/ /**< CNcomment:\B2\A2\D0\D0BURSTģʽ             */
    HI_UNF_DMX_PORT_TYPE_PARALLEL_VALID,          /**<Parallel valid mode*/ /**< CNcomment:\B2\A2\D0\D0VALIDģʽ             */
    HI_UNF_DMX_PORT_TYPE_PARALLEL_NOSYNC_188,     /**<Self-sync 188 mode*/ /**< CNcomment:\D7\D4ͬ\B2\BD188ģʽ             */
    HI_UNF_DMX_PORT_TYPE_PARALLEL_NOSYNC_204,     /**<Self-sync 204 mode*/ /**< CNcomment:\D7\D4ͬ\B2\BD204ģʽ             */
    HI_UNF_DMX_PORT_TYPE_PARALLEL_NOSYNC_188_204, /**<self-sync 188/204 auto-identification mode */ /**< CNcomment:\D7\D4ͬ\B2\BD188/204\D7Զ\AFʶ\B1\F0ģʽ */
    HI_UNF_DMX_PORT_TYPE_SERIAL,                  /**<Serial sync mode, 1bit*/ /**< CNcomment:\B4\AE\D0\D0syncģʽ, 1bit\B4\AE\D0\D0 */
    HI_UNF_DMX_PORT_TYPE_USER_DEFINED,            /**<User defined mode*//**< CNcomment:\D3û\A7\D7Զ\A8\D2\E5ģʽ */
    HI_UNF_DMX_PORT_TYPE_SERIAL2BIT,              /**<Serial sync mode, 2bit*/ /**< CNcomment:\B4\AE\D0\D0syncģʽ, 2bit\B4\AE\D0\D0 */
    HI_UNF_DMX_PORT_TYPE_SERIAL_NOSYNC,           /**<Serial nosync mode, 1bit */ /**< CNcomment:\B4\AE\D0\D0nosyncģʽ, 1bit\B4\AE\D0\D0 */
    HI_UNF_DMX_PORT_TYPE_SERIAL2BIT_NOSYNC,       /**<Serial nosync mode, 2bit */ /**< CNcomment:\B4\AE\D0\D0nosyncģʽ, 2bit\B4\AE\D0\D0 */
    HI_UNF_DMX_PORT_TYPE_AUTO,                    /**<Auto mode*/ /**< CNcomment: \D7Զ\AFģʽ */
    HI_UNF_DMX_PORT_TYPE_PARALLEL_VALID_DUMMY_SYNC, /**<Parallel valid dummy sync mode*/ /**< CNcomment:\B2\A2\D0\D0VALID DUMMY SYNCģʽ \D3\C3\D3ڷ\C7TSȫ\C2\EB\C1\F7¼\D6\C6*/
    HI_UNF_DMX_PORT_TYPE_SERIAL_NOSYNC_NOVALID,     /**<Serial nosync novalid mode, 1bit */ /**< CNcomment:\B4\AE\D0\D0nosync novalidģʽ, 1bit\B4\AE\D0\D0 */
    HI_UNF_DMX_PORT_TYPE_SERIAL2BIT_NOSYNC_NOVALID, /**<Serial nosync novalid mode, 2bit */ /**< CNcomment:\B4\AE\D0\D0nosync novalidģʽ, 2bit\B4\AE\D0\D0 */

    HI_UNF_DMX_PORT_TYPE_BUTT
} HI_UNF_DMX_PORT_TYPE_E;

/**TSO clock mode*/
/**CNcomment:TS\CA\E4\B3\F6\B6˿\DAʱ\D6\D3ģʽ */
typedef enum hiUNF_DMX_TSO_CLK_MODE_E
{
    HI_UNF_DMX_TSO_CLK_MODE_NORMAL,                  /**<Normal clock: clock always active*/ /**< CNcomment:\C6\D5ͨģʽ\B5\C4ʱ\D6\D3,ʱ\D6\D3ƽ\C2ʾ\F9\D4\C8*/
    HI_UNF_DMX_TSO_CLK_MODE_JITTER ,                  /**<Jittered clock: clock active only when outputing data*/ /**< CNcomment:Jittered ģʽʱ\D6\D3,ʱ\D6\D3Ƶ\C2ʲ\BB\BE\F9\D4\C8,\B4\CBʱֻ\D3\D0\D4\DA\D3\D0\CA\FD\BE\DD\CA\E4\B3\F6ʱ\B2Ż\E1\B3\F6ʱ\D6\D3 (valid\D0ź\C5Ϊ\B8ߵ\C4\C7\E9\BF\F6\CF\C2)*/
    HI_UNF_DMX_TSO_CLK_MODE_BUTT
}HI_UNF_DMX_TSO_CLK_MODE_E;

/**TSO valid mode*/
/**CNcomment:TS\CA\E4\B3\F6\B6˿\DAvalid\D0ź\C5ģʽ */
typedef enum hiUNF_DMX_TSO_VALID_MODE_E
{
    HI_UNF_DMX_TSO_VALID_ACTIVE_OUTPUT,          /**<Valid signal high when outputing datas*/ /**< CNcomment:valid\D0ź\C5\D4\DA\CA\E4\B3\F6\CA\FD\BE\DDʱΪ\B8\DF*/
    HI_UNF_DMX_TSO_VALID_ACTIVE_HIGH ,          /**<Valid signal always high*/ /**< CNcomment:valid\D0ź\C5\D7\DC\CA\C7Ϊ\B8\DF*/
    HI_UNF_DMX_TSO_VALID_ACTIVE_BUTT
}HI_UNF_DMX_TSO_VALID_MODE_E;

/**TSO port signal line selector*/
/**CNcomment:TS\CA\E4\B3\F6\B6˿\DA\CF\DF\D0\F2ѡ\D4\F1 */
typedef enum hiUNF_DMX_TSO_SERIAL_BIT_E
{
    HI_UNF_DMX_TSO_SERIAL_BIT_0 = 0x0,          /**< Serial output data using data[0] as signal line*/ /**< CNcomment:ʹ\D3\C3data[0]\D7\F7Ϊ\B4\AE\D0\D0\D0ź\C5\CF\DF\CA\E4\B3\F6*/
    HI_UNF_DMX_TSO_SERIAL_BIT_7 = 0x7,          /**< Serial output data using data[7] as signal line*/ /**< CNcomment:ʹ\D3\C3data[7]\D7\F7Ϊ\B4\AE\D0\D0\D0ź\C5\CF\DF\CA\E4\B3\F6*/
    HI_UNF_DMX_TSO_SERIAL_BIT_BUTT
}HI_UNF_DMX_TSO_SERIAL_BIT_E;

/**TS out mode clock frequency*/
/**CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CA ,ע\D2\E2,ʵ\BCʵ\C4TS out \B6˿\DA\CA\E4\B3\F6Ƶ\C2\CA = TSO ģ\BF\E9ʱ\D6\D3/\B7\D6Ƶ\D2\F2\D7\D3*/
typedef enum hiUNF_DMX_TSO_CLK_E
{
    HI_UNF_DMX_TSO_CLK_100M ,           /**< TS out mode clock frequency 100M*/ /**< CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CAѡ\D4\F1Ϊ100M*/
    HI_UNF_DMX_TSO_CLK_150M ,           /**< TS out mode clock frequency 150M*/ /**< CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CAѡ\D4\F1Ϊ150M*/
    HI_UNF_DMX_TSO_CLK_1200M ,          /**< TS out mode clock frequency 1200M*/ /**< CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CAѡ\D4\F1Ϊ1200M*/
    HI_UNF_DMX_TSO_CLK_1500M ,          /**< TS out mode clock frequency 1500M*/ /**< CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CAѡ\D4\F1Ϊ1500M*/
    HI_UNF_DMX_TSO_CLK_BUTT
}HI_UNF_DMX_TSO_CLK_E;

/** Tag sync mode */
/** CNcomment: Tag ͬ\B2\BDģʽ*/
typedef enum hiUNF_DMX_TAG_SYNC_MODE_E
{
    HI_UNF_DMX_TAG_HEAD_SYNC = 0x0,          /** < tag sync signal at tag head*/ /**< CNcomment:sync\D0ź\C5\D4\DAtagͷ*/
    HI_UNF_DMX_NORMAL_HEAD_SYNC = 0x1,    /** < tag sync signal at 47 heade*/ /** <CNcomment:sync\D0ź\C5\D4\DA47ͷ*/
}HI_UNF_DMX_TAG_SYNC_MODE_E;

/** TS Tag attributes */
/** CNcomment: TS Tag \C5\E4\D6\C3\CA\F4\D0\D4*/
#define MAX_TAG_LENGTH (12)
typedef struct hiUNF_DMX_TAG_PORT_ATTR_S
{
    HI_UNF_DMX_PORT_E enTSSource;                   /**<[IN]Source of this Tag port ,can choose from HI_UNF_DMX_PORT_TSI_XX*/ /**< CNcomment:Tag \B6˿\DA\CA\FD\BE\DDԴ,\BF\C9\D2Դ\D3HI_UNF_DMX_PORT_TSI_XX\D6\D0ѡ\D4\F1*/
    HI_U8             au8Tag[MAX_TAG_LENGTH];       /** <[IN]tag index value*/ /**< CNcomment:\B6˿ڵ\C4tagֵ */
    HI_U32            u32TagLen;   /** <[IN & OUT]Valid tag length(1 ~ 12bytes), which is an input para when setTagAttr, otherwise out para when getTagAttr*/ /** <CNcomment:\D3\D0Чtag\B3\A4\B6\C8(1~12\D7ֽ\DA),setTagAttrʱ\D7\F7Ϊ\CA\E4\C8\EB\B2\CE\CA\FD,getTagAttrʱ\D7\F7Ϊ\CA\E4\B3\F6\B2\CE\CA\FD*/
    HI_BOOL           bEnabled;       /**<[IN & OUT]Port state(default disabled), which is an input para when setTagAttr, otherwise out para when getTagAttr*/ /**< CNcomment:\B6˿\DAʹ\C4\DC(Ĭ\C8ϲ\BBʹ\C4\DC),setTagAttrʱ\D7\F7Ϊ\CA\E4\C8\EB\B2\CE\CA\FD,getTagAttrʱ\D7\F7Ϊ\CA\E4\B3\F6\B2\CE\CA\FD*/
    HI_UNF_DMX_TAG_SYNC_MODE_E enSyncMod; /** <[IN & OUT]Sync mode(default HI_UNF_DMX_TAG_HEAD_SYNC), which is an input para when setTagAttr, otherwise out para when getTagAttr*/ /**<CNcomment:ͬ\B2\BDģʽ(Ĭ\C8\CFֵΪHI_UNF_DMX_TAG_HEAD_SYNC ),setTagAttrʱ\D7\F7Ϊ\CA\E4\C8\EB\B2\CE\CA\FD,getTagAttrʱ\D7\F7Ϊ\CA\E4\B3\F6\B2\CE\CA\FD*/
}HI_UNF_DMX_TAG_PORT_ATTR_S;


/**TS out port attributes*/
/**CNcomment:TS Out \B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_TSO_PORT_ATTR_S
{
    HI_BOOL                     bEnable;       /**<Port enable, default value HI_TRUE means enable*/ /**< CNcomment:\B6˿\DAʹ\C4\DC,Ĭ\C8\CFʹ\C4\DC*/
    HI_BOOL                     bClkReverse;   /**<Clock phase reverse, default value HI_FALSE means do not reverse the phase of clock*/ /**< CNcomment:\B6˿\DAʱ\D6ӷ\B4\CF\F2,Ĭ\C8ϲ\BB\B7\B4\CF\F2*/
    HI_UNF_DMX_PORT_E           enTSSource;    /**<Source of this TS Out port ,can choose from HI_UNF_DMX_PORT_IF_0 to HI_UNF_DMX_PORT_TSI_9*/  /**< CNcomment:TS Out \B6˿\DA\CA\FD\BE\DDԴ,\BF\C9\D2Դ\D3HI_UNF_DMX_PORT_IF_0 \B5\BDHI_UNF_DMX_PORT_TSI_9 ֮\BC\E4ѡ\D4\F1*/
    HI_UNF_DMX_TSO_CLK_MODE_E   enClkMode;     /**<Clock mode: HI_UNF_DMX_TSO_CLK_MODE_NORMAL is the default value*/ /**< CNcomment:ʱ\D6\D3ģʽ: Ĭ\C8\CFֵΪ HI_UNF_DMX_TSO_CLK_MODE_NORMAL*/
    HI_UNF_DMX_TSO_VALID_MODE_E enValidMode;   /**<Wether valid signal always enable : HI_UNF_DMX_TSO_VALID_ACTIVE_OUTPUT is the default value */ /**< CNcomment:Valid ģʽ: Ĭ\C8\CFֵΪ:HI_UNF_DMX_TSO_VALID_ACTIVE_OUTPUT  */
    HI_BOOL                     bBitSync;       /**<The sync signal duration : HI_TRUE: only valid when output the first bit(default). HI_FALSE: keep when outputing the whole byte*/
                                                /**< CNcomment:sync \D0ź\C5\D3\D0Ч\C6\DA : HI_TRUE: ֻ\D4\DA\CA\E4\B3\F6\B5\DAһ\B8\F6bitʱ\D3\D0Ч (Ĭ\C8\CF) . HI_FALSE: \D4\DA\CA\E4\B3\F6\D5\FB\B8\F6\D7ֽ\DAʱ\B6\BC\D3\D0Ч  */
    HI_UNF_DMX_PORT_TYPE_E      enPortType;     /**<Port out put mode: serial(HI_UNF_DMX_PORT_TYPE_SERIAL), parallel(HI_UNF_DMX_PORT_TYPE_PARALLEL_BURST) or serial 2bits(HI_UNF_DMX_PORT_TYPE_SERIAL2BIT) mode. default is serial(HI_UNF_DMX_PORT_TYPE_SERIAL)*/
                                                /**< CNcomment:TSOģ\BF\E9\CA\E4\B3\F6ģʽ:\B4\AE\D0\D0(HI_UNF_DMX_PORT_TYPE_SERIAL)\A3\AC\B2\A2\D0\D0(HI_UNF_DMX_PORT_TYPE_PARALLEL_BURST) \BB\F2\D5ߴ\AE\D0\D02bit(HI_UNF_DMX_PORT_TYPE_SERIAL2BIT) ģʽ\A1\A3 Ĭ\C8\CF\CAǴ\AE\D0\D0(HI_UNF_DMX_PORT_TYPE_SERIAL)*/
    HI_UNF_DMX_TSO_SERIAL_BIT_E enBitSelector;  /**<Port line sequence select In serial mode.only valid when using serial out put mode,HI_UNF_DMX_TSO_SERIAL_BIT_7 is the default value.*/
                                                /**< CNcomment:\B6˿ڴ\AE\D0\D0ģʽ\CF\DF\D0\F2ѡ\D4\F1,ֻ\D3\D0ʹ\D3ô\AE\D0\D0\CA\E4\B3\F6ģʽ\B5\C4ʱ\BA\F2\D3\D0Ч,Ĭ\C8\CFֵΪ HI_UNF_DMX_TSO_SERIAL_BIT_7*/
    HI_BOOL                     bLSB;           /**<Out put byte endian .only valid when using serial out put mode: HI_FALSE: first output MSB (default). HI_TRUE:  first output LSB*/
                                                /**< CNcomment:\B6˿\DA\CA\E4\B3\F6\B4\F3С\B6\CBģʽ,ֻ\D3\D0ʹ\D3ô\AE\D0\D0\CA\E4\B3\F6ģʽ\B5\C4ʱ\BA\F2\D3\D0Ч: HI_FALSE: \CA\D7\CF\C8\CA\E4\B3\F6\D7\EE\B8\DFλ (Ĭ\C8\CF) . HI_TRUE: \CA\D7\CF\C8\CA\E4\B3\F6\D7\EE\B5\CDλ  */
    HI_UNF_DMX_TSO_CLK_E        enClk;          /**<TS out mode clock frequency,default is HI_UNF_DMX_TSO_CLK_150M*/ /**< CNcomment:TS\CA\E4\B3\F6ģ\BF\E9ʱ\D6\D3Ƶ\C2\CA,Ĭ\C8\CF\CA\C7 HI_UNF_DMX_TSO_CLK_150M*/
    HI_U32                      u32ClkDiv;      /**<TS out mode clock frequency divider,must be times of 2 ,and must meet (2 <= u32ClkDiv <= 32) .default is 2*/ /**< CNcomment:TSOģ\BF\E9\B7\D6Ƶ\D2\F2\D7\D3,\B1\D8\D0\EB\CA\C72\B5\C4\D5\FB\CA\FD\B1\B6,ȡֵ\B7\B6Χ\D4\DA2\D3\EB32֮\BC\E4*/
} HI_UNF_DMX_TSO_PORT_ATTR_S;


/**TS port attributes*/
/**CNcomment:TS\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_PORT_ATTR_S
{
    HI_UNF_DMX_PORT_MODE_E enPortMod;       /**<Port mode.Readonly*/ /**< CNcomment:\B6˿\DAģʽ ֻ\B6\C1*/
    HI_UNF_DMX_PORT_TYPE_E enPortType;      /**<Port type*/ /**< CNcomment:\B6˿\DA\C0\E0\D0\CD */
    HI_U32 u32SyncLostTh;                   /**<Sync loss threshold.The default value is recommended.*/ /**< CNcomment:ͬ\B2\BD\B6\AAʧ\C3\C5\CFޣ\AC\CDƼ\F6ʹ\D3\C3Ĭ\C8\CFֵ */
    HI_U32 u32SyncLockTh;                   /**<Sync lock threshold.The default value is recommended.*/ /**< CNcomment:ͬ\B2\BD\CB\F8\B6\A8\C3\C5\CFޣ\AC\CDƼ\F6ʹ\D3\C3Ĭ\C8\CFֵ */
    HI_U32 u32TunerInClk;                   /**<Whether to reverse the phase of the clock input from the tuner*/ /**< CNcomment:Tuner\CA\E4\C8\EBʱ\D6\D3\CAǷ\F1\B7\B4\CF\E0.0: ͬ\CF\E0(Ĭ\C8\CF); 1: \B7\B4\CF\E0*/
    HI_U32 u32SerialBitSelector;            /**<Port line sequence select In parallel mode: 0: cdata[7] is the most significant bit (MSB) (default). 1: cdata[0] is the MSB.
                                                            In serial mode: 1: cdata[0] is the data line (default). 0: cdata[7] is the data line.*/
                                            /**< CNcomment:\B6˿\DA\CF\DF\D0\F2ѡ\D4񡣲\A2\D0\D0ʱ:0: \B1\EDʾcdata[7]\D7\EE\B8\DFλ(Ĭ\C8\CF);1: \B1\EDʾcdata[0]\D7\EE\B8\DFλ\A1\A3
                                                            \B4\AE\D0\D0ʱ:1: \B1\EDʾcdata[0]Ϊ\CA\FD\BE\DD\CF\DF(Ĭ\C8\CF); 0: \B1\EDʾcdata[7]Ϊ\CA\FD\BE\DD\CF\DF*/

    HI_U32 u32TunerErrMod;                  /**<Level mode of the cerr_n line from the tuner to a DEMUX.
                                                       0: A data error occurs when the cerr_n line is high.
                                                       1: A data error occurs when the cerr_n line is low (default).*/
                                            /**< CNcomment:tuner\B5\BDDEMUX\B5\C4cerr_n\CFߵ\E7ƽģʽ:
                                                       0: \B1\EDʾcerr_n\CF\DFΪ\B8\DFʱ\B1\EDʾ\CA\FD\BEݴ\ED\CE\F3;
                                                       1: \B1\EDʾcerr_n\CF\DFΪ\B5\CDʱ\B1\EDʾ\CA\FD\BEݴ\ED\CE\F3 (Ĭ\C8\CF) */
    HI_U32 u32UserDefLen1;                  /**<User defined length1,valid when enPortType is HI_UNF_DMX_PORT_TYPE_USER_DEFINED,188~255 *//**< CNcomment:\D3û\A7\D7Զ\A8\D2峤\B6ȼ\EC\B2\E2\B0\FC\B3\A41\A3\ACֻ\D3ж˿\DA\C0\E0\D0\CDΪ\D3û\A7\D7Զ\A8\D2\E5ʱ\D3\D0Ч\A3\AC\D3\D0Ч\B7\B6Χ188~255 */
    HI_U32 u32UserDefLen2;                  /**<User defined length2,valid when enPortType is HI_UNF_DMX_PORT_TYPE_USER_DEFINED,188~255 *//**< CNcomment:\D3û\A7\D7Զ\A8\D2峤\B6ȼ\EC\B2\E2\B0\FC\B3\A42\A3\ACֻ\D3ж˿\DA\C0\E0\D0\CDΪ\D3û\A7\D7Զ\A8\D2\E5ʱ\D3\D0Ч\A3\AC\D3\D0Ч\B7\B6Χ188~255*/
    HI_UNF_DMX_PORT_E enSerialPortShareClk; /**<Port of clock that this port shared, only valid for TSI port tpye *//**< CNcomment:ָ\B6\A8\B8ö˿\DA\CB\F9\B8\B4\D3\C3ʱ\D6ӵĶ\D4Ӧ\B6˿ڣ\AC\B8ó\C9Ա\BD\F6\B6\D4TSI\B6˿\DA\C0\E0\D0\CD\D3\D0Ч*/
} HI_UNF_DMX_PORT_ATTR_S;

/**Status of the TS port*/
/**CNcomment:TS\B6˿ڵ\C4״̬*/
typedef struct hiUNF_DMX_PORT_PACKETNUM_S
{
    HI_U32  u32TsPackCnt;    /**<Number of TS packets received from the TS port*/ /**< CNcomment:\B6˿\DA\CAյ\BD\B5\C4TS\B0\FC\BC\C6\CA\FD*/
    HI_U32  u32ErrTsPackCnt; /**<Number of error TS packets received from the TS port*/ /**< CNcomment:\B6˿\DA\C9ϴ\ED\CE\F3TS\B0\FC\B5ļ\C6\CA\FD*/
    HI_U32  u32TsSyncByteErrCnt;  /**<Number of sync byte error TS packets received from the TS port*/  /**< CNcomment:\B6˿ڽ\D3\CAյ\BD\B7Ƿ\A8\B4\AB\CA\E4ͬ\B2\BD\D7ֽڵ\C4TS\B0\FC\BC\C6\CA\FD*/
    HI_U32  u32TsSyncLossCnt;    /**<Number of sync loss TS packets received from the TS port*/ /**< CNcomment:\B6˿ڽ\D3\CAյ\BDͬ\B2\BD\B6\AAʧ\B5\C4TS\B0\FC\BC\C6\CA\FD*/
    HI_U32  u32TsPackDrainedCnt;    /**<Number of Drained TS packets received from the TS port*/ /**< CNcomment:\B6˿ڳɹ\A6\BB\F1ȡ\B5\BD\B5ĺϷ\A8TS\B0\FC\BC\C6\CA\FD*/
    HI_U32  u32PackDisCCCnt;    /**<Number of Discontinuity TS packets received from the TS port*/ /**< CNcomment:\BD\E2\C8ź\F3\B6˿\DA\CAյ\BD\B5Ĳ\BB\C1\AC\D0\F8\B4\ED\CE\F3TS\B0\FC\BC\C6\CA\FD*/
    HI_U32  u32PackDisCCCntCA;    /**<Number of Discontinuity TS packets received before descrambler from the TS port, the value is same as u32PackDisCCCnt*/ /**< CNcomment: \BD\E2\C8\C5ǰ\BD\F8\C8\EB\B6˿ڵ\C4TS\B0\FC\B2\BB\C1\AC\D0\F8\B4\ED\CE\F3\B4\CE\CA\FD,ֵ\D3\EBu32PackDisCCCntһ\D6\C2*/
} HI_UNF_DMX_PORT_PACKETNUM_S;

/** Secure mode type*/
/**CNcomment:\B0\B2ȫģʽ\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_SECURE_MODE_E
{
    HI_UNF_DMX_SECURE_MODE_NONE = 0,        /** <no security protection*/ /**<CNcomment:\CEް\B2ȫ\B1\A3\BB\A4*/
    HI_UNF_DMX_SECURE_MODE_TEE,             /** <trustedzone security protection*/ /**<CNcomment:trustedzone\B0\B2ȫ\B1\A3\BB\A4*/

    HI_UNF_DMX_SECURE_MODE_BUTT
} HI_UNF_DMX_SECURE_MODE_E;

/** TS buffer attribute*/
/**CNcomment:TS buffer \CA\F4\D0\D4*/
typedef struct hiUNF_DMX_TSBUF_ATTR_S
{
    HI_UNF_DMX_SECURE_MODE_E enSecureMode;  /**<Secure indication*/ /**<CNcomment:\B0\B2ȫ\B1\EAʾ*/
    HI_U32  u32BufSize;                     /**<Buffer size*/ /**< CNcomment:\BB\BA\B3\E5\C7\F8\B4\F3С*/
}HI_UNF_DMX_TSBUF_ATTR_S;

/**Status of a TS buffer of a DEMUX*/
/**CNcomment:DEMUX\B5\C4TS Buffer״̬ */
typedef struct hiUNF_DMX_TSBUF_STATUS_S
{
    HI_U32 u32BufSize;    /**<Buffer size*/ /**< CNcomment:\BB\BA\B3\E5\C7\F8\B4\F3С*/
    HI_U32 u32UsedSize;   /**<Used buffer size*/ /**< CNcomment:\BB\BA\B3\E5\C7\F8\D2\D1ʹ\D3ô\F3С,\B8\C3ֵ\B1\C8ʵ\BC\CAʹ\D3\C3ֵ\B4\F30x100\D7ֽ\DA */
    HI_UNF_DMX_SECURE_MODE_E enSecureMode;  /**<Secure indication*/ /**<CNcomment:\B0\B2ȫ\B1\EAʾ*/
    HI_U32 u32HardwareUsedSize;             /**<Hardware Used Buffer Size, used for special scene*/ /**< CNcomment:Ӳ\BC\FE\B5\B1ǰ\D5\FD\D4\DAʹ\D3õ\C4buffer\B4\F3С\A3\AC\CC\D8\CAⳡ\BE\B0ʹ\D3ã\AC\CDⲿ\BFͻ\A7\B2\BB\D0\E8Ҫ\B9\D8\D0\C4*/
} HI_UNF_DMX_TSBUF_STATUS_S;

/**Channel type*/
/**CNcomment:ͨ\B5\C0\C0\E0\D0\CD */
typedef enum hiUNF_DMX_CHAN_TYPE_E
{
    HI_UNF_DMX_CHAN_TYPE_SEC = 0, /**<Channel that receives sections data such as program specific information (PSI) or service information (SI) data*/ /**< CNcomment:\D3\C3\D3ڽ\D3\CA\D5 PSI/SI\B5\C8secitons\CA\FD\BEݵ\C4ͨ\B5\C0*/
    HI_UNF_DMX_CHAN_TYPE_PES,     /**<Channel that receives packetized elementary stream (PES) data*/ /**< CNcomment:\D3\C3\D3ڽ\D3\CA\D5PES\B0\FC\CA\FD\BEݵ\C4ͨ\B5\C0*/
    HI_UNF_DMX_CHAN_TYPE_AUD,     /**<Channel that receives audio data*/ /**< CNcomment:\D3\C3\D3ڽ\D3\CA\D5\D2\F4Ƶ\CA\FD\BEݵ\C4ͨ\B5\C0*/
    HI_UNF_DMX_CHAN_TYPE_VID,     /**<Channel that receives video data*/ /**< CNcomment:\D3\C3\D3ڽ\D3\CA\D5\CA\D3Ƶ\CA\FD\BEݵ\C4ͨ\B5\C0*/
    HI_UNF_DMX_CHAN_TYPE_POST,      /**<Entire-packet posting channel that receives an entire TS packet with a specific packet identifier (PID). */ /**< CNcomment:\D5\FB\B0\FC\C9\CF\CB\CDͨ\B5\C0\A3\AC\D3\C3\D3ڽ\D3\CA\D5ĳPID\B5\C4\CD\EA\D5\FBTS\B0\FC*/
    HI_UNF_DMX_CHAN_TYPE_ECM_EMM,   /**<Channel that receives entitlement control message (ECM) or entitlement management message (EMM) data*/ /**< CNcomment:\D3\C3\D3ڽ\D3\CA\D5ECM\BB\F2EMM\CA\FD\BEݵ\C4ͨ\B5\C0*/

    HI_UNF_DMX_CHAN_TYPE_BUTT
} HI_UNF_DMX_CHAN_TYPE_E;

/**Status of the channel*/
/**CNcomment:channel\B5\C4״̬\D0\C5Ϣ*/
typedef struct hiUNF_DMX_CHAN_PACKETNUM_S
{
    HI_U32          u32CCDiscCnt;   /**<CC Discontinuity Count */ /**< CNcomment:CC\B2\BB\C1\AC\D0\F8\BC\C6\CA\FD*/
} HI_UNF_DMX_CHAN_PACKETNUM_S;

/**Cyclic redundancy check (CRC) mode of a channel*/
/**CNcomment:ͨ\B5\C0\B5\C4CRCģʽ */
typedef enum hiUNF_DMX_CHAN_CRC_MODE_E
{
    HI_UNF_DMX_CHAN_CRC_MODE_FORBID = 0,                /**<The CRC check is disabled*/ /**< CNcomment:CRCУ\D1\E9\BD\FBֹ */
    HI_UNF_DMX_CHAN_CRC_MODE_FORCE_AND_DISCARD = 1,     /**<The CRC check is enabled, and the error Section data is discarded*/ /**< CNcomment:CRCУ\D1\E9ʹ\C4ܣ\AC\B2\A2\B6\AA\C6\FA\B4\ED\CE\F3Section */
    HI_UNF_DMX_CHAN_CRC_MODE_FORCE_AND_SEND = 2,        /**<The CRC check is enabled, and the error Section data is received*/ /**< CNcomment:CRCУ\D1\E9ʹ\C4ܣ\AC\B2\A2\C9\CF\CBʹ\ED\CE\F3Section */
    HI_UNF_DMX_CHAN_CRC_MODE_BY_SYNTAX_AND_DISCARD = 3, /**<Whether the CRC check is performed depends on the syntax, and the error Section data is discarded*/ /**< CNcomment:\B8\F9\BE\DD\D3﷨\C5ж\CF\CAǷ\F1\BD\F8\D0\D0CRCУ\D1飬\B2\A2\B6\AA\C6\FA\B4\ED\CE\F3Section */
    HI_UNF_DMX_CHAN_CRC_MODE_BY_SYNTAX_AND_SEND = 4,    /**<Whether the CRC check is performed depends on the syntax, and the error Section data is received*/ /**< CNcomment:\B8\F9\BE\DD\D3﷨\C5ж\CF\CAǷ\F1\BD\F8\D0\D0CRCУ\D1飬\B2\A2\C9\CF\CBʹ\ED\CE\F3Section */

    HI_UNF_DMX_CHAN_CRC_MODE_BUTT
} HI_UNF_DMX_CHAN_CRC_MODE_E;

/**Output mode of a channel*/
/**CNcomment:ͨ\B5\C0\B5\C4\CA\E4\B3\F6ģʽ */
typedef enum hiUNF_DMX_CHAN_OUTPUT_MODE_E
{
    HI_UNF_DMX_CHAN_OUTPUT_MODE_PLAY = 0x1,     /**<Mode of playing audios/videos or receiving data*/ /**< CNcomment:\D2\F4\CA\D3Ƶ\B2\A5\B7Ż\F2\CA\FD\BEݽ\D3\CA\D5 */
    HI_UNF_DMX_CHAN_OUTPUT_MODE_REC  = 0x2,     /**<Recording mode*/ /**< CNcomment:¼\D6\C6 */
    HI_UNF_DMX_CHAN_OUTPUT_MODE_PLAY_REC = 0x3, /**<Mode of recording and playing data or receiving data*/ /**< CNcomment:ͬʱ¼\D6ƺͲ\A5\B7Ż\F2\CA\FD\BEݽ\D3\CA\D5 */
    HI_UNF_DMX_CHAN_OUTPUT_MODE_BUTT
} HI_UNF_DMX_CHAN_OUTPUT_MODE_E;

/**Channel attribute*/
/**CNcomment:ͨ\B5\C0\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_CHAN_ATTR_S
{
    HI_U32 u32BufSize;                            /**<Buffer size used by channels*/ /**< CNcomment:ͨ\B5\C0Ӳ\BC\FEʹ\D3\C3buffer\B4\F3С*/
    HI_UNF_DMX_CHAN_TYPE_E enChannelType;         /**<Channel type*/ /**< CNcomment:ͨ\B5\C0\C0\E0\D0\CD */
    HI_UNF_DMX_CHAN_CRC_MODE_E enCRCMode;         /**<CRC mode.It is valid for the DEMUX_CHAN_SEC channel.*/ /**< CNcomment:CRCģʽ\A3\ACͨ\B5\C0\C0\E0\D0\CDΪDMX_CHAN_SEC ʱ\D3\D0Ч */
    HI_UNF_DMX_CHAN_OUTPUT_MODE_E enOutputMode;   /**<Output mode of the channel data*/ /**< CNcomment:ͨ\B5\C0\CA\FD\BE\DD\CA\E4\B3\F6ģʽ */
    HI_UNF_DMX_SECURE_MODE_E enSecureMode;        /**<Secure channel indication*/ /**<CNcomment:\B0\B2ȫͨ\B5\C0\B1\EAʾ*/
} HI_UNF_DMX_CHAN_ATTR_S;

/**Scrambled flag of the channel data*/
/**CNcomment:ͨ\B5\C0\CA\FD\BEݵļ\D3\C8ű\EA־ */
typedef enum hiUNF_DMX_SCRAMBLED_FLAG_E
{
    HI_UNF_DMX_SCRAMBLED_FLAG_TS,  /**<TS data is scrambled*/ /**< CNcomment:\CA\FD\BEݱ\BBTS\BC\B6\BC\D3\C8\C5*/
    HI_UNF_DMX_SCRAMBLED_FLAG_PES, /**<PES data is scrambled*/ /**< CNcomment:\CA\FD\BEݱ\BBPES\BC\B6\BC\D3\C8\C5*/
    HI_UNF_DMX_SCRAMBLED_FLAG_NO,  /**<Data is not scrambled*/ /**< CNcomment:\CA\FD\BE\DDδ\B1\BB\BC\D3\C8\C5*/

    HI_UNF_DMX_SCRAMBLED_FLAG_BUTT
} HI_UNF_DMX_SCRAMBLED_FLAG_E;

/**Channel status*/
/**CNcomment:ͨ\B5\C0״̬ */
typedef enum hiUNF_DMX_CHAN_STATUS_E
{
    HI_UNF_DMX_CHAN_CLOSE = 0x0,        /**<The channel is stopped.*/ /**< CNcomment:ͨ\B5\C0\B4\A6\D3ڹر\D5״̬*/
    HI_UNF_DMX_CHAN_PLAY_EN = 0x1,      /**<The channel is playing audios/videos or receiving data.*/ /**< CNcomment:ͨ\B5\C0\B4\A6\D3\DA\D2\F4\CA\D3Ƶ\B2\A5\B7Ż\F2\CA\FD\BEݽ\D3\CA\D5״̬*/
    HI_UNF_DMX_CHAN_REC_EN = 0x2,       /**<The channel is recording data.*/ /**< CNcomment:ͨ\B5\C0\B4\A6\D3\DA\CA\FD\BE\DD¼\D6\C6״̬*/
    HI_UNF_DMX_CHAN_PLAY_REC_EN = 0x3,  /**<The channel is recording and receiving data.*/ /**< CNcomment:ͨ\B5\C0\B4\A6\D3\DAͬʱ¼\D6ƺ\CD\CA\FD\BEݽ\D3\CA\D5״̬*/
} HI_UNF_DMX_CHAN_STATUS_E;

/**Defines the channel status*/
/** CNcomment:\B6\A8\D2\E5ͨ\B5\C0״̬\BDṹ\CC\E5*/
typedef struct hiUNF_DMX_CHAN_STATUS_S
{
    HI_UNF_DMX_CHAN_STATUS_E enChanStatus;   /**<Channel status*/ /**< CNcomment:ͨ\B5\C0״̬*/
} HI_UNF_DMX_CHAN_STATUS_S;

/**Filter attribute*/
/**CNcomment:\B9\FD\C2\CB\C6\F7\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_FILTER_ATTR_S
{
    HI_U32  u32FilterDepth;                     /**<Depth of a filter.*/ /**< CNcomment:\B9\FD\C2\CB\C6\F7\C9\EE\B6\C8*/
    HI_U8   au8Match[DMX_FILTER_MAX_DEPTH];     /**<Matched bytes of a filter.The data is compared by bit.*/ /**< CNcomment:\B9\FD\C2\CB\C6\F7ƥ\C5\E4\D7ֽ\DA,\B0\B4bit\B1Ƚ\CF*/
    HI_U8   au8Mask[DMX_FILTER_MAX_DEPTH];      /**<Masked bytes of a filter. The conditions are set by bit. 0: no mask. Comparison is required. 1: mask. Comparison is not required.*/ /**< CNcomment:\B9\FD\C2\CB\C6\F7\C6\C1\B1\CE\D7ֽ\DA,\B0\B4bit\C9\E8\D6\C3, 0:û\D3\D0mask\A3\ACҪ\BD\F8\D0бȽ\CF, 1:mask\C6\F0\D7\F7\D3ã\AC\B2\BB\BD\F8\D0бȽ\CF*/
    HI_U8   au8Negate[DMX_FILTER_MAX_DEPTH];    /**<Negated bytes of a filter. 0: not negated; 1: negated*/ /**< CNcomment:\B9\FD\C2\CB\C6\F7ȡ\B7\B4\D7ֽ\DA,\B0\B4byte\C9\E8\D6\C3, 0:\B2\BBȡ\B7\B4,1:ȡ\B7\B4*/
} HI_UNF_DMX_FILTER_ATTR_S;

/**Type of the DEMUX data packet.*/
/**CNcomment:DEMUX\CA\FD\BEݰ\FC\B5\C4\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_DATA_TYPE_E
{
    HI_UNF_DMX_DATA_TYPE_WHOLE = 0,  /**<The data segment contains a complete data packet*/ /**< CNcomment:\B4˶\CE\CA\FD\BEݰ\FC\BA\AC\CD\EA\D5\FB\B5\C4\CA\FD\BEݰ\FC, \B6\D4\D3\DASECTIONÿ\B8\F6\B0\FC\B6\BC\CA\C7\CD\EA\D5\FB\B5\C4*/
    HI_UNF_DMX_DATA_TYPE_HEAD,       /**<The data segment contains the head of a data packet, but the data packet may not be complete*/ /**< CNcomment:\B4˶\CE\CA\FD\BEݰ\FC\BA\AC\CA\FD\BEݰ\FC\B5\C4\C6\F0ʼ\A3\AC\B5\AB\CAǲ\BBһ\B6\A8\CA\C7\CD\EA\D5\FB\B5İ\FC, ֻ\D3\C3\D3\DAPES\CA\FD\BE\DD*/
    HI_UNF_DMX_DATA_TYPE_BODY,       /**<This type is valid only for the PES data.The data segment contains the body of a data packet. */ /**< CNcomment:\B4˶\CE\CA\FD\BEݰ\FC\BA\AC\CA\FD\BEݰ\FC\B5\C4\C4\DA\C8ݣ\AC\B2\BB\B0\FC\BA\AC\C6\F0ʼ\A3\AC\BF\C9\C4\DC\D3н\E1β, ֻ\D3\C3\D3\DAPES\CA\FD\BE\DD*/
    HI_UNF_DMX_DATA_TYPE_TAIL,       /**<This type is valid only for the PES data.The data segment contains the tail of a data packet, and is used to identify the end of a data packet.*/ /**< CNcomment:\B4˶\CE\CA\FD\BEݰ\FC\BA\AC\CA\FD\BEݰ\FC\B5Ľ\E1β\A3\AC\D3\C3\D3\DAָʾ\BF\C9ʶ\B1\F0\B5İ\FC\BD\E1\CA\F8, ֻ\D3\C3\D3\DAPES\CA\FD\BE\DD*/

    HI_UNF_DMX_DATA_TYPE_BUTT
} HI_UNF_DMX_DATA_TYPE_E;

/**DEMUX data packet*/
/**CNcomment:DEMUX\CA\FD\BEݰ\FC\BDṹ*/
typedef struct hiUNF_DMX_DATA_S
{
    HI_U8   *pu8Data;                   /**<Data pointer*/ /**< CNcomment:\CA\FD\BE\DDָ\D5\EB */
    HI_U32  u32Size;                    /**<Data length*/ /**< CNcomment:\CA\FD\BEݳ\A4\B6\C8 */
    HI_UNF_DMX_DATA_TYPE_E enDataType;  /**<Data packet type*/ /**< CNcomment:\CA\FD\BEݰ\FC\B5\C4\C0\E0\D0\CD */
} HI_UNF_DMX_DATA_S;

/**type of record*/
/**CNcomment: ¼\D6\C6\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_REC_TYPE_E
{
    HI_UNF_DMX_REC_TYPE_SELECT_PID, /**<Record selected pid ts data *//**<CNcomment: ¼\D6\C6ָ\B6\A8PID TS\CA\FD\BE\DD*/
    HI_UNF_DMX_REC_TYPE_ALL_PID,    /**<Record all pid ts data *//**<CNcomment: ¼\D6\C6ȫ\C2\EB\C1\F7TS\CA\FD\BE\DD*/
    HI_UNF_DMX_REC_TYPE_ALL_DATA,   /**<Record raw data,TLV etc *//**<CNcomment: ¼\D6\C6ԭʼ\CA\FD\BEݣ\AC\C8\E7TLV\B5\C8*/
    HI_UNF_DMX_REC_TYPE_BUTT
} HI_UNF_DMX_REC_TYPE_E;

/**type of index*/
/**CNcomment: \CB\F7\D2\FD\C0\E0\D0\CD */
typedef enum hiUNF_DMX_REC_INDEX_TYPE_E
{
    HI_UNF_DMX_REC_INDEX_TYPE_NONE,     /**<No index is created */  /**<CNcomment: \B2\BB\BD\A8\CB\F7\D2\FD */
    HI_UNF_DMX_REC_INDEX_TYPE_VIDEO,    /**<Video index */          /**<CNcomment: \CA\D3Ƶ\CB\F7\D2\FD */
    HI_UNF_DMX_REC_INDEX_TYPE_AUDIO,    /**<Audio index */          /**<CNcomment: \D2\F4Ƶ\CB\F7\D2\FD */
    HI_UNF_DMX_REC_INDEX_TYPE_BUTT
} HI_UNF_DMX_REC_INDEX_TYPE_E;

/**<TS stream type.*/
/**<CNcomment: ts\C2\EB\C1\F7\B5\C4\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_TS_PACKET_TYPE_E
{
    HI_UNF_DMX_TS_PACKET_188,           /**<ts stream packet size of 188 bytes*//**<CNcomment: ts\C2\EB\C1\F7\B0\FC\B4\F3СΪ188\D7ֽ\DA*/
    HI_UNF_DMX_TS_PACKET_192,           /**<ts stream packet size of 192 bytes*//**<CNcomment: ts\C2\EB\C1\F7\B0\FC\B4\F3СΪ192\D7ֽ\DA*/
    HI_UNF_DMX_TS_PACKET_BUTT
}HI_UNF_DMX_TS_PACKET_TYPE_E;

/**record attribute*/
/**CNcomment: ¼\D6\C6\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_REC_ATTR_S
{
    HI_U32                      u32DmxId;
    HI_U32                      u32RecBufSize;  /**<Buffer size used by record */ /**< CNcomment: ¼\D6ƻ\BA\B4\E6\B4\F3С */
    HI_UNF_DMX_REC_TYPE_E       enRecType;      /**<Record type */ /**< CNcomment: ¼\D6\C6\C0\E0\D0\CD */
    HI_BOOL                     bDescramed;     /**<HI_TRUE is the descrambled TS. HI_FALSE is the original TS. */ /**<CNcomment: HI_TRUE\B1\EDʾ¼\D6ƽ\E2\C8ź\F3\B5\C4TS\C1\F7\A3\ACHI_FALSE\B1\EDʾ¼\D6\C6ԭʼ\C1\F7 */
    HI_UNF_DMX_REC_INDEX_TYPE_E enIndexType;    /**<Index type */ /**< CNcomment: \CB\F7\D2\FD\C0\E0\D0\CD */
    HI_U32                      u32IndexSrcPid; /**<The index information is formed according to the PID. when indexing video, it has to be set to the video of PID. when indexing audio, it has to be set to the audio of PID. */ /**< CNcomment: \B8\F9\BEݴ\CBPID\C9\FA\B3\C9\CB\F7\D2\FD\CA\FD\BEݣ\AC\CA\D3Ƶ\CB\F7\D2\FDʱ\C9\E8\D6\C3Ϊ\CA\D3Ƶ\B5\C4PID\A3\AC\D2\F4Ƶ\CB\F7\D2\FDʱ\C9\E8\D6\C3Ϊ\D2\F4Ƶ\B5\C4PID */
    HI_UNF_VCODEC_TYPE_E        enVCodecType;   /**<Video encoding protocol. The protocol needs to be set only when the index type is HI_UNF_DMX_REC_INDEX_TYPE_VIDEO.*/ /**< CNcomment: \CA\D3Ƶ\CB\F7\D2\FDʱ\C9\E8\D6\C3\CA\D3Ƶ\B5ı\E0\C2\EB\C0\E0\D0\CD */
    HI_UNF_DMX_SECURE_MODE_E    enSecureMode;   /**<Secure record indication*/ /**<CNcomment:\B0\B2ȫ¼\D6Ʊ\EAʾ*/
    HI_UNF_DMX_TS_PACKET_TYPE_E enTsPacketType; /**<TS stream type of recorded TS.*/ /**<CNcomment: ¼\D6\C6\C9\FA\B3\C9\CEļ\FE\D6\D0\C2\EB\C1\F7\B5\C4TS\C0\E0\D0\CD */
} HI_UNF_DMX_REC_ATTR_S;

/**record data*/
/**CNcomment: ¼\D6\C6\CA\FD\BE\DD*/
typedef struct hiUNF_DMX_REC_DATA_S
{
    HI_U8  *pDataAddr;      /**<Data address*/          /**<CNcomment: \CA\FD\BEݵ\D8ַ */
    HI_U32  u32DataPhyAddr; /**<Data physical address*/ /**<CNcomment: \CA\FD\BEݵ\C4\CE\EF\C0\ED\B5\D8ַ */
    HI_U32  u32Len;         /**<Data length*/           /**<CNcomment: \CA\FD\BEݳ\A4\B6\C8 */
    HI_BOOL bLastDataFlag;  /**<Last Data Flag */       /**<CNcomment: \D7\EE\BA\F3\CA\FD\BEݰ\FC\B1\EA\BC\C7 */
} HI_UNF_DMX_REC_DATA_S;

/**index data*/
/**CNcomment: \CB\F7\D2\FD\CA\FD\BE\DD*/
typedef struct hiUNF_DMX_REC_INDEX_S
{
    HI_UNF_VIDEO_FRAME_TYPE_E   enFrameType;        /**< it is meaningless when indexing audio. */ /**<CNcomment: \D2\F4Ƶ\CB\F7\D2\FDʱ\CE\DE\D2\E2\D2\E5 */
    HI_U32                      u32PtsMs;
    HI_U64                      u64GlobalOffset;
    HI_U32                      u32FrameSize;       /**< it is meaningless when indexing audio. */ /**<CNcomment: \D2\F4Ƶ\CB\F7\D2\FDʱ\CE\DE\D2\E2\D2\E5 */
    HI_U32                      u32DataTimeMs;
} HI_UNF_DMX_REC_INDEX_S;

/**index and record data*/
/**CNcomment: \CB\F7\D2\FD\CA\FD\BEݺ\CD¼\D6\C6\CA\FD\BE\DD*/
typedef struct hiUNF_DMX_REC_DATA_INDEX_S
{
    HI_U32 u32IdxNum;                                   /**< Number of index */ /**<CNcomment: \CB\F7\D2\FD\CA\FD\BEݸ\F6\CA\FD */
    HI_U32 u32RecDataCnt;                               /**< Number of record data block*/ /**<CNcomment: ¼\D6\C6\CA\FD\BEݿ\E9\B8\F6\CA\FD ,һ\B0\E3Ϊ1\B8\F6\A3\ACֻ\D3\D0\D4ڵ\B1ǰ¼\D6\C6\CA\FD\BE\DDһ\B2\BF\B7\D6\D4\DA¼\D6\C6bufferβ\B2\BF\A3\ACһ\B2\BF\B7\D6\D4\DAͷ\B2\BF\B5\C4ʱ\BA򣬻\E1\B7ֳ\C9\C1\BD\B8\F6block \B7ֱ\F0\BB\F1ȡ\C9\CF\C0\B4 */
    HI_UNF_DMX_REC_INDEX_S stIndex[DMX_MAX_IDX_ACQUIRED_EACH_TIME];
    HI_UNF_DMX_REC_DATA_S  stRecData[2];
} HI_UNF_DMX_REC_DATA_INDEX_S;

/**record buffer status*/
/**CNcomment: ¼\D6ƻ\BA\B3\E5\C7\F8״̬\BDṹ*/
typedef struct hiUNF_DMX_RECBUF_STATUS_S
{
    HI_U32  u32BufSize;     /**<Buffer size*/ /**< CNcomment:\BB\BA\B3\E5\C7\F8\B4\F3С */
    HI_U32  u32UsedSize;    /**<Used buffer*/ /**< CNcomment:\BB\BA\B3\E5\C7\F8\D2\D1ʹ\D3ô\F3С */
} HI_UNF_DMX_RECBUF_STATUS_S;

/**Repeat CC mode of channel*//**CNcomment:ͨ\B5\C0\B5\C4CC\D6ظ\B4ģʽ */
typedef enum hiUNF_DMX_CHAN_CC_REPEAT_MODE
{
    HI_UNF_DMX_CHAN_CC_REPEAT_MODE_RSV   = 0x0,     /**<Receive CC repeat ts packet*/ /**< CNcomment:\BD\D3\CA\D5cc\D6ظ\B4\B5\C4ts\B0\FC*/
    HI_UNF_DMX_CHAN_CC_REPEAT_MODE_DROP  = 0x1,     /**<Drop CC repeat ts packet*/ /**< CNcomment:\B6\AA\C6\FAcc\D6ظ\B4\B5\C4ts\B0\FC */
    HI_UNF_DMX_CHAN_CC_REPEAT_MODE_BUTT = -1
}HI_UNF_DMX_CHAN_CC_REPEAT_MODE_E;

typedef struct hiUNF_DMX_CHAN_CC_REPEAT_SET_S
{
    HI_HANDLE hChannel;                               /**<The channel handle*/ /**< CNcomment:ͨ\B5\C0\BE\E4\B1\FA*/
    HI_UNF_DMX_CHAN_CC_REPEAT_MODE_E enCCRepeatMode;   /**<Repeat CC mode of channel*/ /**< CNcomment:ͨ\B5\C0\B5\C4CCģʽ*/
}HI_UNF_DMX_CHAN_CC_REPEAT_SET_S;

/** PUSI (Payload Unit Start Index) config structure*/
/**CNcomment: PUSI \C5\E4\D6ýṹ\CC\E5 */
typedef struct hiUNF_DMX_PUSI_SET_S
{
    HI_BOOL bPusi;                               /**< Value of Pusi , Default is HI_FALSE means receive ts packet without checking PUSI*/ /**< CNcomment:NoPusiEn \B5\C4ֵ\A3\ACĬ\C8\CFΪ HI_FALSE \B1\EDʾ\BD\D3\CA\D5TS\B0\FC\B5\C4ʱ\BA򲻼\EC\B2\E2PUSI\B1\EA־*/
}HI_UNF_DMX_PUSI_SET_S;

/** TEI (Transport Error Index) config structure*/
/**CNcomment: TEI \C5\E4\D6ýṹ\CC\E5 */
typedef struct hiUNF_DMX_TEI_SET_S
{
    HI_U32   u32DemuxID;                    /**<The Subdiviece ID*/ /**< CNcomment:Demux \D7\D3\C9豸ID*/
    HI_BOOL bTei;                                   /**< Value of bTei , Default is HI_FALSE means receive ts packet even TEI equal 1*/ /**< CNcomment:TEICfg \B5\C4ֵ\A3\ACĬ\C8\CFΪ HI_FALSE \B1\EDʾ\BD\D3\CA\D5TEIΪ1 \B5\C4 TS\B0\FC\C8\D4Ȼ\BD\D3\CA\D5*/
}HI_UNF_DMX_TEI_SET_S;

/** Define of how TSI and TSO to be attached */
/**CNcomment: TSI/TSO\B0󶨹\D8ϵ\BDṹ\CC\E5 */
typedef struct hiUNF_DMX_TSI_ATTACH_TSO_S
{
    HI_UNF_DMX_PORT_E       enTSI;              /**<The TSI ID*/ /**< CNcomment:TSI \B6˿\DAID*/
    HI_UNF_DMX_TSO_PORT_E   enTSO;              /**<The TSO ID*/ /**< CNcomment:TSO \B6˿\DAID*/
}HI_UNF_DMX_TSI_ATTACH_TSO_S;

typedef enum hiUNF_DMX_INVOKE_TYPE
{
    HI_UNF_DMX_INVOKE_TYPE_CHAN_CC_REPEAT_SET  = 0,  /**<dmx set channel extra attr,param:HI_UNF_DMX_CHAN_CC_REPEAT_SET_S*//**<CNcomment: \C9\E8\D6\C3ͨ\B5\C0\B8\BD\BC\D3\CA\F4\D0ԣ\ACʹ\D3ò\CE\CA\FDHI_UNF_DMX_CHAN_CC_REPEAT_SET_S */
    HI_UNF_DMX_INVOKE_TYPE_PUSI_SET,                    /**<dmx set PUSI flag,param:HI_UNF_DMX_PUSI_SET_S*//**<CNcomment: \C9\E8\D6\C3 NoPusiEn \B1\EA־\A3\ACʹ\D3ò\CE\CA\FDHI_UNF_DMX_PUSI_SET_S */
    HI_UNF_DMX_INVOKE_TYPE_TEI_SET,             /**<dmx set TEI flag,param:HI_UNF_DMX_TEI_SET_S*//**<CNcomment: \C9\E8\D6\C3Demux \D7\D3\C9豸TEICfg \B1\EA־\A3\ACʹ\D3ò\CE\CA\FDHI_UNF_DMX_TEI_SET_S */
    HI_UNF_DMX_INVOKE_TYPE_TSI_ATTACH_TSO,      /**<Attach TSI with TSO ,param:HI_UNF_DMX_TSI_ATTACH_TSO_S*//**<CNcomment: \BD\ABTSI \D3\EB ĳ\B8\F6 TSO \B0\F3\B6\A8,\BC\B4: TSI \B5\C4\C2\EB\C1\F7\C0\B4\D7\D4 TSO \A3\ACʹ\D3ò\CE\CA\FDHI_UNF_DMX_TEI_SET_S */
    HI_UNF_DMX_INVOKE_TYPE_BUTT
} HI_UNF_DMX_INVOKE_TYPE_E;

/** Define cb context type */
/**CNcomment:\B6\A8\D2\E5\BBص\F7\C9\CF\CF\C2\CEĵ\C4\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_CB_CONTEXT_TYPE_E
{
    HI_UNF_DMX_CB_CONTEXT_TYPE_SHARED = 0, /**<public shared context thread*//**<CNcomment:\B9\B2\CF\ED\B5Ĺ\AB\B9\B2\C9\CF\CF\C2\CE\C4 */
    HI_UNF_DMX_CB_CONTEXT_TYPE_PRIVATE, /**<private context thread *//**<CNcomment:˽\D3\D0\C9\CF\CF\C2\CE\C4*/
    HI_UNF_DMX_CB_CONTEXT_TYPE_BUTT
}HI_UNF_DMX_CB_CONTEXT_TYPE_E;

/** Declare section/pes/post cb function interface */
/**CNcomment:\C9\F9\C3\F7section/pes/postͨ\B5\C0\B5Ļص\F7\BA\AF\CA\FD\BDӿ\DA*/
typedef HI_S32 (*HI_UNF_DMX_CHAN_BUF_CB_FUNC)(HI_HANDLE hChannel, HI_U32 u32AcquiredNum, HI_UNF_DMX_DATA_S *pstBuf, HI_VOID *pUserData);

/** Define cb descriptor */
/**CNcomment:\B6\A8\D2\E5\BBص\F7\C3\E8\CA\F6\D0\C5Ϣ*/
typedef struct hiUNF_DMX_CB_DESC_S
{
    HI_UNF_DMX_CB_CONTEXT_TYPE_E enContextType; /**<cb context type*//**<CNcomment:\BBص\F7\C9\CF\CF\C2\CE\C4\C0\E0\D0\CD*/
    HI_UNF_DMX_CHAN_BUF_CB_FUNC pfnChanBufCb; /**<section/pes/post cb function *//**<CNcomment:section/pes/postͨ\B5\C0\BBص\F7\BA\AF\CA\FD*/
    HI_VOID *pUserData; /** user private data *//**<CNcomment:\D3û\A7˽\D3\D0\D0\C5Ϣ */
}HI_UNF_DMX_CB_DESC_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      DEMUX */
/** @{ */  /** <!-- [DEMUX] */

/**
\brief Initializes the DEMUX module.CNcomment:\B3\F5ʼ\BB\AFDEMUXģ\BF顣CNend
\attention \n
Before using DEMUXs, you must call this application programming interface (API).\n
Before using the personal video recorder (PVR) or audio/video player (AVPLAY), you need to initialize the DEMUX module.\n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:\D4ڽ\F8\D0\D0DEMUX\CF\E0\B9ز\D9\D7\F7ǰӦ\B8\C3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA\n
\D4\DAʹ\D3\C3PVR\BA\CDAVPLAYǰ\C7\EB\CC\E1ǰ\BD\F8\D0\D0DEMUXģ\BF\E9\B5ĳ\F5ʼ\BB\AF\n
\D6ظ\B4\B5\F7\D3ñ\BE\BDӿڷ\B5\BBسɹ\A6\A1\A3CNend
\param  N/A.CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\see \n
N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_Init(HI_VOID);


/**
\brief Deinitializes the DEMUX module. CNcomment:ȥ\B3\F5ʼ\BB\AFDEMUXģ\BF顣CNend
\attention \n
After this API is called, the DEMUX module is stopped, and the DEMUX resources used by the process are released.\n
This API is valid when it is called for the first time. If this API is called repeatedly, the error code HI_SUCCESS is returned.
CNcomment:\B5\F7\D3ñ\BE\BDӿ\DAֹͣʹ\D3\C3DEMUXģ\BF飬\B2\A2\CAͷű\BE\BD\F8\B3\CC\CB\F9ռ\D3õ\C4DEMUX\D7\CAԴ\n
\B1\BE\BDӿڵ\DAһ\B4ε\F7\D3\C3\C6\F0\D7\F7\D3ã\AC\D6ظ\B4\B5\F7\D3÷\B5\BBسɹ\A6\A1\A3CNend
\param  N/A.CNcomment:\CEޡ\A3CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DeInit(HI_VOID);


/**
\brief Obtains the information about the service capabilities of the DEMUX module.The information includes the numbers of channels, filters, keys, ports, DEMUXs, and audio/video channels.
CNcomment:\B2\E9ѯDEMUXģ\BF\E9ҵ\CE\F1\C4\DC\C1\A6\A1\A3ҵ\CE\F1\B9\A6\C4ܰ\FC\C0\A8ͨ\D3\C3ͨ\B5\C0\CA\FDĿ\A1\A2\B9\FD\C2\CB\C6\F7\CA\FDĿ\A1\A2\C3\DCԿ\CA\FDĿ\A1\A2\B6˿\DA\CA\FDĿ\A1\A2DEMUX\C9豸\CA\FDĿ\BA\CD\D2\F4\CA\D3Ƶͨ\B5\C0\CA\FDĿ\B5ȡ\A3CNend
\attention \n
N/A.CNcomment:\CEޡ\A3CNend
\param[out] pstCap   Pointer to the capability of the DEMUX module (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6DEMUXģ\BF\E9\C4\DC\C1\A6\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null.CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
::HI_UNF_DMX_CAPABILITY_S
*/
HI_S32 HI_UNF_DMX_GetCapability(HI_UNF_DMX_CAPABILITY_S *pstCap);


/**
\brief Obtains the attributes of a DEMUX port.CNcomment:\BB\F1ȡDEMUX\B6˿\DA\CA\F4\D0ԡ\A3CNend
\attention \n
 N/A.CNcomment:\CEޡ\A3CNend
\param[in] enPortId Port ID.CNcomment:\B6˿ںš\A3CNend
\param[out] pstAttr Pointer to the port attributes (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null.CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSPortAttr(HI_UNF_DMX_PORT_E enPortId, HI_UNF_DMX_PORT_ATTR_S *pstAttr);


/**
\brief Sets the attributes of a DEMUX port.CNcomment:\C9\E8\D6\C3DEMUX\B6˿\DA\CA\F4\D0ԡ\A3CNend
\attention \n
It is recommended to query the default attributes of a DEMUX port by calling HI_UNF_DMX_GetTSPortAttr before modifying the attributes of the port.\n
The port mode can be queried only, notice that it will lose TS data if call this function during receiving data.\n
If the sync loss threshold and sync lock threshold are used, their default values are recommended.\n
For details on how to set the input clock of the tuner, select the line sequence of the port, and set the level of the tuner error line, contact hardware engineers of HiSilicon\n
and refer to tuner user manuals.
CNcomment:\BD\A8\D2\E9\CF\C8ͨ\B9\FDHI_UNF_DMX_GetTSPortAttr\BB\F1ȡĬ\C8\CF\CA\F4\D0ԣ\ACȻ\BA\F3\B6\D4Ҫ\B8ı\E4\B5\C4\CA\F4\D0Խ\F8\D0\D0\C9\E8\D6\C3\n
\B6˿\DAģʽֻ֧\B3ֲ\E9ѯ\A3\AC\B2\BB֧\B3\D6\D0޸ģ\ACע\D2\E2\CA\D5\CA\FD\BEݹ\FD\B3̵\F7\D3øýӿڻ\E1\D2\FD\C6\F0\B6\AATS\B0\FC\n
+\B2\BD\B6\AAʧ\BA\CDͬ\B2\BD\CB\F8\B6\A8\C3\C5\CFޣ\AC\CDƼ\F6ʹ\D3\C3Ĭ\C8\CFֵ\n
tuner\CA\E4\C8\EBʱ\D6ӷ\B4\CF򡢶˿\DA\CF\DF\D0\F2ѡ\D4\F1\BA\CDtuner error\CFߵ\E7ƽģʽ\B5\C4\C9\E8\D6\C3\C7\EB\D7\C9ѯӲ\BC\FE\B9\A4\B3\CCʦ\n
\B2\A2\B2ο\BCtuner\B5\C4\D3û\A7\CAֲᣬȻ\BA\F3\C9\E8\D6\C3Ϊ\BA\CF\CAʵ\C4ֵ\A1\A3CNend
\param[in] enPortId Port ID.CNcomment:\B6˿ںš\A3CNend
\param[in] pstAttr  Pointer to port attributes.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetTSPortAttr(HI_UNF_DMX_PORT_E enPortId, const HI_UNF_DMX_PORT_ATTR_S *pstAttr);


/**
\brief Obtains the attributes of a DEMUX TSO port.CNcomment:\BB\F1ȡDEMUX TS\CA\E4\B3\F6\B6˿\DA\CA\F4\D0ԡ\A3CNend
\attention \n
 N/A.CNcomment:\CEޡ\A3CNend
\param[in] enPortId Port ID.CNcomment:\B6˿ںš\A3CNend
\param[out] pstAttr Pointer to the port attributes (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null.CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSOPortAttr(HI_UNF_DMX_TSO_PORT_E enPortId, HI_UNF_DMX_TSO_PORT_ATTR_S *pstAttr);


/**
\brief Sets the attributes of a DEMUX TSO port.CNcomment:\C9\E8\D6\C3DEMUX TS \CA\E4\B3\F6\B6˿\DA\CA\F4\D0ԡ\A3CNend
\attention \n
It is recommended to query the default attributes of a DEMUX TSO port by calling HI_UNF_DMX_GetTSOPortAttr before modifying the attributes of the TSO port.
CNcomment:\BD\A8\D2\E9\CF\C8ͨ\B9\FDHI_UNF_DMX_GetTSPortAttr\BB\F1ȡĬ\C8\CF\CA\F4\D0ԣ\ACȻ\BA\F3\B6\D4Ҫ\B8ı\E4\B5\C4\CA\F4\D0Խ\F8\D0\D0\C9\E8\D6á\A3CNend
\param[in] enPortId Port ID.CNcomment:\B6˿ںš\A3CNend
\param[in] pstAttr  Pointer to port attributes.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetTSOPortAttr(HI_UNF_DMX_TSO_PORT_E enPortId, HI_UNF_DMX_TSO_PORT_ATTR_S *pstAttr);

/**
\brief Get the tag attributes.CNcomment:\BB\F1ȡtag \B5\C4\CF\E0\B9\D8\CA\F4\D0ԡ\A3CNend
\attention \n
pstAttr.au8Tag is a key index, this interface will return corresponding tag attrs if this key value has registered, otherwise return default tag attrs.
 N/A.CNcomment:pstAttr.au8Tag\B2\CE\CA\FD\CA\C7һ\B8\F6\CB\F7\D2\FD\A3\AC\D5\E2\B8\F6\BDӿڻ᷵\BBض\D4Ӧ\B5\C4tag\B2\CE\CA\FD\C8\E7\B9\FB\D5\E2\B8\F6\CB\F7\D2\FD\D2Ѿ\AD\B1\BBע\B2ᣬ\B7\F1\D4\F2\B5Ļ\B0\B7\B5\BB\D8Ĭ\C8ϵ\C4tag\CA\F4\D0\D4\C5\E4\D6á\A3CNend
\param[in] enPortId  TagPort ID.CNcomment:TapPort ID\BAš\A3CNend
\param[in & out] pstAttr Pointer to the tag port attributes (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACtag\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTagPortAttr(HI_UNF_DMX_PORT_E enPortId, HI_UNF_DMX_TAG_PORT_ATTR_S *pstAttr);

/**
\brief Set the tag attributes.CNcomment:\C9\E8\D6\C3tag\B5\C4\CF\E0\B9\D8\CA\F4\D0ԡ\A3CNend
\attention \n
pstAttr.au8Tag is a key index, it will register this new tag if this key value has not registered. otherwise increase tag reference number.
 N/A.CNcomment:pstAttr.au8Tag\B2\CE\CA\FD\CA\C7һ\B8\F6\CB\F7\D2\FD\A3\AC\D5\E2\B8\F6\BDӿڻ\E1ע\B2\E1\D0µ\C4tagֵ\C8\E7\B9\FBtagδ\B1\BBע\B2\E1\B5Ļ\B0\A3\AC\B7\F1\D4\F2\BB\E1\D4\F6\BC\D3tag\B5\C4Ӧ\D3ü\C6\CA\FD\A1\A3CNend
\param[in] enPortId  TagPort ID.CNcomment:TapPort ID\BAš\A3CNend
\param[in] pstAttr Pointer to the tag port attributes (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACtag\B6˿\DA\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
 */
HI_S32 HI_UNF_DMX_SetTagPortAttr(HI_UNF_DMX_PORT_E enPortId, const HI_UNF_DMX_TAG_PORT_ATTR_S *pstAttr);


/**
\brief Attaches a DEMUX to a port.CNcomment:\B0\F3\B6\A8DEMUX\B5\BD\B6˿\DA\C9ϡ\A3CNend
\attention \n
Each DEMUX can be attached to only one port, but the data from a port can be delivered to multiple DEMUXs.\n
After a DEMUX is attached to a port, the DEMUX starts to receive the data input from this port.\n
If the DEMUX is not used, you can detach it by calling HI_UNF_DMX_DetachTSPort.\n
The DEMUXs can be attached to different ports dynamically. That is, you can attach the DEMUXs without detaching them.\n
If you call this API to attach a DEMUX to the same channel, the error code HI_SUCCESS is returned.
CNcomment:ÿ·DEMUXֻ\C4ܰ󶨵\BDһ\B8\F6PORT\A3\AC\B5\AB\CA\C7һ\B8\F6PORT\B5\C4\CA\FD\BEݿ\C9\D2Էַ\A2\B5\BD\B6\E0\B8\F6DEMUX\n
DEMUX\B0󶨵\BD\B6˿\DA\C9\CF֮\BA\F3\BEͿ\AAʼ\BD\D3\CA\D5\D5\E2\B8\F6\B6˿\DA\C9\CF\CA\E4\C8\EB\B5\C4\CA\FD\BE\DD\n
\B2\BB\D4\D9ʹ\D3\C3\D5\E2·DEMUX\BD\D3\CA\D5\CA\FD\BEݺ\F3\A3\ACʹ\D3\C3HI_UNF_DMX_DetachTSPort\BDӿڽ\E2\B0\F3\B6\A8DEMUX\n
\BF\C9\D2Զ\AF̬\B5İ󶨵\BD\B2\BBͬ\B5Ķ˿\DA\C9ϣ\AC\B2\BB\D3\C3\CFȽ\E2\B0\F3\B6\A8\n
\D6ظ\B4\B5\F7\D3ô˽ӿڰ󶨵\BD\CF\E0ͬͨ\B5\C0\C9Ϸ\B5\BBسɹ\A6\A1\A3CNend
\param[in] u32DmxId  DEMUX ID.CNcomment:DEMUX\BAš\A3CNend
\param[in] enPortId  Port ID.CNcomment:\B6˿ںš\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
::HI_UNF_DMX_DetachTSPort
*/
HI_S32 HI_UNF_DMX_AttachTSPort(HI_U32 u32DmxId, HI_UNF_DMX_PORT_E enPortId);


/**
\brief Detaches a DEMUX from a port.CNcomment:\B4Ӷ˿\DA\C9Ͻ\E2\B0\F3\B6\A8DEMUX\A1\A3CNend
\attention \n
If a DEMUX is not used, you can detach it from the corresponding port by calling this API.\n
This API can be called dynamically, and can be used to disable the input sources of a DEMUX.\n
If this API is called repeatedly, the error code HI_SUCCESS is returned.
CNcomment:\B2\BB\D4\D9ʹ\D3\C3DEMUX\BD\D3\CA\D5\C8κ\CE\CA\FD\BE\DDʱʹ\D3ô˽ӿڽ\ABDEMUX\B4Ӷ˿\DA\C9Ͻ\E2\B0\F3\B6\A8\n
\BF\C9\D2Զ\AF̬ʹ\D3ý\E2\B0󶨽ӿڣ\AC\BF\C9\D2\D4ͨ\B9\FD\BD\E2\B0󶨽ӿ\DA\C7ж\CFDEMUX\B5\C4\CA\E4\C8\EBԴ\n
\D6ظ\B4\BD\E2\B0󶨷\B5\BBسɹ\A6\A1\A3CNend
\param[in] u32DmxId  DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
::HI_UNF_DMX_AttachTSPort
*/
HI_S32 HI_UNF_DMX_DetachTSPort(HI_U32 u32DmxId);


/**
\brief Obtains the ID of the port that is attached to a DEMUX. CNcomment:\BB\F1ȡDEMUX\CB\F9\B0󶨵Ķ˿ڵĶ˿ںš\A3CNend
\attention \n
If a DEMUX is not attached to any port, an error code is returned.CNcomment:\C8\E7\B9\FBDEMUXû\D3а󶨵\BD\C8κζ˿\DA\C9ϻ᷵\BBش\ED\CE\F3\C2롣CNend
\param[in] u32DmxId  DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[out] penPortId  Pointer to the ID of the port that is attached to a DEMUX(output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6DEMUX\B0󶨵Ķ˿ںš\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOATTACH_PORT  The DEMUX is not attached to any port.CNcomment:\B4\CB·DEMUXû\D3а󶨵\BD\C8κζ˿\DA\C9ϡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSPortId(HI_U32 u32DmxId, HI_UNF_DMX_PORT_E *penPortId);

/**
\brief Obtains the default attributes of a TS Buffer.CNcomment:\BB\F1ȡTS BufferĬ\C8\CF\CA\F4\D0ԡ\A3CNend
\attention \n
It is recommended to query the default TS Buffer attributes before creating a TS Buffer, and then modify the attributes,\n
notice the secure mode of default attributes is None Secure Mode.
CNcomment:\D7\EE\BA\C3\D4\DA\C9\EA\C7\EBTS Buffer֮ǰʹ\D3ô˽ӿڻ\F1ȡĬ\C8\CF\CA\F4\D0ԣ\AC\n
Ȼ\BA\F3\B8ı\E4\D0\E8Ҫ\D0޸ĵ\C4\CA\F4\D0Լ\B4\BFɣ\ACע\D2\E2Ĭ\C8\CF\CA\F4\D0\D4Ϊ\B7ǰ\B2ȫģʽ\A1\A3CNend
\param[out] pstTsBufAttr Pointer to the structure of the TS Buffer attributes.CNcomment:TS Buffer\CA\F4\D0Խṹ\CC\E5ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBufferDefaultAttr(HI_UNF_DMX_TSBUF_ATTR_S *pstTsBufAttr);

/**
\brief Creates a TS buffer for the RAM port to receive the TS data from Internet or local memory. CNcomment:ΪRAM\B6˿ڴ\B4\BD\A8TS Buffer\D3\C3\D3ڽ\D3\CAմ\D3\CD\F8\C2\E7\BB򱾵ش洢\D6\D0\CA\E4\C8\EB\B5\C4TS\CA\FD\BEݡ\A3CNend
\attention \n
A TS buffer can be created for the RAM port only.\n
The buffer size must range from 4 KB to 16 MB.\n
It is recommended to set the buffer size to an integral multiple of 4 KB. Otherwise, bottom alignment is performed inside.\n
The TS buffer cannot be created for the same port for multiple times; otherwise, an error code is returned.
CNcomment:ֻ\D3\D0RAM\B6˿ڿ\C9\D2Դ\B4\BD\A8TS Buffer\n
buffer\B4\F3С\B1\D8\D0\EB\D4\DA4K\BA\CD16M֮\BC䣬\B5\A5λΪ\D7ֽ\DA\n
buffer\B4\F3С\D7\EE\BA\C3Ϊ4K\B5\C4\D5\FB\CA\FD\B1\B6\A3\AC\C8\E7\B9\FB\B2\BB\CA\C7\D5\FB\CA\FD\B1\B6\A3\AC\C4ڲ\BF\BB\E1\BD\F8\D0\D0\CF\F2\CF¶\D4\C6\EB\B2\D9\D7\F7\n
+һ\B8\F6\B6˿ڲ\BB\C4\DC\D6ظ\B4\B4\B4\BD\A8TS Buffer,\B7\F1\D4򷵻ش\ED\CE\F3\C2롣CNend
\param[in] enPortId  Port ID.CNcomment:\B6˿ںš\A3CNend
\param[in] u32TsBufSize Size of a TS buffer.CNcomment:TS Buffer\B4\F3С\A1\A3CNend
\param[out] phTsBuffer  Pointer to the handle of a created TS buffer (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B4\B4\BD\A8\B5\C4TS Buffer \BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_RECREAT_TSBUFFER  The TS buffer corresponding to the port is created.CNcomment:\D6ظ\B4\B4\B4\BD\A8TS Buffer\A1\A3CNend
\see \n
N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateTSBuffer(HI_UNF_DMX_PORT_E enPortId, HI_U32 u32TsBufSize, HI_HANDLE *phTsBuffer);

/**
\brief Creates a TS buffer for the RAM port to receive the TS data from Internet or local memory. CNcomment:ΪRAM\B6˿ڴ\B4\BD\A8TS Buffer\D3\C3\D3ڽ\D3\CAմ\D3\CD\F8\C2\E7\BB򱾵ش洢\D6\D0\CA\E4\C8\EB\B5\C4TS\CA\FD\BEݡ\A3CNend
\attention \n
A TS buffer can be created for the RAM port only.\n
The buffer size must range from 4 KB to 16 MB.\n
It is recommended to set the buffer size to an integral multiple of 4 KB. Otherwise, bottom alignment is performed inside.\n
The TS buffer cannot be created for the same port for multiple times; otherwise, an error code is returned.
CNcomment:ֻ\D3\D0RAM\B6˿ڿ\C9\D2Դ\B4\BD\A8TS Buffer\n
buffer\B4\F3С\B1\D8\D0\EB\D4\DA4K\BA\CD16M֮\BC䣬\B5\A5λΪ\D7ֽ\DA\n
buffer\B4\F3С\D7\EE\BA\C3Ϊ4K\B5\C4\D5\FB\CA\FD\B1\B6\A3\AC\C8\E7\B9\FB\B2\BB\CA\C7\D5\FB\CA\FD\B1\B6\A3\AC\C4ڲ\BF\BB\E1\BD\F8\D0\D0\CF\F2\CF¶\D4\C6\EB\B2\D9\D7\F7\n
+һ\B8\F6\B6˿ڲ\BB\C4\DC\D6ظ\B4\B4\B4\BD\A8TS Buffer,\B7\F1\D4򷵻ش\ED\CE\F3\C2롣CNend
\param[in] enPortId  Port ID.CNcomment:\B6˿ںš\A3CNend
\param[in] pstTsBufAttr Attributes of a TS buffer.CNcomment:TS Buffer\B4\B4\BD\A8\CA\F4\D0ԡ\A3CNend
\param[out] phTsBuffer  Pointer to the handle of a created TS buffer (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B4\B4\BD\A8\B5\C4TS Buffer \BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_RECREAT_TSBUFFER  The TS buffer corresponding to the port is created.CNcomment:\D6ظ\B4\B4\B4\BD\A8TS Buffer\A1\A3CNend
\see \n
N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateTSBufferExt(HI_UNF_DMX_PORT_E enPortId, const HI_UNF_DMX_TSBUF_ATTR_S *pstTsBufAttr, HI_HANDLE *phTsBuffer);

/**
\brief Destroys an existing TS buffer. CNcomment:\CF\FA\BBٴ\B4\BD\A8\B5\C4TS Buffer\A1\A3CNend
\attention \n
A TS buffer cannot be destroyed repeatedly. If a TS buffer is destroyed, its handle is also destroyed.\n
In addition, if a buffer is destroyed, its data is cleared. In this case, the get and put operations are not available.\n
However, the data in channels is retained when a TS buffer is destroyed. To switch streams, you need disable the channel, and then enable the channel again.
CNcomment:\B2\BB\C4\DC\D6ظ\B4\CF\FA\BB\D9һ\B8\F6TS Buffer,\CF\FA\BB\D9֮\BA\F3handle\BEͲ\BB\B4\E6\D4\DA\C1\CB\n
\CF\FA\BB\D9֮\BA\F3buffer\D6е\C4\CA\FD\BEݾͻᱻ\C7\E5\BFգ\AC\B2\BB\C4\DC\D4ٽ\F8\D0\D0Get\BA\CDPut\B2\D9\D7\F7\n
\CF\FA\BB\D9TS buffer\B2\A2\B2\BB\C4\DC\C7\E5\BF\D5ͨ\B5\C0\D6\D0\CA\FD\BEݣ\ACҪ\C7л\BB\C2\EB\C1\F7\A3\ACҪע\D2\E2\B9ر\D5ͨ\B5\C0\A3\AC\D6\D8\D0´򿪡\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DestroyTSBuffer(HI_HANDLE hTsBuffer);

/**
\brief Behavior1, Default,need work with HI_UNF_DMX_PutTSBuffer. Obtains a TS buffer to input data.
CNcomment:\D0\D0Ϊһ\A3\ACĬ\C8\CFģʽ\A3\AC\D0\E8Ҫ\BA\CDHI_UNF_DMX_PutTSBuffer\C5\E4\BA\CFʹ\D3á\A3\BB\F1ȡTS Buffer\BFռ䣬\D3\C3\D3\DA\CA\FD\BE\DD\CA\E4\C8롣CNend
\attention \n
If you call this API repeatedly, the address of the same buffer is returned.\n
The input data length must be appropriate. If the data length is too large, data cannot be input in time.\n
If the data length is too small, the buffer is scheduled frequently, which causes the system performance to deteriorate.\n
If the size of the available space is smaller than the requested data length, an error code is returned.\n
To be specific, the requested data length must be smaller than the size of the available space, that is, the buffer cannot be full.\n
In addition, the requested data length cannot be 0; otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If u32TimeOutMs is set to 0, it indicates that the waiting time is 0; if u32TimeOutMs is set to 0XFFFFFFFF, it indicates infinite wait; if u32TimeOutMs is set to other values, it indicates that the waiting time is u32TimeOutMs ms.\n
If no buffer can be applied for during the block period, the error code HI_ERR_DMX_TIMEOUT is returned.\n
If u32TimeOutMs is set to 0, and no buffer can be applied for, it indicates that the internal TS buffer is full. In this case, you need to call the usleep(10000) function to release the CPU. Therefore, other threads can be scheduled.
CNcomment:\D6ظ\B4get\B7\B5\BB\D8ͬһ\B8\F6buffer\B5\D8ַ\n
\CA\E4\C8\EB\CA\FD\BE\DDʱע\D2\E2ÿ\B4\CE\CA\E4\C8\EB\B5\C4\CA\FD\BEݳ\A4\B6ȣ\AC̫\B3\A4\BF\C9\C4ܻᵼ\D6\C2\CA\E4\C8\EB\CA\FD\BEݲ\BB\BC\B0ʱ\n
+\B6̿\C9\C4ܻᵼ\D6µ\F7\B6\C8̫Ƶ\B7\B1\A3\AC\D0\D4\C4\DC\CF½\B5\n
\B5\B1ʣ\D3\E0\BFռ\E4С\D3ڵ\C8\D3\DA\C7\EB\C7\F3\B5ĳ\A4\B6\C8ʱ\A3\AC\B7\B5\BBش\ED\CE\F3\C2\EB\n
ÿ\B4\CE\C9\EA\C7\EB\B5ĳ\A4\B6\C8ҪС\D3\DAʣ\D3\E0ʣ\D3೤\B6ȣ\AC\BC\B4buffer\B2\BB\BF\C9\C4ܱ\BB\CC\EE\C2\FA\n
\C7\EB\C7󳤶Ȳ\BB\D4\CA\D0\EDΪ0\A3\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C9\E8\D6\C3Ϊ0\B1\EDʾ\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffff\B1\EDʾһֱ\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ\C6\E4\CB\FBֵ\B1\EDʾ\B5ȴ\FDu32TimeOutMs\BA\C1\C3롣\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\BB\B9\CE޷\A8\C9\EA\C7뵽Buffer\A3\AC\D4򷵻\D8HI_ERR_DMX_TIMEOUT\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C5\E4\D6\C3Ϊ0ʱ\A3\AC\C8\E7\B9\FB\C9\EA\C7벻\B5\BDBuffer\A3\AC˵\C3\F7\B4\CBʱ\C4ڲ\BFTS Buffer\BFռ\E4\D2\D1\C2\FA\A3\AC\D0\E8Ҫͨ\B9\FDusleep(10000)\CAͷ\C5cpu
\D2\D4ʹ\C6\E4\CB\FC\CF߳\CC\C4ܹ\BB\B5õ\BD\B5\F7\B6ȡ\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ReqLen Requested data length.CNcomment:\C7\EB\C7\F3\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\param[out] pstData  Data buffer.CNcomment:\CA\FD\BE\DDbuffer\BDṹ\A1\A3CNend
\param[in] u32TimeOutMs      Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out. CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_BUF  The size of the available buffer is smaller than the requested data length.CNcomment:ʣ\D3\E0buffer\BFռ\E4С\D3\DA\C7\EB\C7󳤶ȡ\A3CNend

\Behavior2,Support multrtherad operate one tsbuffer,Only Valid wen CFG_HI_DMX_TSBUF_MULTI_THREAD_SUPPORT=y, need work with HI_UNF_DMX_PushTSBuffer and HI_UNF_DMX_ReleaseTSBuffer. Obtains a TS buffer to input data.
CNcomment:\D0\D0Ϊ\B6\FE\A3\AC֧\B3ֶ\E0\CF̲߳\D9\D7\F7ͬһ\B8\F6TSbufferģʽ\A3\AC\BD\F6\B5\B1CFG_HI_DMX_TSBUF_MULTI_THREAD_SUPPORT=y\D3\D0Ч\A3\AC\D0\E8Ҫ\BA\CDHI_UNF_DMX_PushTSBuffer\A1\A2HI_UNF_DMX_ReleaseTSBuffer\C5\E4\BA\CFʹ\D3á\A3\BB\F1ȡTS Buffer\BFռ䣬\D3\C3\D3\DA\CA\FD\BE\DD\CA\E4\C8롣CNend
\attention \n
If you call this API repeatedly and didn't call HI_UNF_DMX_ReleaseTSBuffer, the address of the different buffer block is
returned and memory leak will be happened, this function must be couple with HI_UNF_DMX_ReleaseTSBuffer.\n
The input data length must be appropriate. If the data length is too large, data cannot be input in time.\n
If the data length is too small, the buffer is scheduled frequently, which causes the system performance to deteriorate.\n
If the size of the available space is smaller than the requested data length, an error code is returned.\n
To be specific, the requested data length must be smaller than the size of the available space, that is, the buffer cannot be full.\n
In addition, the requested data length cannot be 0; otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If u32TimeOutMs is set to 0, it indicates that the waiting time is 0; if u32TimeOutMs is set to 0XFFFFFFFF, it indicates infinite wait; if u32TimeOutMs is set to other values, it indicates that the waiting time is u32TimeOutMs ms.\n
If no buffer can be applied for during the block period, the error code HI_ERR_DMX_TIMEOUT is returned.\n
If u32TimeOutMs is set to 0, and no buffer can be applied for, it indicates that the internal TS buffer is full. In this case, you need to call the usleep(10000) function to release the CPU. Therefore, other threads can be scheduled.
CNcomment:\D6ظ\B4get\B7\B5\BBز\BBͬbuffer\BF\E9\B5ĵ\D8ַ\A3\AC\B2\A2\C7\D2\C8\E7\B9\FB\B1\BE\BDӿڵ\F7\D3óɹ\A6\B6\F8\B2\BB\B5\F7\D3\C3HI_UNF_DMX_ReleaseTSBuffer\A3\AC
\D4\F2\BB\E1\D2\FD\C6\F0\C4ڴ\E6й©\A3\AC\CB\F9\D2\D4ֻҪ\B1\BE\BDӿڵ\F7\D3óɹ\A6\A3\AC\B1\D8\D0\EB\B5\F7\D3\C3HI_UNF_DMX_ReleaseTSBufferȷ\B1\A3buffer\BF\E9\D5\FDȷ\CAͷš\A3\n
\CA\E4\C8\EB\CA\FD\BE\DDʱע\D2\E2ÿ\B4\CE\CA\E4\C8\EB\B5\C4\CA\FD\BEݳ\A4\B6ȣ\AC̫\B3\A4\BF\C9\C4ܻᵼ\D6\C2\CA\E4\C8\EB\CA\FD\BEݲ\BB\BC\B0ʱ\n
+\B6̿\C9\C4ܻᵼ\D6µ\F7\B6\C8̫Ƶ\B7\B1\A3\AC\D0\D4\C4\DC\CF½\B5\n
\B5\B1ʣ\D3\E0\BFռ\E4С\D3ڵ\C8\D3\DA\C7\EB\C7\F3\B5ĳ\A4\B6\C8ʱ\A3\AC\B7\B5\BBش\ED\CE\F3\C2\EB\n
ÿ\B4\CE\C9\EA\C7\EB\B5ĳ\A4\B6\C8ҪС\D3\DAʣ\D3\E0ʣ\D3೤\B6ȣ\AC\BC\B4buffer\B2\BB\BF\C9\C4ܱ\BB\CC\EE\C2\FA\n
\C7\EB\C7󳤶Ȳ\BB\D4\CA\D0\EDΪ0\A3\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C9\E8\D6\C3Ϊ0\B1\EDʾ\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffff\B1\EDʾһֱ\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ\C6\E4\CB\FBֵ\B1\EDʾ\B5ȴ\FDu32TimeOutMs\BA\C1\C3롣\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\BB\B9\CE޷\A8\C9\EA\C7뵽Buffer\A3\AC\D4򷵻\D8HI_ERR_DMX_TIMEOUT\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C5\E4\D6\C3Ϊ0ʱ\A3\AC\C8\E7\B9\FB\C9\EA\C7벻\B5\BDBuffer\A3\AC˵\C3\F7\B4\CBʱ\C4ڲ\BFTS Buffer\BFռ\E4\D2\D1\C2\FA\A3\AC\D0\E8Ҫͨ\B9\FDusleep(10000)\CAͷ\C5cpu
\D2\D4ʹ\C6\E4\CB\FC\CF߳\CC\C4ܹ\BB\B5õ\BD\B5\F7\B6ȡ\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ReqLen Requested data length.CNcomment:\C7\EB\C7\F3\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\param[out] pstData  Data buffer.CNcomment:\CA\FD\BE\DDbuffer\BDṹ\A1\A3CNend
\param[in] u32TimeOutMs      Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out. CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_BUF  The size of the available buffer is smaller than the requested data length.CNcomment:ʣ\D3\E0buffer\BFռ\E4С\D3\DA\C7\EB\C7󳤶ȡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBuffer(HI_HANDLE hTsBuffer, HI_U32 u32ReqLen,
            HI_UNF_STREAM_BUF_S *pstData, HI_U32 u32TimeOutMs);

/**
\brief Obtains a TS buffer to input data.CNcomment:\BB\F1ȡTS Buffer\BFռ䣬\D3\C3\D3\DA\CA\FD\BE\DD\CA\E4\C8롣CNend
\attention \n
If you call this API repeatedly, the address of the same buffer is returned.\n
The input data length must be appropriate. If the data length is too large, data cannot be input in time.\n
If the data length is too small, the buffer is scheduled frequently, which causes the system performance to deteriorate.\n
If the size of the available space is smaller than the requested data length, an error code is returned.\n
To be specific, the requested data length must be smaller than the size of the available space, that is, the buffer cannot be full.\n
In addition, the requested data length cannot be 0; otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If u32TimeOutMs is set to 0, it indicates that the waiting time is 0; if u32TimeOutMs is set to 0XFFFFFFFF, it indicates infinite wait; if u32TimeOutMs is set to other values, it indicates that the waiting time is u32TimeOutMs ms.\n
If no buffer can be applied for during the block period, the error code HI_ERR_DMX_TIMEOUT is returned.\n
If u32TimeOutMs is set to 0, and no buffer can be applied for, it indicates that the internal TS buffer is full. In this case, you need to call the usleep(10000) function to release the CPU. Therefore, other threads can be scheduled.
CNcomment:\D6ظ\B4get\B7\B5\BB\D8ͬһ\B8\F6buffer\B5\D8ַ\n
\CA\E4\C8\EB\CA\FD\BE\DDʱע\D2\E2ÿ\B4\CE\CA\E4\C8\EB\B5\C4\CA\FD\BEݳ\A4\B6ȣ\AC̫\B3\A4\BF\C9\C4ܻᵼ\D6\C2\CA\E4\C8\EB\CA\FD\BEݲ\BB\BC\B0ʱ\n
+\B6̿\C9\C4ܻᵼ\D6µ\F7\B6\C8̫Ƶ\B7\B1\A3\AC\D0\D4\C4\DC\CF½\B5\n
\B5\B1ʣ\D3\E0\BFռ\E4С\D3ڵ\C8\D3\DA\C7\EB\C7\F3\B5ĳ\A4\B6\C8ʱ\A3\AC\B7\B5\BBش\ED\CE\F3\C2\EB\n
ÿ\B4\CE\C9\EA\C7\EB\B5ĳ\A4\B6\C8ҪС\D3\DAʣ\D3\E0ʣ\D3೤\B6ȣ\AC\BC\B4buffer\B2\BB\BF\C9\C4ܱ\BB\CC\EE\C2\FA\n
\C7\EB\C7󳤶Ȳ\BB\D4\CA\D0\EDΪ0\A3\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C9\E8\D6\C3Ϊ0\B1\EDʾ\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffff\B1\EDʾһֱ\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ\C6\E4\CB\FBֵ\B1\EDʾ\B5ȴ\FDu32TimeOutMs\BA\C1\C3롣\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\BB\B9\CE޷\A8\C9\EA\C7뵽Buffer\A3\AC\D4򷵻\D8HI_ERR_DMX_TIMEOUT\B4\ED\CE\F3\C2\EB\n
u32TimeOutMs\C5\E4\D6\C3Ϊ0ʱ\A3\AC\C8\E7\B9\FB\C9\EA\C7벻\B5\BDBuffer\A3\AC˵\C3\F7\B4\CBʱ\C4ڲ\BFTS Buffer\BFռ\E4\D2\D1\C2\FA\A3\AC\D0\E8Ҫͨ\B9\FDusleep(10000)\CAͷ\C5cpu
\D2\D4ʹ\C6\E4\CB\FC\CF߳\CC\C4ܹ\BB\B5õ\BD\B5\F7\B6ȡ\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ReqLen Requested data length.CNcomment:\C7\EB\C7\F3\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\param[out] pstData  Data buffer.CNcomment:\CA\FD\BE\DDbuffer\BDṹ\A1\A3CNend
\param[out] pu32PhyAddr buffer physical address.CNcomment:buffer\B5\C4\CE\EF\C0\ED\B5\D8ַ\A1\A3CNend
\param[in] u32TimeOutMs      Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out. CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_BUF  The size of the available buffer is smaller than the requested data length.CNcomment:ʣ\D3\E0buffer\BFռ\E4С\D3\DA\C7\EB\C7󳤶ȡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBufferEx(HI_HANDLE hTsBuffer, HI_U32 u32ReqLen,
            HI_UNF_STREAM_BUF_S *pstData, HI_U32 *pu32PhyAddr, HI_U32 u32TimeOutMs);

/**
\brief Updates the write pointer of a TS buffer after the TS data is input.CNcomment:TS\CA\FD\BE\DD\CA\E4\C8\EB\CD\EA\B1ϣ\AC\D3\C3\D3ڸ\FC\D0\C2TS Bufferдָ\D5롣CNend
\attention \n
This API must work with HI_UNF_DMX_GetTSBuffer. That is, if you call HI_UNF_DMX_PutTSBuffer without calling HI_UNF_DMX_GetTSBuffer, no operation takes effect, but the error code HI_SUCCESS is returned.\n
If the valid data length is 0, no operation takes effect, and the error code HI_SUCCESS.\n
The valid data length cannot be greater than data length queried by calling HI_UNF_DMX_GetTSBuffer. Otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If the valid data length is smaller than the data length queried by calling HI_UNF_DMX_GetTSBuffer, it indicates that a part of data is stored.
CNcomment:\B4˽ӿڱ\D8\D0\EB\BA\CDGet\BDӿ\DA\C5\E4\B6\D4ʹ\D3ã\AC\C8\E7\B9\FBû\D3\D0Get\D4\F2\BD\F8\D0\D0Put\B2\D9\D7\F7\A3\AC\D4򲻻\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7\A3\AC\B5\AB\B7\B5\BBسɹ\A6\n
Put\B5ĳ\A4\B6\C8\C8\E7\B9\FBΪ0\A3\ACҲ\B2\BB\BB\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7ֱ\BDӷ\B5\BBسɹ\A6\n
\B2\BB\D4\CA\D0\EDPut\B3\A4\B6ȴ\F3\D3\DAʵ\BC\CAGet\B5\BD\B5ĳ\A4\B6ȣ\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
\D4\CA\D0\EDPut\B3\A4\B6\C8С\D3\DAGet\B3\A4\B6ȣ\AC\B1\ED\C3\F7ֻ\CA\E4\C8\EB\C1\CBһ\B2\BF\B7\D6\CA\FD\BE\DD\n
Ϊ\CC\E1\B8\DFЧ\C2ʣ\ACPut\B5ĳ\A4\B6Ⱦ\A1\C1\BF\B2\BBҪ̫\B6̣\AC\BE\A1\C1\BF\B1\A3\B3\D6\D4\DA10\B8\F6ts\B0\FC\D2\D4\C9\CFPutһ\B4Σ\AC\CA\FD\BE\DD̫\B6̻ᵼ\D6\C2\D0\D4\C4\DC\CF½\B5\n\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ValidDataLen Valid data length.CNcomment:\D3\D0Ч\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_PutTSBuffer(HI_HANDLE hTsBuffer, HI_U32 u32ValidDataLen);

/**
\brief Updates the write pointer of a TS buffer after the TS data is input.CNcomment:TS\CA\FD\BE\DD\CA\E4\C8\EB\CD\EA\B1ϣ\AC\D3\C3\D3ڸ\FC\D0\C2TS Bufferдָ\D5롣CNend
\attention \n
This API must work with HI_UNF_DMX_GetTSBuffer. That is, if you call HI_UNF_DMX_PutTSBuffer without calling HI_UNF_DMX_GetTSBuffer, no operation takes effect, but the error code HI_SUCCESS is returned.\n
If the valid data length is 0, no operation takes effect, and the error code HI_SUCCESS.\n
The valid data length cannot be greater than data length queried by calling HI_UNF_DMX_GetTSBuffer. Otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If the valid data length is smaller than the data length queried by calling HI_UNF_DMX_GetTSBuffer, it indicates that a part of data is stored.
CNcomment:\B4˽ӿڱ\D8\D0\EB\BA\CDGet\BDӿ\DA\C5\E4\B6\D4ʹ\D3ã\AC\C8\E7\B9\FBû\D3\D0Get\D4\F2\BD\F8\D0\D0Put\B2\D9\D7\F7\A3\AC\D4򲻻\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7\A3\AC\B5\AB\B7\B5\BBسɹ\A6\n
Put\B5ĳ\A4\B6\C8\C8\E7\B9\FBΪ0\A3\ACҲ\B2\BB\BB\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7ֱ\BDӷ\B5\BBسɹ\A6\n
\B2\BB\D4\CA\D0\EDPut\B3\A4\B6ȴ\F3\D3\DAʵ\BC\CAGet\B5\BD\B5ĳ\A4\B6ȣ\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
\D4\CA\D0\EDPut\B3\A4\B6\C8С\D3\DAGet\B3\A4\B6ȣ\AC\B1\ED\C3\F7ֻ\CA\E4\C8\EB\C1\CBһ\B2\BF\B7\D6\CA\FD\BE\DD\n
Ϊ\CC\E1\B8\DFЧ\C2ʣ\ACPut\B5ĳ\A4\B6Ⱦ\A1\C1\BF\B2\BBҪ̫\B6̣\AC\BE\A1\C1\BF\B1\A3\B3\D6\D4\DA10\B8\F6ts\B0\FC\D2\D4\C9\CFPutһ\B4Σ\AC\CA\FD\BE\DD̫\B6̻ᵼ\D6\C2\D0\D4\C4\DC\CF½\B5\n\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ValidDataLen Valid data length.CNcomment:\D3\D0Ч\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
\param[in] u32StartPos start position of the valid data. CNcomment:\D3\D0Ч\CA\FD\BEݵ\C4\C6\F0ʼλ\D6á\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_PutTSBufferEx(HI_HANDLE hTsBuffer, HI_U32 u32ValidDataLen, HI_U32 u32StartPos);

/**
\brief Only valid when CFG_HI_DMX_TSBUF_MULTI_THREAD_SUPPORT=y Updates the write pointer of a TS buffer after the TS data is input.CNcomment:TS\CA\FD\BE\DD\CA\E4\C8\EB\CD\EA\B1ϣ\AC\D3\C3\D3ڸ\FC\D0\C2TS Bufferдָ\D5롣CNend
\attention \n
This API must work after HI_UNF_DMX_GetTSBuffer success. That is, if you call HI_UNF_DMX_PushTSBuffer without calling HI_UNF_DMX_GetTSBuffer, no operation takes effect, but the error code HI_SUCCESS is returned.\n
If the valid data length is 0, no operation takes effect, and the error code HI_SUCCESS.\n
The valid data length cannot be greater than data length queried by calling HI_UNF_DMX_GetTSBuffer. Otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If the valid data length is smaller than the data length queried by calling HI_UNF_DMX_GetTSBuffer, it indicates that a part of data is stored.
CNcomment:\B4˽ӿڱ\D8\D0\EB\D4\DAGet\BDӿڵ\F7\D3óɹ\A6\BA\F3ʹ\D3ã\AC\C8\E7\B9\FBû\D3\D0Get\D4\F2\BD\F8\D0\D0Push\B2\D9\D7\F7\A3\AC\D4򲻻\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7\A3\AC\B5\AB\B7\B5\BBسɹ\A6\n
Put\B5ĳ\A4\B6\C8\C8\E7\B9\FBΪ0\A3\ACҲ\B2\BB\BB\E1\BD\F8\D0\D0\C8κβ\D9\D7\F7ֱ\BDӷ\B5\BBسɹ\A6\n
\B2\BB\D4\CA\D0\EDPush\B3\A4\B6ȴ\F3\D3\DAʵ\BC\CAGet\B5\BD\B5ĳ\A4\B6ȣ\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
\D4\CA\D0\EDPush\B3\A4\B6\C8С\D3\DAGet\B3\A4\B6ȣ\AC\B1\ED\C3\F7ֻ\CA\E4\C8\EB\C1\CBһ\B2\BF\B7\D6\CA\FD\BE\DD\n
Ϊ\CC\E1\B8\DFЧ\C2ʣ\ACPush\B5ĳ\A4\B6Ⱦ\A1\C1\BF\B2\BBҪ̫\B6̣\AC\BE\A1\C1\BF\B1\A3\B3\D6\D4\DA10\B8\F6ts\B0\FC\D2\D4\C9\CFPushһ\B4Σ\AC\CA\FD\BE\DD̫\B6̻ᵼ\D6\C2\D0\D4\C4\DC\CF½\B5\n\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] pstData, the pointer of HI_UNF_STREAM_BUF_S.CNcomment:buffer\C3\E8\CA\F6\BDṹ\CC\E5ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_PushTSBuffer(HI_HANDLE hTsBuffer, const HI_UNF_STREAM_BUF_S *pstData);

/**
\brief Only valid when CFG_HI_DMX_TSBUF_MULTI_THREAD_SUPPORT=y Release the Ts buffer Get by  HI_UNF_DMX_GetTSBuffer.CNcomment:\CAͷ\C5\D3\C9HI_UNF_DMX_GetTSBuffer\BDӿ\DA\C9\EA\C7\EB\B5\C4TS buffer\BFռ䡣
\attention \n
This API must work with HI_UNF_DMX_GetTSBuffer. That is, you must call HI_UNF_DMX_ReleaseTSBuffer if HI_UNF_DMX_GetTSBuffer has success,
if not, there will be memory leak happened.\n
The valid data length cannot be greater than data length queried by calling HI_UNF_DMX_GetTSBuffer. Otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If the valid data length must be same as the data length queried by calling HI_UNF_DMX_GetTSBuffer.
CNcomment:\B4˽ӿڱ\D8\D0\EB\BA\CDGet\BDӿ\DA\C5\E4\B6\D4ʹ\D3ã\AC\BB\BB\BE仰˵HI_UNF_DMX_GetTSBuffer\B5\F7\D3óɹ\A6\BA\F3\B1\D8\D0\EB\B5\F7\D3ñ\BE\BDӿ\DA\CAͷ\C5buffer\A3\AC
\B7\F1\D4\F2\BD\AB\D3\D0\C4ڴ\E6й©\B7\A2\C9\FA\A1\A3\n
\B2\BB\D4\CA\D0\EDRelease\B3\A4\B6ȴ\F3\D3\DAʵ\BC\CAGet\B5\BD\B5ĳ\A4\B6ȣ\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
Release\B3\A4\B6ȱ\D8\D0\EB\BA\CDGet\B5ĳ\A4\B6\C8һ\D6¡\A3\n
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[in] pstData, the pointer of HI_UNF_STREAM_BUF_S.CNcomment:buffer\C3\E8\CA\F6\BDṹ\CC\E5ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_ReleaseTSBuffer(HI_HANDLE hTsBuffer, const HI_UNF_STREAM_BUF_S *pstData);

/**
\brief Resets a TS buffer to clear its data.CNcomment:\B8\B4λTS Buffer\A3\AC\C7\E5\BF\D5TS Buffer\D6е\C4\CA\FD\BEݡ\A3CNend
\attention \n
If a TS buffer is reset, you can call HI_UNF_DMX_PutTSBuffer only after calling HI_UNF_DMX_GetTSBuffer.CNcomment:TS Buffer\B8\B4λ\BA\F3\D0\E8Ҫ\D6\D8\D0\C2get\B2\C5\C4\DCִ\D0\D0put\B2\D9\D7\F7\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_ResetTSBuffer(HI_HANDLE hTsBuffer);

/**
\brief Obtains the status of a TS buffer. CNcomment:\BB\F1ȡTS Buffer״̬\A1\A3CNend
\attention \n
You can query the size of a TS buffer and the used buffer size by calling this API. CNcomment:\BF\C9\D2Բ\E9ѯTS Buffer\B4\F3С\BA\CD\D2\D1\D3õĿռ\E4\B4\F3С\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[out] pStatus  TS buffer status.CNcomment:TS Buffer״̬\BDṹ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBufferStatus(HI_HANDLE hTsBuffer, HI_UNF_DMX_TSBUF_STATUS_S *pStatus);

/**
\brief Obtains the ID of the port corresponding to a TS buffer.CNcomment:\BB\F1ȡTS Buffer\B6\D4Ӧ\B5\C4Port ID\A1\A3CNend
\attention \n
If you query the ID of the port corresponding to a TS buffer that is not applied for successfully, an error code is returned.
CNcomment:\B6\D4\D3\DAû\D3\D0\C9\EA\C7\EB\B5\C4TS buffer,\B2\E9ѯ\BB᷵\BBش\ED\CE\F3\A1\A3CNend
\param[in] hTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\param[out] penPortId  ID of the port.corresponding to a TS buffer  CNcomment:TS Buffer\B6\D4Ӧ\B5\C4Port ID\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBufferPortId(HI_HANDLE hTsBuffer, HI_UNF_DMX_PORT_E *penPortId);

/**
\brief Obtains the handle of the TS buffer corresponding to a port ID.CNcomment:\BB\F1ȡPort ID\B6\D4Ӧ\B5\C4TS Buffer handle\A1\A3CNend
\attention \n
If you obtain the handle of a TS buffer that is not created, an error code is returned.CNcomment:\B6\D4\D3\DAû\D3\D0\C9\EA\C7\EB\B5\C4TS buffer,\B2\E9ѯ\BB᷵\BBش\ED\CE\F3\A1\A3CNend
\param[in] enPortId   Port ID. CNcomment:\B6˿ںš\A3CNend
\param[out] phTsBuffer Handle of a TS buffer.CNcomment:TS Buffer\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSBufferHandle(HI_UNF_DMX_PORT_E enPortId, HI_HANDLE *phTsBuffer);

/**
\brief Obtains the information about TS packets of a port.CNcomment:\BB\F1ȡ\B6˿ڵ\C4TS\B0\FC\D0\C5Ϣ\A1\A3CNend
\attention \n
If you query the information about an unattached port, an error code is returned.
CNcomment:\B6\D4\D3\DAû\D3а󶨵Ķ˿\DA,\B2\E9ѯ\BB᷵\BBش\ED\CE\F3\A1\A3CNend
\param[in] enPortId    Port ID. CNcomment:\B6˿ںš\A3CNend
\param[out] sPortStat   Number of TS packets .CNcomment:TS\B0\FC\BC\C6\CA\FD\D0\C5Ϣ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetTSPortPacketNum(HI_UNF_DMX_PORT_E enPortId, HI_UNF_DMX_PORT_PACKETNUM_S *sPortStat);

/**
\brief Obtains the information of a channel.CNcomment:\BB\F1ȡָ\B6\A8channel\B5\C4\D0\C5Ϣ\A1\A3CNend
\attention \n
\param[in] hChannel    Channel handle. CNcomment:Channel\BE\E4\B1\FA CNend
\param[out] sChStat   Status of the channel .CNcomment:channel\B5\C4״̬\D0\C5Ϣ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelPacketNum(HI_HANDLE hChannel, HI_UNF_DMX_CHAN_PACKETNUM_S *sChStat);

/**
\brief Obtains the default attributes of a channel.CNcomment:\BB\F1ȡͨ\B5\C0Ĭ\C8\CF\CA\F4\D0ԡ\A3CNend
\attention \n
It is recommended to query the default channel attributes before creating a channel, and then modify the attributes.\n
By default, the attributes of the Section channel are returned. If other channels are used, you need to modify the attributes.
CNcomment:\D7\EE\BA\C3\D4\DA\C9\EA\C7\EBͨ\B5\C0֮ǰʹ\D3ô˽ӿڻ\F1ȡĬ\C8\CF\CA\F4\D0ԣ\ACȻ\BA\F3\B8ı\E4\D0\E8Ҫ\D0޸ĵ\C4\CA\F4\D0Լ\B4\BF\C9\n
Ĭ\C8\CF\CA\F4\D0԰\B4һ\B0\E3\B5\C4sectionͨ\B5\C0\B7\B5\BBصģ\AC\C8\E7\B9\FBҪʹ\D3\C3\C6\E4\CB\FB\C0\E0\D0͵\C4ͨ\B5\C0ע\D2\E2\D0޸\C4\CA\F4\D0\D4ֵ\A1\A3CNend
\param[out] pstChAttr Pointer to the structure of the channel attributes.CNcomment:ͨ\B5\C0\CA\F4\D0Խṹ\CC\E5ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelDefaultAttr(HI_UNF_DMX_CHAN_ATTR_S *pstChAttr);


/**
\brief Creates a PID channel based on channel attributes.CNcomment:\B8\F9\BE\DDͨ\B5\C0\CA\F4\D0Դ\B4\BD\A8һ\B8\F6PIDͨ\B5\C0\A1\A3CNend
\attention \n
It is recommended to call HI_UNF_DMX_GetChannelDefaultAttr to query default channel attributes before calling HI_UNF_DMX_CreateChannel.
For the Section channel and ECM/EMM channel, you can set the CRC mode, and dynamically change the CRC mode by calling HI_UNF_DMX_SetChannelAttr.\n
For other channels, the CRC check is always disabled. If you select other CRC modes, the CRC disable mode takes effect by default.\n
You need to set the buffer size when creating a channel. The buffer size is in the unit of byte and the default size is 16 KB.\n
It is recommended to set the buffer size to a value greater than 4 KB for the Section channel, ECM/EMM channel, or post channel. If the buffer size is smaller than 4 KB, the size of 4 KB is used by default.\n
It is recommended to set the buffer size to a value greater than 64 KB for the PES channel. If the buffer size is smaller than 64 KB, the size of 64 KB is used by default.\n
The playing channel and playing/recording channel cannot be created at the same time./n
The audio/video playing channels are allocated and managed by the player.
CNcomment:\BD\A8\D2\E9\B5\F7\D3ô˽ӿ\DA֮ǰ\A3\AC\BD\A8\D2\E9\CFȵ\F7\D3\C3HI_UNF_DMX_GetChannelDefaultAttr\BB\F1ȡͨ\B5\C0Ĭ\C8\CF\CA\F4\D0\D4\n
+\D3\D0section\C0\E0\D0͵\C4ͨ\B5\C0\BA\CDecm emm\C0\E0\D0͵\C4ͨ\B5\C0֧\B3\D6\C9\E8\D6\C3CRCģʽ\A3\AC\B2\A2\C7ҿ\C9\D2\D4ͨ\B9\FD\CA\F4\D0\D4\C9\E8\D6ýӿڶ\AF̬\D0޸\C4CRCģʽ\n
\C6\E4\CB\FB\C0\E0\D0\CDͨ\B5\C0ֻ֧\B3\D6\C9\E8\D6\C3ΪCRC\BD\FBֹ\A3\AC\C8\E7\B9\FBѡ\D4\F1\C1\CB\C6\E4\CB\FB\C0\E0\D0͵\C4CRC\BBᱻĬ\C8\CF\D0޸\C4ΪCRC\BD\FBֹ\n
\D4\DA\C9\EA\C7\EBͨ\B5\C0ʱע\D2\E2Buffer\B4\F3С\B5\C4\C5\E4\D6ã\ACĬ\C8ϴ\F3СΪ16K\A3\ACbuffer\B4\F3С\B5ĵ\A5λΪ\D7ֽ\DA\n
Section\A1\A2ecm emm\BA\CDPOSTͨ\B5\C0\B5\C4buffer\B4\F3С\D6\C1\C9\D9Ϊ4K\A3\AC\C8\E7\B9\FBС\D3\DA4K\BBᱻĬ\C8\CF\D0޸\C4Ϊ4K\n
PESͨ\B5\C0\BD\A8\D2\E9ʹ\D3\C364K\D2\D4\C9ϵ\C4buffer\B4\F3С\A3\AC\C8\E7\B9\FBС\D3\DA64K\BBᱻĬ\C8\CF\D0޸\C4Ϊ64K\n
\B2\A5\B7\C5\C0\E0\D0ͺ\CDͬʱ\B2\A5\B7\C5\D3\EB¼\D6\C6\C0\E0\D0͵\C4\D2\F4\CA\D3Ƶͨ\B5\C0\CAǲ\BB\C4\DC\C9\EA\C7\EB\B5\C4\n
\D2\F4\CA\D3Ƶ\B5Ĳ\A5\B7\C5ͨ\B5\C0\D3\C9Playerͳһ\B7\D6\C5\E4\BA͹\DC\C0\ED\A1\A3CNend
\param[in] u32DmxId  DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[in] pstChAttr  Pointer to the attributes of an input channel. For details, see the description of HI_UNF_DMX_CHAN_ATTR_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EBͨ\B5\C0\CA\F4\D0ԡ\A3\C7\EB\B2μ\FB::HI_UNF_DMX_CHAN_ATTR_S\A1\A3CNend
\param[out] phChannel  Pointer to the handle of an allocated channel.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B7\D6\C5\E4\B5\C4ͨ\B5\C0Handle\A1\A3\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_CHAN  There is no available channel.CNcomment:û\D3п\D5\CF\D0ͨ\B5\C0\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateChannel(HI_U32 u32DmxId, const HI_UNF_DMX_CHAN_ATTR_S *pstChAttr,
            HI_HANDLE *phChannel);

/**
\brief Creates or reuse a channel based on PID.CNcomment:\B8\F9\BE\DDPID \B4\B4\BD\A8\BB\F2\B8\B4\D3\C3һ\B8\F6ͨ\B5\C0\A1\A3CNend
\attention \n
It is recommended to call HI_UNF_DMX_GetChannelDefaultAttr to query default channel attributes before calling HI_UNF_DMX_CreateChannel.
For the Section channel and ECM/EMM channel, you can set the CRC mode, and dynamically change the CRC mode by calling HI_UNF_DMX_SetChannelAttr.\n
For other channels, the CRC check is always disabled. If you select other CRC modes, the CRC disable mode takes effect by default.\n
You need to set the buffer size when creating a channel. The buffer size is in the unit of byte and the default size is 16 KB.\n
It is recommended to set the buffer size to a value greater than 4 KB for the Section channel, ECM/EMM channel, or post channel. If the buffer size is smaller than 4 KB, the size of 4 KB is used by default.\n
It is recommended to set the buffer size to a value greater than 64 KB for the PES channel. If the buffer size is smaller than 64 KB, the size of 64 KB is used by default.\n
The playing channel and playing/recording channel cannot be created at the same time./n
The audio/video playing channels are allocated and managed by the player.
CNcomment:\BD\A8\D2\E9\B5\F7\D3ô˽ӿ\DA֮ǰ\A3\AC\BD\A8\D2\E9\CFȵ\F7\D3\C3HI_UNF_DMX_GetChannelDefaultAttr\BB\F1ȡͨ\B5\C0Ĭ\C8\CF\CA\F4\D0\D4\n
+\D3\D0section\C0\E0\D0͵\C4ͨ\B5\C0\BA\CDecm emm\C0\E0\D0͵\C4ͨ\B5\C0֧\B3\D6\C9\E8\D6\C3CRCģʽ\A3\AC\B2\A2\C7ҿ\C9\D2\D4ͨ\B9\FD\CA\F4\D0\D4\C9\E8\D6ýӿڶ\AF̬\D0޸\C4CRCģʽ\n
\C6\E4\CB\FB\C0\E0\D0\CDͨ\B5\C0ֻ֧\B3\D6\C9\E8\D6\C3ΪCRC\BD\FBֹ\A3\AC\C8\E7\B9\FBѡ\D4\F1\C1\CB\C6\E4\CB\FB\C0\E0\D0͵\C4CRC\BBᱻĬ\C8\CF\D0޸\C4ΪCRC\BD\FBֹ\n
\D4\DA\C9\EA\C7\EBͨ\B5\C0ʱע\D2\E2Buffer\B4\F3С\B5\C4\C5\E4\D6ã\ACĬ\C8ϴ\F3СΪ16K\A3\ACbuffer\B4\F3С\B5ĵ\A5λΪ\D7ֽ\DA\n
Section\A1\A2ecm emm\BA\CDPOSTͨ\B5\C0\B5\C4buffer\B4\F3С\D6\C1\C9\D9Ϊ4K\A3\AC\C8\E7\B9\FBС\D3\DA4K\BBᱻĬ\C8\CF\D0޸\C4Ϊ4K\n
PESͨ\B5\C0\BD\A8\D2\E9ʹ\D3\C364K\D2\D4\C9ϵ\C4buffer\B4\F3С\A3\AC\C8\E7\B9\FBС\D3\DA64K\BBᱻĬ\C8\CF\D0޸\C4Ϊ64K\n
\B2\A5\B7\C5\C0\E0\D0ͺ\CDͬʱ\B2\A5\B7\C5\D3\EB¼\D6\C6\C0\E0\D0͵\C4\D2\F4\CA\D3Ƶͨ\B5\C0\CAǲ\BB\C4\DC\C9\EA\C7\EB\B5\C4\n
\D2\F4\CA\D3Ƶ\B5Ĳ\A5\B7\C5ͨ\B5\C0\D3\C9Playerͳһ\B7\D6\C5\E4\BA͹\DC\C0\ED\A1\A3CNend
\param[in] u32DmxId  DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[in] u32Pid  PID. CNcomment: PID ֵ\A1\A3CNend
\param[in] pstChAttr  Pointer to the attributes of an input channel. For details, see the description of HI_UNF_DMX_CHAN_ATTR_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EBͨ\B5\C0\CA\F4\D0ԡ\A3\C7\EB\B2μ\FB::HI_UNF_DMX_CHAN_ATTR_S\A1\A3CNend
\param[out] phChannel  Pointer to the handle of an allocated channel.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B7\D6\C5\E4\B5\C4ͨ\B5\C0Handle\A1\A3\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_CHAN  There is no available channel.CNcomment:û\D3п\D5\CF\D0ͨ\B5\C0\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateChannelWithPID(HI_U32 u32DmxId, HI_U32 u32Pid, const HI_UNF_DMX_CHAN_ATTR_S *pstChAttr, HI_HANDLE *phChannel);

/**
\brief Destroys an existing PID channel.CNcomment:\CF\FA\BBٴ\B4\BD\A8\B5\C4PIDͨ\B5\C0\A1\A3CNend
\attention \n
If you release an enabled channel, the channel is disabled automatically. If you release a channel that is attached to a filter or key area, the channel is detached from the filter or key area automatically.\n
However, the filter or key area is not released.\n
It is recommended to explicitly detach channels by calling corresponding detach APIs. In this way, resources are managed in a unified manner.
CNcomment:\CAͷ\C5ͨ\B5\C0ʱ\C8\E7\B9\FBͨ\B5\C0\B4\A6\D3ڴ\F2\BF\AA״̬\BB\E1\D7Զ\AF\B9ر\D5ͨ\B5\C0\A3\AC\C8\E7\B9\FBͨ\B5\C0\C9ϰ\F3\B6\A8\C1˹\FD\C2\CB\C6\F7\BB\F2\C3\DCԿ\C7\F8\A3\AC\BB\E1\D7Զ\AF\BD\E2\B0\F3\B6\A8\n
\B5\AB\CAǲ\A2\B2\BB\BB\E1\CAͷŹ\FD\C2\CB\C6\F7\BA\CD\C3\DCԿ\C7\F8
\BD\A8\D2\E9ʹ\D3ý\E2\B0󶨽ӿڽ\F8\D0\D0\CF\D4ʽ\B5Ľ\E2\B0󶨲\D9\D7\F7\A3\AC\B6\D4\D7\CAԴ\B5\C4ʹ\D3ý\F8\D0\D0\C7\E5\CE\FA\B5Ĺ\DC\C0\ED\A1\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DestroyChannel(HI_HANDLE hChannel);


/**
\brief Obtains the attributes of a channel.CNcomment:\BB\F1ȡͨ\B5\C0\CA\F4\D0ԡ\A3CNend
\attention \n
The API can be called only after a channel is allocated.CNcomment:\B1\BE\BDӿڱ\D8\D0\EB\D4\DAͨ\B5\C0\B7\D6\C5\E4\D2Ժ\F3\B2ſ\C9\D2Ե\F7\D3á\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0Handle\A1\A3CNend
\param[out] pstChAttr  Pointer to the attributes of a specified channel. For details, see the description of HI_UNF_DMX_CHAN_ATTR_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ָ\B6\A8ͨ\B5\C0\CA\F4\D0ԡ\A3\C7\EB\B2μ\FB::HI_UNF_DMX_CHAN_ATTR_S\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelAttr(HI_HANDLE hChannel, HI_UNF_DMX_CHAN_ATTR_S *pstChAttr);


/**
\brief Sets the attributes of a channel.CNcomment:\C9\E8\D6\C3ͨ\B5\C0\CA\F4\D0ԡ\A3CNend
\attention \n
The API can be called only after a channel is allocated.\n
You cannot dynamically modify all attributes except the CRC mode by calling HI_UNF_DMX_SetChannelAttr.\n
To be specific, the CRC mode can be changed dynamically after a channel is created.\n
If you modify other attributes, the error code HI_ERR_DMX_INVALID_PARA is returned.
CNcomment:\B1\BE\BDӿڱ\D8\D0\EB\D4\DAͨ\B5\C0\B7\D6\C5\E4\D2Ժ\F3\B2ſ\C9\D2Ե\F7\D3\C3\n
\B3\FD\C1\CBCRCģʽ\C6\E4\CB\FB\CA\F4\D0Զ\BC\B2\BB\D4\CA\D0\EDʹ\D3\C3HI_UNF_DMX_SetChannelAttr\BDӿڽ\F8\D0ж\AF̬\D0޸\C4\n
CRCģʽ\BF\C9\D2\D4\D4\DAͨ\B5\C0\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CC\D0޸ģ\AC\B6\AF̬\C9\FAЧ\n
Ҫ\D0޸\C4\C6\E4\CB\FB\CA\F4\D0Ի᷵\BBز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2롣CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] pstChAttr    Pointer to the attributes of an input channel. For details, see the description of HI_UNF_DMX_CHAN_ATTR_S.  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EBͨ\B5\C0\CA\F4\D0ԡ\A3\C7\EB\B2μ\FB ::HI_UNF_DMX_CHAN_ATTR_S\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetChannelAttr(HI_HANDLE hChannel, const HI_UNF_DMX_CHAN_ATTR_S *pstChAttr);


/**
\brief Sets the PID of a channel.CNcomment:\C9\E8\D6\C3ͨ\B5\C0PID\A1\A3CNend
\attention \n
If you set the same PID for two channels of a DEMUX, the PID of the second channel is valid, and the PID of the first channel is changed to 0x1FFF.\n
You must set the PID of a channel after the channel is disabled.\n
If you set the PID of a channel to 0x1FFF, the channel cannot receive data. That is, the channel is disabled.
CNcomment:ͬһ·DEMUX\B5\C4\C1\BD\B8\F6ͨ\B5\C0\C9\E8\D6\C3\CF\E0ͬ\B5\C4PID\A1\A3\BA\F3\C9\E8\D6õ\C4ͨ\B5\C0\D3\D0Ч\A3\AC\CF\C8\C9\E8\D6õ\C4ͨ\B5\C0\B5\C4PID\B1\BB\D0޸\C4Ϊ0x1fff\n
\B1\D8\D0\EB\D4\DAͨ\B5\C0\B9رյ\C4״̬\CF\C2\C5\E4\D6\C3ͨ\B5\C0\B5\C4PID\n
\D4\CA\D0\ED\BD\ABͨ\B5\C0\B5\C4PID\C5\E4\D6\C3Ϊ0x1fff,\C5\E4\D6\C3Ϊ0x1fff\BA󲻽\D3\CA\D5\C8κ\CE\CA\FD\BEݣ\AC\CF൱\D3ڹر\D5ͨ\B5\C0\A1\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] u32Pid     Channel PID.CNcomment:ͨ\B5\C0PID\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_OPENING_CHAN  The channel is enabled.CNcomment:ͨ\B5\C0\B4\A6\D3ڴ\F2\BF\AA״̬\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetChannelPID(HI_HANDLE hChannel, HI_U32 u32Pid);


/**
\brief Obtains the PID of a channel.CNcomment:\BB\F1ȡͨ\B5\C0\C5\E4\D6õ\C4PID\A1\A3CNend
\attention \n
If no PID is set for a channel, the obtained value is 0x1FFF.\n
You can obtain the channel PID after a channel is created.
CNcomment:û\D3\D0\C5\E4\D6\C3PIDǰ\A3\AC\BB\F1ȡ\B5\BD\B5\C4PIDΪ0x1fff\n
\BF\C9\D2\D4\D4\DAͨ\B5\C0\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF̻\F1ȡͨ\B5\C0PID\A1\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] pu32Pid   Pointer to the PID of a channel (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0\B5\C4PID\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelPID(HI_HANDLE hChannel, HI_U32 *pu32Pid);


/**
\brief Enables a channel.CNcomment:\B4\F2\BF\AAͨ\B5\C0\A1\A3CNend
\attention \n
If you call this API to enable a PID channel that has been enabled, no error occurs.\n
If you call this API to enable a Section channel that is not attached to a filter, the channel cannot receive data.\n
If you want to receive data without filter, you can create a filter and then set its filter depth to 0.
CNcomment:\D4\DAPIDͨ\B5\C0\B4\F2\BF\AA״̬\CF£\AC\B5\F7\D3ñ\BE\BDӿڴ\F2\BF\AAͨ\B5\C0\B2\BB\BBᷢ\C9\FA\B4\ED\CE\F3\n
\B6\D4\D3\DAsectionͨ\B5\C0\A3\AC\D4\DAͨ\B5\C0û\D3а󶨹\FD\C2\CB\C6\F7ʱ\B5\F7\D3ñ\BE\BDӿڣ\ACͨ\B5\C0\B2\BB\C4ܽ\D3\CA\D5\CA\FD\BE\DD\n
\C8\E7\B9\FB\B2\BB\CF\EBʹ\D3\C3filter\BD\D3\CA\D5\CA\FD\BEݣ\AC\BF\C9\D2\D4\C9\EA\C7\EBһ\B8\F6filter\BD\AB\B9\FD\C2\CB\C9\EE\B6\C8\C5\E4\D6\C3Ϊ0\A3\AC\BD\F8\D0\D0\CA\FD\BEݽ\D3\CAա\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_OpenChannel(HI_HANDLE hChannel);


/**
\brief Disables a channel.CNcomment:\B9ر\D5ͨ\B5\C0\A1\A3CNend
\attention \n
If you this API to disable a PID channel that has been disabled, no error occurs.CNcomment:\D4\DAPIDͨ\B5\C0\B9ر\D5״̬\CF£\AC\B5\F7\D3ñ\BE\BDӿڹر\D5ͨ\B5\C0\B2\BB\BBᷢ\C9\FA\B4\ED\CE\F3\A1\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CloseChannel(HI_HANDLE hChannel);


/**
\brief Obtains the status of a channel.CNcomment:\BB\F1ȡͨ\B5\C0״̬\A1\A3CNend
\attention \n
You can call this API after a channel is created.CNcomment:\BF\C9\D2\D4\D4\DAͨ\B5\C0\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF̵\F7\D3á\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] pstStatus  Pointer to the status of a channel (output). For details, see the description of ::HI_UNF_DMX_CHAN_STATUS_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0״̬\A1\A3\C7\EB\B2μ\FB::HI_UNF_DMX_CHAN_STATUS_S\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelStatus(HI_HANDLE hChannel, HI_UNF_DMX_CHAN_STATUS_S *pstStatus);

/**
\brief Obtains the ts count of a channel.CNcomment:\BB\F1ȡͨ\B5\C0ts\B0\FC\BC\C6\CA\FD\A1\A3CNend
\attention \n
You can call this API after a channel is created.CNcomment:\BF\C9\D2\D4\D4\DAͨ\B5\C0\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF̵\F7\D3á\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] pu32TsCount  Pointer to the count of a channel (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0ts\B0\FC\BC\C6\CA\FD\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
 */
HI_S32 HI_UNF_DMX_GetChannelTsCount(HI_HANDLE hChannel, HI_U32 *pu32TsCount);



/**
\brief Obtains the handle of the channel with a specific PID.CNcomment:\BB\F1ȡ\C5\E4\D6\C3ĳPID\B5\C4ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\attention \n
You must specify the DEMUX ID when calling this API, because the channel PIDs of different DEMUXs can be the same.\n
You cannot query the PID that is equal to or greater than 0x1FFF; otherwise, the error code HI_ERR_DMX_INVALID_PARA is returned.\n
If no channel with a specific PID is found, an error code is returned.
CNcomment:\D2\F2\B2\BBͬDEMUX\C9豸\B5\C4ͨ\B5\C0\D4\CA\D0\ED\C9\E8\D6\C3\CF\E0ͬ\B5\C4PID\A3\AC\B5\F7\D3ñ\BE\BDӿ\DA\D0\E8Ҫָ\B6\A8DEMUX ID\n
\B2\BB\D4\CA\D0\ED\B2\E9ѯ0x1fff\BC\B0\D2\D4\C9ϵķǷ\A8PIDֵ\A3\AC\B7\F1\D4򷵻ز\CE\CA\FD\B7Ƿ\A8\B4\ED\CE\F3\C2\EB\n
\C8\E7\B9\FBû\D3в\E9ѯ\B5\BD\C8κ\CEͨ\B5\C0\C9\E8\D6\C3\C1\CBҪ\B2\E9ѯ\B5\C4PID\A3\AC\BD\AB\B7\B5\BBش\ED\CE\F3\C2롣CNend
\param[in] u32DmxId    DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[in] u32Pid      Channel PID.CNcomment:ͨ\B5\C0PID\A1\A3CNend
\param[out] phChannel Pointer to channel handle.CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_UNMATCH_CHAN  No matched channel is found.CNcomment:û\D3в\E9ѯ\B5\BDƥ\C5\E4ͨ\B5\C0\A1\A3CNend
\retval ::HI_ERR_DMX_OCCUPIED_PID  The same pid was found on multiple channels.CNcomment:\D4ڶ\E0\B8\F6ͨ\B5\C0\C9Ϸ\A2\CF\D6\C1\CB\CF\E0ͬ\B5\C4PID\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetChannelHandle(HI_U32 u32DmxId , HI_U32 u32Pid, HI_HANDLE *phChannel);


/**
\brief Obtains the number of available channels of a DEMUX.CNcomment:\BB\F1ȡDEMUX\C9豸\BF\C9\D3õĿ\D5\CF\D0ͨ\B5\C0\B5\C4\CA\FD\C1\BF\A1\A3CNend
\attention \n
The returned number is the number of all remaining channels including the used audio/video channels.\n
Because channels are allocated in a unified manner, the parameter u32DmxId is invalid.
CNcomment:\B7\B5\BBص\C4\CA\FD\C1\BFΪ\CB\F9\D3\D0ͨ\B5\C0ʣ\D3\E0\B5\C4\CA\FD\C1\BF\A3\AC\B0\FC\C0\A8\D2ѱ\BBʹ\D3õ\C4\D2\F4\CA\D3Ƶͨ\B5\C0\n
\D3\C9\D3\DAͨ\B5\C0\D7\CAԴͳһ\B7\D6\C5\E4\CB\F9\D2Բ\CE\CA\FDu32DmxId\D2Ѿ\ADû\D3\D0\D2\E2\D2塣CNend
\param[in] u32DmxId         DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[out] pu32FreeCount   Pointer to the number of available channels of a DEMUX.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6DEMUX\BF\D5\CF\D0ͨ\B5\C0\CA\FDĿ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetFreeChannelCount (HI_U32 u32DmxId, HI_U32 *pu32FreeCount);


/**
\brief Obtains the scrambled flag of the channel data.CNcomment:\BB\F1ȡͨ\B5\C0\CA\FD\BEݼ\D3\C8ű\EA־\A1\A3CNend
\attention \n
You can query the scrambled PES data and ES data.CNcomment:֧\B3\D6PES\BC\B6\BC\D3\C8ź\CDTS\BC\B6\BC\D3\C8ŵĲ\E9ѯ\A1\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] penScrambleFlag   Pointer to the scrambled flag of the channel data (output). For details, see the description of ::HI_UNF_DMX_SCRAMBLED_FLAG_E.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0\CA\FD\BEݼ\D3\C8ű\EA־\A1\A3\C7\EB\B2μ\FB::HI_UNF_DMX_SCRAMBLED_FLAG_E\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetScrambledFlag(HI_HANDLE hChannel, HI_UNF_DMX_SCRAMBLED_FLAG_E *penScrambleFlag);

/**
\brief Creates a data filter.CNcomment:\B4\B4\BD\A8һ\B8\F6\CA\FD\BEݹ\FD\C2\CB\C6\F7\A1\A3CNend
\attention \n
The maximum depth of a filter is 16 bytes.\n
For details on how to set the attributes of a filter, see the description of ::HI_UNF_DMX_FILTER_ATTR_S.\n
You can set a filter when creating it. If you do not want to filter data, you can set the filter depth to 0.\n
To modify the attributes of a filter, call HI_UNF_DMX_SetFilterAttr.\n
The attributes can be modified dynamically.\n
If a filter is used to filter the Section data, the valid byte is byte 1 and byte 4 to byte 18.\n
If a filter is used to filter the PES data, the valid byte is byte 4 and byte 7 to byte 21.\n
The filter can be used to filter the data of general-purpose channels only, including the Section channel, ECM/EMM channel, and PES channel.\n
If a filter is allocated successfully, phFilter returns the handle of the created filter.
CNcomment:\B9\FD\C2\CB\C6\F7\C9\EE\B6\C8\D7\EE\B4\F3Ϊ16\n
\B9\FD\C2\CB\C6\F7\CA\F4\D0\D4\C5\E4\D6\C3\C7\EB\B2ο\BC::HI_UNF_DMX_FILTER_ATTR_S\n
\B4\B4\BD\A8\B9\FD\C2\CB\C6\F7ʱ\A3\ACͬʱʵ\CFֶԹ\FD\C2\CB\C6\F7\B5\C4\C9\E8\D6ã\BB\C8\F4\B2\BB\D0\E8Ҫ\CA\FD\BEݹ\FD\C2ˣ\AC\C9\E8\D6ù\FD\C2\CB\C6\F7\C9\EE\B6\C8Ϊ0\BC\B4\BF\C9\n
\C8\F4\D0\E8Ҫ\D0޸Ĺ\FD\C2\CB\C6\F7\CA\F4\D0ԣ\AC\BFɵ\F7\D3\C3HI_UNF_DMX_SetFilterAttr\BD\F8\D0\D0\CA\F4\D0\D4\D0޸\C4\n
+\B3\D6\CA\F4\D0ԵĶ\AF̬\D0޸\C4\n
\B9\FD\C2\CB\C6\F7\D3\C3\D3ڹ\FD\C2\CBSection\CA\FD\BE\DDʱ\A3\AC\D3\D0Ч\B9\FD\C2\CB\D7ֽ\DAΪ\B5\DA1\D7ֽڼ\B0\B5\DA4\D7ֽڡ\AB\B5\DA18\D7ֽ\DA\n
\B9\FD\C2\CB\C6\F7\D3\C3\D3ڹ\FD\C2\CBPES\CA\FD\BE\DDʱ\A3\AC\D3\D0Ч\B9\FD\C2\CB\D7ֽ\DAΪ\B5\DA4\D7ֽڼ\B0\B5\DA7\D7ֽڡ\AB\B5\DA21\D7ֽ\DA\n
\B9\FD\C2\CB\C6\F7ֻ\CA\CA\D3\C3\D3\DAͨ\D3\C3ͨ\B5\C0\B5\C4\CA\FD\BEݹ\FD\C2ˣ\AC\B0\FC\C0\A8sectionͨ\B5\C0\A1\A2ECM/EMMͨ\B5\C0\BA\CDPESͨ\B5\C0\n
\C8\F4\B7\D6\C5\E4\B3ɹ\A6\A3\ACphFilter\B7\B5\BBػ\F1ȡ\B5Ĺ\FD\C2\CB\C6\F7Handle\A1\A3CNend
\param[in] u32DmxId    DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[in] pstFilterAttr   Pointer to the attributes of a filter (input).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EB\B9\FD\C2\CB\C6\F7\CA\F4\D0ԡ\A3CNend
\param[out] phFilter   Pointer to the handle of the created filter (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\C9\EA\C7\EB\B5Ĺ\FD\C2\CB\C6\F7Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_FILTER There is no available filter.CNcomment:û\D3п\D5\CF\D0filter\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateFilter(HI_U32 u32DmxId, const HI_UNF_DMX_FILTER_ATTR_S  *pstFilterAttr,
            HI_HANDLE *phFilter);


/**
\brief Destroys an existing data filter.CNcomment:\CF\FA\BBٴ\B4\BD\A8\B5\C4\CA\FD\BEݹ\FD\C2\CB\C6\F7\A1\A3CNend
\attention \n
If a filter is attached to a general-purpose channel, you can call this API to release the filter when the channel is enabled or disabled.\n
If no filter is attached to a Section channel, the channel cannot receive data. This restriction is not applicable to other channels.
CNcomment:\C8\F4\B9\FD\C2\CB\C6\F7\BA\CDͨ\D3\C3ͨ\B5\C0\B0󶨣\AC\D4\CA\D0\ED\D4\DAͨ\B5\C0\B4򿪻\F2\D5߹ر\D5״̬\CF£\AC\B5\F7\D3ñ\BE\BDӿ\DA\CAͷŹ\FD\C2\CB\C6\F7\n
\B6\D4\D3\DAsectionͨ\B5\C0\B5\B1ͨ\B5\C0\C9\CFû\D3\D0\C8κι\FD\C2\CB\C6\F7\B0\F3\B6\A8ʱ\A3\AC\D4\F2\B2\BB\D4ٽ\D3\CA\D5\CA\FD\BEݣ\AC\C6\E4\CB\FBͨ\B5\C0û\D3д\CB\CF\DE\D6ơ\A3CNend
\param[in] hFilter  Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DestroyFilter(HI_HANDLE hFilter);


/**
\brief Releases all the filters attached to a channel.CNcomment:\CAͷŰ\F3\B6\A8\D4\DAĳ\B8\F6ͨ\B5\C0\C9ϵ\C4\CB\F9\D3й\FD\C2\CB\C6\F7\A1\A3CNend
\attention \n
You can call this API to release all filters attached to a channel when the channel is enabled or disabled.CNcomment:\D4\CA\D0\ED\D4\DAͨ\B5\C0\B4򿪻\F2\D5߹ر\D5״̬\CF£\AC\B5\F7\D3ñ\BE\BDӿ\DA\CAͷ\C5ͨ\B5\C0\C9ϰ󶨵\C4\CB\F9\D3й\FD\C2\CB\C6\F7\A1\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is valid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DeleteAllFilter(HI_HANDLE hChannel);


/**
\brief Sets the filter criteria of a filter.CNcomment:\C9\E8\D6ù\FD\C2\CB\C6\F7\B5Ĺ\FD\C2\CB\CC\F5\BC\FE\A1\A3CNend
\attention \n
The maximum filter depth u32FilterDepth is 16.\n
For details on how to set the attributes of a filter, see the description of ::HI_UNF_DMX_FILTER_ATTR_S.\n
If a filter is used to filter the Section data, the valid byte is byte 1 and byte 4 to byte 18.\n
If a filter is used to filter the PES data, the valid byte is byte 4 and byte 7 to byte 21.\n
The attributes can be modified dynamically.
CNcomment:\B9\FD\C2\CB\C6\F7\B5\C4\C9\EE\B6\C8\CA\F4\D0\D4u32FilterDepth\D7\EE\B4\F3Ϊ16\n
\B9\FD\C2\CB\C6\F7\CA\F4\D0\D4\C5\E4\D6\C3\C7\EB\B2ο\BC::HI_UNF_DMX_FILTER_ATTR_S\n
\B9\FD\C2\CB\C6\F7\D3\C3\D3ڹ\FD\C2\CBSection\CA\FD\BE\DDʱ\A3\AC\D3\D0Ч\B9\FD\C2\CB\D7ֽ\DAΪ\B5\DA1\D7ֽڼ\B0\B5\DA4\D7ֽڡ\AB\B5\DA18\D7ֽ\DA\n
\B9\FD\C2\CB\C6\F7\D3\C3\D3ڹ\FD\C2\CBPES\CA\FD\BE\DDʱ\A3\AC\D3\D0Ч\B9\FD\C2\CB\D7ֽ\DAΪ\B5\DA4\D7ֽڼ\B0\B5\DA7\D7ֽڡ\AB\B5\DA21\D7ֽ\DA\n
+\B3\D6\CA\F4\D0ԵĶ\AF̬\D0޸ġ\A3CNend
\param[in] hFilter   Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\param[in] pstFilterAttr   Pointer to the attributes of a filter (input).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\C8\EB\B9\FD\C2\CB\C6\F7\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_ATTACHED_FILTER  The attributes cannot be set dynamically, because the filter is attached to a channel.CNcomment:\B9\FD\C2\CB\C6\F7\B0\F3\B6\A8\D4\DAͨ\B5\C0\C9ϣ\AC\B2\BB\C4ܶ\AF̬\C9\E8\D6á\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetFilterAttr(HI_HANDLE hFilter, const HI_UNF_DMX_FILTER_ATTR_S *pstFilterAttr);


/**
\brief Obtains the filter criteria of a filter.CNcomment:\BB\F1ȡ\B9\FD\C2\CB\C6\F7\B5Ĺ\FD\C2\CB\CC\F5\BC\FE\A1\A3CNend
\attention \n
If you call the API before a filter is allocated, an error code is returned.
CNcomment:\D4ڹ\FD\C2\CB\C6\F7δ\B7\D6\C5\E4ʱ\B5\F7\D3øýӿڣ\AC\B7\B5\BBش\ED\CE\F3\A1\A3CNend
\param[in] hFilter   Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\param[out] pstFilterAttr   Pointer to the attributes of a filter (output). For details, see the description of ::HI_UNF_DMX_FILTER_ATTR_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B9\FD\C2\CB\C6\F7\CA\F4\D0ԡ\A3\C7\EB\B2μ\FB::HI_UNF_DMX_FILTER_ATTR_S\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetFilterAttr(HI_HANDLE hFilter, HI_UNF_DMX_FILTER_ATTR_S *pstFilterAttr);


/**
\brief  Attaches filters to a specific channel.CNcomment:\B0󶨹\FD\C2\CB\C6\F7\B5\BDָ\B6\A8\B5\C4ͨ\B5\C0\A1\A3CNend
\attention \n
One or more filters can be attached to a general-purpose channel. All filters are ORed.\n
That is, if the data meets the filter criteria of a filter, the data is transmitted to the DMA buffer.\n
Filters cannot be attached to the audio/video channel and post channel.\n
If a filter is used, it cannot be attached to one or more channels repeatedly.\n
If a filter and a channel do not belong to the same DEMUX, the filter cannot be detached from the channel.\n
A filter can be attached to a general-purpose channel when the channel is enabled or disabled.
CNcomment:һ\B8\F6ͨ\D3\C3ͨ\B5\C0\BF\C9\D2԰\F3\B6\A8һ\B8\F6\BB\F2\D5߶\E0\B8\F6\CA\FD\BEݹ\FD\C2\CB\C6\F7\A3\AC\CB\F9\D3й\FD\C2\CB\C6\F7֮\BC\E4\B5Ĺ\FD\C2˹\D8ϵ\CAǻ\F2\A1\A3\n
\BC\B4ֻҪ\C2\FA\D7\E3\C6\E4\D6\D0\C8κ\CEһ\B8\F6\B9\FD\C2\CB\C6\F7\B5Ĺ\FD\C2\CB\CC\F5\BC\FE\A3\AC\B5\B1ǰ\B9\FD\C2˵\C4\CA\FD\BEݶ\BC\BD\ABͨ\B9\FD\B9\FD\C2˶\F8\B1\BB\CB\CD\C8\EBDMA\BB\BA\B3\E5\C7\F8\n
\B2\BB֧\B3\D6\D2\F4\CA\D3Ƶͨ\B5\C0\BA\CDPOSTͨ\B5\C0\B5Ĺ\FD\C2\CB\C6\F7\B0\F3\B6\A8\n
\B2\BB\C4ܽ\ABһ\B8\F6\B9\FD\C2\CB\C6\F7\D6ظ\B4\B0󶨵\BDһ\B8\F6\BB\F2\B6\E0\B8\F6ͨ\B5\C0\C9\CF\n
\B9\FD\C2\CB\C6\F7\D3\EBͨ\B5\C0\B2\BB\CA\F4\D3\DAͬһ·DEMUXʱ\A3\AC\B2\BB\C4ܽ\F8\D0а󶨲\D9\D7\F7\n
+\B3\D6ͨ\D3\C3ͨ\B5\C0\B4򿪻\F2\D5߹ر\D5״̬\CFµĹ\FD\C2\CB\C6\F7\B0󶨡\A3CNend
\param[in] hFilter  Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_ATTACHED_FILTER  The filter is attached.CNcomment:\B9\FD\C2\CB\C6\F7\D2Ѿ\AD\B4\A6\D3ڰ\F3\B6\A8״̬\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT   No filter can be attached to the channel.CNcomment:\B4\CB\C0\E0\D0\CDͨ\B5\C0\B2\BB֧\B3ְ󶨹\FD\C2\CB\C6\F7\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_AttachFilter(HI_HANDLE hFilter, HI_HANDLE hChannel);



/**
\brief Detaches a filter from a specific channel.CNcomment:\BD\AB\B9\FD\C2\CB\C6\F7\B4\D3ָ\B6\A8ͨ\B5\C0\C9Ͻ\E2\B0󶨡\A3CNend
\attention \n
If no filter is attached to a channel, the error code HI_FAILURE is returned when you call this API.\n
If a filter and a channel do not belong to the same DEMUX, an error code is returned.\n
A filter can be detached from a general-purpose channel when the channel is enabled or disabled.
CNcomment:ͨ\B5\C0\C9\CFû\D3а󶨹\FD\C2\CB\C6\F7\BD\F8\D0н\E2\B0󶨷\B5\BB\D8ʧ\B0\DC\n
\B9\FD\C2\CB\C6\F7\D3\EBͨ\B5\C0\B2\BB\CA\F4\D3\DAͬһ·DEMUXά\BB\A4ʱ\A3\AC\B7\B5\BBش\ED\CE\F3\n
+\B3\D6ͨ\D3\C3ͨ\B5\C0\B4򿪻\F2\D5߹ر\D5״̬\CFµĹ\FD\C2\CB\C6\F7\BD\E2\B0󶨡\A3CNend
\param[in] hFilter   Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NOATTACH_FILTER  No filter is attached to any channel.CNcomment:filterû\D3а\F3\B6\A8\D4\DA\C8κ\CEͨ\B5\C0\C9ϡ\A3CNend
\retval ::HI_ERR_DMX_UNMATCH_FILTER  No filter is attached to the channel.CNcomment:filterû\D3а\F3\B6\A8\D4ڴ\CBͨ\B5\C0\C9ϡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DetachFilter(HI_HANDLE hFilter, HI_HANDLE hChannel);


/**
\brief Obtains the handle of the channel to which a filter is attached.CNcomment:\BB\F1ȡ\B9\FD\C2\CB\C6\F7\CB\F9\B0󶨵\C4ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\attention \n
Each filter corresponds to a channel. If a filter is not attached to a channel, the error code HI_ERR_DMX_NOATTACH_FILTER is returned.CNcomment:ÿ\B8\F6\B9\FD\C2\CB\C6\F7Ψһ\B6\D4Ӧһ\B8\F6ͨ\B5\C0\A1\A3\C8\F4\B9\FD\C2\CB\C6\F7û\D3а\F3\B6\A8\C8κε\BDͨ\B5\C0\C9ϣ\AC\D4򷵻\D8HI_ERR_DMX_NOATTACH_FILTER\B4\ED\CE\F3\C2롣CNend
\param[in] hFilter    Filter handle.CNcomment:\B9\FD\C2\CB\C6\F7\BE\E4\B1\FA\A1\A3CNend
\param[out] phChannel   Pointer to the handle of the channel to which a filter is attached (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B9\FD\C2\CB\C6\F7\B0󶨵\C4ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOATTACH_FILTER  No filter is attached to any channel.CNcomment:filterû\D3а\F3\B6\A8\D4\DA\C8κ\CEͨ\B5\C0\C9ϡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetFilterChannelHandle(HI_HANDLE hFilter, HI_HANDLE *phChannel);


/**
\brief Obtains the number of available filters of a DEMUX.CNcomment:\BB\F1ȡDEMUX\C9豸\BF\C9\D3õĿ\D5\CFй\FD\C2\CB\C6\F7\CA\FD\C1\BF\A1\A3CNend
\attention \n
The number of unallocated filters is returned. The filters that are allocated but not attached to channels are excluded.
CNcomment:\B7\B5\BBص\B1ǰδ\B7\D6\C5\E4\B5Ĺ\FD\C2\CB\C6\F7\CA\FDĿ\A3\AC\D2ѷ\D6\C5䵫δ\B0󶨵\BDͨ\B5\C0\C9ϵĹ\FD\C2\CB\C6\F7\B2\BBͳ\BCơ\A3CNend
\param[in] u32DmxId   DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[out]  pu32FreeCount  Pointer to the number of allocated filters (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\B5\B1ǰδ\B7\D6\C5\E4\B5Ĺ\FD\C2\CB\C6\F7\CA\FDĿ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetFreeFilterCount(HI_U32 u32DmxId ,  HI_U32 * pu32FreeCount);


/**
\brief Obtains the handles of all channels that receive new data.CNcomment:\BB\F1ȡ\D3\D0\D0\C2\CA\FD\BEݵ\BD\B4\EF\B5\C4\CB\F9\D3\D0ͨ\B5\C0\B5ľ\E4\B1\FA\A1\A3CNend
\attention \n
When you call this API, the parameter pu32ChNum serves as the input parameter and is used to specify the data length pointed by phChannel. pu32ChNum indicates the number of channels to be queried.\n
The number of channels must be initialized, and the initial value cannot be 0.\n
It is recommended to set the number of channels to the total number. For details about the total number of channels.\n
After you call this API successfully, the parameter pu32ChNum serves as the output parameter and is used to specify the valid data length pointed by phChannel.\n
The block time is configurable (in ms). If u32TimeOutMs is set to 0, it indicates that the block time is 0; if u32TimeOutMs is set to 0xFFFFFFFF, it indicates infinite wait.\n
If no data is received when the block time is exceeded, the error code HI_ERR_DMX_TIMEOUT is returned.\n
If the wait time is 0, and no data is received in any channel, ::HI_ERR_DMX_NOAVAILABLE_DATA is returned.
CNcomment:\B5\F7\D3øýӿ\DAʱ\A3\ACpu32ChNum\D7\F7Ϊ\CA\E4\C8\EB\B2\CE\CA\FD\A3\AC\D3\C3\D3\DAָ\B6\A8phChannelָ\CF\F2\CA\FD\D7\E9\B5ĳ\A4\B6ȣ\AC\B1\EDʾҪ\B2\E9ѯ\B5\C4ͨ\B5\C0\B8\F6\CA\FD\A3\BB\n
+\B5\C0\B8\F6\CA\FD\B1\D8\D0\EB\B3\F5ʼ\BB\AF\A3\AC\C7ҳ\F5ʼֵ\B1\D8\D0\EBΪ\B7\C70ֵ\n
\BD\A8\D2齫ͨ\B5\C0\B8\F6\CA\FD\C9\E8\D6\C3Ϊͨ\B5\C0\B5\C4\D7ܸ\F6\CA\FD\n
\B5\B1\B8ýӿڵ\F7\D3óɹ\A6ʱ\A3\ACpu32ChNum\D7\F7Ϊ\CA\E4\B3\F6\B2\CE\CA\FD\A3\ACָ\B6\A8phChannelָ\CF\F2\CA\FD\D7\E9\B5\C4\D3\D0Ч\B3\A4\B6\C8\n
\D7\E8\C8\FBʱ\BC\E4\BF\C9\D2\D4\C9\E8\D6ã\ACʱ\BC䵥λΪ\BA\C1\C3룬\C9\E8\D6\C3Ϊ0\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffffһֱ\B5ȴ\FD\A1\A3\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\CB\F9\D3\D0ͨ\B5\C0\B6\BCû\D3\D0\CA\FD\BEݵ\BD\B4\D4򷵻صȴ\FD\B3\ACʱ\B4\ED\CE\F3\n
\C8\E7\B9\FB\B5ȴ\FDʱ\BC\E4Ϊ0\A3\AC\B6\F8\C7\D2û\D3\D0\C8κ\CEͨ\B5\C0\D3\D0\CA\FD\BE\DD\D4򷵻\D8::HI_ERR_DMX_NOAVAILABLE_DATA\A1\A3CNend
\param[out] phChannel      Pointer to the number of channels. The number of channels depends on the value of pu32ChNum.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ͨ\B5\C0\BE\E4\B1\FA\CA\FD\D7顣\CA\FD\D7鳤\B6\C8\D3\D0pu32ChNum\BE\F6\B6\A8\A1\A3CNend
\param[in] pu32ChNum    Pointer type
                           Input: indicates the number of channel handles to which pChannelHandle points.
                           Output: indicates the number of lower-layer channels that receive new data. The maximum value cannot be greater than the input value.
                           CNcomment: ָ\D5\EB\C0\E0\D0͡\A3ע\D2\E2:\B8ò\CE\CA\FDͬʱ\D7\F7Ϊ\CA\E4\C8\EB\BA\CD\CA\E4\B3\F6\A1\A3CNend
                           CNcomment: \CA\E4\C8룺pChannelHandleָ\CF\F2\CA\FD\D7\E9\B5ĳ\A4\B6ȡ\A3CNend
                           CNcomment: \CA\E4\B3\F6\A3\BA\B5ײ\E3\D3\D0\D0\C2\CA\FD\BE\DDͨ\B5\C0\B5\C4\CA\FDĿ\A3\BB\D7\EE\B6಻\B3\AC\B9\FD\CA\E4\C8\EB\B5\C4\CA\FDֵ\A1\A3CNend
\param[in] u32TimeOutMs      Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA  No data is received in any channel.CNcomment:û\D3\D0\C8κ\CEͨ\B5\C0\D3\D0\CA\FD\BEݵ\BD\B4CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out.CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_GetDataHandle(HI_HANDLE *phChannel, HI_U32 *pu32ChNum,
            HI_U32 u32TimeOutMs);

/**
\brief Obtains whether data is received in some channels.CNcomment:\B2\E9ѯ\B2\BF\B7\D6ͨ\B5\C0\CAǷ\F1\D3\D0\CA\FD\BEݵ\BD\B4CNend
\attention \n
This API is a supplementary interface of ::HI_UNF_DMX_GetDataHandle. You can call this API when you only want to check whether data is received in some channels.
The handles of the channels to be queried are specified by phWatchChannel, and the number of channels to be queried is specified by u32WatchNum.\n
If phWatchChannel is NULL, all channels are queried. The value of u32WatchNum cannot be 0.\n
The block time is configurable (in ms). If u32TimeOutMs is set to 0, it indicates that the block time is 0; if u32TimeOutMs is set to 0xFFFFFFFF, it indicates infinite wait.\n
If no data is received when the block time is exceeded, the error code HI_ERR_DMX_TIMEOUT is returned.\n
If the wait time is 0, and no data is received in any channel, ::HI_ERR_DMX_NOAVAILABLE_DATA is returned.
CNcomment:\D3\C3\C0\B4\D7\F7Ϊ::HI_UNF_DMX_GetDataHandle\B5Ĳ\B9\B3䣬\B5\B1Ӧ\D3\C3\D6\D0ֻ\B9\D8ע\B2\BF\B7\D6ͨ\B5\C0\B5\C4\CA\FD\BEݵ\BD\B4\EF\C7\E9\BF\F6ʱʹ\D3ô˽ӿ\DA\n
\B1\BB\BC\E0\CA\D3ͨ\B5\C0\B5ľ\E4\B1\FA\D3\C9phWatchChannelָ\B6\A8\A3\AC\B8\F6\CA\FD\D3\C9u32WatchNumָ\B6\A8\n
phWatchChannelΪNULL,\B2\E9ѯ\CB\F9\D3\D0ͨ\B5\C0\B5\C4\CA\FD\BEݵ\BD\B4\EF\C7\E9\BF\F6\A3\ACu32WatchNum\B1\D8\D0\EBΪ\B7\C70ֵ\n
\D7\E8\C8\FBʱ\BC\E4\BF\C9\D2\D4\C9\E8\D6ã\ACʱ\BC䵥λΪ\BA\C1\C3룬\C9\E8\D6\C3Ϊ0\B2\BB\B5ȴ\FD\A3\AC\C9\E8\D6\C3Ϊ0xffffffffһֱ\B5ȴ\FD\A1\A3\n
\C8\F4\B3\AC\B9\FD\D7\E8\C8\FBʱ\BC䣬\CB\F9\D3\D0ͨ\B5\C0\B6\BCû\D3\D0\CA\FD\BEݵ\BD\B4\D4򷵻صȴ\FD\B3\ACʱ\B4\ED\CE\F3\n
\C8\E7\B9\FB\B5ȴ\FDʱ\BC\E4Ϊ0\A3\AC\B6\F8\C7\D2û\D3\D0\C8κ\CEͨ\B5\C0\D3\D0\CA\FD\BE\DD\D4򷵻\D8::HI_ERR_DMX_NOAVAILABLE_DATA\A1\A3CNend
\param[in] phWatchChannel   Pointer to the number of handles of the channels to be queried. The number depends on the value of u32WatchNum.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF򱻼\E0\CA\D3ͨ\B5\C0\B5ľ\E4\B1\FA\CA\FD\D7顣\CA\FD\D7鳤\B6\C8\D3\D0u32WatchNum\BE\F6\B6\A8\A1\A3CNend
\param[in] u32WatchNum      Number of channels to be queried.CNcomment:\BC\E0\CA\D3ͨ\B5\C0\B5ĸ\F6\CA\FD\A1\A3CNend
\param[in] phDataChannel    Pointer to the number of handles of the channels that contain data The number depends on the value of pu32ChNum.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\B4\E6\D4\DA\CA\FD\BEݵ\C4ͨ\B5\C0\B5ľ\E4\B1\FA\CA\FD\D7顣\CA\FD\D7鳤\B6\C8\D3\D0pu32ChNum\BE\F6\B6\A8\A1\A3CNend
\param[out] pu32ChNum       Pointer to the number of lower-layer channels that receive new data. The maximum value cannot be greater than the input value.CNcomment:ָ\D5\EB\C0\E0\D0͡\A3\B5ײ\E3\D3\D0\D0\C2\CA\FD\BE\DDͨ\B5\C0\B5\C4\CA\FDĿ\A3\BB\D7\EE\B6಻\B3\AC\B9\FD\B1\BB\BC\E0\CAӵ\C4ͨ\B5\C0\B5\C4\CA\FDֵ\A1\A3CNend
\param[in] u32TimeOutMs     Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR   The pointer is null.CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA   No data is received in any channel.CNcomment:û\D3\D0\C8κ\CEͨ\B5\C0\D3\D0\CA\FD\BEݵ\BD\B4CNend
\retval ::HI_ERR_DMX_TIMEOUT   The wait times out.CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_SelectDataHandle(HI_HANDLE *phWatchChannel, HI_U32 u32WatchNum,
            HI_HANDLE *phDataChannel, HI_U32 *pu32ChNum, HI_U32 u32TimeOutMs);

/**
\brief Obtains the received data packets from a specific channel.CNcomment:\B4\D3ָ\B6\A8ͨ\B5\C0\D6л\F1ȡ\CA\E4\B3\F6\B5\C4\CA\FD\BEݰ\FC\A1\A3CNend
\attention \n
Before calling this API, you need to set the value of u32AcquireNum to specify the maximum number of buffers that can be queried. The number of buffers depends on the value of u32AcquireNum.\n
The value of pu32AcquiredNum is not greater than that of u32AcquireNum.\n
For the Section channel, ECM channel, or EMM channel, each data packet contains a complete Section.\n
For the PES channel, each data packet may contain a complete PES. If the PES is too large, it is divided into multiple PES packets to transfer.\n
The enDataType field determines whether a transferred data packet is complete.\n
For the post channel, each data packet may contain one or more complete TS packets. Each TS packet consists of 188 bytes.\n
For the audio/video channel, data cannot be obtained by calling this API. The audio data and video data are transferred to the decoder through internal interfaces.
You cannot call this API repeatedly, but you can call this API once and release buffers for several times. Note that you must release buffers in sequence, and the address and size of the buffer to be released must be consistent with those obtained by calling HI_UNF_DMX_AcquireBuf.
In addition, you can call HI_UNF_DMX_AcquireBuf again only after all data packets are released. Otherwise, the error code HI_ERR_DMX_REACQUIRE_BUF is returned.
CNcomment:\D4ڵ\F7\D3ñ\BE\BDӿ\DA֮ǰ\A3\AC\B8\F8u32AcquireNum\B8\B3ֵ\A3\ACָ\B6\A8\D4\CA\D0\ED\B2\E9ѯ\B5Ļ\BA\B3\E5\C7\F8\D0\C5Ϣ\D7\EE\B4\F3\CA\FDĿ\A1\A3\CF\FBϢ\BB\BA\B3\E5\C7\F8\CA\FD\D7\E9\B5ĳ\A4\B6\C8\D3\C9u32AcquireNum\BE\F6\B6\A8\n
ʵ\BCʻ\F1ȡ\B5Ļ\BA\B3\E5\C7\F8\D0\C5Ϣ\CA\FDĿpu32AcquiredNum\CA\FDֵ\B2\BB\BBᳬ\B9\FDu32AcquireNum\n
\B6\D4\D3\DAsectionͨ\B5\C0\BA\CDECM/EMMͨ\B5\C0\A3\ACÿ\B8\F6\CA\FD\BEݰ\FC\B0\FC\BA\ACһ\B8\F6\CD\EA\D5\FB\B5\C4section\n
\B6\D4\D3\DAPESͨ\B5\C0\A3\ACÿ\B8\F6\CA\FD\BEݰ\FC\BE\A1\C1\BF\B0\FC\BA\AC\CD\EA\D5\FB\B5\C4pes\A3\AC\B5\AB\CA\C7\C8\E7\B9\FBpes̫\B4󣬿\C9\C4\DCҪ\B7ֶ\E0\B8\F6pes\B0\FC\CA\E4\B3\F6\A3\AC\n
\CA\E4\B3\F6\B5\C4\CA\FD\BE\DD\CAǷ\F1\CD\EA\D5\FBͨ\B9\FD\CA\FD\BEݰ\FC\BDṹ\B5\C4enDataType\D7ֶ\CEָ\B6\A8\n
\B6\D4\D3\DAPOST\C0\E0\D0͵\C4ͨ\B5\C0\A3\ACÿ\B8\F6\CA\FD\BEݰ\FC\B0\FC\BA\ACһ\B8\F6\BB\F2\B6\E0\B8\F6\CD\EA\D5\FB\B5\C4TS\B0\FC\A3\ACTS\B0\FC\B3\A4188\D7ֽ\DA\n
\B6\D4\D3\DA\D2\F4\CA\D3Ƶͨ\B5\C0\CAǲ\BB\C4\DCͨ\B9\FD\B4˽ӿڻ\F1ȡ\CA\FD\BEݵģ\AC\D2\F4\CA\D3Ƶ\CA\FD\BEݻ\E1ͨ\B9\FD\C4ڲ\BF\BDӿ\DAֱ\BD\D3\CB͸\F8\BD\E2\C2\EB\C6\F7\BD\F8\D0н\E2\C2\EB\n
\B2\BB\D4\CA\D0\ED\D6ظ\B4\B5\F7\D3ô˽ӿڣ\AC\BF\C9\D2\D4һ\B4\CE\C7\EB\C7\F3\B6\E0\B4\CE\CAͷţ\AC\B5\AB\CA\C7\CAͷű\D8\D0밴˳\D0򣬶\F8\C7\D2\CAͷŵĵ\D8ַ\BAͳ\A4\B6ȱ\D8\D0\EB\BA\CD\C7\EB\C7\F3\B5\C4һ\D6\C2\n
\B2\A2\C7\D2ֻ\D3\D0\CAͷ\C5\CD\EA\CB\F9\D3е\C4\CA\FD\BEݰ\FC\B2\C5\C4\DC\D4ٴ\CE\C7\EB\C7󣬷\F1\D4򷵻\D8\D6ظ\B4\C7\EB\C7\F3\B4\ED\CE\F3\C2롣CNend
\param[in] hChannel            Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] u32AcquireNum       Maximum number of obtained data packets.CNcomment:\C7\EB\C7\F3\B5\C4\CA\FD\BEݰ\FC\B5\C4\D7\EE\B4\F3\B8\F6\CA\FD\A1\A3CNend
\param[out] pu32AcquiredNum    Pointer to the actual number of obtained data packets.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ʵ\BC\CA\C7\EB\C7󵽵\C4\CA\FD\BEݰ\FC\B8\F6\CA\FD\A1\A3CNend
\param[out] pstBuf             Pointer to the number of data packets. The number depends on the value of pu32AcquiredNum.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\CA\FD\BEݰ\FC\D0\C5Ϣ\CA\FD\D7飬\CA\FD\D7\E9\B8\F6\CA\FD\D3\C9pu32AcquiredNum\BE\F6\B6\A8\A1\A3CNend
\param[in] u32TimeOutMs        Wait timeout, in ms.CNcomment:\B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λΪms\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA  There is no valid data in the channel.CNcomment:ͨ\B5\C0\D6\D0û\D3\D0\D3\D0Ч\CA\FD\BEݡ\A3CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out.CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\retval ::HI_ERR_DMX_REACQUIRE_BUF  The data packet has been obtained.CNcomment:\D6ظ\B4\C7\EB\C7\F3\CA\FD\BEݰ\FC\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AcquireBuf(HI_HANDLE hChannel, HI_U32 u32AcquireNum,
            HI_U32 * pu32AcquiredNum, HI_UNF_DMX_DATA_S *pstBuf,
            HI_U32 u32TimeOutMs);


/**
\brief Releases the buffers for storing data packets after data packets are processed.CNcomment:\B4\A6\C0\ED\CD\EA\CA\FD\BEݰ\FC\B5\C4\CA\FD\BEݺ\F3\A3\AC\CAͷ\C5\CA\FD\BEݰ\FCռ\D3õĻ\BA\B3\E5\BFռ䡣CNend
\attention \n
If you release buffers by calling this API, the buffers must be those obtained by calling ::HI_UNF_DMX_AcquireBuf, and the addresses and sizes of these buffers cannot be changed.\n
The number of released buffers can be less than the number of obtained buffers.
CNcomment:\B1\BE\BDӿ\DA\CAͷŵĻ\BA\B3\E5\C7\F8һ\B6\A8\CA\C7ͨ\B9\FD::HI_UNF_DMX_AcquireBuf\BB\F1ȡ\B5Ļ\BA\B3\E5\C7\F8\A3\AC\BB\BA\B3\E5\C7\F8\B5ĵ\D8ַ\BAͳ\A4\B6Ȳ\BB\C4ܸ\FC\B8\C4\n
\CAͷŵĻ\BA\B3\E5\C7\F8\B8\F6\CA\FD\BF\C9\D2\D4С\D3ڻ\F1ȡ\B5Ļ\BA\B3\E5\C7\F8\B8\F6\CA\FD\A1\A3CNend
\param[in] hChannel        Channel handl.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] u32ReleaseNum   Number of released buffers.CNcomment:\CAͷ\C5\CA\FD\BEݰ\FC\B8\F6\CA\FD\A1\A3CNend
\param[in] pstBuf          Pointer to the number of released buffers. The number depends on the value of u32ReleaseNum.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\CAͷŻ\BA\B3\E5\C7\F8\D0\C5Ϣ\CA\FD\D7飬\B3\A4\B6\C8\D3\C9u32ReleaseNum\BE\F6\B6\A8\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_ReleaseBuf(HI_HANDLE hChannel, HI_U32 u32ReleaseNum,
            HI_UNF_DMX_DATA_S *pstBuf);

/**
\brief Obtains the received es data packets from a specific channel.CNcomment:\B4\D3ָ\B6\A8ͨ\B5\C0\D6л\F1ȡ\CA\E4\B3\F6\B5\C4es\CA\FD\BEݰ\FC\A1\A3CNend
\attention \n
You can call this API to obtain video or audio es data.\n
It's allowed to call repeatedly and then release in the same order.
CNcomment:\D2\F4\CA\D3Ƶͨ\B5\C0ͨ\B9\FD\B4˽ӿڻ\F1ȡes\CA\FD\BE\DD.\n
\D4\CA\D0\ED\D6ظ\B4\B5\F7\D3ô˽ӿڻ\F1ȡ\D3\D0Ч\CA\FD\BEݣ\ACȻ\BA\F3\B0\B4\CF\E0ͬ˳\D0\F2\CAͷš\A3CNend
\param[in] hChannel            Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] pEsBuf             Pointer to the es data packets.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2es\CA\FD\BEݰ\FC\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA  There is no valid data in the channel\A1\A3CNcomment:ͨ\B5\C0\D6\D0û\D3\D0\D3\D0Ч\CA\FD\BEݡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_AcquireEs(HI_HANDLE hChannel, HI_UNF_ES_BUF_S *pEsBuf);

/**
\brief Releases the es buffers after processed.CNcomment:\B4\A6\C0\ED\CD\EAes\CA\FD\BEݰ\FC\B5\C4\CA\FD\BEݺ\F3\A3\AC\CAͷ\C5\CA\FD\BEݰ\FC\CB\F9\D4\DAbuffer\A1\A3CNend
\attention \n
If you release buffers by calling this API, the buffers must be those obtained by calling ::HI_UNF_DMX_AcquireEs, and the addresses and sizes of these buffers cannot be changed.
CNcomment:\B1\BE\BDӿ\DA\CAͷŵĻ\BA\B3\E5\C7\F8һ\B6\A8\CA\C7ͨ\B9\FD::HI_UNF_DMX_AcquireEs\BB\F1ȡ\B5Ļ\BA\B3\E5\C7\F8\A3\AC\BB\BA\B3\E5\C7\F8\B5ĵ\D8ַ\BAͳ\A4\B6Ȳ\BB\C4ܸ\FC\B8\C4.CNend
\param[in] hChannel        Channel handl.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[in] pEsBuf          Pointer to the es data packets.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2es\CA\FD\BEݰ\FC\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_ReleaseEs(HI_HANDLE hChannel, const HI_UNF_ES_BUF_S *pEsBuf);

/**
\brief Creates a record channel. CNcomment: \B4\B4\BD\A8һ\B8\F6¼\D6\C6ͨ\B5\C0\A1\A3CNend
\attention \n
A demux can be set only one recording channe.
CNcomment: һ\B8\F6DEMUX\C9\CFֻ\C4ܴ\B4\BD\A8һ\B8\F6¼\D6\C6ͨ\B5\C0\A1\A3CNend
\param[in]  pstRecAttr  record attribute.   CNcomment: ¼\D6\C6\CA\F4\D0ԡ\A3CNend
\param[out] phRecChn    record handle.      CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment: ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_CHAN  There is no available channel. CNcomment: û\D3п\D5\CFе\C4ͨ\B5\C0\A1\A3CNend
\retval ::HI_ERR_DMX_ALLOC_MEM_FAILED  memory allocate failure. CNcomment: \C4ڴ\E6\B7\D6\C5\E4ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_MMAP_FAILED  memory map failed. CNcomment: \C4ڴ\E6ӳ\C9\E4ʧ\B0ܡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_CreateRecChn(HI_UNF_DMX_REC_ATTR_S *pstRecAttr, HI_HANDLE *phRecChn);

/**
\brief Destroys an existing record channel. CNcomment: \CF\FA\BBٴ\B4\BD\A8\B5\C4¼\D6\C6ͨ\B5\C0\A1\A3CNend
\attention \n
 N/A. CNcomment: \CEޡ\A3CNend
\param[in] hRecChn  record handle. CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment: ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_DestroyRecChn(HI_HANDLE hRecChn);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_SELECT_PID, it would increase the recorded PID that we need. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_SELECT_PIDʱ\D4\F6\BC\D3\D0\E8Ҫ¼\D6Ƶ\C4PID\A1\A3CNend
\attention \n
 N/A. CNcomment: \CEޡ\A3CNend
\param[in]  hRecChn     record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in]  u32Pid      pid value.      CNcomment: PIDֵ\A1\A3CNend
\param[out] phChannel   channel handle. CNcomment: ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment: ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AddRecPid(HI_HANDLE hRecChn, HI_U32 u32Pid, HI_HANDLE *phChannel);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_SELECT_PID, it would delete increase PID. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_SELECT_PIDʱɾ\B3\FD\D2\D1\D4\F6\BCӵ\C4PID\A1\A3CNend
\attention \n
 N/A. CNcomment: \CEޡ\A3CNend
\param[in]  hRecChn     record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in]  hChannel    channel handle. CNcomment: ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_DelRecPid(HI_HANDLE hRecChn, HI_HANDLE hChannel);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_SELECT_PID, it would delete all increase PID. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_SELECT_PIDʱɾ\B3\FD\CB\F9\D3\D0\D2\D1\D4\F6\BCӵ\C4PID\A1\A3CNend
\attention \n
 N/A. CNcomment: \CEޡ\A3CNend
\param[in] hRecChn  record handle. CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_DelAllRecPid(HI_HANDLE hRecChn);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_ALL_PID, it would remove the specified PID. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_ALL_PIDʱ\C5ų\FDָ\B6\A8\B5\C4PID\A1\A3CNend
\attention \n
chips do not support the function.
CNcomment: оƬ\B2\BB֧\B3ִ˹\A6\C4\DCʱ\B7\B5\BBز\BB֧\B3֡\A3CNend
\param[in]  hRecChn record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in]  u32Pid  pid value.      CNcomment: PIDֵ\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AddExcludeRecPid(HI_HANDLE hRecChn, HI_U32 u32Pid);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_ALL_PID, it would cancel the PID that have been removed. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_ALL_PIDʱȡ\CF\FB\D2\D1\C5ų\FD\B5\C4PID\A1\A3CNend
\attention \n
chips do not support the function.
CNcomment: оƬ\B2\BB֧\B3ִ˹\A6\C4\DCʱ\B7\B5\BBز\BB֧\B3֡\A3CNend
\param[in]  hRecChn record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in]  u32Pid  pid value.      CNcomment: PIDֵ\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_DelExcludeRecPid(HI_HANDLE hRecChn, HI_U32 u32Pid);

/**
\brief if the type of record were the HI_UNF_DMX_REC_TYPE_ALL_PID, it would cancel all the PID that have been removed. CNcomment: ¼\D6\C6\C0\E0\D0\CDΪHI_UNF_DMX_REC_TYPE_ALL_PIDʱȡ\CF\FB\CB\F9\D3\D0\D2\D1\C5ų\FD\B5\C4PID\A1\A3CNend
\attention \n
chips do not support the function.
CNcomment: оƬ\B2\BB֧\B3ִ˹\A6\C4\DCʱ\B7\B5\BBز\BB֧\B3֡\A3CNend
\param[in] hRecChn  record handle. CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_DelAllExcludeRecPid(HI_HANDLE hRecChn);

/**
\brief Starts a recording channel. CNcomment: \C6\F4\B6\AF¼\D6\C6ͨ\B5\C0\A1\A3CNend
\attention \n
when the recording channel has been activated, it should use the interface to come back success.
CNcomment: \D4\DA¼\D6\C6ͨ\B5\C0\D2\D1\C6\F4\B6\AF\B5\C4״̬\CFµ\F7\D3ñ\BE\BDӿڷ\B5\BBسɹ\A6\A1\A3CNend
\param[in] hRecChn  record handle. CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_StartRecChn(HI_HANDLE hRecChn);

/**
\brief Stops a recording channel. CNcomment: ֹͣ¼\D6\C6ͨ\B5\C0\A1\A3CNend
\attention \n
when the recording channel has been stopped, it should use the interface to come back success.
CNcomment: \D4\DA¼\D6\C6ͨ\B5\C0\D2\D1ֹͣ\B5\C4״̬\CFµ\F7\D3ñ\BE\BDӿڷ\B5\BBسɹ\A6\A1\A3CNend
\param[in] hRecChn  record handle. CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_StopRecChn(HI_HANDLE hRecChn);

/**
\brief Obtains record data. CNcomment: \BB\F1ȡ¼\D6\C6\CA\FD\BEݡ\A3CNend
\attention \n
The obtained data must use the ::HI_UNF_DMX_ReleaseRecData function to release.
CNcomment: \B5\F7\D3ñ\BE\BDӿڻ\F1ȡ\B5\BD\B5\C4\CA\FD\BEݱ\D8\D0\EBʹ\D3\C3::HI_UNF_DMX_ReleaseRecData\BDӿڽ\F8\D0\D0\CAͷš\A3CNend
\param[in]  hRecChn         record handle.          CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[out] pstRecData      record data.            CNcomment: ¼\D6\C6\CA\FD\BEݡ\A3CNend
\param[in]  u32TimeOutMs    Wait timeout, in ms.    CNcomment: \B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λΪ\BA\C1\C3롣CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AcquireRecData(HI_HANDLE hRecChn, HI_UNF_DMX_REC_DATA_S *pstRecData, HI_U32 u32TimeoutMs);

/**
\brief Releases record data. CNcomment: \CAͷŻ\F1ȡ\B5\BD\B5\C4¼\D6\C6\CA\FD\BEݡ\A3CNend
\attention \n
 N/A. CNcomment:\CEޡ\A3CNend
\param[in] hRecChn      record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in] pstRecData   record data.    CNcomment: ¼\D6\C6\CA\FD\BEݡ\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_ReleaseRecData(HI_HANDLE hRecChn, const HI_UNF_DMX_REC_DATA_S *pstRecData);

/**
\brief Obtains index data. CNcomment: \BB\F1ȡ\CB\F7\D2\FD\CA\FD\BEݡ\A3CNend
\attention \n
when indexing video or audio, it would use the interface to gain indexing data, or it will not support if you return.
CNcomment: \D2\F4Ƶ\BB\F2\CA\D3Ƶ\CB\F7\D2\FDʱ\B2\C5\C4ܻ\F1ȡ\CB\F7\D2\FD\CA\FD\BEݣ\AC\B7\F1\D4򷵻ز\BB֧\B3֡\A3CNend
\param[in]  hRecChn         record handle.          CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[out] pstRecIndex     index data.             CNcomment: \CB\F7\D2\FD\CA\FD\BEݡ\A3CNend
\param[in]  u32TimeOutMs    Wait timeout, in ms.    CNcomment: \B5ȴ\FD\B3\ACʱʱ\BC䣬\B5\A5λΪ\BA\C1\C3롣CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_START_REC_CHAN  CNcomment: ¼\D6\C6ͨ\B5\C0δ\C6\F4\B6\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA  no data. CNcomment: \CE\DE\CA\FD\BEݡ\A3CNend
\retval ::HI_ERR_DMX_TIMEOUT  The wait times out. CNcomment:\B5ȴ\FD\B3\ACʱ\A1\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AcquireRecIndex(HI_HANDLE hRecChn, HI_UNF_DMX_REC_INDEX_S *pstRecIndex, HI_U32 u32TimeoutMs);

/**
\brief Obtains index and rec data with synchronous. CNcomment: ͬ\B2\BD\BB\F1ȡ\CB\F7\D2\FD\BA\CD¼\D6\C6\CA\FD\BE\DD \A1\A3CNend
\attention \n
1. when indexing video or audio, it would use the interface to gain indexing data and record TS data with synchronous, \n
2. when recording all ts without index, .it would use the interface to gain only record TS data, as there is no index. \n
3. Length of each block of record data is Alligned with 188 and 16 if it is not 0.
CNcomment:
1. \D2\F4Ƶ\BB\F2\CA\D3Ƶ\CB\F7\D2\FDʱ\A3\AC\BF\C9\D2Ի\F1ȡ\CB\F7\D2\FD\CA\FD\BEݺ\CD\D3\EB֮\B6\D4Ӧ\B5\C4¼\D6\C6TS\CA\FD\BE\DD\n
2.\C8\E7\B9\FB\CA\C7allts ¼\D6ƣ\AC\D4\F2ֻ\BF\C9\D2Ի\F1ȡ¼\D6Ƶ\C4TS\CA\FD\BEݣ\AC\B4\CBʱ\CE\DE\CB\F7\D2\FD\CA\FD\BE\DD\n
3. \BB\F1ȡ\C9\CF\C0\B4\B5\C4ÿһ\B8\F6\CA\FD\BEݿ\E9\B5ĳ\A4\B6\C8\C8\E7\B9\FB\B2\BBΪ0\A3\AC\B6\BC\CA\C7188 \D3\EB 16 \B6\D4\C6\EB\B5ġ\A3CNend
\param[in]  hRecChn         record handle.          CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[out] pstRecDataIdx     index and record data.             CNcomment: \CB\F7\D2\FD\CA\FD\BEݺ\CD¼\D6\C6TS\CA\FD\BEݡ\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_START_REC_CHAN  CNcomment: ¼\D6\C6ͨ\B5\C0δ\C6\F4\B6\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\retval ::HI_ERR_DMX_NOAVAILABLE_DATA  no data. CNcomment: \CE\DE\CA\FD\BEݡ\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_AcquireRecDataAndIndex(HI_HANDLE hRecChn, HI_UNF_DMX_REC_DATA_INDEX_S* pstRecDataIdx);

/**
\brief Releases record data. CNcomment: \CAͷŻ\F1ȡ\B5\BD\B5\C4\CB\F7\D2\FD\CA\FD\BEݺ\CD¼\D6\C6\CA\FD\BEݡ\A3CNend
\attention \n
 N/A. CNcomment:\CEޡ\A3CNend
\param[in] hRecChn      record handle.  CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[in] pstRecDataIdx   record data and index.    CNcomment: ¼\D6\C6\CA\FD\BEݺ\CD\CB\F7\D2\FD\CA\FD\BEݡ\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_MDX_REC_BUFNOTMATCH  The param is not mattched . CNcomment:\B2\CE\CA\FD\B2\BBƥ\C5䣬\C0\FD\C8\E7\CAͷŵĵ\D8ַ\BB\F2\D5߳\A4\B6ȷǷ\A8\A1\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_ReleaseRecDataAndIndex(HI_HANDLE hRecChn, HI_UNF_DMX_REC_DATA_INDEX_S* pstRecDataIdx);
/**
\brief Obtains the status of a record buffer. CNcomment: \BB\F1ȡ¼\D6ƻ\BA\B4\E6\B5\C4״̬\A1\A3CNend
\attention \n
 N/A. CNcomment:\CEޡ\A3CNend
\param[in]  hRecChn         record handle.          CNcomment: ¼\D6ƾ\E4\B1\FA\A1\A3CNend
\param[out] pstBufStatus    record buffer status.   CNcomment: ¼\D6ƻ\BA\B4\E6\B5\C4״̬\A1\A3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
*/
HI_S32  HI_UNF_DMX_GetRecBufferStatus(HI_HANDLE hRecChn, HI_UNF_DMX_RECBUF_STATUS_S *pstBufStatus);

/**
\brief register channel callback .CNcomment:ע\B2\E1ͨ\B5\C0\BBص\F7\A1\A3CNend
\attention \n
 N/A. CNcomment:\CEޡ\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0Handle\A1\A3CNend
\param[out] pstCbDesc  Pointer to the descriptor of a specified cb. For details, see the description of HI_UNF_DMX_CB_DESC_S.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ָ\B6\A8ͨ\B5\C0 \BBص\F7\C3\E8\CA\F6\D0\C5Ϣ\A1\A3\C7\EB\B2μ\FB::HI_UNF_DMX_CB_DESC_S\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_RegisterCallback(HI_HANDLE hChannel, HI_UNF_DMX_CB_DESC_S *pstCbDesc);

/**
\brief unregister channel callback.CNcomment:ע\CF\FAͨ\B5\C0\BBص\F7\A1\A3CNend
\attention \n
 N/A. CNcomment:\CEޡ\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_UnRegisterCallback(HI_HANDLE hChannel);

/**
\brief Set or get the extra attributes of a demux through the commands.CNcomment:ͨ\B9\FD\C3\FC\C1\EE\C9\E8\D6û\F2\BB\F1ȡDMX\B8\BD\BC\D3\CA\F4\D0\D4CNend
\attention \n
Diffrent CMD use diffrent param, for details see the description of HI_UNF_DMX_INVOKE_TYPE_E.\n
CNcomment:\B2\BBͬ\B5\C4\C3\FC\C1\EEʹ\D3õĲ\CE\CA\FD\B2\BBͬ\A3\AC\BE\DF\CC\E5\D0\C5Ϣ\C7\EB\B2ο\BC\C3\FC\C1\EEö\BEٵĶ\A8\D2\E5HI_UNF_DMX_INVOKE_TYPE_E\n CNend
\param[in] enCmd   Command type.CNcomment:\C3\FC\C1\EE\C0\E0\D0͡\A3CNend
\param[in] pCmdPara    Pointer to command param.  CNcomment:\C3\FC\C1\EE\B2\CE\CA\FDCNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DCCNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AFCNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5CNend
\see \n
 N/A. CNcomment:\CEޡ\A3CNend
 */
HI_S32 HI_UNF_DMX_Invoke(HI_UNF_DMX_INVOKE_TYPE_E enCmd, const HI_VOID *pCmdPara);


/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif  /* __HI_UNF_DEMUX_H__ */

