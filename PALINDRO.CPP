
#include<stdio.h>
#include<conio.h>
void main()
{
 clrscr();
 int a,b,r=0;
 printf("enter a number");
 scanf("%d",&a);
 b=a+0;
 while(a>0)
 {
 r=(10*r)+(a%10);
 a=a/10;
 }
 if(b==r)
 printf("no. is palindrome");
 else
 printf("go to hell");
 getch();
}