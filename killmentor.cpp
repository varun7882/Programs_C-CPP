#include<iostream>
#include<math.h>
using namespace std;
 bool pc[10000000];
int main()
{
    long int x,t,i,c=0,f,j,fc;
    for(i=0;i<10000000;i++)
    {
        pc[i]=true;
    }
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
            if(c==0)
            {
            c=x;
            for(i=2;i*i<=x;i++)
            {
                if(pc[i]==true)
                {
                    for(j=i+i;j<=x;j=j+i)
                    {
                        pc[j]=false;
                    }
                }

            }
//            for(i=1;i<=x;i++)
//            {
//                cout<<pc[i]<<" "<<i<<endl;
//            }
            }

            if(x<=c)
            {
                if(pc[x]==true)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    f=(int)sqrt(x);
                    if(f*f==x && pc[f]==1)
                    {
                   //    cout<<"spcl NO "<< pc[f]<<" "<<f<<endl;
                   cout<<"NO"<<endl;
                    }
                    else
                    {
                      //  cout<<"spcl YES"<< pc[f]<<" "<<f<<endl;
                   cout<<"YES"<<endl;
                    }
                }
            }
            else
            {
                fc=c;
                c=x;
                for(i=2;i*i<=x;i++)
                {
                    if(pc[i]==true)
                    {
                        for(j=i+i;j<=x;j=j+i)
                        {
                            pc[j]=false;
                        }
                    }

                }
//             for(i=1;i<=x;i++)
//            {
//                cout<<pc[i]<<" "<<i<<endl;
//            }
            if(pc[x]==true)
                {
                   // cout<<"excd NO"<<endl;
                    cout<<"NO"<<endl;
                }
                else
                {
                    f=sqrt(x);
                    if(f*f==x && pc[f]==1)
                    {
                      // cout<<"excd spcl NO"<<endl;
                      cout<<"NO"<<endl;
                    }
                    else
                    {
                        //cout<<"excd spcl YES"<<endl;
                        cout<<"YES"<<endl;
                    }
                }

            }

        }
    }
}
