int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int max=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min)
            {min=prices[i];
            max=0;}
            if(prices[i]>max)
                max=prices[i];
            if(max-min>ans)
                ans=max-min;
        }
        return ans;
    }
