#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c;
clrscr();
printf("enter two numbers ");
scanf("%d%d",&a,&b);
c=a;
a=b;
b=c;
printf("after swapping %d %d",a,b);
getch();
}
