#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    long int i,k,r,t,maxsofar,max,adder,n;
    scanf("%d",&t);
    while(t>0)
    {

        char a[1000000];
        scanf("%s",a);
         n=strlen(a);
         r=k=0;
         max=0;
         maxsofar=-999999;
        for(i=0;i<n;i++)
        {
            if(a[i]=='R')
            {
                r++;
                adder=-1;
            }
            else
            {
                k++;
                adder=1;
            }
            temp=max+adder;
            if(temp>adder)
            {
                max=temp;
            }
            else
            {
                max=adder;
            }
            if(max>maxsofar)
            {
                maxsofar=max;
            }
        }

     printf("%d\n",r+maxsofar);
    t--;
    }
    return 0;

}

