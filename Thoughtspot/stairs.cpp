#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int mod = 1e9+7;

int q(int B, int c, vvi &dp){
    if(c==0) return 1;
    if(c<0) return 0;
    if(dp[B][c]!=-1) return dp[B][c];
    ll o = q(B, c-1, dp);
    ll t = q(B, c-2, dp);
    ll th = 0;
    if(B>0)
        th = q(B-1, c-3, dp);
    dp[B][c] = (o%mod+t%mod+th%mod + mod)%mod;
    return dp[B][c];
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int A, B;
        cin>>A>>B;
        ll ans = 0;
        ans = q(B, A, dp);
        cout<<ans<<endl;
    }
}