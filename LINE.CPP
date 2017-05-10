#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void drawline(float,float,float,float);
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
drawline(100,100,200,200);
drawline(200,200,200,100);
drawline(100,100,200,100);
drawline(100,100,200,300);
 getch();
 closegraph();
}
void drawline(float x1,float y1,float x2,float y2)
{float m,x,y,temp;

if(x2<x1||y2<y1)  //to avoid the problem in for loop of x=x1;x<x2
 {temp=x2;
 x2=x1;
 x1=temp;
 temp=y2;
 y2=y1;
 y1=temp;
 }
if(x2!=x1)          //to remove error for x=constant lines or m=infinity
{m=(y2-y1)/(x2-x1);

 if((x2-x1)>=(y2-y1))
 {      y=y1;
	for(x=x1;x<=x2;x++)
	{
	y=y+m;
	putpixel(floor(x),floor(y),RED);
	}
 }
 else
 {   x=x1;
      for(y=y1;y<=y2;y++)
	{
	x=x+(1/m);
	putpixel(floor(x),floor(y),RED);
	}
 }
}
else
 {  x=x1;
  for(y=y1;y<=y2;y++)
  {putpixel(floor(x),floor(y),RED);
  }
 }
}