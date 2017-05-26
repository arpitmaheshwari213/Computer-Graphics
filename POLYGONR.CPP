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

int polygonRelation(Point poly1[],int n1,Point poly2[],int n2)
{ int c=0;
 for(int i=0;i<n2;i++)
  {c=c+isInside(poly1,n1,poly2[i]);
  }
  if(c==0)
  {if(isInside(poly2,n2,poly1[1]))
   return 2;
   return 1;
  }
  else if(c==n2)
  return 2;
  else return 0;
}
void main()
{Point polygon1[]={{100,100},{200,100},{200,200},{100,200}},polygon2[]={{50,250},{250,50},{250,250},{50,250}};
 clrscr();
 int n1=sizeof(polygon1)/sizeof(polygon1[0]);
 int n2=sizeof(polygon2)/sizeof(polygon2[0]);
 int j=polygonRelation(polygon1,n1,polygon2,n2);
 if(j==0)
 printf("Intersecting");
 else if(j==1)
 printf("Non-Intersecting");
 else
 printf("Surrounding");
 getch();
}