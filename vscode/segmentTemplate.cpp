#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define sz 500005
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
struct node
{
    long long maxsum=0,sum=0,prefixsum=0,suffixsum=0;
    void baseUpdate(int val)
    {
        sum=val;
        maxsum=val;
        prefixsum=val;
        suffixsum=val;
    }
    void eachNodeUpdate(struct node& lchild,struct node& rchild)
    {
    sum=lchild.sum+rchild.sum;
    prefixsum=max(lchild.prefixsum,lchild.sum+rchild.prefixsum);
    suffixsum=max(rchild.suffixsum,lchild.suffixsum+rchild.sum);
    maxsum = 
    max(prefixsum,
    max(suffixsum,
    max(lchild.maxsum,
    max(rchild.maxsum,lchild.suffixsum+rchild.prefixsum   
    ))));
    }
};
vector<node> segment(4*50010,node());
void update(int node,int start,int end,int pos,int val)
{
    if(start==end)
    {
        segment[node].baseUpdate(val);
         return;
    }
    int mid=(start+end)/2;
    if(pos<=mid)
    {
        update(2*node,start,mid,pos,val);
    }
    else
    {
        update(2*node+1,mid+1,end,pos,val);
    }
    segment[node].eachNodeUpdate(segment[2*node],segment[2*node+1]);
}
node query(int node,int start,int end,int l,int r)
{
    struct node res;
    res.prefixsum=res.suffixsum=res.sum=INT_MIN;
    res.maxsum=INT_MIN;
    if(l>end || r<start)
    {
        return res;
    }
    if(l<=start && r>=end)
    {
        return segment[node];
    }
    int mid=(start+end)/2;
    struct node left=query(2*node,start,mid,l,r);
    struct node right=query(2*node+1,mid+1,end,l,r);
    res.eachNodeUpdate(left,right);
    return res;
}
int main()
{
    int n,m,l,r,t;
    cin>>n;
    vector<long long> values(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>values[i];
        update(1,1,n,i,values[i]);
    }
    cin>>m;
    while(m--)
    {
        cin>>t>>l>>r;
        if(t==1)
        {
        cout<<query(1,1,n,l,r).maxsum<<"\n";
        }
        else
        {
            values[l]=r;
            update(1,1,n,l,r);
        }
        
    }

}
