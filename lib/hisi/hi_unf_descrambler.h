/******************************************************************************
 Copyright (C), 2009-2014, Hisilicon Tech. Co., Ltd.
 ******************************************************************************
 File Name     : hi_unf_descrambler.h
 Version       : Initial Draft
 Author        : Hisilicon multimedia software group
 Created       : 2013/04/16
 Description   :
******************************************************************************/

#ifndef __HI_UNF_DESCRAMBLER_H__
#define __HI_UNF_DESCRAMBLER_H__

#include "hi_error_mpi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      Descrambler */
/** @{ */  /** <!-- [Descrambler] */

/**Conditional access (CA) type, indicating whether advanced CA is used.*/
/**CNcomment:CA\C0\E0\D0ͣ\AC\CAǷ\F1ʹ\D3ø߰\B2ȫCA*/
typedef enum hiUNF_DMX_CA_TYPE_E
{
    HI_UNF_DMX_CA_NORMAL = 0,    /**<Common CA*/ /**< CNcomment:\C6\D5ͨCA*/
    HI_UNF_DMX_CA_ADVANCE,       /**<Advanced CA*/ /**< CNcomment:\B8߰\B2ȫCA*/

    HI_UNF_DMX_CA_BUTT
} HI_UNF_DMX_CA_TYPE_E;

/**CA Entropy reduction mode*/
/**CNcomment:\ECؼ\F5\C9\D9ģʽ*/
typedef enum hiUNF_DMX_CA_ENTROPY_REDUCTION_E
{
    HI_UNF_DMX_CA_ENTROPY_REDUCTION_CLOSE = 0,  /**<64bit*/
    HI_UNF_DMX_CA_ENTROPY_REDUCTION_OPEN,       /**<48bit*/

    HI_UNF_DMX_CA_ENTROPY_REDUCTION_BUTT
} HI_UNF_DMX_CA_ENTROPY_E;


/**Type of the descrambler protocol.*/
/**CNcomment:\BD\E2\C8\C5\C6\F7Э\D2\E9\C0\E0\D0\CD*/
typedef enum hiUNF_DMX_DESCRAMBLER_TYPE_E
{
    HI_UNF_DMX_DESCRAMBLER_TYPE_CSA2      = 0,       /**<CSA2.0*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_CSA3      ,          /**<CSA3.0*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_IPTV  ,          /**<AES IPTV of SPE*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_ECB   ,          /**<SPE AES ECB*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CI    ,          /**<SPE AES CIPLUS*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_DES_CI    ,          /**<DES CIPLUS*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_DES_CBC   ,          /**<DES CBC*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_NS    ,          /**<AES NS-Mode, AES NOVEL*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_SMS4_NS   ,          /**<SMS4 NS-Mode, SMS4 NOVEL*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_SMS4_IPTV ,          /**<SMS4 IPTV*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_SMS4_ECB  ,          /**<SMS4 ECB*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_SMS4_CBC  ,          /**<SMS4 CBC*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CBC   ,          /**<AES CBC*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_DES_IPTV,            /**<DES IPTV*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_TDES_IPTV,           /**<TDES IPTV*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_TDES_ECB,            /**<TDES ECB */
    HI_UNF_DMX_DESCRAMBLER_TYPE_TDES_CBC,            /**<TDES CBC */
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_ECB_L,           /**<AES_ECB_L the clear stream left in the leading */
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CBC_L,           /**<AES_CBC_L the clear stream left in the leading */
    HI_UNF_DMX_DESCRAMBLER_TYPE_ASA,                 /**<ASA 64/128 Algorithm */
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CISSA,           /**<Common IPTV Software-oriented Scrambling Algorithm (CISSA) */
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CBC_IDSA,        /**<AES128 CBC Payload / ATIS IIF Default Scrambling Algorithm (IDSA), the difference between AES_CBC_IDSA and AES_IPTV is AES_CBC_IDSA only support 0 IV */
    HI_UNF_DMX_DESCRAMBLER_TYPE_AES_CTR,             /**<AES CTR */
    HI_UNF_DMX_DESCRAMBLER_TYPE_BUTT
} HI_UNF_DMX_DESCRAMBLER_TYPE_E;

