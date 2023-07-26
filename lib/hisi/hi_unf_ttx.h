/******************************************************************************

*
* Copyright (C) 2014 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
* This program is confidential and proprietary to Hisilicon  Technologies Co., Ltd. (Hisilicon),
*  and may not be copied, reproduced, modified, disclosed to others, published or used, in
* whole or in part, without the express prior written permission of Hisilicon.
*

******************************************************************************
  File Name     : hi_unf_ttx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2011/10/20
  Description   : Teletext UNF header file
  History       :
  1.Date        : 2011/10/20
    Author      : sdk
    Modification: Created file

******************************************************************************/
#ifndef __HI_UNF_TTX_H__
#define __HI_UNF_TTX_H__

#include "hi_type.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif  /* End of #ifdef __cplusplus */

/********************************Structure Definition********************************/
/** \addtogroup      Teletext */
/** @{ */  /** <!-- [Teletext] */

/** Teletext max line in page *//** CNcomment:teletextҳ\B5\C4\D7\EE\B4\F3\D0\D0\CA\FD */
#define HI_UNF_TTX_MAX_LINES (32)
/** Teletext line size */ /** CNcomment:teletext\D0еĳ\A4\B6\C8 */
#define HI_UNF_TTX_LINE_SIZE (46)

/** Teletext key support list *//** CNcomment:Ĭ\C8\CF֧\B3ֵĽ\BB\BB\A5\B7\BDʽ */
typedef enum hiUNF_TTX_KEY_E
{
    HI_UNF_TTX_KEY_0,
    HI_UNF_TTX_KEY_1,
    HI_UNF_TTX_KEY_2,
    HI_UNF_TTX_KEY_3,
    HI_UNF_TTX_KEY_4,
    HI_UNF_TTX_KEY_5,
    HI_UNF_TTX_KEY_6,
    HI_UNF_TTX_KEY_7,
    HI_UNF_TTX_KEY_8,
    HI_UNF_TTX_KEY_9, /**<Three number key to open a specified page *//**<CNcomment:\C8\FD\B8\F6\CA\FD\D7ּ\FC\B4\F2\BF\AAָ\B6\A8ҳ */
    HI_UNF_TTX_KEY_PREVIOUS_PAGE, /**<Previous page *//**<CNcomment:\C9\CFһҳ */
    HI_UNF_TTX_KEY_NEXT_PAGE, /**<Next page *//**<CNcomment:\CF\C2һҳ */
    HI_UNF_TTX_KEY_PREVIOUS_SUBPAGE, /**<Previous subpage *//**<CNcomment:\C9\CFһ \D7\D3ҳ */
    HI_UNF_TTX_KEY_NEXT_SUBPAGE, /**<Next subpage *//**<CNcomment:\CF\C2һ \D7\D3ҳ */
    HI_UNF_TTX_KEY_PREVIOUS_MAGAZINE, /**<Previous magazine *//**<CNcomment:\C9\CFһ\D4\D3־ */
    HI_UNF_TTX_KEY_NEXT_MAGAZINE, /**<Next magazine *//**<CNcomment:\CF\C2һ\D4\D3־ */
    HI_UNF_TTX_KEY_RED,    /**<First link in packet X/27, if inexistence, Show first valid page*//**<CNcomment:X/27 \B0\FC\D6еĵ\DAһ\B8\F6\C1\B4\BDӣ\AC\CE\DEX/27\D4\F2\CF\D4ʾ\D7\EE\BD\FC\D3\D0Чҳ */
    HI_UNF_TTX_KEY_GREEN,  /**<Second  link in packet X/27, if inexistence, Show second valid page*//**<CNcomment:X/27 \B0\FC\D6еĵڶ\FE\B8\F6\C1\B4\BDӣ\AC\CE\DEX/27\D4\F2\CF\D4ʾ\B5ڶ\FE\D3\D0Чҳ */
    HI_UNF_TTX_KEY_YELLOW, /**<Third  link in packet X/27, if inexistence, Show third valid page*//**<CNcomment:X/27 \B0\FC\D6еĵ\DA\C8\FD\B8\F6\C1\B4\BDӣ\AC\CE\DEX/27\D4\F2\CF\D4ʾ\B5\DA\C8\FD\D3\D0Чҳ */
    HI_UNF_TTX_KEY_CYAN,   /**<Fourth  link in packet X/27, if inexistence, Show fourth valid page. you can replace it with blue key if no cyan key on the user's control unit*/
                           /**<CNcomment:X/27 \B0\FC\D6еĵ\DA\CBĸ\F6\C1\B4\BDӣ\AC\CE\DEX/27\D4\F2\CF\D4ʾ\B5\DA\CB\C4\D3\D0Чҳ\A1\A3\C8\E7\B9\FBң\BF\D8\C6\F7\C9\CFû\D3\D0CYAN\BC\FC\A3\AC\C4\E3\BF\C9\D2\D4\D3\C3BLUE\BC\FC\C0\B4\CC\E6\B4\FA\A1\A3*/
    HI_UNF_TTX_KEY_INDEX,  /**<Sixth  link in packet X/27, if inexistence, Show index  page*//**<CNcomment:X/27 \B0\FC\D6еĵ\DA\C1\F9\B8\F6\C1\B4\BDӣ\AC\CE\DEX/27\D4\F2ָ\CF\F2\C6\F0ʼҳ */
    HI_UNF_TTX_KEY_REVEAL, /**<Reveal or hide concealed  information *//**<CNcomment:\CF\D4ʾ/\D2\FE\B2\D8conceal \D0\C5Ϣ */
    HI_UNF_TTX_KEY_HOLD,   /**<Switch between hold and resume ttx play  *//**<CNcomment:\D4\DDͣͼ\CEĲ\A5\B7\C5/\BBָ\B4ͼ\CEĲ\A5\B7\C5\C7л\BB */
    HI_UNF_TTX_KEY_MIX,    /**<Switch  between  transparent and nontransparent  background *//**<CNcomment:Teletext\B1\B3\BE\B0͸\C3\F7/\B2\BB͸\C3\F7\C7л\BB */
    HI_UNF_TTX_KEY_UPDATE, /**<Update current page*//**<CNcomment:\B8\FC\D0µ\B1ǰҳ */
    HI_UNF_TTX_KEY_ZOOM,   /**<Send this cmd sevral times to display the upper,then the lower part of the screen and then return to the normal size teletext page*/
                           /**<CNcomment:ͨ\B9\FD\C1\AC\D0\F8\B7\A2\CBʹ\CB\C3\FC\C1\EE\D2\C0\B4\CE\CF\D4ʾteletextҳ\C3\E6\B5\C4\C9ϰ벿\B7֡\A2\CF°벿\B7֡\A2ȫ\B2\BF */
    HI_UNF_TTX_KEY_SUBPAGE,/**<switch from page num ipunt mode to subpage input mode*//**<CNcomment:\CA\E4\C8\EBҳ\BA\C5\CA\E4\C8\EBģʽת\B5\BDsubpage\CA\E4\C8\EBģʽ */
    HI_UNF_TTX_KEY_CANCEL, /**<Hide or display current page except page number, currently not support*//**<CNcomment:\D2\FE\B2ػ\F2\D5\DF\CF\D4ʾ\B3\FD\C1\CBҳ\BA\C5\CD\E2\B5ĵ\B1ǰҳ\C4\DA\C8\DD ,\B5\B1ǰ\D4ݲ\BB֧\B3\D6*/
    HI_UNF_TTX_KEY_TIME,   /**<Hide or display current time*//**<CNcomment:\D2\FE\B2ػ\F2\D5\DF\CF\D4ʾ\B5\B1ǰʱ\BC\E4*/
    HI_UNF_TTX_KEY_BUTT    /**<Invalid key*//**<CNcomment:\CE\DEЧ\B5İ\B4\BC\FC */
} HI_UNF_TTX_KEY_E;

