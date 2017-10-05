#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,j;
char a[30];
printf("enter the word\n");
gets(a);
printf("enter 1 for lower case to upper case 2 for viceversa\n");
scanf("%d",&j);
i=0;
while(a[i]!='\0')
{
if(j==1)
{
printf("%c",(a[i]-32));
}
if(j==2)
{
if((int)a[i]==32)
printf(" ");
else
printf("%c",(a[i]+32));
}
i++;
}
getch();
}
