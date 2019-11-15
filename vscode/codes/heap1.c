#include<stdio.h>
void swap(int A[],int a, int b)
{
//    it doesn't work now but it will one day;
    //it's working now
    int t;
        t=A[a];
        A[a]=A[b];
        A[b]=t;
   // printf("swapping %d %d\n",A[a],A[b]);
}
void heap(int A[],int i,int n)
{
    int l,r,largest;
    l=2*i;
    r=(2*i)+1;
    largest=i;
    if(l<=n&&A[l]>A[largest])
    {
        largest=l;
    }
    if(r<=n&&A[r]>A[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
//        printf("largest element is %d\n",A[largest]);
//        printf("largest is %d\n",largest);
       swap(A,i,largest);
        heap(A,largest,n);

    }
}
void buildheap(int A[],int n)
{
    int i;
    for(i=n/2;i>0;i--)
    {
        heap(A,i,n);
    }
}
void main()
{
    int A[100],n,t,i,hs;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(t=1;t<=n;t++)
    {
        scanf("%d",&A[t]);
    }
    buildheap(A,n);
    hs=n;
    for(t=n;t>1;t--)
    {
        swap(A,1,t);
       //printf("\n%d\n",t);
    hs=hs-1;
     //   printf("\n%d %d %d\n",A[1],A[t],t);
        heap(A,1,hs);
    for(i=1;i<=n;i++)
    {
        printf("%d ",A[i]);
    }

    }
    printf("Sorted elements are...\n");
    for(t=1;t<=n;t++)
    {
        printf("%d\n",A[t]);
    }
}
