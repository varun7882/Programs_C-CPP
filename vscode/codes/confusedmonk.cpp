#include<iostream>
using namespace std;

int modpowIter(int a, int b, int c) {
        int ans=1;
        while(b != 0) {
                if(b%2 == 1)
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}
int main() {
        int a=170,b=170,c=1000000007,ans,ans1;
        ans = modpowIter(a,b,c);
        cout << ans << endl;
}
