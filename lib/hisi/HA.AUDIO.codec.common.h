#ifndef __HISI_AUDIO_CODEC_COMMON_H__
#define __HISI_AUDIO_CODEC_COMMON_H__

#include "hi_type.h"
#include "hi_audio_codec.h"
#include "securec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define HA_CHECK_MEM_SUCCESS(api)\
do {\
    errno_t _ret_mem_ = (api); \
    if(EOK != _ret_mem_) { \
        HA_ERR_PRINT("%s[%d]:%s failed(0x%x)\n", __FUNCTION__, __LINE__, #api, _ret_mem_); \
    } \
} while(0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HISI_AUDIO_CODEC_COMMON_H__ */
iff -Naur a/lib/hisi/Makefile.inc b/lib/hisi/Makefile.inc
-- a/lib/hisi/Makefile.inc	1970-01-01 01:00:00.000000000 +0100
++ b/lib/hisi/Makefile.inc	2021-12-07 18:08:15.661960700 +0100
@ -0,0 +1,124 @@
noinst_LIBRARIES += hisi/libenigma_hisi.a

hisi_libenigma_hisi_a_CXXFLAGS = \
	$(LIBXINE_CFLAGS)

hisi_libenigma_hisi_a_SOURCES = \
	hisi/hi_adp_mpi.c \
	hisi/hi_adp_hdmi.c \
	hisi/hi_adp_ini.c

hisiincludedir = $(pkgincludedir)/lib/hisi
hisiinclude_HEADERS = \
	hisi/HA.AUDIO.AAC.decode.h \
	hisi/HA.AUDIO.AAC.encode.h \
	hisi/HA.AUDIO.AC3PASSTHROUGH.decode.h \
	hisi/HA.AUDIO.AMRNB.codec.h \
	hisi/HA.AUDIO.AMRWB.codec.h \
	hisi/HA.AUDIO.BLURAYLPCM.decode.h \
	hisi/HA.AUDIO.codec.common.h \
	hisi/HA.AUDIO.COOK.decode.h \
	hisi/HA.AUDIO.CUSTOM.decode.h \
	hisi/HA.AUDIO.DOLBYMS12.decode.h \
	hisi/HA.AUDIO.DOLBYMS12EXT.decode.h \
	hisi/HA.AUDIO.DOLBYPLUS.decode.h \
	hisi/HA.AUDIO.DOLBYTRUEHD.decode.h \
	hisi/HA.AUDIO.DRA.decode.h \
	hisi/HA.AUDIO.DTSHD.decode.h \
	hisi/HA.AUDIO.DTSM6.decode.h \
	hisi/HA.AUDIO.DTSPASSTHROUGH.decode.h \
	hisi/HA.AUDIO.FFMPEG_DECODE.decode.h \
	hisi/HA.AUDIO.FFMPEG_DTS.decode.h \
	hisi/HA.AUDIO.FFMPEG_EAC3.decode.h \
	hisi/HA.AUDIO.FFMPEG_LPCM.decode.h \
	hisi/HA.AUDIO.FFMPEG_TRUEHD.decode.h \
	hisi/HA.AUDIO.FFMPEG_WMA.decode.h \
	hisi/HA.AUDIO.FFMPEG_WMAPRO.decode.h \
	hisi/HA.AUDIO.FFMPEG_WMA_PRO.decode.h \
	hisi/HA.AUDIO.G711.codec.h \
	hisi/HA.AUDIO.G722.codec.h \
	hisi/HA.AUDIO.MP2.decode.h \
	hisi/HA.AUDIO.MP3.decode.h \
	hisi/HA.AUDIO.OPUS.codec.h \
	hisi/HA.AUDIO.PCM.decode.h \
	hisi/HA.AUDIO.TRUEHDPASSTHROUGH.decode.h \
	hisi/HA.AUDIO.VOICE.codec.h \
	hisi/HA.AUDIO.VORBIS.codec.h \
	hisi/HA.AUDIO.WMA9STD.decode.h \
	hisi/hi_adp.h \
	hisi/hi_adp_boardcfg.h \
	hisi/hi_adp_data.h \
	hisi/hi_adp_hdmi.h \
	hisi/hi_adp_ini.h \
	hisi/hi_adp_mpi.h \
	hisi/hi_audio_codec.h \
	hisi/hi_common.h \
	hisi/hi_debug.h \
	hisi/hi_error_mpi.h \
	hisi/hi_go.h \
	hisi/hi_go_bliter.h \
	hisi/hi_go_comm.h \
	hisi/hi_go_cursor.h \
	hisi/hi_go_decoder.h \
	hisi/hi_go_encoder.h \
	hisi/hi_go_errno.h \
	hisi/hi_go_gdev.h \
	hisi/hi_go_surface.h \
	hisi/hi_go_text.h \
	hisi/hi_memory.h \
	hisi/hi_module.h \
	hisi/hi_system.h \
	hisi/hi_type.h \
	hisi/hi_unf_advca.h \
	hisi/hi_unf_aenc.h \
	hisi/hi_unf_ai.h \
	hisi/hi_unf_audio.h \
	hisi/hi_unf_avplay.h \
	hisi/hi_unf_cc.h \
	hisi/hi_unf_ci.h \
	hisi/hi_unf_cipher.h \
	hisi/hi_unf_common.h \
	hisi/hi_unf_demux.h \
	hisi/hi_unf_descrambler.h \
	hisi/hi_unf_disp.h \
	hisi/hi_unf_ecs.h \
	hisi/hi_unf_edid.h \
	hisi/hi_unf_frontend.h \
	hisi/hi_unf_gpio.h \
	hisi/hi_unf_hdcp.h \
	hisi/hi_unf_hdmi.h \
	hisi/hi_unf_i2c.h \
	hisi/hi_unf_ir.h \
	hisi/hi_unf_keyled.h \
	hisi/hi_unf_klad.h \
	hisi/hi_unf_klad_common_ca.h \
	hisi/hi_unf_klad_dcas.h \
	hisi/hi_unf_mailbox.h \
	hisi/hi_unf_mce.h \
	hisi/hi_unf_otp.h \
	hisi/hi_unf_otp_common_ca.h \
	hisi/hi_unf_otp_customize.h \
	hisi/hi_unf_otp_dcas.h \
	hisi/hi_unf_payloadcipher.h \
	hisi/hi_unf_pdm.h \
	hisi/hi_unf_pmoc.h \
	hisi/hi_unf_pq.h \
	hisi/hi_unf_pvr.h \
	hisi/hi_unf_pwm.h \
	hisi/hi_unf_sci.h \
	hisi/hi_unf_session_manager.h \
	hisi/hi_unf_so.h \
	hisi/hi_unf_sound.h \
	hisi/hi_unf_spi.h \
	hisi/hi_unf_subt.h \
	hisi/hi_unf_ttx.h \
	hisi/hi_unf_venc.h \
	hisi/hi_unf_version.h \
	hisi/hi_unf_vi.h \
	hisi/hi_unf_video.h \
	hisi/hi_unf_vo.h \
	hisi/hi_unf_vp.h \
	hisi/hi_unf_wdg.h \
	hisi/hi_user_proc.h \
	hisi/hi_video_codec.h

