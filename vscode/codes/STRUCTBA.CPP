#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
 struct emp
 {
 char name[100];
 int age;
 float sal;
 };
 struct emp e;
 printf("enter the name,age and salary\n");
 scanf("%s%d%f",e.name,&e.age,&e.sal);
 printf("%s\n%d\n%f",e.name,e.age,e.sal);
 getch();
}
