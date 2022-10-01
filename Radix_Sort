#include<bits/stdc++.h>                                                                                     
using namespace std;
void countSort(int arr[],int n,int digit)
{
    vector<int> count(10,0);
    int num =pow(10,digit);
    for(int i=0;i<n;i++)
    {
        count[(arr[i]/num)%10]++;
    }
    for(int i=1;i<10;i++)                                                            // time comeplexity O(n+k)
    {
        count[i]=count[i-1]+count[i];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/num)%10]-1]=arr[i];
        count[(arr[i]/num)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
}
void radixSort(int arr[],int n,int digit)
{
    for(int i=0;i<=digit;i++)
    {
        countSort(arr,n,i);
    }
}
int main()
{
    int n;                                                            //low range value of an array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int digit=0;
    for(int i=0;i<n;i++)
    {
        int x=log10(arr[i]);
        digit=max(digit,x);
    }
    radixSort(arr,n,digit);
    cout<<"Array for Sorting"<<endl;
    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}
