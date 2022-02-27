Node* reverseList(Node *head){
    Node *cur, *prev=NULL, *nxt;
    cur=head;
    while(cur!=NULL){
        nxt = cur->next;
        cur->next=prev;
        prev = cur;
        cur=nxt;
    }
    return prev;
}