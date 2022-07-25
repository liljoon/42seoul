#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
	int fd = open("./test.txt", O_RDONLY);

	char *p;

	for(int i=0;i<10;i++)
	{
		p = get_next_line(fd);
		printf("%s",p);
	}



}
