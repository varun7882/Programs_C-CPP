#include<iostream>
#include<string>
typedef int dty;
char s[1000000];
int main()
{
    dty n,i,pc=-1,c=0;
    std::cin>>n>>s;
    for(i=0;i<n;i++)
    {
     if(s[i]=='R')
     {
         if(pc!=-1)
         {
             c++;
         }
         pc=1;
     }
     else
     {
         if(pc==1)
         {
             c++;
         }
         pc=0;
     }
    }
    std::cout<<c;
    return 0;
}
