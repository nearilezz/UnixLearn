#include <stdio.h>

#ifndef __PUBLIC_H__
#define __PUBLIC_H__

typedef signed char S8;
typedef unsigned char U8;
typedef signed short S16;
typedef unsigned short U16;
typedef signed int S32;
typedef unsigned int U32;
typedef signed long long S64;
typedef unsigned long long U64;

typedef enum { false, true } BOOL;

#define Log_MSG(msg_id, fmt, arg ...)\
    printf("%-20s\t", __FUNCTION__);\
    printf(fmt, ##arg);

#endif