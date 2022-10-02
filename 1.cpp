//insertion sort
#include<iostream>
using namespace std;
int main(){
    int arr[] = {50,40,10,30,20};
    int n = sizeof(arr)/sizeof(int);//if size of array is n then it takes n-1 passes.
        int key;
        for(int i =1;i<=n-1;i++){
            //in ith path we insert 1st element of unsorted part to correct position in sorted part
            key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>key ){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
            // for ( j = i-1; j >=0; j--)
            // {
            //     if(key<arr[j]){
            //         arr[j+1] = arr[j];
            //     }
            //     else
            //     break;
            // }
            // arr[j+1] = key;
        }

        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout <<endl;
        
        return 0;
}
/*
analysis of insertion sort
sorted part 1 to n-1
unsorted part form sorted part minus 1 (n-2 to 0,n-3 to 0,) to 0 for every sorted number  and as i increases ,,j from i -1 to 0.
key = 1 to n-1
so the time taken will be n(n-1)/2 => O(n^2);
 

BEST CASE 
- 
 FOR AN ALREADY SORTED ARRAY IT IS n-1;
*/