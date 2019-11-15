#include<iostream>
#define m 1000000007
using namespace std;
int a[1005],s[1005],e[1005],mn[1005],n;
int root(int x)
{
    while(x!=a[x])
    {
        x=a[x];
    }
    return x;
}
void Union(int x,int y)
{
    int rx,ry;
        if(x<1 || x>n || y<1 || y>n)
        {
            return;
        }
        else
        {
            rx=root(x);
            ry=root(y);
            cout<<"roots are "<<rx<<" "<<ry<<endl;
            if(rx!=ry)
            {
                if(s[rx]<=s[ry])
                {
                   if(e[rx]<e[ry])
                   {
                       e[ry]=e[rx];
                   }
                   else if(e[rx]==e[ry])
                   {
                       mn[ry]=mn[rx]+mn[ry];
                   }
                  a[rx]=a[ry];
                  s[ry]=s[ry]+s[rx];
                }
                else
                {
                    if(e[ry]<e[rx])
                   {
                       e[rx]=e[ry];
                   }
                   else if(e[rx]==e[ry])
                   {
                       mn[rx]=mn[rx]+mn[ry];
                   }
                  a[ry]=a[rx];
                  s[rx]=s[rx]+s[ry];

                }
            }
        }
}
int main()
{
        long long int ans=1;
    int k,i,x,y;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       s[i]=mn[i]=1;
        a[i]=i;
        cin>>k;
        e[i]=k;
    }
    cin>>k;
    while(k--)
    {
        cin>>x>>y;
        Union(x,y);
    }
     for(i=1;i<=n;i++)
    {
       cout<<mn[i]<<" ";
    }
    cout<<endl;
     for(i=1;i<=n;i++)
    {
       cout<<a[i]<<" ";
    }
    for(i=1;i<=n;i++)
    {
        x=root(i);
        if(mn[x]!=-1)
        {
            ans=((ans%m)*(mn[x]%m))%m;
            mn[x]=-1;
        }
    }
    cout<<endl<<ans<<endl;
    cout<<root(1)<<" "<<root(8)<<endl;
    return 0;
}
