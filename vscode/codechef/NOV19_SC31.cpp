#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int getOnes(int x)
{
    int c=0;
    while(x)
    {
        x=x&(x-1);
    }
    return c;
}
int main()
{
    fastIO;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        bitset<10> bit(string("0000000000"));
        for(int i=0;i<n;i++)
        {
            cin>>s;
            bitset<10> bit2(s);
            bit=bit^bit2;
        }
        cout<<bit.count()<<"\n";
    }
    
}
