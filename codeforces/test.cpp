#include <bits/stdc++.h>
using namespace std;

int done[101];
int dfs(int c,vector<int> adj[]){
    done[c]=1;
    for(int i=0;i<adj[c].size();i++){
        int v=adj[c][i];
        if(done[v]==1){
            return 1;
        }
        if(done[v]==2){
            continue;
        }
        if(dfs(v,adj)){
            return 1;
        }
    }
    done[c]=2;
    return 0;
}
bool isCyclic(int V, vector<int> adj[]){
    memset(done,0,sizeof(done));
    for(int i=0;i<V;i++){
        if(done[i]!=2){
            if(dfs(i,adj)){
                return true;
            }
            done[i]=2;
        }
    }
    return false;
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