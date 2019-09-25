bool dfs(int s, vector<int> adj[], vector<int> &vis, int V){
    if(vis[s]==1)
        return 1;
    vis[s]=1;
    bool ans=0;
    for(int i=0;i<adj[s].size();i++){
        ans = ans||dfs(adj[s][i], adj, vis, V);
    }
    vis[s]=2;
    return ans;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            if(vis[adj[i][j]]==0){
                if(dfs(adj[i][j], adj, vis, V))
                    return 1;
            }
        }
    }
    return 0;
}