#include<stdio.h>
#include<conio.h>
void insertionsort(float b[][100],int p,int n)
{
    int i,j,k;
       for(i=1;i<n;i++)
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
     int n,i;
     int a[100];
     printf("enter the number of elements\n");
     scanf("%d",&n);
     printf("enter the elemnts\n");
     for(i=0;i<n;i++)
     {
         scanf("%f",&a[i]);
     }
   printf("\n%d",sizeof(a)/sizeof(a[0]));

 }
