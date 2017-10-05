#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
 void main()
 {
 static int j=1000,c=1;
 char ch;
  while(c<3)
  {
  while(j<1200)
  {
  j=j+10;
  sound(j);
  delay(100);
  }
  while(j>1000)
  {
   j=j-10;
   sound(j);
   delay(100);
  }
  c++;
  }
  nosound();
  getch();
 }