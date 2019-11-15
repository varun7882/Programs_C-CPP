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
void print(vector<pair<int,int>>& vs)
{
    cout<<"start array\n";
    for(int i=0;i<vs.size();i++)
    {
        cout<<vs[i].first<<" "<<vs[i].second<<"\n";
    }
    cout<<"ends arrya\n";
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> vs(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>vs[i];
    }
    unordered_map<long,vector<pair<int,int>>> ump;
    int d=-1,newd,l,r;
    if(n>1)
    {
        l=1;
        d=vs[2]-vs[1];
    }
    int i=3;
    while(i<=n)
    {
       if(vs[i]==vs[i-1]+d)
       {
           i++;
       }
       else
       {
           r=i-1;
           ump[d].push_back({l,r});
           l=i-1;
           d=vs[i]-vs[i-1];
       }
    }
    ump[d].push_back({l,n});
   // cout<<ump.size()<<"map size\n";
    while(q--)
    {
       cin>>l>>r>>d;
       vector<pair<int,int>> ts=ump[d];
    //   print(ts);
       if(ts.size()==0)
       {
           cout<<1<<"\n";
       }
       else
       {
           int ans=-1;
           for(i=0;i<ts.size();i++)
           {
               if(l>=ts[i].first && r<=ts[i].second)
               {
                   ans=(r-l+1);
               }
                if(l<=ts[i].first && r>=ts[i].second)
               {
                   ans=max(ans,(ts[i].second-ts[i].first+1));
               }
                if(ts[i].first<=l && l<=ts[i].second)
               {
                    if(ts[i].second-l+1<=(r-l+1))
                   {
                       ans=max(ans,ts[i].second-l+1);
                   }
               }
                 if(ts[i].first<=r && r<=ts[i].second)
               {
                   if(r-ts[i].first+1<=(r-l+1))
                   {
                       ans=max(ans,r-ts[i].first+1);
                   }
               }
           }
           cout<<ans<<"\n";
       }
    }
}








