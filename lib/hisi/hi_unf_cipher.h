#ifndef __HI_UNF_CIPHER_H__
#define __HI_UNF_CIPHER_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
/*************************** Structure Definition ****************************/
/** \addtogroup      CIPHER */
/** @{ */  /** <!-- [CIPHER] */

/** max length of SM2, unit: word */
/** CNcomment: SM2\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λword */
#define SM2_LEN_IN_WROD                   (8)

/** max length of SM2, unit: byte */
/** CNcomment: SM2\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λbyte */
#define SM2_LEN_IN_BYTE                   (SM2_LEN_IN_WROD * 4)

/** CIPHER only update key, don't set the IV */
/** CNcomment: CIPHER \BD\F6\B8\FC\D0\C2\C3\DCԿ\A3\AC\B2\BB\B8\FC\CA\FD\BEݰ\FC\B5\C4IV */
#define CIPHER_IV_CHANGE_KEY_ONLY         (0)

/** CIPHER set key and IV for first package */
/** CNcomment: CIPHER \B8\FC\D0µ\DAһ\B8\F6\CA\FD\BEݰ\FC\B5\C4IV\BA\CD\C3\DCԿ*/
#define CIPHER_IV_CHANGE_ONE_PKG          (1)

/** CIPHER set key and IV for all package */
/** CNcomment: CIPHER \B8\FC\D0\C2\CB\F9\D3\D0\CA\FD\BEݰ\FC\B5\C4IV\BA\CD\C3\DCԿ*/
#define CIPHER_IV_CHANGE_ALL_PKG          (2)

/** CIPHER only update IV for first package, don't update the key*/
/** CNcomment: CIPHER \BD\F6\B8\FC\D0µ\DAһ\B8\F6\CA\FD\BEݰ\FC\B5\C4IV\A3\AC\B2\BB\B8\FC\D0\C2\C3\DCԿ */
#define CIPHER_IV_CHANGE_ONE_PKG_IV_ONLY  (3)


/** Cipher work mode */
/** CNcomment:CIPHER\B9\A4\D7\F7ģʽ */
typedef enum hiHI_UNF_CIPHER_WORK_MODE_E
{
    HI_UNF_CIPHER_WORK_MODE_ECB,        /**<Electronic codebook (ECB) mode, ECB has been considered insecure and it is recommended not to use it.*/    /**< CNcomment:ECBģʽ,ECB\B1\BB\C8\CFΪ\CAǲ\BB\B0\B2ȫ\CB㷨\A3\AC\BD\A8\D2鲻Ҫʹ\D3\C3\CB\FC\A1\A3*/
    HI_UNF_CIPHER_WORK_MODE_CBC,        /**<Cipher block chaining (CBC) mode*/  /**< CNcomment:CBCģʽ */
    HI_UNF_CIPHER_WORK_MODE_CFB,        /**<Cipher feedback (CFB) mode*/        /**< CNcomment:CFBģʽ */
    HI_UNF_CIPHER_WORK_MODE_OFB,        /**<Output feedback (OFB) mode*/        /**< CNcomment:OFBģʽ */
    HI_UNF_CIPHER_WORK_MODE_CTR,        /**<Counter (CTR) mode*/                /**< CNcomment:CTRģʽ */
    HI_UNF_CIPHER_WORK_MODE_CCM,        /**<Counter (CCM) mode*/                /**< CNcomment:CCMģʽ */
    HI_UNF_CIPHER_WORK_MODE_GCM,        /**<Counter (GCM) mode*/                /**< CNcomment:GCMģʽ */
    HI_UNF_CIPHER_WORK_MODE_BUTT
}HI_UNF_CIPHER_WORK_MODE_E;

/** Cipher algorithm */
/** CNcomment:CIPHER\BC\D3\C3\DC\CB㷨 */
typedef enum hiHI_UNF_CIPHER_ALG_E
{
    HI_UNF_CIPHER_ALG_DES           = 0x0,  /**< Data encryption standard (DES) algorithm,DES has been considered insecure and it is recommended not to use it. */     /**< CNcomment: DES\CB㷨\A3\AC\B1\BB\C8\CFΪ\CAǲ\BB\B0\B2ȫ\CB㷨\A3\AC\BD\A8\D2鲻Ҫʹ\D3\C3\CB\FC\A1\A3*/
    HI_UNF_CIPHER_ALG_3DES          = 0x1,  /**< 3DES algorithm */                               /**< CNcomment: 3DES\CB㷨 */
    HI_UNF_CIPHER_ALG_AES           = 0x2,  /**< Advanced encryption standard (AES) algorithm */ /**< CNcomment: AES\CB㷨 */
    HI_UNF_CIPHER_ALG_SM1           = 0x3,  /**<SM1 algorithm*/  /**< CNcomment: SM1\CB㷨 */
    HI_UNF_CIPHER_ALG_SM4           = 0x4,  /**<SM4 algorithm*/  /**< CNcomment: SM4\CB㷨 */
    HI_UNF_CIPHER_ALG_DMA           = 0x5,  /**<DMA copy*/  /**< CNcomment: DMA\BF\BD\B1\B4 */
    HI_UNF_CIPHER_ALG_BUTT          = 0x6
}HI_UNF_CIPHER_ALG_E;

/** Key length */
/** CNcomment: \C3\DCԿ\B3\A4\B6\C8 */
typedef enum hiHI_UNF_CIPHER_KEY_LENGTH_E
{
    HI_UNF_CIPHER_KEY_AES_128BIT    = 0x0,  /**< 128-bit key for the AES algorithm */ /**< CNcomment:AES\D4\CB\CB㷽ʽ\CF²\C9\D3\C3128bit\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_KEY_AES_192BIT    = 0x1,  /**< 192-bit key for the AES algorithm */ /**< CNcomment:AES\D4\CB\CB㷽ʽ\CF²\C9\D3\C3192bit\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_KEY_AES_256BIT    = 0x2,  /**< 256-bit key for the AES algorithm */ /**< CNcomment:AES\D4\CB\CB㷽ʽ\CF²\C9\D3\C3256bit\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_KEY_DES_3KEY      = 0x2,  /**< Three keys for the DES algorithm */  /**< CNcomment:DES\D4\CB\CB㷽ʽ\CF²\C9\D3\C33\B8\F6key */
    HI_UNF_CIPHER_KEY_DES_2KEY      = 0x3,  /**< Two keys for the DES algorithm */    /**< CNcomment: DES\D4\CB\CB㷽ʽ\CF²\C9\D3\C32\B8\F6key  */
    HI_UNF_CIPHER_KEY_DEFAULT       = 0x0,  /**< default key length, DES-8, SM1-48, SM4-16 */    /**< CNcomment: Ĭ\C8\CFKey\B3\A4\B6ȣ\ACDES-8, SM1-48, SM4-16*/
}HI_UNF_CIPHER_KEY_LENGTH_E;

/** Cipher bit width */
/** CNcomment: \BC\D3\C3\DCλ\BF\ED */
typedef enum hiHI_UNF_CIPHER_BIT_WIDTH_E
{
    HI_UNF_CIPHER_BIT_WIDTH_64BIT   = 0x0,  /**< 64-bit width */   /**< CNcomment:64bitλ\BF\ED */
    HI_UNF_CIPHER_BIT_WIDTH_8BIT    = 0x1,  /**< 8-bit width */    /**< CNcomment:8bitλ\BF\ED */
    HI_UNF_CIPHER_BIT_WIDTH_1BIT    = 0x2,  /**< 1-bit width */    /**< CNcomment:1bitλ\BF\ED */
    HI_UNF_CIPHER_BIT_WIDTH_128BIT  = 0x3,  /**< 128-bit width */  /**< CNcomment:128bitλ\BF\ED */
}HI_UNF_CIPHER_BIT_WIDTH_E;

/** Cipher control parameters */
/** CNcomment:\BC\D3\C3ܿ\D8\D6Ʋ\CE\CA\FD\B1\E4\B8\FC\B1\EA־ */
typedef struct hiUNF_CIPHER_CTRL_CHANGE_FLAG_S
{
    HI_U32   bit1IV:4;              /**< Initial Vector change flag, 0-don't set, 1-set IV for first package, 2-set IV for each package  */ /**< CNcomment:\CF\F2\C1\BF\B1\E4\B8\FC, 0-\B2\BB\C9\E8\D6ã\AC1-ֻ\C9\E8\D6õ\DAһ\B8\F6\B0\FC\A3\AC2-ÿ\B8\F6\B0\FC\B6\BC\C9\E8\D6\C3 */
    HI_U32   bitsResv:28;           /**< Reserved */                     /**< CNcomment:\B1\A3\C1\F4 */
}HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S;

/** Key ladder selecting parameters */
/** CNcomment:ʹ\D3\C3\C4ĸ\F6key ladder\B1\EA־ */
typedef enum hiUNF_CIPHER_CA_TYPE_E
{
    HI_UNF_CIPHER_CA_TYPE_R2R   = 0x0,      /**< Using R2R key ladder */                                                 /**< CNcomment:ʹ\D3\C3R2R key ladder */
    HI_UNF_CIPHER_CA_TYPE_SP,               /**< Using SP key ladder */                                                  /**< CNcomment:ʹ\D3\C3SP key ladder */
    HI_UNF_CIPHER_CA_TYPE_CSA2,             /**< Using CSA2 key ladder */                                                /**< CNcomment:ʹ\D3\C3CSA2 key ladder */
    HI_UNF_CIPHER_CA_TYPE_CSA3,             /**< Using CSA3 key ladder */                                                /**< CNcomment:ʹ\D3\C3CSA3 key ladder */
    HI_UNF_CIPHER_CA_TYPE_MISC,             /**< Using MISC ladder */                                                    /**< CNcomment:ʹ\D3\C3SP key ladder */
    HI_UNF_CIPHER_CA_TYPE_GDRM,             /**< Using GDRM ladder */                                                    /**< CNcomment:ʹ\D3\C3GDRM key ladder */
    HI_UNF_CIPHER_CA_TYPE_BLPK,             /**< Using BLPK ladder */                                                    /**< CNcomment:ʹ\D3\C3BLPK key ladder */
    HI_UNF_CIPHER_CA_TYPE_LPK,              /**< Using LPK ladder */                                                     /**< CNcomment:ʹ\D3\C3LPK key ladder */
    HI_UNF_CIPHER_CA_TYPE_IRDETO_HCA,       /**< Using high level code authentication key ladder*/                       /**< CNcomment:\C9ϲ\E3Ӧ\D3\C3У\D1\E9keyladder*/
    HI_UNF_CIPHER_CA_TYPE_STBROOTKEY,       /**< Using for AntiCopy With STB_Root_Key  */                                /**< CNcomment:ʹ\D3\C3STB_Root_Key\BCӽ\E2\C3\DC,\D3\C3\D3ڷ\C0\BF\BD\B1\B4 */
    HI_UNF_CIPHER_CA_TYPE_SECSTORE,         /**< Using SECSTORE keyladder */                                             /**< CNcomment:ʹ\D3\C3SecStore key ladder */
    HI_UNF_CIPHER_CA_TYPE_CLEARCW,          /**< Using Clear keyladder */                                                /**< CNcomment:ʹ\D3\C3͸\C3\F7 key ladder */
    HI_UNF_CIPHER_CA_TYPE_OTHER,            /**< Using Other keyladder */                                                /**< CNcomment:ʹ\D3\C3\C6\E4\CB\FC key ladder */
    HI_UNF_CIPHER_CA_TYPE_BUTT
}HI_UNF_CIPHER_CA_TYPE_E;

/** Encryption/Decryption type selecting */
/** CNcomment:CIPHER\BCӽ\E2\C3\DC\C0\E0\D0\CDѡ\D4\F1 */
typedef enum
{
    HI_UNF_CIPHER_TYPE_NORMAL       = 0x0,  /**< Create normal channel */                                                /**< CNcomment: \B4\B4\BD\A8\C6\D5ͨͨ\B5\C0 */
    HI_UNF_CIPHER_TYPE_COPY_AVOID,          /**< Create special channel for avoid copy */                                /**< CNcomment: \B4\B4\BD\A8\B7\C0ֹ\B1\BB\BF\BD\B1\B4\B5\C4ר\D3\C3ͨ\B5\C0 */
    HI_UNF_CIPHER_TYPE_NONSEC,              /**< Create unsecured channel, for internal use only */                      /**< CNcomment: \B4\B4\BD\A8\B1\A3\C1\F4\B5ķǰ\B2ȫͨ\B5\C0\A3\AC\BD\F6\CF\DE\C4ڲ\BFʹ\D3\C3 */
    HI_UNF_CIPHER_TYPE_BUTT,
}HI_UNF_CIPHER_TYPE_E;

