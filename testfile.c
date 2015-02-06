#include <stdio.h>
#include <fcntl.h>
//#include <type.h>
#include <sys/stat.h>

int main(void)
{
	int fd = 0;
	if ( (fd = open("test.txt", O_RDWR)) < 0 )
	{
	    printf("open file fail!\n");
	    return 0;
	}

	return 0;
}