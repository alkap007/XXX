#ifndef __HI_GO_TEXT_H__
#define __HI_GO_TEXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/***************************** Macro Definition ******************************/


/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_TEXT */
/** @{ */  /** <!\A1\AA[HIGO_TEXT] */

#define LAYOUT_LEFT          HIGO_LAYOUT_LEFT     /**<Horizontally left*//**<CNcomment:ˮƽ\BE\D3\D7\F3*/
#define LAYOUT_RIGHT         HIGO_LAYOUT_RIGHT    /**<Horizontally right*//**<CNcomment:ˮƽ\BE\D3\D3\D2*/
#define LAYOUT_HCENTER       HIGO_LAYOUT_HCENTER  /**<Horizontally center*//**<CNcomment:ˮƽ\BE\D3\D6\D0*/
#define LAYOUT_TOP           HIGO_LAYOUT_TOP      /**<Vertically top*//**<CNcomment:\B4\B9ֱ\BEӶ\A5*/
#define LAYOUT_BOTTOM        HIGO_LAYOUT_BOTTOM   /**<Vertically bottom*//**<CNcomment:\B4\B9ֱ\BEӵ\D7*/
#define LAYOUT_VCENTER       HIGO_LAYOUT_VCENTER  /**<Vertically center*//**<CNcomment:\B4\B9ֱ\BE\D3\D6\D0*/
#define LAYOUT_WRAP          HIGO_LAYOUT_WRAP     /**<Wrap*//**<CNcomment:\D7Զ\AF\BB\BB\D0\D0*/
#define LAYOUT_WORDELLIPSIS  HIGO_LAYOUT_WORDELLIPSIS /**<Ellipsis format*//**<CNcomment:ʹ\D3\C3ʡ\C2Ժŷ\E7\B8\F1*/
#define LAYOUT_FORCE_LEFT    HIGO_LAYOUT_FORCE_LEFT     /**<Force Horizontally left*//**<CNcomment:ǿ\D6\C6ˮƽ\BE\D3\D7\F3*/
#define LAYOUT_FORCE_RIGHT   HIGO_LAYOUT_FORCE_RIGHT    /**<Force Horizontally right*//**<CNcomment:ǿ\D6\C6ˮƽ\BE\D3\D3\D2*/

/** */
typedef enum
{
    HIGO_LAYOUT_LEFT             = 0x0001,
    HIGO_LAYOUT_RIGHT            = 0x0002,
    HIGO_LAYOUT_HCENTER          = 0x0004,
    HIGO_LAYOUT_WRAP             = 0x0008,
    HIGO_LAYOUT_WORDELLIPSIS     = 0x0010,
    HIGO_LAYOUT_TOP              = 0x0100,
    HIGO_LAYOUT_BOTTOM           = 0x0200,
    HIGO_LAYOUT_VCENTER          = 0x0400,
    HIGO_LAYOUT_FORCE_LEFT       = 0x8000,
    HIGO_LAYOUT_FORCE_RIGHT      = 0x10000,
    HIGO_LAYOUT_VERTICAL         = 0x20000,
    HIGO_LAYOUT_BUTT             = 0x40000,
} HIGO_LAYOUT_E;

/**<Definition of a character set*//** CNcomment: \D7ַ\FB\BC\AF\B6\A8\D2\E5 */
typedef enum
{
    HIGO_CHARSET_UNKOWN,
    HIGO_CHARSET_ASCI,
    HIGO_CHARSET_GB2312,
    HIGO_CHARSET_UTF8,
    HIGO_CHARSET_UTF16,
    HIGO_CHARSET_UCS2 = HIGO_CHARSET_UTF16,
    HIGO_CHARSET_UTF32,
    HIGO_CHARSET_BUTT,
} HIGO_CHARSET_E;

