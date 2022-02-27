class Solution {
public:
    typedef pair<int,int> pii;
    #define f first
    #define s second    
    vector<vector<int>> merge(vector<vector<int>>& I) {
        vector<vector<int>> ans;
        if(I.size()==0||I[0].size()==0) return ans;
        vector<pii> g;
        for(int i=0;i<I.size();i++) g.push_back({I[i][0], I[i][1]});
        sort(g.begin(), g.end());
        int sv=g[0].f;
        int ev=g[0].s;
        int l=0,r=0;
        while(r<g.size()){
            if(g[r].f<=ev){
                ev=max(ev, g[r].s);
                r++;
            }
            else{
                ans.push_back({sv,ev});
                sv=g[r].f;
                ev=g[r].s;
                l=r;
            }
        }
        ans.push_back({sv,ev});
        return ans;
    }
};