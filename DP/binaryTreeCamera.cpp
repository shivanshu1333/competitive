int ans;
int dfs(TreeNode* r){
    if(r==NULL) return 1;
    if(r->left==NULL && r->right==NULL) return 0;
    int lstate = dfs(r->left);
    int rstate = dfs(r->right);
    if(lstate==0||rstate==0){
        ans++;
        return 2;
    }
    if(lstate==2 || rstate==2)
        return 1;
    return 0;
}

int minCameraCover(TreeNode* r) {
    ans=0;
    if(dfs(r)==0) ans++;
    return ans;
}