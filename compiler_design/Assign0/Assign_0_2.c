/*Write a program that takes from the user the name of a file and a "field-number", and then reads that file and for each line in that file prints on the terminal word at position "field-number". For example if there are the following lines in the specified file -

    C is a programming language.
    lex produces a lexical analyser

          cc is a compiler 

and if the field-number specified is 4, then the output of the program is -

    programming
    lexical
    (NULL)
    compiler 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp = fopen("file2.txt","r");
	char* buff[100];
	int count = 0;
	while(1)
	{
		if(feof(fp))
		{
			break;
		}
		char c = fgetc(fp);
		if(c==" ")
		{
			count++;
			if(count==4)
			{
				fscanf(fp,"%s",buff);
				printf("\n%s\n",buff);
				count = 0;
			}
		}
	}
}