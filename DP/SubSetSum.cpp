bool isSubset(vector<long long> &v, long long sum){
    int r = v.size();
    int c = sum;
    vector<vector<bool>> dp(r+1, vector<bool> (c+1,0));

    for(int i=0;i<=r;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(j<v[i-1])
                dp[i][j] = dp[i-1][j];
            if (j >= v[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
        }
    }
    return dp[r][c];
}