#include<stdio.h>
long int G[1000000],a1[1000000],a2[1000000],c[1000005],copy[1000000];
void merge(long int A[],long int p,long int q,long int r)
{
   long int i,j,k,n1,n2,ct=0;
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

            c[a1[i]]=ct+c[a1[i]];
            A[k++]=a1[i++];
        }
        else
        {
            ct++;
            A[k++]=a2[j++];
        }
    }


        while(j<n2)
        {
            A[k++]=a2[j++];
        }
        while(i<n1)
        {
            c[a1[i]]=ct+c[a1[i]];
            A[k++]=a1[i++];
        }
    }
void merge_sort(long int A[],long int p,long int r)
{
  long int q;
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
       copy[t]=G[t];
   }
    merge_sort(G,0,n-1);
   for(t=0;t<n;t++)
   {
       printf("%ld ",c[copy[t]]);
   }
   printf("\n");
    }
 return 0;
}
