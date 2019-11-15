#include<stdio.h>
#include<limits.h>
 int p[100],m[100][100],s[100][100];
int main()
{
    int n,i,l,j,k,q;
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
        m[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
    printf("%d ",m[i][j]);
        }
        printf("\n");
    }
printf("\n%d",m[1][n-1]);
   return 0;
}
