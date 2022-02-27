// modified root function.

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
// this map will contain reprsentative of a set as key and value as no. of members in that set;
unordered_map<int, int> m;
for(int i=0;i<stones.size();i++){
    m[find(pa, stones[i][0])]++;
}
////////////////////////////////////////////////////////////////////////////
///////find all those edges which creates cycles
bool processEdge(vector<int> &pa, vector<int> &size, vector<vector<int>> &e){
    for(int i=0;i<e.size();i++){
        int u,v;
        u=e[i][0];
        v=e[i][1];
        if(find(pa, u)==find(pa, v))
            return 1;/// adding u v creates cycle
        else
            unio(pa, u, v);
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////
int find(vector<int> &pa ,int i){
    while(pa[i] != i){
        pa[i] = pa[pa[i]]; 
        i = pa[i]; 
    }
return i;
}

void unio(vector<int> &pa, vector<int> &size , int A, int B){
    int root_A = find(pa, A);
    int root_B = find(pa, B);
    if(size[root_A] < size[root_B ]){
        pa[root_A] = pa[root_B];
        size[root_B] += size[root_A];
    }
    else{
        pa[root_B] = pa[root_A];
        size[root_A] += size[root_B];
    }
}
