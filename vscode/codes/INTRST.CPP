#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
float p,r,t,s,c;
clrscr();
printf("enter the principal amount, rate of intrest and time :");
scanf("%f%f%f",&p,&r,&t);
s=(p*r*t)/100.0;
c=p*pow((1+r/100.0),t);
printf("\nthe simple intrest is %f",s);
printf("\nthe compound intrest is %f",c);
getch();
}