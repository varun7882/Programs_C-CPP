#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
int main()
{
 int gm,gd=DETECT;
 float xs,ys,x1,y1,x2,y2;
 int r,i,j=0;
 float e;
 initgraph(&gd,&gm,"");
 printf("enter the radius of the circle to be made\n");
 scanf("%d",&r);
  xs=0,ys=r;
   x1=xs;
   y1=ys;
  i=1;
  while(1)
  {
    if(((pow(2,i-1))<=r)&&((pow(2,i))>r))
	    {
	  break;
      }
   i++;
  }
  e=pow(2,(-i));
  putpixel(300,200,CYAN);
  do
  {
      x2=x1+(e*y1);
      y2=y1-(e*x2);
     putpixel(300+x2,200+y2,WHITE);

     j++;
     x1=x2;
     y1=y2;
  }while(j<(4*3.14*r));
  getch();
 closegraph();
 return 0;
}
