Node* lca(Node* root, int a, int b){

    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    Node *l = lca(root->left, a, b);
    Node *r = lca(root->right, a, b);

    if(l!=NULL && r!=NULL)
        return root;

    return (l!=NULL) ? l:r;
}

