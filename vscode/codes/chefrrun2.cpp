#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long int dty;
vector<dty>vis(1000001);
vector<dty>chk(1000001);
vector<dty>v[1000001];
set<dty> s;
dty f=0;
void dfsvisit(dty i)
{
    vis[i]=1;
    dty j;
   // cout<<"vistied "<<i<<endl;
    for(j=0;j<v[i].size();j++)
    {
        if(!vis[v[i][j]])
        {
        dfsvisit(v[i][j]);
        }
    if(s.find(v[i][j])==s.end() && f==0 && !chk[v[i][j]] )
    {
    s.insert(v[i][j]);
    chk[v[i][j]]=1;
    }
    else
    {
        f=1;
    }
    }
}
int main()
{
    dty t,n,i,cf,ti,x,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
         vector<dty>a(n+1);
        fill(vis.begin(),vis.end(),0);
         fill(chk.begin(),chk.end(),0);
        for(i=1;i<=n;i++)
        {
            cin>>x;
            a[i]=x;
            ti=i+x+1;
            if(ti>n)
            {
                cf=ti/n;
                ti=ti-(cf*n);
            }
            v[i].push_back(ti);
        }
        for(i=1;i<=n;i++)
        {
            f=0;
            if(!vis[i])
            {
                dfsvisit(i);
            }
            ans+=s.size();
            s.clear();
        }
        cout<<ans<<endl;
        for(i=1;i<=n;i++)
        {
        v[i].clear();
        }
    }
    return 0;
}

