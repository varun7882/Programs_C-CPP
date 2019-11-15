
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
 void main()
{
 float a,b,c,d,dx,dy,e,x,y;
 int gd=DETECT,gm,i;
 printf("enter the first point (x1,y1)\n");
 scanf("%f%f",&a,&b);
 printf("enter the second point (x2,y2)\n");
 scanf("%f%f",&c,&d);
 initgraph(&gd,&gm,"");
 dy=abs(d-b);
 dx=abs(c-a);
 x=a,y=b;
 e=(2*dy)-dx;
 i=0;
 while(i<dx)
 {
     putpixel(x,y,BLUE);
     while(e>=0)
     {
         y=y+1;
         e=e-(2*dx);
     }
     x=x+1;
     e=e+(2*dy);
  i++;
 }
 getch();
 closegraph();
}
