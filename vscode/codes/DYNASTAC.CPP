#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int d;
 struct node *ptr;
};
typedef struct node NODE;
NODE *top,*t,*head,*first;
int choice=0;
void push()
{
 t=top;
 head=(NODE*)malloc(sizeof(NODE));
 if(head==0)
 printf(" stack overflow\n");
 else
 printf(" enter the element in stack\n");
 scanf("%d",&head->d);
 if(first==0)
 {
 first=top=head;
 first->ptr=0;
 }
 else
 {
  first=top=head;
  top->ptr=t;
 }
}
void pop()
{
 if(first==0)
 printf(" stack is empty idiot\n");
 else
 {
  printf(" popped element is.... \n %d\n",top->d);
  first=top=top->ptr;
 }
 free(head);
}
void traverse()
{
 printf("\n your stack is....\n");
 if(first==0)
 printf(" empty\n");
 else
 {
  while(top!=0)
  {
   printf(" %d\n",top->d);
   top=top->ptr;
  }
  top=first;
 }
}
void main()
{
 clrscr();
 first=0;
 printf(" enter 1 to create stack\n");
 scanf("%d",&choice);
 while(choice)
 {
 push();
 printf(" to keep on adding enter 1 otherwise enter 0\n");
 scanf("%d",&choice);
 }
 traverse();
 printf(" enter 1 if you want to perform push-pop operation otherwise enter 0\n");
 scanf(" %d",&choice);
 while(choice)
 {
a:printf(" enter 1 for push operaton\n enter 2 for pop operation\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
   push();
   traverse();
   break;
  case 2:
   pop();
   traverse();
   break;
  default:
   goto a;
 }
 printf(" enter 1 if you want to perform push-pop operation otherwise enter 0\n");
 scanf(" %d",&choice);
 }
 traverse();
 getch();
}