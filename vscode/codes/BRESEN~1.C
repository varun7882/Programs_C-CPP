#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
    int x,y,d,r,gd=DETECT,gm;
    printf("enter the radius\n");
    scanf("%d",&r);
    x=0,y=r;
    d=3-(2*r);
    initgraph(&gd,&gm,"");
    do
    {
	putpixel(300+x,200+y,CYAN);
	putpixel(300-x,200+y,WHITE);
	putpixel(300+x,200-y,BLUE);
	putpixel(300-x,200-y,GREEN);
	putpixel(300+y,200+x,CYAN);
	putpixel(300-y,200+x,WHITE);
	putpixel(300+y,200-x,BLUE);
	putpixel(300-y,200-x,GREEN);
	if(d<0)
	{
            d=d+(4*x)+6;
        }
        else
        {
            d=d+(4*(x-y))+10;
            y=y-1;
        }
    x=x+1;
    delay(50);
    }while(x<y);
    getch();
    closegraph();
    return 0;
}
