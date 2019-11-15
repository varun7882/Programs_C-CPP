    #include<iostream>;
    #include<vector>
    using namespace std;
    typedef long long int giant;
    giant a[100005];
    bool vis[100005];
    giant ans,pans;
    static giant sum;
      vector<int>v[100005];
    //<int>::iterator it;
    giant max(giant a,giant b)
    {
        if(a<b)
        {
            return b;
        }
        else return a;
    }
    giant DfSvisit(int vertice)
    {
        vis[vertice]=true;
        sum=sum+a[vertice];
        for(int i=0;i<v[vertice].size();i++)
        {
            if(vis[v[vertice][i]]==false)
            {
                DfSvisit(v[vertice][i]);
            }
        }
         return sum;
    }
    int main()
    {
        int t,n,m,i,e1,e2;
        cin>>t;
        while(t--)
        {
            cin>>n>>m;
            sum=ans=pans=0;
            for(i=0;i<m;i++)
            {
                    cin>>e1>>e2;


                        v[e1].push_back(e2);
                        v[e2].push_back(e1);

            }
            for(i=1;i<=n;i++)
            {
                cin>>a[i];
                 vis[i]=false;
            }
            for(i=1;i<=n;i++)
            {
                if(vis[i]==false)
                {
                    sum=0;
                    pans=DfSvisit(i);
                    ans=max(ans,pans);
                }
            }
            for(i=0;i<100005;i++)
            {
                v[i].clear();
            }
            cout<<ans<<endl;
        }
    }
