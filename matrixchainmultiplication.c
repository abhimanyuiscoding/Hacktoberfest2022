#include <stdio.h>
#include <limits.h>
int matrix_chain(int p[],int i,int j)
{
    if (i==j)
    {
        return 0;
    }
    int k,a = INT_MAX,val;
    for(k=i;k<j;k++)
    {
        val = matrix_chain(p,i,k)+matrix_chain(p,k+1,j)+p[i-1]*p[k]*p[j];
        if (val<a)
        {
            a = val;
        }
    }    
    return a;
}
int main()
{
    int p[] = {5,6,7,8,5};
    int n =  sizeof(p)/sizeof(p[0]);
    printf("Minimum cost:- %d",matrix_chain(p,1,n-1));
    return 0;
}