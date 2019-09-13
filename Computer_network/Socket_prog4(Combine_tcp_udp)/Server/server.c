#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<errno.h>
#include<sys/select.h>
#include<sys/time.h>

int max(int tcp_socket,int sockfd)
{
	if(tcp_socket > sockfd)
	{
		return tcp_socket;
	}
	else
	{
		return sockfd;
	}
}


int child_process(int mysock)
	{
		int l,i;
		char DATA2[20];
		char ch;
		while(1)
		{
			recv(mysock,DATA2,sizeof(DATA2),0);
			//printf("\nsizeofdata: %d\n",DATA);
			printf("\nTCP_Received: %s\n",DATA2);
			//memset(DATA,0,sizeof(DATA));
			l = strlen(DATA2);
			//printf("sizeof:%d",l);
			for(i=0;i<l/2;i++)
			{
				ch = DATA2[i];
				DATA2[i] = DATA2[l-1-i];
				DATA2[l-1-i] = ch;

			}
			printf("\nTCP_Send: %s",DATA2);
			//scanf("%s",DATA);
			send(mysock,DATA2,strlen(DATA2),0);

			memset(DATA2,0,sizeof(DATA2));

		}
	}


int main()
{
	int tcp_socket,child;
	struct sockaddr_in server;
	int mysock,nready;
	int rval;
	fd_set rset;
	int port = 5000;
	int maxfdp1;
	//int addr_size;

	//Creating tcp 
	tcp_socket = socket(AF_INET,SOCK_STREAM,0);
	if(tcp_socket<0)
	{
		perror("\n[-]TCP_Socket Connection Failed\n");
		exit(1);
	}
	else
	{
		perror("\n[+]TCP_Socket Established\n");
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);
	if(bind(tcp_socket,(struct sockaddr*)&server,sizeof(server)))
	{
		perror("\n[-]TCP_Bind Failed\n");
		exit(1);
	}
	else
	{
		perror("\n[+]TCP_Bind Established\n");
	}
	listen(tcp_socket,10);

	//------------------**********--------------------//

	//Creating UDP

	int sockfd,l,i;
	char ch;
	struct sockaddr_in si_me,si_other;
	char buffer[1024];
	socklen_t addr_size;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		perror("\n[-]UDP_Socket Connection Failed\n");
	}
	else
	{
		perror("\n[+]UDP_Socket Established\n");
	}
	memset(&si_me,0,sizeof(si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(port);
	si_me.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd,(struct sockaddr*)&si_me,sizeof(si_me));
	addr_size = sizeof(si_other);
	//-----------------------------------*****************************-----------------------//

	//Using Select

	FD_ZERO(&rset);
	maxfdp1 = max(tcp_socket,sockfd)+1;

	while(1)
	{
		FD_SET(tcp_socket,&rset);
		FD_SET(sockfd,&rset);
		if((nready = select(maxfdp1,&rset,NULL,NULL,NULL))<0)
		{
			if(errno == EINTR)
				continue;
		}
		if(FD_ISSET(tcp_socket,&rset))
		{
			//TCP
			//do
			//{
				mysock = accept(tcp_socket,(struct sockaddr*)0,0);

				if((child=fork())==0)
				{
					close(sockfd);
					child_process(mysock);
				}
			//}while(1);
		}
		else if(FD_ISSET(sockfd,&rset))
		{
			//UDP
			//while(1)
			//{
				recvfrom(sockfd,buffer,1024,0,(struct sockaddr*)&si_other,&addr_size);
				printf("\nUDP_RECEIVED: %s\n",buffer);


				l = strlen(buffer);
				//printf("sizeof:%d",l);
				for(i=0;i<l/2;i++)
				{
					ch = buffer[i];
					buffer[i] = buffer[l-1-i];
					buffer[l-1-i] = ch;
				}
				sendto(sockfd,buffer,1024,0,(struct sockaddr*)&si_other,sizeof(si_other));
				memset(buffer,0,sizeof(buffer));
			//}

		}
	}
	return 0;
}