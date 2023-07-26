/******************************************************************************

  Copyright (C) Hisilicon Technologies Co., Ltd. 2008-2018. All rights reserved.

 ******************************************************************************
  File Name     : hi_unf_pvr.h
  Version       : Initial draft
  Author        : HiSilicon multimedia software group
  Created Date   : 2008-04-09
  Description   : hi_pvr_api.h header file
  Change History:
  Date        : 2008-04-09
    Author      : sdk
    Description: This file is created.

******************************************************************************/
/**
 * \file
 * \brief Describes the information about the personal video recorder (PVR). CNcomment: \CCṩPVR\B5\C4\CF\E0\B9\D8\D0\C5Ϣ CNend
 */
#ifndef __HI_UNF_PVR_H__
#define __HI_UNF_PVR_H__

#include "hi_type.h"
#include "hi_debug.h"
#include "hi_unf_cipher.h"
#include "hi_unf_common.h"
#include "hi_unf_avplay.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* End of #ifdef __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup    PVR */
/** @{ */  /** <!--[PVR]*/

/**Recommended value of the recording attribute u32ScdBufSize*//** CNcomment: ¼\D6\C6\CA\F4\D0\D4\D6\D0u32ScdBufSize\B5\C4\CDƼ\F6ֵ */
#define PVR_STUB_SC_BUF_SZIE (7*4*2048)

/**Recommended value of the recording attribute u32DavBufSize when the recording attribute enTsPacketType is HI_UNF_PVR_TS_PACKET_188 and Resolution is FHD and below*//** CNcomment:  \B5\B1¼\D6\C6\CA\F4\D0\D4\D6\D0enTsPacketTypeΪHI_UNF_PVR_TS_PACKET_188,\C7ҷֱ\E6\C2\CAΪFHD\BC\B0\D2\D4\CF\C2ʱ,¼\D6\C6\CA\F4\D0\D4\D6\D0u32DavBufSize\B5\C4\CDƼ\F6ֵ */
#define PVR_STUB_TSDATA_SIZE (188*12*2048)

/**Recommended value of the recording attribute u32DavBufSize when the recording attribute enTsPacketType is HI_UNF_PVR_TS_PACKET_192 and Resolution is FHD and below*//**<CNcomment: \B5\B1¼\D6\C6\CA\F4\D0\D4\D6\D0enTsPacketTypeΪHI_UNF_PVR_TS_PACKET_192,\C7ҷֱ\E6\C2\CAΪFHD\BC\B0\D2\D4\CF\C2ʱ,¼\D6\C6\CA\F4\D0\D4\D6\D0u32DavBufSize\B5\C4\CDƼ\F6ֵ */
#define PVR_STUB_TSDATA_SIZE_192 (192*12*2048)

/*****************Macro Definition*******************************/
/**Maximum length of the file name, in byte*//** CNcomment:  \CEļ\FE\C3\FB\D7\EE\B4󳤶ȣ\AC\B5\A5λ:\D7ֽ\DA*/
#define PVR_MAX_FILENAME_LEN            256
/**Maximum length of the encryption key, in byte. Note: The valid key length may not be the maximum length, and depends on the encryption algorithm.*/
/** CNcomment: \BC\D3\C3\DC\C3\DCԿ\D7\EE\B4󳤶ȣ\AC\B5\A5λ:\D7ֽڡ\A3ע\D2\E2: \C3\DCԿ\B5\C4\D3\D0Ч\B3\A4\B6Ȳ\BBһ\B6\A8\CA\C7\D7\EE\B4󳤶ȣ\AC\B6\F8\CA\C7\D3ɼ\D3\C3ܵ\C4\CB㷨\BE\F6\B6\A8 */
#define PVR_MAX_CIPHER_KEY_LEN          128
/**Maximum length of the user data, in byte*//** CNcomment:  \D3û\A7\CA\FD\BE\DD\D7\EE\B4󳤶ȣ\AC \B5\A5λ:\D7ֽ\DA */
#define PVR_MAX_USERDATA_LEN            (1024*1024)
#define PVR_MAX_CADATA_LEN              (16*1024)
/**<Maximum number of PID for one recording*//**<CNcomment: һ·¼\D6\C6֧\B3ֵ\C4\D7\EE\B4\F3PID\B8\F6\CA\FD*/
#define HI_UNF_PVR_REC_MAX_PID_NUM (32)

/**<Flag value of trick play with audio*//**<CNcomment: \B4\F8\C9\F9\D2\F4\B5\C4\CCؼ\BC\B2\A5\B7\C5\CBٶȱ\EA־ֵ*/
#define HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE     (0x0A000000)

/***********************************************************
                Data Structure Definition
 ***********************************************************/

/***** Common Data Structures*****/

/** Secure mode type*/
/**CNcomment:\B0\B2ȫģʽ\C0\E0\D0\CD*/
typedef enum hiUNF_PVR_SECURE_MODE_E
{
    HI_UNF_PVR_SECURE_MODE_NONE = 0,        /** <no security protection*/ /**<CNcomment:\CEް\B2ȫ\B1\A3\BB\A4*/
    HI_UNF_PVR_SECURE_MODE_TEE,             /** <trustedzone security protection*/ /**<CNcomment:trustedzone\B0\B2ȫ\B1\A3\BB\A4*/

    HI_UNF_PVR_SECURE_MODE_BUTT
} HI_UNF_PVR_SECURE_MODE_E;

/**Cyclic control data structure of the PVR index file*//** CNcomment: PVR index\CEļ\FE\D6\D0ѭ\BB\B7\BF\D8\D6ƽṹ\D0\C5Ϣ */
typedef struct hiPVR_CYC_HEADER_INFO_S
{
    HI_U32 u32StartFrame;     /**<Offset of the start frame in the index file. The start frame is at u32StartFrame.*//**<CNcomment: \C2\EB\C1\F7\B5\C4\C6\F0ʼ֡\D4\DAindex\CEļ\FE\D6е\C4ƫ\D2\C6, \C6\F0ʼ֡\B7\C5\D4\DAu32StartFrame\B5\C4λ\D6\C3*/
    HI_U32 u32EndFrame;       /**<Offset of the end frame in the index file. The end frame is at u32EndFrame - 1.*//**<CNcomment: \C2\EB\C1\F7\B5Ľ\E1\CA\F8֡\D4\DAindex\CEļ\FE\D6е\C4ƫ\D2\C6, \BD\E1\CA\F8֡\B7\C5\D4\DAu32EndFrame-1\B5\C4λ\D6\C3*/
    HI_U32 u32LastFrame;      /**<Offset of the last frame in the index file. The last frame is at u32LastFrame - 1.*//**<CNcomment: index\CEļ\FE\D6н\E1β֡\B5\C4ƫ\D2\C6, \BD\E1β֡\B7\C5\D4\DAu32LastFrame-1\B5\C4λ\D6\C3*/
    HI_U32 u32IsRewind;       /**<Whether to record the file in rewind mode. 0: no rewind; 1: rewind*//**<CNcomment: \CEļ\FE\CAǷ\F1\BB\D8\C8\C6¼\D6\C6, 0 \B7ǻ\D8\C8\C6, 1 \BB\D8\C8\C6*/
}PVR_CYC_HEADER_INFO_S;

/**Structure of the file header in the PVR index file*//** CNcomment: PVR index\CEļ\FE\D6\D0\CEļ\FEͷ\D0\C5Ϣ\BDṹ */
typedef struct hiPVR_IDX_HEADER_INFO_S
{
    HI_U32 u32StartCode;                          /**<Start code (0x5A5A5A5A)*//**<CNcomment: \C6\F0ʼ\C2\EB(0x5A5A5A5A) */
    HI_U32 u32HeaderLen;                          /**<Length from u32StartCode to UsrData*//**<CNcomment: \B4\D3u32StartCode\BF\AAʼ\B5\BDUsrData\BD\E1\CA\F8\B5ĳ\A4\B6\C8 */
    PVR_CYC_HEADER_INFO_S stCycInfo;              /**<Records the cyclic control information in the index file*//**<CNcomment: index\D6\D0¼\D6ƻ\B7\BBؿ\D8\D6\C6\D0\C5Ϣ */
    HI_U64 u64ValidSize;                          /**<Size of the valid content in a file, in byte*//**<CNcomment:\CEļ\FE\D6\D0\D3\D0Ч\C4\DA\C8ݴ\F3С \B5\A5λByte */
    HI_U32 u32Reserved;                           /**<Reserved, for alignment*//**<CNcomment:\B1\A3\C1\F4\A3\AC\D3\C3\D7\F7\B6\D4\C6\EB */
    HI_U32 u32UsrDataInfoLen;                     /**<User information length*//**<CNcomment: \D3û\A7\D0\C5Ϣ\B3\A4\B6\C8 */
    HI_U32 u32CADataInfoLen;
}PVR_IDX_HEADER_INFO_S;

/**Index data saved in the PVR index file*//** CNcomment: PVR index\CEļ\FE\D6б\A3\B4\E6\B5\C4\CB\F7\D2\FD\CA\FD\BEݽṹ */
typedef struct hiPVR_INDEX_ENTRY_S
{
    HI_U16 u16FrameTypeAndGop;                    /**<2-bit frame type and 14-bit group of pictures (GOP)*/
    HI_U16 u16UpFlowFlag;                         /**<DAV overflow flag*/
    HI_U32 s32CycTimes;                           /**<Number of times that the file is rewound*/
    HI_U64 u64GlobalOffset;                       /**<Total global offset (rewind ignored), in byte*/
    HI_U32 u32DisplayTimeMs;                      /**<Display time (in ms), no rewind*/
    HI_U32 u32FrameSize;                          /**<Frame size*/
    HI_U64 u64Offset;                             /**<Frame offset in a stream file*/
    HI_U32 u32PtsMs;                              /**<Presentation time stamp (PTS), in ms*/
    HI_U16 u16IndexType;                          /**<Index type*/
    HI_U16 u161stFrameOfTT;                       /**<Useless*/
}PVR_INDEX_ENTRY_S,*PTR_PVR_INDEX_ENTRY;


/**Encryption or decryption configuration of the PVR*//** CNcomment:  PVR\BCӽ\E2\C3\DC\C5\E4\D6\C3 */
typedef struct hiUNF_PVR_CIPHER_S
{
    HI_BOOL             bDoCipher;                             /**<Whether to perform encryption or decryption. When this parameter is set to HI_FALSE, other parameters are invalid.*//**<CNcomment:  \CAǷ\F1\BD\F8\D0м\D3\C3ܻ\F2\D5߽\E2\C3ܣ\AC\B4\CB\CF\EE\C5\E4\D6\C3ΪHI_FALSEʱ\A3\AC\C6\E4\CB\FB\CF\EEû\D3\D0\D2\E2\D2\E5 */
    HI_UNF_CIPHER_ALG_E enType;                                /**<Encryption or decryption algorithm type that supports only the AES, DES, and 3DES*//**<CNcomment: \BC\D3\C3ܻ\F2\D5߽\E2\C3ܵ\C4\CB㷨\C0\E0\D0ͣ\ACֻ֧\B3\D6AES\A1\A2DES\A1\A23DES */
    HI_U8               au8Key[PVR_MAX_CIPHER_KEY_LEN];        /**<In normal PVR,it's cipher key.If advance security PVR, it's Keyladder's first session key*//**<CNcomment: \C6\D5ͨPVR\B7\BD\B0\B8\D6У\AC\D7\F7ΪCipher\B5\C4\C3\DCԿ\A3\AC\B8߰\B2ȫPVR\B7\BD\B0\B8\D6У\AC\D7\F7ΪKeyladder\B5\C4һ\BC\B6\BBỰ\C3\DCԿ */
    HI_U32              u32KeyLen;                             /**<Cipher key length*//**<CNcomment: \C3\DCԿ\B3\A4\B6\C8 */
}HI_UNF_PVR_CIPHER_S;

/**Type of the PVR event*//** CNcomment:  PVR\CA¼\FE\C0\E0\D0\CD */
typedef enum hiUNF_PVR_EVENT_E
{
    HI_UNF_PVR_EVENT_PLAY_EOF                       = 0x001,          /**<A file is played at the end of file (EOF).*//**<CNcomment:  \B2\A5\B7ŵ\BD\CEļ\FEβ */
    HI_UNF_PVR_EVENT_PLAY_SOF                       = 0x002,          /**<A file is played to the start of file (SOF).*//**<CNcomment:  \BB\D8\CD˵\BD\CEļ\FEͷ */
    HI_UNF_PVR_EVENT_PLAY_ERROR                     = 0x003,          /**<An internal error occurs during playing.*//**<CNcomment:  \B2\A5\B7\C5\C4ڲ\BF\B4\ED\CE\F3 */
    HI_UNF_PVR_EVENT_PLAY_REACH_REC                 = 0x004,          /**<The playing speed reaches the recording speed during time shift.*//**<CNcomment:  ʱ\D2Ƶ\C4ʱ\BA򲥷\C5׷\C9\CF¼\D6\C6 */
    HI_UNF_PVR_EVENT_PLAY_FIRST_FRAME_DISPLAYED     = 0x005,          /**<the first deocded frame have been displayed out by the tv.*//**<CNcomment: \B5\DAһ֡\D2ѱ\BB\CF\D4ʾ*/
    HI_UNF_PVR_EVENT_PLAY_RESV                      = 0x00f,          /**<Reserved*//**<CNcomment:  \B1\A3\C1\F4 */
    HI_UNF_PVR_EVENT_REC_DISKFULL                   = 0x010,          /**<The disk is full.*//**<CNcomment:  \B4\C5\C5\CC\C2\FA */
    HI_UNF_PVR_EVENT_REC_ERROR                      = 0x011,          /**<An internal error occurs during recording.*//**<CNcomment:  ¼\D6\C6\C4ڲ\BF\B4\ED\CE\F3 */
    HI_UNF_PVR_EVENT_REC_OVER_FIX                   = 0x012,          /**<The length of the recorded data reaches the specified length. after report this event, in non-rewind mode, pvr stop recording; In rewind mode, pvr keep recording.*//**<CNcomment: ¼\D6Ƴ\A4\B6ȴﵽָ\B6\A8\B5ĳ\A4\B6\C8. \C9ϱ\A8\D5\E2\B8\F6\CA¼\FE\BA󣬷ǻ\D8\C8\C6¼\D6\C6ģʽ\CF\C2ֹͣ¼\D6ƣ\BB\BB\D8\C8\C6¼\D6\C6ģʽ\CF¼\CC\D0\F8¼\D6\C6 */
    HI_UNF_PVR_EVENT_REC_REACH_PLAY                 = 0x013,          /**<The recording speed reaches the playing speed during time shift.*//**<CNcomment:  ʱ\D2Ƶ\C4ʱ\BA\F2¼\D6\C6׷\C9ϲ\A5\B7\C5 */
    HI_UNF_PVR_EVENT_REC_DISK_SLOW                  = 0x014,          /**<The storage speed of the disk is slower than the recording speed.*//**<CNcomment: \B4\C5\C5̴洢\CBٶ\C8\C2\FD\D3\DA¼\D6\C6\CBٶ\C8 */
    HI_UNF_PVR_EVENT_REC_REWIND_TO_LINEAR_COMPLETE  = 0x015,          /**<Rewinding switch to non-rewinding completed.the success or failure of the callback event reported*//**<CNcomment: \BB\D8\C8\C6ģʽ\C7л\BB\D6\C1\B7ǻ\D8\C8\C6ģʽ\CD\EA\B3ɣ\AC\CAǷ\F1\C7л\BB\B3ɹ\A6\D3ɻص\F7\BA\AF\CA\FD\BD\F8\D0\D0\C9ϱ\A8*/
    HI_UNF_PVR_EVENT_RECFILE_LINEARIZATION_COMPLETE = 0x016,          /**<File linearization completed.the success or failure of the callback event reported*//**<CNcomment:  \CEļ\FE\CF\DF\D0Ի\AF\CD\EA\B3\C9 \CAǷ\F1\CF\DF\D0Ի\AF\B3ɹ\A6\D3ɻص\F7\BA\AF\CA\FD\BD\F8\D0\D0\C9ϱ\A8*/
    HI_UNF_PVR_EVENT_REC_EOS                        = 0x017,          /**<all the data in the record buffer is received.*//*<CNcomment:PVR\D2\D1\CA\D5ȡ\B5\BD\CB\F9\D3\D0¼\D6\C6buffer\B5\C4TS\CA\FD\BE\DD*/
    HI_UNF_PVR_EVENT_REC_RESV                       = 0x01f,          /**<Reserved*//**<CNcomment:  \B1\A3\C1\F4 */
    HI_UNF_PVR_EVENT_BUTT                           = 0x020           /**<Invalid event type*//**<CNcomment: \CE\DEЧ\B5\C4\CA¼\FE\C0\E0\D0\CD */
} HI_UNF_PVR_EVENT_E;

/**Callback function of PVR event*//** CNcomment: PVR\CA¼\FE\BBص\F7\BA\AF\CA\FD */
typedef void (*eventCallBack)(HI_U32 u32ChnID, HI_UNF_PVR_EVENT_E EventType, HI_S32 s32EventValue, HI_VOID *args);

/**Type of recorded and played streams of the PVR*//** CNcomment: PVR¼\D6ơ\A2\B2\A5\B7ŵ\C4\C2\EB\C1\F7\C0\E0\D0\CD */
typedef enum hiUNF_PVR_STREAM_TYPE_E
{
    HI_UNF_PVR_STREAM_TYPE_TS,        /**<Transport stream (TS)*//**<CNcomment:  TS\C1\F7 */
    HI_UNF_PVR_STREAM_TYPE_PES,       /**<Packetized elementary stream (PES)*//**<CNcomment: PES\C1\F7 */
    HI_UNF_PVR_STREAM_TYPE_ALL_TS,    /**<All types of streams. That is, the streams at all frequencies are recorded.*//**<CNcomment: ȫ\C2\EB\C1\F7¼\D6ƣ\AC¼\D6\C6\D5\FB\B8\F6Ƶ\B5\E3\B5\C4\CB\F9\D3\D0\C2\EB\C1\F7 */
    HI_UNF_PVR_STREAM_TYPE_OTHER,     /**<Invalid*//**<CNcomment:  \CE\DEЧ\B5\C4\C0\E0\D0\CD */
    HI_UNF_PVR_STREAM_TYPE_BUTT
} HI_UNF_PVR_STREAM_TYPE_E;

/**Index type*//** CNcomment: \CB\F7\D2\FD\C0\E0\D0\CD */
typedef enum hiUNF_PVR_REC_INDEX_TYPE_E
{
    HI_UNF_PVR_REC_INDEX_TYPE_NONE,      /**<No index is created. You need to select this type when recording all streams.*//**<CNcomment: <\B2\BB\BD\A8\CB\F7\D2\FD\A1\A3ȫ\C2\EB\C1\F7¼\D6Ƶ\C4ʱ\BA\F2\C7\EBʹ\D3ô\CB\C0\E0\D0\CD  */
    HI_UNF_PVR_REC_INDEX_TYPE_VIDEO,     /**<The index is created based on videos.*//**<CNcomment: <\D5\EB\B6\D4\CA\D3Ƶ\BD\A8\C1\A2\CB\F7\D2\FD\A1\A3 */
    HI_UNF_PVR_REC_INDEX_TYPE_AUDIO,     /**<The index is created based on audios. *//**<CNcomment: <\D5\EB\B6\D4\D2\F4Ƶ\BD\A8\C1\A2\CB\F7\D2\FD\A1\A3 */
    HI_UNF_PVR_REC_INDEX_TYPE_BUTT       /**<Invalid*//**<CNcomment: <\CE\DEЧ\B5\C4\CB\F7\D2\FD\C0\E0\D0͡\A3   */
} HI_UNF_PVR_REC_INDEX_TYPE_E;

/**Information about a stream file recorded by the PVR*//** CNcomment:  PVR¼\D6Ƶ\C4\C2\EB\C1\F7\CEļ\FE\D0\C5Ϣ */
typedef struct hiUNF_PVR_FILE_ATTR_S
{
    HI_UNF_PVR_REC_INDEX_TYPE_E enIdxType;          /**<Index type*//**<CNcomment:  \CB\F7\D2\FD\C0\E0\D0\CD */
    HI_U32                      u32FrameNum;        /**<For a video file: number of frames in the file. For an audio file: number of PESs in the file*//**<CNcomment:  \B6\D4\CA\D3Ƶ\CEļ\FE\A3\BA\CEļ\FE֡\CA\FD;\B6\D4\D2\F4Ƶ\CEļ\FE\A3\BA\CEļ\FE\D6е\C4PES\CA\FD */
    HI_U32                      u32StartTimeInMs;   /**<Start time of the file, in ms*//**<CNcomment: \CEļ\FE\C4\DA\C8ݵ\C4\C6\F0ʼʱ\BC䣬\C6\F0ʼ֡PTS\A3\AC\B5\A5λms */
    HI_U32                      u32EndTimeInMs;     /**<End time of the file, in ms*//**<CNcomment: \CEļ\FE\C4\DA\C8ݵĽ\E1\CA\F8ʱ\BC䣬\BD\E1\CA\F8֡PTS\A3\AC\B5\A5λms  */
    HI_U64                      u64ValidSizeInByte; /**<Valid data length of the file, in byte *//**<CNcomment:  \CEļ\FE\B5\C4\D3\D0Ч\CA\FD\BEݳ\A4\B6ȣ\AC\B5\A5λbyte */
} HI_UNF_PVR_FILE_ATTR_S;

/***** Data Structures for Recording  *****/
/** Record statuses*/
/**INVALID -> INIT -> RUNNING -> STOPPING ->    STOP ->    INVALID  (saveIndex)  (saveStream)*/

