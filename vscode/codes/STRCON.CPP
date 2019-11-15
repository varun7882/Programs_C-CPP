#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,j;
char a[20],b[20];
printf("enter the strings");
scanf("%s%s",a,b);
i=0;
j=0;
while(a[i]!='\0')
{
i++;
}
while(b[j]!='\0')
{
a[i]=b[j];
i++;
j++;
}
j=0;
while(j<i)
{
printf("%c",a[j]);
j++;
}
  getch();
}
