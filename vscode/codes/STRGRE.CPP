#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i=0;
char a[30],b[30];
printf("enter the words to campare\n");
scanf("%s%s",a,b);
while(a[i]!='\0'|| b[i]!='\0')
{
if((int)a[i]>(int)b[i])
{
printf("first string is greater");
break;
}

else if((int)a[i]==(int)b[i])
{
printf("strings are equal");
}
else
{
printf("second string is greater");
break;
}

i++;
}
  getch();
}
