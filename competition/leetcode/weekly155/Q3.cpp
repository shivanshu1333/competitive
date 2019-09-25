#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
// #define s second
vector<int> xr = {-2,-1,-2,-1,1,2,2,1};
vector<int> yc = {1,2,-1,-2,-2,-1,1,2};

void dfs(int i, vector<vector<int>> &g, vector<bool> &vis, vector<int> &ind, string &st, string &s){
    if(vis[i]==1) return;
    vis[i]=1;
    ind.push_back(i);
    st+=s[i];
    for(int k=0;k<g[i].size();k++){
        dfs(g[i][k], g, vis, ind, st, s);
    }
}
string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
    vector<vector<int>> g(s.length());
    for(int i=0;i<p.size();i++){
        g[p[i][0]].push_back(p[i][1]);
        g[p[i][1]].push_back(p[i][0]);
    }
    string ans=s;
    vector<bool> vis(s.length(), 0);
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            vector<int> ind;
            string st="";
            dfs(i, g, vis, ind, st, s);
            sort(ind.begin(), ind.end());
            sort(st.begin(), st.end());
            for(int k=0;k<ind.size();k++){
                ans[ind[k]]=st[k];
            }
        }
    }
    return ans;
}

int main(){
fast;
freopen("i.txt", "r", stdin);
freopen("o.txt", "w", stdout);
    string s;
    int n;
    cin>>s>>n;
    vector<vector<int>> pairs(n, vector<int> (2,0));
    for(int i=0;i<n;i++) cin>>pairs[i][0]>>pairs[i][1];
    cout<<smallestStringWithSwaps(s, pairs);
}

