/******************************************************************************

  Copyright (C), 2011-2018. Hisilicon Technologies Co., Ltd. All rights reserved.

******************************************************************************
    File Name     : hi_adp_ini.c
    Version       : Initial Draft
    Author        : Device Chipset STB Development Dept
    Created       : 2018/08/23
    Description   : Read value from ini file.
******************************************************************************/

#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "hi_adp_ini.h"

static HI_CHAR *skiphead(const HI_CHAR *str)
{
    while (*str != '\0' && *str <= ' ')
    {
        str++;
    }
    return (HI_CHAR *)str;
}

static HI_CHAR *skiptail(const HI_CHAR *str, const HI_CHAR *base)
{
    while (str > base && *(str-1) <= ' ')
    {
        str--;
    }
    return (HI_CHAR *)str;
}

static HI_CHAR *striptail(HI_CHAR *str)
{
    HI_CHAR *p = skiptail(strchr(str, '\0'), str);
    if(p != NULL)
    {
        *p = '\0';
    }
    return str;
}

static HI_CHAR * copystring(HI_CHAR *dest, const HI_CHAR *source, HI_U32 len)
{
    HI_U32 i;

    for (i = 0; i < len - 1 && source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }

    dest[i] = '\0';

    return dest;
}

static HI_CHAR *cleanstring(HI_CHAR *string)
{
    HI_S32 isstring;
    HI_CHAR *p;

    isstring = 0;
    for (p = string; *p != '\0' && ((*p != ';' && *p != '#') || isstring); p++)
    {
        if (*p == '"')
        {
            if (*(p + 1) == '"')
            {
                p++;
            }
            else
            {
                isstring = !isstring;
            }
        }
        else if (*p == '\\' && *(p + 1) == '"')
        {
            p++;
        }
    }

    *p = '\0';
    striptail(string);
    if (*string == '"' && (p = strchr(string, '\0')) != NULL && *(p - 1) == '"')
    {
        string++;
        *--p = '\0';
    }

    return string;
}

static HI_S32 getstring(FILE **fp, const HI_CHAR *section, const HI_CHAR *key, HI_CHAR *buffer, HI_S32 size)
{
    HI_CHAR *start, *end;
    HI_S32 len;
    HI_CHAR buf[HI_INI_BUFSIZE];


    len = (section != NULL) ? strlen(section) : 0;

    if (len > 0)
    {
        do
        {
            if (!HIADP_INI_Read(buf, HI_INI_BUFSIZE, fp))
            {
                return 0;
            }
            start = skiphead(buf);
            end = strchr(start, ']');
        } while (*start != '[' || end == NULL || ((HI_S32)(end-start-1) != len || strncasecmp(start+1,section,len) != 0));
    }

    len = (key != NULL) ? (HI_S32)strlen(key) : 0;
    do
    {
        if (!HIADP_INI_Read(buf,HI_INI_BUFSIZE,fp) || *(start = skiphead(buf)) == '[')
        {
            return 0;
        }
        start = skiphead(buf);
        end = strchr(start, '=');
        if (end == NULL)
        {
            end = strchr(start, ':');
        }
    } while (*start == ';' || *start == '#' || end == NULL || ((HI_S32)(skiptail(end,start)-start) != len || strncasecmp(start,key,len) != 0));

    start = skiphead(end + 1);
    start = cleanstring(start);
    copystring(buffer, start, size);

    return 1;
}

HI_S32 HIADP_INI_Gets(const HI_CHAR *section, const HI_CHAR *key, const HI_CHAR *default_value,
             HI_CHAR *buffer, HI_S32 size, const HI_CHAR *file)
{
    FILE *fp;
    HI_S32 Ret = 0;

    if (buffer == NULL || size <= 0 || key == NULL)
    {
        return 0;
    }

    if (HIADP_INI_OpenRead(file, &fp))
    {
        Ret = getstring(&fp, section, key, buffer, size);
        (void)HIADP_INI_Close(&fp);
    }
    else if (HIADP_INI_OpenRead(basename(file), &fp))
    {
        Ret = getstring(&fp, section, key, buffer, size);
        (void)HIADP_INI_Close(&fp);
    }
    else
    {
        printf("open file:%s or %s failed!\n",file,basename(file));
        return HI_FAILURE;
    }

    if (!Ret)
    {
        copystring(buffer, default_value, size);
    }

    return strlen(buffer);
}

long HIADP_INI_Getl(const HI_CHAR *section, const HI_CHAR *key, long default_value, const HI_CHAR *file)
{
    HI_CHAR buf[64];

    HI_S32 len = HIADP_INI_Gets(section, key, "", buf, sizeof(buf)/sizeof(buf[0]), file);
    return (len == 0) ? default_value
                    : ((len >= 2 && toupper(buf[1]) == 'X') ? strtol(buf, NULL, 16)
                                                            : strtol(buf, NULL, 10));
}

float HIADP_INI_Getf(const HI_CHAR *section, const HI_CHAR *key, float default_value, const HI_CHAR *file)
{
    HI_CHAR buf[64];

    HI_S32 len = HIADP_INI_Gets(section, key, "", buf, sizeof(buf)/sizeof(buf[0]), file);
    return (len == 0) ? default_value : HIADP_INI_Atof(buf);
}

HI_BOOL HIADP_INI_Getbool(const HI_CHAR *section, const HI_CHAR *key, HI_BOOL default_value, const HI_CHAR *file)
{
    HI_CHAR buf[2];
    HI_S32 Ret;

    HIADP_INI_Gets(section, key, "", buf, sizeof(buf)/sizeof(buf[0]), file);

    buf[0] = (HI_CHAR)toupper(buf[0]);

    if (buf[0] == 'Y' || buf[0] == '1' || buf[0] == 'T')
    {
        Ret = HI_TRUE;
    }
    else if (buf[0] == 'N' || buf[0] == '0' || buf[0] == 'F')
    {
        Ret = HI_FALSE;
    }
    else
    {
        Ret = default_value;
    }

    return(Ret);
}