/** Teletext output type *//** CNcomment:Teletext\CA\E4\B3\F6\B5\C4\C0\E0\D0\CD */
typedef enum hiUNF_TTX_OUTPUT_E
{
    HI_UNF_TTX_VBI_OUTPUT,  /**<Only VBI output *//**<CNcomment:VBI \CA\E4\B3\F6 */
    HI_UNF_TTX_OSD_OUTPUT,  /**<Only OSD output *//**<CNcomment:OSD \CA\E4\B3\F6 */
    HI_UNF_TTX_DUAL_OUTPUT, /**<VBI OSD dual output *//**<CNcomment:VBI\BA\CDOSDͬʱ\CA\E4\B3\F6 */
    HI_UNF_TTX_BUTT         /**<Invalid output type *//**<CNcomment:\CE\DEЧ\CA\E4\B3\F6\C0\E0\D0\CD */
} HI_UNF_TTX_OUTPUT_E;

/** Teletext type *//** CNcomment:Teletext\B5\C4\C0\E0\D0\CD */
typedef enum hiUNF_TTX_TYPE_E
{
    HI_UNF_TTX_INITTTX = 1, /**<Initial Teletext page *//**<CNcomment:Teletext ͼ\CE\C4 */
    HI_UNF_TTX_TTXSUBT = 2, /**<Teletext subtitle page *//**<CNcomment:Teletext \D7\D6Ļ */
    HI_UNF_TTX_ADDINFO = 3, /**<Nonsupport for the moment <Additional information page *//**<CNcomment:\D4ݲ\BB֧\B3ָ\BD\BC\D3\D0\C5Ϣҳ */
    HI_UNF_TTX_PROGSCD = 4, /**<Nonsupport for the moment <Programme schedule page *//**<CNcomment:\D4ݲ\BB֧\B3ֽ\DAĿָ\C4\CFҳ */
    HI_UNF_TTX_TTXSUBT_HIP = 5, /**<Nonsupport for the moment <Teletext subtitle page for hearing impaired people *//**<CNcomment:\D4ݲ\BB֧\B3\D6Ϊ\CC\FD\C1\A6\D3\D0\D5ϰ\AD\B5\C4\C8\CB\C9\E8\D6õ\C4Teletext\D7\D6Ļҳ */
    HI_UNF_TTX_TTXSUBT_BUTT /**<Invalid teletext type *//**<CNcomment:\CE\DEЧ\B5\C4teletext \C0\E0\D0\CD */
} HI_UNF_TTX_TYPE_E;

/** Teletext page type *//** CNcomment:Teletextҳ\B5\C4\C0\E0\D0\CD */
typedef enum hiUNF_TTX_PAGE_TYPE_E
{
    HI_UNF_TTX_PAGE_CUR,   /**<Current reveal page *//**<CNcomment:\B5\B1ǰ\CF\D4ʾҳ */
    HI_UNF_TTX_PAGE_INDEX, /**<Initial Teletext page , if  packet X/30 exist, return index page in X/30, otherwise return default index page 100*/
                           /**<CNcomment:\B3\F5ʼҳ\A3\AC\C8\E7\B9\FB\D3\D0X/30\B0\FC\A3\AC\B7\B5\BB\D8X/30\B0\FCָ\B6\A8\B3\F5ʼҳ\A3\AC\B7\F1\D4򷵻\D8Ĭ\C8\CF\CA\D7ҳ100 */
    HI_UNF_TTX_PAGE_LINK1, /**<First link  in packet  X/27, if  inexistence, return first valid page*//**<CNcomment:X/27\B0\FC\D6е\DA1\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BBص\B1ǰҳ\D7\EE\BD\FC\D3\D0Чҳ */
    HI_UNF_TTX_PAGE_LINK2, /**<Second link  in packet  X/27, if inexistence, return second valid page*//**<CNcomment:X/27\B0\FC\D6е\DA2\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BBص\B1ǰҳ\B5ڶ\FE\D3\D0Чҳ */
    HI_UNF_TTX_PAGE_LINK3, /**<Third link  in packet  X/27, if  inexistence, return third valid page*//**<CNcomment:X/27\B0\FC\D6е\DA3\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BBص\B1ǰҳ\B5\DA\C8\FD\D3\D0Чҳ */
    HI_UNF_TTX_PAGE_LINK4, /**<Fourth  link  in packet  X/27, if  inexistence, return fourth valid page*//**<CNcomment:X/27\B0\FC\D6е\DA4\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BBص\B1ǰҳ\B5\DA\CB\C4\D3\D0Чҳ */
    HI_UNF_TTX_PAGE_LINK5, /**<Fifth link  in packet  X/27, if inexistence, return fifth valid page*//**<CNcomment:X/27\B0\FC\D6е\DA5\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BB\D80ff:3f7f */
    HI_UNF_TTX_PAGE_LINK6, /**<Sixth link  in packet  X/27, if inexistence, return Sixth valid page*//**<CNcomment:X/27\B0\FC\D6е\DA6\B8\F6\C1\B4\BDӣ\AC\C8\E7\B9\FBû\D3У\AC\B7\B5\BB\D80ff:3f7f */
    HI_UNF_TTX_PAGE_BUTT   /**<Invalid  page type *//**<CNcomment:\CE\DEЧҳ\C0\E0\D0\CD */
} HI_UNF_TTX_PAGE_TYPE_E;

