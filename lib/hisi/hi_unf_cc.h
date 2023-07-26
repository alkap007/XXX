/******************************************************************************

Copyright (C), 2012-2019, HiSilicon Technologies Co., Ltd.
******************************************************************************
File Name       : hi_unf_cc.h
Version         : Initial draft
Author          :
Created Date    :
Last Modified by:
Description     :
Function List   :
Change History  :
******************************************************************************/

/**
 * \file
 * \brief Describes the information about CC module (CC).
*/

#ifndef _HI_UNF_CC_H_
#define _HI_UNF_CC_H_

#include "hi_type.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
*                    Macro Definitions
*****************************************************************************/
#define ARIBCC_MAX_LANGUAGE 2

/*************************** Structure Definition ****************************/
/** \addtogroup      CC */
/** @{*/  /** <!-- [CC]*/

/**CC data type*//** CNcomment:CC\CA\FD\BE\DD\C0\E0\D0ͷ\D6\C0\E0 */
typedef enum hiUNF_CC_DATA_TYPE_E
{
    HI_UNF_CC_DATA_TYPE_608,  /**<CC608*//**<CNcomment:CC608\CA\FD\BE\DD */
    HI_UNF_CC_DATA_TYPE_708,        /**<CC708*//**<CNcomment:CC708\CA\FD\BE\DD */
    HI_UNF_CC_DATA_TYPE_ARIB,       /**<ARIB CC*//**<CNcomment:ARIB CC\CA\FD\BE\DD */
    HI_UNF_CC_DATA_TYPE_BUTT
}HI_UNF_CC_DATA_TYPE_E;

/**708CC service channel*//** CNcomment:708CC\B5ķ\FE\CE\F1ͨ\B5\C0\BA\C5*/
typedef enum hiUNF_CC_708_SERVICE_NUM_E
{
    HI_UNF_CC_708_SERVICE1 = 0x1, /**<708CC service 1*//**<CNcomment:708CC\B7\FE\CE\F11 */
    HI_UNF_CC_708_SERVICE2,       /**<708CC service 2*//**<CNcomment:708CC\B7\FE\CE\F12 */
    HI_UNF_CC_708_SERVICE3,       /**<708CC service 3*//**<CNcomment:708CC\B7\FE\CE\F13 */
    HI_UNF_CC_708_SERVICE4,       /**<708CC service 4*//**<CNcomment:708CC\B7\FE\CE\F14 */
    HI_UNF_CC_708_SERVICE5,       /**<708CC service 5*//**<CNcomment:708CC\B7\FE\CE\F15 */
    HI_UNF_CC_708_SERVICE6,       /**<708CC service 6*//**<CNcomment:708CC\B7\FE\CE\F16 */
    HI_UNF_CC_708_SERVICE_BUTT
}HI_UNF_CC_708_SERVICE_NUM_E;

/**CC608 data type*//** CNcomment:CC608\D4\DAline 21\B5\C4\CA\FD\BE\DD\C0\E0\D0ͷ\D6\C0\E0 */
typedef enum hiUNF_CC_608_DATATYPE_E
{
    HI_UNF_CC_608_DATATYPE_CC1,       /**<CC1*//**<CNcomment:CC1 */
    HI_UNF_CC_608_DATATYPE_CC2,       /**<CC2*//**<CNcomment:CC2 */
    HI_UNF_CC_608_DATATYPE_CC3,       /**<CC3*//**<CNcomment:CC3 */
    HI_UNF_CC_608_DATATYPE_CC4,       /**<CC4*//**<CNcomment:CC4 */
    HI_UNF_CC_608_DATATYPE_TEXT1,     /**<TEXT1*//**<CNcomment:TEXT1 */
    HI_UNF_CC_608_DATATYPE_TEXT2,     /**<TEXT2*//**<CNcomment:TEXT2 */
    HI_UNF_CC_608_DATATYPE_TEXT3,     /**<TEXT3*//**<CNcomment:TEXT3 */
    HI_UNF_CC_608_DATATYPE_TEXT4,     /**<TEXT4*//**<CNcomment:TEXT4 */
    HI_UNF_CC_608_DATATYPE_BUTT
}HI_UNF_CC_608_DATATYPE_E;

/**standard color*//** CNcomment:\B1\EA׼\D1\D5ɫ */
typedef enum hiUNF_CC_COLOR_E
{
    HI_UNF_CC_COLOR_DEFAULT=0x00000000,       /**<default color*//**<CNcomment:Ĭ\C8\CF\D1\D5ɫ */
    HI_UNF_CC_COLOR_BLACK=0xff000000,         /**<black*//**<CNcomment:\BA\DAɫ */
    HI_UNF_CC_COLOR_WHITE=0xffffffff,         /**<white*//**<CNcomment:\B0\D7ɫ */
    HI_UNF_CC_COLOR_RED=0xffff0000,           /**<red*//**<CNcomment:\BA\ECɫ */
    HI_UNF_CC_COLOR_GREEN=0xff00ff00,         /**<green*//**<CNcomment:\C2\CCɫ */
    HI_UNF_CC_COLOR_BLUE=0xff0000ff,          /**<blue*//**<CNcomment:\C0\B6ɫ */
    HI_UNF_CC_COLOR_YELLOW=0xffffff00,        /**<yellow*//**<CNcomment:\BB\C6ɫ */
    HI_UNF_CC_COLOR_MAGENTA=0xffff00ff,       /**<magenta*//**<CNcomment:Ʒ\BA\EC */
    HI_UNF_CC_COLOR_CYAN=0xff00ffff,          /**<cyan*//**<CNcomment:\C7\E0ɫ */
}HI_UNF_CC_COLOR_E;

/**opacity*//** CNcomment:͸\C3\F7\B6\C8 */
typedef enum hiUNF_CC_OPACITY_E
{
    HI_UNF_CC_OPACITY_DEFAULT,         /**<default*//**<CNcomment:Ĭ\C8\CF͸\C3\F7\B6\C8 */
    HI_UNF_CC_OPACITY_SOLID,           /**<opaque*//**<CNcomment:\B2\BB͸\C3\F7 */
    HI_UNF_CC_OPACITY_FLASH,           /**<flash*//**<CNcomment:\C9\C1˸ */
    HI_UNF_CC_OPACITY_TRANSLUCENT,     /**<translucent*//**<CNcomment:\B0\EB͸\C3\F7 */
    HI_UNF_CC_OPACITY_TRANSPARENT,     /**<transparent*//**<CNcomment:͸\C3\F7 */
    HI_UNF_CC_OPACITY_BUTT
}HI_UNF_CC_OPACITY_E;

/**justify*//** CNcomment:\C5Ű\E6*/
typedef enum hiUNF_CC_JUSTIFY_E
{
    HI_UNF_CC_JUSTIFY_LEFT,        /**<left*//**<CNcomment:\BE\D3\D7\F3 */
    HI_UNF_CC_JUSTIFY_RIGHT,       /**<rigth*//**<CNcomment:\BE\D3\D3\D2 */
    HI_UNF_CC_JUSTIFY_CENTER,      /**<center*//**<CNcomment:\BE\D3\D6\D0 */
    HI_UNF_CC_JUSTIFY_FULL,        /**<full*//**<CNcomment:\C1\BD\B6˶\D4\C6\EB */
    HI_UNF_CC_JUSTIFY_BUTT
}HI_UNF_CC_JUSTIFY_E;

