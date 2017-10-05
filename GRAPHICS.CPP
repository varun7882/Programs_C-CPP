#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
 {
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\TurboC++\Disk\BGI");
 bar(250,250,50,50);
 getch();
 closegraph();
 }
