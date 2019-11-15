#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int i,j,n; char c;
	printf("enter a number");
	scanf("%d",&n);
	c='A';
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(n+1-i);j++)
		{
			printf("%c",c);
		}
		c=c+1;
		printf("\n");
	}
	getch();
}
