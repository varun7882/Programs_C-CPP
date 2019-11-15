#include<stdio.h>
int main()
{
   int t,n,m,i,j;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       if(n<7)
       {
           m=-1;
       }
       else
       {
           m=n;
       }
       if(m==-1)
       {
           printf("%d\n",m);
       }
       else
       {
          printf("%d\n",m);
          for(i=1;i<6;i++)
          {
              printf("%d %d\n",i,i+1);
          }
          m=1;
          for(i=n;i>=6;i--)
          {
              printf("%d %d\n",i,m);
          }
          printf("%d\n",m+1);
       }
   }
    return 0;
}
