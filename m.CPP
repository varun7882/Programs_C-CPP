#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[5],b[5];
printf("enter the numbers\n");
for(int i=0;i<5;i++)
{
 scanf("%d",&a[i]);
}
printf("even no are\n");
for(i=0;i<5;i++)
{
if(a[i]%2==0)
printf("%d\n",a[i]);
}
printf("odd no are\n");
for(i=0;i<5;i++)
if(a[i]%2!=0)
printf("%d\n",a[i]);
getch();
}
