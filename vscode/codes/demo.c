#include<stdio.h>
#include<limits.h>
#include<string.h>
int v[100][100],x[99],y[99];
char u[100][100];
int max(int a,int b)
{
    return (a>b)?a:b;
}
void printlcs(char u[][100],int x[],int m,int n)
{
    printf("tezhimansu");
    if(m==0 && n==0)
    {


     if (u[m][n]=='T')
    {
        printlcs(u,x,m-1,n-1);
        printf("%c",x[m]);
    }
    else if(u[m][n]=='U')

    {
         printlcs(u,x,m-1,n);
    }
    else
    {
        printlcs(u,x,m,n-1);
    }
    }
}
int LCS(int x[],int y[],int m,int n)
{
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
        if(i==0 || j==0)
        {
            v[i][j]=0;
        }
        else if(x[i]==y[j])
         {
            v[i][j]=v[i-1][j-1]+1;
            u[i][j]='T';
        }
        else
            v[i][j]=max(v[i-1][j],v[i][j-1]);
            if(v[i][j]==v[i-1][j])
            {
                u[i][j]='U';
            }
            else
            {
                u[i][j]='L';
            }
        }
    }

   return v[m-1][n-1];
}
int main()
{
    int m,n,l;
    printf("enter the strings");
    scanf("%s%s",x,y);
    m=strlen(x);
    n=strlen(y);
    l=LCS(x,y,m,n);
    printf("%d",l);
    printlcs(u,x,m-1,n-1);
    return 0;
}
