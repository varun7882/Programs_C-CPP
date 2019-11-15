#include<stdio.h>
void countsort(int a[],int n,int exp)
{
    int b[10]={0};
    int res[100],i;
    for(i=0;i<n;i++)
    {
        b[(a[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        b[i]=b[i]+b[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        res[b[(a[i]/exp)%10]-1]=a[i];
        b[(a[i]/exp)%10]=b[(a[i]/exp)%10]-1;
    }
    for(i=0;i<n;i++)
    {
        a[i]=res[i];
    }
}
int main()
{
    int a[100],n,i,exp,m;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    m=a[0];
    for(i=0;i<n;i++)
    {
        if(m<a[i])
        {
            m=a[i];
        }
    }
    for(exp=1;(m/exp)>0;exp=exp*10)
    {
        countsort(a,n,exp);
    }
    printf("sorted array is..\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
