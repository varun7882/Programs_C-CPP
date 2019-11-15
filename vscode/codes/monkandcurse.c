#include<stdio.h>
#include<limits.h>
long int rss,css;
void sort(long int a[],long int n)
{
    int j,f=-1;
    long int t;
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                f=1;
            }
            else
            {
                f=0;
            }
            if(f==0)
            {
                break;
            }
        }

}
long int part(long int a[],long int p,long int r)
{
    long int i,j,k,t;
    i=p-1;
    k=a[r];
    for(j=p;j<r;j++)
    {
        if(k>a[j])
        {
            i=i+1;
           t=a[i];
           a[i]=a[j];
           a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}
void quick(long int A[],long int p,long int r)
{
   long int q;
    if(p<r)
    {
    q= part(A,p,r);
    quick(A,p,q-1);
    quick(A,q+1,r);
    }
}
long int val(long int r[], long int c[],long int n)
{
    int i,f;
    long int rt;
    f=0;
    if(r[0]+rss<c[0]+css)
    {
        rt=r[0]+rss;
        css++;
        r[0]=r[0]+n;
        sort(r,n);
        f=1;
    }
    else if(r[0]+rss>c[0]+css)
    {
        rt=c[0]+css;
        rss++;
        c[0]=c[0]+n;
        sort(c,n);
        f=1;
    }
    else
    {
        rt=c[0]+css;
        for(i=1;i<n;i++)
        {
            if(r[i]+rss<c[i]+css)
            {
                css++;
                r[0]=r[0]+n;
                sort(r,n);
                f=1;
                break;
            }
            else if(r[i]+rss>c[i]+css)
            {
                rss++;
                c[0]=c[0]+n;
                sort(c,n);
                f=1;
                break;
            }
        }
    }
    if(f==1)
    {
        return rt;
    }
    else
    {
        css++;
        r[0]=r[0]+n;
        sort(r,n);
        return rt;
    }
}
void main()
{
    long int t,n,k,a[205][205],i,j,rs[205],cs[205],c,r,s;
    //long int *rm,*cm;
    scanf("%ld",&t);
    while(t--)
    {
        s=0;
        scanf("%ld%ld",&n,&k);
        c=0;
        r=0;
        rss=0;
        css=0;
        for(i=0;i<205;i++)
        {
            rs[i]=0;
            cs[i]=0;
        }
    for(i=0;i<n;i++)
    {
        r=0;
        for(j=0;j<n;j++)
        {
            scanf("%ld",&a[i][j]);
            r=r+a[i][j];
            cs[j]=cs[j]+a[i][j];
        }
        rs[i]=r;
    }
    quick(rs,0,n-1);
    quick(cs,0,n-1);
//    for(i=0;i<n;i++)
//    {
//        printf("%ld ",rs[i]);
//    }
//    for(i=0;i<n;i++)
//    {
//        printf("%ld ",cs[i]);
//    }

    for(j=0;j<k;j++)
    {
        s=s+val(rs,cs,n);
    }
    printf("%ld\n",s);
    }

    }