/** Teletext user command type *//** CNcomment:Teletext\C3\FC\C1\EE\C0\E0\D0\CD */
typedef enum hiUNF_TTX_CMD_E
{
    HI_UNF_TTX_CMD_KEY,          /**<(HI_UNF_TTX_KEY_E *)Default alternation type, key *//**<CNcomment:\B0\B4\BC\FC\A3\ACĬ\C8ϵĽ\BB\BB\A5\B7\BDʽ */
    HI_UNF_TTX_CMD_OPENPAGE,     /**<(HI_UNF_TTX_PAGE_ADDR_S *) Open specified page*//**<CNcomment:(HI_UNF_TTX_PAGE_ADDR_S *)\B4\F2\BF\AAָ\B6\A8ҳ */
    HI_UNF_TTX_CMD_GETPAGEADDR,  /**<(HI_UNF_TTX_GETPAGEADDR_S *)Get current page , index page and  link page  address*//**<CNcomment:(HI_UNF_TTX_GETPAGEADDR_S *) \BB\F1ȡ\B5\B1ǰ\A1\A2\CA\D7ҳ\A1\A2\C1\B4\BD\D3ҳ\B5\D8ַ */
    HI_UNF_TTX_CMD_CHECKPAGE,    /**<(HI_UNF_TTX_CHECK_PARAM_S *) Check the specified page be received or not*//**<CNcomment:(HI_UNF_TTX_CHECK_PARAM_S *) \BC\EC\B2\E9\CAǷ\F1\CAյ\BD\B2\CE\CA\FD\D6\D0ָ\B6\A8\B5\C4ҳ */
    HI_UNF_TTX_CMD_SETREQUEST,   /**<(HI_UNF_TTX_REQUEST_RAWDATA_S *) Sets up a request for teletext raw data*//**<CNcomment:(HI_UNF_TTX_REQUEST_RAWDATA_S *) \C7\EB\C7\F3\BB\F1ȡteletext\D6е\C4ԭʼ\CA\FD\BE\DD */
    HI_UNF_TTX_CMD_CLEARREQUEST, /**<(HI_UNF_TTX_REQUEST_RAWDATA_S *) Clears a request set up by the HI_UNF_TTX_CMD_SETREQUEST*//**<CNcomment:(HI_UNF_TTX_REQUEST_RAWDATA_S *) \CAͷ\C5\D3\C9HI_UNF_TTX_CMD_SETREQUEST\B4\B4\BD\A8\B5\C4\CA\FD\BE\DD\C7\EB\C7\F3 */
    HI_UNF_TTX_CMD_BUTT          /**<Invalid command type *//**<CNcomment:\CE\DEЧ\C3\FC\C1\EE\C0\E0\D0\CD */
} HI_UNF_TTX_CMD_E;

/** G0 char set *//** CNcomment:G0\D7ַ\FB\BC\AF */
typedef  enum   hiUNF_TTX_G0SET_E
{
    HI_UNF_TTX_G0SET_LATIN,      /**<LATIN G0 Primary Set  *//**<CNcomment:LATIN G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_CYRILLIC_1, /**<CYRILLIC_1 G0 Primary Set *//**<CNcomment:CYRILLIC_1  G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_CYRILLIC_2, /**<CYRILLIC_2 G0 Primary Set*//**<CNcomment:CYRILLIC_2 G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_CYRILLIC_3, /**<CYRILLIC_3 G0 Primary Set*//**<CNcomment:CYRILLIC_3 G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_GREEK,      /**<GREEK G0 Primary Set*//**<CNcomment:GREEK G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_HEBREW,     /**<HEBREW G0 Primary Set*//**<CNcomment:HEBREW  G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_ARABIC,     /**<ARABIC G0 Primary Set*//**<CNcomment:ARABIC G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G0SET_BUTT        /**<Invalid G0 Primary Set *//**<CNcomment:\CE\DEЧG0\D6\F7\D7ַ\FB\BC\AF */
} HI_UNF_TTX_G0SET_E;

/** G2 char set *//** CNcomment:G2\D7ַ\FB\BC\AF */
typedef enum hiUNF_TTX_G2SET_E
{
    HI_UNF_TTX_G2SET_LATIN,    /**<LATIN G2 Set *//**<CNcomment:LATIN G2\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G2SET_CYRILLIC, /**<CYRILLIC G2 Set *//**<CNcomment:CYRILLIC G2\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G2SET_GREEK,    /**<GREEK G2 Set *//**<CNcomment:GREEK G2\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G2SET_ARABIC,   /**<ARABIC G2 Set *//**<CNcomment:ARABIC G2\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G2SET_BUTT      /**<Invalid G2 Set *//**<CNcomment:\CE\DEЧG2\D7ַ\FB\BC\AF */
}HI_UNF_TTX_G2SET_E;

