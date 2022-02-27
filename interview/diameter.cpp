int dia;
int fd(Node* rt){
    if(rt==NULL) return 0;
    int lv = fd(rt->left);
    int rv = fd(rt->right);
    dia = max(dia, lv+rv+1);
    return max(lv, rv)+1;
}
int diameter(Node* rt){
    dia=0;
    fd(rt);
    return dia;
}