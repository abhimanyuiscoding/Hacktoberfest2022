#include <bits/stdc++.h>
using namespace std;
//Dev Wadhwa
int main()
{
    cout<<"Stock Span Problem"<<endl;
    cout<<"Enter number of elements"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<pair<int,int>> s;
    vector<int> result;
    pair <int,int> p;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            result.push_back(1);
        }
        else
        {
            while(s.empty()==false && s.top().second<=arr[i])       //Should be <= because the same element needs to be popped to get the correct number of days
            {
                s.pop();
            }
            if(s.empty())
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(i-s.top().first);
            }
        }
        p.first=i;
        p.second=arr[i];
        s.push(p);
    }
    cout<<"Result"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
    return 0;
}
