#include<stdio.h>
#include<limits.h>
#include<string.h>
int v[100][100];
char x[99],y[99];
char u[100][100];
void printlcs(int m,int n)
{
    if(m==0 || n==0)
    {
        return;
    }
     if (u[m][n]=='T')
    {
        printlcs(m-1,n-1);
        printf("%c",y[n]);
        //printf("\ntezhimansu");
    }
    else if(u[m][n]=='U')

    {
         printlcs(m-1,n);
         //printf("\nu");
    }
    else
    {
        printlcs(m,n-1);
           //printf("\nl");
    }

}
int LCS(int m,int n)
{
    int i,j;
    for(i=0;i<=m;i++)
    {
       v[0][i]=0;
    }
    for(i=0;i<=m;i++)
    {
       v[i][0]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
        if(x[i]==y[j])
         {
            v[i][j]=v[i-1][j-1]+1;
            u[i][j]='T';
            //printf("\ntez");
          }
        else
          {
           if(v[i-1][j]>=v[i][j-1])
            {
            v[i][j]=v[i-1][j];
            u[i][j]='U';
            }

            else
            {
                 v[i][j]=v[i][j-1];
                u[i][j]='L';
            }
          }
        }
    }

   return v[m][n];
}
int main()
{
    char a[100],b[100];
    int m,n,l,i,j;
    printf("enter the strings\n");
    scanf("%s%s",a,b);
    m=strlen(a);
    n=strlen(b);
    for(i=0;i<m;i++)
    {
        x[i+1]=a[i];
    }
    for(i=0;i<n;i++)
    {
         y[i+1]=b[i];
    }
    l=LCS(m,n);
    printf("%d\n",l);
   /*  for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           u[i][j]=u[j][i];
           v[i][j]=v[j][i];
        }

    }*/
    printlcs(m,n);
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%c ",u[i][j]);
        }
        printf("\n");
    }
      printf("\n\n\n");
     for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
