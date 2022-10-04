#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    cout<<"pattern ="<<pattern<<"\n";
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

int maxAND (int arr[], int n)
{
    int res = 0, count;
    for (int bit = 4; bit >= 0; bit--)
    {
        count = checkBit(res | (1 << bit),arr,n);
        cout<<"count ="<<count<<"\n";
        if ( count >= 2 )        
            res |= (1 << bit);        
    }
    cout<<"res ="<<res<<"\n";
    return res;
}


int main(){
   IOS;
   int t;
   cin>>t;
   while (t--)
     {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<maxAND(a,n);
     }

return 0;
}