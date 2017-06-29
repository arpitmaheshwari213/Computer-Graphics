#include <stdio.h>
#include<conio.h>
#include<graphics.h>
// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int x_max = 100;
const int y_max = 80;
const int x_min = 40;
const int y_min = 40;

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < x_min)
	code |= LEFT;
    else if (x > x_max)
	code |= RIGHT;
    if (y < y_min)
	code |= BOTTOM;
    else if (y > y_max)
	code |= TOP;

    return code;
}


void cohenSutherlandClip(double x1, double y1,
			 double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
     int code_out;
     double x,y;

    int accept = 0;

   while(1)
       {if ((code1 == 0) && (code2 == 0))
	  {  accept = 1;break;}

	else if (code1 & code2)
	     {	accept=0;break;}
	else
	{
	    // Some segment of line lies within the rectangle
	    if (code1 != 0)
		code_out = code1;
	    else
		code_out = code2;


	    if (code_out & TOP)
	    {
		x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
		y = y_max;
	    }
	    else if (code_out & BOTTOM)
	    {
		x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
		y = y_min;
	    }
	    else if (code_out & RIGHT)
	    {
		y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
		x = x_max;
	    }
	    else if (code_out & LEFT)
	    {
		y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
		x = x_min;
	    }
	    else break;

	    if (code_out == code1)
	    {
		x1 = x;
		y1 = y;
		code1=computeCode(x1,y1);
	    }
	    else
	    {
		x2 = x;
		y2 = y;
		code2=computeCode(x2,y2);
	    }
	}
      }
    if (accept==1)
    {
       line(x1,y1,x2,y2);
    }

}
void main()
{ int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");
 setbkcolor(WHITE);
    setcolor(RED);
    rectangle(x_min,y_min,x_max,y_max);
    setcolor(BLUE);
    cohenSutherlandClip(50, 50, 70, 70);
    cohenSutherlandClip(70, 90, 110, 40);
    cohenSutherlandClip(10, 50, 40, 10);

    getch();
    closegraph();
}