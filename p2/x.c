#include<stdio.h>
#include<unistd.h>

int main()
{
	for(char ch = 'a'; ch <= 'z'; ++ch)
	{
		printf("%c \n", ch);
		sleep(1);
	}
	return 0;
}
