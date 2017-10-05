#include <iostream>
#include<set>
using namespace std;
typedef int dty;
int main()
{
    dty t,n,i,x,nn,nz,mx,mn,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        nz=nn=0;
        multiset<dty> s;
        multiset<dty>::iterator it;
        for(i=0;i<n;i++)
        {
            cin>>x;
            s.insert(x);
        }
        for(it=s.begin();it!=s.end();it++)
        {
            x=*it;
            if(x<0)
            {
                nn++;
            }
           // cout<<x<<" ";
        }
        if(s.size()==1)
        {
           it=s.begin();
           mx=mn=(*it);
        }
        else
        {
        if(nn%2==0)
        {
            if(nn==0)
            {
                dty tmx=0;
                it=s.begin();
                mn=(*it);
                mx=1;
                it=s.begin();
                for(i=0;i<n;i++)
                {
                    x=(*it);
                    if(x!=0)
                    {
                     mx*=x;
                     tmx=1;
                    }
                    it++;
                }
                if(tmx==0)
                {
                    mx=0;
                }
            }
            else
            {
                mx=1;
                it=s.begin();
                for(i=0;i<n;i++)
                {
                    x=(*it);
                    if(x!=0)
                    {
                     mx*=x;
                    }
                    it++;
                }
                nn--;
                dty ps=0;
                it=s.begin();
                mn=1;
                for(i=0;i<n;i++)
                {
                    x=(*it);
                    if(ps!=nn && x!=0)
                    {
                        mn*=x;
                    }
                    it++;
                    ps++;
                }
            }
        }
        else
        {
                it=s.begin();
                mn=1;
                for(i=0;i<n;i++)
                {
                    x=(*it);
                    if(x!=0)
                    {
                        mn*=x;
                    }
                    it++;
                }
                nn--;
                mx=1;
                dty ps=0,tmx=0;
                it=s.begin();
                for(i=0;i<n;i++)
                {
                    x=(*it);
                    if(ps!=nn && x!=0)
                    {
                        mx*=x;
                        tmx=1;
                    }
                    it++;
                    ps++;
                }
                if(tmx==0)
                {
                    mx=0;
                }

        }
        }
        cout<<mx<<" "<<mn<<endl;
        s.clear();
    }
    return 0;
}
