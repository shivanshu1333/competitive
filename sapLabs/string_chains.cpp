//String Chains, given a dict and start word and end word

unordered_map<string, int> m;
unordered_set<string> s;

int memo(string a){
    if(m.count(a)) return m[a];
    int ans=1;
    for(int i=0;i<a.length();i++){
        string tmp=a;
        tmp.erase(i,1);
        if(s.count(tmp))
            ans = max(ans,1+memo(tmp));
    }
    m[a]=ans;
    return m[a];
}

int longestStrChain(vector<string>& w) {
    m.clear(); s.clear();int ans = 0;
    for(int i=0;i<w.size();i++) s.insert(w[i]);
    for(int i=0;i<w.size();i++) ans = max(memo(w[i]), ans);            
    return ans;
}