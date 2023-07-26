#ifndef __HI_GO_DECODE_H__
#define __HI_GO_DECODE_H__

#include "hi_type.h"
#include "hi_go_comm.h"
#include "hi_go_surface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_DEC */
/** @{ */  /** <!-- [HIGO_DEC] */

/** Decoding type of the decoding instance*//** CNcomment: \BD\E2\C2\EBʵ\C0\FD\B5Ľ\E2\C2\EB\C0\E0\D0\CD */
typedef enum
{
    HIGO_DEC_IMGTYPE_JPEG = HIGO_IMGTYPE_JPEG, /**<.jpeg picture*//**<CNcomment: JPEG\B8\F1ʽͼƬ*/
    HIGO_DEC_IMGTYPE_GIF  = HIGO_IMGTYPE_GIF,  /**<.gif picture*//**<CNcomment: GIF\B8\F1ʽͼƬ*/
    HIGO_DEC_IMGTYPE_BMP  = HIGO_IMGTYPE_BMP, /**<.bmp picture*//**<CNcomment: BMP\B8\F1ʽͼƬ */
    HIGO_DEC_IMGTYPE_PNG  = HIGO_IMGTYPE_PNG,  /**<.png picture*//**<CNcomment: PNG\B8\F1ʽͼƬ */
    HIGO_DEC_IMGTYPE_RLE  = HIGO_IMGTYPE_RLE,  /**<.rle picture*//**<CNcomment: RLE\B8\F1ʽͼƬ */
    HIGO_DEC_IMGTPYE_BUTT
} HIGO_DEC_IMGTYPE_E;

/**Stream source*//** CNcomment: \C2\EB\C1\F7\B5\C4\C0\B4Դ */
typedef enum
{
    HIGO_DEC_SRCTYPE_FILE = 0, /**<Streams are derived from files.*//**<CNcomment: \C2\EB\C1\F7\C0\B4Դ\D3\DA\CEļ\FE*/
    HIGO_DEC_SRCTYPE_MEM,      /**<Streams are derived from the memory.*//**<CNcomment: \C2\EB\C1\F7\C0\B4Դ\D3\DA\C4ڴ\E6*/
    HIGO_DEC_SRCTYPE_STREAM,   /**<Streams are derived from stream data.*/  /**<CNcomment: \C2\EB\C1\F7\C0\B4Դ\D3\DA\C1\F7ʽ\CA\FD\BE\DD*/
    HIGO_DEC_SRCTYPE_BUTT
} HIGO_DEC_SRCTYPE_E;

typedef struct
{
    HIGO_MEMTYPE_E MemType;
    HI_BOOL IsPubPalette;  /*Decoder uses common Palette or not*//** CNcomment:\BD\E2\C2\EBͼƬ\CAǷ\F1ʹ\D3ù\AB\B9\B2\B5\F7ɫ\B0\E5,ֻ\B6\D4\CA\E4\B3\F6\B8\F1ʽ\D3\D0Ч*/
}HIGO_DEC_SURINFO_S;

typedef HI_S32 (*PTR_Dec_WriteStreamCB_FN)(HI_ULONG ClientData, HI_ULONG Offset);

/**Detailed information about the stream source*//** CNcomment:\C2\EB\C1\F7\C0\B4Դ\B5\C4\CF\EAϸ\D0\C5Ϣ*/
typedef union
{
    /*The following information is required if the input source is the memory.*//** CNcomment:\CA\E4\C8\EBԴΪ\C4ڴ\E6\BF\E9ʱ\D0\E8Ҫ\B5\C4\D0\C5Ϣ*/
    struct
    {
        HI_CHAR* pAddr;      /**<Memory pointer address*//**<CNcomment: \C4ڴ\E6ָ\D5\EB\B5\D8ַ*/
        HI_U32 Length;       /**<Length*//**<CNcomment: \B3\A4\B6\C8*/
    } MemInfo;

    /*Picture name*//** CNcomment:ͼƬ\CEļ\FE\C3\FB*/
    const HI_CHAR *pFileName;
    struct
    {
        PTR_Dec_WriteStreamCB_FN pWriteCB;
        HI_ULONG ClientData; /**<Save client data.*//**<CNcomment: \D3\C3\C0\B4\B1\A3\B4\E6\C1\D9ʱ\D0\C5Ϣ */
    } Stream;
} HIGO_DEC_SRCINFO_U;

