#include<iostream>
using namespace std;
int hpart(int a[],int l,int h)
{
    int i,j,x,t;
    i=l-1;
    j=h+1;;
    x=a[l];
    while(1)
    {
        do
       {
           j--;
       }while(x<a[j]);
       do
       {
           i++;
       }while(x>a[i]);
       if(i<j)
       {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
       }
       else
        return j;
    }
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=hpart(a,l,h);
        quicksort(a,l,m);
        quicksort(a,m+1,h);
    }
}
int main()
{
    int n,a[100],i;
    cout<<"enter the elements"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
     cout<<"elements are... "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,0,n-1);
     for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
