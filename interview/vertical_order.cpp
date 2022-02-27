void verticalOrder(Node *root){
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    int nc;
    while(!q.empty()){
        nc=q.size();
        while(nc>0){
            pair<Node*, int> tp = q.front();
            q.pop();
            nc--;
            Node* rt = tp.f;
            int l = tp.s;
            mp[l].pb(rt->data);
            if(rt->left!=NULL) q.push({rt->left, l-1});
            if(rt->right!=NULL) q.push({rt->right, l+1});
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int> temp = it->s;
        for(int i=0;i<temp.size();i++) cout<<temp[i]<<" ";
    }
}