/**Parameters for creating a decoding instance.*//** CNcomment: \B4\B4\BD\A8\BD\E2\C2\EBʵ\C0\FD\D0\E8Ҫ\B5Ĳ\CE\CA\FD */
typedef struct
{
    HIGO_DEC_SRCTYPE_E SrcType; /**<Type of the input stream.*//**<CNcomment: \CA\E4\C8\EB\C2\EB\C1\F7\B5\C4\C0\E0\D0\CD*/
    HIGO_DEC_SRCINFO_U SrcInfo; /**<Information about the input source.*//**<CNcomment: \CA\E4\C8\EBԴ\CF\EAϸ\D0\C5Ϣ*/
} HIGO_DEC_ATTR_S;

/** Major information after decoding*//** CNcomment: \BD\E2\C2\EB\BA\F3\D6\F7\D0\C5Ϣ */
typedef struct
{
    HI_U32             Count;           /**<Number of pictures*//**<CNcomment: ͼƬ\B5ĸ\F6\CA\FD */
    HIGO_DEC_IMGTYPE_E ImgType;         /**<Type of the input source.*//**<CNcomment: \CA\E4\C8\EBԴ\C0\E0\D0\CD */
    HI_U32             ScrWidth;        /**<Screen width. The screen refers to that of the picture. The value 0 indicates "invalid".*//**<CNcomment: \C6\C1Ļ\BF\ED\B6ȣ\AC\B4˴\A6\C6\C1Ļ\B1\EDʾͼƬ\CEļ\FE\C6\C1Ļ\A3\AC0\B1\EDʾ\CE\DEЧ */
    HI_U32             ScrHeight;       /**<Screen height. The screen refers to that of the picture. The value 0 indicates "invalid".*//**<CNcomment: \C6\C1Ļ\B8߶ȣ\AC\B4˴\A6\C6\C1Ļ\B1\EDʾͼƬ\CEļ\FE\C6\C1Ļ\A3\AC0\B1\EDʾ\CE\DEЧ */
    HI_BOOL            IsHaveBGColor;   /**<Whether there is any background color.*//**<CNcomment: \CAǷ\F1\D3б\B3\BE\B0ɫ */
    HI_COLOR           BGColor;         /**<Background color*//**<CNcomment: \B1\B3\BE\B0\D1\D5ɫ */
} HIGO_DEC_PRIMARYINFO_S;

