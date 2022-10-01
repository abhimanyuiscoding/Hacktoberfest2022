#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout<<"Enter the size of array : ";
    cin>>N;

    vector<int> nums(N);
    int target;
    cout<<"Enter the sorted array : ";
    for(int i=0; i<N; i++)
        cin>>nums[i];
    
    cout<<"Enter the target : ";
    cin>>target;

    // Binary Search Algorithm
    int low = 0, high = N-1;
    int index = -1;
    while(low<=high) {
        int mid = low +(high-low)/2;
        if(nums[mid]==target) {
            index = mid;
            break;
        }
        else if(nums[mid]<target) {
            low = mid+1;
        }
        else
            high = mid-1;
    }
    if(index==-1) {
        cout<<"Target element not found!\n";
    }
    else
        cout<<"Element found on index : "<<index<<".\n";
        
    return 0;
}