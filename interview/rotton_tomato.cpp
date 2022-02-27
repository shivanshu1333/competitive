#include <bits/stdc++.h>
using namespace std;

int x[4] = {1,-1,0,0};
int y[4] = {0, 0,-1,1};

int bfs(vector<vector<int>> &g){
    vector<vector<bool>> vis(g.size(), vector<bool> (g[0].size(), 0));
    queue<pair<int, int>> q;
    int cnt=0;
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            if(g[i][j]==2){
                vis[i][j]=1;
                q.push({i, j});
            }
            if(g[i][j]==1) cnt++;
        }
    }
    int nc,l=1, no=0;
    if(no==cnt) return 0;
    while(!q.empty()){
        nc = q.size();
        while(nc>0){
            pair<int, int> tp = q.front();
            q.pop();
            nc--;
            for(int i=0;i<4;i++){
                int xx = tp.first+x[i];
                int yy = tp.second+y[i];
                if(xx>=0 && yy>=0 && xx<g.size() && yy<g[0].size() && g[xx][yy]==1 && vis[xx][yy]==0){
                    no++;
                    if(no==cnt) return l;
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
        l++;
    }
    return-1;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> g(r, vector<int> (c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>g[i][j];
            }
        }
        // int ans=0;
        int ans = bfs(g);
        cout<<ans<<endl;
    }
}