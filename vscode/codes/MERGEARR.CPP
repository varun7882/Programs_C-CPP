#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr();
  int a[100],b[100],c[200];
  int n,m,i,j,k;
  printf("enter the number of elements in array 1\n");
  scanf("%d",&n);
  printf("enter the elements in array 1\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  printf("enter the number of elements in array 2\n");
  scanf("%d",&m);
  printf("enter the elements in array 2\n");
  for(i=0;i<m;i++)
  {
   scanf("%d",&b[i]);
  }
  printf("merged array is\n");
  j=0,k=0;
  for(i=0;i<(n+m);i++)
  {
   if(i<n)
   {
    c[i]=a[j];
    j++;
   }
   else
   {
   c[i]=b[k];
   k++;
   }
  }
  for(i=0;i<(n+m);i++)
  {
  printf("%d\n",c[i]);
  }
  getch();
}
