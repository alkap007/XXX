/******************************************************************************

   Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_unf_disp.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2009/12/15
   Description   :
   History       :
   1.Date        : 2009/12/15
    Author      : sdk
    Modification: Created file

 *******************************************************************************/


/**
 * \file
 **\brief : define DISPLAY module information
 * \brief supply infor about display.
 */

#ifndef  __HI_UNF_DISP_H__
#define  __HI_UNF_DISP_H__

#include "hi_unf_common.h"
#include "hi_unf_hdmi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      DISPLAY */
/** @{ */  /** <!-- [DISPLAY] */

/**enum define about DISPLAY channel*/
/**CNcomment:\B6\A8\D2\E5DISPLAYͨ\B5\C0ö\BE\D9*/
typedef enum hiUNF_DISP_E
{
    HI_UNF_DISPLAY0 = 0x0,  /**< DISPLAY0,Compatible with SD */ /**<CNcomment:\B8\DF\C7\E5DISPLAY0\A3\AC\BC\E6\C8ݱ\EA\C7\E5 */
    HI_UNF_DISPLAY1,        /**< DISPLAY1 *//**<CNcomment: \B8\DF\C7\E5DISPLAY1 */
    HI_UNF_DISPLAY2,        /**< DISPLAY2 *//**<CNcomment: \B8\DF\C7\E5DISPLAY2 */
    HI_UNF_DISPLAY_BUTT
}HI_UNF_DISP_E;

/**max DAC count*/
/**CNcomment:\D7\EE\B4\F3\B5\C4DAC\CA\FDĿ*/
#define MAX_DAC_NUM ( 6 )

/**define the LCD data format*/
/**CNcomment:\B6\A8\D2\E5LCD\B5\C4\CA\FD\BEݸ\F1ʽ*/
typedef enum hiHI_UNF_DISP_INTF_DATA_FMT
{
    HI_UNF_DISP_INTF_DATA_FMT_YUV422   = 0,         /**<YUV422,data width is 16*//**<CNcomment:YUV422\A3\ACλ\BF\EDΪ16*/
    HI_UNF_DISP_INTF_DATA_FMT_RGB565   = 0x8,       /**<RGB565,data width is 16*//**<CNcomment:RGB565\A3\ACλ\BF\EDΪ16*/
    HI_UNF_DISP_INTF_DATA_FMT_RGB444   = 0xa,       /**<RGB444,data width is 16*//**<CNcomment:RGB444\A3\ACλ\BF\EDΪ16*/
    HI_UNF_DISP_INTF_DATA_FMT_RGB666   = 0xb,       /**<RGB666,data width is 24*//**<CNcomment:RGB666\A3\ACλ\BF\EDΪ24*/
    HI_UNF_DISP_INTF_DATA_FMT_RGB888   = 0xc,       /**<RGB888,data widht is 24*//**<CNcomment:RGB888\A3\ACλ\BF\EDΪ24*/
    HI_UNF_DISP_INTF_DATA_FMT_BUTT
}HI_UNF_DISP_INTF_DATA_FMT_E;

/**define LCD output data width*/
/**CNcomment:\B6\A8\D2\E5LCD\CA\E4\B3\F6\B5\C4\CA\FD\BE\DDλ\BF\ED*/
typedef enum hiUNF_DISP_INTF_DATA_WIDTH_E
{
    HI_UNF_DISP_INTF_DATA_WIDTH8 = 0,       /**<8 bits*//**<CNcomment:8λ*/
    HI_UNF_DISP_INTF_DATA_WIDTH16,          /**<16 bits*//**<CNcomment:16λ*/
    HI_UNF_DISP_INTF_DATA_WIDTH24,          /**<24 bits*//**<CNcomment:24λ*/
    HI_UNF_DISP_INTF_DATA_WIDTH_BUTT
}HI_UNF_DISP_INTF_DATA_WIDTH_E;

/**define LCD timing */
/**CNcomment:\B6\A8\D2\E5LCD\B5\C4ʱ\D0\F2\B2\CE\CA\FD*/
typedef struct hiUNF_DISP_TIMING_S
{
    HI_U32                        VFB;            /**<vertical front blank*//**<CNcomment:\B4\B9ֱǰ\CF\FB\D2\FE*/
    HI_U32                        VBB;            /**<vertical back blank*//**<CNcomment:\B4\B9ֱ\BA\F3\CF\FB\D2\FE*/
    HI_U32                        VACT;           /**<vertical active area*//**<CNcomment:\B4\B9ֱ\D3\D0Ч\C7\F8*/
    HI_U32                        HFB;            /**<horizonal front blank*//**<CNcomment:ˮƽǰ\CF\FB\D2\FE*/
    HI_U32                        HBB;            /**<horizonal back blank*//**<CNcomment:ˮƽ\BA\F3\CF\FB\D2\FE*/
    HI_U32                        HACT;           /**<horizonal active area*/ /**<CNcomment:ˮƽ\D3\D0Ч\C7\F8*/
    HI_U32                        VPW;            /**<vertical sync pluse width*//**<CNcomment:\B4\B9ֱ\C2\F6\B3\E5\BF\ED\B6\C8*/
    HI_U32                        HPW;            /**<horizonal sync pluse width*/ /**<CNcomment:ˮƽ\C2\F6\B3\E5\BF\ED\B6\C8*/
    HI_BOOL                       IDV;            /**< flag of data valid signal is needed flip*//**<CNcomment:\D3\D0Ч\CA\FD\BE\DD\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_BOOL                       IHS;            /**<flag of horizonal sync pluse is needed flip*//**<CNcomment:ˮƽͬ\B2\BD\C2\F6\B3\E5\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_BOOL                       IVS;            /**<flag of vertical sync pluse is needed flip*//**<CNcomment:\B4\B9ֱͬ\B2\BD\C2\F6\B3\E5\D0ź\C5\CAǷ\F1\B7\ADת*/
    HI_BOOL                       ClockReversal;  /**<flag of clock is needed flip*//**<CNcomment:ʱ\D6\D3\CAǷ\F1\B7\ADת*/
    HI_UNF_DISP_INTF_DATA_WIDTH_E DataWidth;      /**<data width*/ /**<CNcomment:\CA\FD\BE\DDλ\BF\ED*/
    HI_UNF_DISP_INTF_DATA_FMT_E   ItfFormat;      /**<data format.*//**<CNcomment:\CA\FD\BEݸ\F1ʽ.*/

    HI_BOOL DitherEnable;                           /**< flag of is enable Dither*//**<CNcomment:\CA\FD\BEݸ\F1ʽ.*/
    HI_U32  ClkPara0;                               /**<PLL  register SC_VPLL1FREQCTRL0  value *//**<CNcomment:PLL  SC_VPLL1FREQCTRL0  \BCĴ\E6\C6\F7*/
    HI_U32  ClkPara1;                               /**<PLL  register SC_VPLL1FREQCTRL1 value*//**<CNcomment:PLL   SC_VPLL1FREQCTRL1\BCĴ\E6\C6\F7*/

    HI_BOOL bInterlace;                             /**<progressive or interlace*//**<CNcomment:\D6\F0\D0л\F2\D5߸\F4\D0\D0*/
    HI_U32  PixFreq;                                /**<pixel clock*//**<CNcomment:\CF\F1\CB\D8ʱ\D6\D3*/
    HI_U32  VertFreq;                               /**<display rate*//**<CNcomment:ˢ\D0\C2\C2\CA*/
    HI_U32  AspectRatioW;                           /**<width of screen*//**<CNcomment:\C6\C1Ļ\BF\ED\B6\C8*/
    HI_U32  AspectRatioH;                           /**<height of screen*//**<CNcomment:\C6\C1Ļ\B8߶\C8*/
    HI_BOOL bUseGamma;                              /**<gamma modulation*//**<CNcomment:٤\C2\ED\B5\F7\BD\DA*/
    HI_U32  Reserve0;                               /**<reserved byte*//**<CNcomment:\B1\A3\C1\F4λ*/
    HI_U32  Reserve1;                               /**<reserved byte*//**<CNcomment:\B1\A3\C1\F4λ*/
} HI_UNF_DISP_TIMING_S;

/**define video and graphics layers */
/**CNcomment:\CA\D3Ƶ\BA\CDͼ\D0β\E3*/
typedef enum hiUNF_DISP_LAYER_E
{
    HI_UNF_DISP_LAYER_VIDEO = 0,                   /**<video layer *//**<CNcomment:\CA\D3Ƶ\B2\E3*/
    HI_UNF_DISP_LAYER_GFX,                  /**<graphics layer *//**<CNcomment:ͼ\D0β\E3*/
    HI_UNF_DISP_LAYER_BUTT
}HI_UNF_DISP_LAYER_E;

/**bt1120 interface ID */
/**CNcomment:bt1120 \BDӿ\DAID  */
typedef enum hiUNF_DISP_BT1120_E
{
    HI_UNF_DISP_BT1120_0,    /**<BT1120 interface 0 *//**<CNcomment:BT1120\BDӿ\DA0 */
    HI_UNF_DISP_BT1120_BUTT,
}HI_UNF_DISP_BT1120_E;

/**BT656 interface ID */
/**CNcomment:BT656 \BDӿ\DAID  */
typedef enum hiUNF_DISP_BT656_E
{
    HI_UNF_DISP_BT656_0,    /**<BT656 interface 0 *//**<CNcomment:BT656\BDӿ\DA0 */
    HI_UNF_DISP_BT656_BUTT,
}HI_UNF_DISP_BT656_E;

/**LCD interface ID */
/**CNcomment:LCD \BDӿ\DAID  */
typedef enum hiUNF_LCD_E
{
    HI_UNF_DISP_LCD_0,    /**<LCD interface 0 *//**<CNcomment:LCD\BDӿ\DA0 */
    HI_UNF_DISP_LCD_BUTT,
}HI_UNF_DISP_LCD_E;

/**define the type of interface*/
/**CNcomment:\B6\A8\D2\E5\BDӿ\DA\C0\E0\D0\CD*/
typedef enum  hiUNF_DISP_INTF_TYPE_E
{
    HI_UNF_DISP_INTF_TYPE_HDMI,     /**<HDMI interface type *//**<CNcomment:HDMI\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_LCD,      /**<LCD interface type *//**<CNcomment:LCD\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_BT1120,   /**<bt1120 digital interface type *//**<CNcomment:BT1120\CA\FD\D7ֽӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_BT656,    /**<bt656 digital interface type*//**<CNcomment:BT656\CA\FD\D7ֽӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_YPBPR,    /**<YPBPR interface type*//**<CNcomment:YPBPR\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_RGB,      /**<RGB interface type*//**<CNcomment:RGB\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_CVBS,     /**<CVBS interface type*//**<CNcomment:CVBS\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_SVIDEO,   /**<SVIDEO interface type*//**<CNcomment:SVIDEO\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_VGA,      /**<VGA interface type*//**<CNcomment:VGA\BDӿ\DA\C0\E0\D0\CD*/
    HI_UNF_DISP_INTF_TYPE_BUTT
}HI_UNF_DISP_INTF_TYPE_E;

