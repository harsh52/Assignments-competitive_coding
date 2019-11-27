#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<unistd.h>

//#define key 0x1111
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

struct sembuf p = {0,-1,SEM_UNDO};
struct sembuf v = {0,+1,SEM_UNDO};

int main()
{
//	int id = semget(key,1,0666|IPC_CREAT);
	int id = 0;
	char filename[20],c;
	FILE *fp = fopen("program.txt","r");
	c = fgetc(fp);
	if(id<0)
	{
		perror("semget error");
		exit(1);
	}
	union semun u;
	u.val = 1;
	if((semctl(id,0,SETVAL,u))<0)
	{
		perror("semctl error");
		exit(1);
	}
	if((semop(id,&p,1))<0)
	{
		perror("semop error");
		exit(1);
	}
	while(c!=EOF)
	{
		printf("%c",c);
		c = fgetc(fp);
		sleep(1);
	}
	if((semop(id,&v,1))<0)
	{
		perror("SEmopm 2 error");
		exit(1);
	}
	return 0 ;
}