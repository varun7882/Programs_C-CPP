#include<stdio.h>
#include<conio.h>
void main()
{
    int x,n=1,a[100],i;
    a[0]=1;
    int t,j,c;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        c=0;
      for(j=0;j<n;j++)
      {
          t=(a[j]*i)+c;
          a[j]=t%10;
          c=t/10;
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
    getch();
}
