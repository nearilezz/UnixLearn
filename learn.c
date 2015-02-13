#include "learn.h"

U32 Learn_Main()
{
	int fd = 0;

	fd = open("main.c", O_WRONLY|O_APPEND);
	Learn_GetFl(0);
	Learn_GetFl(1);
	Learn_GetFl(2);
	Learn_GetFl(fd);

	Learn_IO_main();

	return OK;
}

BOOL Learn_GetFl(int fd)
{
	int val = 0;
	if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
		Log_MSG("Fcntl GETFL fail!\n");
		return false;
	}

	switch (val & O_ACCMODE) {
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

	if (val & O_APPEND) {
		printf(", append");
	}

	printf("\n");

	return true;
}

BOOL Learn_IO_main(void)
{
	Learn_IO_Fwide();
	return true;
}

BOOL Learn_IO_Fwide(void)
{
	FILE *pfile = NULL;
	int value = 0;

	if ( NULL == (pfile = fopen("learn.d", "wr"))) {
		Log_MSG("open learn.d.\n");
		return false;
	}

	value = fwide(pfile, 0);
	Log_MSG("fwide learn.d %s.\n", strerror(errno));
	if (value < 0) {
		Log_MSG("Single Character.\n");
	} else if (value > 0) {
		Log_MSG("Multi Character.\n");
	} else {
		Log_MSG("Won't Orientation.\n");
	}

	return true;
}