/**word wrap*//** CNcomment:\D7Զ\AF\BB\BB\D0\D0*/
typedef enum hiUNF_CC_WORDWRAP_E
{
    HI_UNF_CC_WW_DISABLE,         /**<disable*//**<CNcomment:\B2\BB\D7Զ\AF\BB\BB\D0\D0 */
    HI_UNF_CC_WW_ENABLE,          /**<enable*//**<CNcomment:\D7Զ\AF\BB\BB\D0\D0 */
    HI_UNF_CC_WW_BUTT
}HI_UNF_CC_WORDWRAP_E;

/**font style*//** CNcomment:\D7\D6\CC\E5\B7\E7\B8\F1 */
typedef enum hiUNF_CC_FONTSTYLE_E
{
    HI_UNF_CC_FONTSTYLE_DEFAULT,         /**<default*//**<CNcomment:Ĭ\C8\CF\D7\D6\CC\E5\B7\E7\B8\F1 */
    HI_UNF_CC_FONTSTYLE_NORMAL,          /**<normal*//**<CNcomment:\D5\FD\B3\A3 */
    HI_UNF_CC_FONTSTYLE_ITALIC,          /**<italic*//**<CNcomment:б\CC\E5 */
    HI_UNF_CC_FONTSTYLE_UNDERLINE,       /**<underline*//**<CNcomment:\CF»\AE\CF\DF */
    HI_UNF_CC_FONTSTYLE_ITALIC_UNDERLINE,/**<italic&underline*//**<CNcomment:б\CC岢\C7Ҵ\F8\CF»\AC\CF\DF */
    HI_UNF_CC_FONTSTYLE_BUTT
}HI_UNF_CC_FONTSTYLE_E;

/**font size*//** CNcomment:\D7\D6\CC\E5\B4\F3С */
typedef enum hiUNF_CC_FONTSIZE_E
{
    HI_UNF_CC_FONTSIZE_DEFAULT,       /**<default font size *//**<CNcomment:Ĭ\C8\CF\D7\D6\CC\E5\B4\F3С */
    HI_UNF_CC_FONTSIZE_SMALL,         /**<small*//**<CNcomment:С */
    HI_UNF_CC_FONTSIZE_STANDARD,      /**<standard*//**<CNcomment:\B1\EA׼ */
    HI_UNF_CC_FONTSIZE_LARGE,         /**<large*//**<CNcomment:\B4\F3 */
    HI_UNF_CC_FONTSIZE_BUTT
} HI_UNF_CC_FONTSIZE_E;

typedef enum hiUNF_CC_ARIB_SCALE_E
{
    HI_UNF_CC_ARIB_SCALE_NORMAL,
    HI_UNF_CC_ARIB_SCALE_HALF_ALL,
    HI_UNF_CC_ARIB_SCALE_HALF_WIDTH,
    HI_UNF_CC_ARIB_SCALE_DOUBLE_HEIGHT,
    HI_UNF_CC_ARIB_SCALE_DOUBLE_WIDTH,
    HI_UNF_CC_ARIB_SCALE_DOUBLE_ALL,
    HI_UNF_CC_ARIB_SCALE_TINY,
    HI_UNF_CC_ARIB_SCALE_BUTT
}HI_UNF_CC_ARIB_SCALE_E;

typedef enum tagUNF_CC_ARIB_PRTDIRECT_E
{
    HI_UNF_CC_ARIB_PRINT_HORIZONTAL,
    HI_UNF_CC_ARIB_PRINT_VERTICAL,
} HI_UNF_CC_ARIB_PRTDIRECT_E;

/**font name*//** CNcomment:\D7\D6\CC\E5\D1\F9ʽ */
typedef enum  hiUNF_CC_FONTNAME_E
{
    HI_UNF_CC_FN_DEFAULT,                  /**<default *//**<CNcomment:Ĭ\C8\CF\D7\D6\CC\E5\D1\F9ʽ */
    HI_UNF_CC_FN_MONOSPACED,               /**<monospaced*//**<CNcomment:monospaced\D7\D6\CC\E5 */
    HI_UNF_CC_FN_PROPORT,                  /**<proport*//**<CNcomment:proport\D7\D6\CC\E5 */
    HI_UNF_CC_FN_MONOSPACED_NO_SERIAFS,    /**<monospaced with no seriafs*//**<CNcomment:monospaced\D7\D6\CC\E5(\CE޳\C4\CF\DF) */
    HI_UNF_CC_FN_PROPORT_NO_SERIAFS,       /**<proport with no seriafs*//**<CNcomment:proport\D7\D6\CC\E5(\CE޳\C4\CF\DF) */
    HI_UNF_CC_FN_CASUAL,                   /**<casual*//**<CNcomment:casual\D7\D6\CC\E5 */
    HI_UNF_CC_FN_CURSIVE,                  /**<cursive*//**<CNcomment:cursive\D7\D6\CC\E5 */
    HI_UNF_CC_FN_SMALL_CAPITALS,           /**<small capitals*//**<CNcomment:Сд\D7\D6\CC\E5 */
    HI_UNF_CC_FN_BUTT
}HI_UNF_CC_FONTNAME_E;

/**font edge type*//** CNcomment:\D7\D6\CC\E5\B1\DFԵ\C0\E0\D0\CD */
typedef enum hiUNF_CC_EdgeType_E
{
    HI_UNF_CC_EDGETYPE_DEFAULT,            /**<default *//**<CNcomment:Ĭ\C8\CF\D7\D6\CC\E5\B1\DFԵ\C0\E0\D0\CD */
    HI_UNF_CC_EDGETYPE_NONE,               /**<none edge type *//**<CNcomment:û\D3б\DFԵ */
    HI_UNF_CC_EDGETYPE_RAISED,             /**<raised *//**<CNcomment:\B1\DFԵͻ\C6\F0 */
    HI_UNF_CC_EDGETYPE_DEPRESSED,          /**<depressed *//**<CNcomment:\B1\DFԵ\B0\BC\CF\C2 */
    HI_UNF_CC_EDGETYPE_UNIFORM,            /**<uniform *//**<CNcomment:\B1\DFԵͳһ */
    HI_UNF_CC_EDGETYPE_LEFT_DROP_SHADOW,   /**<left drop shadow *//**<CNcomment:\D7\F3\CF\C2\D2\F5Ӱ */
    HI_UNF_CC_EDGETYPE_RIGHT_DROP_SHADOW,  /**<right drop shadow *//**<CNcomment:\D3\D2\CF\C2\D2\F5Ӱ */
    HI_UNF_CC_EDGETYPE_BUTT
}HI_UNF_CC_EdgeType_E;

