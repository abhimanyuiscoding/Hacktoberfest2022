vector<int> subsetSums(vector<int> arr, int N)
    {
        
        vector <int> ans;
        for(int nums=0;nums<pow(2,N)-1;nums++){
            int sum=0;
            
            for(int i=0;i<N;i++){
                if(nums&(1<<i)){
                    sum=sum+arr[i];
                }
            }
            ans.push_back(sum);
        }
        int k = std::accumulate(arr.begin(),arr.end(),0);
        ans.push_back(k);
        return ans;
    }
