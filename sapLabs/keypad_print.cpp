vector<string> v = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> an;
    void q(int n, string s){
        if(n==0){
            string t = s;
            reverse(t.begin(), t.end());
            an.push_back(t);
            return;
        }
        int sz = n%10 - 2;
        for(int i=0;i<v[sz].length();i++){
            q(n/10, s+v[sz][i]);
        }    
    }

    vector<string> letterCombinations(string s) {
        an.clear();
        if(s.length()==0) return an;
        int n = stoi(s);
        q(n, "");
        sort(an.begin(), an.end());
        return an;
    }