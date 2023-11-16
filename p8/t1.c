//Simple program of signal()

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void handler(int signum)
{
	printf("Signal number = %d\n", signum);
}

int main()
{
	printf("pid = %d\n", getpid());
	signal(SIGINT, handler);
	while(1);
	return 0;
}
