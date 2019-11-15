#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int d;
 struct node *next;
 struct node *prev;
};
typedef struct node NODE;
NODE *first,*last,*temp1,*temp2,*head;
int choice=1;
int c,q=1,count;
void dftrav()
{
 count=0;
 printf("the doubly linked list\n");
 while(temp1!=0)
 {
 count++;
 printf("%d.%d\n",count,temp1->d);
 temp1=temp1->next;
 }
 printf("\nnumber of nodes are %d",count);
 temp1=first;
}
void dbtrav()
{
 count=0;
 printf("the doubly linked is \n");
 while(temp2!=0)
 {
 count++;
 printf("%d.%d\n",count,temp2->d);
 temp2=temp2->prev;
 }
 printf("number of the nodes are %d",count);
 temp2=last;
}
void insert()
{
 int i,ci,p,f=1;
 NODE *pos,*t;
 pos=(NODE*)malloc(sizeof(NODE));
 if(pos==0)
 printf(" no memory");
 else
 printf(" enter 1 to insert by position i.e. 5 for fifth position\n enter 2 to insert after a given element\n");
 scanf("%d",&ci);
a1: switch(ci)
 {
 case 1:
 printf(" enter the position where the element is to be inserted\n");
 scanf("%d",&p);
 if(p>(count+1))
 {
 printf(" not possible\n");
 break;
 }
 printf(" enter the element to be inserted\n");
 scanf("%d",&pos->d);
 if(p==1)
 {
 pos->prev=0;
 first=pos;
 temp1->prev=pos;
 pos->next=temp1;
 temp1=first;
 }
 else if(p==(count+1))
 {
 pos->next=0;
 last->next=pos;
 pos->prev=temp2;
 temp2=last=pos;
 }
 else
 {
 for(i=1;i<p;i++)
 {
  temp1=temp1->next;
 }
  pos->next=temp1;
  t=pos->prev=temp1->prev;
  temp1->prev=pos;
  t->next=pos;
  temp1=first;
  }
  break;
  case 2:
 a2:printf(" enter the element after which the element to be inserted\n");
  scanf("%d",&p);
  while(temp1!=0)
  {
  if(temp1->d==p)
  {
  f=0;
  break;
  }
  temp1=temp1->next;
  }
  if(f==1)
  {
  printf(" entered number is not in list try again\n");
  temp1=first;
  goto a2;
  }
  else
  printf(" enter the element to be inserted\n");
  scanf("%d",&pos->d);
  pos->next=temp1->next;
  temp1->next=pos;
  pos->prev=temp1;
  temp1=first;
  break;
 default:
 printf("enter the correct choice\n");
 }
}
void erase()
{
 int x,F=0;
 NODE *t;
 printf("enter the element to be deleted\n");
 scanf("%d",&x);
 while(temp1!=0)
 {
 if(temp1->d==x)
 {
  if(temp1==first)
  {
   temp1=first=temp1->next;
   temp1->prev=0;
   break;
  }
  else if(temp1==last)
  {
   temp2=last=temp2->prev;
   temp2->next=0;
   temp1=first;
   break;
  }
  else
  {
  t->next=temp1->next;
  t=temp1;
  temp1=temp1->next;
  temp1->prev=t->prev;
  temp1=first;
  break;
  }
  F=1;
 }
  t=temp1;
  temp1=temp1->next;
 }
 if(F==0)
 {
 temp1=first;
 printf("element not in list\n");
 }
}
void main()
{
clrscr();
first=0;
while(choice)
{
printf("enter the element\n");
head=(NODE*)malloc(sizeof(NODE));
scanf("%d",&head->d);
if(first==0)
{
first=temp1=head;
first->prev=0;
}
else
{
temp1->next=head;
head->prev=temp1;
temp1=head;
}
printf(" if you want to continue enter 1 otherwise enter 0\n");
scanf("%d",&choice);
}
temp1->next=0;
last=temp2=temp1,temp1=first;
while(q)
{
a3:printf(" enter 1 if you want to travese normaly\n if you want to traverse backwards enter 2\n");
scanf("%d",&c);
switch(c)
{
case 1:
dftrav();
break;
case 2:
dbtrav();
break;
default:
printf("WRONG CHOICE\n");
goto a3;
}
printf("\n enter 1 to make changes or else 0\n");
scanf("%d",&q);
while(q)
{
a4:printf(" enter 1 to insert an element\n enter 2 to delete any element\n");
scanf("%d",&c);
switch(c)
{
case 1:
insert();
dftrav();
break;
case 2:
erase();
dftrav();
break;
default:
printf("WRONG CHOICE\n");
goto a4;
}
printf(" \nif you want to make changes\n enter 1 or else \n enter 0\n");
scanf("%d",&q);
}
printf("\n to exit enter 0  \n else enter 1\n");
scanf("%d",&q);
}
 getch();
}
