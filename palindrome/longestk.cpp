int slide(string &st, int k){
    int s=0, e=0;
    unordered_map<char, int> m;
    int ml=0;
    while(e<st.length()){
        m[st[e]]++;
        while(m.size()>k){
            m[st[s]]--;
            if(m[st[s]]==0)
                m.erase(st[s]);
            s++;
        }
        if(m.size()==k) //for exactly k
            ml=max(ml, e-s+1);
        e++;
    }
    return ml;
}
