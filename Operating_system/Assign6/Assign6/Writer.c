#include<stdio.h>
#include<stdlib.h>
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
	shmid = shmget(key,SHSIZE,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("[-]SHMGET error");
		exit(1);
	}
	shm = shmat(shmid, NULL, 0);
	if(shm == (char *)-1)
	{
		perror("\n[-]SHM Error\n");
		exit(1);
	}
	memcpy(shm, "Hello_World",12);
	s = shm;
	s += 11;
	*s = 0;

	while(*shm != '*')
		sleep(1);
	return 0;
}
