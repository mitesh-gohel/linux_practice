#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *fun1(void *shared)
{
	printf("fun1 %s \n", (char *)shared);
	sleep(15);
	pthread_exit("Bye");
}

int main()
{
	pthread_t tid1, tid2;
	int a = 1;
	char *p = NULL, *q = NULL;
	pthread_create(&tid1, NULL, fun1, "hello");
	printf("in main tid1 = %u \n", &tid1);
	//pthread_create(&tid2, NULL, fun1, &a);
	//printf("tid2 = %u \n", &tid2);
	printf("Before ... \n");
	pthread_join(tid1, &p);
	printf("After ... %s \n", p);

	printf("End \n");
	return 0;
}

/*
command : gcc p1.c -pthread
*/
