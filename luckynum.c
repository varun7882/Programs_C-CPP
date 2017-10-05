#include<stdio.h>
int main()
{
   int i,t,j,f=1;
   int v = 1;
   long a[1000];
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       scanf("%ld",&a[i]);
   }
   for(i=0;i<t;i++)
   {
       j=3;
       while(j<a[i]/2)
       {
           if((a[i]%j==0) && v==1)
           {
               f=0;
               break;
           }
           v=!v;
           j++;
       }
       if(f==1)
       {
           printf("lucky number");
       }
       else
       {
            printf("sorry");
       }
   }

    return 0;
}
