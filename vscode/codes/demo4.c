#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
int a2,a=12;
float b2,b=12.21;
char *s="heyo",*sq;
char sq1[90];
sprintf(sq,"%d %.2f %s",a,b,s);
printf("%s %d",sq,strlen(sq));
sscanf(sq,"%d%f%s",&a2,&b2,sq1);
printf("\nok %d %f %s\n",a2,b2,sq1);
getchar();
fflush(stdin);
fgetchar();
//getche();
//getch();
}
