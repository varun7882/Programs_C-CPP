#include <stdio.h>
#include<limits.h>
void sum()
{
   static int c=1;
    printf("%d\n",c);
    c=c+1;

}
void sum2()
{
    static int c=10;
     printf("%d\n",c);
    c=c+1;
}
int main()
{
   register int i;
    int i;
    for(i=0;i<10;i++)
    {
      sum();
    }
     for(i=0;i<10;i++)
    {
      sum2();
    }


    return 0;
}
int i=1;
