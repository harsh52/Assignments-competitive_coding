
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




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        FILE *fp=fopen("file2.txt","r");
        int count=0,field,i;
        char text[100];
        printf("Enter field number: ");
        scanf("%d",&field);
        while(!feof(fp))
        {
                fgets(text,50,fp);
                if(text[0]!=' ' && text[0]!='\n')
                {
                        count=1;
                        for(i=0;text[i]!='\0';i++)
                        {
                                if(text[i]==' ')
                                {
                                        count++;
                                        i++;
                                }
                                if(count==field)
                                {
                                        printf("%c",text[i]);
                                }
                        }
                }

                else if(text[0]==' ')
                {
                        i=0;
                        while(text[i]==' ')
                        {
                                i++;
                        }
 count=1;
                        while(text[i]!='\0')
                        {
                                if(text[i]==' ')
                                {
                                        count++;
                                        i++;
                                }
                                if(count==field)
                                {
                                        printf("%c",text[i]);
                                }
                                i++;
                        }
                }
                else if(text[0]=='\n')
                {
                        printf("(NULL)");
                }
        printf("\n");
        strcpy(text,"");
        }
        fclose(fp);

}


