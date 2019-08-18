#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>

/*Write a C program which will take the Process ID and signal ID as input to
demonstrate the use of kill( ) system call.*/

int main()
{
	int pid,status;
	printf("\nPID is: %d\n",getpid());

	printf("Enter PID to kill");
	scanf("%d",&pid);
	status=kill(pid,SIGKILL);
	if(status == 0){
	printf("\nKILLED\n");
	}
	else
	{
		printf("\nSomething Wrong\n");
	}
}