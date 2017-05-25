#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
enum Type{SOLID,DASHED,DOTTED,CENTERLINE};
enum Fill{FILL,HOLLOW};
void drawcircle(int x,int y,int r,COLORS c,int stangle,int endangle,Type per_type,Fill f)
{double x1,y1,i,k=0.1;

if(per_type==DOTTED)
k=4;
for(i=stangle;i<=endangle;i=i+k)
 {if(per_type==DASHED&&(int)i%10>=5)
  continue;
  else if(per_type==CENTERLINE&&(int)i%20>=7&&(int)i%20!=14)
  continue;
 x1=r*cos(i*M_PI/180);
  y1=r*sin(i*M_PI/180);
  putpixel(x+x1,y+y1,c);
 }
 if(f==FILL)
 {for(int j=1;j<r;j++)
  {for(i=stangle;i<=endangle;i=i+0.1)
   {x1=j*cos(i*M_PI/180);
   y1=j*sin(i*M_PI/180);
   putpixel(x+x1,y+y1,c);
   }
  }
 }
}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
drawcircle(200,100,90,WHITE,0,270,DASHED,FILL);
getch();
closegraph();
}