/**Attribute of the key area.*/
/**CNcomment:\C3\DCԿ\C7\F8\CA\F4\D0\D4*/
typedef struct hiUNF_DMX_DESCRAMBLER_ATTR_S
{
    HI_UNF_DMX_CA_TYPE_E enCaType;                    /**<Whether the descrambler adopts advanced CA.*/ /**< CNcomment:\BD\E2\C8\C5\C6\F7\CAǷ\F1ʹ\D3ø߰\B2ȫCA*/
    HI_UNF_DMX_DESCRAMBLER_TYPE_E enDescramblerType;  /**<Descrambling protocol type of the descrambler*/ /**< CNcomment:\BD\E2\C8\C5\C6\F7\BD\E2\C8\C5Э\D2\E9\C0\E0\D0\CD*/
    HI_UNF_DMX_CA_ENTROPY_E enEntropyReduction;       /**<CA Entropy reduction mode,for CSA2.0*/ /**< CNcomment:\ECؼ\F5\C9\D9ģʽ\A3\ACCSA2.0\D3\D0Ч*/
} HI_UNF_DMX_DESCRAMBLER_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      Descrambler */
/** @{ */  /** <!--[Descrambler]*/

/**
\brief Creates a key area.CNcomment:\B4\B4\BD\A8һ\B8\F6\C3\DCԿ\C7\F8\A1\A3CNend
\attention \n
When creating a key area, you can ignore the DUMUX to which the key area belongs, because all DEMUXs share all key areas.
CNcomment:\C9\EA\C7\EB\C3\DCԿ\C7\F8\A3\AC\B2\BB\D3ù\D8\D0\C4\CA\F4\D3\DA\C4\C4·DEMUX\A3\AC\CB\F9\D3\D0DEMUX\B9\B2\D3\C3\CB\F9\D3\D0\C3\DCԿ\C7\F8\A1\A3CNend
\param[in] u32DmxId   DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[out] phKey     Pointer to the handle of a created key area.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\C9\EA\C7뵽\B5\C4\C3\DCԿ\C7\F8Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_KEY There is no available key area. CNcomment:û\D3п\D5\CFе\C4\C3\DCԿ\C7\F8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateDescrambler(HI_U32 u32DmxId, HI_HANDLE *phKey);


/**
\brief Creates a key area. The key area type and descrambling protocol type can be selected.CNcomment:\B4\B4\BD\A8һ\B8\F6\C3\DCԿ\C7\F8,֧\B3\D6ѡ\D4\F1\B8߰\B2ȫCA\BAͽ\E2\C8\C5Э\D2\E9\C0\E0\D0͡\A3CNend
\attention \n
When an advanced CA key area is created, the descrambling protocol depends on the hardware and interface settings are ignored.\n
CNcomment:\C8\E7\B9\FB\CAǸ߰\B2ȫCA\A3\AC\BD\E2\C8\C5Э\D2\E9\D2Ѿ\AD\D3\C9Ӳ\BC\FE\BE\F6\B6\A8\A3\AC\BDӿڵ\C4\C9\E8\D6ñ\BB\BA\F6\C2ԡ\A3CNend
\param[in] u32DmxId   DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[in] pstDesramblerAttr  Pointer to the attributes of a key area.CNcomment:\C3\DCԿ\C7\F8\CA\F4\D0\D4ָ\D5롣CNend
\param[out] phKey      Pointer to the handle of a created key area.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\C9\EA\C7뵽\B5\C4\C3\DCԿ\C7\F8Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_KEY  There is no available key area.CNcomment:û\D3п\D5\CFе\C4\C3\DCԿ\C7\F8\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  Not support HI_UNF_DMX_DESCRAMBLER_ATTR_S type.CNcomment:\B2\BB֧\B3ֵ\C4HI_UNF_DMX_DESCRAMBLER_ATTR_S\C0\E0\D0͡\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_CreateDescramblerExt(HI_U32 u32DmxId, const HI_UNF_DMX_DESCRAMBLER_ATTR_S *pstDesramblerAttr, HI_HANDLE *phKey);

/**
\brief Destroys an existing key area.CNcomment:\CF\FA\BBٴ\B4\BD\A8\B5\C4\C3\DCԿ\C7\F8\A1\A3CNend
\attention \n
If a key area is attached to a channel, the key area needs to be detached from the channel first, but the channel is not disabled.\n
If a key area is detached or destroyed before the attached channel is disabled, an error may occur during data receiving.
CNcomment:\C8\E7\B9\FB\C3\DCԿ\C7\F8\B0\F3\B6\A8\D4\DAͨ\B5\C0\C9ϣ\AC\BB\E1\CFȴ\D3ͨ\B5\C0\C9Ͻ\E2\B0\F3\B6\A8\C3\DCԿ\C7\F8\A3\AC\B5\AB\CA\C7ע\D2ⲻ\BB\E1\B9ر\D5ͨ\B5\C0\n
\C8\E7\B9\FBû\D3йر\D5ͨ\B5\C0\D4\F2\BD\F8\D0\D0\C3\DCԿ\C7\F8\B5Ľ\E2\B0󶨻\F2\CF\FA\BBٲ\D9\D7\F7\A3\AC\BF\C9\C4ܵ\BC\D6\C2\CA\FD\BEݽ\D3\CAյĴ\ED\CE\F3\A1\A3CNend
\param[in] hKey  Handle of the key area to be destroyed.CNcomment:\B4\FDɾ\B3\FD\B5\C4\C3\DCԿ\C7\F8Handle\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DestroyDescrambler(HI_HANDLE hKey);

/**
\brief Gets the attributes of a Descrambler.CNcomment:\BB\F1ȡ\C3\DCԿ\C5\E4\D6\C3\CA\F4\D0ԡ\A3CNend
\attention \n
NA.\n
CNcomment:\CEޡ\A3CNend
\param[in] hKey   key handle. CNcomment: key\BE\E4\B1\FA\A1\A3CNend
\param[out] pstAttr  Pointer to the attributes of a key area.CNcomment:\C3\DCԿ\C7\F8\CA\F4\D0\D4ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_KEY  There is no available key area.CNcomment:û\D3п\D5\CFе\C4\C3\DCԿ\C7\F8\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  Not support HI_UNF_DMX_DESCRAMBLER_ATTR_S type.CNcomment:\B2\BB֧\B3ֵ\C4HI_UNF_DMX_DESCRAMBLER_ATTR_S\C0\E0\D0͡\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetDescramblerAttr(HI_HANDLE hKey, HI_UNF_DMX_DESCRAMBLER_ATTR_S *pstAttr);

/**
\brief Sets the attributes of a Descrambler.CNcomment:\C9\E8\D6\C3\C3\DCԿ\C5\E4\D6\C3\CA\F4\D0ԡ\A3CNend
\attention \n
NA.\n
CNcomment:\CEޡ\A3CNend
\param[in] hKey   key handle. CNcomment: key\BE\E4\B1\FA\A1\A3CNend
\param[out] pstAttr  Pointer to the attributes of a key area.CNcomment:\C3\DCԿ\C7\F8\CA\F4\D0\D4ָ\D5롣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOFREE_KEY  There is no available key area.CNcomment:û\D3п\D5\CFе\C4\C3\DCԿ\C7\F8\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  Not support HI_UNF_DMX_DESCRAMBLER_ATTR_S type.CNcomment:\B2\BB֧\B3ֵ\C4HI_UNF_DMX_DESCRAMBLER_ATTR_S\C0\E0\D0͡\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetDescramblerAttr(HI_HANDLE hKey, HI_UNF_DMX_DESCRAMBLER_ATTR_S *pstAttr);

/**
\brief Sets the even keys of a key area. This API is used to configure the DEMUX descrambler based on even keys after the CA system obtains control words.CNcomment:\C9\E8\D6\C3\C3\DCԿ\C7\F8\B5\C4ż\C3\DCԿ\A1\A3CAϵͳ\B5õ\BD\BF\D8\D6\C6\D7ֺ󣬿ɵ\F7\D3ñ\BE\BDӿڽ\ABż\C3\DCԿ\C5\E4\D6õ\BDDEMUX\BD\E2\C8\C5ģ\BF顣CNend
\attention \n
pEvenKey points to the even key data to be set. The data consists of 16 bytes: CW1, CW2, ..., and CW16.\n
The key value can be set dynamically, that is, the key value can be set at any time after a key area is created.\n
The initial value of each key is 0, which indicates that data is not descrambled.
CNcomment:pEvenKeyָ\CF\F2Ҫ\C9\E8\D6õ\C4ż\C3\DCԿ\CA\FD\BEݡ\A3\CA\FD\BEݹ\B216byte\A3\ACbyte\D2\C0\B4\CE\CA\C7CW1\A1\A2CW2\A1\A2\A1\AD\A1\AD\A1\A2CW16\n
+\B3\D6\C3\DCԿ\C7\F8\B5Ķ\AF̬\C9\E8\D6ã\AC\BF\C9\D2\D4\D4\DA\C3\DCԿ\C7\F8\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CC\C9\E8\D6\C3\C3\DCԿֵ\n
\B5\B1\C9\E8\D6\C3\C3\DCԿ֮ǰ\A3\AC\C3\DCԿ\B5ĳ\F5ʱֵ\B6\BC\CA\C70\A3\AC\B1\EDʾ\B2\BB\D7\F6\BD\E2\C8š\A3CNend
\param[in] hKey  Handle of the key area to be set.CNcomment:\B4\FD\C9\E8\D6õ\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8EvenKey  Pointer to the 16-byte even key data to be set.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4ż\C3\DCԿ\CA\FD\BEݣ\AC\B1\D8\D0\EB\CA\C716\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetDescramblerEvenKey(HI_HANDLE hKey, const HI_U8 *pu8EvenKey);


/**
\brief Sets the odd keys of a key area. This API is used to configure the DEMUX descrambler based on odd keys after the CA system obtains control words.CNcomment:\C9\E8\D6\C3\C3\DCԿ\C7\F8\B5\C4\C6\E6\C3\DCԿ\A1\A3CAϵͳ\B5õ\BD\BF\D8\D6\C6\D7ֺ󣬿ɵ\F7\D3ñ\BE\BDӿڽ\AB\C6\E6\C3\DCԿ\C5\E4\D6õ\BDDEMUX\BD\E2\C8\C5ģ\BF顣CNend
\attention \n
pOddKey points to the odd key data to be set. The data consists of 16 bytes: CW1, CW2, ..., and CW16.\n
The key value can be set dynamically, that is, the key value can be set at any time after a key area is created.\n
The initial value of each key is 0, which indicates that data is not descrambled.
CNcomment:pOddKeyָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\C3\DCԿ\CA\FD\BEݡ\A3\C6\E6\C3\DCԿ\CA\FD\BEݹ\B216byte\A3\ACbyte\D2\C0\B4\CE\CA\C7CW1\A1\A2CW2\A1\A2\A1\AD\A1\AD\A1\A2CW16\n
+\B3\D6\C3\DCԿ\C7\F8\B5Ķ\AF̬\C9\E8\D6ã\AC\BF\C9\D2\D4\D4\DA\C3\DCԿ\C7\F8\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CC\C9\E8\D6\C3\C3\DCԿֵ\n
\B5\B1\C9\E8\D6\C3\C3\DCԿ֮ǰ\A3\AC\C3\DCԿ\B5ĳ\F5ʱֵ\B6\BC\CA\C70\A3\AC\B1\EDʾ\B2\BB\D7\F6\BD\E2\C8š\A3CNend
\param[in] hKey  Handle of the key area to be set.CNcomment:\B4\FD\C9\E8\D6õ\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8OddKey   Pointer to the 16-byte odd key data to be set.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\C3\DCԿ\CA\FD\BEݣ\AC\B1\D8\D0\EB\CA\C716\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetDescramblerOddKey(HI_HANDLE hKey, const HI_U8 *pu8OddKey);


/**
\brief Set Even IV.For algs do not use IV,do not care.CNcomment:\C9\E8\D6\C3ż\C3\DCԿ\C7\F8\B5ĳ\F5ʼ\BB\AF\CF\F2\C1\BF\A1\A3\B6\D4\D3ڲ\BB\C9漰\B3\F5ʼ\BB\AF\CF\F2\C1\BF\B5Ľ\E2\C8\C5\CB㷨\BF\C9\D2Բ\BB\B9\D8ע\A1\A3CNend
\attention \n
pu8IVKey points to the iv key data to be set.The data consists of 16 bytes: CW1, CW2, ..., and CW16.\n
The key value can be set dynamically, that is, the key value can be set at any time after a key area is created.
CNcomment:pu8IVKeyָ\CF\F2Ҫ\C9\E8\D6õĳ\F5ʼ\BB\AF\CF\F2\C1\BF\CA\FD\BEݡ\A3\C6\E6\C3\DCԿ\CA\FD\BEݹ\B216byte\A3\ACbyte\D2\C0\B4\CE\CA\C7CW1\A1\A2CW2\A1\A2\A1\AD\A1\AD\A1\A2CW16\n
+\B3\D6\C3\DCԿ\C7\F8\B5Ķ\AF̬\C9\E8\D6ã\AC\BF\C9\D2\D4\D4\DA\C3\DCԿ\C7\F8\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CC\C9\E8\D6á\A3CNend
\param[in] hKey  Handle of the key area to be set.CNcomment:\B4\FD\C9\E8\D6õ\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8IVKey   Pointer to the 16-byte IV key data to be set.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\C3\DCԿ\CA\FD\BEݣ\AC\B1\D8\D0\EB\CA\C716\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetDescramblerEvenIVKey(HI_HANDLE hKey, const HI_U8 *pu8IVKey);

/**
\brief Set Odd IV.For algs do not use IV,do not care.CNcomment:\C9\E8\D6\C3\C6\E6\C3\DCԿ\C7\F8\B5ĳ\F5ʼ\BB\AF\CF\F2\C1\BF\A1\A3\B6\D4\D3ڲ\BB\C9漰\B3\F5ʼ\BB\AF\CF\F2\C1\BF\B5Ľ\E2\C8\C5\CB㷨\BF\C9\D2Բ\BB\B9\D8ע\A1\A3CNend
\attention \n
pu8IVKey points to the iv key data to be set.The data consists of 16 bytes: CW1, CW2, ..., and CW16.\n
The key value can be set dynamically, that is, the key value can be set at any time after a key area is created.
CNcomment:pu8IVKeyָ\CF\F2Ҫ\C9\E8\D6õĳ\F5ʼ\BB\AF\CF\F2\C1\BF\CA\FD\BEݡ\A3\C6\E6\C3\DCԿ\CA\FD\BEݹ\B216byte\A3\ACbyte\D2\C0\B4\CE\CA\C7CW1\A1\A2CW2\A1\A2\A1\AD\A1\AD\A1\A2CW16\n
+\B3\D6\C3\DCԿ\C7\F8\B5Ķ\AF̬\C9\E8\D6ã\AC\BF\C9\D2\D4\D4\DA\C3\DCԿ\C7\F8\C9\EA\C7\EB\BA\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CC\C9\E8\D6á\A3CNend
\param[in] hKey  Handle of the key area to be set.CNcomment:\B4\FD\C9\E8\D6õ\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] pu8IVKey    Pointer to the 16-byte IV key data to be set.CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4\C6\E6\C3\DCԿ\CA\FD\BEݣ\AC\B1\D8\D0\EB\CA\C716\B8\F6\D7ֽڵ\C4\CA\FD\D7顣CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_SetDescramblerOddIVKey(HI_HANDLE hKey, const HI_U8 *pu8IVKey);

/**
\brief Attaches a key area to a specific channel.CNcomment:\B0\F3\B6\A8\C3\DCԿ\C7\F8\B5\BDָ\B6\A8ͨ\B5\C0\A1\A3CNend
\attention \n
A key area can be attached to multiple channels that belong to different DEMUXs.\n
The static loading data in the key areas that are attached to all types of channels can be descrambled.\n
The same key area or different key areas cannot be attached to the same channel.
CNcomment:һ\B8\F6\C3\DCԿ\C7\F8\BF\C9\D2԰󶨵\BD\B6\E0\B8\F6ͨ\B5\C0\C9ϣ\ACͨ\B5\C0\BF\C9\D2\D4\CA\F4\D3ڲ\BBͬ\B5\C4DEMUX\n
\BF\C9\D2Զ\D4\CB\F9\D3\D0\C0\E0\D0͵\C4ͨ\B5\C0\B0\F3\B6\A8\C3\DCԿ\C7\F8\BD\F8\D0\D0\CA\FD\BEݵĽ\E2\C8\C5\n
\B2\BB\D4\CA\D0\ED\D6ظ\B4\B0\F3\B6\A8\CF\E0ͬ\BB\F2\B2\BBͬ\B5\C4\C3\DCԿ\C7\F8\B5\BDͬһ\B8\F6ͨ\B5\C0\C9ϡ\A3CNend
\param[in] hKey    Handle of the key area to be attached.CNcomment:\B4\FD\B0󶨵\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] hChannel   Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_ATTACHED_KEY  A key area is attached to the channel.CNcomment:ͨ\B5\C0\C9\CF\D2Ѿ\AD\D3\D0һ\B8\F6\C3\DCԿ\C7\F8\B0\F3\B6\A8\D4\DA\C9\CF\C3档CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_AttachDescrambler(HI_HANDLE hKey, HI_HANDLE hChannel);


/**
\brief Detaches a key area from a channel.CNcomment:\BD\AB\C3\DCԿ\C7\F8\B4\D3ͨ\B5\C0\C9Ͻ\E2\B0󶨡\A3CNend
\attention \n
The key area used by a channel can be detached dynamically. That is, you can call this API to detach a key area at any time after it is attached.\n
The scrambled data, however, may not be descrambled after the key area is detached, which causes data error.\n
The value of a key area retains even after it is detached. If the key area is attached again, its value is still the previously configured value.\n
If you do not want to descramble data, you can detach the corresponding key area or set all key values to 0.
CNcomment:\BF\C9\D2Զ\AF̬\B5Ľ\E2\B0\F3\B6\A8ͨ\B5\C0ʹ\D3õ\C4\C3\DCԿ\C7\F8\A3\AC\BF\C9\D2\D4\D4ڰ󶨺\F3\B5\C4\C8\CE\D2\E2ʱ\BF\CCʹ\D3ô˽ӿڽ\E2\B0\F3\B6\A8\C3\DCԿ\C7\F8\n
\B5\AB\CAǽ\E2\B0󶨺\F3\BF\C9\C4ܵ\BC\D6¼\D3\C8\C5\CA\FD\BE\DDû\D3б\BB\BD\E2\C8ţ\AC\B5\BC\D6\C2\CA\FD\BEݴ\ED\CE\F3\n
\BD\E2\B0\F3\B6\A8\C3\DCԿ\C7\F8\B2\A2\B2\BB\C4ܸı\E4\C3\DCԿ\C7\F8\B5\C4ֵ\A3\AC\C8\E7\B9\FB\D6\D8\D0°\F3\B6\A8\C3\DCԿ\C7\F8\A3\AC\C3\DCԿֵ\C8\D4Ȼ\CA\C7\C9ϴ\CE\C9\E8\D6õ\C4ֵ\n
\C8\E7\B9\FB\B2\BB\CF\EB\BD\F8\D0н\E2\C8ţ\AC\B3\FD\C1˽\E2\B0\F3\B6\A8\C3\DCԿ\C7\F8֮\CD⣬Ҳ\BF\C9\D2\D4ֱ\BDӽ\AB\C3\DCԿֵȫ\B2\BF\C9\E8\D6\C3Ϊ0\C0\B4ʵ\CF֡\A3CNend
\param[in] hKey    Handle of the key area to be detached.CNcomment:\B4\FD\BD\E2\B0󶨵\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\param[in] hChannel  Channel handle.CNcomment:ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NOATTACH_KEY  No key areas are attached to the channel.CNcomment:ͨ\B5\C0\C9\CFû\D3а\F3\B6\A8\C8κ\CE\C3\DCԿ\C7\F8\A1\A3CNend
\retval ::HI_ERR_DMX_UNMATCH_KEY  The specified key area is not attached to the specified channel.CNcomment:ָ\B6\A8\B5\C4\C3\DCԿ\C7\F8û\D3а\F3\B6\A8\D4\DAָ\B6\A8\B5\C4ͨ\B5\C0\C9ϡ\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_DetachDescrambler(HI_HANDLE hKey, HI_HANDLE hChannel);


/**
\brief Obtains the handle of the key area that is attached to a channel.CNcomment:\BB\F1ȡͨ\B5\C0\B0󶨵\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\attention \n
If no key area is attached to the channel, the error code HI_ERR_DMX_NOATTACH_KEY is returned when you call this API.
CNcomment:\B5\B1ͨ\B5\C0û\D3а\F3\B6\A8\C3\DCԿ\C7\F8ʱ\A3\AC\B5\F7\D3ñ\BE\BDӿڷ\B5\BB\D8HI_ERR_DMX_NOATTACH_KEY\B4\ED\CE\F3\C2롣CNend
\param[in] hChannel  Handle of the channel to be queried.CNcomment:Ҫ\B2\E9ѯ\B5\C4ͨ\B5\C0\BE\E4\B1\FA\A1\A3CNend
\param[out] phKey     Pointer to the handle of the key area that is attached to a channel (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6ͨ\B5\C0\B0󶨵\C4\C3\DCԿ\C7\F8\BE\E4\B1\FA\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOATTACH_KEY  No key areas are attached to the channel.CNcomment:ͨ\B5\C0\C9\CFû\D3а\F3\B6\A8\C8κ\CE\C3\DCԿ\C7\F8\A1\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetDescramblerKeyHandle(HI_HANDLE hChannel, HI_HANDLE *phKey);


/**
\brief Obtains the number of available key areas.CNcomment:\BB\F1ȡ\BF\D5\CF\D0\C3\DCԿ\C7\F8\CA\FD\C1\BF\A1\A3CNend
\attention \n
Because key areas are shared by multiple DEMUXs, the first parameter is meaningless. Therefore, you only need to enter a valid value.CNcomment:\C3\DCԿ\C7\F8\D4ڼ\B8·DEMUX֮\BC乲\D3ã\AC\CB\F9\D2Ե\DAһ\B8\F6\B2\CE\CA\FDû\D3\D0\D2\E2\D2壬ֻҪ\CA\E4\C8\EBһ\B8\F6\BAϷ\A8ֵ\BEͿ\C9\D2\D4\C1ˡ\A3CNend
\param[in] u32DmxId   DEMUX ID. CNcomment: DEMUX\BAš\A3CNend
\param[out]  pu32FreeCount   Pointer to the number of available key areas (output).CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CA\E4\B3\F6\BF\D5\CF\D0\C3\DCԿ\C7\F8\CA\FDĿ\A1\A3CNend
\retval ::HI_SUCCESS Success.CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILURE  Calling this API fails.CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized.CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n
 N/A.CNcomment:\CEޡ\A3CNend
*/
HI_S32 HI_UNF_DMX_GetFreeDescramblerKeyCount(HI_U32 u32DmxId , HI_U32 * pu32FreeCount);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif  /* __HI_UNF_DESCRAMBLER_H__ */

