#include<iostream>
#include<vector>
#include<stack>

using namespace std;
// Recursive dfs
void dfs(int s, vector<vector<int>> &g, vector<bool> &vis){
    cout<<s<<" ";
    vis[s] = 1;
    for(int i=0;i<g[s].size();i++){
        if(!vis[g[s][i]]){
            // vis[g[s][i]] = 1;
            dfs(g[s][i], g, vis);
        }
    }
    return;
}

// Iterative dfs
void dfs_(int s, vector<vector<int>> &g, vector<bool> &vis){
    stack<int> stk;
    stk.push(s);
    vis[s] = 1;
    while(!stk.empty()){
        int p = stk.top();
        stk.pop();
        cout<<p<<" ";
        // if (!vis[p]){
        //     cout << p << " "; 
        //     vis[p] = 1; 
        // } 
        for(int i=0;i<g[p].size();i++){
            if(!vis[g[p][i]]){
                vis[g[p][i]] = 1;
                stk.push(g[p][i]);
            }
        }
    }
    return;
}


int main(){
    int N,E; // no of vertices, edge
    cin>>N>>E;

    vector<bool> vis (N,0);
    vector<vector<int>> g(N);

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // vis[0]=1;
    dfs(0,g,vis);

}