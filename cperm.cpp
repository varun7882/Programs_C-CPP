#include<iostream>
using namespace std;
typedef long int dty;
#define MOD 1000000007
long long int power(long long int x,long long int y, long long int k)
{
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, k) % k;
    p = (p * p) % k;

    return (y%2 == 0)? p : (x * p) % k;
}
int main()
{
    int t;
    dty n,ans;
    cin>>t;
    while(t--)
    {
      cin>>n;
      if(n<3)
      {
          cout<<"0"<<endl;
      }
      else
      {
        ans=power(2,n-1,MOD)-2;
      cout<<ans<<endl;
      }
    }
    return 0;
}
