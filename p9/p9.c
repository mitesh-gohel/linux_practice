//Check : What happen if we join 2nd time
#include<stdio.h>
#include<pthread.h>


void *my_thread(void *arg)
{
	int i=0;
	for(i=0; i<5; ++i)
	{
		printf("%d\n", i+1);
		sleep(1);
	}
	return NULL;
}
int main()
{
	int ret=0;
	pthread_t tid;
	pthread_create(&tid, NULL, my_thread, NULL);
	ret = pthread_join(tid, NULL);
	if(ret != 0)
		printf("1st pthread_join failed\n");
	ret = pthread_join(tid, NULL);
	if(ret != 0)
		printf("2nd pthread_join failed\n");

	return 0;
}

/*
It will fail
*/
