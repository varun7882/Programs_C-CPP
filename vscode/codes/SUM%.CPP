#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c,d,e;
float g,f,h;
printf("enter maximum marks");
scanf("%d",&f);
printf("enter the marks of subjects");
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
g=(a+b+c+d+e);
h=(5.0*f);
printf("the sum of five subjects is %f",g);
printf("out of %f",(5*f));
printf("the percentage score is %f",(g*100.0)/h);
getch();
}
