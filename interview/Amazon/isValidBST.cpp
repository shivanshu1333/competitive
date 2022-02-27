bool helper(Node* rt, Node* mv, Node* mx){
    if(rt==NULL) return 1;
    if((mv!=NULL && rt->data <= mv->data) || (mx!=NULL && rt->data >= mx->data)) return 0;
    return helper(rt->left, mv, rt) && helper(rt->right, rt, mx);
}

bool isBST(Node* rt) {
    return helper(rt, NULL, NULL);
}