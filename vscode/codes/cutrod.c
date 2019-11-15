#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
int s[100];
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
        return b;
}
int reccutrod(int p[],int n)
{
    int r[100],i;
    for(i=0;i<=n;i++)
    {
        r[i]=0;
    }
    return rec_memocutrod(p,r,n);
}
int rec_memocutrod(int p[],int r[],int n)
{
    int i,q;
    if(r[n]>0)
    {
        return r[n];
    }
    if(n==0)
    {
        return 0;
    }
    else
    q=-9999;
    for(i=1;i<=n;i++)
    {
    q=max(q,p[i]+rec_memocutrod(p,r,n-i));
    }
    r[n]=q;
    return q;
}
int cutrod(int p[],int n)
{
    int r[100],q,i,j,temp;
    for(i=0;i<=n;i++)
    {
        r[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        q=-9999;
        for(j=1;j<=i;j++)
        {
        temp=p[j]+r[i-j];
        if(q<temp)
        {
            q=temp;
            s[i]=j;
        }
        }
        r[i]=q;
    }
    return r[n];
}
void print(int n)
{
    while(n>0)
    {
        if(s[n]==0)
        {
            printf("%d\n",s[n]);
            break;
        }
        printf("%d ",s[n]);
        n=n-s[n];
    }
    printf("\n");
}
void main()
{
   int p[]={0,1,5,8,9,10,17,17,20,24,30};
   int n,x;
   while(1)
   {
   printf("enter the value of n\n");
   scanf("%d",&n);
   x=cutrod(p,n);
   printf("the largest value we can get is...%d\n",x);
   print(n);
   }
}

