//Message Queue
#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include<string.h>

struct msg
{
	int mtype;
	char text[50];
};

int main()
{
	int id = 0;
	struct msg v;
	id = msgget(33, IPC_CREAT|0644);
	perror("msgget");	
	msgrcv(id, &v, 50, 1, 0);
	perror("msgrcv");
	printf("Process B received : %s \n", v.text);
	return 0;	
}

