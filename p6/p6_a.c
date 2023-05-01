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
	
	printf("Process A : ");
	gets(v.text);
	printf("message : %s \n", v.text);
	v.mtype = 1;
	msgsnd(id, &v, strlen(v.text) + 1, 0);
	perror("msgsnd");
	return 0;	
}

