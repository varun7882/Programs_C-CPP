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
    int q,n;
    cin>>q;
    while(q--)
    {
        cin>>n;
        vector<long> a(n);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
        }
        int price=sum/n;
        if(price*n<sum)
        price++;
        cout<<price<<"\n";
    }
}