/** Definition of a text base direction*//** CNcomment: \CEı\BE\CA\E4\B3\F6\BB\F9\B4\A1\B7\BD\CF\F2\B6\A8\D2\E5*/
typedef enum
{
    HIGO_TEXT_DIR_NEUTRAL = 0,/**<neutral deirction*//**<CNcomment:\D6\D0\D0Է\BD\CF򣬰\B4\C4\DA\C8ݲ\E9\D5\D2ǿ\D7ַ\FB\B7\BD\CF\F2*/
    HIGO_TEXT_DIR_LTR,/**<Left to right*//**<CNcomment:\B4\D3\D7\F3\B5\BD\D3ҷ\BD\CF\F2 */
    HIGO_TEXT_DIR_RTL,/**<Right to left*//**<CNcomment:\B4\D3\D3ҵ\BD\D7\F3\B7\BD\CF\F2 */
    HIGO_TEXT_DIR_BUTT
} HIGO_TEXT_DIR_E;


typedef struct
{
    HIGO_CHARSET_E Charset; /**<Character set name*//**<CNcomment:\D7ַ\FB\BC\AF\C3\FB\B3\C6 */
    HI_U8 Height;         /**<Font height*//**<CNcomment:\D7\D6\CC\E5\B8߶\C8 */
    HI_U8 MaxWidth;      /**<Maximum font width*//**<CNcomment:\D7\D6\CC\E5\D7\EE\B4\F3\BF\ED\B6\C8 */
}HIGO_FONTATTR_S;

/** Attributes of a text output object*//** CNcomment: \CEı\BE\CA\E4\B3\F6\B6\D4\CF\F1\CA\F4\D0\D4 */
typedef struct
{
    HI_COLOR        BgColor;     /**<Background color*//**<CNcomment:\B1\B3\BE\B0ɫ */
    HI_COLOR        FgColor;     /**<Foreground color*/ /**<CNcomment:ǰ\BE\B0ɫ */
    HIGO_FONTATTR_S SbFontAttr;  /**<Font attributes of the single-byte character set*/ /**<CNcomment:\B5\A5\D7ֽ\DA\D7ַ\FB\BC\AF\D7\D6\CC\E5\CA\F4\D0\D4 */
    HIGO_FONTATTR_S MbFontAttr;  /**<Font attributes of the multi-byte character set*//**<CNcomment:\B6\E0\D7ֽ\DA\D7ַ\FB\BC\AF\D7\D6\CC\E5\CA\F4\D0\D4 */
} HIGO_TEXTOUTATTR_S;

typedef enum
{
    HIGO_TEXT_STYLE_NORMAL = 0x00, /**<Normal font*//**<CNcomment:\D5\FD\B3\A3\D7\D6\CC\E5*/
    HIGO_TEXT_STYLE_ITALIC = 0x01, /**<Italic font*//**<CNcomment:б\CC\E5\D7\D6\CC\E5*/
    HIGO_TEXT_STYLE_BOLD   = 0x02, /**<Bold font*//**<CNcomment:\B4\D6\CC\E5\D7\D6\CC\E5*/
    HIGO_TEXT_STYLE_HALF_HEIGHT   = 0x04, /**<Half-height font *//**<CNcomment:\B0\EB\B8\DF\D7\D6\CC\E5 */
    HIGO_TEXT_STYLE_HALF_WIDTH    = 0x08, /**<Half-width font *//**<CNcomment:\B0\EB\BF\ED\D7\D6\CC\E5 */
    HIGO_TEXT_STYLE_DOUBLE_HEIGHT = 0x10, /**<Double-height font *//**<CNcomment:˫\B1\B6\B8߶\C8\D7\D6\CC\E5*/
    HIGO_TEXT_STYLE_DOUBLE_WIDTH  = 0x20, /**<Double-widht font *//**<CNcomment:˫\B1\B6\BF\ED\B6\C8\D7\D6\CC\E5*/
    HIGO_TEXT_STYLE_BUTT          = 0x40
} HIGO_TEXT_STYLE_E;

