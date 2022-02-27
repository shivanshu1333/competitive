Node* swapKth(Node *A, int n, int k){
    // edge cases #1 k>n, #2 same node, #3 adjacent node, #4 head change(k==1||k==n)
    if(k>n) return A;
    int fd = k, bd = n+1-k;
    if(fd==bd || A==NULL) return A;
    Node *f = A;
    Node *fp = NULL;
    int c=1;
    while(c<fd){
        c++;
        fp=f;
        f=f->next;
    }
    Node *b = A;
    Node *bp = NULL;
    c=1;
    while(c<bd){
        c++;
        bp = b;
        b = b->next;
    }
    //ratta
    if(fp!=NULL)
        fp->next = b;
    if(bp!=NULL)
        bp->next = f;
    Node *tmp = f->next;
    f->next=b->next;
    b->next=tmp;
    if(k==1)
        A=b;
    if(k==n)
        A=f;
    return A;
}