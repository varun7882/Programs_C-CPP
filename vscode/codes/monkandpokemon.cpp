#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<long int,long int> mp;
    map<long int,long int> mf;
    map<long int,long int>::iterator it;
    long int x,y;
    int t,n,tn,tst;
    cin>>t;
    while(t--)
    {
        cin>>n;
        tn=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            if(x!=y)
            {
               if(mf.find(x)==mf.end())
               {
                   mf[x]=1;
               }
               else
               {
                   mf[x]++;
               }

               if(mf.find(y)!=mf.end())
               {
                   mf[y]--;
                   if(mf[y]==0)
                   {
                       mf.erase(y);
                   }
               }
               else
               {
                   if(mp.find(y)==mp.end())
                    {
                    mp[y]=1;
                    }
                    else
                    {
                    mp[y]++;
                    }

               }
//               if(mp.find(x)==mp.end())
//               {
//                   if(mf.find(x)==mf.end())
//                   {
//                       mf[x]=1;
//                   }
//                   else
//                   {
//                       mf[x]++;
//                   }
//                   tn++;
//               }
            }
        }
        tn=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            tn=tn+(it->second);
       //    cout<<it->first <<" "<<it->second<<endl;
        }
        cout<<tn<<endl;
        mp.clear();
        mf.clear();
    }
}
