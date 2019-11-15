#include<iostream>
#include<vector>
using namespace std;
int main()
{
   int t,n,nx;
   vector<long long int> v[37];
   long long int x;
   cin>>t;
   while(t--)
   {
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>x;
           nx=__builtin_popcount(x);
           v[nx].push_back(x);
       }
       for(int i=0;i<=37;i++)
       {
           if(!v[i].empty())
           {
               for(int j=0;j<v[i].size();j++)
               {
                   cout<<v[i][j]<<" ";
               }
               v[i].clear();
           }
       }
       cout<<endl;
   }
}