/** Index picture format*//** CNcomment: \CB\F7\D2\FDͼƬ\B8\F1ʽ */
typedef struct
{
    HI_U32    OffSetX;                /**<X offset value on the screen. The screen mentioned in this document refers to that of the picture.*//**<CNcomment: \D4\DA\C6\C1Ļ\C9ϵ\C4Xƫ\D2\C6\C1\BF\A3\AC\B4˴\A6\C6\C1Ļ\B1\EDʾͼƬ\CEļ\FE\C6\C1Ļ\A3\AC\CF\C2ͬ */
    HI_U32    OffSetY;                /**<Y offset value on the screen.*//**<CNcomment: \D4\DA\C6\C1Ļ\C9ϵ\C4Yƫ\D2\C6\C1\BF*/
    HI_U32    Width;                  /**<Width of the original picture*//**<CNcomment: ԭʼͼƬ\B5Ŀ\ED\B6\C8 */
    HI_U32    Height;                  /**<Height of the original picture*//**<CNcomment: ԭʼͼƬ\B5ĸ߶\C8 */
    HI_U8     Alpha;                  /**<Information about channel alpha used for overlaying pictures. The alpha value ranges from 0 to 255.*//**<CNcomment: \D3\C3\D3\DAͼƬ\BD\F8\D0е\FE\BCӵ\C4ͨ\B5\C0alpha\D0\C5Ϣ\A3\AC\B7\B6Χ\CA\C70-255 */
    HI_BOOL   IsHaveKey;              /**<Key enable. HI_FALSE: disabled; HI_TRUE: enabled*//**<CNcomment: \CAǷ\F1\D3\D0KEY\A1\A3 HI_FALSE: KEY\B2\BBʹ\C4ܣ\BBHI_TRUE: KEYʹ\C4\DC */
    HI_COLOR  Key;                    /**<Information about colorkey used for overlaying pictures*//**<CNcomment: \D3\C3\D3\DAͼƬ\BD\F8\D0е\FE\BCӵ\C4colorkey\D0\C5Ϣ */
    HIGO_PF_E Format;                 /**<Pixel format of the picture source*//**<CNcomment: ͼƬԴ\CF\F1\CBظ\F1ʽ */
    HI_U32    DelayTime;              /**<Time interval between this picture and the previous one (10 ms). The value 0 indicates that the parameter is invalid.*//**<CNcomment: \D3\EB\C9\CFһ\B7\F9ͼƬ\B5\C4ʱ\BC\E4\BC\E4\B8\F4(10ms)\A3\AC0\B1\EDʾ\B8ò\CE\CA\FD\CE\DEЧ */
    HI_U32    DisposalMethod;         /**<Processing method of the current frame. This application programming interface (API) is valid for only GIF pictures. 0: customized processing method; 1: no processing method; 2: use the background color.*/    /**<CNcomment: \B5\B1ǰ֡\B4\A6\C0\ED\B7\BD\B7\A8\A3\AC\B4˽ӿ\DAֻ\B6\D4GIF\D3\D0Ч\A3\AC0:\D3û\A7\BE\F6\B6\A8\B4\A6\C0\ED\B7\BDʽ\A3\AC1:\B2\BB\D7\F6\B4\A6\C0\ED\A3\AC2:ʹ\D3ñ\B3\BE\B0ɫ\A3\AC*/
} HIGO_DEC_IMGINFO_S;

/* Picture attributes after decoding*//** CNcomment: \BD\E2\C2\EB\BA\F3ͼƬ\CA\F4\D0\D4 */
typedef struct
{
    HI_U32    Width;                  /**<Expected width after decoding*//**<CNcomment: \C6\DA\CD\FB\BD\E2\C2\EB\BA\F3\BF\ED\B6\C8 */
    HI_U32    Height;                 /**<Expected height after decoding*//**<CNcomment: \C6\DA\CD\FB\BD\E2\C2\EB\BA\F3\B8߶\C8*/
    HIGO_PF_E Format;                 /**<Expected pixel format after decoding*//**<CNcomment: \C6\DA\CD\FB\BD\E2\C2\EB\BA\F3\CF\F1\CBظ\F1ʽ*/
} HIGO_DEC_IMGATTR_S;

/** Extended data format type*//** CNcomment: \C0\A9չ\CA\FD\BEݸ\F1ʽ\C0\E0\D0\CD */
typedef enum
{
    HIGO_DEC_EXTEND_EXIF = 0,          /**<Extended-data in EXIF format*//**<CNcomment: EXIF\B8\F1ʽ\B5\C4\C0\A9չ\CA\FD\BE\DD */
    HIGO_DEC_EXTEND_EXIF_BUTT
} HIGO_DEC_EXTENDTYPE_E;

