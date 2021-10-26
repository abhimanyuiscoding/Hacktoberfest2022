//Time Complexity O(n)

#include <bits/stdc++.h>

using namespace std;

int stockBuySell(int arr[],int n)
{
    int max_profit =0;
    int minSofar=arr[0];
    for(int i=0;i<n;i++)
    {   int profit;
         minSofar=min(minSofar,arr[i]);
        profit =arr[i]- minSofar;
        max_profit=max(max_profit,profit);


    }
    return max_profit;
}
int main()
{

    int arr[] = {3,1,4,8,7,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxprofit=stockBuySell(arr,n);
    cout<<"Maximum Profit is  "<<maxprofit;
    return 0;

}
