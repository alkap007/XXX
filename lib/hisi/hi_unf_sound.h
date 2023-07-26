/******************************************************************************
  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_sound.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/1/22
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        : z67193
  Modification  : Created file
******************************************************************************/
/**
 * \file
 * \brief Describes the information about the SOUND (SND) module. CNcomment:\CCṩSOUND\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */

#ifndef  __HI_UNF_SND_H__
#define  __HI_UNF_SND_H__

#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/********************************Macro Definition********************************/
/** \addtogroup      SOUND */
/** @{ */  /** <!-- \A1\BESOUND\A1\BF */

/**Maximum sound outputport*/
/**CNcomment:\D7\EE\B4\F3sound\CA\E4\B3\F6\B6˿\DA*/
#define HI_UNF_SND_OUTPUTPORT_MAX (16)
#define HI_UNF_SND_EQ_BANDNUM_MAX (10)

/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      SOUND */
/** @{ */  /** <!--  \A1\BESOUND\A1\BF */

/**Defines the ID of the audio output (AO) device.*/
/**CNcomment:\B6\A8\D2\E5\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5*/
typedef enum hiUNF_SND_E
{
    HI_UNF_SND_0,           /**<AO device 0*/ /**<CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸0 */
    HI_UNF_SND_1,           /**<AO device 1*/ /**<CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸1 */
    HI_UNF_SND_2,           /**<AO device 2*/ /**<CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸2 */
    HI_UNF_SND_BUTT
} HI_UNF_SND_E;

/**Audio volume attribute*/
/**CNcomment:\D2\F4Ƶ\D2\F4\C1\BF\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_GAIN_ATTR_S
{
    HI_BOOL bLinearMode; /**< gain type of volume*/ /**<CNcomment:\D2\F4\C1\BFģʽ */
    HI_S32  s32Gain; /**<Linear gain(bLinearMode is HI_TRUE) , ranging from 0 to 100*/ /**<CNcomment:\CF\DF\D0\D4\D2\F4\C1\BF: 0~100 */
                     /**<Decibel gain(bLinearMode is HI_FALSE) , ranging from -70dB to 0dB */ /**<CNcomment: dB\D2\F4\C1\BF:-70~0*/
} HI_UNF_SND_GAIN_ATTR_S;

/**Audio L/R channel volume attribute*/
/**CNcomment:\D2\F4Ƶ\D7\F3\D3\D2\C9\F9\B5\C0\D2\F4\C1\BF\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_ABSGAIN_ATTR_S
{
    HI_BOOL bLinearMode; /**< gain type*/ /**<CNcomment:\D2\F4\C1\BFģʽ */
    HI_S32  s32GainL; /**<Linear left ch gain(bLinearMode is HI_TRUE) , ranging from 0 to 100*/ /**<CNcomment:\D7\F3\C9\F9\B5\C0\CF\DF\D0\D4\D2\F4\C1\BF: 0~100 */
                     /**<Decibel left ch gain(bLinearMode is HI_FALSE) , ranging from -81dB to 18dB */ /**<CNcomment: \D7\F3\C9\F9\B5\C0dB\D2\F4\C1\BF:-81~+18*/
    HI_S32  s32GainR; /**<Linear right ch gain(bLinearMode is HI_TRUE) , ranging from 0 to 100*/ /**<CNcomment:\D3\D2\C9\F9\B5\C0\CF\DF\D0\D4\D2\F4\C1\BF: 0~100 */
                  /**<Decibel right ch gain(bLinearMode is HI_FALSE) , ranging from -81dB to 18dB */ /**<CNcomment: \D3\D2\C9\F9\B5\C0dB\D2\F4\C1\BF:-81~+18*/
} HI_UNF_SND_ABSGAIN_ATTR_S;

/**High Precision Gain, ranging from -81dB to 18dB, step 0.125dB*/
/**CNcomment:\B8߾\AB\B6\C8\D4\F6\D2棬\B7\B6Χ\B4\D3-81dB\B5\BD18dB\A3\AC\B2\BD\B3\A4Ϊ0.125dB*/
typedef struct hiHI_UNF_SND_PRECIGAIN_ATTR_S
{
    HI_S32 s32IntegerGain; /**<Interger part of high preicision gain*/ /**<CNcomment: \B8߾\AB\B6\C8\D4\F6\D2\E6\B5\C4\D5\FB\CA\FD\B2\BF\B7\D6*/
    HI_S32 s32DecimalGain; /**<decimal part of high preicision gain, if -0.125dB, value is -125*/ /**<CNcomment: \B8߾\AB\B6\C8\D4\F6\D2\E6\B5\C4С\CA\FD\B2\BF\B7\D6 \C8\E70.125\A3\AC\D4\F2ֵΪ125*/
}HI_UNF_SND_PRECIGAIN_ATTR_S;

/**Audio Track Type: Master, Slave, Virtual channel,LowLatency channel*/
/**CNcomment:\D2\F4ƵTrack\C0\E0\D0\CD:\D6\F7ͨ\B5\C0 \B8\A8ͨ\B5\C0 \D0\E9\C4\E2ͨ\B5\C0 \B5\CD\D1\D3ʱͨ\B5\C0*/
/**LowLatency channel not support attach avplay and the data only support 48K,stereo,16Bit.Only support one lowlatency track in a sound*/
/**CNcomment:\B5\CD\D1\D3ʱͨ\B5\C0\B2\BB֧\B3\D6AVPLAY\B0󶨣\AC\B4\CBͨ\B5\C0ֻ֧\B3ֲ\C9\D1\F9\C2\CAΪ48K,˫\C9\F9\B5\C0,16λλ\BF\ED\B5\C4\D2\F4Ƶ\CA\FD\BE\DD,\BD\F6֧\B3ִ\B4\BD\A8һ\B8\F6\B5\CD\D1\D3ʱͨ\B5\C0*/
typedef enum hiHI_UNF_SND_TRACK_TYPE_E
{
    HI_UNF_SND_TRACK_TYPE_MASTER = 0,
    HI_UNF_SND_TRACK_TYPE_SLAVE,
    HI_UNF_SND_TRACK_TYPE_VIRTUAL,
    HI_UNF_SND_TRACK_TYPE_LOWLATENCY,

    HI_UNF_SND_TRACK_TYPE_OTTSOUND,      /**< Ott sound(PCM) MS12 ONLY. Such as app ui audio*/
    HI_UNF_SND_TRACK_TYPE_SYSTEMAUDIO,   /**< System sound(PCM) MS12 ONLY.*/
    HI_UNF_SND_TRACK_TYPE_APPAUDIO,      /**< App audio(PCM) MS12 ONLY. Such as tts audio*/
    HI_UNF_SND_TRACK_TYPE_BUTT
} HI_UNF_SND_TRACK_TYPE_E;

/**Audio output attribute */
/**CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\CA\F4\D0\D4*/
typedef struct hiHI_UNF_AUDIOTRACK_ATTR_S
{
    HI_UNF_SND_TRACK_TYPE_E     enTrackType;        /**<Track Type*/ /**<CNcomment:Track\C0\E0\D0\CD*/
    HI_U32                      u32FadeinMs;        /**<Fade in time(unit:ms)*/ /**<CNcomment:\B5\AD\C8\EBʱ\BC\E4(\B5\A5λ: ms)*/
    HI_U32                      u32FadeoutMs;       /**<Fade out time(unit:ms)*/ /**<CNcomment:\B5\AD\B3\F6ʱ\BC\E4(\B5\A5λ: ms)*/
    HI_U32                      u32OutputBufSize;   /**<Track output buffer size*/ /**<CNcomment:Track\CA\E4\B3\F6\BB\BA\B4\E6\B4\F3С*/
    HI_U32                      u32BufLevelMs;      /**<Output buffer data size control(ms),default 400ms*/ /**<CNcomment:\CA\E4\B3\F6\BB\BA\B4\E6\D6\D0\CA\FD\BE\DD\C1\BF\BF\D8\D6\C6(ms),Ĭ\C8\CF400ms*/
    HI_U32                      u32StartThresholdMs;  /**<Track start threshold (ms), default value is 50ms, max value is equal to u32BufLevelMs, only valid for master track*/
                                                      /**<CNcomment:Track\C6\F4\B6\AF\C3\C5\CFޣ\ACĬ\C8\CFֵ\CA\C750ms\A3\AC\D7\EE\B4\F3ֵΪu32BufLevelMs\A3\AC\B4\CB\CA\F4\D0\D4ֻ\B6\D4master track\D3\D0Ч*/
} HI_UNF_AUDIOTRACK_ATTR_S;

/**Audiotrack config parameter*/
/**CNcomment:\D2\F4Ƶ Track\C5\E4\D6ò\CE\CA\FD*/
typedef struct hiHI_UNF_AUDIOTRACK_CONFIG_S
{
    HI_U32      u32ConfigType;        /**<Track config type*/ /**<CNcomment:Track\C5\E4\D6\C3\C0\E0\D0\CD*/
    HI_VOID*    pConfigData;          /**<Track config data*/ /**<CNcomment:Track\C5\E4\D6\C3\CA\FD\BE\DD*/
} HI_UNF_AUDIOTRACK_CONFIG_S;

/**Audio outputport: DAC0,I2S0,SPDIF0,HDMI0,ARC0*/
/**CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA:DAC0,I2S0,SPDIF0,HDMI0,ARC0*/
typedef enum hiUNF_SND_OUTPUTPORT_E
{
    HI_UNF_SND_OUTPUTPORT_DAC0 = 0,

    HI_UNF_SND_OUTPUTPORT_I2S0,

    HI_UNF_SND_OUTPUTPORT_I2S1,

    HI_UNF_SND_OUTPUTPORT_SPDIF0,

    HI_UNF_SND_OUTPUTPORT_HDMI0,

    HI_UNF_SND_OUTPUTPORT_ARC0,

    HI_UNF_SND_OUTPUTPORT_EXT_DAC1 = 0x50,

    HI_UNF_SND_OUTPUTPORT_EXT_DAC2,

    HI_UNF_SND_OUTPUTPORT_EXT_DAC3,

    HI_UNF_SND_OUTPUTPORT_ALL = 0x7fff,

    HI_UNF_SND_OUTPUTPORT_BUTT,
} HI_UNF_SND_OUTPUTPORT_E;