typedef struct{
    HI_HANDLE     hFont;           	 /**<Handle of font file*//**<CNcomment:\D7\D6\CC\E5\BE\E4\B1\FA*/
    HI_U32        Style;             /**<Layout style*//**<CNcomment:\B2\BC\BE\D6\C0\E0\D0\CD*/
    HI_S32        s32Width;    	     /**<Width of display arear*//**<CNcomment:\CF\D4ʾ\C7\F8\D3\F2\BF\ED\B6\C8*/
    HI_S32        s32Height;         /**<Height of display arear*//**<CNcomment:\CF\D4ʾ\C7\F8\D3\F2\B8߶\C8*/
    HI_S32  	  horz_dist;         /**<Character horizontal spacing*//**<CNcomment:\D7ַ\FB\BC\E4\BE\E0 */
    HI_S32  	  vert_dist;         /**<Raw vertical spacing*//**<CNcomment:\D0м\E4\BE\E0,һ\D0\D0\CE\C4\D7\D6\CF\C2\CFߺ\CD\CF\C2\D0\D0\CE\C4\D7\D6\C9\CF\CF\DF֮\BC\E4\B5ľ\E0\C0\EB*/
    HI_BOOL       single_para_flg;   /**<Whether it is a single paragraph *//**<CNcomment:\CAǷ\F1Ϊ\B5\A5\B6\CE\C2\E4 */
    HI_BOOL    	  auto_dir;          /**<Whether it is automatic direction*//**<CNcomment:\CAǷ\F1Ϊ\D7Զ\AF\B7\BD\CF\F2 */
    HIGO_TEXT_DIR_E base_dir;        /**<Base direction*//**<CNcomment: \BB\F9\B1\BE\B7\BD\CF\F2 */
    HI_U32        max_char;          /**<Max character*//**<CNcomment:\D7\EE\B4\F3\D7ַ\FB\CA\FD\C1\BF */
    HI_COLOR      select_bg;         /**<Selected background color*//**<CNcomment:ѡ\D6еı\B3\BE\B0ɫ*/
    HI_COLOR      select_fg;         /**<Selected frontground color*//**<CNcomment:ѡ\D6е\C4ǰ\BE\B0ɫ*/
}HIGO_LAYOUT_INFO_S;

typedef struct
{
    const HI_CHAR* pSbcFontFile;/**<Single-byte character font file.*//**<CNcomment:\B5\A5\D7ֽ\DA\D7\D6\CC\E5\CEļ\FE*/
    const HI_CHAR* pMbcFontFile;/**<Multi-byte character font file.*//**<CNcomment:\B6\E0\D7ֽ\DA\D7\D6\CC\E5\CEļ\FE*/
    HI_U32   u32Size; /**<This value is ignored for the dot-matrix font.*//**<CNcomment:\C8\E7\B9\FB\CAǵ\E3\D5\F3\D7\D6\CC壬\D4\F2\B8\C3ֵ\B1\BB\BA\F6\C2\D4*/
} HIGO_TEXT_INFO_S;

typedef enum{
	HIGO_LAYOUT_MOVECURSOR_UP,    /**< move cursor to up position*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\C9Ϸ\BDλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_DOWN,  /**< move cursor to down position*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\CF·\BDλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_PREV,  /**< move cursor to previous postion*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BDǰһ\B8\F6λ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_NEXT,  /**< move cursor to next position*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\BA\F3һ\B8\F6λ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_LEFT,  /**< move cursor to left position*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\D7\F3\B7\BDλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_RIGHT, /**< move cursor to right positon*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\D3ҷ\BDλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_SOT,   /**< move cursor to start position of text*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\CEı\BE\BF\AAʼλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_EOT,   /**< move curosr to end position of text*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\CEı\BE\BD\E1\CA\F8λ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_SOL,   /**< move cursor to start of current line*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\B5\B1ǰ\D0п\AAʼλ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_EOL,   /**< move cursor to end of current line*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\B5\B1ǰ\D0н\E1\CA\F8λ\D6\C3*/
	HIGO_LAYOUT_MOVECURSOR_SOP,   /**< move cursor to start of current paragraph*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\B5\B1ǰ\B6\CE\C2\E4\B5Ŀ\AAͷ*/
	HIGO_LAYOUT_MOVECURSOR_EOP,   /**< move cursor to end of current paragraph*//**<CNcomment:\BD\AB\B9\E2\B1\EA\D2ƶ\AF\B5\BD\B5\B1ǰ\B6\CE\C2\E4\B5\C4ĩβ*/
	HIGO_LAYOUT_MOVECURSOR_BUTT,
}HIGO_TEXT_CURSOR_DIR_E;

