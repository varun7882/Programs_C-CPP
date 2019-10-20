#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator 
#define mp make_pair
#define up unordered_map
#define M 1000000007
static auto ___ =  []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vs(n);
    vector<bool> p(n+1,false);
    for(int i=0;i<n;i++)
    {
        cin>>vs[i];
    }
    for(int i=1;i<=k-1;i++)
    {
        cout<<i<<" ";
        p[i]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(!p[vs[i]])
        {
            cout<<vs[i]<<" ";
        }
    }
}
