#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i=1;
float a,b,c,c1,fa,fb,fc,p,q,r,s;
printf("px^3+qx^2+rx+s=0 is equation enter the values of p,q,r,s\n");
scanf("%f%f%f%f",&p,&q,&r,&s);
o:printf(" enter the interval\n");
scanf("%f%f",&a,&b);
while(1)
{
c1=c;
fa=(p*(a*a*a)+q*(a*a)+(r*a)+s);
fb=(p*(b*b*b)+q*(b*b)+(r*b)+s);
if((fa*fb)<0)
{
c=(a+b)/2;
if(c1==c)
{
printf(" root is found %f",c);
break;
}
fc=(p*(c*c*c)+q*(c*c)+(r*c)+s);
if((fa*fc)<0)
{
 b=c;
}
if((fb*fc)<0)
{
 a=c;
}
printf(" iteration no. %d %f\n",i,c);
i++;
}
else
{
 printf(" interval not correct ");
 goto o;
}
}
getch();
}