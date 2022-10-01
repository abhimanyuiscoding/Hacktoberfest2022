class Solution {
    public int trap(int[] height) {
        int[] left=new int[height.length];
        int[] right=new int[height.length];
        int ans=0;
        left[0]=Integer.MIN_VALUE;
        for(int i=1;i<height.length;i++){
            left[i]=Math.max(left[i-1],height[i-1]);
        }
        right[height.length-1]=Integer.MIN_VALUE;
        for(int i=height.length-2;i>=0;i--){
            right[i]=Math.max(right[i+1],height[i+1]);
        }
        for(int i=1;i<height.length-1;i++){
            int curr=Math.min(left[i],right[i])-height[i];
            ans+=curr>0?curr:0;
        }
        return ans;
    }
}
