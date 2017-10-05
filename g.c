#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
 {
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\TurboC++\Disk\TurboC3\BGI");
 bar(100,100,200,200);
 getch();
 closegraph();
 }
