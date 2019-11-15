#include<iostream>
#include<set>
using namespace std;
int a[100001],s[100001],n,mx,mn;
typedef pair<int,int> p;
set<p> ms;
set<p> ::iterator it;
int root(int x)
{
    int i=x;
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}
void Union(int x,int y)
{

    int rx,ry,tm,cm;
    rx=root(x);
    ry=root(y);
    ms.erase(p(s[rx],rx));
    ms.erase(p(s[ry],ry));
    if(s[x]<s[y])
    {
        a[rx]=a[ry];
        tm=s[ry]+=s[rx];
        ms.insert(p(tm,a[ry]));
    }
    else
    {
        a[ry]=a[rx];
        tm=s[rx]+=s[ry];
         ms.insert(p(tm,a[rx]));
    }
//   if(tm>mx)
//   {
//       mx=tm;
//   }

}
int main()
{
   int n,q,x,y,i,tmn;
    cin>>n;
    for(i=1;i<=n;i++)
    {
     a[i]=i;
     s[i]=1;
     ms.insert(p(1,i));
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        Union(x,y);
        it=ms.begin();
        mn=it->first;
        it=ms.end();
        it--;
        mx=it->first;
      //  cout<<mx<<" "<<mn<<endl;
        if(mx!=n)
        {
        cout<<(mx-mn)<<endl;
        }
        else
        {
           cout<<(mx-n)<<endl;
        }
    }
}
