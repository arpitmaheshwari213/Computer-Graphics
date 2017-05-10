#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void drawline(int,int,int,int);
void drawpolygon(int[][2],int);
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
int ver[5][2],n=5;
ver[0][0]=100,ver[0][1]=100 ;
ver[1][0]=200,ver[1][1]=200 ;
ver[2][0]=200,ver[2][1]=400;
ver[3][0]=300,ver[3][1]=400;
ver[4][0]=100,ver[4][1]=200;
drawpolygon(ver,n);
 getch();
 closegraph();
}

void drawline(int x1,int y1,int x2,int y2)
{int m,x,y,temp;

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
	putpixel(x,y,RED);
	}
 }
 else
 {   x=x1;
      for(y=y1;y<=y2;y++)
	{
	x=x+(1/m);
	putpixel(x,y,RED);
	}
 }
}
else
for(y=y1;y<=y2;y++)
{putpixel(x1,y,RED);
}
}
void drawpolygon(int ver[][2],int n)
{ for(int i=0;i<n;i++)
  { drawline(ver[i][0],ver[i][1],ver[(i+1)%n][0],ver[(i+1)%n][1]);
   }
}