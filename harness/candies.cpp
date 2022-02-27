#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define f first
#define s second

int pa[1000];

int find(int i){
    while(pa[i] != i){
        pa[i] = pa[pa[i]];
        i = pa[i];
    }
return i;
}
void unio(int A, int B){
    int root_A = find(A);
    int root_B = find(B);
    if(root_A<root_B){
        pa[root_A] = pa[root_B];
    }
    else
        pa[root_B] = pa[root_A];
}

int process(vector<pii> & edg, int n){
    for(int i=0;i<1000;i++) pa[i]=i;
    for(int i=0;i<edg.size();i++){
        unio(edg[i].f, edg[i].s);
    }
    unordered_map<int, vi> m;
    for(int i=1;i<=n;i++){
        m[find(i)].pb(i);
    }
    int ans=0;
    int msz=0;
    for(auto it=m.begin();it!=m.end();it++){
        int s=it->s.size();
        msz = max(s, msz);
    }
    for(auto it=m.begin();it!=m.end();it++){
        vi val=it->s;
        if(msz==val.size()){
            sort(val.begin(), val.end());
            if(val.size()<2) ans = max(ans, val[0]);
            else ans = max(ans, val[val.size()-1]*val[val.size()-2]);
        }
    }
    return ans;
}

int applyDSU(int n, vi &f, vi &t, vi &c){
    unordered_map<int, vector<pii> > m;
    for(int i=0;i<c.size();i++){
        m[c[i]].pb({f[i], t[i]});
    }
    int ans=n;
    for(auto it=m.begin();it!=m.end();it++){
        vector<pii> edg=it->s;
        ans = max(process(edg, n), ans);
    }
    return ans;
}

int main(){
    int N,n;
    cin>>N>>n;

    vi from(n), to(n), candy(n);
    for(int i=0;i<n;i++){
        int fr, t, cn;
        cin>>fr>>t>>cn;
        from[i]=fr;
        to[i]=t;
        candy[i]=cn;
    }
    cout<<applyDSU(N, from, to, candy)<<endl;
}