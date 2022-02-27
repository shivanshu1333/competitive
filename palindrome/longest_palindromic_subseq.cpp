class Solution {
public:
    int rec(vector<vector<int>> &dp, string &s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j]=2+rec(dp, s, i+1, j-1);
        }
        else{
            dp[i][j] = max(rec(dp, s, i+1, j), rec(dp, s, i, j-1));
        }
        return dp[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        if(n<2) return n;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return rec(dp, s, 0, n-1);
    }
};