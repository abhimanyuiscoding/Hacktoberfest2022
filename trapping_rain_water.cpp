#include<bits/stdc++.h>

using namespace std;


class Solution{

   
    public:
    long long trappingWater(int arr[], int n){
        
        int left[n];
     int right[n];

     left[0] = arr[0];
     for(int i=1; i<n; i++){
         left[i] = max(arr[i], left[i-1]);
     }

     right[n-1] = arr[n-1];
     for(int i=n-2; i>=0; i--){
         right[i] = max(right[i+1] , arr[i]);
     }

     long ans = 0;
     for(int i=0; i<n; i++){
         ans =ans + (min(left[i] , right[i])) - arr[i];
     }
     return ans;
    }
};



int main(){

    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;


        cin >> n;

        int a[n];


        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;

        cout << obj.trappingWater(a, n) << endl;

    }

    return 0;
}