/** Latin G0 National Option Sub-sets *//** CNcomment:Latin G0\B9\FA\BC\D2\D7ַ\FB\D7Ӽ\AF */
typedef enum hiUNF_TTX_NATION_SET_E
{
    HI_UNF_TTX_NATION_SET_PRIMARY,      /**<Latin G0 Primary nation sub set*//**<CNcomment:LATIN\D6\F7\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_CZECH,        /**<Latin czech slovak nation sub set*//**<CNcomment:LATIN czech/slovak\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_ENGLISH,      /**<Latin english nation sub set*//**<CNcomment:LATIN english\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_ESTONIAN,     /**<Latin estonian nation sub set*//**<CNcomment:LATIN estonian\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_FRENCH,       /**<Latin french nation sub set*//**<CNcomment:LATIN french\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_GERMAN,       /**<Latin german nation sub set*//**<CNcomment:LATIN german\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_ITALIAN,      /**<Latin italish nation sub set*//**<CNcomment:LATIN italish\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_LETTISH,      /**<Latin lettish lithuanian nation sub set*//**<CNcomment:LATIN lithuanian\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_POLISH,       /**<Latin polish nation sub set*//**<CNcomment:LATIN polish\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_PORTUGUESE,   /**<Latin portutuese spanish nation sub set*//**<CNcomment:LATIN portutuese/spanish\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_RUMANIAN,     /**<Latin rumanian nation sub set*//**<CNcomment:LATIN rumanian\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_SERBIAN,      /**<Latin serbian croatian slovenian nation sub set*//**<CNcomment:LATIN serbian/croatian/slovenian\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_SWEDISH,      /**<Latin swedish finnish nation sub set*//**<CNcomment:LATIN finnish\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_TURKISH,      /**<Latin turkish nation sub set*//**<CNcomment:LATIN turkish\B9\FA\BC\D2\D7Ӽ\AF*/
    HI_UNF_TTX_NATION_SET_BUTT          /**<Invalid nation sub Set *//**<CNcomment:\CE\DEЧ\B9\FA\BC\D2\D7ַ\FB\D7Ӽ\AF*/

}HI_UNF_TTX_NATION_SET_E;

/** Teletext char set *//** CNcomment:Teletext\D7ַ\FB\BC\AF */
typedef  enum   hiUNF_TTX_CHARSET_E
{
    HI_UNF_TTX_CHARSET_G0,  /**<G0  character set *//**<CNcomment:G0 \D7ַ\FB\BC\AF */
    HI_UNF_TTX_CHARSET_G1,  /**<G1  character set*//**<CNcomment:G1 \D7ַ\FB\BC\AF */
    HI_UNF_TTX_CHARSET_G2,  /**<G2  character set *//**<CNcomment:G2 \D7ַ\FB\BC\AF */
    HI_UNF_TTX_CHARSET_G3,  /**<G3  character set *//**<CNcomment:G3 \D7ַ\FB\BC\AF */
    HI_UNF_TTX_CHARSET_BUTT /**<Invalid  character set *//**<CNcomment:\CE\DEЧ\D7ַ\FB\BC\AF */
} HI_UNF_TTX_CHARSET_E;

/** DRCS character size *//** CNcomment:DRCS\D7ַ\FB\B4\F3С */
typedef enum hiUNF_TTX_DRCS_SIZE_E
{
    HI_UNF_TTX_DRCS_SIZE_NORMAL = 0,  /**<char size is 12*10*//**<CNcomment:\D7ַ\FB\B4\F3С12*10*/
    HI_UNF_TTX_DRCS_SIZE_SMALL = 1,   /**<char size is 6*5*//**<CNcomment:\D7ַ\FB\B4\F3С6*5*/
    HI_UNF_TTX_DRCS_SIZE_BUTT         /**<Invalid char size*//**<CNcomment:\CE\DEЧ\D7ַ\FB\B4\F3С*/
}HI_UNF_TTX_DRCS_SIZE_E;

typedef HI_U32 HI_UNF_TTX_COLOR;

/** Teletext page info *//** CNcomment:Teletextҳ\C7\F8\D3\F2\D0\C5Ϣ */
typedef struct hiUNF_TTX_PAGEAREA_S
{
    HI_U32 u32Row         : 8; /**<The origination  row  number of the area  *//**<CNcomment:\C7\F8\D3\F2\C6\F0ʼ\D0к\C5 */
    HI_U32 u32Column      : 8; /**<The origination  column  number of the area *//**<CNcomment:\C7\F8\D3\F2\C6\F0ʼ\C1к\C5 */
    HI_U32 u32RowCount    : 8; /**<The count of row the area covers *//**<CNcomment:\C7\F8\D3򸲸ǵ\C4\C1\D0\CA\FD */
    HI_U32 u32ColumnCount : 8; /**<The count of column  the area covers *//**<CNcomment:\C7\F8\D3򸲸ǵ\C4\D0\D0\CA\FD */
} HI_UNF_TTX_PAGEAREA_S;

/** Teletext char attribute *//** CNcomment:Teletext\D7ַ\FB\CA\F4\D0\D4 */
typedef  struct  hiUNF_TTX_CHARATTR_S
{
    HI_U32               u32Index    : 8; /**<Index of a char in a character set *//**<CNcomment:\D7ַ\FB\D4\DA\D7ַ\FB\BC\AF\D6е\C4\CB\F7\D2\FD */
    HI_BOOL              bContiguous : 1; /**<Contiguous mosaic char or not *//**<CNcomment:\CAǷ\F1Ϊ\C1\AC\D0\F8\C2\ED\C8\FC\BF˱\EA־ */
    HI_UNF_TTX_G0SET_E   enG0Set     : 3; /**<G0 Primary Set  , latin , arabic .... *//**<CNcomment:G0\D6\F7\D7ַ\FB\BC\AF */
    HI_UNF_TTX_G2SET_E   enG2Set     : 3;  /**<G2 set ,latin, cyrillic, greek, arabic*//**<CNcomment:G2\D6\F7\D7ַ\FB\BC\AF*/
    HI_UNF_TTX_CHARSET_E enCharSet   : 3; /**<Character set  , G0 ,  G1  ....*//**<CNcomment:\D7ַ\FB\BC\AF */
    HI_U32               u8NationSet : 6; /**<Latin National  subset,  English ,French,  German .... *//**<CNcomment:\B9\FA\BC\D2\D7ַ\FB\D7Ӽ\AF */
    HI_U32               u8Reserved  : 8; /**<Reserved *//**<CNcomment:Ԥ\C1\F4 */
} HI_UNF_TTX_CHARATTR_S;

