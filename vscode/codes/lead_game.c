#include<stdio.h>
int main()
{

    long l,x,y,t,w=0,s1,s2;
    scanf("%ld",&t);
    l=-9999;
    x=y=0;
    while(t--)
    {
        scanf("%ld%ld",&s1,&s2);
        x+=s1;
        y+=s2;
        if(x>y)
        {
            if((x-y)>l)
            {
                l=(x-y);
                 w=1;
            }
        }
        else
        {
            if((y-x)>l)
            {
                l=(y-x);
                w=2;
            }
        }

    }
     printf("%ld %ld",w,l);
    return 0;
}
