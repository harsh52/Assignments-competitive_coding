#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
int i;
char input[35],output[35];
printf("Enter:");
scanf("%s",input);
for (i = 0; input[i] != 0; i++)
	{
    output[i] = input[i] - '0';
	}
for(int j=0;j<i;j++)
{
	printf("\n%d\n",output[j]);
}
	return 0;
}