/** Basic picture information*//** CNcomment: ͼƬ\BB\F9\B1\BE\D0\C5Ϣ */
typedef struct
{
    HI_U32    Width;                /**<Picture width*//**<CNcomment: ͼƬ\B5Ŀ\ED\B6\C8 */
    HI_U32    Height;               /**<Picture height*//**<CNcomment: ͼƬ\B5ĸ߶\C8 */
    HIGO_PF_E PixelFormat;          /**<Pixel format*//**<CNcomment: \CF\F1\CBظ\F1ʽ */
    HI_U32    VirAddr[3];           /**<Virtual address. If the address is in RGB format, only the first VirAddr[0] is the start address,
                                                and VirAddr[1] and VirAddr[2] are invalid. If the address is in YC format,
                                                VirAddr[0] indicates the start address of the Y component, VirAddr[1] indicates the start address of the C component,
                                                and VirAddr[2] is invalid.*/
                                                /**<CNcomment: \D0\E9\C4\E2\B5\D8ַ\A1\A3\C8\E7\B9\FB\CA\C7RGB\B8\F1ʽ\A3\ACֻ\D3е\DAһ\B8\F6VirAddr[0]Ϊ\C6\F0ʼ\B5\D8ַ\A3\AC
                                                VirAddr[1]\BA\CDVirAddr[2]\CE\DEЧ\A3\BB\C8\E7\B9\FB\CA\C7YC\B8\F1ʽ\A3\AC
                                                VirAddr[0]\B1\EDʾY\B7\D6\C1\BF\C6\F0ʼ\B5\D8ַ\A3\ACVirAddr[1]\B1\EDʾC\B7\D6\C1\BF\C6\F0ʼ\B5\D8ַ\A3\AC
                                                VirAddr[2]\CE\DEЧ */
    HI_U32    PhyAddr[3];           /**<Physical address. The usage principles are the same as previous ones.*//**<CNcomment: \CE\EF\C0\ED\B5\D8ַ\A3\ACʹ\D3\C3ԭ\D4\F2ͬ\C9\CF */
    HI_U32    Pitch[3];             /**<Pitch. The usage principles are the same as previous ones.*//**<CNcomment: \D0м\E4\BE࣬ʹ\D3\C3ԭ\D4\F2ͬ\C9\CF */
    HI_U32    Palate[256];         /**<Palette*//**<CNcomment: \B5\F7ɫ\B0\E5 */
} HIGO_DEC_IMGDATA_S;

typedef struct {
    HI_VOID *StreamBuf;     /**<Virtual start address of streams *//**<CNcomment: \C1\F7\D0\E9\C4\E2\C6\F0ʼ\B5\D8ַ */
    HI_U32 StreamLen;       /**<Actual read stream length *//**<CNcomment: ʵ\BCʶ\C1ȡ\B5\C4\C2\EB\C1\F7\B3\A4\B6\C8 */
    HI_U32 ExpectStreamLen; /**<Expect read stream length *//**<CNcomment: \C6\DA\CD\FB\B6\C1ȡ\B5\C4\C2\EB\C1\F7\B3\A4\B6\C8 */
} HIGO_DEC_WRITESTREAM_S;

/** @} */  /*! <!-- Structure Definition end */
/********************** Global Variable declaration **************************/

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_DEC */
/** @{ */  /** <!-- [HIGO_DEC] */


 /**
\brief Initializes the decoder.CNcomment: \BD\E2\C2\EB\C6\F7\B3\F5ʼ\BB\AF CNend
\attention \n
::HI_GO_Init already calls the interfaceCNcomment: ::HI_GO_Init\D6\D0\D2Ѱ\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param  N/ACNcomment: \CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
::HI_GO_Init \n
::HI_GO_DeinitDecoder
*/

HI_S32 HI_GO_InitDecoder(HI_VOID);

/**
\brief Deinitializes the decoder.CNcomment: \BD\E2\C2\EB\C6\F7ȥ\B3\F5ʼ\BB\AF CNend
\attention \n
When ::HI_GO_Deinit is called, this API is also called.CNcomment: ::HI_GO_Deinit\D6\D0\D2Ѱ\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param  N/A.CNcomment: \CE\DE CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT

\see \n
::HI_GO_Deinit \n
::HI_GO_InitDecoder
*/

