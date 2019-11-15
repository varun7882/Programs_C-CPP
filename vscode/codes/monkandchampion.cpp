#include <iostream>
#include<set>
using namespace std;
typedef int dtype;
int main()
{
    dtype c=0,m,n,x,i,tmp;
    multiset<dtype> s;
    multiset<dtype>::iterator it;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        cin>>x;
        s.insert(x);
    }
    while(n>0)
    {
      it=s.end();
      it--;
      tmp=*it;
     // cout<<"tmp is "<<tmp<<endl;
      c=c+tmp;
      s.erase(it);
      tmp--;
      s.insert(tmp);
      n--;
    }
    cout<<c<<endl;
    return 0;
}

