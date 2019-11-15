#include<stdio.h>
#include<conio.h>
int main()
{
int a[5],b[5];
printf("enter the numbers");
for(int i=0;i<5;i++)
{
 scanf("%d",&a[i]);
 b[4-i]=a[i];
}
printf("reverse no are");
for(int i=0;i<5;i++)
{
printf("%d\n",b[i]);
}
getch();
return 0;
}
