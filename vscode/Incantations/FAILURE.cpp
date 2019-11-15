#include <bits/stdc++.h>
using namespace std;
#define NIL -1
/*
Initialize this graph
*/
class Graph
{
    int V;
    unordered_set<int> *adj;
    vector<int> degrees;
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector<pair<int, int>> &bridges);
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool removeEdge(int v, int w);
    bool removeEdges(vector<pair<int, int>> &edges);
    bool removeEdgesFromVertex(int v);
    void getBridges(vector<pair<int, int>> &bridges);
    bool isCyclic();
    vector<int>& getDegrees();
};

Graph::Graph(int V)
{
    this->V = V+1;
    adj = new unordered_set<int>[V+1];
    degrees = vector<int>(V+1,0);
}

void Graph::addEdge(int v, int w)
{
    adj[v].insert(w);
    adj[w].insert(v);
    degrees[w]++;
    degrees[v]++;
}

bool Graph::removeEdge(int u, int v)
{
    adj[u].erase(v);
    adj[v].erase(u);
    degrees[u]--;
    degrees[v]--;
}
bool Graph::removeEdges(vector<pair<int, int>> &edges)
{
    //cout<<"remove\n";
    int u, v;
    for (int i = 0; i < edges.size(); i++)
    {
        u = edges[i].first, v = edges[i].second;
      //  cout<<u<<" "<<v<<"\n";
        this->removeEdge(u, v);
    }
}
bool Graph::removeEdgesFromVertex(int u)
{
    unordered_set<int>::iterator i;
    vector<pair<int, int>> edges;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        edges.push_back(make_pair(u, *i));
    }
    this->removeEdges(edges);
}

 vector <int>& Graph::getDegrees()
 {
     return this->degrees;
 }
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                       int low[], int parent[],
                       vector<pair<int, int>> &bridges)
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    unordered_set<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;

        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent, bridges);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                bridges.push_back(make_pair(u, v));
            }
        }

        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void Graph::getBridges(vector<pair<int, int>> &bridges)
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 1; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    for (int i = 1; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent, bridges);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    visited[v] = true; 
    unordered_set<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 

bool Graph::isCyclic() 
{ 
    bool *visited = new bool[V]; 
    for (int i = 1; i < V; i++) 
        visited[i] = false; 
    for (int u = 1; u < V; u++) 
        if (!visited[u]) 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
} 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v, mxe, mxd = -1;
        cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g.addEdge(u, v);
        }
        if (!g.isCyclic())
        {
           // cout<<"not inital cyclic\n";
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int>> bridges;
        g.getBridges(bridges);
        //cout<<"bridges\n";
        for (int i = 0; i < bridges.size(); i++)
        {
           // cout<<bridges[i].first<<" "<<bridges[i].second<<"\n";
            g.removeEdge(bridges[i].first, bridges[i].second);
        }
        vector<int> degrees= g.getDegrees();
        for (int i = 1; i <= n; i++)
        {
        //    cout<<degrees[i]<<"sd\n";
            if (degrees[i] > mxd)
            {
                mxd=degrees[i];
                mxe = i;
            }
        }
       // cout<<"mx "<<mxe<<"\n";
        g.removeEdgesFromVertex(mxe);
        if (g.isCyclic())
        {
            cout << "-1\n";
        }
        else
        {
            cout << mxe << "\n";
        }
    }
    return 0;
}
