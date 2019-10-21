#include <stdio.h>
#include <math.h>
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

int main()
{	
	int c_l=12,i,p_n=4;

	//printf("Please enter the received Code Word:\n");
	//for(i=0;i<c_l;i++)
	//	scanf("%d",&code[i]);

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


	return 0;
}