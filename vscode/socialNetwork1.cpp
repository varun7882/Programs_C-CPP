#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define itr iterator
#define mp make_pair
#define up unordered_map
#define M 1000000007
static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

void printQueue(queue<int> q)
{
	//printing content of queue 
	while (!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
}

int main()
{
    int n, k;
    long id;
    cin >> n >> k;
    deque<long> q;
    up<long,int> ump;
    vector<long>vs(n);
    for(int i=0;i<n;i++)
    {
        cin>>vs[i];
    }
    if(k==1)
    {
        cout<<vs[n-1];
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        id=vs[i];
         if(ump[id])
        {
            continue;
        }    
        if(q.size()==k)
        {
            ump[q.front()]=0;
            q.pop_front();
        }
        ump[id]=1;
        q.push_back(id);
    }
    cout<<q.size()<<"\n";
    while (q.size())
    {
       cout<<q.back()<<" ";
       q.pop_back();
    }   
}
