//sigaction()

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void handler(int signum)
{
	printf("Signal number = %d\n", signum);
	sleep(5);
	printf("Exiting from signal handler\n");
}

int main()
{
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = handler;
	act.sa_flags = SA_NODEFER;
	printf("pid = %d\n", getpid());
	sigaction(SIGINT, &act, NULL);
	while(1)
	{
		printf("sleeping for 1 sec\n");
		sleep(1);
	}
	return 0;
}
