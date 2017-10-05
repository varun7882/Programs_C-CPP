#include <iostream>
using namespace std;
int a[100001];
int root(int x)
{
    int i=x;
    while(a[i]!=i)
    {
        i=a[i];
    }
    return i;
}
void Union(int x,int y)
{
    int rx,ry;
    rx=root(x);
    ry=root(y);
    a[rx]=a[ry];
}
int main()
{
    int n,q,x,y,i,c;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    while(q--)
    {
        cin>>c;
        if(c==1)
        {
            cin>>x>>y;
            if(root(x)!=root(y))
            {
            Union(x,y);
            }
        }
        else if(c==2)
        {
         cin>>x;
         a[root(x)]=x;
         a[x]=x;
        }
        else if(c==3)
        {
           cin>>x;
           cout<<root(x)<<endl;
        }
    }
        return 0;
}

