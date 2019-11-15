#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a,b,n,i=1;
printf("enter the size of paper in format a*b i.e. A-0");
scanf("%d%d",&a,&b);
printf("the sizes reqired i.e. a number");
scanf("%d",&n);
while(i<=n)
 {
  if(a>b)
   {
    a=a/2;
   }
   else
    {
     b=b/2;
    }
    printf("A%d  %d*%d\n",i,a,b);
  i=i++;
 }
getch();
}