/**Defines internal Audio DAC outport attribute */
/**CNcomment:\B6\A8\D2\E5\C4\DA\D6\C3\D2\F4ƵDAC\CA\E4\B3\F6\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_DAC_ATTR_S
{
    HI_U32 u32Reserved;
} HI_UNF_SND_DAC_ATTR_S;

/**Defines  Audio I2S outport attribute */
/**CNcomment:\B6\A8\D2\E5\D2\F4ƵI2S\CA\E4\B3\F6\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_I2S_ATTR_S
{
    HI_UNF_I2S_ATTR_S  stAttr;
}  HI_UNF_SND_I2S_ATTR_S;

/**Defines  S/PDIF outport attribute */
/**CNcomment:\B6\A8\D2\E5S/PDIF\CA\E4\B3\F6\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_SPDIF_ATTR_S
{
    HI_U32 u32Reserved;
}  HI_UNF_SND_SPDIF_ATTR_S;

/**Defines  HDMI Audio outport attribute */
/**CNcomment:\B6\A8\D2\E5HDMI\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_HDMI_ATTR_S
{
    HI_U32 u32Reserved;
} HI_UNF_SND_HDMI_ATTR_S;

/**Defines  HDMI ARC outport attribute */
/**CNcomment:\B6\A8\D2\E5HDMI\D2\F4Ƶ\BBش\ABͨ\B5\C0\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_ARC_ATTR_S
{
    HI_U32 u32Reserved;
} HI_UNF_SND_ARC_ATTR_S;

/**Defines  Audio outport attribute */
/**CNcomment:\B6\A8\D2\E5\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA\CA\F4\D0\D4*/
typedef struct hiUNF_SND_OUTPORT_S
{
    HI_UNF_SND_OUTPUTPORT_E enOutPort;
    union
    {
        HI_UNF_SND_DAC_ATTR_S   stDacAttr;
        HI_UNF_SND_I2S_ATTR_S   stI2sAttr;
        HI_UNF_SND_SPDIF_ATTR_S stSpdifAttr;
        HI_UNF_SND_HDMI_ATTR_S  stHDMIAttr;
        HI_UNF_SND_ARC_ATTR_S   stArcAttr;
    } unAttr;
} HI_UNF_SND_OUTPORT_S;

/**Defines  Render attribute */
/**CNcomment:\B6\A8\D2\E5Render\D2\FD\C7\E6\CA\F4\D0\D4*/
typedef struct hiUNF_SND_RENDER_ATTR_S
{
	HI_CHAR* pCommPath;
} HI_UNF_SND_RENDER_ATTR_S;

/**Defines  Audio Sound device attribute */
/**CNcomment:\B6\A8\D2\E5Sound\C9豸\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_ATTR_S
{
    HI_U32                  u32PortNum;  /**<Outport number attached sound*/ /**<CNcomment:\B0󶨵\BDSound\C9豸\B5\C4\CA\E4\B3\F6\B6˿\DA\CA\FD*/
    HI_UNF_SND_OUTPORT_S    stOutport[HI_UNF_SND_OUTPUTPORT_MAX];  /**<Outports attached sound*/ /**<CNcomment:\B0󶨵\BDSound\C9豸\B5\C4\CA\E4\B3\F6\B6˿\DA*/
    HI_UNF_SAMPLE_RATE_E    enSampleRate;       /**<Sound samplerate*/ /**<CNcomment:Sound\C9豸\CA\E4\B3\F6\B2\C9\D1\F9\C2\CA*/
    HI_U32                  u32MasterOutputBufSize; /**<Sound master channel buffer size*/ /**<CNcomment:Sound\C9豸\D6\F7\CA\E4\B3\F6ͨ\B5\C0\BB\BA\B4\E6\B4\F3С*/
    HI_U32                  u32SlaveOutputBufSize;  /**<Sound slave channel buffer size*/ /**<CNcomment:Sound\C9豸\B4\D3\CA\E4\B3\F6ͨ\B5\C0\BB\BA\B4\E6\B4\F3С*/
} HI_UNF_SND_ATTR_S;

/**define SND CAST config  struct */
/**CNcomment:\B6\A8\D2\E5\C9\F9\D2\F4\B9\B2\CF\ED\C5\E4\D6ýṹ\CC\E5*/
typedef struct hiUNF_SND_CAST_ATTR_S
{
    HI_U32  u32PcmFrameMaxNum;     /**<Max frame of the PCM data at cast buffer*/ /**<CNcomment: \D7\EE\B4\F3\BFɻ\BA\B4\E6֡\CA\FD*/
    HI_U32  u32PcmSamplesPerFrame; /**<Number of sample of the PCM data*/ /**<CNcomment: PCM\CA\FD\BEݲ\C9\D1\F9\B5\E3\CA\FD\C1\BF*/
    HI_BOOL bAddMute;              /**<Add mute frame in cast or not>*/ /**<CNcomment: cast\CAǷ\F1\B2\E5\C8뾲\D2\F4֡*/
} HI_UNF_SND_CAST_ATTR_S;

/**HDMI MODE:AUTO,LPCM,RAW,HBR2LBR*/
/**CNcomment:HDMI ģʽ:AUTO,LPCM,RAW,HBR2LBR*/
typedef enum hiHI_UNF_SND_HDMI_MODE_E
{
    HI_UNF_SND_HDMI_MODE_LPCM = 0,       /**<HDMI LCPM2.0*/ /**<CNcomment: \C1\A2\CC\E5\C9\F9pcm*/
    HI_UNF_SND_HDMI_MODE_RAW,            /**<HDMI Pass-through.*/ /**<CNcomment: HDMI͸\B4\AB*/
    HI_UNF_SND_HDMI_MODE_HBR2LBR,        /**<HDMI Pass-through force high-bitrate to low-bitrate.*/ /**<CNcomment: \C0\B6\B9\E2\B4\CE\CA\C0\B4\FA\D2\F4Ƶ\BD\B5\B9\E6\B8\F1\CA\E4\B3\F6*/
    HI_UNF_SND_HDMI_MODE_AUTO,           /**<automatically match according to the EDID of HDMI */ /**<CNcomment: \B8\F9\BE\DDHDMI EDID\C4\DC\C1\A6\D7Զ\AFƥ\C5\E4*/
    HI_UNF_SND_HDMI_MODE_BUTT
} HI_UNF_SND_HDMI_MODE_E;

/**SPDIF MODE:LPCM,RAW*/
/**CNcomment:SPDIF ģʽ:LPCM,RAW*/
typedef enum hiHI_UNF_SND_SPDIF_MODE_E
{
    HI_UNF_SND_SPDIF_MODE_LPCM,           /**<SPDIF LCPM2.0*/ /**<CNcomment: \C1\A2\CC\E5\C9\F9pcm*/
    HI_UNF_SND_SPDIF_MODE_RAW,            /**<SPDIF Pass-through.*/ /**<CNcomment: SPDIF͸\B4\AB*/
    HI_UNF_SND_SPDIF_MODE_BUTT
} HI_UNF_SND_SPDIF_MODE_E;
/** @} */  /** <!-- ==== Structure Definition end ==== */

/**SPDIF Category Code Setting*/
/**CNcomment:\C9\E8\D6\C3SPDIF Category Code\C0\E0\D0\CD*/
typedef enum hiHI_UNF_SND_SPDIF_CATEGORYCODE_E
{
    HI_UNF_SND_SPDIF_CATEGORY_GENERAL = 0x00,       /**<General*/                  /**<CNcomment:ͨ\D3\C3*/
    /*broadcast reception of digitally encoded audio
    with/without video signals*/
    HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_JP = 0x10,  /**<Japan*/                    /**<CNcomment:\C8ձ\BE*/
    HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_USA,        /**<United States*/            /**<CNcomment:\C3\C0\B9\FA*/
    HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_EU,         /**<Europe*/                   /**<CNcomment:ŷ\D6\DE*/
    /*digital converter & signal-processing products*/
    HI_UNF_SND_SPDIF_CATEGORY_PCM_CODEC = 0x20,     /**<PCM Encoder/Decoder*/      /**<CNcomment:PCM\B1\E0\BD\E2\C2\EB*/
    HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_SNDSAMPLER,   /**<Digital Sound Sampler*/    /**<CNcomment:\CA\FD\D7\D6\D2\F4Ƶ\B2\C9\D1\F9\C6\F7*/
    HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_MIXER,        /**<Digital Signal Mixer*/     /**<CNcomment:\CA\FD\D7\D6\D0źŻ\EC\D2\F4\C6\F7*/
    HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_SNDPROCESSOR, /**<Digital Sound Processor*/  /**<CNcomment:\CA\FD\D7\D6\D2\F4Ƶ\B4\A6\C0\ED\C6\F7*/
    HI_UNF_SND_SPDIF_CATEGORY_SRC,                  /**<Sample Rate Converter*/    /**<CNcomment:\B2\C9\D1\F9\C2\CAת\BB\BB\C6\F7*/
    /*laser optical products*/
    HI_UNF_SND_SPDIF_CATEGORY_MD = 0x30,            /**<MiniDisc*/                 /**<CNcomment:\C3\D4\C4\E3\B4Ź\E2\C5\CC*/
    HI_UNF_SND_SPDIF_CATEGORY_DVD,                  /**<Digital Versatile Disc*/   /**<CNcomment:\CA\FD\D7ֶ๦\C4ܹ\E2\C5\CC*/
    /*musical instruments, microphones and other sources
    that create original sound*/
    HI_UNF_SND_SPDIF_CATEGORY_SYNTHESISER = 0x40,   /**<Synthesiser*/              /**<CNcomment:\BAϳ\C9\C6\F7*/
    HI_UNF_SND_SPDIF_CATEGORY_MIC,                  /**<Microphone*/               /**<CNcomment:\C2\F3\BF˷\E7*/
    /*magnetic tape or magnetic disc based products*/
    HI_UNF_SND_SPDIF_CATEGORY_DAT = 0x50,           /**<Digital Audio Tape*/       /**<CNcomment:\CA\FD\D7\D6¼\D2\F4\B4\F8*/
    HI_UNF_SND_SPDIF_CATEGORY_DCC,                  /**<Digital Compact Cassette*/ /**<CNcomment:\CA\FD\D7ֺ\D0ʽ\B4Ŵ\F8¼\D2\F4\BB\FA*/
    HI_UNF_SND_SPDIF_CATEGORY_VCR,                  /**<Video Cassette Recorder*/  /**<CNcomment:\BA\D0ʽ\B4Ŵ\F8¼\CF\F1\BB\FA*/

    HI_UNF_SND_SPDIF_CATEGORY_BUTT
} HI_UNF_SND_SPDIF_CATEGORYCODE_E;

/**SPDIF SCMS Mode Setting*/
/**CNcomment:\C9\E8\D6\C3SPDIF SCMSģʽ*/
typedef enum hiHI_UNF_SND_SPDIF_SCMSMODE_E
{
    HI_UNF_SND_SPDIF_SCMSMODE_COPYALLOW,                /**<Copy Allow*/      /**<CNcomment:\D4\CA\D0\ED\B8\B4\D6\C6*/
    HI_UNF_SND_SPDIF_SCMSMODE_COPYONCE,                 /**<Copy Once*/       /**<CNcomment:\BFɸ\B4\D6\C6һ\B4\CE*/
    HI_UNF_SND_SPDIF_SCMSMODE_COPYNOMORE,               /**<Copy NoMore*/     /**<CNcomment:\B2\BB\BFɸ\B4\D6\C6*/
    HI_UNF_SND_SPDIF_SCMSMODE_COPYPROHIBITED,           /**<Copy prohibited*/ /**<CNcomment:\BD\FBֹ\B8\B4\D6\C6*/
    HI_UNF_SND_SPDIF_SCMSMODE_BUTT
} HI_UNF_SND_SPDIF_SCMSMODE_E;

