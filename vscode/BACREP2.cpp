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
static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

void printGraph(vector<vector<int>> &graph)
{
    cout << "Graph is \n";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "node " << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "-->" << graph[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
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
void bacteriaSpread(vector<vector<int>>& graph, vector<long long>& bacteria,int node,long long bac,int p)
{
    long long currbac=bacteria[node];
    bool ispassed=false;
    for (int  i = 0; i < graph[node].size(); i++)
    {
        if(graph[node][i]!=p)
        {
            ispassed=true;
            bacteriaSpread(graph,bacteria,graph[node][i],currbac,node);
        }
    }
    if(ispassed)
    {
        bacteria[node]=bac;
    }
    else
    {
        bacteria[node]+=bac;
    }
    
}
int main()
{
    int n, q, x, y;
    long long bac;
    char type;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<long long> bacteria(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //    printGraph(graph);
    for (int i = 0; i < n; i++)
    {
        cin >> bacteria[i + 1];
    }
    print(bacteria);
    for (int i = 0; i < q; i++)
    {
        bacteriaSpread(graph,bacteria,1, 0,-1);
        print(bacteria);
        cin >> type;
        if (type == '?')
        {
            cin >> x;
            cout << bacteria[x] << "\n";
        }
        else
        {
            cin >> x >> bac;
            bacteria[x] += bac;
        }
    }
}
