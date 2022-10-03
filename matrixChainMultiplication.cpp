#include <bits/stdc++.h>
using namespace std;
//Globally declared matrix of 100*100
int dp[100][100];
int matrixChainMultiplication(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMultiplication(p, i, k)
                     + matrixChainMultiplication(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMultiplication(p, i, j);
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
 
    cout << "Minimum number of multiplications is "<< MatrixChainOrder(arr, n);
}