    #include<iostream>
    #include<math.h>
    using namespace std;
    int main()
    {
        long int x,t,i,c,f;
        cin >>t;
        while(t--)
        {
            cin >>x;
           if(x<=4)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                 f=c=0;
                // cout<<sqrt(x)<<endl;
                for(i=2;i<=x/2;i++)
                {
                   if(x%i==0)
                   {
                       f=1;
                       break;
                   }
                }
                if(f==0)
                {
                     cout<<"NO"<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }
    }
