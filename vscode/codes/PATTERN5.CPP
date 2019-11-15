#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,k,n;
printf("enter a number");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=(i-1);j++)
{
printf(" ");
}
for(k=1;k<=(n+1-i);k++)
{
printf("*");
}
printf("\n");
}
getch();
}
