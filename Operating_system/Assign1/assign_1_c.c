/*Write a C program like the assignment 1(b) and overlay a user designed program into the address space of
the child process using execv() system call. Again use wait() system call to synchronize the execution of
parent process in your program until child process finishes. Here use the macro WIFEXITED to capture
the returned status of the child in parent process. Also demonstrate the use of argument vector to print the
program name by the child process.*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

	int child1, grandchild, x=2;
	
	int data = 1;
	grandchild = fork();
	child1=fork();
	if(child1>0 && grandchild > 0)
	{
		printf("\nParent PID %d PPID %d\n",getpid(),getppid());
		wait(NULL);		
		printf("\nChild has terminated\n");	
	}
	else if(child1==0 && grandchild >0)
	{
		printf("\nFirst child PID %d\n",getpid());
		printf("\nprogramme name by child process: %s\n",argv[0]);
		char *args[]={"./dummy",NULL};
		execv(args[0],args);
		
	}
	else if(child1>0 && grandchild == 0)
	{
		//fprintf(fptr,"%d\n",data);
		//printf("\ngrandchild PID %d\n",getpid());
		//printf("\nROll no: CSB17059\n");
	}
	else
	{
		//fprintf(fptr,"%d\n",data);
		//printf("\nThird Child PID %d\n",getpid());
	}
}