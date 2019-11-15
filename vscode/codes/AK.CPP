#include<stdio.h>
#include<conio.h>
int main()
{
	clrscr();
	int a=5,b=5;
	a=(a++)+(a--);
	b=(++b)+(--b);
	printf("%d %d",a,b);
	getch();
	return 0;
}