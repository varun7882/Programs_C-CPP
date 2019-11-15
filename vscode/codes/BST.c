#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int d;
    struct node *l;
    struct node *r;
} NODE;
NODE *root,*R,*nxptemp;
void insert(NODE *trav)
{
    NODE *prnttrav,*temp;
        temp=(NODE*)malloc(sizeof(NODE));
        if(temp==NULL)
        {
            printf("no memory\n");
            return;
        }
        else
        {
            printf("enter a value in the tree\n");
            scanf("%d",&(temp->d));
            temp->l=0;
            temp->r=0;
           if(root!=0)
           {
               trav=root;
               while(trav!=0)
               {
                   if((trav->d)>(temp->d))
                   {
                       prnttrav=trav;
                       trav=trav->l;
                   }
                   else
                   {
                         prnttrav=trav;
                       trav=trav->r;
                   }

                }
                if((prnttrav->l)==0)
                {
                    prnttrav->l=temp;
                }
                else
                {
                    prnttrav->r=temp;
                }
            }
           else
           {
               root=temp;
           }
        }
}
 NODE* insucc(NODE* nxtemp)
 {
     while(nxtemp->l!=0)
     {
           nxptemp=nxtemp;
         nxtemp=nxtemp->l;
     }
     return nxtemp;
 }
void nodedel(NODE *temp)
{
    int x,f=0;
    NODE *prnttrav,*chtemp;
    prnttrav=temp;
    printf("enter the element\n");
    scanf("%d",&x);
    while(temp!=0)
    {
        if((temp->d)==x)
        {
            f=1;
            break;
        }
        else if((temp->d)>x)
        {
            prnttrav=temp;
            temp=temp->l;
        }
        else
        {
          prnttrav=temp;
          temp=temp->r;
        }
    }
    if(f==1)
    {

        if(((temp->l)==0)&&((temp->r)==0))
        {

                 if(temp==root)
                {
                root=0;
                }
            if(prnttrav->l==temp)
            {
               prnttrav->l=0;
            }
             if(prnttrav->r==temp)
            {
                prnttrav->r=0;
            }

            free(temp);
        }
         else if(((temp->l)==0)||((temp->r)==0))
        {
            if(temp->l==0)
            {
               chtemp=temp->r;
            }
            else
            {
                chtemp=temp->l;
            }
                 if(temp==root)
                {
                root=chtemp;
                }
            if(prnttrav->l==temp)
            {
               prnttrav->l=chtemp;
            }
             if(prnttrav->r==temp)
            {
               prnttrav->r=chtemp;
            }

            free(temp);
        }
        else
        {

            chtemp=insucc(temp->r);
              nxptemp->l=chtemp->r;
            chtemp->l=temp->l;
            chtemp->r=temp->r;
              if(temp==root)
                {
                    root=chtemp;
                if(temp->r==chtemp)
                {
                    chtemp->r=0;
                }
                }
             if(prnttrav->l==temp)
            {
                prnttrav->l=chtemp;
            }
             if(prnttrav->r==temp)
            {
                prnttrav->r=chtemp;
            }

            free(temp);
        }
    }
    else
    {
        printf("the element is not in tree\n");
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
}int main()
{
    NODE *temp,*trav,*prnttrav;
    R=root=0;
    int c=1,n;
    while(c)
    {
        insert(root);
        printf("enter 1 if you want to add more elements else enter 0\n");
        scanf("%d",&c);
    }
     preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("enter 1 to make changes or else 0\n");
    scanf("%d",&c);
    while(c)
    {
        printf(" enter 1 to insert \n enter 2 to delete\n");
        scanf("%d",&n);
        if(n==1)
        {
            insert(root);
        }
        if(n==2)
        {
            nodedel(root);
        }
         preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("enter 1 to make changes or else 0\n");
    scanf("%d",&c);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
 return 0;
}
