#include<stdio.h>
#include<conio.h>
int fib(int);
void main()
{
int n,d;
printf("enter the number\n");
scanf("%d",&n);
printf("the fibonacci sequence is...\n");
for(int i=0;i<n;i++)
{
 d=fib(i);
 printf("  %d  ",d);
}
getch();
}
int fib(int a)
{
int d;
if(a==0||a==1)
{
d=a;
return d;
}
else
{
d=fib(a-1)+fib(a-2);
}
return d;
}