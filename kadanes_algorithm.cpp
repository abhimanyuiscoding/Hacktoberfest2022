// The Kadane's Algorithm is used to find the largest contiguous sum of an array :  

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements : \n";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements one by one : \n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int prev_max = INT_MIN, cur_max = 0;

    for (int i = 0; i < n; i++)
    {
        cur_max = cur_max + v[i];
        if (prev_max < cur_max)
            prev_max = cur_max;

        if (cur_max < 0)
            cur_max = 0;
    }
    
    cout<<"The largest contiguous array sum is : "<<prev_max<<"\n";

    return 0;
}
