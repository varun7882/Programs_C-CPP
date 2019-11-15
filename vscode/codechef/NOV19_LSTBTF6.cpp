#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
vector<int> baseDiffs{3, 8, 15, 24, 35, 48, 63, 80};
unordered_map<long long, bool> squareMap;
unordered_map<long long, string> ans;
unordered_map<int, bool> ansCheck;
unordered_map<long long, string> sums;
unordered_map<long long, bool> sumsCheck;
queue<long long> gsumq;
queue<int> gposq;
queue<string> gsq;
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
string processString2(int n, long long bias)
{
    queue<long long> sumq;
    queue<int> posq;
    queue<string> sq;
    string tmp(n, '1');
    if (squareMap[bias + n])
    {
        return tmp;
    }
    long long sum = n;
    for (int i = 1; i < baseSqaures.size(); i++)
    {
        int digit = tmp[n - 1] - '0';
        long long nsum = sum - (digit * digit) + baseSqaures[i];
        string ntmp(tmp);
        ntmp[n - 1] = '0' + (i + 1);
        if (squareMap[bias + nsum])
        {
            return ntmp;
        }
        sumq.push(nsum);
        posq.push(n - 1);
        sq.push(ntmp);
    }
    while (!sq.empty())
    {
        long long oldsum = sumq.front();
        sumq.pop();
        string oldstr = sq.front();
        sq.pop();
        int oldpos = posq.front();
        posq.pop();
        int sqi = oldstr[oldpos] - '0';
        if (oldpos == 0 || oldsum >= 81000000)
        {
            continue;
        }
        for (int i = sqi - 1; i < baseSqaures.size(); i++)
        {
            int digit = oldstr[oldpos - 1] - '0';
            long long newsum = oldsum - (digit * digit) + baseSqaures[i];
            string ntmp(oldstr);
            ntmp[oldpos - 1] = '0' + (i + 1);
            if (squareMap[newsum + bias])
            {
                sort(ntmp.begin(), ntmp.end());
                return ntmp;
            }
            sumq.push(newsum);
            posq.push(oldpos - 1);
            sq.push(ntmp);
        }
    }
    return "-1";
}
string processString(int n, long long bias)
{
    string tmp(n, '1');
    if (squareMap[bias + n])
    {
        return tmp;
    }
    long long sum = n;
    string ans = "-1";
    if (gsq.empty())
    {
        for (int i = 1; i < baseSqaures.size(); i++)
        {
            int digit = tmp[n - 1] - '0';
            long long nsum = sum - (digit * digit) + baseSqaures[i];
            string ntmp(tmp);
            ntmp[n - 1] = '0' + (i + 1);
            sumsCheck[nsum] = true;
            sums[nsum] = ntmp;
            if (squareMap[bias + nsum])
            {
                ans= ntmp;
            }
            gsumq.push(nsum);
            gposq.push(n - 1);
            gsq.push(ntmp);
        }
    }
    if(ans!="-1")return ans;
    int minsqrt = (int)sqrt(n + bias);
    long long maxsqr = 81 * (n + bias);
    long long minsqr = (long long)pow(minsqrt + 1, 2);
    long long possibleVal=-1;
    for (int i = minsqrt + 1; i * i <= maxsqr; i++)
    {
        possibleVal = (i * i) - bias;
        if (sumsCheck[possibleVal])
        {
           // cout << sums[possibleVal] << " possible val\n";
           sort(sums[possibleVal].begin(),sums[possibleVal].end());
            if (ans == "-1")
            {
                ans = sums[possibleVal];
            }
            else
            {
                ans = minstring(ans, sums[possibleVal]);
            }
        }
    }
    if (ans != "-1")
    {
        //cout << "got from here\n";
        return ans;
    }
    while (!gsq.empty())
    {
        long long oldsum = gsumq.front();
        gsumq.pop();
        string oldstr = gsq.front();
        gsq.pop();
        int oldpos = gposq.front();
        gposq.pop();
        int sqi = oldstr[oldpos] - '0';
        bool f=false;
        if (oldpos == 0 || oldsum >= 81000000)
        {
            continue;
        }
        for (int i = sqi-1; i < baseSqaures.size(); i++)
        {
            int digit = oldstr[oldpos - 1] - '0';
            long long newsum = oldsum - (digit * digit) + baseSqaures[i];
            string ntmp(oldstr);
            ntmp[oldpos - 1] = '0' + (i + 1);
            if (!sumsCheck[newsum])
            {
                sumsCheck[newsum] = true;
                sums[newsum] = ntmp;
            }
            else
            {
              //  sums[newsum] = minstring(sums[newsum], ntmp);
            }
            gsumq.push(newsum);
            gposq.push(oldpos - 1);
            gsq.push(ntmp);
            if (squareMap[newsum + bias])
            {
                sort(ntmp.begin(), ntmp.end());
                if (ans == "-1")
                {
                    f=true;
                    ans=ntmp;
                }
                else
                {
                    f=true;
                    ans = minstring(ans, ntmp);
                }
            }
        }
        if(f)return ans;
    }
    return ans;
}

int main()
{
    fastIO;
    int l = 30;
    for (long long i = 1; i * i <= 81000001; i++)
    {
        squareMap[i * i] = true;
    }

    // for (int i = 1; i <= 100; i++)
    // {
    //     cout << "for i " << i << " ";
    //     if (i <= l)
    //     {
    //         cout << processString2(i, 0) << "\n";
    //     }
    //     else
    //     {
    //         string tmp(i - l, '1');
    //         string tmp2 = processString(l, i - l);
    //         cout << tmp + tmp2 << "\n";
    //     }
    //     cout << "RealAnsr ";
    //     cout << processString2(i, 0) << "\n";
    // }

    int t;
    for(int i=1;i<=l;i++)
    {
        ans[i]=processString2(i, 0);
        ansCheck[i]=true;
    }
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        if (ansCheck[i])
        {
            cout << ans[i] << "\n";
            continue;
        }
        if (i <= l)
        {
            ans[i] = processString2(i, 0);
        }
        else
        {
            string tmp(i - l, '1');
            string tmp2 = processString(l, i - l);
            ans[i] = tmp + tmp2;
        }
        cout << ans[i] << "\n";
        ansCheck[i] = true;
    }
}