#include <iostream>
#include<set>
using namespace std;
typedef long int dtype;
int main()
{
    dtype q,qt,x;
    multiset<dtype> s;
     multiset<dtype>:: iterator it;
     cin>>q;
    while(q--)
    {
        cin>>qt;
        if(qt==1)
        {
             cin>>x;
            s.insert(x);
        }
        else if(qt==2)
        {
            if(s.find(x)!=s.end())
              {
                  s.erase(x);
              }
              else
              {
                  cout<<-1<<endl;
              }
        }
        else if(qt==3)
        {
            if(s.empty())
            {
              cout<<-1<<endl;
            }
            else
            {
            it=s.end();
            it--;
            cout<<(*it)<<endl;
            }
        }
        else if(qt==4)
        {
            if(s.empty())
            {
              cout<<"-1"<<endl;
            }
            else
            {
           it=s.begin();
            cout<<(*it)<<endl;
            }
        }
    }
    return 0;
}

