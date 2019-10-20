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
int isVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return 1;
    }
    return 0;
}
void update(int node,int start,int end,int pos,int value,vector<long>& segment)
{
    if(start==end)
    {
        segment[node]=value;
        return;
    }
    int mid=start+(end-start)/2;
    if(pos<=mid)
    {
        update(2*node,start,mid,pos,value,segment);
    }
    else
    {
        update(2*node+1,mid+1,end,pos,value,segment);   
    }
     segment[node]=segment[2*node]+segment[2*node+1];
}
long query(int node,int start,int end,int l,int r,vector<long>& segment)
{
    if(l>end || r<start)
    {
        return 0;
    }
    if(l<=start && end<=r)
    {
        return segment[node];
    }
    int mid=(start+(end-start)/2);
   return query(2*node,start,mid,l,r,segment)+query(2*node+1,mid+1,end,l,r,segment);
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
        vector<long> segment(4*(s.size()+1),0);
        for(int i=0;i<s.size();i++)
        {
            update(1,1,s.size(),i+1,isVowel(s[i]),segment);
        }
      //  print(segment);
        int q;
        cin>>q;
        while (q--)
        {
            cin>>type;
            if(type=='F')
            {
                cin>>l>>r;
                cout<<query(1,1,s.size(),l,r,segment)<<"\n";
            }
            else
            {
                cin>>pos>>c;
                if(isVowel(s[pos-1]) && isVowel(c))
                {
                    //do nothing
                }
                else
                {
                   update(1,1,s.size(),pos,isVowel(c),segment) ;
                }
            }
            
        }
        // print(segment);
    }
    
  
}
