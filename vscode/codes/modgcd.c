#include<stdio.h>
typedef long long int ll;
ll t;
ll mgcd(ll a,ll b)
{
if(a%b==0)
{
    return b;
}
 else
 {
     mgcd(b,a%b);
 }
}
void main()
{
    ll a,b,n,lw,hi,ans,t;
    scanf("%lld%lld",&a,&b);
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    scanf("%lld",&n);
    while(n--)
    {

    }
}
