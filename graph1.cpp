#include<iostream>
#include<vector>
using namespace std;
typedef struct node
{

    int n;
    int d;
    int p;
    char c;
}N;
int main()
{
    int x,y,e;
    vector <N> adj[10];
    cin>>e;
    N n1,*n2;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        n1.n=y;
        n1.d=0;
        n1.p=0;
        n1.c='w';
        adj[x].push_back(n1);
    }
    for(int i=0;i<10;i++)
    {
        while(!adj[i].empty())
        {
        cout<<(*adj)[i].n<<endl;
        cout<<(*adj)[i].d<<endl;
        cout<<(*adj)[i].p<<endl;
        cout<<(*adj)[i].c<<endl;
        ++(*adj)[i];
        }
    }
}
