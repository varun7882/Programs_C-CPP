#include<iostream>
#include<vector>
typedef std::pair<int,int> pr;
int main()
{
   int n,i,j,k,c=1,a[101][101],nr,nc,x,y,p=0;
   std::cin>>n;
   i=0;
   j=0;
   nr=nc=n;
   p=1;
   std::vector<pr> v;
   v.push_back(pr(0,0));
   while(i<nr&&j<nc)
   {
         for(k=j;k<nc;k++)
        {
            if(c%11==0)
            {
                p++;
                v.push_back(pr(i,k));
            }
            a[i][k]=c;
            c++;

        }
        i++;
         for(k=i;k<nr;k++)
        {
            if(c%11==0)
            {
                p++;
                v.push_back(pr(k,nc-1));
            }
            a[k][nc-1]=c;
            c++;
        }
        nc--;
        if(i<nr)
        {
            for(k=nc-1;k>=j;k--)
            {
                   if(c%11==0)
            {
                p++;
                v.push_back(pr(nr-1,k));
            }
                a[nr-1][k]=c;
                c++;
            }
            nr--;
        }
        if(j<nc)
        {
            for(k=nr-1;k>=i;k--)
            {
            if(c%11==0)
            {
                p++;
                v.push_back(pr(k,j));
            }
                a[k][j]=c;
                c++;
            }
            j++;
        }
   }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    i=0;j=0;
    k=0;
    nc=nr=n;

    std::cout<<"Total Power points : "<<p;
    std::cout<<std::endl;
    int sz=v.size();
    for(i=0;i<sz;i++)
    {
        if(i!=sz-1)
        {
        std::cout<<"("<<v[i].first<<","<<v[i].second<<")"<<std::endl;
        }
        else
        {
            std::cout<<"("<<v[i].first<<","<<v[i].second<<")";
        }
    }
  //   std::cout<<"Total Power points : "<<p;
}

