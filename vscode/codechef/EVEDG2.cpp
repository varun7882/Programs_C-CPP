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
        long n, m, u, v, odds, evens;
        odds = evens = 0;
        cin >> n >> m;
        vector<vector<long>> vs(n + 1, vector<long>());
        vector<long> in(n+1,0);
        vector<long> out(n+1,0);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            vs[u].push_back(v);
            vs[v].push_back(u);
            out[u]++;
            in[v]++;
        }
        if (m % 2 == 0)
        {
            cout << "1\n";
            for (int i = 0; i < n; i++)
            {
                cout << "1 ";
            }
        }
        else
        {
            int s;
            for (int i = 1; i <= n; i++)
            {
                if ((in[i]+out[i]) % 2 == 1)
                {
                    odds++;
                    s = i;
                }
                else
                {
                    evens++;
                }
            }
            if (odds == n)
            {
                 cout << n<<"\n";
                for (int i = 0; i < n; i++)
                {
                    cout<<i+1<<" ";
                }
            }
            else
            {
                cout << "2\n";
                for (int i = 0; i < n; i++)
                {
                    if (i+1 == s)
                    {
                        cout << "2 ";
                    }
                    else
                        cout << "1 ";
                }
            }
        }
        cout << "\n";
    }
}