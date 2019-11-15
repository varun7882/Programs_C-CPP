#include <iostream>
#include<vector>
#include<set>
using namespace std;
typedef int dtype;
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
        e=ans=0;
        cin>>n>>m;
         for(i=1;i<=n;i++)
        {
            v[i]=i;
        }
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>c;
            c=-1*c;
            s.insert(pr(c,p(a,b)));
        }
        for(i=1;i<=m;i++)
        {
            if(e==n-1)
            {
                break;
            }
            it=s.begin();
            a=it->second.first;
            b=it->second.second;
            c=it->first;
            if(root(a)!=root(b))
            {
                Union(a,b);
                ans+=c;
                e++;
            }
        }
        ans=-1*ans;
        cout<<ans<<endl;
        s.clear();
    }
    return 0;
}