HI_S32 HI_GO_DeinitDecoder(HI_VOID);

 /**
 \brief Creates a decoding handle.CNcomment: \B4\B4\BD\A8\BD\E2\C2\EB\BE\E4\B1\FA CNend
 \attention \n
 Currently, the formats of .bmp, .png, .jpeg, and .gif are supported. The picture input source can be the memory, files
, and streams. The picture input source of streams is only applicable to the .jpeg format.
CNcomment: Ŀǰ֧\B3\D6BMP\A1\A2PNG\A1\A2JPEG\BA\CDGIF\B8\F1ʽ\A3\ACͼƬ\CA\E4\C8\EBԴֻ\BF\C9\D2\D4Ϊ\C4ڴ桢\CEļ\FE\D2Լ\B0\C1\F7ʽ\A3\AC\C1\F7ʽĿǰֻ\B6\D4JPEG\B8\F1ʽ\D3\D0Ч\A1\A3CNend

 \param[in] pSrcDesc Information about the input source. This parameter cannot be empty.
                The type of the input stream must match the information about the input source. For example,
corresponding file names must be entered for the file stream, and the memory address and memory size must be entered
for the memory stream.CNcomment: \CA\E4\C8\EBԴ\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5\n
                \CA\E4\C8\EB\C2\EB\C1\F7\B5\C4\C0\E0\D0\CDҪ\D3\EB\CA\E4\C8\EBԴ\CF\EAϸ\D0\C5Ϣһһƥ\C5䣬\C8\E7FILE\C2\EB\C1\F7\D4\F2\D0\E8Ҫ\CA\E4\C8\EB\CF\E0Ӧ\B5\C4\CEļ\FE\C3\FB\n
                \C8\E7Memory\C2\EB\C1\F7\D4\F2\D0\E8Ҫ\CA\E4\C8\EBmemory\B5ĵ\D8ַ\D2Լ\B0\B3\A4\B6\C8 CNend
 \param[out] pDecoder Pointer of the decoding instance handle. This parameter cannot be empty.CNcomment: \BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FAָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

 \retval ::HI_SUCCESS
 \retval ::HIGO_ERR_NULLPTR
 \retval ::HIGO_ERR_NOTINIT
 \retval ::HIGO_ERR_NOMEM
 \retval ::HIGO_ERR_INVHANDLE
 \retval ::HIGO_ERR_INVFILE
 \retval ::HIGO_ERR_INVSRCTYPE
 \retval ::HIGO_ERR_INVIMAGETYPE
 \retval ::HIGO_ERR_INVIMGDATA

\see \n
::HI_GO_DestroyDecoder
*/
HI_S32 HI_GO_CreateDecoder(const HIGO_DEC_ATTR_S* pSrcDesc, HI_HANDLE* pDecoder);

 /**
 \brief Destroys a decoding handle.CNcomment:\CF\FA\BBٽ\E2\C2\EB\BE\E4\B1\FA CNend
 \attention \n
 N/A.CNcomment:\CE\DE CNend
 \param[in] Decoder Handle of the decoding instance.CNcomment:\BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend

 \retval ::HI_SUCCESS
 \retval ::HIGO_ERR_INVHANDLE

\see \n
::HI_GO_CreateDecoder
*/
HI_S32 HI_GO_DestroyDecoder(HI_HANDLE Decoder);

/**
 \brief Stream APICNcomment: \C1\F7ʽ\C2\EB\C1\F7\BDӿ\DA CNend
 \attention \n
 N/A.CNcomment:\CE\DE CNend
 \param[in] Decoder Handle of the decoding instance.CNcomment: \BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
 \param[in] pStream Pointer to the stream information. This parameter cannot be empty.CNcomment: \C2\EB\C1\F7\D0\C5Ϣָ\D5\EB \A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

 \retval ::HI_SUCCESS
 \retval ::HI_FAILURE
 \retval ::HIGO_ERR_NULLPTR
 \retval ::HIGO_ERR_INVHANDLE
 \retval ::HIGO_ERR_UNSUPPORTED

\see \n
::HI_GO_CreateDecoder
*/
HI_S32 HI_GO_DecWriteStream(HI_HANDLE Decoder, HIGO_DEC_WRITESTREAM_S *pStream);

