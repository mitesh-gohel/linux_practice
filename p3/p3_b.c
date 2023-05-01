//fork using wait()
#include<stdio.h>
#include<unistd.h>	//for sleep()
#include<sys/wait.h>	//for wait()

int main()
{
	int id = fork();
	if(id < 0)
	{
		perror("fork failed");
	}
	else if(id ==0)
	{
		printf("child \n");
		printf("sleeping ...\n");
		sleep(15);
		printf("sleeping over \n");
	}
	else
	{
		int status = 0;
		printf("Parent \n");
		printf("pid of child = %d \n", id);
		printf("waiting ... \n");
		wait(&status);
		printf("child completed with exit status = %d \n", status);
	}
	return 0;
}
