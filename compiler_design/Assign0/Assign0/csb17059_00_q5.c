

/*
Write a C program that works like the strings program of LINUX (UNIX).
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
        char file[20];
        FILE *fp;
        printf("Enter the filename\n");
        scanf("%s",file);
        fp=fopen("stri.txt","r");
        char ch;
        ch=fgetc(fp);
        while(ch!=EOF)
        {
                if(ch>=32 && ch<=255)
                printf("%c",ch);
                ch=fgetc(fp);
        }
        fclose(fp);

}