/**Status of a recording channel*//** CNcomment: ¼\D6\C6ͨ\B5\C0\B5\C4״̬ */
typedef enum hiUNF_PVR_REC_STATE_E
{
  HI_UNF_PVR_REC_STATE_INVALID,        /**<Not initialized*//**<CNcomment:  δ\B3\F5ʼ\BB\AF\A1\A3    */
  HI_UNF_PVR_REC_STATE_INIT,           /**<Initialized*//**<CNcomment:  \B3\F5ʼ\BB\AF\A1\A3      */
  HI_UNF_PVR_REC_STATE_RUNNING,        /**<Recording*//**<CNcomment:  ¼\D6\C6\D6С\A3      */
  HI_UNF_PVR_REC_STATE_PAUSE,          /**<Pause*//**<CNcomment:  \D4\DDͣ\D6\D0        */
  HI_UNF_PVR_REC_STATE_STOPPING,       /**<Stopping*//**<CNcomment: \D5\FD\D4\DAֹͣ\A1\A3    */
  HI_UNF_PVR_REC_STATE_STOP,           /**<<Stopped*//**<CNcomment: \D2Ѿ\ADֹͣ\A1\A3    */
  HI_UNF_PVR_REC_STATE_PID_CHANGE,     /**<PID is changing*//**<CNcomment: PID\D5\FD\D4\DA\C7л\BB*/
  HI_UNF_PVR_REC_STATE_BUTT            /**<Invalid*//**<CNcomment: \CE\DEЧ\B5\C4״ֵ̬\A1\A3*/
} HI_UNF_PVR_REC_STATE_E;

/**<Record pid info when pid changed.*//**<CNcomment: \BC\C7¼Pid\B1\E4\B8\FCʱ\D0\E8Ҫ\B5\C4pid\D0\C5Ϣ*/
typedef struct hiUNF_PVR_PID_CHANGE_INFO_S
{
    HI_U32                      u32PidNum;                              /**<pid number in u32PidList.*//**<CNcomment: \BC\C7¼pidList\D6\D0pid\B5ĸ\F6\CA\FD\A1\A3*/
    HI_UNF_PVR_REC_INDEX_TYPE_E enIndexType;                            /**<Index type.*//**<CNcomment: \CB\F7\D2\FD\C0\E0\D0\CD*/
    HI_U32                      u32IndexPid;                            /**<Index PID.*//**<CNcomment: \CB\F7\D2\FDPID\A1\A3*/
    HI_UNF_VCODEC_TYPE_E        enVidType;                              /**<Video Type.*//**<CNcomment:\B4\FD\BD\A8\C1\A2\CB\F7\D2\FD\B5\C4\C2\EB\C1\F7\B5\C4\CA\D3Ƶ\B1\E0\C2\EBЭ\D2\E9, \CB\F7\D2\FD\C0\E0\D0\CD\CA\C7HI_UNF_PVR_REC_INDEX_TYPE_VIDEOʱ\B2\C5\D0\E8Ҫ\C5\E4\D6\C3,\BE\B2̬\CA\F4\D0\D4 */
    HI_U32                      u32PidList[HI_UNF_PVR_REC_MAX_PID_NUM]; /**<Pid List*//**<CNcomment: pid\C1б\ED\A1\A3*/
}HI_UNF_PVR_PID_CHANGE_INFO_S;

/**<Packet Type of stream.*//**<CNcomment: \C2\EB\C1\F7\B5İ\FC\C0\E0\D0\CD*/
typedef enum hiUNF_PVR_TS_PACKET_TYPE_E
{
    HI_UNF_PVR_TS_PACKET_188 = 0,       /**<Packet size is 188 byte*//**<CNcomment: \C2\EB\C1\F7\D6а\FC\B4\F3СΪ188\D7ֽ\DA*/
    HI_UNF_PVR_TS_PACKET_192,           /**<Packet size is 192 byte*//**<CNcomment: \C2\EB\C1\F7\D6а\FC\B4\F3СΪ192\D7ֽ\DA*/
    HI_UNF_PVR_TS_PACKET_BUTT           /**<Invalid*//**<CNcomment: \CE\DEЧ\B5İ\FC\C0\E0\D0\CD*/
}HI_UNF_PVR_TS_PACKET_TYPE_E;

/**<PID is changing callback type. <CNcomment: PID\B1\E4\B8\FC\BBص\F7\BA\AF\CA\FD\C0\E0\D0\CDCNend
\param[in] u32ChnId  Record chanel ID CNcomment:¼\D6\C6ͨ\B5\C0IDCNend
\param[in] pstOldPidInfo    Pointer to the old pid info CNcomment:PID\B1\E4\B8\FCǰ\B5\C4PID\D0\C5ϢCNend
\param[in] pstNewPidInfo    Pointer to the new pid info CNcomment:PID\B1\E4\B8\FC\BA\F3\B5\C4PID\D0\C5ϢCNend
\param[in] pArgs    user data CNcomment:\D3û\A7˽\D3\D0\CA\FD\BE\DDCNend
*/
typedef HI_S32 ( *PidChangeCallBack)(HI_U32 u32ChnId, HI_UNF_PVR_PID_CHANGE_INFO_S *pstOldPidInfo, HI_UNF_PVR_PID_CHANGE_INFO_S *pstNewPidInfo, HI_VOID *pArgs);

/**Attributes of a recording channel*//** CNcomment: ¼\D6\C6ͨ\B5\C0\CA\F4\D0\D4\CA\FD\BEݽṹ */
typedef struct hiUNF_PVR_REC_ATTR_S
{
    HI_UNF_PVR_REC_INDEX_TYPE_E enIndexType;                           /**<Index type, static attribute.*//**<CNcomment:  \CB\F7\D2\FD\C0\E0\D0ͣ\AC\BE\B2̬\CA\F4\D0ԡ\A3 */
    HI_UNF_VCODEC_TYPE_E        enIndexVidType;                        /**<Video encoding protocol with which the stream (for which an index is to be created) complies. The protocol (static attribute) needs to be set only when the index type is HI_UNF_PVR_REC_INDEX_TYPE_VIDEO.*/
                                                                       /**<CNcomment: \B4\FD\BD\A8\C1\A2\CB\F7\D2\FD\B5\C4\C2\EB\C1\F7\B5\C4\CA\D3Ƶ\B1\E0\C2\EBЭ\D2\E9, \CB\F7\D2\FD\C0\E0\D0\CD\CA\C7HI_UNF_PVR_REC_INDEX_TYPE_VIDEOʱ\B2\C5\D0\E8Ҫ\C5\E4\D6\C3,\BE\B2̬\CA\F4\D0\D4  */
    HI_U32                      u32IndexPid;                           /**<Index PID, static attribute.*//**<CNcomment:  \CB\F7\D2\FDPID\A3\AC\BE\B2̬\CA\F4\D0\D4*/
    HI_U32                      u32DemuxID;                            /**<Recording DEMUX ID, static attribute.*//**<CNcomment:  ¼\D6\C6DEMUX\BAţ\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_U32                      u32DavBufSize;                         /**<Size (in byte) of a data stream buffer, static attribute.*//**<CNcomment:  \CA\FD\BE\DD\C1\F7\BB\BA\B3\E5\C7\F8\B4\F3С\A3\AC\B5\A5λΪByte\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3  */
    HI_U32                      u32ScdBufSize;                         /**<Size (in byte) of an index data buffer, static attribute.*//**<CNcomment:  \CB\F7\D2\FD\CA\FD\BEݻ\BA\B4\E6\C7\F8\B4\F3С\A3\AC\B5\A5λΪByte\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_U32                      u32UsrDataInfoSize;                    /**<Size (in byte) of the private user data, static attribute.*//**<CNcomment:  \D3û\A7˽\D3\D0\CA\FD\BEݴ\F3С\A3\AC\B5\A5λΪByte\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3  */
    HI_BOOL                     bIsClearStream;                        /**<Whether to record streams as clear streams, static attribute. This item indicates that the stored streams are clear streams or scrambled streams. If the programs to be recorded are scrambled streams, the clear streams can be recorded only after a descrambler is configured for the audio/video channel of the DEMUX.
                                                                       The recording module of the PVR does not descramble the scrambled streams.*/
                                                                       /**<CNcomment: \CAǷ\F1\B0\D1\C2\EB\C1\F7¼\D6Ƴ\C9\C7\E5\C1\F7\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3\B4\CB\CF\EE\B5\C4\D2\E2˼\CAǴ\E6\CF\C2\C0\B4\B5\C4\C2\EB\C1\F7\CA\C7\C7\E5\C1\F7\BB\B9\CAǼ\D3\C8\C5\C1\F7\A1\A3\C8\E7\B9\FB\B4\FD¼\D6ƵĽ\DAĿ\CAǼ\D3\C8\C5\C1\F7\A3\AC\D0\E8Ҫ\D4\DA¼\D6\C6DEMUX\C9\CF\C6\F4\B6\AFһ·CA\B2\C5\C4\DC¼\D6\C6\C7\E5\C1\F7,PVR¼\D6\C6ģ\BF鲢\B2\BB\B8\BA\D4\F0\B6Լ\D3\C8\C5\C1\F7\B5Ľ\E2\C8Ų\D9\D7\F7\A1\A3*/
    HI_UNF_PVR_STREAM_TYPE_E    enStreamType;                          /**<Type of the data to be recorded, static attribute.*//**<CNcomment: \B4\FD¼\D6Ƶ\C4\CA\FD\BE\DD\C0\E0\D0ͣ\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_UNF_PVR_CIPHER_S         stEncryptCfg;                          /**<Stream encryption configuration, static attribute.*//**<CNcomment: \C2\EB\C1\F7\BC\D3\C3\DC\C5\E4\D6\C3\D0\C5Ϣ\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_U64                      u64MaxFileSize;                        /**<Size of the file to be recorded, static attribute. If the value is 0, it indicates that there is no limit on the file size. The minimum file size is 52428800 bytes (50 MB). If the disk space is sufficient, it is recommended to set the file size to a value greater than 512 MB. The file size cannot be 0 in rewind mode. */
                                                                       /**<CNcomment: \B4\FD¼\D6Ƶ\C4\CEļ\FE\B4\F3С\A3\ACΪ0ʱ\B1\EDʾ\CE\DE\CF\DE\D6ƣ\AC\BE\B2̬\CA\F4\D0ԡ\A3\D7\EEСֵΪ50M,\C8\E7\B9\FB\B4\C5\C5̿ռ\E4\D7㹻\B5Ļ\B0\A3\AC\CDƼ\F6\C5\E4\D6\C3Ϊ512M\D2\D4\C9ϡ\A3\C5\E4\D6\C3Ϊ\BB\D8\C8\C6ʱ\B2\BB\D4\CA\D0\ED\B0\D1\CEļ\FE\B4\F3С\BA\CD\CEļ\FE\B2\A5\B7\C5ʱ\BC䶼\C5\E4\D6\C3Ϊ0\A1\A3 */
    HI_U64                      u64MaxTimeInMs;                        /**<Max play time of the file to be recorded, static attribute. If the value is 0, it indicates that there is no limit on the file play time. The minimum file time is 60*1000 MS (1 Min).  The file size  and file time cannot both be 0 in rewind mode.*/
                                                                       /**<CNcomment: \B4\FD¼\D6Ƶ\C4\CEļ\FE\B5\C4\D7\B2\A5\B7\C5ʱ\BC䳤\B6ȣ\ACΪ0ʱ\B1\EDʾ\CE\DE\CF\DE\D6ƣ\AC\BE\B2̬\CA\F4\D0ԡ\A3\D7\EEС\B2\A5\B7\C5ʱ\BC\E4Ϊ60*1000\BA\C1\C3\EB(1\B7\D6\D6\D3)\A1\A3\BB\D8\C8\C6ģʽ\CF£\AC\B2\BB\C4ܽ\AB\CEļ\FE\D7\EE\B4\F3\B4\F3С\BA\CD\CEļ\FE\D7\B2\A5\B7\C5ʱ\BC\E4ͬʱ\C9\E8\D6\C3Ϊ0\A1\A3*/
    HI_BOOL                     bRewind;                               /**<Whether to rewind, If this item is set to HI_TRUE, the PVR rewinds to the file header to record streams after the recorded file size reaches u64MaxFileSize. If this item is set to HI_FALSE, the PVR stops recording after the recorded file size reaches u64MaxFileSize.*/
                                                                       /**<CNcomment: \CAǷ\F1\BB\D8\C8ơ\A3\C8\E7\C5\E4\D6\C3ΪHI_TRUE\A3\AC¼\D6\C6\CEļ\FE\B4\F3С\B5\BD\B4\EFu64MaxFileSize\BA󣬻\E1\BB\D8\C8Ƶ\BD\CEļ\FEͷ\BC\CC\D0\F8\BD\F8\D0\D0¼\D6ƣ\BB\C8\E7\C5\E4\D6\C3ΪHI_FALSE\A3\AC\D4\F2¼\D6\C6\CEļ\FE\B4\F3С\B5\BD\B4\EFu64MaxFileSize\BA󣬻\E1ֹͣ¼\D6ơ\A3*/
    HI_CHAR                     szFileName[PVR_MAX_FILENAME_LEN];      /**<Name of a stream file, static attribute*//**<CNcomment: \C2\EB\C1\F7\CEļ\FE\C3\FB\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_U32                      u32FileNameLen;                        /**<Length of a stream file name, static attribute. You need to set the item to strlen (szFileName).*//**<CNcomment: \C2\EB\C1\F7\CEļ\FE\C3\FB\B3\A4\B6ȣ\AC\BE\B2̬\CA\F4\D0ԡ\A3ȡֵΪstrlen\A3\A8szFileName\A3\A9\BC\B4\BF\C9 */
    HI_UNF_PVR_SECURE_MODE_E    enSecureMode;                          /**<Secure channel indication*/ /**<CNcomment:\B0\B2ȫͨ\B5\C0\B1\EAʾ*/
    HI_BOOL                     bAppendRec;                            /**<Whether to append record,static attribute.If this item is set to HI_TRUE, and the parameters transferred from the upper-layer meets the:(a).add the recording file name the same as that of the before.(b). corresponding to the file name of the file is a wrap-around. (c). bRewind is HI_FALSE. (d). be consistent with the index type. (e).PID information is consistent with the previously.
                                                                                                                   (f). was recording time of the recording files must be greater than or equal to 60s. (g). maximum file size or the maximum recording time is exceeded.The Append recording starts.Otherwise,Append recording failed.If this item is set to HI_FALSE,not need to Append recording.*/
                                                                        /**<CNcomment: \CAǷ\F1\D0\F8¼\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3\C8\E7\B9\FB\C5\E4\D6\C3ΪHI_TRUE\A3\AC\C7\D2\C9ϲ㴫\C8\EB\B5Ĳ\CE\CA\FD\C2\FA\D7㣺(a)\A1\A2׷\BC\D3¼\D6\C6\CEļ\FE\C3\FB\D3\EB֮ǰ\B1\A3\B3\D6һ\D6\C2.(b)\A1\A2\CEļ\FE\C3\FB\B6\D4Ӧ\B5\C4\CEļ\FE\CAǷǻ\D8\C8Ƶġ\A3(c)\A1\A2bRewind\CA\C7HI_FALSE\A1\A3(d)\A1\A2\CB\F7\D2\FD\C0\E0\D0\CD\D3\EB֮ǰ\B1\A3\B3\D6һ\D6¡\A3(e)\A1\A2PID\D0\C5Ϣ\D3\EB֮ǰ\B1\A3\B3\D6һ\D6\C2.
                                                                                                                    (f)\A1\A2\B1\BB\D0\F8¼\CEļ\FE\B5\C4¼\D6\C6ʱ\BC\E4\D0費С\D3\DA60s\A1\A3(g)\A1\A2\D7\EE\B4\F3¼\D6\C6\CEļ\FE\B4\F3С\BB\F2\D7\EE\B4\F3¼\D6\C6ʱ\BC\E4\CAǷ񳬳\F6\A1\A3 \B7\F1\D4\F2\D0\F8¼ʧ\B0ܡ\A3\C8\E7\B9\FB\C9\E8\D6\C3ΪHI_FALSE,\D4򲻽\F8\D0\D0\D0\F8¼*/
    HI_UNF_PVR_TS_PACKET_TYPE_E enTsPacketType;                        /**<Packet Type of the stream to be recorded.*//**<CNcomment: \B4\FD¼\D6\C6\C2\EB\C1\F7\B5İ\FC\C0\E0\D0\CD*/
    HI_U32                      u32Reserved;
}HI_UNF_PVR_REC_ATTR_S;

/**Status of a PVR buffer*//** CNcomment:\B6\A8\D2\E5PVR\BB\BA\B3\E5\C7\F8\B5\C4״̬\D0\C5Ϣ */
typedef struct hiUNF_PVR_BUF_STATUS_S
{
    HI_U32 u32BufSize;       /**<Buffer size*//**<CNcomment: \BB\BA\B3\E5\C7\F8\B4\F3С       */
    HI_U32 u32UsedSize;      /**<Used buffer size*//**<CNcomment: \BB\BA\B3\E5\C7\F8\D2\D1ʹ\D3ô\F3С */
} HI_UNF_PVR_BUF_STATUS_S;

typedef struct hiUNF_PVR_APPEND_REC_INFO_S
{
    HI_BOOL bAppendRec;            /**<if current record is appended*//**<CNcomment: \B5\B1ǰ\CAǷ\F1\CA\C7׷\BC\D3¼\D6ơ\A3    */
    HI_U32 u32Reserved;
    HI_U64 u64AppendOffset;        /**<the offset of beginning to append, only valid if bAppRec=HI_TRUE*//**<CNcomment: ׷\BC\D3¼\D6Ƶ\C4λ\D6\C3, \BD\F6\D4\DA׷\BC\D3¼\D6\C6ʱ\D3\D0Ч\A1\A3    */
}HI_UNF_PVR_APPEND_REC_INFO_S;

/**Status of a recording channel.
The following describes the relationships among u32CurTimeInMs, u32StartTimeInMs, and u32EndTimeInMs by taking examples:
1. Assume that the total recording time is 10000 ms, and no rewind occurs. In this case, u32StartTimeInMs is 0 ms, u32EndTimeInMs is 10000 ms, and u32CurTimeInMs is 10000 ms.
2. Assume that the total recording time is 10000 ms, and rewind occurs at 8000 ms. In this case, u32StartTimeInMs is 2000 ms, u32EndTimeInMs is 10000 ms, and u32CurTimeInMs is 8000 ms.
*/
/** CNcomment:¼\D6\C6ͨ\B5\C0״̬\CA\FD\BEݽṹ.
\B6\D4u32CurTimeInMs\A1\A2u32StartTimeInMs\A1\A2u32EndTimeInMs\C8\FD\D5ߵĹ\D8ϵ\BE\D9\C0\FD˵\C3\F7\C8\E7\CF£\BA
1\A1\A4\BC\D9\C9\E8\B4ӿ\AAʼ¼\D6ƺ\F3һ\B9\B2¼\D6\C6\C1\CB10000\BA\C1\C3룬\C8\E7\B9\FBû\D3з\A2\C9\FA\BB\D8\C8ƣ\AC\C4\C7ôu32StartTimeInMs Ϊ0\A3\ACu32EndTimeInMs Ϊ10000\A3\AC u32CurTimeInMsΪ10000\A1\A3
2\A1\A4\BC\D9\C9\E8\B4ӿ\AAʼ¼\D6ƺ\F3һ\B9\B2¼\D6\C6\C1\CB10000\BA\C1\C3룬\B2\A2\C7\D2\D4ڵ\DA8000\BA\C1\C3\EB\B5\C4ʱ\BA\F2\B7\A2\C9\FA\C1˻\D8\C8ƣ\AC\C4\C7ôu32StartTimeInMs Ϊ2000\A3\ACu32EndTimeInMs Ϊ10000\A3\AC u32CurTimeInMsΪ8000\A1\A3
*/
typedef struct hiUNF_PVR_REC_STATUS_S
{
    HI_UNF_PVR_REC_STATE_E      enState;                 /**<Current status of a channel*//**<CNcomment: ͨ\B5\C0\CB\F9\B4\A6\B5\C4״̬\A1\A3    */
    HI_U32                      u32Reserved;             /**<Reserved, for alignment*//**<CNcomment: \B1\A3\C1\F4\A3\AC\D3\C3\D7\F7\B6\D4\C6롣    */
    HI_U64                      u64CurWritePos;          /**<Current recording position of file, in byte*//**<CNcomment: \B5\B1ǰ¼\D6\C6д\CEļ\FE\B5\C4λ\D6ã\A8\B5\A5λ\A3\BAbyte\A3\A9\A1\A3 */
    HI_U32                      u32CurWriteFrame;        /**<Number of currently recorded frames*//**<CNcomment: \B5\B1ǰ¼\D6Ƶ\C4֡\CA\FD\A1\A3                  */
    HI_U32                      u32CurTimeInMs;          /**<Current recording time (in ms). The value is the valid time for recording the file.*//**<CNcomment: \B5\B1ǰ¼\D6Ƶĺ\C1\C3\EB\CA\FD\A1\A3\C6\E4ֵΪ¼\D6\C6\CEļ\FE\B5\C4ʵ\BC\CA\D3\D0Чʱ\B3\A4\A1\A3*/
    HI_U32                      u32StartTimeInMs;        /**<Actual start time for recording files. Before the recording is rewound, the time is that of the first frame; after the recording is rewound, the time is the rewind time.*//**<CNcomment: ¼\D6\C6\CEļ\FE\B5\C4ʵ\BC\CA\C6\F0ʼ\B5㡣¼\D6ƻ\D8\C8\C6ǰ\A3\ACΪ\B5\DAһ֡ʱ\BC䣻¼\D6ƻ\D8\C8ƺ\F3\A3\ACΪ\BB\D8\C8Ƶ\E3\B5\C4ʱ\BC䡣 */
    HI_U32                      u32EndTimeInMs;          /**<Time of the end frame in the recorded file. Before the recording is rewound, the time is that of the last frame.*//**<CNcomment:¼\D6\C6\CEļ\FE\D6н\E1\CA\F8֡\B5\C4ʱ\BC䣬û\D3л\B7\BB\D8ǰ\BC\B4\D7\EE\BA\F3һ֡\B5\C4ʱ\BC䡣    */
    HI_UNF_PVR_BUF_STATUS_S     stRecBufStatus;          /**<Status of the recording channel buffer*//**<CNcomment:¼\D6\C6ͨ\B5\C0\BB\BA\B3\E5\C7\F8״̬\A1\A3    */
    HI_UNF_PVR_APPEND_REC_INFO_S stAppendRecInfo;        /**the infomation for append-recording*//**<CNcomment:׷\BC\D3¼\D6\C6\D0\C5Ϣ\A1\A3    */
}HI_UNF_PVR_REC_STATUS_S;

