
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter k : ";
    cin>>k;
    priority_queue<int> pq; 

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
  
  cout<<"The Kth smallest element is : "<<pq.top();
  return 0;
}
