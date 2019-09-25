#include<bits/stdc++.h>
using namespace std;

void dfs(int c, int p, vector<vector<int>> &g, vector<int> &cst){
    cst[c]+=cst[p];
    for(int i=0;i<g[c].size();i++){
        if(g[c][i]==p) continue;
        dfs(g[c][i], c, g, cst);
    }
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int v,q;
    cin>>v>>q;
    vector<vector<int>> g(v+1);
    vector<int> cst(v+1, 0);
    int a,b;
    for(int i=1;i<v;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        cin>>a>>b;
        cst[a]+=b;
    }
    dfs(1, 0, g, cst);
    for(int i=1;i<cst.size();i++)
        cout<<cst[i]<<" ";
    cout<<endl;
}