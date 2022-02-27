

TreeNode* LCA(TreeNode* root, int A, int B){
    if(root == NULL)
        return NULL;
    if(root->data > A && root->data > B)
        return LCA(root->left, A, B);
    if(root->data < A && root->data < B)
        return LCA(root->right, A, B);
    return root;
}