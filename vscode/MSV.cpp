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
void makeDivisors(long X,vector<long>& dp)
{
        for (int i = 1; i <= sqrt(X); i++) {
        if (X % i == 0) {
            dp[i] += 1;
            if (X % (X / i) == 0 && i != X / i) {
                dp[X / i] += 1;
            }
        }
    }
}
void print(vector<long>& vs)
{
    for(int i=0;i<vs.size();i++){
        cout<<vs[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
      long n,ans=0,mx=-1;
      cin>>n;
      vector<long> vs(n);
      for(int i=0;i<n;i++)
      {
          cin>>vs[i];
          mx=max(vs[i],mx);
      }
      vector<long> dp(mx+1,0);
      for(int i=0;i<n;i++)
      {
           makeDivisors(vs[i],dp);
         //  cout<<"cc "<<dp[vs[i]]<<"\n";
           ans=max(ans,dp[vs[i]]);
      }
   //   print(dp);
      cout<<ans<<"\n";
  }
  
}
