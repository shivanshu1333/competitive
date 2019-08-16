int Solution::numDecodings(string A) {
    if(A[0]=='0')
        return 0;
    int s = A.length();
    vector<int> dp(s+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=s;i++){
        int x=0,y=0;
        if(A[i-1]!='0')
            x = dp[i-1];
        if ((A[i-2]=='1') || (A[i-2]=='2')&&A[i-1]<'7')
            y = dp[i-2];
        dp[i] = x+y;
    }
    return dp[s];
}