/**audio effect type, HI_UNF_AUDIO_EFFECT_TYPE_E keep consistent with effect type of ARM/DSP*/
/**CNcomment:\D2\F4Ч\C0\E0\D0ͣ\ACHI_UNF_AUDIO_EFFECT_TYPE_E \B1\D8\D0\EB ARM/DSP \B1\A3\B3\D6Ψһֵ */
typedef enum
{
    HI_UNF_SND_AEF_TYPE_DOLBYDV258 = 0x000,  /**<Dolby audio effect*/ /**<CNcomment: Dolby\D2\F4Ч*/

    HI_UNF_SND_AEF_TYPE_SRS3D = 0x010,      /**<SRS audio effect*/ /**<CNcomment: SRS\D2\F4Ч*/

    HI_UNF_SND_AEF_TYPE_BASE = 0x080,       /**<Base audio effect*/ /**<CNcomment: \D7\D4\D1\D0\D2\F4Ч*/
} HI_UNF_SND_AEF_TYPE_E;

typedef enum hiUNF_PEQ_FILTER_TYPE_E
{
    HI_UNF_PEQ_FILTER_TYPE_HP = 0,  /**<high-pass filter*/ /**<CNcomment: \B8\DFͨ\C2˲\A8\C6\F7 */
    HI_UNF_PEQ_FILTER_TYPE_LS = 1,  /**<low-shelving filter*/ /**<CNcomment: \B5\CDƵ\B8\E9\BC\DC\C2˲\A8\C6\F7 */
    HI_UNF_PEQ_FILTER_TYPE_PK = 2,  /**<peaking filter*/ /**<CNcomment: \B7\E5ֵ\C2˲\A8\C6\F7 */
    HI_UNF_PEQ_FILTER_TYPE_HS = 3,  /**<high-shelving filter*/ /**<CNcomment: \B8\DFƵ\B8\E9\BC\DC\C2˲\A8\C6\F7  */
    HI_UNF_PEQ_FILTER_TYPE_LP = 4,  /**<low-pass filter*/ /**<CNcomment: \B5\CDͨ\C2˲\A8\C6\F7 */
    HI_UNF_PEQ_FILTER_TYPE_BUTT
} HI_UNF_PEQ_FILTER_TYPE_E;

/**Defines PEQ band attribute*/
/**CNcomment:PEQ Ƶ\B4\F8\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_PEQ_BAND_ATTR_S
{
    HI_UNF_PEQ_FILTER_TYPE_E enFltType; /**<filter type of the band*/ /**<CNcomment: ĳһƵ\B4\F8\B5\C4\C2˲\A8\C6\F7\C0\E0\D0\CD*/
    HI_U32 u32freq;  /**<center frequency of the band, HP and LS[20, 4000], PK[20, 22000], HS[4000, 22000], LP[50, 22000]*/
                     /**<CNcomment: ĳһƵ\B4\F8\B5\C4\D6\D0\D0\C4Ƶ\C2\CA,\B7\B6Χ: HP and LS[20, 4000], PK[20, 22000], HS[4000, 22000], LP[50, 22000]*/
    HI_U32 u32Q; /**<Q value of the band, if 2.5, value is 25, range:HS and LS[0.7, 1], PK[0.5, 10],HP and LP is fix to be 0.7*/
                 /**<CNcomment: ĳһƵ\B4\F8\B5\C4qֵ,\C8\E7ֵΪ2.5,\C9\E8\D6\C3ֵΪ25,\B7\B6Χ: HS and LS[0.7, 1], PK[0.5, 10], \B8ߵ\CDͨ\C4ڲ\BF\B9̶\A8Ϊ0.7*/
    HI_S32 s32Gain; /**<gain of the band, if -2.125, value is -2125,Gain ranging from -15 to 15 step by 0.125dB*/
                    /**<CNcomment: ĳһƵ\B4\F8\B5\C4\D4\F6\D2\E6,\C8\E7ֵΪ-2.125,\C9\E8\D6\C3ֵΪ-2125,\B7\B6Χ:[-15, 15],\BE\AB\B6\C80.125*/
} HI_UNF_SND_PEQ_BAND_ATTR_S;

/**Defines PEQ attribute */
/**CNcomment:PEQ\CA\F4\D0\D4 */
typedef struct hiHI_UNF_SND_PEQ_ATTR_S
{
    HI_U32 u32BandNum; /**<the PEQ band number,u32BandNum ranging from 5 to 10*/ /**<CNcomment: PEQƵ\B4\F8\CA\FD\C1\BF,\B7\B6Χ:[5,10]*/
    HI_UNF_SND_PEQ_BAND_ATTR_S stEqParam[HI_UNF_SND_EQ_BANDNUM_MAX];/**<PEQ band attribute*/ /**<CNcomment: PEQƵ\B4\F8\CA\F4\D0\D4*/
} HI_UNF_SND_PEQ_ATTR_S;

/**Defines DRC attribute */
/**CNcomment:DRC\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_DRC_ATTR_S
{
    HI_U32  u32AttackTime;   /**<the attack time(unit:ms),ranging from 20 to 2000*/ /**<CNcomment: \BF\AAʼ\C9\FAЧʱ\BC\E4(\B5\A5λ:ms),\B7\B6Χ:[20, 2000]*/
    HI_U32  u32ReleaseTime;  /**<the release time(unit:ms),ranging from 20 to 2000*/ /**<CNcomment: \BF\AAʼʧЧʱ\BC\E4(\B5\A5λ:ms),\B7\B6Χ:[20, 2000]*/
    HI_S32  s32Thrhd;  /**<the threshold value, if -2.125, value is -2125, threshold ranging from -80dB to -1dB step by 0.125dB*/
                       /**<CNcomment: \BF\AAʼ\CF޷\F9\B7\F9ֵ,\C8\E7ֵΪ-2.125,\C9\E8\D6\C3ֵΪ-2125,\B2\BD\B3\A4Ϊ0.125dB,\B7\B6Χ:[-80dB, -1dB)*/
    HI_S32  s32Limit;  /**<the maximum value, if -2.125, value is -2125, threshold ranging from -80dB to -1dB step by 0.125dB*/
                       /**<CNcomment: \D7\EE\B4\F3\CF޷\F9\B7\F9ֵ,\C8\E7ֵΪ-2.125,\C9\E8\D6\C3ֵΪ-2125,\B2\BD\B3\A4Ϊ0.125dB,\B7\B6Χ:[-80dB, -1dB)*/
    HI_U32  u32RefMode;  /**<refmode(0:process both channel together mode, 1:process each channel independently mode)*/ /**<CNcomment:  0: ԭʼ\B0汾Ч\B9\FB\A3\AC 1\A3\BA\B5\A5\C9\F9\B5\C0\B4\A6\C0\ED\A3\AC \C6\E4\D3\E0\C5\E4\D6\C3\CE\DEЧ*/
    HI_U32  u32SpeedCtrlMode;  /**<speedctrlmode(0:normal mode, 1:fast mode)*/ /**<CNcomment: 0: ԭʼ\B0汾Ч\B9\FB\A3\AC 1: \BDϿ\EC\CBٿ\D8\D6ƣ\AC \C6\E4\D3\E0\C5\E4\D6\C3\CE\DEЧ*/
} HI_UNF_SND_DRC_ATTR_S;

/**Defines  AVC attribute */
/**CNcomment:AVC\CA\F4\D0\D4*/
typedef struct hiHI_UNF_SND_AVC_ATTR_S
{
    HI_S32  s32ThresholdLevel;  /**<the threshold value, if -32.125, value is -32125, ranging from -40dB to -16dB step by 0.125dB*/
                                /**<CNcomment: \B4ﵽ\D7\EE\B4\F3̧\C9\FD\D4\F6\D2\E6\B5\C4ת\D5۵\E7ƽ,\C8\E7ֵΪ-32.125,\C9\E8\D6\C3ֵΪ-32125,\B2\BD\B3\A4Ϊ0.125dB,\B7\B6Χ(-40dB, -16dB)*/
    HI_S32  s32Gain;            /**<the gain value, if 2.125, value is 2125,ranging from 0dB to 8dB step by 0.125dB*/
                                /**<CNcomment: ̧\C9\FD\D4\F6\D2\E6,\C8\E7ֵΪ2.125,\C9\E8\D6\C3ֵΪ2125,\B2\BD\B3\A4Ϊ0.125dB,\B7\B6Χ:[0dB, 8dB]*/
    HI_S32  s32LimiterLevel;    /**<the target level value, if -2.125, value is -2125, ranging from -40dB to 0dB step by 0.125dB*/
                                /**<CNcomment:Ŀ\B1\EAֵ,\C8\E7ֵΪ-2.125,\C9\E8\D6\C3ֵΪ-2125,\B2\BD\B3\A4Ϊ0.125dB,\B7\B6Χ:(-40dB, 0dB]*/
    HI_U32  u32AttackTime;      /**<the attack time(unit:ms),ranging from 20 to 2000,default value 50(recommended)*/ /**<CNcomment: \BF\AAʼ\C9\FAЧʱ\BC\E4(\B5\A5λ:ms),\B7\B6Χ:[20, 2000]\A3\ACĬ\C8\CFֵ50\A3\AC\B2\BB\BD\A8\D2\E9\D0޸\C4*/
    HI_U32  u32ReleaseTime;     /**<the release time(unit:ms),ranging from 20 to 2000,default value 100(recommended)*/ /**<CNcomment: \BF\AAʼʧЧʱ\BC\E4(\B5\A5λ:ms),\B7\B6Χ:[20, 2000]\A3\ACĬ\C8\CFֵ100\A3\AC\B2\BB\BD\A8\D2\E9\D0޸\C4*/
} HI_UNF_SND_AVC_ATTR_S;

/**Audio output latency mode*/
/**CNcomment:\D2\F4Ƶ\CA\E4\B3\F6ʱ\D1\D3ģʽ*/
typedef enum
{
    HI_UNF_SND_OUTPUTLATENCY_NORMAL = 0,  /**<normal latency MS12 ONLY.*/ /**<CNcomment:ͨ\D3\C3ʱ\D1\D3*/
    HI_UNF_SND_OUTPUTLATENCY_LOW,         /**<low latency MS12 ONLY*/     /**<CNcomment:\B5\CDʱ\D1\D3*/
    HI_UNF_SND_OUTPUTLATENCY_BUTT,
} HI_UNF_SND_OUTPUTLATENCY_E;

/******************************* API declaration *****************************/
/** \addtogroup      SOUND */
/** @{ */  /** <!--  \A1\BESOUND\A1\BF */

