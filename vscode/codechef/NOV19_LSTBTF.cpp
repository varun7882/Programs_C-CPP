#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
unordered_map<long, vector<vector<int>>> dpFreq;
unordered_map<long, bool> dpCheck;
unordered_map<int, vector<int>> ans;
unordered_map<int, int> ansDigit;
unordered_map<int, bool> ansCheck;

void printSqure(vector<int> &vs)
{
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        cout << i + 1 << "-->" << baseSqaures[i] << "-->" << vs[baseSqaures[i]] << "\n";
    }
}
int getDigitCount(vector<int> &vs)
{
    int c = 0;
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        int sq = baseSqaures[i];
        c += vs[sq];
    }
    return c;
}
vector<int> compareNumber(vector<int> &vs1, vector<int> &vs2)
{
    int n1 = getDigitCount(vs1);
    int n2 = getDigitCount(vs2);
    if (n1 == 0)
        return vs2;
    if (n2 == 0)
        return vs1;
    if (n1 > n2)
    {
        return vs2;
    }
    if (n2 > n1)
    {
        return vs1;
    }
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        int sq = baseSqaures[i];
        if (vs1[sq] > vs2[sq])
        {
            return vs1;
        }
        if (vs1[sq] < vs2[sq])
        {
            return vs1;
        }
    }
    return vs1;
}
string getNumber(vector<int> &fr)
{
    string s = "";
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        int sq = baseSqaures[i];
        if (fr[sq] != 0)
        {
            string tmp(fr[sq], '0' + (i + 1));
            //cout<<"tmp "<<tmp<<"\n";
            s += tmp;
        }
    }
    return s == "" ? "-1" : s;
}
int main()
{

    fastIO;
    int t;
    unordered_map<long long, bool> squareMap;
    for (long long i = 1; i * i <= 1000000; i++)
    {
        squareMap[i * i] = true;
    }
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        int sq = baseSqaures[i];
        vector<int> tmpFreq(82, 0);
        tmpFreq[sq] = 1;
        dpFreq[sq].push_back(tmpFreq);
        dpCheck[sq] = true;
    }
    ans[1] = dpFreq[1][0];
    ansCheck[1] = true;
    for (long long i = 1; i < 50; i++)
    {
        for (int j = baseSqaures.size() - 1; j >= 0; j--)
        {
            long x = i - baseSqaures[j];
            if (dpCheck[x])
            {
                for (int p = 0; p < dpFreq[x].size(); p++)
                {
                    vector<int> freq = dpFreq[x][p];
                    vector<int> tmpFreq(82, 0);
                    for (int k = 0; k < baseSqaures.size(); k++)
                    {
                        tmpFreq[baseSqaures[k]] = freq[baseSqaures[k]];
                    }
                    tmpFreq[baseSqaures[j]] += 1;
                    int dig = getDigitCount(tmpFreq);
                    //dealing with N digit answer
                    if (squareMap[i] && ansCheck[dig])
                    {
                        ans[dig] = compareNumber(ans[dig], tmpFreq);
                        ansDigit[dig] = getDigitCount(ans[dig]);
                    }
                    else if (squareMap[i])
                    {
                        ansCheck[dig] = true;
                        ans[dig] = tmpFreq;
                        ansDigit[dig] = getDigitCount(ans[dig]);
                    }
                    // if (dig == 9 && ansCheck[dig])
                    // {
                    //     cout << "dig is 9\n";
                    //     printSqure(ans[dig]);
                    //     cout << getNumber(ans[dig]) << "\n";
                    // }
                    // Maintinaing the dp
                    // if(i==9)
                    // {
                    //     cout<<"our i is "<<i<<"\n";
                    //     cout<<"dp...\n";
                    //     printSqure(dpFreq[i]);
                    //     cout<<"our x is "<<x<<"\n";
                    //     cout<<"dpx..\n";
                    //     printSqure(dpFreq[x]);
                    //     cout<<"tmp..\n";
                    //     printSqure(tmpFreq);
                    // }
                    dpFreq[i].push_back(tmpFreq);
                    dpCheck[i] = true;
                    // if(i==9)
                    // {
                    //     cout<<"now our i is "<<i<<"\n";
                    //     cout<<"dp...\n";
                    //     printSqure(dpFreq[i]);
                    //      cout<<"our x is "<<x<<"\n";
                    //     cout<<"dpx..\n";
                    //     printSqure(dpFreq[x]);
                    //     cout<<"tmp..\n";
                    //     printSqure(tmpFreq);
                    //
                }
            }
        }
    }

     printSqure(ans[1]);
     cout << getNumber(ans[1]) << "\n";
    //  cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     string s;
    //     if(ansCheck[n])
    //     {
    //        s= getNumber(ans[n]);
    //     }
    //     else
    //     {
    //         s="-1";
    //     }
    //     cout <<s<<"\n";
    // }
    // for (int i = 1; i < 10; i++)
    // {
    //     string s;
    //     if (ansCheck[i])
    //     {
    //         s = getNumber(ans[i]);
    //     }
    //     else
    //     {
    //         s = "-1";
    //     }
    //     cout << "for i-->" << i << "ans " << s << "\n";
    // }
    return 0;
}
