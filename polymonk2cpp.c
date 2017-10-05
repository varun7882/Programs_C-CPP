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
            if(x0<0 && x1<0)
                ans=0;
            else if(x0>0 && x1>0){
                if(x0>x1)
                    ans=x1;
                else
                    ans=x0;
            }
            else{
                if(x0>=0){
                    if((int)x0 == x0)
                        ans=x0;
                    else
                        ans=x0+1;
                }
                else{
                    if((int)x1 == x1)
                        ans=x1;
                    else
                        ans=x1+1;
                }
    }
    cout<<ans<<endl;
    }
    return 0;
}

