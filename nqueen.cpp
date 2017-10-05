#include<iostream>
#include<conio.h>
using namespace std;
int a[100][100],n,c=0;
void printsol()
{
    int i,j;
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"- ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
void cprintsol()
{
    int i,j,r=n;
    char c='a';
    cout<<"\n\n";
    for(i=0;i<n;i++)
    {
        if(r<10)
        {
        cout<<r<<"  ";
        }
        else
        {
            cout<<r<<" ";
        }
        r--;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"- ";
            }
        }
        cout<<"\n";
    }
    if(n<10)
    {
    cout<<"   ";
    }
    else
    {
         cout<<"   ";
    }
     for(j=0;j<n;j++)
        {
           cout<<c<<" ";
           c++;
        }
        cout<<"\n\n";
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
    if(i>=n)
    {
        cout<<"Press any key to view a solution\n";
        getch();
        cprintsol();
        c++;
         cout<<"\n";
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(issafe(i,j))
            {
                a[i][j]=1;
                nqueen(i+1);
                a[i][j]=0;
            }
        }
    }
}
void cnqueen(int i)
{
    if(i>=n)
    {
        //printsol();
        c++;
         //cout<<"\n";
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(issafe(i,j))
            {
                a[i][j]=1;
                cnqueen(i+1);
                a[i][j]=0;
            }
        }
    }
}
int main()
{
    cout<<"Enter N: \n";
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
        {

          a[i][j]=0;
        }
    }
     // cnqueen(0);
   // cout<<"Number of solutions are "<<c<<endl;
    c=0;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
        {

          a[i][j]=0;
        }
    }
    nqueen(0);
   // cout<<"Number of solutions are "<<c<<endl;
    if(c==0)
    {
        cout<<"Not Possible"<<"\n";
    }
    return 0;
}