/**display format of caption display screen*//** CNcomment:\CF\D4ʾ\B4\B0\BFڵ\C4\CF\D4ʾģʽ */
typedef enum hiUNF_CC_DF_E
{
    HI_UNF_CC_DF_720X480,       /**<caption display screen is 720*480*//**<CNcomment:\CF\D4ʾ\B4\B0\BFڵĿ\ED\B8\DF\CA\C7720*480 */
    HI_UNF_CC_DF_720X576,       /**<caption display screen is 720*576*//**<CNcomment:\CF\D4ʾ\B4\B0\BFڵĿ\ED\B8\DF\CA\C7720*576 */
    HI_UNF_CC_DF_960X540,       /**<caption display screen is 960*540*//**<CNcomment:\CF\D4ʾ\B4\B0\BFڵĿ\ED\B8\DF\CA\C7960*540 */
    HI_UNF_CC_DF_1280X720,      /**<caption display screen is 1280*720*//**<CNcomment:\CF\D4ʾ\B4\B0\BFڵĿ\ED\B8\DF\CA\C71280*720 */
    HI_UNF_CC_DF_1920X1080,     /**<caption display screen is 1920*1080*//**<CNcomment:\CF\D4ʾ\B4\B0\BFڵĿ\ED\B8\DF\CA\C71920*1080 */
    HI_UNF_CC_DF_BUTT
} HI_UNF_CC_DF_E;

/**CC display operation*//** CNcomment:CC\CF\D4ʾ\B2\D9\D7\F7 */
typedef enum hiUNF_CC_OPT_E
{
     HI_UNF_CC_OPT_DRAWTEXT = 0x1, /**<draw text *//**<CNcomment:\BB\E6\D6\C6\CEı\BE */
     HI_UNF_CC_OPT_DRAWBITMAP,     /**<draw bitmap *//**<CNcomment:\BB\E6\D6\C6λͼ */
     HI_UNF_CC_OPT_FILLRECT,       /**<fill rect *//**<CNcomment:\CC\EE\B3\E4\BE\D8\D0\CE\C7\F8\D3\F2 */
     HI_UNF_CC_OPT_UPDATE,        /**<Display buffer on the screen. *//**<CNcomment:\BD\AB\BB\BA\B4\E6\CA\FD\BE\DD\C1\A2\BC\B4\BB\E6\D6Ƶ\BD\C6\C1Ļ\C9\CF */
     HI_UNF_CC_OPT_DRAWLINE,        /**<draw line. *//**<CNcomment:\BB\AD\CF\DF*/
     HI_UNF_CC_OPT_BUTT
} HI_UNF_CC_OPT_E;

/**Arib CC rollup mode*//** CNcomment:arib CC rollupģʽ*/
typedef enum hiUNF_CC_ARIB_ROLLUP_E
{
    HI_UNF_CC_ARIB_NON_ROLLUP,        /**<Non roll-up *//**<CNcomment:\B7\C7rollupģʽ*/
    HI_UNF_CC_ARIB_ROLLUP,      /**<roll-up*//**<CNcomment:rollupģʽ*/
    HI_UNF_CC_ARIB_ROLLUP_BUTT
}HI_UNF_CC_ARIB_ROLLUP_E;


/**Arib CC character coding*//** CNcomment:arib CC \D7ַ\FB\B1\E0\C2뷽ʽ*/
typedef enum hiUNF_CC_ARIB_TCS_E
{
    HI_UNF_CC_ARIB_TCS_8BIT,         /**<the type of character codig is 8bit-code*//**<CNcomment:\D7ַ\FB\B1\E0\C2뷽ʽ(8λ)*/
    HI_UNF_CC_ARIB_TCS_BUTT
}HI_UNF_CC_ARIB_TCS_E;

/**Arib CC display format*//** CNcomment:arib CC\CF\D4ʾ\B7\BDʽ*/
typedef enum hiUNF_CC_ARIB_DF_E
{
    HI_UNF_CC_ARIB_DF_HORIZONTAL_SD,                /**<horizontal writing in stardard density*/    /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\B1\EA\C7\E5*/
    HI_UNF_CC_ARIB_DF_VERTICAL_SD,                  /**<vertical writing in standard density*/      /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\B1\EA\C7\E5*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_HD,                /**<horizontal writing in high density*/        /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\B8\DF\C7\E5*/
    HI_UNF_CC_ARIB_DF_VERTICAL_HD,                  /**<vertical writing in high density*/          /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\B8\DF\C7\E5*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_WESTERN,           /**<horizontal writing of western language*/    /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\CE\F7\CE\C4*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_1920X1080,         /**<horizontal writing in 1920X1080*/           /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\C6\C1Ļ1920X1080*/
    HI_UNF_CC_ARIB_DF_VERTICAL_1920X1080,           /**<vertical writing in 1920X1080*/             /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\C6\C1Ļ1920X1080*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_960X540,           /**<horizontal writing in 960X540*/             /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\C6\C1Ļ960X540*/
    HI_UNF_CC_ARIB_DF_VERTICAL_960X540,             /**<vertical writing in 960X540*/               /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\C6\C1Ļ960X540*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_1280X720,          /**<horizontal writing in 1280X720*/            /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\C6\C1Ļ1280X720*/
    HI_UNF_CC_ARIB_DF_VERTICAL_1280X720,            /**<vertical writing in 1280X720*/              /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\C6\C1Ļ1280X720*/
    HI_UNF_CC_ARIB_DF_HORIZONTAL_720X480,           /**<horizontal writing in 720X480*/             /**<CNcomment:ˮƽ\CF\D4ʾ\A3\AC\C6\C1Ļ720X480*/
    HI_UNF_CC_ARIB_DF_VERTICAL_720X480,             /**<vertical writing in 720X480*/               /**<CNcomment:\B4\B9ֱ\CF\D4ʾ\A3\AC\C6\C1Ļ720X480*/
    HI_UNF_CC_ARIB_DF_BUTT
}HI_UNF_CC_ARIB_DF_E;

/**Arib CC display mode*//** CNcomment:arib CC\CF\D4ʾģʽ*/
typedef enum hiUNF_CC_ARIB_DMF_E
{
    HI_UNF_CC_ARIB_DMF_AUTO_AND_AUTO=0x0,           /**<atomatic display when received ,automatic display when recording and playback */                    /**<CNcomment:\BD\D3\CAպ\F3\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_AUTO_AND_NOT,                /**<atomatic display when received ,Non-displayed automatically when recording and playback*/           /**<CNcomment:\BD\D3\CAպ\F3\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\B2\BB\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_AUTO_AND_SELECT,             /**<atomatic display when received ,Selectable display when recording and playback*/                    /**<CNcomment:\BD\D3\CAպ\F3\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\BF\C9ѡ\D4񲥷\C5*/
    HI_UNF_CC_ARIB_DMF_NON_AND_AUTO=0x4,            /**<non-displayed automatically when received, automatic display when recording and playback */         /**<CNcomment:\BD\D3\CA\D5ʱ\B2\BB\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_NON_AND_NON,                 /**<non-displayed automatically when received,Non-displayed automatically when recording and playback*/ /**<CNcomment:\BD\D3\CA\D5ʱ\B2\BB\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\B2\BB\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_NON_AND_SELECT,              /**<non-displayed automatically when received,Selectable display when recording and playback*/          /**<CNcomment:\BD\D3\CA\D5ʱ\B2\BB\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\BF\C9ѡ\D4񲥷\C5*/
    HI_UNF_CC_ARIB_DMF_SELECT_AND_AUTO=0x8,         /**<selectable display when received, automatic display when recording and playback */                  /**<CNcomment:\BD\D3\CA\D5ʱ\BF\C9ѡ\D4񲥷ţ\AC¼\D6ƺͻط\C5ʱ\BF\C9\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_SELECT_AND_NON,              /**<selectable display when received,Non- displayed automatically when recording and playback*/         /**<CNcomment:\BD\D3\CA\D5ʱ\BF\C9ѡ\D4񲥷ţ\AC¼\D6ƺͻط\C5ʱ\B2\BB\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_SELECT_AND_SELECT,           /**<selectable display when received,Selectable display when recording and playback*/                   /**<CNcomment:\BD\D3\CA\D5ʱ\BF\C9ѡ\D4񲥷ţ\AC¼\D6ƺͻط\C5ʱ\BF\C9ѡ\D4񲥷\C5*/
    HI_UNF_CC_ARIB_DMF_SPECIAL_AND_AUTO=0xc,        /**<automatic display/non-display under specific condition when received,automatic display when recording and playback */           /**<CNcomment:\BD\D3\CA\D5ʱ\CCض\A8\C7\E9\BF\F6\CF\C2\D7Զ\AF/\B7\C7\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_SPECIAL_AND_NON,             /**<automatic display/non-display under specific condition when received,Non-displayed automatically when recording and playback*/  /**<CNcomment:\BD\D3\CA\D5ʱ\CCض\A8\C7\E9\BF\F6\CF\C2\D7Զ\AF/\B7\C7\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\B2\BB\D7Զ\AF\B2\A5\B7\C5*/
    HI_UNF_CC_ARIB_DMF_SPECIAL_AND_SELECT,          /**<automatic display/non-display under specific condition when received,Selectable display when recording and playback*/           /**<CNcomment:\BD\D3\CA\D5ʱ\CCض\A8\C7\E9\BF\F6\CF\C2\D7Զ\AF/\B7\C7\D7Զ\AF\B2\A5\B7ţ\AC¼\D6ƺͻط\C5ʱ\BF\C9ѡ\D4񲥷\C5*/
    HI_UNF_CC_ARIB_DMF_BUTT
}HI_UNF_CC_ARIB_DMF_E;

/**Arib CC time control mode*//** CNcomment:arib CCʱ\BC\E4\BF\D8\D6\C6ģʽ*/
typedef enum hiUNF_CC_ARIB_TMD_E
{
    HI_UNF_CC_ARIB_TMD_FREE,            /**<playback time is not restricted to synchronize to the clock*//**<CNcomment:\D6ط\C5ʱ\BC\E4\BA\CDʱ\D6\D3\CE޹\D8*/
    HI_UNF_CC_ARIB_TMD_REAL_TIME,       /**<playback time is given by PTS*//**<CNcomment:\D6ط\C5ʱ\BC\E4\D3\C9PTS\B8\F8\B3\F6*/
    HI_UNF_CC_ARIB_TMD_OFFSET_TIME,     /**<playback time added with offset time should be the new playback time*//**<CNcomment:\D6ط\C5ʱ\BC\E4\BC\D3\C9\CFƫ\D2\C6ʱ\BC佫\CA\C7\D0µ\C4\D6ط\C5ʱ\BC\E4*/
    HI_UNF_CC_ARIB_TMD_BUTT
}HI_UNF_CC_ARIB_TMD_E;

/**CC608 VBI data*//** CNcomment:CC608 VBI\CA\FD\BE\DD */
typedef struct hiUNF_CC_VBI_DADA_S
{
    HI_U8 u8FieldParity; /**<parity field *//**<CNcomment:\C6\E6ż\B3\A1 */
    HI_U8 u8Data1;       /**<first byte *//**<CNcomment:\B5\DAһ\B8\F6\D7ֽ\DA */
    HI_U8 u8Data2;       /**<second byte *//**<CNcomment:\B5ڶ\FE\B8\F6\D7ֽ\DA */
}HI_UNF_CC_VBI_DADA_S;

/**CC rect*//** CNcomment:\B6\A8\D2\E5CC\BE\D8\D0\CE\C7\F8\D3\F2*/
typedef struct hiUNF_CC_RECT_S
{
    HI_U16 x;           /**<x cordinate *//**<CNcomment:\BE\D8\D0\CE\D7\F3\C9Ͻǵ\C4x\D7\F8\B1\EA */
    HI_U16 y;           /**<y cordinate *//**<CNcomment:\BE\D8\D0\CE\D7\F3\C9Ͻǵ\C4y\D7\F8\B1\EA */
    HI_U16 width;       /**<rect width *//**<CNcomment:\BE\D8\D0εĿ\ED\B6\C8 */
    HI_U16 height;      /**<rect heigth *//**<CNcomment:\BE\D8\D0εĸ߶\C8 */
}HI_UNF_CC_RECT_S;

/**CC color components*//** CNcomment:CC\CF\F1\CB\D8\D1\D5ɫ\BDṹ */
typedef struct hiUNF_CC_COLOR_S
{
    HI_U8 u8Blue;       /**<blue component *//**<CNcomment:B\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Green;      /**<green component *//**<CNcomment:G\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Red;        /**<red component *//**<CNcomment:R\B7\D6\C1\BF\D1\D5ɫֵ */
    HI_U8 u8Alpha;      /**<alpha component *//**<CNcomment:͸\C3\F7\B6ȣ\ACֵΪ0Ϊ͸\C3\F7\A3\AC0xFFΪ\B2\BB͸\C3\F7 */
} HI_UNF_CC_COLOR_S;

/**CC data with text format*//** CNcomment:\CEı\BE\B8\F1ʽ\B5\C4CC\CA\FD\BE\DD */
typedef struct hiUNF_CC_TEXT_S
{
    HI_U16                 *pu16Text;    /**<cc data,2 bytes,unicode *//**<CNcomment:cc\CA\FD\BEݣ\ACunicode\B1\E0\C2룬2\B8\F6\D7ֽ\DA */
    HI_U8                  u8TextLen;    /**<cc data length *//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BEݳ\A4\B6\C8 */

    HI_UNF_CC_COLOR_S      stFgColor;    /**<cc foregroud color*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BE\DDǰ\BE\B0ɫ */
    HI_UNF_CC_COLOR_S      stBgColor;    /**<cc backgroud color*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BE\DD\D7\D6\CC屳\BE\B0ɫ */
    HI_UNF_CC_COLOR_S      stEdgeColor;   /**<cc edge color*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BE\DD\D7\D6\CC\E5\B1\DFԵ\D1\D5ɫ*/

    HI_U8                  u8Justify;    /*see HI_UNF_CC_JUSTIFY_E,used when decode cc708*//**<CNcomment:cc\CA\FD\BE\DD\CF\D4ʾʱ\B5\C4\C5Ű淽ʽ */
    HI_U8                  u8WordWrap;   /*see HI_UNF_CC_WORDWRAP_E,used when decode cc708*//**<CNcomment:\D7Զ\AF\BB\BB\D0\D0 */
    HI_UNF_CC_FONTSTYLE_E  enFontStyle;  /*font style ,see HI_UNF_CC_FONTSTYLE_E*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BEݵ\C4\D7\D6\CC\E5\B7\E7\B8\F1 */
    HI_UNF_CC_FONTSIZE_E   enFontSize;   /*font size ,see HI_UNF_CC_FONTSIZE_E*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BEݵ\C4\D7\D6\CC\E5\B4\F3С */
    HI_UNF_CC_EdgeType_E   enEdgetype;  /**<cc edge type*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BE\DD\D7\D6\CC\E5\B1\DFԵ\C0\E0\D0\CD*/
    HI_U8                  u8AribFontSize;   /*font size *//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BEݵ\C4\D7\D6\CC\E5\B4\F3С */
    HI_UNF_CC_ARIB_SCALE_E enScaleType;
    HI_U8                  u8CharInterval;
    HI_U8                  u8LineInterval;
    HI_UNF_CC_ARIB_PRTDIRECT_E enPrtDirect;
} HI_UNF_CC_TEXT_S;

