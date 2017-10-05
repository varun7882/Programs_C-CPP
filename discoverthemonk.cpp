#include<iostream>
using namespace std;
 int G[1000000],a1[1000000],a2[1000000];
 int binary(int a[],int n, int x)
{
    int m,l,b,f=0;
    l=0;
    b=n;
    while(l<=b)
    {
    m=((b+l)/2);
    if(a[m]==x)
    {

    f=1;
    break;
    }
    else if(x>a[m])
    {
    l=m+1;
    }
    else
    {
    b=m-1;
    }
    }
    return f;
}
void merge( int A[],int p,int q,int r)
{
    int i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)
    {
        a1[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        a2[j]=A[q+1+j];
    }
    i=0,j=0;
    k=p;
    while(i<n1&&j<n2)
    {
        if(a1[i]<=a2[j])
        {
            A[k++]=a1[i++];
        }
        else
        {
            A[k++]=a2[j++];
        }
    }


        while(j<n2)
        {
            A[k++]=a2[j++];
        }
        while(i<n1)
        {
            A[k++]=a1[i++];
        }
    }
void merge_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
	merge_sort(A,p,q);
	merge_sort(A,q+1,r);
	merge(A,p,q,r);
    }
}

int main()
{
    int a[100000],n,q,f,t;
    cin >> n >> q;
    //cout << n << q;
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
    merge_sort(a,0,n-1);
//    for(int i=0;i<n;i++)
//    {
//        cout <<a[i]<<" ";
//    }
    while(q--)
    {
        cin>>t;
        f=binary(a,n-1,t);
        if(f==0)
        {
          cout <<"NO"<<endl;
        }
        else
        {
            cout <<"YES"<<endl;
        }
        }
    return 0;
}
