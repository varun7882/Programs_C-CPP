#include<stdio.h>
#include<math.h>
int abs(int x)
{
    if(x<0)
    {
        x=x*(-1);
    }
    return x;
}
int main()
{
  int t;
   int a[100000],b[100000],n,i;
  long long int k,bmax,temp,s,temp2;
  scanf("%d",&t);
  while(t--)
  {
      s=0;
      bmax=-99999;
      scanf("%d%lld",&n,&k);
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      for(i=0;i<n;i++)
      {
          scanf("%d",&b[i]);
      }
      for(i=0;i<n;i++)
      {     temp2=a[i];
            temp=temp2*b[i];
            if(bmax<abs(b[i]))
            {
                bmax=abs(b[i]);
            }
            s=s+temp;
      }
      s=s+k*bmax;
      printf("%lld\n",s);
  }

    return 0;
}
