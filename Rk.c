#include<stdio.h>
#include<conio.h>
#include<string.h>
struct data
{
    int l;
    int r;
    int s;
};
struct data maxcrosssubarray(char a[],int l,int m,int h)
{
    struct data DCA;
    int i,leftsum,rightsum,sum,adder;
    leftsum=-9999;
    sum=0;
    for(i=m;i>=l;i--)
    {
        if(a[i]=='R')
        {
        adder=-1;
        }
        if(a[l]=='K')
        {
        adder=1;
        }
        sum+=adder;
        if(sum>leftsum)
        {
            leftsum=sum;
            DCA.l=i;
        }
    }
   rightsum=-9999;
    sum=0;
    for(i=m+1;i<=h;i++)
    {
         if(a[i]=='R')
        {
        adder=-1;
        }
        if(a[l]=='K')
        {
        adder=1;
        }
        sum+=adder;
        if(sum>rightsum)
        {
            rightsum=sum;
            DCA.r=i;
        }
    }
    DCA.s=leftsum+rightsum;
    return DCA;
}
struct data maximumsubarray(char a[],int l,int h)
{
    struct data DMA;
    if(l==h)
    {
        DMA.r=DMA.l=l;
        if(a[l]=='R')
        {
        DMA.s=-1;
        }
        if(a[l]=='K')
        {
        DMA.s=1;
        }

        return DMA;
    }
    else if(l<h)
    {
         struct data ls,rs,cs;
         int m;
         m=(l+h)/2;
         ls=maximumsubarray(a,l,m);
         rs=maximumsubarray(a,m+1,h);
         cs=maxcrosssubarray(a,l,m,h);
         if((ls.s>rs.s)&&(ls.s>cs.s))
         {
             return ls;
         }
          else if((rs.s>ls.s)&&(rs.s>cs.s))
         {
             return rs;
         }
          else if((cs.s>ls.s)&&(cs.s>rs.s))
         {
             return cs;
         }
    }
}
void main()
{
    struct data res;
    int i,n,IH=0,H=0,t;
    scanf("%d",&t);
    while(t>0)
    {
        char a[1000000];
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='R')
            {
                H++;
                IH++;
            }
        }
      res=maximumsubarray(a,0,n-1);
        if(res.s>0)
        {
            for(i=res.l;i<=res.r;i++)
            {
                if(a[i]=='R')
                {
                    H--;
                }
                if(a[i]=='K')
                {
                    H++;
                }
            }
        }
 printf("maximum subarray is from %d to %d and the sum is... %d\n",res.l,res.r,res.s);

        printf("%d",res.s+H);

    }
    getch();

}

