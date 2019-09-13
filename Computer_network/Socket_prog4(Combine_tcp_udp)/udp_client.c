#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
int main(int argc,char *argv)
{
	int port = 5000;
	int sockfd;
	struct sockaddr_in server_addr;
	char buffer[1024];
	socklen_t addr_size;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		printf("\n[-]Socket Connection Failed\n");
	}
	else
	{
		printf("\n[+]Socket Established\n");
	}
	memset(&server_addr,'0',sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	while(1)
	{
		memset(buffer,'0',sizeof(buffer));
		printf("\nSend:");
		scanf("%s",buffer);
		sendto(sockfd,buffer,1024,0,(struct sockaddr*)&server_addr,sizeof(server_addr));
		memset(buffer,'0',sizeof(buffer));
		addr_size = sizeof(server_addr);
		recvfrom(sockfd,buffer,1024,0,(struct sockaddr*)&server_addr,&addr_size);
		printf("\nRECEIVED: %s\n",buffer);
		memset(buffer,'0',sizeof(buffer));
	}

}