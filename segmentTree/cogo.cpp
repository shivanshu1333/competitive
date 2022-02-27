#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef unordered_map<int, int> uii;
typedef pair<int, int> pii;
int NN=1000001;
vector<int> V(NN);//a
vector<int> W(NN);
vector<int> type(NN);
vector<int> ui(NN);
vector<int> uv(NN);
vector<int> L(NN);
vector<int> R(NN);
vector<int> fw(NN);
vector<uii> t(4000001);

uii compare(uii a, uii b){
    uii ans;
    int key;
    int x;
    int y;
    for(auto it=a.begin();it!=a.end();it++){
        key=a[it->f];
        if(!b.count(key)) ans[key]=a[it->s];
        else{
            x = __builtin_popcount(a[it->s]);
            y = __builtin_popcount(b[it->s]);
            if(x>y) ans[key]=a[it->s];
            else ans[key]=b[it->s];
        }
    }
    for(auto it=b.begin();it!=b.end();it++){
        key=b[it->f];
        if(!ans.count(key)) ans[key]=b[it->s];
    }
    return ans;
}

void build(int v, int tl, int tr){
    if(tl==tr)
        t[v][W[tl]]=V[tl];
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = compare(t[v*2], t[2*v+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val, int key){
    if(tl==tr) t[v][key]=new_val;
    else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(v*2, tl, tm, pos, new_val, key);
        else
            update(v*2, tm+1, tr, pos, new_val, key);
        t[v] = compare(t[v*2], t[v*2+1]);
    }
}

int find(int v, int tl, int tr, int l, int r, int key){
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v][key];
    int tm = (tl+tr)/2;
    int lmv = find(v*2, tl, tm, l, min(r,tm), key);
    int rmv = find(v*2+1, tm+1, tr, max(l, tm+1), r, key);
    return max(lmv, rmv);
}

void solve(int N, int Q){
    build(1, 0, N-1);
    for(int i=1;i<=Q;i++){
        if(type[i]==1)
            update(1, 0, N-1, ui[i], uv[i], W[i]);
        else
            cout<<find(1, 0, N-1, L[i], R[i], fw[i])<<" ";
    }
}


int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    for(int i=0;i<4000001;i++) t[i]={};
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>V[i]>>W[i];
    }
    int Q;
    cin>>Q;
    
    for(int i=1;i<=Q;i++){
        cin>>type[i];
        if(type[i]==1){
            cin>>ui[i];
            cin>>uv[i]; 
        }
        else{
            cin>>L[i];
            cin>>R[i];
            cin>>fw[i];  
        }
    }

    solve(N, Q);
}
