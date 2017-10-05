#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c,d,e;
clrscr();
printf("enter the marks of 5 subjects : ");
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
printf("the sum of five subjects is %d ",(a+b+c+d+e));
printf("\npercentage obtained by the student is %f % ",(a+b+c+d+e)/5.0);
getch();
}
