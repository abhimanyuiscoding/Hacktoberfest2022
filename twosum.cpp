class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].first++;
            mp[nums[i]].second=i;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]].first)
            {
                if(i!=mp[target-nums[i]].second)
                {
                     ans.push_back(i);
                     ans.push_back(mp[target-nums[i]].second);
                    return ans;
                }       
            }
        }
        return ans;
    }
};
