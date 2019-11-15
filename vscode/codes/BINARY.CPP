#include<stdio.h>
#include<conio.h>
int main()
{
int a[100],b,l,m,n,x,f;
printf("enter the number of the elements to be inserted\n");
scanf("%d",&x);
if(x!=1)
{
printf("enter the numbers in sorted manner\n");
for(int i=0;i<x;i++)
{
scanf("%d",&a[i]);
}
b=0;
l=x-1;
printf("enter the number to be searched\n");
scanf("%d",&n);
while(m>0)
{
    f=1;
m=((b+l)/2);
if(a[m]==n)
{
printf("the number is found %d ",n);
f=0;
break;
}

else if(n<a[m])
 {
  l=m;
 }
else if(n>a[m])
{
 b=m;
}
}
}
else
{
printf("you entered a single number idiot\n");
}
if(f==1 )
printf("number not found");
getch();
}
