#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define MAXSIZE 500005
#define fastIO ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
int mxE = -1,sz;
vector<int> graph[MAXSIZE];
vector<int> depth(MAXSIZE);
vector<bool> isLeave(MAXSIZE,true);
vector<long long> segmentTree;
vector<pair<int,long long>> addQuery[MAXSIZE];
vector<pair<int,int>> askQuery[MAXSIZE];
vector<long long> ans(MAXSIZE);
void dfs(int node,int parent)
{
    for(int i=0;i<graph[node].size();i++)
    {
        if(graph[node][i]!=parent)
        {
            isLeave[node]=false;
            depth[graph[node][i]]=depth[node]+1;
            mxE= max(depth[graph[node][i]],mxE);
            dfs(graph[node][i],node);
        }
    }
}
void update(int node,int start,int end,int pos,long long value)
{
    if(start==end)
    {
        segmentTree[node]+=value;
        return;
    }
    int mid=(start+(end-start)/2);
    if(pos<=mid)
    {
        update(2*node,start,mid,pos,value);
    }   
    else
    {
        update(2*node+1,mid+1,end,pos,value);
    }
    segmentTree[node]=segmentTree[2*node]+segmentTree[2*node+1];
}
long long query(int node,int start,int end,int l,int r)
{
   if(l> end || r<start)
   {
       return 0;
   }
   if(l<=start  && r>= end)
   {
       return segmentTree[node];
   }
   int mid=(start+(end-start)/2);
   return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}
void processQuerries(int node,int parent)
{
    for(int i=0;i<addQuery[node].size();i++)
    {
        update(1,0,sz,addQuery[node][i].first,addQuery[node][i].second);
    }
    for (int i = 0; i < askQuery[node].size(); i++)
    {
        if(!isLeave[node])
        {
            ans[askQuery[node][i].second]=query(1,0,sz,askQuery[node][i].first,askQuery[node][i].first);
        }
        else
        {
            ans[askQuery[node][i].second]=query(1,0,sz,0,askQuery[node][i].first);
        }
        
    }
    for(int i=0;i<graph[node].size();i++)
    {
        int child= graph[node][i];
        if(child!=parent)
        {
            processQuerries(child,node);
        }
    }
     for(int i=0;i<addQuery[node].size();i++)
    {
        update(1,0,sz,addQuery[node][i].first,-addQuery[node][i].second);
    }
}
int main()
{
    fastIO;
    int n, q, x, y;
    long long bac;
    char type;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,-1);
    sz=(mxE+q);
    int sizesegmentTree=4*(mxE+q);
    segmentTree.resize(sizesegmentTree,0);
    int ansPointer=0;
    for(int i=1;i<=n;i++)
    {
        cin>>bac;
        addQuery[i].push_back({mxE+0-depth[i],bac});
    }
    for(int i=1;i<=q;i++)
    {
        cin>>type;
        if(type=='+')
        {
            cin>>x>>bac;
            addQuery[x].push_back({mxE+i-depth[x],bac});
        }
        else
        {
            cin>>x;
            askQuery[x].push_back({mxE+i-depth[x],ansPointer++});
        }
    }
    processQuerries(1,-1);
    for(int i=0;i<ansPointer;i++)
    {
        cout<<ans[i]<<"\n";
    }
}
