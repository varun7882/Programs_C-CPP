#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
clrscr();
 struct node
 {
  int d;
  struct node *ptr;
 };
 typedef struct node NODE;
 NODE *head,*first,*temp=0;
 int count=0;
 int choice=1;
 first=0;
 while(choice)
 {
 head=(NODE*)malloc(sizeof(NODE));
 printf("enter the data item\n");
 scanf("%d",&head->d);
 if(first!=0)
 {
 temp->ptr=head;
 temp=head;
 }
 else
 {
 first=temp=head;
 }
 fflush(stdin);
 printf("want to continue");
 scanf("%d",&choice);
 }
 temp->ptr=0;
 temp=first;
 printf("status of linked list\n");
 while(temp!=0)
 {
 printf("%d\n",temp->d);
 count++;
 temp=temp->ptr;
 }
 printf("nodes%d",count);
  getch();
 }
