#include<bits/stdc++.h>

#define MAX 500005

typedef long long ll;

using namespace std;

vector<int> adj[MAX], depth(MAX);
vector<bool> leaf(MAX, true);

// to store the quries at the asked node
vector<pair<int, ll>> updates[MAX];
vector<pair<int, int>> queries[MAX];

// stores the result of queries
vector<ll> res(MAX);

/* mxh = store the max depth
   shift = store the minimum value to add so as to make every index positive
   tme = value of running time
   res_index = to order the result properly
   sz = represent size of the segment tree
*/
int mxh = 0, shift, tme = 0, res_index = 0, sz;

// represent the tree itself
vector<ll> tree;

// ============= segment tree related code =================
// to add vl at the pos 
void update(int v, int l, int r, int pos, ll vl){
    if( l == r ){
        tree[v] += vl;
        return;
    }
    int md = (l+r)/2;
    if(pos <= md)
        update(2*v, l, md, pos, vl);
    else
        update(2*v+1, md+1, r, pos, vl);
    tree[v] = tree[2*v] + tree[2*v+1];
}

// to query sum of values from indices st to en
ll query(int v, int l, int r, int st, int en){
    if( st > r || en < l )
        return 0;
    if( st <= l && en >= r )
        return tree[v];
    int md = (l+r)/2;
    return query(2*v, l, md, st, en) + query(2*v+1, md+1, r, st, en);
}

// calculate depth, leaf status of every node
void dfs(int n, int p){
    for(int nei : adj[n]){
        if(nei != p){
            depth[nei] = depth[n]+1;
            mxh = max(mxh, depth[nei]);
            leaf[n] = false;
            dfs(nei, n);
        }
    }
}

void solve(int n, int p){
    // updating each query of node n
    for(auto up : updates[n]){
        update(1, 0, sz, up.first, up.second);
    }

    // calculating results as now segment tree contains all the updates from root to n
    for(auto qr : queries[n]){
        if(leaf[n])
            res[qr.second] = query(1, 0, sz, 0, qr.first);
        else
            res[qr.second] = query(1, 0, sz, qr.first, qr.first);
    }

    // proceeding down the graph
    for(int nei : adj[n])
        if( nei != p )
            solve(nei, n);

    // removing the updates as they are not required now
    for(auto up : updates[n]){
        update(1, 0, sz, up.first, -up.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, a, b;
    char c;
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    shift = mxh;
    sz = shift+q;
    tree.resize(4*(shift+q), 0);
    for(int i = 1; i <= n; i++){
        cin >> a;
        updates[i].push_back({shift+0-depth[i], a});
    }
    for(int i = 0; i < q; i++){
        tme++;
        cin >> c >> a;
        if(c == '+'){
            cin >> b;
            updates[a].push_back({shift+tme-depth[a], b});
        }else{
            queries[a].push_back({shift+tme-depth[a], res_index++});
        }
    }

    solve(1, 0);

    for(int i = 0; i < res_index; i++)
        cout << res[i] << endl;

    return 0;
}
