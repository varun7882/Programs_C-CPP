#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int dty;
dty a[20][180][1620],d[20];
dty dpget(dty ps,dty sm,dty sqsm,dty chk)
{
    if(ps<0)
    {
        return __gcd(sm,sqsm)==1;
    }
    if(!chk && a[ps][sm][sqsm]!=-1)
    {
        return a[ps][sm][sqsm];
    }
    dty ans=0,cn,en;
    if(chk)
    {
        en=d[ps];
    }
    else
    {
        en=9;
    }
    for(cn=0;cn<=en;cn++)
    {
        ans=ans+dpget(ps-1,sm+cn,sqsm+cn*cn,chk&& cn==en);
    }
    if(!chk)
    {
        a[ps][sm][sqsm]=ans;
    }
    return ans;
}
dty get(dty x)
{
    dty i=0,ans;
    while(x>0)
    {
        d[i++]=x%10;
        x=x/10;
    }
    ans=dpget(i-1,0,0,1);
}
int main()
{
    dty t,l,r;
    memset(a,-1,sizeof(a));
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<get(r)-get(l-1)<<endl;
    }
    return 0;
}
