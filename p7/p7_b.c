#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	int ret_val_1 = 0, ret_val_2 = 0., ret_val_3 = 0;
	int sleep_sec  = 0;
	int child_pid = 0;
	ret_val_1 = fork();
	if (ret_val_1 == 0)
	{
		srand(getpid());
		sleep_sec = rand() % 10 + 1;
		printf("child 1 : sleep for %d sec\n", sleep_sec);
		sleep(sleep_sec);
	}
	else if (ret_val_1 > 0)
	{
		ret_val_2 = fork();
		if (ret_val_2 == 0)
		{
			srand(getpid());
			sleep_sec = rand() % 10 + 1;
			printf("child 2 : sleep for %d sec\n", sleep_sec);
			sleep(sleep_sec);
		}
		else if (ret_val_2 > 0)
		{
			ret_val_3 = fork();
			if (ret_val_3 == 0)
			{
				srand(getpid());
				sleep_sec = rand() % 10 + 1;
				printf("child 3 : sleep for %d sec\n", sleep_sec);
				sleep(sleep_sec);
			}
			else if (ret_val_3 > 0)
			{
				while((child_pid = wait(NULL)) != -1)
				{
					if (child_pid == ret_val_1)
						printf("1st child terminated\n");
					else if (child_pid == ret_val_2)
						printf("2nd child terminated\n");
					else if (child_pid == ret_val_3)
						printf("3rd child terminated\n");
				}
			}
			else
			{
				printf("fork() failed for 3rd child\n");
			}
		}
		else
		{
			printf("fork() failed for 2nd child\n");
		}
	}
	else
	{
		printf("fork() failed for 1st child\n");
	}
}
