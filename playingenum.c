#include <stdio.h>
int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}
 int main()
{
    long int t,n,sum,i;
    scanf("%ld",&t);
    while(t--)
    {
        sum=0;
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
        {
            sum=sum+lcm(i,n);
        }
        printf("%ld\n",sum);
    }
    return 0;
}
