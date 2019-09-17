#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>

/*
Assignment 3
Problem for the Lab
Write  a  C  program  to  handle  the  
reception  of  INTERRUPT  FROM  THE  
KEYBOARD  signal  by  executing  a  particul
ar  (user)  function,  which  function  is  
responsible  for  crea
ting  a  child  process  by  
using  fork()  system  call.  Also,  the  child  
process will take an input N (N is the no. of terms to generate the Fibonacci series) 
from  the  user  and  generate  the  Fibonacci  series  up  to  N  terms.  Then  the  child  
process  will  send  the  Fibonacci  series  terms  one  by  one  to  the  parent  process  by  
using pipe() system call and the parent pr
ocess will read the Fibonacci series terms 
one by one and will display it. 
*/

int main()
{
	pid_t pid;
	int mypipfd[2];
	int ret;
	int buffer[200];
	int input;

	ret = pipe(mypipfd);
	if(ret == -1)
	{
		perror("\n[-]Pipe Error\n");
		exit(1);
	}
	pid=fork();
	if(pid == 0)
	{
		//Child Process
		printf("\nEnter number to generate fibonacci series:");
		scanf("%d",&input);

	int t1=0,t2=0,t3=1;
	for(int i=0; i <= input;i++)
	{
		t1 = t2;
		t2 = t3;
		t3 = t1 + t2;
		//printf("\n%d\n",t3);
		buffer[i] = t3;
		close(mypipfd[0]);
		write(mypipfd[1],buffer,sizeof(buffer));
	}
	for(int j = 0;j<=input;j++)
	{
	printf("\nvfjb%d\n",buffer[j]);
	}
		
	}
	else
	{
		//Parent Process
		close(mypipfd[1]);
		read(mypipfd[0],buffer,10);
		for(int i=0;i<=input;i++)
		{
			
			printf("\n%d\n",buffer[i]);
		}
		//wait(NULL);
	}
	return 0;
}