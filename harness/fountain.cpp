int fountainActivation(vi v) {
    int n = v.size();
    vi dp(n, 0);
    for (int i = 0; i < n; i++) {
        int lv = max(i - v[i], 0);
        int rv = min(i + (v[i] + 1), n);
        dp[lv] = max(dp[lv], rv);
    }
    int ans = 1,rv = dp[0], nrv = 0;
    for (int i = 0; i < n; i++) {
        nrv = max(nrv, dp[i]);
        if (i == rv) {
            ans++;
            rv = nrv;
        }
    }
    return ans;
}