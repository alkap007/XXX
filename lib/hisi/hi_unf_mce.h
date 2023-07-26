/******************************************************************************

  Copyright (C), 2001-2014, HiSilicon Technologies Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_mce.h
  Version       : Initial Draft
  Author        : HiSilicon multimedia software group
  Created       : 2011-xx-xx
  Description   : hi_unf_mce.h header file
  History       :
  1.Date        : 2011/xx/xx
    Author      :
    Modification: This file is created.

******************************************************************************/
/**
 * \file
 * \brief Describes the logo and play contents and related configuration information.
 */
#ifndef __HI_UNF_MCE_H__
#define __HI_UNF_MCE_H__

#include "hi_unf_common.h"
#include "hi_unf_disp.h"
#include "hi_unf_vo.h"
#include "hi_unf_avplay.h"
#include "hi_unf_frontend.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif  /* End of #ifdef __cplusplus */

/********************************Struct Definition********************************/
/** \addtogroup      MCE */
/** @{ */  /** <!-- [MCE] */


/** Defines the logo parameter*/
/** CNcomment:\BF\AA\BB\FALogo\B2\CE\CA\FD*/
typedef struct hiUNF_MCE_LOGO_PARAM_S
{
    HI_BOOL     bLogoEnable;    /**<Whether logo is enable*//**<CNcomment: Logo\CAǷ\F1ʹ\C4\DC*/
    HI_U32      u32LogoLen;     /**<Length of logo data*//**<CNcomment: Logo\CA\FD\BEݵĳ\A4\B6\C8*/
}HI_UNF_MCE_LOGO_PARAM_S;


/*fastplay supports the decoding mode of ADEC*//**<CNcomment:fastplay ֧\B3ֵ\C4ADEC\BD\E2\C2\EB\B8\F1ʽ */
typedef enum hiUNF_MCE_ADEC_TYPE_E
{
    HI_UNF_MCE_ADEC_TYPE_MP2 = 0,       /**<MP2 format*//**<CNcomment:MP2 \D6\C6ʽ */
    HI_UNF_MCE_ADEC_TYPE_MP3 = 1,       /**<MP3 format*//**<CNcomment:MP3 \D6\C6ʽ */
    HI_UNF_MCE_ADEC_TYPE_BUTT           /**<Invalid format*//**<CNcomment:\CE\DEЧ \D6\C6ʽ */
}HI_UNF_MCE_ADEC_TYPE_E;

/**fastplay supports the decoding mode of VDEC*//**<CNcomment:fastplay ֧\B3ֵ\C4VDEC\BD\E2\C2\EB\B8\F1ʽ */
typedef enum hiUNF_MCE_VDEC_TYPE_E
{
    HI_UNF_MCE_VDEC_TYPE_MPEG2 = 0,     /**<MPEG2 format*//**<CNcomment:MPEG2  \D6\C6ʽ */
    HI_UNF_MCE_VDEC_TYPE_MPEG4 = 1,     /**<MPEG4 format*//**<CNcomment:MPEG4  \D6\C6ʽ */
    HI_UNF_MCE_VDEC_TYPE_H264  = 2,     /**<H264 format*//**<CNcomment:H264  \D6\C6ʽ */
    HI_UNF_MCE_VDEC_TYPE_AVS   = 3,     /**<AVS format*//**<CNcomment:AVS   \D6\C6ʽ */
    HI_UNF_MCE_VDEC_TYPE_HEVC  = 4,     /**<HEVC format*//**<CNcomment:H265  \D6\C6ʽ */
    HI_UNF_MCE_VDEC_TYPE_BUTT           /**<Invalid format*//**<CNcomment:\CE\DEЧ \D6\C6ʽ */
}HI_UNF_MCE_VDEC_TYPE_E;


