#include<iostream>
#include<vector>
using namespace std;
typedef long int dty;
dty a[1000001];
int main()
{
    dty t,n,i,ch,f,ti,cf,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ch=0;
        vector<dty> a(n);
        vector<dty> ans(n,-1);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                vector<dty> c(n,0);
                vector<dty> v;
                ti=i;
                while(!c[ti] && ans[ti]==-1)
                {

                        c[ti]=1;
                        v.push_back(ti);
                        ti+=a[ti]+1;
                        if(ti>=n)
                        {
                            cf=ti/n;
                            ti=ti-(cf*n);
                        }
                }
                if(ti==i)
                {
                    ch++;
                    j=v.size();
                    j--;
                    ans[v[j]]=1;
                    j--;
                    int lf=0;
                    while(1 && j>0)
                    {
                        if(lf==0)
                        {
                        ans[v[j]]=1;
                        }
                        else
                        {
                            ans[v[j]]=0;
                        }

                        if(v[j]==ti)
                        {
                            lf=1;
                        }
                        j--;
                    }
                    v.clear();
                }

            }
            else
            {
                ch++;
            //    cout<<"chla"<<endl;
            }

        }

        cout<<ch<<endl;
        a.clear();
    }
    return 0;
}
