#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,k,s;
int a[3][3],b[3][3];
printf("enter first matrix\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("enter second matrix\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&b[i][j]);
}
}
printf("the multiplied matrix is..\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
s=0;
for(k=0;k<3;k++)
{
s=s+a[i][k]*b[k][j];
}
printf("%d  ",s);
}
printf("\n");
}
return 0;
getch();
}