/**CC data with bitmap format*//** CNcomment:λͼ\B8\F1ʽ\B5\C4CC\CA\FD\BE\DD */
typedef struct hiUNF_CC_BITMAP_S
{
    HI_S32                 s32BitWidth;         /**<bit width, is 2/4/8/16/24/32 *//**<CNcomment:λ\BF\ED,ֵ\CA\C72/4/8/16/24/32 */
    HI_U8                  *pu8BitmapData;      /**<pixel data *//**<CNcomment:ͼ\CF\F1\CA\FD\BE\DD */
    HI_U32                 u32BitmapDataLen;    /**<length of pixel data *//**<CNcomment:ͼ\CF\F1\CA\FD\BEݳ\A4\B6\C8 */
    HI_UNF_CC_COLOR_S      astPalette[256];     /**<palette data *//**<CNcomment:\B5\F7ɫ\B0\E5\CA\FD\BE\DD */
    HI_U32                 u32PaletteLen;       /**<length of palette data *//**<CNcomment:\B5\F7ɫ\B0\E5\CA\FD\BEݳ\A4\B6\C8 */
} HI_UNF_CC_BITMAP_S;

/**parameter of fill rect*//** CNcomment:\CC\EE\B3\E4\BE\D8\D0\CE\C7\F8\D3\F2\B5Ĳ\CE\CA\FD */
typedef struct hiUNF_CC_FILLRECT_S
{
    HI_UNF_CC_COLOR_S      stColor;      /**<color *//**<CNcomment:\D1\D5ɫֵ */
} HI_UNF_CC_FILLRECT_S;

typedef struct hiUNF_CC_LINE_S
{
    HI_U32 u32X1;      /*\BB\AD\CF\DF\C6\F0\B5\E3\D7\F8\B1\EAX1*/
    HI_U32 u32Y1;      /*\BB\AD\CF\DF\C6\F0\B5\E3\D7\F8\B1\EAY1*/
    HI_U32 u32X2;      /*\BB\AD\CF\DF\D6յ\E3\D7\F8\B1\EAX2*/
    HI_U32 u32Y2;      /*\BB\AD\CF\DF\D6յ\E3\D7\F8\B1\EAY2*/
    HI_UNF_CC_COLOR_S      stColor;      /*\CFߵ\C4\D1\D5ɫֵ*/
} HI_UNF_CC_LINE_S;

/**CC display param*//** CNcomment:\B6\A8\D2\E5CC\CA\FD\BE\DD\CF\D4ʾʱ\B5Ĳ\CE\CA\FD */
typedef struct hiUNF_CC_DISPLAY_PARAM_S
{
    HI_UNF_CC_OPT_E        enOpt;
    HI_U32                 u32DisplayWidth; /**<display screen width*//**<CNcomment:\BB\AD\B2\BC\BF\ED\B6\C8 */
    HI_U32                 u32DisplayHeight;/**<display screen height*//**<CNcomment:\BB\AD\B2\BC\B8߶\C8 */
    HI_UNF_CC_RECT_S       stRect;          /**<cc display location*//**<CNcomment:Ҫ\CF\D4ʾ\B5\C4cc\CA\FD\BEݵ\C4λ\D6\C3\D0\C5Ϣ */
    union
    {
        HI_UNF_CC_TEXT_S   stText;          /**<CC data with text format*//**<CNcomment:\CEı\BE\B8\F1ʽ\B5\C4CC\CA\FD\BE\DD */
        HI_UNF_CC_BITMAP_S stBitmap;        /**<CC data with bitmap format*//**<CNcomment:λͼ\B8\F1ʽ\B5\C4CC\CA\FD\BE\DD */
        HI_UNF_CC_FILLRECT_S stFillRect;    /**<parameter of fill rect*//**<CNcomment:\CC\EE\B3\E4\BE\D8\D0\CE\C7\F8\D3\F2\B5Ĳ\CE\CA\FD */
        HI_UNF_CC_LINE_S   stLine;          /**<CC data with line format*//**<CNcomment:ֱ\CF߸\F1ʽ\B5\C4CC\CA\FD\BE\DD */
    } unDispParam;

    HI_BOOL bBlit;                          /**<Whether display on screen. HI_TRUE for display immediately and HI_FALSE for save in buffer. */
                                            /**<CNcomment:\CAǷ\F1\C1\A2\BC\B4\BB\E6\D6Ƶ\BD\C6\C1Ļ\C9ϣ\ACHI_TRUE\B1\EDʾ\C1\A2\BC\B4\BB\E6\D6ƣ\ACHI_FALSE\B1\EDʾ\CFȻ\BA\B4浽buffer\C9ϣ\AC\D4ݲ\BB\BB\E6\D6Ƶ\BD\C6\C1Ļ\C9\CF */
} HI_UNF_CC_DISPLAY_PARAM_S;

