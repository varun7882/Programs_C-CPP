#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
        string A;
        int B;
        cin>>A>>B;
        vector<int> s(B,0);
    int in=1,d=1,i,j,sum,tsum=0;
    sum=(B*(B+1))/2;
    i=1;
    for(j=0;j<B-1;j++)
    {
        if(A[j]=='I')
        {
            s[i]=s[i]+in;
            in++;
        }
        else
        {
            s[i]=s[i]-d;
            d++;
        }
        i++;
    }
    for(i=0;i<B;i++)
    {
        tsum=tsum+s[i];
    }
    sum=sum-tsum;
    sum=sum/B;
     for(i=0;i<B;i++)
    {
        s[i]=s[i]+sum;
    }
     for(i=0;i<B;i++)
    {
        cout<<s[i]<<" ";
    }

}

