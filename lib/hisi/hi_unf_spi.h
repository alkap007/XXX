/******************************************************************************
Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_unf_spi.h  
Version       : Initial Draft  
Author        : Hisilicon STB SDK group 
Created       : 2013/4/22  
Last Modified : 
Description   : output control  Function 
Modification  : Created file
******************************************************************************/
#ifndef  __HI_UNF_SPI_H__
#define  __HI_UNF_SPI_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */


/*************************** Structure Definition ****************************/

/** \addtogroup      SPI */
/** @{*/  /** <!-[SPI]*/

/** SPI device select */
/** CNcomment: SPI \C9豸 */
typedef enum hiUNF_SPI_DEV_E
{
    HI_UNF_SPI_DEV_0 =0 ,
    HI_UNF_SPI_DEV_1 = 1,
    HI_UNF_SPI_DEV_BUTT
}HI_UNF_SPI_DEV_E;

/** SPI CS Config */
/** CNcomment: SPI CS\BD\C5\C5\E4\D6\C3*/
typedef enum hiUNF_SPI_CFGCS_E
{
    HI_UNF_SPI_LOGIC_CS =0 ,
    HI_UNF_SPI_GPIO_CS = 1,
}HI_UNF_SPI_CFGCS_E;


/** SPICLOCKOUT polarity */
/** CNcomment: SPICLOCKOUT \BC\AB\D0\D4ֵö\BE\D9 */
typedef enum hiUNF_SPI_SPO_E
{
    HI_UNF_SPI_SPO_0 = 0,
    HI_UNF_SPI_SPO_1 = 1 
}HI_UNF_SPI_SPO_E;

/** SPICLOCKOUT  phase */
/** CNcomment: SPICLOCKOUT \CF\E0λֵö\BE\D9 */
typedef enum hiUNF_SPI_SPH_E
{
    HI_UNF_SPI_SPH_0 = 0,
    HI_UNF_SPI_SPH_1 = 1 
}HI_UNF_SPI_SPH_E;

/** SPI Frame format */
/** CNcomment: ֡\B8\F1ʽ */
typedef enum hiUNF_SPI_FRF_E
{
    HI_UNF_SPI_FRF_MOTO = 0,	/**< Motorola SPI */ /** CNcomment: Motorola SPI*/
    HI_UNF_SPI_FRF_TI   = 1, 		/**< TI SPI */ /** CNcomment: TI SPI */
    HI_UNF_SPI_FRF_NM   = 2,		/**< National Microwire */ /** CNcomment: National Microwire */
    HI_UNF_SPI_FRF_BUTT = 3	
}HI_UNF_SPI_FRF_E;

/** SPI Data byte order */
/** CNcomment: \CA\FD\BEݴ\F3С\B6˶\A8\D2\E5 */
typedef enum hiUNF_SPI_BIGEND_E
{
	HI_UNF_SPI_BIGEND_LITTLE,	/**< little endian */ /** CNcomment: С\B6\CB*/
	HI_UNF_SPI_BIGEND_BIG			/**< big endian */ /** CNcomment: \B4\F3\B6\CB*/
}HI_UNF_SPI_BIGEND_E;

/** SPI addition attribute about Motorola SPI */
/** CNcomment: Motorola SPI Э\D2\E9ר\D3\D0\CA\F4\D0\D4 */

typedef struct hiUNF_SPI_ATTR_MOTO_S
{
	HI_UNF_SPI_SPO_E enSpo;	/**< only effactive when enCs is HI_UNF_SPI_FRF_MOTO */ /** CNcomment: \BD\F6\D4\DAmotorolaЭ\D2\E9\D3\D0Ч*/
	HI_UNF_SPI_SPH_E enSph; /**< only effactive when enCs is HI_UNF_SPI_FRF_MOTO */ /** CNcomment: \BD\F6\D4\DAmotorolaЭ\D2\E9\D3\D0Ч*/
}HI_UNF_SPI_ATTR_MOTO_S;

/** SPI additional attribute about National Microwire SPI */
/** CNcomment: National Microwire SPI Э\D2\E9ר\D3\D0\CA\F4\D0\D4 */
typedef struct hiUNF_SPI_ATTR_NM_S
{
	HI_BOOL	bWaitEn;		/**< wait enable. */  /** CNcomment: \B5ȴ\FDʹ\C4\DC*/
	HI_U32 u32Waitval;	/**< wait time value. */	/** CNcomment: \B5ȴ\FDʱ\BC\E4*/
}HI_UNF_SPI_ATTR_NM_S;

