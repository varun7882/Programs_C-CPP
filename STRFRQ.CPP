#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,k,m,n,f,g=1;
m=0;
n=0;
f=0;
char a[50];
char b[50];
printf("enter the string\n");
gets(a);
printf("enter the string to get frequency\n");
gets(b);
i=0;
j=0;
while(a[i]!='\0')
{
m++;
i++;
}
while(b[j]!='\0')
{
j++;
n++;
}
for(i=0;i<m;i++)
{
if(b[0]==a[i])
{
 k=i+0;
 j=0;
 while(j<n)
 {
 if(a[k]==b[j])
 {
 f=1;
 }
 else
 {
 f=0;
 break;
 }
 k++;
 j++;
 }
 g++;
}
}
 if(f==1)
 printf("substring is found %d times",(g-1));
 else
 printf("sub string was not found");
 getch();
}
