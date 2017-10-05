#include<stdio.h>
int main()
{
    int a[100],b[1000],res[100],n,i,j;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements between 0 to 999\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<1000;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(i=1;i<1000;i++)
    {
        b[i]=b[i]+b[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        res[b[a[i]]]=a[i];
        b[a[i]]=b[a[i]]-1;
    }
    printf("sorted array is...\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",res[i]);
    }
}
