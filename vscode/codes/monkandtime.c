#include<stdio.h>
#include<limits.h>
int main()
{
    int qcall[100000],qideal[100000],n,i,time=0,j=0,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&qcall[i]);
    } for(i=0;i<n;i++)
    {
        scanf("%d",&qideal[i]);
    }
    i=0;
    k=n;
    while(j<n)
    {
        if(qcall[i]==qideal[j])
        {
          j++;
          time++;
        }
        else
        {
            qcall[k++]=qcall[i];
            qcall[i]=0;
            time++;
        }
        i++;
    }
    printf("%d",time);
    return 0;
}
