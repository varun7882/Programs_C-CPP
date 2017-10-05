#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int alloc[100][100],need[100][100],max[100][100],avail[100];
    int i,j,k,m,n,f;
    int s[100];
    printf("enter the number of process and number of resources respectively\n");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        s[i]=0,j=0;
        printf("PROCESS NO. %d:\n",(i+1));
        printf("enter the maximum instances of all %d resources needed \n",n);
        scanf("%d%d%d",&max[i][j],&max[i][j+1],&max[i][j+2]);
        printf("enter the instances of all %d resources allocated to process %d\n",n,(i+1));
        scanf("%d%d%d",&alloc[i][j],&alloc[i][j+1],&alloc[i][j+2]);
    }
    for(i=0;i<m;i++)
    {
     for(j=0;j<n;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
        j=0;
 printf("enter the available instance of resources\n");
     scanf("%d%d%d",&avail[j],&avail[j+1],&avail[j+2]);
   printf(" PROCESS NO.\t MAXIMUM\t ALLOCATED\t NEED\n");
   for(i=0;i<m;i++)
   {
       j=0;
           printf("  %d\t\t %d %d %d\t\t %d %d %d\t\t %d %d %d\n",(i+1),max[i][j],max[i][j+1],max[i][j+2],alloc[i][j],alloc[i][j+1],alloc[i][j+2],need[i][j],need[i][j+1],need[i][j+2]);
   }
   printf("available resources are... \n %d %d %d",avail[j],avail[j+1],avail[j+2]);
    i=0,f=1;
        while(i<m)
          {
          if(s[i]==0)
           {
              j=0;
                  if(need[i][j]<=avail[j]&&need[i][j+1]<=avail[j+1]&&need[i][j+2]<=avail[j+2])
                  {
                      s[i]=1;
                     avail[j]=avail[j]+alloc[i][j];
                     avail[j+1]=avail[j+1]+alloc[i][j+1];
                     avail[j+2]=avail[j+2]+alloc[i][j+2];
                     need[i][j]=need[i][j+1]=need[i][j+2]=0;
                  printf("\nPROCESS %d is complete.\n",(i+1));
                   printf(" PROCESS NO.\t MAXIMUM\t ALLOCATED\t NEED\n");
                       for(k=0;k<m;k++)
                       {
                        j=0;
                        printf("  %d\t\t %d %d %d\t\t %d %d %d\t\t %d %d %d\n",(k+1),max[k][j],max[k][j+1],max[k][j+2],alloc[k][j],alloc[k][j+1],alloc[k][j+2],need[k][j],need[k][j+1],need[k][j+2]);
                       }
                  printf("available resources are... \n %d %d %d",avail[j],avail[j+1],avail[j+2]);

                  }

            }
          i++;
printf("\n%d% d %d %d",need[0][0],need[0][1],need[0][2],s[0]);
}
        for(i=0;i<m;i++)
        {
            if(s[i]==0)
            {
                f=0;
            }
        }

    if(f==1)
    {
        printf("SYSTEM IS IN SAFE STATE\n");
    }
    else

    {
        printf("system is not in safe state\n");
    }
   }
