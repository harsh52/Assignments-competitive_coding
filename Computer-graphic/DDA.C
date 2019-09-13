#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main()
{

int x1,y1,x2,y2,m;
int gd = DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
printf("\nEnter Co-ordinates\n");
scanf("%d",&x1);
scanf("%d",&y1);
scanf("%d",&x2);
scanf("%d",&y2);
m = (y2-y1)/(x2-x1);
while(x1!=x2 && y1 != y2)
{
putpixel(x1,y1,RED);
if(m<1)
	{
	x1 = x1 + 1;
	y1 = y1 + m;
	putpixel(x1,y1,RED);
	}
else if(m>1)
	{
	y1 = y1 + 1;
	x1 = x1 + 1/m;
	putpixel(x1,y1,RED);
	}
else
	{
	x1 = x1 + 1;
	y1 = y1 + 1;
	putpixel(x1,y1,RED);
	}

}
getch(0);
return 0;
}