/**Parameters for digital video broadcasting (DVB) play configuration*//**<CNcomment:DVB\C5\E4\D6\C3\D0\C5Ϣ  */
typedef struct hiUNF_MCE_DVB_PARAM_S
{
    HI_U32                      u32PcrPid;      /**<Program clock reference (PCR) packet ID (PID)*//**<CNcomment:pcr pid*/
    HI_U32                      u32VideoPid;    /**<Video PID*//**<CNcomment:\CA\D3Ƶ pid*/
    HI_U32                      u32AudioPid;    /**<Audio PID*//**<CNcomment:\D2\F4Ƶ pid*/
    HI_UNF_MCE_VDEC_TYPE_E      enVideoType;    /**<Video type*//**<CNcomment:\CA\D3Ƶ \C0\E0\D0\CD*/
    HI_UNF_MCE_ADEC_TYPE_E      enAudioType;    /**<Audio type*//**<CNcomment:\D2\F4Ƶ \C0\E0\D0\CD*/
    HI_U32                      u32Volume;      /**<volume of output*//**<CNcomment:\D2\F4\C1\BF */
    HI_UNF_TRACK_MODE_E         enTrackMode;    /**<Track mode. Only HI_UNF_TRACK_MODE_STEREO is supported.*//**<CNcomment:\BD\F6֧\B3\D6\C1\A2\CC\E5\C9\F9 */
    HI_UNF_VO_DEV_MODE_E        enDevMode;      /**<Working mode of the VO device*//**<CNcomment:dev \B5\C4 vo ģʽ  */
    HI_UNF_TUNER_CONNECT_PARA_S stConnectPara;  /**<Tuner connect parameter*//**<CNcomment:Tuner\CB\F8Ƶ\B2\CE\CA\FD.*/
    HI_UNF_TUNER_FE_LNB_CONFIG_S    stLnbCfg;   /**<LNB config*//**<CNcomment:LNB \C5\E4\D6\C3 */
    HI_UNF_TUNER_FE_LNB_POWER_E            enLNBPower;/**<LNB Power*//**<CNcomment:LNB\B9\A9\B5\E7\BF\D8\D6\C6 */
    HI_UNF_TUNER_DISEQC_SWITCH16PORT_S     st16Port;/**<Switch16 parameter*//**<CNcomment:Switch16\BF\AA\B9ز\CE\CA\FD */
    HI_UNF_TUNER_DISEQC_SWITCH4PORT_S      st4Port;/**<Switch4 parameter*//**<CNcomment:Switch4\BF\AA\B9ز\CE\CA\FD */
    HI_UNF_TUNER_SWITCH_22K_E              enSwitch22K; /**<22K switch parameter*//**<CNcomment:22K\BF\AA\B9ز\CE\CA\FD */
}HI_UNF_MCE_DVB_PARAM_S;

/**Play parameter configuration of transport stream (TS) files*//**<CNcomment:TS\CEļ\FE\C5\E4\D6\C3\D0\C5Ϣ */
typedef struct hiUNF_MCE_TSFILE_PARAM_S
{
    HI_U32                      u32ContentLen;  /**File length*//**<CNcomment:\CEļ\FE\B3\A4\B6\C8  */
    HI_U32                      u32PcrPid;      /**<pcr pid*//**<CNcomment:pcr pid  */
    HI_U32                      u32VideoPid;    /**<Video PID*//**<CNcomment:\CA\D3Ƶ pid. */
    HI_U32                      u32AudioPid;    /**<Audio PID*//**<CNcomment:\D2\F4Ƶ pid. */
    HI_UNF_MCE_VDEC_TYPE_E      enVideoType;    /**<Video type*//**<CNcomment:\CA\D3Ƶ \C0\E0\D0\CD */
    HI_UNF_MCE_ADEC_TYPE_E      enAudioType;    /**<Audio type*//**<CNcomment:\D2\F4Ƶ \C0\E0\D0\CD */
    HI_U32                      u32Volume;      /**<volume of output *//**<CNcomment:\D2\F4\C1\BF */
    HI_UNF_TRACK_MODE_E         enTrackMode;    /**<Track mode. Only HI_UNF_TRACK_MODE_STEREO is supported.*//**<CNcomment:\BD\F6֧\B3\D6\C1\A2\CC\E5\C9\F9 */
    HI_UNF_VO_DEV_MODE_E        enDevMode;      /**<mode of vo device  *//**<CNcomment:vo\C9豸\B5\C4ģʽ  */
}HI_UNF_MCE_TSFILE_PARAM_S;

#define ANI_MAX_PIC_SUPPORT (30)
typedef struct hiUNF_MCE_ANI_PARAM_S
{
    HI_U32  u32ContentLen;  /**File length*//**<CNcomment:\CEļ\FE\B3\A4\B6\C8  */
    HI_U32  u32PicCount;
    HI_U32  au32PicTime[ANI_MAX_PIC_SUPPORT];
}HI_UNF_MCE_ANI_PARAM_S;

/**Play type*//**<CNcomment:\B2\A5\B7\C5\C0\E0\D0\CD*/
typedef enum hiUNF_MCE_PLAY_TYPE_E
{
    HI_UNF_MCE_TYPE_PLAY_DVB     = 0,   /**<DVB type*/ /**<CNcomment:DVB \C0\E0\D0\CD */
    HI_UNF_MCE_TYPE_PLAY_TSFILE  = 1,   /**<TS file type*/ /**<CNcomment:ts \CEļ\FE\C0\E0\D0\CD */
    HI_UNF_MCE_TYPE_PLAY_ANI     = 2,   /**<ES file type*/ /**<CNcomment:es \CEļ\FE\C0\E0\D0\CD */
    HI_UNF_MCE_TYPE_PLAY_BUTT
}HI_UNF_MCE_PLAY_TYPE_E;


