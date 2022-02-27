#include<bits/stdc++.h>
using namespace std;

bool dfs(int s, int p, vector<int> adj[], vector<bool> &vis){
    bool ans = 0;
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++){
        if(!vis[adj[s][i]])
        ans = ans || dfs(adj[s][i], s, adj, vis);
        else if(adj[s][i] != p)
            return 1;
    }
    return ans;
}
bool isCyclic(vector<int> adj[], int V){
    vector<bool> vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0)
            if(dfs(i, -1, adj, vis))
                return 1;
    }
    return 0;
}

int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        int V, E;
        cin>>V>>E;
        vector<int> adj[V];
        int u, v;
        for(int i=0;i<E;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}