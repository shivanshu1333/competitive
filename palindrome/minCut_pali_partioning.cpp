    void pre_process(vector<vector<bool>> &dp, string s) {
        int n = s.size(); 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) 
                dp[i][j] = false; 
        } 
        for (int j = 1; j <= n; j++) { 
            for (int i = 0; i <= n - j; i++) { \
                if (j <= 2) { 
                    if (s[i] == s[i + j - 1]) 
                        dp[i][i + j - 1] = true; 
                } 
                else if (s[i] == s[i + j - 1]) 
                    dp[i][i + j - 1] = dp[i + 1][i + j - 2]; 
            } 
        } 
    }     
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        pre_process(dp, s);
        vector<int> c(n);
        cout<<dp[n-1][0]<<endl;
        for(int i=0;i<n;i++){
            if(dp[0][i]) c[i]=0;
            else{
                c[i]=INT_MAX;
                for(int j=0;j<i;j++){
                    if(dp[j+1][i]==1 && 1+c[j]<c[i])
                    c[i]=c[j]+1;
                }
            }
        }
        return c[n-1];
    }