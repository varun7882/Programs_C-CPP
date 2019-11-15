#include<iostream>
using namespace std;
typedef long long int dty;
int main()
{
    dty t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1 && m==1)
        {
            cout<<"No"<<endl;
        }
        else if(n==1 || m==1)
        {
            if(n==1)
            {
                if(m%2==0)
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
            else if(m==1)
            {
                 if(n%2==0)
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
        }
        else
        {
            if(n%2==0 || m%2==0)
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
