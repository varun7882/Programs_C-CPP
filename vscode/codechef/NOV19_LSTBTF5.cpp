#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
vector<int> baseDiffs{3, 8, 15, 24, 35, 48, 63, 80};
;
unordered_map<long long, bool> squareMap;
unordered_map<long long, string> ans;
unordered_map<int, bool> ansCheck;
unordered_map<long long, string> sums;
unordered_map<long long, bool> sumsCheck;
unordered_map<long long, int> diffDigits;
queue<long long> sumq;
queue<int> posq;
queue<string> sq;
int pos = 0;
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
int getDigits(long long val)
{
    if (diffDigits[val] != 0)
    {
        return diffDigits[val];
    }
    int ret = INT_MAX;
    for (int i = 0; i < baseDiffs.size(); i++)
    {
        if (val - baseDiffs[i] > 0)
        {
            ret = min(ret, getDigits(val - baseDiffs[i]));
        }
    }
    if (ret == INT_MAX)
        return ret;
    diffDigits[val] = ret + 1;
    return ret + 1;
}
string processString2(int n, long long bias)
{
    queue<long long> lsumq;
    queue<int> lposq;
    queue<string> lsq;
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
        lsumq.push(nsum);
        lposq.push(n - 1);
        lsq.push(ntmp);
    }
    while (!lsq.empty())
    {
        long long oldsum = lsumq.front();
        lsumq.pop();
        string oldstr = lsq.front();
        lsq.pop();
        int oldpos = lposq.front();
        lposq.pop();
        int sqi = oldstr[oldpos] - '0';
        if (oldpos == 0)
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
            lsumq.push(newsum);
            lposq.push(oldpos - 1);
            lsq.push(ntmp);
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
    if (sq.empty())
    {
        for (int i = 1; i < baseSqaures.size(); i++)
        {
            int digit = tmp[n - 1] - '0';
            long long nsum = sum - (digit * digit) + baseSqaures[i];
            string ntmp(tmp);
            ntmp[n - 1] = '0' + (i + 1);
            pos = 1;
            if (!sumsCheck[nsum])
            {
                sumsCheck[nsum] = true;
                sums[nsum] = ntmp;
            }
            sumq.push(nsum);
            posq.push(n - 1);
            sq.push(ntmp);
        }
    }
    int minsqrt = (int)sqrt(n + bias);
    long long maxsqr = 81 * (n + bias);
    long long minsqr = (long long)pow(minsqrt + 1, 2);
    long long possibleVals;
    int digits = INT_MAX;
    long long sumNeeded = LONG_LONG_MAX;
    for (int i = minsqrt + 1; i * i <= maxsqr; i++)
    {
        possibleVals = (i * i) - bias;
        long long diff = possibleVals - n;
        int tmp = getDigits(diff);
        if (digits > tmp)
        {
            digits = tmp;
        }
    }
    // cout<<"digits is "<<digits<<"\n";
    if (digits == INT_MAX)
    {
        //cout<<""
        return "integer maximum";
    }
    bool f = true;
    while (!sq.empty() && digits >= pos)
    {
        // if (f)
        // {
        //     f = false;
        //     cout << "in case of " << (n + bias) << "\n";
        // }
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
            pos = n - oldpos + 1;
            long long newsum = oldsum - (digit * digit) + baseSqaures[i];
            string ntmp(oldstr);
            ntmp[oldpos - 1] = '0' + (i + 1);
            string ttmp(ntmp);
            if (!sumsCheck[newsum])
            {
                sumsCheck[newsum] = true;
                sort(ntmp.begin(), ntmp.end());
                sums[newsum] = ntmp;
            }
            else
            {
                sort(ntmp.begin(), ntmp.end());
                sums[newsum] = minstring(sums[newsum], ntmp);
            }
            // if(pos==3)
            // {
            //     cout<<ntmp<<"\n";
            // }
            ntmp = ttmp;
            sumq.push(newsum);
            posq.push(oldpos - 1);
            sq.push(ntmp);
        }
    }
    string ans = "-1";
    for (int i = minsqrt + 1; i * i <= maxsqr; i++)
    {
        possibleVals = (i * i) - bias;
        if (sumsCheck[possibleVals])
        {
            if(ans=="-1")
            {
                ans=sums[possibleVals];
            }
            else
            {
                ans=min(ans,sums[possibleVals]);
            }
        }
    }

    return ans;
}

int main()
{
    fastIO;
    int l = 26;
    for (int i = 0; i < baseDiffs.size(); i++)
    {
        diffDigits[baseDiffs[i]] = 1;
    }
    for (long long i = 1; i * i <= 81000001; i++)
    {
        squareMap[i * i] = true;
    }

    for (int i = 1; i <= 10; i++)
    {
        string ans;
        cout << "for i " << i << " ";
        if (i <= l)
        {
            cout << processString2(i, 0) << "\n";
        }
        else
        {
            string tmp(i - l, '1');
            string tmp2 = processString(l, i - l);
            ans = tmp + tmp2;
            cout << tmp + tmp2 << "\n";
        }
        cout << "RealAnsr ";
        string ac = processString2(i, 0);
        cout << ac << "\n";
        // if (ac != ans)
        // {
        //     //cout<<"WRONG ANSWER for "<<i<<"\n";
        // }
    }

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int i;
    //      cin>>i;
    //     if (ansCheck[i])
    //     {
    //         cout << ans[i] << "\n";
    //         continue;
    //     }
    //     if (i <= l)
    //     {
    //         ans[i] = processString2(i, 0);
    //     }
    //     else
    //     {
    //         string tmp(i - l, '1');
    //         string tmp2 = processString(l, i - l);
    //         ans[i] = tmp + tmp2;
    //     }
    //     cout << ans[i] << "\n";
    //     ansCheck[i] = true;
    // }
}
