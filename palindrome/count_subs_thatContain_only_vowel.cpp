int countSubstringsUtil(string s) {
    int count = 0; 
    // Map is used to store count of each vowel 
    map<char, int> mp; 
    int n = s.length(); 
    // Start index is set to 0 initially 
    int start = 0; 
    for (int i = 0; i < n; i++) { 
        mp[s[i]]++; 
        // If substring till now have all vowels 
        // atleast once increment start index until 
        // there are all vowels present between 
        // (start, i) and add n - i each time 
        while (mp['a'] > 0 && mp['e'] > 0 
               && mp['i'] > 0 && mp['o'] > 0 
               && mp['u'] > 0) { 
            count += n - i; 
            mp[s[start]]--; 
            start++; 
        } 
    } 
    return count; 
} 