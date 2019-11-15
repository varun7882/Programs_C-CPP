#include<iostream>
#include<math.h>
#include<set>
using namespace std;
int a[100001],s[100001],trs[100001],n;
int root(int x)
{
    int i=x;
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}
void Union(int x,int y)
{

    int rx,ry,tm;

    rx=root(x);
    ry=root(y);

    trs[s[a[rx]]]--;
    trs[s[a[ry]]]--;
    if(s[rx]<s[ry])
    {
        a[rx]=a[ry];
        s[ry]=s[ry]+s[rx];
        trs[s[ry]]++;
    }

    else
    {
        a[ry]=a[rx];
        s[rx]=s[rx]+s[ry];
        trs[s[rx]]++;
    }


}
int getans()
{
    int i,ans,ps,min=9999999,pmin;
    if(trs[n]!=0)
    {
        ans=0;
        return ans;
    }
    i=1;
    while(trs[i]==0)
    {
        i++;
    }
    ps=i;
    for(;i<=n;i++)
    {
        if(trs[i]>=2)
        {
            ans=0;
            return ans;
        }
        else
        {
             if(trs[i]!=0)
             {
                 pmin=i-ps;
                 if(min>pmin)
                 {
                     min=pmin;
                 }
             }

        }
    }
    ans=min;
    return ans;
}
int main()
{
   int q,x,y,i,ans;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        trs[i]=0;
    }
    for(i=1;i<=n;i++)
    {
     a[i]=i;
     s[i]=1;
        trs[s[i]]++;
    }
    while(q--)
    {
        cin>>x>>y;

        if(root(x)!=root(y))
        {
        Union(x,y);
        }

        ans=getans();

      cout<<ans<<endl;
    }
    return 0;
}