/**
\brief Initializes an AO device. CNcomment:\B3\F5ʼ\BB\AF\D2\F4Ƶ\CA\E4\B3\F6\C9豸 CNend
\attention \n
Before calling the SND module, you must call this application programming interface (API). CNcomment:\B5\F7\D3\C3SNDģ\BF\E9Ҫ\C7\F3\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Init(HI_VOID);

/**
\brief Deinitializes an AO device. CNcomment:ȥ\B3\F5ʼ\BB\AF\D2\F4Ƶ\CA\E4\B3\F6\C9豸 CNend
\attention \n
N/A
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_DeInit(HI_VOID);

/**
\brief Obtains the default configured parameters of an AO device. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6\C9豸Ĭ\C8\CF\C9\E8\D6ò\CE\CA\FD CNend
\attention \n
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pstAttr     Audio attributes CNcomment:\D2\F4Ƶ\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetDefaultOpenAttr(HI_UNF_SND_E enSound, HI_UNF_SND_ATTR_S* pstAttr);

/**
\brief Starts an AO device. CNcomment:\B4\F2\BF\AA\D2\F4Ƶ\CA\E4\B3\F6\C9豸 CNend
\attention \n
One port only can attach to one sound.
CNcomment:ÿ\B8\F6\B6˿\DAֻ\C4ܰ\F3\B6\A8һ\B8\F6sound CNend
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] pstAttr     Attribute of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Open(HI_UNF_SND_E enSound, const HI_UNF_SND_ATTR_S* pstAttr);

/**
\brief Destroys a AO SND instance. CNcomment:\CF\FA\BB\D9\D2\F4Ƶ\CA\E4\B3\F6Soundʵ\C0\FD CNend
\attention \n
An instance cannot be destroyed repeatedly. CNcomment:\B2\BB֧\B3\D6\D6ظ\B4\CF\FA\BB\D9 CNend
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Close(HI_UNF_SND_E enSound);


/**
\brief Sets the mute status of  AO ports. CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\BE\B2\D2\F4\BF\AA\B9\D8\C9\E8\D6\C3 CNend
\attention \n
N/A
\param[in] enSound
\param[in] enOutPort CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[in] bMute
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetMute(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bMute);

/**
\brief Obtains the mute status of AO ports. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6\B5ľ\B2\D2\F4\BF\AA\B9\D8״̬ CNend
\attention \n
N/A
\param[in] enSound CNcomment:
\param[in] enOutPort CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[out] pbMute CNcomment:
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetMute(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL* pbMute);

/**
\brief Sets the output mode of the HDMI(Auto/PCM/RAW/HBR2LBR).
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] enHdmiMode HDMI mode CNcomment:HDMIģʽCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetHdmiMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_HDMI_MODE_E enHdmiMode);

/**
\brief Gets the output mode of the HDMI.
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] Pointer to the obtained HDMI mode CNcomment:\BB\F1ȡ\B5\BD\B5\C4HDMIģʽ\B5\C4ָ\D5\EBCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetHdmiMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_HDMI_MODE_E* penHdmiMode);

/**
\brief Sets the output mode of the SPDIF(PCM/RAW).
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] enHdmiMode SPDIF mode CNcomment:SPDIFģʽCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID    The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetSpdifMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_MODE_E enSpdifMode);

/**
\brief Gets the output mode of the SPDIF.
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] penSpdifMode Pointer to the obtained SPDIF mode CNcomment:\BB\F1ȡ\B5\BD\B5\C4SPDIFģʽ\B5\C4ָ\D5\EBCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID    The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetSpdifMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_MODE_E* penSpdifMode);

/**
 \brief Sets the output volume value. CNcomment:\C9\E8\D6\C3\CA\E4\B3\F6\D2\F4\C1\BF CNend
 \attention \n
If s32Gain is set to a value greater than 100 or 0dB, then return failure. CNcomment:\C8\E7\B9\FBs32Gain\C9\E8\D6ô\F3\D3\DA100\BB\F20dB\A3\AC\B7\B5\BB\D8ʧ\B0\DC CNend
 \param[in] enSound        ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
 \param[in] pstGain     Volume value CNcomment:\C9\E8\D6õ\C4\D2\F4\C1\BFֵ CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_AO_INVALID_PARA       The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
 \retval ::HI_ERR_SND_INVALID_ID        The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
 \retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
 \see \n
N/A
 */
HI_S32   HI_UNF_SND_SetVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, const HI_UNF_SND_GAIN_ATTR_S* pstGain);

