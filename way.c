#include<stdio.h>
#include<limits.h>
#define mod 1000000007
int main()
{
    long int i,j,n,k,a[100001],p,min,t;
    scanf("%ld%ld",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&a[i]);
    }
    i=1;
    p=a[i];
    while(i<=n-k+1)
    {
        min=LONG_MAX;
        j=i+k;
        while((j>i))
        {
            if(min>(a[j]*a[i]))
            {
                min=a[j];
                t=j;
               // printf("min is %ld\n",min);
            }
            if(j==n)
            {
                min=a[j];
               i=j;
                break;
            }
        j--;
        }
        p=(p*min)%mod;
        // printf("p is %ld\n",p);
        i=t;
    }
    printf("%ld",p);
    return 0;
}
