#include<iostream>
#define m 1000000007;
typedef long long int dty;
dty power(dty x,dty y)
{
    if(y==0)
        return 1;
    long long int p = power(x, y/2) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}
dty fact(dty x)
{
    if(x==1 || x==0)
    {
        return 1;
    }
    else
    {
        dty t=x%m;
        dty tf=fact(x-1)%m;
        return (t*tf)%m;
    }
}

int main()
{
    dty n,k,i,uk,nk,ans=0,tans,tuk,tuk1,tuk2,tm=m-2;
    std::cin>>n>>k;
    uk=1;
    for(i=0;i<=k;i=i+2)
    {
        nk=fact(i);
        tuk=uk%m;
        if(i==0)
        {
            tuk1=1;
            tuk2=1;
        }
        else
        {
            tuk1=n-(i-2);
            tuk2=n-(i-1);
            tuk1=tuk1%m;
            tuk2=tuk2%m;
            tuk1=(tuk1*tuk2)%m;
        }
        tuk=tuk%m;
        tuk1=tuk1%m;
        uk=tuk*tuk1%m;
        tans=(uk/nk)%m;
        uk=uk%m;
        tm=1000000005;
        nk=power(nk,tm);
        tans=uk*nk%m;
     //   std::cout<<uk<<" "<<nk<<" "<<tans<<std::endl;
        ans=ans+tans;
    }
    std::cout<<ans<<std::endl;
    return 0;
}

