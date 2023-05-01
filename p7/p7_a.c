//Behaviour of wait() without child

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	int ret_val = 0;
	printf("Hello \n");
	ret_val = wait(NULL);  // We can use wait(0) also
	perror("Check result of wait() without child");
	printf("ret_val = %d\n", ret_val);
	return 0;
}

/*
========= Output =========
mitesh@mitesh-IdeaPad-3i:~/mitesh_workspace/linux/p7$ gcc p7_a.c -o p7_a
mitesh@mitesh-IdeaPad-3i:~/mitesh_workspace/linux/p7$ ./p7_a 
Hello 
Check result of wait() without child: No child processes
ret_val = -1
mitesh@mitesh-IdeaPad-3i:~/mitesh_workspace/linux/p7$
==========================

Conclusion :
Without child, if we use wait() then it fails and return -1
*/
