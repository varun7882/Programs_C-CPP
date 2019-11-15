#include <stdio.h>
#define m 1000000007
typedef long long int dty;
int main()
{
    dty t,n,i;
    scanf("%lld",&t);
    while(t--)
    {
          scanf("%lld",&n);
        dty v[1000001];
        v[1]=1;
        v[2]=2;
        for(i=3;i<=n;i++)
        {
            v[i]=(v[i-1]%m+(((i-1)%m)*(v[i-2]%m))%m)%m;
        }
        printf("%lld\n",v[n]);
    }
    return 0;
}


