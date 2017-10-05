#include<stdio.h>
#include<conio.h>
void main ()
 {
  clrscr();
 Q:int i,j,k,n;
  printf("\nenter an odd no.");
  scanf("%d",&n);
  if((n%2)==!0)
  {
  i=1;
  while(i<=n)
  {
  if(i<=((n+1)/2))
  {
   for(k=1;k<=(i-1);k++)
  {
  printf("    ");
  }
  for(j=1;j<=((n+2)-(2*i));j++)
  {
  printf("   *");
  }
  }
  else
  {
  for(k=1;k<=(n-i);k++)
  {
  printf("    ");
  }
  for(j=1;j<=((2*i)-n);j++)
  {
  printf("   *");
  }
 }
 i++;
 printf("\n");
 }
 }
 else
  {
  printf("i said an odd no. try again");
  goto Q;
  }
  getch();
  }