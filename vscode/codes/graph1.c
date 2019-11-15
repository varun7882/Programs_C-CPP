#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node *nxt;
}NODE;
typedef struct heads
{
 NODE *start;
}H;
typedef struct graph
{
    int v;
   H *strt;
}graph;
graph* makegraph(int v)
{
    graph *G;
    int i;
    G=(graph*)malloc(sizeof(graph));
    G->v=v;
    G->strt=(H*)malloc(sizeof(H)*v);
    for(i=0;i<v;i++)
    {
        G->strt[i].start=0;
    }
    return G;
}
void addedge(graph*g,int s,int d)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->x=d;
    temp->nxt=g->strt[s].start;
    g->strt[s].start=temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->x=s;
    temp->nxt=g->strt[d].start;
    g->strt[d].start=temp;
}
void print(graph *g)
{
    int i;
    NODE *temp;
    printf("Graph is...\n");
    for(i=0;i<g->v;i++)
    {
         printf("%d ",i);
         temp=g->strt[i].start;
        while(temp!=0)
        {
          printf("-> %d ",temp->x);
          temp=temp->nxt;
        }
        printf("\n");
    }
}
int main()
{
    int v,i,c,s,d;
    graph *G;
    printf("enter number of vertices\n");
    scanf("%d",&v);
    G=makegraph(v);
      printf("To add edges enter 1 or else enter 0\n");
      scanf("%d",&c);

    while(c)
    {
        printf("enter an edge in format: source destination respectively\n");
         scanf("%d%d",&s,&d);
        if(s>=0 && s<5 && d>=0 && d<5)
        {
         addedge(G,s,d);
        }
        else{
         printf("invalid value:try again\n");
         }
         printf("To add edges enter 1 or else enter 0\n");
      scanf("%d",&c);
    }
    print(G);
    return 0;
}
