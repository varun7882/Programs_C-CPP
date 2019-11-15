#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
unordered_map<long long, bool> squareMap;
unordered_map<long long, string> ans;
string processString(int n)
{
    string tmp(n, '1');
    long long sum = n;
    int ilast = n - 1;
    int isecondLast = n - 2;
    int ithirdLast = n - 3;
    int ifourthLast = n - 4;
    for (int h = 0; h < baseSqaures.size(); h++)
    {
        long long fsl = '0' - tmp[ifourthLast];
        fsl *= fsl;
        sum = sum - fsl;
        tmp[ifourthLast] = '0' + (h + 1);
        sum = sum + (baseSqaures[h]);
        for (int g = h; g < baseSqaures.size(); g++)
        {
            long long tsl = '0' - tmp[ithirdLast];
            tsl *= tsl;
            sum = sum - tsl;
            tmp[ithirdLast] = '0' + (g + 1);
            sum = sum + (baseSqaures[g]);
            for (int i = g; i < baseSqaures.size(); i++)
            {
                long long sl = '0' - tmp[isecondLast];
                sl *= sl;
                sum = sum - sl;
                tmp[isecondLast] = '0' + (i + 1);
                sum = sum + (baseSqaures[i]);
                for (int j = i; j < baseSqaures.size(); j++)
                {
                    long long ll = '0' - tmp[ilast];
                    ll *= ll;
                    sum = sum - ll;
                    tmp[ilast] = '0' + (j + 1);
                    sum = sum + (baseSqaures[j]);
                    if (squareMap[sum])
                    {
                        // cout<<"for n "<<n<<" square is "<<sum<<"\n";
                        sort(tmp.begin(), tmp.end());
                        return tmp;
                    }
                }
            }
        }
    }
    // cout << "YE DEKHO WRONG ANSWER\n";
    return tmp;
}
string getNumber(string s, int pos, long long sum)
{
    if (squareMap[sum])
    {
        return s;
    }
    if (pos < 0)
    {
        return "-1";
    }
    char c = s[pos];
    long long osum = sum;
    bool f=true;
    for (int i = 1; i < baseSqaures.size(); i++)
    {
        int digit = '0' - s[pos];
        sum = sum - (digit * digit);
        sum = sum + baseSqaures[i];
        s[pos] = '0' + (i+1);
        if (squareMap[sum])
        {
            sort(s.begin(),s.end());
            return s;
        }
    }
    s[pos]=c;
    sum=osum;
    string ans="-1";
    for (int i = 1; i < baseSqaures.size(); i++)
    {
        int digit = '0' - s[pos];
        sum = sum - (digit * digit);
        sum = sum + baseSqaures[i];
        s[pos] = '0' + (i+1);
        string res=getNumber(s,pos-1,sum);
        s[pos]=c;
        sum=osum;
        if(res!="-1")
        {
            return res;
        }
    }
    return ans;
}
int main()
{
    fastIO;
    for (long long i = 1; i * i <= 1000001; i++)
    {
        squareMap[i * i] = true;
    }
    ans[1] = "1";
    ans[2] = "34";
    ans[3] = "122";
    ans[4] = "1111";
    for (int i = 1; i <= 100; i++)
    {
        if(i>4)
        ans[i] = processString(i);
        cout << "for i " << i << " ans " << ans[i] << "\n";
        string tmp(i,'1');
        //cout<< "for i "<<i<<" ans recursive "<<getNumber(tmp,i-1,i)<<"\n";
    }
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     string tmp(n,'1');
    //     cout<<getNumber(tmp,n-1,n)<<"\n";
    // }
}
