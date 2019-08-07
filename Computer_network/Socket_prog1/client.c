#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
//#define DATA "Hello There"

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	struct hostent *hp;
	char line[100];
	char buff[1024];
	char* DATA[100];
	int i = 0;
	sock = socket(AF_INET,SOCK_STREAM,0);
	FILE *fp;
	fp = fopen("msg.txt","r");

	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		
		DATA[i] = line;
		i++;
		//printf("%s",&DATA[i]);
	}
	
	if(sock<0)
	{
		perror("Socket Failed");
		exit(1);
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if(hp==0)
	{
		perror("[-]gethostbyname Failed");
		close(sock);
		exit(1);
	}
	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port=htons(5000);
	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0)
	{
		perror("[-]Connection Failed");
		close(sock);
		exit(1);
	}
	printf("%s",DATA[0]);
	if(send(sock,DATA[1],sizeof(DATA),0)<0)
	{
	perror("[-]Send Failed");
	close(sock);
	exit(1);
	}
	printf("send %s \n",DATA[0]);
	close(sock);
	return 0;
}
