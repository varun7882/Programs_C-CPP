#include<stdio.h>
#include<conio.h>
int n;
void insertionsort(double b[][100],int p,int n1)
{

    int i,j,k;
       for(i=1;i<n1;i++)
    {
        k=b[p][i];
        j=i-1;
        while((j>=0)&&(b[p][j]>=k))
        {
            b[p][j+1]=b[p][j];
            j=j-1;
        }
        b[p][j+1]=k;
    }
 }
void main()
 {
     int i,j,t,c[10]={0};
     double a[100],b[10][100];
     printf("enter the number of elements\n");
     scanf("%d",&n);
     printf("enter the elements in range [0,1)\n");
     for(i=0;i<n;i++)
     {
         scanf("%f",&a[i]);
     }
      for(i=0;i<n;i++)
   {
       printf("%.2f\n",a[i]);
   }
    for(i=0;i<10;i++)
     {
         if(c[i]>0)
         {
        insertionsort(b,i,c[i]);
        }
     }
      for(i=0;i<n;i++)
   {
       printf("%.2f\n",a[i]);
   }
     j=0;
    for(i=0;i<10;i++)
    {
        while(c[i]>0)
        {
        a[j++]=b[i][c[i]];
        }
    }
   for(i=0;i<n;i++)
   {
       printf("%.2f\n",a[i]);
   }
}
