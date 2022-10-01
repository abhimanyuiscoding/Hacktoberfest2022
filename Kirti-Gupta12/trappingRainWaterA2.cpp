class Solution {
public:
    int trap(vector<int>& height) {
         //TC - log(N), SC - log(1)
            
        int n = height.size();
        
        if(n<3)
        {
            return 0;
        }
        int leftMax = height[0];
        int rightMax = height[n-1];
        int trappedWater = 0;
        
        int left=1;
        int right=n-2;
        
        while(left<=right)
        {
            if(leftMax<rightMax)
            {
                if(height[left]>=leftMax)
                    leftMax = height[left];
                
                else
                    trappedWater+=leftMax-height[left];
                left++;
            }
            else
            {
                if(height[right]>rightMax)
                    rightMax=height[right];
                else
                    trappedWater+=rightMax-height[right];
                right--;
            }
        }
        return trappedWater;
    }
};
