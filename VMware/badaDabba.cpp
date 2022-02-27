int q(int n) {
    string s = to_string(n);
    map<char, int> m;
    for (char c : s) m[c] = 1;
    if (m.size() == s.length()) return 1;
    return 0;
}

// Complete the countNumbers function below.
void countNumbers(vector<vector<int>> arr) {
    vector<int> dp(pow(10, 6) + 1);
    for (int i = 1; i <= pow(10, 6); i++) {
        dp[i] = dp[i - 1];
        if (q(i)) dp[i]++;
    }
    for (vector<int> v : arr) {
        cout<<dp[v[1]] - dp[v[0] - 1]<<endl;
    }
}