/** Structure of the cipher type */
/** CNcomment:\BC\D3\C3\DC\C0\E0\D0ͽṹ */
typedef struct
{
    HI_UNF_CIPHER_TYPE_E enCipherType;
}HI_UNF_CIPHER_ATTS_S;

/** sm1 round config */
/** CNcomment: sm1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FD */
typedef enum hiHI_UNF_CIPHER_SM1_ROUND_E
{
    HI_UNF_CIPHER_SM1_ROUND_08 = 0x00,          /**< sm1 round 08 */ /**< CNcomment:SM1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FDΪ08 */
    HI_UNF_CIPHER_SM1_ROUND_10 = 0x01,          /**< sm1 round 10 */ /**< CNcomment:SM1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FDΪ10 */
    HI_UNF_CIPHER_SM1_ROUND_12 = 0x02,          /**< sm1 round 12 */ /**< CNcomment:SM1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FDΪ12 */
    HI_UNF_CIPHER_SM1_ROUND_14 = 0x03,          /**< sm1 round 14 */ /**< CNcomment:SM1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FDΪ14 */
    HI_UNF_CIPHER_SM1_ROUND_BUTT,
}HI_UNF_CIPHER_SM1_ROUND_E;

/** Structure of the cipher control information */
/** CNcomment:\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_S
{
    HI_U32 u32Key[8];                               /**< Key input */                                                                                                     /**< CNcomment:\CA\E4\C8\EB\C3\DCԿ */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_BOOL bKeyByCA;                               /**< Encryption using advanced conditional access (CA) or decryption using keys */                                    /**< CNcomment:\CAǷ\F1ʹ\D3ø߰\B2ȫCA\BC\D3\C3ܻ\F2\BD\E2\C3\DCKey */
    HI_UNF_CIPHER_CA_TYPE_E enCaType;                   /**< Select keyladder type when using advanced CA */                                                                  /**< CNcomment:ʹ\D3ø߰\B2ȫCAʱ,ѡ\D4\F1\BA\CE\D6\D6\C0\E0\D0͵\C4keyladder */
    HI_UNF_CIPHER_ALG_E enAlg;                      /**< Cipher algorithm */                                                                                              /**< CNcomment:\BC\D3\C3\DC\CB㷨 */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:\BC\D3\C3ܻ\F2\BD\E2\C3ܵ\C4λ\BF\ED */
    HI_UNF_CIPHER_WORK_MODE_E enWorkMode;           /**< Operating mode */                                                                                                /**< CNcomment:\B9\A4\D7\F7ģʽ */
    HI_UNF_CIPHER_KEY_LENGTH_E enKeyLen;            /**< Key length */                                                                                                    /**< CNcomment:\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_S;

/** Structure of the cipher AES control information */
/** CNcomment:AES\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_AES_S
{
    HI_U32 u32EvenKey[8];                           /**< Key input, default use this key*/                                                                                /**< CNcomment:\CA\E4\C8\EBż\C3\DCԿ, Ĭ\C8\CFʹ\D3\C3ż\C3\DCԿ */
    HI_U32 u32OddKey[8];                            /**< Key input, only valid for Multi encrypt/decrypt*/                                                                /**< CNcomment:\CA\E4\C8\EB\C6\E6\C3\DCԿ, ֻ\B6Զ\E0\B0\FC\BCӽ\E2\C3\DC\D3\D0Ч */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:\BC\D3\C3ܻ\F2\BD\E2\C3ܵ\C4λ\BF\ED */
    HI_UNF_CIPHER_KEY_LENGTH_E enKeyLen;            /**< Key length */                                                                                                    /**< CNcomment:\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_AES_S;

/** Structure of the cipher AES CCM/GCM control information */
/** CNcomment:AES CCM/GCM \BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_AES_CCM_GCM_S
{
    HI_U32 u32Key[8];                               /**< Key input */                                                                                                     /**< CNcomment:\CA\E4\C8\EB\C3\DCԿ */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_KEY_LENGTH_E enKeyLen;            /**< Key length */                                                                                                    /**< CNcomment:\C3\DCԿ\B3\A4\B6\C8 */
    HI_U32 u32IVLen;                                /**< IV lenght for CCM/GCM, which is an element of {7, 8, 9, 10, 11, 12, 13} for CCM, and is an element of [1-16] for GCM*/  /**< CNcomment: CCM/GCM\B5\C4IV\B3\A4\B6ȣ\ACCCM\B5\C4ȡֵ\B7\B6Χ{7, 8, 9, 10, 11, 12, 13}\A3\AC GCM\B5\C4ȡֵ\B7\B6Χ[1-16]*/
    HI_U32 u32TagLen;                               /**< Tag lenght for CCM which is an element of {4,6,8,10,12,14,16}*/          /**< CNcomment: CCM\B5\C4TAG\B3\A4\B6ȣ\ACȡֵ\B7\B6Χ{4,6,8,10,12,14,16}*/
    HI_U32 u32ALen;                                 /**< Associated data for CCM and GCM*/                                        /**< CNcomment: CCM/GCM\B5Ĺ\D8\C1\AA\CA\FD\BEݳ\A4\B6\C8*/
    HI_U32 u32APhyAddr;                             /**< Physical address of Associated data for CCM and GCM*/                                        /**< CNcomment: CCM/GCM\B5Ĺ\D8\C1\AA\CA\FD\BEݳ\A4\B6\C8*/
} HI_UNF_CIPHER_CTRL_AES_CCM_GCM_S;

/** Structure of the cipher DES control information */
/** CNcomment:DES\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_DES_S
{
    HI_U32 u32Key[2];                               /**< Key input */                                                                                                     /**< CNcomment:\CA\E4\C8\EBż\C3\DCԿ */
    HI_U32 u32IV[2];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:\BC\D3\C3ܻ\F2\BD\E2\C3ܵ\C4λ\BF\ED */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_DES_S;

/** Structure of the cipher 3DES control information */
/** CNcomment:3DES\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_3DES_S
{
    HI_U32 u32Key[6];                               /**< Key input */                                                                                                     /**< CNcomment:\CA\E4\C8\EBż\C3\DCԿ */
    HI_U32 u32IV[2];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:\BC\D3\C3ܻ\F2\BD\E2\C3ܵ\C4λ\BF\ED */
    HI_UNF_CIPHER_KEY_LENGTH_E enKeyLen;            /**< Key length */                                                                                                    /**< CNcomment:\C3\DCԿ\B3\A4\B6\C8 */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_3DES_S;

/** Structure of the cipher SM1 control information */
/** CNcomment:SM1\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_SM1_S
{
    HI_U32 u32EK[4];                               /**< Key of EK input */                                                                                                /**< CNcomment:\CA\E4\C8\EB\C3\DCԿEK */
    HI_U32 u32AK[4];                               /**< Key of AK input */                                                                                                /**< CNcomment:\CA\E4\C8\EB\C3\DCԿAK */
    HI_U32 u32SK[4];                               /**< Key of SK input */                                                                                                /**< CNcomment:\CA\E4\C8\EB\C3\DCԿSK */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:\BC\D3\C3ܻ\F2\BD\E2\C3ܵ\C4λ\BF\ED */
    HI_UNF_CIPHER_SM1_ROUND_E enSm1Round;           /**< SM1 round number, should be 8, 10, 12 or 14*/                                                                                                    /**< CNcomment:sm1\BC\C6\CB\E3\B5\C4\C2\D6\CA\FD\C5\E4\D6\C3 */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_SM1_S;

/** Structure of the cipher SM4 control information */
/** CNcomment:SM4\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_SM4_S
{
    HI_U32 u32Key[4];                               /**< Key  input */                                                                                                    /**< CNcomment:\CA\E4\C8\EB\C3\DCԿ */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:\B3\F5ʼ\CF\F2\C1\BF */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:\BF\D8\D6\C6\D0\C5Ϣ\B1\E4\B8\FCѡ\CFѡ\CF\EE\D6\D0û\D3б\EAʶ\B5\C4\CF\EEĬ\C8\CFȫ\B2\BF\B1\E4\B8\FC */
} HI_UNF_CIPHER_CTRL_SM4_S;

/** Expand Structure of the cipher control information */
/** CNcomment:\BC\D3\C3ܿ\D8\D6\C6\D0\C5Ϣ\C0\A9չ\BDṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_EX_S
{
    HI_UNF_CIPHER_ALG_E enAlg;                      /**< Cipher algorithm */                                                                                              /**< CNcomment:\BC\D3\C3\DC\CB㷨 */
    HI_UNF_CIPHER_WORK_MODE_E enWorkMode;           /**< Operating mode */                                                                                                /**< CNcomment:\B9\A4\D7\F7ģʽ */
    HI_BOOL bKeyByCA;                               /**< Encryption using advanced conditional access (CA) or decryption using keys */                                    /**< CNcomment:\CAǷ\F1ʹ\D3ø߰\B2ȫCA\BC\D3\C3ܻ\F2\BD\E2\C3\DCKey */
    /**< Parameter for special algorithm
        for AES, the pointer should point to HI_UNF_CIPHER_CTRL_AES_S;
        for AES_CCM or AES_GCM, the pointer should point to HI_UNF_CIPHER_CTRL_AES_CCM_GCM_S;
        for DES, the pointer should point to HI_UNF_CIPHER_CTRL_DES_S;
        for 3DES, the pointer should point to HI_UNF_CIPHER_CTRL_3DES_S;
        for SM1, the pointer should point to HI_UNF_CIPHER_CTRL_SM1_S;
        for SM4, the pointer should point to HI_UNF_CIPHER_CTRL_SM4_S;
    */
    /**< CNcomment: \CB㷨\B5\C4ר\D3ò\CE\CA\FD
        \B6\D4\D3\DA AES, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_AES_S;
        \B6\D4\D3\DA AES_CCM \BB\F2 AES_GCM, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_AES_CCM_GCM_S;
        \B6\D4\D3\DA DES, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_DES_S;
        \B6\D4\D3\DA 3DES, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_3DES_S;
        \B6\D4\D3\DA SM1, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_SM1_S;
        \B6\D4\D3\DA SM4, ָ\D5\EBӦָ\CF\F2 HI_UNF_CIPHER_CTRL_SM4_S;
    */
    HI_VOID *pParam;
} HI_UNF_CIPHER_CTRL_EX_S;

/** Cipher data */
/** CNcomment:\BCӽ\E2\C3\DC\CA\FD\BE\DD */
typedef struct hiHI_UNF_CIPHER_DATA_S
{
    HI_U32 u32SrcPhyAddr;     /**< phy address of the original data */   /**< CNcomment:Դ\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ */
    HI_U32 u32DestPhyAddr;    /**< phy address of the purpose data */    /**< CNcomment:Ŀ\B5\C4\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ */
    HI_U32 u32ByteLength;     /**< cigher data length*/                 /**< CNcomment:\BCӽ\E2\C3\DC\CA\FD\BEݳ\A4\B6\C8 */
    HI_BOOL bOddKey;    /**< Use odd key or even key*/                  /**< CNcomment:\CAǷ\F1ʹ\D3\C3\C6\E6\C3\DCԿ */
} HI_UNF_CIPHER_DATA_S;

/** Hash algrithm type */
/** CNcomment:\B9\FEϣ\CB㷨\C0\E0\D0\CD */
typedef enum hiHI_UNF_CIPHER_HASH_TYPE_E
{
    HI_UNF_CIPHER_HASH_TYPE_SHA1,
    HI_UNF_CIPHER_HASH_TYPE_SHA256,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA1,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA256,
    HI_UNF_CIPHER_HASH_TYPE_IRDETO_CBCMAC,
    HI_UNF_CIPHER_HASH_TYPE_SHA224,
    HI_UNF_CIPHER_HASH_TYPE_SHA384,
    HI_UNF_CIPHER_HASH_TYPE_SHA512,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA224,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA384,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA512,
    HI_UNF_CIPHER_HASH_TYPE_SM3,
    HI_UNF_CIPHER_HASH_TYPE_BUTT,
}HI_UNF_CIPHER_HASH_TYPE_E;

