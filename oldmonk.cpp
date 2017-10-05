#include<iostream>
using namespace std;
long int max(long int a,long int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int main()
{
    long int a[100000],b[100000],i,j,n,t,ans,l,m,h,a1,a2;
    cin>>t;
    while(t--)
    {
        cin >>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        ans=0;
        a2=-1;
        for(i=0;i<n;i++)
        {
            l=0;
            h=n-1;
            a1=-1;
            while(l<=h)
            {
              //  a1=-1;
                m=(l+h)/2;
                if(a[i]<=b[m])
                {
                    a1=m-i;
                    l=m+1;
                }
                else{ h=m-1;}
                a2=max(a1,a2);
            }
            ans=max(ans,a2);
        }

//        cout<<a1<<" "<<a2<<endl;
  //      ans=max(a1,a2);
        cout<<ans<<endl;
    }
    return 0;
}
