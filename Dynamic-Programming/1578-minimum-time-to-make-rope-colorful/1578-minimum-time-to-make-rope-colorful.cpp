class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        if(colors.size() <= 1)
            return 0;
        vector<int> dp(time.size() + 1, 0);
        for(int i = 2; i < dp.size(); i++)
        {
            dp[i] = dp[i - 1];
            if(colors[i-1] == colors[i-2])
            {
                dp[i] += min(time[i-1], time[i-2]);
                time[i-1] = max(time[i-1], time[i-2]);
            }
        }
        return dp[dp.size() - 1];
    }
};