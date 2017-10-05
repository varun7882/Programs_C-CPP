#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a,b;
int *p,*q,*t;
p=&a;
q=&b;
printf("enter the values\n");
scanf("%d%d",&a,&b);
*t=*p;
*p=*q;
*q=*t;
printf("swapped values are%d\n%d",a,b);
   getch();
}