/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_TEXT */
/** @{ */  /** <!\A1\AA[HIGO_TEXT] */

/**
\brief Creates a text output object.CNcomment: \B4\B4\BD\A8\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3 CNend
\attention \n
The values of pSbFontFile and pMbFontFile cannot be empty at the same time. If the received file name is in vector
font, the font height is set based on the 22-dot array.
CNcomment: pSbFontFile\BA\CDpMbFontFile\B2\BB\BF\C9ͬʱΪ\BF\D5,\C8\E7\B9\FB\B4\AB\C8\EB\B5\C4\CA\C7ʸ\C1\BF\D7\D6\CC\E5\CEļ\FE\C3\FB,\D4\F2\D7\D6\CC\E5\B8߶Ȱ\B4
22\B5\E3\D5󴴽\A8 CNend
\param[in] pSbFontFile Font file of the single-byte character set. If the value is empty, it indicates that the single
-byte character set library is not used.CNcomment: \B5\A5\D7ֽ\DA\D7ַ\FB\BC\AF\D7\D6\CC\E5\CEļ\FE\A3\ACΪ\BFձ\EDʾ\B2\BBʹ\D3õ\A5\D7ֽ\DA\D7ַ\FB\BC\AF\D7ֿ\E2 CNend
\param[in] pMbFontFile  Font file of the multi-byte character set. If the value is empty, it indicates that the multi-
byte character set library is not used. Ensure that the font files of the single-byte and multi-byte character sets
cannot be empty concurrently.CNcomment: \B6\E0\D7ֽ\DA\D7ַ\FB\BC\AF\D7\D6\CC\E5\CEļ\FE\A3\ACΪ\BFձ\EDʾ\B2\BBʹ\D3ö\E0\D7ֽ\DA\D7ַ\FB\BC\AF\D7ֿ⣬\B5\AB\CAǲ\BB\C4\DC\D3뵥\D7ֽ\DA\D7ַ\FB\CEļ\FEͬʱΪ\BFա\A3 CNend
\param[out]  pTextOut Handle of a text output object.CNcomment: \CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NOMEM

\see \n
::HI_GO_DestroyText
*/
HI_S32 HI_GO_CreateText(const HI_CHAR* pSbFontFile, const HI_CHAR* pMbFontFile, HI_HANDLE* pTextOut);

/**
\brief Destroys a text output object.CNcomment:\CF\FA\BB\D9\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_CreateText
*/
HI_S32 HI_GO_DestroyText(HI_HANDLE TextOut);

/**
\brief set the input charset. CNcomment:\C9\E8\D6\C3\CA\E4\C8\EB\D7ַ\FB\BC\AF CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[out] CharSet  charset of input text.CNcomment:\CA\E4\C8\EB\CEı\BE\D7ַ\FB\BC\AF\BA\CF CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
::HI_GO_CreateText
*/
HI_S32 HI_GO_SetInputCharSet(HI_HANDLE TextOut, HIGO_CHARSET_E CharSet);

