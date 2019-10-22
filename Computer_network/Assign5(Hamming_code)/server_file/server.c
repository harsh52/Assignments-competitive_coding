#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include <math.h>

int input[32];
int code[32];
int ham_calc(int,int);
//int reverse()


int ham_calc(int position,int c_l)
{
	int count=0,i,j;
	i=position-1;
	while(i<c_l)
	{
		for(j=i;j<i+position;j++)
		{
			if(code[j] == 1)
				count++;
		}
		i=i+2*position;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}



int child_process(int mysock)
	{
		int l;
		char DATA2[20];
		char ch;
		int c_l=12,p_n=4;
		while(1)
		{
			recv(mysock,DATA2,sizeof(DATA2),0);
			//printf("\nsizeofdata: %d\n",DATA);
			printf("\nReceived: %s\n",DATA2);
			//memset(DATA,0,sizeof(DATA));
			/*l = strlen(DATA2);
			//printf("sizeof:%d",l);
			for(i=0;i<l/2;i++)
			{
				ch = DATA2[i];
				DATA2[i] = DATA2[l-1-i];
				DATA2[l-1-i] = ch;

			}
			printf("\nSend: %s",DATA2);
			//scanf("%s",DATA);
			send(mysock,DATA2,strlen(DATA2),0);*/

			//Char to int

			int i;
			//int output[35];
		for(i = 0; DATA2[i] != 0; i++)
			{
    		code[i] = DATA2[i] - '0';
			}


			//////////////////////////////////

			int error_pos = 0;
			for(i=0;i<p_n;i++)
			{
				int position = (int)pow(2,i);
				int value = ham_calc(position,c_l);
				if(value != 0)
					error_pos+=position;
			}
			if(error_pos == 0)
				printf("The received Code Word is correct.\n");
			else
			{
				printf("Error at bit position: %d\n",error_pos);
				if(code[error_pos-1]==0)
				{
					code[error_pos-1]=1;
				}
				else
				{
					code[error_pos-1]=0;
				}



			}
			int p=0;
			for(i=0;i<c_l;i++)
			{
				if(i==0 || i==1 || i==3|| i==7)
				{
					continue;
				}
				else
				{
					input[p] =  code[i];
					p++;
				}
			}

			//Print Correct bit
			printf("Correct Bit:");
			for(i=0;i<8;i++)
			{
				printf("%d",input[i]);
			}
			/////////////////////////////////
			
			memset(DATA2,0,sizeof(DATA2));

		}
	}

int main()
{
	int sock,child;
	struct sockaddr_in server;
	int mysock;
	//char DATA[60];
	int rval;
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("\n[-]Socket connection failed\n");
		exit(1);
	}
	else
	{
		perror("\n[+]Socket Established\n");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);

	if(bind(sock, (struct sockaddr*)&server, sizeof(server)))
	{
		perror("\n[-]Bind Failed\n");
		exit(1);
	}
	else
	{
		printf("\n[+]Bind Established\n");
	}

	//listen
	listen(sock,10);
	do
	{
		mysock = accept(sock,(struct sockadd*)0,0);

		if((child=fork())==0)
		{
			close(sock);
			//size = sizeof(DATA);
			child_process(mysock);
		}

	}while(1);
	return 0;
}
