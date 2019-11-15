#include <iostream>
#include <vector>
#include <map>
typedef int dty;
using namespace std;
typedef pair<dty,dty>p;
typedef pair<p,dty> pi;
dty sk[10001];
int main()
{
    dty t,m,n,u,v,g,h,i,cg,ch;
    cin>>t;
    while(t--)
    {
        cg=ch=0;
        cin>>m>>n;
        vector<dty> spm[m+1];
        vector<dty> spn[n+1];
        map<p,dty> mp;
         map<p,dty>::iterator it;
        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            spm[i].push_back(u);
            spm[i].push_back(v);
        }
         for(i=1;i<=n;i++)
        {
            cin>>u>>v;
            spn[i].push_back(u);
            spn[i].push_back(v);
            sk[u]++;
            it=mp.find(p(u,v));

                mp[p(u,v)]++;
              //  cout<<mp[p(u,v)]<<" od";

        }
        cin>>g>>h;
        for(i=1;i<=m;i++)
        {
            u=spm[i][0];
            v=spm[i][1];
            if(sk[u]>0)
            {
                sk[u]--;
                cg++;
            }
            if(mp.find(p(u,v))!=mp.end() && mp[p(u,v)]>0)
            {
                mp[p(u,v)]--;
                ch++;
            }
        }
        if(ch>=h)
        {
            cout<<"Great"<<endl;
        }
        else if(cg>=g)
        {
             cout<<"Good"<<endl;
        }
        else
        {
             cout<<":("<<endl;
        }
        mp.clear();
        for(i=0;i<10001;i++)
        {
            sk[i]=0;
        }
    }
    return 0;
}

