#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
clrscr();
int x,d;
printf("Enter no.");
scanf("%d",&x);
d=fact(x);
printf("%d",d);
getch();
}
int  fact(int a)
{
int d;
if(a==0)
{
return 1;
}
else
{
d=a*fact(a-1);
return d;
}
}
