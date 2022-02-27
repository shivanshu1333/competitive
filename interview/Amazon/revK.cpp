Node* rev(Node* head, int k){
    if(head==NULL || k==1) return head;
    int cnt=k;
    Node *c=head, *p=NULL, *n;
    while(c!=NULL && cnt--){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head->next = rev(n, k);
    return p;
}