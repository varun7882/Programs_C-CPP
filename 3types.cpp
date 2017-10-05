#include <iostream>
#include<vector>
#include<queue>
using namespace std;
typedef int dtype;
typedef pair<dtype,dtype>p;
dtype vis[1001];
dtype vis2[1001];
dtype vis1[1001];
vector<p> v[1001];
dtype edgs[1001][4];
int main()
{   dtype n,m,a,b,c,i,f,ans,wt,vt;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(p(c,b));
        v[b].push_back(p(c,a));
        edgs[a][c]=1;
        edgs[b][c]=1;
    }
    f=c=0;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        vis2[i]=0;
        vis1[i]=0;
    }
    //cout<<"hey";
    for(i=1;i<=n;i++)
    {
       if(edgs[i][3]==1 || (edgs[i][1]==1&&edgs[i][2]==1))
       {
           continue;
       }
       else
       {
           f=1;
           break;
       }
    }
    // cout<<"hey 2";
    if(f==1)
    {
        ans=-1;
        cout<<ans<<endl;
    }
    else
    {
        ans=-1;
        priority_queue<p> pq;
        p tp;
        for(i=1;i<=n;i++)
        {
        vis[i]=0;
        }
        pq.push(p(10,1));
        while(!pq.empty())
        {
            tp=pq.top();pq.pop();
            wt=tp.first;
            vt=tp.second;
            if(vis[vt]==0)
            {
                if(wt>=3)
                {
                ans++;
                vis[vt]=1;
                for(i=0;i<v[vt].size();i++)
                {
                    pq.push(v[vt][i]);
                }
                }
                else if(wt==2)
                {

                    if(vis2[vt]==0)
                    {
                        vis2[vt]=1;
                        ans++;
                        for(i=0;i<v[vt].size();i++)
                        {
                        pq.push(v[vt][i]);
                        }
                    }
                    if(vis1[vt]==1)
                    {
                        vis[vt]=1;
                    }

                }
                else
                {
                    if(vis1[vt]==0)
                    {
                        vis1[vt]=1;
                        ans++;
                        for(i=0;i<v[vt].size();i++)
                        {
                        pq.push(v[vt][i]);
                        }
                    }
                    if(vis2[vt]==1)
                    {
                        vis[vt]=1;
                    }

                }
            }
           // cout<<"ans: "<<ans<<endl;
        }
        cout<<m-ans<<endl;
    }
    return 0;
}

