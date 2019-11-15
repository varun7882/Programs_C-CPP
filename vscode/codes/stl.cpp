#include<iostream>
#include<queue>
using namespace std;
int main()
{

    priority_queue<int> pq;
    //priority_queue<int>::iterator it;
    pq.push(10);
    pq.push(100);
    cout<<pq.top();
}
