#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
vector<int> baseDiffs{3, 8, 15, 24, 35, 48, 63, 80};
vector<int> diffsDigit(81000000, INT_MAX);
unordered_map<long long, bool> squareMap;
unordered_map<long long, string> ans;
unordered_map<int, bool> ansCheck;
queue<long> q;
queue<int> qd;
int l = 30;
// unordered_map<long long, string> sums;
// unordered_map<long long, bool> sumsCheck;
string minstring(string x, string y)
{
    if (x.size() < y.size())
        return x;
    if (y.size() < x.size())
        return y;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == y[i])
            continue;
        int d1, d2;
        d1 = x[i] - '0';
        d2 = y[i] - '0';
        if (d1 < d2)
            return x;
        return y;
    }
    return x;
}
string getString(string ans, long long diff, int digits)
{
    // if (sumsCheck[diff])
    // {
    //     return sums[diff];
    // }
    if (diff == 0)
    {
        return ans;
    }
    string ret = "-1";
    if (digits == 0)
    {
        if (diff == 0)
        {
            return ans;
        }
        else
        {
            return "-1";
        }
    }
    else
    {
        for (int i = 0; i < baseDiffs.size(); i++)
        {
            char c = (i + 2) + '0';
            if (diff - baseDiffs[i] >= 0)
            {
                int dd=digits-1;
                dd=min(dd,diffsDigit[diff - baseDiffs[i]]);
                ret = getString(ans + c, diff - baseDiffs[i], dd);
            }
            if (ret != "-1" && ret != "")
            {
                // sumsCheck[diff] = true;
                // sums[diff] = ans;
                return ret;
            }
        }
    }
    return ret;
}
string getAnswer(int n, int bias)
{
    if (squareMap[n + bias])
    {
        string ans(n + bias, '1');
        return ans;
    }
    int minsqrt = (int)sqrt(n + bias);
    long long minsqr = (long)pow(minsqrt + 1, 2);
    long long maxsqr = 81 * (n + bias);
    unordered_map<long long, vector<int>> digits;
    int mn = INT_MAX;
    string ans = "-1";
    for (long long i = minsqrt + 1; i * i <= maxsqr; i++)
    {
        long long sqr = i * i;
        long long diff = sqr - bias - n;
        //cout<<diff<<"sdds \n";
        if (diffsDigit[diff] != INT_MAX)
        {
            mn = min(mn, diffsDigit[diff]);
            digits[diffsDigit[diff]].push_back(diff);
        }
    }
    while (!q.empty() && mn==INT_MAX)
    {
        long sum = q.front();
        q.pop();
        int digit = qd.front();
        qd.pop();
        if (digit >= l)
        {
            break;
        }
        if (sum >= 81000000)
            continue;
        for (int i = 0; i < baseDiffs.size(); i++)
        {
            if (diffsDigit[sum + baseDiffs[i]] == INT_MAX)
            {
                diffsDigit[sum + baseDiffs[i]] = digit + 1;
                q.push(sum + baseDiffs[i]);
                qd.push(digit + 1);
            }
        }
        if(squareMap[sum+bias+n])
        {
            mn=diffsDigit[sum];
            digits[mn].push_back(sum);
            break;
        }
    }
    //cout<<mn<<"sfs\n";
    for (int i = 0; i < digits[mn].size(); i++)
    {
        if (ans == "-1")
        {
            ans = getString("", digits[mn][i], mn);
        }
        else
        {
            ans = minstring(ans, getString("", digits[mn][i], mn));
        }
    }
    if (n + bias > ans.size())
    {
        string tmp(n + bias - ans.size(), '1');
        sort(ans.begin(), ans.end());
        ans = tmp + ans;
    }

    return ans;
}
int main()
{
    fastIO;
    
    for (long long i = 1; i * i <= 81000001; i++)
    {
        squareMap[i * i] = true;
    }
    for (int i = 0; i < baseDiffs.size(); i++)
    {
        diffsDigit[baseDiffs[i]] = 1;
        q.push(baseDiffs[i]);
        qd.push(1);
    }
    
    // cout << "hello\n";
    // for (int i = 1; i <= 100; i++)
    // {
    //     if (i <= l)
    //     {
    //         cout << getAnswer(i, 0) << "\n";
    //     }
    //     else
    //     {
    //         cout << getAnswer(l, i - l) << "\n";
    //     }
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        // if (ansCheck[i])
        // {
        //     cout << ans[i] << "\n";
        //     continue;
        // }
        if (i <= l)
        {
            ans[i] = getAnswer(i, 0);
        }
        else
        {
            ans[i] = getAnswer(l, i - l);
        }
        ansCheck[i] = true;
        cout << ans[i] << "\n";
    }
}