/**
\brief cc get text size callback function. CNcomment: cc\D3\C3\D3ڻ\F1\B5\C3\D7\D6\CC\E5\B4\F3С(\BF\ED\B8\DF)\B5Ļص\F7\BA\AF\CA\FD\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] pUserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[in] u16Str  string. CNcomment: \CA\FD\BEݵ\D8ַ\A1\A3CNend
\param[in] s32StrNum  number of character. CNcomment: \CA\FD\BEݳ\A4\B6ȡ\A3CNend
\param[out] ps32Width  total width of character. CNcomment: \B5õ\BD\B5\C4\D7\D6\CC\E5\BF\ED\A1\A3CNend
\param[out] ps32Heigth heigth of character. CNcomment: \B5õ\BD\B5\C4\D7\D6\CC\E5\B8ߡ\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_GETTEXTSIZE_CB_FN)(HI_VOID* pUserData, HI_U16 *u16Str,HI_S32 s32StrNum, HI_S32 *ps32Width, HI_S32 *ps32Heigth);

/**
\brief cc get text size callback function(EX). CNcomment: cc\D3\C3\D3ڻ\F1\B5\C3\D7\D6\CC\E5\B4\F3С(\BF\ED\B8\DF)\B5Ļص\F7\BA\AF\CA\FD(\C0\A9չ\C8\EB\B2\CE)\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] pUserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[in] pstText  text data. CNcomment: \CEı\BE\D0\C5Ϣ\A1\A3CNend
\param[out] ps32Width  total width of character. CNcomment: \B5õ\BD\B5\C4\D7\D6\CC\E5\BF\ED\A1\A3CNend
\param[out] ps32Heigth heigth of character. CNcomment: \B5õ\BD\B5\C4\D7\D6\CC\E5\B8ߡ\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_GETTEXTSIZE_EX_CB_FN)(HI_VOID* pUserData, HI_UNF_CC_TEXT_S *pstText, HI_S32 *ps32Width, HI_S32 *ps32Heigth);


/**
\brief cc display callback function. CNcomment: cc\CF\D4ʾ\CA\FD\BEݻص\F7\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] u32UserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[in] pstCCdisplayParam parameter of display. CNcomment: cc\CF\D4ʾ\CA\FD\BEݽṹ\A1\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_DISPLAY_CB_FN)(HI_VOID* pUserData, HI_UNF_CC_DISPLAY_PARAM_S *pstCCdisplayParam);


/**
\brief cc get avplay pts callback function. CNcomment: cc\BB\F1ȡ\B5\B1ǰ\BD\DAĿ\B5\C4PTSֵ\B5Ļص\F7\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] pUserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[out] ps64CurrentPts current pts. CNcomment: \B4洢\B5\B1ǰPTSֵ\B5ı\E4\C1\BFָ\D5롣CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_GETPTS_CB_FN)(HI_VOID* pUserData, HI_S64 *ps64CurrentPts);

/**
\brief cc data blit callback function. CNcomment: cc\CA\FD\BEݰ\E1\D2ƻص\F7\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] pUserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[in] SrcRect source rect. CNcomment: \D0\E8Ҫ\B0\E1\D2Ƶ\C4ԭ\C7\F8\D3\F2\A1\A3CNend
\param[in] DstRect destination rect. CNcomment: \D0\E8Ҫ\B0\E1\D2Ƶ\C4Ŀ\B1\EA\C7\F8\D3\F2\A1\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_BLIT_CB_FN)(HI_VOID* pUserData, HI_UNF_CC_RECT_S *pstSrcRect, HI_UNF_CC_RECT_S *pstDstRect);

/**
\brief cc data blit callback function. CNcomment: cc vbi \CA\FD\BE\DD\CA\E4\B3\F6\BBص\F7\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in] pUserData user data. CNcomment: HI_UNF_CC_Create\B4\AB\C8\EB\B5\C4\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3CNend
\param[out] pstVBIOddDataField1 VBI data,odd field data. CNcomment: VBI\CA\FD\BEݽṹ,\C6泡\CA\FD\BEݡ\A3CNend
\param[out] pstVBIEvenDataField2 VBI data,even field data. CNcomment: VBI\CA\FD\BEݽṹ,ż\B3\A1\CA\FD\BEݡ\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_VBI_CB_FN)(HI_VOID* pUserData, HI_UNF_CC_VBI_DADA_S *pstVBIOddDataField1,HI_UNF_CC_VBI_DADA_S *pstVBIEvenDataField2);

/**
\brief output XDS packets in CC608. CNcomment: \CA\E4\B3\F6CC608\D6е\C4XDS\B0\FC\CA\FD\BEݡ\A3CNend
\attention \n
XDS packet is a third data service intended to supply program related and other information.
CNcomment: XDS\B0\FC\CAǵ\DA\C8\FD\B7\BD\CA\FD\BEݷ\FE\CE\F1\A3\AC\D3\C3\C0\B4\CCṩ\BD\DAĿ\BB\F2\D5\DF\C6\E4\CB\FB\CF\E0\B9\D8\D0\C5Ϣ\A1\A3CNend
\param[in] u8XDSClass XDS class. CNcomment: XDS\B5ķ\D6\C0ࡣCNend
\param[in] u8XDSPacketType  XDS packet type. CNcomment: XDS\CA\FD\BEݰ\FC\B5\C4\C0\E0\D0͡\A3CNend
\param[in] pu8Data  XDS data. CNcomment: XDS\CA\FD\BEݡ\A3CNend
\param[in] u8DataLen  XDS data length. CNcomment: XDS\CA\FD\BEݳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\see \n
Decoding of XDS packet data, see sample/cc/sample_cc_xds.c.
CNcomment: XDS\CA\FD\BEݰ\FC\B5Ľ\E2\CE\F6\A3\AC\C7\EB\B2ο\B4sdk\B0\FCsample/cc/sample_cc_xds.c\A1\A3CNend
*/
typedef HI_S32 (*HI_UNF_CC_XDS_CB_FN)(HI_U8 u8XDSClass, HI_U8 u8XDSPacketType, HI_U8 *pu8Data, HI_U8 u8DataLen);


/**user data in MPEG*//** CNcomment:MPEG\D6е\C4USERDATA\CA\FD\BE\DD */
typedef struct hiUNF_CC_USERDATA_S
{
    HI_U8       *pu8userdata;  /**<cc user data in mpeg *//**<CNcomment:mpeg\CA\D3Ƶ֡\D6е\C4cc\D3û\A7\CA\FD\BE\DD */
    HI_U32      u32dataLen;    /**<cc user data length *//**<CNcomment:cc\CA\FD\BEݳ\A4\B6\C8 */
    HI_BOOL     bTopFieldFirst;/**<cc top field first flag *//**<CNcomment:cc\B6\A5\B3\A1\D3\C5\CFȱ\EA\BC\C7 */
} HI_UNF_CC_USERDATA_S;

/**CC608 config param *//** CNcomment:CC608 \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
/**CC608 just support 8 stardard colors*//**CNcomment:CC608ֻ֧\B3\D68\D6ֱ\EA׼\D1\D5ɫ*/
typedef struct hiUNF_CC_608_CONFIGPARAM_S
{
    HI_UNF_CC_608_DATATYPE_E    enCC608DataType;        /**<CC608 data type *//**<CNcomment:\C5\E4\D6\C3cc608\CA\FD\BE\DD\C0\E0\D0\CD */
    HI_U32                      u32CC608TextColor;      /**<CC608 text color *//**<CNcomment:\C5\E4\D6\C3cc608\D7\D6\CC\E5\D1\D5ɫ */
    HI_UNF_CC_OPACITY_E         enCC608TextOpac;        /**<CC608 text opacity *//**<CNcomment:\C5\E4\D6\C3cc608\D7\D6\CC\E5͸\C3\F7\B6\C8 */
    HI_U32                      u32CC608BgColor;        /**<CC608 background color *//**<CNcomment:\C5\E4\D6\C3cc608\B1\B3\BE\B0ɫ */
    HI_UNF_CC_OPACITY_E         enCC608BgOpac;          /**<CC608 background opacity *//**<CNcomment:\C5\E4\D6\C3cc608\B1\B3\BE\B0͸\C3\F7\B6\C8 */
    HI_UNF_CC_FONTSTYLE_E       enCC608FontStyle;       /**<CC608 font style *//**<CNcomment:\C5\E4\D6\C3cc608\D7\D6\CC\E5\B7\E7\B8\F1 */
    HI_UNF_CC_DF_E              enCC608DispFormat;      /**<CC608 display format of caption display screen *//**<CNcomment:\C5\E4\D6\C3cc608\CF\D4ʾģʽ */
    HI_BOOL                     bLeadingTailingSpace;   /**<CC608 leading/tailing space flag*//**<CNcomment: \CAǷ\F1\CF\D4ʾleading/tailing space*/
} HI_UNF_CC_608_CONFIGPARAM_S;

