#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	clrscr();
	int count=80,dot=80,i,base=80;
	gotoxy(1,10);
	while(base--)
	{
	delay(50);
	printf("_");
	}
	gotoxy(1,20);
	printf("                                    Loading...\n" );
	while(dot--)
	printf(".");
	for(i=0;i<5;i++)
	{
	delay(500);
	gotoxy(25,5+i);
	printf("O");
	}
	delay(500);
	gotoxy(25,10);
	printf("o");
	for(i=1;i<5;i++)
	{
	delay(500);
	gotoxy(26+i,10-i);
	printf("O");
	}
	for(i=1;i<5;i++)
	{
	delay(500);
	gotoxy(30+i,5+i);
	printf("O");
	}
	delay(500);
	gotoxy(35,10);
	printf("o");
	for(i=1;i<4;i++)
	{
	delay(500);
	gotoxy(35+i,10-i);
	printf("O");
	}
	for(i=1;i<4;i++)
	{
	delay(500);
	gotoxy(39+i,6+i);
	printf("O");
	}
	delay(500);
	gotoxy(43,10);
	printf("o");

	delay(1000);
	gotoxy(1,21);
	while(count--)
	{       delay(75);
		textattr(12+'a'+BLINK);
		cprintf(" ");
	}
getch();
return 0;
}