/**
\brief Obtains the attributes of a text output object.CNcomment:\BB\F1ȡ\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\CA\F4\D0\D4 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[out] pTextOutAttr  Attributes of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\CA\F4\D0\D4 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetTextAttr(HI_HANDLE TextOut,HIGO_TEXTOUTATTR_S *pTextOutAttr);

/**
\brief Obtains the width and height of text contents.CNcomment:\BB\F1ȡ\CEı\BE\C4\DA\C8ݵĿ\ED\B8\DF CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] pText Text contents.CNcomment:\CEı\BE\C4\DA\C8\DD CNend
\param[out] pWidth Width of text contents. It cannot be empty.CNcomment:\CEı\BE\C4\DA\C8ݿ\ED\B6ȣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pHeight Height of text contents. It cannot be empty.CNcomment:\CEı\BE\C4\DA\C8ݸ߶ȣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetTextExtent(HI_HANDLE TextOut, const HI_CHAR *pText, HI_S32 *pWidth, HI_S32 *pHeight);

/**
\brief Obtains the width and height of vertical text contents.CNcomment:\BB\F1ȡ\CA\FA\C5\C5\CEı\BE\C4\DA\C8ݵĿ\ED\B8\DF CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] pText Text contents.CNcomment:\CEı\BE\C4\DA\C8\DD CNend
\param[out] pTextWidth Actual width of text contents. It cannot be empty.CNcomment:\CEı\BE\C4\DA\C8\DDʵ\BCʿ\ED\B6ȣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pHeight Height of text contents. It cannot be empty.CNcomment:\CEı\BE\C4\DA\C8ݸ߶ȣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[out] pLayoutAreaWidth Minmal width of layout area. It cannot be empty.CNcomment:\CEı\BE\C5Ű\E6\C7\F8\D3\F2\B5\C4\D7\EEС\BF\ED\B6ȣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORT_CHARSET

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_GetVerticalTextExtent(HI_HANDLE hFont, const HI_CHAR *pText,
                                   HI_S32 *pTextWidth, HI_S32 *pHeight, HI_S32 *pLayoutAreaWidth);

/**
\brief Sets to display the background color of a text output object.CNcomment:\C9\E8\D6\C3\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\B5ı\B3\BE\B0ɫ\CAǷ\F1\CF\D4ʾ CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] bTransparent  Whether to display the background color of a text output object. If the value is set to
HI_TRUE, the background color is not displayed. The default value is HI_TRUE.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF󱳾\B0ɫ\CAǷ\F1\CF\D4ʾ\A3\ACΪHI_TRUE, \D4\F2\B2\BB\CF\D4ʾ\A3\ACĬ\C8\CFΪHI_TRUE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/ACNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetTextBGTransparent(HI_HANDLE TextOut, HI_BOOL bTransparent);

/**
\brief Sets the background color of a text output object.CNcomment:\C9\E8\D6\C3\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\B5ı\B3\BE\B0ɫ CNend
\attention \n
If the target surface is a palette, the color is the palette index.CNcomment:\C8\E7\B9\FBĿ\B1\EAsurface\CAǵ\F7ɫ\B0壬\D4\F2Color\CAǵ\F7ɫ\B0\E5\CB\F7\D2\FD CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] Color  Background color of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF󱳾\B0ɫ\A3\ACCNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetTextBGColor(HI_HANDLE TextOut, HI_COLOR Color);

/**
\brief Sets the font color of a text output object.CNcomment: \C9\E8\D6\C3\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\B5\C4\D7\D6\CC\E5\D1\D5ɫ CNend
\attention \n
If the target surface is a palette, the color is the palette index.CNcomment: \C8\E7\B9\FBĿ\B1\EAsurface\CAǵ\F7ɫ\B0壬\D4\F2Color\CAǵ\F7ɫ\B0\E5\CB\F7\D2\FD CNend
\param[in] TextOut Handle of a text output object.CNcomment: \CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] Color  Font color of a text output object.CNcomment: \CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\D7\D6\CC\E5\D1\D5ɫ CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment: \CE\DE CNend
*/
HI_S32 HI_GO_SetTextColor(HI_HANDLE TextOut, HI_COLOR Color);