/** Data structures for playing */

/**Playing direction of the PVR: forward*//** CNcomment:PVR\B2\A5\B7ŷ\BD\CF\F2:\CD\F9ǰ\B2\A5\B7\C5 */
#define HI_UNF_PVR_PLAY_DIRECTION_FORWARD             (1)
/**Playing direction of the PVR: backward*//** CNcomment: PVR\B2\A5\B7ŷ\BD\CF\F2:\CD\F9\BA󲥷\C5 */
#define HI_UNF_PVR_PLAY_DIRECTION_BACK                (-1)

/**Type of the playing position*//** CNcomment: \B2\A5\B7\C5λ\D6\C3\C0\E0\D0\CD */
typedef enum hiUNF_PVR_PLAY_POS_TYPE_E
{
  HI_UNF_PVR_PLAY_POS_TYPE_SIZE,              /**<The playing position is expressed by size (in byte). This type is not supported currently.*//**<CNcomment: \D3ô\F3С\A3\A8\B5\A5λ\A3\BAbyte\A3\A9\B1\EDʾλ\D6ã\A8\D4ݲ\BB֧\B3֣\A9 */
  HI_UNF_PVR_PLAY_POS_TYPE_TIME,              /**<The playing position is expressed by time (in ms).*//**<CNcomment: \D3\C3ʱ\BC䣨\B5\A5λ\A3\BAms\A3\A9\CA\FD\B1\EDʾλ\D6\C3 */
  HI_UNF_PVR_PLAY_POS_TYPE_FRAME,             /**<The playing position is expressed by the number of frames or PESs. This type is not supported currently.*//**<CNcomment: \D3\C3֡\CA\FD\A3\A8\BB\F2\D5\DFPES\CA\FD\A3\A9\B1\EDʾλ\D6ã\A8\D4ݲ\BB֧\B3֣\A9  */
  HI_UNF_PVR_PLAY_POS_TYPE_BUTT               /**<Invalid*//**<CNcomment:\CE\DEЧ\B5\C4λ\D6\C3\C0\E0\D0\CD*/
} HI_UNF_PVR_PLAY_POS_TYPE_E;

/**Status of a playing channel*//** CNcomment: \B2\A5\B7\C5ͨ\B5\C0\B5\C4״̬  */
typedef enum hiUNF_PVR_PALY_STATE_E
{
    HI_UNF_PVR_PLAY_STATE_INVALID,       /**<Not initialized*//**<CNcomment: δ\B3\F5ʼ\BB\AF            */
    HI_UNF_PVR_PLAY_STATE_INIT,          /**<Initialized*//**<CNcomment: \B3\F5ʼ\BB\AF              */
    HI_UNF_PVR_PLAY_STATE_PLAY,          /**<Normal playing*//**<CNcomment: \D5\FD\B3\A3\B2\A5\B7\C5\D6\D0          */
    HI_UNF_PVR_PLAY_STATE_PAUSE,         /**<Pause*//**<CNcomment: \D4\DDͣ                */
    HI_UNF_PVR_PLAY_STATE_FF,            /**<Fast forward*//**<CNcomment: \BF\EC\BD\F8                */
    HI_UNF_PVR_PLAY_STATE_FB,            /**<Fast backward*//**<CNcomment: \BF\EC\CD\CB                */
    HI_UNF_PVR_PLAY_STATE_SF,            /**<Slow forward*//**<CNcomment: \C2\FD\B7\C5                */
    HI_UNF_PVR_PLAY_STATE_SB,            /**<Slow backward*//**<CNcomment:\C2\FD\CD\CB         */
    HI_UNF_PVR_PLAY_STATE_STEPF,         /**<Step forward*//**<CNcomment:\D6\F0֡\B2\A5\B7\C5            */
    HI_UNF_PVR_PLAY_STATE_STEPB,         /**<Step backward*//**<CNcomment: \D6\F0֡\B5\B9\B7\C5            */
    HI_UNF_PVR_PLAY_STATE_STOP,          /**<Stop*//**<CNcomment: ֹͣ                */
    HI_UNF_PVR_PLAY_STATE_BUTT           /**<Invalid*//**<CNcomment: \CE\DEЧ\B5\C4״ֵ̬        */
} HI_UNF_PVR_PLAY_STATE_E;

/**Identifier of the playing speed*//** CNcomment: \B2\A5\B7\C5\CBٶȱ\EAʶ */
typedef enum hiUNF_PVR_PLAY_SPEED_E
{
    HI_UNF_PVR_PLAY_SPEED_NORMAL            = 1024,                                     /**<Normal playing speed*//**<CNcomment:\D5\FD\B3\A3\CBٶȲ\A5\B7š\A3    */
    HI_UNF_PVR_PLAY_SPEED_2X_FAST_FORWARD   = 2 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast forward at two times the normal speed*//**<CNcomment:2\B1\B6\CBٿ\EC\B7š\A3            */
    HI_UNF_PVR_PLAY_SPEED_4X_FAST_FORWARD   = 4 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast forward at four times the normal speed*//**<CNcomment:4\B1\B6\CBٿ\EC\B7š\A3            */
    HI_UNF_PVR_PLAY_SPEED_8X_FAST_FORWARD   = 8 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast forward at eight times the normal speed*//**<CNcomment:8\B1\B6\CBٿ\EC\B7š\A3            */
    HI_UNF_PVR_PLAY_SPEED_12X_FAST_FORWARD   = 12 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast forward at 12 times the normal speed*//**<CNcomment:12\B1\B6\CBٿ\EC\B7š\A3            */
    HI_UNF_PVR_PLAY_SPEED_16X_FAST_FORWARD  = 16 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast forward at 16 times the normal speed*//**<CNcomment:16\B1\B6\CBٿ\EC\B7š\A3           */
    HI_UNF_PVR_PLAY_SPEED_24X_FAST_FORWARD   = 24 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast forward at 24 times the normal speed*//**<CNcomment:24\B1\B6\CBٿ\EC\B7š\A3            */
    HI_UNF_PVR_PLAY_SPEED_32X_FAST_FORWARD  = 32 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast forward at 32 times the normal speed*//**<CNcomment:32\B1\B6\CBٿ\EC\B7š\A3           */
    HI_UNF_PVR_PLAY_SPEED_64X_FAST_FORWARD  = 64 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast forward at 64 times the normal speed*//**<CNcomment:64\B1\B6\CBٿ\EC\B7š\A3           */
    HI_UNF_PVR_PLAY_SPEED_1X_FAST_BACKWARD  = -1 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast backward at 1 times the normal speed, not support*//**<CNcomment:1\B1\B6\CBٵ\B9\B2\A5\A3\AC\D4ݲ\BB֧\B3֡\A3 */
    HI_UNF_PVR_PLAY_SPEED_2X_FAST_BACKWARD  = -2 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast backward at two times the normal speed*//**<CNcomment:2\B1\B6\CBٿ\EC\CDˡ\A3            */
    HI_UNF_PVR_PLAY_SPEED_4X_FAST_BACKWARD  = -4 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast backward at four times the normal speed*//**<CNcomment:4\B1\B6\CBٿ\EC\CDˡ\A3            */
    HI_UNF_PVR_PLAY_SPEED_8X_FAST_BACKWARD  = -8 * HI_UNF_PVR_PLAY_SPEED_NORMAL,        /**<Fast backward at eight times the normal speed*//**<CNcomment:8\B1\B6\CBٿ\EC\CDˡ\A3            */
    HI_UNF_PVR_PLAY_SPEED_12X_FAST_BACKWARD   = -12 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast backward at 12 times the normal speed*//**<CNcomment:12\B1\B6\CBٿ\EC\CDˡ\A3            */
    HI_UNF_PVR_PLAY_SPEED_16X_FAST_BACKWARD = -16 * HI_UNF_PVR_PLAY_SPEED_NORMAL,       /**<Fast backward at 16 times the normal speed*//**<CNcomment:16\B1\B6\CBٿ\EC\CDˡ\A3           */
    HI_UNF_PVR_PLAY_SPEED_24X_FAST_BACKWARD   = -24 * HI_UNF_PVR_PLAY_SPEED_NORMAL,         /**<Fast backward at 24 times the normal speed*//**<CNcomment:24\B1\B6\CBٿ\EC\CDˡ\A3            */
    HI_UNF_PVR_PLAY_SPEED_32X_FAST_BACKWARD = -32 * HI_UNF_PVR_PLAY_SPEED_NORMAL,       /**<Fast backward at 32 times the normal speed*//**<CNcomment:32\B1\B6\CBٿ\EC\CDˡ\A3           */
    HI_UNF_PVR_PLAY_SPEED_64X_FAST_BACKWARD = -64 * HI_UNF_PVR_PLAY_SPEED_NORMAL,       /**<Fast backward at 64 times the normal speed*//**<CNcomment:64\B1\B6\CBٿ\EC\CDˡ\A3           */
    HI_UNF_PVR_PLAY_SPEED_0_75X_SLOW_FORWARD   = HI_UNF_PVR_PLAY_SPEED_NORMAL * 3/ 4,         /**<Slow forward at 3/4 times the normal speed*//**<CNcomment:3/4\B1\B6\CB\D9\C2\FD\B7š\A3          */
    HI_UNF_PVR_PLAY_SPEED_2X_SLOW_FORWARD   = HI_UNF_PVR_PLAY_SPEED_NORMAL / 2,         /**<Slow forward at 1/2 times the normal speed*//**<CNcomment:1/2\B1\B6\CB\D9\C2\FD\B7š\A3          */
    HI_UNF_PVR_PLAY_SPEED_4X_SLOW_FORWARD   = HI_UNF_PVR_PLAY_SPEED_NORMAL / 4,         /**<Slow forward at 1/4 times the normal speed*//**<CNcomment:1/4\B1\B6\CB\D9\C2\FD\B7š\A3          */
    HI_UNF_PVR_PLAY_SPEED_8X_SLOW_FORWARD   = HI_UNF_PVR_PLAY_SPEED_NORMAL / 8,         /**<Slow forward at 1/8 times the normal speed*//**<CNcomment:1/8\B1\B6\CB\D9\C2\FD\B7š\A3          */
    HI_UNF_PVR_PLAY_SPEED_16X_SLOW_FORWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / 16,        /**<Slow forward at 1/16 times the normal speed*//**<CNcomment:1/16\B1\B6\CB\D9\C2\FD\B7š\A3         */
    HI_UNF_PVR_PLAY_SPEED_32X_SLOW_FORWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / 32,        /**<Slow forward at 1/32 times the normal speed*//**<CNcomment:1/32\B1\B6\CB\D9\C2\FD\B7š\A3         */
    HI_UNF_PVR_PLAY_SPEED_64X_SLOW_FORWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / 64,        /**<Slow forward at 1/64 times the normal speed*//**<CNcomment:1/64\B1\B6\CB\D9\C2\FD\B7š\A3         */
    HI_UNF_PVR_PLAY_SPEED_0_75X_SLOW_BACKWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL *3/ (-4),      /**<Slow backward at 3/4 times the normal speed.*//**<CNcomment:3/4\B1\B6\CB\D9\C2\FD\CDˡ\A3  */
    HI_UNF_PVR_PLAY_SPEED_2X_SLOW_BACKWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-2),      /**<Slow backward at 1/2 times the normal speed. *//**<CNcomment:1/2\B1\B6\CB\D9\C2\FD\CDˡ\A3  */
    HI_UNF_PVR_PLAY_SPEED_4X_SLOW_BACKWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-4),      /**<Slow backward at 1/4 times the normal speed.*//**<CNcomment:1/4\B1\B6\CB\D9\C2\FD\CDˡ\A3  */
    HI_UNF_PVR_PLAY_SPEED_8X_SLOW_BACKWARD  = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-8),      /**<Slow backward at 1/8 times the normal speed. This mode is not supported currently.*//**<CNcomment:1/8\B1\B6\CB\D9\C2\FD\CDˣ\AC\D4ݲ\BB֧\B3֡\A3  */
    HI_UNF_PVR_PLAY_SPEED_16X_SLOW_BACKWARD = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-16),     /**<Slow backward at 1/16 times the normal speed. This mode is not supported currently.*//**<CNcomment:1/16\B1\B6\CB\D9\C2\FD\CDˣ\AC\D4ݲ\BB֧\B3֡\A3 */
    HI_UNF_PVR_PLAY_SPEED_32X_SLOW_BACKWARD = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-32),     /**<Slow backward at 1/32 times the normal speed. This mode is not supported currently.*//**<CNcomment:1/32\B1\B6\CB\D9\C2\FD\CDˣ\AC\D4ݲ\BB֧\B3֡\A3 */
    HI_UNF_PVR_PLAY_SPEED_64X_SLOW_BACKWARD = HI_UNF_PVR_PLAY_SPEED_NORMAL / (-64),     /**<Slow backward at 1/64 times the normal speed. This mode is not supported currently.*//**<CNcomment:1/64\B1\B6\CB\D9\C2\FD\CDˣ\AC\D4ݲ\BB֧\B3֡\A3 */

    HI_UNF_PVR_PLAY_SPEED_0_5X_WITH_AUDIO = (HI_UNF_PVR_PLAY_SPEED_NORMAL / 2) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,    /**<Slow forward with audio at 0.5 times the normal speed*//**<CNcomment:0.5\B1\B6\CBٴ\F8\C9\F9\D2\F4\C2\FD\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_0_8X_WITH_AUDIO = (4 * HI_UNF_PVR_PLAY_SPEED_NORMAL / 5) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,     /**<Slow forward with audio at 0.8 times the normal speed*//**<CNcomment:0.8\B1\B6\CBٴ\F8\C9\F9\D2\F4\C2\FD\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_0_9X_WITH_AUDIO = (9 * HI_UNF_PVR_PLAY_SPEED_NORMAL / 10) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,    /**<Slow forward with audio at 0.9 times the normal speed*//**<CNcomment:0.9\B1\B6\CBٴ\F8\C9\F9\D2\F4\C2\FD\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_1_1X_WITH_AUDIO = (11 * HI_UNF_PVR_PLAY_SPEED_NORMAL / 10) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,    /**<Fast forward with audio at 1.1 times the normal speed*//**<CNcomment:1.1\B1\B6\CBٴ\F8\C9\F9\D2\F4\BF\EC\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_1_2X_WITH_AUDIO = (6 * HI_UNF_PVR_PLAY_SPEED_NORMAL / 5) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,    /**<Fast forward with audio at 1.2 times the normal speed*//**<CNcomment:1.2\B1\B6\CBٴ\F8\C9\F9\D2\F4\BF\EC\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_1_5X_WITH_AUDIO = (3 * HI_UNF_PVR_PLAY_SPEED_NORMAL / 2) | HI_UNF_PVR_TRICK_WITH_AUDIO_ENABLE,    /**<Fast forward with audio at 1.5 times the normal speed*//**<CNcomment:1.5\B1\B6\CBٴ\F8\C9\F9\D2\F4\BF\EC\B7š\A3*/
    HI_UNF_PVR_PLAY_SPEED_BUTT                                                          /**<Invalid value*//**<CNcomment:\CE\DEЧ\B5\C4\CBٶ\C8ֵ\A1\A3         */
} HI_UNF_PVR_PLAY_SPEED_E;

/**Trick mode*//** CNcomment: \CCؼ\BC\B2\A5\B7ŵ\C4ģʽ  */
typedef struct hiUNF_PVR_PLAY_MODE_S
{
    HI_UNF_PVR_PLAY_SPEED_E               enSpeed;    /**<For details about the playing speed, see the description of HI_UNF_PVR_PLAY_SPEED_E.*//**<CNcomment: \CBٶȣ\AC\BC\FBHI_UNF_PVR_PLAY_SPEED_E\B5Ķ\A8\D2\E5 */
}HI_UNF_PVR_PLAY_MODE_S;

typedef enum hiUNFPVR_TRICKPLAYTOEND_ACTION_E
{
    HI_UNF_PVR_TRICKPLAYTOEND_ACTION_STOP = 0, /**report event and stop channel when fast forward to end of the file or fast backward to the start**//**<CNcomment:\BF\EC\BD\F8\B5\BDβ\BB\F2\BF\EC\CD˵\BDͷ\A3\BA\C9ϱ\A8\CA¼\FE\BA\CDֹͣ\B2\A5\B7\C5ͨ\B5\C0**/
    HI_UNF_PVR_TRICKPLAYTOEND_ACTION_PLAY,     /**report event and switch to normal play when fast forward to end of the file or fast backward to the start**//**<CNcomment:\BF\EC\BD\F8\B5\BDβ\BB\F2\BF\EC\CD˵\BDͷ\A3\BA\C9ϱ\A8\CA¼\FE\BA\CD\C7л\BB\B5\BD\D5\FD\B3\A3\B2\A5\B7\C5**/
    HI_UNF_PVR_TRICKPLAYTOEND_ACTION_BUTT        /**Invalid option**//**<CNcomment:\B7Ƿ\A8ѡ\CF\EE**/
}HI_UNF_PVR_TRICKPLAYTOEND_ACTION_E;

/**Attributes of a playing channel*//** CNcomment:\B2\A5\B7\C5ͨ\B5\C0\CA\F4\D0\D4 */
typedef struct hiUNF_PVR_PLAY_ATTR_S
{
    HI_UNF_PVR_STREAM_TYPE_E        enStreamType;                         /**<Type of the played stream, static attributes. At present, only the TS is supported.*//**<CNcomment: \B2\A5\B7\C5\C2\EB\C1\F7\C0\E0\D0ͣ\ACĿǰֻ֧\B3\D6TS\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3*/
    HI_BOOL                         bIsClearStream;                       /**<Whether the stream to be played is the clear stream, static attribute. Scrambled streams can be played in normal mode only rather than in trick mode.*//**<CNcomment: \B4\FD\B2\A5\B7ŵ\C4\C2\EB\C1\F7\CAǷ\F1\C7\E5\C1\F7\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3\BC\D3\C8\C5\C1\F7\B2\BB֧\B3\D6\CCؼ\BC\B2\A5\B7ţ\ACֻ֧\B3\D6\D5\FD\B3\A3\B2\A5\B7\C5 */
    HI_UNF_PVR_CIPHER_S             stDecryptCfg;                         /**<Decryption configuration, static attribute                  *//**<CNcomment: \BD\E2\C3\DC\C5\E4\D6ã\AC\BE\B2̬\CA\F4\D0ԡ\A3                  */
    HI_CHAR                         szFileName[PVR_MAX_FILENAME_LEN];     /**<Name of the file that contains the streams to be played, static attribute        *//**<CNcomment: \B4\FD\B2\A5\B7\C5\C2\EB\C1\F7\B5\C4\CEļ\FE\C3\FB\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3        */
    HI_U32                          u32FileNameLen;                       /**<Length of the file name, static attribute. You need to set the item to strlen (szFileName).*//**<CNcomment: \CEļ\FE\C3\FB\B3\A4\B6ȣ\AC\BE\B2̬\CA\F4\D0ԡ\A3ȡֵΪstrlen\A3\A8szFileName\A3\A9\BC\B4\BF\C9 */
    HI_UNF_PVR_SECURE_MODE_E        enSecureMode;                         /**<Secure channel indication*/ /**<CNcomment:\B0\B2ȫͨ\B5\C0\B1\EAʾ*/
    HI_UNF_PVR_TRICKPLAYTOEND_ACTION_E  enTrickPlayToEndAction;             /**option for timeshift play, reference the HI_UNF_PVR_TRICKPLAYTOEND_ACTION_E**//**<CNcomment:ʱ\D2Ʋ\A5\B7\C5ѡ\CF\BF\EC\BD\F8\B5\BDβ\BB\F2\BF\EC\CD˵\BDͷ\B2\C9ȡ\B5Ķ\AF\D7\F7**/
}HI_UNF_PVR_PLAY_ATTR_S;


/**Description of the playing position*//** CNcomment: \B2\A5\B7\C5λ\D6\C3\C3\E8\CA\F6  */
typedef struct hiUNF_PVR_PLAY_POSITION_S
{
    HI_UNF_PVR_PLAY_POS_TYPE_E  enPositionType;       /**<Position type*//**<CNcomment: λ\D6\C3\C0\E0\D0͡\A3           */
    HI_S32                      s32Whence;            /**<Offset type, including SEEK_SET, SEEK_CUR, or SEEK_END*//**<CNcomment:ƫ\D2\C6\C0\E0\D0ͣ\ACȡֵ\B7\B6ΧΪSEEK_SET/SEEK_CUR/SEEK_END\A1\A3*/
    HI_S64                      s64Offset;            /**<Offset. If the offset type is time, the offset is in the unit of millisecond; if the offset type is frame, the offset is in the unit of frame.*//**<CNcomment:ƫ\D2ơ\A3 ƫ\D2\C6\C0\E0\D0\CDΪʱ\BC\E4ʱ\A3\AC\B5\A5λ\BA\C1\C3룻ƫ\D2\C6\C0\E0\D0\CDΪ֡ʱ\A3\AC\B5\A5λΪһ֡ */
}HI_UNF_PVR_PLAY_POSITION_S;

