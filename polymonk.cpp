#include<iostream>
#include<math.h>
using namespace std;
double min(double a,double b)
{
    if(a<b)
    {
        return a;
    }
    else
        return b;
}
double max(double a,double b)
{
    if(a>b)
    {
        return a;
    }
    else
        return b;
}
int main()
{
    long int t,a,b,c,k,d;
    double x0,x1,ch,ans;
    cin >>t;
    while(t--)
    {
    cin >>a>>b>>c>>k;
    if((c-k)>=0)
    {
        ans=0;
    }
    else
    {
        c=c-k;
        d=(b*b)-(4*a*c);
//        cout<<d<<endl;
//         cout<<sqrt(d)<<endl;
//         cout<<ceil(sqrt(d))<<endl;
//         cout<<floor(sqrt(d))<<endl;
        x0=(-b+(sqrt(d)))/(2*a);
        x1=(-b-(sqrt(d)))/(2*a);
     // cout <<x0 <<" "<<x1<<endl;
    //cout<<" ch h "<<ch<<endl;
        if(x0<0&&x1<0)
        {
            ans=0;
        }
        else if(x0>0 && x1>0)
        {
            ans=(int)min(x0,x1);
        }
        else
        {
            ans=max(x0,x1);
            if((int)ans!=ans)
            {
                ans++;
                ans=(int)ans;
            }
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
