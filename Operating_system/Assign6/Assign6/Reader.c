#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHSIZE 100
int main(int argc, char *argv[])
{
	int shmid;
	key_t key;
	char *shm;
	char *s;
	key = 9876;
	shmid = shmget(key,SHSIZE,0666);
	if(shmid<0)
	{
		perror("[-]SHMGET error");
		exit(1);
	}
	shm = shmat(shmid ,NULL ,0);
	if(shm == (char *)-1)
	{
		perror("\n[-]SHM error\n");
		exit(1);
	}
	for(s = shm; *s != 0; s++)
		printf("%c",*s);
	printf("\n");
	*shm = '*';
	return 0;
}