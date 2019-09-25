#include<bits/stdc++.h>
using namespace std;

bool bfs(int s, int d, vector<vector<bool>> &g, vector<bool> &vis, int &dis){
    queue<short int> q;
    q.push(1);
    vis[1]=1;
    int l=-1;
    int noc;
    while(!q.empty()){
        noc = q.size();
        l++;
        while(noc>0){
            int tc = q.front();
            q.pop();
            noc--;
            if(tc==d){
                dis=l;
                return 1;
            }
            for(int i=1;i<g.size();i++){
                if(vis[i]==0 && g[tc][i]==1){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
    }
    return 0;
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int v;
    int e;
    cin>>v>>e;
    if(e==v*(v-1)/2){
        cout<<-1<<endl;
    }
    else{
        vector<vector<bool>> gt(v+1, vector<bool> (v+1, 0));
        vector<vector<bool>> gr(v+1, vector<bool> (v+1, 1));
        vector<bool> vis(v+1, 0);
        vis[0]=1;
        for(int i=0;i<=v;i++){
            for(int j=0;j<=v;j++){
                if(i==j || i==0 || j==0)
                    gr[i][j]=0;
            }
        }
        int u, z;
        for(int i=0;i<e;i++){
            cin>>u>>z;
            gt[u][z]=1;
            gt[z][u]=1;
            gr[u][z]=0;
            gr[z][u]=0;
        }
        int dist = INT_MAX;
        int disr = INT_MAX;
        if(bfs(1, v, gt, vis, dist)){
            for(int i=1;i<=v;i++)
                    vis[i]=0;
            if(bfs(1, v, gr, vis, disr)){
                cout<<max(dist, disr)<<endl;;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
}