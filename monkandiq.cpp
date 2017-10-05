#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef int dtype;
typedef pair<dtype,dtype>pr;
int main()
{
   dtype c,p,n,i,ans,z,j,tmp;
   cin>>c>>p>>n;
   vector<dtype> iqp(p+1);
   vector<dtype> iqn(n+1);
   vector<dtype> nofc(c+1,0);
    vector<dtype> last2c[c+1];
   multiset<pr> m;
   multiset<pr>::iterator it;
    for(i=1;i<=n;i++)
    {
     cin>>iqn[i];
     nofc[i]++;
     last2c[i].push_back(iqn[i]);
    }
    for(i=1;i<=p;i++)
    {
        cin>>iqp[i];
    }
    for(i=1;i<=c;i++)
    {
        if(i<=n)
        {
        m.insert(pr(iqn[i],i));
        }
        else
        {
            m.insert(pr(0,i));
        }
    }
//    for(it=m.begin();it!=m.end();it++)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
    for(i=1;i<=p;i++)
    {
        it=m.begin();
        ans=it->second;
        cout<<ans<<" ";
        nofc[ans]++;
        m.erase(it);
        if(last2c[ans].size()==2)
        {
            last2c[ans].erase(remove(last2c[ans].begin(),last2c[ans].end(),last2c[ans][0]),last2c[ans].end());
            last2c[ans].push_back(iqp[i]);
        }
        else
        {
         last2c[ans].push_back(iqp[i]);
        }
        tmp=0;
        for(j=0;j<last2c[ans].size();j++)
        {
           tmp=tmp+last2c[ans][j];
        }
        z=tmp*nofc[ans];
        m.insert(pr(z,ans));
    }
    return 0;
}

