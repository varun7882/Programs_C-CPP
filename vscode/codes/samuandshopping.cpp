#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef int dty;
dty min3(dty a,dty b,dty c)
{
    return min(a,min(b,c));
}
dty shop(vector<dty> v[],vector<dty> p[],dty n,dty it)
{
    if(n==0)
    {
        return 0;
    }
    else if(v[n][it]!=-1)
    {
        return v[n][it];
    }
    else
    {
        v[n][it]=min(shop(v,p,n-1,abs(2-it)),shop(v,p,n-1,abs(1-it)))+p[n][it];
        return v[n][it];
    }
}
int main()
{
    dty t,n,i,x,y,z,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<dty> v[n+1],p[n+1];
        for(i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            p[i].push_back(x);
            p[i].push_back(y);
            p[i].push_back(z);
            v[i].push_back(-1);
            v[i].push_back(-1);
            v[i].push_back(-1);
        }
        v[1][0]=p[1][0];
        v[1][1]=p[1][1];
        v[1][2]=p[1][2];
        shop(v,p,n,0);shop(v,p,n,1);shop(v,p,n,2);
//        for(i=2;i<=n;i++)
//        {
//            v[i][0]=min(v[i-1][1],v[i-1][2])+p[i][0];
//            v[i][2]=min(v[i-1][0],v[i-1][1])+p[i][2];
//            v[i][1]=min(v[i-1][2],v[i-1][0])+p[i][1];
//        }
        ans=min3(v[n][0],v[n][1],v[n][2]);
        cout<<ans<<endl;
        for(i=1;i<=n;i++)
        {
            cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        }
    }
    return 0;
}

