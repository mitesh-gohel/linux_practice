#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	int a[3] = {0};
	printf("%d \n", a[0]);
	if((a[0] = fork()) == 0)
	{
		printf("Child : %d\n", a[0]);
	}
	else
	{
		printf("Parent : %d\n", a[0]);
	}
	while(1);
	return 0;
}

