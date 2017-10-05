#include<stdio.h>
#include<limits.h>
int largest;
void heapify(int a[],int s,int i)
{
    int l,r,t;
    l=(2*i);
    r=(2*i)+1;
    if((l<=s)&&(a[l]>a[i]))
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
     if((r<=s)&&(a[r]>a[largest]))
    {
        largest=r;
    }
    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        heapify(a,s,largest);
    }
}
void buildheap(int a[],int s)
{
    int j;
    for(j=s/2;j>=1;j--)
    {
        heapify(a,s,j);
    }
}
void heapsort(int a[],int s)
{
    int j,t,k=s;
     buildheap(a,s);
    for(j=s;j>=2;j--)
    {
     t=a[1];
     a[1]=a[j];
     a[j]=t;
     k--;
     heapify(a,k,1);
    }
}

int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("here\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}