/**Information required for creating an index file*//** CNcomment: \B4\B4\BD\A8\CB\F7\D2\FD\CEļ\FE\D0\E8Ҫ\B5\C4\D0\C5Ϣ */
typedef struct hiUNF_PVR_GEN_IDX_ATTR_S
{
    HI_U32                      u32UsrDataInfoLen;         /**<Length of the user data*//**<CNcomment: \D3û\A7\CA\FD\BEݳ\A4\B6\C8 */
    HI_U32                      u32IdxPid;                 /**<Index PID*//**<CNcomment: \D5\EB\B6\D4\C4ĸ\F6Pid\BD\A8\C1\A2\CB\F7\D2\FD */
    HI_UNF_PVR_REC_INDEX_TYPE_E enIdxType;                 /**<Index type*//**<CNcomment: \CB\F7\D2\FD\C0\E0\D0\CD */
}HI_UNF_PVR_GEN_IDX_ATTR_S;

/**Status of a playing channel*//** CNcomment:\B2\A5\B7\C5ͨ\B5\C0\B5\C4״̬ */
typedef struct hiUNF_PVR_PLAY_STATUS_S
{
    HI_UNF_PVR_PLAY_STATE_E     enState;                              /**<Status of a playing channel*//**<CNcomment:\B2\A5\B7\C5ͨ\B5\C0״̬\A1\A3                                  */
    HI_UNF_PVR_PLAY_SPEED_E     enSpeed;                              /**<Playing speed of a playing channel*//**<CNcomment: \B2\A5\B7\C5ͨ\B5\C0\B5Ĳ\A5\B7\C5\CBٶȡ\A3                            */
    HI_U64                      u64CurPlayPos;                        /**<Start position (byte) of the current frame in the file*//**<CNcomment:\B5\B1ǰ\B2\A5\B7\C5֡\B5\C4\C6\F0ʼ\D4\DA\CEļ\FE\D6е\C4λ\D6ã\A8byte\CA\FD\A3\A9\A1\A3      */
    HI_U32                      u32CurPlayFrame;                      /**<Start position (number of frames or PESs) of the current frame in the file*//**<CNcomment:\B5\B1ǰ\B2\A5\B7\C5֡\D4\DA\CEļ\FE\D6е\C4λ\D6ã\A8֡\CA\FD\BB\F2\D5\DFPES\CA\FD\A3\A9       */
    HI_U32                      u32CurPlayTimeInMs;                   /**<PTS of the current frame, in ms*//**<CNcomment: \B5\B1ǰ\B2\A5\B7\C5֡\B5\C4PTS, \B5\A5λ\BA\C1\C3롣                     */
}HI_UNF_PVR_PLAY_STATUS_S;

/**<Data file attribution *//** CNcomment:\CA\FD\BE\DD\CEļ\FE\CA\F4\D0\D4*/
typedef struct hiUNF_PVR_DATA_ATTR_S
{
    HI_U32     u32ChnID;                              /**<PVR channel, just consider one channel*//**<CNcomment: PVRͨ\B5\C0\A3\AC\CF\D6\D4ڿ\C9\D2\D4ֻ\BF\BC\C2\C7һ\D6\D6ͨ\B5\C0\B5\C4\C7\E9\BF\F6 */
    HI_CHAR    CurFileName[PVR_MAX_FILENAME_LEN];     /**<Current reading file 's name include direction.If there are multi-node, the file name maybe different*//**<CNcomment: \B5\B1ǰ\D5\FD\D4ڶ\C1ȡ\B5\C4\CEļ\FE\C3\FB\A3\AC\B0\FC\C0\A8\BE\F8\B6\D4·\BE\B6\A1\A3\B6\E0\B8\F6\BDڵ\E3\C7\E9\BF\F6\CF£\AC\B8\C3\CEļ\FE\C3\FB\D3п\C9\C4ܻ\E1\B1䡣  */
    HI_CHAR    IdxFileName[PVR_MAX_FILENAME_LEN+5];
    HI_U64     u64FileStartPos;                       /**<Position of start frame ,it should be considered if rewind record ,0 invalid*//**<CNcomment:\CEļ\FE\B5Ŀ\AAʼλ\D6ã\AC\D6\F7Ҫ\D4\DA\CEļ\FE\BB\B7\BBص\C4\C7\E9\BF\F6\CF\C2\D0\E8Ҫ\BF\BC\C2\C7,Ϊ0ʱ\B1\EDʾ\CE\DEЧ  */
    HI_U64     u64FileEndPos;                         /**<Position of end frame ,it should be considered if rewind record ,0 invalid*//**<CNcomment:\CEļ\FE\B5Ľ\E1\CA\F8λ\D6ã\AC\D6\F7Ҫ\D4\DA\CEļ\FE\BB\B7\BBص\C4\C7\E9\BF\F6\CF\C2\D0\E8Ҫ\BF\BC\C2\C7,Ϊ0ʱ\B1\EDʾ\CE\DEЧ   */
    HI_U64     u64GlobalOffset;
    HI_U64     u64FileReadOffset;
} HI_UNF_PVR_DATA_ATTR_S;

/**<save buffer infomation *//**<CNcomment: \B1\A3\B4\E6buffer \D0\C5Ϣ*/
typedef struct hiUNF_PVR_BUF_S
{
    HI_U8 *pu8VirAddr;        /**<virtual address*//**<CNcomment:\D0\E9\C4\E2\B5\D8ַ*/
    HI_U32 u32PhyAddr;        /**<physical address*//**<CNcomment:\CE\EF\C0\ED\B5\D8ַ*/
    HI_U32 u32Len;            /**<buffer length*//**<CNcomment:buffer \B3\A4\B6\C8*/
}HI_UNF_PVR_BUF_S;

/**<Read or write data extra callback *//** CNcomment:\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD*/
typedef enum hiUNF_PVR_EXTRA_CALLBACK_E
{
    HI_UNF_PVR_EXTRA_READ_CALLBACK,          /**<Read data callback *//**<CNcomment:\B6\C1\CA\FD\BEݻ򲥷Żص\F7\BA\AF\CA\FD*/
    HI_UNF_PVR_EXTRA_WRITE_CALLBACK,         /**<Write data callback*//**<CNcomment:д\CA\FD\BEݻ\F2¼\D6ƻص\F7\BA\AF\CA\FD*/
    HI_UNF_PVR_EXTRA_CALLBACK_BUTT           /**<Invalid*//**<CNcomment: \CE\DEЧ\B5\C4״ֵ̬        */
} HI_UNF_PVR_EXTRA_CALLBACK_E;

/**<the record channel attribute ID *//** CNcomment:¼\D6\C6ͨ\B5\C0\B2\CE\CA\FD\B5\C4ID*/
typedef enum hiUNF_PVR_REC_ATTR_ID_E
{
    HI_UNF_PVR_REC_ATTR_ID_REWIND = 0,                   /**<change the rewind attribute,only support changing the rewind attribute to not rewind, HI_BOOL*//** <CNcomment: \B8ı\E4\BB\D8\C8\C6\CA\F4\D0ԣ\AC\BD\F6֧\B3ֻ\D8\C8Ʊ\E4\B8\FCΪ\B7ǻ\D8\C8\C6*/
    HI_UNF_PVR_REC_ATTR_ID_FILE_FRAGMENT_SIZE,           /**<set the file fragment size when recording in merged storage PVR, HI_U64*//**<CNcomment:\B5\B1PVR\BD\F8\D0кϲ\A2\B4洢¼\D6\C6ʱ\A3\AC\C9\E8\D6\C3¼\D6\C6\CEļ\FE\B7\D6Ƭ\B4\F3С*/
    HI_UNF_PVR_REC_ATTR_ID_BUTT                          /**<Invalid*//**<CNcomment: \CE\DEЧ\B5\C4״ֵ̬        */
} HI_UNF_PVR_REC_ATTR_ID_E;

/**Attributes of Linearization channel*//** CNcomment:\CF\DF\D0Ի\AFͨ\B5\C0\CA\F4\D0\D4 */
typedef struct hiUNF_PVR_LINEARIZATION_ATTR_S
{
    HI_CHAR                     szSrcFileName[PVR_MAX_FILENAME_LEN];     /**<File name to be linearized, static attribute        *//**<CNcomment: \B4\FD\D0޸\B4\B5\C4\CEļ\FE\C3\FB\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3        */
    HI_U32                      u32SrcFileNameLen;                       /**<Length of the file name, static attribute. You need to set the item to strlen (szSrcFileName).*//**<CNcomment: \CEļ\FE\C3\FB\B3\A4\B6ȣ\AC\BE\B2̬\CA\F4\D0ԡ\A3ȡֵΪstrlen\A3\A8szSrcFileName\A3\A9\BC\B4\BF\C9 */
    HI_CHAR                     szDstFileName[PVR_MAX_FILENAME_LEN];     /**<After the linearization of the file name, static attribute        *//**<CNcomment: \D0޸\B4\CD\EA\B3ɱ\A3\B4\E6\B5\C4\CEļ\FE\C3\FB\A3\AC\BE\B2̬\CA\F4\D0ԡ\A3        */
    HI_U32                      u32DstFileNameLen;                       /**<Length of the file name, static attribute. You need to set the item to strlen (szDstFileName).*//**<CNcomment: \CEļ\FE\C3\FB\B3\A4\B6ȣ\AC\BE\B2̬\CA\F4\D0ԡ\A3ȡֵΪstrlen\A3\A8szDstFileName\A3\A9\BC\B4\BF\C9 */
}HI_UNF_PVR_LINEARIZATION_ATTR_S;

/**status of Linearization channel*//** CNcomment:\CF\DF\D0Ի\AFͨ\B5\C0״̬ */
typedef struct hiUNF_PVR_LINEARIZATION_STATUS_S
{
    HI_U32  u32TotalFrameNum;               /**The total number of frames currently processed for the file..*//**<CNcomment: \B5\B1ǰ\B4\A6\C0\ED\CEļ\FE\B5\C4\D7\DC֡\CA\FD*/
    HI_U32  u32CurrentFixFrameNum;          /**The current number of frames processed..*//**<CNcomment: \B5\B1ǰ\D2Ѵ\A6\C0\ED\B5\C4֡\B8\F6\CA\FD*/
}HI_UNF_PVR_LINEARIZATION_STATUS_S;

/**<Callback function type when asynchronously processing truncate. CNcomment:\D2첽\B4\A6\C0\EDtruncateʱ\B5Ļص\F7\BA\AF\CA\FD\C0\E0\D0\CDCNend
\param[in] pszSrcFileName  Pointer to the original file name CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ԭ\CEļ\FE\C3\FBCNend
\param[in] u32SrcFileNameLen    The length of original file name CNcomment:ԭ\CEļ\FE\C3\FB\B5ĳ\A4\B6\C8CNend
\param[in] pszDstFileName    Pointer to the destination file name  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ŀ\B1\EA\CEļ\FE\C3\FBCNend
\param[in] u32DstFileNameLen   The length of destination file name  CNcomment:Ŀ\B1\EA\CEļ\FE\C3\FB\B5ĳ\A4\B6\C8CNend
\param[in] s32ErrCode The error code of truncate CNcomment:truncate\B9\FD\B3\CC\D6еĴ\ED\CE\F3\C2\EBCNend
\param[in] pArgs    User private data CNcomment:\D3û\A7˽\D3\D0\CA\FD\BE\DDCNend
\note: This callback function only needs to be processed asynchronously CNcomment:\B8ûص\F7\BA\AF\CA\FD\BD\F6\D4\DA\D2첽\B4\A6\C0\EDʱ\D0\E8ҪCNend
*/
typedef HI_S32 (*TruncateCallBack)(HI_CHAR *pszSrcFileName, HI_U32 u32SrcFileNameLen, HI_CHAR *pszDstFileName, HI_U32 u32DstFileNameLen, HI_S32 s32ErrCode, HI_VOID *pArgs);

/*Attributes of truncate*/
typedef struct hiUNF_PVR_RECFILE_TRUNCATE_INFO_S
{
    HI_BOOL             bSync;                  /**Whether need to be synchronized*//**<CNcomment: \CAǷ\F1\D0\E8Ҫͬ\B2\BD\B4\A6\C0\ED*/
    HI_U32              u32PaddingTimeMs;       /**Redundant data that guarantees data integrity*//**<CNcomment: \C8\DF\D3೤\B6ȣ\AC\B1\A3֤\CA\FD\BE\DD\CD\EA\D5\FB\D0\D4*/
    HI_BOOL             bTruncateHead;          /**Whether need to be deal with Head*//**<CNcomment: \CAǷ\F1\D0\E8Ҫ\B4\A6\C0\EDͷ\B2\BF*/
    HI_U32              u32StartTimeMs;         /**Expected starting position*//**<CNcomment: \C6\DA\CD\FB\B5\C4\C6\F0ʼλ\D6\C3*/ /*ʵ\BCʴ\A6\C0\ED\BA\F3\B5\C4\C6\F0ʼλ\D6\C3 <= u32StartTimeMs-u32PaddingTimeMs*/
    HI_BOOL             bTruncateTail;          /**Whether need to be deal with Tail*//**<CNcomment: \CAǷ\F1\D0\E8Ҫ\B4\A6\C0\EDβ\B2\BF*/
    HI_U32              u32EndTimeMs;           /**Expected end position*//**<CNcomment: *\C6\DA\CD\FB\B5\C4β\B2\BFλ\D6\C3*/ /*ʵ\BCʴ\A6\C0\ED\BA\F3\B5Ľ\E1\CA\F8λ\D6\C3 >= u32EndTimeMs+u32PaddingTimeMs*/
    TruncateCallBack    pfnAsyncCB;             /**The callback funcation of Asynchronously*//**<CNcomment: \D2첽\B4\A6\C0\EDʱ\B4\A6\C0\ED\CD\EA\B3ɵĻص\F7\BA\AF\CA\FD*/
    HI_VOID             *pArgs;                 /**The private data of callback*//**<CNcomment: \BBص\F7\BA\AF\CA\FD\B5\C4˽\D3\D0\CA\FD\BEݣ\AC\B5ײ㲻\D7\F7\C8κδ\A6\C0\ED\A3\ACֱ\BD\D3͸\B4\AB*/
}HI_UNF_PVR_RECFILE_TRUNCATE_INFO_S;

/**<Read or write data extra callback type. CNcomment:\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\C0\E0\D0\CDCNend
\param[in] pstDataAttr  Pointer to the attributes of current used data file CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\param[in] pu8DataAddr    Pointer to the virtual address CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\D0\E9\C4\E2\B5\D8ַCNend
\param[in] u32PhyAddr    Pointer to the physical address CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\CE\EF\C0\ED\B5\D8ַCNend
\param[in] u32Offset    offset CNcomment:ƫ\D2\C6\C1\BFCNend
\param[in] u32DataSize buffer size CNcomment:buffer \B5ĳ\A4\B6\C8CNend
*/
typedef HI_S32 ( *ExtraCallBack)(HI_UNF_PVR_DATA_ATTR_S *pstDataAttr, HI_U8 *pu8DataAddr, HI_U32 u32PhyAddr, HI_U32 u32Offset, HI_U32 u32DataSize);

/**<Read or write data extend callback type. CNcomment:\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\C0\E0\D0\CDCNend
\param[in] pstDataAttr  Pointer to the attributes of current used data file CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\param[in] pstDstBuf    Pointer to the attributes of destination buffer CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ŀ\B5\C4buffer \CA\F4\D0\D4CNend
\param[in] pstSrcBuf    Pointer to the attributes of source buffer CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Դbuffer \CA\F4\D0\D4CNend
\param[in] u32Offset    offset CNcomment:ƫ\D2\C6\C1\BFCNend
\param[in] u32DataSize buffer size CNcomment:buffer \B5ĳ\A4\B6\C8CNend
\param[in] pUserData    user data CNcomment:\D3û\A7˽\D3\D0\CA\FD\BE\DDCNend
\note: This callback has two different from the ExtraCallBack: 1) support different address for src/dst buffer; 2) support the use of user's private data. the address of src/dst buffer are different for tee record.
	   CNcomment:\D3\EBExtraCallBack\CF\E0\B1ȣ\BA1)\B8ûص\F7\BA\AF\CA\FD֧\B3\D6Դ\BA\CDĿ\B5\C4buffer\B2\BBͬ\B5\D8ַ\A3\BB2)֧\B3\D6\D3û\A7˽\D3\D0\CA\FD\BEݡ\A3TEE¼\D6\C6ʱ\A3\ACԴ\BA\CDĿ\B5\C4buffer\B5\D8ַ\B2\BBͬ\A1\A3CNend
*/
typedef HI_S32 (*ExtendCallBack)(HI_UNF_PVR_DATA_ATTR_S *pstDataAttr, HI_UNF_PVR_BUF_S *pstDstBuf, HI_UNF_PVR_BUF_S *pstSrcBuf,
                                    HI_U32 u32Offset, HI_U32 u32DataSize, HI_VOID *pUserData);

/**Defines the attributes when an recording channel is in Flushing Stream Status.*/
/**CNcomment:\B6\A8\D2\E5PVR¼\D6\C6ͨ\B5\C0Flush Streamʱ\CA\F4\D0\D4\C9\E8\D6ýṹ\CC\E5 */
typedef struct hiUNF_PVR_FLUSH_STREAM_OPT_S
{
    HI_U32          u32Reserved;
}HI_UNF_PVR_FLUSH_STREAM_OPT_S;


/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      PVR  */
/** @{ */  /** <!-- [PVR]*/

/***** Application programming interfaces (APIs) for the PVR recoding module*****/

/**
\brief Initializes the PVR recording module. CNcomment:\B3\F5ʼ\BB\AFPVR¼\D6\C6ģ\BF\E9 CNend
\attention \n
If you initialize the PVR recording module repeatedly, the error code HI_SUCCESS is returned.
Before using the APIs of the PVR recording module, you must call this API. Otherwise, other APIs are unavailable.
CNcomment: \D6ظ\B4\B3\F5ʼ\BB\AF\B7\B5\BBسɹ\A6.
ÿ\B8\F6\BD\F8\B3\CCʹ\D3\C3PVR¼\D6\C6ģ\BF\E9\BDӿ\DAǰ\A3\AC\B1\D8\D0\EB\CFȵ\F7\D3ô˽ӿڣ\AC\B7\F1\D4\F2\C6\E4\CB\FB\BDӿھ\F9\CE޷\A8ʹ\D3\C3 CNend
\param N/A CNcomment: \CE\DE CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called due to system errors. CNcomment: \B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
::HI_UNF_PVR_RecDeInit
*/
HI_S32 HI_UNF_PVR_RecInit(HI_VOID);

/**
\brief Deinitializes the PVR recording module. CNcomment: ȥ\B3\F5ʼ\BB\AFPVR¼\D6\C6ģ\BF\E9 CNend
\attention \n
If you deinitialize the PVR recording module repeatedly, the error code HI_SUCCESS is returned.\n
Before deintializing the PVR recording module, you must release all the recording channels. Otherwise,
the error code HI_ERR_PVR_BUSY is returned.
CNcomment:\D6ظ\B4ȥ\B3\F5ʼ\BB\AF\B7\B5\BBسɹ\A6\n
ȥ\B3\F5ʼ\BB\AFPVR¼\D6\C6ģ\BF\E9ǰ\CE\F1\B1ر\A3֤\B1\BE\BD\F8\B3\CC\C4\DA\CB\F9\D3\D0¼\D6\C6ͨ\B5\C0\B6\BC\D2Ѿ\AD\CAͷţ\AC\C8\E7\B9\FB\BB\B9\D3\D0¼\D6\C6ͨ\B5\C0û\D3\D0\CAͷţ\AC\B4˽ӿڽ\AB\BB᷵\BBش\ED\CE\F3\C2\EBHI_ERR_PVR_BUSY CNend
\param N/A CNcomment:\CE\DE CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE This API fails to be called due to system errors.CNcomment: \B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_PVR_BUSY  The PVR recording module is being used. CNcomment: ¼\D6\C6ģ\BF黹\D4\DAʹ\D3\C3\D6\D0 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized. CNcomment: ¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\see \n
::HI_UNF_PVR_RecInit
*/
HI_S32 HI_UNF_PVR_RecDeInit(HI_VOID);

