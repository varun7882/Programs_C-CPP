#include<stdio.h>
int check(long int a[],long int n,long int x)
{
    int i,f=0;;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            f=1;
            break;
        }
    }
    return f;
}
void merge(int A[],int p,int q,int r)
{
   int a1[500],a2[500],i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)
    {
        a1[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        a2[j]= A[q+1+j];
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
        q=p+(r-p)/2;
	merge_sort(A,p,q);
	merge_sort(A,q+1,r);
	merge(A,p,q,r);
    }
}
int main()
{
    long int lock,key,a[1000],i,t=0,n,largest=-9999,f=0,temp;
    scanf("%ld%ld",&key,&lock);
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",a[i]);
    }
    merge_sort(a,0,n-1);
    if(lock==key)
    {
        f=1;
    }
    else
    {
        if(lock>key)
        {
            temp=lock/key;
            f=check(a,n,temp);
            if(f==1)
            {
                t++;
            }
        }
        if(f!=1)
        {
        while(lock>key)
        {
            for(i=0;i<n;i++)
            {
                key=key*a[i];
            }
        }
        }
    }
    return 0;
}
