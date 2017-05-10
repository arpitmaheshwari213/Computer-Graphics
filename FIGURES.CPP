#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(RED);
setbkcolor(GREEN);
circle(120,300,50);
arc(50,50,0,120,40);
ellipse(300,200,0,360,60,30);
rectangle(400,200,500,300);
line(330,330,400,400);
rectangle(300,50,500,100);
int poly[10]={100,100,100,150,160,230,200,250,100,100};
drawpoly(5,poly);
sector(200,450,30,150,200,50);
pieslice(500,400,20,140,50);
getch();
closegraph();
}