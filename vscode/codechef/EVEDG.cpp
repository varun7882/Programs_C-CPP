#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator
#define mp make_pair
#define up unordered_map
#define M 1000000007
using namespace std;


static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, m, u, v, odds, evens,k;
        odds = evens = 0;
        k=1;
        cin >> n >> m;
        vector<long> ans(n+1,1);
       vector<vector<long>> vs(n+1,vector<long>());
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            vs[u].push_back(v);
            vs[v].push_back(u);
        }
        if (m % 2 == 0)
        {
           //do nothing
        }
        else
        {
            int s=-1;
            evens=-1;
            for (int i = 1; i <= n; i++)
            {
                if ((vs[i].size()) % 2 == 1)
                {
                    odds++;
                    s==-1?s=i:s=s;
                }
                else
                {
                    if(vs[i].size()!=0 && evens==-1)
                    {
                        evens=i;
                    }
                }
                
            }
            if(s!=-1)
            {
                ans[s]=++k;
            }
            else
            {
                ans[evens]=++k;
                ans[vs[evens][0]]=++k;
            }
            
        }
        cout<<k<<"\n";
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout << "\n";
    }
}
