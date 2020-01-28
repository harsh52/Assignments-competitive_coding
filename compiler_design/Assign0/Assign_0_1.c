/*Write a C program that reads text from a file and prints on the terminal each input line, preceded by the line number. The output will look like -

    1     This is the first trial line in the file,
    2     and this is the second line. 

Try the problem once using fgetc() function and once using fgets() function for reading the input. Why is fread() not suitable for this purpose?

Do not ignore the value returned by the functions fgetc() and fgets(). After this exercise the you should be comfortable with the formatted input and output functions of C. */



#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=1;
	char buff[60];

	FILE *fp  = fopen("file.txt","r");
	if(fp == NULL)
	{
		printf("\nCould not open file\n");
		return 0;
	}
	printf("\n==== Using fgetc ====\n");
	printf("%d  ",i);
	while(1)
	{
		char c = fgetc(fp);
		if(c=='\n')
		{
			i++;
			printf("\n%d  ",i);
			continue;
		}
		if(feof(fp))
		{
			break;
		}
		printf("%c",c);
	}
	printf("\n==== Using fgets ====\n");

	i = 0;
	FILE *fp2  = fopen("file.txt","r");
	
	while(1)
	{
		if(feof(fp2))
		{
			break;
		}
		i++;
		printf("%d  ",i);
		fgets(buff,60,fp2);
		printf("%s",buff);

	} 

	return 0;
}