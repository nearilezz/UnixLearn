#include <stdio.h>
#include <fcntl.h>
#include <wchar.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "public.h"

#ifndef __LEARN_H__
#define __LEARN_H__

U32 Learn_Main(void);
BOOL Learn_GetFl(int fd);
BOOL Learn_IO_main(void);
BOOL Learn_IO_Fwide(void);

#endif 