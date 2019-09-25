void topo(vector<vector<int>> &g){
    int v = g.size();
    vector<int> in_deg(v, 0);

    for(int i=0;i<v;i++){
        for(int j=0;j<g[i].size();j++){
            in_deg[g[i][j]]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++)
        if(in_deg[i]==0)
            q.push(i);
    int cnt=0;
    vector<int> topo;
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
        topo.clear();
        //cycle exits
    }
    for(int i=0;i<topo.size();i++)
        cout<<topo[i]<<" ";
    cout<<endl;
}