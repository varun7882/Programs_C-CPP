#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
 void main()
 {
  int j=500,c=1;
  while(c<5)
  {
  while(j<1000)
  {
  j=j+50;
  sound(j);
  delay(200);
  }
  while(j>1500)
  {
   j=j-50;
   sound(j);
   delay(200);
  }
  c++;
  }
  nosound();
  getch();
 }