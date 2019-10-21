#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<math.h>

int input[32];
int code[32];
int ham_calc(int,int);

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

int main(int argc, char *argv[])
{
	//variable
	int sock;
	struct sockaddr_in server;
	int mysock;
	char code[1024];
	int rval;
	//FILE *fp;
	//fp = fopen("msg.txt","w");

	int c_l=12,i,p_n=4;

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
			memset(code,0,sizeof(code));
		}
		if((rval = recv(mysock,code,sizeof(code),0))<0)
			perror("Error");
		else if(rval==0)
		{
			printf("Ending connection");
		}
		else
		{

			//////

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
		for(i=0;i<c_l;i++)
		{
			//printf("%d\n",code[i]);
		}


	}
	int p=0;
	for(i=0;i<c_l;i++)
	{
		if(i==0 || i==1 || i==3|| i==7)
		{
			/*for(int c = (int)pow(2,i)-1; c < c_l-1; c++)
			{
				//printf("bit delete%d\n",i );
				code[c] = code[c+1];

			}


			printf("i");
			for(int p=0;p<c_l-1;p++)
			{
				printf("%d",code[p]);
			}
			c_l--;
			printf("\n");
			*/
			//printf("break at%d",i);
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


			/////


			//printf("MSG %s \n",buff);
			//fprintf(fp,"%s",buff);
		}
		close(mysock);
		//fclose(fp);
	}while(1);

	return 0;
}
