#include<stdio.h>
#include<conio.h>
int main()
{
 int i,j,k,a;
 static int n;
 printf("enter odd no.");
 scanf("%d",&n);
 if(n%2==0)
 {
 printf("i said odd no. stupid ODD NO.");
 }
 else
 {
 a=n+0;
 for(i=1;i<=((a+1)/2);i++)
 {
  for(k=1;k<=(i-1);k++)
  {
  printf("       ");
  }
  for(j=1;j<=n;j++)
  {
   printf("%d      ",j);

  }
  n=n-2;
  printf("\n");
  }
  }
  getch();
}
