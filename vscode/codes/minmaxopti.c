#include<stdio.h>
#include<conio.h>
  int a[100],min,max,n,i;
  void op()
  {
   for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                if(min>a[i+1])
                {
                    min=a[i+1];
                }
                if(max<a[i])
                {
                    max=a[i];
                }
            }
            else
            {
               if(min>a[i])
                {
                    min=a[i];
                }
                if(max<a[i+1])
                {
                    max=a[i+1];
                }
            }
        }
    printf("minimum is : %d\nmaximum is : %d",min,max);
  }
void main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n%2==0)
    {
        if(a[0]>a[1])
        {
            min=a[1];
            max=a[0];
        }
        else
        {
            min=a[0];
            max=a[1];
        }
        op();
    }
    else
    {
        min=max=a[0];
        op();
    }

}

