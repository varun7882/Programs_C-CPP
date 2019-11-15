#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
    int x,y,d,r;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    printf("enter the radius\n");
    scanf("%d",&r);
    x=0,y=r;
    d= 1.25-r;
    do
    {
	putpixel(300+x,200+y,WHITE);
	putpixel(300-x,200+y,WHITE);
	putpixel(300+x,200-y,WHITE);
	putpixel(300-x,200-y,WHITE);
	putpixel(300+y,200+x,WHITE);
	putpixel(300-y,200+x,WHITE);
	putpixel(300+y,200-x,WHITE);
	putpixel(300-y,200-x,WHITE);
	if(d<0)
	{
	     x=x+1;
         y=y;
         d=d+(2*x)+1;
        }
        else
        {
            x=x+1;
            d=d+(2*(x-y))+1;
            y=y-1;
        }
    x=x+1;
    delay(50);
    }while(x<y);
    getch();
    closegraph();
    return 0;
}
