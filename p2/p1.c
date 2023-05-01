//mutex


#include<stdio.h>
#include<unistd.h>	//fo sleep()
#include<pthread.h>

pthread_mutex_t m1, m2;
void *fun1(void *shared)
{
	int return_status = 0;
	for(char ch = 'A'; ch <= 'Z'; ++ch)
	{
		pthread_mutex_lock(&m1);
		printf("%c \t", ch);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m2);
	}
	pthread_exit(&return_status);
}

void *fun2(void *shared)
{
	int return_status = 1;
	for(char ch = 'a'; ch <= 'a'; ++ch)
	{
		pthread_mutex_lock(&m2);
		printf("%c \n", ch);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}
	pthread_exit(&return_status);
}

int main()
{
	pthread_t tid1, tid2;
	void *status_ptr1, *status_ptr2;
	pthread_mutex_init(&m1, NULL);
	pthread_mutex_init(&m2, NULL);
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//pthread_join(tid1, NULL);
	//pthread_join(tid1, NULL);
	pthread_join(tid1, &status_ptr1);
	printf("thread 1 return status = %d \n", *(int *)status_ptr1);
	pthread_join(tid2, &status_ptr2);
	printf("thread 2 return status = %d \n", *(int *)status_ptr2);
	printf("End \n");
	return 0;
}
