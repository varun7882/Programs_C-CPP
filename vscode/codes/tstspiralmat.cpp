#include<iostream>
#include<vector>
using namespace std;
int main()
{

   return 0;
}
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	 int n,i,j,r,c,p=1,R,C;
	 R=A.size();
	 C=A[0].size();
    r=c=0;
    R=C=n;
    i=0;j=0;
    while(p<=(n*n))
    {
        j=c;
        while(j<C)
        {
            a[i][j]=p++;
            j++;
        }
        r++;
        i=r;
        j--;
        while(i<R)
        {
            a[i][j]=p++;
            i++;
        }
        C--;
        i--;
        j=C-1;
        while(j>=c)
        {
            a[i][j]=p++;
            j--;
        }
        R--;
        i=R-1;
        j++;
        while(i>=r)
        {
            a[i][j]=p++;
            i--;
        }
        i++;
        c++;
    }
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
