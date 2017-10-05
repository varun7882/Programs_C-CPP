#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    multiset<int> s;
    multiset<int>::iterator it;
    int n,i,x;
    cin>>n;
    vector<int> v(n);
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
     for(i=1;i<=n;i++)
    {

        s.insert(v[i]);
        if(i>2)
        {
        x=1;
        it=s.end();
        it--;
        x=x*(*it);
        it--;
        x=x*(*it);
        it--;
        x=x*(*it);
        }
        else
        {
            x=-1;
        }
        cout<<x<<endl;
    }
}
