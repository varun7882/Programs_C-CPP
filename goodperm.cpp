#include <iostream>
using namespace std;
void goodperm(int *a,int n)
{
    int t;
    for(int i=0;i<n-1;i=i+2)
    {
        t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
        {
            a[i]=i;
        }
        if(n%2==0)
        {
            goodperm(a,n);
        }
        else
        {
            goodperm(a,n-3);
            int t=a[n-1];
            a[n-1]=a[n-3];
            a[n-3]=a[n-2];
            a[n-2]=t;
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]+1<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
