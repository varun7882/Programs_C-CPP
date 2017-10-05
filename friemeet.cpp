#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int dty;
typedef pair<dty,dty> p;
dty ans=0;
dty vis[50005];
dty ms[50005];
vector<p> tr[50005];
dty gcd(dty x,dty y)
{
    if(y==1)
    {
        return 1;
    }
    if(y==0)
    {
        return x;
    }
    if(x%y==0)
    {
        return y;
    }
    else
    {
        gcd(y,x%y);
    }
}
void dfs(dty pr,dty u,dty m)
{
    if(ms[u])
    {
        vis[u]=1;
    }
    else
    {
        vis[u]=0;
    }
    for(int i=0;i<tr[u].size();i++)
    {
        p p1=tr[u][i];
        if(p1.first!=pr)
        {
        dfs(u,p1.first,m);
        vis[u]=vis[u]+vis[p1.first];
       // cout<<"hey "<<vis[p1.first]<<endl;
        ans=ans+(vis[p1.first]*(m-vis[p1.first])*(dty)2*(p1.second));
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        dty u,v,l,n,m,i,j,num,den;
        cin>>n>>m;
        ans=0;
         for(i=1;i<=n;i++)
        {
           tr[i].clear();
           ms[i]=vis[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            cin>>u>>v>>l;
           tr[u].push_back(p(v,l));
           tr[v].push_back(p(u,l));

        }
        for(i=0;i<m;i++)
        {
            cin>>l;
            ms[l]=1;
        }
       // cout<<"here1";
        dfs(0,1,m);
         //cout<<"here2";
        den=m*m;
        num=ans;
       // cout<<ans<<" "<<den;
       if(num>den)
        l=gcd(num,den);
        else
            l=gcd(den,num);
         //   l=__gcd(num,den);
       // cout<<"here4";
        cout<<num/l<<" "<<den/l<<endl;
    }
    return 0;
}
