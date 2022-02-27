#define ll long long
int mod = 1000000007;
    
ll rec(ll n, vector<ll> &dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    ll ans=0;
    for(ll i=0;i<=n-1;i++)
        ans=((ans+((rec(i, dp)%mod+mod)%mod)*(((rec(n-i-1, dp)%mod)+mod)%mod)%mod)+mod)%mod;
    dp[n]=ans;
    return dp[n];
}
    
int Solution::chordCnt(int A) {
    vector<ll> dp(A+1, -1);
    return rec(A, dp);
}