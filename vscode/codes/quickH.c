#include<stdio.h>
int hpart(int a[],int l,int h)
{

}
void quicksort(int a[],int l,int h)
{
    if(i<h)
    {
        int m=hpart(a,l,h);
        quicksort(a,l,m);
        quicksort(a,m+1,h);
    }
}
int main()
{
    int n,a[100],i;
    printf("enter the elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf()
    }

}
