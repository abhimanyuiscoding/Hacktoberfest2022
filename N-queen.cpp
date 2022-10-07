#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    void solve(int col, vector<vector<int>> &ans, vector<int> &temp, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                temp.push_back(row+1);
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1, ans, temp, n, leftRow, upperDiagonal, lowerDiagonal);
                temp.pop_back();
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board;
        for(int i=0;i<n;i++){
            vector<int> temp(n,i+1);
            board.push_back(temp);
        }
        vector<int> temp;
        
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        
        solve(0,ans,temp,n,leftRow,upperDiagonal, lowerDiagonal);
        return ans;
        
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
