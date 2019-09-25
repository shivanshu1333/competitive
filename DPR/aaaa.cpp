    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    int n,q,a,b,p,x;
    cin>>n>>q;
    vector<int> g[n+1];
    for(int i=0;i<n-1;i++){
    cin>>a>>b;
    g[a].push_back(b);
    }
    vector<int> inc(n+1,0);
    while(q--){
        cin>>p>>x;
        inc[p]+=x;
    }
    queue<int> qq;

    for(int i=0;i<n+1;i++){
        if(g[i].size()>0){
            qq.push(i);
            break;
        }
    }

    // qq.push(1);
    while(!qq.empty()){
        int t=qq.front();
        qq.pop();
        for(int i=0;i<g[t].size();i++){
            int u=g[t][i];
            qq.push(u);
        }
        if(inc[t]==0){
            continue;
        }
        int ct=inc[t];
        for(int i=0;i<g[t].size();i++){
            int u=g[t][i];
            inc[u]+=ct;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<inc[i]<<" ";
    }
    cout<<endl;
    return 0;
    }