#include<stdio.h>
#include<conio.h>
int n;
void tower(int,char,char,char);
void main()
{
clrscr();
printf(" enter the number of pegs...\n");
scanf("%d",&n);
printf(" We have 3 towers namely A,B,C\n we have to transfer the pegs from    tower A to tower C using B as an auxiliary tower\n");
printf(" the steps required to do so are given below sequencially\n");
tower(n,'A','B','C');
getch();
}
void tower(int x, char a, char b, char c)
{
if(x>0)
{
tower((x-1),a,c,b);
printf("  %c --> %c\n",a,c);
tower((x-1),b,a,c);
}
}