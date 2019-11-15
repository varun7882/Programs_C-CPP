#include <iostream>
#include<vector>
#include<set>
#define mod 1000000007
using namespace std;
typedef long long int dtype;
typedef pair<dtype,dtype>p;
typedef pair<dtype,p>pr;
dtype v[5001];
dtype root(dtype i)
{
    dtype x=i;
    while(v[x]!=x)
    {
        v[x]=v[v[x]];
        x=v[x];
    }
    return x;
}
void Union(dtype x, dtype y)
{
    dtype rx,ry;
    rx=root(x);
    ry=root(y);
    v[rx]=v[ry];
}
int main()
{
    dtype t,n,m,a,b,c,i,ans,e;
    set<pr> s;
    set<pr> ::iterator it;
    cin>>t;
    while(t--)
    {
        e=0;
        ans=1;
        cin>>n>>m;
         for(i=1;i<=n;i++)
        {
            v[i]=i;
        }
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>c;
            s.insert(pr(c,p(a,b)));
        }
        it=s.begin();
        for(i=1;i<=m;i++)
        {
            if(e==n-1)
            {
                break;
            }
            a=it->second.first;
            b=it->second.second;
            c=it->first;
            if(root(a)!=root(b))
            {
                Union(a,b);
                ans=(ans%mod*c%mod)%mod;
                e++;
            }
            it++;
        }
        cout<<ans<<endl;
        s.clear();
    }
    return 0;
}

