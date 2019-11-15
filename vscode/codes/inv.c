#include<stdio.h>
long int G[1000000],a1[1000000],a2[1000000],c[1000005],copy[1000000],inv=0;
void merge(long int A[],long int p,long int q,long int r)
{
    long int cou=0,i,j,k,jk;
    j=p;
    k=q+1;
    jk=0;
    for(i=p;i<=r;i++)
    {
        if(j>q)
        {
            a1[jk++]=A[k++];
        }
        else if(k>r)
        {
            a1[jk++]=A[j];
            c[A[j]]+=cou;
            j++;
        }
        else if(A[j]<=A[k])
        {
            c[A[j]]+=cou;
            a1[jk++]=A[j++];
        }
        else
        {
            cou++;
            a1[jk++]=A[k++];
        }
    }
    for(i=0;i<jk;i++)
    {
        A[p++]=a1[i];
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
   for(t=0;t<100000;t++)
   {
       c[t]=0;
   }
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
