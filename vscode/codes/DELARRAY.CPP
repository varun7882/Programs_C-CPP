#include<stdio.h>
#include<conio.h>
  int a[100];
  int n,i,c,x,f=0;
  void showtime()
  {
  printf("the elements in array are...\n");
  for(i=0;i<n;i++)
  {
  printf("%d\n",a[i]);
  }
  }
  void main()
  {
  clrscr();
  printf("enter the number of elements in an array\n");
  scanf("%d",&n);
  printf("enter the elements\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
a:showtime();
  printf(" enter 1 if you want to delete any element\n enter 0 to exit\n");
  scanf("%d",&c);
  if(c==1)
  {
  printf("enter the element to be deleted\n");
  scanf("%d",&x);
  for(i=0;i<n;i++)
  {
  if(x==a[i])
  {
  while(i<n)
  {
  a[i]=a[i+1];
  i++;
  f=1;
  }
  n=n-1;
  break;
  }
  }
  if(f=0)
  {
  printf("number not found\n");
  }
  goto a;
  }
  showtime();
  getch();
}
