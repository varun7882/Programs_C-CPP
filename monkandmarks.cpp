#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    int t,m;
    string x;
  //  map<int,set<string> > mp;
  //  map<int,set<string> > ::iterator it;
    multiset<string>::iterator it;
    multiset<string> s[101];
     cin>>t;
    while(t--)
    {
        cin>>x>>m;
        s[m].insert(x);
//        mp[m]=s[m];
    }
    for(t=100;t>=0;t--)
    {
        if(!s[t].empty())
        {

            for(it=s[t].begin();it!=s[t].end();it++)
            {
                cout<<t<<" "<<*it<<endl;
            }
        }
    }
}
