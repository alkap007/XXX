/*
 * Copyright (C) Hisilicon Technologies Co., Ltd. 2009-2019. All rights reserved.
 * Description:
 * Author: guoqingbo
 * Create: 2009-12-15
 */

#ifndef __HI_COMMON_H__
#define __HI_COMMON_H__

#define CHIP_TYPE_hi3798mv200 1
#define HI_DAC_CVBS 1

#include "hi_system.h"
#include "hi_memory.h"
#include "hi_user_proc.h"

/*******************************Structure declaration *****************************/
/** @addtogroup     COMMON */
/** @{ */ /** <!--  [COMMON] */

typedef struct hiRECT_S
{
    HI_S32 s32X;
    HI_S32 s32Y;
    HI_S32 s32Width;
    HI_S32 s32Height;
} HI_RECT_S;

typedef enum hiLAYER_ZORDER_E
{
    HI_LAYER_ZORDER_MOVETOP = 0,  /**<Move to the top*/ /**<CNcomment:  \D2Ƶ\BD\D7\B2\BF */
    HI_LAYER_ZORDER_MOVEUP,       /**<Move up*/ /**<CNcomment:  \CF\F2\C9\CF\D2Ƶ\BD */
    HI_LAYER_ZORDER_MOVEBOTTOM,   /**<Move to the bottom*/ /**<CNcomment:  \D2Ƶ\BD\D7\EE\B5ײ\BF */
    HI_LAYER_ZORDER_MOVEDOWN,     /**<Move down*/ /**<CNcomment:  \CF\F2\CF\C2\D2Ƶ\BD */
    HI_LAYER_ZORDER_BUTT
} HI_LAYER_ZORDER_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#endif /* __HI_COMMON_H__ */

