bool dfs(int c, int p, vector<int> adj[], int V, vector<bool> &vis){
    bool ans=0;
    vis[c]=1;
    for(int i=0;i<adj[c].size();i++){
        if(!vis[adj[c][i]])
            ans = ans||dfs(adj[c][i], c, adj, V, vis);
        else if(adj[c][i]!=p)
            return 1;
    }
    return ans;
}

bool isCyclic(vector<int> adj[], int V){
    vector<bool> vis(V, 0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            if(dfs(i, -1, adj, V, vis)==1)
                return 1;
        }
    }
    return 0;
}