/**
\brief Obtains the output volume value. CNcomment:\BB\F1ȡ\CA\E4\B3\F6\D2\F4\C1\BF CNend
\attention \n
The default linear volume value is 100 and abslute volume is 0dB. CNcomment:\B2\E9ѯ\B5\C4Ĭ\C8\CF\D2\F4\C1\BFֵΪ100(\CF\DF\D0\D4\D2\F4\C1\BF) and 0dB(\BE\F8\B6\D4\D2\F4\C1\BF) CNend
\param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
 \param[out] pstGain    Pointer to the obtained volume value CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\F1ȡ\B5\BD\B5\C4\D2\F4\C1\BFֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_GAIN_ATTR_S* pstGain);

/**
\brief Sets the category code of the SPDIF.
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] enSpdifCategoryCode  SPDIF category code CNcomment:SPDIF \CA\E4\B3\F6\C9豸\B7\D6\C0\E0\C2\EBCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID    The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSpdifCategoryCode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_CATEGORYCODE_E enSpdifCategoryCode);

/**
\brief Gets the category code of the SPDIF.
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] enSpdifCategoryCode Pointer to the obtained category code CNcomment:\BB\F1ȡ\B5\BD\B5ķ\D6\C0\E0\C2\EB\B5\C4ָ\D5\EBCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN      Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID          The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR            The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetSpdifCategoryCode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_CATEGORYCODE_E* penSpdifCategoryCode);

/**
\brief Sets the SCMS mode of the SPDIF(COPYALLOW/COPYONCE/COPYPROHIBITED).
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] enSpdifSCMSMode  SPDIF SCMS mode CNcomment:SPDIF SCMS ģʽCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID    The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSpdifSCMSMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_SCMSMODE_E enSpdifSCMSMode);

/**
\brief Gets the SCMS mode of the SPDIF.
\attention \n
\param[in] enSound CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5  CNend
\param[in] enOutPort  Audio OutputPort   CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] enSpdifSCMSMode Pointer to the obtained SPDIF SCMS mode CNcomment:\BB\F1ȡ\B5\BD\B5\C4SPDIF SCMSģʽ\B5\C4ָ\D5\EBCNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN      Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID          The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR            The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetSpdifSCMSMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_SPDIF_SCMSMODE_E* enSpdifSCMSMode);

/**
\brief Sets the sampling rate during audio output. CNcomment:\C9\E8\D6\C3\D2\F4Ƶ\CA\E4\B3\F6ʱ\B5Ĳ\C9\D1\F9\C2\CA CNend
\attention \n
At present, the sampling rate cannot be set, and it is fixed at 48 kHz. The streams that are not sampled at 48 kHz are resampled at 48 kHz.
CNcomment:Ŀǰ\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAĬ\C8\CFΪ48k(ʵ\BC\CA\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAΪ48K~192K)\A3\AC֧\B3ִ\D38K\B5\BD192K\C2\EB\C1\F7\CA\E4\C8룬\D2\F2\D7\EE\B4\F3֧\B3\D66\B1\B6\D6ز\C9\D1\F9\A3\AC\n
\D2\F2\B4˵\B1\C9趨\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAΪ192Kʱ(ʵ\BC\CA\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAΪ192K)\A3\AC\B2\A5С\D3\DA32K\B5\C4\C2\EB\C1\F7\BB\E1\B3\F6\B4\ED(\B4\CBʱ\B2\BBӰ\CF\EC\C6\E4\CB\FC\B2\C9\D1\F9\C2ʵ\C4\C2\EB\C1\F7\C7л\BB)\n
Ȼ\B6\F8\B5\B1\C9趨\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAΪ8Kʱ(ʵ\BC\CA\CA\E4\B3\F6\B2\C9\D1\F9\C2\CAΪ8K~192K)\A3\AC\B4\CBʱ\B2\BB\C4\DCͨ\B9\FDHDMI\CA\E4\B3\F6С\D3\DA32K\B5\C4\C2\EB\C1\F7(HDMI\B2\BB֧\B3\D6) CNend
\param[in] enSound          ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enSampleRate    Audio sampling rate. For details, see the description of ::HI_UNF_SAMPLE_RATE_E. CNcomment:\D2\F4Ƶ\B2\C9\D1\F9\C2ʡ\A3\C7\EB\B2μ\FB::HI_UNF_SAMPLE_RATE_E CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E enSampleRate);

/**
\brief Obtains the sampling rate during audio output. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6ʱ\B5Ĳ\C9\D1\F9\C2\CA CNend
\attention \n
The 48 kHz sampling rate is returned by default. CNcomment:\B4˽ӿ\DAĬ\C8Ϸ\B5\BB\D848kHz\B2\C9\D1\F9\C2\CA CNend
\param[in] enSound           ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] penSampleRate   Pointer to the type of the audio sampling rate CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D2\F4Ƶ\B2\C9\D1\F9\C2ʵ\C4\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E* penSampleRate);

/**
\brief set aduiodelay for output port. CNcomment: \C9\E8\D6\C3\D2\F4Ƶ\B6˿\DA\D1\D3ʱCNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort output port .CNcomment:\CA\E4\B3\F6\B6˿ں\C5 CNend
\param[in] u32DelayMs Audio delay ms .CNcomment:\D1\D3ʱʱ\B3\A4 CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetDelayCompensationMs(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_U32 u32DelayMs);

/**
\brief get aduiodelay for output port. CNcomment: \BB\F1ȡ\D2\F4Ƶ\B6˿\DA\D1\D3ʱCNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort output port .CNcomment:\CA\E4\B3\F6\B6˿ں\C5 CNend
\param[in] pu32DelayMs Audio delay ms .CNcomment:\D1\D3ʱʱ\B3\A4 CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetDelayCompensationMs(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_U32* pu32DelayMs);

/**
\brief enable ADAC audio output. CNcomment: \C9\E8\D6\C3ADAC \CAǷ\F1\CA\E4\B3\F6 CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] bEnable enable ADAC output .CNcomment:\C9\E8\D6\C3ADAC \CAǷ\F1\CA\E4\B3\F6 CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAdacEnable(HI_UNF_SND_E enSound, HI_BOOL bEnable);

/**
\brief Sets the smart volume for audio output. CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\BD\F8\D0\D0\D6\C7\C4\DC\D2\F4\C1\BF\B4\A6\C0\ED\B4\A6\C0\ED\BF\AA\B9\D8\C9\E8\D6\C3 CNend
\attention \n
1. The smart volume is disabled by default.\n
2. The smart volume is valid only for the track.\n
3. The smart volume is enabled only when the program is switched.
CNcomment:1. Ĭ\C8Ϲرո\C3\D6\C7\C4\DC\D2\F4\C1\BF\n
2. \D6\C7\C4\DC\D2\F4\C1\BF\BD\F6\B6\D4track\D3\D0Ч\n
3. \D6\C7\C4\DC\D2\F4\C1\BF\BD\F6\D4\DA\C7л\BB\BD\DAĿʱ\B4\A5\B7\A2 CNend
\param[in] hTrack           Track handle CNcomment:Track \BE\E4\B1\FA CNend
\param[in] bSmartVolume     Smart volume enable, HI_TRUE: enabled; HI_FALSE: disabled CNcomment:\CAǷ\F1\B4\F2\BF\AA\D6\C7\C4\DC\D2\F4\C1\BF\A1\A3HI_TRUE\A3\BA\B4򿪣\BBHI_FALSE\A3\BA\B9ر\D5 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_NOTSUPPORT Unsupport CNcomment:\B2\BB֧\B3\D6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetTrackSmartVolume(HI_HANDLE hTrack, HI_BOOL bEnable);

/**
\brief Obtains the status of the smart volume for audio output. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6\D6\C7\C4\DC\D2\F4\C1\BF\BF\AA\B9\D8״̬ CNend
\attention \n
\param[in] hTrack           Track handle CNcomment:Track \BE\E4\B1\FA CNend
\param[out] pbSmartVolume     Pointer to the enable status of the smart volume CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\CAǷ\F1\B4\F2\BF\AA\D6\C7\C4\DC\D2\F4\C1\BF CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE Failure CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_NOTSUPPORT Unsupport CNcomment:\B2\BB֧\B3\D6 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetTrackSmartVolume(HI_HANDLE hTrack, HI_BOOL* pbEnable);

/**
\brief Seting low latency threshold for audio output. CNcomment: \C9\E8\D6\C3Sound\B6˿ڵ\CD\D1\D3ʱ\CF\DE\D6\C6 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  CNcomment:sound \CA\E4\B3\F6\B6˿\DA CNend
\param[in] u32LatecnyMs,  latency ms .CNcomment:\C9\E8\D6õ\C4\D1\D3ʱ\B4\F3С CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetLowLatency(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E eOutPort, HI_U32 u32LatecnyMs);

/**
\brief Geting low latency threshold for audio output. CNcomment: \BB\F1ȡSound\B6˿ڵ\CD\D1\D3ʱ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  CNcomment:sound \CA\E4\B3\F6\B6˿\DA CNend
\param[in] pu32LatecnyMs,  latency ms .CNcomment:\D1\D3ʱ\B4\F3С CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetLowLatency(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E eOutPort, HI_U32* p32LatecnyMs);

/**
\brief Set the AO track mode. CNcomment:\C9\E8\D6\C3\D2\F4Ƶ\CA\E4\B3\F6\C9\F9\B5\C0ģʽ CNend
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort   CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[in] enMode     Audio track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E. CNcomment:\D2\F4Ƶ\C9\F9\B5\C0ģʽ\A3\AC\C7\EB\B2μ\FB::HI_UNF_TRACK_MODE_E CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetTrackMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_TRACK_MODE_E enMode);

/**
\brief Obtains the AO track mode. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6\C9\F9\B5\C0ģʽ CNend
\attention \n
N/A
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort   CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[out] penMode   Pointer to the AO track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E.
CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D2\F4Ƶ\C9\F9\B5\C0ģʽ\A1\A3\C7\EB\B2μ\FB::HI_UNF_TRACK_MODE_E CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetTrackMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_TRACK_MODE_E* penMode);

/**
\brief Attaches the SND module to an audio/video player (AVPLAY). CNcomment:\B0\F3\B6\A8\D2\F4Ƶ\CA\E4\B3\F6Sound\BA\CDAV\A3\A8Audio Video\A3\A9\B2\A5\B7\C5\C6\F7 CNend
\attention \n
Before calling this API, you must create a player and ensure that the player has no output. CNcomment:\B5\F7\D3ô˽ӿ\DAǰ\B1\D8\D0\EB\CFȴ\B4\BD\A8\B2\A5\B7\C5\C6\F7\A3\AC\B6\D4Ӧ\D5\E2·\B2\A5\B7\C5\C6\F7û\D3\D0\CA\E4\B3\F6 CNend
\param[in] hTrack             Instance handle of an AVPLAY CNcomment:Track ʵ\C0\FD\BE\E4\B1\FA CNend
\param[in] hSource           Instance handle of an AVPLAY CNcomment:AV\B2\A5\B7\C5\C6\F7\B2\A5\B7\C5ʵ\C0\FD\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_Attach(HI_HANDLE hTrack, HI_HANDLE hSource);

/**
\brief Detaches the SND module from an AVPLAY. CNcomment:\BD\E2\B3\FDTrack\BA\CDAV\B2\A5\B7\C5\C6\F7\B0\F3\B6\A8 CNend
\attention \n
N/A
\param[in] hTrack             Instance handle of an AVPLAY CNcomment:Track ʵ\C0\FD\BE\E4\B1\FA CNend
\param[in] hSource    Instance handle of an AVPLAY CNcomment:AV\B2\A5\B7\C5\C6\F7\B2\A5\B7\C5ʵ\C0\FD\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_Detach(HI_HANDLE hTrack, HI_HANDLE hSource);

/**
\brief Sets the mixing weight of an audio player. CNcomment:\C9\E8\D6\C3\D2\F4ƵTrack \BB\EC\D2\F4Ȩ\D6\D8 CNend
\attention \n
The output volumes of two players are calculated as follows: (volume x weight 1 + volume x weight 2)/100. The formula of calculating the output volumes of multiple players is similar.
CNcomment:\C1\BD\B8\F6Track \CA\E4\B3\F6\D2\F4\C1\BF\B5ļ\C6\CB㷽\B7\A8Ϊ\A3\BA\A3\A8\C9\E8\D6õ\C4\D2\F4\C1\BF%Ȩ\D6\D81+\C9\E8\D6õ\C4\D2\F4\C1\BF%Ȩ\D6\D82\A3\A9/100\A3\AC\B6\E0\B8\F6\B2\A5\B7\C5\C6\F7\B5ļ\C6\CB㷽\B7\A8\D3\EB\B4\CB\C0\E0\CB\C6 CNend
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] pstMixWeightGain   the MixWeight Gain, ranging from 0 to 100. 0: minimum value; 100: maximum value CNcomment:Ȩ\D6أ\AC\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\D7\EEСֵ\A3\BB100\A3\BA\D7\EE\B4\F3ֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_SetTrackWeight(HI_HANDLE hTrack, const HI_UNF_SND_GAIN_ATTR_S* pstMixWeightGain);

/**
\brief Obtains the mixing weight of an audio player. CNcomment:\BB\F1ȡ\D2\F4Ƶ\B2\A5\B7\C5\C6\F7\BB\EC\D2\F4Ȩ\D6\D8 CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] pstMixWeightGain     Pointer to the MixWeight Gain CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACȨ\D6\D8\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetTrackWeight(HI_HANDLE hTrack, HI_UNF_SND_GAIN_ATTR_S* pstMixWeightGain);

/**
\brief Sets the L/R channel weight of an audio player. CNcomment:\C9\E8\D6\C3\D2\F4ƵTrack\D7\F3\D3\D2\C9\F9\B5\C0Ȩ\D6\D8 CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] pstAbsWeightGain   the channel Weight Gain CNcomment:Ȩ\D6\D8 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_SetTrackAbsWeight(HI_HANDLE hTrack, const HI_UNF_SND_ABSGAIN_ATTR_S* pstAbsWeightGain);

/**
\brief Obtains the L/R channel weight of an audio player. CNcomment:\BB\F1ȡ\D2\F4Ƶ\B2\A5\B7\C5\C6\F7\D7\F3\D3\D2\C9\F9\B5\C0Ȩ\D6\D8 CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] pstAbsWeightGain     Pointer to the ChannelWeight Gain CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACȨ\D6\D8\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_GetTrackAbsWeight(HI_HANDLE hTrack, HI_UNF_SND_ABSGAIN_ATTR_S* pstAbsWeightGain);

/**
\brief Sets the prescale of an audio player. CNcomment:\C9\E8\D6\C3\D2\F4ƵTrack\B5\C4Ԥ\D4\F6\D2\E6 CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] pstPreciGain        Pointer of the prescale CNcomment:Ԥ\D4\F6\D2\E6\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_SetTrackPrescale(HI_HANDLE hTrack, const HI_UNF_SND_PRECIGAIN_ATTR_S* pstPreciGain);

/**
\brief Obtains the prescale of an audio player. CNcomment:\BB\F1ȡ\D2\F4ƵTrack\B5\C4Ԥ\D4\F6\D2\E6 CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[out] pstPreciGain        Pointer to the prescale CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACԤ\D4\F6\D2\E6\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_GetTrackPrescale(HI_HANDLE hTrack, HI_UNF_SND_PRECIGAIN_ATTR_S* pstPreciGain);

/**
\brief Sets mute or unmute of an audio player. CNcomment:\C9\E8\D6õ\A5\B8\F6\D2\F4ƵTrack \BE\B2\D2\F4\B9\A6\C4\DC CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] bMute               mute or not CNcomment:\BE\B2\D2\F4\D3\EB\B7\F1 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_SetTrackMute(HI_HANDLE hTrack, HI_BOOL bMute);

/**
\brief Gets mute status of an audio player. CNcomment:\BB\F1ȡ\B5\A5\B8\F6\D2\F4ƵTrack\B5ľ\B2\D2\F4״̬ CNend
\attention \n
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[out] pbMute               mute status CNcomment:\BE\B2\D2\F4״̬ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA       The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_GetTrackMute(HI_HANDLE hTrack, HI_BOOL* pbMute);

/**
\brief Sets mute or unmute of all players. CNcomment:\C9\E8\D6\C3\CB\F9\D3\D0\D2\F4ƵTrack \BE\B2\D2\F4\B9\A6\C4\DC CNend
\attention \n
\param[in] enSound              all track of the sound CNcomment:\B8\C3sound\CB\F9\D3\D0track CNend
\param[in] bMute               mute or not CNcomment:\BE\B2\D2\F4\D3\EB\B7\F1 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_SetAllTrackMute(HI_UNF_SND_E enSound, HI_BOOL bMute);

/**
\brief Gets mute status of all players. CNcomment:\BB\F1ȡ\CB\F9\D3\D0\D2\F4ƵTrack\B5ľ\B2\D2\F4״̬ CNend
\attention \n
\param[in] enSound              all track of the sound CNcomment:\B8\C3sound track CNend
\param[in] pbMute               mute status CNcomment:\BE\B2\D2\F4״̬ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA       The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_GetAllTrackMute(HI_UNF_SND_E enSound, HI_BOOL* pbMute);

/**
\brief Set the track channel mode. CNcomment:\C9\E8\D6\C3\D2\F4ƵTrack  \C9\F9\B5\C0ģʽ CNend
\attention \n
N/A
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[in] enMode             The audio track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E. CNcomment:\D2\F4Ƶ\C9\F9\B5\C0ģʽ\A3\AC\C7\EB\B2μ\FB::HI_UNF_TRACK_MODE_E CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetTrackChannelMode(HI_HANDLE hTrack, HI_UNF_TRACK_MODE_E enMode);

/**
\brief Obtains the track channel mode. CNcomment:\BB\F1ȡ\D2\F4ƵTrack \C9\F9\B5\C0ģʽ CNend
\attention \n
N/A
\param[in] hTrack              ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6Track CNend
\param[out] penMode   Pointer to the audio track mode. For details, see the description of ::HI_UNF_TRACK_MODE_E.
CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\D2\F4Ƶ\C9\F9\B5\C0ģʽ\A1\A3\C7\EB\B2μ\FB::HI_UNF_TRACK_MODE_E CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetTrackChannelMode(HI_HANDLE hTrack, HI_UNF_TRACK_MODE_E* penMode);

/**
 \brief Obtains the default configured parameters of an AO Track. CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6TrackĬ\C8\CF\C9\E8\D6ò\CE\CA\FD CNend
 \attention \n
 \param[in] enTrackType              Track Type CNcomment:Track\C0\E0\D0\CD CNend
 \param[out] pstAttr     Audio attributes CNcomment:\D2\F4Ƶ\CA\F4\D0\D4 CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE  Failure  CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
 \see \n
N/A
 */
