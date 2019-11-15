#include<iostream>
using namespace std;
int main()
{
    int t,n,x,a[10],c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        c=0;
        for(int i=0;i<10;i++)
        {
            a[i]=0;
        }
        while(n--)
        {
            cin>>x;
            if(a[x%10]!=0)
            {
                c++;
            }
            else
            {
                a[x%10]=1;
            }

        }
        cout<<c<<endl;
    }
}
