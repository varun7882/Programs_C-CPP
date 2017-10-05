#include<stdio.h>
#include<math.h>
int main()
{
    int a[1000],i=0,j,t,p[1000];
    scanf("%d",&t);
    while(i<t)
    {
        scanf("%d",&j);
        if((1900<=j)&&(j<=2500))
        {
            a[i]=j;
            j=a[i]-2001;
            p[i]=abs(a[i]-2001);
            p[i]=(p[i]*365)+(p[i]/4);
            p[i]=p[i]%7;
            if(j<0)
            {
                p[i]=6-p[i];
            }
            i++;
        }
    }
    i=0;
    while(i<t)
    {
        switch(p[i])
        {
            case 0:
                printf("Monday\n");
                break;
            case 1:
                printf("Tuesday\n");
                break;
            case 2:
                printf("Wednesday\n");
                break;
            case 3:
                printf("Thusday\n");
                break;
            case 4:
                printf("Friday\n");
                break;
            case 5:
                printf("Saturday\n");
                break;
            case 6 :
                printf("Sunday\n");
                break;

        }
        i++;
    }
    return 0;
}
