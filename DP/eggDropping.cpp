class Solution {
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    Map<Integer, Integer> memo = new HashMap();
    public int dp(int K, int N) {
        if (!memo.containsKey(N * 100 + K)) {
            int ans;
            if (N == 0)
                ans = 0;
            else if (K == 1)
                ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2)
                        lo = x;
                    else if (t1 > t2)
                        hi = x;
                    else
                        lo = hi = x;
                }

                ans = 1 + Math.min(Math.max(dp(K-1, lo-1), dp(K, N-lo)),
                                   Math.max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo.put(N * 100 + K, ans);
        }

        return memo.get(N * 100 + K);
    }
}

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int eggDrop(int n, int k){
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for(int i=1;i<=k;i++)
        dp[1][i] = i;
    for(int i = 1;i<=n;i++)
        dp[i][1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            int res = INT_MAX;
            for(int l=1;l<=j;l++){
                res = min(res,(1+max(dp[i-1][l-1],dp[i][j-l])));
            }
            dp[i][j] = res;
        }
    }
    return dp[n][k];

}

int main(){
    int T;
    cin>>T;
    while(T--){
        int egg, k;
        cin>>egg>>k;
        cout<<eggDrop(egg,k)<<endl;
    }
}