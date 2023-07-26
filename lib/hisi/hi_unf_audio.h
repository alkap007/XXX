/******************************************************************************

  Copyright (C), 2004-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_audio.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/17
  Description   :
  History       :
  1.Date        : 2009/12/17
    Author      : sdk
    Modification: Created file

*******************************************************************************/

#ifndef __HI_UNF_AUDIO_H__
#define __HI_UNF_AUDIO_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_common.h"
#include "hi_audio_codec.h"

/*************************** Structure Definition ****************************/
/** \addtogroup      Audio_Common */
/** @{ */  /** <!-- [Audio_Common] */

/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\B2\C9\D1\F9\C2\CAö\BE\D9*/
typedef enum hiUNF_SAMPLE_RATE_E
{
    HI_UNF_SAMPLE_RATE_UNKNOWN=0,       /**<Unknown*/ /**<CNcomment: δ֪\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_8K    = 8000,    /**<8 kHz sampling rate*/ /**<CNcomment: 8K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_11K   = 11025,   /**<11.025 kHz sampling rate*/ /**<CNcomment: 11.025K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_12K   = 12000,   /**<12 kHz sampling rate*/ /**<CNcomment: 12K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_16K   = 16000,   /**<16 kHz sampling rate*/ /**<CNcomment: 16K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_22K   = 22050,   /**<22.050 kHz sampling rate*/ /**<CNcomment: 22.050K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_24K   = 24000,   /**<24 kHz sampling rate*/ /**<CNcomment: 24K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_32K   = 32000,   /**<32 kHz sampling rate*/ /**<CNcomment: 32K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_44K   = 44100,   /**<44.1 kHz sampling rate*/ /**<CNcomment: 44.1K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_48K   = 48000,   /**<48 kHz sampling rate*/ /**<CNcomment: 48K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_88K   = 88200,   /**<88.2 kHz sampling rate*/ /**<CNcomment: 88.2K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_96K   = 96000,   /**<96 kHz sampling rate*/ /**<CNcomment: 96K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_176K  = 176400,  /**<176 kHz sampling rate*/ /**<CNcomment: 176K\B2\C9\D1\F9Ƶ\C2\CA */
    HI_UNF_SAMPLE_RATE_192K  = 192000,  /**<192 kHz sampling rate*/ /**<CNcomment: 192K\B2\C9\D1\F9Ƶ\C2\CA */

    HI_UNF_SAMPLE_RATE_BUTT
} HI_UNF_SAMPLE_RATE_E;

/**Defines the bit depth during audio sampling.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\B2\C9\D1\F9λ\BF\EDö\BE\D9*/
typedef enum hiUNF_BIT_DEPTH_E
{
    HI_UNF_BIT_DEPTH_UNKNOWN =0,/**<Unknown*/ /**<CNcomment: δ֪\B2\C9\D1\F9λ\BF\ED  */
    HI_UNF_BIT_DEPTH_8  = 8,    /**< 8-bit depth*/ /**<CNcomment: 8λ\B2\C9\D1\F9λ\BF\ED  */
    HI_UNF_BIT_DEPTH_16 = 16,   /**<16-bit depth*/ /**<CNcomment: 16λ\B2\C9\D1\F9λ\BF\ED */
    HI_UNF_BIT_DEPTH_18 = 18,   /**<18-bit depth*/ /**<CNcomment: 18λ\B2\C9\D1\F9λ\BF\ED */
    HI_UNF_BIT_DEPTH_20 = 20,   /**<20-bit depth*/ /**<CNcomment: 20λ\B2\C9\D1\F9λ\BF\ED */
    HI_UNF_BIT_DEPTH_24 = 24,   /**<24-bit depth*/ /**<CNcomment: 24λ\B2\C9\D1\F9λ\BF\ED */
    HI_UNF_BIT_DEPTH_32 = 32,   /**<32-bit depth*/ /**<CNcomment: 32λ\B2\C9\D1\F9λ\BF\ED */

    HI_UNF_BIT_DEPTH_BUTT
} HI_UNF_BIT_DEPTH_E;

