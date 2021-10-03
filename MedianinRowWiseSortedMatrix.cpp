// Problem link : https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int minElement = INT_MAX;
    	int maxELement = INT_MIN;
    
    	for(int i=0; i<r; i++) {
    		minElement = min(minElement, matrix[i][0]);
    		maxELement = max(maxELement, matrix[i][c-1]);
    	}
    
    	int desiredElements = (r*c+1)/2;	
    
    	while(minElement < maxELement) {
    
    		int currentElements = 0;
    		int mid = minElement + (maxELement- minElement)/2;
    
    		for(int i=0; i<r; i++) {
    			currentElements += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    		}
    
    		if(currentElements< desiredElements) {
    			minElement = mid+1;
    		} else {
    			maxELement = mid;
    		}
    	}
    
    	return minElement;
    }
};

// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]

// Output: 5

// Explanation:
// Sorting matrix elements gives us 
// {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

int main()
{
        int r=3, c=3;
        vector<vector<int>> matrix(r, vector<int>(c));
        matrix[0] = {1,3,5};
        matrix[1] = {2,6,9};
        matrix[2] = {3,6,9};
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    return 0;
}
