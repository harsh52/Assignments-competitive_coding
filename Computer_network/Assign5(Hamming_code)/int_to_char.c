#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
int i;
int input[35];
char output[35];
memset(output,0,sizeof(output));
memset(input,0,sizeof(input));
printf("Enter:");
for(int j=0;j<12;j++)
{
	scanf("%d",&input[j]);
}
for (i = 0; i< 12; i++)
	{
    output[i] = input[i] + '0';
	}


	printf("\n%s\n",output);

	return 0;
}
