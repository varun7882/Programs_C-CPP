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
        vector<long long> vs;
        long long x, ans = LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            vs.push_back(x);
        }
        for(int i=0;i<=n-m;i++)
        {
            for(int j=i+m-1;j<n;j++)
            {
                if(i%m!=j%m)
                {
                    ans=min(ans,abs(vs[i]-vs[j]));
                }
            }
        }
        cout<<ans<<"\n";
    }
}
