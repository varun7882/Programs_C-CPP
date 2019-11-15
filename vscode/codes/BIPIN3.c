#include<stdio.h>
#define Mod 1000000007
long long int power(long long int x,long long int y, long long int m)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}
int main()
{
    long long int n,k,p,ans;
    int T;
    scanf("%d",&T);
    while(T--)
    {
      scanf("%lld%lld",&n,&k);
      p=power(k-1,n-1,Mod);
      printf("%lld\n",(p%Mod*k%Mod)%Mod);
    }
    return 0;
}
