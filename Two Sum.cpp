#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int>  twoSum(vector<int>& nums, int target) {
        int rem = 0,count=0,indexI=0,indexJ=0;
        vector<int>indexes,v;
        bool flag = false;
        vector<int>::iterator itr,itr1,itr2;
        itr = find(nums.begin(), nums.end(), rem);
        for (auto i : nums)
        {
            rem = target - i;
            for (auto j : nums)
            {
                if (indexJ != indexI)
                {
                    if (j == rem)
                    {
                        indexes.push_back(indexI);
                        indexes.push_back(indexJ);
                        flag = true;
                        break;
                    }
                }
                indexJ++;
            }
            indexJ = 0;
            indexI++;
            if (flag)
                break;
            /*rem = target - i;
            if (rem == 0) {
                 count++;
                continue;
            }
            if (rem == i && count==0)
            {
                flag = true;
                count++;
                continue;
            }
             if(rem==i && count>0 && flag)
               itr = find_end(nums.begin(), nums.end(),v.begin() ,v.end());
            else
        itr = find(nums.begin(), nums.end(), rem);
        vector<int>::iterator itr1 = find(nums.begin(), nums.end(), i);
            if (distance(nums.begin(), itr) != distance(nums.begin(), itr1))
            {
                indexes.push_back(distance(nums.begin(), itr1));
                if(count>0 &&flag)
                indexes.push_back(distance(nums.begin(), itr-1));
                else
                    indexes.push_back(distance(nums.begin(), itr));
                break;
            }*/ 
        }
        return indexes;
    }
};
int main()
{
    vector<int>v={2,4,5,11,9};
    vector<int>v1;
    Solution s;
    v1=s.twoSum(v,13);
    for (auto i : v1)
    {
        cout << i << ",";
    }
	return 0;
}