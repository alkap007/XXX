#ifndef __HI_GO_ENCODER_H__
#define __HI_GO_ENCODER_H__

#include "hi_go_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

/*************************** Structure Definition ****************************/
/** \addtogroup      HIGO_ENC */
/** @{ */  /** <!-- [HIGO_ENC] */

/**Encoder attributes*/
/** CNcomment:\B1\E0\C2\EB\C6\F7\CA\F4\D0\D4*/
typedef struct
{
   HIGO_IMGTYPE_E ExpectType;   /**<Type of the encoded picture*//**<CNcomment:\B1\E0\C2\EBͼƬ\C0\E0\D0\CD*/
   HI_U32 QualityLevel;        /**<The quality level ranges from 1 to 99. The higher the level, the better the quality, and the greater the encoded picture or occupied memory. The QualityLevel parameter is valid for .jpeg pictures only.*//**<CNcomment:1-99\BC\B6, \BC\B6\B1\F0Խ\B8ߣ\AC\D6\CA\C1\BFԽ\BAã\AC\B1\E0\C2\EB\B3\F6\C0\B4ͼ\CF\F1\CEļ\FE\BB\F2\C4ڴ\E6ҲԽ\B4\F3\A3\ACֻ\B6\D4JPEG\D3\D0Ч*/
}HIGO_ENC_ATTR_S;
/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      HIGO_ENC */
/** @{ */  /** <!-- [HIGO_ENC] */
 /**
\brief Initializes the encoder. CNcomment:\B1\E0\C2\EB\C6\F7\B3\F5ʼ\BB\AF CNend
\attention \n
When ::HI_GO_Init is called, this application programming interface (API) is also called.
CNcomment: ::HI_GO_Init\D6\D0\D2Ѱ\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param  N/A

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_DEPEND_TDE

\see \n
::HI_GO_Init \n
::HI_GO_DeinitDecoder
*/

HI_S32 HI_GO_InitEncoder(HI_VOID);


/**
\brief Deinitializes the encoder. CNcomment:\B1\E0\C2\EB\C6\F7ȥ\B3\F5ʼ\BB\AF CNend
\attention \n
When ::HI_GO_Deinit is called, this API is also called.
CNcomment: ::HI_GO_Deinit\D6\D0\D2Ѱ\FC\BA\AC\B6Ըýӿڵĵ\F7\D3\C3 CNend
\param  N/A

\retval ::HI_SUCCESS
\retval ::HIGO_ERR_NOTINIT

\see \n
::HI_GO_Deinit \n
::HI_GO_InitDecoder
*/

HI_S32 HI_GO_DeinitEncoder(HI_VOID);

/**
\brief Encodes a surface in a specified format, and saves the encoded surface in a file.
CNcomment:\BD\ABһ\B8\F6surface\B1\E0\C2뵽ָ\B6\A8ͼ\CF\F1\B8\F1ʽ\B2\A2\B1\A3\B4浽\CEļ\FE\D6\D0 CNend
\attention \n
The .bmp encoding format is supported.
The hardware platform determines whether the .jpeg encoding foramt is supported.
CNcomment:֧\B3ֱ\E0\C2\EB\B3\C9bmp\B8\F1ʽ\CEļ\FE \n
(\CAǷ\F1֧\B3ֱ\E0\C2\EB\B3\C9JPEG,ȡ\BE\F6\D3\DAӲ\BC\FEƽ̨) CNend

\param[in] hSurface  Surface to be encoded. CNcomment:\D0\E8Ҫ\B1\E0\C2\EB\B5\C4surface, CNend
\param[in] pFile    Name of the encoded file. This parameter can be empty. If this parameter is not set, the encoded file is named [year]-[month]-[date]-[hour]-[minute]-[second].
                        CNcomment:\B1\E0\C2\EB\BA\F3\B5\C4\CEļ\FE\C3\FB\A3\AC\BF\C9\D2\D4Ϊ\BFգ\ACΪ\BF\D5\D4\F2\D3õ\B1ǰʱ\BC\E4[\C4\EA]-[\D4\C2]-[\C8\D5]-[ʱ]-[\B7\D6]-[\C3\EB]\C0\B4\C3\FC\C3\FB CNend
\param[in] pAttr    Encoding attributes. This parameter cannot be empty. CNcomment:\B1\E0\C2\EB\C9\E8\D6õ\C4\CA\F4\D0ԣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS Success.
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVSRCTYPE
\retval ::HIGO_ERR_INVIMAGETYPE
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVMIRRORTYPE
\retval ::HIGO_ERR_INVROTATETYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_DEPEND_JPGE

\see \n
*/
HI_S32 HI_GO_EncodeToFile(HI_HANDLE hSurface, const HI_CHAR* pFile, const HIGO_ENC_ATTR_S* pAttr);

