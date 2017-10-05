#include <iostream>
#include<vector>
using namespace std;
typedef long int dtype;
int main()
{
    dtype q,qt,x,c=0,i;
     cin>>q;
     vector<dtype> v(100001,0);
    while(q--)
    {
        cin>>qt;
        if(qt==1)
        {
             cin>>x;
            v[x]++;
            c++;
        }
        else if(qt==2)
        {
            cin>>x;
            if(v[x]>0)
            {
                v[x]--;
                c--;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        else if(qt==3)
        {
            if(c==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                i=100001;
                while(v[i]==0)
                {
                    i--;
                }
                cout<<i<<endl;
            }
        }
        else if(qt==4)
        {
             if(c==0)
            {
                cout<<-1<<endl;
            }
             else
            {
                i=0;
                while(v[i]==0)
                {
                    i++;
                }
                cout<<i<<endl;
            }
        }
    }
    return 0;
}


