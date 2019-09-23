#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<pthread.h>

/*
gcc Assign2_c.c -lpthread

Write a C program to create a user level thread using system call pthread_create( ) and assign the thread to display the “HELLO WORLD” . Use pthread_exit() in your program (if possible) for terminating the thread. 
 You need to put explanatory comment in your program to demonstrate the purpose and why you have used the system calls */

void *myfun(void *i)
{
	printf("HELLO WORLD\n");
	//pthread_exit(NULL);
	return NULL;

}
int main()
{
	pthread_t thread_id;
	//int thread_id;
	pthread_create(&thread_id,NULL,myfun,NULL);
	pthread_join(thread_id,NULL);
	//exit(0);
}