/**
\brief Creates a recording channel. CNcomment: \B4\B4\BD\A81·¼\D6\C6ͨ\B5\C0 CNend
\attention \n
The PVR recording module automatically generates an .idx index file based on the file name specified in pAttr. \n
The PVR recording module splits the recorded streams files to ensure that the size of each file is not greater than 4 GB (the size of each file is about 3.99 GB). \n
The names of streams files are szFileName, szFileName.0001, szFileName.0002, szFileName.0003, szFileName.0004.\n
If the file specified in pAttr already exists, it is replaced.\n
If the index file to be created by the PVR recording module already exists, the file is also replaced.\n
If the PVR calls the APIs of other modules (such as the APIs of the audio module, video module, and DEMUX module), the error codes of other modules may be returned.\n
the error codes of other modules may be returned. For details, see the definitions of the error codes of corresponding modules.This description is applicable to the following APIs.
This description is applicable to the following APIs.
CNcomment:PVR¼\D6\C6ģ\BF\E9\BB\E1\B8\F9\BE\DDpAttr\D6\D0ָ\B6\A8\B5\C4\CEļ\FE\C3\FB\D7Զ\AF\C9\FA\B3\C9һ\B8\F6\BA\F3׺\C3\FBΪ".idx"\CB\F7\D2\FD\CEļ\FE\n
PVR¼\D6\C6ģ\BF\E9\BB\E1\B6\D4¼\D6Ƶ\C4\C2\EB\C1\F7\CEļ\FE\BD\F8\D0зָ\D2\D4ȷ\B1\A3\C2\EB\C1\F7\CEļ\FE\B2\BB\B3\AC\B9\FD4G\B5Ĵ\F3С\A3\A8ÿ\B8\F6\CEļ\FE\B5Ĵ\F3СԼΪ3.99G\A3\A9\A3\AC
\C9\FA\B3ɵ\C4\C2\EB\C1\F7\CEļ\FE\D2\C0\B4\CEΪszFileName\A3\ACszFileName.0001\A3\ACszFileName.0002\A3\ACszFileName.0003\A3\ACszFileName.0004\A1\A4\A1\A4\A1\A4\n
\C8\E7\B9\FBpAttr\D6\D0ָ\B6\A8\B5\C4\CEļ\FE\D2Ѿ\AD\B4\E6\D4ڣ\AC\C4\C7ô\D5\E2\B8\F6\CEļ\FE\BBᱻ\B8\B2\B8\C7\n
\C8\E7\B9\FBPVR¼\D6\C6ģ\BF齫Ҫ\B4\B4\BD\A8\B5\C4\CB\F7\D2\FD\CEļ\FE\D2Ѿ\AD\B4\E6\D4ڣ\AC\D4\F2\CB\F7\D2\FD\CEļ\FEҲ\BBᱻ\B8\B2\B8\C7\n
\D3\C9\D3\DAPVRʹ\D3õ\BD\C1\CB\C6\E4\CB\FBģ\BF\E9\B5\C4API\BDӿں\AF\CA\FD\A3\A8\B1\C8\C8\E7\D2\F4\CA\D3ƵAPI\BDӿں\CDDEMUX API\BDӿڣ\A9\A3\AC\D2\F2\B4˷\B5\BBصĴ\ED\CE\F3\C2\EB\D3п\C9\C4\DC\CA\C7\C6\E4\CB\FBģ\BF\E9\B5Ĵ\ED\CE\F3\C2룬
\BE\DF\CC\E5\B4\ED\CE\F3\C2\EBֵ\C7\EB\B2ο\BC\CF\E0Ӧģ\BF\E9\B4\ED\CE\F3\C2\EBֵ\B6\A8\D2塣\BA\F3\C3\E6\B5\C4\C6\E4\CB\FBAPI\BA\AF\CA\FD\BE\F9\BB\E1\D3д\CB\D6\D6\C7\E9\BF\F6  CNend
\param[in] pu32ChnID   ID of the obtained recording channel  CNcomment: \BB\F1ȡ\B5\BD\B5\C4¼\D6\C6ͨ\B5\C0ID CNend
\param[in] pstRecAttr  Pointer to the attributes of a channel   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized.  CNcomment:¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_NUL_PTR The pointer is null. CNcomment: ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_PVR_INVALID_PARA  The parameter is invalid.  CNcomment:  \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_FILE_INVALID_FNAME  The file name is invalid.  CNcomment:\CEļ\FE\C3\FB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_FILE_EXIST The file already exists.  CNcomment:\CEļ\FE\D2Ѿ\AD\B4\E6\D4\DA CNend
\retval ::HI_ERR_PVR_NO_CHN_LEFT  There is no available channel.   CNcomment:\D2Ѿ\ADû\D3п\D5\CFе\C4ͨ\B5\C0\B9\A9\B7\D6\C5\E4 CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN  The file cannot be opened.  CNcomment: \CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_INDEX_CANT_MKIDX  The index file cannot be opened.  CNcomment: \CE޷\A8\B4\F2\BF\AA\CB\F7\D2\FD\CEļ\FE CNend
\retval ::HI_ERR_PVR_REC_INVALID_DMXID The DEMUX ID received during recording is incorrect.  CNcomment: ¼\D6\C6ʱ\B4\AB\C8\EB\C1˴\ED\CE\F3\B5\C4DEMUX ID CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RecCreateChn(HI_U32 *pu32ChnID, const HI_UNF_PVR_REC_ATTR_S *pstRecAttr);

/**
\brief  Releases a specified recording channel. CNcomment: \CAͷ\C5ָ\B6\A8\B5\C4¼\D6\C6ͨ\B5\C0 CNend
\attention \n
CNcomment:If the channel to be released is not stopped, the error code HI_ERR_PVR_BUSY is returned.
\C8\E7\B9\FB\B4\FD\CAͷŵ\C4ͨ\B5\C0û\D3\D0ֹͣ\A3\AC\BD\AB\B7\B5\BBش\ED\CE\F3\C2\EB::HI_ERR_PVR_BUSY CNend
\param[in] u32ChnID   ID of the channel to be released CNcomment: \D0\E8Ҫ\CAͷŵ\C4ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_BUSY  The current operation is forbidden because the channel is busy. CNcomment: ͨ\B5\C0æ\A3\AC\B2\BB\D4\CA\D0\ED\BD\F8\D0е\B1ǰ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RecDestroyChn(HI_U32 u32ChnID);

/**
\brief Sets the attributes of a recording channel. CNcomment: \C9\E8\D6\C3¼\D6\C6ͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
You can modify only the dynamic attributes by calling this API.
CNcomment:ֻ\D3ж\AF̬\CA\F4\D0Բ\C5\C4\DC\D3ô˽ӿڸı\E4\C9\E8\D6ã\AC\D3\C9\D3\DAĿǰ\CA\F4\D0Զ\BC\CAǾ\B2̬\B5ģ\AC\CB\F9\D2Դ˽ӿ\DA\D4\DDʱ\B2\BB֧\B3ֹ\A6\C4\DC\C9\E8\D6\C3 CNend
\param[in] u32ChnID   Channel ID CNcomment: ͨ\B5\C0\BA\C5 CNend
\param[in] pstRecAttr  Attribute to be set  CNcomment:\B4\FD\C9\E8\D6õ\C4\CA\F4\D0\D4 CNend
\retval ::HI_SUCCESS Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized. CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  The function is not supported. CNcomment:\B9\A6\C4ܲ\BB֧\B3\D6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RecSetChn(HI_U32 u32ChnID, const HI_UNF_PVR_REC_ATTR_S *pstRecAttr);

/**
\brief Obtains the attributes of a recording channel. CNcomment: \BB\F1ȡ¼\D6\C6ͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
N/A
\param[in] u32ChnID   Channel ID CNcomment: ͨ\B5\C0\BA\C5 CNend
\param[out] pstRecAttr   Pointer to the obtained channel attributes   CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\BB\F1ȡ\B5\BD\B5\C4ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT    The PVR recording module is not initialized.  CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_NUL_PTR        The pointer is null.  CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The specified channel is not initialized.   CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RecGetChn(HI_U32 u32ChnID, HI_UNF_PVR_REC_ATTR_S *pstRecAttr);

/**
\brief Starts a recording channel. CNcomment:\C6\F4\B6\AF¼\D6\C6ͨ\B5\C0 CNend
\attention \n
N/A
\param[in] u32ChnID Channel ID   CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT   The PVR recording module is not initialized. CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID    The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   The specified channel is not initialized.  CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY       The specified channel has been started.  CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF CNend
\retval ::HI_FAILURE                 This API fails to be called due to system errors.  CNcomment:\B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
::HI_UNF_PVR_RecStopChn
*/
HI_S32 HI_UNF_PVR_RecStartChn(HI_U32 u32ChnID);

/**
\brief Stops a recording channel. CNcomment: ֹͣ¼\D6\C6ͨ\B5\C0 CNend
\attention \n
If a recording channel is working in time-shift playing mode, the channel cannot be stopped until the time-shift operation stops.
In this case, the error code HI_ERR_PVR_BUSY is returned if you call this API.
CNcomment:\C8\E7\B9\FB1\B8\F6¼\D6\C6ͨ\B5\C0\D5\FD\D4ڽ\F8\D0\D0ʱ\D2Ʋ\A5\B7Ų\D9\D7\F7\A3\AC\D4\F2\D4\DAֹͣʱ\D2Ʋ\A5\B7\C5֮ǰ\A3\AC\B2\BB\D4\CA\D0\EDֹͣ\B8\C3¼\D6\C6ͨ\B5\C0 \n
\C8\E7\B9\FB\B8\C3ͨ\B5\C0\D5\FD\D4ڽ\F8\D0\D0ʱ\D2Ʋ\A5\B7Ų\D9\D7\F7\A3\AC\BD\AB\B7\B5\BBش\ED\CE\F3\C2\EBHI_ERR_PVR_BUSY CNend
\param[in] u32ChnID   Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT    The PVR recording module is not initialized.  CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID     The channel ID is invalid.    CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT     The specified channel is not initialized. CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY         The specified channel has been stopped.    CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\ADֹͣ CNend
\retval ::HI_ERR_PVR_BUSY            The current operation is forbidden because the channel is busy. CNcomment:ͨ\B5\C0æ\A3\AC\B2\BB\D4\CA\D0\ED\BD\F8\D0е\B1ǰ\B2\D9\D7\F7 CNend
\see \n
::HI_UNF_PVR_RecStartChn
*/
HI_S32 HI_UNF_PVR_RecStopChn(HI_U32 u32ChnID);

/**
\brief Pauses a recording channel. CNcomment: \D4\DDͣ¼\D6\C6ͨ\B5\C0 CNend
\attention \n
It should be called under recording mode and can be repeated call.
CNcomment:ֻ\D3\D0¼\D6\C6״̬\B5\F7\D3øýӿڲ\C5\D3\D0\D7\F7\D3ã\AC\D4\CA\D0\ED\D6ظ\B4\B5\F7\D3\C3 CNend
\param[in] u32ChnID   Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_REC_INVALID_STATE  PVR isn't playing or pausing. CNcomment: PVR\B7ǲ\A5\B7Ż\F2\D5\DF\D4\DDͣ״̬ CNend
\see \n
::HI_UNF_PVR_RecResumeChn
*/
HI_S32 HI_UNF_PVR_RecPauseChn(HI_U32 u32ChnID);

/**
\brief Resumes a recording channel. CNcomment: \BBָ\B4¼\D6\C6ͨ\B5\C0 CNend
\attention \n
It should be called under recording mode and can be repeated call.
CNcomment:ֻ\D3\D0¼\D6\C6״̬\B5\F7\D3øýӿڲ\C5\D3\D0\D7\F7\D3ã\AC\D4\CA\D0\ED\D6ظ\B4\B5\F7\D3\C3 CNend
\param[in] u32ChnID   Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_REC_INVALID_STATE  PVR isn't playing or paused.CNcomment: PVR\B7ǲ\A5\B7Ż\F2\D5\DF\D4\DDͣ״̬ CNend
\see \n
::HI_UNF_PVR_RecPauseChn
*/
HI_S32 HI_UNF_PVR_RecResumeChn(HI_U32 u32ChnID);

/**
\brief Obtains the status of a recording channel.CNcomment:  \BB\F1ȡ¼\D6\C6ͨ\B5\C0״̬ CNend
\attention \n
N/A
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[out] pstRecStatus   Pointer to the recording status   CNcomment:¼\D6\C6״̬\D0\C5Ϣָ\D5\EB CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT    The PVR recording module is not initialized.  CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID   The channel ID is invalid.   CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT    The specified channel is not initialized.  CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_NUL_PTR        The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RecGetStatus(HI_U32 u32ChnID, HI_UNF_PVR_REC_STATUS_S *pstRecStatus);


/***** APIs for the PVR playing module *****/
/**
\brief Initializes the PVR playing module. CNcomment: \B3\F5ʼ\BB\AFPVR\B2\A5\B7\C5ģ\BF\E9 CNend
\attention \n
If you initialize the PVR playing module repeatedly, the error code HI_SUCCESS is returned.\n
Before using the APIs of the PVR playing module, you must call this API. Otherwise, other APIs are unavailable.
CNcomment:\D6ظ\B4\B3\F5ʼ\BB\AF\B7\B5\BBسɹ\A6 \n
ÿ\B8\F6\BD\F8\B3\CCʹ\D3\C3PVR\B2\A5\B7\C5ģ\BF\E9\BDӿ\DAǰ\A3\AC\B1\D8\D0\EB\CFȵ\F7\D3ô˽ӿڣ\AC\B7\F1\D4\F2\C6\E4\CB\FB\BDӿھ\F9\CE޷\A8ʹ\D3\C3 CNend
\param N/A
\retval ::HI_SUCCESS         Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE           This API fails to be called due to system errors.    CNcomment:\B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
::HI_UNF_PVR_PlayDeInit
*/
HI_S32 HI_UNF_PVR_PlayInit(HI_VOID);

/**
\brief Deinitializes the PVR playing module.  CNcomment:ȥ\B3\F5ʼ\BB\AFPVR\B2\A5\B7\C5ģ\BF\E9 CNend
\attention \n
If you deinitialize the PVR recording module repeatedly, the error code HI_SUCCESS is returned.\n
Before deintializing the PVR playing module, you must release all the playing channels. Otherwise, the error code HI_ERR_PVR_BUSY is returned.
CNcomment:\D6ظ\B4ȥ\B3\F5ʼ\BB\AF\B7\B5\BBسɹ\A6 \n
ȥ\B3\F5ʼ\BB\AFPVR\B2\A5\B7\C5ģ\BF\E9ǰ\CE\F1\B1ر\A3֤\B1\BE\BD\F8\B3\CC\C4\DA\CB\F9\D3в\A5\B7\C5ͨ\B5\C0\B6\BC\D2Ѿ\AD\CAͷţ\AC\C8\E7\B9\FB\BB\B9\D3в\A5\B7\C5ͨ\B5\C0û\D3\D0\CAͷţ\AC\B4˽ӿڽ\AB\BB᷵\BBش\ED\CE\F3\C2\EB::HI_ERR_PVR_BUSY CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_FAILURE          This API fails to be called due to system errors.   CNcomment: \B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\retval ::HI_ERR_PVR_BUSY  The PVR playing module is being used.  CNcomment: PVR\B2\A5\B7\C5ģ\BF黹\D4\DAʹ\D3\C3\D6\D0 CNend
\retval ::HI_ERR_PVR_NOT_INIT   The PVR recording module is not initialized.CNcomment:  PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\see \n
::HI_UNF_PVR_PlayInit
*/
HI_S32 HI_UNF_PVR_PlayDeInit(HI_VOID);

/**
\brief Creates a playing channel. CNcomment:\B4\B4\BD\A81·\B2\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
The PVR playing module automatically searches for an .idx index file based on the file name specified in pAttr.
If the index file does not exist, the PVR playing module attempts to play the stream file, but cannot support some features,
such as fast forward, fast backward, or seek. The features vary according to versions of the software developer's kit (SDK).
Only the playing function is supported in the current version.
The played file may be the file that is being recorded (that is, time-shift playing).
The audio/video player (AVPLAY) indicated by hAVPLAY must be stopped.
CNcomment:PVR\B2\A5\B7\C5ģ\BF\E9\BB\E1\B8\F9\BE\DDpAttr\D6\D0ָ\B6\A8\B5\C4\CEļ\FE\C3\FB\D7Զ\AFѰ\D5Һ\F3׺\C3\FBΪ".idx"\B5\C4\CB\F7\D2\FD\CEļ\FE \n
\C8\E7\B9\FB\CB\F7\D2\FD\CEļ\FE\B2\BB\B4\E6\D4ڣ\ACPVR\B2\A5\B7\C5ģ\BF\E9Ҳ\BB᳢\CAԲ\A5\B7\C5\D5\E2\B8\F6\CEļ\FE\A3\AC\B5\AB\CAǿ\C9\C4\DC\CE޷\A8֧\B3\D6ĳЩ\CC\D8\D0ԣ\AC
\B1\C8\C8\E7\BF\EC\BD\F8\BF\EC\CD˻\F2\D5\DFSEEK\B2\D9\D7\F7\A3\A8\B8\F9\BEݰ汾\B5Ĳ\BBͬ\B6\F8\D3\D0\CB\F9\B2\EE\B1𣬵\B1ǰ\B0汾ֻ֧\B3ֲ\A5\B7ţ\A9\n
\B2\A5\B7ŵ\C4\CEļ\FE\BF\C9\D2\D4\CA\C7\D5\FD\D4\DA¼\D6Ƶ\C4\CEļ\FE\A3\A8\BC\B4\BD\F8\D0\D0ʱ\D2Ʋ\A5\B7ţ\A9
hAVPlay\CB\F9\B4\FA\B1\ED\B5\C4avplay\B1\D8\D0봦\D3\DAstop״̬\A1\A3 CNend
\param[out] pu32ChnID  ID of the obtained playing channel  CNcomment: \BB\F1ȡ\B5\BD\B5Ĳ\A5\B7\C5ͨ\B5\C0ID CNend
\param[in] pstPlayAttr  Pointer to the channel attributes CNcomment: ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3ָ\D5\EB CNend
\param[in] hAvplay      AVPLAY handle. It specifies the APVPLAY to be used. CNcomment: avplay\BE\E4\B1\FA\A3\AC\B1\EAʶ\D3\C3\C4ĸ\F6avplay\C0\B4\B2\A5\B7\C5 CNend
\param[in] hTsBuffer  TS buffer handle. It specifies that TS buffer that is used for playback. In general, the TS port corresponding to the TS buffer must be attached to the DEMUX corresponding to the AVPLAY.
tCNcomment:s buffer\BE\E4\B1\FA\A3\AC\B1\EAʶ\D3\C3\C4ĸ\F6ts buffer\C0\B4\BBطţ\ACһ\B0\E3\C0\B4˵\A3\AC\B4\CBts buffer\B6\D4Ӧ\B5\C4ts\B6˿\DAӦ\B8\C3\CAǰ\F3\B6\A8\D4\DAhAVPlay\B6\D4Ӧ\B5\C4demux\C9ϵ\C4 CNend
\retval ::HI_SUCCESS   Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT       The PVR recording module is not initialized.  CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_NUL_PTR            The pointer is null. CNcomment:  ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_DMX_INVALID_PARA        The parameter is invalid.  CNcomment: \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_FILE_INVALID_FNAME   The file name is invalid.   CNcomment:\CEļ\FE\C3\FB\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_FILE_EXIST          The file already exists.  CNcomment:\CEļ\FE\D2Ѿ\AD\B4\E6\D4\DA CNend
\retval ::HI_ERR_PVR_NO_CHN_LEFT        There is no available channel. CNcomment:  \D2Ѿ\ADû\D3п\D5\CFе\C4ͨ\B5\C0\B9\A9\B7\D6\C5\E4 CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN      The file cannot be opened.   CNcomment:  \CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_FILE_NOT_EXIST      The file cannot be played because it does not exist. CNcomment: \CEļ\FE\B2\BB\B4\E6\D4ڣ\AC\CE޷\A8\B2\A5\B7\C5 CNend
\retval ::HI_ERR_PVR_NO_MEM             The buffer required for playing cannot be allocated due to insufficient memory. CNcomment: \C4ڴ治\D7㣬\CE޷\A8\B7\D6\C5䲥\B7\C5\D0\E8Ҫ\B5\C4Buffer CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ   The file cannot be read.  CNcomment:   \CEļ\FE\B6\C1ȡ\B3\F6\B4\ED CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayCreateChn(HI_U32 *pu32ChnID, const HI_UNF_PVR_PLAY_ATTR_S *pstPlayAttr, HI_HANDLE hAvplay, HI_HANDLE hTsBuffer);

/**
\brief Releases a specified playing channel. CNcomment:\CAͷ\C5ָ\B6\A8\B5Ĳ\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
If the channel to be released is not stopped, the error code HI_ERR_PVR_BUSY is returned.
CNcomment:\C8\E7\B9\FB\B4\FD\CAͷŵ\C4ͨ\B5\C0û\D3\D0ֹͣ\A3\AC\BD\AB\B7\B5\BBش\ED\CE\F3\C2\EB::HI_ERR_PVR_BUSY CNend
\param[in] u32ChnID  ID of the channel to be released CNcomment:\D0\E8Ҫ\CAͷŵ\C4ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT     The PVR recording module is not initialized.   CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID       The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_BUSY  The current operation is forbidden because the channel is busy.  CNcomment: ͨ\B5\C0æ\A3\AC\B2\BB\D4\CA\D0\ED\BD\F8\D0е\B1ǰ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayDestroyChn(HI_U32 u32ChnID);

/**
\brief
Starts a time-shift playing channel.
You can call this API to start a time-shift playing channel based on the entered IDs of recording channels. To be specific, this API automatically initializes a playing channel to play files based on the parameter configuration of the corresponding recording channel.
CNcomment:\C6\F4\B6\AFʱ\D2Ʋ\A5\B7\C5ͨ\B5\C0\A1\A3\B5\F7\D3ô˽ӿڿ\C9\D2Ը\F9\BE\DD\CA\E4\C8\EB\B5\C4¼\D6\C6ͨ\B5\C0\BAţ\AC\C6\F4\B6\AF1·ʱ\D2Ʋ\A5\B7š\A3\B4˽ӿڽ\AB\B8\F9\BEݶ\D4Ӧ¼\D6\C6ͨ\B5\C0\B5Ĳ\CE\CA\FD\D7Զ\AF\B3\F5ʼ\BB\AF1\B8\F6\B2\A5\B7\C5ͨ\B5\C0\A3\AC\B2\A2\BF\AAʼ\B2\A5\B7\C5 CNend
\attention \n
This API is not recommended. It is used to be compatible with other interfaces. You are recommended to call HI_UNF_PVR_PlayCreateChn and HI_UNF_PVR_PlayStartChn in sequence to start to play. If you want to enable the time-shift playing mode,
you only need to set same names for the file to be played and recorded file. Then the PVR automatically identifies the same names, and enters the time-shift playing mode.
After HI_UNF_PVR_PlayStartTimeShift is called, HI_UNF_PVR_PlayCreateChn is automatically called to allocate a playing channel. Therefore, you do not need to call HI_UNF_PVR_PlayNewChn.\n
In addition, before calling HI_UNF_PVR_PlayStartTimeShift, you must start the corresponding recording channel. Otherwise, the error code HI_ERR_PVR_REC_INVAL_STATE is returned.\n
After you start a time-shift playing channel by calling this API, the corresponding recording channel cannot be stopped or destroyed until time-shift playing stops.
CNcomment:\B2\BB\CDƼ\F6ʹ\D3ô˽ӿڣ\AC\B1\A3\C1\F4\B4˽ӿ\DAֻ\CA\C7Ϊ\C1˱\A3\B3\D6\D3\EB\C0Ͻӿڵļ\E6\C8ݣ\AC\CDƼ\F6ʹ\D3\C3HI_UNF_PVR_PlayCreateChn\BA\F3\D4ٵ\F7\D3\C3HI_UNF_PVR_PlayStartChn\C6\F4\B6\AF\B2\A5\B7ţ\AC\C8\E7\B9\FBҪ\BD\F8\D0\D0ʱ\D2ƣ\AC
+\D0\E8Ҫ\C9\E8\D6ò\A5\B7ŵ\C4\CEļ\FE\C3\FB\D3\EB¼\D6Ƶ\C4\CEļ\FE\C3\FBһ\D1\F9\BC\B4\BFɣ\ACPVR\BB\E1\D7Զ\AFʶ\B1\F0\CF\E0ͬ\B5\C4\CEļ\FE\C3\FB\B2\A2\BD\F8\C8\EBʱ\D2\C6״̬\A1\A3
\B5\F7\D3ô˽ӿڿ\C9\D2\D4ֱ\BD\D3\C6\F4\B6\AF1·ʱ\D2Ʋ\A5\B7ţ\AC\BDӿ\DA\C4ڲ\BF\BB\E1\D7Զ\AF\B5\F7\D3\C3HI_UNF_PVR_PlayCreateChn\B7\D6\C5䲥\B7\C5ͨ\B5\C0\A3\AC\D3û\A7\B2\BB\D0\E8Ҫ\D4\D9\CFȵ\F7\D3\C3HI_UNF_PVR_PlayCreateChn\B4\B4\BD\A8\B2\A5\B7\C5ͨ\B5\C0 \n
\B5\F7\D3ô˽ӿ\DAǰ\C7\EBȷ\B1\A3\B6\D4Ӧ\B5\C4¼\D6\C6ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF\A3\AC\B7\F1\D4򽫻᷵\BBش\ED\CE\F3\C2\EBHI_ERR_PVR_REC_INVAL_STATE \n
\B5\F7\D3ô˽ӿ\DA\C6\F4\B6\AF1·ʱ\D2ƺ󣬶\D4Ӧ\B5\C4¼\D6\C6ͨ\B5\C0\BD\AB\B2\BB\C4ܱ\BBֹͣ\BB\F2\D5\DF\CF\FA\BB\D9ֱ\B5\BDʱ\D2Ʋ\A5\B7\C5ֹͣ CNend
\param[out] pu32PlayChnID   ID of a playing channel CNcomment:\B2\A5\B7\C5ͨ\B5\C0\BA\C5 CNend
\param[in] u32RecChnID    ID of the recording channel to be time-shifted CNcomment: \D0\E8Ҫʱ\D2Ƶ\C4¼\D6\C6ͨ\B5\C0\BA\C5 CNend
\param[in] hAvplay     AVPLAY handle. It specifies the APVPLAY to be used.   CNcomment:avplay\BE\E4\B1\FA\A3\AC\B1\EAʶ\D3\C3\C4ĸ\F6avplay\C0\B4\B2\A5\B7\C5 CNend
\param[in] hTsBuffer    TS buffer handle. It specifies that TS buffer that is used for playback. In general, the TS port corresponding to the TS buffer must be attached to the DEMUX corresponding to the AVPLAY.
CNcomment:ts buffer\BE\E4\B1\FA\A3\AC\B1\EAʶ\D3\C3\C4ĸ\F6ts buffer\C0\B4\BBطţ\ACһ\B0\E3\C0\B4˵\A3\AC\B4\CBts buffer\B6\D4Ӧ\B5\C4ts\B6˿\DAӦ\B8\C3\CAǰ\F3\B6\A8\D4\DAhAVPlay\B6\D4Ӧ\B5\C4demux\C9ϵ\C4 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NUL_PTR The pointer is null.  CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_DMXID The DEMUX ID received during playing is incorrect. CNcomment:\B2\A5\B7\C5ʱ\B4\AB\C8\EB\C1˴\ED\CE\F3\B5\C4DEMUX ID CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT The specified channel is not initialized. CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY  The specified channel has been started. CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF CNend
\retval ::HI_ERR_PVR_NO_CHN_LEFT  There is no available playing channel.CNcomment: \D2Ѿ\ADû\D3п\D5\CFеĲ\A5\B7\C5ͨ\B5\C0\B9\A9\B7\D6\C5\E4 CNend
\retval ::HI_ERR_PVR_REC_INVALID_STATE  The recording channel is not started.CNcomment:  ¼\D6\C6ͨ\B5\C0û\D3\D0\C6\F4\B6\AF CNend
\retval ::HI_ERR_PVR_NO_MEM   The buffer required for playing cannot be allocated due to insufficient memory.CNcomment: \C4ڴ治\D7㣬\CE޷\A8\B7\D6\C5䲥\B7\C5\D0\E8Ҫ\B5\C4Buffer CNend
\retval ::HI_FAILURE This API fails to be called due to system errors. CNcomment:\B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
::HI_UNF_PVR_PlayStopTimeShift
*/
HI_S32 HI_UNF_PVR_PlayStartTimeShift(HI_U32 *pu32PlayChnID, HI_U32 u32RecChnID, HI_HANDLE hAvplay, HI_HANDLE hTsBuffer);

