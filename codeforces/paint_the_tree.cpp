#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void dfs(vvi &g, int i, vi &lg, int p){
    if (i==0) return;
    lg.pb(i);
    for(int k=0;k<g[i].size();k++)
        if(g[i][k]!=p)
            dfs(g, g[i][k], lg, i);
}

int main(){
    int n;
    cin>>n;
    vi in(n+1, 0);
    vvi g(n+1);
    int u, v;
    bool fl=0;
    vvi c(3, vi (n+1, 0));
    for(int i=1;i<=n;i++) cin>>c[0][i];
    for(int i=1;i<=n;i++) cin>>c[1][i];
    for(int i=1;i<=n;i++) cin>>c[2][i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        
        g[u].pb(v);
        g[v].pb(u);
        in[u]++;
        in[v]++;
        if(in[u]>2 || in[v]>2) {
            fl=1;
        }
    }
    vi lg;
    int st;
    if(fl) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++){
            if(in[i]==1){
                st=i;
                break;
            }
        }
        dfs(g, st, lg, -1);
        long long ans=1e18;
        vi av;
        vector<int> per = {0,1,2};
        do{
            long long t=0;
            int ch=0;
            for(int i=0;i<lg.size();i++){
                t+=c[per[ch]][lg[i]];
                ch = (ch+1)%3;
            }
            if(ans>t){
                ans=t;
                av=per;
            }
        }while(next_permutation(per.begin(), per.end()));
        cout<<ans<<endl;
        int ch=0;
        vector<int> an(n+1);
        for(int i=0;i<lg.size();i++){
            an[lg[i]] = av[ch]+1;
            ch = (ch+1)%3;
        }
        for(int i=1;i<=n;i++)
            cout<<an[i]<<" ";
        cout<<endl;
    }


}