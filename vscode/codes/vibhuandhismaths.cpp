#include <iostream>
#include<vector>
#define m 1000000007
using namespace std;
typedef long long int dty;
vector<dty> v(1000001,0);
int main()
{
    dty t,n,i,an=2;
    cin>>t;
    v[1]=1;
    v[2]=2;
    while(t--)
    {
        cin>>n;
        if(n>an)
        {
        for(i=an+1;i<=n;i++)
        {
            v[i]=(v[i-1]%m+(((i-1)%m)*(v[i-2]%m))%m)%m;
        }
        an=n;
        }
        cout<<v[n]<<endl;
    }
    return 0;
}

