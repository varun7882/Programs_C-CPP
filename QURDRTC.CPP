#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 clrscr();
 float a,b,c;
 float x1,x2,d,p,q;
 printf(" let as assume a quardatic equation of format ax2+bx+c=0\n enter the values of a,b and c\n");
 scanf("%f%f%f",&a,&b,&c);
 printf("%fx^2+%fx+%f",a,b,c);
 d=((b*b)-(4*a*c));
 if(d<0)
 {
 printf("roots are imaginary\n");
 d=(d*(-1));
 d=sqrt(d);
 p=((-b)/(2*a));
 q=(d/(2*a));
 printf("%f+%fi",p,q);
 printf("\n%f%fi",p,(-q));
 }
 else if(d==0||d>0)
 {
 d=sqrt(d);
 x1=(((-b)+d)/(a*2));
 printf("the roots are\n %f",x1);
 x2=(((-b)-d)/(2*a));
 printf("\n %f",x2);
 }
 getch();
}
