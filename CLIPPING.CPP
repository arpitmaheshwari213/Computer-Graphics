#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct Point{
int x,y;
};
int max(int a, int b)
{return a>b?a:b;
}
int min(int a,int b)
{return a>b?b:a;
}
void drawclipwindow(Point p1,Point p2)
{ rectangle(min(p1.x,p2.x),min(p1.y,p2.y),max(p1.x,p2.x),max(p1.y,p2.y));
}
void clippoint(Point p1,Point p2,Point test)
{
if(!((min(p1.x,p2.x)<=test.x)&&(max(p1.x,p2.x)>=test.x)&&(min(p1.y,p2.y)<=test.x)&&(max(p1.y,p2.y)>=test.y)))
   putpixel(test.x,test.y,getbkcolor());

}
void main()
{int gd=DETECT,gm;
 initgraph(&gd,&gm,"c://tc//bgi");
 Point p1={100,100},p2={200,200},test1={150,150},test2={20,20};
 drawclipwindow(p1,p2);
 putpixel(test1.x,test1.y,RED);
 putpixel(test2.x,test2.y,RED);
 clippoint(p1,p2,test1);   //only point inside clip window remains
 clippoint(p1,p2,test2);  //test by commenting this line
			  // as test2 lies outside it is going to be clipped
 getch();
 closegraph();
}