/**
\brief Reset decoding.CNcomment:\B8\B4λ\BD\E2\C2\EB\C6\F7 CNend
\attention only support jpeg decode\n
N/A.CNcomment: ֻ֧\B3\D6jpeg\C0\E0\D0\CD CNend
\param[in] Decoder Handle of the decoding instance.CNcomment:\BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVIMAGETYPE

\see sample_dec_stream.c\n
::HI_GO_ResetDecoder
*/
HI_S32 HI_GO_ResetDecoder(HI_HANDLE Decoder);

 /**
 \brief Obtains the major information about pictures.CNcomment:\BB\F1ȡͼƬ\CEļ\FE\B5\C4\D6\F7Ҫ\D0\C5Ϣ CNend
 \attention
 N/A.CNcomment:\CE\DE CNend
\param[in] Decoder Handle of the decoding instance.CNcomment:\BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
\param[out] pPrimaryInfo  Pointer to the major information about the decoded picture. This parameter cannot be empty.CNcomment:\BD\E2\C2\EBͼƬ\D6\F7\D0\C5Ϣָ\D5룬\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_NULLPTR
\retval ::HI_NULL_PTR
\retval ::HIGO_ERR_INVIMGDATA

\see \n
::HI_GO_DecImgInfo
*/
HI_S32 HI_GO_DecCommInfo(HI_HANDLE Decoder, HIGO_DEC_PRIMARYINFO_S *pPrimaryInfo);

/**
 \brief Obtains the information about the specified picture. You can customize the picture format.CNcomment: \BB\F1ȡָ\B6\A8ͼƬ\B5\C4\D0\C5Ϣ\A3\AC\B5\ABͬʱ\D3û\A7\BF\C9\D2\D4\C9\E8\D6\C3\C6\DA\CD\FB\B5\C4ͼ\CF\F3\B8\F1ʽ CNend
 \attention \n
  N/A.CNcomment: \CE\DE CNend
 \param[in] Decoder Handle of the decoding instance.CNcomment: \BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
 \param[in] Index
 Picture index number. For .jpeg pictures, the index number of the main picture is 0, and index
numbers of thumbnails start from 1.
                   The index numbers of GIF pictures start from 0 and increase by 1 according to the sequence of the
pictures stored in a file.
CNcomment: ͼƬ\CB\F7\D2\FD\BAš\A3JPEG\B8\F1ʽͼƬ\A3\AC\D6\F7ͼ\B5\C4\CB\F7\D2\FD\BA\C5\CA\C70\A3\AC\CB\F5\C2\D4ͼ\CB\F7\D2\FD\BA\C5\D3\C91\BF\AAʼ\A3\BB\n
                   GIF\B8\F1ʽͼƬ\B0\B4\D5\D5\D4\DA\CEļ\FE\D6еĴ洢˳\D0\F2\A3\AC\CB\F7\D2\FD\BA\C5\D3\C90\BF\AAʼ\B5ݼ\D3 CNend
 \param[out] pImgInfo Picture information. This parameter cannot be empty.CNcomment: ͼƬ\D0\C5Ϣ\A3\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

 \retval ::HI_SUCCESS
 \retval ::HIGO_ERR_NULLPTR
 \retval ::HIGO_ERR_INVHANDLE
 \retval ::HIGO_ERR_INVINDEX
 \retval ::HI_FAILURE
 \retval ::HI_NULL_PTR
 \retval ::HIGO_ERR_INVIMGDATA

\see \n
::HI_GO_DecCommInfo
*/
HI_S32 HI_GO_DecImgInfo(HI_HANDLE Decoder, HI_U32 Index, HIGO_DEC_IMGINFO_S *pImgInfo);

 /**
 \brief Obtains the data of a picture.CNcomment:\BB\F1ȡ\B5\A5\B8\F6ͼƬ\B5\C4\CA\FD\BE\DD CNend
 \attention \n
 The format in the destination picture attributes does not support the macro block format.CNcomment:Ŀ\B1\EAͼƬ\CA\F4\D0\D4\D6е\C4ͼ\CF\F1\B8\F1ʽ\B2\BB֧\B3ֺ\EA\BF\E9\B8\F1ʽ CNend

\param[in] Decoder Handle of the decoding instance.CNcomment:\BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
\param[in] Index Index number of a picture, starting from 0.CNcomment:ͼƬ\CB\F7\D2\FD\BAţ\AC\CB\F7\D2\FD\BAŴ\D30\BF\AAʼ CNend
\param[in] pImgAttr Attribute of the destination picture. If the value is empty, it indicates that the original
picture attributes are retained.CNcomment:Ŀ\B1\EAͼƬ\CA\F4\D0ԣ\ACΪ\BFձ\EDʾ\B1\A3\B3\D6ԭͼƬ\CA\F4\D0\D4 CNend
\param[out] pSurface Handle of the surface where the decoded data is stored.CNcomment:\BD\E2\C2\EB\BA\F3\CA\FD\BEݴ\E6\B7ŵ\C4surface\B5ľ\E4\B1\FA CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVINDEX
\retval ::HI_FAILURE
\retval ::HI_NULL_PTR
\retval ::HIGO_ERR_INVIMGDATA
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_UNSUPPORTED

\see \n
::HI_GO_DecCommInfo
*/
HI_S32 HI_GO_DecImgData(HI_HANDLE Decoder, HI_U32 Index, const HIGO_DEC_IMGATTR_S *pImgAttr, HI_HANDLE *pSurface);

