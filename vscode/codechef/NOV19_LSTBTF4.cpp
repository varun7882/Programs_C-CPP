#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
unordered_map<long long, bool> squareMap;
unordered_map<long long, string> ans;
unordered_map<int,bool> ansCheck;
string processString(int n,long long bias)
{
    queue<long long> sumq;
    queue<int> posq;
    queue<string> sq;
    string tmp(n, '1');
    if (squareMap[bias+n])
    {
        return tmp;
    }
    long long sum = n;
    for (int i = 1; i < baseSqaures.size(); i++)
    {
        int digit = tmp[n - 1]-'0';
        long long nsum = sum - (digit * digit) + baseSqaures[i];
        string ntmp(tmp);
        ntmp[n - 1] = '0' + (i + 1);
        if (squareMap[bias+nsum])
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
        int sqi=oldstr[oldpos]-'0';
        if(oldpos==0 || oldsum>=81000000)
        {
            continue;
        }
        for (int i = sqi-1; i < baseSqaures.size(); i++)
        {
            int digit = oldstr[oldpos - 1]-'0';
            long long newsum = oldsum - (digit * digit) + baseSqaures[i];
            string ntmp(oldstr);
            ntmp[oldpos - 1] = '0' + (i + 1);
            if (squareMap[newsum+bias])
            {
                sort(ntmp.begin(),ntmp.end());
                return ntmp;
            }
            sumq.push(newsum);
            posq.push(oldpos - 1);
            sq.push(ntmp);
        }
    }
    return "-1";
}

int main()
{
    fastIO;
    int l=28;
    for (long long i = 1; i * i <= 81000001; i++)    {
        squareMap[i * i] = true;
    }

    for (int i = 1; i <= 100; i++)
    {
        cout<<"for i "<<i<<" ";
        if(i<=l)
        {
            cout<<processString(i,0)<<"\n";
        }
        else
        {
            string tmp(i-l,'1');
            string tmp2=processString(l,i-l);
            cout<<tmp+tmp2<<"\n";
        } 
        cout<<"actualAns ";
        cout<<processString(i,0)<<"\n";
     }

    // int t;
    // cin >>t;
    // while (t--)
    // {
    //     int i;
    //     cin >> i;
    //     if(ansCheck[i])
    //     {
    //         cout<<ans[i]<<"\n";
    //         continue;
    //     }
    //     if(i<=l)
    //     {
    //         ans[i]=processString(i,0);
    //     }
    //     else
    //     {
    //         string tmp(i-l,'1');
    //         string tmp2=processString(l,i-l);
    //         ans[i]=tmp+tmp2;
    //     }
    //      cout<<ans[i]<<"\n";
    //     ansCheck[i]=true;
    //  }
}