/** The info of draw char *//** CNcomment:\BB\E6\D6\C6\D7ַ\FB\B5\C4\D0\C5Ϣ */
typedef struct hiUNF_TTX_DRAWCAHR_S
{
    HI_UNF_TTX_CHARATTR_S  * pstCharAttr;   /**<Character attribution, it can decide the position of a char in  a  font */
                                            /**<CNcomment:\D7ַ\FB\CA\F4\D0ԣ\AC\BE\F6\B6\A8\C1\CBһ\B8\F6\D7ַ\FB\D4\DA\CCض\A8\D7ֿ\E2\D6е\C4λ\D6\C3 */
    HI_UNF_TTX_PAGEAREA_S * pstPageArea;    /**<Area of character in page *//**<CNcomment:\D7ַ\FB\D4\DAҳ\C3\E6\C9ϵ\C4λ\D6\C3 */
    HI_UNF_TTX_COLOR        u32Foreground;  /**<Foreground color *//**<CNcomment:ǰ\BE\B0ɫ */
    HI_UNF_TTX_COLOR        u32Background;  /**<Background color *//**<CNcomment:\B1\B3\BE\B0ɫ */
} HI_UNF_TTX_DRAWCAHR_S;

/** The info of draw DRCS character *//** CNcomment:\BB\E6\D6\C6DRCS\D7ַ\FB\B5\C4\D0\C5Ϣ */
typedef struct hiUNF_TTX_DRAWDRCSCHAR_S
{
    HI_UNF_TTX_PAGEAREA_S  *pstPageArea;      /**<Area of character in page *//**<CNcomment:\D7ַ\FB\D4\DAҳ\C3\E6\C9ϵ\C4λ\D6\C3 */
    HI_UNF_TTX_COLOR       u32Background;     /**<Background color *//**<CNcomment:\B1\B3\BE\B0ɫ */
    HI_UNF_TTX_COLOR*      pu32DRCSColorInfo; /**<color info of DRCS char,which define the color value of  every pixel in a DRCS char*/
                                              /**<CNcomment:DRCS\D7ַ\FB\D1\D5ɫ\D0\C5Ϣ\A3\ACָ\B6\A8\C1\CBDRCS\D7ַ\FBÿ\B8\F6\CF\F1\CBص\C4\D1\D5ɫֵ*/
    HI_UNF_TTX_DRCS_SIZE_E enDRCSSize;        /**<size of DRCS char,normal is 12*10,and small is 6*5*//**<CNcomment:DRCS\D7ַ\FB\B4\F3С\A3\AC\D5\FD\B3\A3\CA\C712*10,С\D7ַ\FB\CA\C76*5 */
}HI_UNF_TTX_DRAWDRCSCHAR_S;


/** The filled area *//** CNcomment:\CC\EE\B3\E4\C7\F8\D3\F2 */
typedef struct hiUNF_TTX_FILLRECT_S
{
    HI_UNF_TTX_PAGEAREA_S * pstPageArea; /**<Destination rectangle  *//**<CNcomment:Ŀ\B5ľ\D8\D0\CE */
    HI_UNF_TTX_COLOR        u32Color;    /**<Color *//**<CNcomment:\D1\D5ɫֵ */
} HI_UNF_TTX_FILLRECT_S;

/** Refreshed layer *//** CNcomment:ˢ\D0\C2ͼ\B2\E3 */
typedef struct hiUNF_TTX_REFRESHLAYER_S
{
    HI_UNF_TTX_PAGEAREA_S * pstPageArea; /**<Destination rectangle  *//**<CNcomment:(HI_UNF_TTX_BUFFER_PARAM_S *) \B4\B4\BD\A8\BB\BA\B4\E6 */
} HI_UNF_TTX_REFRESHLAYER_S;

/** Teletext Buffer info *//** CNcomment:Teletext\BB\BA\B4\E6\D0\C5Ϣ */
typedef struct hiUNF_TTX_BUFFER_PARAM_S
{
    HI_U32 u32Row     : 8; /**<The row number of buffer page*//**<CNcomment:\BB\BA\B4\E6ҳ\C3\E6\B5\C4\D0\D0\CA\FD */
    HI_U32 u32Column  : 8; /**<The column  number of buffer page*//**<CNcomment:\BB\BA\B4\E6ҳ\C3\E6\B5\C4\C1\D0\CA\FD */
    HI_U32 u8Reserved : 16;/**<Reserved *//**<CNcomment:Ԥ\C1\F4 */
} HI_UNF_TTX_BUFFER_PARAM_S;

/** The set of callback cmd *//** CNcomment:\BBص\F7\C3\FC\C1\BA\CF */
typedef enum hiUNF_TTX_CB_E
{
    HI_UNF_TTX_CB_TTX_TO_APP_MSG, /**<Send message to GUI pthread *//**<CNcomment:\B7\A2\CBͻ\E6\D6\C6\CF\FBϢ\B5\BDGUI\CF߳\CC */
    HI_UNF_TTX_CB_APP_FILLRECT,   /**<(HI_UNF_TTX_FILLRECT_S *) Fill rectangle *//**<CNcomment:(HI_UNF_TTX_FILLRECT_S *)\BE\D8\D0\CE\CC\EE\B3\E4 */
    HI_UNF_TTX_CB_APP_DRAWCHAR,   /**<(HI_UNF_TTX_DRAWCAHR_S*)Select a char from a specified font and draw it  in specified rectangle of OSD by specified foreground and background */
                                  /**<CNcomment:(HI_UNF_TTX_DRAWCAHR_S*) \BB\E6\D6ƺ\AF\CA\FD\A3\AC\BD\ABָ\B6\A8\D7ַ\FB\D2\D4ָ\B6\A8\B5\C4ǰ\A1\A2\B1\B3\BE\B0ɫ\CF\D4ʾ\D4\DAOSD\B5\C4ָ\B6\A8\C7\F8\D3\F2 */
    HI_UNF_TTX_CB_APP_DRAWDRCSCHAR,/**<(HI_UNF_TTX_DRAWDRCSCHAR_S*)draw a DRCS char which specified by the color of every pixel*//**<CNcomment:\BB\E6\D6\C6DRCS\D7ַ\FB\A3\AC\D7ַ\FB\D3\C9ÿ\B8\F6\CF\F1\CBص\C4\D1\D5ɫֵȷ\B6\A8*/
    HI_UNF_TTX_CB_APP_REFRESH,    /**<(HI_UNF_TTX_REFRESHLAYER_S*) Refresh layer *//**<CNcomment:(HI_UNF_TTX_REFRESHLAYER_S*) ͼ\B2\E3ˢ\D0º\AF\CA\FD */
    HI_UNF_TTX_CB_CREATE_BUFF,    /**<(HI_UNF_TTX_BUFFER_PARAM_S *) Create buffer *//**<CNcomment:(HI_UNF_TTX_BUFFER_PARAM_S *) \B4\B4\BD\A8\BB\BA\B4\E6 */
    HI_UNF_TTX_CB_DESTROY_BUFF,   /**<Destroy buffer *//**<CNcomment:\CF\FA\BBٻ\BA\B4\E6 */
    HI_UNF_TTX_CB_GETPTS,         /**<(HI_S64 *) Get the PTS of the stream *//**<CNcomment:(HI_S64 *) \BB\F1ȡ\B5\B1ǰ\B2\A5\B7\C5\C2\EB\C1\F7\B5\C4PTS */
    HI_UNF_TTX_CB_BUTT            /**<Invalid callback type*//**<CNcomment:\CE\DEЧ\BBص\F7\C0\E0\D0\CD */
} HI_UNF_TTX_CB_E;

