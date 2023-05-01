#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main()
{
	char buf[50] = {0};
	int fd = 0;
	mkfifo("f1", 0644);
	perror("mkfifo");
	printf("before : pid = %d \n", getpid());
	fd = open("f1", O_WRONLY);			//Opening  a  FIFO  for reading normally blocks until some other process opens the same FIFO for writing, and vice versa
	printf("after : pid = %d \n", getpid());
	while(1)
	{
		printf("Process A : ");
		gets(buf);
		write(fd, buf, strlen(buf) + 1);
		if(strcmp(buf, "bye") == 0)
		{
			printf("Bye Bye by Process A \n");
			break;
		}
	}
	return 0;
}
