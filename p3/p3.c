//fork without wait()
#include<stdio.h>
#include<unistd.h>

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
		printf("Parent \n");
		printf("pid of child = %d \n", id);
	}
	return 0;
}
