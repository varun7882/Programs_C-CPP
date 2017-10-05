#include<stdio.h>
#include<string.h>
#define m 1000000007
long long int power(long long int x,long long int y, long long int m)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}
