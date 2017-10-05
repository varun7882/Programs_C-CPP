#include <iostream>
#include <iomanip>
using namespace std;
typedef  int dty;
double a[1002][1002];
int main()
{
    dty t,n,x,y,w,p1,p2;
    int i,j;
    double p11,p22,ans,ax,bx,ta,tb;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>n>>w>>p1>>p2;
        p11=p1*.01;
        p22=p2*.01;
       // cout<<p11<<" "<<p22<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=w;j++)
            {
                a[i][j]=0;
            }
        }
        for(j=0;j<=n;j++)
        {
            a[j][0]=1;
        }
        for(j=1;j<=w;j++)
        {
            a[0][j]=0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=w;j++)
            {
                ta=(p11*a[i-1][max(j-x,0)]);
                tb=((1-p11)*a[i-1][max(j,0)]);
//               cout<<"tatbare ";
//                cout<<ta<<" "<<tb<<endl;
                ax=ta+tb;
                bx=(p22*a[i-1][max(j-y,0)])+((1-p22)*a[i-1][max(j,0)]);
//               cout<<"axbxare ";
//                cout<<ax<<" "<<bx<<endl;
                a[i][j]=max(ax,bx);

            }
        }
//         for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=w;j++)
//            {
//                cout<<a[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ans=a[n][w]*100;
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}