HI_S32   HI_UNF_SND_GetDefaultTrackAttr(HI_UNF_SND_TRACK_TYPE_E enTrackType, HI_UNF_AUDIOTRACK_ATTR_S* pstAttr);

/**
\brief Create a Track. CNcomment:\B4\B4\BD\A8һ·Track CNend
\attention \n
Create 8 output tracks(master/slave track) and 6 virtual tracks at the most. only create 1 master track on every sound.
CNcomment:\D7\EE\B6\E0\BFɴ\B4\BD\A88·\CA\E4\B3\F6track(master/slave), 6·\D0\E9\C4\E2track\A3\ACÿ\B8\F6soundֻ\C4ܴ\B4\BD\A8һ·master track CNend
\param[in] enSound     ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] pTrackAttr  Track attributes CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACTrack  \CA\F4\D0\D4 CNend
\param[out] phTrack   Pointer to the handle of the created Track CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\B4\BD\A8\B5\C4Track \BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE  Failure  CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_CreateTrack(HI_UNF_SND_E enSound, const HI_UNF_AUDIOTRACK_ATTR_S* pTrackAttr, HI_HANDLE* phTrack);

/**
\brief Destroy a Track. CNcomment:\CF\FA\BB\D9һ·Track CNend
\attention \n
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_DestroyTrack(HI_HANDLE hTrack);

/**
\brief set the attribute of  a track, reversed. CNcomment:\C9\E8\D6\C3ĳһ·track\B5\C4\CA\F4\D0ԣ\AC Ԥ\C1\F4 CNend
\attention \n
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[in] stTrackAttr   the attribute of the Track CNcomment:Track \CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetTrackAttr(HI_HANDLE hTrack, const HI_UNF_AUDIOTRACK_ATTR_S* pstTrackAttr);

/**
\brief get the attribute of  a track, reversed. CNcomment:\BB\F1ȡĳһ·track\B5\C4\CA\F4\D0ԣ\AC Ԥ\C1\F4 CNend
\attention \n
1.virtual track Attr not support set.\n
2.pstTrackAttr struct: just enTrackType&u32BufLevelMs can be set ,other members not support.
CNcomment:1.\D0\E9\C4\E2track\B2\BB֧\B3\D6\C9\E8\D6\C3\CA\F4\D0\D4\n
2.pstTrackAttr\BDṹ\CC\E5\D6н\F6enTrackType&u32BufLevelMs\BF\C9\D2\D4\C9\E8\D6ã\AC\C6\E4\CB\FB\B3\C9Ա\B2\BB֧\B3\D6 CNend
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[out] pstTrackAttr   the attribute of the Track CNcomment:Track \CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetTrackAttr(HI_HANDLE hTrack, HI_UNF_AUDIOTRACK_ATTR_S* pstTrackAttr);

/**
\brief set the config of a track. CNcomment:\C5\E4\D6\C3ĳһ·track\CA\F4\D0\D4 CNend
\attention \n
1.only support ms12 type track.
CNcomment:1.\BD\F6֧\B3\D6ms12\C0\E0\D0\CDtrack CNend
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[in] pstConfig   the config of the Track CNcomment:Track \C5\E4\D6\C3\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetTrackConfig(HI_HANDLE hTrack, const HI_UNF_AUDIOTRACK_CONFIG_S* pstConfig);

/**
\brief get the config of a track. CNcomment:\BB\F1ȡĳһ·track\B5\C4\C5\E4\D6\C3 CNend
\attention \n
1.only support ms12 type track.
CNcomment:1.\BD\F6֧\B3\D6ms12\C0\E0\D0\CDtrack CNend
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[out] pstConfig   the config of the Track CNcomment:Track \C5\E4\D6\C3\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_ID The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetTrackConfig(HI_HANDLE hTrack, HI_UNF_AUDIOTRACK_CONFIG_S* pstConfig);

/**
\brief Acquire the audio frame from the track. CNcomment:\BB\F1ȡĳһ·track\B5\C4\D2\F4Ƶ֡ CNend
\attention \n
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[in] u32TimeoutMs         acquire timeout.CNcomment:\BB\F1ȡ\B3\ACʱ CNend
\param[out] pstAOFrame the audio frame  CNcomment:Track \D2\F4Ƶ֡ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_INVALID_ID The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA   The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_AcquireTrackFrame(HI_HANDLE hTrack, HI_UNF_AO_FRAMEINFO_S* pstAOFrame, HI_U32 u32TimeoutMs);

/**
\brief Release the audio frame . CNcomment:\CAͷ\C5track \D2\F4Ƶ֡ CNend
\attention \n
\param[in] hTrack   the handle of the Track CNcomment:Track \BE\E4\B1\FA CNend
\param[in] pstAOFrame the audio frame  CNcomment:Track \D2\F4Ƶ֡ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_INVALID_ID  The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_ReleaseTrackFrame(HI_HANDLE hTrack, HI_UNF_AO_FRAMEINFO_S* pstAOFrame);

/**
\brief  Transmits data to a slave track directly. CNcomment:ֱ\BDӽ\AB\CA\FD\BE\DD\CB͵\BDslave track CNend
\attention \n
1. If HI_ERR_AO_OUT_BUF_FULL is returned, you need to transmit the data that fails to be transmitted last time to ensure the audio continuity.
2. For the PCM data, the restrictions are as follows:
    s32BitPerSample must be set to 16.
    bInterleaved must be set to HI_TRUE. Only interlaced mode is supported.
    u32Channels can be set to 1 or 2.
    u32PtsMs can be ignored.
    ps32PcmBuffer indicates the PCM data pointer.
    ps32BitsBuffer can be ignored.
    u32PcmSamplesPerFrame indicates the number of audio sampling. The data length (in byte) is calculated as follows: u32PcmSamplesPerFrame x u32Channels x sizeof(HI_u16)
    u32BitsBytesPerFrame can be ignored.
    u32FrameIndex can be ignored.
CNcomment:1 \C8\E7\B9\FB\B7\B5\BB\D8HI_ERR_AO_OUT_BUF_FULL\A3\AC\D0\E8Ҫ\B5\F7\B6\C8\D5߼\CC\D0\F8\CB\CD\C9ϴ\CEʧ\B0\DC\CA\FD\BEݣ\AC\B2\C5\C4ܱ\A3֤\C9\F9\D2\F4\B5\C4\C1\AC\D0\F8
2 PCM \CA\FD\BEݸ\F1ʽ\D4ڻ\EC\D2\F4\C6\F7\B5\C4\CF\DE\D6\C6\C8\E7\CF\C2
    s32BitPerSample: \B1\D8\D0\EBΪ16
    bInterleaved: \B1\D8\D0\EBΪHI_TRUE, \BD\F6֧\B3ֽ\BB֯ģʽ
    u32Channels: 1 \BB\F22
    u32PtsMs: \BA\F6\C2Ըò\CE\CA\FD
    ps32PcmBuffer: PCM \CA\FD\BE\DDָ\D5\EB
    ps32BitsBuffer: \BA\F6\C2Ըò\CE\CA\FD
    u32PcmSamplesPerFrame: \D2\F4Ƶ\D1\F9\B5\E3\CA\FD, \CA\FD\BEݳ\A4\B6\C8(unit:Bytes): u32PcmSamplesPerFrame*u32Channels*sizeof(HI_u16)
    u32BitsBytesPerFrame: \BA\F6\C2Ըò\CE\CA\FD
    u32FrameIndex: \BA\F6\C2Ըò\CE\CA\FD CNend
\param[in] hTrack   Track handle CNcomment:Track \BE\E4\B1\FA CNend
\param[in] pstAOFrame   Information about the audio data CNcomment:\D2\F4Ƶ\CA\FD\BE\DD\D0\C5Ϣ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_NULL_PTR    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_PARA    The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_OUT_BUF_FULL  Data fails to be transmitted because the mixer buffer is full. CNcomment:\BB\EC\D2\F4\BB\BA\B3\E5\C7\F8\CA\FD\BE\DD\C2\FA\A3\AC\CB\CD\CA\FD\BE\DDʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SendTrackData(HI_HANDLE hTrack, const HI_UNF_AO_FRAMEINFO_S* pstAOFrame);

/**
\brief Obtains the delay ms of track. CNcomment:\BB\F1ȡ\D2\F4ƵTrack\D1\D3ʱʱ\BC\E4 CNend
\attention \n
\param[in] hTrack     ID of ao track CNcomment:\D2\F4ƵTrack ID CNend
\param[out] pDelayMs     DelayMs attributes CNcomment:Track\D1\D3ʱʱ\BC\E4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetTrackDelayMs(const HI_HANDLE hTrack, HI_U32* pDelayMs);

/**
\brief Sets the output high precision volume value. CNcomment:\C9\E8\D6\C3\CA\E4\B3\F6\B5ĸ߾\AB\B6\C8\D2\F4\C1\BF CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound        ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] pstPreciGain     high precision volume value CNcomment:\C9\E8\D6õĸ߾\AB\B6\C8\D2\F4\C1\BFֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_SND_INVALID_ID     The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetPrecisionVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, const HI_UNF_SND_PRECIGAIN_ATTR_S* pstPreciGain);

/**
\brief Obtains the output high precision volume value. CNcomment:\BB\F1ȡ\CA\E4\B3\F6\B5ĸ߾\AB\B6\C8\D2\F4\C1\BF CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] pstPreciGain   Pointer to the obtained high precision volume value CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\F1ȡ\B5\BD\B5ĸ߾\AB\B6\C8\D2\F4\C1\BFֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetPrecisionVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_PRECIGAIN_ATTR_S* pstPreciGain);

/**
\brief Sets the output balance. CNcomment:\C9\E8\D6\C3\CA\E4\B3\F6\B5\C4ƽ\BA\E2 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound        ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] s32Balance     balance value CNcomment:\C9\E8\D6õ\C4ƽ\BA\E2ֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_SND_INVALID_ID     The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetBalance(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_S32 s32Balance);

/**
\brief Obtains balance value. CNcomment:\BB\F1ȡ\CA\E4\B3\F6\B5\C4ƽ\BA\E2ֵ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] ps32Balance   Pointer to the obtained balance value CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\F1ȡ\B5\BD\B5\C4ƽ\BA\E2ֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetBalance(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_S32* ps32Balance);

/**
\brief Start render engine. CNcomment:\C6\F4\B6\AFRender\D2\FD\C7\E6 CNend
\attention \n
N/A
\param[in] enSound  Render of the sound CNcomment:\B4\CBSound\B5\C4Render CNend
\param[in] pstAttr  Attr of Render CNcomment: Render\C6\F4\B6\AF\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_StartRender(HI_UNF_SND_E enSound, HI_UNF_SND_RENDER_ATTR_S* pstAttr);

/**
\brief Stop render engine. CNcomment:\B9ر\D5Render\D2\FD\C7\E6 CNend
\attention \n
N/A
\param[in] enSound  Render of the sound CNcomment:\B4\CBSound\B5\C4Render CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_StopRender(HI_UNF_SND_E enSound);

/**
\brief create screen share channel. CNcomment: \BB\F1ȡ\B9\B2\CF\EDͨ\B5\C0\C9\E8\D6\C3Ĭ\C8\CF\CA\F4\D0\D4 CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound      display channel.CNcomment:\B2\A5\B7\C5ͨ· CNend
\param[out] pstAttr      handle of default attr  .CNcomment:\C9\E8\D6\C3Ĭ\C8\CF\CA\F4\D0Ծ\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32   HI_UNF_SND_GetDefaultCastAttr(HI_UNF_SND_E enSound, HI_UNF_SND_CAST_ATTR_S* pstAttr);

/**
\brief create screen share channel. CNcomment: \B4\B4\BD\A8\C9\F9\D2\F4\B9\B2\CF\EDͨ\B5\C0 CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound      display channel.CNcomment:\B2\A5\B7\C5ͨ· CNend
\param[in] pstAttr      pointer of parameter .CNcomment:ָ\D5\EB,\CA\F4\D0Բ\CE\CA\FD CNend
\param[out] phCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_CreateCast(HI_UNF_SND_E enSound, HI_UNF_SND_CAST_ATTR_S* pstAttr, HI_HANDLE* phCast);

/**
\brief destroy screen share channel. CNcomment: \CF\FA\BB\D9\C9\F9\D2\F4\B9\B2\CF\EDͨ\B5\C0 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_DestroyCast(HI_HANDLE hCast);

/**
\brief enable screen share. CNcomment: ʹ\C4\DC\C9\F9\D2\F4\B9\B2\CF\ED\B9\A6\C4\DC CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] phCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA
\param[in] bEnable      enable screen share .CNcomment:ʹ\C4\DC\C9\F9\D2\F4\B9\B2\CF\ED CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetCastEnable(HI_HANDLE hCast, HI_BOOL bEnable);

/**
\brief get enable flag of screen share. CNcomment: \BB\F1ȡ\C9\F9\D2\F4\B9\B2\CF\ED\CAǷ\F1ʹ\C4\DC CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA CNend
\param[out] bEnable     flag .CNcomment:\B1\EA־ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetCastEnable(HI_HANDLE hCast, HI_BOOL* pbEnable);

/**
\brief get frame info of snd cast. CNcomment: \BB\F1ȡ\C9\F9\D2\F4\B9\B2\CF\ED֡\D0\C5Ϣ CNend
\attention \n
Cast pcm data format  s32BitPerSample(16), u32Channels(2),bInterleaved(HI_TRUE), u32SampleRate(same as SND).
\param[in] hCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA CNend
\param[out] pstCastFrame        frame info.CNcomment:֡\D0\C5Ϣ CNend
\param[in] u32TimeoutMs         acquire timeout.CNcomment:\BB\F1ȡ\B3\ACʱ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_V_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AO_CAST_TIMEOUT   no enough data.CNcomment:\CA\FD\BEݲ\BB\B9\BB CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_AcquireCastFrame(HI_HANDLE hCast, HI_UNF_AO_FRAMEINFO_S* pstCastFrame, HI_U32 u32TimeoutMs);

/**
\brief release frame info of screen share. CNcomment: \CAͷ\C5\C9\F9\D2\F4\B9\B2\CF\ED֡\D0\C5Ϣ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] hCast      handle of screen share .CNcomment:\C9\F9\D2\F4\B9\B2\CF\ED\BE\E4\B1\FA CNend
\param[in] pstCastFrame     frame info.CNcomment:֡\D0\C5Ϣ CNend
\param[in] u32TimeoutMs    release timeout.CNcomment:\CAͷų\ACʱ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_ReleaseCastFrame(HI_HANDLE hCast, HI_UNF_AO_FRAMEINFO_S* pstCastFrame);

/**
\brief Sets the L/R channel weight of snd cast. CNcomment:\C9\E8\D6\C3\D2\F4ƵCast\D7\F3\D3\D2\C9\F9\B5\C0Ȩ\D6\D8 CNend
\attention \n
\param[in] hCast              ID of snd cast CNcomment:\D2\F4ƵCast ID CNend
\param[in] pstAbsWeightGain   the channel Weight Gain, ranging from 0 to 100. 0: minimum value; 100: maximum value CNcomment:Ȩ\D6أ\AC\B7\B6ΧΪ0\A1\AB100\A1\A30\A3\BA\D7\EEСֵ\A3\BB100\A3\BA\D7\EE\B4\F3ֵ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_SetCastAbsWeight(HI_HANDLE hCast, const HI_UNF_SND_ABSGAIN_ATTR_S* pstAbsWeightGain);

/**
\brief Obtains the L/R channel weight of audio cast. CNcomment:\BB\F1ȡ\D2\F4ƵCast\D7\F3\D3\D2\C9\F9\B5\C0Ȩ\D6\D8 CNend
\attention \n

\param[in] hCast              ID of snd cast CNcomment:\D2\F4ƵCast ID CNend
\param[out] pstAbsWeightGain     Pointer to the ChannelWeight Gain CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACȨ\D6\D8\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR               The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA            The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\see \n
N/A
*/
HI_S32  HI_UNF_SND_GetCastAbsWeight(HI_HANDLE hCast,  HI_UNF_SND_ABSGAIN_ATTR_S* pstAbsWeightGain);

