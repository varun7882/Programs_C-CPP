#include<stdio.h>
#include<math.h>
typedef long long int ll;
 typedef struct nodec
{
    long int d;
    struct node *nxt;
}Nc;
 typedef struct node
{
    long int d;
    struct nodec *pf;
    struct nodec *pb;
}N;

struct node* fact(ll x)
{
    long long int i=0,rt;
    N* ls;
    Nc* t1,*t2,*h1,*h2;
    ls=(N*)malloc(sizeof(N));
    ls->d=x;
    rt=sqrt(x);
    printf("hey %lld\n",ls);
    printf("hey %lld\n",ls->d);
    for(i=1;i<rt;i++)
    {
        t1=(Nc*)malloc(sizeof(Nc));
        t2=(Nc*)malloc(sizeof(Nc));
         printf("i is %lld v: %lld %lld\n",i,ls,ls);
          printf("heyo jus %lld\n",ls);
    printf("%lld\n",ls->d);
        if(i==1)
        {
            h1=ls->pf=t1;
            h2=ls->pb=t2;
            t1->d=i;
            t2->d=x;
            t2->nxt=NULL;
            h1->nxt=NULL;
             printf("heyo %lld\n",ls);
    printf("heyo %lld\n",ls->d);
        }
        else
        {
            if(x%i==0)
            {
               t1->nxt=h1;
               t1->d=i;
               h1=t1;
               h2->nxt=t2;
               t2->nxt=NULL;
               t2->d=x/i;
               h2=t2;
                printf("ok %lld\n",ls);
    printf("ok %lld\n",ls->d);
            }
        }
    } printf("%lld\n",ls);
    printf("%lld\n",ls->d);

    return ls;
}
ll mgcd(ll a,ll b)
{

      if(a%b==0)
        {
return b;
   }
        else
        {
            mgcd(b,a%b);
        }

}
void main()
{
    ll a,b,n,lw,hi,ans,t,i;
    N *lss;
    Nc *tr;
    scanf("%lld%lld",&a,&b);
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&lw,&hi);
        ans=mgcd(a,b);
        lss=fact(ans);
        printf("%lld\n",lss);
        if(ans<=lw && ans>=hi)
        {
        printf("%lld\n",ans);
        }
        else if(ans<lw)
        {
            ans=-1;
             printf("%lld\n",ans);
        }
        else
        {
            tr=lss->pf;
            while(tr!=NULL)
            {
                printf("%lld\n",tr->d);
            }
        printf("%lld\n",ans);
        }

    }
}
