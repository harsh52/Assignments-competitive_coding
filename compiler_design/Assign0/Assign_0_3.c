#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dto(int decimal)
{
	int octnum=0,i=1;
	while(decimal!=0)
	{
		octnum+= (decimal % 8) * i;
		decimal /= 8;
		i *= 10;
	}
	return octnum;
}
int main()
{
	FILE *fp  = fopen("file3.txt","r");
	int buff[3],file_name[10];
	int decimal,octnum;
	int k=0;
	printf("\nEnter file name\n");
	gets(file_name);
	fgets(buff,3,fp);
	for(int i=0;i<3;i++)
	{
		decimal = k*10+buff[i];
	}

	octnum = dto(decimal);
	printf("\noct:%d\n",octnum);
}
