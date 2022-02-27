int Solution::solve(string A, string B, vector<string> &C) {
    if(A==B) return 0;
    queue<string> q;
    q.push(A);
    int l=1;
    int nc=0;
    unordered_set<string> s;    
    for(int i=0;i<C.size();i++) s.insert(C[i]);
    unordered_set<string> vis;
    vis.insert(A);
    while(!q.empty()){
        nc=q.size();
        l++;
        while(nc>0){
            string tp=q.front();
            q.pop();
            nc--;
            if(tp==B) return l;
            for(int i=0;i<tp.length();i++){
                for(int j=0;j<26;j++){
                    string tmp = tp;
                    tmp[i]=(char)((int)'a'+j); // gives lowercase alphabets from a to z
                    if(tmp==B){
                        return l;
                    } 
                    if(s.count(tmp) && !vis.count(tmp)){
                        vis.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
        }
    }
    return l;
}