/**define the YPBPR type struct of interface*/
/**CNcomment:\B6\A8\D2\E5YPBPR\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_YPBPR_S
{
    HI_U8 u8DacY;             /**<DAC num of Y  *//**<CNcomment:Y\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8 u8DacPb;            /**<DAC num of Pb  *//**<CNcomment:Pb\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8 u8DacPr;            /**<DAC num of Pr  *//**<CNcomment:Pr\B7\D6\C1\BFdac\B6˿ں\C5*/
}HI_UNF_DISP_INTF_YPBPR_S;

/**define the RGB type struct of interface*/
/**CNcomment:\B6\A8\D2\E5RGB\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_RGB_S
{
    HI_U8  u8DacR;            /**<DAC num of R  *//**<CNcomment:R\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8  u8DacG;            /**<DAC num of G  *//**<CNcomment:G\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8  u8DacB;            /**<DAC num of B  *//**<CNcomment:B\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_BOOL bDacSync;         /**<G without sync signal  *//**<CNcomment:G\B7\D6\C1\BF\B2\BB\B4\F8ͬ\B2\BD\D0ź\C5*/
}HI_UNF_DISP_INTF_RGB_S;

/**define the VGA type struct of interface*/
/**CNcomment:\B6\A8\D2\E5VGA\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_VGA_S
{
    HI_U8  u8DacR;            /**<DAC num of R  *//**<CNcomment:R\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8  u8DacG;            /**<DAC num of G  *//**<CNcomment:G\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8  u8DacB;            /**<DAC num of B  *//**<CNcomment:B\B7\D6\C1\BFdac\B6˿ں\C5*/
}HI_UNF_DISP_INTF_VGA_S;

/**define the CVBS type struct of interface*/
/**CNcomment:\B6\A8\D2\E5CVBS\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_CVBS_S
{
    HI_U8 u8Dac;              /**<DAC num of CVBS  *//**<CNcomment:CVBS\B6\CB\D7\D3dac\B6˿ں\C5*/
}HI_UNF_DISP_INTF_CVBS_S;

/**define the SVIDEO type struct of interface*/
/**CNcomment:\B6\A8\D2\E5SVIDEO\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_SVIDEO_S
{
    HI_U8 u8DacY;             /**<DAC num of Y  *//**<CNcomment:Y\B7\D6\C1\BFdac\B6˿ں\C5*/
    HI_U8 u8DacC;             /**<DAC num of C   *//**<CNcomment:C\B7\D6\C1\BFdac\B6˿ں\C5*/
}HI_UNF_DISP_INTF_SVIDEO_S;

/**define display interface struct*/
/**CNcomment:\B6\A8\D2\E5\CF\D4ʾ\BDӿڽṹ*/
typedef struct  hiUNF_DISP_INTF_S
{
    HI_UNF_DISP_INTF_TYPE_E enIntfType;         /**<interface type *//**<CNcomment:\BDӿ\DA\C0\E0\D0\CD*/
    union
    {
        HI_UNF_HDMI_ID_E        enHdmi;         /**<hdmi id *//**<CNcomment:HDMI \D0\F2\BA\C5*/
        HI_UNF_DISP_BT1120_E    enBT1120;       /**<bt1120 id *//**<CNcomment:BT1120\D0\F2\BA\C5*/
        HI_UNF_DISP_BT656_E     enBT656;        /**<bt656 id *//**<CNcomment:BT656\D0\F2\BA\C5*/
        HI_UNF_DISP_LCD_E       enLcd;          /**<lcd id *//**<CNcomment:LCD\D0\F2\BA\C5*/

        HI_UNF_DISP_INTF_YPBPR_S    stYPbPr;    /**<intf config of YPBPR  *//**<CNcomment:YPBPR\BDӿ\DA\C5\E4\D6\C3*/
        HI_UNF_DISP_INTF_RGB_S      stRGB;      /**<intf config of RGB  *//**<CNcomment:RGB\BDӿ\DA\C5\E4\D6\C3*/
        HI_UNF_DISP_INTF_VGA_S      stVGA;      /**<intf config of VGA  *//**<CNcomment:VGA\BDӿ\DA\C5\E4\D6\C3*/
        HI_UNF_DISP_INTF_CVBS_S     stCVBS;     /**<intf config of CVBS  *//**<CNcomment:CVBS\BDӿ\DA\C5\E4\D6\C3*/
        HI_UNF_DISP_INTF_SVIDEO_S   stSVideo;   /**<intf config of SVIDEO  *//**<CNcomment:SVIDEO\BDӿ\DA\C5\E4\D6\C3*/
    }unIntf;
}HI_UNF_DISP_INTF_S;


/**Defines the device aspect ratio.*/
/**CNcomment: \B6\A8\D2\E5\C9豸\BF\ED\B8߱\C8ö\BE\D9*/
typedef enum hiUNF_DISP_ASPECT_RATIO_E
{
    HI_UNF_DISP_ASPECT_RATIO_AUTO,              /**<aspect ratio as device Resolution*//**<CNcomment: \BF\ED\B8߱\C8\D3\EB\C9豸\B7ֱ\E6\C2\CAһ\D6\C2*/
    HI_UNF_DISP_ASPECT_RATIO_4TO3,              /**<4:3*//**<CNcomment: 4\B1\C83*/
    HI_UNF_DISP_ASPECT_RATIO_16TO9,             /**<16:9*//**<CNcomment: 16\B1\C89*/
    HI_UNF_DISP_ASPECT_RATIO_221TO1,            /**<221:100*//**<CNcomment: 221\B1\C8100*/
    HI_UNF_DISP_ASPECT_RATIO_USER,              /**<user define*//**<CNcomment: \D3û\A7\B6\A8\D2\E5*/

    HI_UNF_DISP_ASPECT_RATIO_BUTT
}HI_UNF_DISP_ASPECT_RATIO_E;

/**Defines the device aspect ratio struct.*/
/**CNcomment: \B6\A8\D2\E5\C9豸\BF\ED\B8߱Ƚṹ*/
typedef struct hiUNF_DISP_ASPECT_RATIO_S
{
    HI_UNF_DISP_ASPECT_RATIO_E enDispAspectRatio;   /**<aspect ratio type of device*//**<CNcomment: \C9豸\BF\ED\B8߱\C8\C0\E0\D0\CD*/
    HI_U32                     u32UserAspectWidth;  /**<user define width of device*//**<CNcomment: \D3û\A7\B6\A8\D2\E5\C9豸\BF\ED\B6\C8*/
    HI_U32                     u32UserAspectHeight; /**<user define height of device*//**<CNcomment: \D3û\A7\B6\A8\D2\E5\C9豸\B8߶\C8*/
}HI_UNF_DISP_ASPECT_RATIO_S;

/**Defines algorithmic  control struct of display device.*/
/**CNcomment: \B6\A8\D2\E5\CF\D4ʾ\C9豸\CB㷨\BF\D8\D6ƽṹ*/
typedef struct hiUNF_DISP_ALG_CFG_S
{
    HI_BOOL bAccEnable;                             /**<acc alg*//**<CNcomment: acc\CB㷨*/
    HI_BOOL bSharpEnable;                           /**<sharp alg*//**<CNcomment: sharp\CB㷨*/
}HI_UNF_DISP_ALG_CFG_S;

/**Defines VBI type.*/
/**CNcomment: \B6\A8\D2\E5VBI\CA\FD\BE\DD\C0\E0\D0\CD*/
typedef enum hiUNF_DISP_VBI_TYPE_E
{
    HI_UNF_DISP_VBI_TYPE_TTX = 0,                   /**<Teltext type*//**<CNcomment:teltext\C0\E0\D0\CD*/
    HI_UNF_DISP_VBI_TYPE_CC,                        /**<Closed caption/V-Chip type *//**<CNcomment: \D2\FE\B2\D8\D7\D6Ļ/V-Chip\C0\E0\D0\CD*/
    HI_UNF_DISP_VBI_TYPE_WSS,                       /**<Wide screen signal*//**<CNcomment:\BF\ED\C6\C1\D0\C5\C1\EE*/
    HI_UNF_DISP_VBI_TYPE_BUTT
} HI_UNF_DISP_VBI_TYPE_E;

/**Defines VBI config struct.*/
/**CNcomment: \B6\A8\D2\E5VBI\C5\E4\D6ýṹ*/
typedef struct hiUNF_DISP_VBI_CFG_S
{
    HI_UNF_DISP_VBI_TYPE_E  enType;                  /**<VBI type*//**<CNcomment: VBI \C0\E0\D0\CD*/
    HI_U32                  u32InBufferSize;        /**<VBI data(pes) buffer size,more than 4K,suggest 4K*//**<CNcomment:VBI pes \CA\FD\BE\DD\CA\E4\C8뻺\B3\E5\B4\F3С,\B2\BBС\D3\DA4K\A3\AC\CDƼ\F6ֵ4K*/
    HI_U32                  u32WorkBufferSize;      /**<VBI data buffer size used in driver,more than 2K,suggest 2K*//**<CNcomment:VBI\BD\E2\CE\F6\BA\F3\CA\FD\BE\DD\D4\DA\C7\FD\B6\AF\D6н\D3\CAջ\BA\B3\E5\B4\F3С\B2\BBС\D3\DA2K\A3\AC\CDƼ\F6ֵ2K*/
} HI_UNF_DISP_VBI_CFG_S;

/** define VBI information structure*/
/**CNcomment: \B6\A8\D2\E5VBI\D0\C5Ϣ\CA\FD\BEݽṹ*/
typedef struct hiUNF_DISP_VBI_DATA_S
{
    HI_UNF_DISP_VBI_TYPE_E  enType;                  /**<VBI type*//**<CNcomment: VBI \C0\E0\D0\CD*/
    HI_U8                   *pu8DataAddr;           /**<Vbi data buffer virtual address*//**<CNcomment:Vbi\CA\FD\BE\DD\D3û\A7\D0\E9\C4\E2\B5\D8ַ*/
    HI_U32                  u32DataLen;             /**<Vbi data lenght*//**<CNcomment:Vbi\CA\FD\BEݳ\A4\B6\C8*/
} HI_UNF_DISP_VBI_DATA_S;

/**Defines the MAX buffer number.*/
/** CNcomment:\B6\A8\D2\E5\D7\EE\B4\F3\B5\C4buffer \B7\D6\C5\E4\CA\FD*/
#define HI_DISP_CAST_BUFFER_MAX_NUMBER ( 16 )

