#include <bits/stdc++.h>
using namespace std;
#define r 4
#define c 4

void spiral_matrix(int m,int n,int matrix[r][c])
{
    int i,k=0,l=0;

    //k = start row index
    //m = ending row index
    //l = start column index
    //n = ending column indes 
    
    //Printing the elements of the kth row
    while(k<m && l<n)
    {
        //this Prints the top row
        for(int i=0;i<n;i++)
        {
            cout<<matrix[k][i]<<" ";
        }
        k++;

        //this Print the right column
        for(i=k;i<m;i++)
        {
            cout<<matrix[i][n-1]<<" ";
        }
        n--;


        //this Print the bottom row
        if(k<m){

            for(i = n-1; i>=1;i--)
            {
                cout<<matrix[m-1][i]<<" ";
            }
            m--;
        }

        //this prints the left column
        if(l<n)
        {
            for(i=m-1;i>=k;i--)
            {
                cout<<matrix[i][l]<<" ";
            }
            l++;
        }
    }
}
int main()
{
    int matrix[r][c];
    cout<<"Enter the elements of the matrix"<<endl;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>matrix[i][j];
        }
    }

    spiral_matrix(r,c,matrix);
    return 0;


}