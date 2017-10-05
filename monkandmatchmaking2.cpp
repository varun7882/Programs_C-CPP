#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[100005];
    int q,l1,r1,l2,r2;
    gets(s);
    cin>>q;
    cout<<s;
    while(q--)
    {
        cin>>l1>>r1>>l2>>r2;
        if((r1-l1+1)!=(r2-l2+1))
        {
            cout<<"No"<<endl;
        }
        else
        {
//            if(memcmp(s+l1-1,s+l2-1,l2-r2+1))
            {

            }
        }
    }
    return 0;
}

