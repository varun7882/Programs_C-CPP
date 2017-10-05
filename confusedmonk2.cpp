#include<iostream>
#include<limits.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        gcd(b,a%b);
    }
}
int main()
{
   long long int a[55],n,i,gx,min=INT_MAX,fx,ans,m=1000000007,b,p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n!=1)
    {

        fx=a[0];
        for(i=1;i<n;i++)
        {
            // p=(p)*(a[i]%m)%m;
            gx=gcd(a[0],a[i]);
            if(gx<min)
            {
                min=gx;
            }
           fx=fx*a[i];
        }
        gx=min;
    }
    else
    {
        fx=gx=a[0];
    }
    //  cout<<fx<<" "<<gx<<endl;
        ans=1;
        p=fx;
        b=gx;
        while(b!=0)
        {
            if(b%2==1)
            {
              //  ans=(ans%m*pow(ans,p)%m)%m;
             //ans=(ans%m*p%m)%m;
             ans=(ans*p)%m;

            }
         //  p=(p%m*2%m)%m;
           // p=(p%m*p%m)%m;
           p=(p*p)%m;
          // p=p%m;
           b=b/2;
        //   cout<<ans<<"ans "<<p<<"p "<<endl;
        }
        cout<<ans<<endl;
    return 0;
}

