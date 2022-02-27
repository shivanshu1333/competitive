#include<iostream>
#include<vector>
// #include<map>
// #include<climits>
// #include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>
// #include <fstream>
using namespace std;

void dfs(vector<vector<int>> &g, int c, int p,vector<int> &dis, int l){
    dis[c]=l;
    for(int i=0;i<g[c].size();i++){
        if(g[c][i]==p) continue;
        dfs(g, g[c][i], c, dis, l+1);
    }
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int v,b;
    cin>>v>>b;
    vector<vector<int>> g(v+1);
    for(int i=1;i<v;i++){
        int q,w;
        cin>>q>>w;
        g[q].push_back(w);
        g[w].push_back(q);
    }
    vector<int> ad(v+1),bd(v+1);
    dfs(g, 1, -1, ad, 0);
    dfs(g, b, -1, bd, 0);
    int ans = 0;
    for(int i=1;i<=v;i++){
        if(ad[i]>bd[i]){
            ans = max(ans, 2*ad[i]);
        }
    }
    cout<<ans<<endl;
}