#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long int dty;
vector<dty>v;
set<dty> s;
set<dty>:: iterator it;
dty f=0;
int main()
{
    dty t,n,i,cf,ti,x,ans,j,cn,tc;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        vector<dty>a(n+1);
        vector<dty>gt(n+1);
         for(i=1;i<=n;i++)
        {
            cin>>x;
            a[i]=x;
            s.insert(i);
            ti=i+x+1;
            if(ti>n)
            {
                cf=ti/n;
                ti=ti-(cf*n);
            }
            gt[i]=ti;
        }
        vector<dty> vis(n+1,0);
        while(!s.empty())
        {
         it=s.begin();
         tc=1;
         i=*it;
         s.erase(i);
         vis[i]=tc;
         tc++;
         ti=gt[i];
            while(!vis[ti])
            {
                vis[ti]=tc;
                tc++;
                ti=gt[ti];
              cout<<"tc "<<tc<<endl;
            }
            ans+=tc-vis[ti];
        }
        cout<<ans<<endl;

    }
    return 0;
}


