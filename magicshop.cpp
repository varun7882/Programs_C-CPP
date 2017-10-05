#include<iostream>
#include<string.h>
using namespace std;
typedef pair<int,int> p;
using namespace std;
int main()
{
    long int a,b,p,s;
    int i,j,l;
    char str[100005];
    cin >>a>>b;
    cin>>str;
    l=strlen(str);
    p=a;
    s=0;
    for(i=1;i<=l;i++)
    {
     if(i!=1)
     {
         p=(p%b*p%b)%b;
     }
     if(str[i-1]=='1')
     {
        s=(s%b+p%b)%b;
     }
    }
    cout<<s<<endl;
}
