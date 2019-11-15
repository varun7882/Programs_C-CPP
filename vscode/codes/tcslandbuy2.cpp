#include<iostream>
#include<set>
#include<string>
typedef int dty;
typedef std::pair<dty,dty>pr;
typedef std::pair<dty,std::multiset<dty> >prr;
dty isc[100000];
std::multiset<dty> is[100000];
int oneDigit(int num)
{
    return (num >= 0 && num < 10);
}

bool isPalUtil(int num, int* dupNum)
{

    if (oneDigit(num))
        return (num == (*dupNum) % 10);


    if (!isPalUtil(num/10, dupNum))
        return false;


    *dupNum /= 10;

    return (num % 10 == (*dupNum) % 10);
}

int isPal(int num)
{

    if (num < 0)
       num = -num;


    int *dupNum = new int(num);

    return isPalUtil(num, dupNum);
}
int main()
{
    dty f,l,r,i,c=0,x,y,mx=-1,py=0,sum=0,sz;
    std::multiset<dty> p,t;
    std::multiset<pr> diff;
    std::multiset<prr> nya;
    std::multiset<pr>:: iterator d1;
    std::multiset<dty>::iterator it1,it2;
    std::cin>>f>>l>>r;
//    std::cout<<ispalin(123)<<std::endl;
  //  std::cout<<itoa(32123)<<std::endl;
    for(i=f;i<=l;i++)
    {
  //std::cout<<ispalin(i)<<std::endl;
        if(isPal(i))
        {
           p.insert(i);
           c++;
        }
    }
  // std::cout<<"c is "<<c<<std::endl;
    if(c!=0)
    {
//        for(it1=p.begin();it1!=p.end();it1++)
//        {
//            x=*it1;
//            std::cout<<x<<" ";
//        }
        for(it1=p.begin();it1!=p.end();it1++)
        {
            x=*it1;
            for(it2=it1;it2!=p.end();it2++)
            {
                y=*it2;
                if(y-x<r)
                {
                    t.insert(y);
                }
                else
                {
                    break;
                }
            }
            nya.insert(prr(x,t));
            t.clear();

        }
//        for(it1=p.begin();it1!=p.end();it1++)
//        {
//            x=*it1;
//            for(it2=is[x].begin();it2!=is[x].end();it2++)
//            {
//                y=*it2;
//                std::cout<<y<<" ";
//            }
//            std::cout<<std::endl;
//        }
//        std::cout<<"hm yaha 1 "<<std::endl;
        mx=-999;
        for(it1=nya.begin();it1!=nya.end();it1++)
        {
            x=*it1;
            y=is[x].size();
            //std::cout<<"size "<<y<<std::endl;
            if(mx<y)
            {
                mx=y;
            }
        }
       // std::cout<<"hm yaha 2 or max h "<<mx<<std::endl;
        for(it1=p.begin();it1!=p.end();it1++)
        {
            x=*it1;
            sz=is[x].size();
            if(mx==sz)
            {
                sum=0;
                py=x;
                for(it2=is[x].begin();it2!=is[x].end();it2++)
                {

                    y=*it2;
                    sum=sum+(y-py);
                    py=y;
                }
                diff.insert(pr(sum,x));
            }
        }
      //  std::cout<<"hm yaha 3 "<<std::endl;
        d1=diff.begin();
      //  std::cout<<"hm yaha 4 "<<std::endl;
        x=d1->second;
      //  std::cout<<"hm yaha 5 "<<x<<std::endl;
        std::cout<<is[x].size();
        for(it1=is[x].begin();it1!=is[x].end();it1++)
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