/**
\brief Outputs text contents to a specified surface.CNcomment:\CA\E4\B3\F6\CEı\BE\C4\DA\C8ݵ\BDָ\B6\A8surface CNend
\attention
N/A.CNcomment:\CE\DE CNend
\param[in] TextOut Handle of a text output object.CNcomment:\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BE\E4\B1\FA CNend
\param[in] Surface Surface handle.CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] pText  Text contents.CNcomment:\CEı\BE\C4\DA\C8\DD CNend
\param[in] pRect Text output region. If the value is empty, it indicates that text contents are output from the
surface origin.CNcomment:\CEı\BE\CA\E4\B3\F6\C7\F8\D3\F2\A3\ACΪ\BFձ\EDʾ\B4\D3surfaceԭ\B5\E3\CA\E4\B3\F6 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_TextOut(HI_HANDLE TextOut,HI_HANDLE Surface, const HI_CHAR *pText,
                           const HI_RECT *pRect);

/**
\brief Outputs texts. This API is an extended API. You can call this API to output contents based on customized
styles and formatting.CNcomment:\CEı\BE\CA\E4\B3\F6\C0\A9չ\BDӿ\DA,\CA\E4\B3\F6\C4\DA\C8ݿ\C9\D2԰\B4\D5\D5\D3û\A7ָ\B6\A8\B5\C4\C5Ű\E6\BD\F8\D0\D0\CA\E4\B3\F6\A1\A3CNend
\param[in] hTextOut Text output handle.CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] hSurface Surface handle.CNcomment:Surface\BE\E4\B1\FA CNend
\param[in] pText    Text contents ending with /0.CNcomment:\D2\D4/0\BD\E1β\B5\C4\CEı\BE\C4\DA\C8\DD CNend
\param[in] pRect    Text output region.CNcomment:\CEı\BE\CA\E4\B3\F6\C7\F8\D3\F2 CNend
\param[in] Style    Styles and formatting including LAYOUT_LEFT, LAYOUT_RIGHT, and LAYOUT_HCENTER.CNcomment:\C5Ű\E6\B8\F1ʽ\A3\AC\C8\E7LAYOUT_LEFT\A1\A2LAYOUT_RIGHT\A1\A2LAYOUT_HCENTER\B5\C8 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_TextOutEx(HI_HANDLE hTextOut, HI_HANDLE hSurface,
                               const HI_CHAR *pText,  const HI_RECT *pRect,
                               HIGO_LAYOUT_E Style);

/**
\brief Calculates the number of characters in a specified text output region.CNcomment: \BC\C6\CB\E3ָ\B6\A8\CEı\BE\CA\E4\B3\F6\C7\F8\D3\F2\D7ַ\FB\B8\F6\CA\FD CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] hTextOut Text output handle.CNcomment: \CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] pText    Text contents ending with /0.CNcomment: \D2\D4/0\BD\E1β\B5\C4\CEı\BE\C4\DA\C8\DD CNend
\param[in] pRect    Text output region. The value cannot be empty.CNcomment: \CEı\BE\CA\E4\B3\F6\C7\F8\D3\F2,\B2\BB\BF\C9Ϊ\BF\D5 CNend
\param[in] pLen      Pointer to the string length.CNcomment: \D7ַ\FB\B4\AE\B3\A4\B6\C8ָ\D5\EB CNend

\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVHANDLE
\retval ::HI_SUCCESS

\see \n
N/A.CNcomment: \CE\DE CNend
*/
HI_S32 HI_GO_GetTextExtentEx(HI_HANDLE TextOut, const HI_CHAR *pText,
                                       const HI_RECT *pRect, HI_U32 *pLen);

