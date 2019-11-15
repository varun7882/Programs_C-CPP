#include<stdio.h>
#include<conio.h>
int main()
{
int n,j;

printf("enter no.");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
 for(j=1;j<=i;j++)
 {
  printf("%d   ",j);

 }
printf("\n");
}
getch();
}
