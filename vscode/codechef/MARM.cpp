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
void print(vector<long>& vs)
{
    for (int i = 0; i < vs.size(); i++)
        {
            cout << vs[i] << " ";
        }
        cout << "\n";
}
void printextra(vector<long>& vs,int k)
{
   long a,b;
   int i;
    for(int ki=0;ki<k;ki++)
    {
        i=ki%vs.size();
        a=vs[i];
        b=vs[vs.size()-1-i];
        vs[i]=a^b;
        cout<<"for k "<<ki+1<<":";
        print(vs);
    }
}
void processVS(vector<long> &vs, int k)
{
    long a,b;
    int i;
    for(int ki=0;ki<k;ki++)
    {
        i=ki%vs.size();
        a=vs[i];
        b=vs[vs.size()-1-i];
        vs[i]=a^b;
    }
}
int main()
{
    int t,test=0;
    int n;
    long k;
    cin >> t;
    while (t--)
    {
        test++;
        cin >> n >> k;
        vector<long> vs(n, 0);
        vector<long> ss(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vs[i];
            ss[i]=vs[i];
        }
        if (k < n)
        {
            processVS(vs, k);
        }
        else
        {
       //      cout<<"test case :"<<test<<"\n";
            long d = k / n, a, b;
            long rem = k % n;
            if (d % 3 == 1)
            {
        //        cout<<"div 1\n";
                for (int i = 0; i < n / 2; i++)
                {
                    a = vs[i];
                    b = vs[n - 1 - i];
                    vs[i] = a ^ b;
                    vs[n - 1 - i] = a;
                };
            }
            else if(d%3==2)
            {
                for (int i = 0; i < n / 2; i++)
                {
                    a = vs[i];
                    b = vs[n - 1 - i];
                    vs[i] = b;
                    vs[n - 1 - i] = a ^ b;
                }
           //     cout<<"div 2\n";
            }
            if (n % 2 != 0)
            {
                vs[(n / 2)] = 0;
            }
            processVS(vs, rem);
        }
      //  cout<<"mine is\n";
        print(vs);
        // cout<<"actual should be\n";
        // processVS(ss,k);
        // print(ss);
    }
    // cout<<"detailed\n";
    // vector<long> ts({1,2,3,4,5});
    // print(ts);
    //  printextra(ts,150);
}
