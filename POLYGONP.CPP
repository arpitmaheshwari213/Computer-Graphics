#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct Point{
int x,y;
};
void drawPoly(Point ver[],int n)
{ for(int i=0;i<n;i++)
  { line(ver[i].x,ver[i].y,ver[(i+1)%n].x,ver[(i+1)%n].y);
   }
}

int isInside(Point poly[],int n,Point test)
{int i,j,c=0;
for(i=0;i<n;i++)
{j=(i+1)%n;

//check whether point lie on vertex
 if((test.x==poly[j].x&&test.y==poly[j].y)||(test.x==poly[i].x&&test.y==poly[i].y))
   {c=1;
   break;
   }
 if(poly[j].y!=poly[i].y)
 {if((poly[i].y>test.y)!=(poly[j].y>test.y))
 if(test.x<(poly[j].x-poly[i].x)*(test.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x)
  c=!c;
 else if(test.x==(poly[j].x-poly[i].x)*(test.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x)
 {c=1;
 break;
 }
 }
  else{
  if((poly[i].x>test.x)!=(poly[j].x>test.x)&&(poly[i].y==poly[j].y&&poly[i].y==test.y))
  {c=1;
  break;
  }
  }

}
return c;
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tc\\bgi");
Point polygon[]={{100,100},{100,200},{200,200},{200,100}},p={200,200};
 clrscr();
 int n=sizeof(polygon)/sizeof(polygon[0]);
 int j=isInside(polygon,n,p);
// drawPoly(polygon,n);
// putpixel(p.x,p.y,RED);
 if(j==1)
 printf("YES");
 else
 printf("NO");

getch();
closegraph();
}
