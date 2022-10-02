
<h2><a href="https://leetcode.com/problems/maximum-length-of-repeated-subarray/">718. Maximum Length of Repeated Subarray</a></h2>
<h3>Medium</h3>
<hr>
<div><p>
 
 Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

</p>


<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong>  nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
<strong>Output:</strong> 3
</pre>

Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
 
<hr>
 <strong><b>Solution</b></strong>
 <br>
 <p><pre>
 class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        int n = nums1.size(),m = nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i==n-1 || j==m-1){
                    if(nums1[i]==nums2[j]){
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(nums1[i]==nums2[j]){
                        dp[i][j] = 1+dp[i+1][j+1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
 </pre>
</p>
