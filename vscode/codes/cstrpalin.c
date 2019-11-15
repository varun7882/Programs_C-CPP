#include<stdio.h>
#include<string.h>
int main()
{
    int t,n1,n2,i,k,flag;
    char a[10000],b[10000];
    scanf("%d",&t);
    while(t--)
    {
      int f[26]={0};
     flag=0;
      scanf("%s%s",a,b);
      n1=strlen(a);
      n2=strlen(b);
      for(i=0;i<n1;i++)
      {
       k=(int)a[i];
       k=k-97;
       if(f[k]==0)
       {
           f[k]=1;
       }
      }
      for(i=0;i<n2;i++)
      {
        k=(int)b[i];
       k=k-97;
       if(f[k]==1)
       {
           flag=1;
           break;
       }
      }
    if(flag==1)
    {
        printf("Yes\n");
    }
    else
    {
         printf("No\n");
    }

    }

    return 0;
}