/**Defines the mode of audio channels.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\C9\F9\B5\C0ģʽö\BE\D9*/
typedef enum hiUNF_TRACK_MODE_E
{
    HI_UNF_TRACK_MODE_STEREO = 0,          /**<Stereo*/ /**<CNcomment: \C1\A2\CC\E5\C9\F9*/
    HI_UNF_TRACK_MODE_DOUBLE_MONO,         /**<Data is output after being mixed in the audio-left channel and audio-right channel.*/ /**<CNcomment: \D7\F3\D3\D2\C9\F9\B5\C0\BB\EC\BAϺ\F3\CA\E4\B3\F6*/
    HI_UNF_TRACK_MODE_DOUBLE_LEFT,         /**<The audio-left channel and audio-right channel output the data of the audio-left channel.*/ /**<CNcomment: \D7\F3\D3\D2\C9\F9\B5\C0\CA\E4\B3\F6\D7\F3\C9\F9\B5\C0\CA\FD\BE\DD*/
    HI_UNF_TRACK_MODE_DOUBLE_RIGHT,        /**<The audio-left channel and audio-right channel output the data of the audio-right channel.*/ /**<CNcomment: \D7\F3\D3\D2\C9\F9\B5\C0\CA\E4\B3\F6\D3\D2\C9\F9\B5\C0\CA\FD\BE\DD*/
    HI_UNF_TRACK_MODE_EXCHANGE,            /**<Data is output after being exchanged in the audio-left channel and audio-right channel.*/ /**<CNcomment: \D7\F3\D3\D2\C9\F9\B5\C0\CA\FD\BEݽ\BB\BB\BB\CA\E4\B3\F6 */
    HI_UNF_TRACK_MODE_ONLY_RIGHT,          /**<Only the data in the audio-right channel is output.*/ /**<CNcomment: ֻ\CA\E4\B3\F6\D3\D2\C9\F9\B5\C0\CA\FD\BE\DD*/
    HI_UNF_TRACK_MODE_ONLY_LEFT,           /**<Only the data in the audio-left channel is output.*/ /**<CNcomment: ֻ\CA\E4\B3\F6\D7\F3\C9\F9\B5\C0\CA\FD\BE\DD*/
    HI_UNF_TRACK_MODE_MUTED,               /**<Mute*/ /**<CNcomment: \BE\B2\D2\F4*/

    HI_UNF_TRACK_MODE_BUTT
} HI_UNF_TRACK_MODE_E;

/**Defines the attributes of the audio decoder.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\BD\E2\C2\EB\C6\F7\CA\F4\D0Խṹ*/
typedef struct hiUNF_ACODEC_ATTR_S
{
    HA_CODEC_ID_E        enType;                    /**<Audio decoder type*/ /**<CNcomment: \D2\F4Ƶ\BD\E2\C2\EB\C0\E0\D0\CD*/
    HI_HADECODE_OPENPARAM_S stDecodeParam;   /**<Audio decoder parameter*/ /**<CNcomment: \D2\F4Ƶ\BD\E2\C2\EB\B2\CE\CA\FD*/
} HI_UNF_ACODEC_ATTR_S;

/**Defines the attributes of audio encoder.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\B1\E0\C2\EB\C6\F7\CA\F4\D0Խṹ*/
typedef struct hiUNF_AENC_ATTR_S
{
    HI_U32         enAencType;              /**<Audio encoder type*/ /**<CNcomment: \D2\F4Ƶ\B1\E0\C2\EB\C0\E0\D0\CD*/
    HI_HAENCODE_OPENPARAM_S   sOpenParam;   /**<Audio encoder parameter*/ /**<CNcomment: \D2\F4Ƶ\B1\E0\C2\EB\B2\CE\CA\FD*/
} HI_UNF_AENC_ATTR_S;

