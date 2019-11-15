#include<stdio.h>
int main()
{
    int i;
    long long int n,k,c=0;
    long long int a[10000000];
    scanf("%lld%lld\n",&n,&k);
    while(n--)
    {
        scanf("%lld",&a[i]);
        if(a[i]%k==0)
        {
            c++;
        }
    }
    printf("%lld",c);
    return 0;
}
