#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *fun1(void *shared)
{
	printf("fun1 %d \n", pthread_self());
	sleep(5);
	printf("Thread end \n");
	pthread_exit("Bye fun1\n");
}

int main()
{
	pthread_t tid1, tid2;
	int a = 1;
	char *p = NULL, *q = NULL;
	pthread_create(&tid1, NULL, fun1, &a);
	printf("tid1 = %u \n", &tid1);
	pthread_create(&tid2, NULL, fun1, &a);
	printf("tid2 = %u \n", &tid2);

	pthread_join(tid1, &p);	//if we do not call this function, then it will not wait thread to be completed		So in  thread "Thread end " will nit be executed"
	pthread_join(tid2, &q);
	printf("return by thread 1 : %s \n",p);
	printf("return by thread 2 : %s \n",q);
	printf("End \n");
	return 0;
}

/*
command : gcc p1.c -pthread
*/