/**
 \brief Obtains the extended data.CNcomment: \BB\F1ȡ\C0\A9չ\CA\FD\BE\DD CNend
 \attention \n
 Hi3110E does not support the API.CNcomment: Hi3110E\B2\BB֧\B3ִ˺\AF\CA\FD\A1\A3 CNend
 \param[in] Decoder Handle of the decoding instance.CNcomment: \BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
 \param[in] DecExtendType
 Type of the obtained extended data. Currently, only the EXIF information in .jpeg format is available.
 CNcomment: \BB\F1ȡ\C0\A9չ\CA\FD\BEݵ\C4\C0\E0\D0ͣ\ACĿǰ\D6\F7Ҫֻ\D3\D0JPEG\B5\C4EXIF\D0\C5Ϣ CNend
 \param[out] ppData Pointer to the extended data pointer.CNcomment: ָ\CF\F2\C0\A9չ\CA\FD\BE\DDָ\D5\EB\B5\C4ָ\D5\EB CNend
 \param[out] pLength ppData Length.CNcomment: ppData\B3\A4\B6\C8 CNend
 \retval ::HI_SUCCESS
 \retval ::HIGO_ERR_NULLPTR
 \retval ::HIGO_ERR_INVHANDLE
 \retval ::HIGO_ERR_UNSUPPORTED

\see \n
::HI_GO_ReleaseDecExtendData
*/
HI_S32 HI_GO_DecExtendData(HI_HANDLE Decoder, HIGO_DEC_EXTENDTYPE_E DecExtendType, HI_VOID **ppData, HI_U32 *pLength);

 /**
 \brief Releases extended data.CNcomment:\CAͷ\C5\C0\A9չ\CA\FD\BE\DD CNend
 \attention \n
 Hi3110E does not support the API.CNcomment:Hi3110E\B2\BB֧\B3ִ˺\AF\CA\FD\A1\A3CNend
 \param[in] Decoder Decoder handle.CNcomment:Decoder\BE\E4\B1\FA CNend
 \param[in] DecExtendType Type of the obtained extended data. Currently, only the EXIF information in .jpeg format is
available.CNcomment:\BB\F1ȡ\C0\A9չ\CA\FD\BEݵ\C4\C0\E0\D0ͣ\ACĿǰ\D6\F7Ҫֻ\D3\D0JPEG\B5\C4EXIF\D0\C5Ϣ CNend
 \param[in] pData Pointer to the extended data.CNcomment:ָ\CF\F2\C0\A9չ\CA\FD\BE\DDָ\D5\EB CNend
 \retval ::HI_SUCCESS
 \retval ::HIGO_ERR_NULLPTR
 \retval ::HIGO_ERR_UNSUPPORTED

\see \n
::HI_GO_DecExtendData
*/
HI_S32 HI_GO_ReleaseDecExtendData(HI_HANDLE Decoder, HIGO_DEC_EXTENDTYPE_E DecExtendType, HI_VOID *pData);

