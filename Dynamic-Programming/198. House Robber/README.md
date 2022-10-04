<h2><a href="https://leetcode.com/problems/house-robber/">198. House Robber</a></h2>
<h3>Hard</h3>
<hr>
<div><p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 </p>





<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
</pre>
Explanation: 
Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
<br>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
</pre>

 <pre>
 // IMP question 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        
        int prev2 = 0; 
        int prev = nums[0]; 
        
        for(int i = 1; i<n; i++){
            int pick = nums[i]; 
            if(i > 1) pick+=prev2; 
            
            int notPick = prev; 
            
            int curr = max(pick, notPick); 
            
            prev2 = prev;
            prev = curr; 
        }
        return prev; 
    }
};

 </pre>
