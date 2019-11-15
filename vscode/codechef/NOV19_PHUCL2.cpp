#include <bits/stdc++.h>
#include<climits>
using namespace std;
#define M 1000000007
#define ll long long
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
double getDistance(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double minDistance(vector<long long>& vs,double x,double y,int& p)
{
    double ret= DBL_MAX,tmp;
    for (int i = 0; i < vs.size(); i=i+2)
    {
        tmp=getDistance(x,y,vs[i],vs[i+1]);
        if(ret>tmp)
        {
            ret=tmp;
            p=i;
        }
    } 
    return ret;
}
int main()
{
    fastIO;
    cout<<setprecision(12);
    cin>>setprecision(12);
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        double x,y;
        cin>>x>>y;
        cin>>n>>m>>k;
        vector<long long> set1(2*n);
        vector<long long> set2(2*m);
        vector<long long> set3(2*k);
        double ans1=0,ans2=0,ans3=0,ans=DBL_MAX;
        for(int i=0;i<set1.size();i++)
        {
            cin>>set1[i];
        }
         for(int i=0;i<set2.size();i++)
        {
            cin>>set2[i];
        }
         for(int i=0;i<set3.size();i++)
        {
            cin>>set3[i];
        }
        double min1,min2,min3;
        int p1=-1,p2=-1,p3=-1;
        
        for(int i=0;i<set1.size();i=i+2)
        {
            for(int j=0;j<set2.size();j=j+2)
            {
                min1= getDistance(set1[i],set1[i+1],set2[j],set2[j+1]);
                if(min1<ans)
                {
                   min2=getDistance(x,y,set1[i],set1[i+1]);//+minDistance(set3,set2[j],set2[j+1],p3);
                   min3=getDistance(x,y,set2[j],set2[j+1]);//+minDistance(set3,set1[i],set1[i+1],p3); 
                   if(min1+min2<ans)
                   {
                       ans=min(ans,min1+min2+minDistance(set3,set2[j],set2[j+1],p3));
                   }
                    if(min1+min3<ans)
                   {
                       ans=min(ans,min1+min3+minDistance(set3,set1[i],set1[i+1],p3));
                   } 
                }
            }
        }
        cout<<ans<<"\n";
    }
    
}
