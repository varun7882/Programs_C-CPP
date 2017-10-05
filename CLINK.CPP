#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int d;
struct node *ptr;
};
typedef struct node NODE;
NODE *first,*temp,*head;
int count,choice=1;
void trav()
{
count=0;
printf(" the linked list is...\n");
do
{
count++;
printf("%d.%d\n",count,temp->d);
temp=temp->ptr;
}
while(temp!=first);
temp=first;
}
void main()
{
 first=0;
 clrscr();
 while(choice)
 {
 printf(" enter the element\n");
 head=(NODE*)malloc(sizeof(NODE));
 scanf("%d",&head->d);
 if(first==0)
 {
  first=temp=head;
 }
 else
 {
 temp->ptr=head;
 temp=head;
 }
 printf(" if you want to continue enter 1 otherwise enter 0\n");
 scanf("%d",&choice);
 }
 temp->ptr=first;
 temp=first;
 trav();
 getch();
}
