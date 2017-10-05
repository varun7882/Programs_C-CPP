#include<iostream>
using namespace std;
int main()
{
    int t,f,a[1005],n,i,b[1005],s1,s2,s=0;
    cin>>t;
    while(t--)
    {
        f=-1;
        s=0;
        s1=1;
        cin>>n;
        for(i=0;i<1005;i++)
        {
            b[i]=0;
        }
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        for(i=1005;i>0;i--)
        {
            if(b[i]>=4 && s==0)
            {

                s1=i*i;
                f=1;
                break;
            }
            if(b[i]>=2)
            {
                b[i]=b[i]-2;
                s1=s1*i;
                s=s+2;
            }
            if(s>=4)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            cout<<s1<<endl;
        }
        else
        {
            cout<<f<<endl;
        }
    }
}
