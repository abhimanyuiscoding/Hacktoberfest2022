//Optimal Strategy For A Game
//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:

    //Method-1 (DP solution) (Time- O(n^2))
    long long maximumAmount(int arr[], int n){
        // Your code here
        int dp[n][n];
        
        for(int i=0;i<n-1;i++)
            dp[i][i+1]=max(arr[i],arr[i+1]);
        
        int j; 
        for(int gap=3;gap<n;gap+=2)
            for(int i=0;i+gap<n;i++){
                j=i+gap;
                dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]), 
                            arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
            }
            
        return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends