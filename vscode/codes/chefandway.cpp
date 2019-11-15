#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef  long long int  dty;
typedef pair<double,dty>pr;
dty m=1000000007;
int main()
{
    dty n,k,x,i,j,tmn,ti;
    cin>>n>>k;
    vector<dty> p(n+1);
    vector<dty> v(n+1);
    vector<double> vl(n+1);
    priority_queue<pr> pq;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        p[i]=x;
    }
    v[1]=p[1];
    vl[1]=log(p[1]);
    pq.push(pr(-vl[1],1));
    for(i=2;i<=n;i++)
    {
        while(i-pq.top().second>k)
        {
         //   cout<<"out "<<pq.top().second;
            pq.pop();
        }
      //  cout<<"in "<<pq.top().second<<endl;
        v[i]=(v[pq.top().second]%m)*(p[i]%m)%m;
        vl[i]=vl[pq.top().second]+log(p[i]);
      //  pq.pop();
        pq.push(pr(-vl[i],i));
    }
//    for(i=1;i<v.size();i++)
//    {
//        cout<<v[i]<<" "<<vl[i]<<endl;
//    }
    cout<<v[n]<<endl;
    return 0;
}
