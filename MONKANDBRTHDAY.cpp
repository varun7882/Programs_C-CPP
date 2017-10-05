#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<string> s1;
     set<string> ::iterator it;;
    string x;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
           cin>>x;
        s1.insert(x);
        }
        for(it=s1.begin();it!=s1.end();it++)
        {
            cout<<*it<<endl;
        }
    }
}
