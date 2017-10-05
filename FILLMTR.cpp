#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        bool f=true;
        cin>>n>>q;
        int a[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=-1;
            }
        }
        while(q--)
        {
            int i,j,val;
            cin>>i>>j>>val;
            if(i==j && val!=0)
            {
                f=false;
            }
            a[i-1][j-1]=val;
        }
        if(!f)
        {
            cout<<"no\n";
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1 && (a[j][i]==1 || a[j][i]==-1))
                {
                    continue;
                }
                if(a[i][j]==0 && (a[j][i]==0 || a[j][i]==-1))
                {
                    continue;
                }
                if(a[i][j]==-1)
                {
                    continue;
                }
                f=false;
                break;
            }
        }
        if(f)
        {
            cout<<"yes\n";
        }
        else
        {
           cout<<"no\n";
        }
    }
    return 0;
}
