#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
char a, c;
clrscr();
printf("\nType an alphabet : ");
scanf("%c",&a);
c=(a>96)?toupper(a):tolower(a);
printf("\nConverted character is %c",c);
getch();
}