/**Defines the information about audio streams.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ\C2\EB\C1\F7\D0\C5Ϣ\BDṹ*/
typedef struct hiUNF_ACODEC_STREAMINFO_S
{
    HI_U32               enACodecType;     /**<Audio Codec type*/ /**<CNcomment: \D2\F4ƵCodec\C0\E0\D0\CD HA_CODEC_ID_E*/
    HI_U32               enSampleRate;     /**<Audio sampling rate*/ /**<CNcomment: \D2\F4Ƶ\B2\C9\D1\F9\C2\CA*/
    HI_UNF_BIT_DEPTH_E   enBitDepth;       /**<Bit depth during audio sampling*/ /**<CNcomment: \D2\F4Ƶ\B2\C9\D1\F9λ\BF\ED*/
    HI_U32               u32Channel;       /**<Audio output channel*//**<CNcomment: \D2\F4Ƶ\CA\E4\B3\F6\C9\F9\B5\C0\CA\FD*/
    HI_U32               u32BitRate;       /**<Audio bitrate*/ /**<CNcomment: \D2\F4Ƶ\B1\C8\CC\D8\C2\CA*/
    HA_FORMAT_E          enAudioFormat;    /**<Audio stream format*/ /**<CNcomment: \D2\F4Ƶ\C2\EB\C1\F7\B8\F1ʽ*/
    HA_AUDIO_CHANNELMODE_E enChannelMode;  /**<Audio channel mode*/ /**<CNcomment: \D2\F4Ƶ\C9\F9\B5\C0ģʽ*/
    HI_BOOL              bLfePresent;      /**<Lfe present flag*/ /**<CNcomment: \CAǷ\F1\B4\E6\D4\DA\D6ص\CD\D2\F4*/
    HI_BOOL              bAtmos;           /**<Atmos stream flag*/ /**<CNcomment: \D2\F4Ƶ\C2\EB\C1\F7\CAǷ\F1\CA\C7Atmos*/
} HI_UNF_ACODEC_STREAMINFO_S;

/**Defines the I2S(Inter-IC Sound) mode.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵI2S\BDӿ\DAģʽö\BE\D9*/
typedef enum hiHI_UNF_I2S_MODE_E
{
    HI_UNF_I2S_STD_MODE = 0,     /**<I2S standard mode*/ /**<CNcomment: I2S\B1\EA׼ģʽ*/
    HI_UNF_I2S_PCM_MODE,         /**<pcm mode*/ /**<CNcomment: PCMģʽ*/
    HI_UNF_I2S_TDM_MODE,         /**<TDM mode*/ /**<CNcomment: TDMģʽ*/

    HI_UNF_I2S_MODE_BUTT
} HI_UNF_I2S_MODE_E;

/**Defines the I2S(Inter-IC Sound) master clock.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵI2S\BDӿڹ\A4\D7\F7ʱ\D6\D3ö\BE\D9*/
typedef enum hiHI_UNF_I2S_MCLK_SEL_E
{
    HI_UNF_I2S_MCLK_128_FS = 0,      /* mclk 128*fs  */
    HI_UNF_I2S_MCLK_256_FS,          /* mclk 256*fs */
    HI_UNF_I2S_MCLK_384_FS,          /* mclk 384*fs */
    HI_UNF_I2S_MCLK_512_FS,          /* mclk 512*fs */
    HI_UNF_I2S_MCLK_768_FS,          /* mclk 768*fs */
    HI_UNF_I2S_MCLK_1024_FS,         /* mclk 1024*fs */
    HI_UNF_I2S_MCLK_BUTT
} HI_UNF_I2S_MCLK_SEL_E;

