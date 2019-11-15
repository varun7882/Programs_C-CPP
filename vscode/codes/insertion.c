#include<stdio.h>
#include<conio.h>
void main()
{
    int a[100],n,i,j,k;
    printf("enter the number of elements in an array\n");
    scanf("%d",&n);
    printf("enter the elements to be sorted\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while((j>=0)&&(a[j]>=k))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;

    }
    printf("sorted array is...\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
