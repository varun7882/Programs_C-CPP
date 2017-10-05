#include<stdio.h>
#include<conio.h>
void main()
{
struct emp
{
 char name[20];
 int age;
 float sal;
}a[2];
int i;
clrscr();
for(i=0;i<2;i++)
{
printf("enter the name,age and salary of the employee\n");
scanf("%s %d %f",a[i].name,&a[i].age,&a[i].sal);
}
for(i=0;i<2;i++)
{
printf("%s\n%d\n%f\n",a[i].name,a[i].age,a[i].sal);
}
getch();
}







