#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct Point{
int x,y;
};
int isInside(Point poly[],int n,Point test)
{int i,j,c=0;
for(i=0;i<n;i++)
{j=(i+1)%n;
//check whether point lie on vertex
 if((test.x==poly[j].x&&test.y==poly[j].y)||(test.x==poly[i].x&&test.y==poly[i].y))
   {c=1;
   break;
   }
 //check by slope comparing
 if(poly[j].y!=poly[i].y)
 {if((poly[i].y>test.y)!=(poly[j].y>test.y))
   if(test.x<(poly[j].x-poly[i].x)*(test.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x)
    c=!c;
   else if(test.x==(poly[j].x-poly[i].x)*(test.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x)
   {c=1;
    break;
   }

 }  //special case for horizontal lines
  else
  {
   if((poly[i].x>test.x)!=(poly[j].x>test.x)&&(poly[i].y==poly[j].y&&poly[i].y==test.y))
   {
    c=1;
    break;
   }
  }
}
return c;
}
void fillPoly(Point ver[],int n)
{ int xmax=ver[0].x,xmin=ver[0].x,ymax=ver[0].y,ymin=ver[0].y,i,j;
  Point p;
  for(i=1;i<n;i++)
  {if(xmax<ver[i].x)
   xmax=ver[i].x;
   if(xmin>ver[i].x)
   xmin=ver[i].x;
   if(ymax<ver[i].y)
   ymax=ver[i].y;
   if(ymin>ver[i].y)
   ymin=ver[i].y;
 }
  for(j=ymin;j<=ymax;j++)
  {for(i=xmin;i<=xmax;i++)
   {p.x=i;p.y=j;
   if(isInside(ver,n,p))
   putpixel(i,j,WHITE);
   }
  }
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tc\\bgi");
Point polygon[]={{50,100},{100,50},{150,100},{100,150},{120,70},{100,90}};
 clrscr();
 int n=sizeof(polygon)/sizeof(polygon[0]);
 fillPoly(polygon,n);
getch();
closegraph();
}
