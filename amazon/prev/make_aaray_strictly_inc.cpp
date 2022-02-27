int rec(vector<int> &a, vector<int> &v, int i, int j){
    if(j>=v.size()) return 0;
    if(i==a.size()-1) return 1;
    
    if(a[i]<a[i+1]){
        rec(a, v, i+1, j), rec(a, )
    }
    
}

int makeArrayIncreasing(vector<int>& a, vector<int>& a2) {
    set<int> s;
    for(int i=0;i<a2;i++)
        s.insert(a2[i]);
    vector<int> v;
    for(auto it=s.begin();it!=s.end();it++)
        v.push_back(*it);
    
    rec(a, v, 0, 0);
}