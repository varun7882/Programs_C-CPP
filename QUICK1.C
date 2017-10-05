#include<stdio.h>
#include<conio.h>
int part(int a[],int p,int r)
{
    int i,j,k,t;
    i=p-1;
    k=a[r];
    for(j=p;j<r;j++)
    {
        if(k>a[j])
        {
            i=i+1;
           t=a[i];
           a[i]=a[j];
           a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}
void quick(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
    q= part(A,p,r);
    quick(A,p,q-1);
    quick(A,q+1,r);
    }
}
int main()
{
    int A[100],n,i;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    quick(A,0,n-1);
    printf("sorted array is...\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",A[i]);

    }
    getch();
}
