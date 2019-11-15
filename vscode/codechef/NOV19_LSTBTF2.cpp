#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<int> baseSqaures{1, 4, 9, 16, 25, 36, 49, 64, 81};
vector<int> dpDigits(1000001, 0);
vector<vector<int>> dpFreq(1000001, vector<int>(82));
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
        int sq=baseSqaures[i];
        if (fr[sq] != 0)
        {
            string tmp(fr[sq],'0'+(i+1));
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
    for (long long i = 1; i * i <= 8100; i++)
    {
        squareMap[i * i] = true;
    }
    for (int i = 0; i < baseSqaures.size(); i++)
    {
        dpDigits[baseSqaures[i]] = 1;
        dpFreq[baseSqaures[i]][baseSqaures[i]]++;
    }
    ans[1]=dpFreq[1];
    ansCheck[1]=true;
    for (long i = 1; i < 8101; i++)
    {
        for (int j = baseSqaures.size() - 1; j >= 0; j--)
        {
            long x = i - baseSqaures[j];
            if (x > 0 && dpDigits[x] != 0)
            {
                vector<int> tmpFreq(82, 0);
                for (int k = 0; k < baseSqaures.size(); k++)
                {
                    tmpFreq[baseSqaures[k]] = dpFreq[x][baseSqaures[k]];
                }
                tmpFreq[baseSqaures[j]] += 1;
                int dig=getDigitCount(tmpFreq);
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
                //Maintinaing the dp
                // if(i==10 || i==11)
                // {
                //     cout<<"our i is "<<i<<"\n";
                //     cout<<"dp...\n";
                //     printSqure(dpFreq[i]);
                //     cout<<"tmp..\n";
                //     printSqure(tmpFreq);
                // }
                dpFreq[i] = compareNumber(dpFreq[i], tmpFreq);
                dpDigits[i] = getDigitCount(dpFreq[i]);
                //   if(i==10 || i==11)
                // {
                //    cout<<" now our i is "<<i<<"\n";
                //     cout<<"dp...\n";
                //     printSqure(dpFreq[i]);
                //     cout<<"tmp..\n";
                //     printSqure(tmpFreq);
                // }
            }
        }
    }
    // for (int i = 1; i < 12; i++)
    // {
    //     cout << "\nFor i " << i << "\n";
    //     cout << "For digits " << dpDigits[i] << "\n";
    //     printSqure(dpFreq[i]);
    // }
    //  printSqure(ans[1]);
    //  cout << getNumber(ans[1]) << "\n";
     cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;

        if(squareMap[n])
        {
            s=string(n,'1');
        }
        else if(ansCheck[n])
        {
           s= getNumber(ans[n]);
        }
        else
        {
            s="-1";
        }
        cout <<s<<"\n";
    }
    return 0;
}
