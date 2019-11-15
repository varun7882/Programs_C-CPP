#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 clrscr();
 FILE *fp;
 int d=0,i=0;
 char ch[100];
 fp=fopen("abc.txt","w");
 do
 {
 printf(" enter the word\n")  ;
 i++;
 scanf("%s",ch);
 fprintf(fp,"%s\n",ch);
 printf(" if you want to continue enter 1\n");
 scanf("%d",&d);
 }
 while(d==1);
 fclose(fp);
 printf(" your file is ready\n");
 FILE *fp1;
 fp1=fopen("abc.txt","r");
 for(d=1;d<=i;d++)
 {
  fscanf(fp1,"%s",ch);
  printf("%s ",ch);
 }
 fclose(fp1);
 getch();
}