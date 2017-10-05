#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,n;
printf("enter a no.");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  if(i==j||i==((n+1)-j))
   {
    printf("  *");
   }
   else
    printf("   ");
 }
 printf("\n");
}
getch();
}