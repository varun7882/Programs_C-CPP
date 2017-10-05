#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long int dty;
dty t,i,n,c,d,x,f;
dty gcd(dty x,dty y)
{
    if(x%y==0)
    {
        return y;
    }
    else
    {
        gcd(y,x%y);
    }
}
dty lcm(dty x, dty y)
{
    dty h,l;
    h=gcd(x,y);
    l=(x/h)*y;
    return l;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        f=LLONG_MAX;
        vector<dty> a(n+1,-1);
        for(i=1;i<=n;i++)
        {
        cin>>a[i];
        }

        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                x=lcm(max(a[i],a[j]),min(a[i],a[j]));

                if(x<f)
                {
                    f=x;
                }
                }
            }
        }
        cout<<f<<endl;

    }

}
