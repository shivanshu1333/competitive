class Solution {
public:
    #define f first
    #define s second
    typedef pair<int, pair<int, int>> pii;
    struct comp{
        bool operator()(pii a, pii b){
            return a.s.s>b.s.s;
        }    
    };
    
    int dijkstra(vector<vector<pair<int,int>>> &g, int src, int d, int k){
        priority_queue<pii, vector<pii>, comp > q;
        vector<bool> vis(g.size(), 0);
        q.push({-1, {src, 0}}); 
        
        while(!q.empty()){
            pii tp = q.top();
            q.pop();
            vis[tp.s.f]=1;
            if(tp.s.f==d) return tp.s.s;
            for(int i=0;i<g[tp.s.f].size();i++)
                if(!vis[g[tp.s.f][i].f] && tp.f+1<=k)
                    q.push({tp.f+1, {g[tp.s.f][i].f, tp.s.s+g[tp.s.f][i].s}});
        }
        return -1;
} 
    
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        if(src==dst) return 0;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<f.size();i++)
            g[f[i][0]].push_back({f[i][1], f[i][2]});
        return dijkstra(g, src, dst, k);
    }
};