/**
\brief Sets the mute status of audio cast. CNcomment:\C9\E8\D6\C3\D2\F4ƵCast\BE\B2\D2\F4״̬ CNend
\attention \n
N/A
\param[in] enSound
\param[in] enOutPort CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[in] bMute
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_SetCastMute(HI_HANDLE hCast, HI_BOOL bMute);

/**
\brief Obtains the mute status of audio cast. CNcomment:\BB\F1ȡ\D2\F4ƵCast\BE\B2\D2\F4״̬ CNend
\attention \n
N/A
\param[in] enSound CNcomment:
\param[in] enOutPort CNcomment:sound\CA\E4\B3\F6\B6˿\DA CNend
\param[out] pbMute CNcomment:
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA        The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID      The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\see \n
N/A
*/
HI_S32   HI_UNF_SND_GetCastMute(HI_HANDLE hCast, HI_BOOL* pbMute);

/**
\brief enable/disable audio effect for output port. CNcomment: ʹ\C4\DC\CA\E4\B3\F6\B6˿ڵ\C4\D2\F4Ƶ\D2\F4Ч CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  output port .CNcomment:\CA\E4\B3\F6\B6˿ں\C5 CNend
\param[in] bBypass    enable/disable .CNcomment:ʹ\C4ܱ\EA\BC\C7 CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAefBypass(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bBypass);

/**
\brief get info of audio effect for output port. CNcomment: \BB\F1ȡ\CA\E4\B3\F6\B6˿ڵ\C4\D2\F4Ƶ\D2\F4Чʹ\C4\DC\D0\C5Ϣ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  output port .CNcomment:\CA\E4\B3\F6\B6˿ں\C5 CNend
\param[in] pbBypass   enable/disable .CNcomment:ʹ\C4ܱ\EA\BC\C7ָ\D5\EB CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetAefBypass(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL* pbBypass);

/**
\brief Registers Audio effect authorize library . CNcomment: ע\B2\E1\D2\F4Ƶ\D2\F4Ч\CA\DAȨ\BF\E2 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] pAefLibFileName  file name of authorize library .CNcomment:\CA\DAȨ\BF\E2\CEļ\FE\C3\FB CNend
\retval ::HI_SUCCESS    success. CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_RegisterAefAuthLib(const HI_CHAR* pAefLibFileName);

/**
\brief Create audio effect . CNcomment: \B8\F9\BE\DD\C0\E0\D0ʹ\B4\BD\A8һ·\D2\F4Ч\B4\A6\C0\ED CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enAefType  audio effect type .CNcomment:\D2\F4Ч\C0\E0\D0\CD CNend
\param[in] pstAdvAttr audio effect attribute .CNcomment:\D2\F4Ч\B4\B4\BD\A8\B2\CE\CA\FD CNend
\param[in] u32AttrLen audio effect attribute length .CNcomment:\D2\F4Ч\B4\B4\BD\A8\B2\CE\CA\FDָ\D5\EBָ\CF\F2\B5Ŀռ\E4\B4\F3С CNend
\param[out] phAef     the point of audio effect handle  .CNcomment:\D2\F4Ч\BE\E4\B1\FAָ\D5\EB CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_CreateAef(HI_UNF_SND_E enSound, HI_UNF_SND_AEF_TYPE_E enAefType, HI_VOID* pstAdvAttr, HI_U32 u32AttrLen, HI_HANDLE* phAef);

/**
\brief Destroy audio effect . CNcomment: \CF\FA\BB\D9һ·\D2\F4Ч CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef  audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\retval ::HI_SUCCESS success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_DestroyAef(HI_HANDLE hAef);

/**
\brief start/stop audio effect postprocess. CNcomment: \C6\F4\B6\AF/ֹͣ\D2\F4Ч\B4\A6\C0\ED CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef   audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\param[in] bEnable start/stop .CNcomment:\D2\F4Ч\C6\F4\B6\AF/ֹͣ CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAefEnable(HI_HANDLE hAef, HI_BOOL bEnable);

/**
\brief Set audio effect params. CNcomment: \C9\E8\D6\C3\D2\F4Ч\BE\B2̬\B2\CE\CA\FD CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef  audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\param[in] u32ParamType parameter type .CNcomment:\B2\CE\CA\FD\C0\E0\D0\CD CNend
\param[in] pstParms     point of parameter .CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\param[in] u32ParamLen  input parameter buffer length .CNcomment:\D2\F4Ч\B2\CE\CA\FDָ\D5\EBָ\CF\F2\B5Ŀռ\E4\B5Ĵ\F3С CNend
\retval ::HI_SUCCESSsuccess. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAefParams(HI_HANDLE hAef, HI_U32 u32ParamType, const HI_VOID* pstParms, HI_U32 u32ParamLen);

/**
\brief Get audio effect params. CNcomment: \BB\F1ȡ\D2\F4Ч\BE\B2̬\B2\CE\CA\FD CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef    audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\param[in] u32ParamType  parameter type .CNcomment:\B2\CE\CA\FD\C0\E0\D0\CD CNend
\param[out] pstParms      point of parameter .CNcomment:\B2\CE\CA\FDָ\D5\EB CNend
\param[in] u32ParamLen  output parameter buffer length .CNcomment:\D2\F4Ч\B2\CE\CA\FDָ\D5\EBָ\CF\F2\B5Ŀռ\E4\B5Ĵ\F3С CNend
\retval ::HI_SUCCESS     success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetAefParams(HI_HANDLE hAef, HI_U32 u32ParamType, HI_VOID* pstParms, HI_U32 u32ParamLen);

/**
\brief Set audio effect config. CNcomment: \C9\E8\D6\C3\D2\F4Ч\B6\AF̬\C5\E4\D6\C3 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef  audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\param[in] u32CfgType   config type .CNcomment:\C5\E4\D6\C3\C0\E0\D0\CD CNend
\param[in] pstConfig    point of config .CNcomment:\C5\E4\D6\C3ָ\D5\EB CNend
\param[in] u32ConfigLen input config buffer length .CNcomment:\D2\F4Ч\C5\E4\D6ò\CE\CA\FDָ\D5\EBָ\CF\F2\B5Ŀռ\E4\B5Ĵ\F3С CNend
\retval ::HI_SUCCESS    success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAefConfig(HI_HANDLE hAef, HI_U32 u32CfgType, const HI_VOID* pstConfig, HI_U32 u32ConfigLen);

/**
\brief Get audio effect config. CNcomment: \BB\F1ȡ\D2\F4Ч\B6\AF̬\C5\E4\D6\C3 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] phAef   audio effect handle .CNcomment:\D2\F4Ч\BE\E4\B1\FA CNend
\param[in] u32CfgType  config type .CNcomment:\C5\E4\D6\C3\C0\E0\D0\CD CNend
\param[out] pstConfig   point of config .CNcomment:\C5\E4\D6\C3ָ\D5\EB CNend
\param[in] u32ConfigLen output config buffer length .CNcomment:\D2\F4Ч\C5\E4\D6ò\CE\CA\FDָ\D5\EBָ\CF\F2\B5Ŀռ\E4\B5Ĵ\F3С CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR          Input pointer is NULL.CNcomment:\CA\E4\C8\EBָ\D5\EBΪ\BF\D5 CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetAefConfig(HI_HANDLE hAef, HI_U32 u32CfgType, HI_VOID* pstConfig, HI_U32 u32ConfigLen);

/**
\brief Set audio avc attr. CNcomment: \C9\E8\D6\C3avc\CA\F4\D0\D4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] pstAvcAttr  the attribute of the avc .CNcomment:avc\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAvcAttr(HI_UNF_SND_E enSound, const HI_UNF_SND_AVC_ATTR_S* pstAvcAttr);

/**
\brief get the attribute of  avc, reversed. CNcomment:\BB\F1ȡavc\B5\C4\CA\F4\D0ԣ\ACԤ\C1\F4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pstAvcAttr   the attribute of avc CNcomment:avc \CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetAvcAttr(HI_UNF_SND_E enSound, HI_UNF_SND_AVC_ATTR_S* pstAvcAttr);

/**
\brief start/stop avc process. CNcomment: \C6\F4\B6\AF/ֹͣavc\B4\A6\C0\ED\B9\A6\C4\DC CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] bEnable    start/stop .CNcomment: \C6\F4\B6\AF/ֹͣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetAvcEnable(HI_UNF_SND_E enSound, HI_BOOL bEnable);

/**
\brief Get start/stop status of avc postprocess. CNcomment: \BB\F1ȡavc\B4\A6\C0\ED\B5\C4\C6\F4\B6\AF/ֹͣ״̬ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pbEnable start/stop status .CNcomment:avc\C6\F4\B6\AF/ֹͣ״ָ̬\D5\EB CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetAvcEnable(HI_UNF_SND_E enSound, HI_BOOL* pbEnable);

/**
\brief Set audio drc attr. CNcomment: \C9\E8\D6\C3drc\CA\F4\D0\D4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] pstDrcAttr  the attribute of the drc .CNcomment:drc\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetDrcAttr(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, const HI_UNF_SND_DRC_ATTR_S* pstDrcAttr);

/**
\brief Get audio drc attr. CNcomment: \BB\F1ȡdrc\CA\F4\D0\D4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] pstDrcAttr  the attribute of the drc .CNcomment:drc\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetDrcAttr(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_DRC_ATTR_S* pstDrcAttr);

/**
\brief start/stop drc process. CNcomment: \C6\F4\B6\AF/ֹͣdrc\B4\A6\C0\ED\B9\A6\C4\DC CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] bEnable    start/stop .CNcomment: \C6\F4\B6\AF/ֹͣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetDrcEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bEnable);

/**
\brief Get start/stop status of drc postprocess. CNcomment: \BB\F1ȡdrc\B4\A6\C0\ED\B5\C4\C6\F4\B6\AF/ֹͣ״̬ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pbEnable start/stop status .CNcomment:drc\C6\F4\B6\AF/ֹͣ״ָ̬\D5\EB CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetDrcEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL* pbEnable);

/**
\brief Set audio peq attr. CNcomment: \C9\E8\D6\C3peq\CA\F4\D0\D4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] pstPeqAttr  the attribute of the peq .CNcomment:peq\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS   success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetPeqAttr(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, const HI_UNF_SND_PEQ_ATTR_S* pstPeqAttr);

/**
\brief get the attribute of  peq, reversed. CNcomment:\BB\F1ȡpeq\B5\C4\CA\F4\D0ԣ\ACԤ\C1\F4 CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] pstPeqAttr   the attribute of peq CNcomment:peq \CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_NULL_PTR           The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetPeqAttr(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_PEQ_ATTR_S* pstPeqAttr);

/**
\brief start/stop peq process. CNcomment: \C6\F4\B6\AF/ֹͣpeq\B4\A6\C0\ED\B9\A6\C4\DC CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[in] bEnable    start/stop .CNcomment: \C6\F4\B6\AF/ֹͣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetPeqEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bEnable);

/**
\brief Get start/stop status of peq postprocess. CNcomment: \BB\F1ȡpeq\B4\A6\C0\ED\B5\C4\C6\F4\B6\AF/ֹͣ״̬ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] enOutPort  Audio OutputPort     CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\B6˿\DA CNend
\param[out] pbEnable start/stop status .CNcomment:peq\C6\F4\B6\AF/ֹͣ״ָ̬\D5\EB CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetPeqEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL* pbEnable);

/**
\brief Get snd underload count. CNcomment: \BB\F1ȡ\C9\F9\BF\A8Ƿ\D4ش\CE\CA\FD CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pu32Count underload count .CNcomment:Ƿ\D4ش\CE\CA\FD CNend
\retval ::HI_SUCCESS  success. CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA      invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_GetUnderloadCount(HI_UNF_SND_E enSound, HI_U32* pu32Count);

/**
\brief set continue output MS12 only. CNcomment: \C9\E8\D6\C3continue output CNend
\attention \n
none. CNcomment:\CE\DE
\param[in] enSound    ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[in] bEnable    start/stop .CNcomment: \C6\F4\B6\AF/ֹͣ CNend
\retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
none.CNcomment:\CE\DE CNend
*/
HI_S32 HI_UNF_SND_SetContinueOutputEnable(HI_UNF_SND_E enSound, HI_BOOL bEnable);

