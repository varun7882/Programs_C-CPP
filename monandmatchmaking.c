#include <stdio.h>
#include<string.h>
int main()
{
    char s[100005];
    int q,l1,r1,l2,r2;
    gets(s);
    scanf("%d",&q);
  //  puts(s);
    //printf("\n%d",s);
    while(q--)
    {
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if((r1-l1+1)!=(r2-l2+1))
        {
            printf("No\n");
        }
        else
        {
           if(memcmp(s+l1-1,s+l2-1,r2-l2+1))
            {
                 printf("No\n");
            }
            else
            {
                 printf("Yes\n");
            }
        }
    }
    return 0;
}


