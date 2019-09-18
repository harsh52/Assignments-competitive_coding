#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

/*

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



int mypipfd[2];
pid_t pid;
char buffer[200];
int input;

//oid interrupt_fun(int mypipfd[],int pid,char buffer[],int input)
void interrupt_fun()
{	
	pid=fork();

	if(pid == 0)
	{
		//Child Process
	int t1=0,t2=0,t3=1,child_pid;

	close(mypipfd[0]); //Close reading mode
	
	child_pid=getpid();
	sprintf(buffer,"%d",child_pid);
	write(mypipfd[1],buffer,sizeof(buffer)+1);
	printf("\nChild Send the PID\n");

	//Fibonacci series
	for(int i=0; i <= input;i++)
		{
		t1 = t2;
		t2 = t3;
		t3 = t1 + t2;
		sprintf(buffer,"%d",t3);

		write(mypipfd[1],buffer,sizeof(buffer)+1);
		printf("\nchild write: %d\n",t3);
		sleep(3);
		}
	
	}
	else
	{
		//Parent Process
		int t3;
		close(mypipfd[1]);
		read(mypipfd[0],buffer,sizeof(buffer)+1);
		sscanf(buffer,"%d",&t3);
		printf("Parent Received Child Process Id: %d",t3);
		for(int j = 0; j<= input;j++)
		{
			read(mypipfd[0],buffer,sizeof(buffer)+1);
			sscanf(buffer,"%d",&t3);
			printf("\nParent Read%d\n",t3 );
		}
	}
}
int main()
{

	int ret,a=1;
	char buffer[200];
	ret = pipe(mypipfd);
	if(ret == -1)
	{
		perror("\n[-]Pipe Error\n");
		exit(1);
	}
	printf("\nEnter number to generate fibonacci series:");
	scanf("%d",&input);
	

	while(1)
	{
		printf("\nWaiting for interrupt signal :)\n");
		//scanf("%d",ret);
		

		signal(SIGINT,interrupt_fun);
		a = SIGINT;
		if(a!=2)
			break;
		sleep(2);
	}
	return 0;
}