/**
\brief Obtains continue output MS12 only. CNcomment:\BB\F1ȡcontinue output\B5\C4ʹ\C4\DC״̬ CNend
\attention \n
none. CNcomment:\CE\DE CNend
\param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
\param[out] pbEnable   Pointer to the obtained continue output status CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\BB\F1ȡ\B5\BD\B5\C4ʹ\C4\DC״̬ CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
\retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
\retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_ERR_AO_INVALID_ID       The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
\retval ::HI_ERR_AO_NULL_PTR         The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SND_GetContinueOutputEnable(HI_UNF_SND_E enSound, HI_BOOL* pbEnable);

/**
 \brief Set audio output latency mode MS12 only.CNcomment:\C9\E8\D6\C3\D2\F4Ƶ\CA\E4\B3\F6ʱ\D1\D3ģʽ CNend
 \attention \n
CNcomment: \CE\DECNend
 \param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[in] enMode Output mode .CNcomment:\CA\E4\B3\F6ģʽCNend
 \retval ::HI_SUCCESS CNcomment: success.\B3ɹ\A6 CNend
 \retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_AO_INVALID_PARA   invalid input parameter.CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8 CNend
 \see \n
 N/A
 */
HI_S32 HI_UNF_SND_SetOutputLatencyMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTLATENCY_E enOutMode);

/**
 \brief Get audio output latency mode MS12 only.CNcomment:\BB\F1ȡ\D2\F4Ƶ\CA\E4\B3\F6ʱ\D1\D3ģʽ CNend
 \attention \n
CNcomment: \CE\DECNend
 \param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[out] penMode Return output mode .CNcomment:\B7\B5\BB\D8\CA\E4\B3\F6ģʽCNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
 \retval ::HI_ERR_AO_INVALID_ID       The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
 \retval ::HI_ERR_AO_NULL_PTR         The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
 \see \n
 N/A
 */
HI_S32 HI_UNF_SND_GetOutputLatencyMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTLATENCY_E *penOutMode);

/**
 \brief Set ATMOS Lock Enable.CNcomment:\C9\E8\D6\C3ATMOS Lock \B9\A6\C4\DCʹ\C4\DC CNend
 \attention \n
CNcomment: \CE\DECNend
 \param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[in] bAtmosLockEnable   AtmosLock flag .CNcomment:ATMOSLOCK ʹ\C4ܱ\EA־ CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
 \retval ::HI_ERR_AO_INVALID_ID       The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
 \see \n
 N/A
 */
HI_S32 HI_UNF_SND_SetAtmosLockEnable(HI_UNF_SND_E enSound, HI_BOOL bAtmosLockEnable);

/**
 \brief Get ATMOS Lock state.CNcomment:\BB\F1ȡATMOS Lock ״̬ CNend
 \attention \n
CNcomment: \CE\DECNend
 \param[in] enSound         ID of an AO device CNcomment:\D2\F4Ƶ\CA\E4\B3\F6\C9豸\BA\C5 CNend
 \param[out] pbAtmosLockEnable   AtmosLock flag .CNcomment:ATMOSLOCK ״̬\B1\EA־ CNend
 \retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
 \retval ::HI_FAILURE FAILURE CNcomment:ʧ\B0\DC CNend
 \retval ::HI_ERR_AO_SOUND_NOT_OPEN    Sound device is not opened. CNcomment:Sound\C9豸δ\B4\F2\BF\AA CNend
 \retval ::HI_ERR_AO_INVALID_PARA     The parameter is invalid. CNcomment:\CE\DEЧ\B5Ĳ\CE\CA\FD CNend
 \retval ::HI_ERR_AO_INVALID_ID       The parameter enSound is invalid. CNcomment:\CE\DEЧSound ID CNend
 \see \n
 N/A
 */
HI_S32 HI_UNF_SND_GetAtmosLockEnable(HI_UNF_SND_E enSound, HI_BOOL* pbAtmosLockEnable);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_SND_H__*/

