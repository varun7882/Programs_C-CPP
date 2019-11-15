#include<iostream>
using namespace std;
int main()
{
    int n,k,i,x,y,c=0;
    cin>>n;
    cin>>k;
    int a[100005];
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    while(k--)
    {
        cin>>x>>y;
        a[y]=a[x];
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==i)
        {
            c++;
        }
    }
    cout<<c<<endl;

    return 0;
}
