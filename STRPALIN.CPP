#include<stdio.h>
#include<conio.h>
void main()
{
 clrscr();
 char a[20];
 int i,j,f=0;
 printf("enter the string\n");
 gets(a);
 i=0;
 while(a[i]!='\0')
  {
  i++;
  }
  j=0;
  while(j<=i)
  {
  if(a[j]==a[i-1])
  f=1;
  j++;
  i--;
  }
  if(f==1)
  printf("string is palindrome");
  else
  printf("string is not palindrome");
  getch();
  }



