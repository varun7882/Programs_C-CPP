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
 int choice=1;
 int count;
 void traverse ()
 {
   count=0;
 printf("status of your list\n");
 while(temp!=0)
 {
 printf("%d.%d\n",(count+1),temp->d);
 temp=temp->ptr;
 count++;
 }
 printf("no of nodes are %d\n ",count);
 temp=first;
 }
 void insertbeg()
 {
 NODE *beg,*t;
 beg=(NODE*)malloc(sizeof(NODE));
 printf("enter the element at beginning\n");
 scanf("%d",&beg->d);
 t=first;
 first=beg;
 beg->ptr=t;
 temp=first;
 }
 void insertend()
 {
 NODE *end,*y;
 end=(NODE*)malloc(sizeof(NODE));
 printf("enter the element\n");
 scanf("%d",&end->d);
 while(temp!=0)
 {
 y=temp;
 temp=temp->ptr;
 }
 y->ptr=end;
 end->ptr=0;
 temp=first;
 }
 void insertpos()
 {
 int i,p,c;
  printf(" enter 1 to insert an element at a given position\n enter 2 to insert an element after an element\n");
  scanf("%d",&c);
  NODE *pos,*z;
  pos=(NODE*)malloc(sizeof(NODE));
  if(c==1)
  {
  d:printf("enter the position i.e. 4 for fourth position\n");
  scanf("%d",&p);
  if(p==1)
  {
  insertbeg();
  }
  else
  {
  if(p>(count+1))
  {
   printf(" position not possible\n");
   goto d;
  }
  else if(p<=(count+1))
   printf("enter the element\n");
  scanf("%d",&pos->d);
  for(i=1;i<(p-1);i++)
  {
  temp=temp->ptr;
  }
  z=temp;
  z=z->ptr;
  temp->ptr=pos;
  pos->ptr=z;
  temp=first;
  }
  }
  else if(c==2)
  {
  int q,m=1;
  printf("enter the element after which new element is to be inserted\n");
  scanf("%d",&q);
  printf("enter the element to be inserted\n");
  scanf("%d",&pos->d);
  while(temp!=0)
  {
  if(q==temp->d)
  {
  m=0;
  break;
  }
  temp=temp->ptr;
  }
   if(m==0)
   {
   z=temp->ptr;
   temp->ptr=pos;
   pos->ptr=z;
   }
  else
  {
   printf(" entered element not found in the list\n");
  }
  temp=first;
  }
  }
 void erase()
 {
 int i,p,r;
 printf(" enter 1 to delete by position i.e. 6 for sixth element\n enter 2 to delete by the element\n");
 scanf("%d",&r);
 if(r==1)
 {
 NODE *t;
 printf("enter the node to be deleted\n");
 scanf("%d",&p);
 if(p>count)
 {
 printf(" node not available\n");
 }
 if(p==1)
 {
 first=temp=temp->ptr;
 }
 else if(p==count)
 {
 for(i=1;i<(p-1);i++)
 {
 temp=temp->ptr;
 }
 temp->ptr=0;
 }
 else
 {
 for(i=1;i<(p+1);i++)
 {
  temp=temp->ptr;
 }
 t=temp;
 temp=first;
 for(i=1;i<(p-1);i++)
 {
 temp=temp->ptr;
 }
 temp->ptr=t;
 }
 temp=first;
 }
 else if(r==2)
 {
 int c=0,z=0;
 printf("enter the element to be deleted\n");
 scanf("%d",&p);
 while(temp!=0)
 {
  if(temp->d==p)
  {
  c=1;
  break;
  }
  temp=temp->ptr;
 }
 temp=first;
 if(c==1)
 {
 do
 {
 z++;
 NODE *t;
  if(p==temp->d)
  {
  if(z==1)
   {
    first=temp->ptr;
    temp=first;
    break;
   }
   else
   {
   t->ptr=temp->ptr;
   temp=first;
   break;
   }
   }
  t=temp;
 temp=temp->ptr;
 }
 while(temp!=0);
 }
 else if(c==0)
 {
 printf(" dekh to liya kro paggl ldki ki number list me h bhi ya ni -_- \n");
 }
 }
 }
 void rev()
 {
 NODE *next,*prev;
 prev=0;
 while(temp!=0)
 {
  next=temp->ptr;
  temp->ptr=prev;
  prev=temp;
  temp=next;
 }
 first=prev;
 temp=first;
 }
 void sort()
 {
  NODE *a,*b;
  int i,j,c,t;
  printf(" enter 1 for selection sort \n enter 2 for bubble sort \n ");
  scanf("%d",&c);
  switch(c)
  {
  case 1:
   a=first;
   for(i=0;i<(count-1);i++)
   {
    b=a->ptr;
    for(j=i+1;j<count;j++)
    {
     if((a->d)>(b->d))
     {
      t=a->d;
      a->d=b->d;
      b->d=t;
     }
     b=b->ptr;
    }
    a=a->ptr;
   }
   break;
  case 2:
  for(i=0;i<(count-1);i++)
  {
   a=first;
   for(j=0;j<(count-1-i);j++)
   {
    if((a->d)>(a->ptr->d))
    {
     t=a->d;
     a->d=a->ptr->d;
     a->ptr->d=t;
    }
    a=a->ptr;
   }
  }
  break;
  default:
  printf(" incorrect choice\n");
  }
 }
 void p_sort()
 {
  NODE *a,*b,*c,*d,*t;
  int i,j,ci;
  printf(" enter 1 for selection sort \n enter 2 for bubble sort \n ");
  scanf("%d",&ci);
  switch(ci)
  {
   case 1:
   a=first;
   while(a->ptr!=0)
   {
   b=d=a->ptr;
    while(b!=0)
    {
     if((a->d)>(b->d))
     {
      if(a->ptr==b)
      {
       if(a==first)
       {
	a->ptr=b->ptr;
	b->ptr=first;
	first=b;
	t=a;
	a=b;
	b=t;
	d=b;
	b=b->ptr;
       }
       else
       {
	a->ptr=b->ptr;
	b->ptr=a;
	c->ptr=b;
	t=a;
	a=b;
	b=t;
	d=b;
	b=b->ptr;
       }
      }
      else
      {
       if(a==first)
       {
	t=a->ptr;
	a->ptr=b->ptr;
	b->ptr=t;
	first=b;
	d->ptr=a;
	t=a;
	a=b;
	b=t;
	d=b;
	b=b->ptr;
       }
       else
       {
	t=a->ptr;
	a->ptr=b->ptr;
	b->ptr=t;
	d->ptr=a;
	c->ptr=b;
	t=a;
	a=b;
	b=t;
	d=b;
	b=b->ptr;
       }
      }
     }
      d=b;
      b=b->ptr;
     }
      c=a;
      a=a->ptr;
    }
     break;
    case 2:
    a=first;
    while(a->ptr!=0)
    {
     b=first;
    while(b->ptr!=0)
     {
     c=b->ptr;
     if((b->d)>(c->d))
     {
      if(b==first)
      {
      b->ptr=c->ptr;
      c->ptr=b;
      first=c;
      t=b;
      b=c;
      c=t;
      d=b;
      b=b->ptr;
      }
      else
      {
      b->ptr=c->ptr;
      c->ptr=b;
      d->ptr=c;
      t=b;
      b=c;
      c=t;
      d=b;
      b=b->ptr;
      }
     }
     d=b;
     b=b->ptr;
     }
     a=a->ptr;
    }
    break;
   default:
   printf(" enter the correct choice\n");
  }
  temp=first;
 }

 int main()
 {
 system("cls");
 int qw;
 first=0;
 int b;
 int bg;
 while(choice)
 {
A: head=(NODE*)malloc(sizeof(NODE));
 printf("enter the data item\n");
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
 printf("if you want to continue enter 1 ni to 0\n");
 scanf("%d",&choice);
 }
  temp->ptr=0;
 temp=first;
 traverse();
 printf("if you want to make changes enter 1 otherwise enter 0\n");
 scanf("%d",&bg);
 while(bg)
 {
 printf(" enter 4 to insert an element in the list\n enter 5 to delete any element\n enter 6 to reverse the list\n enter 7 to sort the list\n");
 scanf("%d",&b);
 if(b==4)
 {
 insertpos();
 }
 else if(b==5)
 {
 erase();
 }
 else if(b==6)
 {
 rev();
 }
 else if(b==7)
 {
 int as;
 printf(" enter 1 for sorting by changing values\n enter 2 for sorting by changing links\n");
 scanf("%d",&as);
 if(as==1)
 sort();
 else if(as==2)
 p_sort();
 else
 printf(" incorrect choice\n");
 }
 else
 {
 printf(" incorrect choice\n");
 }
 traverse();
 printf("if want to continue making changes enter 1 otherwise 0\n");
 scanf("%d",&bg);
 }
 printf("final \n");
 traverse();
 printf("\n if you want to create a new list\n enter 1\n if you want to exit\n enter 0 \n");
 scanf("%d",&qw);
 if(qw==1)
 {
 goto A;
 }
 return 0;
 getch();
 }
