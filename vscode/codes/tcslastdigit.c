#include<stdio.h>
typedef long long int dty;
dty power(dty x,dty y)
{
    if(y==0)
        return 1;
    long long int p = power(x, y/2);
    p = (p * p) ;

    return (y%2 == 0)? p : (x * p);
}
dty powerl2(dty x,dty y)
{
    if(y==0)
        return 1;
    long long int p = powerl2(x, y/2)%100;
    p = (p * p)%100 ;

    return (y%2 == 0)? p : (x * p)%100;
}
dty ls(dty x)
{
    dty a;
    if(x%4==0)
    {
      a=6;
    }
    else if(x%4==1)
    {
        a=2;
    }
    else if(x%4==2)
    {
        a=4;
    }
    else
    {
        a=8;
    }
    return a;
}
int main()
{
    dty n,i,j,ft,st,tans,ans=0;
    scanf("%lld",&n);
    i=0;
    while(power(2,i)<=n)
    {
        printf("1");
        for(j=0;j<=n;j++)
        {
            printf("2");
            ft=powerl2(2,i);
            ft=ls(ft);
            st=ls((2*j)%100);
            tans=ft*st;
            ans=(ans+tans)%10;
        }
        i++;
    }
        printf("%lld",ans);
}