/** Hash init struct input */
/** CNcomment:\B9\FEϣ\CB㷨\B3\F5ʼ\BB\AF\CA\E4\C8\EB\BDṹ\CC\E5 */
typedef struct
{
    HI_U8 *pu8HMACKey;
    HI_U32 u32HMACKeyLen;
    HI_UNF_CIPHER_HASH_TYPE_E eShaType;
}HI_UNF_CIPHER_HASH_ATTS_S;

typedef enum hiHI_UNF_CIPHER_RSA_ENC_SCHEME_E
{
    HI_UNF_CIPHER_RSA_ENC_SCHEME_NO_PADDING,            /**< without padding */             /**< CNcomment: \B2\BB\CC\EE\B3\E4 */
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_0,          /**< PKCS#1 block type 0 padding*/  /**< CNcomment: PKCS#1\B5\C4block type 0\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_1,          /**< PKCS#1 block type 1 padding*/  /**< CNcomment: PKCS#1\B5\C4block type 1\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_2,          /**< PKCS#1 block type 2 padding*/  /**< CNcomment: PKCS#1\B5\C4block type 2\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA1,       /**< PKCS#1 RSAES-OAEP-SHA1 padding*/    /**< CNcomment: PKCS#1\B5\C4RSAES-OAEP-SHA1\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA224,     /**< PKCS#1 RSAES-OAEP-SHA224 padding*/  /**< CNcomment: PKCS#1\B5\C4RSAES-OAEP-SHA224\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA256,     /**< PKCS#1 RSAES-OAEP-SHA256 padding*/  /**< CNcomment: PKCS#1\B5\C4RSAES-OAEP-SHA256\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA384,     /**< PKCS#1 RSAES-OAEP-SHA384 padding*/    /**< CNcomment: PKCS#1\B5\C4RSAES-OAEP-SHA384\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA512,     /**< PKCS#1 RSAES-OAEP-SHA512 padding*/  /**< CNcomment: PKCS#1\B5\C4RSAES-OAEP-SHA512\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_PKCS1_V1_5,      /**< PKCS#1 RSAES-PKCS1_V1_5 padding*/   /**< CNcomment: PKCS#1\B5\C4PKCS1_V1_5\CC\EE\B3䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BUTT,
}HI_UNF_CIPHER_RSA_ENC_SCHEME_E;

typedef enum hiHI_UNF_CIPHER_RSA_SIGN_SCHEME_E
{
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA1 = 0x100, /**< PKCS#1 RSASSA_PKCS1_V15_SHA1 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA1ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA224,       /**< PKCS#1 RSASSA_PKCS1_V15_SHA224 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA224ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA256,       /**< PKCS#1 RSASSA_PKCS1_V15_SHA256 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA256ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA384,       /**< PKCS#1 RSASSA_PKCS1_V15_SHA384 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA384ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA512,       /**< PKCS#1 RSASSA_PKCS1_V15_SHA512 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA512ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA1,         /**< PKCS#1 RSASSA_PKCS1_PSS_SHA1 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA1ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA224,       /**< PKCS#1 RSASSA_PKCS1_PSS_SHA224 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA224ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA256,       /**< PKCS#1 RSASSA_PKCS1_PSS_SHA256 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA256ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA384,       /**< PKCS#1 RSASSA_PKCS1_PSS_SHA1 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA384ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA512,       /**< PKCS#1 RSASSA_PKCS1_PSS_SHA256 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA512ǩ\C3\FB\CB㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_BUTT,
}HI_UNF_CIPHER_RSA_SIGN_SCHEME_E;

typedef struct
{
    HI_U8  *pu8N;              /**< point to public modulus  */   /**< CNcomment: ָ\CF\F2RSA\B9\ABԿN\B5\C4ָ\D5\EB*/
    HI_U8  *pu8E;              /**< point to public exponent */   /**< CNcomment: ָ\CF\F2RSA\B9\ABԿE\B5\C4ָ\D5\EB*/
    HI_U16 u16NLen;            /**< length of public modulus, max value is 512Byte*/  /**< CNcomment: RSA\B9\ABԿN\B5ĳ\A4\B6\C8, \D7\EE\B4\F3Ϊ512Byte*/
    HI_U16 u16ELen;            /**< length of public exponent, max value is 512Byte*/  /**< CNcomment: RSA\B9\ABԿE\B5ĳ\A4\B6\C8, \D7\EE\B4\F3Ϊ512Byte*/
}HI_UNF_CIPHER_RSA_PUB_KEY_S;

/** RSA private key struct */
/** CNcomment:RSA˽Կ\BDṹ\CC\E5 */
typedef struct
{
    HI_U8 *pu8N;                      /*!<  public modulus    */ /**< CNcomment: ָ\CF\F2RSA\B9\ABԿN\B5\C4ָ\D5\EB*/
    HI_U8 *pu8E;                      /*!<  public exponent   */ /**< CNcomment: ָ\CF\F2RSA\B9\ABԿE\B5\C4ָ\D5\EB*/
    HI_U8 *pu8D;                      /*!<  private exponent  */ /**< CNcomment: ָ\CF\F2RSA˽ԿD\B5\C4ָ\D5\EB*/
    HI_U8 *pu8P;                      /*!<  1st prime factor  */ /**< CNcomment: ָ\CF\F2RSA˽ԿP\B5\C4ָ\D5\EB*/
    HI_U8 *pu8Q;                      /*!<  2nd prime factor  */ /**< CNcomment: ָ\CF\F2RSA˽ԿQ\B5\C4ָ\D5\EB*/
    HI_U8 *pu8DP;                     /*!<  D % (P - 1)       */ /**< CNcomment: ָ\CF\F2RSA˽ԿDP\B5\C4ָ\D5\EB*/
    HI_U8 *pu8DQ;                     /*!<  D % (Q - 1)       */ /**< CNcomment: ָ\CF\F2RSA˽ԿDQ\B5\C4ָ\D5\EB*/
    HI_U8 *pu8QP;                     /*!<  1 / (Q % P)       */ /**< CNcomment: ָ\CF\F2RSA˽ԿQP\B5\C4ָ\D5\EB*/
    HI_U16 u16NLen;                   /**< length of public modulus */   /**< CNcomment: RSA\B9\ABԿN\B5ĳ\A4\B6\C8*/
    HI_U16 u16ELen;                   /**< length of public exponent */  /**< CNcomment: RSA\B9\ABԿE\B5ĳ\A4\B6\C8*/
    HI_U16 u16DLen;                   /**< length of private exponent */ /**< CNcomment: RSA˽ԿD\B5ĳ\A4\B6\C8*/
    HI_U16 u16PLen;                   /**< length of 1st prime factor,should be half of u16NLen */ /**< CNcomment: RSA˽ԿP\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪu16NLen\B3\A4\B6ȵ\C41/2*/
    HI_U16 u16QLen;                   /**< length of 2nd prime factor,should be half of u16NLen */ /**< CNcomment: RSA˽ԿQ\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪu16NLen\B3\A4\B6ȵ\C41/2*/
    HI_U16 u16DPLen;                  /**< length of D % (P - 1),should be half of u16NLen */      /**< CNcomment: RSA˽ԿDP\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪu16NLen\B3\A4\B6ȵ\C41/2*/
    HI_U16 u16DQLen;                  /**< length of D % (Q - 1),should be half of u16NLen */      /**< CNcomment: RSA˽ԿDQ\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪu16NLen\B3\A4\B6ȵ\C41/2*/
    HI_U16 u16QPLen;                  /**< length of 1 / (Q % P),should be half of u16NLen */      /**< CNcomment: RSA˽ԿQP\B5ĳ\A4\B6ȣ\AC\B1\D8\D0\EBΪu16NLen\B3\A4\B6ȵ\C41/2*/
}HI_UNF_CIPHER_RSA_PRI_KEY_S;

/** RSA public key encryption struct input */
/** CNcomment:RSA \B9\ABԿ\BCӽ\E2\C3\DC\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct
{
    HI_UNF_CIPHER_RSA_ENC_SCHEME_E enScheme;   /** RSA encryption scheme*/ /** CNcomment:RSA\CA\FD\BEݼӽ\E2\C3\DC\CB㷨\B2\DF\C2\D4*/
    HI_UNF_CIPHER_RSA_PUB_KEY_S stPubKey;      /** RSA private key struct */ /** CNcomment:RSA˽Կ\BDṹ\CC\E5 */
}HI_UNF_CIPHER_RSA_PUB_ENC_S;

/** RSA private key decryption struct input */
/** CNcomment:RSA ˽Կ\BD\E2\C3\DC\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct
{
    HI_UNF_CIPHER_RSA_ENC_SCHEME_E enScheme; /** RSA encryption scheme */ /** CNcomment:RSA\CA\FD\BEݼӽ\E2\C3\DC\CB㷨*/
    HI_UNF_CIPHER_RSA_PRI_KEY_S stPriKey;    /** RSA private key struct */ /** CNcomment:RSA˽Կ\BDṹ\CC\E5 */
}HI_UNF_CIPHER_RSA_PRI_ENC_S;

/** RSA signature struct input */
/** CNcomment:RSAǩ\C3\FB\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct
{
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_E enScheme;  /** RSA signature scheme*/ /** CNcomment:RSA\CA\FD\BE\DDǩ\C3\FB\B2\DF\C2\D4*/
    HI_UNF_CIPHER_RSA_PRI_KEY_S stPriKey;      /** RSA private key struct */ /** CNcomment:RSA˽Կ\BDṹ\CC\E5 */
 }HI_UNF_CIPHER_RSA_SIGN_S;

/** RSA signature verify struct input */
/** CNcomment:RSAǩ\C3\FB\D1\E9֤\CB㷨\B2\CE\CA\FD\CA\E4\C8\EB\BDṹ\CC\E5 */
typedef struct
{
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_E enScheme; /** RSA signature scheme*/ /** CNcomment:RSA\CA\FD\BE\DDǩ\C3\FB\B2\DF\C2\D4*/
    HI_UNF_CIPHER_RSA_PUB_KEY_S stPubKey;     /** RSA public key struct */ /** CNcomment:RSA\B9\ABԿ\BDṹ\CC\E5 */
 }HI_UNF_CIPHER_RSA_VERIFY_S;

 /** SM2 signature struct input */
/** CNcomment: SM2ǩ\C3\FB\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
 typedef struct hiHI_UNF_CIPHER_SM2_SIGN_S
{
    HI_U32 u32d[SM2_LEN_IN_WROD];
    HI_U32 u32Px[SM2_LEN_IN_WROD];
    HI_U32 u32Py[SM2_LEN_IN_WROD];
    HI_U8 *pu8Id;
    HI_U16 u16IdLen;
}HI_UNF_CIPHER_SM2_SIGN_S;

/** SM2 signature verify struct input */
/** CNcomment: SM2ǩ\C3\FB\D1\E9֤\CB㷨\B2\CE\CA\FD\CA\E4\C8\EB\BDṹ\CC\E5 */
typedef struct hiHI_UNF_CIPHER_SM2_VERIFY_S
{
    HI_U32 u32Px[SM2_LEN_IN_WROD];
    HI_U32 u32Py[SM2_LEN_IN_WROD];
    HI_U8 *pu8Id;
    HI_U16 u16IdLen;
}HI_UNF_CIPHER_SM2_VERIFY_S;

