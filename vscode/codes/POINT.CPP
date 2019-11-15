#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int swap (int*x int*y
void main()
{
int a,b;
printf("enter two no's");
scanf("%d%d",&a,&b);
swap(&a,&b);
printf("%d%d",a,b);
getch();
}
int swap(int *x,int *y); 																																						   int *y)
{
int t;
t=*x;
*x=*y;
*y=t;
}
