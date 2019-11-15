#include<iostream>
//#include<set>
using namespace std;
typedef long long int dty;
//typedef pair<dty,dty>p;
int main()
{
    dty t,n,m,ans;
    cin>>t;
    while(t--)
    {
       cin>>n>>m;
       ans=n^m;
       ans=__builtin_popcount(ans);
         cout<<ans<<endl;
    }

    return 0;
}