/**Defines the I2S(Inter-IC Sound) bclk clock.*/
typedef enum hiHI_UNF_I2S_BCLK_SEL_E
{
     HI_UNF_I2S_BCLK_1_DIV = 1,           /* bclk=mclk/1  */
     HI_UNF_I2S_BCLK_2_DIV = 2,           /* bclk=mclk/2  */
     HI_UNF_I2S_BCLK_3_DIV = 3,           /* bclk=mclk/3  */
     HI_UNF_I2S_BCLK_4_DIV = 4,           /* bclk=mclk/4  */
     HI_UNF_I2S_BCLK_6_DIV = 6,           /* bclk=mclk/6  */
     HI_UNF_I2S_BCLK_8_DIV = 8 ,          /* bclk=mclk/8  */
     HI_UNF_I2S_BCLK_12_DIV= 12,          /* bclk=mclk/12 */
     HI_UNF_I2S_BCLK_24_DIV= 24,          /* bclk=mclk/24 */
     HI_UNF_I2S_BCLK_32_DIV= 32,          /* bclk=mclk/32 */
     HI_UNF_I2S_BCLK_48_DIV= 48,          /* bclk=mclk/48 */
     HI_UNF_I2S_BCLK_64_DIV= 64,          /* bclk=mclk/64 */
     HI_UNF_I2S_BCLK_BUTT
} HI_UNF_I2S_BCLK_SEL_E;

/**Defines the I2S(Inter-IC Sound) channels.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵI2S\BDӿ\DA\D2\F4Ƶͨ\B5\C0ö\BE\D9*/
typedef enum hiHI_UNF_I2S_CHNUM_E
{
    HI_UNF_I2S_CHNUM_1  = 1,
    HI_UNF_I2S_CHNUM_2  = 2,              /* only work for I2S mode */
    HI_UNF_I2S_CHNUM_8  = 8,              /* only work for I2S mode */
    HI_UNF_I2S_CHNUM_16 = 16,             /* only work for TDM mode */

    HI_UNF_I2S_BUTT,
} HI_UNF_I2S_CHNUM_E;

/**Defines the I2S(Inter-IC Sound) bit depth.*/
typedef enum hiHI_UNF_I2S_BITDEPTH_E
{
    HI_UNF_I2S_BIT_DEPTH_16 = 16,
    HI_UNF_I2S_BIT_DEPTH_24 = 24,         /* only work for I2S mode */
} HI_UNF_I2S_BITDEPTH_E;

/**Defines the I2S(Inter-IC Sound) data valid after frame sync clock at PCM mode .*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵI2S\BDӿڣ\AC\CA\FD\BE\DD\D3\D0Ч\D1ӳ\D9\D6\DC\C6ڣ\AC\BD\F6PCMģʽ\D3\D0Ч*/
typedef enum hiHI_UNF_I2S_PCMDELAY_E
{
    HI_UNF_I2S_PCM_0_DELAY = 0,           /* 0  bclk cycles delay*/
    HI_UNF_I2S_PCM_1_DELAY = 1,           /* 1  bclk cycles delay*/
    HI_UNF_I2S_PCM_8_DELAY = 8,           /* 8  bclk cycles delay*/
    HI_UNF_I2S_PCM_16_DELAY = 16,         /* 16 bclk cycles delay*/
    HI_UNF_I2S_PCM_17_DELAY = 17,         /* 17 bclk cycles delay*/
    HI_UNF_I2S_PCM_24_DELAY = 24,         /* 24 bclk cycles delay*/
    HI_UNF_I2S_PCM_32_DELAY = 32,         /* 32 bclk cycles delay*/
    HI_UNF_I2S_PCM_DELAY_BUTT
} HI_UNF_I2S_PCMDELAY_E;

/**Defines the I2S(Inter-IC Sound) attribute .*/
/**CNcomment: \B6\A8\D2\E5\D2\F4ƵI2S\BDӿ\DA\C5\E4\D6\C3\CA\F4\D0\D4*/
typedef struct hiHI_UNF_I2S_ATTR_S
{
    HI_BOOL               bMaster;           /* HI_TRUE:master, HI_FALSE: slave */
    HI_UNF_I2S_MODE_E     enI2sMode;
    HI_UNF_I2S_MCLK_SEL_E enMclkSel;
    HI_UNF_I2S_BCLK_SEL_E enBclkSel;
    HI_UNF_I2S_CHNUM_E    enChannel;
    HI_UNF_I2S_BITDEPTH_E enBitDepth;
    HI_BOOL               bPcmSampleRiseEdge; /* only work for PCM mode. HI_TRUE:sample data at positive edge of bclk, HI_FALSE: sample data at  negative edge of bclk */
    HI_UNF_I2S_PCMDELAY_E enPcmDelayCycle;    /* only work for PCM mode.  */
} HI_UNF_I2S_ATTR_S;

