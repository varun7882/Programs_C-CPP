#include <iostream>
#include <set>
using namespace std;
typedef long long int dty;
int main()
{
    int t;
    dty n,k,i,diff,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        multiset<dty> s,ds;
        multiset<dty>:: iterator it,rt;
        for(i=0;i<n;i++)
        {
            cin>>x;
            s.insert(x);
        }
        it=s.begin();
        rt=s.end();
        rt--;
        n=n/2;
        for(i=0;i<n;i++)
        {
            x=*it;
            y=*rt;
            ds.insert(x+y);
            it++;
            rt--;
        }
        it=ds.begin();
        rt=ds.end();
        rt--;
        x=*it;
        y=*rt;
        diff=y-x;
        if(diff==k)
        {
            cout<<diff<<end;
            cout<<"Lucky chap!"<<endl;
        }
        else if(diff>k)
        {
            cout<<diff<<end;
             cout<<"No more girlfriends!"<<endl;
        }
        else
        {
            cout<<diff<<end;
            cout<<"Chick magnet Jhool!"<<endl;
        }
    }
    return 0;
}

