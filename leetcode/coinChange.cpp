class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,0));
        int c = coins.size();
        int t = amount;
        for(int i=1;i<=c;i++){
            for(int j=1;j<=t;j++){
                if((j-coins[i-1])<0)
                    dp[i][j] = dp[i-1][j];
                else if((j-coins[i-1])==0){
                    dp[i][j] = 1;
                }
                else{
                    if(dp[i][j-coins[i-1]]==0)
                        dp[i][j] = dp[i-1][j];
                    else{
                        if(dp[i-1][j]==0)
                            dp[i][j] = 1+dp[i][j-coins[i-1]];
                        else
                            dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                    }
                }
            }
        }
        int mi = INT_MAX;
        int a;
        for(int i=1;i<=c;i++){
            if(dp[i][t]==0)
                a=INT_MAX;
            else
                a=dp[i][t];
            mi = min(mi,a);
        }
        if(mi==INT_MAX)
            return -1;
        else
        return mi;
    }
};