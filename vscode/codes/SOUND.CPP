#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
void main()
 {
 int gd=DETECT,gm,i=100;
 initgraph(&gd,&gm,"");
 circle(100,200,20);
 printf("%d",abs(1.8));
 for(i=0;i<2000;i++)
 {
 sound(i);
 delay(100);
 }
 delay(2000);
 nosound();
 getch();
 closegraph();
 }
