#include <bits/stdc++.h>
using namespace std;

bool dfs(int c, vector<int> adj[], vector<int> &vis){
    bool ans = 0;
    if(vis[c]==1)
        return 1;
    vis[c]=1;
    for(int i=0;i<adj[c].size();i++){
        if(vis[adj[c][i]]!=2)
            ans = ans || dfs(adj[c][i], adj, vis);
    }
    vis[c]=2;
    return ans;
}

bool isCyclic(int v, vector<int> adj[]){
    vector<int> vis(v,0);
    bool ans=0;
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            ans = dfs(i, adj, vis);
        }
        if(ans==1)
            return 1;
    }
    return ans;
}

int main() {
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);	
	int t;
	cin >> t;	
	while(t--){
	    int v, e;
	    cin >> v >> e;
	    vector<int> adj[v];
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    cout << isCyclic(v, adj) << endl;
	}
	return 0;
}