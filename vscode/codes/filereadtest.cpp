#include<iostream>
#include<fstream>
int main()
{
    FILE *fp;
    int b,x,p;
    fp=fopen("abc.txt","r");
    while(fp!=EOF)
    {
    b=fgetc(fp);
    x=fgetc(fp);
    p=fgetc(fp);
    std::cout<<b<<" "<<x" "<<p<<endl;
    }
    return 0;
}