/** SPI additional attribute union */
/** CNcomment: Motorola SPI/NM Э\D2\E9ר\D3\D0\CA\F4\D0\D4 */
typedef union
{
	HI_UNF_SPI_ATTR_MOTO_S stMoto;
	HI_UNF_SPI_ATTR_NM_S stNm;
}HI_UNF_SPI_ATTR_EXT_U;

/** The SPI attribute*/
/** CNcomment: SPI\B9\A4\D7\F7ģʽ\CA\F4\D0\D4*/
typedef struct hiUNF_SPI_ATTR_S
{
	HI_UNF_SPI_DEV_E enDev;	/**< chip select */  /** CNcomment: ָ\B6\A8\C9豸*/
	HI_UNF_SPI_CFGCS_E csCfg; /**< cs select */  /** CNcomment: ѡ\D4\F1Ƭѡ\C5\E4\D6\C3*/
	HI_U32	u32Baud;  /**< baud rate */  /** CNcomment: \B2\A8\CC\D8\C2\CA*/
	HI_UNF_SPI_FRF_E enFrf;	/**< frame format */  /** CNcomment: ֡ģʽ*/
	HI_U32 u32Dss;  /**< number of bits per transfer, 4-15bit, value of u32Dss : [4, 15]. */  /** CNcomment: \C9\E8\D6÷\B6Χ4-15*/
	HI_UNF_SPI_BIGEND_E enBigend;	/**< byte order */  /** CNcomment: \B4\F3С\B6\CB*/
	HI_UNF_SPI_ATTR_EXT_U unExtAttr; /**< addition attr when frf is moto or nm. */  /** CNcomment: ģʽΪMOTO\BB\F2\D5\DFNMʱʹ\D3\C3*/
	
}HI_UNF_SPI_ATTR_S;


/** @}*/  /** <!-- ==== Structure Definition End ====*/


/******************************* API Declaration *****************************/
/** \addtogroup      SPI*/
/** @{*/  /** <!-- -SPI=*/

/**
 \brief Init the SPI device.
CNcomment:\brief \B3\F5ʼ\BB\AFSPI\A3\A8the Inter-Integrated Circuit\A3\A9\C9豸\A1\A3CNend

 \param N/A                                                               CNcomment:\CEޡ\A3CNend
 \retval 0 Success                                                        CNcomment:\B3ɹ\A6\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SPI_Init(HI_VOID);

/**
 \brief  DeInit the SPI device.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFSPI\C9豸\A1\A3CNend

 \param N/A                                                        CNcomment:\CEޡ\A3CNend
 \retval 0 Success                                                 CNcomment: \B3ɹ\A6\A1\A3CNend
 \see \n
N/A
 */
HI_S32 HI_UNF_SPI_DeInit(HI_VOID);



/**
 \brief Open the SPI device.
CNcomment:\brief \B4\F2\BF\AAָ\B6\A8SPI\C9豸\A1\A3CNend

  \attention \n
 Hi3719MV100/ Hi3718MV100 has SPI0 only.\n
 CNcomment: Hi3719MV100/ Hi3718MV100 ֻ\D3\D0SPI0\n CNend

 \param[in] enDev  select device		  CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
  
 \retval 0 Success                                                        CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SPI_OPEN_ERR  Opne Spi Error.	 	   CNcomment:SPI\C9豸\B4\F2\BF\AAʧ\B0ܡ\A3CNend
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_Open(HI_UNF_SPI_DEV_E enDev);	


/**
 \brief Close the SPI device.
CNcomment:\brief \B9ر\D5ָ\B6\A8SPI\C9豸\A1\A3CNend

 \param[in] enDev  select device		  CNcomment:ָ\B6\A8\C9豸\A1\A3CNend

 \retval 0 Success                                                        CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_ERR_SPI_CLOSE_ERR  Close Spi Error.	 	   CNcomment:SPI\C9豸\B9ر\D5ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_Close(HI_UNF_SPI_DEV_E enDev);

/**
 \brief  Set the SPI working mode.
CNcomment:\\C9\E8\D6\C3SPI\B9\A4\D7\F7\B7\BDʽ\A1\A3CNend

 \param[in] enDev  select device		  CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
 \param[in] stAttr  The attribute of the SPI . CNcomment:SPI\B5\C4\CA\F4\D0ԡ\A3CNend

 \retval 0 Success                                                 CNcomment: \B3ɹ\A6\A1\A3CNend
 \retval ::	 
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_SetAttr(HI_UNF_SPI_DEV_E enDev, HI_UNF_SPI_ATTR_S *stAttr);

/**
 \brief  Get the SPI working mode.
CNcomment:\\BB\F1ȡSPI\B9\A4\D7\F7\B7\BDʽ\CF\E0\B9\D8\CA\F4\D0ԡ\A3CNend

 \param[in] enDev  select device          CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
 \param[out] stAttr  The attribute of the SPI . CNcomment:SPI\B5\C4\CA\F4\D0ԡ\A3CNend
 
 \retval 0 Success                                                 CNcomment: \B3ɹ\A6\A1\A3CNend
 \retval ::	 
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_GetAttr(HI_UNF_SPI_DEV_E enDev, HI_UNF_SPI_ATTR_S *stAttr);

/**
 \brief Trans data by using the SPI.
CNcomment:\brief SPI\CA\FD\BEݴ\AB\CA䡣CNend

 \attention \n
N/A
 \param[in] enDev  select device          CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
 \param[in] pu8Send  Buffer for storing the data to be written       CNcomment:\B4\E6\B7Ŵ\FDд\C8\EB\CA\FD\BEݡ\A3CNend
 \param[in] u32SendCnt  Length of the data to be written        CNcomment:\B4\FDд\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
 \param[in] pu8Read  Buffer for storing the data to be read . CNcomment:\B4\E6\B7Ž\D3\CA\D5\CA\FD\BEݡ\A3CNend
 \param[in] u32ReadCnt  Length of the data to be read                                    CNcomment:Ҫ\B6\C1ȡ\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3CNend
 \retval 0 Success                                                                      CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Read data failed					  	CNcomment:ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_ReadExt(HI_UNF_SPI_DEV_E enDev, HI_U8 *pu8Send, HI_U32 u32SendCnt, HI_U8 *pu8Read, HI_U32 u32ReadCnt);

/**
 \brief Reads data by using the SPI.
CNcomment:\brief SPI\CA\FD\BEݽ\D3\CAա\A3CNend

 \attention \n
N/A
 \param[in] enDev  select device          CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
 \param[out] pu8Read  Buffer for storing the data to be read . CNcomment:\B4\E6\B7Ž\D3\CA\D5\CA\FD\BEݡ\A3CNend
 \param[in] u32ReadCnt  Length of the data to be read                                    CNcomment:Ҫ\B6\C1ȡ\B5\C4\CA\FD\BEݳ\A4\B6ȡ\A3CNend

 \retval 0 Success                                                                      CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Read data failed					  	CNcomment:ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_Read(HI_UNF_SPI_DEV_E enDev, HI_U8 *pu8Read, HI_U32 u32ReadCnt);

/**
 \brief Reads data by using the SPI.
CNcomment:\brief SPI\CA\FD\BEݷ\A2\CB͡\A3CNend

 \attention \n
N/A
 \param[in] enDev  select device          CNcomment:ָ\B6\A8\C9豸\A1\A3CNend
 \param[in] pu8Send  Buffer for storing the data to be written       CNcomment:\B4\E6\B7Ŵ\FDд\C8\EB\CA\FD\BEݡ\A3CNend
 \param[in] u32SendCnt  Length of the data to be written        CNcomment:\B4\FDд\CA\FD\BEݵĳ\A4\B6ȡ\A3CNend
 
 \retval 0 Success                                                                      CNcomment:\B3ɹ\A6\A1\A3CNend
 \retval ::HI_FAILURE	Read data failed					  	CNcomment:ʧ\B0ܡ\A3CNend
 \see \n
N/A
 */

HI_S32 HI_UNF_SPI_Write(HI_UNF_SPI_DEV_E enDev, HI_U8 *pu8Send, HI_U32 u32SendCnt);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */


#endif
