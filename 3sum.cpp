class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

         vector<vector<int>> result;
        int sum , n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            
            if(i==0 || nums[i]!=nums[i-1]){
                int left = i+1;
                int right = n-1;
                while(left<right){
                    sum = nums[i]+nums[left]+nums[right];
                    if(sum==0){
                        result.push_back({nums[i], nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left+1]){
                            left++;

                        }while(left<right && nums[right] == nums[right+1]){
                            right--;
                            
                        }
                        left++;
                        right--;


                    }
                    else if(sum<0){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
            return result;


       
        }
    };
};
