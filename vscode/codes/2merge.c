#include<stdio.h>
long int G[1000000],a1[1000000],a2[1000000];
void merge(long int p,long int q)
{
   long int i,j,k;
   i=0;
   j=0;
   k=0;
    while(i<p&&j<q)
    {
        if(a1[i]>a2[j])
        {
            G[k++]=a1[i++];
        }
        else
        {
            G[k++]=a2[j++];
        }
    }

        while(j<q)
        {
            G[k++]=a2[j++];
        }
        while(i<p)
        {
            G[k++]=a1[i++];
        }
    }
//void merge_sort(long int A[],long int p,long int r)
//{
//    int q;
//    if(p<r)
//    {
//        q=(p+r)/2;
//	merge_sort(A,p,q);
//	merge_sort(A,q+1,r);
//	merge(A,p,q,r);
//    }
//}
 int main()
{
    long int p,r,n,t,tt,m;
    scanf("%ld",&tt);
    while(tt--)
    {
   scanf("%ld%ld",&n,&m);
    for(t=0;t<1000000;t++)
   {
     a1[t]=0;
     a2[t]=0;
   }
   for(t=0;t<n;t++)
   {
       scanf("%ld",&a1[t]);
   }
    for(t=0;t<m;t++)
   {
       scanf("%ld",&a2[t]);
   }
    merge(n,m);
   for(t=0;t<n+m;t++)
   {
       printf("%ld ",G[t]);
   }
   printf("\n");
    }
 return 0;
}
