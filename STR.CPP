#include<stdio.h>
#include<conio.h>
void main()
{
 char q[10],w[10],e[20];
 printf("enter the string");
 gets(q);
 gets(w);
 int i,j;
 i=0;
 j=0;
 while(q[i]!='\0')
 {
  e[j]=q[i];
  i++;
  j++;
 }
 i=0;
 while(w[i]!='\0')
 {
  e[j]=w[i];
  i++;
  j++;
 }
puts(e);
getch();
}