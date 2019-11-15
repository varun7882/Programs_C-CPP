#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
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
void update(int position,int value,vector<long long>& fenwickTree)
{
    position++;
    while (position<fenwickTree.size())
    {
        fenwickTree[position]+=value;
        position+=(position&(-position));
    }
}
long long query(int position,vector<long long>& fenwickTree)
{
    long long ans=0;
    position++;
    while (position>0)
    {
        ans+=fenwickTree[position];
        position-=(position&(-position));
    }
    return ans;
}
void processQuerries(int node,int parent,
                    vector<vector<pair<int,long long>>>& addQuery,
                    vector<vector<pair<int,int>>>& askQuery,
                    vector<vector<int>>& graph,
                    vector<bool>& isLeave,
                    vector<long long>& fenwickTree,
                    vector<long long>& ans
)
{
    for(int i=0;i<addQuery[node].size();i++)
    {
        update(addQuery[node][i].first,addQuery[node][i].second,fenwickTree);
    }
    for (int i = 0; i < askQuery[node].size(); i++)
    {
        if(!isLeave[node])
        {
            ans[askQuery[node][i].second]=query(askQuery[node][i].first,fenwickTree)-query(askQuery[node][i].first-1,fenwickTree);
        }
        else
        {
            ans[askQuery[node][i].second]=query(askQuery[node][i].first,fenwickTree);
        }
        
    }
    for(int i=0;i<graph[node].size();i++)
    {
        int child= graph[node][i];
        if(child!=parent)
        {
            processQuerries(child,node,addQuery,askQuery,graph,isLeave,fenwickTree,ans);
        }
    }
     for(int i=0;i<addQuery[node].size();i++)
    {
        update(addQuery[node][i].first,-addQuery[node][i].second,fenwickTree);
    }
}
int main()
{
    fastIO;
    int n, q, x, y;
    long long bac;
    char type;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> depth(n+1,0);
    vector<bool> isLeave(n+1,true);
    vector<long long> bacteria(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,-1,graph,depth,isLeave);
    int sizeFenwickTree=mxE+q+1;
    int ansPointer=0;
    vector<long long> fenwickTree(sizeFenwickTree,0);
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
    processQuerries(1,-1,addQuery,askQuery,graph,isLeave,fenwickTree,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
}
