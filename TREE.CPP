#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int d;
 struct node *l;
 struct node *r;
};
typedef struct node NODE;
int c=1,p,a=0;
int ch;
NODE *root,*head,*R,*preroot,*t,*succ,*presucc,*temp;
void insert(NODE*,NODE*)
{
 if(root==0)
 {
 R=root=head;
 }
else
 {
  if(((head->d)<(root->d))||((head->d)==(root->d)))
  {
   if(root->l==0)
   {
    root->l=head;
   }
   else
   {
    root=root->l;
    insert(root,head);
   }
  }
  if((head->d)>(root->d))
   {
    if(root->r==0)
    {
     root->r=head;
    }
    else
    {
     root=root->r;
     insert(root,head);
    }
   }
  }
  root=R;
 }
void create()
{
while(c)
{
 head=(NODE*)malloc(sizeof(NODE));
 if(head==0)
 {
 printf("no memory");
 }
 else
  {
  printf(" enter the element\n");
  scanf("%d",&(head->d));
  head->l=0;
  head->r=0;
  insert(root,head);
  }
  printf(" to continue enter 1 or else enter 0\n");
  scanf("%d",&c);
 }
 }
void preorder(NODE *temp)
{
 if(temp!=0)
 {
  printf(" %d ",temp->d);
  preorder(temp->l);
  preorder(temp->r);
 }
}
void inorder(NODE *temp)
{
 if(temp!=0)
 {
  inorder(temp->l);
  printf(" %d ",temp->d);
  inorder(temp->r);
 }
}
void postorder(NODE *temp)
{
 if(temp!=0)
 {
 postorder(temp->l);
 postorder(temp->r);
 printf(" %d ",temp->d);
 }
}
NODE* inordersucc(NODE *temp)
{
    if(temp->l!=0)
    {
        presucc=temp;
        succ=temp->l;
        inordersucc(temp->l);
    }
    return succ;
}
void elmntdelete(NODE*,int x)
{
    if(x==root->d)
    {
        if(a==0)
        {
            if(root->l==0 && root->r==0)
            {
                free(root);
                R=0;
            }
            else if(root->l==0 || root->r==0)
            {
                if(root->l==0)
                {
                    t=root->r;
                }
                else
                {
                    t=root->l;
                }
                free(root);
                R=t;
                a=0;
            }
            else
            {
                  presucc=t=root;
                  succ=root->r;
                succ=inordersucc(succ);
                if(root->r->d==succ->d)
                {
                root->d=succ->d;
                root->r=0;
                }
                else
                {
                 root->d=succ->d;
                 presucc->l=0;
                }
                free(succ);
            }
        }
    }
    else if(x<root->d)
    {
        root=root->l;
        elmntdelete(root,x);
    }
    else
    {
        root=root->r;
        elmntdelete(root,x);
    }
    root=R;
}
int main()
{
    int d;
  root=0;
 create();
 printf("\n preorder traversal is...\n");
 preorder(root);
 printf("\n inorder traversal is...\n");
 inorder(root);
 printf("\n postorder traversal is...\n");
 postorder(root);
 c=1;
 while(c)
 {
    printf("\nenter 1 to insert an element\n");
    printf("enter 2 to delete an element\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        head=(NODE*)malloc(sizeof(NODE));
        if(head==0)
        {
        printf("no memory");
        }
        else
        {
        printf(" enter the element\n");
        scanf("%d",&(head->d));
        head->l=0;
        head->r=0;
        insert(root,head);
        }

    }
    if(ch==2)
    {
        printf("enter the element to be deleted\n");
        scanf("%d",&d);
        elmntdelete(root,d);
    }
    printf("\n preorder traversal is...\n");
    preorder(root);
    printf("\n inorder traversal is...\n");
    inorder(root);
    printf("\n postorder traversal is...\n");
    postorder(root);
    printf("\nif you want to make changes enter 1 or else enter 0\n");
    scanf("%d",&c);
 }
 return 0;
}
