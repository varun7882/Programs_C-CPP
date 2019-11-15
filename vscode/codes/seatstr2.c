#include<stdio.h>
#include<string.h>
#define m 1000000007
long long int power(long long int x,long long int y, long long int k)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, k) % k;
    p = (p * p) % k;

    return (y%2 == 0)? p : (x * p) % k;
}
long long int fact(long long x,long long y)
{
    if(x==0 || x==1)
    {
        return 1;
    }
    long long f=1,i;
    for(i=1;i<=x;i++)
    {
        f=(((f%y)*(i%y))%y);
    }
    return f;
}
long long int ncr(long long int x,long long y)
{
    if(x==y)
        return 1;
    if(x>y)
       return (fact(x,m)%m*power(fact(y,m)*fact(x-y,m),m-2,m)%m)%m;
}
int main()
{
    int t;
   long long int i,n,ta,ans,num,den,temp,n1,nc,tc;
    char s[100000];
    scanf("%d",&t);
    while(t--)
    {
        nc=ans=0;
        tc=den=1;
        long int a[26]={0};
        scanf("%s",s);
        n1=n=strlen(s);
        for(i=0;i<n;i++)
        {
            ta=(int)s[i];
           // printf("%c %lld\n",s[i],ta);
            a[(ta-97)]++;
        }
        n1=n;
        for(i=0;i<26;i++)
       {
          // printf("%lld",a[i]);
           if(a[i]>1)
           {
             n1=n-a[i]+1;;
           }
       }
       if(n1<0)
       {
           n1=0;
       }
      // printf("\nn1 is %lld",n1);
       num=fact(n,m);
       // printf("\nnum is %lld\n",num);
       for(i=0;i<26;i++)
       {
           if(a[i]>1)
           {
            den=((den%m)*(fact(a[i],m)%m)%m);
           }
       }
       //printf("\nden is %lld\n",den);
       nc=tc=ncr(n1,2)*ncr(n1-2,2);
       //printf("%lld\n",tc);
       for(i=4;i<n1;i+2)
       {
           tc=tc*ncr(n1-i,2);
           nc=nc+tc;
       }
       temp=((nc%m)*(num%m)*power(den,m-2,m))%m;
       //printf("nc is %lld\n",nc);
       //ans=(2%m*temp%m)%m;
       printf("%lld\n",temp);
    }
    return 0;
}
