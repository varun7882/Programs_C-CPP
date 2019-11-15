#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int i,j,k,id,d,t,n,ir,ri=0,ki=0;
    scanf("%d",&t);
    while(t>0)
    {
        ir=id=0;
        char a[1000000];
        scanf("%s",a);
         n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='R')
            {
                ir++;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                ri=ki=0;
                for(k=i;k<n-j;k++)
                {
                    if(a[k]=='R')
                    {
                        ri++;
                    }
                    if(a[k]=='K')
                    {
                        ki++;
                    }
                }
                d=ki-ri;
                    if(d>id)
                    {
                        id=d;
                    }
            }
        }
     printf("%d\n",id+ir);
     printf("%d %d\n",id,ir);
    t--;
    }
    getch();

}