/**Play configuration*//**<CNcomment:\B2\A5\B7\C5\C5\E4\D6\C3\D0\C5Ϣ */
typedef struct hiUNF_MCE_PLAY_PARAM_S
{
    HI_UNF_MCE_PLAY_TYPE_E          enPlayType;     /**<Play type*//**<CNcomment:\B2\A5\B7\C5\C0\E0\D0\CD*/
    HI_BOOL                         bPlayEnable;    /**<Whether play is enable*//**<CNcomment: ˲\B2\A5\CAǷ\F1ʹ\C4\DC*/

    union
    {
        HI_UNF_MCE_DVB_PARAM_S     stDvbParam;      /**<dvb parameter*//**<CNcomment:dvb\B2\CE\CA\FD*/
        HI_UNF_MCE_TSFILE_PARAM_S  stTsParam;       /**<ts parameter*//**<CNcomment:ts\B2\CE\CA\FD*/
        HI_UNF_MCE_ANI_PARAM_S     stAniParam;      /**<es parameter*//**<CNcomment:es\B2\CE\CA\FD*/
    }unParam;

    HI_BOOL                         bContentValid;  /**<whether mce content is valid *//**<CNcomment:mce \CA\FD\BE\DD\CAǷ\F1\D3\D0Ч*/
}HI_UNF_MCE_PLAY_PARAM_S;

/**Mode of Play Control*//**CNcomment:\B2\A5\B7ſ\D8\D6\C6ģʽ */
typedef enum hiUNF_MCE_PLAYCTRL_MODE_E
{
    HI_UNF_MCE_PLAYCTRL_BY_TIME,    /**<play control by time*//**<CNcomment:ͨ\B9\FDʱ\BC\E4\BF\D8\D6\C6*/
    HI_UNF_MCE_PLAYCTRL_BY_COUNT,   /**<play control by count*//**<CNcomment:ͨ\B9\FD\B2\A5\B7Ŵ\CE\CA\FD\BF\D8\D6\C6*/
    HI_UNF_MCE_PLAYCTRL_BUTT
}HI_UNF_MCE_PLAYCTRL_MODE_E;

/**Defines the parameter of fastplay stop*//**CNcomment:˲\B2\A5ֹͣ\B2\CE\CA\FD */
typedef struct hiUNF_MCE_STOPPARM_S
{
    HI_UNF_AVPLAY_STOP_MODE_E   enStopMode;     /**<Mode of Stop,see ::HI_UNF_AVPLAY_STOP_MODE_E*//**<CNcomment:ֹͣģʽ\A3\AC\B2μ\FB::HI_UNF_AVPLAY_STOP_MODE_E*/
    HI_UNF_MCE_PLAYCTRL_MODE_E  enCtrlMode;     /**<Mode of Play Control*//**<CNcomment:\B2\A5\B7ſ\D8\D6\C6ģʽ */
    HI_U32                      u32PlayTimeMs;    /**<Play time*//**<CNcomment:\B2\A5\B7\C5ʱ\BC\E4 */
    HI_U32                      u32PlayCount;   /**<Play count*//**<CNcomment:\B2\A5\B7Ŵ\CE\CA\FD */
} HI_UNF_MCE_STOPPARM_S;

/**Defines the parameter of fastplay exit*//**CNcomment:˲\B2\A5\CD˳\F6\B2\CE\CA\FD */
typedef struct hiUNF_MCE_EXITPARAM_S
{
    HI_HANDLE   hNewWin;          /**<Handle of new window*//**<CNcomment:\D0´\B0\BFھ\E4\B1\FA */
}HI_UNF_MCE_EXITPARAM_S;

/**Defines the parameter of fastplay init*//**CNcomment:˲\B2\A5\B3\F5ʼ\BB\AF\B2\CE\CA\FD */
typedef struct hiUNF_MCE_INIT_PARAM_S
{
    HI_U32      u32Reserved;
}HI_UNF_MCE_INIT_PARAM_S;


/** @} */  /** <!-- ==== Struct Definition end ==== */

/********************************API declaration********************************/
/** \addtogroup      MCE */
/** @{ */  /** <!-- [MCE]*/

