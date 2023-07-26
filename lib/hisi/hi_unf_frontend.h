/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
File Name       : hi_unf_frontend.h
Version         : Initial draft
Author          : HiSilicon multimedia software group
Created Date    : 2008-06-05
Description     : Application programming interfaces (APIs) of the external chip software (ECS)
Function List   :
Change History  :
 ******************************************************************************/
#ifndef __HI_UNF_FRONTEND_H__
#define __HI_UNF_FRONTEND_H__

#include "hi_common.h"

#include "hi_unf_i2c.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define HI_I2C_MAX_NUM_USER (15)    /** Maximum I2C channel ID*/ /** CNcomment:\D7\EE\B4\F3I2Cͨ\B5\C0\BA\C5*/

#define HI_UNF_DISEQC_MSG_MAX_LENGTH    (6)     /** DiSEqC message length*/  /** CNcomment:DiSEqC\CF\FBϢ\B3\A4\B6\C8*/
#define HI_UNF_DISEQC_MAX_REPEAT_TIMES  (4)     /** DiSEqC message max repeat times*/ /** CNcomment:DiSEqC\CF\FBϢ\D7\EE\B4\F3\D6ظ\B4\B7\A2\CBʹ\CE\CA\FD*/
#define MAX_TS_LINE 11                      /** The NO of ts lines that can be configured*/ /** CNcomment:\BF\C9\C5\E4\D6õ\C4ts\D0ź\C5\CF\DF\CA\FD\C1\BF*/
#define TER_MAX_TP              (20)

#define DISEQC_MAX_MOTOR_PISITION (255) /** DiSEqC motor max stored position*/ /** CNcomment:DiSEqC\C2\ED\B4\EF\D7\EE\B4\F3\B4洢\D0\C7λ\B8\F6\CA\FD*/

/*************************** Structure Definition ****************************/
/** \addtogroup      FRONTEND */
/** @{ */  /** <!-- [FRONTEND] */

/** Sample data, complex format*/
/** CNcomment: \B2ɼ\AF\CA\FD\BE\DD, \B8\B4\B8\F1ʽ*/
typedef struct  hiUNF_TUNER_SAMPLE_DATA_S
{
    HI_S32 s32DataIP;   /*sample data, i component*/    /**<CNcomment:\B2ɼ\AF\CA\FD\BEݵ\C4I\B7\D6\C1\BF*/
    HI_S32 s32DataQP;   /*sample data, q component*/    /**<CNcomment:\B2ɼ\AF\CA\FD\BEݵ\C4Q\B7\D6\C1\BF*/
} HI_UNF_TUNER_SAMPLE_DATA_S;

/** Sample data length*/
/** CNcomment: \B2\C9\CA\FD\B3\A4\B6\C8*/
typedef enum hiUNF_TUNER_SAMPLE_DATALEN_E
{
    HI_UNF_TUNER_SAMPLE_DATALEN_32,         /*sample 32 pts*/
    HI_UNF_TUNER_SAMPLE_DATALEN_64,         /*sample 64 pts*/
    HI_UNF_TUNER_SAMPLE_DATALEN_128,        /*sample 128 pts*/
    HI_UNF_TUNER_SAMPLE_DATALEN_256,        /*sample 256 pts*/
    HI_UNF_TUNER_SAMPLE_DATALEN_512,        /*sample 512 pts*/      /**<CNcomment:\B2ɼ\AF512\B5\E3*/
    HI_UNF_TUNER_SAMPLE_DATALEN_1024,       /*sample 1024 pts*/     /**<CNcomment:\B2ɼ\AF1024\B5\E3*/
    HI_UNF_TUNER_SAMPLE_DATALEN_2048,       /*sample 2048 pts*/     /**<CNcomment:\B2ɼ\AF2048\B5\E3*/
    HI_UNF_TUNER_SAMPLE_DATALEN_BUTT        /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SAMPLE_DATALEN_E;

/** Modulation mode*/
/** CNcomment: \B5\F7\D6Ʒ\BDʽ*/
typedef enum hiUNF_QAM_TYPE_E
{
    HI_UNF_MOD_TYPE_DEFAULT,          /**<Default QAM mode. The default QAM mode is HI_UNF_MOD_TYPE_QAM_64 at present.*/                /**<CNcomment:Ĭ\C8ϵ\C4QAM\C0\E0\D0\CD, \B5\B1ǰϵͳĬ\C8\CFΪHI_UNF_MOD_TYPE_QAM_64 */
    HI_UNF_MOD_TYPE_QAM_16 = 0x100,   /**<Enumeration corresponding to the 16QAM mode*/                                                 /**<CNcomment:16QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QAM_32,           /**<Enumeration corresponding to the 32QAM mode*/                                                 /**<CNcomment:32QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QAM_64,           /**<Enumeration corresponding to the 64QAM mode*/                                                 /**<CNcomment:64QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QAM_128,          /**<Enumeration corresponding to the 128QAM mode*/                                                /**<CNcomment:128QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QAM_256,          /**<Enumeration corresponding to the 256QAM mode*/                                                /**<CNcomment:256QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QAM_512,          /**<Enumeration corresponding to the 512QAM mode*/                                                /**<CNcomment:512QAM\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/

    HI_UNF_MOD_TYPE_BPSK = 0x200,     /**<Enumeration corresponding to the binary phase shift keying (BPSK) mode. */                    /**<CNcomment:BPSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_QPSK = 0x300,     /**<Enumeration corresponding to the quaternary phase shift keying (QPSK) mode. */                /**<CNcomment:QPSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_DQPSK,
    HI_UNF_MOD_TYPE_8PSK,             /**<Enumeration corresponding to the 8 phase shift keying (8PSK) mode*/                           /**<CNcomment:8PSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_16APSK,           /**<Enumeration corresponding to the 16-Ary Amplitude and Phase Shift Keying (16APSK) mode*/      /**<CNcomment:16APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_32APSK,           /**<Enumeration corresponding to the 32-Ary Amplitude and Phase Shift Keying (32APSK) mode*/      /**<CNcomment:32APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_64APSK,           /**<Enumeration corresponding to the 64-Ary Amplitude and Phase Shift Keying (64APSK) mode*/      /**<CNcomment:64APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_128APSK,          /**<Enumeration corresponding to the 128-Ary Amplitude and Phase Shift Keying (128APSK) mode*/    /**<CNcomment:128APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_256APSK,          /**<Enumeration corresponding to the 256-Ary Amplitude and Phase Shift Keying (256APSK) mode*/    /**<CNcomment:256APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_8VSB,             /**<Enumeration corresponding to (8VSB) mode*/                                                    /**<CNcomment:8VSB\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_16VSB,            /**<Enumeration corresponding to (16VSB) mode*/                                                   /**<CNcomment:16VSB\B6\D4Ӧ\B5\C4ö\BE\D9ֵ*/
    HI_UNF_MOD_TYPE_VLSNR_SET1,         /**<Enumeration corresponding to (VLSNR_SET1) mode,only used in DVB-S2X*/                       /**<CNcomment:VLSNR_SET1\B6\D4Ӧ\B5\C4ö\BE\D9ֵ\A3\ACDVB-S2X\D0\C2\D4\F6*/
    HI_UNF_MOD_TYPE_VLSNR_SET2,         /**<Enumeration corresponding to (VLSNR_SET2) mode,only used in DVB-S2X*/                       /**<CNcomment:VLSNR_SET2\B6\D4Ӧ\B5\C4ö\BE\D9ֵ\A3\ACDVB-S2X\D0\C2\D4\F6*/
    HI_UNF_MOD_TYPE_8APSK,              /**<Enumeration corresponding to (8APSK) mode,only used in DVB-S2x*/                            /**<CNcomment:8APSK\B6\D4Ӧ\B5\C4ö\BE\D9ֵ\A3\ACDVB-S2X\D0\C2\D4\F6*/

    /**<Enumeration corresponding to the auto mode. For DVB-S/S2, if detect modulation type fail, it will return auto*/
    /**<CNcomment:\CE\C0\D0\C7\D0źŵ\F7\D6Ʒ\BDʽ\D7Զ\AF\BC\EC\B2⣬\C8\E7\B9\FB\BC\EC\B2\E2ʧ\B0ܷ\B5\BB\D8AUTO*/
    HI_UNF_MOD_TYPE_AUTO,

    HI_UNF_MOD_TYPE_BUTT              /**<Invalid Modulation mode*/       /**<CNcomment:\B7Ƿ\A8\B5ĵ\F7\D6\C6\C0\E0\D0\CDö\BE\D9ֵ*/
} HI_UNF_MODULATION_TYPE_E;

/** Frequency locking status of the tuner*/
/** CNcomment:TUNER\CB\F8Ƶ״̬*/
typedef enum  hiUNF_TUNER_LOCK_STATUS_E
{
    HI_UNF_TUNER_SIGNAL_DROPPED = 0,       /**<The signal is not locked.*/  /**<CNcomment:\D0ź\C5δ\CB\F8\B6\A8*/
    HI_UNF_TUNER_SIGNAL_LOCKED,            /**<The signal is locked.*/      /**<CNcomment:\D0ź\C5\D2\D1\CB\F8\B6\A8*/
    HI_UNF_TUNER_SIGNAL_BUTT               /**<Invalid value*/              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_LOCK_STATUS_E;

/** Output mode of the tuner*/
/** CNcomment:TUNER\CA\E4\B3\F6ģʽ*/
typedef enum hiUNF_TUNER_OUTPUT_MODE_E
{
    HI_UNF_TUNER_OUTPUT_MODE_DEFAULT               = 0,   /**<Default mode*/                       /**<CNcomment:Ĭ\C8\CFģʽ*/
    HI_UNF_TUNER_OUTPUT_MODE_PARALLEL_MODE_A       = 1,   /**<Parallel mode A*/                    /**<CNcomment:\B2\A2\D0\D0ģʽA*/
    HI_UNF_TUNER_OUTPUT_MODE_PARALLEL_MODE_B       = 2,   /**<Parallel mode B*/                    /**<CNcomment:\B2\A2\D0\D0ģʽB*/
    HI_UNF_TUNER_OUTPUT_MODE_SERIAL                = 3,   /**<Serial mode 74.25M*/                 /**<CNcomment:\B4\AE\D0\D0ģ74.25M*/
    HI_UNF_TUNER_OUTPUT_MODE_SERIAL_50             = 4,   /**<Serial mode 50M*/                    /**<CNcomment:\B4\AE\D0\D0ģ50M*/
    HI_UNF_TUNER_OUTPUT_MODE_SERIAL_2BIT           = 5,   /**<Serial mode witch 2 bit data line*/  /**<CNcomment:2bit\B4\AE\D0\D0*/
    HI_UNF_TUNER_OUTPUT_MODE_FULLBAND_PARALLEL     = 6,   /**<FULLBAND Parallel mode */            /**<CNcomment:FULLBAND \B2\A2\D0\D0ģʽ*/
    HI_UNF_TUNER_OUTPUT_MODE_FULLBAND_SERIAL_3WIRE = 7,   /**<FULLBAND SERIAL three wire mode */   /**<CNcomment:FULLBAND \B4\AE\D0\D0\C8\FD\CF\DFģʽ*/
    HI_UNF_TUNER_OUTPUT_MODE_FULLBAND_SERIAL_4WIRE = 8,   /**<FULLBAND SERIAL four wire mode */    /**<CNcomment:FULLBAND \B4\AE\D0\D0\CB\C4\CF\DFģʽ*/
    HI_UNF_TUNER_OUTPUT_MODE_BUTT                         /**<Invalid value*/                      /**<CNcomment:\B7Ƿ\A8ֵ*/
} HI_UNF_TUNER_OUPUT_MODE_E;

/** Output order*/
/** CNcomment:TUNER\CA\E4\B3\F6\CF\DF\D0\F2 */
typedef enum hiUNF_TUNER_OUTPUT_TS_E
{
    HI_UNF_TUNER_OUTPUT_TSDAT0,        /**<data0*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF0bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT1,        /**<data1*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF1bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT2,        /**<data2*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF2bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT3,        /**<data3*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF3bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT4,        /**<data4*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF4bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT5,        /**<data5*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF5bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT6,        /**<data6*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF6bit*/
    HI_UNF_TUNER_OUTPUT_TSDAT7,        /**<data7*/                       /**<CNcomment:\CA\FD\BE\DD\CF\DF7bit*/
    HI_UNF_TUNER_OUTPUT_TSSYNC,        /**<sync*/                        /**<CNcomment:sync\D0ź\C5\CF\DF*/
    HI_UNF_TUNER_OUTPUT_TSVLD,         /**<valid*/                       /**<CNcomment:valid\D0ź\C5\CF\DF*/
    HI_UNF_TUNER_OUTPUT_TSERR,         /**<err*/                         /**<CNcomment:err\D0ź\C5\CF\DF*/
    HI_UNF_TUNER_OUTPUT_BUTT           /**<Invalid value*/               /**<CNcomment:\B7Ƿ\A8ֵ*/
} HI_UNF_TUNER_OUTPUT_TS_E;

/** ts output port order*/
/** CNcomment:ts\BDӿ\DA\CA\E4\B3\F6\CF\DF\D0\F2 */
typedef struct hiUNF_TUNER_TSOUT_SET_S
{
    HI_UNF_TUNER_OUTPUT_TS_E enTSOutput[MAX_TS_LINE];   /**<ts output port order*/    /**<CNcomment:ts\BDӿ\DA\CA\E4\B3\F6\CF\DF\D0\F2*/
} HI_UNF_TUNER_TSOUT_SET_S;

/** Signal type of the tuner*/
/** CNcomment:TUNER\D0ź\C5\C0\E0\D0\CD*/
typedef enum    hiTUNER_SIG_TYPE_E
{
    HI_UNF_TUNER_SIG_TYPE_CAB       = 1,        /**<Cable signal*/          /**<CNcomment:ITU-T J.83 ANNEX A/C(DVB_C)\D0ź\C5\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_SAT       = 2,        /**<Satellite signal*/      /**<CNcomment:\CE\C0\D0\C7\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_DVB_T     = 4,        /**<Terrestrial signal*/    /**<CNcomment:\B5\D8\C3\E6\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_DVB_T2    = 8,        /**<Terrestrial signal*/    /**<CNcomment:\B5\D8\C3\E6\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_ISDB_T    = 16,       /**<Terrestrial signal*/    /**<CNcomment:\B5\D8\C3\E6\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_ATSC_T    = 32,       /**<Terrestrial signal*/    /**<CNcomment:\B5\D8\C3\E6\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_DTMB      = 64,       /**<Terrestrial signal*/    /**<CNcomment:\B5\D8\C3\E6\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_J83B      = 128,      /**<Cable signal*/          /**<CNcomment:ITU-T J.83 ANNEX B(US Cable)\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_ABSS      = 256,      /**ABS-S signal */          /**<CNcomment: ֱ\B2\A5\D0\C7\CE\C0\D0\C7\D0ź\C5*/
    HI_UNF_TUNER_SIG_TYPE_BUTT                  /**<Invalid value*/         /**<CNcomment:\B7Ƿ\A8ֵ*/
} HI_UNF_TUNER_SIG_TYPE_E;

/** type of TUNER device*/
/** CNcomment:TUNER\C9豸\C0\E0\D0\CD*/
typedef enum    hiUNF_TUNER_DEV_TYPE_E
{
    HI_UNF_TUNER_DEV_TYPE_XG_3BL        = 0,    /**<XG_3BL,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_CD1616        = 1,    /**<CD1616,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_ALPS_TDAE     = 2,    /**<ALPS_TDAE,              Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_TDCC          = 3,    /**<TDCC,                   Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_TDA18250      = 4,    /**<TDA18250*/                                 /**<CNcomment:֧\B3\D6TDA18250\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_CD1616_DOUBLE = 5,    /**<CD1616 with double agc, Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_MT2081        = 6,    /**<MT2081,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_TMX7070X      = 7,    /**<THOMSON7070X,           Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_R820C         = 8,    /**<R820C*/                                    /**<CNcomment:֧\B3\D6R820C\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL203        = 9,    /**<MXL203 */                                  /**<CNcomment:֧\B3\D6MXL203\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_AV2011        = 10,   /**<AV2011*/                                   /**<CNcomment:֧\B3\D6AV2011\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_SHARP7903     = 11,   /**<SHARP7903,              Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_MXL101        = 12,   /**<MXL101,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_MXL603        = 13,   /**<MXL603*/                                   /**<CNcomment:֧\B3\D6MXL603\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_IT9170        = 14,   /**<IT9170,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_IT9133        = 15,   /**<IT9133,                 Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_TDA6651       = 16,   /**<TDA6651,                Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_TDA18250B     = 17,   /**<TDA18250B*/                                /**<CNcomment:֧\B3\D6TDA18250B\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_M88TS2022     = 18,   /**<M88TS2022,              Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_RDA5815       = 19,   /**<RDA5815*/                                  /**<CNcomment:֧\B3\D6RDA5815\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL254        = 20,   /**<MXL254*/                                   /**<CNcomment:֧\B3\D6MXL254\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_CXD2861       = 21,   /**<CXD2861,                Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_SI2147        = 22,   /**<Si2147*/                                   /**<CNcomment:֧\B3\D6Si2147\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_RAFAEL836     = 23,   /**<Rafael836*/                                /**<CNcomment:֧\B3\D6Rafael836\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL608        = 24,   /**<MXL608*/                                   /**<CNcomment:֧\B3\D6MXL608\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL214        = 25,   /**<MXL214*/                                   /**<CNcomment:֧\B3\D6MXL214\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_TDA18280      = 26,   /**<TDA18280*/                                 /**<CNcomment:֧\B3\D6TDA18280\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_TDA182I5A     = 27,   /**<TDA182I5A*/                                /**<CNcomment:֧\B3\D6TDA182I5AоƬ*/
    HI_UNF_TUNER_DEV_TYPE_SI2144        = 28,   /**<Si2144*/                                   /**<CNcomment:֧\B3\D6Si2144оƬ*/
    HI_UNF_TUNER_DEV_TYPE_AV2018        = 29,   /**<AV2018*/                                   /**<CNcomment:֧\B3\D6AV2018оƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL251        = 30,   /**<MXL251*/                                   /**<CNcomment:֧\B3\D6MXL251оƬ*/
    HI_UNF_TUNER_DEV_TYPE_M88TC3800     = 31,   /**<M88TC3800,              Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_TUNER_DEV_TYPE_MXL601        = 32,   /**< MXL601 */                                 /**<CNcomment:֧\B3\D6MXL601\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL683        = 33,   /**<MXL683*/                                   /**<CNcomment:֧\B3\D6MXL683\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_AV2026        = 34,   /**<AV2026*/                                   /**<CNcomment:֧\B3\D6AV2026\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_R850          = 35,   /**<R850*/                                     /**<CNcomment:֧\B3\D6R850\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_R858          = 36,   /**<R858*/                                     /**<CNcomment:֧\B3\D6R858\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL541        = 37,   /**<MXL541*/                                   /**<CNcomment:֧\B3\D6MXL541\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL581        = 38,   /**<MXL581*/                                   /**<CNcomment:֧\B3\D6MXL581\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL582        = 39,   /**<MXL582*/                                   /**<CNcomment:֧\B3\D6MXL582\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_MXL661        = 40,   /**<MXL661*/                                   /**<CNcomment:֧\B3\D6MXL661\C9\E4ƵоƬ*/
    HI_UNF_TUNER_DEV_TYPE_BUTT                  /**<Invalid value*/                            /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DEV_TYPE_E ;

/** Type of the demod device*/
/** CNcomment:demod\C9豸\C0\E0\D0\CD*/
typedef enum    hiUNF_DEMOD_DEV_TYPE_E
{
    HI_UNF_DEMOD_DEV_TYPE_NONE,                 /**<Not supported*/                         /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_DEMOD_DEV_TYPE_3130I       = 0x100,  /**<Internal QAM, same as HI_UNF_DEMOD_DEV_TYPE_INTERNAL0*/
                                                /**<CNcomment:\C4ڲ\BFQAM,\D3\EBHI_UNF_DEMOD_DEV_TYPE_INTERNAL0\CF\E0ͬ*/
    HI_UNF_DEMOD_DEV_TYPE_3130E       = 0x101,  /**<External Hi3130*/                       /**<CNcomment:\CDⲿQAM hi3130оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_J83B        = 0x102,  /**<suppoort j83b*/                         /**<CNcomment:֧\B3\D6j83b*/
    HI_UNF_DEMOD_DEV_TYPE_AVL6211     = 0x103,  /**<Avalink 6211*/                          /**<CNcomment:֧\B3\D6Avalink 6211*/
    HI_UNF_DEMOD_DEV_TYPE_MXL101      = 0x104,  /**<Maxlinear mxl101,    Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_DEMOD_DEV_TYPE_MN88472     = 0x105,  /**<PANASONIC mn88472*/                     /**<CNcomment:֧\B3\D6PANASONIC mn88472*/
    HI_UNF_DEMOD_DEV_TYPE_IT9170      = 0x106,  /**<ITE it9170,          Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_DEMOD_DEV_TYPE_IT9133      = 0x107,  /**<ITE it9133,          Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_DEMOD_DEV_TYPE_3136        = 0x108,  /**<External Hi3136*/                       /**<CNcomment:\CDⲿhi3136оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL254      = 0x10A,  /**<External mxl254*/                       /**<CNcomment:\CDⲿMXL254оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_CXD2837     = 0x10B,  /**Sony cxd2837,         Not supported*/    /**<CNcomment:\B2\BB֧\B3\D6*/
    HI_UNF_DEMOD_DEV_TYPE_3137        = 0x10C,  /**External Hi3137*/                        /**<CNcomment:֧\B3\D6\CDⲿhi3137оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL214      = 0x10D,  /**<External mxl214*/                       /**<CNcomment:\CDⲿMXL214оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_TDA18280    = 0x10E,  /**<External tda18280*/                     /**<CNcomment:\CDⲿtda18280оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL251      = 0x111,  /**<External mxl251*/                       /**<CNcomment:\CDⲿMXL251оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_ATBM888X    = 0x113,  /**External ATBM888X*/                      /**<CNcomment:֧\B3\D6\CDⲿATBM888XоƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MN88473     = 0x114,  /**< Panasonic 88473 */                     /**<CNcomment:֧\B3\D6Panasonic 88473 */
    HI_UNF_DEMOD_DEV_TYPE_MXL683      = 0x115,  /**<External mxl683*/                       /**<CNcomment:\CDⲿmxl683оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_TP5001      = 0x116,  /**External TP5001*/                        /**<CNcomment:֧\B3\D6\CDⲿTP5001оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_HD2501      = 0x117,  /**External HD2501*/                        /**<CNcomment:֧\B3\D6\CDⲿHD2501оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_AVL6381     = 0x118,  /**External AVL6381*/                       /**<CNcomment:֧\B3\D6\CDⲿAVL6381оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL541      = 0x119,  /**External MXL541*/                        /**<CNcomment:֧\B3\D6\CDⲿMXL541оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL581      = 0x11A,  /**External MXL581*/                        /**<CNcomment:֧\B3\D6\CDⲿMXL581оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_MXL582      = 0x11B,  /**External MXL582*/                        /**<CNcomment:֧\B3\D6\CDⲿMXL582оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_INTERNAL0   = 0x11C,  /**Internal Demod*/                         /**<CNcomment:֧\B3\D6\C4ڲ\BF\BD\E2\B5\F7оƬ*/
    HI_UNF_DEMOD_DEV_TYPE_BUTT                  /**<Invalid value*/                         /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_DEMOD_DEV_TYPE_E;

/** Defines the cable transmission signal.*/
/** CNcomment:\B6\A8\D2\E5CABLE\B4\AB\CA\E4\D0ź\C5*/
typedef struct  hiUNF_CAB_CONNECT_PARA_S
{
    HI_U32                      u32Freq;            /**<Frequency, in kHz*/         /**<CNcomment:Ƶ\C2ʣ\AC\B5\A5λ\A3\BAkHz*/
    HI_U32                      u32SymbolRate;      /**<Symbol rate, in bit/s*/     /**<CNcomment:\B7\FB\BA\C5\C2ʣ\AC\B5\A5λbps */
    HI_UNF_MODULATION_TYPE_E    enModType;          /**<QAM mode*/                  /**<CNcomment:QAM\B5\F7\D6Ʒ\BDʽ*/
    HI_BOOL                     bReverse;           /**<Spectrum reverse mode*/     /**<CNcomment:Ƶ\C6׵\B9\D6ô\A6\C0\ED\B7\BDʽ*/
    HI_U32                      u32BandWidth;       /**<bandwidth in KHz*/          /**<CNcomment:\B4\F8\BF\ED\A3\AC\B5\A5λkHz*/
} HI_UNF_CAB_CONNECT_PARA_S;

/** Guard interval of OFDM*/
/** CNcomment:\B6\E0\D4ز\A8\B5\F7\D6\C6\CFµı\A3\BB\A4\BC\E4\B8\F4*/
typedef enum hiUNF_TUNER_FE_GUARD_INTV_E
{
    HI_UNF_TUNER_FE_GUARD_INTV_DEFALUT = 0,     /**<default guard interval mode*/   /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F4Ĭ\C8\CFģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_1_128,           /**<1/128*/                         /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F41/128ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_1_32,            /**<1/32*/                          /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F41/32ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_1_16,            /**<1/16*/                          /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F41/16ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_1_8,             /**<1/8*/                           /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F41/8ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_1_4,             /**<1/4*/                           /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F41/4ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_19_128,          /**<19/128*/                        /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F419/128ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_19_256,          /**<19/256*/                        /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F419/256ģʽ*/
    HI_UNF_TUNER_FE_GUARD_INTV_BUTT             /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_GUARD_INTV_E;

/** OFDM Mode, used in multi-carrier modulation*/
/** CNcomment:OFDMģʽ\A3\AC\D3\C3\D3ڶ\E0\D4ز\A8\B5\F7\D6\C6ģʽ\CF\C2*/
typedef enum hiUNF_TUNER_FE_FFT_E
{
    HI_UNF_TUNER_FE_FFT_DEFAULT = 0,   /**<default mode*/     /**<CNcomment:Ĭ\C8\CFģʽ*/
    HI_UNF_TUNER_FE_FFT_1K ,           /**<1k mode*/          /**<CNcomment:1kģʽ*/
    HI_UNF_TUNER_FE_FFT_2K ,           /**<2k mode*/          /**<CNcomment:2kģʽ*/
    HI_UNF_TUNER_FE_FFT_4K ,           /**<4k mode*/          /**<CNcomment:4kģʽ*/
    HI_UNF_TUNER_FE_FFT_8K ,           /**<8k mode*/          /**<CNcomment:8kģʽ*/
    HI_UNF_TUNER_FE_FFT_16K ,          /**<16k mode*/         /**<CNcomment:16kģʽ*/
    HI_UNF_TUNER_FE_FFT_32K ,          /**<32k mode*/         /**<CNcomment:32kģʽ*/
    HI_UNF_TUNER_FE_FFT_64K ,          /**<64k mode*/         /**<CNcomment:64kģʽ*/
    HI_UNF_TUNER_FE_FFT_BUTT           /**<Invalid value*/    /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_FFT_E;

/** Hierarchical modulation mode, only used in DVB-T*/
/** CNcomment:\BD\F6\D3\C3\D3\DADVB-T*/
typedef enum hiUNF_TUNER_FE_HIERARCHY_E
{
    HI_UNF_TUNER_FE_HIERARCHY_DEFAULT = 0,      /**<hierarchical modulation default mode*/      /**<CNcomment:Ĭ\C8\CFģʽ*/
    HI_UNF_TUNER_FE_HIERARCHY_NO,               /**<no hierarchical modulation mode*/           /**<CNcomment:\B2\BB\B7ּ\B6\B1\F0ģʽ*/
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA1,           /**<hierarchical mode, alpha = 1*/              /**<CNcomment:\B7ּ\B6\B1\F0ģʽ, alpha = 1*/
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA2,           /**<hierarchical mode, alpha = 2*/              /**<CNcomment:\B7ּ\B6\B1\F0ģʽ, alpha = 2*/
    HI_UNF_TUNER_FE_HIERARCHY_ALHPA4,           /**<hierarchical mode, alpha = 4*/              /**<CNcomment:\B7ּ\B6\B1\F0ģʽ, alpha = 4*/
    HI_UNF_TUNER_FE_HIERARCHY_BUTT              /**<Invalid value*/                             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_HIERARCHY_E;

/** TS Priority, only used in DVB-T*/
/** CNcomment:\BD\F6\D3\C3\D3\DADVB-T*/
typedef enum hiUNF_TUNER_TS_PRIORITY_E
{
    HI_UNF_TUNER_TS_PRIORITY_NONE = 0,      /**<no priority mode*/          /**<CNcomment:\CE\DE\D3\C5\CFȼ\B6ģʽ*/
    HI_UNF_TUNER_TS_PRIORITY_HP,            /**<high priority mode*/        /**<CNcomment:\B8\DF\D3\C5\CFȼ\B6ģʽ*/
    HI_UNF_TUNER_TS_PRIORITY_LP,            /**<low priority mode*/         /**<CNcomment:\B5\CD\D3\C5\CFȼ\B6ģʽ*/
    HI_UNF_TUNER_TS_PRIORITY_BUTT           /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TS_PRIORITY_E;

/** base channel or lite channel, only used in DVB-T2*/
/** CNcomment:\BD\F6\D3\C3\D3\DADVB-T2*/
typedef enum hiUNF_TUNER_TER_MODE_E
{
    HI_UNF_TUNER_TER_MODE_BASE = 0,     /**< the channel is base mode*/         /**<CNcomment:ͨ\B5\C0\D6н\F6֧\B3\D6base\D0ź\C5*/
    HI_UNF_TUNER_TER_MODE_LITE,         /**< the channel is lite mode*/         /**<CNcomment:ͨ\B5\C0\D6\D0\D0\E8Ҫ֧\B3\D6lite\D0ź\C5*/
    HI_UNF_TUNER_TER_MODE_BUTT      /**<Invalid value*/            /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_MODE_E;

/** Stream type*/
/** CNcomment:\C1\F7\C0\E0\D0\CD*/
typedef enum hiUNF_TUNER_TER_STREAM_TYPE_E
{
    HI_UNF_TUNER_TER_STREAM_TYPE_GFPS = 0,    /**< Generic Fixed Packet size Stream*/     /**<CNcomment:ͨ\D3ù̶\A8\B0\FC\B3\A4\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_STREAM_TYPE_GCS,         /**< Generic Continuous Stream*/            /**<CNcomment:ͨ\D3\C3\C1\AC\D0\F8\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_STREAM_TYPE_GSE,         /**< Generic Stream Encapsulated*/          /**<CNcomment:GSE\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_STREAM_TYPE_TS,          /**< Trasport Stream*/                      /**<CNcomment:TS\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_STREAM_TYPE_GSE_HEM,     /**< GSE in High Efficiency Mode*/          /**<CNcomment:GSE\C1\F7HEMģʽ*/
    HI_UNF_TUNER_TER_STREAM_TYPE_TS_HEM,      /**< TS in High Efficiency Mode*/           /**<CNcomment:TS\C1\F7HEMģʽ*/
    HI_UNF_TUNER_TER_STREAM_TYPE_BUTT         /**< Invalid value*/                        /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_STREAM_TYPE_E;

/** DVB-T2 data PLP's ISSY type*/
/** CNcomment:\BD\F6\D3\C3\D3\DADVB-T2*/
typedef enum hiUNF_TUNER_DVBT2_ISSY_E
{
    HI_UNF_TUNER_DVBT2_ISSY_NO = 0,   /**< No Input Stream SYnchronizer*/        /**<CNcomment:\CE\DEISSY*/
    HI_UNF_TUNER_DVBT2_ISSY_SHORT,    /**< Short Input Stream SYnchronizer*/     /**<CNcomment:\B6\CCISSY*/
    HI_UNF_TUNER_DVBT2_ISSY_LONG,     /**< Long Input Stream SYnchronizer*/      /**<CNcomment:\B3\A4ISSY*/
    HI_UNF_TUNER_DVBT2_ISSY_BUTT      /**< Invalid value*/                       /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DVBT2_ISSY_E;

/** TS clock polarization*/
/** CNcomment:TSʱ\D6Ӽ\AB\D0\D4*/
typedef enum hiUNF_TUNER_TSCLK_POLAR_E
{
    HI_UNF_TUNER_TSCLK_POLAR_FALLING,       /**<Falling edge*/      /**<CNcomment:\CF½\B5\D1\D8*/
    HI_UNF_TUNER_TSCLK_POLAR_RISING,        /**<Rising edge*/       /**<CNcomment:\C9\CF\C9\FD\D1\D8*/
    HI_UNF_TUNER_TSCLK_POLAR_BUTT           /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TSCLK_POLAR_E;

/** TS format*/
/** CNcomment:TS\B8\F1ʽ*/
typedef enum hiUNF_TUNER_TS_FORMAT_E
{
    HI_UNF_TUNER_TS_FORMAT_TS,              /**<188*/               /**<CNcomment:188\D7ֽڸ\F1ʽ*/
    HI_UNF_TUNER_TS_FORMAT_TSP,             /**<204*/               /**<CNcomment:204\D7ֽڸ\F1ʽ*/
    HI_UNF_TUNER_TS_FORMAT_BUTT             /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TS_FORMAT_E;

/** TS serial PIN*/
/** CNcomment:\B4\AE\D0\D0TS\CA\FD\BEݹܽ\C5*/
typedef enum hiUNF_TUNER_TS_SERIAL_PIN_E
{
    HI_UNF_TUNER_TS_SERIAL_PIN_0,           /**<Serial pin 0, default*/  /**<CNcomment:\B4\AE\D0\D0ģʽ\A3\AC\CA\FD\BE\DD\CF\DFʹ\D3õ\DA0bit*/
    HI_UNF_TUNER_TS_SERIAL_PIN_7,           /**<Serial pin 7*/           /**<CNcomment:\B4\AE\D0\D0ģʽ\A3\AC\CA\FD\BE\DD\CF\DFʹ\D3õ\DA7bit*/
    HI_UNF_TUNER_TS_SERIAL_PIN_BUTT         /**<Invalid value*/          /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TS_SERIAL_PIN_E;

/** ISDBT layer information,each layer can be received indepent*/
/** CNcomment:ISDBT\B2\E3\D0\C5Ϣ\A3\ACÿ\B2㶼\BF\C9\D2Զ\C0\C1\A2\BD\D3\CA\D5*/
typedef enum hiUNF_TUNER_ISDBT_MONITOR_LAYER_E
{
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_ALL,
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_A,
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_B,
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_C,
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_BUTT
}HI_UNF_TUNER_ISDBT_MONITOR_LAYER_E;
/** Tuner RF AGC mode*/
/** CNcomment:agc\BF\D8\D6\C6ģʽ*/
typedef enum hiUNF_TUNER_RFAGC_MODE_E
{
    /**< Inverted polarization, default.This setting is used for a tuner whose gain decreases with increased AGC voltage*/   /**<CNcomment:agc\B7\B4\CF\F2\BF\D8\D6\C6ģʽ*/
    HI_UNF_TUNER_RFAGC_INVERT,

    /**< Normal polarization. This setting is used for a tuner whose gain increases with increased AGC voltage*/             /**<CNcomment:agc\D5\FD\CF\F2\BF\D8\D6\C6ģʽ*/
    HI_UNF_TUNER_RFAGC_NORMAL,
    HI_UNF_TUNER_RFAGC_BUTT                  /**<Invalid value*/                                                             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_RFAGC_MODE_E;

/** TS sync head length */
typedef enum hiUNF_TUNER_TS_SYNC_HEAD_E
{
    HI_UNF_TUNER_TS_SYNC_HEAD_AUTO,
    HI_UNF_TUNER_TS_SYNC_HEAD_8BIT,
    HI_UNF_TUNER_TS_SYNC_HEAD_BUTT
} HI_UNF_TUNER_TS_SYNC_HEAD_E;

/** Tuner IQ spectrum mode*/
/** CNcomment:IQģʽ*/
typedef enum hiUNF_TUNER_IQSPECTRUM_MODE_E
{
    HI_UNF_TUNER_IQSPECTRUM_NORMAL,         /**<The received signal spectrum is not inverted*/    /**<CNcomment:IQ\B2\BB\B7\B4ת*/
    HI_UNF_TUNER_IQSPECTRUM_INVERT,         /**<The received signal spectrum is inverted*/        /**<CNcomment:IQ\B7\B4ת*/
    HI_UNF_TUNER_IQSPECTRUM_BUTT            /**<Invalid value*/                                   /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_IQSPECTRUM_MODE_E;

/** DiSEqC Wave Mode*/
/** CNcomment:DiSEqCģʽ*/
typedef enum hiUNF_TUNER_DISEQCWAVE_MODE_E
{
    HI_UNF_TUNER_DISEQCWAVE_NORMAL,         /**<Waveform produced by demod*/                 /**<CNcomment:\B2\A8\D0\CE\D3\C9demod\B2\FA\C9\FA*/
    HI_UNF_TUNER_DISEQCWAVE_ENVELOPE,       /**<Waveform produced by LNB control device*/    /**<CNcomment:\B2\A8\D0\CE\D3ɿ\D8\D6\C6оƬ\B2\FA\C9\FA*/
    HI_UNF_TUNER_DISEQCWAVE_BUTT            /**<Invalid value*/                              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQCWAVE_MODE_E;

/** LNB power supply and control device*/
/** CNcomment:LNB\B9\A9\B5\E7\BAͿ\D8\D6\C6оƬ*/
typedef enum hiUNF_LNBCTRL_DEV_TYPE_E
{
    HI_UNF_LNBCTRL_DEV_TYPE_NONE,           /**<No LNB control device*/      /**<CNcomment:\CE޿\D8\D6\C6оƬ*/
    HI_UNF_LNBCTRL_DEV_TYPE_MPS8125,        /**<MPS8125*/                    /**<CNcomment:MPS8125*/
    HI_UNF_LNBCTRL_DEV_TYPE_ISL9492,        /**<ISL9492*/                    /**<CNcomment:ISL9492*/
    HI_UNF_LNBCTRL_DEV_TYPE_A8300,          /**<A8300*/                      /**<CNcomment:A8300*/
    HI_UNF_LNBCTRL_DEV_TYPE_A8297,
    HI_UNF_LNBCTRL_DEV_TYPE_TPS65233,       /**<TPS65233*/                   /**<CNcomment:TPS65233*/
    HI_UNF_LNBCTRL_DEV_TYPE_BUTT            /**<Invalid value*/              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_LNBCTRL_DEV_TYPE_E;

/** FEC code Rate*/
/** CNcomment:FEC\C2\EB\C2\CA*/
typedef enum hiUNF_TUNER_FE_FECRATE_E
{
    HI_UNF_TUNER_FE_FEC_AUTO = 0,
    HI_UNF_TUNER_FE_FEC_1_2,           /**<1/2*/           /**<CNcomment:1/2\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_2_3,           /**<2/3*/           /**<CNcomment:2/3\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_3_4,           /**<3/4*/           /**<CNcomment:3/4\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_4_5,           /**<4/5*/           /**<CNcomment:4/5\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_5_6,           /**<5/6*/           /**<CNcomment:5/6\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_6_7,           /**<6/7*/           /**<CNcomment:6/7\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_7_8,           /**<7/8*/           /**<CNcomment:7/8\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_8_9,           /**<8/9*/           /**<CNcomment:8/9\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_9_10,          /**<9/10*/          /**<CNcomment:9/10\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_1_4,           /**<1/4*/           /**<CNcomment:1/4\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_1_3,           /**<1/3*/           /**<CNcomment:1/3\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_2_5,           /**<2/5*/           /**<CNcomment:2/5\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_3_5,           /**<3/5*/           /**<CNcomment:3/5\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_13_45,         /**<13/45*/         /**<CNcomment:13/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_9_20,          /**<9/20*/          /**<CNcomment:9/20\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_11_20,         /**<11/20*/         /**<CNcomment:11/20\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_5_9_L,         /**<5/9L*/          /**<CNcomment:5/9L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_26_45_L,       /**<26/45L*/        /**<CNcomment:26/45L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_23_36,         /**<23/36*/         /**<CNcomment:23/36\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_25_36,         /**<25/36*/         /**<CNcomment:25/36\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_13_18,         /**<13/18*/         /**<CNcomment:13/18\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_1_2_L,         /**<1/2L*/          /**<CNcomment:1/2L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_8_15_L,        /**<8/15L*/         /**<CNcomment:8/15L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_26_45,         /**<26/45*/         /**<CNcomment:26/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_3_5_L,         /**<3/5L*/          /**<CNcomment:3/5L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_28_45,         /**<28/45*/         /**<CNcomment:28/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_2_3_L,         /**<2/3L*/          /**<CNcomment:2/3L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_7_9,           /**<7/9*/           /**<CNcomment:7/9\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_77_90,         /**<77/90*/         /**<CNcomment:77/90\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_32_45,         /**<32/45*/         /**<CNcomment:32/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_11_15,         /**<11/15*/         /**<CNcomment:11/15\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_32_45_L,       /**<32/45*/         /**<CNcomment:32/45L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_29_45_L,       /**<29/45L*/        /**<CNcomment:29/45L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_31_45_L,       /**<31/45*/         /**<CNcomment:31/45L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_11_15_L,       /**<11/15L*/        /**<CNcomment:11/15L\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_11_45,         /**<11/45*/         /**<CNcomment:11/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_4_15,          /**<4/15*/          /**<CNcomment:4/15\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_14_45,         /**<14/45*/         /**<CNcomment:14/45\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_7_15,          /**<7/15*/          /**<CNcomment:7/15\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_8_15,          /**<8/15*/          /**<CNcomment:8/15\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_2_9,           /**<2/9*/           /**<CNcomment:2/9\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FEC_1_5,           /**<2/9*/           /**<CNcomment:2/9\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FECRATE_BUTT       /**<Invalid value*/ /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_FECRATE_E;

/** Parameter for ISDB-T layer exist or not*/
/** CNcomment:ISDB-Tģʽ\CF£\AC\B2\E3\CAǷ\F1\B4\E6\D4\DA\D0\C5Ϣ*/
typedef union hiUNF_TUNER_ISDBT_LAYERS_IDENTIFY_U
{
    struct
    {
        HI_U8 u8LayerAExist:1;  /*[0]*/
        HI_U8 u8LayerBExist:1;  /*[1]*/
        HI_U8 u8LayerCExist:1;  /*[2]*/
        HI_U8 reserved:5;       /*[7:3]*/
    }bits;

    HI_U8 ExistanceFlag;
}HI_UNF_TUNER_ISDBT_LAYERS_IDENTIFY_U;

/** Parameter for ISDB-T layer configuration*/
/** CNcomment:ISDB-Tģʽ\CF£\AC\B2\E3\C5\E4\D6\C3\D0\C5Ϣ*/
typedef struct hiUNF_TUNER_MONITOR_LAYERS_CONFIG_S
{
    HI_UNF_TUNER_ISDBT_MONITOR_LAYER_E enMonitorLayer;  /**<ISDB-T layer exist or not*/ /**<CNcomment:ISDB-Tģʽ\CF£\AC\B2\E3\CAǷ\F1\B4\E6\D4\DA\C5\E4\D6\C3\D0\C5Ϣ*/
} HI_UNF_TUNER_MONITOR_LAYERS_CONFIG_S;


/** Parameter for ISDB-T layer information*/
/** CNcomment:ISDB-Tģʽ\CF£\AC\B2\E3 \D0ź\C5\CA\F4\D0\D4\D0\C5Ϣ*/
typedef struct hiUNF_TUNER_ISDBT_LAYERS_INFO_S
{
    HI_U8 u8LayerSegNum;            /**<layer segment number*/              /**<CNcomment:\B2\E3segment\B8\F6\CA\FD*/
    HI_U8 u8LayerReserved[3];
    HI_UNF_TUNER_FE_HIERARCHY_E enLayerHierMod; /**<layer hierarchy mode*/  /**<CNcomment:\B2\E3ʱ\BC佻֯ģʽ*/
    HI_UNF_TUNER_FE_FECRATE_E   enLayerFECRate; /**<layer FEC rate*/        /**<CNcomment:\B2\E3\C2\EB\C2\CA*/
    HI_UNF_MODULATION_TYPE_E    enLayerModType; /**<layer modulation type*/ /**<CNcomment:\B2\E3\B5\F7\D6\C6ģʽ*/
}HI_UNF_TUNER_ISDBT_LAYERS_INFO_S;

/** Parameter for ISDB-T TMCC information*/
/** CNcomment:ISDB-Tģʽ\CF£\ACTMCC \D0\C5Ϣ*/
typedef struct hiUNF_TUNER_TMCC_INFO_S
{
    HI_U8 u8EmergencyFlag;  /**<the start flag for emergency alarm broadcasting*/                   /**<CNcomment:\BD\F4\BC\B1\B1\A8\BE\AF\B2\A5\B1\A8\BF\AAʼ\B1\EA־*/
    HI_U8 u8PartialFlag;    /**<partial reception flag*/                                            /**<CNcomment:\B2\BF\B7ֽ\D3\CAձ\EA־*/
    HI_U8 u8PhaseShiftCorr; /**<phase shift correction value for connected segment transmission*/   /**<CNcomment:\CF\E0λƫ\D2\C6ֵ*/
    HI_U8 u8IsdbtSystemId;  /**<system identification[0 = ISDB_T,1 = ISDB_T_SB]*/                   /**<CNcomment:ϵͳ\B1\EAʶ*/

    HI_UNF_TUNER_ISDBT_LAYERS_INFO_S stIsdbtLayersAInfoBits;
    HI_UNF_TUNER_ISDBT_LAYERS_INFO_S stIsdbtLayersBInfoBits;
    HI_UNF_TUNER_ISDBT_LAYERS_INFO_S stIsdbtLayersCInfoBits;

    HI_U8 u8TMCCReserved[4];    /**<Reserve*/                                                       /**<CNcomment:\B1\A3\C1\F4\B2\CE\CA\FD*/
} HI_UNF_TUNER_TMCC_INFO_S;

/** ADC port select*/
/** CNcomment:ADC\B6˿\DAѡ\D4\F1*/
typedef enum hiUNF_TUNER_ADC_PORT_E
{
    HI_UNF_TUNER_ADC0,          /**<ADC0 port*/   /**<CNcomment:ADC0\B6˿\DA*/
    HI_UNF_TUNER_ADC1,          /**<ADC1 port*/   /**<CNcomment:ADC1\B6˿\DA*/
    HI_UNF_TUNER_ADC_BUTT
}HI_UNF_TUNER_ADC_PORT_E;

/** Satellite extended attribution*/
/** CNcomment:\CE\C0\D0ǻ\FA\B8\BD\BC\D3\CA\F4\D0\D4*/
typedef struct  hiUNF_TUNER_SAT_ATTR_S
{
    HI_U32                         u32DemodClk;     /**<Demod reference clock frequency, KHz*/    /**<CNcomment:demod\B2ο\BCʱ\D6\D3Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U16                         u16TunerMaxLPF;  /**<Tuner max LPF, MHz*/                      /**<CNcomment:tuner\B5\CDͨ\C2˲\A8\C6\F7ͨ\B4\F8Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U16                         u16TunerI2CClk;  /**<Tuner I2C clock, kHz*/                    /**<CNcomment:tuner i2cʱ\D6\D3Ƶ\C2\CA*/
    HI_UNF_TUNER_RFAGC_MODE_E      enRFAGC;         /**<Tuner RF AGC mode*/                       /**<CNcomment:agcģʽ*/
    HI_UNF_TUNER_IQSPECTRUM_MODE_E enIQSpectrum;    /**<Tuner IQ spectrum mode*/                  /**<CNcomment:IQģʽ*/
    HI_UNF_TUNER_TSCLK_POLAR_E     enTSClkPolar;    /**<TS clock polarization*/                   /**<CNcomment:tsʱ\D6Ӽ\AB\D0\D4*/
    HI_UNF_TUNER_TS_FORMAT_E       enTSFormat;      /**<TS format*/                               /**<CNcomment:ts\B8\F1ʽ*/
    HI_UNF_TUNER_TS_SERIAL_PIN_E   enTSSerialPIN;   /**<TS serial PIN*/                           /**<CNcomment:ts\B4\AE\D0\D0\CA\FD\BE\DD\CF\DF*/
    HI_UNF_TUNER_DISEQCWAVE_MODE_E enDiSEqCWave;    /**<DiSEqC Wave Mode*/                        /**<CNcomment:DiSEqCģʽ*/
    HI_UNF_LNBCTRL_DEV_TYPE_E      enLNBCtrlDev;    /**<LNB power supply and control device*/     /**<CNcomment:LNB\BF\D8\D6\C6оƬ*/
    HI_U16                         u16LNBDevAddress;/**<LNB control device address*/              /**<CNcomment:LNB\BF\D8\D6\C6оƬi2c\B5\D8ַ*/
} HI_UNF_TUNER_SAT_ATTR_S;

/** Terrestrial extended attribution*/
/** CNcomment:\B5\D8\C3\E6\BB\FA\B8\BD\BC\D3\CA\F4\D0\D4*/
typedef struct  hiUNF_TUNER_TER_ATTR_S
{
    HI_U32                         u32DemodClk;     /**<Demod reference clock frequency, KHz*/    /**<CNcomment:demod\B2ο\BCʱ\D6\D3Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U32                         u32ResetGpioNo;  /**< Demod reset GPIO NO. */
    HI_U16                         u16TunerMaxLPF;  /**<Tuner max LPF, MHz*/                      /**<CNcomment:tuner\B5\CDͨ\C2˲\A8\C6\F7ͨ\B4\F8Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U16                         u16TunerI2CClk;  /**<Tuner I2C clock, kHz*/                    /**<CNcomment:tuner i2cʱ\D6\D3Ƶ\C2\CA*/
    HI_UNF_TUNER_RFAGC_MODE_E      enRFAGC;         /**<Tuner RF AGC mode*/                       /**<CNcomment:agcģʽ*/
    HI_UNF_TUNER_IQSPECTRUM_MODE_E enIQSpectrum;    /**<Tuner IQ spectrum mode*/                  /**<CNcomment:IQģʽ*/
    HI_UNF_TUNER_TSCLK_POLAR_E     enTSClkPolar;    /**<TS clock polarization*/                   /**<CNcomment:tsʱ\D6Ӽ\AB\D0\D4*/
    HI_UNF_TUNER_TS_FORMAT_E       enTSFormat;      /**<TS format*/                               /**<CNcomment:ts\B8\F1ʽ*/
    HI_UNF_TUNER_TS_SERIAL_PIN_E   enTSSerialPIN;   /**<TS serial PIN*/                           /**<CNcomment:ts\B4\AE\D0\D0\CA\FD\BE\DD\CF\DF*/
    HI_UNF_TUNER_TS_SYNC_HEAD_E    enTSSyncHead;    /**<TS sync head length*/                     /**<CNcomment:tsͬ\B2\BDͷ\B3\A4\B6\C8*/
} HI_UNF_TUNER_TER_ATTR_S;

/** Cable extended attribution*/
/** CNcomment:\D3\D0\CF߸\BD\BC\D3\CA\F4\D0\D4*/
typedef struct  hiUNF_TUNER_CAB_ATTR_S
{
    HI_U32                         u32ResetGpioNo;  /**< Demod reset GPIO NO. */
    HI_U32                         u32DemodClk;     /**< Demod reference clock frequency, KHz */
    HI_UNF_TUNER_TSCLK_POLAR_E     enTSClkPolar;    /**< TS clock polarization */
    HI_UNF_TUNER_TS_FORMAT_E       enTSFormat;      /**< TS format */
    HI_UNF_TUNER_TS_SERIAL_PIN_E   enTSSerialPIN;   /**< TS serial PIN */
    HI_UNF_TUNER_TS_SYNC_HEAD_E    enTSSyncHead;    /**<TS sync head length*/                   /**<CNcomment:tsͬ\B2\BDͷ\B3\A4\B6\C8*/
} HI_UNF_TUNER_CAB_ATTR_S;

/** Polarization type*/
/** CNcomment:\BC\AB\BB\AF\B7\BDʽ*/
typedef enum hiUNF_TUNER_FE_POLARIZATION_E
{
    HI_UNF_TUNER_FE_POLARIZATION_H,     /**<Horizontal Polarization*/           /**<CNcomment:ˮƽ\BC\AB\BB\AF*/
    HI_UNF_TUNER_FE_POLARIZATION_V,     /**<Vertical Polarization*/             /**<CNcomment:\B4\B9ֱ\BC\AB\BB\AF*/
    HI_UNF_TUNER_FE_POLARIZATION_L,     /**<Left-hand circular Polarization*/   /**<CNcomment:\D7\F3\D0\FDԲ\BC\AB\BB\AF*/
    HI_UNF_TUNER_FE_POLARIZATION_R,     /**<Right-hand circular Polarization*/  /**<CNcomment:\D3\D2\D0\FDԲ\BC\AB\BB\AF*/
    HI_UNF_TUNER_FE_POLARIZATION_BUTT,  /**<Invalid value*/                     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_POLARIZATION_E;

/** Pilot type*/
/** CNcomment:\B5\BCƵ*/
typedef enum hiUNF_TUNER_PILOT_E
{
    HI_UNF_TUNER_PILOT_OFF,         /**<Pilot off*/               /**<CNcomment:\B5\BCƵ\B9ر\D5*/
    HI_UNF_TUNER_PILOT_ON,          /**<Pilot on*/                /**<CNcomment:\B5\BCƵ\B4\F2\BF\AA*/
    HI_UNF_TUNER_PILOT_BUTT         /**<Invalid value*/           /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_PILOT_E;

/** FEC length*/
/** CNcomment:FEC֡ \B3\A4\B6\C8*/
typedef enum hiUNF_TUNER_SAT_FEC_FRAME_MODE_E
{
    HI_UNF_TUNER_SAT_FEC_FRAME_NORMAL,  /**<nomal FEC Frame*/       /**<CNcomment:\C6\D5ͨ\B3\A4\B6\C8FEC֡\A3\AC\CA\CA\D3\C3\D3\DADVB-S/S2/S2X*/
    HI_UNF_TUNER_SAT_FEC_FRAME_SHORT,   /**<short FEC Frame*/       /**<CNcomment:\B6\CCFEC֡\A3\AC\CA\CA\D3\C3\D3\DADVB-S2X*/
    HI_UNF_TUNER_SAT_FEC_FRAME_MEDIUM,  /**<medium FEC Fream*/      /**<CNcomment:\D6е\C8FEC֡\A3\AC\CA\CA\D3\C3\D3\DADVB-S2X*/
    HI_UNF_TUNER_SAT_FEC_FRAME_BUTT     /**<Invalid value*/         /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SAT_FEC_FRAME_MODE_E;

/** Roll off*/
/** CNcomment:\B9\F6\BD\B5ϵ\CA\FD*/
typedef enum hiUNF_TUNER_ROLLOFF_E
{
    HI_UNF_TUNER_ROLLOFF_35,        /**<Roll off 0.35*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.35*/
    HI_UNF_TUNER_ROLLOFF_25,        /**<Roll off 0.25*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.25*/
    HI_UNF_TUNER_ROLLOFF_20,        /**<Roll off 0.20*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.20*/
    HI_UNF_TUNER_ROLLOFF_15,        /**<Roll off 0.15*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.15*/
    HI_UNF_TUNER_ROLLOFF_10,        /**<Roll off 0.10*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.10*/
    HI_UNF_TUNER_ROLLOFF_05,        /**<Roll off 0.05*/           /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD0.05*/
    HI_UNF_TUNER_ROLLOFF_BUTT       /**<Invalid value*/           /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_ROLLOFF_E;

/** Stream typef*/
/** CNcomment:\C1\F7\C0\E0\D0\CD*/
typedef enum hiUNF_TUNER_SAT_STREAM_TYPE_E
{
    HI_UNF_TUNER_SAT_STREAM_TYPE_GENERIC_PACKETIZED,  /**< Generic Packetized Stream*/         /**<CNcomment:ͨ\D3ô\F2\B0\FC\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_GENERIC_CONTINUOUS,  /**< Generic Continuous Stream*/         /**<CNcomment:ͨ\D3\C3\C1\AC\D0\F8\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_GSE_HEM,             /**< GSE in High Efficiency Mode*/       /**<CNcomment:GSE\C1\F7\C0\E0\D0\CDHEMģʽ*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_TRANSPORT,           /**< Trensport Stream*/                  /**<CNcomment:TS\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_GSE_LITE,            /**< GSE-Lite*/                          /**<CNcomment:GSE-Lite\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_GSE_LITE_HEM,        /**< GSE-Lite in High Efficiency Mode*/  /**<CNcomment:GSE-Lite\C1\F7HEMģʽ*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_T2MI,                /**< T2MI Stream*/                       /**<CNcomment:T2MI\C1\F7\C0\E0\D0\CD*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_BUTT                 /**< Invalid value*/                     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SAT_STREAM_TYPE_E;

/** FEC Type*/
/** CNcomment:\CE\C0\D0Ǳ\EA׼*/
typedef enum hiUNF_TUNER_FE_FECTYPE_E
{
    HI_UNF_TUNER_FE_DVBS,               /**<DVB-S*/                         /**<CNcomment:DVB-S\B1\EA׼*/
    HI_UNF_TUNER_FE_DVBS2,              /**<DVB-S2*/                        /**<CNcomment:DVB-S2\B1\EA׼*/
    HI_UNF_TUNER_FE_DIRECTV,            /**<DIRECTV*/                       /**<CNcomment:DIRECTV\B1\EA׼*/
    HI_UNF_TUNER_FE_DVBS2X,             /**<DVB-S2X*/                       /**<CNcomment:DVB-S2X\B1\EA׼*/
    HI_UNF_TUNER_FE_BUTT                /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_FECTYPE_E;

/** LNB type*/
/** CNcomment:LNB\C0\E0\D0\CD*/
typedef enum hiUNF_TUNER_FE_FE_LNBTYPE_E
{
    HI_UNF_TUNER_FE_LNB_SINGLE_FREQUENCY,   /**<Single LO frequency*/       /**<CNcomment:\B5\A5\B1\BE\D5\F1*/
    HI_UNF_TUNER_FE_LNB_DUAL_FREQUENCY,     /**<Dual LO frequency*/         /**<CNcomment:˫\B1\BE\D5\F1*/
    HI_UNF_TUNER_FE_LNB_UNICABLE,           /**<Unicable LNB */             /**<CNcomment:unicable\B8\DFƵͷ*/
    HI_UNF_TUNER_FE_LNB_TRIPLE_FREQUENCY,   /**<Triple LO frequency*/       /**<CNcomment:\C8\FD\B1\BE\D5\F1*/
    HI_UNF_TUNER_FE_LNB_UNICABLE2,          /**<Unicable2 LNB */             /**<CNcomment:unicable2\B8\DFƵͷ*/
    HI_UNF_TUNER_FE_LNB_TYPE_BUTT           /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_LNB_TYPE_E;

/** LNB band type*/
/** CNcomment:\CE\C0\D0\C7\D0ź\C5Ƶ\B6\CE*/
typedef enum hiUNF_TUNER_FE_LNB_BAND_E
{
    HI_UNF_TUNER_FE_LNB_BAND_C,             /**<C */                        /**<CNcomment:C\B2\A8\B6\CE*/
    HI_UNF_TUNER_FE_LNB_BAND_KU,            /**<Ku */                       /**<CNcomment:Ku\B2\A8\B6\CE*/
    HI_UNF_TUNER_FE_LNB_BAND_KA,            /**<Ka */                       /**<CNcomment:Ka\B2\A8\B6\CE*/
    HI_UNF_TUNER_FE_LNB_BAND_BUTT           /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_LNB_BAND_E;

/** LNB power control*/
/** CNcomment:\B8\DFƵͷ\B9\A9\B5\E7\BF\D8\D6\C6*/
typedef enum hiUNF_TUNER_FE_LNB_POWER_E
{
    HI_UNF_TUNER_FE_LNB_POWER_OFF,          /**<LNB power off*/                                                     /**<CNcomment:\B9ض\CF*/
    HI_UNF_TUNER_FE_LNB_POWER_ON,           /**<LNB power auto, 13V/18V, default*/                                  /**<CNcomment:Ĭ\C8ϵ\C413/18V\B9\A9\B5\E7*/
    HI_UNF_TUNER_FE_LNB_POWER_ENHANCED,     /**<LNB power auto, 14V/19V, some LNB control device can support.*/     /**<CNcomment:\BC\D3ǿ\B9\A9\B5\E7*/
    HI_UNF_TUNER_FE_LNB_POWER_BUTT          /**<Invalid value*/                                                     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_LNB_POWER_E;

/** Antenna power control*/
/** CNcomment:\CC\EC\CF߹\A9\B5\E7\BF\D8\D6\C6*/
typedef enum hiUNF_TUNER_TER_ANTENNA_POWER_E
{
    HI_UNF_TUNER_TER_ANTENNA_POWER_OFF,     /**<Antenna power off*/          /**<CNcomment:\CC\EC\CFߵ\E7Դ\B9ض\CF*/
    HI_UNF_TUNER_TER_ANTENNA_POWER_ON,      /**<Antenna power on*/           /**<CNcomment:\CC\EC\CFߵ\E7Դ\B4\F2\BF\AA*/
    HI_UNF_TUNER_TER_ANTENNA_POWER_BUTT     /**<Invalid value*/              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_ANTENNA_POWER_E;

/** Demod standby or wake up status*/
/** CNcomment:\BD\E2\B5\F7оƬ\B4\FD\BB\FA\BB\BD\D0\D1״̬*/
typedef enum hiUNF_TUNER_DEMOD_STATUS_E
{
    HI_UNF_TUNER_DEMODE_WAKE_UP = 0,        /**<Demod wake up*/              /**<CNcomment:\BD\E2\B5\F7оƬ\BB\BD\D0\D1*/
    HI_UNF_TUNER_DEMODE_STANDBY,            /**<Demod standby*/              /**<CNcomment:\BD\E2\B5\F7оƬ\B4\FD\BB\FA*/
    HI_UNF_TUNER_DEMOD_STATUS_BUTT          /**<Invalid value*/              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
}HI_UNF_TUNER_DEMOD_STATUS_E;

/** LNB 22K tone status, for Ku band LNB*/
/** CNcomment:22k\D0ź\C5״̬\A3\AC\D3\C3\D3\DAKu˫\B1\BE\D5\F1*/
typedef enum hiUNF_TUNER_FE_LNB_22K_E
{
    HI_UNF_TUNER_FE_LNB_22K_OFF,            /**<22k off*/                    /**<CNcomment:22k\D0źŹأ\ACѡ\D4\F1\B5ͱ\BE\D5\F1*/
    HI_UNF_TUNER_FE_LNB_22K_ON,             /**<22k on*/                     /**<CNcomment:22k\D0źſ\AA\A3\ACѡ\D4\F1\B8߱\BE\D5\F1*/
    HI_UNF_TUNER_FE_LNB_22K_BUTT            /**<Invalid value*/              /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_FE_LNB_22K_E;

/** 0/12V switch*/
/** CNcomment:0/12V\BF\AA\B9\D8*/
typedef enum hiUNF_TUNER_SWITCH_0_12V_E
{
    HI_UNF_TUNER_SWITCH_0_12V_NONE,         /**< None, default*/            /**<CNcomment:\B2\BB\BDӿ\AA\B9\D8״̬*/
    HI_UNF_TUNER_SWITCH_0_12V_0,            /**< 0V*/                       /**<CNcomment:0V״̬*/
    HI_UNF_TUNER_SWITCH_0_12V_12,           /**< 12V*/                      /**<CNcomment:12V״̬*/
    HI_UNF_TUNER_SWITCH_0_12V_BUTT          /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SWITCH_0_12V_E;

/** 22KHz switch*/
/** CNcomment:22K\BF\AA\B9\D8*/
typedef enum hiUNF_TUNER_SWITCH_22K_E
{
    HI_UNF_TUNER_SWITCH_22K_NONE,           /**< None, default*/            /**<CNcomment:\B2\BB\BDӿ\AA\B9\D8״̬*/
    HI_UNF_TUNER_SWITCH_22K_0,              /**< 0*/                        /**<CNcomment:0kHz\B6˿\DA*/
    HI_UNF_TUNER_SWITCH_22K_22,             /**< 22KHz*/                    /**<CNcomment:22kHz\B6˿\DA*/
    HI_UNF_TUNER_SWITCH_22K_BUTT            /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SWITCH_22K_E;

/** Tone burst switch*/
/** CNcomment:Tone burst\BF\AA\B9\D8*/
typedef enum hiUNF_TUNER_SWITCH_TONEBURST_E
{
    HI_UNF_TUNER_SWITCH_TONEBURST_NONE,     /**< Don't send tone burst, default*/ /**<CNcomment:\B2\BB\BDӿ\AA\B9\D8״̬*/
    HI_UNF_TUNER_SWITCH_TONEBURST_0,        /**< Tone burst 0*/                   /**<CNcomment:0 port*/
    HI_UNF_TUNER_SWITCH_TONEBURST_1,        /**< Tone burst 1*/                   /**<CNcomment:1 port*/
    HI_UNF_TUNER_SWITCH_TONEBURST_BUTT      /**<Invalid value*/                   /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SWITCH_TONEBURST_E;

/** pilot pattern */
typedef enum hiUNF_TUNER_TER_PILOT_PATTERN_E
{
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP1 = 0,  /**< pilot pattern pp1 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP2,      /**< pilot pattern pp2 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP3,      /**< pilot pattern pp3 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP4,      /**< pilot pattern pp4 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP5,      /**< pilot pattern pp5 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP6,      /**< pilot pattern pp6 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP7,      /**< pilot pattern pp7 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_PP8,      /**< pilot pattern pp8 */
    HI_UNF_TUNER_T2_PILOT_PATTERN_BUTT
} HI_UNF_TUNER_TER_PILOT_PATTERN_E;

/** information for channel mode*/
/** CNcomment:ͨ\B5\C0ģʽ\D0\C5Ϣ*/
typedef enum hiUNF_TUNER_TER_CHANNEL_MODE_E
{
    HI_UNF_TUNER_TER_PURE_CHANNEL = 0,      /**< pure channel*/     /**<CNcomment:\B4\BFͨ\B5\C0ģʽ*/
    HI_UNF_TUNER_TER_MIXED_CHANNEL,         /**< mixed channel*/    /**<CNcomment:\BB\EC\BA\CFͨ\B5\C0ģʽ*/
    HI_UNF_TUNER_TER_CHANNEL_MODE_BUTT      /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_CHANNEL_MODE_E;

/** information for carrier mode*/
/** CNcomment:\D4ز\A8ģʽ\D0\C5Ϣ*/
typedef enum hiUNF_TUNER_TER_CARRIER_MODE_E
{
    HI_UNF_TUNER_TER_EXTEND_CARRIER = 0,    /**< extend carrier*/   /**<CNcomment:\C0\A9չ\D4ز\A8*/
    HI_UNF_TUNER_TER_NORMAL_CARRIER,        /**< normal carrier*/   /**<CNcomment:\D5\FD\B3\A3\D4ز\A8*/
    HI_UNF_TUNER_TER_CARRIER_MODE_BUTT      /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_CARRIER_MODE_E;

/** CNcomment:code and modulation ģʽ*/
typedef enum hiUNF_TUNER_CODE_MODULATION_E
{
    HI_UNF_TUNER_CODE_MODULATION_VCM_ACM,       /**< VCM/ACM*/      /**<CNcomment:\BFɱ\E4\C2\EB\C2ʺ͵\F7\D6\C6/\D7\D4\CA\CAӦ\C2\EB\C2ʺ͵\F7\D6\C6ģʽ*/
    HI_UNF_TUNER_CODE_MODULATION_CCM,           /**< CCM*/          /**<CNcomment:\B9̶\A8\C2\EB\C2ʺ͵\F7\D6\C6ģʽ*/
    HI_UNF_TUNER_CODE_MODULATION_MULTISTREAM,   /**< MultiStream*/  /**<CNcomment:\B2\BB\B1\E4\B5\F7\D6\C6ģʽ\CFµĶ\E0\C1\F7*/
    HI_UNF_TUNER_CODE_MODULATION_BUTT           /**<Invalid value*/ /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_CODE_MODULATION_E;

/** information for constellation mode*/
/** CNcomment:\D0\C7\D7\F9\CAǷ\F1\D0\FDת*/
typedef enum hiUNF_TUNER_CONSTELLATION_MODE_E
{
    HI_UNF_TUNER_CONSTELLATION_STANDARD = 0,    /**< standard constellation*/   /**<CNcomment:\B2\BB\D0\FDת\D0\C7\D7\F9*/
    HI_UNF_TUNER_CONSTELLATION_ROTATION,        /**< rotation constellation*/   /**<CNcomment:\D0\FDת\D0\C7\D7\F9*/
    HI_UNF_TUNER_CONSTELLATION_MODE_BUTT        /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_CONSTELLATION_MODE_E;

/** FEC frame length*/
/** CNcomment:FEC֡\B3\A4*/
typedef enum hiUNF_TUNER_TER_FEC_FRAME_MODE_E
{
    HI_UNF_TUNER_TER_FEC_FRAME_NORMAL = 0,      /**< normal fec frame*/ /**<CNcomment:\C6\D5ͨ\B3\A4\B6ȵ\C4fec֡*/
    HI_UNF_TUNER_TER_FEC_FRAME_SHORT,           /**< short fec frame*/  /**<CNcomment:fec\B6\CC֡*/
    HI_UNF_TUNER_TER_FEC_FRAME_MODE_BUTT        /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_TER_FEC_FRAME_MODE_E;

/** Structure of the satellite transmission signal.*/
/** CNcomment:\B6\A8\D2\E5Satellite\B4\AB\CA\E4\D0ź\C5*/
typedef struct  hiUNF_SAT_CONNECT_PARA_S
{
    HI_U32                         u32Freq;         /**<Downlink frequency, in kHz*/ /**<CNcomment:\CF\C2\D0\D0Ƶ\C2ʣ\AC\B5\A5λ\A3\BAkHz*/
    HI_U32                         u32SymbolRate;   /**<Symbol rate, in Symb/s*/     /**<CNcomment:\B7\FB\BA\C5\C2ʣ\AC\B5\A5λ\A3\BASymb/s */
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;         /**<Polarization type*/          /**<CNcomment:\BC\AB\BB\AF\B7\BDʽ*/
    HI_U32                         u32ScrambleValue; /**<Physical layer initial scrambling code,range 0~262141,the default value must be 0,when signal sender config some TP using not 0,
    then receiver must modify this value the same as sender,if not,signal will be unlock,the modified value maybe told by signal sender.*/
    /**<CNcomment:\CE\EF\C0\ED\B2\E3\C8\C5\C2\EB\B3\F5ʼֵ\A3\AC\B7\B6Χ0~262141.\B8\C3ֵ\B5\C4Ĭ\C8\CF\C9\E8\D6\C3ֵΪ0,\B8\F6\B1\F0Ƶ\B5㷢\B6\CBû\D3\D0ʹ\D3\C3Ĭ\C8\CFֵ0\A3\AC\CAն˽\D3\CA\D5ʱ\D0\E8\D0޸ĸ\C3ֵ\BAͷ\A2\B6\CBһ\D6£\AC\B7\F1\D4\F2\BB\E1\D2\FD\C6\F0\D0ź\C5ʧ\CB\F8\A3\AC\B8\C3ֵ\BF\C9\D3ɷ\A2\B6˸\E6֪\A1\A3*/
} HI_UNF_SAT_CONNECT_PARA_S;

/** configure lock tp PLP parameter,only in DVB-T2 */
/** CNcomment:\D4\DADVB-T2ʱ\A3\AC\C5\E4\D6\C3Ҫ\CB\F8Ƶ\B5\E3\B5\C4\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CA\F4\D0\D4*/
typedef struct hiUNF_TUNER_TER_PLP_PARA_S
{
    HI_U8                       u8PlpId;            /**<PLP id*/                /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0ID*/
    HI_U8                       u8CommPlpId;        /**<common PLP id*/         /**<CNcomment:\B9\B2\CF\ED\CE\EF\C0\ED\B2\E3\B9ܵ\C0ID*/
    HI_U8                       u8Combination;      /**<PLP combination*/       /**<CNcomment:\CA\FD\BE\DD\CE\EF\C0\ED\B2\E3\B9ܵ\C0\BA͹\B2\CF\ED\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CAǷ\F1\D7\E9\BAϱ\EA־*/
} HI_UNF_TUNER_TER_PLP_PARA_S;

/** Terestrial connect param*/
/** CNcomment:\B5\D8\C3\E6\D0ź\C5\CB\F8̨\B2\CE\CA\FD*/
typedef struct  hiUNF_TER_CONNECT_PARA_S
{
    HI_U32                      u32Freq;            /**<freq in KHz*/               /**<CNcomment:Ƶ\C2ʣ\AC\B5\A5λkHz*/
    HI_U32                      u32BandWidth;       /**<bandwidth in KHz*/          /**<CNcomment:\B4\F8\BF\ED\A3\AC\B5\A5λkHz*/
    HI_UNF_MODULATION_TYPE_E    enModType;          /**<modulation type*/           /**<CNcomment:\B5\F7\D6Ʒ\BDʽ*/
    HI_BOOL                     bReverse;           /**<Spectrum reverse mode*/     /**<CNcomment:Ƶ\C6׷\ADת\B4\A6\C0\ED\B7\BDʽ*/
    HI_UNF_TUNER_TER_MODE_E     enChannelMode;      /**<dvb-t2 channel mode*/       /**<CNcomment:dvb-t2\D0ŵ\C0\BD\D3\CA\D5ģʽ*/
    HI_UNF_TUNER_TS_PRIORITY_E  enDVBTPrio;         /**<dvb-t TS priority*/         /**<CNcomment:dvb-t\C2\EB\C1\F7\D3\C5\CFȼ\B6*/
    HI_UNF_TUNER_TER_PLP_PARA_S stPLPParam;         /**< PLP parameter*/            /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\B2\CE\CA\FD*/
} HI_UNF_TER_CONNECT_PARA_S;

/** Structure of the satellite transmission signal's detailed information.*/
/** CNcomment:\CE\C0\D0\C7\D0ź\C5\CF\EAϸ\D0\C5Ϣ*/
typedef struct  hiUNF_TUNER_SAT_SIGNALINFO_S
{
    HI_U32                         u32Freq;         /**<Downlink frequency, in kHz*/              /**<CNcomment:\CF\C2\D0\D0Ƶ\C2ʣ\AC\B5\A5λ\A3\BAkHz*/
    HI_U32                         u32SymbolRate;   /**<Symbol rate, in Symb/s*/                  /**<CNcomment:\B7\FB\BA\C5\C2ʣ\AC\B5\A5λSymb/s*/
    HI_UNF_MODULATION_TYPE_E       enModType;       /**<Modulation type*/                         /**<CNcomment:\B5\F7\D6Ʒ\BDʽ*/
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;         /**<Polarization type*/                       /**<CNcomment:\BC\AB\BB\AF\B7\BDʽ*/
    HI_UNF_TUNER_FE_FECTYPE_E      enSATType;       /**<Saterllite standard, DVB-S/S2/DIRECTV*/   /**<CNcomment:\CE\C0\D0Ǳ\EA׼\A3\AC ֧\B3\D6DVB-S/S2/DIRECTV*/
    HI_UNF_TUNER_FE_FECRATE_E      enFECRate;       /**<FEC rate*/                                /**<CNcomment:ǰ\CF\F2\BE\C0\B4\ED\C2\EB\C2\CA*/
    HI_UNF_TUNER_CODE_MODULATION_E enCodeModulation;
    HI_UNF_TUNER_ROLLOFF_E         enRollOff;       /**<Rolloff*/                                 /**<CNcomment:\B9\F6\BD\B5ϵ\CA\FD*/
    HI_UNF_TUNER_PILOT_E           enPilot;         /**<Pilot*/                                   /**<CNcomment:\B5\BCƵ*/
    HI_UNF_TUNER_SAT_FEC_FRAME_MODE_E    enFECFrameMode;     /**<FEC fream mode*/                 /**<CNcomment:FEC֡\B3\A4\B6\C8*/
    HI_UNF_TUNER_SAT_STREAM_TYPE_E enStreamType;    /**<Stream type*/                             /**<CNcomment:\C1\F7\C0\E0\D0\CD*/
} HI_UNF_TUNER_SAT_SIGNALINFO_S;

/** PLP type of DVB-T2.*/
/** CNcomment:T2\CF\C2\CE\EF\C0\ED\B2\E3\B9ܵ\C0\C0\E0\D0\CD*/
typedef enum hiUNF_TUNER_T2_PLP_TYPE_E
{
    HI_UNF_TUNER_T2_PLP_TYPE_COM=0,         /**<common type*/              /**<CNcomment:\C6\D5ͨ*/
    HI_UNF_TUNER_T2_PLP_TYPE_DAT1,          /**<data1 type*/               /**<CNcomment:\CA\FD\BE\DD1*/
    HI_UNF_TUNER_T2_PLP_TYPE_DAT2,          /**<data2 type*/               /**<CNcomment:\CA\FD\BE\DD2*/
    HI_UNF_TUNER_T2_PLP_TYPE_BUTT           /**<Invalid value*/            /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_T2_PLP_TYPE_E;

/** Structure of the terrestrial transmission signal's detailed information.*/
/** CNcomment:\B5\D8\C3\E6\D0ź\C5\CF\EAϸ\D0\C5Ϣ*/
typedef struct  hiUNF_TUNER_TER_SIGNALINFO_S
{
    HI_U32                              u32Freq;                /**<Frequency, in kHz*/         /**<CNcomment:Ƶ\C2ʣ\AC\B5\A5λ\A3\BAkHz*/
    HI_U32                              u32BandWidth;           /**<Band width, in KHz*/        /**<CNcomment:\B4\F8\BF\ED\A3\AC\B5\A5λKHz */
    HI_UNF_MODULATION_TYPE_E            enModType;              /**<Modulation type*/           /**<CNcomment:\B5\F7\D6Ʒ\BDʽ*/
    HI_UNF_TUNER_FE_FECRATE_E           enFECRate;              /**<FEC rate*/                  /**<CNcomment:ǰ\CF\F2\BE\C0\B4\ED\C2\EB\C2\CA*/
    HI_UNF_TUNER_FE_FECRATE_E           enLowPriFECRate;
    HI_UNF_TUNER_FE_GUARD_INTV_E        enGuardIntv;            /**<GI mode*/                   /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F4ģʽ*/
    HI_UNF_TUNER_FE_FFT_E               enFFTMode;              /**<FFT mode*/                  /**<CNcomment:FFTģʽ*/
    HI_UNF_TUNER_FE_HIERARCHY_E         enHierMod;              /**<Hierarchical Modulation and alpha, only used in DVB-T*/
                                                                /**<CNcomment:hierachicalģʽ\BA\CDalphaֵ*/
    HI_UNF_TUNER_TS_PRIORITY_E          enTsPriority;           /**<The TS priority, only used in DVB-T*/
                                                                /**<CNcomment:ts priority, \BD\F6\D3\C3\D3\DADVB-Tģʽ\CF\C2*/
    HI_UNF_TUNER_T2_PLP_TYPE_E          enPLPType;              /**<PLP type*/                  /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_PILOT_PATTERN_E    enPilotPattern;         /**<pilot pattern*/             /**<CNcomment:\B5\BCƵģʽ*/
    HI_UNF_TUNER_TER_CARRIER_MODE_E     enCarrierMode;          /**<carrier mode*/              /**<CNcomment:\D4ز\A8ģʽ*/
    HI_UNF_TUNER_CONSTELLATION_MODE_E   enConstellationMode;    /**<constellation mode*/        /**<CNcomment:\D0\C7\D7\F9\CAǷ\F1\D0\FDת*/
    HI_UNF_TUNER_TER_FEC_FRAME_MODE_E   enFECFrameMode;         /**<FEC frame length*/          /**<CNcomment:FEC֡\B3\A4*/
    HI_UNF_TUNER_TER_MODE_E             enChannelMode;          /**<Base channel or Lite channel, only used in DVB-T2 */            /**<CNcomment:Base\BB\F2Liteģʽ\A3\AC\BD\F6\D3\C3\D3\DADVB-T2ģʽ\CF\C2*/
    HI_UNF_TUNER_DVBT2_ISSY_E           enDVBT2ISSY;            /**<DVB-T2 ISSY type */        /**<CNcomment:ISSY\C0\E0\D0\CD*/
    HI_UNF_TUNER_TER_STREAM_TYPE_E      enStreamType;           /**<Stream type */             /**<CNcomment:\C1\F7\C0\E0\D0\CD*/
    HI_U16                              u16CellID;              /**< Cell ID*/                 /**<CNcomment:\B5\A5ԪID*/
    HI_U16                              u16NetworkID;           /**< NetWork ID*/              /**<CNcomment:\CD\F8\C2\E7ID*/
    HI_U16                              u16SystemID;            /**< System ID*/               /**<CNcomment:ϵͳID*/
} HI_UNF_TUNER_TER_SIGNALINFO_S;

/** Structure of the ISDB-T terrestrial transmission signal's detailed information.*/
/** CNcomment:\B5\D8\C3\E6ISDB-T\D0ź\C5\CF\EAϸ\D0\C5Ϣ*/
typedef struct  hiUNF_TUNER_ISDB_T_SIGNALINFO_S
{
    HI_U32                                  u32Freq;            /**<Frequency, in kHz */        /**<CNcomment:Ƶ\C2ʣ\AC\B5\A5λ: kHz */
    HI_U32                                  u32BandWidth;       /**<Band width, in KHz */       /**<CNcomment:\B4\F8\BF\ED\A3\AC\B5\A5λKHz */
    HI_UNF_TUNER_ISDBT_LAYERS_IDENTIFY_U    unISDBTLayers;      /**<the transmission and used information of ISDBT layer*/          /**<CNcomment:ISDBT\B2\E3\D5\FD\D4ڴ\AB\CA\E4ʹ\D3\C3\D0\C5Ϣ*/
    HI_UNF_TUNER_TMCC_INFO_S                stISDBTTMCCInfo;    /**<the para of ISDBT layer*/   /**<CNcomment:ISDBT\B2\E3\B2\CE\CA\FD\D0\C5Ϣ*/
    HI_UNF_TUNER_FE_GUARD_INTV_E            enGuardIntv;        /**<GI mode*/                   /**<CNcomment:\B1\A3\BB\A4\BC\E4\B8\F4ģʽ*/
    HI_UNF_TUNER_FE_FFT_E                   enFFTMode;          /**<FFT mode*/                  /**<CNcomment:FFTģʽ*/
} HI_UNF_TUNER_ISDB_T_SIGNALINFO_S;

/** signal information.*/
/** CNcomment:TUNER\D0ź\C5\CA\F4\D0\D4*/
typedef struct hiUNF_TUNER_SIGNALINFO_S
{
    HI_UNF_TUNER_SIG_TYPE_E enSigType;              /**<Signal transmission type*/    /**<CNcomment:\D0ź\C5\C0\E0\D0\CD*/

    union
    {
        HI_UNF_TUNER_SAT_SIGNALINFO_S stSat;        /**<Signal info of satellite*/    /**<CNcomment:\CE\C0\D0\C7\D0ź\C5\D0\C5Ϣ*/
        HI_UNF_TUNER_TER_SIGNALINFO_S stTer;        /**<Signal info of terrestrial*/  /**<CNcomment:\B5\D8\C3\E6\D0ź\C5\D0\C5Ϣ*/
        HI_UNF_TUNER_ISDB_T_SIGNALINFO_S stIsdbT;/**<Signal info of ISDB-T terrestrial*/  /**<CNcomment:\B5\D8\C3\E6ISDB-T\D0ź\C5\D0\C5Ϣ*/
    } unSignalInfo;
} HI_UNF_TUNER_SIGNALINFO_S;

/** unicable multi-switch port.*/
/** CNcomment:unicable\BF\AA\B9ض˿\DAö\BE\D9*/
typedef enum hiUNF_TUNER_SATPOSITION_E
{
    HI_UNF_TUNER_SATPOSN_A,    /**<unicable switch port A*/    /**<CNcomment:\B6˿\DAA*/
    HI_UNF_TUNER_SATPOSN_B,    /**<unicable switch port B*/    /**<CNcomment:\B6˿\DAB*/
    HI_UNF_TUNER_SATPOSN_BUT   /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_SATPOSITION_E;

/** LNB configurating parameters*/
/** CNcomment:LNB\C5\E4\D6ò\CE\CA\FD*/
typedef struct hiUNF_TUNER_FE_LNB_CONFIG_S
{
    HI_UNF_TUNER_FE_LNB_TYPE_E  enLNBType;      /**<LNB type*/                              /**<CNcomment:LNB\C0\E0\D0\CD*/
    HI_U32                      u32LowLO;       /**< Low Local Oscillator Frequency, MHz */ /**<CNcomment:LNB\B5ͱ\BE\D5\F1Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U32                      u32HighLO;      /**< High Local Oscillator Frequency, MHz*/ /**<CNcomment:LNB\B8߱\BE\D5\F1Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_U32                      u32MediumLO;      /**< Medium Local Oscillator Frequency, MHz*/ /**<CNcomment:LNB\D6б\BE\D5\F1Ƶ\C2ʣ\AC\B5\A5λMHz*/
    HI_UNF_TUNER_FE_LNB_BAND_E  enLNBBand;      /**< LNB band, C or Ku */                   /**<CNcomment:LNB\B2\A8\B6Σ\BAC\BB\F2Ku*/

    /** Structure of the unicable device attribute.*/
    /** CNcomment:\CE\C0\D0\C7Unicable\C9豸\CA\F4\D0\D4*/
    HI_U8 u8UNIC_SCRNO;                         /**< SCR number, 0-31 */                     /**<CNcomment:SCR\D0\F2\BAţ\ACȡֵΪ0-31*/
    HI_U32 u32UNICIFFreqMHz;                    /**< SCR IF frequency, unit MHz */          /**<CNcomment:SCR\D6\D0ƵƵ\C2ʣ\AC \B5\A5λMHz*/
    HI_UNF_TUNER_SATPOSITION_E enSatPosn;       /**< unicable multi-switch port */          /**<CNcomment:unicable\BF\AA\B9ض˿ں\C5*/
    HI_BOOL bPinProtect;                        /**< UB with pin protect */                     /**<CNcomment:\D3û\A7Ƶ\B6\CEpin\C2뱣\BB\A4*/
} HI_UNF_TUNER_FE_LNB_CONFIG_S;

/** tuner attribution.*/
/** CNcomment:TUNER\CA\F4\D0\D4*/
typedef struct  hiHI_UNF_TUNER_ATTR_S
{
    HI_UNF_TUNER_SIG_TYPE_E     enSigType;          /**<Signal type*/                               /**<CNcomment:\D0ź\C5\C0\E0\D0\CD*/
    HI_UNF_TUNER_DEV_TYPE_E     enTunerDevType;     /**<Tuner type*/                                /**<CNcomment:TUNER\C0\E0\D0\CD*/
    HI_U32                      u32TunerAddr;       /*The i2c address of tuner, if demod type is 3130I,3130E or J83B, you cannot set it*/
    HI_UNF_DEMOD_DEV_TYPE_E     enDemodDevType;     /**<QAM type*/                                  /**<CNcomment:QAM\C0\E0\D0\CD*/
    HI_U32                      u32DemodAddr;       /*The i2c address of demod, if demod type is 3130I,3130E or J83B, you cannot set it*/
    HI_UNF_TUNER_OUPUT_MODE_E   enOutputMode ;      /**<Output mode of transport streams (TSs)*/    /**<CNcomment:TS\C1\F7\CA\E4\B3\F6ģʽ*/
    HI_U8                       enI2cChannel;       /**<I2C channel used by the demod*/             /**<CNcomment:DEMODʹ\D3õ\C4I2Cͨ\B5\C0*/
    HI_U8                       enTunerI2cChannel;  /**<I2C channel used by the tuner*/             /**<CNcomment:TUNERʹ\D3õ\C4I2Cͨ\B5\C0\A3\AC\B5\B1 tuner\BA\CD demodʹ\D3ò\BBͬI2Cͨ\B5\C0ʱʹ\D3ã\ACĿǰ\BD\F6\CF\DE\D3\DAR858ģ\BF\E9ʹ\D3\C3*/
    HI_U32                      u32ResetGpioNo;     /**<Demod reset GPIO NO.*/                      /**<CNcomment:\B8\B4λʹ\D3õ\C4gpio\B9ܽź\C5*/
    HI_U32                      u32MemoryMode;      /**<Only valid in Hi3716MV430 DVBT2,0 is low memory mode,1 is high memory mode.Low memory mode default,COMMON PLP is not supported in this mode.*/
                                                    /**<CNcomment: \BD\F6\B6\D4Hi3716MV430\B5\C4DVB-T2\D3\D0Ч\A1\A3 0\B1\EDʾ\B5\CD\C4ڴ\E6ģʽ\A3\AC1\B1\EDʾ\B8\DF\C4ڴ\E6ģʽ\A1\A3Ĭ\C8\CFΪ\B5\CD\C4ڴ\E6ģʽ\A3\AC\B4\CBģʽ\B2\BB֧\B3\D6COMMON PLP*/
} HI_UNF_TUNER_ATTR_S;

/** Frequency locking parameters of the tuner*/
/** CNcomment:TUNER\CB\F8Ƶ\B2\CE\CA\FD*/
typedef struct  hiUNF_TUNER_CONNECT_PARA_S
{
    HI_UNF_TUNER_SIG_TYPE_E enSigType;          /**<Signal type*/                       /**<CNcomment:\D0ź\C5\C0\E0\D0\CD*/

    union
    {
        HI_UNF_CAB_CONNECT_PARA_S stCab;        /**<Cable transmission signal*/         /**<CNcomment:CABLE\B4\AB\CA\E4\D0ź\C5*/
        HI_UNF_TER_CONNECT_PARA_S stTer;        /**<Terrestrial transmission signal*/   /**<CNcomment:\B5\D8\C3洫\CA\E4\D0ź\C5*/
        HI_UNF_SAT_CONNECT_PARA_S stSat;        /**<Satellite transmission signal*/     /**<CNcomment:\CE\C0\D0Ǵ\AB\CA\E4\D0ź\C5*/
    } unConnectPara;
} HI_UNF_TUNER_CONNECT_PARA_S ;

/** Frequency locking status and parameters of the tuner*/
/** CNcomment:TUNER\CB\F8Ƶ״̬\BA\CD\CB\F8Ƶ\B2\CE\CA\FD*/
typedef struct  hiUNF_TUNER_STATUS_S
{
    HI_UNF_TUNER_LOCK_STATUS_E  enLockStatus ;  /**<Frequency locking status*/               /**<CNcomment:\CB\F8Ƶ״̬*/
    HI_UNF_TUNER_CONNECT_PARA_S stConnectPara;  /**<Actual frequency locking parameters*/    /**<CNcomment:ʵ\BC\CA\CB\F8Ƶ\B2\CE\CA\FD*/
} HI_UNF_TUNER_STATUS_S;

/** Tuner blind scan type*/
/** CNcomment:TUNERäɨ\B7\BDʽ*/
typedef enum hiUNF_TUNER_BLINDSCAN_MODE_E
{
    HI_UNF_TUNER_BLINDSCAN_MODE_AUTO = 0,       /**<Blind scan automatically*/  /**<CNcomment:\D7Զ\AFɨ\C3\E8*/
    HI_UNF_TUNER_BLINDSCAN_MODE_MANUAL,         /**<Blind scan manually*/       /**<CNcomment:\CAֶ\AFɨ\C3\E8*/
    HI_UNF_TUNER_BLINDSCAN_MODE_BUTT            /**<Invalid value*/             /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_BLINDSCAN_MODE_E;

/** Definition of blind scan event type*/
/** CNcomment:TUNERäɨ\CA¼\FE*/
typedef enum hiUNF_TUNER_BLINDSCAN_EVT_E
{
    HI_UNF_TUNER_BLINDSCAN_EVT_STATUS,          /**<New status*/        /**<CNcomment:״̬\B1仯*/
    HI_UNF_TUNER_BLINDSCAN_EVT_PROGRESS,        /**<New Porgress */     /**<CNcomment:\BD\F8\B6ȱ仯*/
    HI_UNF_TUNER_BLINDSCAN_EVT_NEWRESULT,       /**<Find new channel*/  /**<CNcomment:\D0\C2Ƶ\B5\E3*/
    HI_UNF_TUNER_BLINDSCAN_EVT_BUTT             /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_BLINDSCAN_EVT_E;

/** Definition of tuner blind scan status*/
/** CNcomment:TUNERäɨ״̬*/
typedef enum hiUNF_TUNER_BLINDSCAN_STATUS_E
{
    HI_UNF_TUNER_BLINDSCAN_STATUS_IDLE,         /**<Idel*/              /**<CNcomment:\BF\D5\CF\D0*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_SCANNING,     /**<Scanning*/          /**<CNcomment:ɨ\C3\E8\D6\D0*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_FINISH,       /**<Finish*/            /**<CNcomment:\B3ɹ\A6\CD\EA\B3\C9*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_QUIT,         /**<User quit*/         /**<CNcomment:\D3û\A7\CD˳\F6*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_FAIL,         /**<Scan fail*/         /**<CNcomment:ɨ\C3\E8ʧ\B0\DC*/
    HI_UNF_TUNER_BLINDSCAN_STATUS_BUTT          /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_BLINDSCAN_STATUS_E;

typedef enum hiUNF_TUNER_UNICABLE_SCAN_STATUS_E
{
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_IDLE,         /**<Idel*/              /**<CNcomment:\BF\D5\CF\D0*/
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_SCANNING,     /**<Scanning*/          /**<CNcomment:ɨ\C3\E8\D6\D0*/
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_FINISH,       /**<Finish*/            /**<CNcomment:\B3ɹ\A6\CD\EA\B3\C9*/
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_QUIT,         /**<User quit*/         /**<CNcomment:\D3û\A7\CD˳\F6*/
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_FAIL,         /**<Scan fail*/         /**<CNcomment:ɨ\C3\E8ʧ\B0\DC*/
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_BUTT          /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_UNICABLE_SCAN_STATUS_E;

/** Structure of satellite TP*/
/** CNcomment:TUNERɨ\B3\F6TP\D0\C5Ϣ*/
typedef struct  hiUNF_TUNER_SAT_TPINFO_S
{
    HI_U32                          u32Freq;            /**<Downlink frequency, in kHz*/    /**<CNcomment:\CF\C2\D0\D0Ƶ\C2ʣ\AC\B5\A5λ\A3\BAkHz*/
    HI_U32                          u32SymbolRate;      /**<Symbol rate, in bit/s*/         /**<CNcomment:\B7\FB\BA\C5\C2ʣ\AC\B5\A5λbps */
    HI_UNF_TUNER_FE_POLARIZATION_E  enPolar;            /**<Polarization type*/             /**<CNcomment:\BC\AB\BB\AF\B7\BDʽ*/
    HI_U8                           cbs_reliablity;     /**<TP reliability*/                /**<CNcomment:TP\B5Ŀɿ\BF\B6\C8*/
} HI_UNF_TUNER_SAT_TPINFO_S;

/** Structure of terrestrial tp information*/
/** CNcomment:\B5\D8\C3\E6\BB\FAƵ\B5\E3\D0\C5Ϣ*/
typedef struct hiUNF_TUNER_TER_CHANNEL_ATTR_S
{
    HI_U32 u32Frequency;        /**<frequency of TP,unit KHz*/                /**<CNcomment:Ƶ\B5\E3\B5\C4Ƶ\C2ʣ\AC\B5\A5λ\CA\C7KHz*/
    HI_U32 u32BandWidth;        /**<BandWidth of TP,unit KHz*/                /**<CNcomment:Ƶ\B5\E3\B5Ĵ\F8\BF\ED\A3\AC\B5\A5λ\CA\C7KHz*/
    HI_U8  u8DVBTMode;          /**<signal type.0--DVB-T2,1--DVB-T*/          /**<CNcomment:\D0ź\C5\C0\E0\D0\CD.0--DVB-T2,1--DVB-T*/
    HI_U8  u8PlpIndex;          /**<plp index*/                               /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CB\F7\D2\FD\BA\C5*/
    HI_U8  u8PlpId;             /**<plp id*/                                  /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0ID*/
    HI_U8  u8CommId;            /**<common plp id*/                           /**<CNcomment:\B9\B2\CF\ED\CE\EF\C0\ED\B2\E3\B9ܵ\C0ID*/
    HI_U8  u8Combination;       /**<plp combination flag*/                    /**<CNcomment:\CA\FD\BE\DD\CE\EF\C0\ED\B2\E3\B9ܵ\C0\BA͹\B2\CF\ED\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CAǷ\F1\D7\E9\BAϱ\EA־*/
    HI_UNF_TUNER_TER_MODE_E     enChannelMode;  /**<channel attribute*/             /**<CNcomment:ͨ\B5\C0\CA\F4\D0\D4*/
    HI_UNF_TUNER_TS_PRIORITY_E  enTSPri;        /**<TS priority, only in DVB-T*/    /**<CNcomment:TS\D3\C5\CFȼ\B6ģʽ\A3\AC\BD\F6\D3\C3\D3\DADVB-T*/
} HI_UNF_TUNER_TER_CHANNEL_ATTR_S;

/** Notify structure of tuner blind scan */
/** CNcomment:TUNERäɨ֪ͨ\D0\C5Ϣ*/
typedef union hiUNF_TUNER_BLINDSCAN_NOTIFY_U
{
    HI_UNF_TUNER_BLINDSCAN_STATUS_E* penStatus;             /**<Scanning status*/            /**<CNcomment:äɨ״̬*/
    HI_U16*                          pu16ProgressPercent;   /**<Scanning progress*/          /**<CNcomment:äɨ\BD\F8\B6\C8*/
    HI_UNF_TUNER_SAT_TPINFO_S* pstResult;                   /**<Scanning result*/            /**<CNcomment:äɨ\BD\E1\B9\FB*/
} HI_UNF_TUNER_BLINDSCAN_NOTIFY_U;

/** Parameter of the satellite tuner blind scan */
/** CNcomment:\CE\C0\D0\C7TUNERäɨ\B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_SAT_BLINDSCAN_PARA_S
{
    /**<LNB Polarization type, only take effect in manual blind scan mode*/
    /**<CNcomment:LNB\BC\AB\BB\AF\B7\BDʽ\A3\AC\D7Զ\AFɨ\C3\E8ģʽ\C9\E8\D6\C3\CE\DEЧ*/
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar;

    /**<LNB 22K signal status, for Ku band LNB which has dual LO, 22K ON will select high LO and 22K off select low LO,
        only take effect in manual blind scan mode*/
    /**<CNcomment:LNB 22K״̬\A3\AC\B6\D4\D3\DAKu\B2\A8\B6\CE˫\B1\BE\D5\F1LNB\A3\ACONѡ\D4\F1\B8߱\BE\D5\F1\A3\ACOFFѡ\D4\F1\B5ͱ\BE\D5\F1\A3\AC\D7Զ\AFɨ\C3\E8ģʽ\C9\E8\D6\C3\CE\DEЧ*/
    HI_UNF_TUNER_FE_LNB_22K_E      enLNB22K;

    /**<Blind scan start IF, in kHz, only take effect in manual blind scan mode */
    /**<CNcomment:äɨ\C6\F0ʼƵ\C2\CA(\D6\D0Ƶ)\A3\AC\B5\A5λ\A3\BAkHz\A3\AC\D7Զ\AFɨ\C3\E8ģʽ\C9\E8\D6\C3\CE\DEЧ*/
    HI_U32                         u32StartFreq;

    /**<Blind scan stop IF, in kHz, only take effect in manual blind scan mode */
    /**<CNcomment:äɨ\BD\E1\CA\F8Ƶ\C2\CA(\D6\D0Ƶ)\A3\AC\B5\A5λ\A3\BAkHz\A3\AC\D7Զ\AFɨ\C3\E8ģʽ\C9\E8\D6\C3\CE\DEЧ*/
    HI_U32                         u32StopFreq;

    /**<The execution of the blind scan may change the 13/18V or 22K status.
        If you use any DiSEqC device which need send command when 13/18V or 22K status change,
        you should registe a callback here. Otherwise, you can set NULL here.*/
    /**<CNcomment:äɨ\B9\FD\B3̿\C9\C4ܻ\E1\C7л\BB\BC\AB\BB\AF\B7\BDʽ\BA\CD22K\A3\AC\C8\E7\B9\FB\C4\E3\D3\C3\C1\CBĳЩDiSEqC\C9豸\D0\E8Ҫ\C9\E8\D6\C313/18V\BA\CD22K\B5ģ\AC
        \C7\EBע\B2\E1\D5\E2\B8\F6\BBص\F7\A3\AC\C8\E7\B9\FBû\D3\D0\D3ã\AC\C7\EB\BFɴ\ABNULL */
    HI_VOID (*pfnDISEQCSet)(HI_U32 u32TunerId, HI_UNF_TUNER_FE_POLARIZATION_E enPolar,
                            HI_UNF_TUNER_FE_LNB_22K_E enLNB22K);

    /**<Callback when scan status change, scan progress change or find new channel.*/
    /**<CNcomment:ɨ\C3\E8״̬\BB\F2\BD\F8\B6Ȱٷֱȷ\A2\C9\FA\B1仯ʱ\A1\A2\B7\A2\CF\D6\D0µ\C4Ƶ\B5\E3ʱ\BBص\F7*/
    HI_VOID (*pfnEVTNotify)(HI_U32 u32TunerId, HI_UNF_TUNER_BLINDSCAN_EVT_E enEVT, HI_UNF_TUNER_BLINDSCAN_NOTIFY_U * punNotify);
} HI_UNF_TUNER_SAT_BLINDSCAN_PARA_S;

typedef enum hiUNF_TUNER_UNICABLE_SCAN_USER_BAND_EVT_E
{
    HI_UNF_TUNER_UNICABLE_SCAN_EVT_STATUS,          /**<New status*/        /**<CNcomment:״̬\B1仯*/
    HI_UNF_TUNER_UNICABLE_SCAN_EVT_PROGRESS,        /**<New Porgress */     /**<CNcomment:\BD\F8\B6ȱ仯*/
    HI_UNF_TUNER_UNICABLE_SCAN_EVT_BUTT             /**<Invalid value*/     /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_UNICABLE_SCAN_USER_BAND_EVT_E;

typedef union hiUNF_TUNER_UNICABLE_SCAN_USER_BAND_NOTIFY_S
{
    HI_UNF_TUNER_UNICABLE_SCAN_STATUS_E* penStatus;         /**<Scanning status*/   /**<CNcomment:äɨ״̬*/
    HI_U16*                          pu16ProgressPercent;   /**<Scanning progress*/ /**<CNcomment:äɨ\BD\F8\B6\C8*/
} HI_UNF_TUNER_UNICABLE_SCAN_USER_BAND_NOTIFY_S;

/** Structure of terrestrial scan*/
/** CNcomment:\C5\E4\D6\C3TUNERɨ\C3\E8DVB-T/T2\D0ź\C5*/
typedef struct hiUNF_TUNER_UNICABLE_SCAN_PARA_S
{
    HI_VOID (*pfnEVTNotify)(HI_U32 u32TunerId, HI_UNF_TUNER_UNICABLE_SCAN_USER_BAND_EVT_E enEVT, HI_UNF_TUNER_UNICABLE_SCAN_USER_BAND_NOTIFY_S *pNotify);
} HI_UNF_TUNER_UNICABLE_SCAN_PARA_S;

/** Parameter of the tuner blind scan */
/** CNcomment:TUNERäɨ\B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_BLINDSCAN_PARA_S
{
    HI_UNF_TUNER_BLINDSCAN_MODE_E enMode;            /**<Scanning mode*/            /**<CNcomment:äɨģʽ*/
    union
    {
        HI_UNF_TUNER_SAT_BLINDSCAN_PARA_S stSat;    /**<Scanning parameter*/        /**<CNcomment:äɨ\B2\CE\CA\FD*/
    } unScanPara;
} HI_UNF_TUNER_BLINDSCAN_PARA_S;

/** PLP information */
/** CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\D0\C5Ϣ*/
typedef struct hiUNF_TUNER_TER_PLP_INFO_S
{
    HI_U8                       u8PlpId;            /**<PLP id*/                /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0ID*/
    HI_U8                       u8PlpGrpId;         /**<PLP group id*/          /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\D7\E9ID*/
    HI_UNF_TUNER_T2_PLP_TYPE_E  enPlpType;          /**<PLP type*/              /**<CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\C0\E0\D0\CD*/
} HI_UNF_TUNER_TER_PLP_INFO_S;

/** DiSEqC Level*/
/** CNcomment:DiSEqC\C9豸\B0汾*/
typedef enum hiUNF_TUNER_DISEQC_LEVEL_E
{
    HI_UNF_TUNER_DISEQC_LEVEL_1_X,      /**<1.x, one way*/                  /**<CNcomment:1.x\A3\AC\B5\A5\CF\F2 */
    HI_UNF_TUNER_DISEQC_LEVEL_2_X,      /**<2.x, two way, support reply*/   /**<CNcomment:2.x\A3\AC˫\CF\F2\A3\AC֧\B3\D6Reply*/
    HI_UNF_TUNER_DISEQC_LEVEL_BUTT      /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_LEVEL_E;

/** Receive status of DiSEqC reply massage*/
/** CNcomment:DiSEqC\CF\FBϢ\BD\D3\CA\D5״̬*/
typedef enum hiUNF_TUNER_DISEQC_RECV_STATUS_E
{
    HI_UNF_TUNER_DISEQC_RECV_OK,        /**<Receive successfully*/          /**<CNcomment:\BD\D3\CAճɹ\A6*/
    HI_UNF_TUNER_DISEQC_RECV_UNSUPPORT, /**<Device don't support reply*/    /**<CNcomment:\C9豸\B2\BB֧\B3ֻش\AB*/
    HI_UNF_TUNER_DISEQC_RECV_TIMEOUT,   /**<Receive timeout*/               /**<CNcomment:\BD\D3\CAճ\ACʱ*/
    HI_UNF_TUNER_DISEQC_RECV_ERROR,     /**<Receive fail*/                  /**<CNcomment:\BD\D3\CAճ\F6\B4\ED*/
    HI_UNF_TUNER_DISEQC_RECV_BUTT       /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_RECV_STATUS_E;

/** Structure of the DiSEqC send massage */
/** CNcomment:DiSEqC\B7\A2\CB\CD\CF\FBϢ\BDṹ*/
typedef struct hiUNF_TUNER_DISEQC_SENDMSG_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E     enLevel;        /**<Device level*/                         /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_SWITCH_TONEBURST_E enToneBurst;    /**<Tone Burst */                          /**<CNcomment:tone\D0ź\C5״̬*/
    HI_U8                           au8Msg[HI_UNF_DISEQC_MSG_MAX_LENGTH]; /**<Message data*/   /**<CNcomment:\CF\FBϢ\D7\D6*/
    HI_U8                           u8Length;       /**<Message length*/                       /**<CNcomment:\D0\C5Ϣ\B3\A4\B6\C8*/
    HI_U8                           u8RepeatTimes;  /**<Message repeat times*/                 /**<CNcomment:\D6ش\AB\B4\CE\CA\FD*/
} HI_UNF_TUNER_DISEQC_SENDMSG_S;

/** Structure of the DiSEqC reply massage */
/** CNcomment:DiSEqC\BD\D3\CA\D5\CF\FBϢ\BDṹ*/
typedef struct hiUNF_TUNER_DISEQC_RECVMSG_S
{
    HI_UNF_TUNER_DISEQC_RECV_STATUS_E enStatus;     /**<Recieve status*/                                 /**<CNcomment:\BD\D3\CA\D5״̬*/
    HI_U8                             au8Msg[HI_UNF_DISEQC_MSG_MAX_LENGTH]; /**<Recieve message data*/   /**<CNcomment:\BD\D3\CA\D5\CA\FD\BEݻ\BA\B4\E6*/
    HI_U8                             u8Length;     /**<Recieve message length*/                         /**<CNcomment:\BD\D3\CA\D5\CA\FD\BEݳ\A4\B6\C8*/
} HI_UNF_TUNER_DISEQC_RECVMSG_S;

typedef struct hiUNF_TUNER_SCR_UB_S
{
    HI_U32          u32SCRNo;
    HI_S32          s32CenterFreq;      /**<Unit MHz*/
}HI_UNF_TUNER_SCR_UB_S;

/** DiSEqC Switch port*/
/** CNcomment:DiSEqC\BF\AA\B9ض˿\DAö\BE\D9*/
typedef enum hiUNF_TUNER_DISEQC_SWITCH_PORT_E
{
    HI_UNF_TUNER_DISEQC_SWITCH_NONE = 0,         /**<none*/                                 /**<CNcomment:\B2\BB\BDӿ\AA\B9\D8*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_1,           /**<port1*/                                /**<CNcomment:\B6˿\DA1*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_2,           /**<port2*/                                /**<CNcomment:\B6˿\DA2*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_3,           /**<port3*/                                /**<CNcomment:\B6˿\DA3*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_4,           /**<port4*/                                /**<CNcomment:\B6˿\DA4*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_5,           /**<port5*/                                /**<CNcomment:\B6˿\DA5*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_6,           /**<port6*/                                /**<CNcomment:\B6˿\DA6*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_7,           /**<port7*/                                /**<CNcomment:\B6˿\DA7*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_8,           /**<port8*/                                /**<CNcomment:\B6˿\DA8*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_9,           /**<port9*/                                /**<CNcomment:\B6˿\DA9*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_10,          /**<port10*/                               /**<CNcomment:\B6˿\DA10*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_11,          /**<port11*/                               /**<CNcomment:\B6˿\DA11*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_12,          /**<port12*/                               /**<CNcomment:\B6˿\DA12*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_13,          /**<port13*/                               /**<CNcomment:\B6˿\DA13*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_14,          /**<port14*/                               /**<CNcomment:\B6˿\DA14*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_15,          /**<port15*/                               /**<CNcomment:\B6˿\DA15*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_16,          /**<port16*/                               /**<CNcomment:\B6˿\DA16*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_BUTT         /**<Invalid value*/                        /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_SWITCH_PORT_E;

/** Parameter for DiSEqC 1.0/2.0 switch
   Some DiSEqC device need set polarization(13/18V) and 22K, you can set them here. */
/** CNcomment:DiSEqC 1.0/2.0 \BF\AA\B9ز\CE\CA\FD
   \D3\D0ЩDiSEqC\C9豸\D0\E8Ҫ\C9\E8\D6ü\AB\BB\AF\B7\BDʽ\BA\CD22K\B5ģ\AC\C8\E7\B9\FB\D3\C3\C1\CB\D5\E2\D6\D6\C9豸\A3\AC\D0\E8Ҫ\D4\DA\D5\E2\C0\EF\C9\E8\D6\C3 */
typedef struct hiUNF_TUNER_DISEQC_SWITCH4PORT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E       enLevel;  /**<DiSEqC device level*/           /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_E enPort;   /**<DiSEqC switch port*/            /**<CNcomment:ѡͨ\B6˿ں\C5*/
    HI_UNF_TUNER_FE_POLARIZATION_E    enPolar;  /**<Polarization type */            /**<CNcomment:\BC\AB\BB\AF\B7\BDʽ*/
    HI_UNF_TUNER_FE_LNB_22K_E         enLNB22K; /**<22K status*/                    /**<CNcomment:22k״̬*/
} HI_UNF_TUNER_DISEQC_SWITCH4PORT_S;

/** Parameter for DiSEqC 1.1/2.1 switch */
/** CNcomment:DiSEqC 1.1/2.1 \BF\AA\B9ز\CE\CA\FD */
typedef struct hiUNF_TUNER_DISEQC_SWITCH16PORT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E       enLevel;  /**<DiSEqC device level*/            /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_DISEQC_SWITCH_PORT_E enPort;   /**<DiSEqC switch port*/             /**<CNcomment:ѡͨ\B6˿ں\C5*/
} HI_UNF_TUNER_DISEQC_SWITCH16PORT_S;

/** DiSEqC motor limit setting*/
/** CNcomment:DiSEqC\C2\ED\B4Ｋ\CF\DE\C9\E8\D6\C3*/
typedef enum hiUNF_TUNER_DISEQC_LIMIT_E
{
    HI_UNF_TUNER_DISEQC_LIMIT_OFF,              /**<Disable Limits*/                /**<CNcomment:\CE\DE\CF\DE\D6\C6*/
    HI_UNF_TUNER_DISEQC_LIMIT_EAST,             /**<Set East Limit*/                /**<CNcomment:\B6\AB\CF\F2\CF\DE\D6\C6*/
    HI_UNF_TUNER_DISEQC_LIMIT_WEST,             /**<Set West Limit*/                /**<CNcomment:\CE\F7\CF\F2\CF\DE\D6\C6*/
    HI_UNF_TUNER_DISEQC_LIMIT_BUTT              /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_LIMIT_E;

/** Difinition of DiSEqC motor move direction*/
/** CNcomment:DiSEqC\C2\ED\B4\EF\D2ƶ\AF\B7\BD\CF\F2*/
typedef enum hiUNF_TUNER_DISEQC_MOVE_DIR_E
{
    HI_UNF_TUNER_DISEQC_MOVE_DIR_EAST,          /**<Move east*/                     /**<CNcomment:\CF\F2\B6\AB\D2ƶ\AF*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_WEST,          /**<Move west*/                     /**<CNcomment:\CF\F2\CE\F7\D2ƶ\AF*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_BUTT           /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_MOVE_DIR_E;

/** Difinition of DiSEqC motor move type*/
/** CNcomment:DiSEqC\C2\ED\B4\EF\D2ƶ\AF\B7\BDʽ*/
typedef enum hiUNF_TUNER_DISEQC_MOVE_TYPE_E
{
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW,         /**<1 step one time, default*/      /**<CNcomment:ÿ\B4\CEת\B6\AF1 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW1,        /**<2 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF2 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW2,        /**<3 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF3 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW3,        /**<4 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF4 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_SLOW4,        /**<5 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF5 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST,         /**<6 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF6 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST1,        /**<7 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF7 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST2,        /**<8 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF8 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST3,        /**<9 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF9 step*/
    HI_UNF_TUNER_DISEQC_MOVE_STEP_FAST4,        /**<10 step one time*/               /**<CNcomment:ÿ\B4\CEת\B6\AF10 step*/
    HI_UNF_TUNER_DISEQC_MOVE_CONTINUE,          /**<Continuous moving*/             /**<CNcomment:\C1\AC\D0\F8\D2ƶ\AF*/
    HI_UNF_TUNER_DISEQC_MOVE_TYPE_BUTT          /**<Invalid value*/                 /**<CNcomment:\B7Ƿ\A8\B1߽\E7ֵ*/
} HI_UNF_TUNER_DISEQC_MOVE_TYPE_E;

/** Parameter for DiSEqC motor store position*/
/** CNcomment:\CC\EC\CFߴ洢λ\D6ò\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_POSITION_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/               /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_U32                      u32Pos;         /**<Index of position, 0-255*/          /**<CNcomment:λ\D6\C3\D0\F2\BA\C5*/
} HI_UNF_TUNER_DISEQC_POSITION_S;

/** Parameter for DiSEqC motor limit setting*/
/** CNcomment:\CC\EC\CF\DFLimit\C9\E8\D6ò\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_LIMIT_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/               /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_DISEQC_LIMIT_E enLimit;        /**<Limit setting*/                     /**<CNcomment:\CF\DE\D6\C6\C9趨*/
} HI_UNF_TUNER_DISEQC_LIMIT_S;

/** Parameter for DiSEqC motor moving*/
/** CNcomment:DiSEqC\C2\ED\B4\EF\D2ƶ\AF\B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_MOVE_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E     enLevel;    /**<DiSEqC device level*/           /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_E  enDir;      /**<Moving direction*/              /**<CNcomment:\D2ƶ\AF\B7\BD\CF\F2*/
    HI_UNF_TUNER_DISEQC_MOVE_TYPE_E enType;     /**<Moving type*/                   /**<CNcomment:\D2ƶ\AF\C0\E0\D0\CD(\C2\FD\CB٣\AC\BF\EC\CB٣\AC\C1\AC\D0\F8)*/
} HI_UNF_TUNER_DISEQC_MOVE_S;

/** Parameter for DiSEqC motor running*/
/** CNcomment:DiSEqC\C2\ED\B4\EFת\B6\AF\B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_RUN_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E     enLevel;    /**<DiSEqC device level*/           /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_UNF_TUNER_DISEQC_MOVE_DIR_E  enDir;      /**<Moving direction*/              /**<CNcomment:ת\B6\AF\B7\BD\CF\F2*/
    HI_U32                          u32RunningSteps;        /**<0 mean running continus;1~128 mean running steps every time.*/
                                                            /**<CNcomment:0\B1\EDʾ\B3\D6\D0\F8ת\B6\AF\A3\BB1~128֮\BC\E4\B1\EDʾÿ\B4\CEת\B6\AFstep\CA\FD\A3\AC*/
} HI_UNF_TUNER_DISEQC_RUN_S;

/** Parameter for DiSEqC motor recalculate*/
/** CNcomment:DiSEqC\CC\EC\CF\DF\D6ؼ\C6\CB\E3\B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_RECALCULATE_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/           /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_U8                       u8Para1;        /**<Parameter 1*/                   /**<CNcomment:\B2\CE\CA\FD1*/
    HI_U8                       u8Para2;        /**<Parameter 2*/                   /**<CNcomment:\B2\CE\CA\FD2*/
    HI_U8                       u8Para3;        /**<Parameter 3*/                   /**<CNcomment:\B2\CE\CA\FD3*/
    HI_U8                       u8Reserve;      /**<Reserve*/                       /**<CNcomment:\B1\A3\C1\F4\B2\CE\CA\FD*/
} HI_UNF_TUNER_DISEQC_RECALCULATE_S;

/** Parameter for USALS*/
/** CNcomment:USALS \B2\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_USALS_PARA_S
{
    HI_U16 u16LocalLongitude;   /**<local longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude)*/
                                /**<CNcomment:\B1\BE\B5ؾ\AD\B6ȣ\AC\B5\A5λ0.1\B6ȣ\AC\B6\AB\BE\ADȡֵ\B7\B6Χ0-1800\A3\AC\CE\F7\BE\ADȡֵ\B7\B6Χ1800-3600\A3\ACֵΪ3600-\BE\AD\B6\C8ֵ*/
    HI_U16 u16LocalLatitude;    /**<local latitude, is 10*latitude, in param N:0-900, S:900-1800(1800-latitude)*/
                                /**<CNcomment:\B1\BE\B5\D8γ\B6ȣ\AC\B5\A5λ0.1\B6ȣ\AC\B1\B1γȡֵ\B7\B6Χ0-900\A3\AC\C4\CFγȡֵ\B7\B6Χ900-1800\A3\ACֵΪ1800-γ\B6\C8ֵ*/
    HI_U16 u16SatLongitude;     /**<sat longitude, is 10*longitude, in param, E:0-1800, W:1800-3600(3600-longtitude)*/
                                /**<CNcomment:\CE\C0\D0Ǿ\AD\B6ȣ\AC\B5\A5λ0.1\B6ȣ\AC\B6\AB\BE\ADȡֵ\B7\B6Χ0-1800\A3\AC\CE\F7\BE\ADȡֵ\B7\B6Χ1800-3600\A3\ACֵΪ3600-\BE\AD\B6\C8ֵ*/
    HI_U16 u16Angular;          /**<calculate result, out param*/
                                /**<CNcomment:\BC\C6\CB\E3\BD\E1\B9\FB\A3\AC\CA\E4\B3\F6\B2\CE\CA\FD*/
} HI_UNF_TUNER_DISEQC_USALS_PARA_S;

/** Parameter for USALS goto angular*/
/** CNcomment:USALS\BDǶȲ\CE\CA\FD*/
typedef struct hiUNF_TUNER_DISEQC_USALS_ANGULAR_S
{
    HI_UNF_TUNER_DISEQC_LEVEL_E enLevel;        /**<DiSEqC device level*/                                       /**<CNcomment:\C6\F7\BC\FE\B0汾*/
    HI_U16                      u16Angular;     /**<Angular, calculated by HI_UNF_TUNER_DISEQC_CalcAngular()*/  /**<CNcomment:\BDǶ\C8ֵ\A3\AC\BF\C9ͨ\B9\FD\BA\AF\CA\FDHI_UNF_TUNER_DISEQC_CalcAngular\BC\C6\CB\E3\B5õ\BD*/
} HI_UNF_TUNER_DISEQC_USALS_ANGULAR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */


/******************************* API Declaration *****************************/
/** \addtogroup      FRONTEND */
/** @{ */  /** <!-- [FRONTEND] */
/*---TUNER---*/
/**
\brief Initializes the tuner.
CNcomment:\brief \B3\F5ʼ\BB\AFTUNER\C9豸\A1\A3CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:֧\B3\D6\D6ظ\B4\B3\F5ʼ\BB\AFTUNER\C9豸\A3\AC\B4\CBʱֱ\BDӷ\B5\BBسɹ\A6\A1\A3CNend
\param N/A                                    CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Init(HI_VOID);


/**
\brief Deinitializes the tuner.
CNcomment:\brief ȥ\B3\F5ʼ\BB\AFTUNER\C9豸\A1\A3CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:֧\B3\D6\D6ظ\B4ȥ\B3\F5ʼ\BB\AFTUNER\C9豸\A3\AC\B4\CBʱֱ\BDӷ\B5\BBسɹ\A6\A1\A3CNend
\param  N/A                    CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DeInit(HI_VOID);

/**
\brief  Obtains the default attributes of the tuner.
CNcomment:\brief  \BB\F1ȡTUNER\B5\C4Ĭ\C8\CF\CA\F4\D0ԡ\A3CNend
\attention \n
This API is available only after the tuner is initialized.
CNcomment:\B4˽ӿ\DA\D4\DATUNER\C9豸\B3\F5ʼ\BB\AF\BA\F3\B2\C5\C4\DCʹ\D3á\A3CNend
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2\A1\A3CNend
\param[out] pstTunerAttr The default attributes of the tuner are returned. CNcomment:\B7\B5\BBص\B1ǰTUNER\B5\C4Ĭ\C8\CF\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success.                                      CNcomment: \B3ɹ\A6 CNend
\retval ::HI_FAILURE Calling this API fails.                                               CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_INIT  The Frontend module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AFCNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EBPORT \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EBPORT \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetDeftAttr(HI_U32  u32tunerId , HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/**
\brief Sets the current attributes of the tuner.
CNcomment:\brief \C9\E8\D6\C3TUNER\B5\B1ǰ\CA\F4\D0ԡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstTunerAttr tuner attributes                            CNcomment:TUNER\B5\C4\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SELECTI2CCHANNEL The input I2C channel is invalid. CNcomment:\CA\E4\C8\EBI2C ͨ\B5\C0\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetAttr(HI_U32  u32tunerId , const HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/**
\brief While using satellite channel, sets the current attributes of the tuner.
CNcomment:\brief \C9\E8\D6\C3\CE\C0\D0\C7TUNER\B8\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:\CE\C0\D0\C7TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstSatTunerAttr tuner attributes                         CNcomment:\CE\C0\D0\C7TUNER\B5ĸ\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETSATATTR Tuner TUNER_SETDEMODATTR_CMD error. CNcomment:\C9\E8\D6\C3\CA\F4\D0\D4ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetSatAttr(HI_U32   u32tunerId , const HI_UNF_TUNER_SAT_ATTR_S *pstSatTunerAttr);

/**
\brief While using terrestrial channel, sets the current attributes of the tuner.
CNcomment:\brief \C9\E8\D6õ\D8\C3\E6TUNER\B8\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:\B5\D8\C3\E6TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstTerTunerAttr tuner attributes                         CNcomment:\B5\D8\C3\E6TUNER\B5ĸ\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETTERATTR Tuner TUNER_SETDEMODATTR_CMD error. CNcomment:\C9\E8\D6\C3\CA\F4\D0\D4ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetTerAttr(HI_U32   u32tunerId , const HI_UNF_TUNER_TER_ATTR_S *pstTerTunerAttr);

/**
\brief While using cable channel, sets the current attributes of the tuner.
CNcomment:\brief \C9\E8\D6\C3\D3\D0\CF\DFTUNER\B8\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:\B5\D8\C3\E6TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstTerTunerAttr tuner attributes                         CNcomment:\B5\D8\C3\E6TUNER\B5ĸ\BD\BC\D3\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                       CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETTERATTR Tuner TUNER_SETDEMODATTR_CMD error. CNcomment:\C9\E8\D6\C3\CA\F4\D0\D4ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetCabAttr(HI_U32   u32tunerId , const HI_UNF_TUNER_CAB_ATTR_S *pstTerTunerAttr);

/**
\brief Obtains the attributes of the tuner.
CNcomment:\brief \BB\F1ȡTUNER\B5\C4\CA\F4\D0ԡ\A3CNend
\attention \n
N/A
This API is available only after the tuner is initialized.
CNcomment:\B4˽ӿ\DA\D4\DATUNER\C9豸\B3\F5ʼ\BB\AF\BA\F3\B2\C5\C4\DCʹ\D3á\A3CNend

\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.                CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pstTunerAttr   The current attributes of the tuner are returned. CNcomment:\B7\B5\BBص\B1ǰTUNER\B5\C4\CA\F4\D0ԡ\A3CNend
\retval ::HI_SUCCESS Success                                                 CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                                CNcomment: APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_INIT  The TUNER module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AFCNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetAttr(HI_U32  u32tunerId , HI_UNF_TUNER_ATTR_S *pstTunerAttr );


/**
\brief Starts the tuner.
CNcomment:\brief \B4\F2\BF\AATUNER\C9豸\A1\A3CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:֧\B3\D6\D6ظ\B4\B4\F2\BF\AATUNER\C9豸\A1\A3\B4\CBʱ\A3\ACֱ\BDӷ\B5\BBسɹ\A6\A1\A3CNend

\param[in] u32tunerId   tuner port ID. The port ID can be 0-2.      CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_INIT  The TUNER module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AFCNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_INIT  Opening The TUNER module  fails. CNcomment:\B4\F2\BF\AA\C9豸ʧ\B0\DCCNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Open (HI_U32    u32tunerId);


/**
\brief Stops the tuner.
CNcomment:\brief \B9ر\D5TUNER\C9豸\A1\A3CNend

\attention \n
The error code HI_SUCCESS is returned if this API is called repeatedly.
CNcomment:֧\B3\D6\D6ظ\B4\B9ر\D5TUNER\C9豸\A1\A3\B4\CBʱ\A3\ACֱ\BDӷ\B5\BBسɹ\A6\A1\A3CNend

\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.     CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS Success                                      CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                     CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_INIT  The TUNER module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AFCNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Close(HI_U32    u32tunerId);


/**
\brief Locks the frequency of the tuner.
CNcomment:\brief TUNER\CB\F8Ƶ\A1\A3CNend
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstConnectPara   Information about the frequency of the tuner  CNcomment:TUNER\B5\C4Ƶ\B5\E3\D0\C5Ϣ\A1\A3CNend
\param[in] u32TimeOut  Wait timeout (in ms) when the frequency of the tuner \n
is locked. The value 0 indicates no wait, and any other value indicates the \n
maximum wait period.
                                                                          CNcomment:TUNER\B5\C4\CB\F8\B6\A8\B5ȴ\FD\B3\ACʱʱ\BC䣬0Ϊ\B2\BB\B5ȴ\FD\A3\AC\C6\E4\CB\FBΪ\D7\B5ȴ\FDʱ\BC䣬\B5\A5λms\A1\A3CNend
\retval ::HI_SUCCESS Success                                              CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                             CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_CONNECT The signal is locked unsuccessfully . CNcomment:\CB\F8\B6\A8Ƶ\B5\E3ʧ\B0\DCCNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Connect(HI_U32  u32tunerId , const HI_UNF_TUNER_CONNECT_PARA_S  *pstConnectPara,HI_U32 u32TimeOut);


/**
\brief  set TS out.CNcomment:\C9\E8\D6\C3TS\CA\E4\B3\F6 CNend
\attention \n
\Please call this API to set TS out. \n
\There are 12 signals in ts interface, ts_dat[0..7], ts_sync, ts_vld, ts_err, ts_clk.\n
\There're 12 pins in HI3136 or HI3130v200 chip, and each pin can be set to output ts_dat[0..7], ts_sync,\n
\ts_vld or ts_err, but ts_clk is binded to one pin, cannot be setted.\n
CNcomment:ts\BDӿڹ\B2\D3\D012\B8\F9\D0ź\C5\CFߣ\AC\B7ֱ\F0\CA\C7ts_dat[0..7], ts_sync, ts_vld, ts_err, ts_clk\A3\ACHI3136/HI3130V200 оƬ\C9\CF\D3\D012\B8\F6ts\B9ܽţ\ACÿ\B8\F6\B9ܽſ\C9\D2\D4\n
\C5\E4\D6óɳ\FDts_clk֮\CD\E2\B5\C4\C8\CE\D2\E2һ\B8\F6\B9ܽţ\ACts_clk\CAǹ̶\A8\B5ģ\AC\B2\BB֧\B3\D6\C5\E4\D6á\A3\C6\E4\D6\D0pstTSOUT->enTSOutput[0..7]\A3\AC\B6\D4ӦоƬTS_OUT0..TS_OUT7\B9ܽ\C5;\n
pstTSOUT->enTSOutput[8..10]\A3\AC\B6\D4ӦоƬTS_SYNC,TS_VALID,TS_ERR\B9ܽš\A3CNend

\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstTSOUT   pointer of ts pin.                                  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACts\B9ܽŶ\A8\D2壬\C7\EB\B2μ\FB::HI_UNF_TUNER_TSOUT_SET_S CNend
\retval ::HI_SUCCESS                                                      CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                             CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETTSOUT Setting tsout fails. CNcomment:\C9\E8\D6\C3ts out ʧ\B0\DC CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_TUNER_SetTSOUT(HI_U32 u32TunerId, HI_UNF_TUNER_TSOUT_SET_S *pstTSOUT);

/**
\brief Obtains the frequency locking status and parameters of the tuner.
CNcomment:\brief \BB\F1ȡTUNER\CB\F8Ƶ״̬\BA\CD\CB\F8Ƶ\B2\CE\CA\FD\A1\A3CNend
\attention \n
N/A
\param[in] u32tunerId tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] u32TimeOut frequency locking timeout, unit: ms, frequency locking time is related to strength of signal CNcomment:\CB\F8Ƶ\B5ĳ\ACʱʱ\BC䣬\B5\A5λ\CAǺ\C1\C3룬\CB\F8Ƶʱ\BC\E4\BA\CD\D0ź\C5ǿ\B6\C8\D3й\D8ϵ\A1\A3CNend
               if you want to get the state of locking, the u32TimeOut should be set 100ms at least;
               if the u32TimeOut is 0, just config register without locking state, return HI_SUCCESS
               CNcomment: \C8\E7\B9\FB\CF\EB\B5õ\BD\CB\F8\B6\A8״̬\A3\AC\CB\F8Ƶ\B3\ACʱ\D7\EEС\C9\E8\D6\C3Ϊ100ms\A3\BB
                          \C8\E7\B9\FB\B3\ACʱʱ\BC\E4Ϊ0\A3\ACֻ\C5\E4\D6üĴ\E6\C6\F7\A3\AC\B2\BB\C5ж\A8\CB\F8\B6\A8״̬\A3\AC\B7\B5\BB\D8HI_SUCCESS\A1\A3CNend
\param[out] pstTunerStatus: The current frequency locking status and parameters of the tuner are returned. Note: This parameter is valid only when HI_SUCCESS is returned.  CNcomment: \B7\B5\BBص\B1ǰTUNER\B5\C4\CB\F8Ƶ״̬\BA\CD\CB\F8Ƶ\B2\CE\CA\FD\A1\A3 ע\D2⣺\B4˲\CE\CA\FDֻ\D4ں\AF\CA\FD\B7\B5\BBسɹ\A6\B5\C4\C7\E9\BF\F6\CF²\C5\D3\D0\D2\E2\D2塣CNend
\retval ::HI_SUCCESS Success                    CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetStatus(HI_U32    u32tunerId , HI_UNF_TUNER_STATUS_S  *pstTunerStatus);


/**
\brief Obtains the current bit error rate (BER) of the tuner. The BER is expressed by using the scientific notation.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER \B5\C4\CE\F3\C2\EB\C2ʣ\AC\D3ÿ\C6ѧ\BC\C6\CA\FD\B7\A8\B1\EDʾ\A1\A3CNend
\attention \n
N/A
\param[in] u32tunerId tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32BER  Pointer to the current BER of the tuner The error bit rate consists of three elements. Their definitions are as follows:
                      Their definitions are as follows:
                    pu32BER[0]: integral part of the base number of the BER
                    pu32BER[1]: decimal part of the base number of the BER x 1000
                    pu32BER[2]: absolute value of the exponential of the BER
                    For example, if the BER is 2.156E-7, the values of the three elements are
                    2, 156, and 7 respectively.
                    The three elements are valid only when HI_SUCCESS is returned.
                    Otherwise, the application layer sets a large value as required, for example, 0.5 (the values of the three elements are 5, 0, and 1 respectively).
                         0.5 (the values of the three elements are 5, 0, and 1 respectively).
CNcomment:\param[out] pu32BER  ָ\CF\F2\B5\B1ǰTUNER \CE\F3\C2\EB\C2ʵ\C4ָ\D5롣\B8\C3ָ\D5\EBָ\CF\F2һ\B8\F6\B0\FC\BA\AC\C8\FD\B8\F6Ԫ\CBص\C4\CA\FD\D7飬\C8\FD\B8\F6Ԫ\CBغ\AC\D2\E5\C8\E7\CF\C2:
                              pu32BER[0]:\CE\F3\C2\EB\C2ʵ\D7\CA\FD\B5\C4\D5\FB\CA\FD\B2\BF\B7\D6
                              pu32BER[1]:\CE\F3\C2\EB\C2ʵ\D7\CA\FD\B5\C4С\CA\FD\B2\BF\B7ֳ\CB\D2\D41000
                              pu32BER[2]:\CE\F3\C2\EB\C2\CAָ\CA\FD\B2\BF\B7\D6ȡ\BE\F8\B6\D4ֵ
                              \C0\FD\C8\E7:\CE\F3\C2\EB\C2\CAΪ2.156E-7\A3\AC\C4\C7ô\C8\FD\B8\F6Ԫ\CBص\C4ȡֵ\B7ֱ\F0Ϊ
                              2\A1\A2156\BA\CD7
                              \D5\E2\C8\FD\B8\F6Ԫ\CB\D8ֻ\D4ں\AF\CA\FD\B7\B5\BBسɹ\A6\B5\C4\C7\E9\BF\F6\CF²\C5\D3\D0\D2\E2\D2壬
                              \B7\F1\D4\F2Ӧ\D3ò\E3\BFɸ\F9\BE\DDʵ\BC\CA\C7\E9\BF\F6\D7\D4\D0\D0\C9\E8\D6\C3һ\B8\F6\BDϴ\F3ֵ(\B1\C8\C8\E70.5\A3\AC\BC\B4\C8\FD\B8\F6Ԫ\CBطֱ\F0Ϊ5\A1\A20\A1\A21)\A1\A3CNend
\retval ::HI_SUCCESS Success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Calling this API fails.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetBER(HI_U32   u32tunerId , HI_U32 *pu32BER);


/**
\brief Obtains the current signal-to-noise ratio (SNR) of the tuner.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER \B5\C4\D0\C5\D4\EB\B1ȡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32SNR  Pointer to the current SNR of the tuner,SNR unit:dB,not reserves fractional part.
                    This parameter is valid only when HI_SUCCESS is returned.
                   Otherwise, the application layer sets the parameter to a small value.
CNcomment:\param[out] pu32SNR  ָ\CF\F2\B5\B1ǰTUNER\D0\C5\D4\EB\B1ȵ\C4ָ\D5룬\D0\C5\D4\EB\B1\C8ȡ\D5\FB\B5\A5λΪdB\A1\A3
                              \B4˲\CE\CA\FDֻ\D4ں\AF\CA\FD\B7\B5\BBسɹ\A6\B5\C4\C7\E9\BF\F6\CF²\C5\D3\D0\D2\E2\D2壬
                              \B7\F1\D4\F2\A3\ACӦ\D3ò\E3\BFɽ\AB\B4\CBֵ\C9\E8\D6\C3Ϊ\D7\EEСֵ\A1\A3CNend
\retval ::HI_SUCCESS Success                   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSNR(HI_U32   u32tunerId , HI_U32 *pu32SNR );

/**
\brief Obtains the current precise signal-to-noise ratio (SNR) of the tuner.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER \B5ľ\ABȷ\D0\C5\D4\EB\B1ȡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pdSNR  Pointer to the current SNR of the tuner,SNR unit:dB,and reserves fractional part.
                    This parameter is valid only when HI_SUCCESS is returned.
                   Otherwise, the application layer sets the parameter to a small value.
CNcomment:\param[out] pdSNR  ָ\CF\F2\B5\B1ǰTUNER\D0\C5\D4\EB\B1ȵ\C4ָ\D5룬\D0\C5\D4\EB\B1ȵ\A5λΪdB\C7ұ\A3\C1\F4С\CA\FD\B2\BF\B7֡\A3
                              \B4˲\CE\CA\FDֻ\D4ں\AF\CA\FD\B7\B5\BBسɹ\A6\B5\C4\C7\E9\BF\F6\CF²\C5\D3\D0\D2\E2\D2壬
                              \B7\F1\D4\F2\A3\ACӦ\D3ò\E3\BFɽ\AB\B4\CBֵ\C9\E8\D6\C3Ϊ\D7\EEСֵ\A1\A3CNend
\retval ::HI_SUCCESS Success                   CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.  CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetPreciseSNR(HI_U32   u32tunerId , HI_DOUBLE *pdSNR );


/**
\brief Obtains the current signal strength of the tuner.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER\B5\C4\D0ź\C5ǿ\B6ȡ\A3CNend
\attention \n
N/A
\param[in] u32tunerId  tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32SignalStrength  Pointer to the current signal strength of the tuner
                            For cable signal, the value of *pu32SignalStrength ranges from 20~120.
                            For satellite signal, the value is 0~100, unit in percent.
                            For terrestrial signal, the value is 0~100, unit in percent.
                  This parameter is valid only when HI_SUCCESS is returned.
                  Otherwise, the application layer sets the parameter to a small value.
CNcomment:\param[out] pu32SignalStrength  ָ\CF\F2\B5\B1ǰTUNER\D0ź\C5ǿ\B6ȵ\C4ָ\D5롣
                            \B6\D4\D3\DACable\D0źţ\AC*pu32SignalStrength\B5\C4ȡֵ\B7\B6ΧΪ20~120
                            \B6\D4\D3\DASatellite\D0źţ\AC*pu32SignalStrength\B5\C4ȡֵ\B7\B6ΧΪ0~100\A3\AC\B5\A5λΪ\B0ٷֱ\C8
                            \B6\D4\D3\DATerrestrial\D0źţ\AC*pu32SignalStrength\B5\C4ȡֵ\B7\B6ΧΪ0~100\A3\AC\B5\A5λΪ\B0ٷֱ\C8
                            \B4˲\CE\CA\FDֻ\D4ں\AF\CA\FD\B7\B5\BBسɹ\A6\B5\C4\C7\E9\BF\F6\CF²\C5\D3\D0\D2\E2\D2壬
                            \B7\F1\D4\F2\A3\ACӦ\D3ò\E3\BFɽ\AB\B4\CBֵ\C9\E8\D6\C3Ϊ\D7\EEСֵ\A1\A3CNend
\retval ::HI_SUCCESS Success                  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails. CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_FAILED_GETSIGNALSTRENGTH Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalStrength(HI_U32   u32tunerId , HI_U32 *pu32SignalStrength );

/**
\brief Obtains the current signal quality of the tuner, returns a percentage value.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER\B5\C4\D0ź\C5\D6\CA\C1\BF\A3\AC\B7\B5\BBذٷֱ\C8( \B4˽ӿڲ\BB֧\B3\D6DVB_C \BA\CDJ83B\D6\C6ʽ)\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32SignalQuality   Output pointer.                       CNcomment:ָ\CF\F2\D0ź\C5\D6\CA\C1\BF\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_FAILED_GETSIGNALQUALITY Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalQuality(HI_U32 u32TunerId, HI_U32 *pu32SignalQuality);

/**
\brief Obtains the actual frequency and symbol rate of the current tuner for cable,terrestrial and satellite
signal, for terrestrial signal, symbol rate means nothing, ignore it.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER\B5\C4ʵ\BC\CAƵ\C2ʺͷ\FB\BA\C5\C2ʡ\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32Freq   Pointer to the current frequency of the tuner. CNcomment:ָ\CF\F2\B5\B1ǰTUNERƵ\B5\E3\B5\C4ָ\D5롣CNend
\param[out] pu32Symb   Points to the current symbol rate.             CNcomment:ָ\CF\F2\B5\B1ǰ\B7\FB\BA\C5\C2\CA CNend
\retval ::HI_SUCCESS Success                                          CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Calling this API fails.                         CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_FAILED_GETSIGNALSTRENGTH  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetRealFreqSymb( HI_U32 u32TunerId, HI_U32 *pu32Freq, HI_U32 *pu32Symb );

/**
\brief Obtains current signal information of the TUNER, used in satellite and terrestrial, not necessary for cable.
CNcomment:\brief \BB\F1ȡ\B5\B1ǰTUNER\B5\C4\D0ź\C5\D0\C5Ϣ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pstSignalInfo Pointer to a signal info structure.         CNcomment:ָ\CF\F2\D0ź\C5\D0\C5Ϣ\BDṹ\CC\E5\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_NOT_CONNECT The signal is droped. CNcomment:\D0ź\C5δ\CB\F8\B6\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETSTATUS Getting status fails. CNcomment:\BB\F1ȡ\D0ŵ\C0\CB\F8\B6\A8״̬ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_FAILED_GETSIGNALINFO  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSignalInfo(HI_U32 u32TunerId, HI_UNF_TUNER_SIGNALINFO_S *pstSignalInfo);

/**
\brief Sets the LNB parameter.
CNcomment:\brief \C9\E8\D6\C3LNB\B2\CE\CA\FD\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstLNB      Pointer to a LNB parameter structure.          CNcomment:ָ\CF\F2LNB\B2\CE\CA\FD\BDṹ\CC\E5\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetLNBConfig(HI_U32 u32TunerId, HI_UNF_TUNER_FE_LNB_CONFIG_S *pstLNB);

/**
\brief Sets the LNB power.
CNcomment:\brief \C9\E8\D6\C3LNB\B9\A9\B5硣CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enLNBPower  The enumeration of the LNB power type.         CNcomment:LNB\B9\A9\B5緽ʽö\BE\D9ֵ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetLNBPower(HI_U32 u32TunerId, HI_UNF_TUNER_FE_LNB_POWER_E enLNBPower);

/**
\brief Gets PLP number, only used in DVB-T2.
CNcomment:\brief \BB\F1ȡ\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CA\FD\C1\BF\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu8PLPNum  The PLP number.                                CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CA\FD\C1\BF\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_GETPLPNUM  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetPLPNum(HI_U32 u32TunerId, HI_U8 *pu8PLPNum);




/**
\brief Sets PLP ID, only used in DVB-T2.
CNcomment:\brief \C9\E8\D6\C3\CE\EF\C0\ED\B2\E3\B9ܵ\C0\B2\CE\CA\FD\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPLPPara  The PLP parameters.                                       CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\B2\CE\CA\FD\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETPLPID  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetPLPPara(HI_U32 u32TunerId, HI_UNF_TUNER_TER_PLP_PARA_S *pstPLPPara);

/**
\brief Get PLP information, only used in DVB-T2.
CNcomment:\brief \BB\F1ȡ\CE\EF\C0\ED\B2\E3\B9ܵ\C0\D0\C5Ϣ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] u32PLPIndex  PLP index.                                    CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\CB\F7\D2\FD\BAš\A3CNend
\param[out] pstPLPInfo  The PLP information.                          CNcomment:\CE\EF\C0\ED\B2\E3\B9ܵ\C0\D0\C5Ϣ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SETPLPID  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/

HI_S32 HI_UNF_TUNER_GetPLPInfo(HI_U32 u32TunerId, HI_U32 u32PLPIndex, HI_UNF_TUNER_TER_PLP_INFO_S *pstPLPInfo);

/**
\brief Set antenna power.
CNcomment:\brief \C9\E8\D6\C3\CC\EC\CFߵ\E7Դ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enPower  The antenna power status.                         CNcomment:\CC\EC\CFߵ\E7Դ״̬\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened.      CNcomment: ģ\BF\E9û\D3д\F2\BF\AA CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid.  CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetAntennaPower(HI_U32 u32TunerId, HI_UNF_TUNER_TER_ANTENNA_POWER_E enPower);


/**
\brief Starts blind scan.
CNcomment:\brief \BF\AAʼäɨ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to the blind scan parameter.       CNcomment:ָ\CF\F2äɨ\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_BLINDSCAN Blind scan busy. CNcomment:äɨ\D5\FD\D4\DAӦ\D3\C3 CNend

\see Please refer to definition of HI_UNF_TUNER_BLINDSCAN_PARA_S.
N/A
*/
HI_S32 HI_UNF_TUNER_BlindScanStart(HI_U32 u32TunerId, const HI_UNF_TUNER_BLINDSCAN_PARA_S *pstPara);

/**
\brief Stops blind scan.
CNcomment:\brief ֹͣäɨ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_BlindScanStop(HI_U32 u32TunerId);

/**
\brief TUNER standby.
CNcomment:\brief TUNER\B4\FD\BB\FA(  \B4˽ӿڲ\BB֧\B3\D6DVB_C \BA\CDJ83B\D6\C6ʽ\A3\AC\B4\CB\C1\BD\D6\D6\D6\C6ʽ\B4\FD\BB\FA\C7\EB\B2μ\FBpmoc \B4\FD\BB\FA\BDӿ\DA)  CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_STANDBY  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Standby(HI_U32 u32TunerId);

/**
\brief Wakes up TUNER.
CNcomment:\brief TUNER\BB\BD\D0\D1(  \B4˽ӿڲ\BB֧\B3\D6DVB_C \BA\CDJ83B\D6\C6ʽ\A3\AC\B4\CB\C1\BD\D6\D6\D6\C6ʽ\BB\BD\D0\D1\C7\EB\B2μ\FBpmoc \BB\BD\D0ѻ\BD\D0ѽӿ\DA) CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_WAKEUP  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_WakeUp( HI_U32 u32TunerId);
/*ZHTQ ADD*/
HI_S32 TUNER_DISEQC_SendMessage(HI_U32 u32TunerId,
                                           const HI_UNF_TUNER_DISEQC_SENDMSG_S * pstSendMsg);

HI_S32 TUNER_DISEQC_RecvMessage(HI_U32 u32TunerId,
                                           HI_UNF_TUNER_DISEQC_RECVMSG_S * pstRecvMsg);

/**
\brief Sends and receives DiSEqC message, only the devices supporting DiSEqC 2.x support receive message.
CNcomment:\brief \B7\A2\CBͽ\D3\CA\D5DiSEqC\CF\FBϢ\A3\AC\BD\F6֧\B3\D6DiSEqC 2.x\B5\C4\C9豸֧\B3ֽ\D3\CA\D5\CF\FBϢ\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ں\C5, ȡֵ\B7\B6Χ0-2 CNend
\param[in] pstSendMsg  The pointer to a sending message structure.    CNcomment:ָ\CF\F2\B7\A2\CB\CD\CF\FBϢ\BDṹ\CC\E5\B5\C4ָ\D5롣CNend
\param[out] pstRecvMsg The pointer to a receiving message structure.If your device is DiSEqC 1.x, you can pass NULL here.
CNcomment:\param[out] pstRecvMsg ָ\CF\F2\BD\D3\CA\D5\CF\FBϢ\BDṹ\CC\E5\B5\C4ָ\D5롣\C8\E7\B9\FB\CA\C7DiSEqC 1.x\C9豸\A3\AC\D5\E2\C0\EF\BF\C9\D2Դ\ABNULL\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_DISEQC Send DiSEqC message fail. CNcomment:\B7\A2\CB\CD\CF\FBϢʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_FAILED_DISEQC Recv DiSEqC message fail. CNcomment:\BD\D3\CA\D5\CF\FBϢʧ\B0\DC CNend

\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_SendRecvMessage(HI_U32 u32TunerId,
                                           const HI_UNF_TUNER_DISEQC_SENDMSG_S * pstSendMsg,
                                           HI_UNF_TUNER_DISEQC_RECVMSG_S * pstRecvMsg);

/**
\brief Sets 0/12V switch. Don't support now.
CNcomment:\brief \C9\E8\D6\C30/12V\BF\AA\B9\D8״̬\A3\AC\D4ݲ\BB֧\B3֡\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enPort      The enumeration of the switch port.            CNcomment:\BF\AA\B9\D8ö\BE\D9ֵ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Switch012V(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_0_12V_E enPort);

/**
\brief Sets 22KHz switch.
CNcomment:\brief \C9\E8\D6\C322KHz\BF\AA\B9\D8״̬\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enPort      The enumeration of the switch port.            CNcomment:\BF\AA\B9\D8ö\BE\D9ֵ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_Switch22K(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_22K_E enPort);

/**
\brief Sets tone burst switch.
CNcomment:\brief \C9\E8\D6\C3Tone burst\BF\AA\B9\D8״̬\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enStatus    The enumeration of the switch port.            CNcomment:\BF\AA\B9\D8ö\BE\D9ֵ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_DISEQC  Calling this CMD fails. CNcomment:ioctlϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SwitchToneBurst(HI_U32 u32TunerId, HI_UNF_TUNER_SWITCH_TONEBURST_E enStatus);

//#ifdef DISEQC_SUPPORT
/**
\brief Sets DiSEqC 1.0/2.0 switch, at most 4 port.
CNcomment:\brief \C9\E8\D6\C3DiSEqC 1.0/2.0\BF\AA\B9أ\AC\D6\C1\B6\E04\BFڡ\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a switch parameter structure.   CNcomment:ָ\CF򿪹ز\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see Please refer to definition of HI_UNF_TUNER_DISEQC_SWITCH4PORT_S.
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Switch4Port(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_SWITCH4PORT_S* pstPara);

/**
\brief Sets DiSEqC 1.1/2.1 switch, supports 8in1, 16in1 switches.
CNcomment:\brief \C9\E8\D6\C3DiSEqC 1.1/2.1\BF\AA\B9أ\AC֧\B3\D68\BFڣ\AC16\BFڿ\AA\B9ء\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a switch parameter structure.   CNcomment:ָ\CF򿪹ز\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Switch16Port(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_SWITCH16PORT_S* pstPara);

/**
\brief Lets the DiSEqC motor store current position.
CNcomment:\brief DiSEqC\C2\ED\B4\EF\B4洢\B5\B1ǰλ\D6á\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a position parameter structure. CNcomment:ָ\CF\F2λ\D6ò\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_StorePos(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_POSITION_S *pstPara);

/**
\brief Lets the DiSEqC motor move to stored position.
CNcomment:\brief DiSEqC\C2\ED\B4\EFת\B6\AF\D6\C1\B4洢λ\D6á\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a position parameter structure. CNcomment:ָ\CF\F2λ\D6ò\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_GotoPos(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_POSITION_S *pstPara);

/**
\brief Enables or disables the DiSEqC motor's limit setting.
CNcomment:\brief \B4򿪡\A2\B9ر\D5DiSEqC\C2\ED\B4\EFȨ\CF\DE\C9\E8\D6á\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a limit parameter structure.    CNcomment:ָ\CF\F2limit\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_SetLimit(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_LIMIT_S* pstPara);

/**
\brief Drives DiSEqC motor.
CNcomment:\brief \C7\FD\B6\AFDiSEqC\C2\ED\B4\EF\D2ƶ\AF\A3\ACע\D2\E2HI_UNF_TUNER_DISEQC_Move\BDӿڻ\E1\D6𽥱\BBHI_UNF_TUNER_DISEQC_RunStep\CC\E6\B4\FA\A3\AC\CFֽ׶β\BB\B7\BD\B1\E3\C7еģ\AC\BF\C9\D2\D4
\BC\CC\D0\F8ʹ\D3\C3HI_UNF_TUNER_DISEQC_Move\BDӿڣ\AC\B5\B1\D3\D0HI_UNF_TUNER_DISEQC_RunStep\BDӿ\DAʱ\A3\AC\BE\A1\C1\BFʹ\D3øýӿڡ\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a movement parameter structure. CNcomment:ָ\CF\F2\D2ƶ\AF\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Move(HI_U32 u32TunerId,  HI_UNF_TUNER_DISEQC_MOVE_S* pstPara);

/**
\brief Drives DiSEqC motor.
CNcomment:\brief \C7\FD\B6\AFDiSEqC\C2\ED\B4\EFת\B6\AF\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a movement parameter structure. CNcomment:ָ\CF\F2\D2ƶ\AF\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_RunStep(HI_U32 u32TunerId,  HI_UNF_TUNER_DISEQC_RUN_S* pstPara);

/**
\brief Halts DiSEqC motor.
CNcomment:\brief ֹͣDiSEqC\C2\ED\B4\EF\D2ƶ\AF\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enLevel     The command level of the DiSEqC motor.         CNcomment:\C2\ED\B4\EF֧\B3ֵ\C4\C3\FC\C1\EE\B5ȼ\B6\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Stop(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief Lets the DiSEqC motor recalculate its stored positions.
CNcomment:\brief \D6\D8\D0¼\C6\CB\E3\C2\ED\B4\EF\B4洢λ\D6á\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a recaulculate parameter structure.
                                                                      CNcomment:ָ\CF\F2\D6ؼ\C6\CB\E3\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Recalculate(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_RECALCULATE_S* pstPara);

/**
\brief Calculates the angular, basing on site-longitude, site-latitude and satellite-longitude.
CNcomment:\brief USALS\B8\F9\BEݵ\B1\B5ؾ\ADγ\B6ȡ\A2\CE\C0\D0Ǿ\AD\B6ȼ\C6\CB\E3\CE\C0\D0ǽǶȡ\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in/out] pstPara The pointer to a USALS parameter structure.    CNcomment:ָ\CF\F2USALS\BC\C6\CB\E3\B2\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_CalcAngular(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_USALS_PARA_S* pstPara);

/**
\brief Gotos the indicated angular.
CNcomment:\brief USALS\C9豸ת\D6\C1ĳ\BDǶȡ\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] pstPara     The pointer to a USALS angular structure.      CNcomment:ָ\CF\F2USALS\BDǶȲ\CE\CA\FD\B5\C4ָ\D5롣CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_GotoAngular(HI_U32 u32TunerId, const HI_UNF_TUNER_DISEQC_USALS_ANGULAR_S* pstPara);

/**
\brief Resets DiSEqC device.
CNcomment:\brief \B8\B4λDiSEqC\C9豸\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:\C9豸֧\B3ֵ\C4\C3\FC\C1\EE\B5ȼ\B6\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Reset(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief DiSEqC device standby.
CNcomment:\brief DiSEqC\C9豸\B4\FD\BB\FA\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:\C9豸֧\B3ֵ\C4\C3\FC\C1\EE\B5ȼ\B6\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_Standby(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief Wakes up DiSEqC device.
CNcomment:\brief \BB\BD\D0\D1DiSEqC\C9豸\A1\A3CNend
\attention \n
N/A
\param[in] u32TunerId  Tuner port ID. The port ID can be 0-2.         CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in] enLevel     The command level of the DiSEqC device.        CNcomment:\C9豸֧\B3ֵ\C4\C3\FC\C1\EE\B5ȼ\B6\A1\A3CNend
\retval ::HI_SUCCESS   Success                                        CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                        CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_DISEQC_WakeUp(HI_U32 u32TunerId, HI_UNF_TUNER_DISEQC_LEVEL_E enLevel);

/**
\brief Acquire data to display constellation.
CNcomment:\brief \BB\F1ȡ\D0\C7\D7\F9ͼ\CA\FD\BEݡ\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  enDataLen     The sample data length, can be 512, 1024 or 2048.  CNcomment:\B2ɼ\AF\B5\C4\CA\FD\BEݳ\A4\B6\C8, ֧\B3\D6512\A3\AC1024\BA\CD2048 3\D6֡\A3CNend
\param[out] pstData       The buffer to store data.                          CNcomment:\CA\FD\BEݴ洢\C7\F8\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SAMPLEDATA Tuner sample data fail. CNcomment:\BB\F1ȡ\CA\FD\BE\DDʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetConstellationData(HI_U32 u32TunerId, HI_UNF_TUNER_SAMPLE_DATALEN_E enDataLen, HI_UNF_TUNER_SAMPLE_DATA_S *pstData);

/**
\brief Acquire data to display spectrum.
CNcomment:\brief \BB\F1ȡƵ\C6\D7ͼ\CA\FD\BEݡ\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  enDataLen     The sample data length, can be 512, 1024 or 2048.  CNcomment:\B2ɼ\AF\B5\C4\CA\FD\BEݳ\A4\B6\C8, ֧\B3\D6512\A3\AC1024\BA\CD2048 3\D6֡\A3CNend
\param[out] pu32Data      The buffer to store data.                          CNcomment:\CA\FD\BEݴ洢\C7\F8\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_FAILED_SAMPLEDATA Tuner sample data fail. CNcomment:\BB\F1ȡ\CA\FD\BE\DDʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSpectrumData(HI_U32 u32TunerId, HI_UNF_TUNER_SAMPLE_DATALEN_E enDataLen, HI_U32 *pu32Data);

/**
\brief Get the upper limit time according to the connect parameter.
CNcomment:\brief \B8\F9\BE\DD\CB\F8Ƶ\B2\CE\CA\FD\BB\F1ȡ\D7\EE\B4\F3\CB\F8Ƶʱ\BC䡣CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  pstConnectPara     The pointer to store the connect parameter.   CNcomment:\CB\F8Ƶ\B2\CE\CA\FDָ\D5롣CNend
\param[out] pu32TimeOutMs      The upper limit time.                         CNcomment:\D7\EE\B4\F3\CB\F8̨ʱ\BC䡣CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_TUNER_NOT_OPEN  The TUNER module is not opened. CNcomment: ģ\BF\E9û\D3д\F2\BF\AACNend
\retval ::HI_ERR_TUNER_INVALID_PORT  The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_POINT The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_TUNER_INVALID_PARA The input parameter is invalid. CNcomment:\CA\E4\C8\EB \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetDefaultTimeout(HI_U32  u32tunerId, const HI_UNF_TUNER_CONNECT_PARA_S  *pstConnectPara, HI_U32 *pu32TimeOutMs);

/**
\brief Set isi id,means selecting the chose vcm stream to receive.
CNcomment:\brief \B5\B1ǰ\B6\CB\CA\C7VCM\D0ź\C5ʱ\A3\AC\B4\E6\D4ڶ\E0\CC\D7\C1\F7\A3\ACͨ\B9\FD\C9\E8\D6\C3\C1\F7ID\A3\AC\BD\D3\CA\D5ָ\B6\A8VCM\C1\F7\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u8SCRNO     user band number,u8SCRNO can be SaTCR1-SaTCR8.       CNcomment:unicable\C9豸\D3û\A7Ƶ\B6κš\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UnicPowerOff(HI_U32 u32TunerId,HI_U8 u8SCRNO);

/**
\brief Each SaTCR generates a tone at the center frequency of its associated band-pass filter.
CNcomment: \C9\E8\D6\C3unicable\D4\DA\CB\F9\D3\D0\D3û\A7Ƶ\B6\CE\D6\D0\D0\C4Ƶ\C2ʴ\A6\B2\FA\C9\FAһ\B8\F6tone \D0źš\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UnicSCRxOn(HI_U32 u32TunerId);

/**
\brief Allows to check the application number.
CNcomment: \BC\EC\B2\E9unicable\B5Ĳ\FAƷ\D0ͺš\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u8SCRNO     user band number,u8SCRNO can be SaTCR1-SaTCR8.       CNcomment:unicable\C9豸\D3û\A7Ƶ\B6κš\A3CNend
\param[in]  u8AppNo     application number.   CNcomment:unicable\B2\FAƷ\D0ͺš\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UnicConfig(HI_U32 u32TunerId,HI_U8 u8SCRNO,HI_U8 u8AppNo);

/**
\brief Allows to check LNB local oscillator frequencies.
CNcomment: \BC\EC\B2\E9unicable LNB\B5ı\BE\D5\F1Ƶ\C2ʡ\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u8SCRNO     user band number,u8SCRNO can be SaTCR1-SaTCR8.       CNcomment:unicable\C9豸\D3û\A7Ƶ\B6κš\A3CNend
\param[in]  u8LoFreqNo     local oscillator number.   CNcomment:\B1\BE\D5\F1Ƶ\C2ʺš\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UnicLOFREQ(HI_U32 u32TunerId,HI_U8 u8SCRNO,HI_U8 u8LoFreqNo);

/**
\brief Set isi id,means selecting the chose vcm stream to receive.
CNcomment:\brief \B5\B1ǰ\B6\CB\CA\C7VCM\D0ź\C5ʱ\A3\AC\B4\E6\D4ڶ\E0\CC\D7\C1\F7\A3\ACͨ\B9\FD\C9\E8\D6\C3\C1\F7ID\A3\AC\BD\D3\CA\D5ָ\B6\A8VCM\C1\F7\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] u8IsiID       isi id,vcm stream id transmitted by server.        CNcomment:\C1\F7\B5\C4ID\BAš\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetSatIsiID(HI_U32 u32TunerId, HI_U8 u8IsiID);

/**
\brief Get total vcm streams number.
CNcomment:\brief \B5\B1ǰ\B6\CB\CA\C7VCM\D0ź\C5ʱ\A3\AC\BB\F1ȡ\D7ܹ\B2\D3ж\E0\C9\D9\CC\D7\C1\F7\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  *pu32TotalStream      total streams number.                      CNcomment:\D7ܹ\B2\B5\C4\C1\F7\CA\FDĿ\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSatTotalStream(HI_U32 u32TunerId, HI_U8 *pu8TotalStream);

/**
\brief Get isi id,by setting stream number,will get isi id.
CNcomment:\brief \B5\B1ǰ\B6\CB\CA\C7VCM\D0ź\C5ʱ\A3\ACͨ\B9\FD\C9\E8\D6\C3\C1\F7\D0\F2\BAţ\AC\C4ܹ\BB\BB\F1ȡ\B5\BD\C1\F7\B5\C4ID\BAš\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u8Stream      stream number,can be 0-n.                          CNcomment:\C1\F7\D0\F2\BAš\A3CNend
\param[out] u8IsiID       isi id,vcm stream id transmitted by server.        CNcomment:\C1\F7\B5\C4ID\BAš\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetSatIsiID(HI_U32 u32TunerId, HI_U8 u8StreamIndex, HI_U8 *pu8IsiID);

/**
\brief scan 950~2150 frequency range,and find out the user bands.
CNcomment: ɨ\C3\E8950~2150MHzƵ\C2ʷ\B6Χ\A3\AC\B2\A2\D5ҳ\F6\D3û\A7Ƶ\B6Ρ\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UNICABLE_ScanUserBands(HI_U32 u32TunerId, HI_UNF_TUNER_UNICABLE_SCAN_PARA_S stScanPara);

/**
\brief exit from user band scanning .
CNcomment: \D6\D0ֹ\D3û\A7Ƶ\B5\E3ɨ\C3衣CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UNICABLE_ExitScanUserBands(HI_U32 u32TunerId);

/**
\brief get user band number after finishing scan .
CNcomment: \CB\D1\CB\F7\BD\E1\CA\F8\BA\F3\BB\F1ȡ\D5ҵ\BD\B5\C4\D3û\A7Ƶ\B6\CE\D7\DC\CA\FD\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pu32UbNum    Total number of user band after finishing scan.     CNcomment:\CB\D1\CB\F7\BD\E1\CA\F8\BA\F3\D5ҵ\BD\B5\C4\D3û\A7Ƶ\B6\CE\D7ܸ\F6\CA\FD\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UNICABLE_GetUserBandsNum(HI_U32 u32TunerId, HI_U32 *pu32UbNum);

/**
\brief Copy scanned results,get user bands information.
CNcomment: \BF\BD\B1\B4ɨ\C3\E8\BD\E1\B9\FB\A3\AC\BB\F1ȡɨ\C3赽\B5\C4\CB\F9\D3\D0\D3û\A7Ƶ\B6\CE\D0\C5Ϣ\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[out] pstUbInfo     user bands information struct array,used to save user band number/user band frequency.       CNcomment:\D3û\A7Ƶ\B6\CE\D0\C5Ϣ\BDṹ\CC\E5\CA\FD\D7飬\D3\C3\D3ڴ洢\D3û\A7Ƶ\B6κţ\AC\D3û\A7Ƶ\C2\CA\D0\C5Ϣ\A1\A3CNend
\param[in]  u32UbInfoNum  the number of user bands information structs.      CNcomment:\D3û\A7Ƶ\B6\CE\D0\C5Ϣ\BDṹ\CC\E5\B8\F6\CA\FD\A1\A3CNend
\param[out]  pu32Num     the number of user bands actual obtained.           CNcomment:ʵ\BCʻ\F1ȡ\B5\BD\B5\C4\D3û\A7Ƶ\B6θ\F6\CA\FD\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_UNICABLE_GetUserBandsInfo(HI_U32 u32TunerId, HI_UNF_TUNER_SCR_UB_S *pstUbInfo, HI_U32 u32UbInfoNum, HI_U32 *pu32Num);

/**
\brief config the scrambing code sequces on physical layer.
CNcomment: \C9\E8\D6\C3\CE\EF\C0\ED\B2\E3\C8\C5\C2\EB\B3\F5ʼ\CF\E0λ\A1\A3CNend
\attention \n
N/A
\param[in]  u32TunerId           Tuner port ID. The port ID can be 0-2.      CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u32ScrambleValue     Initial scrambling code. Range 0-262141,
                                when value is not 0, signal is special       CNcomment:\B3\F5ʼ\BB\AF\C8\C5\C2룬ȡֵΪ0-262141\A3\AC\B7\C70ʱΪ\CC\D8\CA\E2\D0ź\C5 CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_SetScramble(HI_U32 u32TunerId, HI_U32 u32ScrambleValue);

/**
\brief Acquire data to display spectrum.
CNcomment:\brief \BB\F1ȡȫƵ\B6\CEƵ\C6׵\C4\CA\FD\BEݡ\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.                                                                          CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  u32freqStartInHz     The sample data start freqency (Hz), For examle: 435000000 Hz, 698000000 Hz (1000HZ~1300000000HZ).     CNcomment:\B2ɼ\AF\B5\C4\CA\FD\BEݿ\AAʼƵ\B5\E3( \BA\D5\D7\C8)\A3\AC\C0\FD\C8\E7: 435000000 Hz,698000000 Hz(\B7\B6Χ: 1000HZ~1300000000HZ)\A1\A3CNend
\param[in]  u32freqStepInHz     The sample data step(Hz), For examle: 10000 Hz, 20000 Hz (greater than 10000Hz).                CNcomment:\B2ɼ\AF\B5\C4\CA\FD\BEݲ\BD\B3\A4( \BA\D5\D7\C8)\A3\AC\C0\FD\C8\E7: 10000 Hz,20000 Hz (\B7\B6Χ: 10000Hz \D2\D4\C9\CF)\A1\A3CNend
\param[in]  u32numOfFreqSteps     The sample data number, For examle: 1000, 10000.                                          CNcomment:\B2ɼ\AF\B5\C4\CA\FD\BEݸ\F6\CA\FD\A3\AC\C0\FD\C8\E7: 1000,10000\A1\A3CNend
\param[out] ps16powerData      The buffer to store data.                                                                                      CNcomment:\CA\FD\BEݴ洢\C7\F8\A1\A3CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_GetTunerPowerSpectrumData(HI_U32 u32TunerId, HI_U32 u32freqStartInHz,HI_U32 u32freqStepInHz,HI_U32 u32numOfFreqSteps,HI_S16 *ps16powerData);

/**
\brief config which ISDBT layer is select to receive.
CNcomment: \B6\D4ISDBT\D0źţ\AC\BF\C9ѡ\D4\F1\D0Ե\C4\C5\E4\D6ò\E3\D0\C5Ϣ\A3\AC\B1\C8\C8\E7A/B/C\B2\E3\D6е\C4\C4\C4һ\B2\E3\D0ź\C5\D0\E8Ҫ\BD\D3\CAա\A3CNend
\attention \n
N/A
\param[in]  u32TunerId    Tuner port ID. The port ID can be 0-2.             CNcomment:TUNER\B6˿ںţ\ACȡֵΪ0-2 CNend
\param[in]  pstMonLayersConfig    the layers configuration.                              CNcomment:\B2\E3\C5\E4\D6\C3\D0\C5Ϣ CNend
\retval ::HI_SUCCESS   Success                                               CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE   Calling this API fails.                               CNcomment:APIϵͳ\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_TUNER_MonitorISDBTLayer(HI_U32 u32TunerId, HI_UNF_TUNER_MONITOR_LAYERS_CONFIG_S *pstMonLayersConfig);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ECS_TYPE_H__ */

