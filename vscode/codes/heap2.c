#include<stdio.h>
#include<conio.h>
void makeheap(int a[],int n)
{
    int i=1,t,temp;
    for(i=1;i<=n;i++)
    {
     if(a[i]>a[2*i])
     {
         temp=a[i];
         a[i]=a[2*i];
         a[2*i]=temp;

         t=i;
        while((t>=2)&&(a[t/2]>a[t]))
        {
         temp=a[t/2];
         a[t/2]=a[t];
         a[t]=temp;
         t=t/2;
        }
     }

     if(a[i]>a[2*i+1])
     {
         temp=a[i];
         a[i]=a[2*i+1];
         a[2*i+1]=temp;

        t=i;
        while((t>=2)&&(a[t/2]>a[t]))
        {
         temp=a[t/2];
         a[t/2]=a[t];
         a[t]=temp;
         t=t/2;
        }
     }

    }

}
void heapsort(int a[],int heap[],int n)
{
    int i,n1=n;
     for(i=1;i<=n;i++)
    {
        heap[i]=a[1];
        a[1]=a[n1];
        a[n1]=9999;
        n1--;
        makeheap(a,n1);
    }
}

void main()
{
    int a[100],heap[100],n,i,n1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    makeheap(a,n);
    heapsort(a,heap,n);
    printf("sorted array is : ");
     for(i=1;i<=n;i++)
    {
        printf("%d ",heap[i]);
    }

}