/**CC708 config param *//** CNcomment:CC708 \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
/**CC708 color specification CEA-708-B-1999.pdf section 9.20 Color Representation*//**CNcomment:CC708\D1\D5ɫ˵\C3\F7\C7\EB\B2ο\BCЭ\D2\E9CEA-708-B-1999.pdf 9.20 \D1\D5ɫ\B3\CA\CF\D6 \D5½\DA*/
/**The specification does not define the specific color component, using the following component values in our version*/
/**Э\D2\E9\D6\D0û\D3ж\A8\D2\E5\BE\DF\CC\E5\B5\C4\D1\D5ɫ\B7\D6\C1\BF\A3\AC\D4\DA\CE\D2\C3ǰ汾\D6в\C9\D3\C3\C8\E7\CF·\D6\C1\BFֵ*/
/**CC708 support 64 colors.one of RGB color components can be 0x00,0x5f,0xaf,0xff*//**CNcomment:CC708֧\B3\D664\D6\D6\D1\D5ɫ,һ\B8\F6RGB\B7\D6\C1\BF\C4\DCȡ\B5\C4ֵ\D3\D00x00,0x5f,0xaf,0xff\B9\B24\D6\D6*/
/** 0x    FF          FF          FF          FF*/       /**CNcomment: 0x FF     FF         FF          FF*/
/**    reserve    red value   green value  blue value*/  /**              \B1\A3\C1\F4   \BA\ECɫ\B7\D6\C1\BF   \C2\CCɫ\B7\D6\C1\BF    \C0\B6ɫ\B7\D6\C1\BF*/
typedef struct hiUNF_CC_708_CONFIGPARAM_S
{
    HI_UNF_CC_708_SERVICE_NUM_E enCC708ServiceNum;      /**<CC708 service number *//**<CNcomment:\C5\E4\D6\C3cc708\B7\FE\CE\F1ͨ\B5\C0\BA\C5 */
    HI_UNF_CC_FONTNAME_E        enCC708FontName;        /**<CC708 font name *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5 */
    HI_UNF_CC_FONTSTYLE_E       enCC708FontStyle;       /**<CC708 font style *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5\B7\E7\B8\F1 */
    HI_UNF_CC_FONTSIZE_E        enCC708FontSize;        /**<CC708 font size *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5\B4\F3С */
    HI_U32                      u32CC708TextColor;      /**<CC708 text color *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5\D1\D5ɫ */
    HI_UNF_CC_OPACITY_E         enCC708TextOpac;        /**<CC708 text opacity *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5͸\C3\F7\B6\C8 */
    HI_U32                      u32CC708BgColor;        /**<CC708 background color *//**<CNcomment:\C5\E4\D6\C3cc708\B1\B3\BE\B0\D1\D5ɫ */
    HI_UNF_CC_OPACITY_E         enCC708BgOpac;          /**<CC708 background opacity *//**<CNcomment:\C5\E4\D6\C3cc708\B1\B3\BE\B0͸\C3\F7\B6\C8 */
    HI_U32                      u32CC708WinColor;       /**<CC708 window color *//**<CNcomment:\C5\E4\D6\C3cc708\B4\B0\BF\DA\D1\D5ɫ */
    HI_UNF_CC_OPACITY_E         enCC708WinOpac;         /**<CC708 window opacity *//**<CNcomment:\C5\E4\D6\C3cc708\B4\B0\BF\DA͸\C3\F7\B6\C8 */
    HI_UNF_CC_EdgeType_E        enCC708TextEdgeType;    /**<CC708 text egde type *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5\B1\DFԵ\C0\E0\D0\CD */
    HI_U32                      u32CC708TextEdgeColor;  /**<CC708 text edge color *//**<CNcomment:\C5\E4\D6\C3cc708\D7\D6\CC\E5\B1\DFԵ\D1\D5ɫ */
    HI_UNF_CC_DF_E              enCC708DispFormat;      /**<CC708 display format of caption display screen *//**<CNcomment:\C5\E4\D6\C3cc708\CF\D4ʾģʽ */
} HI_UNF_CC_708_CONFIGPARAM_S;

/**ARIB CC config param *//** CNcomment:ARIB CC \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
typedef struct hiUNF_CC_ARIB_CONFIGPARAM_S
{
    HI_U32      u32BufferSize;   /**<size of buffer which used to cache pes data,Recommends its value is 64K ~ 512K.note:This value can only be set when created,does not support dynamic setting*/
                                 /**<CNcomment:\BB\BA\B4\E6PES\CA\FD\BEݵĻ\BA\B3\E5\C7\F8\B4\F3С\A3\ACȡֵΪ64k~512K\A1\A3ע\D2\E2:\D5\E2\B8\F6ֵֻ\C4\DC\D4ڴ\B4\BD\A8ʱ\C9\E8\D6ã\AC\B2\BB֧\B3ֶ\AF̬\C9\E8\D6\C3*/
} HI_UNF_CC_ARIB_CONFIGPARAM_S;

/**CC data attribution *//** CNcomment:CC\CA\F4\D0\D4\D0\C5Ϣ */
typedef struct hiUNF_CC_ATTR_S
{
    HI_UNF_CC_DATA_TYPE_E enCCDataType;   /**<cc data type *//**<CNcomment:cc\CA\FD\BE\DD\C0\E0\D0\CD */
    union
    {
        HI_UNF_CC_608_CONFIGPARAM_S  stCC608ConfigParam;   /**<CC608 config param *//**<CNcomment:CC608 \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
        HI_UNF_CC_708_CONFIGPARAM_S  stCC708ConfigParam;   /**<CC708 config param *//**<CNcomment:CC708 \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
        HI_UNF_CC_ARIB_CONFIGPARAM_S stCCARIBConfigParam;  /**<ARIB CC config param *//**<CNcomment:ARIB CC \C5\E4\D6\C3\D0\C5Ϣ\B2\CE\CA\FD */
    } unCCConfig;
} HI_UNF_CC_ATTR_S;

/**CC instance param *//** CNcomment:\B4\B4\BD\A8ʵ\C0\FDʱ\D0\E8Ҫ\B5Ĳ\CE\CA\FD\D0\C5Ϣ */
typedef struct hiUNF_CC_PARAM_S
{
    HI_UNF_CC_ATTR_S             stCCAttr;           /**<cc attribution *//**<CNcomment:cc\CA\F4\D0\D4\D0\C5Ϣ */

    HI_UNF_CC_GETPTS_CB_FN       pfnCCGetPts;        /**<get current pts callback function *//**<CNcomment:\BB\F1ȡ\B5\B1ǰpts\B5Ļص\F7\BA\AF\CA\FD */
    HI_UNF_CC_DISPLAY_CB_FN      pfnCCDisplay;       /**<cc display callback function *//**<CNcomment:cc\CF\D4ʾ\B5Ļص\F7\BA\AF\CA\FD */
    HI_UNF_CC_GETTEXTSIZE_CB_FN  pfnCCGetTextSize;   /**<cc get text size callback function *//**<CNcomment:cc\D3\C3\D3ڻ\F1\B5\C3\D7\D6\CC\E5\B4\F3С(\BF\ED\B8\DF)\B5Ļص\F7\BA\AF\CA\FD  */
    HI_UNF_CC_GETTEXTSIZE_EX_CB_FN pfnCCGetTextSizeEx;
    HI_UNF_CC_BLIT_CB_FN         pfnBlit;            /**<cc data blit callback function *//**<CNcomment:\D3\C3\D3\DAcc\CA\FD\BE\DD\D4\DA\C6\C1Ļ\C9ϰ\E1\D2ƵĻص\F7\BA\AF\CA\FD */
    HI_UNF_CC_VBI_CB_FN          pfnVBIOutput;       /**<output VBI data callback function *//**<CNcomment:\CA\E4\B3\F6VBI\CA\FD\BEݻص\F7\BA\AF\CA\FD */
    HI_UNF_CC_XDS_CB_FN          pfnXDSOutput;       /**<output XDS packets function *//**<CNcomment:\CA\E4\B3\F6CC608\D6е\C4XDS\B0\FC\CA\FD\BE\DD */
    HI_VOID*                     pUserData;        /**<user data,used in callback function *//**<CNcomment:\D3û\A7˽\D3\D0\CA\FD\BEݣ\AC\D3\C3\D3ڻص\F7\BA\AF\CA\FD */
} HI_UNF_CC_PARAM_S;

