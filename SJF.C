#include<stdio.h>
#include<conio.h>
#include<string.h>
struct pro
{
    char a[100];
    int b;

};
int main()
{
    int i,n,j,t;
    char t1[100];
 struct pro p[100];
 printf("enter the number of processes\n");
 scanf("%d",&n);\
 for(i=0;i<n;i++)
 {
 printf("enter the process name\n");
 scanf("%s",p[i].a);
 printf("enter the CPU burst time\n");
 scanf("%d",&p[i].b);
}
 printf("Assuming that all processes arrive at time '0' \n processes are....\n\n\n");
   printf("PROCESS\t\t BURST TIME\n");
 for(i=0;i<n;i++)
 {
 printf("\n%s\n\t\t ",p[i].a);
 printf("%d",p[i].b);
}
for(i=0;i<n;i++)
{
    for(j=0;j<(n-1);j++)
    {
        if((p[i].b)<=(p[j].b))
        {
           t=p[i].b;
           p[i].b=p[j].b;
           p[j].b=t;

        strcpy(t1,p[i].a);
        strcpy(p[i].a,p[j].a);
        strcpy(p[j].a,t1);
        }

    }
}
  printf("\n\nPROCESS\t\t BURST TIME\n");
 for(i=0;i<n;i++)
 {
 printf("\n%s\n\t\t ",p[i].a);
 printf("%d",p[i].b);
}
}
