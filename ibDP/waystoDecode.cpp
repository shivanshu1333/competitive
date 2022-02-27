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
////memo
int ways(string s, int i, vector<int> &dp){
    if(i==s.length())
        return 1;
    if(dp[i]!=-1) return dp[i];
    else{
        if(s[i]=='0')
            return 0;
        else if(s[i]>'2'){
            dp[i] = ways(s, i+1, dp);
            return dp[i];
        }
        else if(i+1>=s.length()){
            dp[i] = ways(s, i+1, dp);
            return dp[i];
        }
        else if(s[i]=='1' || (s[i]=='2'&&s[i+1]<'7')){
            dp[i] = ways(s, i+2, dp)+ways(s,i+1, dp);
            return dp[i];                
        }
        else{
            dp[i] = ways(s, i+1, dp);
            return dp[i];    
        }  
    }
    return dp[i];
}
    


int Solution::numDecodings(string A) {
    vector<int> dp(s.length(), -1);
    return ways(A,0,dp);
}