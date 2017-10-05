#include<stdio.h>
#include<stdlib.h>
void merge(int A[],int p,int q,int r)
{
   int a1[5000],a2[5000],i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)
    {
        a1[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        a2[j]=A[q+1+j];
    }
    i=0,j=0;
    k=p;
    while(i<n1&&j<n2)
    {
        if(a1[i]<=a2[j])
        {
            A[k++]=a1[i++];
        }
        else
        {
            A[k++]=a2[j++];
        }
    }


        while(j<n2)
        {
            A[k++]=a2[j++];
        }
        while(i<n1)
        {
            A[k++]=a1[i++];
        }
    }
void merge_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=p+(r-p)/2;
	merge_sort(A,p,q);
	merge_sort(A,q+1,r);
	merge(A,p,q,r);
    }
}

int main()
{
  int t,boys,girls,b[10000],g[10000],i,j,f=1;
  scanf("%d",&t);
  while(1<=t && t<=10)
  {
      scanf("%d%d",&boys,&girls);
      for(i=0;i<boys;i++)
      {
          scanf("%d",&b[i]);
          if(b[i]>200 || b[i]<1)
          {
              printf("incorrect entry; enter again");
              i--;
          }
      }
      for(i=0;i<girls;i++)
      {
          scanf("%d",&g[i]);
            if(g[i]>200 || g[i]<1)
          {
              printf("incorrect entry; enter again");
              i--;
          }
      }
      merge_sort(b,0,boys-1);
      merge_sort(g,0,girls-1);
      if(boys>girls)
      {
          return 0;
      }
      i=j=0;
      while(i<boys && j<girls)
      {
          if(b[i]>g[j])
          {
              i++;
              j++;
          }
          else
          {
              j++;
          }
      }
      if(i>=boys)
      {
          printf("\nYES");
      }
      else
      {
          printf("\nNO")
      }
    t--;
  }
  return 0;
}

