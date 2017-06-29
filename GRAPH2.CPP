#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 5
int axisx=40,axisy=40,gscalex=40,gscaley=40,scalex,scaley,startx,starty;
enum Graph{LINE,BAR};
void drawline(float,float,float,float);
void drawlinegraph(int[][2]);
void drawbargraph(int[][2],int);
void graph(int[][2],Graph);
int find(int);
int maxx(int v[][2])
{int m=v[0][0];
for(int i=1;i<n;i++)
m=v[i][0]>m?v[i][0]:m;
return m;
}
int maxy(int v[][2])
{int m=v[0][1];
for(int i=1;i<n;i++)
m=v[i][1]>m?v[i][1]:m;
return m;
}
int minx(int v[][2])
{int m=v[0][0];
for(int i=1;i<n;i++)
m=v[i][0]<m?v[i][0]:m;
return m;
}
int miny(int v[][2])
{int m=v[0][1];
for(int i=1;i<n;i++)
m=v[i][1]<m?v[i][1]:m;
return m;
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
int ver[n][2];
//int n=sizeof(ver)/sizeof(ver[0]);
ver[0][0]=4,ver[0][1]=100;
ver[1][0]=22,ver[1][1]=200;
ver[2][0]=33,ver[2][1]=400;
ver[3][0]=64,ver[3][1]=350;
ver[4][0]=75,ver[4][1]=200;
//graph(ver,LINE);
graph(ver,BAR);
//printf("%d",find(16));
 getch();
 closegraph();
}

void drawline(float x1,float y1,float x2,float y2)
{float m,x,y,temp;

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
	putpixel(floor(x+0.5),floor(y+0.5),WHITE);
	}
 }
 else
 {   x=x1;
      for(y=y1;y<=y2;y++)
	{
	x=x+(1/m);
	putpixel(floor(x+0.5),floor(y+0.5),WHITE);
	}
 }
}
else
for(y=y1;y<=y2;y++)
{putpixel(floor(x1+0.5),floor(y+0.5),WHITE);
}
}
void drawlinegraph(int ver[][2])
{ for(int i=0;i<n-1;i++)
  { drawline(ver[i][0],ver[i][1],ver[i+1][0],ver[i+1][1]);
   }
}
void drawbargraph(int ver[][2],int axisx)
{int b=10;
for(int i=0;i<n;i++)
 {drawline(ver[i][0]-b,ver[i][1],ver[i][0]+b,ver[i][1]);
  drawline(ver[i][0]-b,ver[i][1],ver[i][0]-b,getmaxy()-axisx);
  drawline(ver[i][0]+b,ver[i][1],ver[i][0]+b,getmaxy()-axisx);
 }
}

void graph(int ver[][2],Graph g)
{int in,plot[n][2];
char str[15];
int k,difx,dify;
int availy=((getmaxy()-axisx)/gscaley)+1,availx=((getmaxx()-axisy)/gscalex)+1;
//scaling
difx=ver[0][0]-ver[1][0];
dify=ver[0][1]-ver[1][1];
for(k=1;k<n-1;k++)
{if(difx==(ver[k+1][0]-ver[k][0]))
 continue;
 else                          //check uniform diff
 {difx=-1;break;}
}
for(k=1;k<n-1;k++)
{if(dify==(ver[k+1][1]-ver[k][1]))
 continue;
 else                          //check uniform diff
 {dify=-1;break;}
}
if(difx!=-1)
{ k=1;
  while((difx*availx*k)<(maxx(ver)-minx(ver)))
     k++;
  scalex=difx*k;
}
else if(maxx(ver)-minx(ver)<=availx-1)
scalex=1;
else
scalex=floor(((maxx(ver)-minx(ver))/(double)(availx-3))+0.5);

if(dify!=-1)
{ k=1;
  while(k!=10)
  {if((dify*availy*k)>(maxy(ver)-miny(ver)))
    {scaley=dify;
    break;
    }
   k++;
  }
}
else if(maxy(ver)-miny(ver)<=(availy-1))
scaley=1;
else
scaley=floor(((maxy(ver)-miny(ver))/(double)(availy-3))+0.5);

if(0<minx(ver)&&(2*scalex)>minx(ver))
startx=scalex;
else
startx=minx(ver)-(minx(ver)%scalex);

if(0<miny(ver)&&2>miny(ver))
starty=scaley;
else
starty=miny(ver)-miny(ver)%scaley;

drawline(axisy,0,axisy,getmaxy()-axisx);       //drawing x and y axis
drawline(axisy,getmaxy()-axisx,getmaxx(),getmaxy()-axisx);

for(int i=1;i<availy;i++)                  //draw markings on y-axis
{drawline(axisy-10,getmaxy()-axisx-i*gscaley,axisy,getmaxy()-axisx-i*gscaley);
  in=starty+(i-1)*scaley;
  sprintf(str,"%d",in);               //converting int to string
  outtextxy(axisy-30,getmaxy()-axisx-i*gscaley-2,str);
}
for(int j=1;j<availx;j++)                  //draw markings on x-axis
{drawline(axisy+j*gscalex,getmaxy()-axisx,axisy+j*gscalex,getmaxy()-axisx+10);
 in=startx+(j-1)*scalex;
 sprintf(str,"%d",in);             //converting int to string
 outtextxy(axisy+j*gscalex,getmaxy()-axisx+20,str);
}
for(i=0;i<n;i++)
{plot[i][0]=axisy+(gscalex*(ver[i][0]-startx+scalex)/scalex);               //x in graph = gscalex*(value-startx)/scalex
 plot[i][1]=getmaxy()-axisx-(gscaley*(ver[i][1]-starty+scaley)/scaley);
}
if(g==LINE)
drawlinegraph(plot);
else if(g==BAR)
drawbargraph(plot,axisx);
}


int find(int x)
{x=axisy+(gscalex*(x-startx+scalex)/scalex);
int start=getmaxy()-axisx,g;
 for(start;start>0;start--)
 {g=getpixel(x,start);
 if(g!=BLACK)
 break;
 }
 start=(getmaxy()-axisx-start)*scaley/gscaley+starty-scaley;
 return start;
}