/** SM2 publuc key encryption struct input */
/** CNcomment: SM2\B9\ABԿ\BC\D3\C3\DC\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiHI_UNF_CIPHER_SM2_ENC_S
{
    HI_U32 u32Px[SM2_LEN_IN_WROD];
    HI_U32 u32Py[SM2_LEN_IN_WROD];
}HI_UNF_CIPHER_SM2_ENC_S;

/** SM2 private key decryption struct input */
/** CNcomment: SM2˽Կ\BD\E2\C3\DC\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiHI_UNF_CIPHER_SM2_DEC_S
{
    HI_U32 u32d[SM2_LEN_IN_WROD];
}HI_UNF_CIPHER_SM2_DEC_S;

/** SM2 key generate struct input */
/** CNcomment: SM2\C3\DCԿ\C9\FA\B3\C9\CB㷨\B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiHI_UNF_CIPHER_SM2_KEY_S
{
    HI_U32 u32d[SM2_LEN_IN_WROD];
    HI_U32 u32Px[SM2_LEN_IN_WROD];
    HI_U32 u32Py[SM2_LEN_IN_WROD];
}HI_UNF_CIPHER_SM2_KEY_S;

/** Elliptic curve domain parameters. */
/** CNcomment: ECC\CD\D6Բ\C7\FA\CF߲\CE\CA\FD */
typedef struct
{
  HI_U8 *pu8p; /** Finite field: equal to p in case of prime field curves or equal to 2^n in case of binary field curves.*/
  HI_U8 *pu8a; /** Curve parameter a (q-3 in Suite B).*/
  HI_U8 *pu8b; /** Curve parameter b*/
  HI_U8 *pu8GX;/** X coordinates of G which is a base point on the curve.*/
  HI_U8 *pu8GY;/** Y coordinates of G which is a base point on the curve.*/
  HI_U8 *pu8n; /** Prime which is the order of G point.*/
  HI_U32 u32h; /**<  Cofactor, which is the order of the elliptic curve divided by the order of the point G. For the Suite B curves, h = 1.*/
  HI_U32 u32keySize; /**<  Key size in bytes. It corresponds to the size in bytes of the prime pu8n*/
} HI_UNF_CIPHER_ECC_PARAM_S;

/** CENC subsample struct input */
/** CNcomment: CENC subsample \B2\CE\CA\FD\BDṹ\CC\E5 */
typedef struct hiHI_UNF_CIPHER_SUBSAMPLE_S
{
    HI_U32 u32ClearHeaderLen;
    HI_U32 u32PayLoadLen;
    HI_U32 u32PayloadPatternEncryptLen;
    HI_U32 u32PayloadPatternClearLen;
    HI_U32 u32PayloadPatternOffsetLen;
}HI_UNF_CIPHER_SUBSAMPLE_S;

typedef struct hiHI_UNF_CIPHER_SUBSAMPLE_EX_S
{
    HI_U32 u32ClearHeaderLen;
    HI_U32 u32PayLoadLen;
    HI_U32 u32PayloadPatternEncryptLen;
    HI_U32 u32PayloadPatternClearLen;
    HI_U32 u32PayloadPatternOffsetLen;
    HI_U32 u32IvChange;
    HI_U32 u32IV[4];
}HI_UNF_CIPHER_SUBSAMPLE_EX_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */


#define HI_UNF_CIPHER_Open(HI_VOID)    HI_UNF_CIPHER_Init(HI_VOID);
#define HI_UNF_CIPHER_Close(HI_VOID)   HI_UNF_CIPHER_DeInit(HI_VOID);
#define HI_UNF_CIPHER_HASH_TYPE_CBCMAC HI_UNF_CIPHER_HASH_TYPE_IRDETO_CBCMAC
#define HI_UNF_CIPHER_CA_TYPE_HCA      HI_UNF_CIPHER_CA_TYPE_IRDETO_HCA

