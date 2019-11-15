#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,x,q;
        cin>>n;
        while(n--)
        {
            cin>>x;
            string ans="";
            q=x%8;
            switch(q)
            {
            case 0:
               ans=ans+to_string(x-1)+"SL";
               break;
            case 1:
                ans=ans+to_string(x+3)+"LB";
                break;
            case 2:
                ans=ans+to_string(x+3)+"MB";
                break;
            case 3:
                ans=ans+to_string(x+3)+"UB";
                break;
            case 4:
                ans=ans+to_string(x-3)+"LB";
                break;
            case 5:
                ans=ans+to_string(x-3)+"MB";
                break;
            case 6:
                ans=ans+to_string(x-3)+"UB";
                break;
            case 7:
                ans=ans+to_string(x+1)+"SU";
               break;
            }
            cout<<ans<<"\n";
        }
        return 0;
}
