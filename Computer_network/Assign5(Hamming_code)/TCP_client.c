#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<math.h>
#include <time.h> 
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


int main(int argc,char* argv[])
{
	int sock,rval;
	char DATA[50];
	int n=8,i,p_n = 4,c_l,j,k;
	struct sockaddr_in server;
	struct hostent *hp;
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("\n[-]Socket connection failed\n");
		exit(1);//Unseccessfull exit
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port = htons(5000);
	if(connect(sock,(struct sockaddr*)&server,sizeof(server))<0)

	{
		perror("\n[-]connection failed\n");
		close(sock);
		exit(1);
	}
	while(1)
	{
		memset(DATA,0,sizeof(DATA));

		/*printf("\nSend Message:\n");
		scanf("%s",DATA);*/

		//////////////////////////////////////////////////////


		printf("Please enter the Data Word:\n");
			for(i=0;i<n;i++)
			{
				scanf("%d",&input[i]);
			}

			i=0;
			while(n>(int)pow(2,i)-(i+1))
			{
				p_n++;
				i++;
			}
		
			c_l = p_n + n;

			j=k=0;
			for(i=0;i<c_l;i++)
			{
		
				if(i==((int)pow(2,k)-1))
				{
					code[i]=0;
					k++;
				}
				else
				{
					code[i]=input[j];
					j++;
				}
			}
			for(i=0;i<p_n;i++)
			{
				int position = (int)pow(2,i);
				int value = ham_calc(position,c_l);
				code[position-1]=value;
			}
			printf("\nThe calculated Code Word is: ");
			for(i=0;i<c_l-4;i++)
				printf("%d",code[i]);
			printf("\n");

/////
			int lower = 0, upper = 10, count = 1; 
			int lower2 =0, upper2 = 12;
  
    		// Use current time as  
    		// seed for random generator 
    		srand(time(0));
    		for(int i=0;i<count;i++)
    		{
    			int num = (rand()%(upper-lower+1)) + lower;
    			printf("%d\n",num );
    			if(num == 1 || num ==2 || num ==3)
    			{
    				lower2 = 0, upper = 12, count = 1;
    				for(int j=0;j<count;j++)
    				{
    					int num2 = (rand()%(upper2-lower2+1)) + lower2;

    					if(code[num2]==0)
    					{
    						code[num2]=1;
    					}
    					else
    					{
    						code[num2] = 0;
    					}


    				}
    			}

   			 }
   		 printf("\n");
   		 //Int to char 
   		 int i;
				char output[35];
				memset(output,0,sizeof(output));
				for (i = 0; i< 12; i++)
					{
    				output[i] = code[i] + '0';
					}

    		

					printf("send:%s",output);




		/////////////////////////////////////////////////////


		if(send(sock,output,sizeof(output),0)<0)
		{
			perror("\n[-]Send Failed\n");
			close(sock);
			exit(1);
		}
		//printf("\nSend Message: %s\n",DATA);

		memset(output,0,sizeof(output));

		/*if(rval=recv(sock,DATA,sizeof(DATA),0)<0)
		{
			perror("\n[-]Error\n");
		}
		printf("\nReceived message: %s\n",DATA);*/

	}


}
