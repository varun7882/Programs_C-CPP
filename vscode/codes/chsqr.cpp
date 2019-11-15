#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t,i,j,c,n,pc;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
        }
        else
        {
           pc= c=((n+1)/2)+1;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    cout<<c;
                    c++;
                    if(c>n)
                    {
                        c=1;
                    }
                    if(j!=n)
                    {
                        cout<<" ";
                    }
                }
                cout<<endl;
                c=pc+1;
                if(c>n)
                    {
                        c=1;
                    }
                    pc=c;
            }
        }
    }
        return 0;
}
