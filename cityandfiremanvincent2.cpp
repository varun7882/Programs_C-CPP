#include<iostream>
#include<set>
#define m 1000000007
using namespace std;
int a[1005],s[1005],e[1005],n;
multiset<int> ms[1005];
set<int> ss;
set<int>::iterator it;
multiset<int>::iterator mit;
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
           // cout<<"roots are "<<rx<<" "<<ry<<endl;
            if(rx!=ry)
            {
                if(s[rx]<=s[ry])
                {
                  a[rx]=a[ry];
                  s[ry]=s[ry]+s[rx];
                }
                else
                {
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
       s[i]=1;
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
        if(a[i]==i)
        {
         ss.insert(i);
        }
        ms[root(i)].insert(e[i]);
    }
    ans=1;
    for(it=ss.begin();it!=ss.end();it++)
    {
        int x,c=0;
         x=*(ms[*it].begin());
        for(mit=ms[*it].begin();mit!=ms[*it].end();mit++)
        {

            if(x==*mit)
            {
                c=((c%m)+1)%m;
            }
            else
            {
                break;
            }

        }
        ms[*it].clear();
        ans=((ans%m)*(c%m))%m;
    }
    ss.clear();
    cout<<ans<<endl;
    return 0;
}

