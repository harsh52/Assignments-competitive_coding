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
	
	int data = 1;
	int *buf[10];
	FILE *fptr;
	fptr = fopen("./count_child.txt","w");
	if(fptr == NULL)
	{
		printf("\nUnable to open file\n");
		exit(1);
	}
	
	grandchild = fork();
	child1=fork();
	if(child1>0 && grandchild > 0)
	{
		printf("\nParent PID %d PPID %d\n",getpid(),getppid());
		fprintf(fptr,"%d",data);

		wait(NULL);
//
		FILE *fptr2;
		int* buf2[10];
		int i;
		int total_child = 0;
		fptr2 = fopen("./count_child.txt","r");
		//fscanf(fptr2,"%d",&i);
		//printf("\ndscd%d\n",i);
		while(!feof(fptr2))
		{
			fscanf(fptr2,"%d",&i);
			total_child = total_child + i;
			
		}
		printf("\ntotal child = %d\n",total_child);
//		
		printf("\nChild has terminated\n");
		
		
		
	}
	else if(child1==0 && grandchild >0)
	{
		fprintf(fptr,"%d\n",data);
		printf("\nFirst child PID %d\n",getpid());
	}
	else if(child1>0 && grandchild == 0)
	{
		char *buf;
		buf = (char *)malloc(10*sizeof(int));
		buf = getlogin();//Function to find whho is logged in into the system
		fprintf(fptr,"%d\n",data);
		printf("\ngrandchild PID %d\n",getpid());
		printf("\nROll no: CSB17059\n");
		printf("\n-- %s -- logged into the system\n",buf);
	}
	else
	{
		fprintf(fptr,"%d\n",data);
		printf("\nThird Child PID %d\n",getpid());
	}
}
