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
		printf("Fcntl GETFL fail!\n");
		return false;
	}

	switch (val & O_ACCMODE){
		case O_RDONLY:
			printf("Read only");
			break;
		case O_WRONLY:
			printf("Write only");
			break;
		case O_RDWR:
			printf("Read and Write");
			break;
		default:
			printf("error code");
	}

	if (val & O_APPEND){
		printf(", append");
	}

	printf("\n");

	return true;
}