/**define CAST config */
/**CNcomment:\B6\A8\D2\E5\C6\C1ĻͶӰ\C5\E4\D6\C3*/
typedef struct hiUNF_DISP_CAST_ATTR_S
{
    HI_UNF_VIDEO_FORMAT_E enFormat;                                        /**<the output video format.*//**<CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6\CA\D3Ƶ\B8\F1ʽ*/
    HI_U32                u32Width;                                       /**<the output video width.*//**<CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6\CA\D3Ƶ\B5Ŀ\ED*/
    HI_U32                u32Height;                                      /**<the output video height.*//**<CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6\CA\D3Ƶ\B5ĸ\DF*/
    HI_BOOL               bLowDelay;                                      /**<work at low delay mode.*//**<CNcomment:\C6\F4\D3õ\CD\D1ӳ\D9ģʽ*/
    HI_U32                u32BufNum;                                      /**<the buffer number.*//**<CNcomment:\B6\A8\D2\E5\B7\D6\C5\E4buffer \CA\FD*/
    HI_BOOL               bUserAlloc;                                     /**<whether is user alloc memory*//**<CNcomment:\B6\A8\D2\E5\CAǷ\F1\D3û\A7\B7\D6\C5\E4\C4ڴ\E6*/
    HI_U32                u32BufSize;                                     /**<each the buffer size.*//**<CNcomment:\B6\A8\D2\E5\D3û\A7\B7\D6\C5\E4ÿ\B8\F6buffer \B4\F3С*/
    HI_U32                u32BufStride;                                   /**<the horizonal stride.*//**<CNcomment:\B6\A8\D2\E5\D0ж\D4\C6\EB*/
    HI_U32                u32BufPhyAddr[HI_DISP_CAST_BUFFER_MAX_NUMBER];  /**<the buffer physics address.*//**<CNcomment:\B7\D6\C5\E4\C4ڴ\E6buffer \B3\C9Ա\B5\C4\CE\EF\C0\ED\B5\D8ַ*/
    HI_BOOL               bCrop;                                          /**<whether enable crop .*//**<CNcomment:\B6\A8\D2\E5\CAǷ\F1\BD\F8\D0\D0crop*/
    HI_UNF_CROP_RECT_S    stCropRect;                                     /**<the crop wise .*//**<CNcomment:\B6\A8\D2\E5crop \B7\B6Χ*/
} HI_UNF_DISP_CAST_ATTR_S;

/**define color setting */
/**CNcomment:\B6\A8\D2\E5ɫ\B2\CA\C9\E8\D6\C3*/
typedef struct hiUNF_DISP_COLOR_SETTING_S
{
    HI_BOOL bGammaEnable;         /**<whether Gamma enable.*//**<CNcomment:\B6\A8\D2\E5Gamma ʹ\C4\DC*/
    HI_BOOL bUseCustGammaTable;   /**<whether use custom GammaTable.*//**<CNcomment:\CAǷ\F1ʹ\D3\C3\D3û\A7Gamma\B1\ED*/
    HI_BOOL bColorCorrectEnable;  /**<whether Color Correct.*//**<CNcomment:\CAǷ\F1ɫ\B2\CAУ\D5\FD*/
    HI_S32  s32ColorTemp;         /**<color Temp.*//**<CNcomment:ɫ\CE\C2*/
    HI_U32  u32Reserve;           /**<Reserve.*//**<CNcomment:\B1\A3\C1\F4*/
    HI_VOID *pPrivate;            /**<Private.*//**<CNcomment:˽\D3\D0\CC\E5ָ\D5\EB*/
}HI_UNF_DISP_COLOR_SETTING_S;

/**define the struct about color */
/**CNcomment:\B6\A8\D2\E5\CF\D4ʾ\D1\D5ɫ\B5Ľṹ\CC\E5 */
typedef struct  hiUNF_DISP_BG_COLOR_S
{
    HI_U8 u8Red;                  /**<red *//**<CNcomment:\BA\ECɫ\B7\D6\C1\BF*/
    HI_U8 u8Green;                /**<green*//**<CNcomment:\C2\CCɫ\B7\D6\C1\BF*/
    HI_U8 u8Blue;                 /**<blue*//**<CNcomment:\C0\B6ɫ\B7\D6\C1\BF*/
} HI_UNF_DISP_BG_COLOR_S;

/**define the struct about isogeny attributes */
/**CNcomment:\B6\A8\D2\E5ͬԴ\CA\F4\D0\D4 */
typedef struct  hiUNF_DISP_ISOGENY_ATTR_S
{
    HI_UNF_DISP_E          enDisp; /**<channel id*//**<CNcomment: ͨ\B5\C0\BA\C5*/
    HI_UNF_ENC_FMT_E       enFormat;/**<format type*//**<CNcomment:\D6\C6ʽ\C0\E0\D0\CD*/
}HI_UNF_DISP_ISOGENY_ATTR_S ;


/********************************ENCODER STRUCT********************************/
/** define the enum of Macrovision output type*/
/** CNcomment:\CF\D4ʾ\CA\E4\B3\F6Macrovisionģʽö\BEٶ\A8\D2\E5*/
typedef enum hiUNF_DISP_MACROVISION_MODE_E
{
    HI_UNF_DISP_MACROVISION_MODE_TYPE0,     /**<type 0:no protect process *//**<CNcomment:\CEޱ\A3\BB\A4\B4\A6\C0\ED*/
    HI_UNF_DISP_MACROVISION_MODE_TYPE1,     /**<type 1:AGC (automatic gain control) process only *//**<CNcomment:\BD\F6\D7Զ\AF\D4\F6\D2\E6\BF\D8\D6\C6 */
    HI_UNF_DISP_MACROVISION_MODE_TYPE2,     /**<type 2:AGC + 2-line color stripe *//**<CNcomment:\D7Զ\AF\D4\F6\D2\E6\BF\D8\D6ƺ\CD\C1\BD\CF\DFɫ \B6ȸ\C9\C8\C5*/
    HI_UNF_DISP_MACROVISION_MODE_TYPE3,     /**<type 3:AGC + aggressive 4-line color stripe *//**<CNcomment:\D7Զ\AF\D4\F6\D2\E6\BA\CD\CB\C4\CF\DFǿɫ\B6ȸ\C9\C8\C5*/
    HI_UNF_DISP_MACROVISION_MODE_CUSTOM,    /**<type of configure by user *//**<CNcomment:\D3û\A7\D7Զ\A8\D2\E5\C5\E4\D6\C3 */
    HI_UNF_DISP_MACROVISION_MODE_BUTT
} HI_UNF_DISP_MACROVISION_MODE_E;

/** CGMS type select */
/**CNcomment:CGMS \C0\E0\D0\CDѡ\D4\F1*/
typedef enum hiUNF_DISP_CGMS_TYPE_E
{
    HI_UNF_DISP_CGMS_TYPE_A = 0x00,     /**<CGMS type  A*//**<CNcomment:CGMS \C0\E0\D0\CDA*/
    HI_UNF_DISP_CGMS_TYPE_B,            /**<CGMS type  B*//**<CNcomment:CGMS \C0\E0\D0\CDB*/

    HI_UNF_DISP_CGMS_TYPE_BUTT
}HI_UNF_DISP_CGMS_TYPE_E;

/** definition of CGMS mode */
/**CNcomment:\B6\A8\D2\E5CGMS ģʽ*/
typedef enum hiUNF_DISP_CGMS_MODE_E
{
    HI_UNF_DISP_CGMS_MODE_COPY_FREELY  = 0,     /**<copying is permitted without restriction *//**<CNcomment:\CE\DE\CF\DE\D6ƿ\BD\B1\B4*/
    HI_UNF_DISP_CGMS_MODE_COPY_NO_MORE = 0x01,  /**<No more copies are allowed (one generation copy has been made)*//**<CNcomment:\BF\BD\B1\B4һ\B4κ\F3\B2\BB\D4\CA\D0\ED\D4ٱ\BB\BF\BD\B1\B4*/
    HI_UNF_DISP_CGMS_MODE_COPY_ONCE    = 0x02,  /**<One generation of copies may be made *//**<CNcomment:\BD\F6\D4\CA\D0\ED\BF\BD\B1\B4һ\B4\CE*/
    HI_UNF_DISP_CGMS_MODE_COPY_NEVER   = 0x03,  /**<No copying is permitted *//**<CNcomment:\B2\BB\D4\CA\D0\ED\BF\BD\B1\B4*/

    HI_UNF_DISP_CGMS_MODE_BUTT
}HI_UNF_DISP_CGMS_MODE_E;

/** definition of CGMS configuration */
typedef struct hiUNF_DISP_CGMS_CFG_S
{
    HI_BOOL                 bEnable;            /**<HI_TRUE:CGMS is enabled; HI_FALSE:CGMS is disabled *//**<CNcomment:CGMS ʹ\C4\DCѡ\CF\EE*/
    HI_UNF_DISP_CGMS_TYPE_E enType;             /**<type-A or type-B or None(BUTT) *//**<CNcomment:CGMS \C0\E0\D0\CD*/
    HI_UNF_DISP_CGMS_MODE_E enMode;             /**<CGMS mode. *//**<CNcomment:CGMS ģʽ*/
}HI_UNF_DISP_CGMS_CFG_S;

/**define WSS information structure*/
/**CNcomment:\B6\A8\D2\E5ͼ\CE\C4\D0\C5Ϣ\CA\FD\BEݽṹ */
typedef struct hiUNF_DISP_WSS_DATA_S
{
    HI_BOOL bEnable;                            /**<WSS configure enable HI_TRUE: enable,HI_FALSE: disnable*//**<CNcomment:WSS\C5\E4\D6\C3ʹ\C4ܡ\A3HI_TRUE\A3\BAʹ\C4ܣ\BBHI_FALSE\A3\BA\BD\FBֹ*/
    HI_U16  u16Data;                            /**<Wss data */ /**<CNcomment:Wss\CA\FD\BE\DD*/
}HI_UNF_DISP_WSS_DATA_S;


/**define display 3D mode stucture*/
/**CNcomment:\B6\A8\D2\E5\CF\D4ʾģʽ\BDṹ\CC\E5 */
typedef enum hiUNF_DISP_3D_E
{
    HI_UNF_DISP_3D_NONE = 0,
    HI_UNF_DISP_3D_FRAME_PACKING,                   /**<3d type:Frame Packing*//**<CNcomment:3d ģʽ:֡\B7\E2װ*/
    HI_UNF_DISP_3D_SIDE_BY_SIDE_HALF,               /**<3d type:Side by side half*//**<CNcomment:3d ģʽ:\B2\A2\C5\C5ʽ \D7\F3\D3Ұ\EB\B1\DF*/
    HI_UNF_DISP_3D_TOP_AND_BOTTOM,                  /**<3d type:Top and Bottom*//**<CNcomment:3d ģʽ:\C9\CF\CF\C2ģʽ*/
    HI_UNF_DISP_3D_FIELD_ALTERNATIVE,               /**<3d type:Field alternative*//**<CNcomment:3d ģʽ:\B3\A1\BD\BB\B4\ED*/
    HI_UNF_DISP_3D_LINE_ALTERNATIVE,                /**<3d type:Field alternative*//**<CNcomment:3d ģʽ:\D0н\BB\B4\ED*/
    HI_UNF_DISP_3D_SIDE_BY_SIDE_FULL,               /**<3d type:Side by side full*//**<CNcomment:3d ģʽ:\B2\A2\C5\C5ʽ \D7\F3\D3\D2ȫ\B3\A1*/
    HI_UNF_DISP_3D_L_DEPTH,                         /**<3d type:L+depth*//**<CNcomment:3d ģʽ:L+DEPTH*/
    HI_UNF_DISP_3D_L_DEPTH_GRAPHICS_GRAPHICS_DEPTH, /**<3d type:L+depth+Graphics+Graphics-depth*//**<CNcomment:3d ģʽ:L+depth+Graphics+Graphics-depth*/
    HI_UNF_DISP_3D_BUTT
}HI_UNF_DISP_3D_E;

