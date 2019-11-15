#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int d;
 struct node *ptr;
};
typedef struct node NODE;
NODE *front,*rear,*temp;
int choice=0;
void enqueue()
{
 temp=(NODE*)malloc(sizeof(NODE));
 if(temp==0)
 {
 printf(" no memory\n");
 }
 else
 {
  printf(" enter the element\n");
  scanf("%d",&temp->d);
  if(front==0)
  {
   front=rear=temp;
   rear->ptr=0;
  }
  else
  {
 rear=rear->ptr=temp;
  rear->ptr=0;
  }
 }
}
void dequeue()
{
 NODE *t;
 if(front==0)
 {
 printf(" no element in queue \n");
 }
 else
 {
 printf(" element from the queue is...\n %d",front->d);
 t=front;
 front=front->ptr;
 free(t);
 }
}
void traverse()
{
NODE *t;
t=front;
if(t==0)
printf(" nothing in queue\n");
else
printf("\n  queue is... ");
while(t!=0)
{
 printf("  %d  ",t->d);
 t=t->ptr;
}
}
void main()
{
 clrscr();
 front=0;
 printf(" to create queue enter 1 otherwise 0\n");
 scanf("%d",&choice);
 while(choice)
 {
  enqueue();
  printf("\n to continue adding element enter 1 or else enter 0\n");
  scanf("%d",&choice);
 }
 traverse();
 printf("\n enter 1 to perform operations or else 0\n");
 scanf("%d",&choice);
 while(choice)
 {
a:printf("\n enter 1 to enqueue\n enter 2 to dequeue\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   enqueue();
   traverse();
   break;
   case 2:
   dequeue();
   traverse();
   break;
   default:
   goto a;
  }
  printf("\n enter 1 to perform operations or else 0\n");
 scanf("%d",&choice);
 }
 traverse();
 getch();
}