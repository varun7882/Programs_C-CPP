#include<stdio.h>
#include<limits.h>
 int p[100],m[100][100],s[100][100];
 int matrixchain(int p[],int i,int j)
 {
     if(i==j)
      return 0;
       int k,q;
     if(m[i][j]<INT_MAX)
        return m[i][j];
    else
    {
    for(k=i;k<j;k++)
    {
        q=matrixchain(p,i,k)+matrixchain(p,k+1,j)+(p[i-1]*p[k]*p[j]);
        if(q<m[i][j])
        {
            m[i][j]=q;
            s[i][j]=k;
        }
    }
    return m[i][j];
    }

 }
int main()
{
    int n,i,j,l;
    printf("enter the number of matrices\n");
    scanf("%d",&n);
    printf("enter the values of matrices\n");
    n++;
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
        for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
        {
            m[i][j]=INT_MAX;
        }
        }

  l=  matrixchain(p,1,n-1);

        for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
    printf("%d ",m[i][j]);
        }
        printf("\n");
    }
printf("\n%d",l);
   return 0;
}
