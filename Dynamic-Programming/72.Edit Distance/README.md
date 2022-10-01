<h2><a href="https://leetcode.com/problems/edit-distance/">72. Edit Distance</a></h2>
<h3>Hard</h3>
<hr>
<div><p>Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 </p>





<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> Input: word1 = "horse", word2 = "ros"
<strong>Output:</strong> 3
</pre>
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
<br>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> word1 = "intention", word2 = "execution"
<strong>Output:</strong> 5
</pre>

 <pre>
 // IMP question 
// apply normal dp and memozise it

class Solution {
public:
    int dp[501][501];
    int solve(int m,int n,string w1,string w2)
    {
        //base case
        if(m==0|| n==0) return max(m,n);
         
        // memo
        if(dp[m][n]!=-1) return dp[m][n];
        
        //choice diagram
        int ans=0;
        if(w1[m-1]==w2[n-1]) ans=solve(m-1,n-1,w1,w2);
        else 
            ans=1+min({solve(m-1,n,w1,w2),solve(m,n-1,w1,w2),
                       solve(m-1,n-1,w1,w2)});
        return dp[m][n]=ans;
        
    }
    
    int minDistance(string w1, string w2) {
        memset(dp,-1,sizeof(dp));
        return solve(w1.size(),w2.size(),w1,w2);
    }
};

 </pre>
