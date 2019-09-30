int fd(Node* root, int &dia){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int ld = fd(root->left, dia);
    int rd = fd(root->right, dia);
    dia = max(dia, ld+rd+1);
    return max(ld, rd)+1;
}

int diameter(Node* node){
    int dia=0;
    fd(node, dia);
    return dia;
}