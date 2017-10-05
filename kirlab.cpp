#include<iostream>
#include<limits.h>
using namespace std;
typedef long long int dty;
dty a[100001],dp[100001],n;
// cp[100001];
dty gcd(dty a,dty b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(b,a%b);
    }
}
dty notcoprime(dty a,dty b)
{
    dty x=1;
    if(a%2==0 && b%2==0)
    {
        return 1;
    }
    if(a%3==0 && b%3==0)
    {
        return 1;
    }
    if(a%5==0 && b%5==0)
    {
        return 1;
    }
    if(a>b)
    {
        x=gcd(a,b);
    }
    else
    {
        x=gcd(b,a);
    }
    if(x>1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 bool coprime(long long u, long long v)
{
    if (((u | v) & 1) == 0) return false;

    while ((u & 1) == 0) u >>= 1;
    if (u == 1) return true;

    do
    {
        while ((v & 1) == 0) v >>= 1;
        if (v == 1) return true;

        if (u > v) { long t = v; v = u; u = t; }
        v -= u;
    } while (v != 0);

    return false;
}
dty fn(dty i)
{
    if(dp[i]!=LONG_MIN)
    {
        return dp[i];
    }
    dty j,q=0,x=-1;
    for(j=i+1;j<n;j++)
    {
        if(!coprime(a[i],a[j]))
        {
            if(dp[j]==LONG_MIN)
            {
            x=fn(j);
            }
            else
            {
                x=dp[j];
            }
        }
        if(x>q)
        {
            q=x;
        }
    }
    dp[i]=q+1;

  //  cout<<"ey ";
     return dp[i];
}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        dty ans=0,x;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            dp[i]=LONG_MIN;
        }
         for(i=0;i<n;i++)
        {
            if(dp[i]==LONG_MIN)
            {
            x=fn(i);
            }
            else
            {
                x=dp[i];
            }
            if(x>ans)
            {
                ans=x;
            }
        }
        cout<<ans<<"\n";
    }
}
