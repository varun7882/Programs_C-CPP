#include<stdio.h>
#include<conio.h>
void part(int[],int,int);
void merge(int[],int,int,int);
int i,j,k,n;
void main()
{
 int a[100];
 printf("enter the element to be inserted...\n");
 scanf("%d",&n);
 printf("enter the elements...\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&a[i]);
 }
 part(a,0,n);
 printf("After the merge sort array is...\n");
 for(i=0;i<n;i++)
 {
     scanf("%d\n",a[i]);
 }
 getch();
}
void part(int a[],int min,int max)
{
    int mid;
    if(min<max)
    {
	mid=(min+max)/2;
	part(a,min,mid);
	part(a,mid+1,max);
	merge(a,min,mid,max);
    }
}
void merge(int a[],int min,int mid,int max)
{
    int temp[100];
    k=0;
    i=min;
    j=mid+1;
      while(i<mid&&j<max)
      {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
   while(i<mid)
   {
       temp[k++]=a[i++];
   }
   while(j<max)
   {
       temp[k++]=a[j++];
   }
  for(i=0;i<n;i++)
  {
      a[i]=temp[i];
  }
}
