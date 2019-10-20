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
vector<int>  getSum(vector<vector<int>> &bit, int index)
{
    vector<int> vs(26,0);
    index = index + 1;
    while (index > 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (bit[index][i])
            {
                vs[i]+=bit[index][i];
            }
        }
        index -= index & (-index);
    }
    return vs;
}

void updateAdd(vector<vector<int>> &bit, int n, int index, char val)
{
    index = index + 1;
    while (index <= n)
    {
        bit[index][val - 'a']++;
        index += index & (-index);
    }
}
void updateDelete(vector<vector<int>> &bit, int n, int index, char val)
{
    index = index + 1;
    while (index <= n)
    {
        bit[index][val - 'a']--;
        index += index & (-index);
    }
}
int main()
{
    string s;
    char c;
    int n, q, type, l, r, pos;
    cin >> s;
    cin >> q;
    n = s.size();
    vector<vector<int>> bit(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        updateAdd(bit, n, i, s[i]);
    }
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
        //   cout << "case 1\n";
            cin >> pos >> c;
            pos--;
            updateDelete(bit, n, pos, s[pos]);
            s[pos] = c;
            updateAdd(bit, n, pos, c);
        //    cout << "case 1 updated: " << s << "\n";
        }
        else
        {
        //    cout << "case 2\n";
            cin >> l >> r;
            l--;
            r--;
            if (l != r)
            {
                int ans=0;
                vector<int> sr=getSum(bit, r);
                vector<int> sl=getSum(bit, l - 1);
                for(int i=0;i<26;i++)
                {
                    sr[i]-=sl[i];
                    if(sr[i])
                    {
                        ans++;
                    }
                }
                cout << ans<< "\n";
            }
            else
            {
                cout << "1\n";
            }
        }
    }
}