/**
\brief Stops a playing channel.  CNcomment:ֹͣ\B2\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
This API must work with ::HI_UNF_PVR_PlayStartTimeShift, and this API can be only used to stop the playing channel that is started by calling ::HI_UNF_PVR_PlayStartTimeShift.
You must call ::HI_UNF_PVR_PlayStopTimeShift rather than ::HI_UNF_PVR_PlayStopChn to stop the playing channel that is started by calling ::HI_UNF_PVR_PlayStartTimeShift.

CNcomment:\B4˽ӿ\DA\D3\EB::HI_UNF_PVR_PlayStartTimeShift\BDӿڱ\D8\D0\EB\C5\E4\B6\D4ʹ\D3ã\AC\B4˽ӿ\DAֻ\C4\DCֹͣʹ\D3\C3::HI_UNF_PVR_PlayStartTimeShift\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0 \n
+\B9\FD::HI_UNF_PVR_PlayStartTimeShift\BDӿ\DA\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0\B1\D8\D0\EBʹ\D3ô˽ӿ\DA\C0\B4ֹͣ\A3\AC\B6\F8\B2\BB\D4\CA\D0\ED\D3\C3::HI_UNF_PVR_PlayStopChn\BDӿ\DA\C0\B4ֹͣ CNend
\param[in] u32PlayChnID Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstStopOpt  Pointer to the attribute structure when the AVPLAY stops CNcomment:ֹͣ\B5\C4\CA\F4\D0\D4\C9\E8\D6\C3 CNend
\retval ::HI_SUCCESS  SuccessCNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT        The PVR recording module is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID        The channel ID is invalid. CNcomment:  ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT       The specified channel is not initialized.   CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY            The specified channel has been started.  CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE    The channel status is incorrect. For example, you call this API to stop the playing channel that is started by calling HI_UNF_PVR_PlayStartChn.
CNcomment:ͨ\B5\C0״̬\B4\ED\CE\F3\A1\A3\C0\FD\C8磺\B6\D4\D3\C3::HI_UNF_PVR_PlayStartChn\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0\B5\F7\D3ô˽ӿ\DA CNend
\see \n
::HI_UNF_PVR_PlayStartTimeShift
*/
HI_S32 HI_UNF_PVR_PlayStopTimeShift(HI_U32 u32PlayChnID, const HI_UNF_AVPLAY_STOP_OPT_S *pstStopOpt);

/**
\brief Sets the attributes of a playing channel. CNcomment:\C9\E8\D6ò\A5\B7\C5ͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
You can set the dynamic attributes only by calling this API.
CNcomment:ֻ\D3ж\AF̬\CA\F4\D0Բ\C5\C4\DCͨ\B9\FD\B4˽ӿڽ\F8\D0\D0\C9\E8\D6ã\AC\D3\C9\D3\DAĿǰ\B6\BC\CAǶ\AF̬\CA\F4\D0ԣ\AC\CB\F9\D2Դ˽ӿ\DA\D4\DDʱ\B2\BB\CCṩ\C9\E8\D6ù\A6\C4ܡ\A3 CNend
\param[in] u32ChnID    Channel ID CNcomment: ͨ\B5\C0\BA\C5 CNend
\param[in] pstPlayAttr  Pointer to the channel attributes to be set  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2Ҫ\C9\E8\D6õ\C4ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized. CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  The function is not supported. CNcomment:\B9\A6\C4ܲ\BB֧\B3\D6 CNend
\see \n
::HI_UNF_PVR_PlayGetChn
*/
HI_S32 HI_UNF_PVR_PlaySetChn(HI_U32 u32ChnID, const HI_UNF_PVR_PLAY_ATTR_S *pstPlayAttr);

/**
\brief  Obtains the attributes of a playing channel. CNcomment:\BB\F1ȡ\B2\A5\B7\C5ͨ\B5\C0\CA\F4\D0\D4 CNend
\attention \n
N/A
\param[in] u32ChnID   Channel ID CNcomment:CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[out] pstPlayAttr   Pointer to the obtained channel attributes CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2\BB\F1ȡ\B5\BD\B5\C4ͨ\B5\C0\CA\F4\D0\D4\C5\E4\D6\C3 CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT   The PVR recording module is not initialized.CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID   The channel ID is invalid. CNcomment:  ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   The specified channel is not initialized. CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_NUL_PTR      The pointer is null.  CNcomment:  ָ\D5\EB\B2\CE\CA\FDΪ\BF\D5 CNend
\see \n
::HI_UNF_PVR_PlaySetChn
*/
HI_S32 HI_UNF_PVR_PlayGetChn(HI_U32 u32ChnID, HI_UNF_PVR_PLAY_ATTR_S *pstPlayAttr);

/**
\brief  Starts a playing channel. CNcomment:\C6\F4\B6\AF\B2\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
You can call this API to start the channel that is created by calling ::HI_UNF_PVR_PlayCreateChn only once. To pause or resume playing,
you need to call ::HI_UNF_PVR_PlayPauseChn and ::HI_UNF_PVR_PlayResumeChn respectively.
CNcomment:\B5\F7\D3\C3::HI_UNF_PVR_PlayCreateChn\C9\EA\C7\EB\B5\C4ͨ\B5\C0ֻ\C4\DCͨ\B9\FD\B4˽ӿ\DA\C6\F4\B6\AFһ\B4Σ\AC\C8\E7\B9\FB\CF\EBҪ\D4\DDͣ/\BBָ\B4\B2\A5\B7ţ\AC
\D0\E8ʹ\D3\C3::HI_UNF_PVR_PlayPauseChn\BA\CD::HI_UNF_PVR_PlayResumeChn\BDӿ\DA CNend
\param[in] u32ChnID Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT     The PVR recording module is not initialized.  CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID     The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT    The specified channel is not initialized. CNcomment:  ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY        The specified channel has been started.   CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF CNend
\retval ::HI_FAILURE                 This API fails to be called due to system errors. CNcomment: \B3\F6\CF\D6ϵͳ\B4\ED\CE\F3\A3\ACAPI\B5\F7\D3\C3ʧ\B0\DC CNend
\see \n
::HI_UNF_PVR_PlayStopChn
*/
HI_S32 HI_UNF_PVR_PlayStartChn(HI_U32 u32ChnID);

/**
\brief  Stops a playing channel. CNcomment:ֹͣ\B2\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
This API must work with ::HI_UNF_PVR_PlayStartChn, and this API can be only used to stop the playing channel that is started by calling HI_UNF_PVR_PlayStartChn.
You must call ::HI_UNF_PVR_PlayStopChn rather than HI_UNF_PVR_PlayStopTimeShift to stop the playing channel that is started by calling HI_UNF_PVR_PlayStartChn.
CNcomment:\B4˽ӿ\DA\D3\EB::HI_UNF_PVR_PlayStartChn\BDӿڱ\D8\D0\EB\C5\E4\B6\D4ʹ\D3ã\AC\B4˽ӿ\DAֻ\C4\DCֹͣʹ\D3\C3::HI_UNF_PVR_PlayStartChn\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0 \n
+\B9\FD::HI_UNF_PVR_PlayStartChn\BDӿ\DA\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0\B1\D8\D0\EBʹ\D3ô˽ӿ\DA\C0\B4ֹͣ\A3\AC\B6\F8\B2\BB\D4\CA\D0\ED\D3\C3::HI_UNF_PVR_PlayStopTimeShift\BDӿ\DA\C0\B4ֹͣ CNend
\param[in] u32ChnID  Channel ID CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstStopOpt  Pointer to the attribute structure when the AVPLAY stops  CNcomment:ֹͣ\B5\C4\CA\F4\D0\D4\C9\E8\D6\C3 CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT    The PVR recording module is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID     The channel ID is invalid.  CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT    The specified channel is not initialized.  CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_ALREADY        The specified channel has been started.  CNcomment:  ָ\B6\A8\B5\C4ͨ\B5\C0\D2Ѿ\AD\C6\F4\B6\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE The channel status is incorrect. For example, you call this API to stop the playing channel that is started by calling HI_UNF_PVR_PlayStartTimeShift.
CNcomment:ͨ\B5\C0״̬\B4\ED\CE\F3\A1\A3\C0\FD\C8磺\B6\D4\D3\C3::HI_UNF_PVR_PlayStartTimeShift\C6\F4\B6\AF\B5Ĳ\A5\B7\C5ͨ\B5\C0\B5\F7\D3ô˽ӿ\DA CNend
\see \n
::HI_UNF_PVR_PlayStartChn
*/
HI_S32 HI_UNF_PVR_PlayStopChn(HI_U32 u32ChnID, const HI_UNF_AVPLAY_STOP_OPT_S *pstStopOpt);

/**
\brief  Pauses a playing channel. CNcomment:\D4\DDͣ\B2\A5\B7\C5ͨ\B5\C0 CNend
\attention \n
If you call this API when the channel is paused, the error code HI_SUCCESS is returned.\n
If you call this API is called when the channel is stopped, the error code HI_ERR_PVR_PLAY_INVALID_STATE is returned.
CNcomment:\D4\DAͨ\B5\C0\D2Ѿ\AD\D4\DDͣ\B5\C4\C7\E9\BF\F6\CF\C2\D4ٴε\F7\D3\C3::HI_UNF_PVR_PlayPauseChn\D4\DDͣͨ\B5\C0\BD\AB\B7\B5\BBسɹ\A6 \n
\D4\DAͨ\B5\C0\D2Ѿ\AD\B1\BBֹͣ\B5\C4\C7\E9\BF\F6\CFµ\F7\D3ô˽ӿ\DA\D4\DDͣͨ\B5\C0\BD\AB\B7\B5\BBش\ED\CE\F3\C2\EB::HI_ERR_PVR_PLAY_INVALID_STATE CNend
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS  Success CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT      The PVR recording module is not initialized. CNcomment:  PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID     The channel ID is invalid.  CNcomment:  ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT       The specified channel is not initialized.  CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE   The channel status is incorrect, that is , the channel has been stopped. CNcomment: ͨ\B5\C0״̬\B4\ED\CE\F3\A3\BAͨ\B5\C0\D2Ѿ\ADֹͣ\D4\CB\D0\D0 CNend
\see \n
::HI_UNF_PVR_PlayResumeChn
*/
HI_S32 HI_UNF_PVR_PlayPauseChn(HI_U32 u32ChnID);

/**
\brief Resumes a playing channel. You can resume a playing channel or enable a playing channel to exit the pause mode by calling this API.
CNcomment:\BBָ\B4\B2\A5\B7\C5ͨ\B5\C0\A1\A3\B5\F7\D3ô˽ӿڿ\C9\D2Իָ\B4\B2\A5\B7\C5ͨ\B5\C0\A3\AC\BD\E2\B3\FD\B2\A5\B7\C5ͨ\B5\C0\B5\C4\D4\DDͣ״̬ CNend
\attention \n
This API must work with HI_UNF_PVR_PlayPauseChn. In addition, a channel can be resumed only when it is paused.
CNcomment:\B4˽ӿ\DA\D3\EB::HI_UNF_PVR_PlayPauseChn\BDӿڱ\D8\D0\EB\C5\E4\B6\D4ʹ\D3ã\ACֻ\D3\D0\D4\DAͨ\B5\C0\D2Ѿ\AD\D4\DDͣ\B5\C4\C7\E9\BF\F6\CF²\C5\D4\CA\D0\ED\BBָ\B4ͨ\B5\C0 CNend
\param[in] u32ChnID Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT       The PVR recording module is not initialized.  CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID      The channel ID is invalid.   CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT     The specified channel is not initialized.   CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE The specified channel is not paused.   CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0\B2\BB\D4\DA\D4\DDͣ״̬ CNend
\see \n
::HI_UNF_PVR_PlayPauseChn
*/
HI_S32 HI_UNF_PVR_PlayResumeChn(HI_U32 u32ChnID);

