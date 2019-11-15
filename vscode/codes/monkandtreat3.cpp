#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
bool vis[1005];
vector<int> v[1005];
vector<int> vs;
int dfsvisit(int i)
{
    int c=99999999;
    vis[i]=true;
    vs.push_back(i);
  //  cout<<"vs me gya "<<i<<endl;
    for(int j=0;j<v[i].size();j++)
    {
            if(find(vs.begin(),vs.end(),v[i][j])!=vs.end())
        {
            //cout<<"ver is "<<v[i][j]<<endl;
            c=1;
                 for(int k=vs.size()-1;k>=0;k--)
                 {
                  //   cout<<"ver is "<<v[i][j]<<"k is"<<vs[k]<<endl;
                     if(vs[k]!=v[i][j])
                     c++;
                     else
                     break;
                 }
               //  cout<<"hola "<<c<<endl;
        }
        if(vis[v[i][j]]==false)
        {

            c=min(c,dfsvisit(v[i][j]));
        }
    }
    return c;
}
int main()
{
   int n,d,x,y,i,ans,f=0;
   set<int> s;
   cin>>n>>d;
   for(i=0;i<d;i++)
   {
       cin>>x>>y;
       if(find(v[x].begin(),v[x].end(),y)==v[x].end())
       {
       v[x].push_back(y);
       }
        //v[x].push_back(y);
   }
   for(i=1;i<=n;i++)
   {
       vis[i]=false;

   }
    for(i=1;i<=n;i++)
   {
       if(v[i].empty())
       {
           f=1;
           ans=1;
           break;
       }

   }
   if(f==0)
   {
       ans=9999999;
         for(i=1;i<=n;i++)
       {
           vs.clear();
           if(vis[i]==false)
           {
            ans=min(ans,dfsvisit(i));
           }

       }
   }
    cout<<ans<<endl;
}

