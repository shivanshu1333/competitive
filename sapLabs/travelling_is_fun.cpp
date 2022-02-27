int find(vector<int> &pa ,int i){
    while(pa[i] != i){
        pa[i] = pa[pa[i]]; 
        i = pa[i]; 
    }
return i;
}
void unio(vector<int> &pa, int A, int B){
    int root_A = find(pa, A);
    int root_B = find(pa, B);
    if(root_A<root_B){
        pa[root_A] = pa[root_B];
    }
    else
        pa[root_B] = pa[root_A];
}

vector <int> connectedCities(int n, int g, vector <int> oc, vector <int> dc) {
    vector<int> pa(n+1);
    for(int i=0;i<=n;i++) pa[i]=i;
    
    for(int i=g+1;i<=n;i++){
        for(int j=2;j*i<=n;j++){
            unio(pa, i, j*i);
        }
    }
    vector<int> ans(oc.size(), 0);
    for(int i=0;i<oc.size();i++){
        if(find(pa, oc[i])==find(pa, dc[i])) ans[i]=1;
    }
    return ans;
}