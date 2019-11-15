#include<stdio.h>
#include<conio.h>
void main()
{
    long int a[100000],b[100000],i,j,n,t,tt;
 //   printf("enter the elements in array\n");
    scanf("%ld",&tt);
    while(tt--)
    {
    scanf("%ld",&n);
   // printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        t=0;
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                    t++;
            }
        }
        b[i]=t;
    }
    //printf("Sorted array is...\n");
    for(i=0;i<n;i++)
    {
        printf("%ld ",b[i]);
    }
    printf("\n");
    }
}
