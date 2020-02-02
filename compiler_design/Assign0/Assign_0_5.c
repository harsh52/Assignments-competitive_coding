#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
	int i=0;
	char buff[60]="";

	FILE *fp  = fopen("Assign_0_3","r");
	if(fp == NULL)
	{
		printf("\nCould not open file\n");
		return 0;
	}

	while(1)
	{
		if(feof(fp))
		{
			break;
		}
		char c = fgetc(fp);
		if(65<(int)c<90 || 97<(int)c<122 )
		{
			buff[i]=c;
			i++;
		}
		else
		{
			//memset(buff,0,sizeof(buff));
			buff[60] = "";
			i=0;
		}
		if(strlen(buff)>=5)
		{
			printf("%s\n",buff);
			buff[60] = "";
			i=0;
		}
	}
}