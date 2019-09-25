#include<bits/stdc++.h>
using namespace std;
void topoSort(int v, vector<vector<int>> &g{
    vector<int> in_deg(v+1, 0);
    vector<int> topo;
    for(int i=1;i<=v;i++){
        for(int j=0;j<g[i].size();j++){
            in_deg[g[i][j]]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1;i<=v;i++)
        if(in_deg[i]==0)
            q.push(i);
    int cnt=0;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        topo.push_back(u);
        cnt++;
        for(int i=0;i<g[u].size();i++){
            in_deg[g[u][i]]--;
            if(in_deg[g[u][i]]==0)
                q.push(g[u][i]);
        }
    }
    if(cnt!=v){
        cout<<"Sandro fails."<<endl;
    }
    for(int i=0;i<topo.size();i++)
        cout<<topo[i]<<" ";
    cout<<endl;
}

int main(){
    int N,E;
    cin>>N>>E;
    int u,v;
    vector<vector<int>> g(N+1);
    for(int i=1;i<=E;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    topoSort(N, g);
}