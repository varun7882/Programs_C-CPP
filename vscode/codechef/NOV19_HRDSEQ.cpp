#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        unordered_map<int,int> last;
        unordered_map<int,int> secondLast;
        unordered_map<int,int> count;
        int n;
        cin>>n;
        vector<int> vs;
        vs.push_back(-1);
        vs.push_back(0);
        last[0]=1;
        count[0]++;
        for (int i = 2; i <=n; i++)
        {
            int x;
            if(secondLast[vs[i-1]]!=0)
            {
                 x=last[vs[i-1]]-secondLast[vs[i-1]];
                vs.push_back(x);
            }
            else
            {
                x=0;
                vs.push_back(x);
            }
            secondLast[x]=last[x];
            last[x]=i; 
            count[x]++;     
        }
        for(int i=0;i<vs.size();i++)
        {
            cout<<vs[i]<<" ";
        }
        cout<<count[vs[n]]<<"\n";
    }
    
}
