#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
struct matrix
{ int m[3][3];
};
//int product={{0,0,0},{0,0,0},{0,0,0}};
matrix matrixMult(matrix m1,matrix m2)
{ int i,j,k,sum;
 matrix product;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
    sum=0;
    for(k=0;k<3;k++)
    {sum=sum+m1.m[i][k]*m2.m[k][j];
    }
    product.m[i][j]=sum;
  }
 }
 return product;
}
void displayTriangle(matrix mat,COLORS c)
{setcolor(c);
for(int x=0;x<3;x++)
 line(mat.m[0][x]+320,240-mat.m[1][x],mat.m[0][(x+1)%3]+320,240-mat.m[1][(x+1)%3]);
}
matrix trans(int tx, int ty)
{matrix t={{{1,0,tx},{0,1,ty},{0,0,1}}};
return t;
}
matrix scale(int sx, int sy)
{matrix s={{{sx,0,0},{0,sy,0},{0,0,1}}};
return s;
}
matrix rotation(double q)
{q=q*M_PI/180;
matrix rot={{{floor(cos(q)),floor(-sin(q)),0},{floor(sin(q)),floor(cos(q)),0},{0,0,1}}};
return rot;
}
matrix reflection(int x,int y,int z)
{matrix r={{{x,0,0},{0,y,0},{0,0,z}}};
return r;
}
void main()
{int gd=DETECT,gm;
matrix matr={{{20,40,60},{20,40,20},{1,1,1}}};
initgraph(&gd,&gm,"c://tc//bgi");
matrix ans,ans2;
 line(0,(getmaxy()+1)/2,getmaxx(),(getmaxy()+1)/2);   //x-axis
 line((getmaxx()+1)/2,0,(getmaxx()+1)/2,getmaxy());   //y-axis
 displayTriangle(matr,WHITE);
 //transformation
 ans=matrixMult(trans(20,20),matr);
 displayTriangle(ans,RED);
 //scaling double in both dir wrt origin
 ans=matrixMult(scale(2,2),matr);
 displayTriangle(ans,RED);
// scalling 3 times in x and 4 times in y direction w.r.t. centroid
 ans=matrixMult(trans(-(matr.m[0][0]+matr.m[0][1]+matr.m[0][2])/3,-(matr.m[1][0]+matr.m[1][1]+matr.m[1][2])/3),matr);
 ans2=matrixMult(scale(3,4),ans);
 ans=matrixMult(trans((matr.m[0][0]+matr.m[0][1]+matr.m[0][2])/3,(matr.m[1][0]+matr.m[1][1]+matr.m[1][2])/3),ans2);
  displayTriangle(ans,RED);
  //rotation by 90 in anti wrt (0,0)
  ans=matrixMult(rotation(90),matr);
   displayTriangle(ans,RED);
  //rotating by 90 in anti wrt (40,40)
  ans=matrixMult(trans(-40,-40),matr);
  ans2=matrixMult(rotation(90),ans);
  ans=matrixMult(trans(40,40),ans2);
  displayTriangle(ans,RED);
  //rotation wrt any arbitary point
  int x=-12,y=100;
  ans=matrixMult(trans(-x,-y),matr);
  ans2=matrixMult(rotation(90),ans);
  ans=matrixMult(trans(x,y),ans2);
  displayTriangle(ans,RED);
  //reflection wrt x-axis
    ans=matrixMult(reflection(1,-1,1),matr);          //for x-axis -1 in y and 1 in x and z
     displayTriangle(ans,RED);
  //reflection wrt yaxis
     ans=matrixMult(reflection(-1,1,1),matr);          //for Y-axis -1 in X and 1 in y and z
     displayTriangle(ans,RED);
  //reflection wrt any arbitary axis
   double m=1,q;
   q=atan(m)*180/M_PI;                         //slope of arbitary line
   ans=matrixMult(rotation(q),matr); //for clockwise rotation  360-q
  ans2=matrixMult(reflection(-1,1,1),ans);   //reflection in x-axis
   ans=matrixMult(rotation(-q),ans2);
    displayTriangle(ans,BLUE);
    //shearing wrt (0,0)  in ques no value of shx or shy are given

getch();
closegraph();
}