typedef enum hiUNF_TTX_PACKET_TYPE_E
{
    HI_UNF_TTX_PACKET_TYPE_PES,  /**<ETSI EN DVB 300472 teletext syntax data packets, including PES header information*//**<CNcomment:ETSI EN 300472 DVB teletext\D3﷨\CA\FD\BEݰ\FC,\B0\FC\C0\A8PESͷ\B2\BF\D0\C5Ϣ*/
    HI_UNF_TTX_PACKET_TYPE_RAW,   /**<ETSI EN DVB 300706 teletext syntax data packets, not including PES header information*//**<CNcomment:ETSI EN 300706 DVB teletext\D3﷨\CA\FD\BEݰ\FC,\B2\BB\B0\FC\C0\A8PESͷ\B2\BF\D0\C5Ϣ*/
    HI_UNF_TTX_PACKET_TYPE_BUTT,
}HI_UNF_TTX_PACKET_TYPE_E;

/** Callback function *//** CNcomment:\BBص\F7\BA\AF\CA\FD */
typedef HI_S32 (*HI_UNF_TTX_CB_FN)(HI_HANDLE hTTX, HI_UNF_TTX_CB_E enCB, HI_VOID *pvCBParam);


typedef enum hiUNF_TTX_LEVEL_E
{
    HI_UNF_TTX_LEVEL_1_5 = 0, /**<TTX Level 1.5 *//**<CNcomment:TTX 1.5 \BC\B6\B1\F0 */
    HI_UNF_TTX_LEVEL_2_5 = 1, /**<TTX Level 2.5*//**<CNcomment:TTX 2.5 \BC\B6\B1\F0 */
    HI_UNF_TTX_LEVEL_3_5 = 2, /**<TTX Level 3.5*//**<CNcomment:TTX 3.5 \BC\B6\B1\F0 */
    HI_UNF_TTX_LEVEL_BUTT     /**<Invalid TTX Level*//**<CNcomment:TTX \CE\DEЧ\BC\B6\B1\F0 */
}HI_UNF_TTX_LEVEL_E;

/** Teletext Init param *//** CNcomment:Teletext\B3\F5ʼ\BB\AF\B2\CE\CA\FD */
typedef struct hiUNF_TTX_INIT_PARA_S
{
    HI_U8 *pu8MemAddr;       /**<The address of memory, If  0, malloc the memory in the module, Otherwise malloced outside the module */
                             /**<CNcomment:\CA\FD\BEݷ\D6\C5\E4\B5\C4\C6\F0ʼ\B5\D8ַ\A3\AC\C8\E7\B9\FBΪ0\D4\F2\C4ڲ\BF\B7\D6\C5\E4 \A3\AC\B7\F1\D4\F2\D3\C9\CDⲿ\B7\D6\C5\E4\C4ڴ\E6 */
    HI_U32 u32MemSize;       /**<The size of memory,  If  0, the size decided in the module, Otherwise decided outside the module */
                             /**<CNcomment:\CA\FD\BEݷ\D6\C5\E4\B5Ĵ\F3С\A3\AC\C8\E7\B9\FBΪ0 \A3\AC\D3\C9\C4ڲ\BF\BE\F6\B6\A8\A3\AC\B7\F1\D4\F2\B4\F3С\D3\C9\CDⲿ\BE\F6\B6\A8 */

    HI_UNF_TTX_LEVEL_E  enTtxLevel; /**<TTX level*//**<CNcomment:TTX \BC\B6\B1\F0 */

    HI_UNF_TTX_CB_FN pfnCB;  /**<Callback function *//**<CNcomment:\BBص\F7\BA\AF\CA\FD */
    HI_BOOL          bFlash; /**<Permit flash or not *//**<CNcomment:\CAǷ\F1\BF\AA\C6\F4\C9\C1˸\B9\A6\C4\DC */
    HI_BOOL          bNavigation; /**<Permit navigation bar *//**<CNcomment:\CAǷ\F1\CCṩ\B5\BC\BA\BD\CC\F5 */
} HI_UNF_TTX_INIT_PARA_S;

/** Teletext page address *//** CNcomment:Teletextҳ\CA\F4\D0\D4 */
typedef struct hiUNF_TTX_PAGE_ADDR_S
{
    HI_U8  u8MagazineNum;  /**<Magazine number *//**<CNcomment:\D4\D3־\BA\C5 */
    HI_U8  u8PageNum;      /**<Page number *//**<CNcomment:ҳ\BA\C5 */
    HI_U16 u16PageSubCode; /**<Page sub-code *//**<CNcomment:\D7\D3ҳ\BA\C5 */
} HI_UNF_TTX_PAGE_ADDR_S;

/** Teletext content param *//** CNcomment:Teletext\C4\DA\C8ݲ\CE\CA\FD */
typedef struct hiUNF_TTX_CONTENT_PARA_S
{
    HI_UNF_TTX_TYPE_E      enType; /**<Teletext content type *//**<CNcomment:Teletext\C4\DA\C8\DD\C0\E0\D0\CD */
    HI_U32                         u32ISO639LanCode;/**<teletext iso639  language code*//**<CNcomment:Teletext  iso639\D3\EF\D1\D4*/
    HI_UNF_TTX_PAGE_ADDR_S stInitPgAddr; /**<Init page address, if Magazine number or Page number be equal to 0xFF,set to 100th page.sub-page numbet default  0*/
                                         /**<CNcomment:\B3\F5ʼҳ\B5\D8ַ\A3\AC\C8\E7\B9\FB\D4\D3־\BAŻ\F2ҳ\BA\C5Ϊ0xff\A3\AC\D4\F2\C9\E8\D6\C3Ϊ\B5\DA100ҳ\A1\A3\D7\D3ҳ\BA\C5Ĭ\C8\CFΪ0 */
} HI_UNF_TTX_CONTENT_PARA_S;

