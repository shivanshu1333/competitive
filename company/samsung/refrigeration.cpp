#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

void backTrack(vector<pair<int, int>> &v, int &ans, vector<bool> &vis, int &hx, int &hy, int cur, int ind, int nodes){
    if(nodes==v.size()-1){
        ans = min(ans, cur+abs(v[ind].f-hx)+abs(v[ind].s-hy));
        return;
    }
    for(int i=1;i<v.size();i++){
        if(!vis[i]){
            vis[i]=1;
            cur+=abs(v[ind].f-v[i].f)+abs(v[ind].s-v[i].s);
            backTrack(v, ans, vis, hx, hy, cur, i, nodes+1);
            cur-=abs(v[ind].f-v[i].f)+abs(v[ind].s-v[i].s);
            vis[i]=0;
        }
    }

}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> v(n+1);
    vector<bool> vis(n+1, 0);
    int hx, hy, ox, oy;
    cin>>hx>>hy>>ox>>oy;
    v[0]={ox, oy};
    int x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        v[i]={x,y};
    }
    int ans = INT_MAX;
    backTrack(v, ans, vis, hx, hy, 0, 0, 0);
    cout<<ans<<endl;
}

class Solution {
private:
    int dfs(int i, int depth, int n_1, vector<vector<int>>& graph, vector<bool>& visited){
        int maxDepth = depth;
        visited[i] = true;
        
        for(int j : graph[i]){
            if(!visited[j]){
                maxDepth = max(maxDepth, dfs(j, depth + 1, n_1, graph, visited));
                // Can't be deeper
                if(maxDepth == n_1)
                    return maxDepth;
            }
        }
        
        visited[i] = false;
        return maxDepth;
    }
    
    int shortestPathLength(vector<vector<int>>& graph, int start, int n){
        vector<bool> visited(n, false);
        int maxDepth = dfs(start, 0, n - 1, graph, visited);
        return 2 * (n - 1) - maxDepth;
    }
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        int n_1 = n - 1;
        int minLen = INT_MAX;
        for(int i = 0; i < n; ++i){
            minLen = min(minLen, shortestPathLength(graph, i, n));
            // Can't be shorter
            if(minLen == n_1)
                return minLen;
        }
        return minLen;
    }
};

