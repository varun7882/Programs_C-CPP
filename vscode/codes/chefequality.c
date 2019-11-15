#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        int a[100000],x,y,j,c,k=-1,l,i=0;
        scanf("%d",&x);
        y=x;
        while(x>0)
        {
         scanf(" %d",&a[i++]);
          x--;
        }
     for(x=0;x<i;x++)
     {
       c=a[x];
       k=0;
       for(j=0;j<y;j++)
       {
           if(a[j]==c)
           {
               k++;
               if(k>l)
               {
               l=k;
               }
           }
       }
     }
     if(k==0)
     {
      printf("%d",(y-1));
     }
     else
     {
      printf("%d",(y-l));
     }
  return 0;
}


}
