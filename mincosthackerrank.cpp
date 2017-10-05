#include<iostream>
#include<vector>
using namespace std;
int cost(int n,int* a)
{
    int i,t,c=999999;
    vector<int> hs(1001,0);
    t=c;
    cout<<"hey "<<endl;
    for(i=0;i<1001;i++)
    {
        cout<<hs[i];
    }
    for(i=0;i<n;i++)
    {
        hs[a[i]]++;
         if(hs[a[i]]>1)
        {
            cout<<"from here"<<endl;
            return 0;
        }
        if(t>a[i])
        {
            t=a[i];
        }
    }
    for(i=t+1;i<=1000;i++)
    {
        if(hs[i]>0)
        {
            t=i-t;
            if(t<c)
            {
                c=t;
                t=i;
            }
        }
    }
    return c;
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    cout<<cost(n,a);
    return 0;
}
