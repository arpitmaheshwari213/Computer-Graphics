#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void wheel(int xc,int yc,int r,int speed_delay,int anti)
{int i,x1[4],y1[4];
double ang;
circle(xc,yc,r);

if(anti==0)                         //for anticlockwise and clockwise
ang=5*M_PI/180;                     //angle is - and + respectively
else                                // rotation with respect to center of circle for both lines
ang=-5*M_PI/180;                    // with 5 degree and converted ang in rad
int k=0;                            //for infinite loop can be removed
while(k!=10)
 { k++;
   x1[0]=xc-r,x1[1]=xc+r,x1[2]=xc,x1[3]=xc;     //to remove error from lines values are reassigned
   y1[0]=yc,y1[1]=yc,y1[2]=yc-r,y1[3]=yc+r;
  for(int j=0;j<18;j++)                         //loop for rotation
  {  setcolor(WHITE);
   line(x1[0],y1[0],x1[1],y1[1]);               //drawing lines
   line(x1[2],y1[2],x1[3],y1[3]);
    delay(speed_delay);                         //for  changable speed
    setcolor(BLACK);                            //to remove old line redraw it in black
   line(x1[0],y1[0],x1[1],y1[1]);
   line(x1[2],y1[2],x1[3],y1[3]);               //to find values after rotation
    for(i=0;i<4;i++)
     {                                          //formula for T-1 R T  generated through matrix multiplication
     x1[i]=floor(((double)x1[i])*cos(ang)-((double)y1[i])*sin(ang)+((double)xc)*(1-cos(ang))+((double)yc)*sin(ang)+0.5);
     y1[i]=floor(((double)x1[i])*sin(ang)+((double)y1[i])*cos(ang)+((double)yc)*(1-cos(ang))-((double)xc)*sin(ang)+0.5);
    }
  }
 }
}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
wheel(100,100,50,100,0);
getch();
closegraph();
}
