#include<stdio.h>
#include<conio.h>
void main()
{
int a=2;
while (a<=10)
{
while (a<=a*10)
{
printf("%d\t",a);
a=a+a;
}
a=(a/10)+1;
printf("\n");
}
getch();
}
