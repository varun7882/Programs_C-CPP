#include<stdio.h>
#include<conio.h>
int a[3][3],b[3][3];
int i,j;
void main()
{
clrscr();
printf("enter the elements of the matrix\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("the matrix is\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%d  ",a[i][j]);
}
printf("\n");
}
printf("the transpose of the matrix is\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
b[i][j]=a[j][i];
printf("%d  ",b[i][j]);
}
printf("\n");
}
  getch();
}
