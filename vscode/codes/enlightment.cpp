#include<iostream>
#include<limits.h>
using namespace std;
int n;
int G[1000000],a1[1000000],a2[1000000];
void merge(int A[],int p,int q, int r)
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
int check(int a[],int m,int k)
{
    int monk=a[0]+m;
    k--;
    for(int i=1;i<n;i++)
    {

        if(monk+m>=a[i])
        {
            continue;
        }
        if(k==0)
        {
            return 0;
        }
        monk=m+a[i];
        k--;
    }
    return 1;
}
int main()
{
    int a[100000],l,m,k,h,ans,fm,fm1,om;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    l=0;
    h=100000000;
    while(l<=h)
    {
        om=m;
        m=(l+h)/2;
        fm=check(a,m,k);
        fm1=check(a,m-1,k);
        //cout <<"hey while "<<fm<<" "<<fm1<< " "<<m<< " "<<l<<" "<<h<<endl;
        if(fm && fm1==0)
        {
            ans=m;
       //     cout <<"hey ans"<<endl;
            break;
        }
        else if(fm==0)
        {
            l=m+1;
      //      cout <<"hey low "<<l<<endl;
        }
        else
        {
            h=m-1;
     //       cout <<"hey high "<<h<<endl;
        }
//        if(om==m)
//        {
//            ans=m;
//            break;
//        }
    }
    cout<<ans<<endl;
    return 0;
}
