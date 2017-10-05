#include<stdio.h>
#include<conio.h>
void main()
{
float r,A,C, pi=3.14;
clrscr();
printf("enter the radius\n");
scanf("%f",&r);
A=pi*r*r;
C=2*pi*r;
printf("the area of circle is %f",A);
printf("\nthe circumference of circle is %f",C);
getch();
}