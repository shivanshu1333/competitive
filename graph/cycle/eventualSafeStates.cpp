class Solution {
public:
    int q(vector<vector<int>>& g, vector<int>& v, vector<int>& s, int i) {
        v[i] = 1;
        s.push_back(i);
        for (int j = 0; j < g[i].size(); j++) {
            if (v[g[i][j]] == 0) {
                int an = q(g, v, s, g[i][j]);
                if (an) return 1;
            } else if (v[g[i][j]] == 1) return 1;
        }
        v[i] = 2;
        s.pop_back();
        return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> v(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (v[i] == 2 || v[i] == 1) continue;
            vector<int> s;
            int c = q(g, v, s, i);
            if (c == 1) {
                for (int j : s) {
                    a[j] = 1;
                }
            }
        }
        vector<int> an;
        for (int j = 0; j < n; j++) {
            if (a[j] == 0) an.push_back(j);
        }
        sort(an.begin(), an.end());
        return an;
    }
};