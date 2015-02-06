#include <stdio.h>
#include <fcntl.h>
#include <sys/type.h>
#include <sys/stat.h>

int main(void)
{
	int fd = 0;
	if ( (fd = open("test.txt", 0_RDWR)) < 0 )
	{
	    printf("open file fail!\n");
	    return 0;
	}

	return 0;
}