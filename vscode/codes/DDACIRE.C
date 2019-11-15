#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
 {
 int xs,ys,x1,y1,x2,y2,r,i;
 float e;
 printf("enter the radius of the circle to be made\n");
 scanf("%d",&r);
  xs=0,ys=r;
   x1=xs;
   y1=ys;
  i=1;
  while(1)
  {
      if((pow(2,i-1)<=r)&&(pow(2,i)>r))
      {
          break;
      }
  }
  e=pow(2,(-i));
  printf("%f",e);
  getch();
 }
