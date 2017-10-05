#include<stdio.h>
#include<conio.h>
int main()
{

int i,j,n; char c;
printf("enter a number");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
c='A';
for(j=1;j<=i;j++)
{
printf("%c",c);
c=c+1;
}
printf("\n");
}
getch();
}
