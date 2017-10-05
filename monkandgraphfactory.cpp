#include<iostream>
using namespace std;
int main()
{
   int x,n,sum=0,t;
   cin>>n;
   t=n;
   while(n--)
   {
       cin>>x;
       sum=sum+x;
   }
   sum=sum/2;
    if(sum<=t-1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;

    }

}
