#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100],n,p,i,c=1,t=-1;
void show()
{
if(t==-1)
{
printf(" empty stack:UNDERFLOW\n");
}
else
{
 printf(" stack is...\n");
 for(i=t;i>=0;i--)
 {
 printf(" %d\n",a[i]);
 }
}
}
void push()
{
if(t==(n-1))
{
printf(" not sufficient memory:OVERFLOW\n");
}
else
{
t=t+1;
printf(" enter the element\n");
scanf("%d",&a[t]);
}
}
void pop()
{
 if(t==-1)
 {
 printf(" empty stack:UNDERFLOW\n");
 }
 else
 {
  printf(" popped element is %d\n",a[t]);
  t=t-1;
 }
}
void main()
{
 clrscr();
 printf(" enter the capacity of storing element\n");
 scanf("%d",&n);
 printf(" if you want to add an element in stack enter 1 or else enter 0\n");
 scanf("%d",&c);
 while(c)
{
 if(t<(n-1))
 {
 t++;
 printf(" enter the element in stack\n");
 scanf("%d",&a[t]);
 }
 else
 {
 printf(" stack has no further memory: OVERFLOW\n");
 break;
 }
 printf(" if you want to add an element in stack enter 1 or else enter 0\n");
 scanf("%d",&c);
}
 show();
 printf(" enter 1 if you want to perform push or pop operations else enter 0\n");
 scanf("%d",&c);
 while(c)
 {
a: printf(" enter 1: for push operation\n enter 2: for pop operation\n ");
 scanf("%d",&p);
 switch(p)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 default:
 printf(" thik se padh k koi button dabaya kro -_- \n ");
 goto a;
 }
 show();
 printf(" enter 1 if you want to perform push or pop operations else enter 0\n");
 scanf("%d",&c);
 }
 printf(" finally ");
 show();
 getch();
}
