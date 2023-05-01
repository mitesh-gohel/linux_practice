#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buf[50] = {0};
	int fd = 0;
	mkfifo("f1", 0644);
	perror("mkfifo");
	printf("before : pid = %d \n", getpid());
	fd = open("f1", O_RDONLY);			//Opening  a  FIFO  for reading normally blocks until some other process opens the same FIFO for writing, and vice versa
	printf("after : pid = %d \n", getpid());
	while(1)
	{
		read(fd, buf, 50);
		printf("Process B received : %s \n", buf);
	}
	return 0;
}
