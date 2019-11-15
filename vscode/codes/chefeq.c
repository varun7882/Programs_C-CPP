#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        long int a[100000],x,y,j,c,k=0,i=0;
        scanf("%d",&x);
        y=x;
        while(x>0)
        {
         scanf(" %d",&a[i++]);
          x--;
        }
     for(i=0;i<y;i++)
     {
         c=0;
         for(j=0;j<y;j++)
         {
             if(a[i]==a[j])
             {
              c++;
             }
         }
             if(c>=k)
            {
             k=c;
            }
         }
     if(k==0)
     {
      printf("%d",(y-1));
     }
     else if(k==y)
     {
         printf("%d",0);
     }
     else
     {
      printf("%d",(y-k));
     }

  n--;
}
return 0;
}

