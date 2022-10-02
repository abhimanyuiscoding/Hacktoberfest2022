class Solution {
public:
    int trap(vector<int>& height) {
        // TC - log(N), SC - log(N)
        int n = height.size();
        
        if(n<3)
        {
            return 0;
        }
        
        vector<int> left(n),right(n);
        
        left[0] = 0;
        int leftMax = height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=leftMax;
            leftMax=max(leftMax, height[i]);
        }
        
        
        right[n-1] = 0;
        int rightMax = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=rightMax;
            rightMax=max(rightMax, height[i]);
        }
        
        
        int trappedWater = 0;
        for(int i=1;i<n-1;i++)
        {
            if(height[i]<left[i] && height[i]<right[i])
            {
                trappedWater+=min(left[i],right[i]) - height[i];
            }
        }
        
        return trappedWater;
            
    }
};
