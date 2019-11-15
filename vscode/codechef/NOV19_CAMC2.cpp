#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, int>> vs;
        vector<int> colors(m, 0);
        int countUniqueColor = 0;
        long long x, ans = LONG_MAX, mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
            vs.push_back(make_pair(x, i));
        }
        sort(vs.begin(), vs.end());
        int i, j, color;
        i = 0, j = 0;
        while (i < n)
        {
            color = vs[i].second % m;
            if (colors[color] == 0)
            {
                countUniqueColor++;
            }
            colors[color]++;
            while (countUniqueColor == m && j<n)
            {
                ans = min(ans, vs[i].first - vs[j].first);
                color = vs[j].second % m;
                colors[color]--;
                if (colors[color] == 0)
                {
                    countUniqueColor--;
                }
                j++;
            }
            i++;
        }
        i--;
        while (countUniqueColor == m)
        {
            ans = min(ans, vs[i].first - vs[j].first);
            color = vs[j].second % m;
            colors[color]--;
            if (colors[color] == 0)
            {
                countUniqueColor--;
            }
            j++;
        }
        if (n == m)
        {
            ans = min(ans, mx - mn);
        }
        cout << ans << "\n";
    }
}
