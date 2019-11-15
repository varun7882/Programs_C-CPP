#include<stdio.h>
#include<limits.h>
typedef struct node
{
    int x;
    struct node* nxt;

}NODE;
typedef struct head
{
    NODE *d;
}HEAD;
typedef struct graph
{
    int v;
    HEAD *a;
}G;
G* makegraph(int v)
{
   G *graphstart;

}
int main()
{
    int v,e,i;
    printf("enter the number of vertices\n");
    scanf("%d",&v);

    return 0;
}

