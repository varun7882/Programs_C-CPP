#include<stdio.h>
int main()
{
    int n,m,tn,tm,t,c=0;
    scanf("%d%d",&n,&m);
   tm=m;
   tn=n;
    if(n>m)
    {
        printf("%d",(n-m));
    }
    else
    {
        if(n<(m/2))
       {
        while(n<m)
            {
            n=n*2;
            c++;
            }
          t=n-m;
          t=t+c;
       }
       else
       {
           m=m/2;
           t=n-m;
           tm=tm%2;
           tm=t+tm;
            t=tm+1;
       }
        printf("%d",t);
    }
    return 0;
}
