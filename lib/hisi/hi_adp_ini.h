/******************************************************************************

  Copyright (C), 2011-2018. Hisilicon Technologies Co., Ltd. All rights reserved.

******************************************************************************
    File Name     : hi_adp_ini.h
    Version       : Initial Draft
    Author        : Device Chipset STB Development Dept
    Created       : 2018/08/23
    Description   : head file

******************************************************************************/

#ifndef HI_ADP_INI_H
#define HI_ADP_INI_H

#include <stdio.h>
#include "hi_type.h"

#define HI_INI_BUFSIZE  512

#define HIADP_INI_OpenRead(filename,file)   ((*(file) = fopen((filename),"rb")) != NULL)
#define HIADP_INI_Close(file)               (fclose(*(file)) == 0)
#define HIADP_INI_Read(buffer,size,file)    (fgets((buffer),(size),*(file)) != NULL)
#define HIADP_INI_Atof(string)              (float)strtod((string),NULL)


HI_BOOL  HIADP_INI_Getbool(const HI_CHAR *section, const HI_CHAR *key, HI_BOOL default_value, const HI_CHAR *file);
long     HIADP_INI_Getl(const HI_CHAR *section, const HI_CHAR *key, long default_value, const HI_CHAR *file);
HI_S32   HIADP_INI_Gets(const HI_CHAR *section, const HI_CHAR *key, const HI_CHAR *default_value, HI_CHAR *buffer, HI_S32 size, const HI_CHAR *file);
float    HIADP_INI_Getf(const HI_CHAR *section, const HI_CHAR *key, float default_value, const HI_CHAR *file);



#endif /* HI_ADP_INI_H */
