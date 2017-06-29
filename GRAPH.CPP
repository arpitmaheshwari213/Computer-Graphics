#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define n 5
void drawpiechart(int p[2][n])
{double sum=0,stangle=0,endangle=0;
int x=(getmaxx()+1)/2;
int y=(getmaxy()+1)/2;
int r=100;
for(int j=0;j<n;j++)
sum=sum+p[1][j];
for(int i=0;i<n;i++)
{ setcolor(i+2);
  stangle=endangle;
  //printf("%lf\n",stangle);
  endangle=((p[1][i]/sum)*360+endangle);
  //printf("%lf\n",endangle);
  pieslice(x,y,stangle,endangle,r);
}
}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");
 int pie[2][n]={{1,2,3,4,5},{12,30,18,22,18}};
 drawpiechart(pie);
getch();
closegraph();
}