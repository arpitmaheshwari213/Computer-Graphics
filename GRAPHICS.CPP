#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void main()
{int m,y,x1=100,x2=200,y1=100,y2=200;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");

y=y1;
m=(y2-y1)/(x2-x1);
for(int x=x1;x<x2;x++)
{
y=y+m;
putpixel(x,y,RED);
}

 getch();
 closegraph();
}