/** Teletext checked param *//** CNcomment:Teletext\BC\EC\B2\E2\B2\CE\CA\FD */
typedef struct hiUNF_TTX_CHECK_PARAM_S
{
    HI_UNF_TTX_PAGE_ADDR_S stPageAddr; /**<page address*//**<CNcomment:ҳ\B5\D8ַ  */
    HI_BOOL                bSucceed;   /**<success or failure*//**<CNcomment:\CAǷ\F1\B3ɹ\A6 */
} HI_UNF_TTX_CHECK_PARAM_S;

/** Get page address*//** CNcomment:\BB\F1ȡTeletextҳ */
typedef struct hiUNF_TTX_GETPAGEADDR_S
{
    HI_UNF_TTX_PAGE_TYPE_E enPageType; /**<page type *//**<CNcomment:ҳ\C0\E0\D0\CD */
    HI_UNF_TTX_PAGE_ADDR_S stPageAddr; /**<page address *//**<CNcomment:ҳ\B5\D8ַ*/
} HI_UNF_TTX_GETPAGEADDR_S;

/** Teletext raw data*//** CNcomment:ttxԭʼ\CA\FD\BE\DD */
typedef struct hiUNF_TTX_RAWDATA_S
{
    HI_U32 u32ValidLines; /**<bit-field lines  0..31 *//**<CNcomment:\D3\D0Чλ\B1\EAʶ */
    HI_U8  au8Lines[HI_UNF_TTX_MAX_LINES][HI_UNF_TTX_LINE_SIZE]; /**<line data *//**<CNcomment:ttx\D0\D0\CA\FD\BE\DD */
} HI_UNF_TTX_RAWDATA_S;

/** Callback function in which notified raw data to consumer *//** CNcomment:\D3\C3\D3ڻش\ABttxԭʼ\CA\FD\BEݵĻص\F7\BA\AF\CA\FD */
typedef HI_S32 (*HI_UNF_TTX_REQUEST_CALLBACK_FN)(HI_UNF_TTX_RAWDATA_S *pstRawData);

/** Request teletext raw data*//** CNcomment:\C7\EB\C7\F3ttxԭʼ\CA\FD\BE\DD */
typedef struct hiUNF_TTX_REQUEST_RAWDATA_S
{
    HI_UNF_TTX_RAWDATA_S *pstRawData;  /**<raw data address*//**<CNcomment:ԭʼ\CA\FD\BEݵ\D8ַ */
    HI_UNF_TTX_REQUEST_CALLBACK_FN pfnRequestCallback; /**<Callback function *//**<CNcomment:\BBص\F7\BA\AF\CA\FD */
} HI_UNF_TTX_REQUEST_RAWDATA_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/********************************API declaration********************************/
/** \addtogroup      Teletext  */
/** @{ */  /** <!-- [Teletext] */

/**
\brief     Initializes  TTX  module. CNcomment:\B3\F5ʼ\BB\AFTTXģ\BF顣CNend
\attention \n
none.
\retval ::HI_SUCCESS     success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE     failure. CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_Init(HI_VOID);

/**
\brief  Deinitializes TTX module. CNcomment:ȥ\B3\F5ʼ\BB\AFTTXģ\BF顣CNend
\attention \n
none.
\retval ::HI_SUCCESS     success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE     failure. CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_DeInit(HI_VOID);

/**
\brief  Create a TTX instance, just support for a single  instance for the moment.  CNcomment:\B4\B4\BD\A8TTXʵ\C0\FD\A3\ACĿǰֻ֧\B3ֵ\A5ʵ\C0\FD\A1\A3CNend
\attention \n
After creating a instance  successfully, the instance  default  to be enable , decode and be
prepared to display teletext. Call  correspond interface to display teletext.
CNcomment:\B4\B4\BD\A8\B3ɹ\A6\BA\F3\D5\E2\B8\F6ʵ\C0\FDĬ\C8\CFenable\A3\AC\BD\E2\CE\F6\B2\A2׼\B1\B8\CF\D4ʾteletext\C4\DA\C8ݡ\A3\B5\F7\D3\C3\CF\E0Ӧ\B5\C4\CA\E4\B3\F6\BF\D8\D6ƽӿں\F3\CA\E4\B3\F6\A1\A3CNend
\param[in]  pstInitParam  Initialized  parameter. CNcomment:\B3\F5ʼ\BB\AF\B2\CE\CA\FD\A1\A3CNend
\param[out] phTTX         Teletext instance. CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS      success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE      failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_Create(HI_UNF_TTX_INIT_PARA_S* pstInitParam, HI_HANDLE* phTTX);

/**
\brief    Destory  a  teletext instance.  CNcomment:\CF\FA\BB\D9TTXʵ\C0\FD\A1\A3CNend
\attention \n
none.
\param[in] hTTX        Teletext instance. CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS   success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE   failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_Destroy(HI_HANDLE hTTX);

/**
\brief   Inject the teletext PES data . CNcomment:ע\C8\EBTeletext PES \CA\FD\BEݡ\A3CNend
\attention \n
none.
\param[in] hTTX    Teletext instance. CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8Data   Address of data. CNcomment:\CA\FD\BEݵ\D8ַ\A1\A3CNend
\param[in] u32DataSize  the length of data. CNcomment:\CA\FD\BEݳ\A4\B6ȡ\A3CNend
\retval ::HI_SUCCESS    success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE    failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_InjectData(HI_HANDLE hTTX, HI_U8 *pu8Data, HI_U32 u32DataSize);

/**
\brief   Reset data. CNcomment:\C7\E5\B3\FD\CAյ\BD\B5\C4\CA\FD\BEݡ\A3CNend
\attention \n
none.
\param[in] hTTX   Teletext instance. CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS    success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE    failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_ResetData(HI_HANDLE hTTX);

/**
\brief  Set the initial page address of teletext. CNcomment:\C9\E8\D6\C3Teletext\B5ĳ\F5ʼҳ\A1\A3CNend
\attention \n
none.
\param[in] hTTX   Teletext instance. CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\param[in] pstContentParam  context  parameter.  CNcomment:\C4\DA\C8ݲ\CE\CA\FD\A1\A3CNend
\retval ::HI_SUCCESS    success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE    failure. CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_SwitchContent (HI_HANDLE hTTX, HI_UNF_TTX_CONTENT_PARA_S* pstContentParam);

/**
\brief  All operation related to OSD. CNcomment:\BA\CDOSD\CF\E0\B9ص\C4\CB\F9\D3в\D9\D7\F7\A1\A3CNend
\attention \n
none.
\param[in] hTTX    Teletext instance.   CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\param[in] enMsgAction  Action of the message.  CNcomment:\CF\FBϢָ\B6\A8\B5Ķ\AF\D7\F7\A1\A3CNend
\retval ::HI_SUCCESS    success.   CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE    failure.   CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_Display(HI_HANDLE hTTX, HI_HANDLE hDispalyHandle);

/**
\brief   Enable  or disable teletext output, and set the type of output.
CNcomment:ʹ\C4ܻ\F2\B9ر\D5teletext\CA\E4\B3\F6\A1\A2\C9\E8\D6\C3\CA\E4\B3\F6\C0\E0\D0͡\A3CNend
\attention \n
 The parameter can be reset  time after time.   CNcomment: \BF\C9\D6ظ\B4\BD\F8\D0\D0\CA\E4\B3\F6\C9\E8\D6á\A3CNend
\param[in] hTTX        Teletext instance.     CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\param[in]enOutput     Output  type: OSD,VBI or OSD  VBI dual output.   CNcomment:\CA\E4\B3\F6\C0\E0\D0\CD:OSD / VBI /OSD-VBIͬʱ\CA\E4\B3\F6\A1\A3CNend
\param[in] bEnable       HI_TRUE: enable,  HI_FALSE: disable.   CNcomment:HI_TRUE: ʹ\C4ܣ\ACHI_FALSE: \B9رա\A3CNend
\retval ::HI_SUCCESS      success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE      failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
none.
*/
HI_S32 HI_UNF_TTX_Output (HI_HANDLE hTTX, HI_UNF_TTX_OUTPUT_E enOutput, HI_BOOL bEnable);

