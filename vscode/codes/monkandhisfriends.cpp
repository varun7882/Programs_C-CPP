#include<iostream>
#include<map>
using namespace std;
int main()
{
    long long int x,t,n,m,i,y;
    map <long long int,int> mp;
    map <long long int,int> ::iterator it;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n+m;i++)
        {
            cin>>x;
            if(i<n)
            {
            mp.insert(pair<long long int,int>(x,12));
            }
            else
            {
                y=x;
                if(mp[x]!=12)
                {
                   mp[x]=12;
                   // mp.insert(pair<long long int,int>(12,x));
                    cout<<"NO"<<endl;
                  //  cout<<mp[x]<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }
//        for(it=mp.begin();it!=mp.end();it++)
//        {
//            cout<<it->first<<" "<<it->second<<endl;
//        }
            mp.clear();
    }
}
