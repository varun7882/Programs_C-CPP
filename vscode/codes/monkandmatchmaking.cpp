#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int q,l1,r1,l2,r2;
    long long int x,y;
    long long int a[100005],b[100005];
    cin>>s;
    cin>>q;
    a[0]=(long long int)s[0];
    for(int i=1;i<s.length();i++)
    {
        a[i]=a[i-1]+(((long long int)s[i])*(i+1));
    }
    b[0]=0;
    for(int i=1;i<s.length();i++)
    {
        b[i]=b[i-1]+(((long long int)s[i])*(i));
    }
    while(q--)
    {
        cin>>l1>>r1>>l2>>r2;
        x=y=0;
        if((r1-l1+1)!=(r2-l2+1))
        {
            cout<<"No"<<endl;
        }
        else
        {
            if(l1==r1 && l2==r2)
            {
                if(s[l1-1]==s[l2-1])
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
            else
            {
            x=(a[r1-1])-(a[l1-1]);
          //  cout<<"x is "<<x<<"\n";
            y=(a[r2-1])-(a[l2-1]);
          //  cout<<"y is "<<y<<"\n";
            y=y-((b[r2-1]-b[l2-1])-(b[r1-1]-b[l1-1]));
          //  cout<<"nya y is "<<y<<"\n";
            if(x==y)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            }
        }
    }
    return 0;
}
