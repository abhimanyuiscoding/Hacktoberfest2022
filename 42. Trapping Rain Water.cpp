// Question - https://leetcode.com/problems/trapping-rain-water/

// Brute force
// Approach: For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a 
// particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

// Code - 

int trap(vector<int>& height) {
        int ans =0 , n = height.size();
        for(int i=0;i<n;i++)
        {
            int j=i;
            int leftmax=0,rightmax=0;
            while(j>=0)
            {
                leftmax = max(leftmax,height[j]);
                j--;
            }
            j=i;
            while(j<n)
            {
                rightmax=max(rightmax,height[j]);
                j++;
            }
            
            ans+=min(leftmax,rightmax)-height[i];
        }
        
        return ans;
}



// Optimal

// Intuition: We are taking O(N) for computing leftMax and rightMax at each index. The complexity can be boiled down to O(1) if we precompute the leftMax and 
// rightMax at each index.
// Approach:Take 2 array prefix and suffix array and precompute the leftMax and rightMax for each index beforehand.
// Then use the formula min(prefix[i],suffix[i])-arr[i] to compute water trapped at each index.

// Code - 


int trap(vector<int>& height) {
  
        int n = height.size(),ans=0;
        int leftmax[n],rightmax[n];
        leftmax[0]=height[0];
        for(int i=1;i<n;i++)
            leftmax[i]=max(leftmax[i-1],height[i]);
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            rightmax[i]=max(rightmax[i+1],height[i]);
        
        for(int i=0;i<n;i++)
            ans+=min(leftmax[i],rightmax[i])-height[i];
        
        return ans;
  
}
