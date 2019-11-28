#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include<pthread.h>

void *myfun(void *i)
{
	printf("\nMe the thread with PID %d\n",getpid());
	return NULL;
}

void interrupt_fun2()
{
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,myfun,NULL);
	pthread_join(thread_id,NULL);
}


void interrupt_fun()
{
	int id;
	id = fork();
	if(id==0)
	{
		printf("\nMe the child with PID:%d\n",getpid());
		printf("\nWaiting For 2nd interrupt function\n");
		//signal(SIGINT,interrupt_fun2);
		//sleep(20);

	}
}


int main()
{
	printf("\nWaiting for interrupt\n");
	signal(SIGINT,interrupt_fun);
	sleep(2);
	signal(SIGINT,interrupt_fun2);
	sleep(2);
	return 0;
}