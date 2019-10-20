#include <bits/stdc++.h> 
using namespace std; 
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
vector<vector<int>> vs(257,vector<int>());
void printValue(int x)
{
    int p=x;
    while(x<=256)
    {
        vs[p].push_back(x);
        cout<<x<<" ";
        x+=x&(-x);
    }
    cout<<"\n";
}
void printValueBack(int x)
{
    int p=x;
    while(x>0)
    {
       // vs[p].push_back(x);
        cout<<x<<" ";
        x-=x&(-x);
    }
    cout<<"\n";
}
void print(vector<int>& vs)
{
    for(int i=0;i<vs.size();i++){
        cout<<vs[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    fastIO;
    for(int i=1;i<55;i++)
    {
        cout<<i<<" contributes to \n";
        printValue(i);
    }
     for(int i=1;i<55;i++)
    {
        cout<<i<<" get it from \n";
        printValueBack(i);
    }
    // for (int i = 0; i < 55; i++)
    // {
    //     sort(vs[i].begin(),vs[i].end());
    //     cout<<i<<" contains ";
    //     print(vs[i]);
    //     cout<<"\n";
    // }
    
}
