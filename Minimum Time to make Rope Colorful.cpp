#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
int minCost(string colors, vector<int>& neededtime) {
        char col='1';
        int size=1;
        multiset<int> ms;
        int count=0;
        int sum=0;
        for(int i=0;i<neededtime.size();i++)
        {
            if(colors[i]==col)
            {
                size++;
                sum=sum+neededtime[i];
                ms.insert(neededtime[i]);
                col=colors[i];
            }
            else
            {
                if(size>1)
                {
                    auto it=ms.rbegin();
                    int value=*it;
                    count=count+sum-value;
                    sum=0;
                    ms.clear();
                }
                ms.insert(neededtime[i]);
                col=colors[i];
                size++;
                sum=sum+neededtime[i];
                
            }
        }
        if(size>1)
        {
            auto it=ms.rbegin();
            int value=*it;
            count=count+sum-value;
            sum=0;
            ms.clear();
        }
        return count;
    }
int main()
{
	string colors="aaaba";
	vector<int> neededTime;
	for(int i=0;i<colors.length();i++)
	{
		neededTime.push_back(i+2);
	}
	cout<<minCost(colors,neededTime);
}
