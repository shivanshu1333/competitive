void bfs(TreeNode* root, vector<int> &v){
    if(root==NULL)
        return;
    queue<TreeNode*> q;
    q.push(root);
    int nc;
    TreeNode* p;
    while(!q.empty()){
        nc = q.size();
        while(nc>0){
            p = q.front();
            q.pop();
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            nc--;
            if(nc==0)
                v.push_back(p->val);
        }            
    }
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> v;
    bfs(root,v);
    return v;        
}