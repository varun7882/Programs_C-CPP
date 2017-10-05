#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v[101];
vector<int> vis(101,0);
vector<int> deg(101,0);
int c=0;
void DFSvisit(int x)
{
    int i,tmp=0,j;
    vis[x]=1;
    for(i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]==0)
        {
            DFSvisit(v[x][i]);
            if(deg[v[x][i]]%2==0)
            {
                //cout<<"ok"<<endl;
                c++;
                for(j=0;j<v[v[x][i]].size();j++)
                {
                    if(v[v[x][i]][j]%2==0)
                    {
                        tmp=v[v[x][i]][j];
                        break;
                    }
                }
                if(tmp!=0)
                {
                deg[tmp]--;
                }
                else
                {
                  deg[v[v[x][i]][0]]--;
                }
                deg[v[x][i]]--;
            }
        }
    }
}

int main() {
    int n,e,x,y,te,i;
    cin>>n>>e;
     te=e;
     while(te--)
     {
         cin>>x>>y;
         deg[x]++;
         deg[y]++;
         v[x].push_back(y);
         v[y].push_back(x);
     }
     for(i=1;i<=n;i++)
     {
        if(vis[i]==0)
        DFSvisit(i);
     }
     cout<<c<<endl;
    return 0;
}