/**define display margin stucture*/
/**CNcomment:\B6\A8\D2\E5\CF\D4ʾ\BFհ\D7\C7\F8\D3\F2\BDṹ\CC\E5 */
typedef struct hiUNF_DISP_OFFSET_S
{
    HI_U32 u32Left;    /**<left offset *//**<CNcomment:\D7\F3\B2\E0ƫ\D2\C6*/
    HI_U32 u32Top;     /**<top offset *//**<CNcomment:\C9Ϸ\BDƫ\D2\C6*/
    HI_U32 u32Right;   /**<right offset *//**<CNcomment:\D3Ҳ\E0ƫ\D2\C6*/
    HI_U32 u32Bottom;  /**<bottom offset *//**<CNcomment:\CF·\BDƫ\D2\C6*/
}HI_UNF_DISP_OFFSET_S;

/**define output signal type.*/
/**CNcomment:\B6\A8\D2\E5\CA\E4\B3\F6\D0ź\C5\C0\E0\D0\CD*/
typedef enum hiUNF_DISP_HDR_TYPE_E
{
    HI_UNF_DISP_HDR_TYPE_NONE = 0,      /**<Normal SDR signal output type *//**<CNcomment:\C6\D5ͨSDR \D0ź\C5\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_AUTO,          /**<Optimum signal output type automatically *//**<CNcomment:\D7Զ\AF\CA\CA\C5\E4\D7\EE\BC\D1\D0ź\C5\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_AUTO_FOLLOW_FIRSTFRAME, /**<signal output type follow first frame type.*//**<CNcomment:\B8\F9\BE\DD\CA\D7֡\C0\E0\D0\CD\D7Զ\AFѡ\D4\F1\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_DOLBY,         /**<DolbyVision signal output type *//**<CNcomment:DolbyVision \D0ź\C5\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_HDR10,         /**<HDR10 signal output type *//**<CNcomment:HDR10 \D0ź\C5\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_HLG,           /**<HLG signal output type *//**<CNcomment:HLG \D0ź\C5\CA\E4\B3\F6*/
    HI_UNF_DISP_HDR_TYPE_DOLBY_LOW_LATENCY,/**<DolbyVision low latency output type *//**<CNcomment:DolbyVision \B5\CD\D1\D3ʱ\D0ź\C5\CA\E4\B3\F6*/

    HI_UNF_DISP_HDR_TYPE_BUTT
} HI_UNF_DISP_HDR_TYPE_E;

/**SD format should use BT601*/
/**CNcomment:\B1\EA\C7\E5\D6\C6ʽǿ\D6\C6ʹ\D3\C3ɫ\B2ʿռ\E4BT601*/
typedef enum hiHI_UNF_DISP_COLOR_SPACE_E
{
    HI_UNF_DISP_COLOR_SPACE_AUTO = 0x0,     /**<  optimum output color space *//**<CNcomment:\D7\EE\BC\D1ɫ\B2ʿռ\E4\CA\E4\B3\F6*/
    HI_UNF_DISP_COLOR_SPACE_BT601,          /**< output  color space BT601, Not support*//**<CNcomment:\CA\E4\B3\F6ɫ\B2ʿռ\E4BT601, \B2\BB֧\B3\D6\C9\E8\D6\C3*/
    HI_UNF_DISP_COLOR_SPACE_BT709,          /**< output  color space BT709*//**<CNcomment:\CA\E4\B3\F6ɫ\B2ʿռ\E4BT709*/
    HI_UNF_DISP_COLOR_SPACE_BT2020,         /**< output  color space BT2020*//**<CNcomment:\CA\E4\B3\F6ɫ\B2ʿռ\E4BT2020*/
    HI_UNF_DISP_COLOR_SPACE_BUTT
}HI_UNF_DISP_COLOR_SPACE_E;

/** definition of output hdr infomation */
/**CNcomment:ʵ\BC\CA\CA\E4\B3\F6\B5\C4\D0ź\C5\C0\E0\D0ͼ\B0ɫ\D3\F2\C0\E0\D0\CD*/
typedef struct hiUNF_DISP_OUTPUT_STATUS_S
{
    HI_UNF_DISP_HDR_TYPE_E enActualOutHDRType;
    HI_UNF_DISP_COLOR_SPACE_E enActualOutColorSpace;
}HI_UNF_DISP_OUTPUT_STATUS_S;

/**define the struct about hdr mixed priority mode. */
/**CNcomment:\B6\A8\D2\E5hdr\B5ĵ\FE\BC\D3\D3\C5\CF\C8ģʽ */
typedef enum hiUNF_DISP_HDR_PRIORITY_MODE{
    HI_UNF_DISP_HDR_PRIORITY_VIDEO = 0,  /**< video and graphic tomapping to video   luminance.  */
    HI_UNF_DISP_HDR_PRIORITY_GRAPHIC,    /**< video and graphic tomapping to graphic luminance. */
    HI_UNF_DISP_HDR_PRIORITY_AUTO,       /**< video and graphic tomapping automatically according to scene.  Not support currently. */
    HI_UNF_DISP_HDR_PRIORITY_MAX,
} HI_UNF_DISP_HDR_PRIORITY_MODE;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      DISPLAY */
/** @{ */  /** <!-- [DISPLAY] */


