//#include<stdio.h>
//#include<limits.h>
//long int rss,css;
////void sort(long int *array,long int n)
////{
////    int i,flag,j;
////    long int temp;
////    for(i=0; i<n; i++)
////    {
////       flag = 0;
////       for(j=0; j<n-i-1; j++)
////       {
////          if(array[j]>array[j+1])
////          {
////            flag = 1;
////              temp = array[j+1];
////             array[j+1] = array[j];
////             array[j] = temp;
////          }
////       }
////      // No Swapping happened, array is sorted
////      if(flag==0){
////         return;
////      }
////   }
////}
//void sort(long int a[],long int n)
//{
//    int j,f=-1;
//    long int t;
//        for(j=0;j<n-1;j++)
//        {
//            if(a[j]>a[j+1])
//            {
//                t=a[j];
//                a[j]=a[j+1];
//                a[j+1]=t;
//                f=1;
//            }
//            else
//            {
//                f=0;
//            }
//            if(f==0)
//            {
//                break;
//            }
//        }
//
//}
//long int part(long int a[],long int p,long int r)
//{
//    long int i,j,k,t;
//    i=p-1;
//    k=a[r];
//    for(j=p;j<r;j++)
//    {
//        if(k>a[j])
//        {
//            i=i+1;
//           t=a[i];
//           a[i]=a[j];
//           a[j]=t;
//        }
//    }
//    t=a[i+1];
//    a[i+1]=a[r];
//    a[r]=t;
//    return i+1;
//}
//void quick(long int A[],long int p,long int r)
//{
//   long int q;
//    if(p<r)
//    {
//    q= part(A,p,r);
//    quick(A,p,q-1);
//    quick(A,q+1,r);
//    }
//}
////long int val(long int r[], long int c[],long int n)
////{
////    int i,f;
////    long int rt;
////    f=0;
////    if(r[0]+rss<c[0]+css)
////    {
////        rt=r[0]+rss;
////        css++;
////        r[0]=r[0]+n;
////        sort(r,n);
////        f=1;
////    }
////    else if(r[0]+rss>c[0]+css)
////    {
////        rt=c[0]+css;
////        rss++;
////        c[0]=c[0]+n;
////        sort(c,n);
////        f=1;
////    }
////    else
////    {
////        rt=c[0]+css;
////        for(i=1;i<n;i++)
////        {
////            if(r[i]+rss<c[i]+css)
////            {
////                css++;
////                r[0]=r[0]+n;
////                sort(r,n);
////                f=1;
////                break;
////            }
////            else if(r[i]+rss>c[i]+css)
////            {
////                rss++;
////                c[0]=c[0]+n;
////                sort(c,n);
////                f=1;
////                break;
////            }
////        }
////    }
////    if(f==1)
////    {
////        return rt;
////    }
////    else
////    {
////        css++;
////        r[0]=r[0]+n;
////        sort(r,n);
////        return rt;
////    }
////}
//long int min(long int a, long int b)
//{
//    if(a<=b)
//    return a;
//    else
//    return b;
//}
//void main()
//{
//    long int t,n,k,a[205][205],i,j,rs[205],cs[205],c,r,s,sr[405],sc[405];
//    //long int *rm,*cm;
//    scanf("%ld",&t);
//    while(t--)
//    {
//        s=LONG_MAX;
//        scanf("%ld%ld",&n,&k);
//        c=0;
//        r=0;
//        rss=0;
//        css=0;
//        for(i=0;i<205;i++)
//        {
//            rs[i]=0;
//            cs[i]=0;
//        }
//         for(i=0;i<405;i++)
//        {
//            sr[i]=0;
//            sc[i]=0;
//        }
//    for(i=0;i<n;i++)
//    {
//        r=0;
//        for(j=0;j<n;j++)
//        {
//            scanf("%ld",&a[i][j]);
//            r=r+a[i][j];
//            cs[j]=cs[j]+a[i][j];
//        }
//        rs[i]=r;
//    }
//    quick(rs,0,n-1);
//    quick(cs,0,n-1);
////    for(i=0;i<n;i++)
////    {
////        printf("%ld ",rs[i]);
////    }
////    for(i=0;i<n;i++)
////    {
////        printf("%ld ",cs[i]);
////    }
//   sr[0]=sc[0]=0;
//    for(i=1;i<=k;i++)
//    {
//        sr[i]=sr[i-1]+rs[0];
//        rs[0]=rs[0]+n;
//        sort(rs,n);
//    }
//    for(i=1;i<=k;i++)
//    {
//        sc[i]=sc[i-1]+cs[0];
//        cs[0]=cs[0]+n;
//        sort(cs,n);
//    }
////    for(i=0;i<k;i++)
////    {
////        printf("%ld ",sr[i]);
////    }
////    for(i=0;i<k;i++)
////    {
////        printf("%ld ",sc[i]);
////    }
//    for(j=0;j<=k;j++)
//    {
//        s=min(s,sr[j]+sc[k-j]+(j*(k-j)));
//    }
//    printf("%ld\n",s);
//    }
//
//    }
//
//
#include <stdio.h>
#include <stdbool.h>

int swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition ( int A[],int start ,int end) {
    int i = start + 1,temp;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[ j ] < piv) {
                 //swap (&A[ i ],&A [ j ]);
                 temp=A[i];
				 A[i]=A[j];
				 A[j]=temp;
            i += 1;
        }
   }
   //swap ( A[ start ] ,A[ i-1 ] ) ;
   temp=A[start];
    A[start]=A[i-1];
    A[i-1]=temp;//put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}
void quick_sort ( int A[ ] ,int start , int end ) {
   if( start < end ) {
        //stores the position of pivot element
         int piv_pos = partition (A,start , end ) ;
         quick_sort (A,start , piv_pos -1);    //sorts the left side of pivot.
         quick_sort ( A,piv_pos +1 , end) ; //sorts the right side of pivot.
   }
}
void insert(int A[],int start,int end)
{
	int i,temp;
	for(i=start;i<end;i++)
	{
		if(A[i]>A[i+1])
		{
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
		else break;
	}
}
bool fun(int row[],int col[],int n)
{
    int i;
    for(i=1;i<n;i++){if(row[i]+row[n]<col[i]+col[n]) return true; else if(row[i]+row[n]>col[i]+col[n]) return false;}

    return true;
}
int min(a,b)
{
	if(a>b)
		return b;
	else return a;
}
int main()
{
    int t,n,k,a[200][200],i,j,sum;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%d",&n,&k);
    	int *row=(int *)malloc((n+1)*sizeof(int));
    	int *col=(int *)malloc((n+1)*sizeof(int));
    	int *sr=(int *)malloc((n+1)*sizeof(int));
    	int *sc=(int *)malloc((n+1)*sizeof(int));
    	//for(i=0;i<n;i++)
    	//a[i]=(int *)malloc(n*sizeof(int));
    	for(i=0;i<n;i++)
    		for(j=0;j<n;j++)
    			scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
		{
			sum=0;
    		for(j=0;j<n;j++)
    		{
    			if(i==0)
    				col[j]=a[i][j];
    			else
    				col[j]+=a[i][j];
    			sum+=a[i][j];
    		}
    		row[i]=sum;
		}
		row[n]=0;col[n]=0;
		quick_sort(row,0,n-1);
		quick_sort(col,0,n-1);
		int result=9999999;
		sc[0]=0;sr[0]=0;
		for(i=1;i<=k;i++)
		{
			sr[i]=sr[i-1]+row[0];
			sc[i]=sc[i-1]+col[0];
			row[0]+=n;col[0]+=n;
			insert(row,0,n-1);
			insert(col,0,n-1);
		}
		for(i=0;i<=k;i++)
		{
			//printf("%d %d %d\n",sr[i],sc[i],result);
			result=min(result,sr[i]+sc[k-i]+i*(k-i));
		}

		/*for(i=0;i<k;i++)
		{
			if(row[0]+row[n]<col[0]+col[n] || (row[0]+row[n]==col[0]+col[n] && fun(row,col,n)))
			{
				result+=row[0]+row[n];
				row[0]+=n;
				col[n]+=1;
				insert(row,0,n-1);

			}
			else
			{
				result+=col[0]+col[n];
				col[0]+=n;
				row[n]+=1;
				insert(col,0,n-1);

			}


		}*/

		printf("%d\n",result);
		free(row);free(col);free(sr);free(sc);
		//for(i=0;i<n;i++)
		//	free(a[i]);

    }
    return 0;
}
