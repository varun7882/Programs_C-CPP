#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator 
#define mp make_pair
#define up unordered_map

static auto ___ =  []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

int main()
{
   int n,ones,lens,tmplen,totalones=0;
   bool f=true;
   string s;
   cin>>n>>s;
   lens=1;
   ones=1;
   int j=1;
   vector<vector<long long>> ans(n+1,vector<long long>(n+1,0));
   for(int i=1;i<=n;i++)
   {
       if(s[i-1]=='1')
       {
           totalones++;
       }
       ans[0][i]=1;
   }
   ans[1][1]=1;
   for(int i=2;i<=n;i++)
   {
       cout<<"ans i-->"<<i<<"\n";
       ones=0;
       for(int j=i;j>0;j--)
       {
           if(s[j-1]=='1')
           {
               ones++;
               if(ones>=j-1)
               {
                  cout<<"ans(j-1,j-1)-->"<<ans[j-1][j-1]<<"\n";
                  cout<<"ans(i,ones-1)-->"<<ans[i][ones-1]<<"\n";
                    ans[i][ones]=(ans[i][ones]%M+ans[j-1][j-1]%M)%M;
                    ans[i][ones]=(ans[i][ones]%M+ans[i][ones-1]%M)%M;
               }
               else
               {
                    cout<<"ans(j-1,ones)-->"<<ans[j-1][ones]<<"\n";
                   cout<<"ans(i,ones-1)-->"<<ans[i][ones-1]<<"\n";
                     ans[i][ones]=(ans[i][ones]%M+ans[j-1][ones]%M)%M;   
                     ans[i][ones]=(ans[i][ones]%M+ans[i][ones-1]%M)%M;
               }
           }
           
       }
      
       ans[i][i]=(ans[ones][ones]%M+1)%M;
       cout<<"ans(i,i)-->"<<ans[i][i]<<"\n";
   }
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=n;j++)
       {
           cout<<ans[i][j]<<" ";
       }
       cout<<"\n";
   }
   cout<<ans[n][n];
}
