#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Bresenham_drawline(int x1,int y1,int x2,int y2)
{int dx=abs(x2-x1),dy=abs(y2-y1),x,y,xend,yend;
 int p;
 if(dx>=dy)
 { p=2*dy-dx;
  if(x1>x2)
  {x=x2;
  y=y2;
  xend=x1;
  }
  else
  {x=x1;
  y=y1;
  xend=x2;
  }

  for(x=x;x<xend;x++)
  {
  if(p<0)
  p=p+2*dy;
  else
  p=p+2*dy-2*dx,y++;
  putpixel(x,y,WHITE);
  }
 }
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
Bresenham_drawline(100,200,300,300);
getch();
closegraph();
}