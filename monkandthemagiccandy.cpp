#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<long long int> s;
    multiset<long long int>::iterator it;
    long int t,n,k;
    long long int x,sum,xt;
    cin>>t;
    while(t--)
    {
         sum=0;
        cin>>n>>k;
        while(n--)
        {
            cin>>x;
            s.insert(x);
        }
//        for(it=s.begin();it!=s.end();it++)
//        {
//             cout<<*it<<endl;
//        }
        while(k--)
        {
            it=s.end();
            it--;
            xt=*it;
            //cout<<"xt is "<<xt<<endl;
            sum=sum+xt;
            xt=xt/2;
            s.erase(it);
            s.insert(xt);
        }
        cout<<sum<<endl;

        s.clear();
    }
}