/******************************* API Declaration *****************************/
/** \addtogroup      CIPHER */
/** @{ */  /** <!-- [CIPHER] */
/* ---CIPHER---*/
/**
\brief  Init the cipher device.  CNcomment:\B3\F5ʼ\BB\AFCIPHER\C9豸\A1\A3 CNend
\attention \n
This API is used to start the cipher device.
CNcomment:\B5\F7\D3ô˽ӿڳ\F5ʼ\BB\AFCIPHER\C9豸\A1\A3 CNend
\param N/A                                                                      CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS  Call this API successful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_FAILED_INIT  The cipher device fails to be initialized. CNcomment:CIPHER\C9豸\B3\F5ʼ\BB\AFʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Init(HI_VOID);


/**
\brief  Deinit the cipher device.
CNcomment:\brief  ȥ\B3\F5ʼ\BB\AFCIPHER\C9豸\A1\A3 CNend
\attention \n
This API is used to stop the cipher device. If this API is called repeatedly, HI_SUCCESS is returned, but only the first operation takes effect.
CNcomment:\B5\F7\D3ô˽ӿڹر\D5CIPHER\C9豸\A1\A3\D6ظ\B4\B9رշ\B5\BBسɹ\A6\A3\AC\B5\DAһ\B4\CE\C6\F0\D7\F7\D3á\A3 CNend

\param N/A                                                                      CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS  Call this API successful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DeInit(HI_VOID);


/**
\brief Obtain a cipher handle for encryption and decryption.
CNcomment\A3\BA\B4\B4\BD\A8һ·Cipher\BE\E4\B1\FA\A1\A3 CNend

\param[in] cipher attributes                                                    CNcomment:cipher \CA\F4\D0ԡ\A3 CNend
\param[out] phCipher Cipher handle                                              CNcomment:CIPHER\BE\E4\B1\FA\A1\A3 CNend
\retval ::HI_SUCCESS Call this API successful.                                  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.                     CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_CIPHER_FAILED_GETHANDLE  The cipher handle fails to be obtained, because there are no available cipher handles. CNcomment: \BB\F1ȡCIPHER\BE\E4\B1\FAʧ\B0ܣ\ACû\D3п\D5\CFе\C4CIPHER\BE\E4\B1\FA CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CreateHandle(HI_HANDLE* phCipher, const HI_UNF_CIPHER_ATTS_S *pstCipherAttr);


/**
\brief Destroy the existing cipher handle. CNcomment:\CF\FA\BB\D9\D2Ѵ\E6\D4ڵ\C4CIPHER\BE\E4\B1\FA\A1\A3 CNend
\attention \n
This API is used to destroy existing cipher handles.
CNcomment:\B5\F7\D3ô˽ӿ\DA\CF\FA\BB\D9\D2Ѿ\AD\B4\B4\BD\A8\B5\C4CIPHER\BE\E4\B1\FA\A1\A3 CNend

\param[in] hCipher Cipher handle                                                CNcomment:CIPHER\BE\E4\B1\FA\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DestroyHandle(HI_HANDLE hCipher);


/**
\brief Configures the cipher control information.
CNcomment:\brief \C5\E4\D6\C3CIPHER\BF\D8\D6\C6\D0\C5Ϣ\A1\A3 CNend
\attention \n
Before encryption or decryption, you must call this API or HI_UNF_CIPHER_ConfigHandleEx to configure the cipher control information.
The first 64-bit data and the last 64-bit data should not be the same when using TDES algorithm.
Support AES/DES/3DES/SM4 algorithm, support ECB/CBC/CTR/OFB/CFB mode.
CNcomment:\BD\F8\D0м\D3\C3ܽ\E2\C3\DCǰ\B1\D8\D0\EB\CF\C8ʹ\D3ô˽ӿڻ\F2HI_UNF_CIPHER_ConfigHandleEx\C5\E4\D6\C3CIPHER\B5Ŀ\D8\D6\C6\D0\C5Ϣ\A1\A3
ʹ\D3\C3TDES\CB㷨ʱ\A3\AC\CA\E4\C8\EB\C3\DCԿ\B5\C4ǰ\BA\F364 bit\CA\FD\BEݲ\BB\C4\DC\CF\E0ͬ\A1\A3
+\B3\D6 AES/DES/3DES/SM4 \CB㷨, ECB/CBC/CTR/OFB/CFB ģʽ.CNend

\param[in] hCipher Cipher handle.                                               CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] pstCtrl Cipher control information.                                  CNcomment:CIPHER\BF\D8\D6\C6\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Call this API successful.                                  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.                     CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_ConfigHandle(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_S* pstCtrl);


/**
\brief Configures the cipher control information.
CNcomment:\brief \C5\E4\D6\C3CIPHER\BF\D8\D6\C6\D0\C5Ϣ\A1\A3 CNend
\attention \n
Before encryption or decryption, you must call this API or HI_UNF_CIPHER_ConfigHandle to configure the cipher control information.
The first 64-bit data and the last 64-bit data should not be the same when using TDES algorithm.
Support AES/DES/3DES/SM1/SM4 algorithm, support ECB/CBC/CTR/OFB/CFB/CCM/GCM mode.
CNcomment:\BD\F8\D0м\D3\C3ܽ\E2\C3\DCǰ\B1\D8\D0\EB\CF\C8ʹ\D3ô˽ӿڻ\F2HI_UNF_CIPHER_ConfigHandle\C5\E4\D6\C3CIPHER\B5Ŀ\D8\D6\C6\D0\C5Ϣ\A1\A3
ʹ\D3\C3TDES\CB㷨ʱ\A3\AC\CA\E4\C8\EB\C3\DCԿ\B5\C4ǰ\BA\F364 bit\CA\FD\BEݲ\BB\C4\DC\CF\E0ͬ\A1\A3
+\B3\D6 AES/DES/3DES/SM1/SM4 \CB㷨, ECB/CBC/CTR/OFB/CFB/CCM/GCM ģʽ.CNend

\param[in] hCipher Cipher handle.                                               CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] pstExCtrl Cipher control information.                                CNcomment:CIPHER\C0\A9չ\BF\D8\D6\C6\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Call this API succussful.                                  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.                     CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_ConfigHandleEx(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_EX_S* pstExCtrl);


/**
\brief Performs encryption.
CNcomment:\brief \BD\F8\D0м\D3\C3ܡ\A3 CNend

\attention \n
This API is used to perform encryption by using the cipher module.
The length of the encrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.After this operation, the result will affect next operation.If you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle.
CNcomment:ʹ\D3\C3CIPHER\BD\F8\D0м\D3\C3ܲ\D9\D7\F7\A1\A3TDESģʽ\CF¼\D3\C3ܵ\C4\CA\FD\BEݳ\A4\B6\C8Ӧ\B5\B1\CA\C78\B5ı\B6\CA\FD\A3\ACAES\CF\C2Ӧ\B5\B1\CA\C716\B5ı\B6\CA\FD\A1\A3\B4\CB\CD⣬\BC\D3\C3\DC\CA\FD\BEݳ\A4\B6Ȳ\BB\C4ܳ\A4\D3\DA0xFFFFF\A1\A3\B1\BE\B4β\D9\D7\F7\CD\EA\B3ɺ󣬴˴β\D9\D7\F7\B5\C4\CF\F2\C1\BF\D4\CB\CB\E3\BD\E1\B9\FB\BB\E1\D7\F7\D3\C3\D3\DA\CF\C2һ\B4β\D9\D7\F7\A3\AC\C8\E7\B9\FBҪ\C7\E5\B3\FD\CF\F2\C1\BF\A3\AC\D0\E8Ҫ\D4\DA\CF´μ\D3\C3ܲ\D9\D7\F7֮ǰ\B5\F7\D3\C3HI_UNF_CIPHER_ConfigHandle\D6\D8\D0\C2\C5\E4\D6\C3IV(\D0\E8Ҫ\C9\E8\D6\C3pstCtrl->stChangeFlags.bit1IVΪ1)\A1\A3 CNend
\param[in] hCipher Cipher handle                                                CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] u32SrcPhyAddr Physical address of the source data                    CNcomment:Դ\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32DestPhyAddr Physical address of the target data                   CNcomment:Ŀ\B5\C4\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32ByteLength   Length of the encrypted data                         CNcomment:\BC\D3\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS  Call this API successful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Encrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);


/**
\brief Performs decryption.
CNcomment:\brief \BD\F8\D0н\E2\C3\DC CNend

\attention \n
This API is used to perform decryption by using the cipher module.
The length of the decrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.After this operation, the result will affect next operation.If you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle.
CNcomment:ʹ\D3\C3CIPHER\BD\F8\D0н\E2\C3ܲ\D9\D7\F7\A1\A3TDESģʽ\CF½\E2\C3ܵ\C4\CA\FD\BEݳ\A4\B6\C8Ӧ\B5\B1\CA\C78\B5ı\B6\CA\FD\A3\ACAES\CF\C2Ӧ\B5\B1\CA\C716\B5ı\B6\CA\FD\A1\A3\B4\CB\CD⣬\BD\E2\C3\DC\CA\FD\BEݳ\A4\B6Ȳ\BB\C4ܳ\A4\D3\DA0xFFFFF\A1\A3\B1\BE\B4β\D9\D7\F7\CD\EA\B3ɺ󣬴˴β\D9\D7\F7\B5\C4\CF\F2\C1\BF\D4\CB\CB\E3\BD\E1\B9\FB\BB\E1\D7\F7\D3\C3\D3\DA\CF\C2һ\B4β\D9\D7\F7\A3\AC\C8\E7\B9\FBҪ\C7\E5\B3\FD\CF\F2\C1\BF\A3\AC\D0\E8Ҫ\D4\DA\CF´ν\E2\C3ܲ\D9\D7\F7֮ǰ\B5\F7\D3\C3HI_UNF_CIPHER_ConfigHandle\D6\D8\D0\C2\C5\E4\D6\C3IV(\D0\E8Ҫ\C9\E8\D6\C3pstCtrl->stChangeFlags.bit1IVΪ1)\A1\A3 CNend
\param[in] hCipher Cipher handle.                                               CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] u32SrcPhyAddr Physical address of the source data.                   CNcomment:Դ\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32DestPhyAddr Physical address of the target data.                  CNcomment:Ŀ\B5\C4\CA\FD\BE\DD\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32ByteLength Length of the decrypted data                           CNcomment:\BD\E2\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS Call this API successful.                                  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Decrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);


/**
\brief Encrypt multiple packaged data.
CNcomment:\brief \BD\F8\D0ж\E0\B8\F6\B0\FC\CA\FD\BEݵļ\D3\C3ܡ\A3 CNend
\attention \n
You can not encrypt more than 128 data package one time. When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When encrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ\B4μ\D3\C3ܵ\C4\CA\FD\BEݰ\FC\B8\F6\CA\FD\D7\EE\B6಻\C4ܳ\AC\B9\FD128\B8\F6\A1\A3\B7\B5\BB\D8HI_ERR_CIPHER_BUSY\B5\C4ʱ\BA\F2\A3\AC\CB\CD\C8\EB\CA\FD\BEݰ\FCһ\B8\F6Ҳ\B2\BB\BBᱻ\B4\A6\C0\ED\A3\AC\D3û\A7\D0\E8Ҫ\BC\F5\C9\D9\CB\CD\C8\EB\B5\C4\CA\FD\BEݰ\FC\B5\C4\CA\FD\C1\BF\BB\F2\D5\DF\D4ٴγ\A2\CAԼ\D3\C3ܡ\A3ע\D2\E2: \B6\D4\D3ڶ\E0\B8\F6\B0\FC\B5Ĳ\D9\D7\F7\A3\ACÿ\B8\F6\B0\FC\B6\BCʹ\D3\C3HI_UNF_CIPHER_ConfigHandle\C5\E4\D6õ\C4\CF\F2\C1\BF\BD\F8\D0\D0\D4\CB\CB㣬ǰһ\B8\F6\B0\FC\B5\C4\CF\F2\C1\BF\D4\CB\CB\E3\BD\E1\B9\FB\B2\BB\BB\E1\D7\F7\D3\C3\D3\DA\CF\C2һ\B8\F6\B0\FC\B5\C4\D4\CB\CB㣬ÿ\B8\F6\B0\FC\B6\BC\CAǶ\C0\C1\A2\D4\CB\CB\E3\B5ġ\A3ǰһ\B4κ\AF\CA\FD\B5\F7\D3õĽ\E1\B9\FBҲ\B2\BB\BB\E1Ӱ\CF\EC\BA\F3һ\B4κ\AF\CA\FD\B5\F7\D3õ\C4\D4\CB\CB\E3\BD\E1\B9\FB\A1\A3 CNend
\param[in] hCipher cipher handle                                                                  CNcomment:CIPHER\BE\E4\B1\FA\A1\A3 CNend
\param[in] pstDataPkg data package ready for cipher                                               CNcomment:\B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݰ\FC\A1\A3 CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                      CNcomment:\B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݰ\FC\B8\F6\CA\FD\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                                                   CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                             CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                            CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time   CNcomment:Ӳ\BC\FE\D5\FDæ\A3\AC\CE޷\A8һ\B4\CE\D0Դ\A6\C0\EDȫ\B2\BF\B5\C4\CA\FD\BEݰ\FC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EncryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);


/**
\brief Decrypt multiple packaged data.
CNcomment:\brief \BD\F8\D0ж\E0\B8\F6\B0\FC\CA\FD\BEݵĽ\E2\C3ܡ\A3 CNend
\attention \n
You can not decrypt more than 128 data package one time.When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When decrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ\B4ν\E2\C3ܵ\C4\CA\FD\BEݰ\FC\B8\F6\CA\FD\D7\EE\B6಻\C4ܳ\AC\B9\FD128\B8\F6\A1\A3\B7\B5\BB\D8HI_ERR_CIPHER_BUSY\B5\C4ʱ\BA\F2\A3\AC\CB\CD\C8\EB\CA\FD\BEݰ\FCһ\B8\F6Ҳ\B2\BB\BBᱻ\B4\A6\C0\ED\A3\AC\D3û\A7\D0\E8Ҫ\BC\F5\C9\D9\CB\CD\C8\EB\B5\C4\CA\FD\BEݰ\FC\B5\C4\CA\FD\C1\BF\BB\F2\D5\DF\D4ٴγ\A2\CAԽ\E2\C3ܡ\A3ע\D2\E2: \B6\D4\D3ڶ\E0\B8\F6\B0\FC\B5Ĳ\D9\D7\F7\A3\ACÿ\B8\F6\B0\FC\B6\BCʹ\D3\C3HI_UNF_CIPHER_ConfigHandle\C5\E4\D6õ\C4\CF\F2\C1\BF\BD\F8\D0\D0\D4\CB\CB㣬ǰһ\B8\F6\B0\FC\B5\C4\CF\F2\C1\BF\D4\CB\CB\E3\BD\E1\B9\FB\B2\BB\BB\E1\D7\F7\D3\C3\D3\DA\CF\C2һ\B8\F6\B0\FC\B5\C4\D4\CB\CB㣬ÿ\B8\F6\B0\FC\B6\BC\CAǶ\C0\C1\A2\D4\CB\CB\E3\B5ģ\ACǰһ\B4κ\AF\CA\FD\B5\F7\D3õĽ\E1\B9\FBҲ\B2\BB\BB\E1Ӱ\CF\EC\BA\F3һ\B4κ\AF\CA\FD\B5\F7\D3õ\C4\D4\CB\CB\E3\BD\E1\B9\FB\A1\A3 CNend
\param[in] hCipher cipher handle                                                                 CNcomment:CIPHER\BE\E4\B1\FA\A1\A3 CNend
\param[in] pstDataPkg data package ready for cipher                                              CNcomment:\B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݰ\FC\A1\A3 CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                     CNcomment:\B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݰ\FC\B8\F6\CA\FD\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                  CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                        CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                            CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                           CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time  CNcomment:Ӳ\BC\FE\D5\FDæ\A3\AC\CE޷\A8һ\B4\CE\D0Դ\A6\C0\EDȫ\B2\BF\B5\C4\CA\FD\BEݰ\FC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DecryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);


/**
\brief Get the tag data of CCM/GCM.
CNcomment:\brief \BB\F1ȡCCM/GCM\B5\C4TAG\CA\FD\BEݡ\A3 CNend

\attention \n
This API is used to get the tag data of CCM/GCM.
\param[in] hCipher cipher handle                                                CNcomment:CIPHER\BE\E4\B1\FA\A1\A3 CNend
\param[out] pu8Tag tag data of CCM/GCM                                          CNcomment:TAGָ\D5\EB CNend
\param[in/out] pu32TagLen tag data length of CCM/GCM, the input should be 16 now. CNcomment:TAG\CA\FD\BEݳ\A4\B6ȣ\AC\CA\E4\C8\EB\D0\E8\C9\E8\D6\C3Ϊ16 CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetTag(HI_HANDLE hCipher, HI_U8 *pu8Tag, HI_U32 *pu32TagLen);


/**
\brief Get the random number.
CNcomment:\brief \BB\F1ȡ\CB\E6\BB\FA\CA\FD\A1\A3 CNend

\attention \n
This API is used to obtain the random number from the hardware.
CNcomment:\B5\F7\D3ô˽ӿ\DA\D3\C3\D3ڻ\F1ȡ\CB\E6\BB\FA\CA\FD\A1\A3 CNend

\param[out] pu32RandomNumber Point to the random number.                                        CNcomment:\CB\E6\BB\FA\CA\FD\CA\FDֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetRandomNumber(HI_U32 *pu32RandomNumber);

/**
\brief Get the random bytes.
CNcomment:\brief \BB\F1ȡ\CB\E6\BB\FA\CA\FD\A1\A3 CNend

\attention \n
This API is used to obtain the random number from the hardware.
CNcomment:\B5\F7\D3ô˽ӿ\DA\D3\C3\D3ڻ\F1ȡ\CB\E6\BB\FA\CA\FD\A1\A3 CNend

\param[out] pu32RandomNumber Point to the random number.                                        CNcomment:\CB\E6\BB\FA\CA\FD\CA\FDֵ\A1\A3 CNend
\param[in]  u32Bytes size of the random bytes.                                                  CNcomment:\CB\E6\BB\FA\CA\FD\B4\F3С\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetMultiRandomBytes(HI_U8 *pu8RandomByte, HI_U32 u32Bytes);

/**
\brief Get the AES CBC-MAC value.
CNcomment:\brief \BB\F1ȡ\CA\FD\BEݵ\C4AES CBC-MACֵ\A1\A3 CNend

\attention \n
This API is used to obtain the AES CBC-MAC value.
CNcomment:\B5\F7\D3ô˽ӿ\DA\D3\C3\D3ڻ\F1ȡAES CBC-MACֵ\A1\A3 CNend
\param[in] hCipherHandle:  The cipher handle.                                                   CNcomment:Cipher\BE\E4\B1\FA\A1\A3 CNend
\param[in] pInputData: input data.                                                              CNcomment:\CA\E4\C8\EB\CA\FD\BEݡ\A3 CNend
\param[in] u32InputDataLen: input data length,the length should be multiple of 16 bytes if it is not the last block. CNcomment:\CA\E4\C8\EB\CA\FD\BEݵĳ\A4\B6ȣ\AC\C8\E7\B9\FB\B2\BB\CA\C7\D7\EE\BA\F3һ\B8\F6block\A3\AC\D4\F2\B1\D8\D0\EBΪ16\B8\F6byte\B5ı\B6\CA\FD\A1\A3 CNend
\param[in] bIsLastBlock: Whether this block is last block or not.                               CNcomment:\CAǷ\F1\D7\EE\BA\F3һ\B8\F6block\A1\A3 CNend
\param[out] pOutputMAC: output CBC-MAC value,the length of pOutputMAC should be 16.             CNcomment:\CA\E4\B3\F6\B5\C4CBC-MAC\A1\A3   \CA\E4\B3\F6\B3\A4\B6\C8Ϊ16\A1\A3CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CalcMAC(HI_HANDLE hCipherHandle, HI_U8 *pInputData, HI_U32 u32InputDataLen,
                                        HI_U8 *pOutputMAC, HI_BOOL bIsLastBlock);


/**
\brief Init the hash module, if other program is using the hash module, the API will return failure.
CNcomment:\brief \B3\F5ʼ\BB\AFHASHģ\BF飬\C8\E7\B9\FB\D3\D0\C6\E4\CB\FB\B3\CC\D0\F2\D5\FD\D4\DAʹ\D3\C3HASHģ\BF飬\B7\B5\BB\D8ʧ\B0\DC״̬\A1\A3 CNend

\attention \n
N/A

\param[in] pstHashAttr: The hash calculating structure input.                                      CNcomment:\D3\C3\D3ڼ\C6\CB\E3hash\B5Ľṹ\CC\E5\B2\CE\CA\FD CNend
\param[out] pHashHandle: The output hash handle.                                                CNcomment:\CA\E4\B3\F6\B5\C4hash\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS  Call this API successful.                                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashInit(HI_UNF_CIPHER_HASH_ATTS_S *pstHashAttr, HI_HANDLE *pHashHandle);


/**
\brief Calculate the hash, if the size of the data to be calculated is very big and the DDR ram is not enough, this API can calculate the data one block by one block. Attention: The input block length must be 64bytes alingned except for the last block.
CNcomment:\brief \BC\C6\CB\E3hashֵ\A3\AC\C8\E7\B9\FB\D0\E8Ҫ\BC\C6\CB\E3\B5\C4\CA\FD\BE\DD\C1\BF\B1Ƚϴ󣬸ýӿڿ\C9\D2\D4ʵ\CF\D6һ\B8\F6blockһ\B8\F6block\B5ļ\C6\CB㣬\B1\DC\C3\E2\CA\FD\BE\DD\C1\BF\B1Ƚϴ\F3\B5\C4\C7\E9\BF\F6\CF£\AC\C4ڴ治\D7\E3\B5\C4\CE\CA\CC⡣ \CCر\F0ע\D2⣬\B3\FD\C1\CB\D7\EE\BA\F3һ\B8\F6block\A3\ACǰ\C3\E6\B5\C4ÿһ\C2\D6\CA\E4\C8\EB\B5ĳ\A4\B6ȶ\BC\B1\D8\D0\EB\CA\C764\D7ֽڶ\D4\C6롣CNend

\attention \n
N/A

\param[in] hHashHandl:  Hash handle.                                        CNcomment:Hash\BE\E4\B1\FA\A1\A3 CNend
\param[in] pu8InputData:  The input data buffer.                            CNcomment:\CA\E4\C8\EB\CA\FD\BEݻ\BA\B3\E5 CNend
\param[in] u32InputDataLen:  The input data length, attention: the block length input must be 64bytes aligned except the last block!            CNcomment:\CA\E4\C8\EB\CA\FD\BEݵĳ\A4\B6ȡ\A3\D6\D8Ҫ\A3\BA \CA\E4\C8\EB\CA\FD\BEݿ\E9\B5ĳ\A4\B6ȱ\D8\D0\EB\CA\C764\D7ֽڶ\D4\C6룬\D7\EE\BA\F3һ\B8\F6block\CE޴\CB\CF\DE\D6ơ\A3 CNend
\retval ::HI_SUCCESS  Call this API successful.                             CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashUpdate(HI_HANDLE hHashHandle, HI_U8 *pu8InputData, HI_U32 u32InputDataLen);


/**
\brief Get the final hash value, after calculate all of the data, call this API to get the final hash value and close the handle.If there is some reason need to interupt the calculation, this API should also be call to close the handle.
CNcomment:\BB\F1ȡhashֵ\A3\AC\D4ڼ\C6\CB\E3\CD\EA\CB\F9\D3е\C4\CA\FD\BEݺ󣬵\F7\D3\C3\D5\E2\B8\F6\BDӿڻ\F1ȡ\D7\EE\D6յ\C4hashֵ\A3\AC\B8ýӿ\DAͬʱ\BB\E1\B9ر\D5hash\BE\E4\B1\FA\A1\A3\C8\E7\B9\FB\D4ڼ\C6\CB\E3\B9\FD\B3\CC\D6У\AC\D0\E8Ҫ\D6жϼ\C6\CB㣬Ҳ\B1\D8\D0\EB\B5\F7\D3øýӿڹر\D5hash\BE\E4\B1\FA\A1\A3 CNend

\attention \n
N/A

\param[in] hHashHandle:  Hash handle.                                       CNcomment:Hash\BE\E4\B1\FA\A1\A3  CNend
\param[out] pu8OutputHash:  The final output hash value\A3\ACand its length depends on hash type, it is 20 for sha1,28 for sha224,32 for sha256 or sm3,48 for sha384,64 for sha512.
CNcomment:\CA\E4\B3\F6\B5\C4hashֵ\A3\AC\B3\A4\B6\C8\D3\C9hash\C0\E0\D0;\F6\B6\A8\A3\ACsha1ʱ\CA\E4\B3\F6\B3\A4\B6\C820\A3\ACsha224\CA\E4\B3\F6\B3\A4\B6\C828\A3\ACsha256\BA\CD\C9\CFsm3\CA\E4\B3\F6\B3\A4\B6\C832\A3\ACsha384\CA\E4\B3\F6\B3\A4\B6\C848\A3\ACsha512\CA\E4\B3\F6\B3\A4\B6\C864\A1\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                             CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                                  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashFinal(HI_HANDLE hHashHandle, HI_U8 *pu8OutputHash);


/**
\brief RSA encryption a plaintext with a RSA public key.
CNcomment:ʹ\D3\C3RSA\B9\ABԿ\BC\D3\C3\DCһ\B6\CE\C3\F7\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstRsaEnc:   encryption struct.                                   CNcomment:\BC\D3\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA   input data to be encryption                          CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[out] u32InLen:   length of input data to be encryption                CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8Output\A3\BA output data to be encryption                         CNcomment: \BC\D3\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32OutLen: length of output data to be encryption               CNcomment: \BC\D3\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPublicEncrypt(HI_UNF_CIPHER_RSA_PUB_ENC_S *pstRsaEnc,
                                  HI_U8 *pu8Input, HI_U32 u32InLen,
                                  HI_U8 *pu8Output, HI_U32 *pu32OutLen);


/**
\brief RSA decryption a ciphertext with a RSA private key.
CNcomment:ʹ\D3\C3RSA˽Կ\BD\E2\C3\DCһ\B6\CE\C3\DC\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstRsaDec:   decryption struct.                                   CNcomment: \B9\ABԿ\BD\E2\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA   input data to be decryption                          CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[out] u32InLen:   length of input data to be decryption                CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8Output\A3\BA output data to be decryption                         CNcomment: \BD\E2\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32OutLen: length of output data to be decryption               CNcomment: \BD\E2\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPrivateDecrypt(HI_UNF_CIPHER_RSA_PRI_ENC_S *pstRsaDec,
                                   HI_U8 *pu8Input, HI_U32 u32InLen,
                                   HI_U8 *pu8Output, HI_U32 *pu32OutLen);


/**
\brief RSA encryption a plaintext with a RSA private key.
CNcomment:ʹ\D3\C3RSA˽Կ\BC\D3\C3\DCһ\B6\CE\C3\F7\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstRsaSign:   encryption struct.                                  CNcomment:\BC\D3\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA   input data to be encryption                          CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[out] u32InLen:   length of input data to be encryption                CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8Output\A3\BA output data to be encryption                         CNcomment: \BC\D3\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32OutLen: length of output data to be encryption               CNcomment: \BC\D3\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPrivateEncrypt(HI_UNF_CIPHER_RSA_PRI_ENC_S *pstRsaEnc,
                                   HI_U8 *pu8Input, HI_U32 u32InLen,
                                   HI_U8 *pu8Output, HI_U32 *pu32OutLen);


/**
\brief RSA decryption a ciphertext with a RSA public key.
CNcomment:ʹ\D3\C3RSA\B9\ABԿ\BD\E2\C3\DCһ\B6\CE\C3\DC\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstRsaVerify:   decryption struct.                                CNcomment: \BD\E2\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA   input data to be decryption                          CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[out] u32InLen:   length of input data to be decryption                CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8Output\A3\BA output data to be decryption                         CNcomment: \BD\E2\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32OutLen: length of output data to be decryption               CNcomment: \BD\E2\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPublicDecrypt(HI_UNF_CIPHER_RSA_PUB_ENC_S *pstRsaDec,
                               HI_U8 *pu8Input, HI_U32 u32InLen,
                               HI_U8 *pu8Output, HI_U32 *pu32OutLen);


/**
\brief RSA signature a context with appendix, where a signer\A1\AFs RSA private key is used.
CNcomment:ʹ\D3\C3RSA˽Կǩ\C3\FBһ\B6\CE\CEı\BE\A1\A3 CNend

\attention \n
N/A

\param[in] pstRsaSign:      signature struct.                                    CNcomment: ǩ\C3\FB\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA       input context to be signature\A3\ACmaybe null            CNcomment: \B4\FDǩ\C3\FB\B5\C4\CA\FD\BE\DD, \C8\E7\B9\FBpu8HashData\B2\BBΪ\BFգ\AC\D4\F2\B8\C3ָ\BFտ\C9\D2\D4Ϊ\BFա\A3 CNend
\param[in] u32InLen:        length of input context to be signature              CNcomment: \B4\FDǩ\C3\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[in] pu8HashData\A3\BA    hash value of context,if NULL, let pu8HashData = Hash(context) automatically,its length depends on hash type, it is 20 for sha1,28 for sha224,32 for sha256 or sm3,48 for sha384,64 for sha512.  Ncomment: \B4\FDǩ\C3\FB\CEı\BE\B5\C4HASHժҪ\A3\AC
CNcomment:\CA\E4\B3\F6\B5\C4hashժҪ\A3\AC\B3\A4\B6\C8\D3\C9hash\C0\E0\D0;\F6\B6\A8\A3\ACsha1ʱ\CA\E4\B3\F6\B3\A4\B6\C820\A3\ACsha224\CA\E4\B3\F6\B3\A4\B6\C828\A3\ACsha256\BA\CD\C9\CFsm3\CA\E4\B3\F6\B3\A4\B6\C832\A3\ACsha384\CA\E4\B3\F6\B3\A4\B6\C848\A3\ACsha512\CA\E4\B3\F6\B3\A4\B6\C864\A1\A3\C8\E7\B9\FBΪ\BFգ\AC\D4\F2\D7Զ\AF\BC\C6\CB\E3\CEı\BE\B5\C4HASHժҪ\A1\A3 CNend
\param[out] pu8OutSign\A3\BA    output message of signature                          CNcomment: ǩ\C3\FB\D0\C5Ϣ\A1\A3 CNend
\param[out] pu32OutSignLen: length of message of signature                       CNcomment: ǩ\C3\FB\D0\C5Ϣ\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaSign(HI_UNF_CIPHER_RSA_SIGN_S *pstRsaSign,
                             HI_U8 *pu8InData, HI_U32 u32InDataLen,
                             HI_U8 *pu8HashData,
                             HI_U8 *pu8OutSign, HI_U32 *pu32OutSignLen);


/**
\brief RSA signature verification a context with appendix, where a signer\A1\AFs RSA public key is used.
CNcomment:ʹ\D3\C3RSA\B9\ABԿǩ\C3\FB\D1\E9֤һ\B6\CE\CEı\BE\A1\A3 CNend

\attention \n
N/A

\param[in] pstRsaVerify:    signature verification struct.                         CNcomment: ǩ\C3\FB\D1\E9֤\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Input\A3\BA       input context to be signature verification\A3\ACmaybe null CNcomment: \B4\FDǩ\C3\FB\D1\E9֤\B5\C4\CA\FD\BE\DD, \C8\E7\B9\FBpu8HashData\B2\BBΪ\BFգ\AC\D4\F2\B8\C3ָ\BFտ\C9\D2\D4Ϊ\BFա\A3 CNend
\param[in] u32InLen:        length of input context to be signature                CNcomment: \B4\FDǩ\C3\FB\D1\E9֤\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[in] pu8HashData\A3\BA    hash value of context,if NULL, let pu8HashData = Hash(context) automatically,its length depends on hash type, it is 20 for sha1,28 for sha224,32 for sha256 or sm3,48 for sha384,64 for sha512.  Ncomment: \B4\FDǩ\C3\FB\CEı\BE\B5\C4HASHժҪ\A3\AC
CNcomment:\CA\E4\B3\F6\B5\C4hashժҪ\A3\AC\B3\A4\B6\C8\D3\C9hash\C0\E0\D0;\F6\B6\A8\A3\ACsha1ʱ\CA\E4\B3\F6\B3\A4\B6\C820\A3\ACsha224\CA\E4\B3\F6\B3\A4\B6\C828\A3\ACsha256\BA\CD\C9\CFsm3\CA\E4\B3\F6\B3\A4\B6\C832\A3\ACsha384\CA\E4\B3\F6\B3\A4\B6\C848\A3\ACsha512\CA\E4\B3\F6\B3\A4\B6\C864\A1\A3   Ncomment: \B4\FDǩ\C3\FB\CEı\BE\B5\C4HASHժҪ\A3\AC\C8\E7\B9\FBΪ\BFգ\AC\D4\F2\D7Զ\AF\BC\C6\CB\E3\CEı\BE\B5\C4HASHժҪ\A1\A3 CNend
\param[in] pu8InSign\A3\BA      message of signature                                 CNcomment: ǩ\C3\FB\D0\C5Ϣ\A1\A3 CNend
\param[in] pu32InSignLen:   length of message of signature                       CNcomment: ǩ\C3\FB\D0\C5Ϣ\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API successful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaVerify(HI_UNF_CIPHER_RSA_VERIFY_S *pstRsaVerify,
                               HI_U8 *pu8InData, HI_U32 u32InDataLen,
                               HI_U8 *pu8HashData,
                               HI_U8 *pu8InSign, HI_U32 u32InSignLen);

/**
\brief Generate a RSA private key.
CNcomment:\C9\FA\B3\C9һ\B8\F6RSA˽Կ\A1\A3 CNend

\attention \n
N/A

\param[in] u32NumBits: bit numbers of the integer public modulus. CNcomment: RSA\C3\DCԿN\B5\C4λ\BF\ED\A1\A3 CNend
\param[in] u32Exponent: value of public exponent. CNcomment: RSA\C3\DCԿEֵ\A1\A3 CNend
\param[out] ptRsaPriKey: private key struct. CNcomment: RSA˽Կ\A1\A3 CNend

\retval ::HI_SUCCESS Call this API succussful. CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE Call this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaGenKey(HI_U32 u32NumBits, HI_U32 u32Exponent, HI_UNF_CIPHER_RSA_PRI_KEY_S *pstRsaPriKey);

/**
\brief Computes CRT parameters dP, dQ and qInv from the two primes p and q and the public exponent e.
CNcomment: \B8\F9\BE\DDp\BA\CDq\B2\CE\CA\FD\A3\AC\BC\C6\CB\E3CRT\B2\CE\CA\FDdP, dQ \BA\CD qInv \A1\A3 CNend

\attention \n
N/A

\param[in] u32NumBits:     bit numbers of the integer public modulus.  CNcomment: RSA\C3\DCԿN\B5\C4λ\BF\ED\A1\A3 CNend
\param[in] u32Exponent:    value of public exponent.                   CNcomment: RSA\C3\DCԿEֵ\A1\A3 CNend
\param[in] pu8P Buffer containing the prime number p used as input parameter for the computation of CRT parameters. The buffer is allocated by the caller and is u32NumBits/2 bytes long. CNcomment: CRT\B5\C4p\B2\CE\CA\FD\A3\AC\B3\A4\B6\C8Ϊu32NumBits/2. CNend
\param[in] pu8Q Buffer containing the prime number q used as input parameter for the computation of CRT parameters. The buffer is allocated by the caller and is u32NumBits/2 bytes long. CNcomment: CRT\B5\C4q\B2\CE\CA\FD\A3\AC\B3\A4\B6\C8Ϊu32NumBits/2. CNend
\param[out] pu8DP Buffer where to store the CRT exponent dP computed. The buffer is allocated by the caller and is u32NumBits/2 bytes long. CNcomment: CRT\B5\C4dP\B2\CE\CA\FD\A3\AC\B3\A4\B6\C8Ϊu32NumBits/2. CNend
\param[out] pu8DQ Buffer where to store the CRT exponent dQ computed. The buffer is allocated by the caller and is u32NumBits/2 bytes long. CNcomment: CRT\B5\C4dQ\B2\CE\CA\FD\A3\AC\B3\A4\B6\C8Ϊu32NumBits/2. CNend
\param[out] pu8QP Buffer where to store the CRT exponent qInv computed. The buffer is allocated by the caller and is u32NumBits/2 bytes long. CNcomment: CRT\B5\C4qInv\B2\CE\CA\FD\A3\AC\B3\A4\B6\C8Ϊu32NumBits/2. CNend

\param[out] ptRsaPriKey:   private key struct.                         CNcomment: RSA˽Կ\A1\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaComputeCrtParams(HI_U32 u32NumBits, HI_U32 u32Exponent, HI_U8 *pu8P,
                               HI_U8 *pu8Q, HI_U8 *pu8DP, HI_U8 *pu8DQ, HI_U8 *pu8QP);


/**
\brief SM2 signature a context with appendix, where a signer\A1\AFs SM2 private key is used.
CNcomment:ʹ\D3\C3SM2˽Կǩ\C3\FBһ\B6\CE\CEı\BE\A1\A3 CNend

\attention \n
N/A

\param[in] pstSm2Sign:      signature struct.                                    CNcomment: ǩ\C3\FB\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Msg:          input context to be signature\A3\ACmaybe null            CNcomment: \B4\FDǩ\C3\FB\B5\C4\CA\FD\BE\DD, \C8\E7\B9\FBpu8HashData\B2\BBΪ\BFգ\AC\D4\F2\B8\C3ָ\BFտ\C9\D2\D4Ϊ\BFա\A3 CNend
\param[in] u32MsgLen:       length of input context to be signature              CNcomment: \B4\FDǩ\C3\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8R\A3\BA           The R value of the signature result,its length is 32.CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Rֵ\A3\AC\B3\A4\B6\C832\A1\A3 CNend
\param[out] pu8S:           The S value of the signature result,its length is 32.CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Sֵ\A3\AC\B3\A4\B6\C832\A1\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Sm2Sign(HI_UNF_CIPHER_SM2_SIGN_S *pstSm2Sign, HI_U8 *pu8Msg, HI_U32 u32MsgLen, HI_U8 *pu8R, HI_U8 *pu8S);


/**
\brief SM2 signature verification a context with appendix, where a signer\A1\AFs SM2 public key is used.
CNcomment:ʹ\D3\C3SM2\B9\ABԿǩ\C3\FB\D1\E9֤һ\B6\CE\CEı\BE\A1\A3 CNend

\attention \n
N/A

\param[in] pstSm2Verify:    signature verification struct.                         CNcomment: ǩ\C3\FB\D1\E9֤\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Msg\A3\BA          input context to be signature verification\A3\ACmaybe null CNcomment: \B4\FDǩ\C3\FB\D1\E9֤\B5\C4\CA\FD\BE\DD, \C8\E7\B9\FBpu8HashData\B2\BBΪ\BFգ\AC\D4\F2\B8\C3ָ\BFտ\C9\D2\D4Ϊ\BFա\A3 CNend
\param[in] u32MsgLen:       length of input context to be signature                CNcomment: \B4\FDǩ\C3\FB\D1\E9֤\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[in] pu8R\A3\BA            The R value of the signature result,its length is 32.  CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Rֵ\A3\AC\B3\A4\B6\C832\A1\A3 CNend
\param[in] pu8S:            The S value of the signature result,its length is 32.  CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Sֵ\A3\AC\B3\A4\B6\C832\A1\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Sm2Verify(HI_UNF_CIPHER_SM2_VERIFY_S *pstSm2Verify, HI_U8 *pu8Msg, HI_U32 u32MsgLen, HI_U8 *pu8R, HI_U8 *pu8S);


/**
\brief SM2 encryption a plaintext with a RSA public key.
CNcomment:ʹ\D3\C3SM2\B9\ABԿ\BC\D3\C3\DCһ\B6\CE\C3\F7\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstSm2Enc:   encryption struct.                                   CNcomment: \BC\D3\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8Msg\A3\BA     input data to be encryption                          CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[in] u32MsgLen:   length of input data to be encryption                CNcomment: \B4\FD\BC\D3\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8C\A3\BA      output data to be encryption                         CNcomment: \BC\D3\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32Clen:   length of output data to be encryption               CNcomment: \BC\D3\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Sm2Encrypt(HI_UNF_CIPHER_SM2_ENC_S *pstSm2Enc,  HI_U8 *pu8Msg, HI_U32 u32MsgLen, HI_U8 *pu8C, HI_U32 *pu32Clen);


/**
\brief RSA decryption a ciphertext with a SM2 private key.
CNcomment:ʹ\D3\C3SM2˽Կ\BD\E2\C3\DCһ\B6\CE\C3\DC\CEġ\A3 CNend

\attention \n
N/A

\param[in] pstSm2Dec:   decryption struct.                                   CNcomment: \B9\ABԿ\BD\E2\C3\DC\CA\F4\D0Խṹ\CC塣 CNend
\param[in] pu8C\A3\BA       input data to be decryption                          CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݡ\A3 CNend
\param[out] u32Clen:    length of input data to be decryption                CNcomment: \B4\FD\BD\E2\C3ܵ\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend
\param[out] pu8Msg\A3\BA    output data to be decryption                         CNcomment: \BD\E2\C3ܽ\E1\B9\FB\CA\FD\BEݡ\A3 CNend
\param[out] pu32MsgLen: length of output data to be decryption               CNcomment: \BD\E2\C3ܽ\E1\B9\FB\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Sm2Decrypt(HI_UNF_CIPHER_SM2_DEC_S *pstSm2Dec, HI_U8 *pu8C, HI_U32 u32Clen, HI_U8 *pu8Msg, HI_U32 *pu32MsgLen);


/**
\brief Generate a SM2 key pair.
CNcomment:\C9\FA\B3\C9һ\B8\F6SM2\C3\DCԿ\B6ԡ\A3 CNend

\attention \n
N/A

\param[out] pstSm2Key:   key pair struct.                               CNcomment: SM2\C3\DCԿ\B6ԡ\A3 CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Sm2GenKey(HI_UNF_CIPHER_SM2_KEY_S *pstSm2Key);

/**
\brief CENC decryption a ciphertext.
CNcomment: CENC\B8\F1ʽ\BD\E2\C3\DCһ\B6\CE\C3\DC\CEġ\A3 CNend

\attention \n
This API is used to perform decryption ciphertext base on CENC format.
CNcomment:ʹ\D3\C3CIPHER\BD\F8\D0\D0CENC\B8\F1ʽ\BD\E2\C3ܲ\D9\D7\F7\A1\A3 CNend
\param[in] hCipher Cipher handle                                                   CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] u8Key key for cipher decryption,its length should be 16.                CNcomment:CIPHER \BD\E2\C3\DC\C3\DCԿ,\B3\A4\B6\C8Ϊ16. CNend
\param[in] u8IV  iv for cipher decryption,its length should be 16.                 CNcomment:CIPHER \BD\E2\C3\DCIV ,\B3\A4\B6\C8Ϊ16.CNend
\param[in] u32NonSecInputPhyAddr non-secure Physical address of the source data    CNcomment:Դ\CA\FD\BEݷǰ\B2ȫ\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32SecOutputPhyAddr secure Physical address of the target data          CNcomment:Ŀ\B5\C4\CA\FD\BEݰ\B2ȫ\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32ByteLength   Length of the decrypted data                            CNcomment:\BC\D3\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
\param[in] u32FirstEncrypt offset of the first encrypt block data                  CNcomment:\B5\DAһ\B8\F6\BC\D3\C3\DC\CA\FD\BEݵ\C4ƫ\D2Ƶ\D8ַ\A3\AC0~15 CNend
\retval ::HI_SUCCESS  Call this API succussful.                                    CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.            CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                    CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                     CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CENCDecrypt(HI_HANDLE hCipher, HI_U8 *pu8Key, HI_U8 *pu8IV,
                               HI_U32 u32NonSecInPhyAddr, HI_U32 u32SecOutPhyAddr, HI_U32 u32ByteLength,
                               HI_U32 u32FirstEncryptOffset,
                               HI_UNF_CIPHER_SUBSAMPLE_S *pstSubSample, HI_U32 u32SubsampleNum);

/**
\brief CENC decryption a ciphertext.
CNcomment: CENC\B8\F1ʽ\BD\E2\C3\DCһ\B6\CE\C3\DC\CEġ\A3 CNend

\attention \n
This API is used to perform decryption ciphertext base on CENC format.
CNcomment:ʹ\D3\C3CIPHER\BD\F8\D0\D0CENC\B8\F1ʽ\BD\E2\C3ܲ\D9\D7\F7\A1\A3 CNend
\param[in] hCipher Cipher handle                                                CNcomment:CIPHER\BE\E4\B1\FA CNend
\param[in] u8Key key for cipher decryption,its length should be 16.             CNcomment:CIPHER \BD\E2\C3\DC\C3\DCԿ CNend
\param[in] bOddKey use odd key or not                                           CNcomment:CIPHER \CAǷ\F1ʹ\D3\C3odd key CNend
\param[in] u32NonSecInputPhyAddr non-secure Physical address of the source data    CNcomment:Դ\CA\FD\BEݷǰ\B2ȫ\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32SecOutputPhyAddr secure Physical address of the target data          CNcomment:Ŀ\B5\C4\CA\FD\BEݰ\B2ȫ\CE\EF\C0\ED\B5\D8ַ CNend
\param[in] u32ByteLength   Length of the decrypted data                         CNcomment:\BC\D3\C3\DC\CA\FD\BEݳ\A4\B6\C8 CNend
\param[in] u32FirstEncrypt offset of the first encrypt block data               CNcomment:\B5\DAһ\B8\F6\BC\D3\C3\DC\CA\FD\BEݵ\C4ƫ\D2Ƶ\D8ַ\A3\AC0~15 CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ\B5\F7\D3óɹ\A6 CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:\B2\CE\CA\FD\B4\ED\CE\F3 CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:\BE\E4\B1\FA\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CENCDecryptEx(HI_HANDLE hCipher, HI_U8 *pu8Key, HI_BOOL bOddKey,
                               HI_U32 u32NonSecInPhyAddr, HI_U32 u32SecOutPhyAddr, HI_U32 u32ByteLength,
                               HI_U32 u32FirstEncryptOffset,
                               HI_UNF_CIPHER_SUBSAMPLE_EX_S *pstSubSample, HI_U32 u32SubsampleNum);

/**
\brief Compute Diffie-Hellman shared secret as otherPubKey^privKey mod p.
CNcomment: \BC\C6\CB\E3DH\B9\B2\CF\ED\C3\DCԿ\A1\A3 CNend

\attention \n
N/A

\param[in] pu8P:  Buffer containing the DH prime modulus p used for the operation.  CNcomment: DH\B2\CE\CA\FDp. CNend
\param[in] pu8PrivKey: Buffer containing the DH private key. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.                       CNcomment: DH˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] pu8OtherPubKey: Buffer containing the DH public key of the other peer. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.  CNcomment: \B6Է\BD\B5\C4DH\B9\ABԿ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[out] pu8SharedSecret:  Buffer where to write the computed shared secret. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: DH\B9\B2\CF\ED\C3\DCԿ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] u32KeySize: DH key size. CNcomment: DH\C3\DCԿ\B3\A4\B6\C8. CNend
\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DhComputeKey(HI_U8 * pu8P, HI_U8 *pu8PrivKey, HI_U8 *pu8OtherPubKey,
                                  HI_U8 *pu8SharedSecret, HI_U32 u32KeySize);


/**
\brief Generate Diffie-Hellman public/private key pair from g and p parameters. The public key is equal to g^x mod p, where x is random number considered as the private key.
CNcomment: \C9\FA\B3\C9DH\B9\AB˽\C3\DCԿ\B6ԡ\A3 CNend

\attention \n
N/A

\param[in] pu8G: Buffer containing the DH generator g used for the operation. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.  CNcomment: DH\B5\C4g\B2\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] pu8P: Buffer containing the DH generator p used for the operation. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.  CNcomment: DH\B5\C4p\B2\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] pu8InputPrivKey: Buffer containing an optional input private key from which the public has to be generated.  The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.  If no private key is provided as input (\c pu8InputPrivKey=NULL), function generates a random private key and stores it in pu8OutputPrivKey this buffer. CNcomment: DH\B5\C4˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0, \C8\E7\B9\FBΪ\BF\D5ָ\D5룬\B8ú\AF\CA\FD\BD\AB\C9\FA\B3\C9һ\B8\F6˽Կ\B7ŵ\BDpu8OutputPrivKey\D6С\A3 CNend
\param[out] pu8OutputPrivKey: Buffer where to write the generated private key, in case no private key is provided as input (pu8InputPrivKey==NULL). It must be padded with leading zeros if the effective size of the private key is smaller than the buffer size. CNcomment: DH\B5\C4˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0, \C8\E7\B9\FBpu8InputPrivKeyΪ\BF\D5ָ\D5룬\B8ú\AF\CA\FD\BD\AB\C9\FA\B3\C9һ\B8\F6˽Կ\B7ŵ\BD\D5\E2\B8\F6buffer\D6С\A3 CNend
\param[in] u32KeySize: DH key size.                       CNcomment: DH\C3\DCԿ\B3\A4\B6\C8. CNend
\retval ::HI_SUCCESS  Call this API succussful.           CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DhGenKey(HI_U8 *pu8G, HI_U8 *pu8P, HI_U8 *pu8InputPrivKey,
                                   HI_U8 *pu8OutputPrivKey, HI_U8 *pu8PubKey,
                                   HI_U32 u32KeySize);


/**
\brief Compute ECDH shared secret key. This key corresponds to the X coordinates of the computed P point.
CNcomment: \BC\C6\CB\E3ECC DH\B9\B2\CF\ED\C3\DCԿ\A1\A3 CNend

\attention \n
N/A

\param[in] pstParams:  Elliptic curve domain parameters. The caller is in charge padding each buffer with leading zeros if the effective size of the domain parameter conveyed is smaller than pstParams->keySize.  CNcomment: ECC\CD\D6Բ\C7\FA\CF߲\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0. CNend
\param[in] pu8PrivKey: Buffer containing the ECDH private key. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.                       CNcomment: ECDH˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] pu8OtherPubKeyX: Buffer containing the X coordinates of other peer's ECDH public key. It is padded by the caller with leading zeros if the effective size of the public key X coordinates is smaller than the buffer size.  CNcomment: \B6Է\BD\B5\C4ECDH\B9\ABԿ\B5\C4X\D7\F8\B1꣬\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] pu8OtherPubKeyY: Buffer containing the Y coordinates of other peer's ECDH public key. It is padded by the caller with leading zeros if the effective size of the public key Y coordinates is smaller than the buffer size.  CNcomment: \B6Է\BD\B5\C4ECDH\B9\ABԿ\B5\C4Y\D7\F8\B1꣬\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[out] pu8SharedSecret:  Buffer where to write the computed shared secret. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: ECDH\B9\B2\CF\ED\C3\DCԿ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EcdhComputeKey(HI_UNF_CIPHER_ECC_PARAM_S *pstParams, HI_U8 *pu8PrivKey,
                                    HI_U8 *pu8OtherPubKeyX, HI_U8 *pu8OtherPubKeyY,
                                    HI_U8 *pu8SharedSecret);


/**
\brief Generate ECC public/private key pair.
CNcomment: \C9\FA\B3\C9ECDH\B9\AB˽\C3\DCԿ\B6ԡ\A3 CNend

\attention \n
N/A

\param[in] pstParams:  Elliptic curve domain parameters. The caller is in charge padding each buffer with leading zeros if the effective size of the domain parameter conveyed is smaller than pstParams->keySize.  CNcomment: ECC\CD\D6Բ\C7\FA\CF߲\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0. CNend
\param[in] pu8InputPrivKey: Buffer containing an optional input private key from which the public has to be generated.  The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.  If no private key is provided as input (\c pu8InputPrivKey=NULL), function generates a random private key and stores it in pu8OutputPrivKey this buffer. CNcomment: ECC\B5\C4˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0, \C8\E7\B9\FBΪ\BF\D5ָ\D5룬\B8ú\AF\CA\FD\BD\AB\C9\FA\B3\C9һ\B8\F6˽Կ\B7ŵ\BDpu8OutputPrivKey\D6С\A3 CNend
\param[out] pu8OutputPrivKey: Buffer where to write the generated private key, in case no private key is provided as input (pu8InputPrivKey==NULL). It must be padded with leading zeros if the effective size of the private key is smaller than the buffer size. CNcomment: ECC\B5\C4˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0, \C8\E7\B9\FBpu8InputPrivKeyΪ\BF\D5ָ\D5룬\B8ú\AF\CA\FD\BD\AB\C9\FA\B3\C9һ\B8\F6˽Կ\B7ŵ\BD\D5\E2\B8\F6buffer\D6С\A3 CNend
\pu8PubKeyX[out] Buffer where to write the X coordinates of the generated public key. It must be padded with leading zeros if the effective size of the public key X coordinates is smaller than the buffer size. CNcomment: ECC\B9\ABԿX\D7\F8\B1\EA. CNend
\pu8PubKeyX[out] Buffer where to write the Y coordinates of the generated public key. It must be padded with leading zeros if the effective size of the public key X coordinates is smaller than the buffer size. CNcomment: ECC\B9\ABԿY\D7\F8\B1\EA. CNend
\retval ::HI_SUCCESS  Call this API succussful.           CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EccGenKey(HI_UNF_CIPHER_ECC_PARAM_S *pstParams, HI_U8 *pu8InputPrivKey,
                                    HI_U8 *pu8OutputPrivKey, HI_U8 *pu8PubKeyX, HI_U8 *pu8PubKeyY);


/**
\brief Sign a message with ECDSA algorithm and returns an uncompressed signature made of the pair (r, s).
CNcomment: ECDSAǩ\C3\FB\A1\A3 CNend

\attention \n
N/A

\param[in] pstParams:  Elliptic curve domain parameters. The caller is in charge padding each buffer with leading zeros if the effective size of the domain parameter conveyed is smaller than pstParams->keySize.  CNcomment: ECC\CD\D6Բ\C7\FA\CF߲\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0. CNend
\param[in] pu8PrivKey: Buffer containing the ECDH private key. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.                       CNcomment: ECDH˽Կ\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0\A1\A3 CNend
\param[in] enShaType: One of the hash algorithm.  						CNcomment: HASH \CB㷨\C0\E0\D0͡\A3 CNend
\param[in] pu8Message: Message to be signed.  							CNcomment: \B4\FDǩ\C3\FB\CF\FBϢ\A1\A3 CNend
\param[in] Size in bytes of message to be signed.  						CNcomment: \B4\FDǩ\C3\FB\CF\FBϢ\B5ĳ\A4\B6ȡ\A3 CNend
\param[out] pu8SigR:  Buffer where to write the uncompressed r component of the resulting signature. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Rֵ\A1\A3 CNend
\param[out] pu8SigS:  Buffer where to write the uncompressed s component of the resulting signature. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Sֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EcdsaSign(HI_UNF_CIPHER_ECC_PARAM_S *pstParams, HI_U8 *pu8PrivKey,
                               HI_UNF_CIPHER_HASH_TYPE_E enShaType,
                               HI_U8 *pu8Message, HI_U32 u32MessageSize,
                               HI_U8 *pu8SigR, HI_U8 *pu8SigS);


/**
\brief Verify an ECDSA signature made of an uncompressed pair (r, s).
CNcomment: ECDSAǩ\C3\FB\D1\E9֤\A1\A3 CNend

\attention \n
N/A

\param[in] pstParams:  Elliptic curve domain parameters. The caller is in charge padding each buffer with leading zeros if the effective size of the domain parameter conveyed is smaller than pstParams->keySize.  CNcomment: ECC\CD\D6Բ\C7\FA\CF߲\CE\CA\FD\A3\AC\B3\A4\B6Ȳ\BB\D7\E3Key\B5Ĵ\F3С\A3\ACǰ\C3油0. CNend
\pu8PubKeyX[out] Buffer where to write the X coordinates of the generated public key. It must be padded with leading zeros if the effective size of the public key X coordinates is smaller than the buffer size. CNcomment: ECC\B9\ABԿX\D7\F8\B1\EA. CNend
\pu8PubKeyX[out] Buffer where to write the Y coordinates of the generated public key. It must be padded with leading zeros if the effective size of the public key X coordinates is smaller than the buffer size. CNcomment: ECC\B9\ABԿY\D7\F8\B1\EA. CNend
\param[in] enShaType: One of the hash algorithm.  						CNcomment: HASH \CB㷨\C0\E0\D0͡\A3 CNend
\param[in] pu8Message: Message to be signed.  							CNcomment: \B4\FDǩ\C3\FB\CF\FBϢ\A1\A3 CNend
\param[in] Size in bytes of message to be signed.  						CNcomment: \B4\FDǩ\C3\FB\CF\FBϢ\B5ĳ\A4\B6ȡ\A3 CNend
\param[in] pu8SigR:  Buffer where to write the uncompressed r component of the resulting signature. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Rֵ\A1\A3 CNend
\param[in] pu8SigS:  Buffer where to write the uncompressed s component of the resulting signature. The caller ensures it is padded with leading zeros if the effective size of this key is smaller than the u32KeySize.    CNcomment: ǩ\C3\FB\BD\E1\B9\FB\B5\C4Sֵ\A1\A3 CNend
\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ\B5\F7\D3óɹ\A6\A1\A3 CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0ܡ\A3 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EcdsaVerify(HI_UNF_CIPHER_ECC_PARAM_S *pstParams,
                                 HI_U8 *pu8PubKeyX, HI_U8 *pu8PubKeyY,
                                 HI_UNF_CIPHER_HASH_TYPE_E enShaType,
                                 HI_U8 *pu8Message, HI_U32 u32MessageSize,
                                 HI_U8 *pu8SigR, HI_U8 *pu8SigS);


/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_CIPHER_H__ */
