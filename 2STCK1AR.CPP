#include<stdio.h>
#include<conio.h>
int a[100],t1,t2,i,n;
void push1()
{

if(t1==(t2-1)||t1>t2)
{
 printf(" stack filled\n");
}
else
{
 t1=t1+1;
 printf(" enter the element in stack 1\n");
 scanf("%d",&a[t1]);
}
}
void pop1()
{
if(t1!=-1)
{
printf(" popped element is %d",a[t1]);
a[t1]=0;
t1=t1-1;
}
else
{
printf(" empty stack\n");
}
}
void push2()
{
 if(t1==(t2-1)||t1>t2)
 printf(" stack filled\n");
 else
{
 t2=t2-1;
 printf(" enter the element in stack 2\n");
 scanf("%d",&a[t2]);
}
}
void pop2()
{
if(t2!=n)
{
printf(" popped element is %d",a[t2]);
a[t2]=0;
t2=t2+1;
}
else
{
printf(" empty stack\n");
}
}
void show()
{
 printf("\n your both stacks in one array...... \n\n");
 for(i=0;i<n;i++)
 {
 printf(" %d ",a[i]);
 }
 printf("\n\n now your both stacks seperately\n");
 if(t1!=-1)
 {
  printf("\n stack 1...\n");
  for(i=t1;i>=0;i--)
  {
  printf("%d\n",a[i]);
  }
 }
 else
 printf(" stack 1 is empty\n");
 if(t2!=n)
 {
  printf("\n stack 2... \n");
  for(i=t2;i<n;i++)
  {
  printf("%d\n",a[i]);
  }
 }
 else
 printf(" stack 2 is empty\n");
 }
void main()
{
clrscr();
int c=1,q,e;
printf(" enter the memory of array\n");
scanf("%d",&n);
t1=-1,t2=n;
while(c)
{
printf("\n enter 1 : to enter an element in stack 1\n enter 2 : to enter an element in stack 2\n PS: ek bat bataye ye dono stacks na ek hi array me h bekar ka drama h hona kuch ni h wi same h kuch nya na h\n");
scanf("%d",&q);
switch(q)
{
case 1:
push1();
break;
case 2:
push2();
break;
default:
printf(" yar number to dekh k dal diya kro\n ");
}
printf("\n if you want to continue adding elements in the stacks enter 1 ni to 0\n");
scanf("%d",&c);
}
show();
printf("\n if you want to perform operations like push and pop enter 1 or else enter 0\n");
scanf("%d",&c);
while(c)
{
printf(" enter 1: push operation\n enter 2: pop  operation\n");
scanf("%d",&q);
switch(q)
{
case 1:
printf(" enter 1: to push in stack 1\n enter 2: to push in stack 2\n");
scanf("%d",&e);
if(e==1)
{
push1();
}
else if(e==2)
{
push2();
}
else
{
printf(" are you blind?? yr choice to kayde se dala kro -_- \n ");
}
show();
break;
case 2:
printf(" enter 1: to pop from stack 1\n enter 2: to pop from stack 2\n");
scanf("%d",&e);
if(e==1)
{
pop1();
}
else if(e==2)
{
pop2();
}
else
{
printf(" are you blind?? yr choice to kayde se dala kro -_- \n ");
}
show();
break;
default:
printf(" yr kitni bar bataye dekh k choice dala kro\n");
show();
break;
}
printf("\n if you want to continue doing operations enter 1 or else enter 0\n");
scanf("%d",&c);
}
getch();
}
