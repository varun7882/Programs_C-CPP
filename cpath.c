#include<stdio.h>
#define m 1000000007
int main()
{
    long int a[100000],k,tmin,i,n,t,min,r[100000],p;
    scanf("%ld%ld",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    min=a[0];
    tmin=9999999999999;
    p=k;
    for(i=1;i<n;i++)
    {
        if(i>p)
        {
            min=tmin;
            tmin=9999999999999;
            p=2*p;
        }
        t=(a[i]%m)*(min%m)%m;
        if(tmin>t)
        {
        //  printf("okay %ld\n",t);
            tmin=t;
        }
        r[i]=t;
    }
   // printf("n is %ld",n);
   /* for(i=0;i<n;i++)
    {
        printf(" r %ld\n",r[i]);
    }*/
    printf("%ld",(r[n-1]%m));

}
