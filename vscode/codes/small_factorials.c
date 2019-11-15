#include<stdio.h>
int main()
{
   int a[200],c,n,x,i,j,p,k;
   scanf("%d",&p);
   while(p--)
   {
   a[0]=1;
   n=1;
 scanf("%d",&x);
 for(i=2;i<=x;i++)
 {
     c=0;
    for(j=0;j<n;j++)
    {
  k=(a[j]*i)+c;
   a[j]=k%10;
   c=k/10;
    }
   while(c>0)
   {
     a[n]=c%10;
     c=c/10;
     n++;
   }
 }
 for(i=n-1;i>=0;i--)
 {
     printf("%d",a[i]);
 }
 printf("\n");
  }
 return 0;
 }
