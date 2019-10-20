#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define fastIO ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
int mxE = -1;
template <typename T>
void print(vector<T> &vs)
{
    cout << "array\n";
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << "\n";
}
void dfs(int node,int parent,vector<vector<int>>& graph,vector<int>& depth,vector<bool>& isLeave)
{
    for(int i=0;i<graph[node].size();i++)
    {
        if(graph[node][i]!=parent)
        {
            isLeave[node]=false;
            depth[graph[node][i]]=depth[node]+1;
            mxE= max(depth[graph[node][i]],mxE);
            dfs(graph[node][i],node,graph,depth,isLeave);
        }
    }
}
void update(int node,int start,int end,int pos,long long value,vector<long long>& segmentTree)
{
    if(start==end)
    {
        segmentTree[node]+=value;
        return;
    }
    int mid=(start+(end-start)/2);
    if(pos<=mid)
    {
        update(2*node,start,mid,pos,value,segmentTree);
    }   
    else
    {
        update(2*node+1,mid+1,end,pos,value,segmentTree);
    }
    segmentTree[node]=segmentTree[2*node]+segmentTree[2*node+1];
}
long long query(int node,int start,int end,int l,int r,vector<long long>& segmentTree)
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
   return query(2*node,start,mid,l,r,segmentTree)+query(2*node+1,mid+1,end,l,r,segmentTree);
}
void processQuerries(int node,int parent,
                    vector<vector<pair<int,long long>>>& addQuery,
                    vector<vector<pair<int,int>>>& askQuery,
                    vector<vector<int>>& graph,
                    vector<bool>& isLeave,
                    vector<long long>& segmentTree,
                    int size,
                    vector<long long>& ans
)
{
    for(int i=0;i<addQuery[node].size();i++)
    {
        update(1,0,size,addQuery[node][i].first,addQuery[node][i].second,segmentTree);
    }
    for (int i = 0; i < askQuery[node].size(); i++)
    {
        if(!isLeave[node])
        {
            ans[askQuery[node][i].second]=query(1,0,size,askQuery[node][i].first,askQuery[node][i].first,segmentTree);
        }
        else
        {
            ans[askQuery[node][i].second]=query(1,0,size,0,askQuery[node][i].first,segmentTree);
        }
        
    }
    for(int i=0;i<graph[node].size();i++)
    {
        int child= graph[node][i];
        if(child!=parent)
        {
            processQuerries(child,node,addQuery,askQuery,graph,isLeave,segmentTree,size,ans);
        }
    }
     for(int i=0;i<addQuery[node].size();i++)
    {
        update(1,0,size,addQuery[node][i].first,-addQuery[node][i].second,segmentTree);
    }
}
int main()
{
    fastIO;
    int n, q, x, y;
    long long bac;
    char type;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1);
    vector<int> depth(n+1,0);
    vector<bool> isLeave(n+1,true);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,-1,graph,depth,isLeave);
    int sizesegmentTree=4*(mxE+q);
    int ansPointer=0;
    vector<long long> segmentTree;
    segmentTree.resize(sizesegmentTree,0);
    vector<vector<pair<int,long long>>> addQuery(n+1,vector<pair<int,long long>>());
    vector<vector<pair<int,int>>> askQuery(n+1,vector<pair<int,int>>());
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
    vector<long long> ans(ansPointer);
    processQuerries(1,-1,addQuery,askQuery,graph,isLeave,segmentTree,mxE+q,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
}
