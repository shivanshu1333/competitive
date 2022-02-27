//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac", output 1

bool isInterleave(string s1, string s2, string s3) {
    int m=s1.length(), n=s2.length();
    if((m+n)!=s3.length()) return 0;
    vector<bool> dp(n+1, 0);
    dp[0]=1;
    int i,j=0;
    while(j<n && s2[j]==s3[j]) dp[++j]=1;
    for(i=0;i<m;++i){
        dp[0]=dp[0] & (s1[i]==s3[i]);
        for(j=1;j<=n;++j)
            dp[j] = ((s1[i] == s3[i+j]) & dp[j]) | ((s2[j-1]==s3[i+j]) & dp[j-1]);
    }
    return dp[n];
}