#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
  clrscr();
  int *x,n,i;
  printf("enter the size\n");
  scanf("%d",&n);
  x=(int*)malloc(sizeof(int));
  printf("enter the elements\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&x[i]);
  }
  printf("elements are\n");
  for(i=0;i<n;i++)
  {
  printf("%d\n",x[i]);
  }
  getch();
  }
