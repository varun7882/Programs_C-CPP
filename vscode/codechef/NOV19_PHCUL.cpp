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
        
        // cout<<"initial point "<<x<<" "<<y<<"\n";
        //abc
        ans1=min1=minDistance(set1,x,y,p1);
        ans1+=minDistance(set2,set1[p1],set1[p1+1],p2);
        ans1+=minDistance(set3,set2[p2],set2[p2+1],p3);
        // cout<<"abc "<<ans1<<"\n";
        // cout<<"point "<<set1[p1]<<" "<<set1[p1+1]<<"\n";
        // cout<<"point "<<set2[p2]<<" "<<set2[p2+1]<<"\n";
        // cout<<"point "<<set3[p3]<<" "<<set3[p3+1]<<"\n";
        ans=min(ans,ans1);

        //acb
        ans1=min1;
        ans1+=minDistance(set3,set1[p1],set1[p1+1],p3);
        ans1+=minDistance(set2,set3[p3],set3[p3+1],p2);
        // cout<<"acb "<<ans1<<"\n";
        // cout<<"point "<<set1[p1]<<" "<<set1[p1+1]<<"\n";
        // cout<<"point "<<set3[p3]<<" "<<set3[p3+1]<<"\n";
        // cout<<"point "<<set2[p2]<<" "<<set2[p2+1]<<"\n";
        ans=min(ans,ans1);

        //bac
        ans2=min2=minDistance(set2,x,y,p2);
        ans2+=minDistance(set1,set2[p2],set2[p2+1],p1);
        ans2+=minDistance(set3,set1[p1],set1[p1+1],p3);
        // cout<<"bac "<<ans2<<"\n";
        // cout<<"point "<<set2[p2]<<" "<<set2[p2+1]<<"\n";
        // cout<<"point "<<set1[p1]<<" "<<set1[p1+1]<<"\n";
        // cout<<"point "<<set3[p3]<<" "<<set3[p3+1]<<"\n";
        ans=min(ans,ans2);

        //bca
        ans2=min2;
        ans2+=minDistance(set3,set2[p2],set2[p2+1],p3);
        ans2+=minDistance(set1,set3[p3],set3[p3+1],p1);
        // cout<<"bca "<<ans2<<"\n";
        // cout<<"point "<<set2[p2]<<" "<<set2[p2+1]<<"\n";
        // cout<<"point "<<set3[p3]<<" "<<set3[p3+1]<<"\n";
        // cout<<"point "<<set1[p1]<<" "<<set1[p1+1]<<"\n";
        ans=min(ans,ans2);
        
        cout<<ans<<"\n";
    }
    
}