/**
\brief Starts the trick playing mode. You can call this API to start the trick playing mode. In this mode, the operations include fast forward, fast backward, slow playing, and normal playing.
CNcomment:\BD\F8\D0\D0\CCؼ\BC\B2\A5\B7š\A3\B5\F7\D3ô˽ӿڿ\C9\D2Խ\F8\D0\D0\CCؼ\BC\B2\A5\B7ţ\AC\BC\B4\BD\F8\D0п\EC\BD\F8\A1\A2\BF\EC\CDˡ\A2\C2\FD\B7š\A2\D5\FD\B3\A3\B2\A5\B7ŵȲ\D9\D7\F7 CNend
\attention \n
If you want to switch the trick playing mode to the normal playing mode, you only need to the playing speed in trick playing mode to PVR_PLAY_SPEED_NORMAL.
CNcomment:\BD\F8\C8\EB\CCؼ\BC\B2\A5\B7\C5ģʽ\BA\F3\A3\AC\C8\E7\B9\FB\CF\EB\CD˻\D8\D5\FD\B3\A3\B2\A5\B7\C5ģʽ\A3\ACֻ\D0\E8Ҫ\C9\E8\D6\C3\CCؼ\BC\B2\A5\B7\C5ģʽ\B5\C4\CBٶ\C8ΪPVR_PLAY_SPEED_NORMAL CNend
\param[in] u32ChnID      Channel ID CNcomment: ͨ\B5\C0\BA\C5 CNend
\param[in] pstTrickMode   Pointer to the information about the trick playing mode  CNcomment:\CCؼ\BC\B2\A5\B7\C5ģʽ\D0\C5Ϣָ\D5\EB CNend
\retval ::HI_SUCCESS   Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT        The PVR recording module is not initialized.   CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID     The channel ID is invalid.      CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT       The specified channel is not initialized.   CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE   The channel status is incorrect, that is , the channel has been stopped.  CNcomment:ͨ\B5\C0״̬\B4\ED\CE\F3\A3\BAͨ\B5\C0\D2Ѿ\ADֹͣ\D4\CB\D0\D0 CNend
\retval ::HI_ERR_DMX_INVALID_PARA      The parameter is invalid.     CNcomment:\B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT    The trick playing mode is not supported.  CNcomment:\B2\BB֧\B3ֵ\C4\CCؼ\BC\B2\A5\B7\C5ģʽ CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayTPlay(HI_U32 u32ChnID, const HI_UNF_PVR_PLAY_MODE_S *pstTrickMode);

/**
\brief Seeks a specified position to play, seeks by size and frame is not supported currently. CNcomment:\B6\A8λ\B5\BDָ\B6\A8λ\D6ý\F8\D0в\A5\B7\C5,\D4ݲ\BB֧\B3ְ\B4\D5մ\F3С\BA\CD֡\CA\FD\BD\F8\D0ж\A8λ CNend
\attention \n
If you call this API when the channel is disabled, the error code :HI_ERR_PVR_PLAY_INVALID_STATE is returned.\n
If the sought position is out of the boundary, the position is adjusted to the boundary automatically.\n
If you seek the position backward or from the start of a file, the next I frame in the corresponding position is sought. Otherwise, the previous I frame is sought.\n
If you seek the position forward or from the end of a file, the previous I frame in the corresponding position is sought. Otherwise, the next I frame is sought.\n
If no I frame is found, an error code is returned.
CNcomment:\D4\DAͨ\B5\C0\D2Ѿ\ADֹͣ\B5\C4\C7\E9\BF\F6\CFµ\F7\D3ñ\BE\BDӿڽ\AB\B7\B5\BBش\ED\CE\F3\C2\EB::HI_ERR_PVR_PLAY_INVALID_STATE\n
seekʱ\C8\E7\B9\FB\B3\AC\B9\FD\B1߽磬\D7Զ\AF\B5\F7\D5\FB\B5\BD\B1߽\E7\n
\CF\F2\BA\F3seek\BAʹӿ\AAʼseek\A3\AC\D4\F2seek\B5\BD\B6\D4Ӧλ\D6õ\C4\CF\C2һ\B8\F6I֡\A3\AC\B2\BB\B3ɹ\A6\D4\F2\D5\D2ǰһ\B8\F6I֡\n
\CF\F2ǰseek\BAʹӽ\E1βseek\A3\AC\D4\F2seek\B5\BD\B6\D4Ӧλ\D6õ\C4ǰһ\B8\F6I֡\A3\AC\B2\BB\B3ɹ\A6\D4\F2\D5\D2\CF\C2һ\B8\F6I֡\n
\D5Ҳ\BB\B5\BDI֡\BB᷵\BBش\ED\CE\F3 CNend
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstPosition Pointer to the playing position.  CNcomment:\B2\A5\B7\C5λ\D6\C3\D0\C5Ϣָ\D5\EB CNend
\retval ::HI_SUCCESS  Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT        The PVR recording module is not initialized.  CNcomment:PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID        The channel ID is invalid.   CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT       The specified channel is not initialized.   CNcomment:ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE  The channel status is incorrect, that is , the channel has been stopped.  CNcomment: ͨ\B5\C0״̬\B4\ED\CE\F3\A3\BAͨ\B5\C0\D2Ѿ\ADֹͣ\D4\CB\D0\D0 CNend
\retval ::HI_ERR_DMX_INVALID_PARA       The parameter is invalid.   CNcomment: \B2\CE\CA\FD\B7Ƿ\A8 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT     The seek mode is not supported.   CNcomment:\B2\BB֧\B3ֵ\C4Seekģʽ CNend
\retval ::HI_ERR_PVR_FILE_TILL_END       No corresponding frame is sought till the end of a file.  CNcomment:Seek\B5\BD\CEļ\FEβû\D3\D0\D5ҵ\BD\CF\E0Ӧ\B5\C4֡ CNend
\retval ::HI_ERR_PVR_FILE_TILL_START   No corresponding frame is sought till the start of a file.    CNcomment:Seek\B5\BD\CEļ\FEͷû\D3\D0\D5ҵ\BD\CF\E0Ӧ\B5\C4֡ CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ     The file cannot be read.   CNcomment:\B6\C1ȡ\CEļ\FEʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlaySeek(HI_U32 u32ChnID, const HI_UNF_PVR_PLAY_POSITION_S *pstPosition);

/**
\brief Plays streams by frame. You can call this API to start step forward mode or step backward mode.
CNcomment: \D6\F0֡\B2\A5\B7š\A3\B5\F7\D3ô˽ӿڿ\C9\D2Խ\F8\D0\D0\D6\F0֡\B5\B9\CD˻\F2\D5\DF\D6\F0֡ǰ\BD\F8\B2\A5\B7\C5 CNend
\attention \n
Step backward mode is not supported currently. CNcomment:Ŀǰ\D4\DDʱ\B2\BB֧\B3\D6\D6\F0֡\B5\B9\B2\A5 CNend
\param[in] u32ChnID     Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] s32Direction  Playing direction. If the value is greater than or equal to 0, the direction is forward; if the value is less than 0, the direction is backward. CNcomment:  \B2\A5\B7ŷ\BD\CF򡣴\F3\D3ڵ\C8\D3\DA0\B1\EDʾǰ\BD\F8\A3\BBС\D3\DA0\B1\EDʾ\BA\F3\CD\CB CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT        The PVR recording module is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID      The channel ID is invalid.    CNcomment: ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT       The specified channel is not initialized.  CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_PLAY_INVALID_STATE   The channel status is incorrect, that is , the channel has been stopped. CNcomment: ͨ\B5\C0״̬\B4\ED\CE\F3\A3\BAͨ\B5\C0\D2Ѿ\ADֹͣ\D4\CB\D0\D0 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT   This function is not supported.  CNcomment:\B2\BB֧\B3ֵĹ\A6\C4\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayStep(HI_U32 u32ChnID, HI_S32 s32Direction);

/**
\brief Obtains the playing status of the PVR. CNcomment:\BB\F1ȡPVR\BBطŵ\C4״̬ CNend
\attention \n
Before calling this API to obtain the playing status, you must create a player.
CNcomment:\BB\F1ȡ\B2\A5\B7ŵ\C4״̬\A3\ACע\D2\E2\D4ڲ\A5\B7\C5\C6\F7\B4\B4\BD\A8֮\BA\F3\B5\F7\D3\C3 CNend
\param[in] u32ChnID
\param[in] pstStatus
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_BUSY   The system is busy. Please try again later. CNcomment:ϵͳæ\A3\AC\D3\F6\B5\BD\D5\E2\D6\D6\C7\E9\BF\F6\A3\AC\C7\EB\D6\D8\CAԡ\A3 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayGetStatus(HI_U32 u32ChnID, HI_UNF_PVR_PLAY_STATUS_S *pstStatus);

/**
\brief Obtains the information about the stream file recorded by the PVR based on the ID of the playing channel.  CNcomment:ͨ\B9\FD\B2\A5\B7\C5ͨ\B5\C0ID\A3\AC\BB\F1ȡPVR¼\D6Ƶ\C4\C2\EB\C1\F7\CEļ\FE\D0\C5Ϣ CNend
\attention \n
You can call this API to obtain the fixed information about the file to be played. However, the information is variable in the time-shift scenario.
You can call ::HI_UNF_PVR_PlayGetStatus to obtain the current playing position during playing.\n
You can call ::HI_UNF_PVR_RecGetStatus to obtain the current recording position during time shifting.
In addition, if both recording and playing do not start, you can call ::HI_UNF_PVR_GetFileAttrByFileName to obtain the attributes of a file.
CNcomment: \B5\F7\D3ô˽ӿ\DA\D3\C3\C0\B4\BB\F1ȡ\B2\A5\B7\C5\CEļ\FE\B5Ĺ̶\A8\D0\C5Ϣ\A3\AC\B5\AB\CAǶ\D4\D3\DAʱ\D2Ƴ\A1\BE\B0\D5\E2Щ\D0\C5Ϣ\CAǲ\BB\B6ϱ仯\B5\C4
\D4ڲ\A5\B7Ź\FD\B3\CC\D6п\C9\D2\D4ͨ\B9\FD::HI_UNF_PVR_PlayGetStatus\BDӿڻ\F1ȡ\B5\B1ǰ\B5Ĳ\A5\B7\C5λ\D6\C3 \n
\D4\DAʱ\D2ƹ\FD\B3\CC\D6п\C9\D2\D4ͨ\B9\FD::HI_UNF_PVR_RecGetStatus\BDӿڻ\F1ȡ\B5\B1ǰ\B5\C4¼\D6\C6λ\D6\C3
\B4\CB\CD⣬\C8\E7\B9\FB\BC\C8û\D3\D0\C6\F4\B6\AF¼\D6\C6Ҳû\D3\D0\C6\F4\B6\AF\B2\A5\B7ţ\AC\BF\C9\D2\D4ͨ\B9\FD::HI_UNF_PVR_GetFileAttrByFileName\BDӿڻ\F1ȡ\CEļ\FE\CA\F4\D0\D4 CNend
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pAttr Pointer to the playing status
\param[in] pAttr   CNcomment:\B2\A5\B7\C5״̬\D0\C5Ϣָ\D5\EB CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT            The PVR playing module is not initialized.  CNcomment:PVR\B2\A5\B7\C5ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_NUL_PTR           The pointer is null.   CNcomment: \BF\D5ָ\D5\EB\B4\ED\CE\F3 CNend
\retval ::HI_ERR_PVR_INVALID_CHNID      The channel ID is invalid.   CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT        The specified channel is not initialized. CNcomment: ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN      The file cannot be opened.  CNcomment:\CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ    The file cannot be read.   CNcomment: \CE޷\A8\B6\C1\CEļ\FE CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_PlayGetFileAttr(HI_U32 u32ChnID, HI_UNF_PVR_FILE_ATTR_S *pAttr);

/**
\brief
Obtains the information about a stream file.
By calling this API, you can obtain the information about a specified stream file without creating a playing channel.
CNcomment:\BB\F1ȡ\C2\EB\C1\F7\CEļ\FE\D0\C5Ϣ\A1\A3\B5\F7\D3ô˽ӿڿ\C9\D2\D4\D4ڲ\BB\C9\EA\C7벥\B7\C5ͨ\B5\C0\B5\C4\C7\E9\BF\F6\CF»\F1ȡָ\B6\A8\C2\EB\C1\F7\CEļ\FE\B5\C4\D0\C5Ϣ CNend
\attention \n
pFileName points to the name of a stream file rather than an index file.\n
You can call this API to obtain the attributes of a stream file at any time.
CNcomment:ָ\CF\F2\C2\EB\C1\F7\CEļ\FE\C3\FB\B6\F8\B2\BB\CA\C7\CB\F7\D2\FD\CEļ\FE\C3\FB.\C8κ\CEʱ\BA򶼿\C9\D2Ե\F7\D3ô˽ӿڻ\F1ȡ\C2\EB\C1\F7\CEļ\FE\B5\C4\CA\F4\D0\D4 CNend
\param[in] pFileName Name of a stream file  CNcomment:\C2\EB\C1\F7\CEļ\FE\C3\FB CNend
\param[in] pAttr   Pointer to the playing status   CNcomment:\B2\A5\B7\C5״̬\D0\C5Ϣָ\D5\EB CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NUL_PTR       The pointer is null.    CNcomment:\BF\D5ָ\D5\EB\B4\ED\CE\F3 CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN  The file cannot be opened.  CNcomment:\CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ   The file cannot be read. CNcomment:\CE޷\A8\B6\C1\CEļ\FE CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_GetFileAttrByFileName(const HI_CHAR *pFileName, HI_UNF_PVR_FILE_ATTR_S *pAttr);

/**
\brief  Writes the user data. CNcomment: д\C8\EB\D3û\A7\CA\FD\BE\DD CNend
\attention \n
pFileName points to the name of a stream file rather than an index file.\n
The value of u32UsrDataLen cannot be greater than that of u32UsrDataInfoSize. The value of u32UsrDataInfoSize (one of recording channel attributes) is set before a file is recorded.
The user data is saved in the index file.\n
You need to write the user data after starting a recording channel.
CNcomment:pFileNameָ\CF\F2\C2\EB\C1\F7\CEļ\FE\C3\FB\B6\F8\B2\BB\CA\C7\CB\F7\D2\FD\CEļ\FE\C3\FB \n
u32UsrDataLen\B5\C4ȡֵ\B2\BB\C4ܴ\F3\D3\DA¼\D6ƴ\CB\CEļ\FEʱ\D4\DA¼\D6\C6ͨ\B5\C0\CA\F4\D0\D4\C0\EF\C3\E6ָ\B6\A8\B5\C4u32UsrDataInfoSize\B5\C4ȡֵ \n
\D3û\A7\CA\FD\BEݱ\BB\B1\A3\B4\E6\D4\DA\CB\F7\D2\FD\CEļ\FE\D6\D0 \n
\C7\EB\D4\DA\C6\F4\B6\AF¼\D6\C6ͨ\B5\C0\BA\F3\D4\D9д\C8\EB\D3û\A7\CA\FD\BE\DD\D0\C5Ϣ CNend
\param[in] pFileName Name of a stream file CNcomment: \C2\EB\C1\F7\CEļ\FE\C3\FB CNend
\param[in] pInfo    Pointer to the user data. The memory is allocated by customers. CNcomment:\D3û\A7\CA\FD\BE\DDָ\D5룬\BFռ\E4\D3\C9\D3û\A7\B7\D6\C5\E4 CNend
\param[in] u32UsrDataLen   Length of the user data CNcomment: \D3û\A7\CA\FD\BEݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NUL_PTR       The pointer is null.   CNcomment: \BF\D5ָ\D5\EB\B4\ED\CE\F3 CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN   The file cannot be opened.CNcomment:\CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ  The file cannot be read.  CNcomment:\CE޷\A8\B6\C1\CEļ\FE CNend
\retval ::HI_ERR_DMX_INVALID_PARA    The parameter is invalid.  CNcomment: \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_SetUsrDataInfoByFileName(const HI_CHAR *pFileName, HI_U8 *pInfo, HI_U32 u32UsrDataLen);

/**
\brief  Reads the user data. CNcomment: \B6\C1ȡ\D3û\A7\CA\FD\BE\DD CNend
\attention \n
pFileName points to the name of a stream file rather than an index file.\n
The return value of pUsrDataLen indicates the length of the obtained user data. The value is the smaller one between the values of u32BufLen and actual length of the user data.
The actual length of the user data is greater than or equal to the maximum length of the user data set by calling HI_UNF_PVR_RecCreateChn. In this way, all user data can be read.\n
The PVR does not save the length of the user data set by calling HI_UNF_PVR_SetUsrDataInfoByFileName, but save the maximum length of the user data set by calling HI_UNF_PVR_RecCreateChn.
CNcomment:pFileNameָ\CF\F2\C2\EB\C1\F7\CEļ\FE\C3\FB\B6\F8\B2\BB\CA\C7\CB\F7\D2\FD\CEļ\FE\C3\FB \n
pUsrDataLen\B7\B5\BBض\C1ȡ\B5\BD\B5\C4\D3û\A7\CA\FD\BEݵĳ\A4\B6ȣ\AC\C6\E4ȡֵΪu32BufLen\BA\CD"ʵ\BC\CA\D3û\A7\CA\FD\BEݳ\A4\B6\C8"\B6\FE\D5\DF\D6еĽ\CFСֵ\A1\A3
"ʵ\BC\CA\D3û\A7\CA\FD\BEݳ\A4\B6\C8"\BD\AB\B2\BBС\D3\DAHI_UNF_PVR_RecNewChnʱ\C5\E4\D6õ\C4\D7\EE\B4\F3\D3û\A7\CA\FD\BEݳ\A4\B6ȣ\AC\D2Ա\A3֤\C4ܹ\BB\B0\D1ȫ\B2\BF\D3û\A7\CA\FD\BEݶ\C1\B3\F6 \n
PVRģ\BF鲻\B1\A3\B4\E6HI_UNF_PVR_SetUsrDataInfoByFileNameʱ\B4\AB\C8\EB\B5\C4\D3û\A7\CA\FD\BEݳ\A4\B6ȣ\ACֻ\B1\A3\B4\E6HI_UNF_PVR_RecNewChnʱ\C5\E4\D6õ\C4\D7\EE\B4\F3\D3û\A7\CA\FD\BEݳ\A4\B6\C8 CNend
\param[in] pFileName    Name of a stream file CNcomment:\C2\EB\C1\F7\CEļ\FE\C3\FB CNend
\param[in] pInfo    User data buffer. The memory is allocated by customers.   CNcomment:\D3û\A7\CA\FD\BEݻ\BA\B3\E5\C7\F8\A3\AC\BFռ\E4\D3\C9\D3û\A7\B7\D6\C5\E4 CNend
\param[in] u32BufLen   Buffer length .CNcomment:\BB\BA\B3\E5\C7\F8\B3\A4\B6\C8 CNend
\param[in] pUsrDataLen Actual length of the obtained user data .CNcomment:ʵ\BCʶ\C1ȡ\B5\BD\B5\C4\D3û\A7\CA\FD\BEݳ\A4\B6\C8 CNend
\retval ::HI_SUCCESS  Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NUL_PTR        The pointer is null.      CNcomment: \BF\D5ָ\D5\EB\B4\ED\CE\F3 CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN    The file cannot be opened. CNcomment:\CE޷\A8\B4\F2\BF\AA\CEļ\FE CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ    The file cannot be read.  CNcomment:\CE޷\A8\B6\C1\CEļ\FE CNend
\retval ::HI_ERR_DMX_INVALID_PARA      The parameter is invalid.  CNcomment: \B2\CE\CA\FD\B7Ƿ\A8 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_GetUsrDataInfoByFileName(const HI_CHAR *pFileName, HI_U8 *pInfo, HI_U32 u32BufLen, HI_U32* pUsrDataLen);

/**
\brief  Registers an event callback function. You can call this API to register a callback function for PVR event. In this way, you can handle the events occurred during PVR recording and playing.
CNcomment: ע\B2\E1\CA¼\FE\BBص\F7\BA\AF\CA\FD\A1\A3\B5\F7\D3ô˽ӿڿ\C9\D2\D4ע\B2\E1PVR\CA¼\FE\B5Ļص\F7\BA\AF\CA\FD\A3\AC\B4Ӷ\F8\B6\D4PVR¼\D6ơ\A2\B2\A5\B7Ź\FD\B3\CC\D6в\FA\C9\FA\B5\C4\CA¼\FE\BD\F8\D0д\A6\C0\ED CNend
\attention \n
You can call ::HI_UNF_PVR_UnRegisterEvent to deregister an event. If a registered event is not deregistered, it is always valid.
For the PVR_EVENT_PLAY_REACH_REC message, it is recommended to stop the playing of the PVR by calling the registered callback function, and switch the playing mode to live mode of the AVPLAY.
If the recording attribute is set to non-rewind, the PVR_EVENT_REC_OVER_FIX message is reported at the end of recording when the recording length reaches the specified length.
When the recording attribute is set to rewind, the PVR_EVENT_REC_OVER_FIX message is reported during each rewind. In this case, the value of s32EventValue of the message handling callback function is the times of rewind (counting from 1).
The PVR_EVENT_REC_REACH_PLAY message is reported when the recording speed will reach the playing speed. In this case, the value of s32EventValue is the number of bytes between the recording position and the playing position.
CNcomment: \BF\C9\D2\D4ʹ\D3\C3::HI_UNF_PVR_UnRegisterEvent\C0\B4\B7\B4ע\B2\E11\B8\F6\CA¼\FE\A3\AC\B7\F1\D4\F2\D2Ѿ\ADע\B2\E1\B5\C4\CA¼\FE\BD\ABһֱ\B1\A3\B3\D6\D3\D0Ч
\B6\D4\D3\DAPVR_EVENT_PLAY_REACH_REC\CF\FBϢ\A3\AC\BD\A8\D2\E9\D3û\A7\D4\DAע\B2\E1\B5Ļص\F7\BA\AF\CA\FD\D6\D0ֹͣPVR\B2\A5\B7ţ\AC\B2\A2\C7л\BB\B5\BDֱ\B2\A5ģʽ\D3\C3AVPLAY\BD\F8\D0в\A5\B7š\A3
\B5\B1¼\D6\C6\CA\F4\D0\D4\C5\E4\D6\C3Ϊ\B2\BB\BB\D8\C8Ƶ\C4ʱ\BA\F2\A3\ACPVR_EVENT_REC_OVER_FIX\CF\FBϢ\D4\DA¼\D6Ƴ\A4\B6ȵ\BD\B4\EFָ\B6\A8\B3\A4\B6ȣ\AC\BC\B4\BD\ABֹͣ¼\D6Ƶ\C4ʱ\BA\F2\C9ϱ\A8\A3\BB
\B5\B1¼\D6\C6\CA\F4\D0\D4\C5\E4\D6\C3Ϊ\BB\D8\C8Ƶ\C4ʱ\BA\F2\A3\ACPVR_EVENT_REC_OVER_FIX\CF\FBϢ\D4\DAÿ\B4λ\D8\C8Ƶ\C4ʱ\BA򶼻\E1\C9ϱ\A8\A3\AC\B4\CBʱ\A3\AC\CF\FBϢ\B4\A6\C0\ED\BBص\F7\BA\AF\CA\FD\B5\C4s32EventValue\B2\CE\CA\FDֵΪ\BB\D8\C8ƵĴ\CE\CA\FD(\B4\D31\BF\AAʼ\BC\C6\CA\FD)\A1\A3
PVR_EVENT_REC_REACH_PLAY\CF\FBϢ\D4\DA¼\D6Ƽ\B4\BD\AB׷\C9ϲ\A5\B7ŵ\C4ʱ\BA\F2\C9ϱ\A8\A3\AC\B4\CBʱ\A3\AC\CF\FBϢ\B4\A6\C0\ED\BBص\F7\BA\AF\CA\FD\B5\C4s32EventValue\B2\CE\CA\FDֵΪ¼\D6\C6λ\D6þ\E0\C0벥\B7\C5λ\D6õ\C4\D7ֽ\DA\CA\FD\A1\A3 CNend
\param[in] enEventType  Type of the event to be registered.  CNcomment: \CF\EBҪע\B2\E1\B5\C4\CA¼\FE\C0\E0\D0\CD CNend
\param[in] callBack   Event handling callback function.   CNcomment: \CA¼\FE\B4\A6\C0\ED\BA\AF\CA\FD CNend
\param[in] args      Parameters of a customized callback function.    CNcomment:\D3û\A7\D7Զ\A8\D2\E5\BBص\F7\BA\AF\CA\FD\B5Ĳ\CE\CA\FD CNend
\retval ::HI_SUCCESS   Success CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_INTF_EVENT_INVAL   The event is invalid.  CNcomment: \B7Ƿ\A8\B5\C4\CA¼\FE CNend
\retval ::HI_ERR_PVR_ALREADY         The registering event has been registered.    CNcomment: \B3\A2\CAԶ\D4\D2Ѿ\ADע\B2\E1\B5\C4\CA¼\FE\D4ٴ\CEע\B2\E1 CNend
\retval ::HI_ERR_PVR_INTF_EVENT_NOREG    Registration fails because the callback function pointer is incorrect. CNcomment:  \BBص\F7\BA\AF\CA\FDָ\D5\EB\B3\F6\B4\ED\A3\AC\CE޷\A8ע\B2\E1\B3ɹ\A6 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RegisterEvent(HI_UNF_PVR_EVENT_E enEventType, eventCallBack callBack, HI_VOID *args);

/**
\brief  Deregisters a PVR event. CNcomment: ȥע\B2\E1PVR\CA¼\FE\B5Ļص\F7\BA\AF\CA\FD CNend
\attention \n
You can call this API to deregister an event. If a registered event is not deregistered, it is always valid.
CNcomment: \BF\C9\D2\D4ʹ\D3ô˽ӿ\DA\C0\B4ȥע\B2\E11\B8\F6\CA¼\FE\A3\AC\B7\F1\D4\F2\D2Ѿ\ADע\B2\E1\B5\C4\CA¼\FE\BD\ABһֱ\B1\A3\B3\D6\D3\D0Ч CNend
\param[in] enEventType      Type of the event to be deregistered    CNcomment: \CF\EBҪȥע\B2\E1\B5\C4\CA¼\FE\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS   Success  CNcomment:\B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_INTF_EVENT_INVAL  The event is invalid. CNcomment: \B7Ƿ\A8\B5\C4\CA¼\FE CNend
\retval ::HI_ERR_PVR_INTF_EVENT_NOREG  The deregistering event is not registered. CNcomment: \B6\D4û\D3\D0ע\B2\E1\B5\C4\CA¼\FE\BD\F8\D0\D0ȥע\B2\E1 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_UnRegisterEvent(HI_UNF_PVR_EVENT_E enEventType);

/**
\brief Create index file by ts file. CNcomment:\B8\F9\BE\DD\C2\EB\C1\F7\CEļ\FE\B4\B4\BD\A8\CB\F7\D2\FD\CEļ\FE CNend
\attention \n
This function is not supported currently.
CNcomment: \D4\DDʱ\B2\BB֧\B3ִ˹\A6\C4\DC CNend
\param[in] pstTsFileName
\param[in] pstIdxFileName
\param[in] pAttr
\retval ::HI_SUCCESS Success CNcomment:  \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4\DC CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_CreateIdxFile(HI_U8* pstTsFileName, HI_U8* pstIdxFileName, HI_UNF_PVR_GEN_IDX_ATTR_S* pAttr);

/**
\brief Controls whether to output debugging information.  CNcomment:\C5\E4\D6\C3\CAǷ\F1\CA\E4\B3\F6\B5\F7\CA\D4\D0\C5Ϣ CNend
\attention \n
The debugging information about the severity level higher than the error level is output.
CNcomment:Ĭ\C8\CF\CA\E4\B3\F6error \D2\D4\C9ϼ\B6\B1\F0\B5ĵ\F7\CA\D4\D0\C5Ϣ\A1\A3ע\D2\E2\BA\CDȫ\BEִ\F2ӡ\BC\B6\B1\F0\C5\E4\BA\CFʹ\D3ã\AC\BC\B4\B4˼\B6\B1\F0\D0\E8ҪС\D3ڵ\C8\D3\DAȫ\BEִ\F2ӡ\BC\B6\B1\F0\B2\C5\D3\D0Ч CNend
\param[in] enDebugLevel  Output level of the debugging information CNcomment: \B5\F7\CA\D4\D0\C5Ϣ\CA\E4\B3\F6\BC\B6\B1\F0 CNend
\retval none
\see \n
N/A
*/
HI_VOID HI_UNF_PVR_ConfigDebugInfo(HI_LOG_LEVEL_E enDebugLevel);