/**
\brief Creates a font.CNcomment:\B4\B4\BD\A8\D7\D6\CC\E5 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] phText Text output handle.CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] pInfo  Text information.CNcomment:\CEļ\FE\D0\C5Ϣ CNend

\retval ::HI_SUCCESS A font is created successfully.CNcomment:\D7\D6\CC崴\BD\A8\B3ɹ\A6 CNend
\retval ::HI_FAILURE A font fails to be created.CNcomment:\D7\D6\CC崴\BD\A8ʧ\B0\DC CNend
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_CreateTextEx(const HIGO_TEXT_INFO_S* pInfo, HI_HANDLE* phText);

/**
\brief Sets the style of a font, such as bold, italic, or normal.CNcomment:\C9\E8\D6\C3\D7\D6\CC\E5\B5ķ\E7\B8񣬱\C8\C8\E7:\B4\D6\CC壬б\CC壬\D5\FD\B3\A3\CC\E5 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param[in] hTextOut Text output handle.CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] eStyle   Font style.CNcomment:\D7\D6\CC\E5\B7\E7\B8\F1 CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetTextStyle(HI_HANDLE hTextOut, HIGO_TEXT_STYLE_E eStyle);



/**
\brief Sets the the text base direction
lines.CNcomment:\C9\E8\D6\C3\CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\B5Ļ\F9\B1\BE\B7\BD\CF\F2 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend

\param[in] hTextOut Text output handle. CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] BaseDir the base direction of the text. CNcomment: \CEı\BE\CA\E4\B3\F6\B6\D4\CF\F3\BB\F9\B1\BE\B7\BD\CF\F2 CNend

\retval ::HI_SUCCESS Success.CNcomment: \B3ɹ\A6 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:ʧ\B0\DC CNend

\see \n
N/A.CNcomment:\CE\DE CNend
*/

HI_S32 HI_GO_SetBaseDir(HI_HANDLE TextOut, HIGO_TEXT_DIR_E eBaseDir);
/**
\brief Sets the horizontal spacing between displayed characters, that is, the horizontal spacing between character
lines.CNcomment:\C9\E8\D6\C3\D7ַ\FB\CF\D4ʾˮƽ\BC\E4\BE࣬\C1\BD\B8\F6\D7ַ\FB\D0\D0ˮƽ\BC\E4\BE\E0 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend

\param[in] hTextOut Text output handle.CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] u32Distance Horizontal spacing.CNcomment:ˮƽ\BC\E4\BE\E0 CNend

\retval ::HI_SUCCESS Success.CNcomment: \B3ɹ\A6 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:ʧ\B0\DC CNend

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetCharExtra(HI_HANDLE hTextOut, HI_U32 u32Distance);

/**
\brief Sets the vertical and horizontal spacing.CNcomment:\C9\E8\D6ô\B9ֱˮƽ\BC\E4\BE\E0 CNend
\attention \n
This API is available only when the font style is changed.CNcomment:ֻ\D3л\BB\D0з\E7\B8\F1\B2\C5\D3\D0Ч CNend

\param[in] hTextOut Text output handle.CNcomment:\CEı\BE\CA\E4\B3\F6\BE\E4\B1\FA CNend
\param[in] u32Distance Vertical spacing.CNcomment:\B4\B9ֱ\BC\E4\BE\E0 CNend

\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HIGO_ERR_INVHANDLE Failure.CNcomment:ʧ\B0\DC CNend

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetLineExtra(HI_HANDLE hText, HI_U32 u32Distance);

/**
\brief Initializes the character module.CNcomment: \B3\F5ʼ\BB\AF\D7ַ\FBģ\BF\E9 CNend
\attention \n
N/A.CNcomment: \CE\DE CNend
\param N/A.CNcomment: \CE\DE CNend
\retval ::HI_SUCCESS Success.CNcomment: \B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure.CNcomment: ʧ\B0\DC CNend
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
N/A.CNcomment: \CE\DE CNend
*/
HI_S32 HI_GO_InitText();

/**
\brief Deinitializes the character module.CNcomment:ȥ\B3\F5ʼ\BB\AF\D7ַ\FBģ\BF\E9 CNend
\attention \n
N/A.CNcomment:\CE\DE CNend
\param N/A.CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6 CNend
\retval ::HIGO_ERR_NOTINIT Failure.CNcomment:ʧ\B0\DC CNend

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DeinitText();


/** @} */  /*! <!-- API declaration end */
#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_TEXT_H__ */
