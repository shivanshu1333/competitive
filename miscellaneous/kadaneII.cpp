int maximumSum(vector<int>& v){
    int ans = 0, n = v.size();
    int cm = v[0], gm = v[0];
    vector<int> L(n);
    vector<int> R(n);
    L[0] = v[0];
    for(int i = 1; i < n; i++){
        cm = max(v[i], cm + v[i]); 
        gm = max(gm, cm); 
        L[i] = cm; 
    }
    cm = gm = R[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--){
        cm = max(v[i], cm + v[i]); 
        gm = max(gm, cm); 
        R[i] = cm; 
    }
    ans = gm;
    for(int i = 1; i < n - 1; i++)
        ans = max(ans, L[i - 1] + R[i + 1]);
    return ans;
}