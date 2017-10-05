#include<stdio.h>
int main()
{
    int x;
    float y;
    scanf("%d%f",&x,&y);
	if(x%5==0)
        {
         if(y>=x+.50)
         {
        y=(y-x-.50);
         }
        }
    printf("%.2f",y);
    return 0;
}
