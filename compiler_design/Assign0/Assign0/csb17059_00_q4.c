/*
Write a C program that works like the od program of LINUX (UNIX). 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        FILE *fp;
        fp=fopen("prob.txt","r");
        char array[100];
        int i,k=0;
        printf("%08o ",k);
        while(!feof(fp))
        {
                fgets(array,50,fp);
                for(i=0;i<strlen(array);i++)
                {
                        printf("%03o ",array[i]);
                        k++;
                        if(k%16==0)
                        {
                                printf("\n%08o ",k);
                        }
                }
                strcpy(array,"");
        }
        printf("\n%08o\n",k);
        fclose(fp);
}

