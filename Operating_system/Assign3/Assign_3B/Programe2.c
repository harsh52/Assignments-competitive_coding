#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main()
{
	int fd;
	char *FIFO = "/tmp/FIFO";
	mkfifo(FIFO,0777);
	char arr[100];
	while(1)
	{
		fd = open(FIFO,O_RDONLY);
		read(fd,arr,sizeof(arr)+1);
		printf("\nProgramme1:%s\n",arr);
		close(fd);
		memset(arr,0,sizeof(arr));
		fd = open(FIFO,O_WRONLY);
		printf("\nPrograme2_WRITE:");
		fgets(arr,sizeof(arr)+1,stdin);
		write(fd,arr,strlen(arr));
		close(fd);	
	}
	return 0;
}
