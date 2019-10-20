#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator 
#define mp make_pair
#define up unordered_map
#define M 1000000007
static auto ___ =  []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

void dfsGetParent(vector<vector<int>>& graph,int s,int p,vector<int>& parent)
{
    parent[s]=p;
    for(int i=0;i<graph[s].size();i++)
    {
        if(p!=graph[s][i])
        {
            dfsGetParent(graph,graph[s][i],s,parent);
        }
    }
}
void bacteriaSpread(vector<vector<int>>& graph,vector<long long>& bacteria,vector<int>& parent,vector<int>& leaves)
{
    queue<int> q;
    vector<bool> visited(graph.size(),false);
    int p,s;
    for(int i=0;i<leaves.size();i++)
    {
        q.push(leaves[i]);
        visited[leaves[i]]=true;
    }
    while (!q.empty())
    {
       // cout<<"are you even running\n";
        s=q.front();
         q.pop();
        if(graph[s].size()!=1) 
        bacteria[s]=0;
        p=parent[s];
        if(p==-1)
        {
            continue;
        }
        bacteria[s]+=bacteria[p];
        if(!visited[p])
        {
            visited[p]=true;
            q.push(p);
        }
    }
    bacteria[1]=0;
}
void printGraph(vector<vector<int>>& graph)
{
    cout<<"Graph is \n";
    for(int i=0;i<graph.size();i++)
    {
        cout<<"node "<<i;
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<"-->"<<graph[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
template <typename T> 
void print(vector<T>& vs)
{
    cout<<"array\n";
    for(int i=0;i<vs.size();i++)
    {
        cout<<vs[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n,q,x,y;
    long long bac;
    char type;
    cin>>n>>q;
    vector<int> parent(n+1,-2);
    vector<vector<int>> graph(n+1,vector<int>());
    vector<long long> bacteria(n+1,0);
    vector<int> leaves;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
//    printGraph(graph);
    for(int i=0;i<n;i++)
    {
        if(graph[i+1].size()==1 && i!=0)
        {
            leaves.push_back(i+1);
        }
        cin>>bacteria[i+1];  
    }
    dfsGetParent(graph,1,-1,parent);
  // print(parent);
  print(bacteria);
    for (int i = 0; i <q; i++)
    {
        bacteriaSpread(graph,bacteria,parent,leaves);
       print(bacteria);
        cin>>type;
        if(type=='?')
        {
            cin>>x;
            cout<<bacteria[x]<<"\n";
        }
        else
        {
            cin>>x>>bac;
            bacteria[x]+=bac;
        }
    }
    
    
}