/**
\brief init mce  CNcomment:MCE\C5\E4\D6ó\F5ʼ\BB\AF\BDӿ\DA CNend
\attention \n
Initializes the media control engine (MCE) before call other MCE API.
CNcomment:ʹ\D3\C3MCE\BDӿ\DAǰ\CA\D7\CFȵ\F7\D3øýӿ\DA CNend
\param[in]  pstInitParam  Pointer to MCE init parameter, reserved. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2˲\B2\A5\B3\F5ʼ\BB\AF\B2\CE\CA\FD\A3\AC\B1\A3\C1\F4 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_MCE_DEV_NOT_EXIST      Device is not exist. CNcomment:\C9豸\B2\BB\B4\E6\D4\DA CNend
\retval :: HI_ERR_MCE_NOT_DEVICE      Not a device. CNcomment:\B7\C7\C9豸 CNend
\retval :: HI_ERR_MCE_DEV_OPEN_ERR      Parameter is invalid. CNcomment:\C9豸\B4\F2\BF\AAʧ\B0\DC CNend
\see \n
N/A
*/
HI_S32  HI_UNF_MCE_Init(HI_UNF_MCE_INIT_PARAM_S *pstInitParam);

/**
\brief deinit mce  CNcomment:MCE\C5\E4\D6\C3ȥ\B3\F5ʼ\BB\AF\BDӿ\DA CNend
\attention \n
Destroys all MCE resources.  CNcomment:\CD\EA\B3\C9MCE\C5\E4\D6ù\A4\D7\F7\D7\EE\D6յ\F7\D3øýӿ\DA CNend
\see \n
N/A
*/
HI_VOID HI_UNF_MCE_DeInit(HI_VOID);

/**
\brief deinit mce  CNcomment:\C7\E5\BFտ\AA\BB\FA\BB\AD\C3\E6\BDӿ\DA CNend
\attention \n
Destroys the logo.  CNcomment:\C7\E5\BFտ\AA\BB\FA\BB\AD\C3\E6 CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_MCE_DEV_NOT_INIT      Device is not init. CNcomment:\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval :: HI_ERR_MCE_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_MCE_ClearLogo(HI_VOID);

/**
\brief  stop fastplay. CNcomment:ֹͣfastplay CNend
\attention \n
If enCtrlMode is HI_UNF_MCE_PLAYCTRL_BY_TIME, u32PlayTime is valid; if enCtrlMode is HI_UNF_MCE_PLAYCTRL_BY_COUNT, u32PlayCount is valid
CNcomment: enCtrlModeѡΪHI_UNF_MCE_PLAYCTRL_BY_TIMEʱ\A3\ACu32PlayTime\C9\FAЧ, ѡΪHI_UNF_MCE_PLAYCTRL_BY_COUNTʱ\A3\ACu32PlayCount\C9\FAЧ CNend
\param[in]  pstStopParam  Pointer to fastplay  stop parameter. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2˲\B2\A5ֹͣ\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_MCE_DEV_NOT_INIT      Device is not init. CNcomment:\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval :: HI_ERR_MCE_PTR_NULL      Pointer is null. CNcomment:\BF\D5ָ\D5\EB CNend
\retval :: HI_ERR_MCE_PARAM_INVALID      Parameter is invalid. CNcomment\CE\DEЧ\B2\CE\CA\FD CNend
\retval :: HI_ERR_MCE_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MCE_Stop(HI_UNF_MCE_STOPPARM_S *pstStopParam);


/**
\brief  Exit fastplay and destrory fastplay source CNcomment:\CD˳\F6fastplay,\CF\FA\BB\D9fastplay\D7\CAԴ CNend
\attention \n
N/A
\param[in]  pstExitParam  Pointer to fastplay  exit parameter. CNcomment:ָ\D5\EB\C0\E0\D0ͣ\ACָ\CF\F2˲\B2\A5\CD˳\F6\B2\CE\CA\FD CNend
\retval ::HI_SUCCESS       Success. CNcomment:\B3ɹ\A6 CNend
\retval :: HI_ERR_MCE_DEV_NOT_INIT      Device is not init. CNcomment:\C9豸δ\B3\F5ʼ\BB\AF CNend
\retval :: HI_ERR_MCE_PARAM_INVALID      Parameter is invalid. CNcomment\CE\DEЧ\B2\CE\CA\FD CNend
\retval :: HI_ERR_MCE_INVALID_OPT      The operation is invalid. CNcomment:\CE\DEЧ\B2\D9\D7\F7 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_MCE_Exit(HI_UNF_MCE_EXITPARAM_S *pstExitParam);


/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif



