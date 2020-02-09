%{
int count = 0;
%}
op [+-*\]
letter [a-zA-Z]
digit [0-9]
id {letter}*|({letter}{digit})+
notid ({digit}{letter})+
%%
[\t\n]+
("int")|("char")|("float")|("if") {printf("%s is a keyword\n",yytext);}
{id} {printf("%s is an identifier\n",yytext);count++;}
{notid} {printf("%s is not an identifier\n",yytext);}
%%
int main()
{
FILE *fp;
char file[10];
printf("\nEnter the file name: ");
scanf("%s",file);
fp = fopen(file,"r");
yyin = fp;
yylex();
printf("Total no. of identifier are:%d\n",count);
return 0;
}
