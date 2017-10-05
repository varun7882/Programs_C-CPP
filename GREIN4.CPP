#include<stdio.h>
#include<conio.h>
void main()
{
 clrscr();
 int a,b,c,d;
 printf(" enter the 4 numbers to be compared\n");
 scanf("%d%d%d%d",&a,&b,&c,&d);
 if(a>b)
 {
  if(a>c)
  {
   if(a>d)
   {
    printf(" first number is greatest\n");
   }
   else
   {
   printf(" fourth number is greatest\n");
   }
  }
  else if(c>d)
  {
  printf(" third number is greatest\n");
  }
  else
  {
  printf(" fourth number is greatest\n");
  }
 }
 else if(b>c)
 {
  if(b>d)
  {
  printf(" second number is greatest\n");
  }
  else
  {
  printf(" fourth number is greatest\n");
  }
 }
 else if(c>d)
 {
 printf(" third element is greatest\n");
 }
 else
 {
 printf(" fourth element is greatest\n");
 }
getch();
}