#include<stdio.h>
void heapify(long long int a[],long long int i,long long int s)
{
    long long int largest,left,right,t;
    largest=i;
    left=2*i;
    right=left+1;
    if(left<=s && a[left]>a[largest])
    {
        largest=left;
    }
    if(right<=s && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        heapify(a,largest,s);
    }
}
void buildheap(long long int a[],long long int s)
{
 long long int i;
 for(i=s/2;i>0;i--)
 {
     heapify(a,i,s);
 }
}
void heapsort(long long int a[],long long int n)
{
    long long int t,s=n,i;
    buildheap(a,s);
    t=a[1];
    a[1]=a[n];
    a[n]=t;
    s--;
    for(i=n-1;i>1;i--)
    {
        heapify(a,1,s);
        t=a[s];
        a[s]=a[1];
        a[1]=t;
        s=s-1;
    }
}
int main()
{
    long long int a[100000],n,i,test;
    scanf("%d",&test);
    while(test--)
    {
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
     for(i=n;i>0;i--)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    }
    return 0;
}
