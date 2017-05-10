#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
enum Type{DOTTED,DASHED,CENTERLINE,SOLID};
enum Width{SINGLE,DOUBLE,TRIPLE,FIVETIMES};
void drawline(float,float,float,float,Type,Width,COLORS);
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(WHITE);
drawline(30,30,100,100,CENTERLINE,TRIPLE,RED);
drawline(100,100,200,200,DOTTED,SINGLE,GREEN);
drawline(200,200,300,300,DASHED,DOUBLE,BLUE);
drawline(300,300,400,400,SOLID,FIVETIMES,CYAN);
 getch();
 closegraph();
}
void drawline(float x1,float y1,float x2,float y2,Type t,Width w,COLORS c)
{float m,x,y,temp,i=1;
int j=1;

if(x2<x1||y2<y1)  //to avoid the problem in for loop of x=x1;x<x2
 {temp=x2;
 x2=x1;
 x1=temp;
 temp=y2;
 y2=y1;
 y1=temp;
 }                                           //for dotted lines
 if(t==DOTTED)
 i=4;
 else if(t==DASHED)
 j=10;
 else if(t==CENTERLINE)
 j=12;
if(x2!=x1)          //to remove error for x=constant lines or m=infinity
{m=(y2-y1)/(x2-x1);

 if((x2-x1)>=(y2-y1))
 {      y=y1;
	for(x=x1;x<=x2;x=x+i)             //x is incr with i for dotted lines
	{
	 y=y+i*m;
	if(t==DASHED&&(int(x)%j)>5)                   //for dashed line
	 continue;
	else if(t==CENTERLINE&&(int(x)%j)>6&&int(x)%j!=9)
	 continue;

	 else
	 {
	  putpixel(floor(x),floor(y),c);
	  switch(w)
	  {case SINGLE:continue;
	   case DOUBLE:putpixel(floor(x),floor(y+1),c);break;
	   case TRIPLE:putpixel(floor(x),floor(y+1),c);putpixel(floor(x),floor(y-1),c);break;
	   case FIVETIMES:putpixel(floor(x),floor(y+2),c);putpixel(floor(x),floor(y+1),c);putpixel(floor(x),floor(y-1),c);putpixel(floor(x),floor(y-2),c);break;
	  }
	 }
	}
 }
 else
 {   x=x1;
      for(y=y1;y<=y2;y=y+i)
	{ x=x+(i/m);
	  if(t==DASHED&&(int(y)%j)>5)                   //for dashed line
	  continue;
	  else if(t==CENTERLINE&&(int(y)%j)>6&&int(y)%j!=9)
	  continue;
	  else
	  {
	  putpixel(floor(x),floor(y),c);
	  switch(w)
	  {case SINGLE:continue;
	   case DOUBLE:putpixel(floor(x+1),floor(y),c);break;
	   case TRIPLE:putpixel(floor(x+1),floor(y),c);putpixel(floor(x-1),floor(y),c);break;
	   case FIVETIMES:putpixel(floor(x+2),floor(y),c);putpixel(floor(x+1),floor(y),c);putpixel(floor(x-1),floor(y),c);putpixel(floor(x-2),floor(y),c);break;
	   }
	 }
	}
 }
}
else
{ x=x1;
 for(y=y1;y<=y2;y=y+i)
 {  if(t==DASHED&&(int(y)%j)>5)                   //for dashed line
     continue;
    else if(t==CENTERLINE&&(int(y)%j)>6&&int(y)%j!=9)
     continue;
     else{
	putpixel(x,y,c);
	switch(w)
	{case SINGLE:continue;
	 case DOUBLE:putpixel(floor(x+1),floor(y),c);break;
	 case TRIPLE:putpixel(floor(x+1),floor(y),c);putpixel(floor(x-1),floor(y),c);break;
	 case FIVETIMES:putpixel(floor(x+2),floor(y),c);putpixel(floor(x+1),floor(y),c);putpixel(floor(x-1),floor(y),c);putpixel(floor(x-2),floor(y),c);break;
	 }
	}
 }
}
}