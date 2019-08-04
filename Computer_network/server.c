#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>

int main(int argc, char *argv[])
{
	//variable
	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;

	//creating socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock<0)
	{
		perror("[-]Socket connection failed");
		exit(1);
	}
	else
	{
		printf("[+]Socket Established.");
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);

	//Creating Bind
	if(bind(sock, (struct sockaddr*)&server, sizeof(server)))
	{
		perror("[-]Bind Failed");
		exit(1);
	}
	else
	{
		printf("[+]Bind Established");
	}

	//Listen
	listen(sock,10);

	//Accept
	do
	{
		mysock = accept(sock, (struct sockaddr*)0, 0);
		if(mysock==-1)
		{
			perror("Accept Failed");
		}
		else
		{
			memset(buff,0,sizeof(buff));
		}
		if((rval = recv(mysock,buff,sizeof(buff),0))<0)
			perror("Error");
		else if(rval==0)
		{
			printf("Ending connection");
		}
		else
		{
			printf("MSG %s \n",buff);
		}
		close(mysock);
	}while(1);

	return 0;
}