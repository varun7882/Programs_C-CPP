#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 int *a,**b,r,c;
 printf(" enter the number of rows and columns in your 2 d matrix\n");
 scanf("%d%d",&r,&c);
 printf("enter the element in the matrix\n");
 b=(int**)malloc(r*sizeof(int*));
 for(int i=0;i<r;i++)
 {
  a=(int*)malloc(c*sizeof(int));
  b[i]=a;
  for(int j=0;j<c;j++)
  {
   scanf("%d",&b[i][j]);
  }
 }
 printf(" the matrix is...\n");
 for(i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 printf("%d",b[i][j]);
 }
 printf("\n");
 }
 getch();
 }