/**
\brief     The function  of TTX instance to handle user's operation.  CNcomment:TTXʵ\C0\FD\D3û\A7\B2\D9\D7\F7\B4\A6\C0\ED\BA\AF\CA\FD\A1\A3CNend
\attention \n
none.
\param[in] hTTX     Teletext instance.   CNcomment:Teletext\BE\E4\B1\FA\A1\A3CNend
\param[in] enCMD      Type of command.   CNcomment:\C3\FC\C1\EE\C0\E0\D0͡\A3CNend
\param[in] pvCMDParam     Parameter of  command(The parameter must be  conveted to appropriate  type at every
 specifical application), when the command is UPDATE or EXIT, the command can be NULL.
 CNcomment:\C3\FC\C1\EE\B2\CE\CA\FD(\BE\DF\CC\E5Ӧ\D3\C3\D0\E8Ҫǿ\D6\C6ת\BB\BB)\A3\ACUPDATE/EXITʱ\BF\C9ΪNULL\A1\A3CNend
\param[out] pvCMDParam    Parameter of command , when the command is  GETPAGEADDR, it points to the address of specifical  pages.
 CNcomment:\C3\FC\C1\EE\B2\CE\CA\FD\A3\ACGETPAGEADDRʱ\CA\E4\B3\F6ҳ\B5\D8ַ\A1\A3CNend
\retval ::HI_SUCCESS    success.  CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE    failure.  CNcomment:ʧ\B0ܡ\A3CNend
\see \n
 Please  consult  the definition of  HI_UNF_TTX_CMD_E.  CNcomment:\C7\EB\B2ο\BCHI_UNF_TTX_CMD_E\B6\A8\D2塣CNend
*/
HI_S32 HI_UNF_TTX_ExecCmd(HI_HANDLE hTTX,
                          HI_UNF_TTX_CMD_E enCMD, HI_VOID *pvCMDParam);

/**
\brief  Setting teletext language of region.
CNcomment:\C9\E8\D6\C3ͼ\CE\C4\C7\F8\D3\F2\D3\EF\D1\D4\C2롣CNend
\attention \n
None
\param[in] handle Handle of teletext instance. CNcomment:TTXʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8Language language code.
CNcomment:\D3\EF\D1\D4\C2\EB CNend

\retval ::HI_SUCCESS  Operation success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_TTX_SetLanguage(HI_HANDLE hTTX, HI_U8* pu8Language);

/**
\brief  Setting max interval time of the teletext.
CNcomment:\C9\E8\D6\C3ͼ\CE\C4\D7\EE\B4\F3\B5\C4ʱ\BC\E4ƫ\B2CNend
\attention \n
None
\param[in] handle Handle of teletext instance. CNcomment:TTXʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] u32IntervalMs max interval of teletext, unit is Millisecondes.
CNcomment:ͼ\CE\C4\D7\EE\B4\F3\B5\C4ʱ\BC\E4ƫ\B2\EEֵ\A3\AC\B5\A5λms\A1\A3CNend

\retval ::HI_SUCCESS  Operation success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_TTX_SetMaxInterval(HI_HANDLE hTTX, HI_U32 u32IntervalMs );

/**
\brief  Setting teletext packet type.
CNcomment:\C9\E8\D6\C3ͼ\CEĽ\E2\CE\F6\B5\C4\CA\FD\BEݰ\FC\C0\E0\D0͡\A3CNend
\attention \n
None
\param[in] handle Handle of teletext instance. CNcomment:TTXʵ\C0\FD\BE\E4\B1\FA\A1\A3CNend
\param[in] enPacketType the type of teletext packet
CNcomment:ͼ\CE\C4\CA\FD\BEݰ\FC\C0\E0\D0͡\A3CNend

\retval ::HI_SUCCESS  Operation success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Operation fail. CNcomment:ʧ\B0ܡ\A3CNend

\see \n
None
*/
HI_S32 HI_UNF_TTX_SetPacketType (HI_HANDLE hTTX, HI_UNF_TTX_PACKET_TYPE_E enPacketType);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif
#endif
