#include<iostream>
#include<vector>
// #include<map>
// #include<climits>
// #include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
// #include<queue>
// #include<utility>
// #include <fstream>
// #include <set>
using namespace std;

int dfs(int c, int p, vector<vector<pair<int, int>>> &g, vector<int> &ans){
    int plc=0;
    for(int i=0;i<g[c].size();i++){
        if(g[c][i].first==p) continue;
        int clc = dfs(g[c][i].first, c, g, ans);
        if(clc==0 && g[c][i].second == 2){
            clc++;
            ans.push_back((g[c][i].first)+1);
        }
        plc+=clc;
    }
    return plc;
}

int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> ans;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int ch = dfs(0, -1, g, ans);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}