/**
\brief Decodes a picture to a specified surface.CNcomment:\BD\ABͼ\CF\F1\BD\E2\C2뵽ָ\B6\A8\B5\C4surface CNend
\attention \n
The decoded surface is scaled automatically based on the size of the target surface. In addition, the decoded surface
modifies the attributes of the target surface, such as colorkey, alpha value, and palette.
CNcomment:\BD\E2\C2\EB\BA\F3\B5\C4Surface\BB\E1\D7Զ\AF\B0\B4\D5\D5Ŀ\B1\EAsurface\B5Ĵ\F3С\BD\F8\D0\D0\CB\F5\B7ţ\AC\B2\A2\C7һ\E1\B8ı\E4Ŀ\B1\EAsurface\B5\C4COLORKEY\A1\A2ALPHA\D2Լ\B0\B5\F7ɫ\B0\E5\CA\F4\D0\D4 CNend
\param[in] Decoder Handle of the decoding instance.CNcomment: \BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
\param[in] Index   Index number of a decoded picture.CNcomment:\BD\E2\C2\EBͼƬ\CB\F7\D2\FD CNend
\param[out] Surface Decoded target surface.CNcomment:\BD\E2\C2\EB\B5\C4Ŀ\B1\EAsurface CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVINDEX
\retval ::HIGO_ERR_NULLPTR
\retval ::HI_FAILURE
\retval ::HI_NULL_PTR
\retval ::HIGO_ERR_INVIMGDATA
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_UNSUPPORTED

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DecImgToSurface(HI_HANDLE Decoder, HI_U32 Index, HI_HANDLE Surface);

/**
\brief Decodes a specified file, and generates a new surface.CNcomment:\BD\E2\C2\EBָ\B6\A8\B5\C4\CEļ\FE\A3\AC\B2\A2\C9\FA\B3\C9һ\B8\F6\D0µ\C4surface CNend
\attention \n
    If there are multiple pictures in the file (such as .gif animation, .jpeg main picture, and .jpeg thumbnail),
    only the .jpeg main picture and the first picture of the .gif animation are decoded.
    In addition, the surface size is the same as the picture size.
    CNcomment:\C8\E7\B9\FB\CEļ\FE\D6\D0\D3ж\E0\D5\C5ͼƬ\A3\AC\B1\C8\C8\E7:gif\B6\AF\BB\AD\A3\ACJPEG\B4\F8\D6\F7ͼ\BA\CD\CB\F5\C2\D4ͼ\A3\AC
    JPEGֻ\BD\E2\D6\F7ͼ\A3\ACGIF\BD\E2\C2\EB\BD\E2\C2\EB\B5\DAһ\D5\C5ͼƬsurface\B5Ĵ\F3С\D3\EBͼƬ\B5Ĵ\F3Сһ\D6\C2 CNend
\param[in] pszFile Picture name. The picture can be in the format of .gif, .png, .jpg, or .bmp.CNcomment:ͼƬ\CEļ\FE\C3\FB\A3\AC\BF\C9\D2\D4\CA\C7GIF, PNG, JPG, BMP CNend
\param[out] pSurface, Surface for storing decoded pictures.CNcomment:\B1\A3\B4\E6\BD\E2\C2\EB\BA\F3ͼ\CF\F1 CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVINDEX
\retval ::HIGO_ERR_NULLPTR
\retval ::HI_NULL_PTR
\retval ::HIGO_ERR_INVIMGDATA
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVSRCTYPE
\retval ::HIGO_ERR_INVIMAGETYPE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_DecodeFile(const HI_CHAR* pszFile, HI_HANDLE* pSurface);

/**
\brief Set the attribute of Decoder out Surface memrory.  CNcomment:\C9\E8\D6ý\E2\C2\EB\CA\E4\B3\F6Surface\B5\C4\C4ڴ\E6\CA\F4\D0\D4 CNend
\attention \n
N/A.CNcomment: \CE\DE CNend
\param[in] Decoder handle. CNcomment:\BD\E2\C2\EBʵ\C0\FD\BE\E4\B1\FA CNend
\param[in] pSurfInfo.  CNcomment:Surface\B5\C4\C4ڴ\E6\CA\F4\D0\D4 CNend

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_INVHANDLE

\see \n
N/A.CNcomment:\CE\DE CNend
*/
HI_S32 HI_GO_SetDecSurfInfo(HI_HANDLE Decoder, HIGO_DEC_SURINFO_S  *pSurfInfo);

#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_GO_DECODE_H__ */
