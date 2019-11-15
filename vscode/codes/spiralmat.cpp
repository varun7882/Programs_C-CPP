#include<iostream>
using namespace std;
int main()
{
    int n,i,j,r,c,p=1,R,C;
    int a[100][100];
    cin>>n;
    r=c=0;
    R=C=n;
    i=0;j=0;
    while(p<=(n*n))
    {
        j=c;
        while(j<C)
        {
            a[i][j]=p++;
            j++;
        }
        r++;
        i=r;
        j--;
        while(i<R)
        {
            a[i][j]=p++;
            i++;
        }
        C--;
        i--;
        j=C-1;
        while(j>=c)
        {
            a[i][j]=p++;
            j--;
        }
        R--;
        i=R-1;
        j++;
        while(i>=r)
        {
            a[i][j]=p++;
            i--;
        }
        i++;
        c++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
