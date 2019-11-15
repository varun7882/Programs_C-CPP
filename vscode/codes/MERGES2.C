#include<stdio.h>
#include<conio.h>
void merge(int A[],int p,int q,int r)
{
    int B[100];
   int i=p,j=q+1,k=p;
    while((i<=q)&&(j<=r))
    {
         if(A[i]<A[j])
         {
             B[k]=A[i];
             i++;
         }
        else
        {
            B[k]=A[j];
            j++;
        }
        k++;
    }
    if(i>q)
    {
        j=q+1;
       while(j<r+1)
       {
         B[k++]=A[j];
         j++;
       }
    }
    else
    {
        i=p;
        while(i<=q)
        {
            B[k++]=A[i];
            i++;
        }

    }
    for(i=p;i<r+1;i++)
    {
        A[i]=B[i];
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
    int G[100],p,r,n,t;
   printf("enter the number of elements to be sorted\n");
   scanf("%d",&n);
   printf("enter the elements\n");
   for(t=0;t<n;t++)
   {
       scanf("%d",&G[t]);
   }
    merge_sort(G,0,n-1);
   for(t=0;t<n;t++)
   {
       printf("%d\n",G[t]);
   }
 return 0;
}
