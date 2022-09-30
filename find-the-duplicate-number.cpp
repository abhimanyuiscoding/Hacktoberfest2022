class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        
        
        // Tortoise and hare approach
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
        
        // CANNOT SORT AS IT WILL MODIFY THE ARRAY
//         sort(nums.begin(),nums.end());
            
//         int k = 0;
        
//         for(int i =1; i<nums.size();i++){
//             if(nums[i]==nums[k])
//                 return nums[k];
//             k++;
//         }
//         return -1;
    }
};
