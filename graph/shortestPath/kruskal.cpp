/*
kruskal uses greedy approach by picking up the edges of least weight and adding them without creating a cycle as soon as we reaches V-1 edges


       <1>
  3 /   |   \ 1
<4>     | 10  <2>  
  2 \   |   / 4
       <3>
*/

bool comp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

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

int solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), comp);
    int e=0;
    int i=0;
    vector<int> pa(A+1,0);
    int cst=0;
    for(int i=0;i<pa.size();i++) pa[i]=i;
    while(e<(A-1)){
        if(find(pa, B[i][0])!=find(pa, B[i][1])){
            cst+=B[i][2];
            unio(pa, B[i][0], B[i][1]);
            e++;
        }
        i++;
    }
    return cst;
}
