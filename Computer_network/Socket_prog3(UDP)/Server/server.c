#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
int main(int argc, char *argv)
{
	int port = 5000;
	int sockfd;
	struct sockaddr_in si_me, si_other;
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
	memset(&si_me,'0',sizeof(si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(port);
	si_me.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd,(struct sockaddr*)&si_me,sizeof(si_me));
	addr_size = sizeof(si_other);
	while(1)
	{
		recvfrom(sockfd,buffer,1024,0,(struct sockaddr*)&si_other,&addr_size);
		//memset(buffer,0,sizeof(buffer));
		printf("\nRECEIVED: %s\n",buffer);
		memset(buffer,0,sizeof(buffer));
		printf("\nSEND:");
		scanf("%s",buffer);
		sendto(sockfd,buffer,1024,0,(struct sockaddr*)&si_other,sizeof(si_other));

		memset(buffer,0,sizeof(buffer));
	}
}
