#define pb push_back

void leaf(Node* rt){
    if(rt==NULL) return;
    leaf(rt->left);
    if(rt->left==NULL && rt->right==NULL) cout<<rt->data<<" ";
    leaf(rt->right);
}

void right(Node *rt){
    if(rt==NULL) return;
    if(rt->right!=NULL){
        right(rt->right);
        cout<<rt->data<<" ";
    }
    else if(rt->left!=NULL){
        right(rt->left);
        cout<<rt->data<<" ";
    }
}

void left(Node *rt){
    if(rt==NULL) return;
    if(rt->left!=NULL){
        cout<<rt->data<<" ";
        left(rt->left);
    }
    else if(rt->right!=NULL){
        cout<<rt->data<<" ";
        left(rt->right);        
    }
}

void printBoundary(Node *rt){
    if(rt==NULL) return;
    cout<<rt->data<<" ";
    left(rt->left);
    leaf(rt->left);
    leaf(rt->right);
    right(rt->right);
}