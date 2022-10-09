#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// function to find longest common subsequence
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        if(x<=0 || y<=0)
            return 0;
        
        if(s1[x-1]==s2[y-1])
            return 1 + lcs(x-1, y-1, s1, s2);
        
        return max(lcs(x-1, y-1, s1, s2), max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2)));
    }
};

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
