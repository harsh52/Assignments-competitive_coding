#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
void bla(int x1, int y1, int x2, int y2)
{
	int x,y,dx,dy,p;
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2*dx - dy;
	while(x<=x2)
	{
		putpixel(x,y,RED);
		x++;
		if(p<0)
		{
			p = p + 2*dy;
		}
		else
		{
			p = p + 2*dy - 2*dx;
			y++;
		}
	}
}
int main()
{
int x1, x2, y1, y2, dx, dy, pk, m, y11, x11;

int gd = DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

//int x1, y1, x2, y2, dx, dy, pk, m, y11,x11;
printf("Enter co-ordinates");
scanf("%d",&x1);
scanf("%d",&y1);
scanf("%d",&x2);
scanf("%d",&y2);
bla(x1,y1,x2,y2);
/*
x11 = x1;
y11 = y1;
dx = x2 - x1;
dy = y2 - y1;
pk = 2*dy - dx;
putpixel(x1,y1,RED);
pk = 2*dy - dx;
m = (y2 - y1)/(x2 - x1);
while(x11!=x2 && y11!=y2)
{
if(m<1)
{	if(pk >= 0)
	{
	x11 = x1 + 1;
	y11 = y1 + 1;
	putpixel(x11,y11,RED);
	pk = pk + 2*dy - 2*dx*(y11 - y1);
	}
	else if(pk < 0)
	{
	x11 = x1 + 1;
	y11 = y1;
	putpixel(x11,y11,RED);
	pk = pk + 2*dy - 2*dx*(y11 - y1);
	}
}
else if(m > 1)
	{
		if(pk >= 0)
		{
		x11 = x1 + 1;
		y11 = y1 + 1;
		putpixel(x11,y11,RED);
		pk = pk + 2*dy - 2*dx*(y11 - y1);
		}
		else if(pk < 0)
		{
		x11 = x1;
		y11 = y1 + 1;
		putpixel(x11,y11,RED);
		pk = pk + 2*dy - 2*dx*(y11 - y1);
		}
	}
}
*/
getch(0);
return 0;
}