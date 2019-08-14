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