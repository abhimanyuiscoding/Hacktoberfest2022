// normal lcs code
class Solution {
public:
    int dp[1001][1001];
    string s1,s2;
    int LCS(int n, int m)
    {
        //base case
        if(n==0||m==0) return 0;
        //Memozise
        if(dp[n][m]!=-1) return dp[n][m];
        
        //choice diagram
        int ans=0;
        if(s1[n-1]==s2[m-1]) ans= 1+LCS(n-1,m-1);
        else ans=max(LCS(n-1,m),LCS(n,m-1));
        return dp[n][m]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        s1=text1,s2=text2;
        return LCS(text1.size(),text2.size()); 
    }
}
