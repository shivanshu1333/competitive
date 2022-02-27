#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
#define pb push_back
int cnt;
int edg;

void dfs(vvi &g, int cn, int p){
    cnt++;
    edg += g[cn].size();
    for(int i=0;i<g[cn].size();i++){
        if(g[cn][i]==p) continue;
        dfs(g, g[cn][i],cn);
    }
}

ll find(int A, int B, vvi &C, int D, int E){
    vvi g(A+1);
    for(int i=0;i<B;i++){
        g[C[i][0]].pb(C[i][1]);
        g[C[i][1]].pb(C[i][0]);
    }
    cnt=0;
    edg=0;
    dfs(g, D, -1);
    ll g1 = cnt;
    ll e1 = edg/2;
    cnt = 0;
    edg = 0;
    dfs(g, E, -1);
    ll g2 = cnt;
    ll e2 = edg/2;
    ll rm = A-g1-g2;
    ll re = B-e1-e2;

    ll ans = g1*(g1-1)/2 - e1 + g2*(g2-1)/2 - e2 + rm*(rm-1)/2 - re + max(g1, g2)*rm;
    return ans;
}

int main(){
    int A, B, D, E;
    cin>>A>>B;
    vvi C(B, vi(2, 0));
    int u,v;
    for(int i=0;i<B;i++){
        cin>>u>>v;
        C[i][0]=u;
        C[i][1]=v;
    }
    cin>>D>>E;
    cout<<find(A, B, C, D, E)<<endl;
}