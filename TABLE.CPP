#include<stdio.h>
#include<conio.h>
void main()
{
int a;
clrscr();
printf("Enter a no.");
scanf("%d",&a);
for(int i=1;i<=10;i++)
{
int b;
b=a*i;
printf("%d\n",b);
}
getch();
}