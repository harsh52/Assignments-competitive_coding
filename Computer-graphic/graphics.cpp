#include<graphics.h>
#include<iostream>
using namespace std;
//Roll: CSB17059
class base //base class to call virtual base class
{
public:
	virtual void draw()
	{

	}
};

class cir:public base //inherit base class to cir class
{
private:
	int x,y,radius;
public:
	void getx(int p)
	{
		x=p;
	}
	void gety(int q)
	{
		y=q;
	}
	void getr(int r)
	{
		radius = r;
	}
	void draw()
	{
		circle(x,y,radius);
	}
};

class rec:public base //inherit base class to rec class
{
	public:
	void draw()
	{
		rectangle(300,50,350,100);
	}
};
class triangle:public base //inherit base class to triangle
{
	public:
	void draw()
	{
		   	line(300, 100, 200, 200);
   			line(300, 100, 400, 200);
   			line(200, 200, 400, 200);
	}
};
int main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,NULL); 
	int x,y,z;
	base b;
	base *p;
	cir obj1;
	rec obj2;
	triangle obj3;
	p = &obj1; //p contain address of circle
	cout<<"Enter X coordinates: ";
	cin>>x;
	cout<<"Enter Y coordinates: ";
	cin>>y;
	cout<<"Enter Z coordinates: ";
	cin>>z;
	obj1.getx(x); //coordinates for rectangle x =200
	obj1.gety(y); // y = 100
	obj1.getr(z); // z = 50
	p->draw(); //calling draw function to draw circle
	p = &obj2; // p contains the address of rec 
	p->draw();
	p = &obj3; //p contains address of traingle
	p->draw();
	getch();
}