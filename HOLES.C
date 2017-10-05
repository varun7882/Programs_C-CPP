#include<stdio.h>
#include<string.h>
int main()
{
 char a[100];
 int t,i,j=0,s=0;
 scanf("%d",&t);
 gets(a);
 for(i=1;i<=t;i++)
 {
     s=0;j=0;
    //printf("hi");
	 gets(a);
     while(a[j]!='\0')
     {
        if(a[j]=='A'||a[j]=='D'||a[j]=='O'||a[j]=='P'||a[j]=='Q'||a[j]=='R')
        {
            s=s+1;
        }
        if(a[j]=='B')
        {
            s=s+2;
        }
         j++;
     }
   printf("%d\n",s);
 }
   return 0;
 }

