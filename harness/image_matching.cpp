#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int id;

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

bool isSafe(vvi &g, vector<vector<bool>> &vis, int i, int j){
    return (i>=0) && (j>=0) && (i<g.size()) && (j<g[0].size()) && (!vis[i][j]) && (g[i][j]!=0);
}

void dfs(vvi &g, vector<vector<bool>> &vis, int i, int j, bool &fl){
    vis[i][j]=1;
    if(g[i][j] != id) fl=0;
    for(int k=0;k<4;k++){
        int ii = i+x[k], jj = j+y[k];
        if(isSafe(g, vis, ii, jj))
            dfs(g, vis, ii, jj, fl);
    }
}

int find(vvi &a, vvi &b){
    vvi g=a;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            g[i][j] = g[i][j] + b[i][j];

    int ans=0;
    vector<vector<bool>> vis(g.size(), vector<bool> (g[0].size(), 0));
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            if((!vis[i][j]) && (g[i][j]!=0)){
                bool fl=1;
                id=g[i][j];
                dfs(g, vis, i, j, fl);
                if(fl) ans++;
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi im1(n, vi (m, 0)), im2(n, vi(m, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>im1[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>im2[i][j];
    cout<<find(im1, im2)<<endl;
}