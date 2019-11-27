#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<string.h>
#include<sys/ipc.h>

#define key 0x1111
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

struct sembuf p = {0,-1,SEM_UNDO};
struct sembuf v = {0,+1,SEM_UNDO};

int main()
{
	//FILE *fp = fopen("program.txt","r");
	char filename[20],c;
	int id = semget(key,1, 0666 | IPC_CREAT);
	printf("id: %d\n",id);
	if(id<0)
	{
		perror("\nsemget error\n");
		exit(1);
	}
	union semun u;
	u.val = 1;
	if(semctl(id,0,SETVAL,u)<0)
	{
		perror("\nsemctl error\n");
		exit(1);
	}
	//Enter into critical section.
	if(semop(id,&p,1)<0)
	{
		perror("\nsemop error\n");
		exit(1);
	}
	FILE *fp = fopen("program.txt","r");
	c = fgetc(fp);
	while(c!=EOF)
	{
		printf("%c", c);
		c = fgetc(fp);
		sleep(2);
	}
	if(semop(id,&v,1)<0)
	{
		perror("\nsemop error 2\n");
		exit(1);
	}


	return 0;
}