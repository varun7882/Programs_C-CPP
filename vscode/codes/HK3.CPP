#include<stdio.h>
#include<conio.h>
main()
{
int a[10],b[10];
clrscr();
printf("Enter 10 numbers :-\n");
for(int i=0;i<10;i++)
{
	scanf("\t\t%i"&a[i]);
	int b[i]=a[i];
	a[i]=a[10-i];
	a[10-i]=b[i];
}
for(i=0;i<10;i++)
{
	printf("%i",a[i]);
}
getch();
}