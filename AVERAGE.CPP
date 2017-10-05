#include<stdio.h>
#include<conio.h>
void main()
{
float a,b,c;
clrscr();
printf("\n\n\t\t\tTo find average of two given numbers\n");
printf("\n\n\n\n\t\t\t\tEnter the Two values : ");
printf("\n\t\t\t\t     Numer 1 : ");
scanf("%f",&a);
printf("\t\t\t\t     Numer 2 : ");
scanf("%f",&b);
c=(a+b)/2;
printf("\n\n\t\t\tThe average value is = %f",c);
getch();
}