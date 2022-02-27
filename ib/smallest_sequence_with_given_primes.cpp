vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    res.push_back(1);
    int aa=0, bb=0, cc=0;
    int k=D;
    int tmp;
    while(k--){
        tmp = min(min(res[aa]*A, res[bb]*B), res[cc]*C);
        res.push_back(tmp);
        if(tmp==res[aa]*A) aa++;
        if(tmp==res[bb]*B) bb++;
        if(tmp==res[cc]*C) cc++;
    }
    vector<int> ans;
    for(int i=1;i<res.size();i++){
        ans.push_back(res[i]);
    }
    return ans;
}