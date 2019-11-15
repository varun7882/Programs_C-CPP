#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
char c;
clrscr();

start:

printf("\n Type any character for Religion(h,m,s,c) ");
scanf("%c",&c);
if(c!='h'&&c!='m'&&c!='s'&&c!='c')
{
goto err;
}

if(c=='h')
{
	printf("\nHindu ");
	goto last;
}

if(c=='m')
{
	printf("\nMuslim ");
	goto last;
}

if(c=='s')
{
	printf("\nSikh ");
	goto last;
}

if(c=='c')
{
	printf("\nChristian ");
	goto last;
}
err:
printf("\nWrong Code ");
goto start;

last:
printf("\nEnd of programm");
getch();
}