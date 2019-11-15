#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<long, int>> vs;
        long x, ans = LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            vs.push_back(make_pair(x, i));
        }
        sort(vs.begin(), vs.end());
        for(int i = 0; i < n - 1; i++)
        {
            if(vs[i].second%m!=vs[i+1].second%m)
            {
                ans=min(ans,vs[i+1].first-vs[i].first);
            }
        }
        cout<<ans<<"\n";
    }
}
