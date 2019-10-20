#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator
#define mp make_pair
#define up unordered_map
#define M 1000000007
#define L 1000000000000
unordered_map<long long, int> countMap;
static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
int getNum(char c)
{
    int x = -1;
    if (c >= '0' && c <= '9')
    {
        x = c - '0';
    }
    else
    {
        x = c - 'A' + 10;
    }
    return x;
}
int getMinBase(string s)
{
    int base = 2;
    for (int i = 0; i < s.size(); i++)
    {
        base = max(base, getNum(s[i]) + 1);
    }
    return base;
}
long long getValidNumber(string s, int base)
{
    long long sum = 0, b = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (b > L)
            return -1;
        sum += b * getNum(s[i]);
        if (sum > L)
            return -1;
        b *= base;
    }
    return sum <= L ? sum : -1;
}
bool isPossibleX(string s, int givenBase, long long X)
{
    long long Y;
    if (givenBase != -1)
    {
        Y = getValidNumber(s, givenBase);
        if (Y == X)
        {
            return true;
        }
    }
    else
    {
        int minBase = getMinBase(s);
        for (int b = minBase; b <= 36; b++)
        {
            Y = getValidNumber(s, b);
            if (Y == X)
            {
                return true;
            }
        }
    }
    return false;
}
bool isAllPossible(vector<string> &number, vector<int> &bases, long long X)
{
    for (int i = 0; i < number.size(); i++)
    {
        if (isPossibleX(number[i], bases[i], X))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}
long long getX(vector<string> &number, vector<int> &bases)
{
    long long X, ans = LONG_LONG_MAX;
    int tmp = 0, prevtmp = -1;
    for (int i = 0; i < number.size(); i++)
    {
        if (bases[i] != -1)
        {
            X = getValidNumber(number[i], bases[i]);
            if (X != -1)
            {
                countMap[X]++;
            }
            if (tmp < countMap[X])
            {
                ans = X;
                tmp = countMap[X];
            }
            else if (tmp == countMap[X])
            {
                ans = min(ans, X);
            }
        }
        else
        {
            if (number[i].size() == 1)
            {
                X = getNum(number[i][0]);
                if (X != -1)
                {
                    countMap[X]++;
                }
                if (tmp < countMap[X])
                {
                    ans = X;
                    tmp = countMap[X];
                }
                else if (tmp == countMap[X])
                {
                    ans = min(ans, X);
                }
                continue;
            }
            int minBase = getMinBase(number[i]);
            for (int b = minBase; b <= 36; b++)
            {
                X = getValidNumber(number[i], b);
                // cout<<"valid number "<<X<<"\n";
                if (X != -1)
                {
                    countMap[X]++;
                }
                if (tmp < countMap[X])
                {
                    ans = X;
                    tmp = countMap[X];
                }
                else if (tmp == countMap[X])
                {
                    ans = min(ans, X);
                }
            }
        }
    }
    return tmp == number.size() ? ans : -1;
}
bool isZero(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        countMap.clear();
        int n, b = -1;
        int f = 0, zeros = 0;
        long long sum = 0, tmp = 0, X = -1;
        string s = "@";
        cin >> n;
        vector<string> numbers(n);
        vector<int> bases(n);
        for (int i = 0; i < n; i++)
        {
            cin >> bases[i] >> numbers[i];
            if (isZero(numbers[i]))
            {
                zeros++;
            }
            if (bases[i] != -1 && X == -1)
            {
                f = -1;
                X = getValidNumber(numbers[i], bases[i]);
                if (X != -1)
                {
                    f = 1;
                }
            }
        }
        if (f == 0)
        {
            if (zeros == 0)
            {
                cout << getX(numbers, bases) << "\n";
            }
            else if (zeros == n)
            {
                cout << "0\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
        else
        {
            if (X != -1 && isAllPossible(numbers, bases, X))
            {
                cout << X << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}
