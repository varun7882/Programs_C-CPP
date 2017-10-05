#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
 void main()
{
 float a,b,c,d,dx,dy,p;
 int gm=DETECT,gd,i,j;
 printf("enter the first point (x1,y1)\n");
 scanf("%f%f",&a,&b);
 printf("enter the second point (x2,y2)\n");
 scanf("%f%f",&c,&d);
 initgraph(&gm,&gd,"");
 dy=abs(d-b);
 dx=abs(c-a);
 if(dy>=dx)
 {
 p=dy;
 }
 else
 {
 p=dx;
 }
 dx=dx/p;
 dy=dy/p;
 i=1;
 j=100;
 while(i<=p)
 {
 putpixel(a,b,BLUE);
 a=a+dx;
 b=b+dy;
 i++;
 sound(j);
 delay(10);
 j=j+50;
 }
 nosound();
 getch();
 closegraph();
}