/**
\brief Encodes a surface in a specified picture format and saves it in a memory. Ensure that the memory is sufficient.
CNcomment:\BD\ABһ\B8\F6surface\B1\E0\C2뵽ָ\B6\A8ͼ\CF\F1\B8\F1ʽ\B2\A2\B1\A3\B4浽\C4ڴ\E6\D6У\AC\C7\EB\D7\D4\D0б\A3ָ֤\B6\A8\C4ڴ\E6\BF\E9\D7㹻\B4\F3 CNend
\attention \n
The data can be encoded as .bmp data, and saved in a specified memory.
The hardware platform determines whether the .jpeg encoding format is supported.
CNcomment:֧\B3ֱ\E0\C2\EB\B3\C9bmp\B8\F1ʽ\CA\FD\BEݴ\E6\B7ŵ\BDָ\B6\A8\B5\C4\C4ڴ\E6\D6\D0
(\CAǷ\F1֧\B3ֱ\E0\C2\EB\B3\C9JPEG,ȡ\BE\F6\D3\DAӲ\BC\FEƽ̨) CNend

\param[in] hSurface     Surface to be encoded. CNcomment:\D0\E8Ҫ\B1\E0\C2\EB\B5\C4surface, CNend
\param[in] pMem         Start address of the memory for storing the encoded pictures. CNcomment:\B1\A3\B4\E6\B1\E0\C2\EB\BA\F3\B5\C4ͼ\CF\F1\CA\FD\BE\DD\C4ڴ\E6\BF\E9\B5\C4\C6\F0ʼ\B5\D8ַ CNend
\param[in] MemLen       Size of a specified memory. CNcomment:ָ\B6\A8\C4ڴ\E6\B5Ĵ\F3С CNend
\param[out] pOutLen     Actual size of the used memory, indicating the length of encoded data. Ensure that the value of pOutLen is smaller than or equal to the value of MemLen.
                                CNcomment:ʵ\BC\CAʹ\D3õ\C4\C4ڴ\E6\B4\F3С\A3\AC\B1\E0\C2\EB\BA\F3\CA\FD\BEݳ\A4\B6\C8(\D7\D4\D0\D0ȷ\B1\A3pOutLen <= MemLen) CNend
\param[in] pAttr        Encoding attributes. This parameter cannot be empty. CNcomment:\B1\E0\C2\EB\C9\E8\D6õ\C4\CA\F4\D0ԣ\AC\B2\BB\BF\C9Ϊ\BF\D5 CNend

\retval ::HI_SUCCESS
\retval ::HI_FAILURE
\retval ::HIGO_ERR_NULLPTR
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_UNSUPPORTED
\retval ::HIGO_ERR_NOMEM
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVSRCTYPE
\retval ::HIGO_ERR_INVFILE
\retval ::HIGO_ERR_INVIMAGETY
\retval ::HIGO_ERR_INVIMAGETYPE
\retval ::HIGO_ERR_INVPARAM
\retval ::HIGO_ERR_INVMIRRORTYPE
\retval ::HIGO_ERR_INVROTATETYPE
\retval ::HIGO_ERR_INVCKEYTYPE
\retval ::HIGO_ERR_INVROPTYPE
\retval ::HIGO_ERR_NOCOLORKEY
\retval ::HIGO_ERR_INVPIXELFMT
\retval ::HIGO_ERR_INTERNAL
\retval ::HIGO_ERR_INVHANDLE
\retval ::HIGO_ERR_INVCOMPTYPE
\retval ::HIGO_ERR_LOCKED
\retval ::HIGO_ERR_DEPEND_TDE
\retval ::HIGO_ERR_EMPTYRECT
\retval ::HIGO_ERR_OUTOFBOUNDS
\retval ::HIGO_ERR_DEPEND_JPGE

\see \n
*/

HI_S32 HI_GO_EncodeToMem(HI_HANDLE hSurface, HI_U8* pMem, HI_U32 MemLen, HI_U32* pOutLen, const HIGO_ENC_ATTR_S* pAttr);

/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
#if __cplusplus
}
#endif  /*__cplusplus*/
#endif  /*__cplusplus*/

#endif /* __HI_TYPE_H__ */
