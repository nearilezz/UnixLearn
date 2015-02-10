#include "learn.h"

U32 Learn_Main()
{
	int fd = 0;

	fd = open("main.c", O_WRONLY|O_APPEND);
	Learn_GetFl(0);
	Learn_GetFl(1);
	Learn_GetFl(2);
	Learn_GetFl(fd);
	return 0;
}

BOOL Learn_GetFl(int fd)
{
	int val = 0;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		Log_MSG("Fcntl GETFL fail!\n");
		return false;
	}

	switch (val & O_ACCMODE){
		case O_RDONLY:
			Log_MSG("Read only");
			break;
		case O_WRONLY:
			Log_MSG("Write only");
			break;
		case O_RDWR:
			Log_MSG("Read and Write");
			break;
		default:
			Log_MSG("error code");
	}

	if (val & O_APPEND){
		printf(", append");
	}

	printf("\n");

	return true;
}