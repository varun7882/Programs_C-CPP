#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int sz = -1;
vector<long long> segment;
vector<bool> flips;
void update(int node, int start, int end, int a, int b)
{
    int len = end - start + 1;
    if (flips[node])
    {
        segment[node] = len - segment[node];
        flips[node] = !flips[node];
        if (start != end)
        {
            flips[2 * node] = !flips[2 * node];
            flips[2 * node + 1] = !flips[2 * node + 1];
        }
    }
    if (b < start || a > end)
    {
        return;
    }
    if (a <= start && b >= end)
    {
        segment[node] = len - segment[node];
        if (start != end)
        {
            flips[2 * node] = !flips[2 * node];
            flips[2 * node + 1] = !flips[2 * node + 1];
        }
        return;
    }
    int mid = (start + (end - start) / 2);
    update(2 * node, start, mid, a, b);
    update(2 * node + 1, mid + 1, end, a, b);
    segment[node] = segment[2 * node] + segment[2 * node + 1];
}
long long query(int node, int start, int end, int a, int b)
{
    int len = end - start + 1;
    if (flips[node])
    {
        segment[node] = len - segment[node];
        flips[node] = !flips[node];
        if (start != end)
        {
            flips[2 * node] = !flips[2 * node];
            flips[2 * node + 1] = !flips[2 * node + 1];
        }
    }
    if (b < start || a > end)
    {
        return 0;
    }
    if (a <= start && b >= end)
    {
        return segment[node];
    }
    int mid = (start + (end - start) / 2);
    return query(2 * node, start, mid, a, b) + query(2 * node + 1, mid + 1, end, a, b);
}
int main()
{
    fastIO;
    int n, q, type, a, b;
    cin >> n >> q;
    sz = 4 * 100005;
    segment.resize(sz, 0);
    flips.resize(sz, false);
    while (q--)
    {
        cin >> type >> a >> b;
        if (type == 0)
        {
            update(1, 0, n - 1, a, b);
        }
        else
        {
            cout << query(1, 0, n - 1, a, b) << "\n";
        }
    }
}
