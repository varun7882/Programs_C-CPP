#include<iostream>
using namespace std;
int a[100][100],n,c=0;
int row=0;
void printsol()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                cout<<"Q\t";
            }
            else
            {
                cout<<"-\t";
            }
        }
        cout<<"\n";
    }
}
bool issafe(int i,int j)
{
    int k,l;
    for(k=0;k<i;k++)
    {
        if(a[k][j]==1)
        {
            return false;
        }
    }
    for(k=i-1,l=j-1;k>=0&&l>=0;k--,l--)
    {
       if(a[k][l]==1)
       {
           return false;
       }
    }
     for(k=i-1,l=j+1;k>=0&&l<n;k--,l++)
    {
       if(a[k][l]==1)
       {
           return false;
       }
    }
    return true;
}
void nqueen(int i)
{
    if(i==0)
    {
        printsol();
        c++;
         cout<<"\n";
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(issafe(row,j))
            {
                a[row][j]=1;
                row++;
                i--;
                nqueen(i);
                a[row][j]=0;
                row--;
                i++;
                //cout<<"hey "<<i<<" ";
            }
            else{
                row++;
            }
        }
    }
}
int main()
{
    cin>>n;
    int ln=n;
    int i,j;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
        {

          a[i][j]=0;
        }
    }
    nqueen(ln);
    if(c==0)
    {
        cout<<"Not Possible"<<"\n";
    }
    return 0;
}
