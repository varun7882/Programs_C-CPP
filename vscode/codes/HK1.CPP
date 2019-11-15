#include<stdio.h>
#include<conio.h>
#include<ctype.h>
main()
{
int roll,marks;
float amount=0.0;
char sex;
clrscr();
printf("\n Given sex i.e. m or f ");
scanf("%c",&sex);
printf("\n Given roll number ");
scanf("%i",&roll);
printf("\nGiven marks ");
scanf("%i",&marks);
if(sex=='f')
if(marks>75)
{
	amount = marks*75.0;
	printf("\nscholarship for this girl = %g",amount);
}
else
printf("\nNo scholarship for this girl");
else if(marks>85)
{
	amount = marks*75.0;
	printf("\nscholarship for this boy = %g", amount);
}
else
printf("\nNo scholarship for this boy");
getch();
}