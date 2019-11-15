#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i=0;
char a[20];
printf("enter the string\n");
gets(a);
while(a[i]!='\0')
{
i++;
}
while(i>=0)
{
printf("%c",a[i]);
i--;
}
  getch();
}
