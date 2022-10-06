int dp[102][102];

    int solve(int w, int wt[], int v[], int n){
        if(n==0 || w==0)
            return 0;

        if(dp[n][w]!=-1)
            return dp[n][w];

        if(wt[n-1]<=w)
            return dp[n][w] = max(v[n-1]+solve(w-wt[n-1], wt, v, n-1), solve(w, wt, v, n-1));

        else if(wt[n-1]>w)
            return dp[n][w] = solve(w, wt, v, n-1);
    }

    int main(){
        int n, w;
        cin >> n >> w;
      
        int wt[n], v[n];

        memset(dp, -1, sizeof(dp));

        for(int i=0;i<n;i++)
            cin >> wt[i];

        for(int i=0;i<n;i++)
            cin >> v[i];

        return solve(w, wt, v, n);
    }
