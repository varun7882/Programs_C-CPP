#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool vis[1005];
vector<int> v[1005];
vector<int> vs;
void dfsvisit(int i)
{
    vis[i]=true;
    for(int j=0;j<v[i].size();j++)
    {
        if(vis[v[i][j]]==false)
        {
            dfsvisit(v[i][j]);
        }
    }
}
int main()
{
   int n,d,x,y,i,ans;
   set<int> s;
   cin>>n>>d;
   for(i=0;i<d;i++)
   {
       cin>>x>>y;
       v[x].push_back(y);
   }
   for(i=1;i<=n;i++)
   {


   }
     for(i=1;i<=n;i++)
   {
       if(vis[i]==false)
       {
           dfsvisit(i);
       }

   }
    cout<<ans<<endl;
}
