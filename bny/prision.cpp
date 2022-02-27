#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll prision(int n, int m, int x, int y, vector<int> h, vector<int> v){
    vector<int> hps(n+1, 0), vps(m+1, 0);
    for(int i=0;i<h.size();i++) hps[h[i]]=1;
    for(int i=0;i<v.size();i++) vps[v[i]]=1;
    ll hv=0,vv=0;
    for(int i=1;i<hps.size();i++){
        hps[i] += hps[i-1];
        if(hps[i]>hv)
            hv = hps[i];
    }
    for(int i=1;i<vps.size();i++){
        vps[i] += vps[i-1];
        if(vps[i]>vv)
            vv = vps[i];
    }
    return (vv+1)*(hv+1);
}

int main(){
    int n, m;
    cin>>n>>m;
    int x,y;
    cin>>x;
    vector<int> h(x);
    for(int i=0;i<x;i++) cin>>h[i];
    cin>>y;
    vector<int> v(y);
    for(int i=0;i<y;i++) cin>>v[i];
    cout<<prision(n, m, x, y, h, v);
}