#include<iostream>
#include<set>
#include<string>
typedef int dty;
typedef std::pair<dty,dty>pr;
dty isc[100000];
std::multiset<dty> is[100000];
bool ispalin(dty x)
{
    dty temp,reverse;
    temp = x;

   while( temp != 0 )
   {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp = temp/10;
   }
   if(reverse==x)
   return true;
   else
   return false;
}
int main()
{
    dty f,l,r,i,c=0,x,y,max=-1,py=0,sum=0;
    std::multiset<dty> p;
    std::multiset<pr> diff;
    std::multiset<pr>:: iterator d1;
    std::multiset<dty>::iterator it1,it2;
    std::cin>>f>>l>>r;
//    std::cout<<ispalin(123)<<std::endl;
  //  std::cout<<itoa(32123)<<std::endl;
    for(i=f;i<=l;i++)
    {
  std::cout<<ispalin(i)<<std::endl;
        if(ispalin(i)==1)
        {
           p.insert(i);
           c++;
        }
    }
   std::cout<<"c is "<<c<<std::endl;
    if(c!=0)
    {
    for(it1=p.begin();it2!=p.end();it1++)
    {
        x=*it1;
        for(it2=it1;it2!=p.end();it2++)
        {
            y=*it2;
            if(y-x<=r)
            {
                is[x].insert(y);
            }
        }

    }
    for(it1=p.begin();it2!=p.end();it1++)
    {
        x=*it1;
        if(max<is[x].size())
        {
            max=is[x].size();
        }
    }
    for(it1=p.begin();it2!=p.end();it1++)
    {
        x=*it1;
        if(max==is[x].size())
        {
            sum=py=0;
            for(it2=is[x].begin();it2!=is[x].end();it2++)
            {

                y=*it2;
                sum=sum+(y-py);
                py=y;
            }
            diff.insert(pr(sum,x));
        }
    }
    d1=diff.begin();
    x=d1->second;
    std::cout<<is[x].size();
    for(it1=is[x].begin();it2!=is[x].end();it1++)
    {
        y=*it1;
        std::cout<<","<<y;
    }
    }
    else
    {
        std::cout<<"0,0,0";
    }
    return 0;
}