/**
   \brief Initiallization DISP module.CNcomment:\B3\F5ʼ\BB\AFDISPģ\BF\E9 CNend
   \attention \n
   Please call this API function, before call anyother API of DISP module.
   CNcomment:\B5\F7\D3\C3DISPģ\BF\E9\C6\E4\CB\FC\BDӿ\DAǰҪ\C7\F3\CA\D7\CFȵ\F7\D3ñ\BE\BDӿ\DA CNend
   \param  none.CNcomment:\CE\DE CNend
   \retval ::HI_SUCCESS  operation success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_DEV_NOT_EXIST DISP device not exist.CNcomment:\C9豸\B2\BB\B4\E6\D4\DA CNend
   \retval ::HI_ERR_DISP_NOT_DEV_FILE  DISP  not device file .CNcomment:\B7\C7\C9豸 CNend
   \retval ::HI_ERR_DISP_DEV_OPEN_ERR  DISP  open fail.CNcomment:\B4\F2\BF\AAʧ\B0\DC CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Init( HI_VOID );


/**
   \brief deinital.CNcomment:ȥ\B3\F5ʼ\BB\AFDISPģ\BF\E9 CNend
   \attention \n
   please call API HI_UNF_DISP_Close and open all the DISP device, before call this API.
   CNcomment:\D4ڵ\F7\D3\C3::HI_UNF_DISP_Close\BDӿڹر\D5\CB\F9\D3д򿪵\C4DISP\BA\F3\B5\F7\D3ñ\BE\BDӿ\DA CNend
   \param none.CNcomment:\CE\DE CNend
   \retval ::HI_SUCCESS success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_DEV_CLOSE_ERR  DISP close fail.CNcomment:\B9ر\D5ʧ\B0\DC CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_DeInit( HI_VOID );


/**
   \brief Attach one DISP channel to anoter.CNcomment:\BD\AB\C1\BD\B8\F6DISPͨ\B5\C0\B0\F3\B6\A8 CNend
   \attention \n
   Please finish the attach operation before the DISP channel has been open, and currently we only support HD channel attach to SD channel.
   CNcomment:Ŀǰ֧\B3ֽ\AB\B8\DF\C7\E5DISP\B0󶨵\BD\B1\EA\C7\E5DISPͨ\B5\C0\C9ϣ\AC\B0\F3\B6\A8\D4ڴ\F2\BF\AADISPͨ\B5\C0ǰ\B1\D8\D0\EB\CD\EA\B3ɰ󶨲\D9\D7\F7\A1\A3 CNend
   \param[in] enDstDisp   Destination DISP channel.CNcomment:Ŀ\B1\EADISPͨ\B5\C0\BA\C5 CNend
   \param[in] enSrcDisp   source DISP channel.CNcomment:  ԴDISPͨ\B5\C0\BA\C5 CNend
   \retval ::HI_SUCCESS  operation success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT  display not be initialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT   invalid opeation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Attach( HI_UNF_DISP_E enDstDisp, HI_UNF_DISP_E enSrcDisp );


/**
   \brief dettach DISP.CNcomment:\BD\AB\C1\BD\B8\F6DISPͨ\B5\C0\BD\E2\B0\F3\B6\A8 CNend
   \attention \n
   should  close the DISP channels, before do detach operation.
   CNcomment:ֻ\D3\D0\D4ڹر\D5\C1\BD\B8\F6DISPͨ\B5\C0\BA\F3\B2\C5\C4ܽ\F8\D0н\E2\B0󶨲\D9\D7\F7\A1\A3 CNend
   \param[in] enDstDisp   Destination DISP channel.CNcomment:Ŀ\B1\EADISPͨ\B5\C0\BA\C5 CNend
   \param[in] enSrcDisp    source DISP channel.CNcomment: ԴDISPͨ\B5\C0\BA\C5 CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT   DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT   invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Detach( HI_UNF_DISP_E enDstDisp, HI_UNF_DISP_E enSrcDisp );


/**
   \brief open DISP channel.CNcomment:\B4\F2\BF\AAָ\B6\A8DISPͨ\B5\C0 CNend
   \attention \n
   Please config the valid parameters before open DISP.
   CNcomment:\D4ڴ\F2\BF\AADISP֮ǰ\A3\AC\CF\C8\CD\EA\B3ɶ\D4\C6\E4\B5Ĳ\CE\CA\FD\C9\E8\D6ã\AC\B1\DC\C3⻭\C3\E6\C9\C1˸ CNend
   \param[in] enDisp   DISP channel ID, please reference the define of HI_UNF_DISP_E.CNcomment:DISPͨ\B5\C0\BAţ\AC\C7\EB\B2μ\FB::HI_UNF_DISP_E CNend
   \retval ::HI_SUCCESS success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT   DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_CREATE_ERR    DISP create fail.CNcomment:DISP\B4\B4\BD\A8ʧ\B0\DC CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Open( HI_UNF_DISP_E enDisp );


/**
   \brief  coase DISP channel.CNcomment:\B9ر\D5ָ\B6\A8DISP CNend
   \attention \n
   none.
   CNcomment:\CE\DE CNend
   \param[in] enDisp DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \retval ::HI_SUCCESS success. CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Close( HI_UNF_DISP_E enDisp );


/**
   \brief  set DISP interface parameter.CNcomment:\C9\E8\D6\C3DISP\B5Ľӿڲ\CE\CA\FD CNend
   \attention \n
   The API is uesed for set  interface attach .If the interface has been attached,must be detach it ,or return HI_ERR_DISP_INVALID_OPT;\n
   There are 4 DAC provided by SOC 3712 v300. suggest, DAC 0/1/2 used by HD channel, DAC3 used by SD channel CVBS. \n
   There are 6 DAC provided by SOC 3716 v100/v200/v300. suggest, DAC 0/1/2 used by HD channel, DAC3/4/5 used by SD channel.
   CNcomment:\B8\C3API \D3\C3\C0\B4\C9\E8\D6\C3\CA\E4\B3\F6\BDӿڵİ󶨹\D8ϵ\A3\AC\C8\E7\B9\FB\C9\E8\D6\C3\D2ѱ\BB\B0󶨹\FD\B5Ľӿڣ\AC\D4\F2\D0\E8Ҫ\CFȽ\F8\D0\D0Detach\B2\D9\D7\F7\n
   \BD\E2\B3\FD\B0󶨹\D8ϵ\A3\AC\B7\F1\D4򷵻ش\ED\CE\F3HI_ERR_DISP_INVALID_OPT;\n
   3712 v300 оƬ\B9\B2\D3\D04\B8\F6DAC\A3\AC\CDƼ\F60\A3\AC1\A3\AC2\D3\C3\D7\F7\B8\DF\C7\E5\CA\E4\B3\F6\A3\AC3\D3\C3\D7\F7\B1\EA\C7\E5CVBS\CA\E4\B3\F6\A1\A3\n
   3716 v100/v200/v300 оƬ\B9\B2\D3\D06\B8\F6DAC\A3\AC\CDƼ\F60\A3\AC1\A3\AC2\D3\C3\D7\F7\B8\DF\C7\E5\CA\E4\B3\F6\A3\AC3\A3\AC4\A3\AC5\D3\C3\D7\F7\B1\EA\C7\E5\CA\E4\B3\F6\A1\A3CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32IntfNum  DISP intf num of DISP channel.CNcomment:DISPͨ\B5\C0\C9ϵĽӿ\DA\CA\FDĿ CNend
   \param[in] pstIntf  DISP intf para.CNcomment:DISP\BDӿڲ\CE\CA\FD CNend
   \retval ::HI_SUCCESS   success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT   DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR      Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT   invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_AttachIntf( HI_UNF_DISP_E enDisp, HI_UNF_DISP_INTF_S *pstIntf, HI_U32 u32IntfNum );


/**
   \brief cancel DISP interface parameter.CNcomment:ȡ\CF\FBDISP\B5Ľӿڲ\CE\CA\FD CNend
   \attention \n
   The API is uesed to  detach  interface.
   CNcomment:\D5\E2\B8\F6API \D3\C3\C0\B4\BD\E2\B3\FD\BDӿڵİ󶨹\D8ϵ\A1\A3 CNend
   \param[in] enDisp        DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32IntfNum  DISP interface number of DISP channel.CNcomment:DISPͨ\B5\C0\C9ϵĽӿ\DA\CA\FDĿ CNend
   \param[in] pstIntf  DISP interface para.CNcomment:DISP\BDӿڲ\CE\CA\FD CNend
   \retval ::HI_SUCCESS   success. CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT   DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR        Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA  invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT   invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_DetachIntf( HI_UNF_DISP_E enDisp, HI_UNF_DISP_INTF_S *pstIntf, HI_U32 u32IntfNum );


/**
   \brief set DISP output format.CNcomment:\C9\E8\D6\C3DISP\B5\C4\D6\C6ʽ CNend
   \attention \n
   for HD DISP channel please set HD display format, and for SD DISP channel please set SD display format.\n
   for scenario of HD,SD use same source, only support format which frame rate is 50Hz or 60Hz. \n
   for scenario of HD,SD use same source, when this UNF API sets up HD DISP channel, \n
   the SD DISP channel will be temporarily affected, and vice versa. \n
   It is recommended to use HI_UNF_DISP_SetIsogenyAttr to set up both HD and SD DISP channels to avoid this impact.
   CNcomment:\B6Ը\DF\C7\E5\B5\C4DISP\A3\ACֻ\C4\DC\C9\E8\D6ø\DF\C7\E5\B5\C4\D6\C6ʽ\A3\BB\B6Ա\EA\C7\E5\B5\C4DISP\A3\ACֻ\C4\DC\C9\E8\D6ñ\EA\C7\E5\B5\C4\D6\C6ʽ\A1\A3\n
   \D4\DAͬԴ\CF\D4ʾ\B3\A1\BE\B0\CF£\AC\D4ݲ\BB֧\B3\D6ˢ\D0\C2\C2ʷ\C750Hz/60Hz\B5\C4\D6\C6ʽ\A3\AC\C8磺\D4ݲ\BB֧\B3\D61080P24/1080P25/1080P30\A1\A3\n
   \D4\DAͬԴ\CF\D4ʾ\B3\A1\BE\B0\CF£\AC\B8ýӿ\DA\C9\E8\D6ø\DF\C7\E5ͨ\B5\C0ʱ\A3\AC\B1\EA\C7\E5ͨ\B5\C0\CF\D4ʾ\BB\E1\CAܵ\BD\B6\CC\D4\DDӰ\CF죬\B7\B4֮\D2\E0Ȼ\A1\A3\n
   \CDƼ\F6ʹ\D3\C3HI_UNF_DISP_SetIsogenyAttr\BDӿ\DAͬʱ\C9\E8\D6ø\DF\C7\E5\D3\EB\B1\EA\C7\E5ͨ\B5\C0\A3\AC\D2Ա\DC\C3\E2\D5\E2\D6\D6Ӱ\CF졣 CNend
   \param[in] enDisp               DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enEncodingFormat    DISP format.CNcomment:DISP\B5\C4\D6\C6ʽ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetFormat( HI_UNF_DISP_E enDisp, HI_UNF_ENC_FMT_E enEncodingFormat );


/**
   \brief get DISP format.CNcomment:\BB\F1ȡDISP\B5\C4\D6\C6ʽ CNend
   \attention \n
   none.CNcomment:\CE\DE CNend
   \param[in] enDisp               DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] penEncodingFormat    poiner of DISP format.DCNcomment:ISP\B5\C4\D6\C6ʽָ\D5\EB CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetFormat( HI_UNF_DISP_E enDisp, HI_UNF_ENC_FMT_E *penEncodingFormat );


/**
   \brief set user define LCD clock parameter.CNcomment:\C9\E8\D6\C3\D3û\A7\B6\A8\D2\E5\B5\C4LCDʱ\D0\F2\B2\CE\CA\FD CNend
   \attention \n
   only 3716 v100 v200 is  supported LCD.
   CNcomment:ֻ\D3\D03716 v100 v200 ֧\B3\D6LCD CNend
   \param[in] enDisp               DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstTiming    poiner of DISP format.CNcomment:LCDʱ\D0\F2\B2\CE\CA\FD CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetCustomTiming( HI_UNF_DISP_E enDisp, HI_UNF_DISP_TIMING_S *pstTiming );


/**
   \brief  get LCD parameter which had been config.CNcomment:\BB\F1ȡDISP\B5\C4LCD\B2\CE\CA\FD CNend
   \attention \n
   only 3716 v100 v200 is  supported LCD.
   CNcomment:ֻ\D3\D03716 v100 v200 ֧\B3\D6LCD CNend
   \param[in] enDisp          DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstTiming      pointer of LCD paramter.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACLCD\B2\CE\CA\FD CNend
   \retval ::HI_SUCCESS success.CNcomment: \B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetCustomTiming( HI_UNF_DISP_E enDisp, HI_UNF_DISP_TIMING_S *pstTiming );


/**
   \brief   set DISP layers Z order.CNcomment:\C9\E8\D6\C3DISP\C9ϵ\FE\BCӲ\E3\B5\C4Z\D0\F2 CNend
   \attention \n
   only 3716 v100 v200 is  supported LCD.
   CNcomment:ֻ\D3\D03716 v100 v200 ֧\B3\D6LCD CNend
   \param[in] enDisp          DISP channel ID.CNcomment: DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enLayer        layer ID which needed overlay to the DISP channel.CNcomment: DISP\C9ϵĵ\FE\BCӲ\E3 CNend
   \param[in] enZFlag        the way of overlay.CNcomment:Z\D0\F2\B5\F7\BDڷ\BDʽ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetLayerZorder( HI_UNF_DISP_E enDisp, HI_UNF_DISP_LAYER_E enLayer, HI_LAYER_ZORDER_E enZFlag );


/**
   \brief  get DISP overlay z order.CNcomment:\BB\F1ȡDISP\C9ϵ\FE\BCӲ\E3\B5\C4Z\D0\F2 CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
   CNcomment:\D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp            DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enLayer           CNcomment:DISP\C9ϵĵ\FE\BCӲ\E3 CNend
   \param[in] pu32Zorder        CNcomment:\B5\FE\BCӲ\E3Z\D0\F2\CA\FDֵ\A3\AC\CA\FDֵԽ\B4\F3\D3\C5\CFȼ\B6Խ\B8\DF CNend
   \retval ::HI_SUCCESS success.CNcomment: \B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation.CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetLayerZorder( HI_UNF_DISP_E enDisp, HI_UNF_DISP_LAYER_E enLayer, HI_U32 *pu32Zorder );


/**
   \brief set DISP back ground color.CNcomment:\C9\E8\D6\C3DISP\B1\B3\BE\B0ɫ CNend
   \attention \n
   none.
   CNcomment:\CE\DE CNend
   \param[in] enDisp       CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstBgColor   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C5\E4\D6õ\C4\CF\D4ʾ\CA\E4\B3\F6\B1\B3\BE\B0ɫ\A1\A3\C7\EB\B2μ\FB::HI_UNF_BG_COLOR_S CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetBgColor( HI_UNF_DISP_E enDisp, const HI_UNF_DISP_BG_COLOR_S *pstBgColor );


/**
   \brief  set DISP back ground color.CNcomment:\BB\F1ȡDISP\B1\B3\BE\B0ɫ CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
   CNcomment:\D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp          DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pstBgColor   pointer of back ground color.CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\CA\E4\B3\F6\B1\B3\BE\B0ɫ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetBgColor( HI_UNF_DISP_E enDisp, HI_UNF_DISP_BG_COLOR_S *pstBgColor );


/**
   \brief  set DISP brightness.CNcomment:\C9\E8\D6\C3DISP\C1\C1\B6\C8 CNend
   \attention \n
   if the value seted more than 100, we clip it to 100.CNcomment:\B4\F3\D3\DA100\B5\C4ֵ\B0\B4100\B4\A6\C0\ED CNend
   \param[in] enDisp            DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32Brightness   brightness value. the range is 0~100, 0 means the min brightness value.
   CNcomment:\B4\FD\C9\E8\D6õ\C4\CF\D4ʾ\CA\E4\B3\F6\C1\C1\B6\C8ֵ\A1\A3ȡֵ\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\D7\EEС\C1\C1\B6ȣ\BB100\A3\BA\D7\EE\B4\F3\C1\C1\B6\C8 CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetBrightness( HI_UNF_DISP_E enDisp, HI_U32 u32Brightness );


/**
   \brief   get the DISP brightness.CNcomment:\BB\F1ȡDISP\C1\C1\B6\C8 CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.
   CNcomment:\B2\E9ѯ\B5\C4Ĭ\C8\CF\C1\C1\B6\C8ֵΪ50\A1\A3\n
   \D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp              DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pu32Brightness    pointer of brightness. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\CA\E4\B3\F6\C1\C1\B6\C8ֵ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetBrightness( HI_UNF_DISP_E enDisp, HI_U32 *pu32Brightness );


/**
   \brief  set DISP contrast value.CNcomment:\C9\E8\D6\C3DISP\B6Աȶ\C8 CNend
   \attention \n
   If the value is more than 100, we clip it to 100.
   CNcomment:\B4\F3\D3\DA100\B5\C4ֵ\B0\B4100\B4\A6\C0\ED CNend
   \param[in] enDisp          DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32Contrast    contrast value. the range is 0~100, 0 means the min contrast value. \n
   CNcomment:\B4\FD\C9\E8\D6õ\C4\CF\D4ʾ\CA\E4\B3\F6\B6Աȶ\C8ֵ\A1\A3ȡֵ\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\D7\EEС\B6Աȶȣ\BB100\A3\BA\D7\EE\B4\F3\B6Աȶ\C8 CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetContrast( HI_UNF_DISP_E enDisp, HI_U32 u32Contrast );


/**
   \brief  get DISP contrast value.CNcomment:\BB\F1ȡDISP\B6Աȶ\C8 CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
   CNcomment:\B2\E9ѯ\B5\C4Ĭ\C8϶Աȶ\C8ֵΪ50\A1\A3\n
   \D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp           DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pu32Contrast   pointer of contrast. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\CA\E4\B3\F6\B6Աȶ\C8ֵ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetContrast( HI_UNF_DISP_E enDisp, HI_U32 *pu32Contrast );


/**
   \brief   set DISP saturation.CNcomment:\C9\E8\D6\C3DISP\B1\A5\BAͶ\C8 CNend
   \attention \n
   If the value is more than 100, we clip it to 100.
   CNcomment:\B4\F3\D3\DA100\B5\C4ֵ\B0\B4100\B4\A6\C0\ED CNend
   \param[in] enDisp             DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32Saturation      saturation value. the range is 0~100, 0 means the min saturation value. \n
   CNcomment:\B4\FD\C9\E8\D6õ\C4\CF\D4ʾ\CA\E4\B3\F6\B1\A5\BAͶ\C8ֵ\A1\A3ȡֵ\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\D7\EEС\B1\A5\BAͶȣ\BB100\A3\BA\D7\EE\B4󱥺Ͷ\C8 CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_DISP_SetSaturation( HI_UNF_DISP_E enDisp, HI_U32 u32Saturation );


/**
   \brief   get DISP saturation.CNcomment:\BB\F1ȡDISP\B1\A5\BAͶ\C8 CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
   CNcomment:\B2\E9ѯ\B5\C4Ĭ\C8ϱ\A5\BAͶ\C8ֵΪ50\A1\A3\n
   \D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp                 DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pu32Saturation    pointer of saturation. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\CA\E4\B3\F6\B1\A5\BAͶ\C8ֵ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetSaturation( HI_UNF_DISP_E enDisp, HI_U32 *pu32Saturation );


/**
   \brief  set DISP hueplus.CNcomment:\C9\E8\D6\C3DISPɫ\B5\F7 CNend
   \attention \n
   none.CNcomment:\CE\DE CNend
   \param[in] enDisp              DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32HuePlus       hueplus value. the range is 0~100, 0 means the min hueplus value. \n
   CNcomment:\CF\D4ʾ\CA\E4\B3\F6ɫ\B5\F7\D4\F6\D2\E6ֵ\A1\A3\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\B1\EDʾ\D7\EEСɫ\B5\F7\D4\F6\D2棻100\A3\BA\B1\EDʾ\D7\EE\B4\F3ɫ\B5\F7\D4\F6\D2\E6 CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetHuePlus( HI_UNF_DISP_E enDisp, HI_U32 u32HuePlus );


/**
   \brief get DISP hueplus.CNcomment:\BB\F1ȡDISPɫ\B5\F7 CNend
   \attention \n
   In the case of HD atach to SD. the Z order configuration of HD will auto sync to SD, also the configuration of SD will auto sync to HD.\n
   CNcomment:\B2\E9ѯ\B5\C4Ĭ\C8\CFɫ\B5\F7ֵΪ50\A1\A3\n
   \D4ڸ߱\EA\C7\E5\B0\F3\B6\A8\C7\E9\BF\F6\CF£\AC\B8\DF\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B1\EA\C7\E5DISP\A3\BB\B1\EA\C7\E5DISP\B5\C4\C9\E8\D6û\E1\D7Զ\AFͬ\B2\BD\B5\BD\B8\DF\C7\E5DISP\A1\A3 CNend
   \param[in] enDisp          DISP channel ID.CNcomment: DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pu32HuePlus     pointer of hueplus. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\CA\E4\B3\F6ɫ\B5\F7\D4\F6\D2\E6ֵ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetHuePlus( HI_UNF_DISP_E enDisp, HI_U32 *pu32HuePlus );


/**
   \brief  set Wss.CNcomment:ֱ\BD\D3\C9\E8\D6\C3WSS\A3\A8Wide Screen Singnalling\A3\A9\CA\FD\BE\DD CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp           DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstWssData        pointer of Wss data description structure.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2WSS\CA\FD\BEݵ\C4ָ\D5\EB CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetWss( HI_UNF_DISP_E enDisp, const HI_UNF_DISP_WSS_DATA_S *pstWssData );


/**
   \brief  set Macrovision mode.CNcomment:\C9\E8\D6\C3Macrovisionģʽ CNend
   \attention \n
   none.CNcomment:\CE\DE CNend
   \param[in] enDisp          DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enMode        Macrovision mode.  CNcomment:Macrovisionģʽ\A3\AC\C7\EB\B2μ\FB::HI_UNF_MACROVISION_MODE_E CNend
   \param[in] pData          pointer of Macrovision control data CNcomment: ָ\D5\EB\C0\E0\D0ͣ\AC\D7Զ\A8\D2\E5\B5\C4Macrovision\BF\D8\D6\C6\CA\FD\BE\DD CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetMacrovision( HI_UNF_DISP_E enDisp, HI_UNF_DISP_MACROVISION_MODE_E enMode, const HI_VOID *pData );


/**
   \brief get Macrovision mode.CNcomment: \BB\F1ȡMacrovisionģʽ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] penMode    pointer of Macrovision mode. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACMACROVISIONģʽ CNend
   \param[out] pData      a data pointer only valid whenpenMode=HI_MACROVISION_MODE_CUSTOM.\n
   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BD\F6\B5\B1penMode=HI_MACROVISION_MODE_CUSTOMʱ\D3\D0Ч CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetMacrovision( HI_UNF_DISP_E enDisp, HI_UNF_DISP_MACROVISION_MODE_E *penMode, const HI_VOID *pData );


/**
   \brief   set CGMS data.CNcomment:\C9\E8\D6\C3CGMS\A3\A8Copy Generation Management System\A3\A9\CA\FD\BE\DD CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp                   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstCgmsCfg             pointer of CGMS configuration  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2CGMS\C5\E4\D6\C3\CA\FD\BEݵ\C4ָ\D5\EB CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetCgms( HI_UNF_DISP_E enDisp, const HI_UNF_DISP_CGMS_CFG_S *pstCgmsCfg );


/**
   \brief chip do or not support Macrovision.CNcomment: \BB\F1ȡоƬ\CAǷ\F1֧\B3\D6Macrovision CNend
   \attention \n
   none.CNcomment:\CE\DE CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pbSupport    pointer of Macrovision flag. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACMacrovision \B1\EA־ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetMacrovisionSupport( HI_UNF_DISP_E enDisp, HI_BOOL *pbSupport );

/**
   \brief set aspect ratio attribute of display device.CNcomment: \C9\E8\D6\C3\C9豸\BF\ED\B8߱\C8 CNend
   \attention \n
   If set AspectRatio USER mode ,must be set u32UserAspectWidth and u32UserAspectHeight \n
   (theWidth/Height range is 1/64~64,if set zero means using current screen AspectRatio.) \n
   If not AspectRatio USER mode ,it will be set value by enumeration means;In this mode u32UserAspectWidth and u32UserAspectHeight are invalid ;\n
   If set AspectRatio AUTO mode , use current screen AspectRatio;
   CNcomment:\C8\E7\B9\FB\C9\E8\D6\C3USERģʽ\D4\F2\D0\E8\C9\E8\D6\C3u32UserAspectWidth \BA\CDu32UserAspectHeight\B5\C4ֵ\A3\AC\n
   \B8\B3ֵ\B7\B6ΧΪ\C1\BD\D5߱\C8ֵ1/64~64,\C8\E7\B9\FB\C9\E8\D6\C30\D4\F2\B1\EDʾʹ\D3õ\B1ǰ\C6\C1Ļ\B5Ŀ\ED\B8߱ȣ\BB\n
   \B7\C7USERģʽ\D4\F2\B0\B4\D5ն\D4Ӧ\B5ı\C8ֵ\C6\F0Чu32UserAspectWidth \BA\CDu32UserAspectHeight\B5\C4ֵ\CE\DEЧ\n
   \C6\E4\D6\D0\C9\E8\D6\C3AUTOģʽ\D4\F2\C9豸\BF\ED\B8߱\C8ֵ\D7Զ\AF\C9\E8\D6\C3Ϊ\B5\B1ǰ\C6\C1Ļ\B5Ŀ\ED\B8߱ȡ\A3 CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstDispAspectRatio    pointer of aspect ratio attribute of display device . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\C9豸\BF\ED\B8߱\C8\D0\C5Ϣ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetAspectRatio( HI_UNF_DISP_E enDisp, HI_UNF_DISP_ASPECT_RATIO_S *pstDispAspectRatio );


/**
   \brief get aspect ratio attribute of display device.CNcomment: \BB\F1\B5\C3\C9豸\BF\ED\B8߱\C8\CA\F4\D0\D4 CNend
   \attention \n
   none.
   CNcomment:\CE\DE CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pstDispAspectRatio    pointer of aspect ratio attribute of display device . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\C9豸\BF\ED\B8߱\C8\D0\C5Ϣ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetAspectRatio( HI_UNF_DISP_E enDisp, HI_UNF_DISP_ASPECT_RATIO_S *pstDispAspectRatio );


/**
   \brief set algorithmic attribute of display device.CNcomment: \C9\E8\D6\C3\C9豸\CB㷨\CA\F4\D0\D4 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstAlg    pointer of algorithmic attribute of display device . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\C9豸\CB㷨\CA\F4\D0\D4 CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetAlgCfg( HI_UNF_DISP_E enDisp, HI_UNF_DISP_ALG_CFG_S *pstAlg );


/**
   \brief get algorithmic status of display device.CNcomment: \BB\F1ȡ\C9豸\CB㷨\CA\F4\D0\D4 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pstAlg    pointer of algorithmic attribute of display device . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CF\D4ʾ\C9豸\CB㷨\CA\F4\D0\D4 CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetAlgCfg( HI_UNF_DISP_E enDisp, HI_UNF_DISP_ALG_CFG_S *pstAlg );


/**
   \brief create VBI data channel.CNcomment: \B4\B4\BD\A8VBI\CA\FD\BE\DDͨ\B5\C0 CNend
   \attention \n
   Each VBI type can not  created  repeatedly,if created more than one time,it will be return HI_ERR_DISP_CREATE_ERR;
   CNcomment:ÿ\D6\D6VBI\C0\E0\D0\CDֻ\C4ܴ\B4\BD\A8һ\B4Σ\AC\B6\E0\B4δ\B4\BD\A8\D4򷵻\D8HI_ERR_DISP_CREATE_ERR CNend
   \param[in] enDisp      DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstCfg    pointer of parameter of VBI channel . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACVBIͨ\B5\C0\B2\CE\CA\FD CNend
   \param[out] phVbi    pointer of VBI handle . CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACVBIͨ\B5\C0\BE\E4\B1\FA CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_CREATE_ERR    invalid operation. CNcomment:\B4\B4\BD\A8ʧ\B0\DC CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_CreateVBI( HI_UNF_DISP_E enDisp, HI_UNF_DISP_VBI_CFG_S *pstCfg, HI_HANDLE *phVbi );


/**
   \brief destroy VBI data channel.CNcomment: \CF\FA\BB\D9VBI\CA\FD\BE\DDͨ\B5\C0 CNend
   \attention \n
   none.
   CNcomment:\CE\DE CNend
   \param[in] hVbi      VBI handle ID.CNcomment:VBI ͨ\B5\C0\BE\E4\B1\FA CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_DestroyVBI( HI_HANDLE hVbi );


/**
   \brief send data to vbi channel.CNcomment: \B7\A2\CB\CD\CA\FD\BEݵ\BDVBIͨ\B5\C0 CNend
   \attention \n
   After  call HI_UNF_DISP_CreateVBI creat VBI handle sucess,you can call API HI_UNF_DISP_SendVBIData send VBI data .
   CNcomment:\B5\F7\D3\C3HI_UNF_DISP_CreateVBI \B4\B4\BD\A8VBIͨ\B5\C0\B3ɹ\A6\BA󣬲\C5\C4ܵ\F7\D3\C3HI_UNF_DISP_SendVBIData  \B7\A2\CB\CD\CA\FD\BE\DD CNend
   \param[in] hVbi      VBI handle ID.CNcomment:VBI ͨ·\BE\E4\B1\FA CNend
   \param[in] pstVbiData      pointer of VBI data.CNcomment:VBI\CA\FD\BE\DDָ\D5\EB CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SendVBIData(HI_HANDLE hVbi, HI_UNF_DISP_VBI_DATA_S *pstVbiData);

/**
   \brief Get default attributes of screen share channel.CNcomment: \BB\F1ȡ\C6\C1ĻͶӰͨ\B5\C0\B5\C4Ĭ\C8\CF\CA\F4\D0\D4 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[out]pstAttr     pointer of parameter .CNcomment:ָ\D5\EB,\C5\E4\D6ò\CE\CA\FD CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetDefaultCastAttr(HI_UNF_DISP_E enDisp,HI_UNF_DISP_CAST_ATTR_S *pstAttr);


/**
   \brief create screen share channel.CNcomment: \B4\B4\BD\A8\C6\C1ĻͶӰͨ\B5\C0 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[in] pstAttr      pointer of parameter .CNcomment:ָ\D5\EB,\C5\E4\D6ò\CE\CA\FD CNend
   \param[out] phCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_CreateCast(HI_UNF_DISP_E enDisp, HI_UNF_DISP_CAST_ATTR_S * pstAttr, HI_HANDLE *phCast);


/**
   \brief destroy screen share channel.CNcomment: \CF\FA\BB\D9\C6\C1ĻͶӰͨ\B5\C0 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] phCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_DestroyCast( HI_HANDLE hCast );


/**
   \brief enable screen share.CNcomment: ʹ\C4\DC\C6\C1ĻͶӰ\B9\A6\C4\DC CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] phCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \param[in] bEnable      enable screen share .CNcomment:ʹ\C4\DC\C6\C1ĻͶӰ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetCastEnable( HI_HANDLE hCast, HI_BOOL bEnable );


/**
   \brief get enable flag of screen share.CNcomment: \BB\F1ȡ\C6\C1ĻͶӰ\CAǷ\F1ʹ\C4\DC CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] phCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \param[out] bEnable     flag .CNcomment:\B1\EA־ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetCastEnable( HI_HANDLE hCast, HI_BOOL *pbEnable );


/**
   \brief get frame info of screen share.CNcomment: \BB\F1ȡ\C6\C1ĻͶӰ֡\D0\C5Ϣ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] hCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \param[out] pstFrameInfo        frame info.CNcomment:֡\D0\C5Ϣ CNend
   \param[in] u32TimeoutMs wait time in ms.CNcomment:\B5ȴ\FDʱ\BC䣬\BA\C1\C3\EBΪ\B5\A5λ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_TIMEOUT          operation timeout. CNcomment:\B2\D9\D7\F7\B3\ACʱ CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_AcquireCastFrame(HI_HANDLE hCast, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameInfo, HI_U32 u32TimeoutMs);


/**
   \brief release frame info of screen share.CNcomment: \CAͷ\C5\C6\C1ĻͶӰ֡\D0\C5Ϣ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] hCast      handle of screen share .CNcomment:\C6\C1ĻͶӰ\BE\E4\B1\FA CNend
   \param[in] pstFrameInfo     frame info.CNcomment:֡\D0\C5Ϣ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_ReleaseCastFrame( HI_HANDLE hCast, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameInfo );


/**
   \brief professional color modulation.CNcomment: רҵɫ\B2ʵ\F7\BD\DA CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[in] pstCS      struct of color modulation.CNcomment:ɫ\B2ʵ\F7\BDڽṹ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetColor( HI_UNF_DISP_E enDisp, HI_UNF_DISP_COLOR_SETTING_S *pstCS );


/**
   \brief get color modulation parameter.CNcomment: \BB\F1ȡɫ\B2ʵ\F7\BD\DA\D0\C5Ϣ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[in] pstCS      struct of color modulation.CNcomment:ɫ\B2ʵ\F7\BDڽṹ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetColor( HI_UNF_DISP_E enDisp, HI_UNF_DISP_COLOR_SETTING_S *pstCS );


/**
   \Snapshot truncation screen connection, intercepts the screen complete picture;CNcomment:\BD\D8ȡ\C6\C1Ļ\CD\EA\D5\FB\BB\AD\C3\E6; CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[out] pstFrameInfo     frame info.CNcomment:֡\D0\C5Ϣ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_AcquireSnapshot(HI_UNF_DISP_E enDisp, HI_UNF_VIDEO_FRAME_INFO_S * pstFrameInfo);

/**
   \Release Snapshot picture;CNcomment:\CAͷŽ\D8\C6\C1\BB\AD\C3\E6; CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \param[in] pstFrameInfo     frame info.CNcomment:֡\D0\C5Ϣ CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_ReleaseSnapshot(HI_UNF_DISP_E enDisp, HI_UNF_VIDEO_FRAME_INFO_S * pstFrameInfo);


/**
   \brief get color modulation parameter.CNcomment:\C9\E8\D6\C3DISP\B5\C4Ĭ\C8\CF\CA\F4\D0\D4 CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp      display channel.CNcomment:\CF\D4ʾͨ· CNend
   \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \retval ::HI_ERR_DISP_INVALID_OPT    invalid operation. CNcomment:\B2\D9\D7\F7\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetDefaultPara( HI_UNF_DISP_E enDisp);


/**
   \brief set DISP 3D format.CNcomment:\C9\E8\D6\C3DISP\B5\C43D\D6\C6ʽ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp           DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] en3D             DISP 3D mode.CNcomment:DISP 3Dģʽ CNend
   \param[in] enEncodingFormat DISP format.CNcomment:DISP\B5\C4\D6\C6ʽ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Set3DMode(HI_UNF_DISP_E enDisp, HI_UNF_DISP_3D_E en3D, HI_UNF_ENC_FMT_E enEncFormat);

/**
   \brief get DISP 3D format.CNcomment:\B2\E9ѯDISP\B5\C43D\D6\C6ʽ CNend
   \attention \n
   none. CNcomment:\CE\DE CNend
   \param[in] enDisp           DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pen3D           DISP 3D mode.CNcomment:DISP 3Dģʽ CNend
   \param[out] penEncFormat    DISP format.CNcomment:DISP\B5\C4\D6\C6ʽ CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_Get3DMode(HI_UNF_DISP_E enDisp, HI_UNF_DISP_3D_E *pen3D, HI_UNF_ENC_FMT_E *penEncFormat);

/**
   \brief set right eye first for 3D output.CNcomment:\C9\E8\D6\C33D\CA\E4\B3\F6\D3\D2\D1\DB\D3\C5\CF\C8 CNend
   \attention \n
   Only take effect in 3D output mode. CNcomment: \BD\F6\D4\DA3D\CA\E4\B3\F6ʱ\D3\D0Ч CNend
   \param[in] enDisp     DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] bEnable   Right-Eye-First.CNcomment:\D3\D2\D1\DB\D3\C5\CF\C8 CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetRightEyeFirst(HI_UNF_DISP_E enDisp, HI_BOOL bEnable);

/**
   \brief set virtual screen size of display.CNcomment:\C9\E8\D6\C3\CF\D4ʾͨ\B5\C0\B5\C4\D0\E9\C4\E2\C6\C1Ļ\B4\F3С CNend
   \attention \n
   if not set ,default value is 1280*720. CNcomment: \C8\E7\B9\FB\B2\BB\C9\E8\D6ô˺\AF\CA\FD\A3\ACĬ\C8ϵ\C4\D0\E9\C4\E2\C6\C1Ļ\B4\F3С\CA\C7720p. CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32Width  virtual screen width, the range is [480, 3840].CNcomment:\D0\E9\C4\E2\C6\C1Ļ\BF\ED\B6ȣ\ACȡֵ\B7\B6ΧΪ[480, 3840]. CNend
   \param[in] u32Height  virtual screen height, the range is [480, 3840].CNcomment:\D0\E9\C4\E2\C6\C1Ļ\B8߶ȣ\ACȡֵ\B7\B6ΧΪ[480, 3840]. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetVirtualScreen(HI_UNF_DISP_E enDisp, HI_U32 u32Width, HI_U32 u32Height);

/**
   \brief get virtual screen size of display.CNcomment:\BB\F1ȡ\CF\D4ʾͨ\B5\C0\B5\C4\D0\E9\C4\E2\C6\C1Ļ\B4\F3С CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] u32Width  virtual screen width, the range is [480, 3840].CNcomment:\D0\E9\C4\E2\C6\C1Ļ\BF\ED\B6ȣ\ACȡֵ\B7\B6ΧΪ[480, 3840]. CNend
   \param[out] u32Height  virtual screen height, the range is [480, 3840].CNcomment:\D0\E9\C4\E2\C6\C1Ļ\B8߶ȣ\ACȡֵ\B7\B6ΧΪ[480, 3840]. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetVirtualScreen(HI_UNF_DISP_E enDisp, HI_U32 *u32Width, HI_U32 *u32Height);


/**
   \brief set offset of display area in real screen.CNcomment:\C9\E8\D6\C3\CF\D4ʾ\C7\F8\D3\F2\D4\DAʵ\CC\E5\C6\C1Ļ\C9ϵ\C4ƫ\D2\C6\C1\BF,Ϊ\CE\EF\C0\ED\CF\F1\CBص\E3 CNend
   \attention \n
   must be 4 pixels aligned,if not set, the default value is 0. CNcomment: offset ֵ\B1\D8\D0\EB\CA\C74\B6\D4\C6\EB,\C8\E7\B9\FB\B2\BB\C9\E8\D6\C3Ĭ\C8ϵ\C4ֵΪ0. CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstOffset  offset in pixel, the range is [0, 200].CNcomment:ƫ\D2\C6\CF\F1\CB\D8\CA\FDĿ\A3\ACȡֵ\B7\B6ΧΪ[0, 200]. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetScreenOffset(HI_UNF_DISP_E enDisp, HI_UNF_DISP_OFFSET_S *pstOffset);

/**
   \brief get offset of display area in real screen.CNcomment:\BB\F1ȡ\CF\D4ʾ\C7\F8\D3\F2\D4\DAʵ\CC\E5\C6\C1Ļ\C9ϵ\C4ƫ\D2\C6\C1\BF,Ϊ\CE\EF\C0\ED\CF\F1\CBص\E3 CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pstOffset  offset in pixel, the range is [0, 200].CNcomment:ƫ\D2\C6\CF\F1\CB\D8\CA\FDĿ\A3\ACȡֵ\B7\B6ΧΪ[0, 200]. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetScreenOffset(HI_UNF_DISP_E enDisp, HI_UNF_DISP_OFFSET_S *pstOffset);

/**
   \brief set isogeny attributes. It is recommended to use HI_UNF_DISP_SetIsogenyAttr to \n
   set up both HD and SD DISP channels format when they have the same source.
   \attention \n
   none. CNcomment: \C9\E8\D6\C3ͬԴ\CA\F4\D0ԣ\ACͬԴģʽ\CF\C2\CDƼ\F6ʹ\D3øýӿ\DA\CC\E6\B4\FAHI_UNF_DISP_SetFormat \n
    \C0\B4ͬʱ\C9\E8\D6ø\DF\C7\E5ͨ\B5\C0\D3\EB\B1\EA\C7\E5ͨ\B5\C0\B5\C4\D6\C6ʽ\A1\A3 CNend
   \param[in] pstIsogeny isogenous attributes.CNcomment:ͬԴģʽ\CF£\ACҪ\C9\E8\D6õ\C4\CA\F4\D0\D4\D0\C5Ϣ CNend
   \param[in] u32ChannelNum  channel counts to be set in isogenous mode.CNcomment:ͬԴģʽ\CF£\ACҪ\C9\E8\D6\C3\CA\F4\D0Ե\C4ͨ\B5\C0\B8\F6\CA\FD CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetIsogenyAttr(const HI_UNF_DISP_ISOGENY_ATTR_S *pstIsogeny, const HI_U32 u32ChannelNum);

/**
   \brief set display output type.CNcomment: \C9\E8\D6\C3\CF\D4ʾ\CA\E4\B3\F6\C0\E0\D0\CD CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enHDRType   DISP type.CNcomment:HDR \CA\E4\B3\F6\C0\E0\D0\CDCNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetHDRType(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_HDR_TYPE_E enHDRType);

/**
   \brief Get display output type.CNcomment: \BB\F1ȡ\CF\D4ʾ\CA\E4\B3\F6\C0\E0\D0\CD CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] penHDRType   DISP type.CNcomment:HDR\CA\E4\B3\F6\C0\E0\D0\CDCNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetHDRType(HI_UNF_DISP_E enDisp, HI_UNF_DISP_HDR_TYPE_E *penHDRType);

/**
   \brief Set display output color space.CNcomment: \C9\E8\D6\C3\CA\E4\B3\F6ɫ\B2ʿռ\E4 CNend
   \attention \n
   should set sink capability with HI_UNF_DISP_SetSinkCapability api when set auto out color space.
   CNcomment: \C9\E8\D6\C3AUTO\CA\E4\B3\F6ʱ\A3\AC\B1\D8\D0\EB\CFȵ\F7\D3\C3HI_UNF_DISP_SetSinkCapability\BDӿ\DA CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enColorSpace output color space.CNcomment:\C9\E8\D6\C3\CA\E4\B3\F6ɫ\B2ʿռ\E4CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetOutputColorSpace(HI_UNF_DISP_E enDisp, const HI_UNF_DISP_COLOR_SPACE_E enColorSpace);

/**
   \brief Get display output color space.CNcomment: \BB\F1ȡ\CA\E4\B3\F6ɫ\B2ʿռ\E4 CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] penColorSpace output color space.CNcomment:\BB\F1ȡ\CA\E4\B3\F6ɫ\B2ʿռ\E4CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetOutputColorSpace(HI_UNF_DISP_E enDisp, HI_UNF_DISP_COLOR_SPACE_E *penColorSpace);

/**
   \brief Set capability of sink .CNcomment: \C9\E8\D6\C3Sink\B6\CB\C4\DC\C1\A6\BC\AFCNend
   \attention \n
    Sink capability can acquire from hdmi, Strongly recommend to set sink capability when detect hdmi hot-plot event .
    CNcomment: \BFɴ\D3HDMI\BDӿ\DA\D6л\F1ȡ\B5\BDSink\B6˵\C4\C4\DC\C1\A6\BC\AF\A3\ACǿ\C1ҽ\A8\D2\E9\D4\DAÿһ\B4\CE\C8Ȳ\E5\B0\CE\CA¼\FE\B1\BB\BC\EC\B2⵽ʱ\D6\D8\D0\C2\C9\E8\D6\C3Sink \C4\DC\C1\A6\BC\AF CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pstSinkCap output color space.CNcomment:\C9\E8\D6\C3Sink\B6\CB\C4\DC\C1\A6\BC\AFCNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetSinkCapability( HI_UNF_DISP_E enDisp, const HI_UNF_EDID_BASE_INFO_S *pstSinkCap);

/**
   \brief Set alpha of video .CNcomment: \C9\E8\D6\C3\CA\D3ƵalphaֵCNend
   \attention \n
    none  CNcomment: \CE\DECNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] u32Alpha video alpha value.CNcomment:\CA\D3Ƶ\B5\C4alphaֵCNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetVideoAlpha( HI_UNF_DISP_E enDisp, HI_U32 u32Alpha );

/**
   \brief Get alpha of video .CNcomment: \BB\F1ȡ\CA\D3ƵalphaֵCNend
   \attention \n
    none CNcomment: \CE\DE CNend
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] pu32Alpha video alpha value.CNcomment:\BB\F1ȡ\B5\C4\CA\D3ƵalphaֵCNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetVideoAlpha(HI_UNF_DISP_E enDisp, HI_U32 *pu32Alpha);


/**
   \brief Get display output status Information.CNcomment: \BB\F1ȡ\CF\D4ʾ\CA\E4\B3\F6״̬\D0\C5Ϣ CNend
   \attention \n
   none. CNcomment: \CE\DE CNend
   \param[in] enDisp DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[out] pstOutputStatus.CNcomment: \CA\E4\B3\F6״̬\D0\C5ϢCNend
   \retval ::HI_SUCCESS success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetOutputStatus(HI_UNF_DISP_E enDisp, HI_UNF_DISP_OUTPUT_STATUS_S *pstOutputStatus);


/**
   \brief set hdr mixed priority mode.CNcomment:\C9\E8\D6\C3hdr\B5ĵ\FE\BC\D3\D3\C5\CFȼ\B6ģʽ CNend
   \attention: only take effect when output type is DolbyVision.CNcomment:\B5\B1ǰ\BD\F6\D4\DADolbyVision\CA\E4\B3\F6\B3\A1\BE\B0\CF²\C5\C9\FAЧ CNend\n
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] enPriorityMode hdr priority mode.CNcomment:hdr\D3\C5\CFȼ\B6ģʽ. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_SetHDRPriorityMode(HI_UNF_DISP_E enDisp, HI_UNF_DISP_HDR_PRIORITY_MODE enPriorityMode);

/**
   \brief get hdr mixed priority mode.CNcomment:\BB\F1ȡhdr\B5ĵ\FE\BC\D3\D3\C5\CFȼ\B6ģʽ CNend
   \attention \n
   \param[in] enDisp   DISP channel ID.CNcomment:DISPͨ\B5\C0\BA\C5 CNend
   \param[in] penPriorityMode hdr priority mode.CNcomment:hdr\D3\C5\CFȼ\B6ģʽ. CNend
   \retval ::HI_SUCCESS  success.CNcomment:\B3ɹ\A6 CNend
   \retval ::HI_ERR_DISP_NO_INIT    DISP uninitialization.CNcomment:DISPδ\B3\F5ʼ\BB\AF CNend
   \retval ::HI_ERR_DISP_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
   \see \n
   none.CNcomment:\CE\DE CNend
 */
HI_S32 HI_UNF_DISP_GetHDRPriorityMode(HI_UNF_DISP_E enDisp, HI_UNF_DISP_HDR_PRIORITY_MODE *penPriorityMode);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
