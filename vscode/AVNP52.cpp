#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
template <typename T>
void print(vector<T> &vs)
{
    cout << "array\n";
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << "\n";
}
bool isVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
void update(int ind,int val,vector<long long>& fenwick)
{
   ind++;
   while(ind<fenwick.size())
   {
       fenwick[ind]+=val;
       ind+=ind & (-ind);
   }
}
long query(int ind,vector<long long>& fenwick)
{
    ind++;
    long long ans=0;
    while (ind>0)
    {
        ans+=fenwick[ind];
        ind-=ind & (-ind);
    }
    return ans;
}
int main()
{
    fastIO;
    int t;
    cin>>t;
    while (t--)
    {
        string s; 
        int l,r;
        int pos,val;
        char type,c;
        cin>>s;
        vector<long long> fenwick((s.size()+1),0);
        for(int i=0;i<s.size();i++)
        {
            update(i,isVowel(s[i]),fenwick);
        }
      //  print(fenwick);
        int q;
        cin>>q;
        while (q--)
        {
            cin>>type;
            if(type=='F')
            {
                cin>>l>>r;
                l--,r--;
                cout<<query(r,fenwick)-query(l-1,fenwick)<<"\n";
            }
            else
            {
                cin>>pos>>c;
                pos--;
                if(isVowel(s[pos]))
                {
                    update(pos,-1,fenwick);
                }
                s[pos]=c;
                if(isVowel(c))
                {
                    update(pos,1,fenwick);
                }
            }
            
        }
    }
    
  
}
