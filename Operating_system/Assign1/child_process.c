#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

/*
Write a C program to create a child process using the system call fork( ). From the child process, display
the PID and PPID and then call again the fork( ) to create a grandchild and engage him to display your roll
no. From parent display the PID and PPID of all the processes and display the count of total no. of child
processes created.

----Second Part----
Write a C program like the assignment 1(a). But here use the system call wait() system to synchronize the
execution of parent program in your program until child process finishes.
*/
int main()
{
	int child1, grandchild, x=2;
	child1=fork();
	grandchild = fork();
	if(child1>0 && grandchild > 0)
	{
		printf("\nParent PID %d PPID %d\n",getpid(),getppid());
		wait(NULL);
		printf("\nChild has terminated\n");
	}
	else if(child1==0 && grandchild >0)
	{
		printf("\nFirst child PID %d\n",getpid());
	}
	else if(child1>0 && grandchild == 0)
	{
		printf("\ngrandchild PID %d\n",getpid());
		printf("\nROll no: CSB17059\n");
	}
	else
	{
		printf("\nThird Child PID %d\n",getpid());
	}
}
