//pipe()
#include<stdio.h>
#include<unistd.h>	//for fork()
#include<string.h> 

int main()
{
	int pipe_fd[2];
	//pipe_fd[0] is always fd of read
	//pipe_fd[1] is always fd of write
	int id;
	char buf[50] = {0};
	if(pipe(pipe_fd) < 0)
	{
		perror("pipe() failed \n");
	}
	id = fork();
	if(id < 0)
	{
		perror("fork failed \n");
	}
	else if(id == 0)
	{
		printf("Child \n");
		while(1)
		{
			read(pipe_fd[0], buf, 50);
			printf("Child received : \"%s\" \n",buf);
			if(strcmp(buf, "bye") == 0)
			{
				printf("Child : Bye Bye ... \n ");
				break;
			}
			 
		}
	}
	else
	{
		printf("Parent \n");
		while(1)
		{
			printf("Enter message : ");
			gets(buf);
			write(pipe_fd[1], buf, strlen(buf) + 1);
			if(strcmp(buf, "bye") == 0)
			{
				printf("Parent : Bye Bye ... \n ");
				break;
			}
		}
	}
	return 0;
}
