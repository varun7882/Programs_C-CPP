#include<stdio.h>
#include<conio.h>
struct data
{
    int l;
    int r;
    int s;
};
struct data maxcrosssubarray(int a[],int l,int m,int h)
{
    struct data DCA;
    int i,leftsum,rightsum,sum;
    leftsum=-9999;
    sum=0;
    for(i=m;i>=l;i--)
    {
        sum+=a[i];
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
        sum+=a[i];
        if(sum>rightsum)
        {
            rightsum=sum;
            DCA.r=i;
        }
    }
    DCA.s=leftsum+rightsum;
    return DCA;
}
struct data maximumsubarray(int a[],int l,int h)
{
    struct data DMA;
    if(l==h)
    {
        DMA.r=DMA.l=l;
        DMA.s=a[l];
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
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7},r;
    res=maximumsubarray(a,0,15);


        printf("maximum subarray is from %d to %d and the sum is... %d",res.l+1,res.r+1,res.s);

    getch();
}

