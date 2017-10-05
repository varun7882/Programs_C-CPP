#include<iostream>
#include<set>
using namespace std;
int main()
{
    int t,e,x,y;
    set<int> s;
    cin>>t;
    while(t--)
    {
        cin>>e;
        while(e--)
        {
            cin>>x>>y;
            s.insert(x);
            s.insert(y);
        }
        cout<<s.size()<<endl;
    }
}
