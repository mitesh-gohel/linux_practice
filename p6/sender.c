//Message Queue
#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>

struct msg
{
	int mtype;
	char text[50];
};

int main(int argc, char **argv)
{
	int id = 0;
	struct msg v;
	if(argc != 3)
	{
		printf("usage : ./a.out type data \n");
		return 1;
	}
	id = msgget(5, IPC_CREAT|0644);
	perror("msgget");
	
	printf("id = %d \n", id);
	v.mtype = atoi(argv[1]);
	strcpy(v.text, argv[2]);
	msgsnd(id, &v, sizeof(v.text) + 1, 0);
	perror("msgsnd");
	return 0;	
}

