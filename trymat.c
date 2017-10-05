#include<stdio.h>
#include<conio.h>
int a[100][100],b[100][100],c[100][100],n,i,j;
int c11[50][50],c12[50][50],c21[50][50],c22[50][50];
    int a11[50][50],a12[50][50],a21[50][50],a22[50][50];
    int b11[50][50],b12[50][50],b21[50][50],b22[50][50];
int strmatmulti(int n1,int a[][n1], int b[][n1])
{
    if(n1==1)
    {
        c[0][0]=(a[0][0])*(b[0][0]);
        return c[0][0];
    }
    else
    {
        int t;

    for(i=0;i<n1;i++)
    {
        for(j=0;j<n1;j++)
        {
            a11[i][j]=a[i][j];
            b11[i][j]=b[i][j];
            c11[i][j]=c[i][j];
        }
    }
    t=n1;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n1;j++)
        {
            a12[i][j]=a[i][j+t];
            b12[i][j]=b[i][j+t];
            c12[i][j]=c[i][j+t];
            t++;
        }
    }
    t=n1;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n1;j++)
        {
            a21[i][j]=a[i+t][j];
            b21[i][j]=b[i+t][j];
            c21[i][j]=c[i+t][j];
            t++;
        }
    }
    t=n1;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n1;j++)
        {
            a22[i][j]=a[i+t][j+t];
            b22[i][j]=b[i+t][j+t];
            c22[i][j]=c[i+t][j+t];
            t++;
        }
    }
    n1=n1/2;
    c11[50][50]= (strmatmulti(n1,a11[][n1],b11[][n1]))+(str(n1,a12[][n1],b21[][n1]));
    c12[50][50]= strmatmulti(n1,a11[][n1],b12[][n1])+str(n1,a12[][n1],b22[][n1]);
    c21[50][50]= strmatmulti(n1,a21[][n1],b11[][n1])+str(n1,a22[][n1],b21[][n1]);
    c22[50][50]= strmatmulti(n1,a21[][n1],b12[][n1])+str(n1,a22[][n1],b22[][n1]);
    }
     for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            printf("%d ",c11[i][j]);
            printf("%d ",c12[i][j]);
            printf("%d ",c21[i][j]);
            printf("%d ",c22[i][j]);
        }
        printf("/n");

    }
}
void main()
 {
    printf("enter the order of square martix");
    scanf("%d",&n);
    printf("enter first matrix\n");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
    scanf("%d",&a[i][j]);
    }
    }
    printf("enter second matrix\n");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
    scanf("%d",&b[i][j]);
    }
    }
    strmatmulti(a,b,n);
    printf("the multiplied matrix is..\n");

 }
