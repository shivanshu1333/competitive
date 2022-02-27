int countkDist(string s, int k) {
    int n = s.length(); 
    int ans = 0;  
    int cnt[26]; 
    for (int i = 0; i < n; i++) {
        int dist_count = 0; 
        memset(cnt, 0, sizeof(cnt)); 
        for (int j=i; j<n; j++) {
            if (cnt[s[j] - 'a'] == 0) 
                dist_count++; 
            cnt[s[j] - 'a']++; 
            if (dist_count == k) 
                ans++; 
            if(dist_count > k) break; 
        } 
    } 
    return ans; 
} 