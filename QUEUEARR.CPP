#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,n,c,p,f=-1,r=-1;
int a[100];
 void show()
 {
 if(r==-1||r==f)
 printf(" empty queue:UNDERFLOW\n");
 else
 printf(" queue is \n");
 for(i=(f+1);i<=r;i++)
 {
 printf(" %d ",a[i]);
 }
 }
 void push()
 {
 if(r==(n-1))
 {
 printf(" no space:OVERFLOW\n");
 }
 else
 {
  printf(" enter the element to be pushed\n");
  r=r+1;
  scanf("%d",&a[r]);
 }
 }
 void pop()
 {
 if(r==-1||r==f)
 {
 printf(" empty queue:UNDERFLOW\n");
 }
 else
 {
 f=f+1;
 printf(" popped element is %d\n",a[f]);
 }
 }
 void main()
{
 clrscr();
 printf(" enter the capacity of the queue\n");
 scanf("%d",&n);
 printf(" enter 1 if you want to add an element in the queue\n else enter 0\n");
 scanf("%d",&c);
 while(c)
 {
 if(r==(n-1))
 {
 printf(" no space:OVERFLOW\n");
 break;
 }
 else
 {
 r=r+1;
 printf(" enter the element\n");
 scanf("%d",&a[r]);
 printf(" enter 1 if you want to add an element in the queue\n else enter 0\n");
 scanf("%d",&c);
 }
 }
 show();
 printf("\n enter 1 if you want to perform operations in your queue\n otherwise enter 0\n");
 scanf("%d",&c);
 while(c)
 {
 printf(" Push operation: enter 1\n Pop  operation: enter 2\n");
 scanf("%d",&p);
 switch(p)
 {
 case 1:
 push();
 show();
 break;
 case 2:
 pop();
 show();
 break;
 default:
 printf(" yar dekh k number enter kiya karo\n");
 break;
 }
 printf("\n enter 1 if you want to perform operations in your queue\n otherwise enter 0\n");
 scanf("%d",&c);
 }
 printf(" finally ");
 show();
 getch();
}