/**
\brief  Deletes the stream files and index files generated during recording. CNcomment:ɾ\B3\FD¼\D6\C6ʱ\C9\FA\B3ɵ\C4\C2\EB\C1\F7\CEļ\FE\BA\CD\CB\F7\D2\FD\CEļ\FE CNend
\attention \n
pFileName points to the name of a stream file rather than an index file.\n
After this API is called, the stream files and index files generated during stream recording are deleted.
If a stream file is greater than 4 GB, multiple files named data.ts, data.ts.0001, data.ts.0002, data.ts.0003, and ... are generated. To delete these files, you only need to enter the file name data.ts.
CNcomment:pFileNameָ\CF\F2\C2\EB\C1\F7\CEļ\FE\C3\FB\B6\F8\B2\BB\CA\C7\CB\F7\D2\FD\CEļ\FE\C3\FB\n
\B5\F7\D3ô˽ӿں\F3\A3\AC¼\D6ƴ\CB\C2\EB\C1\F7ʱ\C9\FA\B3ɵ\C4\C2\EB\C1\F7\CEļ\FE\BA\CD\CB\F7\D2\FD\CEļ\FE\B6\BC\BD\AB\B1\BBɾ\B3\FD\n
\C8\E7\B9\FB\C2\EB\C1\F7\CEļ\FE\B4\F3\D3\DA4G\BD\AB\BB\E1\C9\FA\B3\C9data.ts, data.ts.0001, data.ts.0002, data.ts.0003 ...\n
\B5ȶ\E0\B8\F6\CEļ\FE\A3\AC\B5\AB\CA\C7ɾ\B3\FDʱֻ\D0\E8Ҫ\B4\AB\C8\EB\CEļ\FE\C3\FB"data.ts"\BEͿ\C9\D2\D4\C1ˡ\A3 CNend
\param[in] pFileName  Name of a stream file  CNcomment:\C2\EB\C1\F7\CEļ\FE\C3\FB CNend
\retval none
\see \n
N/A
*/
HI_VOID HI_UNF_PVR_RemoveFile(const HI_CHAR *pFileName);


/**
\brief
Register extra write callback function.When the stream file need to be extra processed  CNcomment: ע\B2\E1\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\A1\A3\B5\B1\CEļ\FE\D0\E8Ҫ\CC\D8\CA⴦\C0\EDʱע\B2ᣬ\C8\E7˽\D3\D0Э\D2\E9\BC\D3\C8ŵĽ\DAĿ\A1\A3 CNend
\attention \n
N/A
\param[in] u32ChnID    Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ? CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RegisterExtraCallback(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType, ExtraCallBack fCallback, HI_VOID *args);

/**
\brief Deregisters extra write callback function.When the stream file need to be extra processed  CNcomment:ȥע\B2\E1\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\A1\A3 CNend
\attention \n
N/A
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_UnRegisterExtraCallBack(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType);

/**
\brief
Register extra write callback function.When the stream file need to be extra processed  CNcomment: ע\B2\E1\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\A1\A3\B5\B1\CEļ\FE\D0\E8Ҫ\CC\D8\CA⴦\C0\EDʱע\B2ᣬ\C8\E7˽\D3\D0Э\D2\E9\BC\D3\C8ŵĽ\DAĿ\A1\A3 CNend
\attention \n
N/A
\param[in] u32ChnID    Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\param[in] fCallback  Callback function CNcomment: \BBص\F7\BA\AF\CA\FDCNend
\param[in] pUserData  arguments of the Callback function CNcomment: \BBص\F7\BA\AF\CA\FD\B5\C4\D3û\A7\B2\CE\CA\FDCNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ? CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RegisterExtendCallback(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType, ExtendCallBack fCallback, HI_VOID *pUserData);

/**
\brief Deregisters extra write callback function.When the stream file need to be extra processed  CNcomment:ȥע\B2\E1\CDⲿ\B6\C1\A1\A2д\CA\FD\BEݻص\F7\BA\AF\CA\FD\A1\A3 CNend
\attention \n
N/A
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\param[in] fCallback  Callback function CNcomment: \BBص\F7\BA\AF\CA\FD CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_PARA   invalid input param, E.x.   fCallback hasn't been registered before CNcomment:   \B7Ƿ\A8\CA\E4\C8\EB\B2\CE\CA\FD\A3\AC\C8\E7\CA\E4\C8뺯\CA\FDָ\D5\EBδ\B1\BBע\B2\E1CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_UnRegisterExtendCallback(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType, ExtendCallBack fCallback);

/**
\brief register the callback function Which is called by PVR when the app informs pvr to change the recorded pids CNcomment:ע\B2\E1PID\B1\E4\B8\FC\BBص\F7\BA\AF\CA\FDCNend
\attention \n
N/A
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\param[in] fCallback  Callback function CNcomment: \BBص\F7\BA\AF\CA\FD CNend
\param[in] pArgs  Callback function's parameters CNcomment: \BBص\F7\BA\AF\CA\FD\D0\E8Ҫ\B5Ĳ\CE\CA\FD CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_PARA   invalid input param, E.x.   fCallback hasn't been registered before CNcomment:   \B7Ƿ\A8\CA\E4\C8\EB\B2\CE\CA\FD\A3\AC\C8\E7\CA\E4\C8뺯\CA\FDָ\D5\EBδ\B1\BBע\B2\E1CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PVR_RegisterPidChangeCallback(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType, PidChangeCallBack fCallback, HI_VOID *pArgs);

/**
\brief unregister the callback function which is called by PVR when the app informs pvr to change the recorded pids  CNcomment:ȥע\B2\E1PID\B1\E4\B8\FC\BBص\F7\BA\AF\CA\FD CNend
\attention \n
N/A
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enExtraCallbackType  Callback function type CNcomment: \BBص\F7\BA\AF\CA\FD\C0\E0\D0\CD CNend
\param[in] fCallback  Callback function CNcomment: \BBص\F7\BA\AF\CA\FD CNend
\retval ::HI_SUCCESS Success  CNcomment: \B3ɹ\A6 CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR recording module is not initialized CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_CHNID The channel ID is invalid.  CNcomment:ͨ\B5\C0\BAŷǷ\A8 CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT   Specified channel is not initialized   CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF CNend
\retval ::HI_ERR_PVR_INVALID_PARA   invalid input param, E.x.   fCallback hasn't been registered before CNcomment:   \B7Ƿ\A8\CA\E4\C8\EB\B2\CE\CA\FD\A3\AC\C8\E7\CA\E4\C8뺯\CA\FDָ\D5\EBδ\B1\BBע\B2\E1CNend
\see \n
N/A
*/

HI_S32 HI_UNF_PVR_UnRegisterPidChangeCallback(HI_U32 u32ChnID, HI_UNF_PVR_EXTRA_CALLBACK_E enExtraCallbackType, PidChangeCallBack fCallback);



/**
\brief create pid channel and create the binding relationship of rec channel.  CNcomment:\B4\B4\BD\A8PID  ͨ\B5\C0\B2\A2\BD\A8\C1\A2\D3\EB¼\D6\C6ͨ\B5\C0\B5İ󶨹\D8ϵ\A1\A3 CNend
\attention \n
You can call this api after creating the rec channl successfully.  CNcomment:\B8ýӿڱ\D8\D0\EB\D4ڳɹ\A6\B4\B4\BD\A8¼\D6\C6ͨ\B5\C0\BA󱻵\F7\D3\C3
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] u32Pid  PID value CNcomment: PID ֵ CNend
\retval ::HI_SUCCESS  Success. CNcomment: \B3ɹ\A6\A1\A3CNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The recorde channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The recorde channel is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment: \CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment: ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_ERR_DMX_NOT_SUPPORT  This function is not supported. CNcomment: \B2\BB֧\B3ִ˹\A6\C4ܡ\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecAddPID(HI_U32 u32ChnID, HI_U32 u32Pid);

/**
\brief destroy pid channel and destroy the relationship with rec channel.  CNcomment:\CF\FA\BB\D9PID  ͨ\B5\C0\B2\A2\BD\E2\B3\FD\D3\EB¼\D6\C6ͨ\B5\C0\B5İ󶨹\D8ϵ\A1\A3 CNend
\attention \n
You can call this api before destroying the rec channl.  CNcomment:\B8ýӿڱ\D8\D0\EB\D4\DA\CF\FA\BB\D9¼\D6\C6ͨ\B5\C0ǰ\B1\BB\B5\F7\D3\C3
\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] u32Pid  PID value CNcomment: PID ֵ CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The recorde channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The recorde channel is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecDelPID(HI_U32 u32ChnID, HI_U32 u32Pid);

/**
\brief destroy any pid channel which has binding relationship with rec channel.  CNcomment:\CF\FA\BB\D9\CB\F9\D3\D0\D3\EB¼\D6\C6ͨ\B5\C0\D3а󶨹\D8ϵ\B5\C4PID ͨ\B5\C0\A1\A3 CNend
\attention \n

\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The recorde channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The recorde channel is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_INVALID_PARA  The input parameter is invalid. CNcomment:\CA\E4\C8\EB\B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_DMX_NULL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecDelAllPID(HI_U32 u32ChnID);

/**
\brief change the record pid.  CNcomment: \B1\E4\B8\FC¼\D6Ƶ\C4Pid\A1\A3 CNend
\attention \n
\param[in] u32ChnId  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstPidInfo  PID info  CNcomment: \B1\E4\B8\FC\B5\C4PID\D0\C5Ϣ CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The recorde channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The recorde channel is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment: ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_DMX_NOT_INIT  The DEMUX module is not initialized. CNcomment:ģ\BF\E9û\D3г\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NUL_PTR  The pointer is null. CNcomment:ָ\D5\EB\B2\CE\CA\FDΪ\BFա\A3CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecChangePid(HI_U32 u32ChnId, HI_UNF_PVR_PID_CHANGE_INFO_S *pstPidInfo);

/**
\brief Set the recording channel attribute, only supports the rewind state is set to non-rewind state.  CNcomment: \C9\E8\D6\C3¼\D6\C6ͨ\B5\C0\CA\F4\D0ԣ\ACĿǰ\BD\F6֧\B3ֽ\AB\BB\D8\C8\C6״̬\C9\E8\D6\C3Ϊ\B7ǻ\D8\C8\C6״̬\A1\A3 CNend
\attention \n

\param[in] u32ChnID  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] enRecAttrID  attribute ID  CNcomment:\CA\F4\D0\D4ID CNend
\param[in] pPara  Extra parameters  CNcomment:\C6\E4\CB\FB\D3û\A7\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_INVALID_CHNID  The recorde channel ID is invalid. CNcomment: ͨ\B5\C0\BAŷǷ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The PVR module is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  The record channel not support this operatin. CNcomment: \B5\B1ǰͨ\B5\C0\B2\BB֧\B3ָò\D9\D7\F7\A1\A3CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecSetAttr(HI_U32 u32ChnID, HI_UNF_PVR_REC_ATTR_ID_E enRecAttrID, const HI_VOID *pPara);

/**
\brief Be Linear.  CNcomment: \C6\F4\B6\AF\CF\DF\D0Ի\AF CNend
\attention \n

\param[out] pu32ChnId  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstRepaireAttr  Linearization parameters  CNcomment:\CF\DF\D0Ի\AF\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_NUL_PTR  null pointer. CNcomment: \BF\D5ָ\D5롣CNend
\retval ::HI_ERR_PVR_INVALID_PARA  The parameter is invalid. CNcomment: \B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_FILE_NOT_EXIST  The specified file does not exist. CNcomment:   ָ\B6\A8\B5\C4Դ\CEļ\FE\B2\BB\B4\E6\D4ڡ\A3CNend
\retval ::HI_ERR_PVR_NOT_INIT  The recorde channel is not initialized. CNcomment: PVR¼\D6\C6ģ\BF\E9δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  The record channel not support this operatin. CNcomment: \B5\B1ǰͨ\B5\C0\B2\BB֧\B3ָò\D9\D7\F7\A1\A3CNend
\retval ::HI_ERR_PVR_CHN_NOT_INIT  The recorde channel is not initialized. CNcomment:   ָ\B6\A8\B5\C4ͨ\B5\C0δ\B3\F5ʼ\BB\AF\A1\A3CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN  The specified file is not open. CNcomment: ָ\B6\A8\CEļ\FE\B2\BB\BFɴ򿪡\A3CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ  The specified file is not readable. CNcomment: ָ\B6\A8\CEļ\FE\B2\BB\BFɶ\C1\A1\A3CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecFileStartLinearization(HI_U32 *pu32ChnId, const HI_UNF_PVR_LINEARIZATION_ATTR_S *pstRepaireAttr);

/**
\brief Get linear progress.  CNcomment: \BB\F1ȡ\CF\DF\D0Ի\AF\BD\F8\B6\C8 CNend
\attention \n

\param[in] u32ChnId  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[out] pstLineariztionStatus  Linearization channel status  CNcomment:\CF\DF\D0Ի\AFͨ\B5\C0״̬CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_NUL_PTR  null pointer. CNcomment: \BF\D5ָ\D5롣CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecFileLinearizationGetStatus(HI_U32 u32ChnId, HI_UNF_PVR_LINEARIZATION_STATUS_S *pstLineariztionStatus);

/**
\brief stop Linear.  CNcomment: ֹͣ\CF\DF\D0Ի\AF CNend
\attention \n

\param[in] pu32ChnId  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecFileStopLinearization(HI_U32 u32ChnId);

/**
\brief Be Linear.  CNcomment: \B6\D4ָ\B6\A8PVR¼\D6\C6\CEļ\FE\B0\B4ָ\B6\A8\CC\F5\BC\FE\BD\F8\D0нض\CFCNend
\attention \n
\param[in] pszSrcFileName  The original file name to be processed CNcomment:\B4\FD\B4\A6\C0\ED\B5\C4ԭ\CEļ\FE\C3\FB CNend
\param[in] u32SrcFileNameLen  The length of the original file name CNcomment:ԭ\CEļ\FE \C3\FB\B3\A4\B6\C8 CNend
\param[in] pszDstFileName  The Destination file name to be processed CNcomment:\B4\FD\B4\A6\C0\ED\B5\C4Ŀ\B1\EA\CEļ\FE\C3\FB CNend
\param[in] u32DstFileNameLen  The length of the Destination file name CNcomment:Ŀ\B1\EA\CEļ\FE \C3\FB\B3\A4\B6\C8 CNend
\param[in] pstTruncInfo  Pointer to the attributes of truncate CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2truncate\CA\F4\D0\D4\C5\E4\D6\C3CNend
\retval ::HI_SUCCESS  Success. CNcomment:\B3ɹ\A6\A1\A3CNend
\retval ::HI_FAILUER  Call the function failed!. CNcomment:ִ\D0\D0ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_NUL_PTR  null pointer. CNcomment: \BF\D5ָ\D5롣CNend
\retval ::HI_ERR_PVR_INVALID_PARA  The parameter is invalid. CNcomment: \B2\CE\CA\FD\B7Ƿ\A8\A1\A3CNend
\retval ::HI_ERR_PVR_NOT_SUPPORT  PVR does not support current operation. CNcomment: PVR\B5\B1ǰ\B2\BB֧\B3ָò\D9\D7\F7\A1\A3CNend
\retval ::HI_ERR_PVR_FILE_NOT_EXIST  The specified file does not exist. CNcomment:   ָ\B6\A8\B5\C4Դ\CEļ\FE\B2\BB\B4\E6\D4ڡ\A3CNend
\retval ::HI_ERR_PVR_FILE_CANT_OPEN  The specified file is not open. CNcomment: ָ\B6\A8\CEļ\FE\B2\BB\BFɴ򿪡\A3CNend
\retval ::HI_ERR_PVR_FILE_CANT_READ  The specified file is not readable. CNcomment: ָ\B6\A8\CEļ\FE\B2\BB\BFɶ\C1\A1\A3CNend
\retval ::HI_ERR_PVR_NO_MEM  Failed to malloc memory. CNcomment: \C9\EA\C7\EB\C4ڴ\E6ʧ\B0\DCCNend
\retval ::HI_ERR_PVR_FILE_INVALID_FNAME  Invalid file name. CNcomment: \CE\DEЧ\B5\C4\CEļ\FE\C3\FBCNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecFileTruncate(const HI_CHAR *pszSrcFileName, HI_U32 u32SrcFileNameLen, const HI_CHAR *pszDstFileName, HI_U32 u32DstFileNameLen, const HI_UNF_PVR_RECFILE_TRUNCATE_INFO_S *pstTruncInfo);


/**
\brief notify the record channel that the stream is end, PVR will try to receive all the un-aligned by 47K ts data from demux and report
\        the event of HI_UNF_PVR_EVENT_REC_EOS if all the ts data has been received. if this api is not called, PVR won't receive the un-aligned of 47K ts data from the demux.
\CNcomment:֪ͨ¼\D6\C6ͨ\B5\C0ǰ\B6\CB\CA\FD\BE\DD\D2ѽ\E1\CA\F8\A3\ACPVR\BD\AB\CA\D5ȡdemux\B6\CB\CB\F9\D3з\C747K\B6\D4\C6\EB\B5\C4\CA\FD\BEݣ\AC\B2\A2\C7\D2֧\B3\D6\C9ϱ\A8\CA¼\FEHI_UNF_PVR_EVENT_REC_EOS.
\ CNcomment       \C8\E7\B9\FB\B2\BB\B5\F7\D3øýӿڣ\ACPVR\B2\BB\BB\E1\CA\D5ȡdemux\B6˷\C747K\B6\D4\C6\EB\B5\C4\CA\FD\BE\DD.CNend
\ attention: before calling the API, APP should make sure that no data is injected to the port of demux used by the record channel;
\                  if this API is called, the length of ts data reported by ExtraCallBack/ExtendCallBack isn't always aligned
\                  for the recording which the injecting data is always running(E.x. dvb/iptv recording), this API should not be called.
\ CNcommentע\D2\E2: \D4ڵ\F7\D3ø\C3API֮ǰ\A3\ACAPP\D0\E8Ҫ\B1\A3֤ǰ\B6\CBû\D3\D0\CA\FD\BEݵ\BD\B4\EF¼\D6\C6ͨ\B5\C0ʹ\D3õ\C4demux port\BF\DACNend
\ CNcomment              \B5\F7\D3øú\AF\CA\FD\BBᵼ\D6\C2ExtraCallBack/ExtendCallBack\BBص\F7\C9ϱ\A8\B5\C4\CA\FD\BEݳ\A4\B6Ȳ\BBһ\B6\A8\D7\DC\CAǶ\D4\C6\EB\B5\C4.CNend
\ CNcomment              \B6\D4\D3\DAͷ\B6\CB\CA\FD\BEݲ\BB\BB\E1\D6жϵ\C4¼\D6\C6(\C8\E7dvb/iptv¼\D6\C6)\A3\AC\B2\BB\D0\E8Ҫ\B5\F7\D3øýӿ\DA.CNend
\param[in] u32ChnId  Channel ID  CNcomment:ͨ\B5\C0\BA\C5 CNend
\param[in] pstOpt  Pointer used for expansion. You can set it to NULL  CNcomment:ָ\D5\EB\C0\E0\D0ͣ\AC\B4\FD\C0\A9չʹ\D3ã\AC\C9\E8ΪΪNULL\BC\B4\BF\C9 CNend
\retval ::HI_SUCCESS if successing to configure, others if failure. CNcomment:\B3ɹ\A6\B7\B5\BB\D8HI_SUCCESS\A3\AC\B3\F6\B4\ED\B7\B5\BB\D8\C6\E4\CB\FBֵ\A1\A3CNend
\see \n\see \nN/A
*/
HI_S32 HI_UNF_PVR_RecFlushStream(HI_U32 u32RecChnID, HI_UNF_PVR_FLUSH_STREAM_OPT_S *pstOpt);

/** @} */  /** <!-- ==== API Declaration End ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif /* End of #ifndef __HI_UNF_PVR_H__ */
