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
void print(vector<int>& vs)
{
    for(int i=0;i<vs.size();i++){
        cout<<vs[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q; 
        long odds = 0;
        cin >> n >> m >> q;
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            rows[x - 1]++;
            cols[y - 1]++;
        }
        cout<<"rows\n";
        print(rows);
        cout<<"cols\n";
        print(cols);
        int rodds = 0, revens = 0;
        for (int i = 0; i < n; i++)
        {
            if (rows[i] % 2 != 0)
            {
                rodds++;
            }
            else
            {
                revens++;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(cols[i]%2!=0)
            {
               
                odds+=revens;
            }
            else
            {
                odds+=rodds;
            }
        }
        cout << odds << "\n";
         int ans=0;
         for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
           {
               if((rows[i]+cols[j])%2!=0)
               {
                  ans++;
               }
           }
       }
       cout<<"actual ans "<<ans<<"\n";
    }
}
