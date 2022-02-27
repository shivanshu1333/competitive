#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef unsigned long long ll;

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    fast
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<ll>> dp(n+1, vector<ll> (3, ULLONG_MAX));
        vector<int> h(n+1, 0);
        vector<int> cst(n+1, 0);
        for(int i=1;i<=n;i++)
            cin>>h[i]>>cst[i];
        dp[1][0]=0; dp[1][1]=(ll)cst[1]; dp[1][2]=(ll)2*cst[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<=2;j++){
                if((h[i]+j)!=h[i-1])
                    dp[i][j] = min(dp[i][j], (ll)j*cst[i]+dp[i-1][0]);
                if((h[i]+j)!=(h[i-1]+1))
                    dp[i][j] = min(dp[i][j], (ll)j*cst[i]+dp[i-1][1]);
                if((h[i]+j)!=(h[i-1]+2))
                    dp[i][j] = min(dp[i][j], (ll)j*cst[i]+dp[i-1][2]);
            }
        }
        cout<<min(min(dp[n][0], dp[n][1]), dp[n][2])<<endl;
    }
}