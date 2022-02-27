
    TreeNode* dfs(TreeNode* root, int h, int height){
        if(root == NULL)   
            return NULL;
        if(h == height-1)
            return root;

        TreeNode* l = dfs(root->left, h+1, height);
        TreeNode* r = dfs(root->right, h+1, height);

        if(l!=NULL && r!=NULL)
            return root;

        return (l!=NULL) ? l:r;

    }

    int height(TreeNode* root, int h){
        if(root==NULL)
            return h;
        return max(height(root->left,h+1), height(root->right,h+1));
    }