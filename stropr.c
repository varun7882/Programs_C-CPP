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
    long long int a[100001],n,x,m,i,ans,t,j,d,c;
    int T;
    scanf("%d",&T);
    while(T--)
    {
      scanf("%lld%lld%lld",&n,&x,&m);
      for(i=1;i<=n;i++)
      {
          scanf("%lld",&a[i]);
      }

      if(x==1)
       {
           printf("%lld\n",a[1]%Mod);
       }
      /* else if(1<=n*m && n*m<=1000000)
       {
             for(i=0;i<m;i++)
      {
          for(j=2;j<=x;j++)
          {
              a[j]=(a[j]+a[j-1])%Mod;
          }

      }

      printf("%lld\n",a[x]%Mod);
       }*/
      else
      {
         c=t=m;
          d=1;
          ans=a[x];
        for(i=x-1;i>=1;i--)
        {

          ans=((ans%Mod)+((c%Mod)*(a[i]%Mod))%Mod)%Mod;
          d=(d%Mod*(x-i+1)%Mod)%Mod;
          j=power(d,Mod-2,Mod);
          t=((t%Mod)*(m%Mod+(x-i)%Mod)%Mod)%Mod;
          c=((t%Mod)*(j%Mod))%Mod;

        }
        printf("%lld\n",ans%Mod);
       }
    }
    return 0;
}
