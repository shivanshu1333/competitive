int mod = 1e9+7;
int dieSimulator(int n, vector<int>& r) {
    int dp[n][6][16];
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
            for(int k=0;k<16;k++)
                dp[i][j][k]=0;
    for(int i=0;i<6;i++)
        dp[0][i][1]=1;
    for(int i=1; i<n;i++){
        for(int j=0; j<6; j++) {
            for(int k = 0; k < 6; ++k) {
                if(k == j) continue;
                for(int m=1; m<=r[k];m++)
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][k][m]) % mod;
            }
            for(int m=2; m<=r[j];m++)
                dp[i][j][m]=dp[i-1][j][m-1];
        }
    }
    int ans=0;
    for(int i=0;i<6;i++)
        for(int j = 1; j <= r[i]; ++j)
            ans = (ans + dp[n - 1][i][j]) % mod;
    return ans;
}