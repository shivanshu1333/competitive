//Maximum sum such that no two elements are adjacent
int ms(v<int> &a, int i, v<int> &dp){
    if(i>=a.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i]=max((a[i]+ms(a, i+2, dp)), ms(a, i+1, dp));
    return dp[i];      
}