#include<string.h>
#include<ctype.h>
#include<stdio.h>


//Write the lexical analyser in C without using a tool such as flex. 
void keyboard(char str[10])
{
	if(strcmp("for",str)==0 || strcmp("while",str)==0 || strcmp("do",str) || strcmp("int",str) || strcmp("float",str) || strcmp("char",str) || strcmp("double",str) || strcmp("static",str) || strcmp("switch",str) || strcmp("case",str))
		{
			printf("\n%s is a keyboard",str);
		}
	else
	{
		printf("\n%s is a indentifier");
	}
	
}

int main()
{
	FILE *f1,*f2,*f3;
	char c,str[10],str1[10];
	int num[100],lineno = 0,tokenvalue=0,i=0,j=0,k=0;
	printf("\n Enter C program");
	f1 = fopen("input","w");
	while((c=getchar()) != EOF)
	{
		putc(c,f1);
	}
	fclose(f1);
	f1 = fopen("input","r");
	f2 = fopen("indentifier","w");
	f3 = fopen("specialchar","w");
	while((c=getc(f1))!=EOF)
	{
		if(isdigit(c))
		{
			tokenvalue = c - '0';
			c = getc(f1);
			while(isdigit(0))
			{
				tokenvalue *= 10+c-'0';
				c = getc(f1);
			}
			num[i++] = tokenvalue;
			ungetc(c,f1);
		}
		else if(isalpha(c))
		{
			putc(c,f2);
			c = getc(f1);
			while(isdigit(c)||isalpha(c)||c==' '|| c== '$')
			{
				putc(c,f2);
				c = getc(f1);
			}
			putc(' ',f2);
			ungetc(c,f1);
		}
		else if(c == ' ' || c=='\t')
		{
			printf(" ");
		}
		else if(c=='\n')
		{
			lineno++;
		}
		else
		{
			putc(c,f3);
		}
	}
	fclose(f2);
	fclose(f3);
	fclose(f1);
	printf("\nThe no is the program are");
	for(j=0;j<i;j++)
	{
		printf("%d",num[j]);
	}
	printf("\n");
	f2 = fopen("indentifier","r");
	k=0;
	printf("The keyword and identifier are");
	while((c=getc(f2))!=EOF)
	{
		if(c!=' ')
		{
			str[k++]=c;
		}
		else
		{
			str[k] = '\0';
		
			keyboard(str);
			k=0;
		}
	}
	fclose(f2);
	f3 = fopen("specialchar","r");
	printf("\nspecial character are");
	while((c=getc(f3))!=EOF)
	{
		printf("%c",c);
	}
	printf("\n");
	fclose(f3);
	printf("Total no of lines are %d",lineno);

}