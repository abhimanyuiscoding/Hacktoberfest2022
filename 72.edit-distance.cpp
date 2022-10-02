// 503. Next Greater Element II
#include<bits/stdc++.h>
using namespace std;

int solve(string& word1, string& word2, int i, int j, vector<vector<int> >& dp) {

    if(i == word1.length())
        return word2.length() - j;

    if(j == word2.length())
        return word1.size() - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(word1[i] == word2[j])
        return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
    
    else {

        int insertAns = solve(word1, word2, i, j+1, dp);
        int replaceAns = solve(word1, word2, i+1, j+1, dp);
        int deleteAns = solve(word1, word2, i+1, j, dp);

        return dp[i][j] = 1 + min(insertAns, min(replaceAns, deleteAns));
    }
}

int minDistance(string word1, string word2) {
    vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
    return solve(word1, word2, 0, 0, dp);
}

int main() {

    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2);

    return 0;
}