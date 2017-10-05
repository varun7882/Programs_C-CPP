#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,i,*arr,c;
void print()
{
 printf(" the array is....\n");
 for(c=1,i=0;i<n;i++,c++)
 {
 printf("\n %d.%d",c,arr[i]);
 }
}
void insert()
{
 int p,d;
 printf("\n enter the position and the element to be entered\n");
 scanf("%d%d",&p,&d);
 n=n+1;
 arr=(int*)realloc(arr,n*sizeof(int));
 for(i=n-1;i>=(p-1);i--)
 {
  arr[i+1]=arr[i];
 }
 arr[p-1]=d;
}
void del()
{
 int d,g;
 printf(" enter the element to be deleted\n");
 scanf("%d",&d);
 for(i=0;i<n;i++)
 {
 if(arr[i]==d)
 {
 g=1;
 for(i;i<n;i++)
 {
 arr[i]=arr[i+1];
 }
 n=n-1;
 break;
 }
 }
 if(g!=1)
 printf(" element not in array\n");
 arr=(int*)realloc(arr,n*sizeof(int));
}
void selsort()
{
int i1,j,t;
 for(i1=0;i1<(n-1);i1++)
 {
  for(j=i1+1;j<n;j++)
  {
   if(arr[i1]>arr[j])
   {
   t=arr[i1];
   arr[i1]=arr[j];
   arr[j]=t;
   }
  }
 }
}
void bubsort()
{
 int i1,j,t,k=n;
 for(i1=0;i1<(n-1);i1++)
 {
  for(j=0;j<=(n-1-i1);j++)
  {
  if(arr[j]>arr[j+1])
  {
  t=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=t;
  }
  }
 }
}
void main()
{
 int c,qw=0;
 clrscr();
 printf(" enter the size of the array\n");
 scanf("%d",&n);
 arr=(int*)malloc(n*sizeof(int));
 printf(" enter the elements\n");
 for(i=0;i<n;i++)
 {
 scanf(" %d",&arr[i]);
 }
 print();
 printf(" enter 1 to make changes else 0\n");
 scanf("%d",&qw);
 while(qw)
 {
 printf(" \n enter 1 to insert an element\n enter 2 to delete any element\n enter 3 for sorting\n");
 scanf("%d",&c);
 switch(c)
 {
 case 1:
 insert();
 break;
 case 2:
 del();
 break;
 case 3:
 int q;
 printf(" enter 1 for selection sorting\n enter 2 for bubble sorting\n");
 scanf("%d",&q);
 if(q==1)
 selsort();
 else
 bubsort();
 break;
 default:
 printf("\n enter the choice correctly\n");
 }
 print();
 printf(" to continue making changes enter 1 or else enter 0\n");
 scanf("%d",&qw);
 }
 getch();
}