/**Defines the information about audio frames.*/
/**CNcomment: \B6\A8\D2\E5\D2\F4Ƶ֡\D0\C5Ϣ\BDṹ*/
typedef struct hiUNF_AO_FRAMEINFO_S
{
    /** s32BitPerSample: (PCM) Data depth, and format of storing the output data
          If the data depth is 16 bits, 16-bit word memory is used.
          If the data depth is greater than 16 bits, 32-bit word memory is used, and data is stored as left-aligned data. That is, the valid data is at upper bits.
     */
    /**CNcomment: s32BitPerSample: (PCM) \CA\FD\BE\DDλ\BF\ED\C9\E8\D6\C3. \CA\E4\B3\F6\B4\E6\B7Ÿ\F1ʽ
          \B5\C8\D3\DA16bit:   ռ\D3\C316bit word\C4ڴ\E6
          \B4\F3\D3\DA16bit:   ռ\D3\C332bit word\C4ڴ\E6, \CA\FD\BE\DD\D7\F3\B6\D4\C6뷽ʽ\B4\E6\B7\C5(\D3\D0Ч\CA\FD\BE\DD\D4ڸ\DFλ)
     */
    HI_S32  s32BitPerSample;       /**<Data depth*/ /**<CNcomment: \CA\FD\BE\DDλ\BF\ED*/
    HI_BOOL bInterleaved;          /**<Whether the data is interleaved*/ /**<CNcomment: \CA\FD\BE\DD\CAǷ\F1\BD\BB֯*/
    HI_U32  u32SampleRate;         /**<Sampling rate*/ /**<CNcomment: \B2\C9\D1\F9\C2\CA*/
    HI_U32  u32Channels;           /**<Number of channels*/ /**<CNcomment: ͨ\B5\C0\CA\FD\C1\BF*/
    HI_U32  u32PtsMs;              /**<Presentation time stamp (PTS)*/ /**<CNcomment: ʱ\BC\E4\B4\C1*/
    HI_S32 *ps32PcmBuffer;         /**<Pointer to the buffer for storing the pulse code modulation (PCM) data*/ /**<CNcomment: PCM\CA\FD\BEݻ\BA\B3\E5ָ\D5\EB*/
    HI_S32 *ps32BitsBuffer;        /**<Pointer to the buffer for storing the stream data*/ /**<CNcomment: \C2\EB\C1\F7\CA\FD\BEݻ\BA\B3\E5ָ\D5\EB*/
    HI_U32  u32PcmSamplesPerFrame; /**<Number of sampling points of the PCM data*/ /**<CNcomment: PCM\CA\FD\BEݲ\C9\D1\F9\B5\E3\CA\FD\C1\BF*/
    HI_U32  u32BitsBytesPerFrame;  /**<IEC61937 data size*/ /**<CNcomment: IEC61937\CA\FD\BEݳ\A4\B6\C8*/
    HI_U32  u32FrameIndex;         /**<Frame ID*/ /**<CNcomment: ֡\D0\F2\BA\C5 */
    HI_U32  u32IEC61937DataType;   /**<IEC61937 Data Type*/ /**<CNcomment: IEC61937\CA\FD\BE\DD\C0\E0\D0ͱ\EAʶ\A3\AC\B5\CD8bitΪIEC\CA\FD\BE\DD\C0\E0\D0\CD */
} HI_UNF_AO_FRAMEINFO_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_AUDIO_ H*/
