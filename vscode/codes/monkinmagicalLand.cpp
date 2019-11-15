#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef int dty;
typedef pair<dty,dty>p;
typedef pair<dty,p>pr;
int main()
{
    dty t,n,m,kn,i,j,it,c[101],z[101],k[21],ans,tmpk,pc[(1<<20)+1];
    int gc[21][51];
    for (int y=0; y<(1<<20); y++) pc[y] = __builtin_popcount(y);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>kn;
        for(i=0;i<n;i++)
        {
            cin>>k[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>c[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>z[i];
        }
        ans=-1;
      //  cout<<"okay1";
      for (int y=0; y<n; y++) for (int z=1; z<=50; z++) gc[y][z] = __gcd(k[y],z);
        for(i=1<<kn-1;i<1<<n;i++)
        {
            if (pc[i]!=kn) continue;
            tmpk=0;
            vector<dty> cz(m,0);
           // cout<<"okay2";
            for(j=0;j<n;j++)
            {
                //cout<<"okay3";
                if(i&(1<<j))
                {
                    cout<<j<<" ";
                    for(it=0;it<m;it++)
                    {
                        if(gc[j][c[it]]&&!cz[it])
                        {
                            tmpk+=z[it];
                           cz[it]=1;
                        }
                    }
                }
            }
            if(tmpk>ans)
            {
                ans=tmpk;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

