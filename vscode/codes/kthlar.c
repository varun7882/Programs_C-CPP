#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int f;
void find(int a[],int p,int r,int k)
{
    if(p==r)
    {
        f=a[p];
    }
    else
    {
        int q;
        q=part(a,p,r);
        if(q==k)
        {
            f=a[q];
        }
        else if(q>k)
        {
            find(a,p,q-1,k);
        }
        else
        {
            find(a,q+1,r,k);
        }
    }
}
int part(int a[],int p,int r)
{
    int wall,piv,ran,j,t;
    wall=p-1;
    ran= rand() % (r-p);
    ran=ran+p;
    t=a[ran];
    a[ran]=a[r];
    a[r]=t;
    piv=a[r];
    for(j=p;j<r;j++)
    {
        if(piv<a[j])
        {
            wall++;
            t=a[wall];
            a[wall]=a[j];
            a[j]=t;
        }
    }
    t=a[wall+1];
    a[wall+1]=a[r];
    a[r]=t;
    return wall+1;
}
void main()
{
    int a[50],n,i,k;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the kth largest element that you want to found\n");
    scanf("%d",&k);
    find(a,0,n-1,k-1);
    printf("required element is.... %d",f);
}

