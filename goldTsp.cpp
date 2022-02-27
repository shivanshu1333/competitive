#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define rp pop_back
#define ll long long
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
int N;
ll ans;

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

bool isSafe(vvi &g, vvi &vis, int i, int j){
    return ((i>=0) && (j>=0) && (i<N) && (j<N) && (g[i][j]!=-1) && (vis[i][j]==0));
}

void find(vvi &cost, vi &coins){
    do{
        ll cst=cost[1][coins[0]];
        cst += cost[coins[coins.size()-1]][N*N];
        for(int i=1;i<coins.size();i++)
            cst+= cost[coins[i-1]][coins[i]];
        ans = min(ans, cst);
    }while(next_permutation(coins.begin(), coins.end()));
}

void bfs(vvi &g, int i, int j, vvi &cost){
    queue<pii> q;
    q.push({i, j});
    vvi vis(N, vi (N, 0));
    vis[i][j]=1;
    int l=0;
    int nc=0;
    while(!q.empty()){
        nc = q.size();
        while(nc>0){
            pii tp = q.front();
            q.pop();
            nc--;
            int r=tp.f;
            int c=tp.s;
            cost[i*N+j+1][r*N+c+1]=l;
            cost[r*N+c+1][i*N+j+1]=l;
            for(int k=0;k<4;k++){
                if(isSafe(g, vis, x[k]+r, y[k]+c)){
                    q.push({x[k]+r, y[k]+c});
                    vis[x[k]+r][y[k]+c]=1;
                }
            }
        }
        l++;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        vector<string> cg(N);
        for(int i=0;i<N;i++) cin>>cg[i];
        vvi g(N, vi(N, 0));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(cg[i][j]=='.') g[i][j]=0;
                else if(cg[i][j]=='*') g[i][j]=1;
                else if(cg[i][j]=='#') g[i][j]=-1;
            }
        }
        int val;
        vi coins;
        vvi cost(N*N+1, vi(N*N+1, INT_MAX));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                val = i*N+j+1;
                if(val==1 || val==(N*N) || g[i][j]==1){
                    bfs(g, i, j, cost);
                }
                if(g[i][j]==1) coins.pb(i*N+j+1);
            }
        }
        ans = INT_MAX;
        find(cost, coins);
        if(ans>=INT_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}