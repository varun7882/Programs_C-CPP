#include<stdio.h>
int main()
{
    long int a[100000],n,i,j,freq[128]={0},temp[128],res=0;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<128;j++)
        {
        temp[j]=0;
        }
        for(j=0;j<128;j++)
        {
            if(freq[j]!=0)
            {
                temp[j^a[i]]+=freq[j];
            }
        }
        temp[a[i]]++;
        for(j=0;j<128;j++)
        {
            freq[j]+=temp[j];
        }
    }
    for(i=0;i<128;i++)
    {
        res+=(freq[i]*(freq[i]-1))/2;
    }

    printf("%ld",res);
    return 0;
}
