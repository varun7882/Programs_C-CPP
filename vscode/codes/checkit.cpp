#include <iostream>
#include<set>
#include<vector>
using namespace std;
typedef int dtype;
int main()
{
    dtype n,m,x,y,i,t;
    set<dtype> s;
    cin>>t;
    while(t--)
    {
    cin>>n>>m;
    vector<dtype> v[m+1];

   for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[i].push_back(x);
        v[i].push_back(y);
    }
    for(i=1;i<=n-1;i++)
    {
        cin>>x;
        s.insert(v[x][0]);
        s.insert(v[x][1]);
    }
    if(s.size()==n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
      cout<<"NO"<<endl;
    }
    for(i=1;i<=m;i++)
    {
        v[i].clear();
    }
    s.clear();
    }
    return 0;
}

