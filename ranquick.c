#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void main()
{
    int a[50],r,ran,p=8;
    printf("enter the number of elements\n");
    scanf("%d",&r);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
    ran= rand() % r;
    if(ran<p)
    {
        ran=ran+p;
    }
    printf("random %d ",ran);
}

