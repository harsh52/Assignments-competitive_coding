
/*Write a C program that reads the names (as character strings of length upto 20 bytes) and corresponsing roll-numbers (as integers) of 10 students from the user and stores them in a file whose name is specified by the user-

    in text format
    in binary format 


After running the program check the size of the file created using ls -l command. Also see the content of the binary file using the command
od -c filename. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
        char rollnum[15];
        char Name[20];
};
int main()
{
        int i;
//      int n;
        char roll[10],name[10];
        char textfile[10],binfile[10];
//      char tempfile[10];
        printf("Enter Name of text file: ");
        scanf("%s",textfile);
        strcat(textfile,".txt");
        printf("Enter Name of the binary file: ");
        scanf("%s",binfile);
        strcat(binfile,".bin");
        FILE *fp1,*fp2;
        fp1=fopen(textfile,"w");
        fp2=fopen(binfile,"wb");

        char ch;
        struct student stu;

        printf("Binary Mode\n");
        printf("Enter name & Roll No of 10 students: ");
        for(i=0;i<10;i++)
        {
                printf("\n");
                printf("For student %d : \n",i+1);
                printf("Enter Name: ");
 scanf("%s",stu.Name);
                printf("Enter roll No of %s : \n",stu.Name);
                scanf("%s",stu.rollnum);
                fwrite(&stu,sizeof(stu),1,fp2);
        }
        printf("Text Mode ");
        for(i=0;i<10;i++)
        {
                printf("\n");
                printf("For student %d : \n",i+1);
                printf("Enter Name: ");
                scanf("%s",name);
                printf("Enter roll No of %s : \n",name);
                scanf("%s",roll);
                fprintf(fp1,"%s\t%s\n",name,roll);

        }


fclose(fp1);
fclose(fp2);
return 0;
for(i=0;i<10;i++)
        {
                printf("\n");
                printf("For student %d : \n",i+1);
                printf("Enter Name: ");
                scanf("%s",stu.Name);
                printf("Enter roll No of %s : \n",name);
                scanf("%s",stu.rollnum);
                fprintf(fp1,"%s\t%s\n",name,roll);
                fwrite(&stu,sizeof(stu),1,fp2);
        }
}