/*ARIB CC info node*//** CNcomment:arib cc\D7\D6Ļ\D0\C5Ϣ\BDڵ\E3 */
typedef struct hiUNF_CC_ARIB_INFONODE_S
{
    HI_U8 u8LanguageTag;                   /**<identification of language*//**<CNcomment:\D7\D6Ļ\D3\EF\D1Ա\EA\BC\C7 */
    HI_UNF_CC_ARIB_DMF_E    enCCAribDMF;   /**<display mode *//**<CNcomment:\CF\D4ʾģʽ */
    HI_CHAR    acISO639LanguageCode[4];    /**<language code *//**<CNcomment:\D7\D6Ļ\D3\EF\D1Դ\FA\C2\EB */
    HI_UNF_CC_ARIB_DF_E enCCAribDF;        /**<display format *//**<CNcomment:\CF\D4ʾ\B7\BDʽ */
    HI_UNF_CC_ARIB_TCS_E enCCAribTCS;         /**<character coding *//**<CNcomment:\D7ַ\FB\B1\E0\C2\EB */
    HI_UNF_CC_ARIB_ROLLUP_E enCCAribRollup;    /**<roll-up mode *//**<CNcomment:roll-upģʽ */
}HI_UNF_CC_ARIB_INFONODE_S;

/*ARIB CC info struct*//** CNcomment:arib cc\D7\D6Ļ\D0\C5Ϣ\BDṹ\CC\E5 */
typedef struct hiUNF_CC_ARIB_INFO_S
{
    HI_UNF_CC_ARIB_TMD_E enCCAribTMD;   /**<time control mode*//**<CNcomment:ʱ\BC\E4\BF\D8\D6\C6ģʽ */
    HI_U32 u32NumLanguage;       /**<number of languages *//**<CNcomment:\D7\D6Ļ\D3\EF\D1Ը\F6\CA\FD */
    HI_UNF_CC_ARIB_INFONODE_S stCCAribInfonode[ARIBCC_MAX_LANGUAGE];     /**<array of arib cc info *//**<CNcomment:arib cc\D7\D6Ļ\D0\C5Ϣ\CA\FD\D7\E9 */
}HI_UNF_CC_ARIB_INFO_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API Declaration *****************************/
/**
\brief Initialize cc module. CNcomment: \B3\F5ʼ\BB\AFCCģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\retval ::HI_SUCCESS initialize success. CNcomment: \B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE initialize failure. CNcomment: \B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Init(HI_VOID);

/**
\brief DeInitialize cc module. CNcomment: ȥ\B3\F5ʼ\BB\AFCCģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\retval ::HI_SUCCESS deinitialize success. CNcomment: ȥ\B3\F5ʼ\BB\AF\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE deinitialize failure. CNcomment: ȥ\B3\F5ʼ\BB\AFʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_DeInit(HI_VOID);

/**
\brief Get default attribution in cc module. CNcomment: \BB\F1ȡCCģ\BF\E9\B5\C4Ĭ\C8\CF\CA\F4\D0\D4ֵ\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_GetDefaultAttr(HI_UNF_CC_ATTR_S *pstDefaultAttr);

/**
\brief open cc module. CNcomment: \B4\B4\BD\A8ccʵ\C0\FD\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  pstAttr  cc attribution. CNcomment: \B4\B4\BD\A8ʱ\B4\AB\C8\EB\B5Ľ\E2\C2\EB\C6\F7\CA\F4\D0ԡ\A3CNend
\param[out]  phCC  cc handle. CNcomment: ccģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B4\B4\BD\A8\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: \B4\B4\BD\A8ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Create(HI_UNF_CC_PARAM_S *pstCCParam, HI_HANDLE *phCC);

/**
\brief close cc module. CNcomment: \CF\FA\BB\D9ccʵ\C0\FD\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \CF\FA\BBٳɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: \CF\FA\BB\D9ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Destroy(HI_HANDLE hCC);

/**
\brief start cc module. CNcomment: \BF\AAʼccģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Start(HI_HANDLE hCC);

/**
\brief stop cc module. CNcomment: \BD\E1\CA\F8ccģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Stop(HI_HANDLE hCC);

/**
\brief reset cc module. CNcomment: \B8\B4λccģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_Reset(HI_HANDLE hCC);

/**
\brief inject mpeg userdata to  cc module. CNcomment: ע\C8\EBmpeg\D3û\A7\CA\FD\BEݵ\BDccģ\BF顣CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\param[in]  pstUserData  cc userdata structure used in inject cc data. CNcomment: \D3û\A7\CA\FD\BEݽṹ\CC塣CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_InjectUserData(HI_HANDLE hCC, HI_UNF_CC_USERDATA_S *pstUserData);

/**
\brief inject cc pes data to cc module. CNcomment: ע\C8\EBpes\CA\FD\BEݵ\BDccģ\BF\E9(\D4ݲ\BB֧\B3\D6)\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment:ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\param[in]  pu8PesData  pes data address. CNcomment: pes\CA\FD\BE\DD\CA׵\D8ַ\A1\A3CNend
\param[in]  u32DataLen  pes data length. CNcomment: pes\CA\FD\BEݳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_InjectPESData(HI_HANDLE hCC, HI_U8 *pu8PesData, HI_U32 u32DataLen);

/**
\brief get cc attribution. CNcomment: \BB\F1ȡcc\CA\F4\D0\D4\D0\C5Ϣ\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\param[out]  pstCCAttr  cc attribution structure. CNcomment: \CA\F4\D0\D4\D0\C5Ϣ\BDṹ\CC塣CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_GetAttr(HI_HANDLE hCC, HI_UNF_CC_ATTR_S *pstCCAttr);

/**
\brief set cc attribution. CNcomment:\C9\E8\D6\C3cc\CA\F4\D0\D4\D0\C5Ϣ\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  cc handle. CNcomment. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\param[in]  pstCCAttr  cc attribution structure. CNcomment:\CA\F4\D0\D4\D0\C5Ϣ\BDṹ\CC塣CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_SetAttr(HI_HANDLE hCC, HI_UNF_CC_ATTR_S *pstCCAttr);


/**
\brief get cc arib info. CNcomment: \BB\F1ȡarib cc\D7\D6Ļ\D0\C5Ϣ\A1\A3CNend
\attention \n
none. CNcomment: \CEޡ\A3CNend
\param[in]  hCC  arib cc handle. CNcomment: ģ\BF\E9\BE\E4\B1\FA\A1\A3CNend
\param[out]  pstCCAttr  arib cc info structure. CNcomment:arib cc\D7\D6Ļ\D0\C5Ϣ\BDṹ\CC塣CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ\B0ܡ\A3CNend
\see \n
none. CNcomment: \CEޡ\A3CNend
*/
HI_S32 HI_UNF_CC_GetARIBCCInfo(HI_HANDLE hCC,HI_UNF_CC_ARIB_INFO_S *pstCCAribInfo);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
