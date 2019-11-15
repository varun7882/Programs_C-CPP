#include<iostream>
#include<set>
using namespace std;
typedef int dty;
typedef pair<dty,dty>p;
int main()
{
    dty t,n,k,i,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ans=0;
        multiset<p> s;
        multiset<p>::iterator it;
        for(i=0;i<n;i++)
        {
            cin>>x;
            s.insert(p(__builtin_popcount(x),x));
        }
        it=s.end();
        it--;
        while(k--)
        {
            ans=ans+it->first;
            if(it==s.begin())
            {
                break;
            }
            it--;
        }
         cout<<ans<<endl;
    }

    return 0;
}
