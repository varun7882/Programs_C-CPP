#include<stdio.h>
#include<limits.h>
long int G[1000000],a1[1000000],a2[1000000];
void merge(long int A[],long int p,long int q,long int r)
{
   long int i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    k=p;
    for(i=0;i<n1;i++)
    {
        a1[i]=A[k++];
    //    printf("%d ",a1[i]);
    }
    //printf("change\n");
    a1[n1]=LONG_MAX;
    for(j=0;j<n2;j++)
    {
        a2[j]=A[k++];
   //      printf("%d ",a2[j]);
    }
    a2[n2]=LONG_MAX;
    i=0,j=0;
    for(k=p;k<=r;k++)
    {
        if(a1[i]<a2[j])
        {
            A[k]=a1[i++];
        }
        else
        {
            A[k]=a2[j++];
        }
    }
    }
void merge_sort(long int A[],long int p,long int r)
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
    long int p,r,n,t,tt;
    scanf("%ld",&tt);
    while(tt--)
    {
   scanf("%d",&n);
   for(t=0;t<n;t++)
   {
       scanf("%ld",&G[t]);
   }
    merge_sort(G,0,n-1);
   for(t=n-1;t>=0;t--)
   {
       printf("%ld ",G[t]);
   }
   printf("\n");
    }
 return 0;
}
