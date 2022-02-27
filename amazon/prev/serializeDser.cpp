void serialize(Node *root, FILE *fp){
    if (root == NULL) return;
    fprintf(fp, "%c ", root->key);
    for (int i = 0; i < N && root->child[i]; i++)
         serialize(root->child[i],  fp);
    fprintf(fp, "%c ", MARKER);
}
int deSerialize(Node *&root, FILE *fp){
    char val;
    if ( !fscanf(fp, "%c ", &val) || val == MARKER )
       return 1;
    root = newNode(val); 
    for (int i = 0; i < N; i++) 
      if (deSerialize(root->child[i], fp)) 
         break;
    return 0; 
} 