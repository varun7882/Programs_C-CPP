#include<iostream>
#include<set>
#include<math.h>
using namespace std;
typedef long long int ll;
ll t;
ll mgcd(ll a,ll b)
{
if(a%b==0)
{
    return b;
}
 else
 {
    return mgcd(b,a%b);
 }
}
int main()
{
    ll a,b,n,lw,hi,ans,t,i;
    set<long long int> s;
    set<long long int>::iterator it;
    cin>>a>>b;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    cin>>n;
  //  cout<<mgcd(a,b);
    t=mgcd(a,b);
    for(i=1;i<=sqrt(t);i++)
    {
        if(t%i==0)
        {
            s.insert(i);
            s.insert(t/i);
        }
    }
    while(n--)
    {
        cin>>lw>>hi;
        t=-1;
         it=s.end();
        while(1)
        {
            it--;
         //   cout<<*it<<endl;
         if(lw<=*it && hi>=*it)
         {
             t=*it;
             break;
         }
            if(it==s.begin())
            {
                break;
            }
        }
        cout<<t<<endl;
    }
}
