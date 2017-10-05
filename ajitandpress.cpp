#include <iostream>
#include<algorithm>
typedef int dtype;
using namespace std;
int main()
{
    dtype t,wn,rn,i,j;
    string wrd,res,ans;
    cin>>t;
    while(t--)
    {
        cin>>wrd>>res;
        rn=res.length();
        wn=wrd.length();
        sort(res.begin(),res.end());
        j=0;
        for(i=0;i<wn;i++)
        {
            if(wrd[i]>res[j] && j<rn)
            {
                cout<<res[j];
                j++;
            }
            else
            {
                cout<<wrd[i];
            }
        }
        res.clear();
        wrd.clear();
        cout<<"\n";
    }
    return 0;
}

